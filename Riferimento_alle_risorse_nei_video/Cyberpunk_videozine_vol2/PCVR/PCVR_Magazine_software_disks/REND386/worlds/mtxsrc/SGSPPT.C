/* IMPORTANT NOTE: THIS MODULE MUST NOT BE COMPILED WITH
   THE -3 OPTION IN BORLAND C++ 3.1 */

/* Sega and glove support routines; written by Dave Stampe, July 1992 */

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

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <bios.h>
#include <signal.h>
#include <string.h>     /* stricmp() */
#include "segasupp.h"
#include "f3dkitd.h"    /* set_vpage() */

/************ INTERFACE SPECIFIC GLOVE STUFF ****************/

int port_image = 0;
int sega_port_image = 0;

#define INPORT   0x379       	/* i/o port addresses */
#define OUTPORT  0x378

/* bits from parallel port: */
#define GDATA    0x10    /* PG data in */
#define GLATCH   0x02    /* PG latch out */
#define GCLOCK   0x01    /* PG clock out */
#define GCLOLAT  0x03    /* clock + latch */

#define GMASK    0x03	 /* bits changable for glove access */

/************ GLOVE SPEED AND INTERFACE *****************/

#define FASTCOUNT 8       /* # of fast packet bytes */

#define D2BITS	  12	  /* BIT DELAY: microseconds */
#define D2BYTES	  140	  /* BYTE DELAY: microseconds */

#define MAXRESET  200	  /* failed reads before resetting glove */


/***** declarations for assembly code in glovedel.asm *****/

int glove_none_mask = 0;
int glove_latch_mask = GLATCH;
int glove_clock_mask = GCLOCK;
int glove_clock_latch = GCLOLAT;

int glove_in_port = INPORT;
int glove_out_port = OUTPORT;

int glove_data_mask = GDATA;
int glove_write_mask = GMASK;

int glove_bit_delay = D2BITS;

int glove_byte_delay = D2BYTES;

static int glove_892_delay = 892;
static int glove_2260_delay = 2260;
static int glove_7212_delay = 7212;
static int glove_10000_delay = 10000;

extern unsigned int timed_glove_delay(int count);
	/* returns time in 1.1925 MHZ ticks */
	/* to perform <count> delay steps   */
	/* call with timer at 18.2 Hz rate  */

extern int glove_delay(int count);  /* performs <count> delay steps   */

extern int get_glove_byte(void);  /* reads a byte from glove */

extern void set_glove_bits(int data);  /* sets glove clock, data lines */
                                       /* and does a bit delay         */

/********* defines for output line pair control *******/

#define C0L0() set_glove_bits(glove_none_mask)    /* clock 0 latch 0 */
#define C0L1() set_glove_bits(glove_latch_mask)   /* clock 0 latch 1 */
#define C1L0() set_glove_bits(glove_clock_mask)   /* clock 1 latch 0 */
#define C1L1() set_glove_bits(glove_clock_latch)  /* clock 1 latch 1 */

/************ status and read control **********/

static int glove_rx_try = 10; /* number of read tries: first will be rxflags */
static int glove_rx_flags = 0; /* holds flags (read 10 mS after packet */


/********************** HIRES MODE SETUP *****************/

/*  HIRES ENTRY CODES
	byte:
	1- any value between $05 and $31   (x,y res. divisor???)
	2- only $C1 and $81 work OK (C1)(81 does garbage)
	3- no effect    (08)
	4- no effect    (00)
	5- no effect    (02)
	6- only $FF works   (FF)
	7- seems to affect read rate slightly, 1 fastest (01)
 */

static int glove_ignore = 0; /* # of interrupts to ignore glove so it */
                             /* will recover from mode setup          */

static int hires_code[7] = { 0x05, 0xC1, 0x08, 0x00, 0x02, 0xFF, 0x01 };

static void Hires(void) /* enter HIRES mode */
{
	int i,j,k;
	/* dummy read 4 bits from glove:  */
	C1L0(); 
	C1L1(); /* generate a reset (latch) pulse */
	glove_delay(glove_bit_delay); /* delay for 6 us */
	C1L0();
	glove_delay(glove_bit_delay); /* delay for 6 us */

	C0L0(); 
	C1L0(); /* pulse clock */
	C0L0();
	C1L0(); /* pulse clock */
	C0L0(); 
	C1L0(); /* pulse clock */
	C0L0(); 
	C1L0(); /* pulse clock */

	/* force glove to listen for setup */
	C1L0();
	glove_delay(glove_7212_delay); /* 7212 us delay */
	C1L1();
	glove_delay(glove_2260_delay); /* 2260 us delay */

	for (i = 0; i < 7; i++) /* send 7 bytes of mode data */
	{
		k = hires_code[i];
		for (j = 0; j < 8; j++) /* 8 bits per byte, MSB first */
		{
			if (k & 0x80)
			{
				C1L1();
				C0L1();
				C1L1();
			}
			else
			{
				C1L0();
				C0L0();
				C1L0();
			}
			k <<= 1;
		}
		glove_delay(glove_byte_delay);
	}

	glove_delay(glove_892_delay); /* 892 us delay (end of setup data) */

	C1L0(); /* drop the reset line */
	glove_ignore = 10; /* some time for the glove controller to relax */
}


/**************** HYSTERISIS NOISE REMOVAL: x,y,z,rot *************/

#define XHYST 2		    /* hysterisis for X, Y low noise reduction */
#define YHYST 2		    /* 2 eliminates +/-3 quanta of noise */
#define ZHYST 1
#define RHYST 0

static int ox = -1000; /* last x,y for hysterisis */
static int oy = -1000;
static int oz = -1000;
static int or = -1000;

static void dehyst(glove_data *g) /* hysterisis deglitch (low noise removal) */
{
	int x = g->x;
	int y = g->y;
	int z = g->z;
	int r = g->rot;
	/* handle recentering ("0"key or "Center") */
	if (g->keys == 0) ox = oy = oz = 0;

	if (x-ox > XHYST) ox = x-XHYST; /* X hysterisis */
	else
		if (ox-x > XHYST) ox = x+XHYST;

	if (y-oy > YHYST) oy = y-YHYST; /* Y hysterisis */
	else
		if (oy-y > YHYST) oy = y+YHYST;

	if (z-oz > ZHYST) oz = z-ZHYST; /* Z hysterisis */
	else
		if (oz-z > ZHYST) oz = z+ZHYST;

	if (RHYST)
	{
		if (or < 3 && r > 8) /* CCW around-end */
			if (or > 0 || r < 11) or = r+RHYST; 
		else;
		else
			if (or > 8 && r < 3) /* CW around-end */
				if (or < 11 || r > 0) or = r-RHYST; 
		else;
			else
				if (r-or > RHYST) or = r-RHYST; /* R hysterisis */
				else
					if (or-r > RHYST) or = r+RHYST;

		if (or > 11) or -= 11;
		if (or < 0) or += 11;
	}
	else or = r;
	g->x = ox; /* replace present X,Y data */
	g->y = oy;
	g->z = oz;
	g->rot = or;
}

/****************** DEGLITCHING ***************/

#define XACC 8          /* X, Y maximum accel/decel level. Should */
#define YACC 8		/* be 6-10, but too high limits gesturing */

#define XXTEND 1	/* stretches deglitching time */
#define YXTEND 1
#define ROTTIME 1

static int x1 = 0; /* delayed 1 sample (for smoothed velocity test) */
static int y1 = 0;
static int x2 = 0; /* delayed 2 samples */
static int y2 = 0;
static int lx = 0; /* last good X,Y speed */
static int ly = 0;
static int lax = 0; /* bad data "stretch" counter */
static int lay = 0;
static int lsx = 0; /* X,Y "hold" values to replace bad data */
static int lsy = 0;
static int lcx = 0; /* last X,Y speed for accel. calc. */
static int lcy = 0;

static int saverot = 0;
static int lastrot = 0; /* last stable rotate */
static int chrot = 0; /* time its been stable */

static void deglitch(glove_data *g)
{
	int vx, vy;

	int x = g->x;
	int y = g->y;

	if (g->keys == 0) /* reset on recentering ("0" or "Center" key) */
	{
		x1 = x2 = y1 = y2 = 0;
		lx = ly = lax = lay = 0;
		lsx = lsy = lcx = lcy = 0;
		lastrot = chrot = saverot = 0;
	}

	if (lastrot != g->rot)
	{
		chrot = 0;
		lastrot = g->rot;
		g->rot = saverot;
	}
	else
		{
		if (chrot < ROTTIME)
		{
			chrot++;
			g->rot = saverot;
		}
		else saverot = lastrot = g->rot;
	}

	vx = x-((x1+x2) >> 1); /* smoothed velocity */
	vy = y-((y1+y2) >> 1);

	x2 = x1; /* update last values */
	x1 = g->x;

	y2 = y1;
	y1 = g->y;

	if (abs(lcx-vx) > XACC) lax = XXTEND; /* check for extreme acceleration */
	if (lax == 0) lx = vx; /* save only good velocity        */
	lcx = vx; /* save velocity for next accel.  */

	if (abs(lcy-vy) > YACC) lay = YXTEND; /* same deal for Y accel. */
	if (lay == 0) ly = vy;
	lcy = vy;

	if (lax != 0) /* hold X pos'n if glitch */
	{
		g->x = lsx;
		lax--;
	}

	if (lay != 0) /* hold Y pos'n if glitch */
	{
		g->y = lsy;
		lay--;
	}

	lsx = g->x; /* save position for X,Y hold */
	lsy = g->y;
}

/**************** COMPUTE COUNTS FOR TIME CALIBRATION ***********/

static float factor;

static int uconvert(int t)
{
	float f;
	f = factor*((float)t);
	if (f < 1.0) return 1;
	if (f > 60000.0) return 60000;
	return f;
}


static void calibrate(void)
{
	factor = 11900.0/((float) timed_glove_delay(10000));

	glove_bit_delay = uconvert(glove_bit_delay);
	glove_byte_delay = uconvert(glove_byte_delay);
	glove_892_delay = uconvert(glove_892_delay);
	glove_2260_delay = uconvert(glove_2260_delay);
	glove_7212_delay = uconvert(glove_7212_delay);
	glove_10000_delay = uconvert(glove_10000_delay);
}

/******************* gesture recognition **************/

#define G_FLAT      0
#define G_THUMB_IN  1
#define G_INDEX_IN  2
#define G_MIDDLE_IN 3
#define G_RING_IN   4
#define G_PINCH     5
#define G_FIST      6
#define G_THUMB_OUT 7
#define G_POINT     8
#define G_BADFINGER 9
#define G_RING_OUT 10
#define G_UNKNOWN  11      /* gesture classification */

long gesture_time = 0;
unsigned char gesture_type = G_UNKNOWN;
static unsigned char last_gesture = G_UNKNOWN;

/* more reliable mapped gestures */

static unsigned char gesture_map[12] = { 
	G_FLAT, G_FLAT, G_PINCH, G_MIDDLE_IN,
	G_RING_IN, G_PINCH, G_FIST, G_FIST, G_POINT,
	G_BADFINGER, G_FIST, G_UNKNOWN };

/* unmapped gestures */
/*
char gesture_map[12] = { G_FLAT, G_THUMB_IN, G_INDEX_IN, G_MIDDLE_IN,
			 G_RING_IN, G_PINCH, G_FIST, G_THUMB_OUT,
			 G_POINT, G_BADFINGER, G_RING_OUT, G_UNKNOWN };
*/

static int g_lookup[256]; /* compiled lookup table for gestures */

static char gs[11][8] = { 
	0,1, 0,0, 0,0, 0,0,
	2,3, 0,0, 0,0, 0,1,
	/* data is: for each gesture   */ 0,1, 2,3, 0,1, 0,1,
	/* and for each finger, a max. */ 0,3, 0,1, 2,3, 0,1,
	/* and min. bend value         */ 0,3, 0,1, 0,1, 2,3,
	1,3, 2,3, 0,1, 0,1,
	2,3, 2,3, 2,3, 1,3,
	0,1, 2,3, 2,3, 1,3,
	0,3, 0,1, 2,3, 1,3,
	0,3, 2,3, 0,1, 1,3,
	0,3, 2,3, 2,3, 0,1 };

static void init_gestures(void)
{
	int g,t,i,m,r,x;

	for (g = 0; g < 256; g++) g_lookup[g] = G_UNKNOWN;

	for (g = 11; g; )
	{
		g--;
		for (t = 0; t < 4; t++)
			for (i = 0; i < 4; i++)
				for (m = 0; m < 4; m++)
					for (r = 0; r < 4; r++)
					{
						x = (t<<6)+(i<<4)+(m<<2)+r;
						if (gs[g][0] <= t && gs[g][1] >= t)
							if (gs[g][2] <= i && gs[g][3] >= i)
								if (gs[g][4] <= m && gs[g][5] >= m)
									if (gs[g][6] <= r && gs[g][7] >= r)
										g_lookup[x] = g;
					}
	}
}

static void gesture_process(glove_data *g)
{
	gesture_time++;
	gesture_type = g_lookup[((int)g->fingers) & 255];
	gesture_type = gesture_map[gesture_type];
	if (gesture_type != last_gesture) gesture_time = 0;
	last_gesture = gesture_type;
}


/******************* READ GLOVE DATA PACKET *************/

void getglove(glove_data *buf) /* read 6 byte data packet */
{
	unsigned char *bp = (char *) buf;
	int i;

	for (i = 0; i < FASTCOUNT; ++i)
	{
		*bp++ = get_glove_byte(); /* read data */
		glove_delay(glove_byte_delay);
	}
	glove_rx_try = 0;
	buf->rxflags = 0x3f; /* default all rx fired, but will be read in */
}   /* 8-10 mS when glove_ready returns 2        */
    /* also stored in glove_rx_flags 	     */

/*************** GLOVE INTERRUPT HANDLER **************/

static glove_data glove_int_data; /* our copy of the most recent data */

static unsigned unready = 0; /* number of times glove has been not ready */
static int glove_deglitch; /* switches deglitching on and off */

void glove_int_handler()
{
	int n;

	if (glove_ignore) /* wait out setup time if required */
	{
		glove_ignore--;
		return;
	}

	glove_rx_try++;

	if ((n = get_glove_byte()) != 0xA0)
	{
		if (glove_rx_try == 1) glove_rx_flags = glove_int_data.rxflags = n;
		if (++unready > MAXRESET)
		{ /* glove not responding... reset it */
			unready = 0;
			Hires();
		}
	}
	else
		{ /* data ready! */
		glove_delay(glove_byte_delay);
		unready = 0;
		getglove(&glove_int_data);

		if (glove_deglitch)
			deglitch(&glove_int_data); /* remove spikes and jumps */
		dehyst(&glove_int_data); /* add hysteresis to remove LL noise */
		gesture_process(&glove_int_data);
		++glove_int_data.nmissed; /* flag data as new */
	}
}

/******************* GLOVE INITIALIZATION ***************/

#define TIMER_CONTROL 0x43	/* timer control register */
#define TIMER_0       0x40	/* timer zero data register */
#define TIMER_MODE    0x36	/* byte to write to control register */

void glove_init(int gdeg) /* gdeg switches deglitching */
{
	outportb(TIMER_CONTROL, TIMER_MODE); /* reprogram timer to mod 65536 */
	outportb(TIMER_0, 0); /* so calibration is correct    */
	outportb(TIMER_0, 0);

	glove_deglitch = gdeg;
	calibrate(); /* compute timing counts */
	Hires(); /* enter hires mode */
	init_gestures();
	glove_int_data.nmissed = 0; /* mark no new data yet */
}

/************** EXTERNAL DATA INTERFACE **************/

int glove_read(glove_data *glov) /* return copy of data packet */
{
	disable();
	*glov = glove_int_data;
	glove_int_data.nmissed = 0;
	enable();
	return glov->nmissed;
}

                   /* data status:                   */
int glove_ready()  /* returns 0 if no new data,      */
{                  /*         1 if new data ready,   */
	int lgin, lgrt;  /*         2 if rxflags valid too */

	disable();
	lgin = glove_int_data.nmissed;
	lgrt = glove_rx_try;
	enable();

	if (lgin == 0) return 0;
	if (lgrt > 0) return 2;
	return 1;
}



/****************** SWITCHER DRIVER INTERFACE *************/


#define SW_INIT        0
#define SW_QUIT        1
#define SW_ADV_SWITCH  2
#define SW_SYNC_SWITCH 3

static int (*switch_driver)() = NULL;

static void sdriver_quit()
{
	if (switch_driver) switch_driver(SW_QUIT);
}

extern void *load_driver();

void init_switch_driver(char *sdname)
{
	if (!stricmp(sdname, "sega"))
	{
		atexit(sega_off);
		return;
	}

	switch_driver = load_driver(sdname);

	if (switch_driver == NULL)
	{
		fprintf(stderr,"Cannot read switcher driver %s\n", sdname);
		exit(0);
	}

	switch_driver = MK_FP(FP_SEG(switch_driver), 16+FP_OFF(switch_driver)); /* entry point */
	switch_driver(SW_INIT);
	atexit(sdriver_quit);
}


/********************* SEGA GLASSES CONTROL *****************/

int left_page = 0; /* left image */
int right_page = 1; /* right image */
int has_switched; /* = 3 once both switched in */

static int adv_has_switched = 0;

#define SEGA_LEFT  0x30
#define SEGA_RIGHT 0x20
#define SEGA_OFF   0x00

#define SEGA_MASK  0x30   	/* bits writeable for Sega */

#define COMPORT 0x3fc   	/* com1 = 0x3fc, com2 = 0x2fc */

int sega_left = SEGA_LEFT;
int sega_right = SEGA_RIGHT;
int sega_address = COMPORT;
int sega_mask = SEGA_MASK;
int sega_doff = SEGA_OFF;

static int phase = 1; /* current image */

void select_sega_port(int port)  /* sets up default Sega stuff */
{
 sega_address = port;
 sega_left = SEGA_LEFT;
 sega_right = SEGA_RIGHT;
 sega_mask = SEGA_MASK;
 sega_doff = SEGA_OFF;
}

static void sega_write(int data)  /* write Sega data w/o disturbance */
{                          /* can also handle glove, Sega on same port */
	disable();
	if (sega_address == glove_out_port)
		sega_port_image = port_image =
			(port_image & (~sega_mask)) | (data & sega_mask);
	else
		sega_port_image = (sega_port_image & (~sega_mask)) | (data & sega_mask);
	outportb(sega_address, sega_port_image);
	enable();
}

void switch_sega(int to_go)  /* now gets arg, sync at 0, 1 = advanced signal */
{                            /* 2-step switching ensures adr. load of VGA    */
	if (switch_driver)
	{
		if (to_go == 1)
		{
			if (phase == sega_left)
			{
				phase = sega_right;
				if (switch_driver(SW_ADV_SWITCH, 0) )
					set_vpage(right_page);
				adv_has_switched = 1;
			}
			else
				{
				phase = sega_left;
				if (switch_driver(SW_ADV_SWITCH, 1) )
					set_vpage(left_page);
				adv_has_switched = 2;
			}
		}
		if (to_go == 0)
		{
			switch_driver(SW_SYNC_SWITCH, (phase == sega_left) ? 1 : 0);
			has_switched |= adv_has_switched;
			adv_has_switched = 0;
		}
	}
	else
		{
		if (to_go == 1)
		{
			if (phase == sega_left)
			{
				phase = sega_right;
				set_vpage(right_page);
				adv_has_switched = 1;
			}
			else
				{
				phase = sega_left;
				set_vpage(left_page);
				adv_has_switched = 2;
			}
		}
		if (to_go == 0)
		{
			sega_write(phase);
			has_switched |= adv_has_switched;
			adv_has_switched = 0;
		}
	}
}


void sega_off()
{
	sega_write(sega_doff); /* turn glasses driver off to save lcds! */
}

