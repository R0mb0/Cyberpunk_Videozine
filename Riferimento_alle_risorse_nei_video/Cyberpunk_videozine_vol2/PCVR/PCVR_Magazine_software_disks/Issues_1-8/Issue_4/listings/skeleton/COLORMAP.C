/* Routine to setup and compute colors */
/* for 256-color mode 		       */

/* Written by Dave Stampe Mar 21 1992 */
/* Modified by Bernie Roehl, April 2, 1992 */
/* Substantially upgraded by Dave Stampe, August '92 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

#include <stdio.h>
#include <dos.h>
#include "include/rend386.h"

/* colors to use on screen */

int screen_clear_color = -1;
int sky_color = -1;
int ground_color = -1;
int wireframe_color = -1;
int highlight_color = -1;
int highest_color = -1;

extern int do_horizon;

void preset_default_colors()
{
	if (highest_color > 254)
	{
		if (screen_clear_color == -1) screen_clear_color = 3;
		if (sky_color == -1) sky_color = 3;
		if (ground_color == -1) ground_color = 0x88;
		if (wireframe_color == -1) wireframe_color = 13;
		if (highlight_color == -1) highlight_color = 15;
	}
	else /* if (highest_color > 14) */
	{
		if (screen_clear_color == -1) screen_clear_color = 10;
		if (sky_color == -1) sky_color = 10;
		if (ground_color == -1) ground_color = 5;
		if (wireframe_color == -1) wireframe_color = 12;
		if (highlight_color == -1) highlight_color = 15;
	}
	do_horizon = (sky_color==ground_color) ? 0 : 1 ;
}

void set_colors(int bw)
{
	load_DAC_colors(NULL, highest_color+1, bw);
}


/* USER POLYGON LIGHTING ROUTINE: DETERMINES POLY COLOR # */

/* The 16-bit color the user specifies for a polygon is broken down as
   follows:
                 H R SS CCCC BBBBBBBB        
   
   H is the highlight flag (the polygon should be highlighted in
   some way, usually by outlining it in the highlight_color given above).

   R is a reserved bit, which should be set to zero

   SS is a two-bit field specifying one of four surface types:

      00 is a constant-color surface; the 4-bit field CCCC is ignored, and the
         8-bit field BBBBBBBB is used as an absolute color number

      01 is a cosine-lit surface; the 4-bit field CCCC specifies one of 16
         basic colors, and the 8-bit brightness field BBBBBBBB is multiplied
         by the cosine of the angle between the light source and the polygon's
         surface normal to provide a 4-bit shading value.

      10 is a pseudo-metallic surface; the CCCC field gives the starting hue,
         and the BBBBBBBB value is ignored.  The color will cycle through
         the different shades to give a 'metallic' effect.

      11 is a pseudo-transparent surface made up of alternating rows of
         spaced dots; other than that, it behaves like a pseudo-metallic
         surface.

   This routine maps the above into an 8-bit color number in the low byte
   of its return value, and passes through the top four bits.

 */

extern int ambient_light;

int user_poly_color(POLY *p, int pcolor)
{
	int hilite = pcolor & 0xF000; /* highlight flag  (MSB) */
	int bright = pcolor & 0xFF; /* mask out albedo (7 bits) */
	int hue = (pcolor & 0x0F00) >> 4; /* 16 * basis color */
	signed int color;

	switch(highest_color)
	{
		case 15:
			{
				if (hue == 0) return ((bright & 15) | hilite); /* abs. color */

				if ((pcolor & 0x3000) == 0) /* fixed (unlit) color */
				{
					if (bright > 15) bright = 15;
					return (hilite | bright);
				}

				color = poly_cosine(p);

				if (pcolor & 0x2000) /* develop offset for metal/glass cycle */
				{
					color = (bright >> 6) - (color >> 5) + ((hue+320) >> 6);
					if (color < 0) color = 0;
					if (color > 15) color = 15;
					return (hilite | color);
				}
				/* compute brightness index */
				if (color < 0) color = 0;

				color = (( ((color*(128-ambient_light)) >> 7) + ambient_light)
					* (bright>>1) );
				color = ((color>>5)*((hue+768) >> 4))/2300;

				if (color < 0) return( hilite );
				if (color > 15) return (15 | hilite);
				return (color | hilite);
			}

		case 255:
			{
				if ((pcolor & 0x3000) == 0) /* fixed (unlit) color */
					return hue ? (hilite | hue | ((bright >> 4) & 0x0F)) : (bright | hilite);
	
				color = poly_cosine(p);
	
				if (pcolor & 0x2000) /* develop offset for metal/glass cycle */
				{
					color = (-(color >> 1)) + bright >> 3;
					color = (color & 16) ? (color & 15) | 0x100 : color & 15;
					return (hilite | hue | color);
				}/* compute brightness index */
	
				if (color < 0) color = 0;
				color = (( ((color*(128-ambient_light)) >> 7) + ambient_light)
					* (bright >> 1) ) / 0x440;
				if (color < 1) /* absolute zero: black */
					return (hilite & 0x2000) ? (hilite | hue) : hilite;
				if (color > 15)
					return (15 | hue | hilite);
				return (color | hue | hilite);
			}
	
		default:
			return pcolor;
	}
}
