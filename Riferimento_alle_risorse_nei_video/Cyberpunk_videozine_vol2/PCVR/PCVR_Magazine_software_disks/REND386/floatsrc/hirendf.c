/* 3D graphics routines */

/* Copyright 1992 by Dave Stampe and Bernie Roehl */

/* Written by Bernie Roehl and Dave Stampe, December 1991 */
/* updated 10/1/91 to do first clip pass */
/* completely operational 19/1/92 incl. integerization */

/* REWRITTEN BACK TO FLOAT FOR EXAMPLE PURPOSES */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <alloc.h>

#include "3dstrucf.h"

static VIEW *current_view;

#define MAXPOLYS 1000
NPOLY *vispolys[MAXPOLYS];  /* an array of pointers to visible polygons */
int npols = 0;


/**************** SET AND COMPUTE VIEWPORT **************/

		/* static viewport data copies (assembly speed) */

static float fact1, fact2, fact3, fact4, fact5, fact6, fact7, fact8, fact9;
static float fac1, fac2, fac3, fac4, fac5, fac6, fac7, fac8, fac9;

static float view_x, view_y, view_z;
static float light_x,light_y, light_z;

static float  hither,yon,left,right,top,bottom;

static float hor_C, hor_M;
static float vert_C, vert_M;

static float hsw, hsh;		/* half screen width, height */
static float hsc, vsc;		/* screen center */


static void set_view(VIEW *v)    /* copy viewport data to fast access area */
{
	current_view = v;

	fac1 = v->fac1;     /* raw coefficients for spherical clip */
	fac2 = v->fac2;
	fac3 = v->fac3;
	fac4 = v->fac4;
	fac5 = v->fac5;
	fac6 = v->fac6;
	fac7 = v->fac7;
	fac8 = v->fac8;
	fac9 = v->fac9;

	fact1 = v->sfac1;   /* scaled xy conversion coefficients */
	fact2 = v->sfac2;
	fact3 = v->sfac3;
	fact4 = v->sfac4;
	fact5 = v->sfac5;
	fact6 = v->sfac6;
	fact7 = v->fac7;
	fact8 = v->fac8;
	fact9 = v->fac9;

	view_x = v->ex;                 /* viewport center */
	view_y = v->ey;
	view_z = v->ez;

	light_x = v->lx;                 /* light source */
	light_y = v->ly;
	light_z = v->lz;

	hither  = v->hither;            /* clipping planes */
	left    = v->left;
	yon     = v->yon;
	top     = v->top;
	right   = v->right;
	bottom  = v->bottom;

	hor_C   = v->hor_C;      	/* spherical clip coefficients */
	vert_C  = v->vert_C;
	hor_M   = v->hor_M;
	vert_M  = v->vert_M;

	hsw = v->hsw;
	hsh = v->hsh;			/* half screen width, height*/
	hsc = v->hsc;
	vsc = v->vsc;			/* screen center */
}



#define sine(x)   sin(3.14159/180*x)
#define cosine(x) cos(3.14159/180*x)

	/* compute viewport factors (lotsa room for improvement, but */
	/* this is only done once.  Some stuff will not change       */

void compute_view_factors(VIEW *v)
{
	float sa,ca,sp,cp,st,ct;
	float sx,sy;
	float sh,sw;
	float zoom = v->zoom;
	float aspect = v->aspect;

	ct = cosine(v->pan);     		/* sine, cosine angle compute */
	cp = cosine(v->tilt);
	ca = cosine(v->roll);
	st = sine(-v->pan);
	sp = sine(v->tilt);
	sa = sine(v->roll);

	v->hsc = (v->left + v->right)/2;         /* screen size/center */
	v->vsc = (v->top + v->bottom)/2;
	v->hsw = sw = (v->right - v->left)/2;
	v->hsh = sh = (v->bottom - v->top)/2;

	if (zoom > 16.0) zoom = 16.0;	 /* clip zoom to < 16 */
	if (zoom < 0.5)  zoom = 0.5;	 /* clip zoom to > 0.5 */

	sx = sw * zoom;                          /* screen scale factors */
	sy = sh * zoom * aspect;
					  /* object sphere clip coeffs */
	v->hor_C  = 1.0/sqrt(zoom * zoom + 1);
	v->hor_M  = zoom * v->hor_C;

	zoom = zoom * sw / sh * aspect;          /* refigure vertical zoom */

	v->vert_C  = 1.0/sqrt(zoom * zoom + 1);
	v->vert_M  = zoom * v->vert_C;

	v->fac1 = ca*ct-sa*sp*st;      /* transform matrix */
	v->fac2 = -sa*cp;
	v->fac3 = ca*st+sa*sp*ct;
	v->fac4 = sa*ct+ca*sp*st;
	v->fac5 = ca*cp;
	v->fac6 = sa*st-ca*sp*ct;
	v->fac7 = -cp*st;
	v->fac8 = sp;
	v->fac9 = cp*ct;

	v->sfac1 = v->fac1 * sx;    /* screen scaled transform */
	v->sfac2 = v->fac2 * sx;
	v->sfac3 = v->fac3 * sx;
	v->sfac4 = v->fac4 * sy;
	v->sfac5 = v->fac5 * sy;
	v->sfac6 = v->fac6 * sy;
}

/************ VERTEX AND POLY COPY MEMORY ALLOCATION ************/


static NVERTEX *vtxram;            /* memory allocation area start */
static NPOLY   *polyram;
static NVERTEX *nvalloc;           /* memory alloc ptrs */
static NPOLY *npalloc;
static int npacount;               /* number of used entries */
static int nvacount;


void reset_render()              /* free copy space */
{
	free(vtxram);
	free(polyram);
}
			    /* get space for poly and vertex working
			       copies */
void setup_render()
{
	assert(NULL!=(vtxram = (NVERTEX *)calloc(1000,sizeof(NVERTEX))));
	assert(NULL!=(polyram = (NPOLY *)calloc(1000,
					sizeof(NPOLY)+sizeof(NPOLY *))));
	nvalloc = vtxram;
	npalloc = polyram;
	npacount = nvacount = 0;
}


static void init_render()               /* reclaim all vertex and poly space */
{
	nvalloc = vtxram;
	npalloc = polyram;
	npacount = nvacount = 0;
}


static NVERTEX *newvertex()             /* alloc space for new vertex copy */
{
	NVERTEX *v = nvalloc++;
	memset(v,0,sizeof(NVERTEX));
	nvacount++;
	assert(nvacount<1000);
	return(v);
}


static NPOLY *newpoly()                 /* alloc space for new poly copy */
{
	NPOLY *p = npalloc++;
	memset(p,0,sizeof(NPOLY));
	npacount++;
	assert(npacount<1000);
	return(p);
}
				 /* alloc space for new poly copy vertex
				    table: 4 extra for XY clip
				    In future, if we process polys
				    atomically, we can just incr. npalloc
				    as we use pointers */
static void allocvarray(NPOLY *np)
{
	np->points = (NVERTEX **)npalloc;

	npalloc = (NPOLY *)(((NVERTEX **)npalloc) + (np->npoints + 4));
}




/*********** TRANSFORMS 'N THINGS ************/

	/* X, Y viewport xform, create new vertex copy if needed */
	/* used during Z clip pass only */

static NVERTEX *xy_transform(VERTEX *v)
{
	VALUE tx, ty, tz;
	NVERTEX *nv;

	if (v->new_copy!=NULL) return(v->new_copy);   /* no new copy req'd */
	else nv = newvertex();

				/* transform coordinates */
	tx = v->x - view_x;  		/* shift origin */
	ty = v->y - view_y;
	tz = v->z - view_z;
						/* transform */
	nv->x = fact1 * tx + fact2 * ty + fact3 * tz;
	nv->y = fact4 * tx + fact5 * ty + fact6 * tz;
	nv->z = v->cz;
	v->new_copy = nv;
	return(nv);                                /* pointer to xformed copy */
}

	/* Z coord transform, generate Z outcode      */
	/* done during Z convert, z outcode pass only */

static void z_transform(VERTEX *v)
{

	v->cz = fact7 * (v->x - view_x) +
		fact8 * (v->y - view_y) +
		fact9 * (v->z - view_z);

	v->z_transformed = 1;

	v->z_outcode = (v->cz < hither) ? HITHER : 0 ;
	if (v->cz > yon) v->z_outcode |= YON ;
}



/********* Z CLIP AND VERTEX COPY *********/

static NVERTEX *nvert[20];     /* table of new poly vertices created and copied */
static int nvcount;            /* table pointer/count (Z clip pass) */
static int nvcptr;		/* pointer for XY clip pass */

static int xy_outcode_and;     /* XY outcode accums used for reject etc */
static int xy_outcode_or;



		     /* int. of edge v1->v2 with hither to nv3 */

static NVERTEX *clip_z_int(VERTEX *v1, VERTEX *v2, NVERTEX *nv3)
{
	NVERTEX *nv1, *nv2;
	float  x1,y1,z1,x2,y2,z2;
	float dv;
			/* copy/xform points if not yet done */
			/* nothing done if already processed */
	nv1 = xy_transform(v1);
	nv2 = xy_transform(v2);

	x1 = nv1->x;               /* get values (BC can't do it inline) */
	y1 = nv1->y;
	z1 = nv1->z;

	x2 = nv2->x;
	y2 = nv2->y;
	z2 = nv2->z;

	if (z1<z2)		     /* always clip edge in same direction */
		{                          /* to hide roundoff errors in integer */
		dv = z1 - z2;
		if (dv!=0.0)               /* just truncate if parallel to edge */
			{
			x1 = x2 + (x1 - x2)*(hither - z2)/dv;
			y1 = y2 + (y1 - y2)*(hither - z2)/dv;
			}
		}
	else
		{
		dv = z2 - z1;
		if (dv!=0.0)
			{
			x1 = x1 + (x2 - x1)*(hither - z1)/dv;
			y1 = y1 + (y2 - y1)*(hither - z1)/dv;
			}
		}

	nv3->x = x1;
	nv3->y = y1;
	nv3->z = hither;      /* Z is known already */

	return(nv3);
}


				  /* final processing for vertex passed */
				  /* by clipper.  Figure perspective    */
				  /* screen positions and poly outcodes */
static NVERTEX *z_output(NVERTEX *nv) 	  /* XY for trivial accept/reject       */
{
	if (nv->perspect == 0) 		    /* if not yet done... */
		{
		nv->xs = nv->x / nv->z + hsw;    /* perspective XY */
		nv->ys = nv->y / -nv->z + hsh;

		nv->outcode = (nv->ys < top) ? TOP : 0;       /* generate XY outcodes */
		if (nv->ys > bottom) nv->outcode |= BOTTOM;
		if (nv->xs < left)   nv->outcode |= LEFT;
		if (nv->xs > right)  nv->outcode |= RIGHT;
		nv->perspect = 1;
		}

	xy_outcode_or  |=  nv->outcode;                 /* track outcodes */
	xy_outcode_and &=  nv->outcode;

	nvert[nvcount] = nv;
	assert(nvcount < 20);
	nvcount++;
	return(nv);
}



	       /* clipper record variables */

static int first_z;           /* 1 if first vertex in pass  */
static int first_z_out;       /* Z outcode of first vertex  */
static VERTEX *first_z_vtx;   /* orig. (world) first vertex */
static int last_z_out;        /* previous vertex Z outcode  */
static VERTEX *last_z_vtx;    /* orig. (world) prev. vertex */


static NVERTEX *z_clip_and_copy(VERTEX *v)   /* Z hither clipper */
{				      /* set first=1 before first call */
				      /* call with all (orig.) vertices */
	NVERTEX *nv;			      /* call with NULL to flush */
				      /* also does XY xform, copy */

	if (first_z)          /* first vertex processing */
		{
		first_z = 0;                      /* save it */
		first_z_vtx = last_z_vtx = v;
		first_z_out = last_z_out = v->z_outcode & HITHER;
		if (first_z_out) return(NULL);

		return( z_output( xy_transform(v) ) );  /* output it if OK */
		}
	else if (v == NULL)    		/* flush clipper processing */
		{
		if (first_z_out == last_z_out) return(NULL);  /* no flush needed */
		return(	z_output( clip_z_int(last_z_vtx, first_z_vtx, newvertex()) ) );
		}
	else                        /* normal vertex process: */
		{                          /* output intersection if crosses hither */
		if (last_z_out != (v->z_outcode & HITHER))
			z_output( clip_z_int(last_z_vtx, v, newvertex()) );

		if ((last_z_out = v->z_outcode & HITHER) == 0)  /* output vtx if OK */
			z_output( xy_transform(v));

		last_z_vtx = v;          /* record last vertex data for next vtx */
		return(v->new_copy);
		}
}



/*************** XY POLYGON CLIPPER **************/

     /* clipper record variables: */
				   /* top clipper: */
static int first_top;              /* 1 if first vertex in pass  */
static NVERTEX *first_top_vtx;     /* first vertex */
static NVERTEX *last_top_vtx;      /* prev. vertex */


static NVERTEX *first_bottom_vtx;  /* bottom clipper */
static NVERTEX *last_bottom_vtx;


static NVERTEX *first_left_vtx;    /* left clipper */
static NVERTEX *last_left_vtx;


static NVERTEX *first_right_vtx;   /* right clipper */
static NVERTEX *last_right_vtx;

static NVERTEX **vpoly;		   /* where to put output */


static void init_XY_clip(NPOLY *np)       /* initialize clipper */
{
	vpoly = np->points;
	last_top_vtx = last_bottom_vtx = last_left_vtx = last_right_vtx = NULL;
}



static NVERTEX *y_intercept(NVERTEX *v1, NVERTEX *v2, float edge)
{
	NVERTEX *nv = newvertex();	  /* create new vertex */

	float dv;
	float  x1 = v1->xs;               /* get values (BC can't do it inline) */
	float  y1 = v1->ys;
	float  z1 = v1->z;

	float  x2 = v2->xs;
	float  y2 = v2->ys;
	float  z2 = v2->z;

	if (y1 < y2)            /* always clip in same dir. to fix roundoff */
		{
		dv = y1 - y2;
		if (dv != 0.0)      /* just truncate if parallel to edge */
			{
			z1 = z2 + (z1 - z2)*(edge - y2)/dv;
			x1 = x2 + (x1 - x2)*(edge - y2)/dv;
			}
		}
	else
		{
		dv = y2 - y1;
		if (dv!=0.0)
			{
			z1 = z1 + (z2 - z1)*(edge - y1)/dv;
			x1 = x1 + (x2 - x1)*(edge - y1)/dv;
			}
		}

	nv->xs = x1;
	nv->ys = edge;
	nv->z = z1;
	return(nv);
}


static NVERTEX *x_intercept(NVERTEX *v1, NVERTEX *v2, float edge)
{
	NVERTEX *nv = newvertex();	  /* create new vertex */

	float dv;
	float  x1 = v1->xs;               /* get values (BC can't do it inline) */
	float  y1 = v1->ys;
	float  z1 = v1->z;

	float  x2 = v2->xs;
	float  y2 = v2->ys;
	float  z2 = v2->z;

	if (x1<x2)	    /* always clip in same dir. to fix roundoff */
		{
		dv = x1 - x2;
		if (dv!=0.0)      /* just truncate if parallel to edge */
			{
			z1 = z2 + (z1 - z2)*(edge - x2)/dv;
			y1 = y2 + (y1 - y2)*(edge - x2)/dv;
			}
		}
	else
		{
		dv = x2 - x1;
		if (dv!=0.0)
			{
			z1 = z1 + (z2 - z1)*(edge - x1)/dv;
			y1 = y1 + (y2 - y1)*(edge - x1)/dv;
			}
		}

	nv->xs = edge;
	nv->ys = y1;
	nv->z = z1;
	return(nv);
}




static void XY_clip(NVERTEX *v, int stage)   /* XY semirecursive clipper 	  */
{				      /* set last = NULL before first call */
				      /* call with all (copied) vertices  */
	NVERTEX *nv;      /* call with NULL to flush 	  */
				      /* also copies output to poly table */

	switch(stage)
		{
		case BOTTOM: goto bottom_clip;
		case LEFT:   goto left_clip;
		case RIGHT:  goto right_clip;
		}
				/* can use outcode in top clip */
top_clip:                       /* but may not be valid later  */
	if (last_top_vtx == NULL)              /* first vertex? */
		{
		first_top_vtx = last_top_vtx = v;              /* save it */
		if ((v->outcode & TOP) == 0) goto right_clip;   /* "output" if OK */
		else return;                                   /* else get next  */
		}
	else if (v == NULL)    		/* flush clipper processing */
		{
		if ((first_top_vtx->outcode & TOP)!=(last_top_vtx->outcode & TOP))
			{
			nv = y_intercept(first_top_vtx, last_top_vtx, top);
			XY_clip(nv,RIGHT); 		   /* process this new point */
			}
		goto right_clip;           /* and continue flush */
		}
	else                          /* normal vertex process: */
		{                            /* output intersection if crosses top */
		if ((v->outcode & TOP)!=(last_top_vtx->outcode & TOP))
			{
			nv = y_intercept(v, last_top_vtx, top);
			XY_clip(nv,RIGHT); 	/* process this new point */
			}
		last_top_vtx = v;
		if ((v->outcode & TOP) == 0) goto right_clip;  /* "output" if OK */
		else return;                                  /* else get next  */
		}



right_clip:  /* goto end_clip; */

	if (last_right_vtx == NULL)               /* first vertex? */
		{
		first_right_vtx = last_right_vtx = v;  /* save it */
		if (v->xs <= right) goto bottom_clip;   /* "output" if OK */
		else return;                           /* else get next  */
		}
	else if (v == NULL)    		/* flush clipper processing */
		{
		if ((first_right_vtx->xs > right)!=(last_right_vtx->xs > right))
			{
			nv = x_intercept(first_right_vtx, last_right_vtx, right);
			XY_clip(nv,BOTTOM); 		     /* process this new point */
			}
		goto bottom_clip;          /* and continue flush */
		}
	else                        /* normal vertex process: */
		{                          /* output intersection if crosses right */
		if ((v->xs > right)!=(last_right_vtx->xs > right))
			{
			nv = x_intercept(v, last_right_vtx, right);
			XY_clip(nv,BOTTOM); 	/* process this new point */
			}
		last_right_vtx = v;
		if (v->xs <= right) goto bottom_clip;  /* "output" if OK */
		else return;                          /* else get next  */
		}



bottom_clip: /* goto end_clip; */

	if (last_bottom_vtx == NULL)               /* first vertex? */
		{
		first_bottom_vtx = last_bottom_vtx = v;  /* save it */
		if (v->ys <= bottom) goto left_clip;    /* "output" if OK */
		else return;                             /* else get next  */
		}
	else if (v == NULL)    		/* flush clipper processing */
		{
		if ((first_bottom_vtx->ys > bottom)!=(last_bottom_vtx->ys > bottom))
			{
			nv = y_intercept(first_bottom_vtx, last_bottom_vtx, bottom);
			XY_clip(nv,LEFT); 	/* process this new point */
			}
		goto left_clip;	/* and continue flush */
		}
	else                          /* normal vertex process: */
		{                            /* output intersection if crosses bottom */
		if ((v->ys > bottom)!=(last_bottom_vtx->ys > bottom))
			{
			nv = y_intercept(v, last_bottom_vtx, bottom);
			XY_clip(nv,LEFT); 	/* process this new point */
			}
		last_bottom_vtx = v;
		if (v->ys <= bottom) goto left_clip;  /* "output" if OK */
		else return;                          /* else get next  */
		}



left_clip:  /* goto end_clip; */

	if (last_left_vtx == NULL)                /* first vertex? */
		{
		first_left_vtx = last_left_vtx = v;    /* save it */
		if (v->xs >= left) goto end_clip;      /* "output" if OK */
		else return;                           /* else get next  */
		}
	else if (v == NULL)    		/* flush clipper processing */
		{
		if ((first_left_vtx->xs < left)!=(last_left_vtx->xs < left))
			{
			nv = x_intercept(first_left_vtx, last_left_vtx, left);
			*vpoly++ = nv;		/* store the vertex */
			nvcptr++;
			}
		return;                      /* end of flush  */
		}
	else                        /* normal vertex process: */
		{                         /* output intersection if crosses left */
		if ((v->xs < left)!=(last_left_vtx->xs < left))
			{
			nv = x_intercept(v, last_left_vtx, left);
			*vpoly++ = nv;		/* store the vertex */
			nvcptr++;
			}
		last_left_vtx = v;
		if (v->xs >= left) goto end_clip;     /* "output" if OK */
		else return;                         /* else get next  */
		}


end_clip:
	*vpoly++ = v;		/* store the vertex */
	nvcptr++;              /* ideal point to remove extra bits from XYZ */
}




/*************** POLYGON CLIP AND PROCESS *************/

				/* test for backfacing poly */
static int backfacing(POLY *p)
{
	return (p->normalx * (view_x - p->points[0]->x) +
		p->normaly * (view_y - p->points[0]->y) +
		p->normalz * (view_z - p->points[0]->z)) <= 0.0;
}




static int light_poly(NPOLY *p)
{

	POLY *pp = p->parent;
	VERTEX *v0 = pp->points[0];

	float nx = pp->normalx;          /* unit length poly normal */
	float ny = pp->normaly;
	float nz = pp->normalz;

	float dlx = light_x - v0->x;     /* vector from light source */
	float dly = light_y - v0->y;
	float dlz = light_z - v0->z;

	float light, mag;

	/* compute vector from light source to surface  */
	/* find dot product, normalize by vector length */
	/* returns 16...31 for now (light+diffuse)      */

	mag = sqrt(dlx*dlx + dly*dly + dlz*dlz); /* magnitude of light vector */
	light = dlx*nx + dly*ny + dlz*nz;        /* dot product */
	light = light/mag;                       /* cosine */

	light = (light*8) + 8;       /* offset-cosine w/backlight (looks OK) */
	if (light<0) light = 0;
	if (light>15) light = 15;

	return(16 + light);  /* 4 bits hue, 4 bits intensity eventually */
}





static void proc_poly(POLY *p)  /* accept/reject tests on polys */
{                               /* transforms vertices, clips   */
	int i;                         /* and computes screen coords   */
	int z_outcode_or  = 0;         /* Also copies polys and points */
	int z_outcode_and = 3;         /* for minimum disruption of    */
	VERTEX *v;                     /* the world database           */
	NVERTEX *nv;
	NPOLY *np;

				/* skip backfacing polygons */
	if (backfacing(p)) return;

		/* scan through the poly's points, transforming Z
		    and doing outcode clipping to hither and yon   */

	for (i = 0; i < p->npoints; ++i)       /* Z transform pass */
		{
		v = p->points[i];
		if (!v->z_transformed)  		/* transform Z coordinate */
			z_transform(v);
		z_outcode_or |= v->z_outcode;        /* track outcodes */
		z_outcode_and &= v->z_outcode;
		}




	if (z_outcode_and) return;       /* all hither/yon? Reject poly */


			/* otherwise, begin Z clip and XY transforms */
	xy_outcode_or  = 0;
	xy_outcode_and = 0xFF;   /* Z-clip pass setup */
	first_z = 1;
	nvcount = 0;                        /* Pass 2: */
				     /* Z-clip and XY conv. vertices   */
				     /* also make copies to temp array */

	for (i = 0; i < p->npoints; ++i) z_clip_and_copy(p->points[i]);

	z_clip_and_copy(NULL);              /* Flush clipper */

	if (nvcount<3 || xy_outcode_and) return;   /* reject poly if degenerate */
					   /* or XY clip will delete it */


	np = newpoly();               /* create copy of poly for XY clip */
	np->parent = p;
	np->color = light_poly(np);
	np->npoints = nvcount;

	allocvarray(np);              /* space for vertex array (see note) */


	if ((xy_outcode_or) == 0)		/* does poly need XY clipping? */
		for (i = 0; i < nvcount; i++) np->points[i] = nvert[i] ;  /* no: copy it */
	else                           /* yes: XY clip it */
		{
		init_XY_clip(np);         /* initialize clipper */
		nvcptr = 0;
				/* clip all vertices */
		for (i = 0; i < nvcount; i++)  XY_clip(nvert[i], TOP);
		XY_clip(NULL, TOP);         /* flush pending vertices  */

		if (nvcptr < 3) return;      /* discard degenerate poly */
		np->npoints = nvcptr;       /* set point count */
		}



	np->maxz = -1e9;        /* also keep track of maximum Z for poly */

	for (i = 0; i < np->npoints; ++i)
		if (np->points[i]->z > np->maxz) np->maxz = np->points[i]->z;
			       /* add to list of polys to render */
	if (npols < MAXPOLYS)	vispolys[npols++] = np;
}


/************ OBJECT-CLIPPING STUFF **************/

/*
   Some background: we compute the coefficients of the left, right, top and
   bottom clipping planes, and use these to do bounding-sphere testing.
   The routine define_view_volume() computes the various plane normals
   and use to measure the distance from the plane to the sphere center.
   Actual math is mixed up for efficiency.
*/



static int clip_by_volume(OBJECT *obj)
{
	float sx, sy, sz;	
	float ca,cb;

	float tx = obj->sphx - view_x;   /* sphere center, relative to viewpoint */
	float ty = obj->sphy - view_y;
	float tz = obj->sphz - view_z;

	float r = obj->sphr;

     /* transform Z coord of bounding sphere; keep for optional depth sort */
	obj->z_coordinate = sz = fac7 * tx + fac8 * ty + fac9 * tz;

	if (sz + r < hither) return 1;  /* front clip */
	if (sz - r > yon) return 2;     /* back clip */

		/* transform X coordinate of bounding sphere */
	sx = fac1 * tx + fac2 * ty + fac3 * tz;

	ca = -hor_C * sz - r;
	cb = hor_M * sx;
	if (ca > cb) return 3;    /* left */
	if (ca > -cb) return 4;   /* right */

		/* transform Y coordinate of bounding sphere */
	sy = fac4 * tx + fac5 * ty + fac6 * tz;

	ca = -vert_C * sz - r;
	cb = vert_M * sy;
	if (ca > cb) return 5;    /* bottom */
	if (ca > -cb) return 6;   /* top    */

	/* otherwise, it's at least partially inside the viewing volume */
	return 0;
}



/*********** OBJECT-RENDERING CONTROL **********/


static int proc_obj(OBJECT *obj)
{
	int i;

	if ((i = clip_by_volume(obj)) != 0) return i; /* return non-zero, object clipped */

	for (i = 0; i < obj->nverts; ++i)             /* at first, no transforms done */
		{
		obj->verts[i].new_copy = NULL;
		obj->verts[i].z_transformed = 0;
		}


	for (i = 0; i < obj->npolys; ++i)  	       /* process polygons */
		proc_poly(&obj->polys[i]);

	return 0;  /* return 0, object not clipped */
}


static int polsort(void *pol1, void *pol2)  /* used for sorting vispolys[] */
{
	NPOLY *p1, *p2;

	p1 = *((NPOLY **) pol1); p2 = *((NPOLY **) pol2);
	if (p1->maxz > p2->maxz) return -1;
	if (p1->maxz < p2->maxz) return  1;
	return 0;
}



void render(OBJECT *objlist, VIEW *view, int v_page)
{
	OBJECT *obj;
	int i;

	init_render();
	set_view(view);
	npols = 0;
					/* do clipping and transforms */
	for (obj = objlist; obj; obj = obj->next) proc_obj(obj);

					/* sort polys by max Z */
	qsort(vispolys, npols, sizeof(NPOLY *), polsort);

	clear_display(v_page);
	set_drawpage(v_page);
	for (i = 0; i < npols; ++i) render_poly(vispolys[i]);
}
