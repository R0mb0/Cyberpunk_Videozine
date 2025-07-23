/* Written by Bernie Roehl, January 1992 */
/* Redone by Dave Stampe for integer, fast polys, colors etc */
/* Modified by Bernie Roehl to support surface types */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stamrpe
   for permission to incorporate any part of this software into their
   products!

	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
 */

/* Contact: broehl@sunee.waterloo.edu or dstampe@sunee.waterloo.edu */

#include <stdio.h>
#include <dos.h>
#include <stdlib.h>	/* labs */
#include "f3dkitd.h"
#include "rend386.h"
#include "f3dkitd.h"
#include "intmath.h"
#include "splits.h"

#define MAIN_VGA  1  /* for multi-VGA only */
#define LEFT_VGA  2
#define RIGHT_VGA 4
#define ALL_VGA   7

#define MONOSCOPIC 0 /* stereo types */
#define SWITCHED   1
#define SPLITLR    3
#define SEPARATE   5

struct Screeninfo *screeninfo;

extern int set_colors(); /* defined in color file */
extern int reset_colors();
extern int screen_clear_color;
extern int sky_color;
extern int ground_color;
extern int wireframe_color;
extern int highlight_color;
extern int highest_color;

extern int use_wide;
extern int use_ht;
extern int use_BW;
extern int vdmode;

long display_tilt =8*65536L; /* correction for display toe-in */

enter_graphics() /* enter and setup graphics screen */
{
	int i;

	set_gmode(vdmode);
	set_vpage(0);
	set_drawpage(0);
	clr_page(0,0);
	set_colors(use_BW);

	return(0);
}


exit_graphics() /* exit and restore text screen */
{
	exit_gmode();
	return 0;
}

void clear_display(int pge)
{
if(pge<screeninfo->pages) clr_page(pge,screen_clear_color);
}

void ptpoly(int count, int *pcoords, int color)
{
	int surface_type = (color>>12)&3;

	color &= 0xFFF;

	switch (surface_type) {
	case 0:
	case 1:
		fastpoly(count, pcoords, color);
		break;
	case 2:
		m_fastpoly(count, pcoords, color, 0xFF, 0x00);
		break;
	case 3:
		m_fastpoly(count, pcoords, color, 0xAA, 0xFF);
		break;
	}
}


extern int above_horizon(long x, long y, VIEW *v, long offset);
extern long y_horizon(long x, VIEW *v, long offset);
extern long x_horizon(long y, VIEW *v, long offset);
extern int clr_block(int left, int top, int right, int bottom, int page, int color);


#define HORSTEP 128L
#define HORDIVS 7
unsigned hcolors[20] = { 0xae, 0xad, 0xac, 0xab, 0x8a, 0x8b, 0x8c, 0x8d };

void init_ext_poly();
void add_ext_vertex(long x, long y);
void render_ext_poly(unsigned color);


static nhorizon(VIEW *v, int page, long step, int nstep, int *colorlist)
{
 int l = v->left;
 int r = v->right;
 int t = v->top;
 int b = v->bottom;
 int i, j, k;
 int vert = 0;
 int mfup, mfdn;
 int upright;
 int cd = 1;           /* step direction in thru color list */

 long offset;

 int olx, orx, oly, ory;
 int nlx, nrx, nly, nry;

 if(nstep==0)		/* just clear screen totally */
  {
   clr_block(l, t, r, b, page, colorlist[0]);
   return;
  }

 if(nstep>20) nstep = 20;
 offset = -(step * nstep)/2;     /* uppermost position */

 mfup = (above_horizon(l,t,v,offset) ) +   /* corners with top of horizon */
	(above_horizon(r,t,v,offset)<<1) +
	(above_horizon(l,b,v,offset)<<2) +
	(above_horizon(r,b,v,offset)<<3) ;

 mfdn = (above_horizon(l,t,v,-offset) ) +   /* corners with bot of horizon */
	(above_horizon(r,t,v,-offset)<<1) +
	(above_horizon(l,b,v,-offset)<<2) +
	(above_horizon(r,b,v,-offset)<<3) ;

 if(mfup==15)                               /* sky only case */
   {
    clr_block(l, t, r, b, page, colorlist[0]);
    return;
   }
 if(mfdn==0)                                /* ground only case */
   {
    clr_block(l, t, r, b, page, colorlist[nstep]);
    return;
   }

 if(labs(v->eye_xform[0][1]) > labs(v->eye_xform[1][1]) ) /* check slope */
  {
   vert++;        /* horizon is more vertical than horizontal */
   upright = (v->eye_xform[0][1]>=0); 	  /* sky on left */
  }
 else upright = (v->eye_xform[1][1]>=0);  /* sky on top */

 if(!upright)         /* will work backwards through colors */
  {                   /* and through horizon offsets */
   cd = -1;
   colorlist += nstep;
   step = -step;
   offset = step-offset;
  }

 if(!vert)
  {
   olx = l;               /* forcing top... */
   orx = r;
   oly = ory = -32000;
  }
 else
  {
   oly = t;               /* forcing left... */
   ory = b;
   olx = orx = 32000;
  }

 for(i=0;i<nstep;i++)
  {
   int nlx, nrx, nly, nry;
                                 /* compute new division */
   if(!vert)
    {
     nlx = l;
     nrx = r;
     nly = y_horizon(l, v, offset);
     nry = y_horizon(r, v, offset);
    }
   else
    {
     nly = t;
     nry = b;
     nlx = x_horizon(t, v, offset);
     nrx = x_horizon(b, v, offset);
    }

   init_ext_poly();              /* clip, draw polys */
   add_ext_vertex(orx, ory);
   add_ext_vertex(olx, oly);
   add_ext_vertex(nlx, nly);
   add_ext_vertex(nrx, nry);
   render_ext_poly(*colorlist);
   colorlist += cd;
   olx = nlx;
   oly = nly;
   orx = nrx;
   ory = nry;
   offset += step;
  }

 init_ext_poly();                 /* finish off last slice */
 add_ext_vertex(orx, ory);
 add_ext_vertex(olx, oly);
 if(!vert)
  {
   i = 32000;  /* force bottom */
   add_ext_vertex(l, i);
   add_ext_vertex(r, i);
  }
 else
  {
   i = -32000;  /* force right */
   add_ext_vertex(i, t);
   add_ext_vertex(i, b);
  }
 render_ext_poly(*colorlist);

}

#define OLD_HORIZON 1

static void horizon(VIEW *v, int page)
{
 set_drawpage(page);
 setup_hdwe(0);

#ifdef OLD_HORIZON
 hcolors[0] = sky_color;
 hcolors[1] = ground_color;
 nhorizon(v, page, 0, 1, hcolors);
#else
 nhorizon(v, page, HORSTEP, HORDIVS, hcolors);
#endif

 reset_hdwe();
 return;
}


extern volatile int has_switched; /* 3 when Sega has shown both eyes */
extern int v_page;
extern int fancy_background, reflection_pool, have_logo, show_logo;
extern int do_screen_clear, do_horizon;
extern int reframe, use_frame;
extern int stereo_type;
extern int swap_eyes;
extern int left_page, right_page;
extern STEREO default_stereo;
extern SPLIT *split_tree;
extern int show_location, show_compass, show_framerate;
extern int splitlx1, splitly1, splitlx2, splitly2;


extern int screen_clear_color;

long last_render_time = 8; /* time in 1/180 sec to redraw */

static int ccyc[30] = { 
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
	14,13,12,11,10,9,8,7,6,5,4,3,2,1 };

void background(int page, int top, int bot, int color)
{
	int inc = (top + (color & 15)) % 30;
	color &= 0xF0;

	for (; top <= bot; top += 2)
	{
		clr_block(0, top, 319, top+1, page, color+ccyc[inc]);
		if ((++inc) == 30) inc = 0;
	}
}

void reflection(int page, int top, int bot, int step)
{
	int src = top-step;

	for( ; top <= bot; top++)
	{
		copy_block(page, 0, src, page, 0, top, 320, 1);
		src -= step;
	}
}

static void coord_ref(int xc, int yc, int size, VIEW *v, int xcolor, int ycolor, int zcolor, int bcolor)
{
	long x, y, z;
	MATRIX m;

	if (show_compass == 0) return;

	view_to_matrix(v,m);
	m[3][0] = m[3][1] = m[3][2] = 0;
	matrix_transpose(m,m);

	setup_hdwe(0);
	x = size; 
	y = 0; 
	z = 0;
	matrix_point(m, &x, &y, &z);
	if (v->orientation & XFLIP)
	{
		vgaline(xc,yc,xc-x,yc-y,bcolor);
		printxyr(xc-x-5,yc-y,bcolor,"x",1);
		setup_hdwe(0);
		vgaline(xc-1,yc+1,xc-1-x,yc+1-y,xcolor);
		printxyr(xc-x-5-1,yc-y+1,xcolor,"x",1);
	}
	else
		{
		vgaline(xc,yc,x+xc,yc-y,bcolor);
		printxyr(x+xc+5,yc-y,bcolor,"x",0);
		setup_hdwe(0);
		vgaline(xc+1,yc+1,x+xc+1,yc-y+1,xcolor);
		printxyr(x+xc+5+1,yc-y+1,xcolor,"x",0);
	}

	setup_hdwe(0);
	y = size; 
	x = 0; 
	z = 0;
	matrix_point(m, &x, &y, &z);
	if (v->orientation & XFLIP)
	{
		vgaline(xc,yc,xc-x,yc-y,bcolor);
		printxyr(xc-x-5,yc-y,bcolor,"y",1);
		setup_hdwe(0);
		vgaline(xc-1,yc+1,xc-1-x,yc+1-y,ycolor);
		printxyr(xc-x-5-1,yc-y+1,ycolor,"y",1);
	}
	else
		{
		vgaline(xc,yc,x+xc,yc-y,bcolor);
		printxyr(x+xc+5,yc-y,bcolor,"y",0);
		setup_hdwe(0);
		vgaline(xc+1,yc+1,x+xc+1,yc-y+1,ycolor);
		printxyr(x+xc+5+1,yc-y+1,ycolor,"y",0);
	}

	setup_hdwe(0);
	z = size; 
	y = 0; 
	x = 0;
	matrix_point(m, &x, &y, &z);
	if (v->orientation & XFLIP)
	{
		vgaline(xc,yc,xc-x,yc-y,bcolor);
		printxyr(xc-x-5,yc-y,bcolor,"z",1);
		setup_hdwe(0);
		vgaline(xc-1,yc+1,xc-1-x,yc+1-y,zcolor);
		printxyr(xc-x-5-1,yc-y+1,zcolor,"z",1);
	}
	else
		{
		vgaline(xc,yc,x+xc,yc-y,bcolor);
		printxyr(x+xc+5,yc-y,bcolor,"z",0);
		setup_hdwe(0);
		vgaline(xc+1,yc+1,x+xc+1,yc-y+1,zcolor);
		printxyr(x+xc+5+1,yc-y+1,zcolor,"z",0);
	}
	reset_hdwe();
}


static VIEW left_view, right_view;

extern int frame_x, frame_y, frame_w, frame_h;

void reset_screens()
{
	int i;
	cursor_hide();
	for (i = 0; i < 4; ++i) {
		if (use_frame)
			copy_block(3, 0, 0, i, frame_x, frame_y, frame_w, frame_h);
		else
			clear_display(i);
	}
	cursor_show(v_page);
}

void screen_refresh(VIEW *current_view) /* now does stereo drawing */
{
	long old_time = current_time();
	int mxpge = 2;
	if (screeninfo->pages < 3) mxpge = 1;

	if (stereo_type == MONOSCOPIC)
	{
		if (reframe && use_frame) {
			copy_block((v_page == 3) ? 0 : (v_page + 1), 0, 0,
				v_page, 0, 0, 320, 200);
			reframe = 0;
		}
		if (++v_page > mxpge) v_page = 0; /* use 3 pages to avoid flicker */
		set_drawpage(v_page);

		render_set_view(current_view);

		if (fancy_background)
		{
			if (have_logo && show_logo)
				background(v_page, 30, reflection_pool ? 160 : 199, 0xBF);
			else background(v_page, 0, reflection_pool ? 160 : 199, 0xB0);
		}
		else if (use_frame && do_screen_clear && !do_horizon)
			clr_block(current_view->left,current_view->top,
				current_view->right,current_view->bottom,
				v_page,screen_clear_color);
		else if (do_horizon) {
			horizon(current_view,v_page);
		}
		else if (do_screen_clear)
			clear_display(v_page);
		if (have_logo && show_logo)
			copy_block(3, 0, 0, v_page, 0, 0, 320, 30);
		render_split(split_tree, current_view);
		if (reflection_pool) reflection(v_page, 160, 199, 3);
		status_on_screen();
		coord_ref(250,65,35,current_view,15,13,10,0);
		set_vpage(v_page);
		cursor_hide();
	}
 else if (stereo_type==SPLITLR)
	{
	if (++v_page > mxpge) v_page = 0;
	make_stereo_view(current_view,&left_view,LEFT_EYE);

	set_drawpage(v_page);
	render_set_view(&left_view);
	if (do_horizon) horizon(&left_view,v_page);
	else clear_display(v_page);

	setup_hdwe(0);
	render_split(split_tree, &left_view);
	reset_hdwe();
	make_stereo_view(current_view,&right_view,RIGHT_EYE);
	render_set_view(&right_view);
	if (do_horizon) horizon(&right_view,v_page);
	setup_hdwe(0);
	render_split(split_tree, &right_view);
	reset_hdwe();
	set_vpage(v_page);
	cursor_hide();
	if(splitlx1 >= 0)
	  {
	   setup_hdwe(0);
	   vgaline(splitlx1, splitly1, splitlx2, splitly2, highest_color);
	   reset_hdwe();
	  }
	if (mxpge < 2) vsync();
	}
 else
	{
	v_page = v_page ^ 2;

	if (stereo_type == SWITCHED)
		{
		make_stereo_view(current_view,&left_view,0);
		while ((has_switched&1) == 0) if (kbhit()) break;
		set_drawpage(v_page);
		render_set_view(&left_view);
		if (do_horizon) horizon(&left_view,v_page);
		else if (do_screen_clear)
		clear_display(v_page);
		render_split(split_tree, &left_view);
		setup_hdwe(0);
		printxyr(20,10,0,"L",0);
		status_on_screen();
		reset_hdwe();
		coord_ref(250,65,35,current_view,15,13,10,0);
		make_stereo_view(current_view,&right_view,1);
		while ((has_switched&2) == 0) if (kbhit()) break;
		set_drawpage(v_page+1);
		render_set_view(&right_view);
		if (do_horizon) horizon(&right_view,v_page+1);
		else if (do_screen_clear)
			clear_display(v_page+1); /* right page */
		render_split(split_tree, &right_view);
		setup_hdwe(0);
		printxyr(300,10,0,"R",0);
		status_on_screen();
		reset_hdwe();
		coord_ref(250,65,35,current_view,15,13,10,0);
		disable();
		if (swap_eyes)
			{
			left_page = v_page+1; /* display them now */
			right_page = v_page;
			}
		else
			{
			left_page = v_page;
			right_page = v_page+1;
			}
		has_switched = 0;
		enable();
		cursor_hide();
		}
	else if (stereo_type == SEPARATE) /* wide- angle display with seperate VGA cards */
		{
		set_drawpage(v_page);
		VGA_select(swap_eyes ? RIGHT_VGA : LEFT_VGA|MAIN_VGA);
		make_stereo_view(current_view, &left_view,0);
		render_set_view(&left_view);
		if (do_horizon) horizon(&left_view,v_page);
		else if (do_screen_clear)
				clear_display(v_page);
		render_split(split_tree, &left_view);
		setup_hdwe(0);
		printxyr(20,10,0,"L",0);
		reset_hdwe();

		VGA_select(swap_eyes ? LEFT_VGA|MAIN_VGA : RIGHT_VGA);
		make_stereo_view(current_view, &right_view, 1);
		render_set_view(&right_view);
		if (do_horizon) horizon(&right_view,v_page);
		else if (do_screen_clear)
				clear_display(v_page);
		render_split(split_tree, &right_view);
		setup_hdwe(0);
		printxyr(20,10,0,"R",1);
		coord_ref(60,175,25,&right_view,15,14,13,0);
		reset_hdwe();

		VGA_select(LEFT_VGA|MAIN_VGA);
		set_vpage(v_page);
		VGA_select(LEFT_VGA);
		VGA_select(RIGHT_VGA);
		set_vpage(v_page);
		VGA_select(MAIN_VGA);
		cursor_hide();
		}
	}

	last_render_time = current_time() - old_time;
	if (last_render_time == 0) last_render_time++;
	if (show_framerate)
	{
		char c[69];
		sprintf(c,"Frames/sec: %d",get_ticks_per_second()/last_render_time);
		printxyr(5,170,15,c,0);
	}
	set_drawpage(v_page);
	cursor_show(v_page);

}



/********************************************************/
/* USER ROUTINES CALLED BY THE RENDERING LIBRARY        */
/* KEEP THIS AS FAST AS POSSIBLE: SOME MAY BE           */
/* CALLED UP TO 1000 TIMES PER SCREEN!                  */
/********************************************************/

extern int wireframe;

/* USER ROUTINE TO SETUP FOR POLY DRAWING - CALLED ONCE PER FRAME */
void user_setup_blitter()
{
	setup_hdwe(0);
}

/* USER ROUTINE TO RECOVER AFTER POLY DRAWING: ONCE PER FRAME */
void user_reset_blitter()
{
	reset_hdwe();
}


/* USER ROUTINE TO DRAW TEXT BOXES */
void user_box(int x1, int y1, int x2, int y2, int color)
{
	int av[8];

	setup_hdwe(0);

	if (x1 < screeninfo->xmin) x1 = screeninfo->xmin; 
	if (x2 < screeninfo->xmin) x2 = screeninfo->xmin;
	if (y1 < screeninfo->ymin) y1 = screeninfo->ymin; 
	if (y2 < screeninfo->ymin) y2 = screeninfo->ymin;
	if (x1 > screeninfo->xmax) x1 = screeninfo->xmax; 
	if (x2 > screeninfo->xmax) x2 = screeninfo->xmax;
	if (y1 > screeninfo->ymax) y1 = screeninfo->ymax; 
	if (y2 > screeninfo->ymax) y2 = screeninfo->ymax;

	av[0] = x1; 
	av[1] = y1;
	av[2] = x1; 
	av[3] = y2;
	av[4] = x2; 
	av[5] = y2;
	av[6] = x2;
	av[7] = y1;

	fastpoly(4, &av[0], color);
	reset_hdwe();
}

/* USER ROUTINE TO DRAW TEXT */
void user_text(int x, int y, int color, char *string)
{
	printxyr(x, y, color, string,0);
}


static int x1, y1;
static void vlineto(int x, int y, int color)
{
	vgaline(x,y,x1,y1,color);
	x1 = x;
	y1 = y;
}

/* CALLED FROM RENDREP TO DRAW POLYS */

void user_render_poly(int number, int *pcoords, unsigned color, long maxz)
{
	int i;

	if (number == 1)
	{
		vgapoint(pcoords[0], pcoords[1], color);
		return;
	}
	if (number == 2)
	{
		vgaline(pcoords[0],pcoords[1],pcoords[2],pcoords[3],color);
		return;
	}
	if (!wireframe)
	{
		ptpoly(number, pcoords, color);

		if (color & 0x8000) /* highlighted? */
		{
			x1 = pcoords[0];
			y1 = pcoords[1];
			for (i = 1; i < number; ++i) vlineto(pcoords[i+i], pcoords[i+i+1], highlight_color);
			vlineto(pcoords[0], pcoords[1], highlight_color);
		}
	}
	else
		{
		x1 = pcoords[0];
		y1 = pcoords[1];
		for (i = 1; i < number; ++i) vlineto(pcoords[i+i], pcoords[i+i+1], wireframe_color);
		vlineto(pcoords[0], pcoords[1], wireframe_color);
	}
}

void vgabox(int left, int top, int right, int bottom, int color)
{
	setup_hdwe(0);
	vgaline(left, top, right, top, color);
	vgaline(right, top, right, bottom, color);
	vgaline(right, bottom, left, bottom, color);
	vgaline(left, bottom, left, top, color);
	reset_hdwe();
}
