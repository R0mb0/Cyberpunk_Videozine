/* 2D pointer device (built-in) */

/* Written by Dave Stampe, Aug. 1992 */

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
#include <dos.h>
#include <bios.h>

#include "rend386.h"
#include "pointer.h"


/************** INTERNAL MOUSE SETUP ***********/

PDRIVER *mouse_device;

void mouseptr_quit()
{
	pointer_quit(mouse_device);
}


PDRIVER *mouseptr_init(char *mname)
{
 PDRIVER *p;
 POINTER x;

 p = pointer_init(P_IS2DP, mname); /* setup mouse device */
 if (p==NULL) return NULL;

 init_pointer(&x); /* so that defaults are OK */
 pointer_tscale(p, 1000, 1000, 1000); /* scale mouse */
 set_mouse_limits(p, screeninfo->xmax, screeninfo->ymax);
 pointer_read(p, &x);
 pointer_read(p, &x); /* save current position */
 mouse_read(p, NULL, NULL, NULL);

 mouse_device = p;
 atexit(mouseptr_quit);

 return p;
}



/***************** MOUSE POINTER DRIVER *************/

pconfig mouse_pconfig = {
	65536L, 65536L, 65536L, /* position res: mm/tick in <16.16>  */
	320, 200, 200, -320, -200, -200, /* xyz ranges:                */
	0, 0, 0, 0, 0, 0, 0, 0, 0, /* no rotation                       */
	640, 480, /* mouse emulation limits (writable) */
	P_HASB1 | P_HASB2 | P_HASX | P_HASY | P_HASZ | P_HASSCR, /* databits  */
	P_CENTER | P_SCREEN, 0, 0, /* modes, nullkey, flexnum           */
	1, 10, 60, /* delay, idelay, reads/sec          */
	P_IS2DP | P_IS2D, /* uses  */
	"Default Mouse Driver"
};


static mtype; /* if == P_IS2D, don't map Z with buttons */
static x_acc, y_acc, z_acc, xs_acc, ys_acc;

pconfig *mouse_driver(int op, POINTER *p, int mode)
{
 union REGS r;
 int type = FP_OFF(p); /* way to get integer arg. */

 switch(op)
  {
   case DRIVER_CMD:
    if (!(type & P_CENTER)) break;
    if (type & P_SCREEN)
     {
      xs_acc = mouse_pconfig.maxsx >> 1;
      ys_acc = mouse_pconfig.maxsy >> 1;
     }
    if (type & P_POINTER)
     {
      x_acc = y_acc = z_acc = 0;
     }
    break;
   case DRIVER_INIT:
   case DRIVER_RESET:
    r.x.ax = 0;
    int86(0x33, &r, &r);
    if (r.x.ax == 0) return NULL;
    x_acc = y_acc = z_acc = 0;
    xs_acc = mouse_pconfig.maxsx>>1;
    ys_acc = mouse_pconfig.maxsy>>1;
    break;

   case DRIVER_READ:/* pointer (2DP) read */
    if (mode == P_POINTER)
     {
      r.x.ax = 3; /* read button status */
      int86(0x33, &r, &r);
      p->buttons = r.x.bx;
      r.x.ax = 11; /* read motion counters */
      int86(0x33, &r, &r);
      x_acc += ((int) r.x.cx);
      if (p->buttons & 0x02)
       {
	z_acc -= ((int) r.x.dx);
	p->buttons &= 0x01;
       }
      else
       y_acc -= ((int) r.x.dx);
       p->x = x_acc;
       p->y = y_acc;
       p->z = z_acc;
     }
    else if (mode == P_SCREEN) /* mouse read (640x480) */
     {
      r.x.ax = 3; /* read button status */
      int86(0x33, &r, &r);
      p->buttons = r.x.bx;
      r.x.ax = 11; /* read motion counters */
      int86(0x33, &r, &r);
      xs_acc += ((int) r.x.cx);
      ys_acc += ((int) r.x.dx);
      if (xs_acc < 0) xs_acc = 0;
      if (ys_acc < 0) ys_acc = 0;
      if (xs_acc > mouse_pconfig.maxsx) xs_acc = mouse_pconfig.maxsx;
      if (ys_acc > mouse_pconfig.maxsy) ys_acc = mouse_pconfig.maxsy;
      p->x = xs_acc;
      p->y = ys_acc;
     }
    break;

   case DRIVER_CHECK:
    break;
   case DRIVER_QUIT:
    break;
  }
 return &mouse_pconfig;
}

