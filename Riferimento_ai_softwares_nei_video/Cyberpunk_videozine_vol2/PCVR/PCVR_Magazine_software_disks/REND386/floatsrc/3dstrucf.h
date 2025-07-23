/* Data structures for the REND386 package */

/* Copyright 1992 by Dave Stampe and Bernie Roehl */

/* Written by Bernie Roehl and Dave Stampe, December 1991 */
/* updated 10/1/91 for renderer clip (first stage) */
/* Integerization finished 19/1/92 and comments added by Dave Stampe */
/* RE_FLOATED VERSION AS EXAMPLE CODE begin 20/1/92*/

typedef int COLOR;
typedef float VALUE;    /* where still needed */
typedef float ANGLE;    /* where still needed */


/* new vertex copies, internal to renderer */

typedef struct nV NVERTEX;
struct nV{
	float x, y, z;          /* viewport coordinates */
	float xs, ys;           /* screen coordinates */
	unsigned char outcode;  /* XY clip outcodes */
	unsigned char perspect; /* flags perspective done */
	};

#define LEFT    1    /* XY outcode bits */
#define RIGHT   2
#define TOP     4
#define BOTTOM  8


/* world database vertices */
/* object coords are referenced to object */
/* world coords are updated when moving or rotating object */
/* all others are renderer workspace */

typedef struct {
	float ox, oy, oz;               /* object coordinates */
	float x, y, z;                  /* world coordinates */
	float cz;                       /* converted Z coord */
	NVERTEX *new_copy;              /* non-NULL if x and y transformed */
	unsigned char z_transformed;    /* non-zero if z has been transformed */
	unsigned char z_outcode;        /* 1 set if hither, 2 set if yon */
	} VERTEX;

#define HITHER 1    /* Z outcode bits */
#define YON    2


/* world database polys */
/* object-based normal must be rotated to world copy with object */

typedef struct {
	COLOR color;       /* color (not used yet-- will set chroma, reflectance */
	VERTEX **points;   /* array of pointers to the vertices of this polygon */
	int npoints;       /* number of entries in points[] */
	float onormalx,	onormaly, onormalz; /* unit length surface normal (OBJECT) */
	float normalx, normaly, normalz;    /* unit length surface normal (WORLD)*/
	} POLY;


/* renderer poly copy */
/* parent points back to original poly for lighting */
/* color computed by cosine lighting (currently 0-15) */
/* maxz is deepest poly point for sorting */

typedef struct {
	POLY *parent;
	NVERTEX **points;   /* array of pointers to the vertices of this polygon */
	int npoints;        /* number of entries in points[] */
	int color;          /* color after illumination	*/
	float maxz;         /* maximum Z value (for sorting) */
	} NPOLY;


/* world database object */
/* vertex list used for preclearing vertex flags (z_transformed, new_copy) */
/* sphx, sphy, sphz, sphr used for clipping object using bounding sphere   */

typedef struct _object {
	VERTEX *verts;   /* array of vertices in the object */
	int nverts;      /* number of entries in verts[] */
	POLY *polys;     /* array of polygons composing the object */
	int npolys;      /* number of entries in polys[] */
	float sphx, sphy, sphz, sphr; /* bounding sphere center and radius */
	float z_coordinate;           /* for optional depth sorting by object */
	unsigned char invisible;      /* set if object should not be drawn */
	struct _object *next;
	} OBJECT;


/* renderer viewpoint/screen control structure */
/* viewoint in X, Y, Z coords */
/* zoom is equiv. to magnification from 90 deg. FOV */
/* aspect sets how much to magnify Y more than X to fix up displays */
/* light source point in world coordinates */
/* left, right, top, bottom set edges of screen */
/* hither sets closest point: keep >16 for best range of world coords */
/* yon sets max. distance: keep it 1<<26 if not used */
/* all others are renderer workspace */

typedef struct {
	/* VIEWPOINT */
	float ex, ey, ez;       /* location of eyepoint         */
	float pan, tilt, roll;  /* viewing angles (deg) +/- 128 */
	float zoom;             /* 1/tan(H FOV/2) 0.5 to 16     */
	float lx,ly,lz;         /* location of light source     */

	/* SCREEN DATA */
	float left,right;       /* clipping planes */
	float top, bottom;
	float hither, yon;      /* near and far clipping planes  */
	float aspect;           /* x:y fixup factor (magnify Y by..*/

	/* INTERNAL RECORDS */
	float hsw, hsh;         /* half screen width, height */
	float hsc, vsc;         /* screen center */

	float fac1,fac2,fac3,
		fac4,fac5,fac6,
		fac7,fac8,fac9;     /* conversion coefficients */

	float sfac1,sfac2,sfac3, /* scaled conversion factors */
		sfac4,sfac5,sfac6;

	float hor_C, vert_C;    /* spherical clip coefficients */
	float hor_M, vert_M;

	} VIEW;
