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

	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
 */

#pragma inline

#include <stdio.h>
#include <stdlib.h>  /* strtoul() */
#include <dos.h>
#include <ctype.h>   /* isdigit(), isalnum() */
#include <string.h>  /* strnicmp() */
#include "3dstruct.h"	/* for POLY struct */
#include "rend386.h"

extern void load_DAC_colors(void *ptr, int high, int bwflag);

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
 if (screen_clear_color==-1 && sky_color!=-1) screen_clear_color=sky_color;
 if (screen_clear_color!=-1 && sky_color==-1) sky_color=screen_clear_color;
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

int ambient_light = 76;

int light1_i = 51;
long light1_x, light1_y, light1_z;
int light1_s = 0;

int light2_i = 0;
long light2_x, light2_y, light2_z;
int light2_s = 0;

SEGMENT *light_seg  = NULL;
SEGMENT *light_seg2  = NULL;

int user_poly_color(POLY *p, int pcolor, long maxz)
{
 int hilite = pcolor & 0xF000; /* highlight flag  (MSB) */
 int bright = pcolor & 0xFF; /* mask out albedo (7 bits) */
 int hue = (pcolor & 0x0F00) >> 4; /* 16 * basis color */
 signed int color, color1, color2;

 switch(highest_color)
  {
   case 15:
    {
     if (hue == 0) return ((bright & 15) | hilite); /* abs. color */

     if ((pcolor & 0x3000) == 0 || p->npoints<3) /* fixed (unlit) color */
      {
       if (bright > 15) bright = 15;
       return (hilite | bright);
      }

     if (pcolor & 0x2000) /* develop offset for metal/glass cycle */
      {
       color = poly_cosine(p, light1_x, light1_y, light1_z, light1_s);
       color = (bright >> 6) - (color >> 5) + ((hue+320) >> 6);
       if (color < 0) color = 0;
       if (color > 15) color = 15;
       return (hilite | color);
      }
				/* compute brightness index */
     color1 = color2 = 0;
     if(light1_i) color1 = poly_cosine(p, light1_x, light1_y, light1_z, light1_s);
     if(light2_i) color2 = poly_cosine(p, light2_x, light2_y, light2_z, light2_s);
     if (color1 < 0) color1 = 0;
     if (color2 < 0) color2 = 0;

/*     color = (( ((color*(128-ambient_light)) >> 7) + ambient_light)
		* (bright>>1) );
     color = ((color>>5)*((hue+768)>>4))>>11;  */

     asm {
	.386
	mov	ax,color1
	mul	byte ptr light1_i
	mov	bx,ax
	mov	ax,color2
	mul	byte ptr light2_i
	add	ax,bx
	shr	ax,7
	add	ax,ambient_light
	mul	byte ptr bright
	shr	ax,6
	mov	bx,hue
	add	bx,768
	shr	bx,4
	mul     bx
	shr	ax,11
	mov	color,ax
	 }

     if (color <= 0) return( hilite );
     if (color > 15) return (15 | hilite);
     return (color | hilite);
    }

   case 255:
    {
     if ((pcolor & 0x3000) == 0 || p->npoints<3) /* fixed (unlit) color */
     return hue ? (hilite | hue | ((bright >> 4) & 0x0F)) : (bright | hilite);

     if (pcolor & 0x2000) 	/* develop offset for metal/glass cycle */
      {
     color = poly_cosine(p, light1_x, light1_y, light1_z, light1_s);

/*       color = (-(color >> 1)) + bright >> 3;
       color = (color & 16) ? (color & 15) | 0x100 : color & 15;  */

       asm {
	mov	ax,color
	shl	ax,1
	sub	ax,bright
	neg	ax
	sar	ax,4
	mov	ah,al
	shr	ah,4
	and	ax,010Fh
	mov	color,ax
	   }

       return (hilite | hue | color);
      }				/* compute brightness index */
     color1 = color2 = 0;
     if(light1_i) color1 = poly_cosine(p, light1_x, light1_y, light1_z, light1_s);
     if(light2_i) color2 = poly_cosine(p, light2_x, light2_y, light2_z, light2_s);
     if (color1 < 0) color1 = 0;
     if (color2 < 0) color2 = 0;

     asm {
	mov	ax,color1
	mul	byte ptr light1_i
	mov	bx,ax
	mov	ax,color2
	mul	byte ptr light2_i
	add	ax,bx
	shr	ax,7
	add	ax,ambient_light
	mul	byte ptr bright
	shr	ax,11
	mov	color,ax
	 }

/*     color = (( ((color*light_1+color*light_2) >> 7) + ambient_light)
		* (bright >> 1) ) >>10;
     color = (( ((color*(128-ambient_light)) >> 7) + ambient_light)
		* (bright >> 1) ) >>10;           */

     if (color < 1) /* absolute zero: black */
	  return (hilite & 0x2000) ? (hilite | hue) : hilite;
     if (color > 15) return (15 | hue | hilite);
     return (color | hue | hilite);
    }

   default:
    return pcolor;
  }
}

unsigned convert_color(char *s, char **ptr)
	{
	int hue, value;
	if (isdigit(*s)) return (unsigned) strtoul(s, ptr, 0);
	if (ptr) for (*ptr = s; isalnum(**ptr) || **ptr == '_'; ++*ptr);
	if (!strnicmp(s, "shaded", 6)) {
		sscanf(s, "shaded_%d_%d", &hue, &value);
		return 0x1000 | ((hue & 0x0F) << 8) | (value & 0xFF);
		}
	else if (!strnicmp(s, "metal", 5)) {
		sscanf(s, "metal_%d_%d", &hue, &value);
		return 0x2000 | ((hue & 0x0F) << 8) | ((value & 0x1F) << 3);
		}
	else if (!strnicmp(s, "glass", 5)) {
		sscanf(s, "glass_%d_%d", &hue, &value);
		return 0x3000 | ((hue & 0x0F) << 8) | ((value & 0x1F) << 3);
		}
	return 0;
	}

