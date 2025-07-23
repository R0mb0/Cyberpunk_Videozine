/*
 POTENTIOMETER 2D head tracker:
 pot 3 is pan
 pot 4 is tilt
 button 3 is hold
 button 4 is recenter
 config file use:
	pot <pscale> <poff> <tscale> <toff> <nr> <nrinc>
 by Dave Stampe, May 1993
 (c) 1993 Dave Stampe
*/

#include <stdlib.h>
#include <dos.h>
#include <bios.h>
#include <stdio.h>
#include <conio.h>
#include <signal.h>
#include <mem.h>

#include "rend386.h"
#include "userint.h"
#include "pointer.h"


/*****************/



/*
static p_dump(int i)
{
 char c[100];

 sprintf(c,"%d: %d %.0f,%.0f,%.0f %.0f,%.0f,%.0f", i, status_6d,
 ((float) x_6d) / 40.0, ((float) y_6d) / 40.0, ((float) z_6d) / 40.0,
 ((float) rx_6d) / 40.0, ((float) ry_6d) / 40.0, ((float) rz_6d) / 40.0);

 popmsg(c);
}
*/


/************* POTENTIOMETER POINTER DRIVER *************/

static pconfig pot_pconfig = {
	1640L, 1640L, 1640L,	        /* position res: mm/tick in <16.16>  */
	1048575L, 1048575L, 1048575L,   /* xyz ranges: just dummies */
	-1048575L, -1048575L, -1048575L,
	1640L, 1640L, 1640L,		/* rotation res: <ticks per */
	7200L, 7200L, 7200L,
	-7200L, -7200L, -7200L,         /* rotation range      */
	320, 200, /* mouse emulation limits (writable) */
	P_HASRX | P_HASRY,	        /* databits  */
	P_POINTER, 0, 0,                 /* modes, nullkey, flexnum           */
	5, 5, 100,                     /* delay, idelay, reads/sec          */
	P_IS6D | P_IS6H | P_IS3D,       /* uses  */
	"Joystick Pot Head Tracker"
};


static int pan_off = 0;
static int tilt_off = 0;
static int boxnr = 0;
static long boxnrs = 0;

static long rx, ry;

static pot_init()
{
 extern int use_pothead;
 extern int joystick_check();
 extern float hdo_x, hdo_y, hdo_z, hdo_rx, hdo_ry, hdo_rz;

 if((joystick_check() & 1)==0)
  {
   popmsg("No Pot Headtracker!");
   getch();
   exit(0);
  }

 pot_pconfig.xrres = hdo_x*65536.0;	/* set scaling of rotation */
 pot_pconfig.yrres = hdo_z*65536.0;

 pan_off = hdo_y;
 tilt_off = hdo_rx;

 boxnr = hdo_ry;
 boxnr = hdo_rz*256;

 rx = ry = 0;

 use_pothead++;

 hdo_x = hdo_y = hdo_z = hdo_rx = hdo_ry = hdo_rz = 0.0;  /* use only locally */
}

static read_pots()
{
 extern int have_joystick;
 extern int joystick_j1;
 extern int joystick_j2;
 extern int joystick_j3;
 extern int joystick_j4;
 extern int joystick_bt;
 int x, y;
 int boxx, boxy;

 if(!have_joystick)	/* make sure it's read */
  {
   joystick_data joy;

   joy.port = 0;
   joy.scale = 0;
   joystick_read(&joy);
  }

 x = joystick_j4;
 y = joystick_j3;

 if(joystick_bt & 8)  /* recenter */
  {
   pan_off = y;
   tilt_off = x;
   rx = 0;
   ry = 0;
   return 0;
  }
 if(joystick_bt & 4) /* hold */
  {
   tilt_off = x - rx;
   pan_off = y - ry;
   return 0;
  }

 boxx = boxnr;
 boxy = boxnr;
 if(boxnrs)                 /* adj. threshold for noise level */
  {
   boxx += (x*boxnrs)>>8;
   boxy += (y*boxnrs)>>8;
  }

 x -= tilt_off;
 y -= pan_off;

 if (x-rx > boxx) rx = x-boxx; 		/* X nr */
 else if (rx-x > boxx) rx = x+boxx;
 if (y-ry > boxy) ry = y-boxy; 		/* Y nr */
 else if (ry-y > boxy) ry = y+boxy;
}


pconfig far *pot_driver(int op, POINTER *p, int mode)
{
	int type = FP_OFF(p); 		/* way to get integer arg. */
	int ft, fi, fm, fp;

	switch(op)
	{
	case DRIVER_CMD:
	case DRIVER_RESET:
		break;

	case DRIVER_INIT:
		pot_init();
		break;

	case DRIVER_READ:		/* head pointer (6DP) read */
		if (mode == P_POINTER)
		 {
		  read_pots();
		  p->x = 0;
		  p->z = 0;
		  p->y = 0;
		  p->rx = rx*65536L;
		  p->ry = ry*65536L;
		  p->buttons = 0;
		  p->keys = 0;
		  p->gesture = -1 ;
		 }
		break;

	case DRIVER_CHECK:
		break;
	case DRIVER_QUIT:
		break;
	}
	return &pot_pconfig;
}

