/* Routines for moving, scaling and rotating objects */
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

#include <stdio.h>
#include "3dstruct.h"

#define XFSC 536870912   /* 2**29 for shifting xform coeffs to long */

/*************** TRIGNOMETRIC FUNCTIONS *****************/

/* (from inttrig.c) */

extern long isine(long x);
extern long icosine(long x);
extern long arcsine(long x);
extern long arccosine(long x);
extern long arctan2(long y, long x);

/*************** MATRIX MANIPULATION *****************/

/* (from matrix.c) */

#define RXYZ 1		/* matrix rotation types */
#define RYXZ 0          /* ONLY RYXZ guaranteed to be tested */
#define RXZY 2
#define RZYX 5
#define RZXY 4
#define RYZX 6

extern void matrix_point(MATRIX m, long *xp, long *yp, long *zp);
extern void matrix_rotate(MATRIX m, long *xp, long *yp, long *zp);
extern void cross_column(MATRIX m, int col);
extern long m_mult(long a, long b);    /* perform mult. by matrix element */
extern long dot_prod_29(long a, long b, long c, long x, long y, long z);
extern void matrix_mult(MATRIX a, MATRIX b, MATRIX c);
extern void matrix_product(MATRIX a, MATRIX b, MATRIX c);
extern void matrix_transpose(MATRIX a, MATRIX b);
extern void inverse_matrix(MATRIX a, MATRIX b);
extern void identity_matrix(MATRIX m);
extern void matrix_copy(MATRIX m, MATRIX n);
extern void matrix_rot_copy(MATRIX m, MATRIX n);

		       /* create rotation/translation */
		       /* "matrix" from angle data    */

/******************** APPLY MATRIX TO OBJECTS **************/

void matmove_rep(REP *rep, MATRIX m)
{
 int i;
 VERTEX *v = rep->verts;     /* use "matrix" to rotate then translate */
 POLY   *p = rep->polys;
 int vs = sizeof(VERTEX);
 int ps = sizeof(POLY);
 int vc = rep->nverts;
 int pc = rep->npolys;
 long rx,ry,rz;

 asm {
	.386
	push	ds
	push	si
	push	di
	push	cx
	push	dx
	lds	si,DWORD PTR m

	les	di,DWORD PTR v   /* rotate/translate all vertices */
      }
vconv:
 asm {
	mov	eax,ds:[si]
	imul	DWORD PTR es:[di].(VERTEX)ox
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+4]
	imul	DWORD PTR es:[di].(VERTEX)oy
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+8]
	imul	DWORD PTR es:[di].(VERTEX)oz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,ds:[si+36]
	mov	es:[di].(VERTEX)x,eax

	mov	eax,ds:[si+12]
	imul	DWORD PTR es:[di].(VERTEX)ox
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+16]
	imul	DWORD PTR es:[di].(VERTEX)oy
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+20]
	imul	DWORD PTR es:[di].(VERTEX)oz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,ds:[si+40]
	mov	es:[di].(VERTEX)y,eax

	mov	eax,ds:[si+24]
	imul	DWORD PTR es:[di].(VERTEX)ox
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+28]
	imul	DWORD PTR es:[di].(VERTEX)oy
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+32]
	imul	DWORD PTR es:[di].(VERTEX)oz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,ds:[si+44]
	mov	es:[di].(VERTEX)z,eax

	add	di,vs
	dec     WORD PTR vc
	jz      vconve
	jmp	vconv
     }
vconve:
 asm {
	les	di,DWORD PTR p      /* rotate all normals */
     }
pconv:
 asm {
	mov	eax,ds:[si]
	imul	DWORD PTR es:[di].(POLY)onormalx
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+4]
	imul	DWORD PTR es:[di].(POLY)onormaly
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+8]
	imul	DWORD PTR es:[di].(POLY)onormalz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,0
	mov	es:[di].(POLY)normalx,eax

	mov	eax,ds:[si+12]
	imul	DWORD PTR es:[di].(POLY)onormalx
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+16]
	imul	DWORD PTR es:[di].(POLY)onormaly
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+20]
	imul	DWORD PTR es:[di].(POLY)onormalz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,0
	mov	es:[di].(POLY)normaly,eax

	mov	eax,ds:[si+24]
	imul	DWORD PTR es:[di].(POLY)onormalx
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+28]
	imul	DWORD PTR es:[di].(POLY)onormaly
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+32]
	imul	DWORD PTR es:[di].(POLY)onormalz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,0
	mov	es:[di].(POLY)normalz,eax

	add	di,ps
	dec     WORD PTR pc
	jz      pconve
	jmp	pconv
			}
pconve:
 asm {
	pop	dx
	pop	cx
	pop	di
	pop	si
	pop	ds
		 }

 rep->update_count++;
}


void matmove_osphere(OBJECT *obj, MATRIX m)
{
 asm {                            /* rotate/translate sphere center */
	.386
	push	ds
	push	si
	push	di
	push	cx
	push	dx
	lds	si,DWORD PTR m

	les	di,DWORD PTR obj
	mov	eax,ds:[si]
	imul	DWORD PTR es:[di].(OBJECT)osphx
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+4]
	imul	DWORD PTR es:[di].(OBJECT)osphy
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+8]
	imul	DWORD PTR es:[di].(OBJECT)osphz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,ds:[si+36]
	mov	es:[di].(OBJECT)sphx,eax

	mov	eax,ds:[si+12]
	imul	DWORD PTR es:[di].(OBJECT)osphx
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+16]
	imul	DWORD PTR es:[di].(OBJECT)osphy
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+20]
	imul	DWORD PTR es:[di].(OBJECT)osphz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,ds:[si+40]
	mov	es:[di].(OBJECT)sphy,eax

	mov	eax,ds:[si+24]
	imul	DWORD PTR es:[di].(OBJECT)osphx
	mov	ecx,edx
	mov	ebx,eax
	mov	eax,ds:[si+28]
	imul	DWORD PTR es:[di].(OBJECT)osphy
	add	ebx,eax
	adc	ecx,edx
	mov	eax,ds:[si+32]
	imul	DWORD PTR es:[di].(OBJECT)osphz
	add	eax,ebx
	adc	edx,ecx
	shrd	eax,edx,29
	adc	eax,ds:[si+44]
	mov	es:[di].(OBJECT)sphz,eax

	pop	dx
	pop	cx
	pop	di
	pop	si
	pop	ds
		 }

 obj->update_count++;
}
															/* works as if only current rep existed */

void apply_matrix(OBJECT *obj, MATRIX m)
{
 REP *rep = obj->current_rep;
 if(rep==NULL) return;

 matmove_osphere(obj, m);
 matmove_rep(rep, m);
 obj->update_count++;
 rep->update_count++;
}


				 /* used to compute floor/ceiling of areas */

long plane_y(long a, long b, long c, long d, long x, long z)
{
 /* computes (Ax + Cz + D)/-B */

 long result;

 asm {
	push	si
	push	di

	mov	eax,a
	imul	DWORD PTR x
	mov	esi,eax
	mov	edi,edx

	mov	eax,c
	imul	DWORD PTR z
	add	esi,eax
	adc	edi,edx

	mov	eax,DWORD PTR d
	cdq
	add	eax,esi
	adc	edx,edi
	idiv	DWORD PTR b
	mov	result,eax

	pop	di
	pop	si
		 }
 return result;
}



/************ COLLISION DETECTION AND SELECTION ***********/

long sphere_pretest(OBJECT *obj, long x, long y, long z)
{
 long dist = 0;     /* returns 0x7FFFFFFF if not in, else (D) */

 long sx = obj->sphx;
 long sy = obj->sphy;
 long sz = obj->sphz;
 long sr = obj->sphr;

 asm {
	push	cx

	mov	eax,sx   /* x bounds */
	sub	eax,x
	cmp	eax,sr
	jg	notin
	neg	eax
	cmp	eax,sr
	jg	notin

	mov	eax,sy   /* y bounds */
	sub	eax,y
	cmp	eax,sr
	jg	notin
	neg	eax
	cmp	eax,sr
	jg	notin

	mov	eax,sz   /* z bounds */
	sub	eax,z
	cmp	eax,sr
	jg	notin
	neg	eax
	cmp	eax,sr
	jg	notin

	imul	eax      /* square of distance to center */
	mov	ebx,eax
	mov	ecx,edx

	mov	eax,sx
	sub	eax,x
	imul	eax
	add	ebx,eax
	adc	ecx,edx

	mov	eax,sy
	sub	eax,y
	imul	eax
	add	ebx,eax
	adc	ecx,edx

	mov	eax,sr   /* square of radius */
	imul	eax
	cmp	edx,ecx
	ja	in
	jb	notin
	cmp	eax,ebx
	jae	in
		 }
notin:                   /* outside of sphere */
 asm pop cx;
 return 0x7FFFFFFF;      /* big never wins */

in:
 asm {
	test	ebx,-1         /* shift so denom. is 32-bit or less */
	jz	nolo1
	mov	eax,edx
	xor	edx,edx
	mov	ebx,ecx
	xor	ecx,ecx
     }
nolo1:
 asm {
	mov	eax,x    /* abs(x-sx)+abs(y-sy)+abs(z-sz) approx. dist from center */
	sub	eax,sx
	cdq
	xor	eax,edx
	sub	eax,edx
	mov	ebx,eax

	mov	eax,x
	sub	eax,sx
	cdq
	xor	eax,edx
	sub	eax,edx
	add	ebx,eax

	mov	eax,x
	sub	eax,sx
	cdq
	xor	eax,edx
	sub	eax,edx
	add	ebx,eax

	mov	dist, ebx
	pop	cx
		 }
 return dist;      /* for comparison between objects: smallest wins */
}



/************* POLYGON NORMAL COMPUTATION *************/

	  /* returns abs(x1-x2) + abs(y1-y2) + abs(z1-z2) */

long big_dist(long x1, long y1, long z1,
	       long x2, long y2, long z2 )
{
 long dist;

 asm {
	mov     eax,x1
	sub	eax,x2
	cdq
	xor	eax,edx
	sub	eax,edx
	mov	ecx,eax

	mov     eax,y1
	sub	eax,y2
	cdq
	xor	eax,edx
	sub	eax,edx
	add	ecx,eax

	mov     eax,z1
	sub	eax,z2
	cdq
	xor	eax,edx
	sub	eax,edx
	add	ecx,eax

	mov	dist,ecx
     }
 return dist;
}


	/* compute, unitize (3.29 format) normal to plane.   */
	/* returns -1 if normal is zero, else log2(length)   */

int find_normal(long x1, long y1, long z1,
		long x2, long y2, long z2,
		long x3, long y3, long z3,
		long *xn, long *yn, long *zn)
{
 long xh, xl, yh, yl, zh, zl;
 long xah, xal, yah, yal, zah, zal;
 int length;

 extern int sqrtable[1024];

 asm {
	push	dx
	push	cx
	push	si
	push	di

	mov	eax,y2        /* compute 64-bit cross product   */
	sub	eax,y1        /* and also abs. value for shifts */
	mov	ecx,z3
	sub	ecx,z2
	imul	ecx
	mov	edi,edx
	mov	esi,eax
	mov	eax,y3
	sub	eax,y2
	mov	ecx,z2
	sub	ecx,z1
	imul	ecx
	sub	esi,eax
	sbb	edi,edx
	mov	xh,edi
	mov	xl,esi
	jge	stax
	not	edi
	not	esi
	add	esi,1
	adc	edi,0
     }
stax:
 asm {
	mov	xah,edi
	mov	xal,esi

	mov	eax,z2
	sub	eax,z1
	mov	ecx,x3
	sub	ecx,x2
	imul	ecx
	mov	edi,edx
	mov	esi,eax
	mov	eax,z3
	sub	eax,z2
	mov	ecx,x2
	sub	ecx,x1
	imul	ecx
	sub	esi,eax
	sbb	edi,edx
	mov	yh,edi
	mov	yl,esi
	jge	stay
	not	edi
	not	esi
	add	esi,1
	adc	edi,0
     }
stay:
 asm {
	mov	yah,edi
	mov	yal,esi

	mov	eax,x2
	sub	eax,x1
	mov	ecx,y3
	sub	ecx,y2
	imul	ecx
	mov	edi,edx
	mov	esi,eax
	mov	eax,x3
	sub	eax,x2
	mov	ecx,y2
	sub	ecx,y1
	imul	ecx
	sub	esi,eax
	sbb	edi,edx
	mov	zh,edi
	mov	zl,esi
	jge	staz
	not	edi
	not	esi
	add	esi,1
	adc	edi,0
     }
staz:
 asm {
	mov	zah,edi
	mov	zal,esi
     }

 asm {					/* now normalize to 3.29 */
	or	esi,yal
	or	esi,xal
	or	edi,yah
	or	edi,xah
	jz	zero_h

	xor	ax,ax           /* ax is shift count */
	test	edi,0FFFF0000h  /* top word not zero: cnvt to 1.n <3.29> */
	jz	z16h
	add	ax,16
	shr	edi,16
     }
z16h:
 asm {
	test	di,0FF00h
	jz	z8h
	add	ax,8
	shr	edi,8
     }
z8h:
 asm {
	shl	edi,8       /* most ecomonical pos'n */
	bsr	cx,di       /* get exact shift */
	sub	cx,5
	add     cx,ax

	mov	eax,xh      /* convert cross product to 1.n */
	shrd	xl,eax,cl
	mov	eax,yh
	shrd	yl,eax,cl
	mov	eax,zh
	shrd	zl,eax,cl

	add	cx,29
	mov	length,cx

	jmp	dshnorm
		 }

zero_h:
 asm {
	or	esi,esi
	jz	zero_normal
	mov	ax,24
	test	esi,0FFFF0000h  /* top word is zero: cnvt to 1.n <3.29> */
	jz	z16l
	sub	ax,16
	shr	esi,16
     }
z16l:
 asm {
	test	si,0FF00h
	jz	z8l
	sub	ax,8
	shr	esi,8
     }
z8l:
 asm {
	shl	esi,8       /* most ecomonical pos'n */
	bsr	cx,si       /* get exact shift */
	neg	cx
	add	cx,13
	add	cx,ax

	jz	noshiftl
	jg	lshiftl

	neg	cx
	mov	eax,xh      /* convert cross product to 1.n   */
	shrd	xl,eax,cl   /* need ext. for borderline cases */
	mov	eax,yh
	shrd	yl,eax,cl
	mov	eax,zh
	shrd	zl,eax,cl
     }
noshiftl:
 asm {
	add	cx,29
	mov	length,cx

	jmp	dshnorm
     }
lshiftl:
 asm {
	shl	DWORD PTR xl,cl
	shl	DWORD PTR yl,cl
	shl	DWORD PTR zl,cl

	mov	ax,29
	sub	ax,cx
	mov	length,ax
     }
dshnorm:  goto finish;

zero_normal:
 asm {
	pop	di
	pop	si
	pop	cx
	pop	dx
     }
 *xn = *yn = *zn = -1;
 return 0;

finish:             /* compute magnitude, convert to unit length */

 asm {
	mov	eax,xl            /* compute squares */
	sar	eax,16
	imul	ax
	mov	bx,dx
	mov	cx,ax

	mov	eax,yl
	sar	eax,16
	imul	ax
	add	cx,ax
	adc	bx,dx

	mov	eax,zl
	sar	eax,16
	imul	ax
	add	cx,ax
	adc	bx,dx

	shr	bx,4             /* magnitude << 13 */
	shl	bx,1
	mov	cx,sqrtable[bx]
	movzx	ecx,cx

	mov	eax,xl           /* scale cross product */
	cdq
	shld	edx,eax,13
	shl	eax,13
	idiv	ecx
	mov	xl,eax

	mov	eax,yl
	cdq
	shld	edx,eax,13
	shl	eax,13
	idiv	ecx
	mov	yl,eax

	mov	eax,zl
	cdq
	shld	edx,eax,13
	shl	eax,13
	idiv	ecx
	mov	zl,eax

	pop	di
	pop	si
	pop	cx
	pop	dx
     }

 *xn = -xl; 	/* left-hand coordinate system */
 *yn = -yl;
 *zn = -zl;

 return length;
}


long scale_16(long s, long a, long x)    /* perform scaling by 16.16 number */
{
 long result;

 asm {
	mov	eax,DWORD PTR x
	add eax,DWORD PTR a
	imul	DWORD PTR s
	shrd	eax,edx,16
	adc	eax,0
	mov	DWORD PTR result,eax
     }
 return result;
}

long calc_scale_16(long a, long b, long s)   /* compute 16.16 scaling factor */
{
 long result = 0;

 asm {
	mov	ebx,DWORD PTR a
	sub	ebx,DWORD PTR b
	je	cdiv
	mov	eax, DWORD PTR s
	cdq
	shld	edx,eax,17
	shl	eax,17
	idiv  ebx
	mov	DWORD PTR result,eax
		 }
cdiv:
 return result;
}




