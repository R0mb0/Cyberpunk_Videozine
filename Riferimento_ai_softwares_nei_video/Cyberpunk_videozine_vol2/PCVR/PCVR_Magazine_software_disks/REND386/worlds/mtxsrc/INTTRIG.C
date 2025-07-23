/* Routines for trignometry */
/* assembly by Dave Stampe */

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


/*************** TRIGNOMETRIC FUNCTIONS *****************/

#define XFSC 536870912   /* 2**29 for shifting xform coeffs to long */

extern long sintable[258];
extern long atantable[258];    /* <3.29> args -> <16.16> angle */


long isine(long angle)           /* returns <3.29> sine of <16.16> angle */
{
 long result;

/* return(XFSC * sin(3.14159/180*angle/65536.0));*/

 asm {
	.386
	push	si
	push	di
	push	cx
	push	dx
	mov	eax,angle
	mov	edx,5B05B05Bh
	imul	edx
	shrd	eax,edx,29	   /* convert so 90 deg -> 256 */
	adc	eax,0              /* 2 upper bits = quadrant  */
	mov	angle,eax          /* 16 lsb used to interp.   */
     }

 asm {
	mov	ebx,eax
	mov	esi,eax
	mov	edx,eax

	shr	ebx,14             /* 8 bit 2.84*degree index */
	and	ebx,03FCh
	test    esi,01000000h
	jz	forward
	not	edx
	xor	ebx,03FCh
     }
forward:
 asm {
	mov	ecx,DWORD PTR ds:sintable[bx]
	mov	eax,DWORD PTR ds:sintable+4[bx]  /* lookup this, next entry */
	sub	eax,ecx

	and	edx,0000FFFFh       /* compute interp. factor */
	mul     edx
	shrd	eax,edx,16
	adc	ecx,eax             /* add in */

	test    esi,02000000h
	jz	positive
	neg	ecx
     }
positive:
 asm {
	mov	result,ecx
	pop	dx
	pop	cx
	pop	di
	pop	si
     }
 return result;
}


long icosine(long angle)
{
 return isine(90*65536L + angle);
}


/************ INVERSE TRIG FUNCTIONS *************/

long arcsine(long x)      /* <3.29> args -> <16.16> angle */
{                         /* have to use table in reverse */
 int sign = 0;            /* because slope varies widely  */
 long result;
 long *stp = &sintable[0];

 if(x==0) return 0;
 if(x<0)
  {
   sign++;
   x = -x;
  }
 if(x>=XFSC)
  {
   result = 90*65536L;
   goto ret90;
  }

 asm {
	push	si
	push	di
	push	dx
	push	cx

	mov	bx,WORD PTR stp      /* fast binary search sine table */
	xor	ecx,ecx
	mov	eax,x
	cmp	eax,[bx+512]
	jb	b1
	add	ebx,512
	or	ecx,00800000h
     }
b1:
 asm {
	cmp	eax,[bx+256]
	jb	b2
	add	ebx,256
	or	ecx,00400000h
     }
b2:
 asm {
	cmp	eax,[bx+128]
	jb	b3
	add	ebx,128
	or	ecx,00200000h
     }
b3:
 asm {
	cmp	eax,[bx+64]
	jb	b4
	add	ebx,64
	or	ecx,00100000h
     }
b4:
 asm {
	cmp	eax,[bx+32]
	jb	b5
	add	ebx,32
	or	ecx,00080000h
		 }
b5:
 asm {
	cmp	eax,[bx+16]
	jb	b6
	add	ebx,16
	or	ecx,00040000h
     }
b6:
 asm {
	cmp	eax,[bx+8]
	jb	b7
	add	ebx,8
	or	ecx,00020000h
     }
b7:
 asm {
	cmp	eax,[bx+4]
	jb	b8
	add	ebx,4
	or	ecx,00010000h
     }
b8:
 asm {
	sub	eax,[bx]
	je	nointerp
	mov	esi,[bx+4]
	sub	esi,[bx]
	je	okinterp
	cmp	eax,esi
	jb	okinterp
	add	ecx,00010000h
	jmp	nointerp
     }
okinterp:
 asm {
	cdq
	shld	edx,eax,16
	shl	eax,16
	idiv	esi
	mov	cx,ax
     }
nointerp:
 asm {
	mov	eax,05A000000h    /* convert to <16.16> angle */
	imul	ecx
	mov	result,edx

	pop	cx
	pop	dx
	pop	di
	pop	si
     }

ret90:
 return (sign) ? -result : result;
}


long arccosine(long x)
{
 return(90*65536L - arcsine(x));
}

						 /* we can use a table for atan  */
			       /* as slope is fairly constant  */
long arctan2(long y, long x)
{
 long result;
 int sx = 0;
 int sy = 0;
 int g45 = 0;

 if(x<0)           /* extract signs */
  {
   sx++;
   x = -x;
  }
 if(y<0)           /* look for trivial solutions */
  {
   sy++;
   y = -y;
  }
 if(x==0)
  {
   result = 90*65536L;
   goto retconst;
  }
 if(y==0)
  {
   result = 0;
   goto retconst;
  }

 if(y>x)		/* confine to single octant */
  {
   g45++;
   result = x;
   x = y;
   y = result;
  }

 asm {
	mov	edx,y
	xor	eax,eax
	mov	ebx,x
	cmp	edx,ebx
	jne	non45
	mov	eax,02D0000h	/* 45 degrees */
	mov	result,eax
	jmp	retconst
     }
non45:
 asm {
	push	si
	push	di

	shrd	eax,edx,8      /* shift so it will divide OK */
	shr	edx,8
	idiv	ebx            /* y/x << 24 */
	mov	ebx,eax
	shr	ebx,14         /* top 8 bits are index into table */
	and	ebx,03FCh
	mov	edi,DWORD PTR atantable[bx]
	mov	esi,DWORD PTR atantable+4[bx]
	sub	esi,edi
	and	eax,0000FFFFh  /* bottom 16 bits interpolate */
	mul	esi
	shr	eax,16
	add	eax,edi
	mov	result,eax

	pop	di
	pop	si
     }

 if(g45) result = 90*65536L - result;

retconst:
 if(sx)
  {
   if(sy) return result - 180*65536L;
   else   return 180*65536L - result;
  }
 else
  {
   if(sy) return -result;
   else   return  result;
  }
}

