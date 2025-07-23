/* 3D graphics routines */

/* Written by Bernie Roehl and Dave Stampe, December 1991 */
/* updated 10/1/91 to do first clip pass */
/* completely operational 19/1/92 incl. integerization */

/* Contact: broehl@sunee.waterloo.edu or dstampe@sunee.waterloo.edu */

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
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <alloc.h>
#include <dos.h>

#include "3dstruct.h"
#include "intmath.h"
#include "f3dkitd.h"

static VIEW *current_view;

int wireframe = 0;

#define XFSC 536870912   /* 2**29 for shifting xform coeffs to long */
static float xfsc = XFSC;




/**************** SET AND COMPUTE VIEWPORT **************/

      /* static viewport data copies (assembly speed) */

static long  fact1, fact2, fact3, fact4, fact5, fact6, fact7, fact8, fact9;
static long  fac1, fac2, fac3, fac4, fac5, fac6, fac7, fac8, fac9;

static long  iview_x, iview_y, iview_z;

static long  hither,yon,left,right,top,bottom;
static long  hither4,yon4,left4,right4,top4,bottom4; /* prescaled */

static long left_C, left_M;     /* spherical object clip coefficients */
static long right_C, right_M;
static long top_C, top_M;
static long bot_C, bot_M;

static long hsw, hsh;		/* half screen width, height */
static long hsc, vsc;		/* screen center with offset */

static int xshift, yshift;      /* binary exponent factors */
static long sx,sy;              /* screen scale mantissa */
static long scx,scy;

static int orientation;		/* flipping for wierd displays */

extern int ambient_light;
extern int light1_s;
extern int light1_i;
extern long light1_x, light1_y, light1_z;
extern int light2_i;


void render_set_view(VIEW *v)    /* copy viewport data to fast access area */
{
 current_view = v;

 ambient_light = v->ambient;
 light1_i = 128 - light2_i - ambient_light;
 if(light1_i<0) light1_i = 0;
 if(ambient_light<0) ambient_light = 0;
 light1_s = v->directional;

 light1_x = v->lx;               /* light source */
 light1_y = v->ly;
 light1_z = v->lz;

 sx = v->sx;
 sy = v->sy;
 scx = v->scx;
 scy = v->scy;
 orientation = v->orientation;
 if(orientation & XFLIP) sx = -sx;
 if(orientation & YFLIP) sy = -sy;

 fac1 = v->eye_xform[0][0];
 fac2 = v->eye_xform[0][1];
 fac3 = v->eye_xform[0][2];
 fac4 = v->eye_xform[1][0];
 fac5 = v->eye_xform[1][1];
 fac6 = v->eye_xform[1][2];
 fact7 = fac7 = v->eye_xform[2][0];
 fact8 = fac8 = v->eye_xform[2][1];
 fact9 = fac9 = v->eye_xform[2][2];

 asm {
	.386                  /* produce scaled matrix for screen size */
	mov	eax,DWORD PTR sx
	imul    DWORD PTR fac1
	shrd	eax,edx,16
	adc	eax,0
	mov	DWORD PTR fact1,eax

	mov	eax,DWORD PTR sx
	imul    DWORD PTR fac2
	shrd	eax,edx,16
	adc	eax,0
	mov	DWORD PTR fact2,eax

	mov	eax,DWORD PTR sx
	imul    DWORD PTR fac3
	shrd	eax,edx,16
	adc	eax,0
	mov	DWORD PTR fact3,eax

	mov	eax,DWORD PTR sy
	imul    DWORD PTR fac4
	shrd	eax,edx,16
	adc	eax,0
	mov	DWORD PTR fact4,eax

	mov	eax,DWORD PTR sy
	imul    DWORD PTR fac5
	shrd	eax,edx,16
	adc	eax,0
	mov	DWORD PTR fact5,eax

	mov	eax,DWORD PTR sy
	imul    DWORD PTR fac6
	shrd	eax,edx,16
	adc	eax,0
	mov	DWORD PTR fact6,eax
     }

 iview_x = v->eye_xform[3][0];   /* viewport center */
 iview_y = v->eye_xform[3][1];
 iview_z = v->eye_xform[3][2];

 hither  = v->hither;            /* clipping planes */
 left    = v->left;
 yon     = v->yon;
 top     = v->top;
 right   = v->right;
 bottom  = v->bottom;

/* yon4    = yon    << PRESCALEZ;   /* prescaled clipping planes for tests */
/* hither4 = hither << PRESCALEZ;   */
/* top4    = top    << PRESCALE;    */
/* bottom4 = bottom << PRESCALE;    */
/* left4   = left   << PRESCALE;    */
/* right4  = right  << PRESCALE;    */

 _CX = PRESCALEZ;
 asm {
	mov	eax,DWORD PTR yon
	shl	eax,cl
	mov	DWORD PTR yon4,eax

	mov	eax,DWORD PTR hither
	shl	eax,cl
	mov	DWORD PTR hither4,eax
     }

  _CX = PRESCALE;
  asm {
	mov	eax,DWORD PTR top
	shl	eax,cl
	mov	DWORD PTR top4,eax

	mov	eax,DWORD PTR bottom
	shl	eax,cl
	mov	DWORD PTR bottom4,eax

	mov	eax,DWORD PTR left
	shl	eax,cl
	mov	DWORD PTR left4,eax

	mov	eax,DWORD PTR right
	shl	eax,cl
	mov     DWORD PTR right4,eax
       }

 left_C  = v->left_C;             /* spherical clip coefficients */
 left_M  = v->left_M;
 right_C = v->right_C;
 right_M = v->right_M;
 top_C   = v->top_C;
 top_M   = v->top_M;
 bot_C   = v->bot_C;
 bot_M   = v->bot_M;

 hsw = v->hsw;
 hsh = v->hsh;			/* half screen width, height*/
 hsc = v->hsc;
 vsc = v->vsc;			/* screen center */

 _CX = PRESCALE;
 asm {
	mov	eax,DWORD PTR hsc
	shl	eax,cl
	mov	DWORD PTR hsc,eax

	mov	eax,DWORD PTR vsc
	shl	eax,cl
	mov	DWORD PTR vsc,eax
     }

 xshift = v->xshift;
 yshift = v->yshift;   		/* binary part of form factors */

 wireframe = v->flags & WIREFRAME;
}



				 /* tables for sphere object clipping:   */
extern long sclip_C[800]; /* 1/sqrt(zoom^2 + 1) table   		*/
extern long sclip_M[800]; /* zoom * C table  (table: i = 32*zoom) */
				 /* range: FOV = 2*atan(1/zoom)          */
				 /* or about 150 to 7 degrees 		*/
/* thus: for smaller window, divide zoom by fraction of h. screen */

					/* compute screen and viewport   */
					/* factors.  These stay constant */
					/* over eye point changes        */
void initialize_screen_factors(VIEW *v)
{
 long sx,sy;
 int ti,bi,li,ri;
 long sh,sw;
 int xshift,yshift;

 long zoom = v->zoom;
 long aspect = v->aspect;
 int x_offset = v->x_offset;
 int y_offset = v->y_offset;
 long tt = v->top;
 long bb = v->bottom;
 long ll = v->left;
 long rr = v->right;
 long r1,r2;
 long scx, scy;

/*
 v->hsc = (v->left + v->right)/2 + v->x_offset;
 v->vsc = (v->top + v->bottom)/2 + v->y_offset;
 v->hsw = sw = (v->right - v->left)/2;
 v->hsh = sh = (v->bottom - v->top)/2;
					*/
 asm {
	mov	eax,ll
	add	eax,rr
	shr	eax,1
	add	ax,x_offset
	mov	r1,eax

	mov	eax,tt
	add	eax,bb
	shr	eax,1
	add	ax,y_offset
	mov	r2,eax

	mov	eax,rr
	sub	eax,ll
	shr	eax,1
	mov     sw,eax

	mov	eax,bb
	sub	eax,tt
	shr	eax,1
	mov     sh,eax
     }
 v->hsc = r1;
 v->vsc = r2;
 v->hsw = sw;
 v->hsh = sh;

			 /* setup zoom (FOV) */
 if(zoom > 16*65536L) zoom = 16*65536L;	 /* clip zoom to < 16 */
 if(zoom < 32768L)  zoom = 32768L;	 /* clip zoom to > 0.5 */

 if(v->orientation&XFLIP) x_offset = -x_offset;
 if(v->orientation&YFLIP) y_offset = -y_offset;

 asm {
	.386

	mov	eax,zoom     /* left pc = z*w/(w+xo) */
	mov	edx,sw
	imul	edx
	push	eax
	push	edx

	mov	ebx,sw
	add	bx,x_offset
	movzx	ebx,bx
	idiv	ebx
	shr	eax,12
	mov	li,ax

	pop	edx
	pop	eax
	mov	ebx,sw       /* right pc = z*w/(w-xo) */
	sub	bx,x_offset
	movzx	ebx,bx
	idiv	ebx
	shr	eax,12
	mov	ri,ax
			     /* compute vert. scale zoom */
/* zoom * sw / sh * (aspect/65536.0); */
	mov	eax,zoom		/* <16.16> */
	mul	DWORD PTR aspect        /* <16.16> -> <32.32> */
	shrd	eax,edx,16		/* -> <16.16> */
	mul	DWORD PTR sw
	div	DWORD PTR sh		/* still <16.16> */

	mov	edx,sh      /* top pc = z*h/(h+yo) */
	imul	edx
	push	edx
	push	eax

	mov	ebx,sh
	add	bx,y_offset
	movzx	ebx,bx
	idiv	ebx
	shr	eax,12
	mov	ti,ax

	pop	eax          /* bot pc = z*h/(h-yo) */
	pop	edx
	mov	ebx,sh
	sub	bx,y_offset
	movzx	ebx,bx
	idiv	ebx
	shr	eax,12
	mov	bi,ax
      }

 if(li>799)li=799;
 if(ri>799)ri=799;
 if(ti>799)ti=799;
 if(bi>799)bi=799;

 v->left_C  = sclip_C[li];             /* spherical clip coefficients */
 v->left_M  = sclip_M[li];
 v->right_C = sclip_C[ri];
 v->right_M = sclip_M[ri];
 v->top_C   = sclip_C[ti];
 v->top_M   = sclip_M[ti];
 v->bot_C   = sclip_C[bi];
 v->bot_M   = sclip_M[bi];

 xshift = yshift = PRESCALEZ;	/* preset shifts */
			/* compute screen scaling factors  */
			/* which are pseudo-floating point */
			/* to maximize precision and range */
			/* width sets overall scaling      */

/* sx = v->hsw * (zoom/65536.0);                       */
/* sy = v->hsw * (zoom/65536.0) * (v->aspect/65536.0); */
 asm {
	mov	eax,zoom		/* <16.16>            */
	mul	DWORD PTR aspect        /* <16.16> -> <32.32> */
	shrd	eax,edx,16		/* -> <16.16>         */
	mul	DWORD PTR sw            /* <16.0> -> <48.16>  */
	mov	scy, eax
	bsr	ecx,eax
	sub	cx,15
	jle	nofixs
	add     yshift,cx		/* and record shift */
	shrd	eax,edx,cl		/* normalize to <16.16> */
     }
nofixs:
 asm {
	mov	DWORD PTR sy,eax

	mov	eax,zoom		/* <16.16>            */
	mul	DWORD PTR sw            /* <16.0> -> <48.16>  */
	mov	scx,eax
	bsr	ecx,eax
	sub	cx,15
	jle	nofixs2
	add     xshift,cx		/* and record shift */
	shrd	eax,edx,cl		/* normalize to <16.16> */
     }
nofixs2:
 asm {
	mov	DWORD PTR sx,eax
     }

 v->xshift = xshift;
 v->yshift = yshift;
 v->sx = sx;
 v->sy = sy;
 v->scx = scx;
 v->scy = scy;
}


	/* compute eye point/ angle movement factors only */

void real_viewpoint(VIEW *v, long *x, long *y, long *z)
{
 *x = v->eye_xform[3][0] ;
 *y = v->eye_xform[3][1] ;
 *z = v->eye_xform[3][2] ;
}

	/* compute eye point/ angle movement factors only */

void fast_view_factors(VIEW *v)
{
 MATRIX m;

 std_matrix(m, v->tilt,v->pan,v->roll,v->ex,v->ey,v->ez);
 matrix_transpose(m, v->eye_xform);   /* copy matrix rotational inverse */
 v->eye_xform[3][0] = m[3][0];
 v->eye_xform[3][1] = m[3][1];
 v->eye_xform[3][2] = m[3][2];
}

	/* compute viewport factors (lotsa room for improvement, but */
	/* this is only done once.  Some stuff will not change       */
	/* 100% compatible with original (bit of a waste of time)    */

void compute_view_factors(VIEW *v)
{
 v->orientation = NOFLIP;
 v->x_offset = 0;
 v->y_offset = 0;
 initialize_screen_factors(v);
 fast_view_factors(v);
}

														/* matrix gives view vector and origin */
														/* while viewpoint matrix is world->cam xform */

void matrix_view_factors(VIEW *v,MATRIX m) /* set up from matrix xform */
{
 matrix_transpose(m, v->eye_xform);   /* copy matrix rotational inverse */
 v->eye_xform[3][0] = m[3][0];
 v->eye_xform[3][1] = m[3][1];
 v->eye_xform[3][2] = m[3][2];
}


void view_to_matrix(VIEW *v,MATRIX m)      /* view matrix to xform matrix */
{
 matrix_transpose(v->eye_xform, m);   /* copy matrix rotational inverse */
 m[3][0] = v->eye_xform[3][0];
 m[3][1] = v->eye_xform[3][1];
 m[3][2] = v->eye_xform[3][2];
}


/************ HORIZON IMPLEMENTATION MATH *****************/

int above_horizon(long x, long y, VIEW *v, long offset)
{
 long scx = v->scx;
 long scy = v->scy;
 long B = v->eye_xform[0][1];
 long E = v->eye_xform[1][1];
 long H = v->eye_xform[2][1];

 H += offset<<16;

 x -= v->hsc;
 y = -y + v->vsc;

 if(v->orientation & XFLIP) scx = -scx;
 if(v->orientation & YFLIP) scy = -scy;

 asm {
	mov	eax,x
	imul	DWORD PTR B
	idiv	DWORD PTR scx
	mov	ecx,eax
	mov	eax,y
	imul	DWORD PTR E
	idiv	DWORD PTR scy
	add	ecx,eax
	mov	eax, H
	neg	eax
	sar	eax,16
	cmp	ecx,eax
	jge	above
     }
 return 0;
above:
 return 1;
}


long y_horizon(long x, VIEW *v, long offset)
{
 long scx = v->scx;
 long scy = v->scy;
 long B = v->eye_xform[0][1];
 long E = v->eye_xform[1][1];
 long H = v->eye_xform[2][1];
 long result;

 H += offset<<16;

 x -= v->hsc;

 if(v->orientation & XFLIP) scx = -scx;
 if(v->orientation & YFLIP) scy = -scy;

 asm {
	mov	eax,x
	imul	DWORD PTR B
	idiv	DWORD PTR scx
	mov	edx, H
	sar	edx,16
	add	eax,edx
	neg	eax
	imul    DWORD PTR scy
	idiv 	DWORD PTR E
	mov	result,eax
     }
 return -result + v->vsc;
}


long x_horizon(long y, VIEW *v, long offset)
{
 long scx = v->scx;
 long scy = v->scy;
 long B = v->eye_xform[0][1];
 long E = v->eye_xform[1][1];
 long H = v->eye_xform[2][1];
 long result;

 H += offset<<16;

 y = -y + v->vsc;

 if(v->orientation & XFLIP) scx = -scx;
 if(v->orientation & YFLIP) scy = -scy;

 asm {
	mov	eax,y
	imul	DWORD PTR E
	idiv	DWORD PTR scy
	mov	edx, H
	sar	edx,16
	add	eax,edx
	neg	eax
	imul    DWORD PTR scx
	idiv 	DWORD PTR B
	mov	result,eax
     }
 return result + v->hsc;
}



/************ VERTEX AND POLY COPY MEMORY ALLOCATION ************/

static int r_objects_tested;
static int r_objects_passed;
static int r_polys_tested;
static int r_polys_passed;
static int r_polys_xyclipped;
static int r_polys_drawn;
static int r_vertices;
static int r_new_vertices;


DSORT *vispolys;       /* an array of pointers to visible polygons */
DSORT *visobjs;
DSORT *polist;		/* which array to put polys in */

int npols = 0;

static NVERTEX *vtxram;       /* memory allocation area start */
static NVERTEX *nvalloc;      /* memory alloc ptrs */
static NPOLY *npalloc;
static OK;		      /* cleared if too many vertices */

static int maxpolys = 1200;

void reset_render()           /* free copy space */
{
 free(vtxram);
 free(vispolys);
 free(visobjs);
}

static unsigned render_mem;

			    /* get space for poly and vertex working
			       copies */
void *setup_render(unsigned mem, int polys)
{
 maxpolys = polys;
 render_mem = mem<<10;
 if(mem>63) abort();
 if(NULL==(vtxram = (NVERTEX *)calloc(mem,1024))) goto emem;
 if(NULL==(vispolys = (DSORT *)calloc(maxpolys,sizeof(DSORT))))
	{
	 free(vtxram);
	 goto emem;
	}
 if(NULL ==(visobjs = (DSORT *)calloc(maxpolys,sizeof(DSORT))))
	{
	 free(vtxram);
	 free(vispolys);
	 goto emem;
	}
 else goto nemem;

emem:
	{
	 printf("\nCannot allocate memory for renderer!\n");
	 abort();
	}

nemem:
 npalloc = (NPOLY *)vtxram;
 nvalloc = (NVERTEX *)((char *)vtxram+render_mem-50);
 fill_sqrt();
 fill_sine();
 fill_sclip();
 return vtxram;
}


static void init_render()               /* reclaim all vertex and poly space */
{
 npalloc = (NPOLY *)vtxram;
 nvalloc = (NVERTEX *)((char *)vtxram+render_mem-50);
}



static NVERTEX *newvertex()             /* alloc space for new vertex copy */
{
 NVERTEX *v;

 r_new_vertices++;

 _CX = sizeof(NVERTEX);
 asm {
	mov	eax,DWORD PTR nvalloc     /* save address to v */
	sub	ax,cx
	mov	DWORD PTR v,eax
	mov	DWORD PTR nvalloc,eax     /* update pointer */
	les	bx,DWORD PTR v
	mov	BYTE PTR es:[bx].(NVERTEX)perspect,0    /* reset flags */
	sub	ax,200
	cmp	ax,WORD PTR npalloc
	ja	ok_v
	xor	ax,ax
	mov	WORD PTR OK,ax
     }
ok_v:
 return(v);
}

static NPOLY *newpoly()             /* alloc space for new poly copy */
{
 NPOLY *p;

 _CX = sizeof(NPOLY);
 asm {
	mov	eax,DWORD PTR npalloc     /* save address to v */
	mov	DWORD PTR p,eax
	add     ax,cx
	mov	DWORD PTR npalloc,eax     /* update pointer */
	add	ax,200
	cmp	ax,WORD PTR nvalloc
	jb	ok_p
	xor	ax,ax
	mov	WORD PTR OK,ax
     }
ok_p:
 return(p);
}




/*********** TRANSFORMS 'N THINGS ************/

	/* X, Y viewport xform, create new vertex copy if needed */
	/* used during Z clip pass only */

static NVERTEX *xy_transform(VERTEX *v)
{
 NVERTEX *nv;

 long wx,wy,wz;

 asm {                               /* quick test if conv. needed */
	les	bx,DWORD PTR v
	mov	eax,DWORD PTR es:[bx].(VERTEX)new_copy
	mov	DWORD PTR nv,eax
	or	eax,eax
	jz	need_new_one
     }
 return(nv);

need_new_one:

 nv = newvertex();

 asm {
	.386
	push	si
	push	di
	les	bx,DWORD PTR v
	mov	eax,DWORD PTR es:[bx].(VERTEX)x
	sub	eax,DWORD PTR iview_x
	mov	DWORD PTR wx,eax

	mov	eax,DWORD PTR es:[bx].(VERTEX)y
	sub	eax,DWORD PTR iview_y
	mov	DWORD PTR wy,eax

	mov	eax,DWORD PTR es:[bx].(VERTEX)z
	sub	eax,DWORD PTR iview_z
	mov	DWORD PTR wz,eax

	mov	eax,DWORD PTR fact1
	mov	edx,DWORD PTR wx
	imul	edx
	mov	esi,eax
	mov	edi,edx

	mov	eax,DWORD PTR fact2
	mov	edx,DWORD PTR wy
	imul	edx
	add	esi,eax
	adc	edi,edx

	mov	eax,DWORD PTR fact3
	mov	edx,DWORD PTR wz
	imul	edx
	add	esi,eax
	adc	edi,edx

	shrd    esi,edi,27	    /* 29 - PRESCALE */
	adc	esi,0
	mov	ecx,esi

	mov	eax,DWORD PTR fact4
	mov	edx,DWORD PTR wx
	imul	edx
	mov	esi,eax
	mov	edi,edx

	mov	eax,DWORD PTR fact5
	mov	edx,DWORD PTR wy
	imul	edx
	add	esi,eax
	adc	edi,edx

	mov	eax,DWORD PTR fact6
	mov	edx,DWORD PTR wz
	imul	edx
	add	esi,eax
	adc	edi,edx

	shrd    esi,edi,27	    /* 29 - PRESCALE */
	adc	esi,0
	mov	eax,esi

	mov	esi,DWORD PTR nv
	mov	DWORD PTR es:[bx].(VERTEX)new_copy,esi
	mov	esi,DWORD PTR es:[bx].(VERTEX)cz   /* copy z (conv before) */

	les	bx, DWORD PTR nv
	mov	DWORD PTR es:[bx].(NVERTEX)x,ecx    /* new x,y */
	mov	DWORD PTR es:[bx].(NVERTEX)y,eax
	mov	DWORD PTR es:[bx].(NVERTEX)z,esi

	pop     di
	pop	si
   }
 return(nv);                   /* pointer to xformed copy */
}




/********* Z CLIP AND VERTEX COPY *********/

static NVERTEX *nvert[20];     /* table of new poly vertices created */
static int nvcount;            /* table pointer/count (Z clip pass) */
static int nvcptr;		/* pointer for XY clip pass */

static unsigned char xy_outcode_and;     /* XY outcode accums used for reject etc */
static unsigned char xy_outcode_or;




		     /* int. of edge v1->v2 with hither */

static NVERTEX *clip_z_int(VERTEX *v1, VERTEX *v2)
{
 NVERTEX *nv1, *nv2, *nv3;
 long  x1,y1,z1,x2,y2,z2;
			/* copy/xform points if not yet done */
			/* nothing done if already processed */

 asm {                               /* quick test if conv. needed */
	les	bx,DWORD PTR v1
	mov	eax,DWORD PTR es:[bx].(VERTEX)new_copy
	mov	DWORD PTR nv1,eax
	or	eax,eax
	jnz	need_new_1
     }
 nv1 = xy_transform(v1);
need_new_1:
 asm {                               /* quick test if conv. needed */
	les	bx,DWORD PTR v2
	mov	eax,DWORD PTR es:[bx].(VERTEX)new_copy
	mov	DWORD PTR nv2,eax
	or	eax,eax
	jnz	need_new_2
     }
 nv2 = xy_transform(v2);
need_new_2:

 nv3 = newvertex();

 asm {
	les	bx,DWORD PTR nv1
	mov	eax,DWORD PTR es:[bx].(NVERTEX)x
	mov	DWORD PTR x1,eax
	mov	eax,DWORD PTR es:[bx].(NVERTEX)y
	mov	DWORD PTR y1,eax
	mov	eax,DWORD PTR es:[bx].(NVERTEX)z
	mov	DWORD PTR z1,eax

	les	bx,DWORD PTR nv2
	mov	eax,DWORD PTR es:[bx].(NVERTEX)x
	mov	DWORD PTR x2,eax
	mov	eax,DWORD PTR es:[bx].(NVERTEX)y
	mov	DWORD PTR y2,eax
	mov	eax,DWORD PTR es:[bx].(NVERTEX)z
	mov	DWORD PTR z2,eax

	cmp	eax,z1
	jg	other_way

	mov	ecx,z1       /* compute denominator */
	sub	ecx,z2
	je	zcltza

	mov	eax,DWORD PTR hither4   /* compute new x */
	sub	eax,z2
	mov	edx,x1
	sub	edx,x2
	imul	edx
	idiv	ecx
	add	eax,x2
	mov	x1,eax

	mov	eax,DWORD PTR hither4   /* compute new y */
	sub	eax,z2
	mov	edx,y1
	sub	edx,y2
	imul	edx
	idiv	ecx
	add	eax,y2
	mov     y1,eax
     }
zcltza: goto zcltz;

other_way:
 asm {
	mov	ecx,z2       /* compute denominator */
	sub	ecx,z1
	je	zcltz

	mov	eax,DWORD PTR hither4   /* compute new x */
	sub	eax,z1
	mov	edx,x2
	sub	edx,x1
	imul	edx
	idiv	ecx
	add	eax,x1
	mov	x1,eax

	mov	eax,DWORD PTR hither4   /* compute new y */
	sub	eax,z1
	mov	edx,y2
	sub	edx,y1
	imul	edx
	idiv	ecx
	add	eax,y1
	mov     y1,eax
     }

zcltz:       	/* no clipping: just transfer if zero denom. */

 asm {
	les	bx,DWORD PTR nv3
	mov	eax,x1
	mov	DWORD PTR es:[bx].(NVERTEX)x,eax
	mov	eax,y1
	mov	DWORD PTR es:[bx].(NVERTEX)y,eax
	mov	eax,DWORD PTR hither4
	mov	DWORD PTR es:[bx].(NVERTEX)z,eax
     }

 return(nv3);
}


				      /* final processing for vertex passed */
static NVERTEX *z_output(NVERTEX *nv) /* by clipper.  Figure perspective    */
{                                     /* screen positions and poly outcodes */

 asm {
	les	bx,DWORD PTR nv
	test    BYTE PTR es:[bx].(NVERTEX)perspect,0FFh
	je	do_perspective
     }
 goto skip_perspective;

do_perspective:

   asm {						/* es:[bx] = nv */
	mov	esi,DWORD PTR es:[bx].(NVERTEX)z
	mov	cl,BYTE PTR xshift  		/* prescale x, y for accuracy  */
	mov	eax,DWORD PTR es:[bx].(NVERTEX)x
	cdq
	shld	edx,eax,cl
	shl	eax,cl
	idiv	esi                 		/* divide by z */
	add	eax,DWORD PTR hsc   		/* add prescaled screen center */
	and	eax,0FFFFFFFCh			/* lock to integer */
	mov	DWORD PTR es:[bx].(NVERTEX)xs,eax     /* and store */

	xor	ch,ch
	cmp	eax,DWORD PTR right4
	jle	nsro                   /* check outcodes */
	or	ch,RIGHT
       }
nsro:
   asm {
	cmp	eax,DWORD PTR left4
	jge     nslo
	or	ch,LEFT
       }
nslo:
   asm {
	mov	cl,BYTE PTR yshift;   		/* same deal for y */
	mov	eax,DWORD PTR es:[bx].(NVERTEX)y
	cdq
	shld	edx,eax,cl
	shl	eax,cl
	idiv	esi
	neg	eax                   		/* except upside down */
	add	eax,DWORD PTR vsc
	and	eax,0FFFFFFFCh			/* lock to integer */
	mov	DWORD PTR es:[bx].(NVERTEX)ys,eax

	cmp	eax,DWORD PTR bottom4
	jle	nsbo
	or	ch,BOTTOM
       }
nsbo:
   asm {                              		/* check outcodes */
	cmp	eax,DWORD PTR top4
	jge     nsto
	or	ch,TOP
       }
nsto:
   asm {
	mov	BYTE PTR es:[bx].(NVERTEX)outcode,ch
	mov	BYTE PTR es:[bx].(NVERTEX)perspect,1
       }

skip_perspective:

 asm {
	mov	al, es:[bx].(NVERTEX)outcode  /* update accum. outcodes */
	or	BYTE PTR xy_outcode_or,al
	and	BYTE PTR xy_outcode_and,al
     }

 nvert[nvcount] = nv;
 if(nvcount > 20) OK = 0;
 nvcount++;
 return(nv);
}




/*************** XY POLYGON CLIPPER **************/

     /* clipper record variables: */
				   /* top clipper: */
static int first_top;              /* 1 if first vertex in pass  */
static NVERTEX *first_top_vtx;     /* first vertex */
static NVERTEX *last_top_vtx;      /* prev. vertex */

  /* bottom clipper */
static NVERTEX *first_bottom_vtx;
static NVERTEX *last_bottom_vtx;


static NVERTEX *first_left_vtx;    /* left clipper */
static NVERTEX *last_left_vtx;


static NVERTEX *first_right_vtx;   /* right clipper */
static NVERTEX *last_right_vtx;

static NVERTEX **vpoly;		   /* where to put output */



static NVERTEX *y_intercept(NVERTEX *v1, NVERTEX *v2, long edge)
{
 NVERTEX *nv = newvertex();	  /* create new vertex */

 long  x1 = v1->xs;               /* get values (BC can't do it inline) */
 long  y1 = v1->ys;
 long  z1 = v1->z;

 long  x2 = v2->xs;
 long  y2 = v2->ys;
 long  z2 = v2->z;

 if(y1<y2) goto fwd_clip;    /* always clip in same dir. to fix roundoff */

 asm {
	mov	ecx,y1       /* compute denominator */
	sub	ecx,y2
	je	zcltlz

	mov	eax,edge     /* compute new z */
	sub	eax,y2
	mov	edx,z1
	sub	edx,z2
	imul	edx
	idiv	ecx
	add	eax,z2
	mov	z1,eax

	mov	eax,edge     /* compute new x */
	sub	eax,y2
	mov	edx,x1
	sub	edx,x2
	imul	edx
	idiv	ecx
	add	eax,x2
	mov     x1,eax

     }
zcltlz:
 goto zcltz;

fwd_clip:
 asm {
	mov	ecx,y2       /* compute denominator */
	sub	ecx,y1
	je	zcltz

	mov	eax,edge     /* compute new z */
	sub	eax,y1
	mov	edx,z2
	sub	edx,z1
	imul	edx
	idiv	ecx
	add	eax,z1
	mov	z1,eax

	mov	eax,edge     /* compute new x */
	sub	eax,y1
	mov	edx,x2
	sub	edx,x1
	imul	edx
	idiv	ecx
	add	eax,x1
	mov     x1,eax
     }
zcltz:       /* no clipping: just transfer if zero denom. */

 nv->xs = x1;
 nv->ys = edge;
 nv->z = z1;
 return(nv);
}


static NVERTEX *x_intercept(NVERTEX *v1, NVERTEX *v2, long edge)
{
 NVERTEX *nv = newvertex();	  /* create new vertex */

 long  x1 = v1->xs;               /* get values (BC can't do it inline) */
 long  y1 = v1->ys;
 long  z1 = v1->z;

 long  x2 = v2->xs;
 long  y2 = v2->ys;
 long  z2 = v2->z;

 if(x1<x2) goto fwd_clip;

 asm {
	mov	ecx,x1       /* compute denominator */
	sub	ecx,x2
	je	zcltlz

	mov	eax,edge     /* compute new z */
	sub	eax,x2
	mov	edx,z1
	sub	edx,z2
	imul	edx
	idiv	ecx
	add	eax,z2
	mov	z1,eax

	mov	eax,edge     /* compute new y */
	sub	eax,x2
	mov	edx,y1
	sub	edx,y2
	imul	edx
	idiv	ecx
	add	eax,y2
	mov     y1,eax
     }
zcltlz:
 goto zcltz;

fwd_clip:
 asm {
	mov	ecx,x2       /* compute denominator */
	sub	ecx,x1
	je	zcltz

	mov	eax,edge     /* compute new z */
	sub	eax,x1
	mov	edx,z2
	sub	edx,z1
	imul	edx
	idiv	ecx
	add	eax,z1
	mov	z1,eax

	mov	eax,edge     /* compute new y */
	sub	eax,x1
	mov	edx,y2
	sub	edx,y1
	imul	edx
	idiv	ecx
	add	eax,y1
	mov     y1,eax
     }
zcltz:       /* no clipping: just transfer if zero denom. */

 nv->xs = edge;
 nv->ys = y1;
 nv->z = z1;
 return(nv);
}




static void XY_clip(NVERTEX *v, int stage)   /* XY semirecursive clipper 	  */
{				      /* set last = NULL before first call */
				      /* call with all (copied) vertices  */
 NVERTEX *nv;			      /* call with NULL to flush 	  */
				      /* also copies output to poly table */

 switch(stage)
  {
   case BOTTOM: goto bottom_clip;
   case LEFT:   goto left_clip;
   case RIGHT:  goto right_clip;
  }

top_clip:
 asm {
	mov	eax,DWORD PTR last_top_vtx
	or	eax,eax
	jnz	not_first_top
	mov 	eax,DWORD PTR v
	mov	DWORD PTR last_top_vtx,eax
	mov	DWORD PTR first_top_vtx,eax
	les	bx,DWORD PTR v
	mov	al,BYTE PTR es:[bx].(NVERTEX)outcode
	test	al,TOP
	jnz	stt
	jmp	right_clip
     }
stt:
 return;

not_first_top:
 asm {
	mov	eax,DWORD PTR v
	or	eax,eax
	jnz	not_flush_top
	les	bx,DWORD PTR first_top_vtx
	mov	al,BYTE PTR es:[bx].(NVERTEX)outcode
	les	bx,DWORD PTR last_top_vtx
	xor	al,BYTE PTR es:[bx].(NVERTEX)outcode
	test	al,TOP
	jnz	stt2
	jmp	right_clip
     }
stt2:
   nv = y_intercept(first_top_vtx, last_top_vtx, top4);
   XY_clip(nv,RIGHT); 		   /* process this new point */
   goto right_clip;                /* and continue flush */

not_flush_top:
 asm {
	les	bx,DWORD PTR v
	mov	al,BYTE PTR es:[bx].(NVERTEX)outcode
	push	ax
	les	bx,DWORD PTR last_top_vtx
	xor	al,BYTE PTR es:[bx].(NVERTEX)outcode
	test	al,TOP
	jz	do_top_clip
     }
   nv = y_intercept(v, last_top_vtx, top4);
   XY_clip(nv,RIGHT); 		   /* process this new point */

do_top_clip:
 asm {
	mov	eax,DWORD PTR v
	mov	DWORD PTR last_top_vtx,eax
	pop	ax
	test	al,TOP
	jz	right_clip
     }
 return;


right_clip:
 asm {
	mov	eax,DWORD PTR last_right_vtx
	or	eax,eax
	jnz	not_first_right
	mov 	eax,DWORD PTR v
	mov	DWORD PTR last_right_vtx,eax
	mov	DWORD PTR first_right_vtx,eax
	les	bx,DWORD PTR v
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR right4
	jg	str
	jmp	bottom_clip
     }
str:
 return;

not_first_right:
 asm {
	mov	eax,DWORD PTR v
	or	eax,eax
	jnz	not_flush_right
	les	bx,DWORD PTR first_right_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR right4
	jle	pas1b

	les	bx,DWORD PTR last_right_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR right4
	jle	pas2b
	jmp	bottom_clip
     }
pas1b:
 asm {
	les	bx,DWORD PTR last_right_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR right4
	jg	pas2b
	jmp	bottom_clip
     }
pas2b:
   nv = x_intercept(first_right_vtx, last_right_vtx, right4);
   XY_clip(nv,BOTTOM); 		   /* process this new point */
   goto bottom_clip;                /* and continue flush */

not_flush_right:
 asm {
	les	bx,DWORD PTR v
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR right4
	jle	pat1b

	les	bx,DWORD PTR last_right_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR right4
	jg	no_right_clip
     }
   nv = x_intercept(v, last_right_vtx, right4);
   XY_clip(nv,BOTTOM); 		   /* process this new point */
no_right_clip:
 asm {
	mov	eax,DWORD PTR v
	mov	DWORD PTR last_right_vtx,eax
     }
 return;

pat1b:
 asm {
	les	bx,DWORD PTR last_right_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR right4
	jle	do_right_clip
     }
   nv = x_intercept(v, last_right_vtx, right4);
   XY_clip(nv,BOTTOM); 		   /* process this new point */

do_right_clip:
 asm {
	mov	eax,DWORD PTR v
	mov	DWORD PTR last_right_vtx,eax
     }
 goto bottom_clip;



bottom_clip:
 asm {
	mov	eax,DWORD PTR last_bottom_vtx
	or	eax,eax
	jnz	not_first_bottom
	mov 	eax,DWORD PTR v
	mov	DWORD PTR last_bottom_vtx,eax
	mov	DWORD PTR first_bottom_vtx,eax
	les	bx,DWORD PTR v
	mov	eax,DWORD PTR es:[bx].(NVERTEX)ys
	cmp	eax,DWORD PTR bottom4
	jg	stb
	jmp	left_clip
     }
stb:
 return;

not_first_bottom:
 asm {
	mov	eax,DWORD PTR v
	or	eax,eax
	jnz	not_flush_bottom
	les	bx,DWORD PTR first_bottom_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)ys
	cmp	eax,DWORD PTR bottom4
	jle	pas1bb

	les	bx,DWORD PTR last_bottom_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)ys
	cmp	eax,DWORD PTR bottom4
	jle	pas2bb
	jmp     left_clip
     }
pas1bb:
 asm {
	les	bx,DWORD PTR last_bottom_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)ys
	cmp	eax,DWORD PTR bottom4
	jg	pas2bb
	jmp	left_clip
     }
pas2bb:
   nv = y_intercept(first_bottom_vtx, last_bottom_vtx, bottom4);
   XY_clip(nv,LEFT); 		   /* process this new point */
   goto left_clip;                 /* and continue flush */

not_flush_bottom:
 asm {
	les	bx,DWORD PTR v
	mov	eax,DWORD PTR es:[bx].(NVERTEX)ys
	cmp	eax,DWORD PTR bottom4
	jle	pat1t

	les	bx,DWORD PTR last_bottom_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)ys
	cmp	eax,DWORD PTR bottom4
	jg	no_bottom_clip
     }
   nv = y_intercept(v, last_bottom_vtx, bottom4);
   XY_clip(nv,LEFT); 		   /* process this new point */
no_bottom_clip:
 asm {
	mov	eax,DWORD PTR v
	mov	DWORD PTR last_bottom_vtx,eax
     }
 return;

pat1t:
 asm {
	les	bx,DWORD PTR last_bottom_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)ys
	cmp	eax,DWORD PTR bottom4
	jle	do_bottom_clip
     }
   nv = y_intercept(v, last_bottom_vtx, bottom4);
   XY_clip(nv,LEFT); 		   /* process this new point */

do_bottom_clip:
 asm {
	mov	eax,DWORD PTR v
	mov	DWORD PTR last_bottom_vtx,eax
     }
 goto left_clip;



left_clip:
 asm {
	mov	eax,DWORD PTR last_left_vtx
	or	eax,eax
	jnz	not_first_left
	mov 	eax,DWORD PTR v
	mov	DWORD PTR last_left_vtx,eax
	mov	DWORD PTR first_left_vtx,eax
	les	bx,DWORD PTR v
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR left4
	jl	stl
	jmp	end_clip
     }
stl:
 return;

not_first_left:
 asm {
	mov	eax,DWORD PTR v
	or	eax,eax
	jnz	not_flush_left
	les	bx,DWORD PTR first_left_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR left4
	jge	pas1x

	les	bx,DWORD PTR last_left_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR left4
	jge     pas2x
	jmp	thru_flush
     }
pas1x:
 asm {
	les	bx,DWORD PTR last_left_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR left4
	jge	thru_flush
     }
pas2x:
   nv = x_intercept(first_left_vtx, last_left_vtx, left4);
   *vpoly++ = nv;		/* store the vertex */
   nvcptr++;
thru_flush:
   return;

not_flush_left:
 asm {
	les	bx,DWORD PTR v
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR left4
	jge	pat1x

	les	bx,DWORD PTR last_left_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR left4
	jl	no_left_clip
     }
   nv = x_intercept(v, last_left_vtx, left4);
   *vpoly++ = nv;		/* store the vertex */
   nvcptr++;
no_left_clip:
 asm {
	mov	eax,DWORD PTR v
	mov	DWORD PTR last_left_vtx,eax
     }
 return;

pat1x:
 asm {
	les	bx,DWORD PTR last_left_vtx
	mov	eax,DWORD PTR es:[bx].(NVERTEX)xs
	cmp	eax,DWORD PTR left4
	jge	do_left_clip
     }
   nv = x_intercept(v, last_left_vtx, left4);
   *vpoly++ = nv;		/* store the vertex */
   nvcptr++;

do_left_clip:
 asm {
	mov	eax,DWORD PTR v
	mov	DWORD PTR last_left_vtx,eax
     }

end_clip:
 asm {
	mov	eax,DWORD PTR v
	mov	DWORD PTR last_left_vtx,eax
     }
 *vpoly++ = v;		/* store the vertex */
 nvcptr++;              /* ideal point to remove extra bits from XYZ */
}




/*************** POLYGON CLIP AND PROCESS *************/



extern int sqrtable[1024];


int poly_cosine(POLY *pp, long lx, long ly, long lz, int spot)   /* returns 128 * cos poly-light angle */
{

 VERTEX *v0 = pp->points[0];

 long nx = pp->normalx;
 long ny = pp->normaly;
 long nz = pp->normalz;

 long dlx = v0->x;
 long dly = v0->y;
 long dlz = v0->z;

 int light;
		/* directional light instead of point source */

 if(spot)  dlx = dly = dlz = 0;

	/* compute vector from light source to surface  */
	/* find dot product, normalize by vector length */
	/* returns -128<light<128 (signed 8-bit)        */

 asm {
	push si
	push di
	mov	eax,DWORD PTR lx
	sub	eax,dlx
	mov     ecx,eax             /* delta X */
	jge	xnn
	neg	ecx
     }
xnn:
 asm {
	mov	dlx,ecx             /* abs value for scaling */
	mov	ebx,ecx
	imul	DWORD PTR nx
	mov	edi,edx
	mov	esi,eax

	mov	eax,DWORD PTR ly
	sub	eax,dly
	mov     ecx,eax
	jge	ynn
	neg	ecx
     }
ynn:
 asm {
	mov	dly,ecx
	or	ebx,ecx            /* OR abs deltas for scaling test */
	imul	DWORD PTR ny
	add	esi,eax
	adc	edi,edx

	mov	eax,DWORD PTR lz
	sub	eax,dlz
	mov     ecx,eax
	jge	znn
	neg	ecx
     }
znn:
 asm {
	mov	dlz,ecx           /* same for y, z */
	or	ebx,ecx
	jnz	golight		  /* max light at zero distance */
	mov	ax,127
	mov	light,ax
     }
 goto fincos;

golight:
 asm {
	imul	DWORD PTR nz
	add	esi,eax
	adc	edi,edx           /* edi:esi now 64-bit dot product */

	shrd	esi,edi,16
	sar	edi,16

	xor	cx,cx
	test    ebx,0ff000000h           /* prescale by 16 bits */
	je	not32sig
	add	cx,16
	jmp	shft16sig
     }
not32sig:
 asm {
	test	ebx,0ffff0000h
	je	nonesig                  /* prescale by 8 bits */
	add	cx,8
     }
shft16sig:
 asm {
	shr	ebx,cl                   /* conv. test to word (save 2 us) */
     }
nonesig:
 asm {
	bsr	ax,bx
	add	cx,ax
	sub	cx,7                     /* how many bits to normalize? */
	je	noshiftn
	jl	bumpup

	shr	DWORD PTR dlx,cl         /* divide */
	shr	DWORD PTR dly,cl
	shr	DWORD PTR dlz,cl
	shrd	esi,edi,cl
	sar	edi,cl
	jmp	noshiftn
     }
bumpup:
 asm {
	neg	cl
	shl	DWORD PTR dlx,cl         /* multiply */
	shl	DWORD PTR dly,cl
	shl	DWORD PTR dlz,cl
	shld	edi,esi,cl
	shl	esi,cl
     }
noshiftn:
 asm {
	mov	al,BYTE PTR dlx          /* now 8-bit diff's: find mag */
	mul	al
	mov	bx,ax                    /* square */
	xor	dx,dx

	mov	al,BYTE PTR dly
	mul	al
	add	bx,ax
	adc	dx,0

	mov	al,BYTE PTR dlz
	mul	al
	add	bx,ax
	adc	dx,0

	shrd	bx,dx,7                  /* lookup in table */
	and     ebx,0FFFEh
	mov	ax,sqrtable[bx]
	cwde
	mov	ebx,eax
	mov	edx,edi
	mov	eax,esi
	idiv	ebx
	mov	light,ax
     }
fincos:
asm {
	pop di
	pop si
	}
 return light;
}




/* DO POLY PROCESSING - LOTS OF STUFF INLINE DUE TO HIGH USAGE */

static int depth_type;		/* selects depth sort style */


static void proc_poly(POLY *p)  /* accept/reject tests on polys */
{                               /* transforms vertices, clips   */
 int i,j,k;                     /* and computes screen coords   */
 char z_outcode_or  = 0;        /* Also copies polys and points */
 char z_outcode_and = 3;        /* for minimum disruption of    */
 VERTEX **vp;
 VERTEX *v;                     /* the world database           */
 NVERTEX *nv;
 NPOLY *np;
 long ny,nz;
 VERTEX **pv;

 char last_z_out;        /* previous vertex Z outcode  */
 VERTEX *last_z_vtx;     /* orig. (world) prev. vertex */
				/* skip backfacing polygons */
/* return if (p->normalx * (current_view->ex - p->points[0]->x) +
	 p->normaly * (current_view->ey - p->points[0]->y) +
	 p->normalz * (current_view->ez - p->points[0]->z)) >= 0.0; */


r_polys_tested++;

 if(p->npoints<3) goto proceed;	/* don't test if it's a line! */

 asm {
	push	esi
	push	edi
	les	bx,DWORD PTR p
	mov     edx,DWORD PTR es:[bx].(POLY)normalx
	mov	eax,DWORD PTR es:[bx].(POLY)normaly
	mov	DWORD PTR ny,eax
	mov	eax,DWORD PTR es:[bx].(POLY)normalz
	mov	DWORD PTR nz,eax
	les	bx,DWORD PTR es:[bx].(POLY)points
	les	bx,es:[bx]

	mov	eax,DWORD PTR es:[bx].(VERTEX)x
	sub	eax,DWORD PTR iview_x
	imul	edx
	mov	esi,eax
	mov	edi,edx

	mov	eax,DWORD PTR es:[bx].(VERTEX)y
	sub	eax,DWORD PTR iview_y
	imul	DWORD PTR ny
	add	esi,eax
	adc	edi,edx

	mov	eax,DWORD PTR es:[bx].(VERTEX)z
	sub	eax,DWORD PTR iview_z
	imul	DWORD PTR nz
	add	esi,eax
	adc	edi,edx
	pop	edi
	pop	esi
	jl      proceed
     }
 return;

proceed:


r_polys_passed++;

		/* scan through the poly's points, transforming Z
		    and doing outcode clipping to hither and yon   */

 asm {
	push	si            /* setup loop with # points, point table ptr */
	push	di
	les	bx,DWORD PTR p
	mov	ax,WORD PTR es:[bx].(POLY)npoints
	mov	WORD PTR j,ax
	mov	eax,DWORD PTR es:[bx].(POLY)points
	mov	pv,eax
     }

 loopz:
 asm {  les	si,DWORD PTR pv
	les	si,es:[si]
	test	BYTE PTR es:[si].(VERTEX)z_transformed,0ffh
	jnz	already_z

	/* Z coord transform, generate Z outcode      */


}
r_vertices++;
asm{


	mov	eax,DWORD PTR fact7
	mov	edx,DWORD PTR es:[si].(VERTEX)x
	sub	edx,DWORD PTR iview_x
	imul	edx
	mov	ecx,eax
	mov	edi,edx

	mov	eax,DWORD PTR fact8
	mov	edx,DWORD PTR es:[si].(VERTEX)y
	sub	edx,DWORD PTR iview_y
	imul	edx
	add	ecx,eax
	adc	edi,edx

	mov	eax,DWORD PTR fact9
	mov	edx,DWORD PTR es:[si].(VERTEX)z
	sub	edx,DWORD PTR iview_z
	imul	edx
	add	ecx,eax
	adc	edi,edx

	shrd    ecx,edi,27	    /* 29 - PRESCALEZ */
	adc	ecx,0

	mov	DWORD PTR es:[si].(VERTEX)cz,ecx
	mov	BYTE PTR es:[si].(VERTEX)z_transformed,1

	xor	ax,ax
	cmp	ecx,DWORD PTR hither4
	jge	nonhither
	or	al,HITHER
     }
nonhither:
 asm {
	cmp     ecx,DWORD PTR yon4
	jle	nonyon
	or	al,YON
     }
nonyon:
 asm {
	mov     BYTE PTR es:[si].(VERTEX)z_outcode,al
     }
already_z:                              /* accumulate outcodes */
 asm {
	mov     al,BYTE PTR es:[si].(VERTEX)z_outcode
	or	BYTE PTR z_outcode_or,al
	and	BYTE PTR z_outcode_and,al

	add	WORD PTR pv,4			/* next vertex */
	dec	WORD PTR j
	jz      loopze
	jmp	loopz
     }
loopze:
 asm {
	pop     di
	pop	si
     }

 if (z_outcode_and == HITHER ||
     z_outcode_and == YON)  return;       /* all hither/yon? Reject poly */

			/* otherwise, begin Z clip and XY transforms */
 xy_outcode_or  = 0;
 xy_outcode_and = 15;   /* Z-clip pass setup */
 nvcount = 0;                        /* Pass 2: */
				     /* Z-clip and XY conv. vertices   */
				     /* also make copies to temp array */
{
 char first_z_out;        /* first vertex Z outcode     */
 VERTEX *first_z_vtx;     /* orig. (world) first vertex */
 char last_z_out;         /* previous vertex Z outcode  */
 VERTEX *last_z_vtx;      /* orig. (world) prev. vertex */
 char z_ocode;
 VERTEX *pv;

 asm {
	les	bx,p
	mov	eax,DWORD PTR es:[bx].(POLY)points
	mov	pv,eax
	mov	ax,WORD PTR es:[bx].(POLY)npoints
	mov	WORD PTR j,ax

	les	bx,DWORD PTR pv
	mov	eax,es:[bx]
	les	bx,es:[bx]
	mov	DWORD PTR first_z_vtx,eax
	mov	DWORD PTR last_z_vtx,eax
	mov	al,BYTE PTR es:[bx].(VERTEX)z_outcode
	and	al,HITHER
	mov	BYTE PTR first_z_out,al
	mov	BYTE PTR last_z_out,al
	jne	no_z_first
     }
  z_output(xy_transform(first_z_vtx));  /* output it if OK */
no_z_first:
zcloop:
 asm {
	dec	WORD PTR j
	jz	donezcl
	add	WORD PTR pv,4
	les	bx,DWORD PTR pv
	mov	edx,es:[bx]
	les	bx,es:[bx]
	mov	DWORD PTR v,edx
	mov	al,BYTE PTR es:[bx].(VERTEX)z_outcode
	and	al,HITHER
	mov	BYTE PTR z_ocode,al
	cmp	al,BYTE PTR last_z_out
	jz	no_z_mid
     }
  z_output( clip_z_int(last_z_vtx, v) );
no_z_mid:
 asm {
	les	bx,DWORD PTR pv
	mov	edx,es:[bx]
	mov	DWORD PTR last_z_vtx,edx
	mov	al,BYTE PTR z_ocode
	mov	BYTE PTR last_z_out,al
	or	al,al
	push	si
	jnz	no_z_m_out
     }
 z_output( xy_transform(last_z_vtx));
no_z_m_out:
 goto zcloop;

donezcl:

 if(first_z_out != last_z_out)     /* no flush needed? */
	 z_output( clip_z_int(last_z_vtx, first_z_vtx) );

 if((nvcount<3 && p->npoints>2) || xy_outcode_and)
	{
	 return;   /* reject poly if degenerate */
	}
						 /* or XY clip will delete it */
}

{
 NVERTEX **nvp = &nvert[0];
 np = newpoly();
 np->parent = p;
 vpoly = (NVERTEX **)npalloc;  	/* copy space pointer for vertex ptr storage */
 np->npoints = nvcount;
				/* vertex ptrs after poly */

 if(depth_type & AVERAGE)
  {
   long sumz;
   asm {
	push	si
	les	bx,np
	mov	cx,WORD PTR nvcount
	mov	si,WORD PTR nvp                 /* nvert[] in dseg */
	xor	eax,eax
       }
zfcaloop:
   asm {
	les	bx,ds:[si]
	add	eax,DWORD PTR es:[bx].(NVERTEX)z
	add	si,4
	loop	zfcaloop

	xor	edx,edx
	xor	esi,esi
	mov	si,WORD PTR nvcount
	idiv    esi
	mov	DWORD PTR nz,eax
	pop	si
       }
   }
  else		 /* default: use deepest Z in polygon */
   {
	 /* for (i = 0; i < nvcount; ++i)
			{
			 if (np->points[i]->z > np->maxz) np->maxz = np->points[i]->z;
			}    */
   asm {
	push	si
	mov	cx,WORD PTR nvcount
	mov	si,WORD PTR nvp
	mov	eax,080000001h
       }
 zfcloop:
   asm {
	les	bx,ds:[si]
	cmp	eax,DWORD PTR es:[bx].(NVERTEX)z
	jge	notlow
	mov	eax,DWORD PTR es:[bx].(NVERTEX)z
       }
 notlow:
   asm {
	add	si,4
	loop	zfcloop
	pop	si
	mov	nz,eax
       }
   }

 if(depth_type & ATBACK)
   {
    nz |= 0x40000000;
   }


 np->maxz = nz;

 if((xy_outcode_or) == 0)	/* does poly need XY clipping? */
  {
 /*  for(i=0;i<nvcount;i++) *vpoly++ = *nvp++ ;  /* no: copy it */
  asm {
	push	si
	push	di
	push	ds
	les	di,DWORD PTR vpoly      /* ya, so it saves 2 mS/frame! */
	mov	cx,WORD PTR nvcount
	lds	si,DWORD PTR nvp
	rep	movsd
	pop	ds
	mov	WORD PTR vpoly,di
	mov	WORD PTR nvp,si
	pop	di
	pop	si
      }
  }
 else                           /* yes: XY clip it */
  {
   /* (do XY clip) */

r_polys_xyclipped++;

   last_top_vtx = last_bottom_vtx = NULL;  /* initialize clipper */
   last_left_vtx = last_right_vtx = NULL;
   nvcptr = 0;
				/* clip all vertices */
   for(i=0;i<nvcount;i++)
       XY_clip(*nvp++, TOP);

   if(nvcount>2) XY_clip(NULL, TOP);   /* flush pending vertices (poly)  */


   if((nvcptr<3 && p->npoints>2) || nvcptr<2)
     {
       return;      /* discard degenerate poly */
     }
   np->npoints = nvcptr;
  }
 npalloc = (NPOLY *)vpoly;         /* update space pointer */
}

 np->color = user_poly_color(p,p->color,nz);    /* user poly color select */

{
			/* add to list of polys to render */
 if (npols < maxpolys)
  {

r_polys_drawn++;

   polist[npols].ptr = np;
   polist[npols++].depth = nz;
  }
 else OK = 0;
}

}




/************ ALLOWS EXTERNAL (HORIZON) POLYS TO USE CLIPPER ***********/

static NPOLY *ext_poly = NULL;

int ext_oor, ext_oand;   /* outcode and, or */
int ext_count;
NVERTEX **ext_vlist;      /* used to store original vertexes */

void init_ext_poly()
{
 ext_poly = newpoly();
 ext_vlist = &(nvert[0]);
 ext_count = 0;
 xy_outcode_or = 0;
 xy_outcode_and = 15;
 vpoly = (NVERTEX **) npalloc;
}

void add_ext_vertex(long x, long y)
{
 int ocode = 0;

 NVERTEX *v = newvertex();
 v->xs = x<<2;
 v->ys = y<<2;
 if((x<<2)<left4)   ocode |= LEFT;
 if((x<<2)>right4)  ocode |= RIGHT;
 if((y<<2)<top4)    ocode |= TOP;
 if((y<<2)>bottom4) ocode |= BOTTOM;
 xy_outcode_or |= ocode;
 xy_outcode_and &= ocode;
 v->outcode = ocode;
 ext_count++;
 *ext_vlist++ = v;
}

void render_ext_poly(unsigned color)
{
 void submit_poly(NPOLY *p, long maxz);
 int i;

 if(!ext_poly) return;

 ext_poly->color = color;
 ext_poly->parent = NULL;

 if(ext_count<3 || xy_outcode_and) return;   /* reject poly if degenerate */
 ext_poly->npoints = ext_count;
 ext_vlist = &(nvert[0]);

 if((xy_outcode_or) == 0)	/* does poly need XY clipping? */
  {
   for(i=0;i<ext_count;i++) *vpoly++ = *ext_vlist++;
  }
 else                           /* yes: XY clip it */
  {
   last_top_vtx = last_bottom_vtx = NULL;  /* initialize clipper */
   last_left_vtx = last_right_vtx = NULL;
   nvcptr = 0;
				/* clip all vertices */
   for(i=0;i<ext_count;i++)
       XY_clip(*ext_vlist++, TOP);
   if(ext_count>2) XY_clip(NULL, TOP);   /* flush pending vertices (poly)  */
   if(nvcptr<3) return;      /* discard degenerate poly */
   ext_poly->npoints = nvcptr;
  }

 npalloc = (NPOLY *)vpoly;         /* update space pointer */

 submit_poly(ext_poly, 0x7FFFFFFFL);
}


/************ OBJECT-CLIPPING STUFF **************/

/* Some background: we compute the coefficients of the left, right, top and
   bottom clipping planes, and use these to do bounding-sphere testing.
   The routine define_view_volume() computes the various _A, _B, and _C
   variables (e.g. left_B); note that these are in viewpoint coordinates
   (i.e. viewer at the origin, looking in the +ve Z direction).
   Since all the clipping planes pass through the origin, _D is always zero.
   We also compute an _M value for each clipping plane, which
   is the magnitude of the plane normal (which is just [_A, _B, _C].  Note
   that the sign of the magnitude is the same as the sign of _C (since _D
   is always zero).
   Optimization: we don't bother with coefficients that are zero, and we
   don't bother multiplying by coefficients that are one.
 */

static long center_z;

static int clip_by_volume(OBJECT *obj)
{
 long sx, sy, sz;

 long tx = obj->sphx;
 long ty = obj->sphy;
 long tz = obj->sphz;

 long r = obj->sphr;

 if (obj->oflags & OBJ_INVIS) return 7;  /* invisible object */
 if (obj->oflags & OBJ_HIGHLIGHTED) {
	if (current_view->flags & HIDE_HIGHLIGHTED) return 8;
	}
 else {
	if (current_view->flags & HIDE_UNHIGHLIGHTED) return 9;
	}
      /* transform Z coord of bounding sphere; keep for optional depth sort */
asm{
	.386
	push	si
	push	di

	mov	eax,DWORD PTR fac7
	mov	edx,DWORD PTR tx
	sub	edx,DWORD PTR iview_x
	imul	edx
	mov	esi,eax
	mov	edi,edx

	mov	eax,DWORD PTR fac8
	mov	edx,DWORD PTR ty
	sub	edx,DWORD PTR iview_y
	imul	edx
	add	esi,eax
	adc	edi,edx

	mov	eax,DWORD PTR fac9
	mov	edx,DWORD PTR tz
	sub	edx,DWORD PTR iview_z
	imul	edx
	add	esi,eax
	adc	edi,edx

	shrd    esi,edi,27	/* prescaled z */
	mov	DWORD PTR center_z,esi
	sar	esi,2
	mov	DWORD PTR sz,esi

	pop     di
	pop	si
   }

 if (sz + r < hither) return 1;  /* front clip */
 if (sz - r > yon) return 2;     /* back clip */

	/* transform X coordinate of bounding sphere */
asm{
	.386
	push	si
	push	di

	mov	eax,DWORD PTR fac1
	mov	edx,DWORD PTR tx
	sub	edx,DWORD PTR iview_x
	imul	edx
	mov	esi,eax
	mov	edi,edx

	mov	eax,DWORD PTR fac2
	mov	edx,DWORD PTR ty
	sub	edx,DWORD PTR iview_y
	imul	edx
	add	esi,eax
	adc	edi,edx

	mov	eax,DWORD PTR fac3
	mov	edx,DWORD PTR tz
	sub	edx,DWORD PTR iview_z
	imul	edx
	add	esi,eax
	adc	edi,edx

	shrd    esi,edi,29
	mov	DWORD PTR sx,esi

	pop     di
	pop	si
   }

/* if (-(left_C*sz + left_M*sx) > r) return 3;    /* left */
 asm {
	mov	eax,DWORD PTR left_C
	neg	eax
	imul	DWORD PTR sz
	shrd	eax,edx,29
	mov	ecx,eax			/* compute -Cz - r */
	sub	ecx,r

	mov	eax,DWORD PTR left_M	/* compute Mz */
	imul    DWORD PTR sx
	shrd	eax,edx,29

	cmp	ecx,eax
	jle	lvis
     }
 return 3;		/* left clipped */

lvis:

/* if (-(right_C*sz - right_M*sx) > r) return 4;    /* right */
 asm {
	mov	eax,DWORD PTR right_C
	neg	eax
	imul	DWORD PTR sz
	shrd	eax,edx,29
	mov	ecx,eax			/* compute -Cz - r */
	sub	ecx,r

	mov	eax,DWORD PTR right_M	/* compute Mz */
	imul    DWORD PTR sx
	shrd	eax,edx,29

	neg	eax
	cmp	ecx,eax
	jle	rvis
     }
 return 4;		/* right clipped */

rvis:
	/* transform Y coordinate of bounding sphere */
asm{
	push	si
	push	di

	mov	eax,DWORD PTR fac4
	mov	edx,DWORD PTR tx
	sub	edx,DWORD PTR iview_x
	imul	edx
	mov	esi,eax
	mov	edi,edx

	mov	eax,DWORD PTR fac5
	mov	edx,DWORD PTR ty
	sub	edx,DWORD PTR iview_y
	imul	edx
	add	esi,eax
	adc	edi,edx

	mov	eax,DWORD PTR fac6
	mov	edx,DWORD PTR tz
	sub	edx,DWORD PTR iview_z
	imul	edx
	add	esi,eax
	adc	edi,edx

	shrd    esi,edi,29	    /* 25 for x and y, 29 for z */
	mov	DWORD PTR sy,esi

	pop     di
	pop	si
   }

/* if (-(bot_C*sz + bot_M*sy) > r) return 5;    /* below */
 asm {
	mov	eax,DWORD PTR bot_C
	neg	eax
	imul	DWORD PTR sz
	shrd	eax,edx,29
	mov	ecx,eax			/* compute -Cz - r */
	sub	ecx,r

	mov	eax,DWORD PTR bot_M	/* compute Mz */
	imul    DWORD PTR sy
	shrd	eax,edx,29

	cmp	ecx,eax
	jle	bvis
     }
 return 5;		/* bottom clipped */

bvis:

/* if (-(top_C*sz - top_M*sy) > r) return 6;    /* above */
 asm {
	mov	eax,DWORD PTR top_C
	neg	eax
	imul	DWORD PTR sz
	shrd	eax,edx,29
	mov	ecx,eax			/* compute -Cz - r */
	sub	ecx,r

	mov	eax,DWORD PTR top_M	/* compute Mz */
	imul    DWORD PTR sy
	shrd	eax,edx,29

	neg	eax
	cmp	ecx,eax
	jle	tvis
     }
 return 6;		/* top clipped */

tvis:
	/* otherwise, it's at least partially inside the viewing volume */
 return 0;
}



static long compute_z(long tx,long ty,long tz)
{
 long sz;    /* Z coord transform for use in object depth sort  */

asm{
	.386
	push	cx
	push	di

	mov	eax,DWORD PTR fact7
	mov	edx,DWORD PTR tx
	sub	edx,DWORD PTR iview_x
	imul	edx
	mov	ecx,eax
	mov	edi,edx

	mov	eax,DWORD PTR fact8
	mov	edx,DWORD PTR ty
	sub	edx,DWORD PTR iview_y
	imul	edx
	add	ecx,eax
	adc	edi,edx

	mov	eax,DWORD PTR fact9
	mov	edx,DWORD PTR tz
	sub	edx,DWORD PTR iview_z
	imul	edx
	add	ecx,eax
	adc	edi,edx

	shrd    ecx,edi,27	    /* 29 - PRESCALEZ */

	mov	DWORD PTR sz,ecx

	pop     di
	pop	cx
   }
 return sz;
}

/*********** OBJECT-RENDERING CONTROL **********/

extern void move_rep(OBJECT *obj);

static int proc_obj(OBJECT *obj, long centz)
{
 int i;
 REP *repp;
 long r = obj->sphr;
 long oscreen;

 if(obj==NULL) return 1;
 if(obj->oflags&OBJ_REPLOCK)
  {
   repp = obj->current_rep;
   goto use_it;
  }
 if((repp = obj->replist)==NULL) return 1; 	/* no representation */
 if(centz<hither) goto usethis;                 /* bad center */

 while(repp!=NULL)            	/* choose representation to use */
	{
	 if(repp->size==0) goto usethis;
   asm {
	mov	eax,r           /* size = scale*radius/distance */
	imul	DWORD PTR scx
	shrd	eax,edx,8	    /* range-extended <16.16> -> <32.0> */
	sar	edx,8
	idiv	DWORD PTR centz
	sar	eax,6               /* 2x true size */
	mov	oscreen,eax
       }
   if(oscreen<0) goto usethis;
   if(oscreen>=(repp->size)) goto usethis;  /* 0 size always drawn */
	 if(repp->next!=NULL) repp = repp->next;
	 else return 1;
  }
usethis:
 obj->current_rep = repp;
 if(repp==NULL)
	return 1;    	/* nothing if too far */

use_it:
 if(obj->update_count != repp->update_count)  /* move if needed */
	move_rep(obj);

/* for (i = 0; i < obj->npoints; ++i)      /* at first, no transforms done */
/*  {
   repp->verts[i].new_copy = NULL;
   repp->verts[i].z_transformed = 0;
  }*/

 i = sizeof(VERTEX);

 asm {
	les	bx,repp
	mov	cx,es:[bx].(REP)nverts
	les	bx,es:[bx].(REP)verts
     }
cvloop:
 asm {
	mov	DWORD PTR es:[bx].(VERTEX)new_copy,0
	mov     BYTE PTR es:[bx].(VERTEX)z_transformed,0
	add	bx,WORD PTR i
	loop	cvloop
     }

 i = sizeof(POLY);

 asm {
	les	bx,repp
	mov	cx,es:[bx].(REP)npolys
	les	bx,es:[bx].(REP)polys
     }
cploop:
 asm {
	push	cx
	push	es
	push	bx
	push	cs
	call	near ptr proc_poly
	pop	bx
	pop	es
	pop	cx
	add	bx,WORD PTR i
	mov	ax,OK
	or	ax,ax
	jz	abort
	loop	cploop
     }
 abort:
 return 0;  /* return 0, object not clipped */
}


		/* quicksort DSORT array by depth */

static void iqsort(int m, int n)    /* m, n actually near ptrs into array */
{                                   /* es is seg. of array throughout */
 int i,j;                           /* keep array under 32K in size!  */

 asm {
	.386
	mov	si,m			/* i */
	cmp	si,n
	jl	keepon
     }
 return;

keepon:
 asm {
	mov	di,n    		/* j */
	add     di,8
	mov	eax,DWORD PTR es:[si].(DSORT)depth  /* k */
     }

gloop:

fmax:
 asm {
	add	si,8
	cmp	DWORD PTR es:[si].(DSORT)depth,eax
	jg	fmax
     }

fmin:
 asm {
	sub	di,8
	cmp	DWORD PTR es:[di].(DSORT)depth,eax
	jl	fmin

	cmp	si,di
	jge	nonswap

	mov	ecx,DWORD PTR es:[si]
	mov	edx,DWORD PTR es:[di]
	mov	DWORD PTR es:[di],ecx
	mov	DWORD PTR es:[si],edx
	mov	ecx,DWORD PTR es:[si+4]
	mov	edx,DWORD PTR es:[di+4]
	mov	DWORD PTR es:[di+4],ecx
	mov	DWORD PTR es:[si+4],edx
	jmp	gloop
     }
nonswap:
 asm {
	mov	si,m
	mov	ecx,DWORD PTR es:[si]
	mov	edx,DWORD PTR es:[di]
	mov	DWORD PTR es:[di],ecx
	mov	DWORD PTR es:[si],edx
	mov	ecx,DWORD PTR es:[si+4]
	mov	edx,DWORD PTR es:[di+4]
	mov	DWORD PTR es:[di+4],ecx
	mov	DWORD PTR es:[si+4],edx

	mov	j,di
     }

 if(m < j-8) iqsort(m,j-8);
 if(j+8 < n) iqsort(j+8,n);
 }


static int test_poly_point = 0;
static int test_point_x;
static int test_point_y;
static int which_vertex;    /* npoly vertex # closest <UNTESTED YET> */
static POLY * in_poly;
static long poly_depth;

static test_poly(int n, int *p, long maxz, int polarity, NPOLY *np)
{
 int left = 0;                   /* test if point in poly on screen */
 int right = 0;
 int point = n;

 asm {
	push	si
	push	di
	push	cx
	mov	cx,n
	dec	cx
	les	bx,p
	mov	si,bx
	add	si,4
     }
tedge:
 asm {
	mov	ax,test_point_y   /* test point */
	mov	dx,test_point_x

	cmp	ax,[bx+2]	  /*; check vertical */
	jle	above1
	cmp	ax,[si+2]
	jg	notine        /*; not in edge */
     }
above1:
 asm {
	cmp	ax,[bx+2]
	jge	vertok
	cmp	ax,[si+2]
	jl	notine        /*; not in edge */
		 }
vertok:
 asm {
	cmp	dx,[bx]
	jg	rt1
	cmp	dx,[si]
	jle	left           /* ; to left of edge */
	jmp	allok
     }
rt1:
 asm {
	cmp	dx,[si]
	jg	right          /* ; to right of edge */
     }
allok:
 asm {
	sub	ax,[bx+2]       /* ; y - y1 */
	mov	dx,[si]
	sub	dx,[bx]         /* ; x2 - x1 */
	imul	dx
	mov	di,[si+2]
	sub	di,[bx+2]       /* ; y2 - y1 */
	je	pend		/* must be between... */
	idiv	di
	add	ax,[bx]		/* ; + x1 */
	cmp	ax,test_point_x
	jle	right		/* ; tested left */
     }
left:
 asm {
	inc	WORD PTR left
	test	WORD PTR right,-1
	jnz     inpoly
	jmp	pend
     }
right:
 asm {
	inc	WORD PTR right
	test	WORD PTR left,-1
	jnz     inpoly
     }
notine:
pend:
 asm {
	add	si,4
	add	bx,4
	sub	cx,1
	jg	tedge
	jl	notin
	mov	si,WORD PTR p
	jmp     tedge
     }
inpoly:
 asm {
	mov	eax,maxz
	cmp	eax,DWORD PTR poly_depth
	jg	notin

	mov	cx,n
	mov	bx,-1
     }
vdtest:
 asm {
	mov	ax,test_point_x
	sub	ax,[si]
	cwd
	xor	ax,dx
	sub	ax,dx
	mov	di,ax
	mov	ax,test_point_y
	sub	ax,[si+2]
	cwd
	xor	ax,dx
	sub	ax,dx
	add	di,ax
	cmp	bx,di
	jbe	nond
	mov     bx,di
	mov	point,cx
	add	si,4
     }
nond:
 asm {
	loop	vdtest
	pop	cx
	pop	di
	pop	si
     }
 which_vertex = n-point;
 if(polarity) which_vertex = n-1-which_vertex;
 return 1;

notin:
 asm {
	pop	cx
	pop	di
	pop	si
     }
 return 0;
}


#define INTASZE 30
static int pcoords[INTASZE*2];
extern void user_render_poly(int vertex_count, int *pcoords,
				 unsigned poly_color, long max_depth);

			/* copies poly data, submits to renderer   */
			/* copy in reverse order if flipped screen */
static void submit_poly(NPOLY *p, long maxz)
{
 int number;
 int polarity = 0;
 unsigned color = p->color;
 int a = FP_OFF(&pcoords[0]);

 if(orientation==NOFLIP || orientation==(XFLIP|YFLIP))
  {
    _AX = sizeof(NPOLY);
    asm {
	.386
	push	si
	les	bx,DWORD PTR p
	mov	cx,WORD PTR es:[bx].(NPOLY)npoints
	mov	WORD PTR number,cx
	mov	si,bx
	add	si,ax        				/* table of ptrs */
	mov	di,WORD PTR a
	push	es
	 }
  coppl:
    asm {
	pop	es
	push	es
	les	bx,DWORD PTR es:[si]
	mov	ax,WORD PTR es:[bx].(NVERTEX)xs
	add	ax,2
	shr	ax,2
	mov	WORD PTR ds:[di],ax
	add	di,2
	mov	ax,WORD PTR es:[bx].(NVERTEX)ys
	add	ax,2
	shr	ax,2
	mov	WORD PTR ds:[di],ax
	add	di,2
	add	si,4
	loop	coppl
	pop	si
	pop	si
       }
  }
 else		/* copy vertices in reverse order */
  {
   _AX = sizeof(NPOLY);
   asm {
	.386
	push	si
	not	WORD PTR polarity
	les	bx,DWORD PTR p
	mov	si,bx
	add	si,ax				/* table of ptrs */
	mov	cx,WORD PTR es:[bx].(NPOLY)npoints
	mov	WORD PTR number,cx
	mov	di,WORD PTR a
	add	si,cx
	add	si,cx
	add	si,cx
	add	si,cx
	sub	si,4
	push	es
       }
   copplr:
	 asm {
	pop	es
	push	es
	les	bx,DWORD PTR es:[si]
	mov	ax,WORD PTR es:[bx].(NVERTEX)xs
	add	ax,2
	shr	ax,2
	mov	WORD PTR ds:[di],ax
	add	di,2
	mov	ax,WORD PTR es:[bx].(NVERTEX)ys
	add	ax,2
	shr	ax,2
	mov	WORD PTR ds:[di],ax
	add	di,2
	sub	si,4
	loop	copplr
	pop	si
	pop	si
       }
  }

 user_render_poly(number, &pcoords[0], color, maxz);
 if(test_poly_point && number>2 && p->parent)
  if(test_poly(number, &pcoords[0], maxz, polarity, p))
   {
    poly_depth = maxz;
    in_poly = p->parent;
   }
}



extern void user_setup_blitter();
extern void user_reset_blitter();

static MATRIX dummy;

void subrender(OBJLIST *objlist)
{
 OBJECT *obj;
 int i;
 int lseg;
 int snpoly = 0;
 int nobs = 0;

 init_render();

 if(objlist==NULL ||
    objlist->nnext==NULL ||
    objlist->nnext==objlist->prev)  return;

 npols = 0;
 OK = 1;
				/* step 1: sort objects and polys together */
 polist = visobjs;
 for (obj = objlist->nnext; obj; obj = obj->nnext)
  {

r_objects_tested++;
    if (clip_by_volume(obj) == 0)
     {
r_objects_passed++;

      if((depth_type = obj->oflags)&BYOBJECT)
	{
	  obj->oflags |= IS_OBJECT;
	  polist[npols].ptr = (NPOLY *) obj;             /* obj. depth only */
	  polist[npols++].depth = center_z;
	}
     else
	{
	 proc_obj(obj, center_z);                /* all polys in object */
	 if(OK==0) break;
	}
     }
  }

 if(npols>1)
  {
   npols--;
   lseg = FP_SEG(polist);			/* sort all items by max Z */
   asm {
	push	si
	push	di
	mov	ax,lseg                  /* visobjs segment */
	mov	es,ax
       }
   iqsort( FP_OFF(&visobjs[0]), FP_OFF(&visobjs[npols]) );
   asm {
	pop	di
	pop	si
       }
   npols++;
  }
 nobs = npols;
 npols = 0;
 polist = vispolys;
 lseg = FP_SEG(polist);

 for (i=0;i<nobs;i++)                  /* now expand objects */
  {
   if(!(*((int *)visobjs[i].ptr) & IS_OBJECT))
    {
     memcpy(&vispolys[npols++], &visobjs[i], sizeof(DSORT));   /* just copy polys */
    }
   else
    {
     snpoly = npols;                   /* expand objects */
     proc_obj((OBJECT *) visobjs[i].ptr, visobjs[i].depth);
     if(OK==0) break;
     if(npols-snpoly>1)
      {
       npols--;                        /* resort within objects */
       asm {
		push	si
		push	di
		mov	ax,lseg                  /* vispolys segment */
		mov	es,ax
	   }
       iqsort( FP_OFF(&vispolys[snpoly]), FP_OFF(&vispolys[npols]) );
       asm {
		pop	di
		pop	si
	   }
       npols++;
      }
    }
   if(npols >= maxpolys) break;
  }

 user_setup_blitter();                /* draw the polys */
 for (i = 0; i < npols; ++i)
    submit_poly(vispolys[i].ptr,vispolys[i].depth);
 user_reset_blitter();
}


void set_screen_monitor(int x, int y)
{
 test_poly_point = 1;
 test_point_x = x;
 test_point_y = y;
 poly_depth = 0x7FFFFFFF;
 in_poly = NULL;
}

void render(OBJLIST *objlist, VIEW *view)
{
 render_set_view(view);
 subrender(objlist);
}

void clear_screen_monitor()
{
 test_poly_point = 0;
}

POLY *read_screen_monitor()
{
 return in_poly;
}


