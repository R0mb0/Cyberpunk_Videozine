/* User interface routines for 3DVIEW */

/* Written by Bernie Roehl, January 1992 (broehl@sunee.waterloo.edu) */

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
#include <ctype.h>
#include <dos.h>
#include <conio.h>     /* kbhit() */
#include <bios.h>      /* bioskey() */
#include <string.h>    /* strlen() */

#include "rend386.h"
#include "userint.h"
#include "pointer.h"
#include "cursor.h"

/* Colors */
#define INTERIOR   4
#define TEXT      14

#define TEXTHEIGHT 9
#define TEXTWIDTH 8

extern int left_page, right_page;
extern PDRIVER *menu_device;

#define CTRLF10   0x6700

unsigned getkey(void)
{
	unsigned c, d;
	union REGS regs;
	int shifted;

	c = bioskey(0);
	regs.h.ah = 2;
	int86(0x16, &regs, &regs);
	shifted = (regs.h.al & 3);
	d = c & 0xFF;
	if (d == 0)
	{
		c |= shifted; /* normal case */
		if (c == CTRLF10)
		{
			screendump();
			return 0;
		}
		return c; /* special case (shifted keypad) */
	}
	if (!shifted) return d;
	if (d == '8' || d == '4' || d == '6' || d == '2') return (c << 8) + shifted;
	else return d;
}

void neatbox(int w, int h, int *x, int *y)
{
	extern int v_page;
	*x = (screeninfo->xcent - (w >> 1)) & 0x0FF8;
	*y = screeninfo->ycent - (h >> 1);
	right_page = left_page = v_page; /* stop stereo for now */
	user_box(*x-2, *y-2, *x+w+8, *y+h+8, 0);
	user_box(*x-5, *y-5, *x+w+5, *y+h+5, INTERIOR);
}

static int last_jb, last_mb;	/* used to detect click for exit */

void poptext(char *text[])
{
 int i, h = 0, w = 0, x, y, page;

 page = cursor_hide();
 for (i = 0; text[i]; ++i)
  {
   h += TEXTHEIGHT;
   if (strlen(text[i])*TEXTWIDTH > w)
   w = strlen(text[i])*TEXTWIDTH;
  }
 if (w > 300) w = 300;
 neatbox(w , h , &x, &y);
 for (i = 0; text[i]; ++i)
  {
   user_text(x, y, TEXT, text[i]);
   y += TEXTHEIGHT;
  }
 cursor_show(page);
 set_goodbye();
}

set_goodbye()
{
 extern int have_joystick;
 int x,y;

 if(have_joystick)	/* update click status */
  {
   joystick_data joy;
   joy.port = 0;
   joy.scale = 0;
   joystick_read(&joy);
   last_jb = joy.buttons;
  }
 last_mb = 0;
 move_2D(menu_device,&x,&y,&last_mb);
}

int goodbye()  /* returns 1 if click, else key, else 0 if none */
{                            /* used to exit menus, etc */
 extern int have_joystick;
 int x, y, b;

 if(have_joystick)	/* test for joystick click */
  {
   joystick_data joy;
   joy.port = 0;
   joy.scale = 0;
   joystick_read(&joy);
   b = joy.buttons;
   if((b^last_jb)&b) return 1;
   last_jb = b;
  }

 b = 0;
 move_2D(menu_device,&x,&y,&b);  /* test for mouse click */
 if((b^last_mb)&b) return 1;
 last_mb = b;

 if(kbhit())			/* check for key click */
  {
   return getkey();
  }

 return 0;
}


int menu(char *text[]) /* returns key/click */
{
	int i, h = 0, w = 0, x, y, page;
	int top, left;
	unsigned buttons;
	int num = 0;
	char *c;

	page = cursor_hide();
	for (i = 0; text[i]; ++i)
	{
		h += TEXTHEIGHT;
		if (strlen(text[i])*TEXTWIDTH > w)
			w = strlen(text[i])*TEXTWIDTH;
	}
	if (w > 300) w = 300;
	neatbox(w, h, &x, &y);
	top = y; 
	left = x;
	for (i = 0; text[i]; ++i)
	{
		user_text(x, y, TEXT, text[i]);
		y += TEXTHEIGHT;
		num++;
	}
	cursor_show(page);
	do
		{
		while (move_2D(menu_device, &x, &y, &buttons) == 0) if (kbhit()) return toupper(getkey());
		;
		do
			{
			move_2D(menu_device,&x, &y, &buttons);
			if (kbhit()) return toupper(getkey());
		}
		while (!buttons);
		do
			{
			move_2D(menu_device,&x, &y, &buttons);
			if (kbhit()) return toupper(getkey());
		}
		while (buttons);
		if (y < top || x < left || x > left+w || y > h+top) return 0;
		i = (y-top) / TEXTHEIGHT;
	}
	while ((i < 0) || (i >= num));
	for (c = text[i]; (!(isupper(*c))) && (*c); c++)
		;
	i = *c;
	return(i);

	return toupper(getkey());
}


void popmsg(char *msg)
{
	int x, y, page;
	page = cursor_hide();
	neatbox(strlen(msg)*TEXTWIDTH+16, TEXTHEIGHT+16, &x, &y);
	user_text(x+8, y+8, TEXT, msg);
	cursor_show(page);
}

unsigned askfor(char *prompt, char *buff, int n)
{
	unsigned c, page;
	int x, y, i;

	if(n+strlen(prompt)>36) n = 36-strlen(prompt);
	page = cursor_hide();
	neatbox(strlen(prompt)*TEXTWIDTH + n * TEXTWIDTH + 10,
		TEXTHEIGHT + 5, &x, &y);
	user_text(x, y, TEXT, prompt);
	x += strlen(prompt) * TEXTWIDTH;
	buff[i = 0] = '\0';
	set_goodbye();
	while (1)
	 {
	  c = goodbye();
	  if(c==0x1B || c==1)	/* abort */
	   {
	    buff[0] = 0;
	    break;
	   }
	  if (c == '\r') break;
	  if (c == '\b' && i > 0)
	   {
	    user_box(x, y, x+TEXTWIDTH*strlen(buff), y+TEXTHEIGHT, INTERIOR);
	    buff[--i] = '\0';
	    user_text(x, y, TEXT,buff);
	   }
	    if (isprint(c) && i < n)
	   {
	    buff[i++] = c;
	    buff[i] = '\0';
	    user_text(x, y, TEXT, buff);
	  }
	 }
	cursor_show(page);
	return c;
}
