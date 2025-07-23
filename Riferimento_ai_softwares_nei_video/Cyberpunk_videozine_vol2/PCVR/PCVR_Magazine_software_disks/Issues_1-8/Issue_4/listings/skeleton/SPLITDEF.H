/* Splitting-tree structures */

/* Written by Bernie Roehl, June 1992 */
/* Substantially upgraded by Dave Stampe, August '92 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */


#ifndef SPLITDEF
typedef struct _split SPLIT;

struct _split {
	long x, y, z;    /* a point in the splitting plane */
	long nx, ny, nz; /* the normal vector to the splitting plane */
	OBJLIST *olist;  /* list of objects making up this split */
	unsigned flags;
	char left_type;  /* indicates what the left pointer points to */
	char right_type; /* indicates what the right pointer points to */
#define ISSPLIT    0
#define ISAREA     1
#define ISOBJLIST  2
	void *left, *right; /* can point to a split, an area or an objlists */
	};

#define SPLITDEF 1
#endif

#ifndef AREADEF
typedef struct _area AREA;
#endif

typedef struct _area_ref AREA_REF; /* element in a list of area pointers */

struct _area_ref {
	AREA *area;
	AREA_REF *next;
	};

#ifndef AREADEF
struct _area {
	long floor_a, floor_b, floor_c, floor_d; /* ax + y + cx + d = 0 */
	long ceiling_a, ceiling_b, ceiling_c, ceiling_d; /* ax + y + cx + d = 0 */
	void (*fn)();
	AREA_REF *visfrom;
	int has_tree : 1;
	void *ptr;
	};
#define AREADEF 1
#endif

/* End of splitdef.h */
