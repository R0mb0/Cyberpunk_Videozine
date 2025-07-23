/* Support for steroscopic viewing */

/* Written by Dave Stampe, July 1992 */

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

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   /* toupper() */
#include <dos.h>

#include "rend386.h"
#include "intmath.h"

/* default screen data setup: example only */

/* STEREO default_stereo = { 1000, 250, 320, 63, 1000, 10*65536L }; */

/* static VIEW default_view = {       (EXAMPLE ONLY) */
/*			0,0,-1000,       */ /* ex,ey,ez */
/*			0,0,0,           */ /* pan,tilt,roll */
/*			9*65536L,        */ /* zoom */
/*			1000,15000,-5000, */ /* lx,ly,lz */
/*			0,319,0,200,     */ /* left,right,top,bottom */
/*			1,100000,        */ /* hither, yon */
/*			1/1.25*65536L,   */ /* aspect ratio */
/*			0,               */ /* flags */
/*			0,0		         */ /* no offset */
/*          };               */ /* don't init. matrix */


struct stview {
	MATRIX xform;
	long zoom;
	int x_offset;
	long left, top, right, bottom;
	int orientation;
};

static struct stview sview[2];

int splitlx1=-1, splitly1, splitlx2, splitly2;

/* call once for each eye to create cached stereo data */
/* as general as possible to support all devices       */

void compute_stereo_data(STEREO *stereo, int eye, int xflip, int xdist, long yr,
	long left, long top, long right, long bottom )
{
	long x_fixup;
	long world_iod;
	MATRIX c;

	sview[eye].zoom = (2*65536L * stereo->phys_screen_dist) /
		stereo->phys_screen_width;

	/* screen offset */
	x_fixup = (stereo->phys_eye_spacing *
		stereo->phys_screen_dist * stereo->pixel_width ) /
		(stereo->phys_convergence * 2 *stereo->phys_screen_width);

	/* eye point */
	world_iod = (stereo->phys_eye_spacing * stereo->world_scaling) >> 17;

	/* make left/right */
	if (eye == 0)
	{
		sview[eye].x_offset = xdist + ((xflip) ? -x_fixup : x_fixup) ;
		std_matrix(sview[eye].xform, 0, -yr, 0, -world_iod, 0, 0);
	}
	else if (eye == 1)
	{
		sview[eye].x_offset = xdist + ((xflip) ? x_fixup : -x_fixup) ;
		std_matrix(sview[eye].xform, 0, yr, 0, world_iod, 0, 0);
	}
	sview[eye].left = left;
	sview[eye].right = right;
	sview[eye].top = top;
	sview[eye].bottom = bottom;
	sview[eye].orientation = xflip ? XFLIP : 0;

	if(eye==1)
	 {
	  if( abs(sview[0].top-sview[1].top)<20 &&
	      abs(sview[0].bottom-sview[1].bottom)<20 )
	   {
	    splitly1 = (sview[0].top<sview[1].top) ? sview[0].top : sview[1].top ;
	    splitly2 = (sview[0].bottom<sview[1].bottom) ? sview[0].bottom : sview[1].bottom ;
	    if (sview[0].left<sview[1].left)
	      splitlx1 = splitlx2 = (sview[0].right+sview[1].left)/2;
	    else
	      splitlx1 = splitlx2 = (sview[1].right+sview[0].left)/2;
	   }
	  else splitlx1 = -1;
	 }
}


void make_stereo_view(VIEW *root, VIEW *nview, int eye)
{
	MATRIX c;

	*nview = *root; /* copy root view */
	nview->zoom = sview[eye].zoom;

	nview->x_offset +=
		sview[eye].orientation ? -sview[eye].x_offset : -sview[eye].x_offset ;

	view_to_matrix(nview,c);
	matrix_product(c, sview[eye].xform, c);
	matrix_view_factors(nview,c);

	nview->left = sview[eye].left;
	nview->right = sview[eye].right;
	nview->top = sview[eye].top;
	nview->bottom = sview[eye].bottom;

	nview->orientation = sview[eye].orientation ^ nview->orientation;

	initialize_screen_factors(nview);
}


/* sufficient if only view point has changed and no twist or offset */
void update_stereo_view(VIEW *v, STEREO *s, int eye)
{
	long world_iod = (s->phys_eye_spacing * s->world_scaling) >> 17;

	if (eye == LEFT_EYE)
	{
		v->eye_xform[3][0] -= m_mult(world_iod,v->eye_xform[0][0]);
		v->eye_xform[3][1] -= m_mult(world_iod,v->eye_xform[1][0]);
		v->eye_xform[3][2] -= m_mult(world_iod,v->eye_xform[2][0]);
	}
	else if (eye == RIGHT_EYE)
	{
		v->eye_xform[3][0] += m_mult(world_iod,v->eye_xform[0][0]);
		v->eye_xform[3][1] += m_mult(world_iod,v->eye_xform[1][0]);
		v->eye_xform[3][2] += m_mult(world_iod,v->eye_xform[2][0]);
	}
}

/* makes a standard SWITCHED stereo screen */

void default_stereo_setup(VIEW *v, STEREO *s)
{
	compute_stereo_data(s, 0, 0, 0, 0*65536L, v->left, v->top, v->right, v->bottom);
	compute_stereo_data(s, 1, 0, 0, 0*65536L, v->left, v->top, v->right, v->bottom);
}

