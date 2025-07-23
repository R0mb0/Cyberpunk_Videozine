/* Data structures for 3D modelling */

/* Written by Bernie Roehl and Dave Stampe, December 1991 */
/* updated 10/1/91 for renderer clip (first stage */
/* Integerizaation finished 19/1/91 and comments added */

/* Copyright 1991, 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
	 for permission to incorporate any part of this software into their
   products!
 */

/* NOTE ON FORMATS:
 <nn.ff> means that nn bits are available as the integer part, and
 ff bits are used as a fractional part.  Multiply a float by 2^ff
 to get a long value to feed in.

 World coordinates should be kept below signed 24 bits (16.7M) to
 assure no errors.  This allows a range of 1mm->16.7 km, which
 should be plenty!

 Angles are in <16.16> format, where the integer part is in degrees.
*/


#ifndef MATRIXDEF
typedef long MATRIX[4][3];  	  /* 3x3 rotate plus 3 translate para's */
			/* rotate matrix is <3.29>, translate is <32.0> */
#define MATRIXDEF 1
#endif

/* new vertex copies, internal to renderer */

typedef struct nV NVERTEX;
struct nV{
		long  x, y, z;       	  /* viewport coordinates (used for saving time) */
	  long  xs, ys ;          /* screen coordinates */
		unsigned char outcode;  /* XY clip outcodes */
		unsigned char perspect; /* flags perspective done */
		};

#define LEFT   1	/* XY outcode bits */
#define RIGHT  2
#define TOP    4
#define BOTTOM 8



/* world database vertices */
/* object coords are referenced to object */
/* world coords are updated when moving or rotating object */
/* all others are renderer workspace */

typedef struct {
	long ox, oy, oz;   /* object coordinates */
	long x, y, z;      /* world coordinates  */
	long cz;	   /* converted Z coord  */
	NVERTEX *new_copy;  /* non-zero if x and y transformed */
	unsigned char z_transformed;   /* non-zero if z has been transformed */
	unsigned char z_outcode;       /* 1 set if hither, 2 set if yon */
	} VERTEX;

#define HITHER 1	/* Z outcode bits */
#define YON    2


/* world database polys */
/* object-based normal must be rotated to world copy with object */
/* color will have 8-bit color, 8-bit reflectance field */

#ifndef POLYDEF
#define POLYDEF 1

typedef struct {
	unsigned color;   /* color (not used yet-- will set chroma, reflectance */
	VERTEX **points;  /* array of pointers to the vertices of this polygon */
	int npoints;      /* number of entries in points[] */
	long onormalx,
	     onormaly,
	     onormalz;    /* unit length surface normal (OBJECT) */
	long normalx,
	     normaly,
	     normalz;     /* unit length surface normal (WORLD)*/
	struct _object *object;
	} POLY;

#endif


/* renderer poly copy */
/* paernt points back to original poly for lighting */
/* color computed by cosine lighting (currently 0-15) */
/* maxz is deepest poly point for sorting */

typedef struct {
	int npoints;       /* number of entries in points[] MUST BE FIRST */
	POLY *parent;
	unsigned color;	   /* color after illumination */
	long maxz;        /* maximum Z value (for sorting) */
	} NPOLY;


typedef struct { NPOLY *ptr; long depth; } DSORT; /* used for depth sorting */

#ifndef REPDEF
#define REPDEF 1

typedef struct _rep {     /* a representation for an object */
	long size;            /* if the object is bigger than this, use this rep */
	int nverts, npolys;   /* number of vertices, number of polys */
	VERTEX *verts;        /* array of vertices */
	POLY *polys;          /* array of polygons */
	struct _rep *next;    /* pointer to next rep in list */
	long update_count;    /* inc. every time rep moves */
	unsigned flags;
	} REP;

#endif


/* world database object */
/* sphx, sphy, sphz, sphr used for sphere object clipping */

#define OBJ_FLAG_MASK 0x7C00
#define OBJ_DEPTH_MASK 0x03FF

#ifndef OBJDEF
#define OBJDEF 1

typedef struct _object OBJECT;

struct _object
 {
	unsigned int oflags;
#define OBJ_REPLOCK      0x0400
#define OBJ_NONSEL       0x0800 /* can't be selected (i.e. pointer) */
#define OBJ_INVIS        0x1000
#define OBJ_HIGHLIGHTED  0x2000
#define OBJLIST_HEADER   0x4000
#define IS_OBJECT        0x8000	/* required by renderer: it will set */


#define DEEPEST 0x0000		/* sort polys by deepest point */
#define ATBACK  0x0001		/* push this object's poly's waaaay back */
#define AVERAGE 0x0002		/* sort polys by average depth */

#define BYOBJECT   0x0100	/* sort by object */
#define BYPOLY     0x0000	/* put polys in world before sort */

	struct _object *prev;
	struct _object *nnext;

	void *owner;       /* for example, a body segment description struct */
	REP *replist;              /* pointer to list of representations */
	REP *current_rep;          /* the currently-active rep */
	int (*coll_eval)(OBJECT *obj, long x, long y, long z);    /* evaluate collision */

	long osphx, osphy, osphz;     /* object-coord sphere center */
	long sphx, sphy, sphz, sphr;  /* bounding sphere center and radius */
	long update_count;         /* inc. every time object moved */
	float sclx,scly,sclz;
	char obj_name[15];
	char obj_filename[20];
 };

#endif


/* world database object list head */
/* dual linked for fast remove/insert needed for splits */

#ifndef OBJLDEF
#define OBJLDEF 1

typedef struct _objlist
 {
	unsigned int oflags;
#define OBJ_INVIS        0x1000
#define OBJ_HIGHLIGHTED  0x2000
#define OBJLIST_HEADER   0x4000
#define IS_OBJECT        0x8000	/* required by renderer: it will set */

	struct _object *prev;
	struct _object *nnext;
 } OBJLIST;

#endif


#ifndef VIEWDEF
/* renderer viewpoint/screen control structure */
/* viewoint in X, Y, Z coords */
/* pan, tilt, roll in (float*65536) formats */
/* zoom is equiv. to magnification from 90 deg. FOV (also float*65536) */
/* aspect sets how much to magnify Y more than X to fix up displays */
/* light source point in world coordinates */
/* left, right, top, bottom set edges of screen */
/* hither sets closest point: keep >16 for best range of world coords */
/* yon sets max. distance: keep it 1<<26 if not used */
/* all others are renderer workspace */

#define NOFLIP 0      /* for orientation flags */
#define XFLIP  1
#define YFLIP  2

typedef struct {
		     /* VIEWPOINT */
	long ex, ey, ez;        /* <25.0>  location of eyepoint         */
	long pan, tilt, roll;   /* <16.16> viewing angles (deg) +/- 128 */
	long zoom;              /* <16.16> 1/tan(H FOV/2) 0.5 to 16     */
		/* Light source stuff... will eventually be separate from view struct */
	long lx,ly,lz;		/* <25.0>  location of light source     */
	int  directional;	/* 0 for point, 1 for normal (not unit) */
	int  ambient;		/* ambient light: 0-256 (72 recc.)      */

				 /* SCREEN DATA */
	long left,right;        /* <25.0> clipping planes */
	long top, bottom;
	long hither, yon;   /* <25.0> near and far clipping planes   */
	long aspect;		/* <16.16> x:y fixup factor (magnify Y by..*/

	/* RENDERING CONTROL */
	unsigned flags;     /* 16 bits of flags */

				 /* ADVANCED SCREEN DATA */
	long x_offset, y_offset; /* amount to move screen center in pixels */
	unsigned orientation;    /* used to mirror screen image */
	MATRIX eye_xform;

		     /* INTERNAL RECORDS */
	long hsw, hsh;		/* half screen width, height */
	long hsc, vsc;		/* screen center (with offset) */
	long scx, scy;		/* full-resolution scaling for horizon */
	long sx,sy;		/* mantissa of screen scaling  */
	int  xshift, yshift;    /* scaling bit shifts */

	long left_C, left_M;    /* spherical clip coefficients */
	long right_C, right_M;
	long top_C, top_M;
	long bot_C, bot_M;

	long fac1,fac2,fac3,
	     fac4,fac5,fac6,
	     fac7,fac8,fac9;    /* conversion coefficients */

	long sfac1,sfac2,sfac3, /* scaled conversion factors */
			 sfac4,sfac5,sfac6;

	long hor_C, vert_C;     /* spherical clip coefficients */
	long hor_M, vert_M;

	       } VIEW;

/* View flags: */

#define WIREFRAME           0x0001
#define HIDE_HIGHLIGHTED    0x0002
#define HIDE_UNHIGHLIGHTED  0x0004
#define VIEWDEF 1
#endif

/* Prescaling (used in hrendo5.c and 3dsupp.c (in where_screen_pt()) */

#define PRESCALE  2	/* frac bits in XY coords */
#define PRESCALEZ 2

#ifndef SCRIDEF
#define SCRIDEF 1
struct Screeninfo {
	int xmin, ymin, xmax, ymax, xcent, ycent, colors, pages, bw;
	long aspect;
	char id[80];
	};
#endif


extern struct Screeninfo *screeninfo;

extern long isine(long angle);
extern long icosine(long angle);
					/* create rotation/translation */
					/* "matrix" from angle data    */
					/* CALL setup_render FIRST!    */

/* End of structs */

extern void set_screen_monitor(int x, int y);
extern void clear_screen_monitor();
extern POLY * read_screen_monitor();

/* Provided by user, in render.c: */

extern void user_render_poly(int vertex_count, int *pcoords,
                             unsigned poly_color, long max_depth);
extern void user_setup_blitter();
extern void user_reset_blitter();

/* End of 3dstruct.h */

