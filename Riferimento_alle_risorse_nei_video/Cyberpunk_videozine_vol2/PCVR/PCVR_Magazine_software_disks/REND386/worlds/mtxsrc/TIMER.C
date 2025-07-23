/* Timer routines for REND386; written by Dave Stampe, July 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!

	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
 */

#include <dos.h>
#include <bios.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <signal.h>

extern void vsync(void);

/******************* TIMER INTERRUPT STUFF ****************/

#define TIMER_VECT 8		/* timer chip int. vector */
#define UNUSED_VECT 128         /* user vector: used to link to std ISR */

#define PIC_CMD 0x20            /* constants for PIC EOI command */
#define NONSPEC_EOI 0x20
#define TIMER_MODE 0x34         /* timer setup command */
#define TIMER_CONTROL 0x43	/* timer control register port */
#define TIMER_0 0x40		/* timer 0 port */

#define LATCH_COUNT 0x00	/* command to latch count */

#define SYNC_INTERVAL 5	      /* how many frames between resynchronization */

static void init_SG_timer(int time);
static void reset_SG_timer(void);

static void interrupt fast_SG_timer(void);
static void interrupt (*oldint)(void) = NULL; /* old timer ISR vector */

unsigned int clock_rate = 0; /* calibrated timer rate for vertical */
static unsigned int clock_rate_hi = 0;
static unsigned int clock_rate_lo = 0;

static unsigned int divisor = 0; /* counter to emulate 18.2 Hz tick */

static int syncount = SYNC_INTERVAL; /* resync counter */

static long int_timer = 0; /* incremented each frame (use for timing) */

static void (*frame_interrupt_routine)(int) = NULL;
static void (*glove_interrupt_routine)(void) = NULL;

static int glovecount = 0;
static int glove_rate = 2; /* count of how many glove calls per frame */

/******************* FIND VERTICAL FRAME RATE *************/

#define ADVANCE 100             /* time (microseconds) of advance   */
                                /* in vert. interrupt.  Will act as */

static int find_sega_speed(void)  /* "vertical hold" adjustment       */
{
	unsigned int old, new; /* Routine to compute vertical frame    */

	vsync();
	outportb(TIMER_CONTROL, TIMER_MODE);
	outportb(TIMER_0, 0);
	outportb(TIMER_0, 0); /* timer must count modulo 65536 */

	disable(); /* time of vert. retrace */
	vsync();
	outportb(TIMER_CONTROL,LATCH_COUNT);
	enable();
	old = inportb(TIMER_0) & 0xFF;
	old |= (inportb(TIMER_0) << 8);

	vsync(); /* time 2 vert. retraces later */
	disable();
	vsync();
	outportb(TIMER_CONTROL,LATCH_COUNT);
	enable();
	new = inportb(TIMER_0) & 0xFF;
	new |= (inportb(TIMER_0) << 8);

	return ((old-new)>>1) - ADVANCE; /* compute interrupt rate */
}


long current_time(void)
{
	long i;

	disable();
	i = int_timer;
	enable();
	return i;
}

void set_current_time(long i)
{
	disable();
	int_timer = i;
	enable();
}


volatile int interrupts_occurred = 0;

static void interrupt fast_SG_timer(void) /* NEW TIMER ISR */
{
	unsigned int olddiv = divisor;

	disable();

	int_timer++;
	interrupts_occurred++;

	if (frame_interrupt_routine == NULL) goto glove;
	else frame_interrupt_routine(glovecount-1);
	if (--glovecount <= 0) glovecount = glove_rate;
	else goto glove;


	syncount--;
	if (syncount < 0)
	{
		syncount = SYNC_INTERVAL;
		outportb(TIMER_CONTROL, TIMER_MODE); /* stop timer */
		outportb(TIMER_0, 255);
		outportb(TIMER_0, 255);
		enable();
		disable();
		vsync();
		outportb(TIMER_CONTROL, TIMER_MODE); /* restart timer */
		outportb(TIMER_0, clock_rate_lo);
		outportb(TIMER_0, clock_rate_hi);
	}


glove:

	if (glove_interrupt_routine) glove_interrupt_routine();
	divisor += clock_rate; /* dec divide count */
	if (divisor < olddiv) /* simulate 18.2 Hz ISR if time */
		geninterrupt(UNUSED_VECT);

	outportb(PIC_CMD, NONSPEC_EOI);
	enable();
}


static int ticks_per_second = 0;

int get_ticks_per_second(void)
{
	return ticks_per_second;
}

void tdelay(int d)
{
 long dl = current_time() + (((long)d*ticks_per_second)/1000L);
 while(current_time()<=dl);
}


static void reset_SG_timer();

static void init_SG_timer(int speed) /* SET UP FAST TIMER */
{
	atexit(reset_SG_timer); /* set traps for error, ctrl c, */
	signal(SIGABRT, reset_SG_timer);
	signal(SIGFPE, reset_SG_timer);
	signal(SIGINT, reset_SG_timer);

	clock_rate = speed; /* save speed for future work */
	ticks_per_second = 1190000L/speed;
	clock_rate_hi = clock_rate >> 8;
	clock_rate_lo = clock_rate & 255;

	divisor = 0; /* set up timers */
	syncount = SYNC_INTERVAL;
	int_timer = 0;

	if (getvect(UNUSED_VECT) == NULL)
	{ /* setup int's if required(first run) */
		disable();
		oldint = getvect(TIMER_VECT); /* setup ISR vectors */
		setvect(UNUSED_VECT,oldint);
		setvect(TIMER_VECT, fast_SG_timer);
		outportb(TIMER_CONTROL, TIMER_MODE); /* load timer */
		outportb(TIMER_0, clock_rate_lo);
		outportb(TIMER_0, clock_rate_hi);
		enable();
	}
}


static void reset_SG_timer()   /* RESET PC TO NORMAL */
{
	disable();
	setvect(TIMER_VECT, oldint); /* reset vector */
	outportb(TIMER_CONTROL, TIMER_MODE); /* reset timer */
	outportb(TIMER_0, 0);
	outportb(TIMER_0, 0);
	setvect(UNUSED_VECT,NULL); /* disconnect flag */
	enable();

	signal(SIGINT, SIG_DFL);
	signal(SIGABRT, SIG_DFL);
	signal(SIGFPE, SIG_DFL);
}

/* SET EVERYTHING UP         */
/* (init. glove, Sega first) */

void init_SG_interrupt( void (*sega_switcher)(), /* NULL if no sega/video   */
	void (*glove_handler)(),                     /* NULL if no glove driver */
	int glove_tc)                                /* 1.19*uS (test interval) */
{                                                /* 6500 sugg. ALWAYS (fast timer)  */
	int i_rate;

	glove_interrupt_routine = glove_handler;
	frame_interrupt_routine = sega_switcher;

	if (sega_switcher == NULL)
		i_rate = glove_tc; /* glove only: use suggested speed */
	else
		{
		i_rate = find_sega_speed(); /* use a multiple of video rate   */
		if (glove_tc != 0)
		{
			glove_rate = i_rate/glove_tc; /* about 2x for 72 fps, 3x for 60 */

			if (glove_rate < 1) glove_rate = 1; /* handle no glove driver   */
			if (glove_rate > 20) glove_rate = 20; /* come on now...           */
			i_rate /= glove_rate;
		}
		else i_rate /=3;
	}
	init_SG_timer(i_rate); /* start 'er up! */
}

void init_timer()
{
	init_SG_interrupt(NULL,NULL,6500);
}

