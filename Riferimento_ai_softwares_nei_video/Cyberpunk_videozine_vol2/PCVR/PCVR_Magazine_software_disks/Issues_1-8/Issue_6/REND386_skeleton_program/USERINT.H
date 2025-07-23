/* Header file for user-interface routines */

/* Written by Bernie Roehl, January 1992 (broehl@sunee.waterloo.edu) */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

typedef struct { 
	int x, y, buttons;
	int cenx, ceny;
	int xrange, yrange;
	long scale; /* maximum acceptable returned value for X and Y */
	int port;  /* port number, 0 or 1; -1 means 'unused' */
	} joystick_data;

extern int joystick_check();
extern void joystick_init(joystick_data *joy, int port);
extern int joystick_read(joystick_data *joystick);
extern void joystick_quit();
extern void joystick_setscale(joystick_data *joy, int value);
extern void joystick_scale(joystick_data *joy, int dir);
extern void neatbox(int w, int h, int *x, int *y);
extern void poptext(char *text[]);
extern void popmsg(char *msg);
extern unsigned askfor(char *prompt, char *buff, int n);
extern int menu(char *text[]);

/* End of userint.h */
