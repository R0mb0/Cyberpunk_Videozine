/* Matrix math, assembly by Dave Stampe */

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

/* Contact: broehl@sunee.waterloo.edu or dstampe@sunee.waterloo.edu */

#pragma inline

#include <mem.h>   /* memcpy() */

#include "3dstruct.h"

#define XFSC 536870912   /* 2**29 for shifting xform coeffs to long */

/*************** TRIGNOMETRIC FUNCTIONS *****************/

/* (from inttrig.c) */

extern long isine(long x);
extern long icosine(long x);
extern long arcsine(long x);
extern long arccosine(long x);
extern long arctan2(long y, long x);

/***************** MATRIX-VECTOR OPERATIONS **************/

				/* rotate/translate XYZ by matrix */

void matrix_point(MATRIX m, long *xp, long *yp, long *zp)
{
 long x = *xp;
 long y = *yp;
 long z = *zp;

 long xr,yr,zr;

 asm {
	.386
	push	si
	push	di
	push	cx
	push	dx
	les	di,DWORD PTR m

	mov	eax,es:[di]
	imul	DWORD PTR x
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,es:[di+4]
	imul	DWORD PTR y
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[di+8]
	imul	DWORD PTR z
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,es:[di+36]
	mov	xr,eax

	mov	eax,es:[di+12]
	imul	DWORD PTR x
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,es:[di+16]
	imul	DWORD PTR y
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[di+20]
	imul	DWORD PTR z
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,es:[di+40]
	mov	yr,eax

	mov	eax,es:[di+24]
	imul	DWORD PTR x
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,es:[di+28]
	imul	DWORD PTR y
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[di+32]
	imul	DWORD PTR z
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,es:[di+44]
	mov	zr,eax

	pop	dx
	pop	cx
	pop	di
	pop	si
		 }

 *xp = xr;
 *yp = yr;
 *zp = zr;
}

				/* rotate XYZ by matrix */

void matrix_rotate(MATRIX m, long *xp, long *yp, long *zp)
{
 long x = *xp;
 long y = *yp;
 long z = *zp;

 long xr,yr,zr;

 asm {
	.386
	push	si
	push	di
	push	cx
	push	dx
	les	di,DWORD PTR m

	mov	eax,es:[di]
	imul	DWORD PTR x
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,es:[di+4]
	imul	DWORD PTR y
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[di+8]
	imul	DWORD PTR z
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,0
	mov	xr,eax

	mov	eax,es:[di+12]
	imul	DWORD PTR x
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,es:[di+16]
	imul	DWORD PTR y
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[di+20]
	imul	DWORD PTR z
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,0
	mov	yr,eax

	mov	eax,es:[di+24]
	imul	DWORD PTR x
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,es:[di+28]
	imul	DWORD PTR y
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[di+32]
	imul	DWORD PTR z
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,0
	mov	zr,eax

	pop	dx
	pop	cx
	pop	di
	pop	si
      }

 *xp = xr;
 *yp = yr;
 *zp = zr;
}



/******************** MISC. VECTOR MATH ****************/

		/* replaces column N of a matrix with cross of other 2 */
		/* used to speed computations, repair matrix scaling   */

void cross_column(MATRIX m, int col)
{
 long x, y, z;
 long x1, y1, z1, x2, y2, z2;

 switch (col)
  {
   case 0:
    x1 = m[0][1];
    y1 = m[1][1];
    z1 = m[2][1];
    x2 = m[0][2];
    y2 = m[1][2];
    z2 = m[2][2];
    break;

   case 1:
    x1 = m[0][2];
    y1 = m[1][2];
    z1 = m[2][2];
    x2 = m[0][0];
    y2 = m[1][0];
    z2 = m[2][0];
    break;

   case 2:
    x1 = m[0][0];
    y1 = m[1][0];
    z1 = m[2][0];
    x2 = m[0][1];
    y2 = m[1][1];
    z2 = m[2][1];
    break;
  }

 asm {
	push	dx
	push	si
	push	di

	mov	eax,y1        /* compute cross product */
	mov	edx,z2
	imul	edx
	mov	edi,edx
	mov	esi,eax
	mov	eax,y2
	mov	edx,z1
	imul	edx
	sub	esi,eax
	sbb	edi,edx
	shrd	esi,edi,29
	adc	esi,0
	mov	x,esi

	mov	eax,z1
	mov	edx,x2
	imul	edx
	mov	edi,edx
	mov	esi,eax
	mov	eax,z2
	mov	edx,x1
	imul	edx
	sub	esi,eax
	sbb	edi,edx
	shrd	esi,edi,29
	adc	esi,0
	mov	y,esi

	mov	eax,x1
	mov	edx,y2
	imul	edx
	mov	edi,edx
	mov	esi,eax
	mov	eax,x2
	mov	edx,y1
	imul	edx
	sub	esi,eax
	sbb	edi,edx
	shrd	esi,edi,29
	adc	esi,0
	mov	z,esi

	pop	di
	pop	si
	pop	dx
     }


 switch (col)
  {
   case 0:
    m[0][0] = x;
    m[1][0] = y;
    m[2][0] = z;
    break;

   case 1:
    m[0][1] = x;
    m[1][1] = y;
    m[2][1] = z;
    break;

   case 2:
    m[0][2] = x;
    m[1][2] = y;
    m[2][2] = z;
    break;
  }
}


long m_mult(long a, long b)    /* perform mult. by matrix element         */
{                              /* where either a or b is in <3.29> format */
 long result;

 asm {
	push	edx
	mov	eax,DWORD PTR a
	imul	DWORD PTR b
	shrd	eax,edx,29
	adc	eax,0
	mov	DWORD PTR result,eax
	pop	edx
     }
 return result;
}


long dot_prod_29(long a, long b, long c, long x, long y, long z)
{
 /* computes (Ax + By + Cz)>>29 */

 long result;

 asm {
	push	si
	push	di

	mov	eax,a
	imul	DWORD PTR x
	mov	esi,eax
	mov	edi,edx

	mov	eax,b
	imul	DWORD PTR y
	add	esi,eax
	adc	edi,edx

	mov	eax,c
	imul	DWORD PTR z
	add	esi,eax
	adc	edi,edx

	shrd	esi,edi,29
	adc	esi,0
	mov	result,esi

	pop	di
	pop	si
     }
 return result;
}

/****************** MATRIX MANIPULATION ***************/


void matrix_mult(MATRIX a, MATRIX b, MATRIX c)
{
	long r1,r2,r3,r4,r5,r6,r7,r8,r9;

 asm {
	.386                	/* 3x3 section of matrixs: A*B->C       */
	push	ds              /* now gets z column from cross product */
	push	si
	push	di
	push	cx
	push	dx

	les	si,DWORD PTR a
	lds	di,DWORD PTR b

	mov	eax,es:[si]
	imul	DWORD PTR ds:[di]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+4]
	imul	DWORD PTR ds:[di+12]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+8]
	imul	DWORD PTR ds:[di+24]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r1,ebx

	mov	eax,es:[si]
	imul	DWORD PTR ds:[di+4]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+4]
	imul	DWORD PTR ds:[di+16]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+8]
	imul	DWORD PTR ds:[di+28]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r2,ebx

#ifndef CROSS_Z
	mov	eax,es:[si]
	imul	DWORD PTR ds:[di+8]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+4]
	imul	DWORD PTR ds:[di+20]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+8]
	imul	DWORD PTR ds:[di+32]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r3,ebx
#endif

	mov	eax,es:[si+12]
	imul	DWORD PTR ds:[di]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+16]
	imul	DWORD PTR ds:[di+12]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+20]
	imul	DWORD PTR ds:[di+24]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r4,ebx

	mov	eax,es:[si+12]
	imul	DWORD PTR ds:[di+4]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+16]
	imul	DWORD PTR ds:[di+16]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+20]
	imul	DWORD PTR ds:[di+28]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r5,ebx

#ifndef CROSS_Z
	mov	eax,es:[si+12]
	imul	DWORD PTR ds:[di+8]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+16]
	imul	DWORD PTR ds:[di+20]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+20]
	imul	DWORD PTR ds:[di+32]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r6,ebx
#endif

	mov	eax,es:[si+24]
	imul	DWORD PTR ds:[di]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+28]
	imul	DWORD PTR ds:[di+12]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+32]
	imul	DWORD PTR ds:[di+24]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r7,ebx

	mov	eax,es:[si+24]
	imul	DWORD PTR ds:[di+4]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+28]
	imul	DWORD PTR ds:[di+16]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+32]
	imul	DWORD PTR ds:[di+28]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r8,ebx

#ifndef CROSS_Z
	mov	eax,es:[si+24]
	imul	DWORD PTR ds:[di+8]
	mov	ebx,eax
	mov	ecx,edx
	mov	eax,es:[si+28]
	imul	DWORD PTR ds:[di+20]
	add	ebx,eax
	adc	ecx,edx
	mov	eax,es:[si+32]
	imul	DWORD PTR ds:[di+32]
	add	ebx,eax
	adc	ecx,edx
	shrd	ebx,ecx,29
	adc	ebx,0
	mov	r9,ebx
#endif

#ifdef CROSS_Z
	mov	eax,r4        /* compute cross product of  */
	mov	edx,r8        /* columns 1&2 to get col. 3 */
	imul	edx
	mov	edi,edx
	mov	esi,eax
	mov	eax,r5
	mov	edx,r7
	imul	edx
	sub	esi,eax
	sbb	edi,edx
	shrd	esi,edi,29
	adc	esi,0
	mov     r3,esi

	mov	eax,r7
	mov	edx,r2
	imul	edx
	mov	edi,edx
	mov	esi,eax
	mov	eax,r8
	mov	edx,r1
	imul	edx
	sub	esi,eax
	sbb	edi,edx
	shrd	esi,edi,29
	adc	esi,0
	mov     r6,esi

	mov	eax,r1
	mov	edx,r5
	imul	edx
	mov	edi,edx
	mov	esi,eax
	mov	eax,r2
	mov	edx,r4
	imul	edx
	sub	esi,eax
	sbb	edi,edx
	shrd	esi,edi,29
	adc	esi,0
	mov     r9,esi
#endif

	les	di,DWORD PTR c
	mov	eax,r1
	mov	es:[di],eax
	mov	eax,r2
	mov	es:[di+4],eax
	mov	eax,r4
	mov	es:[di+12],eax
	mov	eax,r5
	mov	es:[di+16],eax
	mov	eax,r7
	mov	es:[di+24],eax
	mov	eax,r8
	mov	es:[di+28],eax
	mov	eax,r3
	mov	es:[di+8],eax
	mov	eax,r6
	mov	es:[di+20],eax
	mov	eax,r9
	mov	es:[di+32],eax

	pop	dx
	pop	cx
	pop	di
	pop	si
	pop	ds
	}

}

		 /* full homogenous matrix multiply */

void matrix_product(MATRIX a, MATRIX b, MATRIX c)
{
 MATRIX d;
 long x, y, z;
 matrix_mult(a, b, d);
 x = b[3][0];
 y = b[3][1];
 z = b[3][2];
 matrix_point(a, &x, &y, &z);
 d[3][0] = x;
 d[3][1] = y;
 d[3][2] = z;
 memcpy (c, &d, sizeof(MATRIX));
}


void matrix_transpose(MATRIX a, MATRIX b)
{
 long s;

	b[0][0] = a[0][0];     /* generate inverse of rotate matrix (transpose) */
	b[1][1] = a[1][1];     /* ONLY WORKS FOR ORTHOGONAL MATRICES            */
	b[2][2] = a[2][2];     /* will do self_transpose as well as copy */

	s = a[0][1];
	b[0][1] = a[1][0];
	b[1][0] = s;

	s = a[2][0];
	b[2][0] = a[0][2];
	b[0][2] = s;

	s = a[2][1];
	b[2][1] = a[1][2];
	b[1][2] = s;
}


void inverse_matrix(MATRIX a, MATRIX b)
{
	long x = -a[3][0];       /* generate inverse of    */
	long y = -a[3][1];       /* full homogenous matrix */
	long z = -a[3][2];

	matrix_transpose(a,b);
				/* old: Ax+b = c      */
	b[3][0] = 0;            /* b' = (1/A)(-b)     */
	b[3][1] = 0;           	/* (1/A) = t(A)       */
	b[3][2] = 0;           	/* new: (1/A)c+b' = x */

	matrix_point(b,&x,&y,&z);

	b[3][0] = x;
	b[3][1] = y;
	b[3][2] = z;
}



void identity_matrix(MATRIX m)
{
 int i, j;

 m[0][0] = m[1][1] = m[2][2] = XFSC;
 m[1][0] = m[2][0] = m[3][0] = 0;
 m[0][1] = m[2][1] = m[3][1] = 0;
 m[0][2] = m[1][2] = m[3][2] = 0;
}

			/* copy 3x4 matrix */

void matrix_copy(MATRIX m, MATRIX n)
{
 memcpy (n, m, sizeof(MATRIX));
}

			/* copy 3x3 rotation part of matrix */

void matrix_rot_copy(MATRIX m, MATRIX n)
{
 memcpy (n, m, sizeof(MATRIX));
 n[3][0] = n[3][1] = n[3][2] = 0;
}



/*************** ANGLE/POSITION TO HOMOGENOUS MATRIX ************/


#define RXYZ 1		/* matrix rotation types */
#define RYXZ 0          /* ONLY RYXZ guaranteed to be tested */
#define RXZY 2
#define RZYX 5
#define RZXY 4
#define RYZX 6                       /* create rotation/translation */
				     /* "matrix" from angle data    */

void multi_matrix(MATRIX m, long rx, long ry, long rz,
		  long tx, long ty, long tz, int type )
{
 long sinx,cosx,siny,cosy,sinz,cosz;
 long result;

 if (rx == 0)            /* tests for single-axis rotates */
  {                   /* much faster to directly make  */
   if (ry == 0)
    {
     identity_matrix(m);
     if (rz != 0)
      {
       m[0][0] = m[1][1] = icosine(rz);
       m[1][0] = isine(rz);
       m[0][1] = -m[1][0];
      }
     goto shortcut;
    }
   else if (rz == 0)
    {
     identity_matrix(m);
     m[0][0] = m[2][2] = icosine(ry);
		 m[0][2] = isine(ry);
     m[2][0] = -m[0][2];
     goto shortcut;
    }
  }
 else if (ry == 0 && rz == 0)
	{
   identity_matrix(m);
   m[1][1] = m[2][2] = icosine(rx);
   m[2][1] = isine(rx);
   m[1][2] = -m[2][1];
   goto shortcut;
  }

 cosx = icosine(rx);          /* angle compute */
 cosy = icosine(ry);
 cosz = icosine(rz);
 sinx = isine(rx);
 siny = isine(ry);
 sinz = isine(rz);

 asm {
	.386
	push	si
	push	di
	push	cx
	push	dx
     }


 if (type & 4)		      /* negate angles? */
  asm {
	neg	DWORD PTR sinx
	neg	DWORD PTR siny
	neg	DWORD PTR sinz
      }

 switch (type & 3)
  {
	 case RXYZ:
    {
      asm {
	mov	eax,cosz
	imul	DWORD PTR cosy
	shrd	eax,edx,29
	adc	eax,0
	mov	result,eax
	 }
      m[0][0] = result;

     asm {
	mov	eax,cosx
	imul	DWORD PTR sinz
	shrd	eax,edx,29
	adc	eax,0
	mov	ecx,eax
	mov	eax,cosz
	imul	DWORD PTR sinx
	shrd	eax,edx,29
	adc	eax,0
	imul	DWORD PTR siny
	shrd	eax,edx,29
	adc	ecx,eax
	mov	result,ecx
	 }
      m[1][0] = result;

     asm {
	mov	eax,sinz
	imul	DWORD PTR sinx
	shrd	eax,edx,29
	adc	eax,0
	mov	ecx,eax
	mov	eax,cosz
	imul	DWORD PTR cosx
	shrd	eax,edx,29
	adc	eax,0
	imul	DWORD PTR siny
	shrd	eax,edx,29
	adc	eax,0
	sub	ecx,eax
	mov	result,ecx
	 }
      m[2][0] = result;

      m[0][2] = siny;

      asm {
	mov	eax,cosy
	imul	DWORD PTR sinx
	shrd	eax,edx,29
	adc	eax,0
	neg	eax
	mov	result,eax
	 }
      m[1][2] = result;

      asm {
	mov	eax,cosx
	imul	DWORD PTR cosy
	shrd	eax,edx,29
	adc	eax,0
	mov	result,eax
	 }
			m[2][2] = result;

      cross_column(m,1);
      break;
    }

   case RYXZ:
    {
     asm {
	mov	eax,cosz
	imul	DWORD PTR cosy
	shrd	eax,edx,29
	adc	eax,0
	mov	ecx,eax
	mov	eax,sinz
	imul	DWORD PTR sinx
	shrd	eax,edx,29
	adc	eax,0
	imul	DWORD PTR siny
	shrd	eax,edx,29
	adc	ecx,eax
	mov	result,ecx
	 }
      m[0][0] = result;

      asm {
	mov	eax,cosx
	imul	DWORD PTR sinz
	shrd	eax,edx,29
	adc	eax,0
	mov	result,eax
	 }
      m[1][0] = result;

		 asm {
	mov	eax,cosy
	imul	DWORD PTR sinz
	shrd	eax,edx,29
	adc	eax,0
	imul	DWORD PTR sinx
	shrd	eax,edx,29
	adc	eax,0
	mov	ecx,eax
	mov	eax,cosz
	imul	DWORD PTR siny
	shrd	eax,edx,29
	adc	eax,0
	sub	ecx,eax
	mov	result,ecx
	 }
      m[2][0] = result;

      asm {
	mov	eax,cosx
	imul	DWORD PTR siny
	shrd	eax,edx,29
	adc	eax,0
	mov	result,eax
	 }
      m[0][2] = result;

      m[1][2] = -sinx;

      asm {
	mov	eax,cosx
	imul	DWORD PTR cosy
	shrd	eax,edx,29
	adc	eax,0
	mov	result,eax
	 }
      m[2][2] = result;

      cross_column(m,1);
      break;
    }

   case RXZY:
    {
      asm {
	mov	eax,cosz
	imul	DWORD PTR cosy
	shrd	eax,edx,29
	adc	eax,0
	mov	result,eax
	 }
      m[0][0] = result;

     asm {
	mov	eax,sinx
	imul	DWORD PTR siny
	shrd	eax,edx,29
	adc	eax,0
	mov	ecx,eax
	mov	eax,cosx
	imul	DWORD PTR cosy
	shrd	eax,edx,29
	adc	eax,0
	imul	DWORD PTR sinz
	shrd	eax,edx,29
	adc	ecx,eax
	mov	result,ecx
	 }
      m[1][0] = result;

     asm {
	mov	eax,cosy
	imul	DWORD PTR sinz
	shrd	eax,edx,29
	adc	eax,0
	imul	DWORD PTR sinx
	shrd	eax,edx,29
	adc	eax,0
	mov	ecx,eax
	mov	eax,cosx
	imul	DWORD PTR siny
	shrd	eax,edx,29
	adc	eax,0
	sub	ecx,eax
	mov	result,ecx
	 }
      m[2][0] = result;

      m[0][1] = -sinz;

      asm {
	mov	eax,cosz
	imul	DWORD PTR cosx
	shrd	eax,edx,29
	adc	eax,0
	mov	result,eax
	 }
      m[1][1] = result;

			asm {
	mov	eax,cosz
	imul	DWORD PTR sinx
	shrd	eax,edx,29
	adc	eax,0
	mov	result,eax
	 }
      m[2][1] = result;

      cross_column(m,2);
      break;
    }
  }

 asm {
	pop	dx
	pop	cx
	pop	di
	pop	si
     }

 if (type & 4) matrix_transpose(m,m);

shortcut:
 m[3][0] = tx;
 m[3][1] = ty;
 m[3][2] = tz;
}

		/* the default matrix: RYXZ  */
		/* used for camera transform */

void std_matrix(MATRIX m, long rx, long ry, long rz,
	long tx, long ty, long tz)
{
 multi_matrix(m, rx, ry, rz, tx, ty, tz, RYXZ);
}


/*************** MATRIX-TO-ANGLES (RYXZ ONLY) *************/


extern long slow_magnitude(long a, long b);  /* done the float way */

void matrix_to_angle(MATRIX m, long *rx, long *ry, long *rz)
{
 long t,p,a;
 long c2;

 if (m[1][2] > 536334041 || m[1][2] < -536334041)
  {
   c2 = slow_magnitude(m[0][2],m[2][2]);    /* need accuracy for this one */
   if (c2 > 2000000)
    {
     p = arccosine(c2);
		 if (m[1][2] < 0) p = -p;
    }
   else
    {
/*
     t = (m[1][2] < 0) ? 90*65536L : -90*65536L;
     p = 0;
     a = arctan2(m[0][1], m[0][0]);
*/
     t = (m[1][2] < 0) ? 90*65536L : -90*65536L;  /* works with Z-axis rule */
     a = 0;
     p = arccosine(m[1][0]);
     if (m[1][2] > 0) p = -p;

     goto assign;
    }
  }
 else p = -arcsine(m[1][2]);

 t = arctan2(m[0][2], m[2][2]);
 a = arctan2(m[1][0], m[1][1]);

assign:

 *ry = t;
 *rx = p;
 *rz = a;
}

