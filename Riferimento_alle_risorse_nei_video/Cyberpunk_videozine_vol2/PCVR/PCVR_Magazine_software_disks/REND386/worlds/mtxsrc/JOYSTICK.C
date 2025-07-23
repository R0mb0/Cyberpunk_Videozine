/* Read the joystick */

/* Written by Bernie Roehl, January 1992 (broehl@sunee.waterloo.edu)
	 Adapted from code written by ajmyrvold@violet.waterloo.edu (Alan J. Myrvold)
	 who got technical assistance from : uunet!netxcom!jallen (John Allen)

	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
 */

/* DSmods: - rotate calibration - switch debounce */
/* joystick interaction mods, timer read by Dave Stampe */

#pragma inline

#define TIMERJOYREAD 1

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <bios.h>
#include <conio.h>
#include "userint.h"   /* for joystick struct */
#include "rend386.h"   /* for interrupts_occurred */

extern void hookints(void);

/* This routine returns two bits; bit 0 on => joystick 1 found, bit 1 => joystick 2 */

int joystick_check(void)
{
	int c, result;
	disable();
	outportb(0x201,0xff); /* Trigger joystick */
	c = inportb(0x201);
	c = inportb(0x201);
	c = inportb(0x201);
	delay(2); /* wait a few milliseconds */
	c ^= inportb(0x201); /* any bits that changed state are now set */
	enable();
	result = 0;
	if (c & 0x03) result |= 1;
	if (c & 0x0C) result |= 2;
	return result;
}

int joystick_j1 = 0;     /* raw joystick results */
int joystick_j2 = 0;
int joystick_j3 = 0;
int joystick_j4 = 0;


#ifdef TIMERJOYREAD

void raw_joystick_read(int mask,
    int *j1, int *j2, int *j3, int *j4, int *buttons)
{					/* timer peek version */
 int c;					/* much more stable   */
 int vj1,vj2,vj3,vj4;			/* by Dave STampe, 8/5/93 */
 extern unsigned clock_rate;
 unsigned last_time;
 unsigned char raw = 0;
 int abort = 0;

 int k;

 if(!mask) return;

 interrupts_occurred = 0; 	/* repeat if timer interrupt! */
 do
  {
   if (interrupts_occurred) for (c = 0; c < 1000; c++); /* let it reset */
   interrupts_occurred = 0; /* repeat if timer interrupt! */
	 k = kbhit();

   vj1 = vj2 = vj3 = vj4 = 0;

   asm {
	push	dx

	cli
	mov	dx,0201h          /* start port timers */
	mov	al,0ffh
	out	dx,al

	mov	al,00h            /* read timer */
	out	043h,al
	nop
	nop
	nop
	nop
	in	al,040h
	mov	ah,al
	nop
	nop
	in	al,040h
	xchg	al,ah
	mov	last_time,ax

	in	al,dx            /* record port value */
	mov	raw,al
	and	al,mask
	mov	bl,al
	je      timeout        /* very short time */
	mov	cx,4000	/* safety timer */
	sti
       }
wloop:
	 asm {
	sti                      /* allow ints */
	cli
	in	al,dx
	mov	raw,al           /* port change? */
	and	al,mask
	xor	al,bl
	and     al,mask
	jne	timeout
	loop	wloop            /* safety timer */
	mov	al,mask
	not	al
	mov	raw,al
	mov	abort,ax
       }
timeout:
   asm {
	mov	bl,raw           /* record change */
	mov	bh,al

	mov	al,00h		 /* read new timer value */
	out	043h,al
	nop
	nop
	nop
	nop
	in	al,040h
	mov	ah,al
	nop
	nop
	in	al,040h
	xchg	al,ah
	sti

	sub	ax,last_time	 /* compute delay */
	neg	ax
	jge	posj
	add	ax,clock_rate	 /* fixup for timeout */
       }
posj:
   asm {
	test	bh,8		/* update proper values */
	je	ns4
	mov	vj4,ax
       }
ns4:
   asm {
	test	bh,4
	je	ns3
	mov	vj3,ax
       }
ns3:
   asm {
	test	bh,2
	je	ns2
	mov	vj2,ax
       }
ns2:
   asm {
	test	bh,1
	je	ns1
	mov	vj1,ax
       }
ns1:
   asm {
	mov	al,raw		/* check if all done */
	not	al
	and	al,mask
	cmp	al,mask
	jne	wloop
			 }
shorttime:
   asm {
	pop	dx
       }
  if(interrupts_occurred == 0 && k == kbhit() || abort) break;
 }
  while (1);
 *j1 = vj1;
 *j2 = vj2;
 *j3 = vj3;
 *j4 = vj4;
 *buttons = ((~raw) >> 4) & 0x0F;
 joystick_j1 = vj1;
 joystick_j2 = vj2;
 joystick_j3 = vj3;
 joystick_j4 = vj4;
}

#else

void raw_joystick_read(int mask,
    int *j1, int *j2, int *j3, int *j4, int *buttons)
{
 int vj1,vj2,vj3,vj4;
 int c, k, kb;
 int savemask;

 if(!mask) return;

#ifdef JOY_INTS
 /* mask all but timer IRQ : cannot use with some serial devices */
 disable();
 outportb(PIC_MASK,((savemask=inportb(PIC_MASK))|IRQ0_MASK));
 outportb(PIC_CMD, NONSPEC_EOI);
 enable();
#endif

 interrupts_occurred = 0; /* repeat if timer interrupt! */
 while(1)
  {
   kb = kbhit();
   if (interrupts_occurred) for (c = 0; c < 1000; c++); /* let it reset */
   interrupts_occurred = 0; /* repeat if timer interrupt! */
   outportb(0x201, 0xff); /* Trigger joystick */
   c = inportb(0x201);
   if (mask==0x0C) c >>= 2;
   *buttons = ((~c) >> 4) & 0x0F;

   for (k = 0; c & 3; k++) /* Get X and Y positions */
    {
     if (c & 1) vj1 = k;
     if (c & 2) vj2 = k;
     if (c & 4) vj3 = k;
     if (c & 8) vj4 = k;
     c = inportb(0x201);
    }
  if(interrupts_occurred == 0 && kb == kbhit()) break;
 }

 *j1 = vj1;
 *j2 = vj2;
 *j3 = vj3;
 *j4 = vj4;
 joystick_j1 = vj1;
 joystick_j2 = vj2;
 joystick_j3 = vj3;
 joystick_j4 = vj4;
#ifdef JOY_INTS
  disable();
	outportb(PIC_MASK,savemask); /* re-enable */
  enable();
#endif
}



#endif

/* This routine reads the joystick, setting x y and buttons */

int joystick_bt = 0;      /* used by pot head tracker */
int use_pothead = 0;

int joystick_read(joystick_data *joy)
{
 int c, k, jx, jy;
 int j;
 if (joy->port == -1) return 0;
 c = (joy->port) ? 0x0C : 0x03;
 if(use_pothead) c |= 0x0C;

 raw_joystick_read(c, &jx, &jy, &j, &j, &joystick_bt);
 joy->buttons = joystick_bt;
 if(joy->port) joy->buttons >>= 2;

 joy->x = jx - joy->cenx;
 joy->y = jy - joy->ceny;
 if (joy->scale)
  {
   joy->x = (joy->x * joy->scale) /joy->xrange;
   joy->y = (joy->y * joy->scale) /joy->yrange;
  }
 return 1;
}


/* This routine assumes the joystick is centered; sets the port and the
   maximum range for the joystick (i.e. minx to maxx) */

void joystick_init(joystick_data *joy, int port)
{
 joy->cenx = joy->ceny = 0;
 joy->port = port;
 joy->scale = 0;
 joystick_read(joy);
 joy->cenx = joy->x;
 joy->ceny = joy->y;
 joy->xrange = 2*joy->x;
 joy->yrange = 2*joy->y;
 if(joy->xrange==0) joy->xrange = 1;
 if(joy->yrange==0) joy->yrange = 1;
}

void joystick_setscale(joystick_data *joy, int value)
{
 joy->scale = value;
}

void joystick_quit(void)
{
}

/* If dir == 0, we're at top left; else, we're at bottom right */
/* NO LONGER USED */
void joystick_scale(joystick_data *joy, int dir)
{
	long t;
	long maxx, maxy, minx, miny;

	maxx = maxy = 0;
	minx = miny = 10000;

	t = joy->scale;
	joy->scale = 0;
	do {
		joystick_read(joy);
		if (joy->x > maxx) maxx = joy->x;
		if (joy->y > maxy) maxy = joy->y;
		if (joy->x < minx) minx = joy->x;
		if (joy->y < miny) miny = joy->y;
	}
	while (joy->buttons == 0);

	joy->xrange = maxx - minx;
	joy->yrange = maxy - miny;
	delay(10);
	do {
		joystick_read(joy);
	}
	while (joy->buttons);
	delay(10);

	joy->scale = t;
}


static int oldalt = 0;
static mjx = 0;
static mjy = 0;

static int old_mjx = 0;
static int old_mjy = 0;

extern int mouse_nav;
extern flymode;


mouse_joy(joystick_data *joy)
{
	union REGS r;
	int x,y,b;
	int alt;

	if (!mouse_nav) {

		r.h.ah = 2;
		int86(0x16, &r, &r);
		alt = r.h.al & 8;
		if (alt == 0)
		{
			joy->x = 0;
			joy->y = 0;
			joy->buttons = 0;
			oldalt = 0;
			return 0;
		}
		else
			if (oldalt == 0)
		{
			mjx = 0;
			mjy = 0;
			oldalt = alt;
		}
	}
	r.x.ax = 3; /* read button status */
	int86(0x33, &r, &r);
	{
		int b=0;
		if (r.x.bx & 1) b |= 2;
		if (r.x.bx & 2) b |= 1;
		joy->buttons = b;
	}

	r.x.ax = 11; /* read motion counters */
	int86(0x33, &r, &r);
	if(!flymode) old_mjx = old_mjy = 0;
	if ((!flymode) || (r.x.bx&2))
	{
		mjx = ((int) r.x.cx); /* MOUSE STEP: remove hysteresis */
		mjy = ((int) r.x.dx);

		if (mjx<0) mjx += -11;
		if (mjy<0) mjy += -11;
		if (mjx>0) mjx += 11;
		if (mjy>0) mjy += 11;
	}
	else
	{
		mjx = old_mjx; 	/* save for reversion */
		mjy = old_mjy;
		mjx += ((int) r.x.cx)>>2; /*  SPEED STEP */
		mjy += ((int) r.x.dx)>>2;
		if (mjx < -joy->scale) mjx = -joy->scale;
		if (mjy < -joy->scale) mjy = -joy->scale;
		if (mjx > joy->scale) mjx = joy->scale;
		if (mjy > joy->scale) mjy = joy->scale;
		old_mjx = mjx;
		old_mjy = mjy;
	}
	joy->x = mjx>>1;
	joy->y = mjy>>1;
	return 1;
}


#ifdef TEST
void main(void)
{
	joystick_data joy;
	if (joystick_check())
		printf("We found a joystick!\n");
	else {
		printf("No joy.\n");
		exit(0);
	}
	joystick_init(&joy, 0);
	joystick_setscale(&joy, 100);
	printf("Move joystick to upper left:\n");
	joystick_scale(&joy, 0);
	printf("Move joystick to lower right:\n");
	joystick_scale(&joy, 1);
	do {
		joystick_read(&joy);
		printf("%d,%d        \r", joy.x, joy.y);
	}
	while (joy.buttons == 0);
}
#endif
