/* Routines for dealing with segmented figures */

/* Written by Bernie Roehl, March 1992 */
/* Major paradigm shift: Dave Stampe, Aug. '92 */

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

#include <stdio.h>
#include <alloc.h>
#include <string.h>
#include "3dstruct.h"
#include "intmath.h"

typedef struct _segment SEGMENT;

static int fix_init = 100;


struct _segment {
	SEGMENT *parent, *child, *sibling;
	MATRIX jmatrix; /* joint relationship */
	MATRIX pmatrix; /* world position     */
	OBJECT *object;
	long rx, ry, rz; /* added for animation control */
	SEGMENT *root;
	char *name;
	unsigned flags; /* if bit 0 set, segment has been modified */
	unsigned fix_count; /* used to fix scale after rel_rotate      */
#define SEG_MODIFIED   1
};

SEGMENT *find_root_segment(SEGMENT *s)
{
	SEGMENT *ss = s;
	while (s->parent) s = s->parent;
	ss->root = s; /* ADDED FOR ANIMATION */
	return s;
}

SEGMENT *get_root_segment(SEGMENT *s)
{
	return s->root; /* ADDED FOR ANIMATION */
}

SEGMENT *new_seg(SEGMENT *parent)
{
	SEGMENT *s;

	if ((s = malloc(sizeof(SEGMENT))) == NULL) return NULL;
	s->parent = parent;
	s->child = NULL;
	if (parent)
	{
		s->sibling = parent->child;
		parent->child = s;
	}
	else s->sibling = NULL;

	identity_matrix(s->jmatrix);
	if (parent) memcpy(&(s->pmatrix), &(parent->pmatrix), sizeof(MATRIX));
	else identity_matrix(s->pmatrix);

	s->object = NULL;
	s->flags = 1;
	s->name = NULL;
	find_root_segment(s);
	s->rx = s->ry = s->rz = 0;
	s->fix_count = fix_init;
	fix_init = (fix_init+7) & 0x7F; /* pseudorandom to prevent clumping */

	return s;
}

void seg_set_object(SEGMENT *s, void *app)
{
	s->object = app;
	s->flags |= 1;
}

void *seg_get_object(SEGMENT *s)
{
	return s->object;
}

char *seg_getname(SEGMENT *s)
{
	return s->name;
}

void seg_setname(SEGMENT *s, char *name)
{
	s->name = strdup(name);
}

void seg_getposang(SEGMENT *s, long *rx, long *ry, long *rz)
{
	matrix_to_angle(s->pmatrix, rx, ry, rz);
}

void seg_getjointang(SEGMENT *s, long *rx, long *ry, long *rz)
{
	matrix_to_angle(s->jmatrix, rx, ry, rz);
	s->rx = *rx;
	s->ry = *ry; /* ADDED FOR ANIMATION */
	s->rz = *rz;
}

void seg_getrxyz(SEGMENT *s, long *rx, long *ry, long *rz)
{
	*rx = s->rx; /* ADDED FOR ANIMATION */
	*ry = s->ry;
	*rz = s->rz;
}

void seg_getposxyz(SEGMENT *s, long *x, long *y, long *z)
{
	*x = s->pmatrix[3][0];
	*y = s->pmatrix[3][1];
	*z = s->pmatrix[3][2];
}

void seg_getjointxyz(SEGMENT *s, long *x, long *y, long *z)
{
	*x = s->jmatrix[3][0];
	*y = s->jmatrix[3][1];
	*z = s->jmatrix[3][2];
}


void abs_move_segment(SEGMENT *s, long tx, long ty, long tz)
{
	s->jmatrix[3][0] = tx;
	s->jmatrix[3][1] = ty;
	s->jmatrix[3][2] = tz;
	s->flags |= 1;
}

void rel_move_segment(SEGMENT *s, long tx, long ty, long tz)
{
	s->jmatrix[3][0] += tx;
	s->jmatrix[3][1] += ty;
	s->jmatrix[3][2] += tz;
	s->flags |= 1;
}


void abs_mat_segment(SEGMENT *s, MATRIX m)
{
	memcpy(s->jmatrix, m, sizeof(MATRIX));
	s-> flags |= 1;
}


void rel_mat_segment(SEGMENT *s, MATRIX m)
{
	matrix_product(s->jmatrix, m, s->jmatrix);
	s-> flags |= 1;
	s->fix_count--;
	if (s->fix_count == 0)
	{
		s->fix_count = fix_init;
		fix_init = (fix_init+7) & 0x7F; /* pseudorandom to prevent clumping */
		fix_matrix_scale(s->jmatrix);
	}
}


void abs_rotmat_segment(SEGMENT *s, MATRIX m)
{
	s->jmatrix[0][0] = m[0][0];
	s->jmatrix[0][1] = m[0][1];
	s->jmatrix[0][2] = m[0][2];
	s->jmatrix[1][0] = m[1][0];
	s->jmatrix[1][1] = m[1][1];
	s->jmatrix[1][2] = m[1][2];
	s->jmatrix[2][0] = m[2][0];
	s->jmatrix[2][1] = m[2][1];
	s->jmatrix[2][2] = m[2][2];
	s->flags |= 1;
}


void rel_rotmat_segment(SEGMENT *s, MATRIX m)
{
	matrix_mult(s->jmatrix, m, s->jmatrix);
	s-> flags |= 1;
	s->fix_count--;
	if (s->fix_count == 0)
	{
		s->fix_count = fix_init;
		fix_init = (fix_init+7) & 0x7F; /* pseudorandom to prevent clumping */
		fix_matrix_scale(s->jmatrix);
	}
}

#define RXYZ 1		/* matrix rotation orders            */
#define RYXZ 0          /* ONLY RYXZ guaranteed to be tested */
#define RXZY 2
#define RZYX 5
#define RZXY 4
#define RYZX 6

void abs_rot_segment(SEGMENT *s, long rx, long ry, long rz, int order)
{
	MATRIX m;
	multi_matrix(m, rx, ry, rz, 0, 0, 0, order);
	s->rx = rx;
	s->ry = ry; /* ADDED FOR ANIMATION */
	s->rz = rz;
	abs_rotmat_segment(s, m);
}

void rel_rot_segment(SEGMENT *s, long rx, long ry, long rz, int order)
{
	MATRIX m;
	multi_matrix(m, rx, ry, rz, 0, 0, 0, order);
	rel_rotmat_segment(s, m);
}


void move_rep(OBJECT *obj) /* move current rep of object  */
{ /* called from renderer itself */
	REP *rep = obj->current_rep;
	SEGMENT *s = obj->owner;

	matmove_rep(rep, s->pmatrix);
}


static void (*move_handler)(OBJECT *) = NULL; /* called when object moved */

void set_move_handler(void (*move_handler_ptr)(OBJECT *))
{
	move_handler = move_handler_ptr;
}


void full_update_segment(SEGMENT *seg)
{
	SEGMENT *s;
	OBJECT *obj;

	seg->flags &= ~1;
	if (seg->parent)
		matrix_product(seg->parent->pmatrix, seg->jmatrix, seg->pmatrix);
	else
		memcpy(&(seg->pmatrix), &(seg->jmatrix), sizeof(MATRIX));

	if ((obj = seg->object)!=NULL)
	{
		matmove_osphere(obj, seg->pmatrix);
		obj->owner = seg; /* just to be safe...       */
		if (move_handler) move_handler(obj); /* this moves in split tree */
	}

	for (s = seg->child; s; s = s->sibling) full_update_segment(s);
}


void update_segment(SEGMENT *seg) /* scan till update needed */
{
	SEGMENT *s;

	if (seg->flags & 1)
		full_update_segment(seg);
	else
		for (s = seg->child; s; s = s->sibling) update_segment(s);
}

int seg_get_flags(SEGMENT *s)
{
	return s->flags & 0xFFFE ;
}

void seg_set_flags(SEGMENT *s, int f)
{
	s->flags = (s->flags&1)|(f&0xFFFE);
}


SEGMENT *parent_segment(SEGMENT *s)
{
	return s->parent;
}

SEGMENT *child_segment(SEGMENT *s)
{
	return s->child;
}

SEGMENT *sibling_segment(SEGMENT *s)
{
	return s->sibling;
}

MATRIX *get_seg_jmatrix(SEGMENT *s)
{
	return &s->jmatrix;
}

MATRIX *get_seg_pmatrix(SEGMENT *s)
{
	return &s->pmatrix;
}


void detach_segment(SEGMENT *s) /* assumes segment is updated! */
{
	SEGMENT *p;
	MATRIX n;

	if ((p = s->parent) == NULL) return;
	s->parent = NULL;
	memcpy(&(s->jmatrix), &(s->pmatrix), sizeof(MATRIX));
	s->flags |= 1;
	if (p->child == s)
	{
		p->child = s->sibling;
		s->sibling = NULL;
		return;
	}
	for (p = p->child; p->sibling; p = p->sibling)
		if (p->sibling == s)
		{
			p->sibling = s->sibling;
			s->sibling = NULL;
			return;
		}
	update_segment(s);
}

void attach_segment(SEGMENT *s, SEGMENT *to) /* assumes parent is updated! */
{
	MATRIX m,n;

	if (s->parent) detach_segment(s);
	s->parent = to;
	s->sibling = to->child;
	to->child = s;

	inverse_matrix(to->pmatrix, m);
	matrix_product(m, s->pmatrix, s->jmatrix);
	s->flags &= ~1;
	to->flags |= 1;
	update_segment(to);
}

void delete_segment(SEGMENT *s, void (*delapp_fn)(OBJECT *))
{
	SEGMENT *p, *q;

	detach_segment(s); /* first detach us from our parent */
	p = s->child; /* then recursively delete all our child segments */
	while (p)
	{
		q = p->sibling;
		delete_segment(p, delapp_fn);
		p = q;
	}
	if (s->object && delapp_fn) (*delapp_fn)(s->object);
	free(s);
}


SEGMENT *find_segment_by_name(SEGMENT *s, char *name)
{
	SEGMENT *p;
	if (s->name) /* if this segment has a name */
		if (!stricmp(s->name, name)) /* and it matches */
			return s; /* then we've found the segment with that name */
	/* otherwise, recursively check all of our children and their subtrees */
	for (p = s->child; p; p = p->sibling)
		if ((s = find_segment_by_name(p, name)) != NULL) /* found it! */
			return s;
	return NULL; /* neither us nor any of our descendants has that name */
}

