/* Routines to initialize math tables for greater speed later on.
   Part of the REND386 package by Dave Stampe and Bernie Roehl.
 */

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

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "rend386.h"
#include "intmath.h"

/* this stuff moved out of integer core so that there are
   no uncompilable TC references in integer core library */

#define XFSC 536870912   /* 2**29 for shifting xform coeffs to long */
static float xfsc = XFSC;

long sintable[258];
long atantable[258];

fill_sine()
{
	int i;

	for (i = 0; i < 256; i++)
		sintable[i] = (XFSC * sin(3.14159/2/256 * i));
	sintable[256] = XFSC;
	sintable[257] = XFSC;

	for (i = 0; i < 256; i++)
		atantable[i] = 180.0/3.14159*65536.0 * atan(i/256.0);
	atantable[256] = atantable[257] = 45*65536L;

	return 0;
}


/* tables for sphere object clipping:   */

long sclip_C[800]; /* 1/sqrt(zoom^2 + 1) table   		*/
long sclip_M[800]; /* zoom * C table  (table: i = 32*zoom) */

/* range: FOV = 2*atan(1/zoom)          */
/* or about 150 to 7 degrees 		*/

fill_sclip()
{
	int i;
	float n;

	for (i = 0; i < 800; i++)
	{
		n = 1.0/sqrt((i/16.0)*(i/16.0) + 1);
		sclip_C[i] = XFSC * n;
		sclip_M[i] = XFSC * ((i/16.0) * n) ;
	}
	return 0;
}

int sqrtable[1024];

fill_sqrt()
{
	int i;

	for (i = 0; i < 1024; i++)
		sqrtable[i] = 1024*sqrt(i);
	return 0;
}


long slow_magnitude(long a, long b) /* done the float way */
{
	float x = a;
	float y = b;

	return sqrt(x*x + y*y);
}


/*  m[0][0] = cos(rz)*cos(ry) + sin(rz)*sin(rx)*sin(ry) */
/*  m[0][1] = -sin(rz)*cos(rx);  */
/*  m[0][2] = cos(rz)*sin(ry) + sin(rz)*sin(rx)*cos(ry); */
/*  m[1][0] = sin(rz)*cos(ry) - cos(rz)*sin(rx)*sin(ry); */
/*  m[1][1] = cos(rz)*cos(rx);   */
/*  m[1][2] = -sin(rz)*sin(ry) - cos(rz)*sin(rx)*cos(ry); */
/*  m[2][0] = cos(rx)*sin(ry); */
/*	m[2][1] = sinx;              */
/*  m[2][2] = cos(rx)*cos(ry) ;  */

/* this uses float, so use only where speed is not important */
#define XFLC 536870912.0
#define XRLC 3754939.378


/* makes matrix that will xform Z axis to given vector */
void vector_to_matrix(MATRIX m, long x, long y, long z)
{
	float ya = atan2(x, z);
	float xa = -asin(y/sqrt((float)x*x+(float)y*y+(float)z*z));

	std_matrix(m, xa*XRLC, ya*XRLC, 0, 0, 0, 0);
}


static void setlength(long length, long *x, long *y, long *z)
{
	float fx = *x;
	float fy = *y;
	float fz = *z;
	float d = length/sqrt(fx*fx + fy*fy + fz*fz);
	*x = d*fx;
	*y = d*fy;
	*z = d*fz;
}

void fix_matrix_scale(MATRIX m) /* slow but sure: do once every 1000 matrix mults */
{
	setlength(XFLC, &m[0][0], &m[0][1], &m[0][2]);
	setlength(XFLC, &m[1][0], &m[1][1], &m[1][2]);
	setlength(XFLC, &m[2][0], &m[2][1], &m[2][2]);
	setlength(XFLC, &m[0][0], &m[1][0], &m[2][0]);
	setlength(XFLC, &m[0][1], &m[1][1], &m[2][1]);
	setlength(XFLC, &m[0][2], &m[1][2], &m[2][2]);
}
