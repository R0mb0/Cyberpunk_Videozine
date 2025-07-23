/* Glove pointer device */

/* Written by Dave Stampe, August 1992 */

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
#include <stdlib.h>    /* atexit() */
#include <dos.h>
#include <conio.h>     /* kbhit() */
#include "rend386.h"
#include "segasupp.h"
#include "pointer.h"
#include "intmath.h"
#include "userint.h"   /* popmsg(), getkey() */

/************** INTERNAL GLOVE SETUP ***********/

PDRIVER *glove_device;

extern int stereo_type; /* required for proper int. initialization */
extern refresh_display(void);

static void gloveptr_quit()
{
	pointer_quit(glove_device);
}


PDRIVER *gloveptr_init(char *gname, long sx, long sy, long sz, long srx, long sry, long srz)
{
	PDRIVER *p;
	POINTER x;

	p = pointer_init(P_IS3DG | P_IS6DG, gname); /* setup glove device */
	if (p == NULL) return NULL;

	init_pointer(&x); /* so that defaults are OK */
	/* use abs. glove motion */
	pointer_abscale(p, sx, sy, sz, srx, sry, srz);
	set_mouse_limits(p, screeninfo->xmax, screeninfo->ymax);
	pointer_read(p, &x);
	pointer_read(p, &x); /* save current position */
	mouse_read(p, NULL, NULL, NULL);

	glove_device = p;
	atexit(gloveptr_quit);

	return p;
}



/***************** GLOVE POINTER DRIVER *************/

static pconfig glove_pconfig = {
	5*65536L, 5*65536L, -15*65536L, 	/* position res: mm/tick in <16.16>  */
	120, 120, 120, -120, -120, -120, 	/* xyz ranges:                */
	0, -30*65536L, 0,
	0, 0, 0, 120, 11, 120, 			/* some rotation (swing emulation)       */
	320, 200, 				/* mouse emulation limits (writable) */
	P_HASX | P_HASY | P_HASZ | P_HASRY | P_HASSCR |
		P_HASGEST | P_HASFLEX | P_HASKEYS, 		/* databits  */
	P_CENTER | P_SCREEN, 0xFF, 11, 				/* modes, nullkey, flexnum           */
	2, 50, 20, 				/* delay, idelay, reads/sec          */
	P_IS3DG | P_IS3D | P_IS2D, 		/* uses  */
	"Default Powerglove Driver"
};

static glove_data glove_new; /* glove data structure */

#define DEBOUNCE_TIME 8

static setup_glove(void) /* glove initialize (incl. int. system) */
{
	glove_init(1);
	if (stereo_type != SWITCHED)
		init_SG_interrupt(NULL, glove_int_handler, 6500);
	else
	{
		init_SG_interrupt(switch_sega, glove_int_handler, 6500); /* start Sega interrupt */
		atexit(sega_off);
	}
	popmsg("Waiting for glove...");
	delay(1000);

	while (!glove_ready())
		if (kbhit())
		{
			getkey();
			return -3;
		}
	refresh_display();
	glove_read(&glove_new);
	return 0;
}


static fbend[4] = { 0, 40, 90, 127 }; /* finger flexions      */
static tbbend[4] = { 0, 25, 72, 127 };
static ttbend[4] = { 0, 35, 80, 127 };

pconfig *glove_driver(int op, POINTER *p, int mode)
{
	int ft, fi, fm, fp;

	switch(op)
	{
	case DRIVER_CMD:
	case DRIVER_RESET:
		break;

	case DRIVER_INIT:
		setup_glove();
		break;

	case DRIVER_READ:/* pointer (2DP) read */
		if (mode == P_POINTER)
		{
			if (glove_ready() == 0) return NULL;
			glove_read(&glove_new);
			p->x = glove_new.x;
			p->y = glove_new.y;
			p->z = glove_new.z;
			p->rx = 0;
			p->ry = ((long) glove_new.rot) << 16;
			p->rz = 0;
			p->buttons = 0;
			p->keys = glove_new.keys;

			ft = (glove_new.fingers >> 6) & 3; /* finger joint angles */
			fi = (glove_new.fingers >> 4) & 3;
			fm = (glove_new.fingers >> 2) & 3;
			fp = (glove_new.fingers >> 0) & 3;

			p->flex[0] = tbbend[ft];
			p->flex[1] = ttbend[ft];
			p->flex[2] = p->flex[3] = fbend[fi];
			p->flex[4] = p->flex[5] = fbend[fm];
			p->flex[6] = p->flex[7] = fbend[fp];
			p->flex[8] = p->flex[9] = fbend[fp];

			p->gesture = (gesture_time>DEBOUNCE_TIME)?gesture_type:G_UNKNOWN ;
		}
		else if (mode == P_SCREEN) /* mouse read (640x480) */
		{
			glove_read(&glove_new);
			p->x = scale_16(((long) glove_pconfig.maxsx) << 8, 127, (long)glove_new.x);
			p->y = scale_16(((long) glove_pconfig.maxsy) << 8, 127, -(long)glove_new.y);
			if (p->x < 0) p->x = 0;
			if (p->y < 0) p->y = 0;
			if (p->x > glove_pconfig.maxsx) p->x = glove_pconfig.maxsx;
			if (p->y > glove_pconfig.maxsy) p->y = glove_pconfig.maxsy;
			p->gesture = (gesture_time > DEBOUNCE_TIME) ? gesture_type : G_UNKNOWN;
			p->buttons = (p->gesture == G_FIST) ? 1 : 0;
		}
		break;

	case DRIVER_CHECK:
		break;
	case DRIVER_QUIT:
		break;
	}
	return &glove_pconfig;
}

