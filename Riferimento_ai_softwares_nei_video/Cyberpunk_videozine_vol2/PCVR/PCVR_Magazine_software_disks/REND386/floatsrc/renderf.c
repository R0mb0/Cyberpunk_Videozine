/* Lower-level renderer */

/* Copyright 1992 by Bernie Roehl and Dave Stampe */

/* Written by Bernie Roehl, January 1992 */
/* Redone by Dave Stampe for integer, fast polys, colors etc */

/* REWRITTEN BACK TO FLOAT FOR EXAMPLE PURPOSES */

#include <stdio.h>
#include <graphics.h>
#include "3dstrucf.h"
#include "f3dkitn.h"

extern int wireframe;

extern int far Svga16_fdriver[];
extern int far Svga256_fdriver[];

static int huge DetectVGA()
{
	return 0;
}

static void setup_mode_16()
{
	int Gd = DETECT, Gm;

	installuserdriver("Svga16",DetectVGA);
	initgraph(&Gd,&Gm,"");
}

static void setup_mode_256()
{
	int Gd = DETECT, Gm;

	installuserdriver("Svga256",DetectVGA);
	initgraph(&Gd,&Gm,"");
}


static char palette_def[17] = {16,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

static char rst_pal[20] = {16,0,1,2,3,4,5,20,7,56,57,58,59,60,61,62,63};

enter_graphics()
{
	int i;

	setup_mode_16();
	set_gmode();
	set_vidpage(0,0);
	set_drawpage(0);
	clr_page(0,0);

	getpalette((struct palettetype *) rst_pal);
	setallpalette((struct palettetype *) palette_def);

	setrgbpalette(0,10,20,30);
	for (i = 1; i < 16; i++)
	setrgbpalette(i, i*4, i*3+4, i*2+4);

	return(0);
}


exit_graphics()
{
	exit_gmode();
	setallpalette((struct palettetype *) rst_pal);
	closegraph();
	return 0;
}


void clear_display(int pge)
{
	clr_page(pge,0);
}


static int xcoords[100], ycoords[100];
static int x1, y1;


static void vlineto(int x, int y)
{
	setup_hdwe(PUT);
	vgaline(x,y,x1,y1,13);
	reset_hdwe();
	x1 = x; y1 = y;
}



static void ppoly(int start, int count, int color)
{
	if (count<2) return;
	if (count==3)                 /* does 3-polys to draw multisided */
		{
		poly3(xcoords[0],ycoords[0],
		xcoords[start],ycoords[start],
		xcoords[start+1],ycoords[start+1], color);
		return;
		}
	ppoly(start,3,color);
	ppoly(start+1,count-1,color);
}



void render_poly(NPOLY *p)
{
	int i;
	NVERTEX **pv = p->points;
	NVERTEX *v;
	int *xp = &xcoords[0];
	int *yp = &ycoords[0];
	int number = p->npoints;
	int color = (p->color & 15) + 1;

	if (color>15) color = 15;

	for (i = 0; i < number; ++i)
		{
		v = *pv++;
		*xp++ = (*v).xs;        /* attempts to speedup xy coord copy   */
		*yp++ = (*v++).ys;      /* by using pointers: C still kills it */
		}

	if (!wireframe)
		{
		setup_hdwe(PUT);
		ppoly(1,number,color);
		reset_hdwe();
		return;
		}

	x1 = xcoords[0];
	y1 = ycoords[0];
	for (i = 1; i < p->npoints; ++i) vlineto(xcoords[i], ycoords[i]);
	vlineto(xcoords[0], ycoords[0]);
}
