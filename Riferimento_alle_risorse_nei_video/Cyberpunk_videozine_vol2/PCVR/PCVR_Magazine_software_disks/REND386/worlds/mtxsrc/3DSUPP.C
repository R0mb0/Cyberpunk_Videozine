/* Routines to compute poly normals and bounding sphere and lots more */

/* Written by Bernie Roehl, December 1991 */
/* updated 10/1/91 D. Stampe (for render first stage clip) */
/* now supports integers where needed */

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

#include <stdio.h>
#include <alloc.h>
#include <string.h>
#include <math.h>
#include <dos.h>

#include "3dstruct.h"
#include "intmath.h"		/* for special sphere test */

extern POLY *read_screen_monitor(void);
extern void refresh_display(void);

static unsigned default_depth_sort = DEEPEST ;

unsigned get_default_depth_sort()
{
	return default_depth_sort;
}

void set_default_depth_sort(unsigned value)
{
	default_depth_sort = value;
}

static void find_bounding_sphere(OBJECT *obj, REP *rep)
{
	int i;
	float minx, maxx, miny, maxy, minz, maxz;

	if (rep == NULL) return;

	minx = maxx = rep->verts[0].x;
	miny = maxy = rep->verts[0].y;
	minz = maxz = rep->verts[0].z;

	for (i = 1; i < rep->nverts; ++i)
	{ /* find bounding cube */
		if (rep->verts[i].x < minx) minx = rep->verts[i].x;
		if (rep->verts[i].y < miny) miny = rep->verts[i].y;
		if (rep->verts[i].z < minz) minz = rep->verts[i].z;
		if (rep->verts[i].x > maxx) maxx = rep->verts[i].x;
		if (rep->verts[i].y > maxy) maxy = rep->verts[i].y;
		if (rep->verts[i].z > maxz) maxz = rep->verts[i].z;
	}

	/* compute center of cube */
	obj->osphx = obj->sphx = (maxx - minx) /2 + minx;
	obj->osphy = obj->sphy = (maxy - miny) /2 + miny;
	obj->osphz = obj->sphz = (maxz - minz) /2 + minz;

	/* farthest point from center is the radius of the bounding sphere */

	for (i = 0; i < rep->nverts; ++i)
	{
		float r;

		r = (float)(rep->verts[i].x - obj->sphx) * (float)(rep->verts[i].x - obj->sphx) +
			(float)(rep->verts[i].y - obj->sphy) * (float)(rep->verts[i].y - obj->sphy) +
			(float)(rep->verts[i].z - obj->sphz) * (float)(rep->verts[i].z - obj->sphz);
		r = sqrt(r);
		if (r > obj->sphr) obj->sphr = r;
	}
}


#define NSCALE 536870912     /* 2^29: desired magnitude of normal */

static void compute_normal(POLY *p) /* Compute a polygon's normal */
{
	int i = 0;
	int j, k;
	long qinx, qiny, qinz;
	long longest = 0;
	long size;
	VERTEX *s,*e, *ls, *le;

	p->onormalx = p->normalx = NSCALE; /* default solution  */
	p->onormaly = p->normaly = 0;
	p->onormalz = p->normalz = 0;

	if (p->npoints < 3) return; /* fake it for lines */

	if (p->npoints == 3) /* only one solution for triangle */
	{
		find_normal(p->points[0]->ox,p->points[0]->oy,p->points[0]->oz,
		p->points[1]->ox,p->points[1]->oy,p->points[1]->oz,
		p->points[2]->ox,p->points[2]->oy,p->points[2]->oz,
		&qinx, &qiny, &qinz );
		p->onormalx = p->normalx = qinx;
		p->onormaly = p->normaly = qiny;
		p->onormalz = p->normalz = qinz;
		return;
	}

	/* if more sides: find longest */
	for (i = 0; i < p->npoints-1; i++)
	{
		s = p->points[i];
		e = p->points[i+1];
		size = big_dist(s->ox, s->oy, s->oz, e->ox, e->oy, e->oz);
		if (size > longest)
		{
			longest = size;
			ls = s;
			le = e;
		}
	}
	s = p->points[i];
	e = p->points[0];
	size = big_dist(s->ox, s->oy, s->oz, e->ox, e->oy, e->oz);
	if (size > longest)
	{
		longest = size;
		ls = s;
		le = e;
	}

	if (longest == 0) return;

	k = -1; /* now find acceptable point */
	for (i = 0; i < p->npoints; i++)
	{
		s = p->points[i];
		if (s != ls && s != le)
		{
			j = find_normal(ls->ox, ls->oy, ls->oz, le->ox, le->oy, le->oz,
				s->ox, s->oy, s->oz, &qinx, &qiny, &qinz );
			if (j > k) /* more precision */
			{
				p->onormalx = p->normalx = qinx;
				p->onormaly = p->normaly = qiny;
				p->onormalz = p->normalz = qinz;
				k = j;
			}
			if (j > 16) return; /* enough already */
		}
	}
}


void lock_rep(OBJECT *o, int n)
{
	REP *r;
	if (o)
	{
		o->oflags |= OBJ_REPLOCK;
		r = o->replist;
		while (n-- && r->next) r = r->next;
		o->current_rep = r;
	}
}

void unlock_rep(OBJECT *o)
{
	if (o) o->oflags &= ~OBJ_REPLOCK;
}

static void activate_rep(OBJECT *obj, REP *rep)
{
	obj->current_rep = rep;
}

void first_rep(OBJECT *obj)
{
	activate_rep(obj, obj->replist);
}

int next_rep(OBJECT *obj) /* return 1 if wrapping back to first */
{
	if (obj->current_rep == NULL)
		activate_rep(obj, obj->replist);
	else if ((obj->current_rep)->next == NULL)
	{
		activate_rep(obj, obj->replist);
		return 1;
	}
	else
		{
		activate_rep(obj, (obj->current_rep)->next);
		return 0;
	}
	return 1;
}

REP *add_representation(OBJECT *obj, long size, int nv, int np)
{
	REP *p, *q;
	if (obj == NULL) return NULL;
	if ((p = malloc(sizeof(REP))) == NULL) return NULL;
	p->size = size;
	p->nverts = 0;
	p->npolys = 0; /* used as counters when adding */
	p->update_count = 0;
	p->flags = 0;
	if ((p->verts = calloc(nv, sizeof(VERTEX))) == NULL) {
		free(p);
		return NULL;
	}
	if ((p->polys = calloc(np, sizeof(POLY))) == NULL) {
		free(p->verts);
		free(p);
		return NULL;
	}
	activate_rep(obj, p);
	if (obj->replist == NULL) {
		obj->replist = p;
		p->next = NULL;
		return p;
	}
	q = obj->replist;
	if (q->size <= size) {
		p->next = q;
		obj->replist = p;
		return p;
	}
	while (q->next) {
		if ((q->next)->size <= size)
			break;
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	return p;
}

void select_representation(OBJECT *obj, long size)
{
	REP *p;
	for (p = obj->replist; p; p = p->next)
		if (p->size <= size) {
			activate_rep(obj, p);
			break;
		}
}

void set_rep_size(OBJECT *obj, long size)
{
	REP *rep = obj->current_rep;
	if (rep == NULL) return;
	rep->size = size;
}


long get_rep_size(OBJECT *obj)
{
	REP *rep = obj->current_rep;
	if (rep == NULL) return 0;
	return rep->size;
}



/* allocate an OBJECT */
OBJECT *new_obj(int type, int nv, int np)
{
	OBJECT *obj;

	if ((obj = malloc(sizeof(OBJECT))) == NULL) return NULL;
	obj->oflags = IS_OBJECT | default_depth_sort;
	obj->owner = NULL;
	obj->current_rep = obj->replist = NULL;
	if (add_representation(obj, 0, nv, np) == NULL)
	{
		free(obj);
		return NULL;
	}
	obj->sphx = obj->sphy = obj->sphz = 0;
	obj->osphx = obj->osphy = obj->osphz = 0;
	obj->sphr = 0;
	obj->prev = NULL;
	obj->nnext = NULL;
	obj->update_count = 0;
	return obj;
}

void add_vertex(OBJECT *obj, long x, long y, long z)
{
	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	rep->verts[rep->nverts].x = rep->verts[rep->nverts].ox = x;
	rep->verts[rep->nverts].y = rep->verts[rep->nverts].oy = y;
	rep->verts[rep->nverts].z = rep->verts[rep->nverts].oz = z;
	++rep->nverts;
}


POLY *add_poly(OBJECT *obj, unsigned color, int npoints)
{
	POLY *p;
	REP *rep = obj->current_rep;
	if (rep == NULL) return NULL;

	p = &(rep->polys[rep->npolys]);
	if ((p->points = calloc(npoints, sizeof(VERTEX *))) == NULL) return NULL;
	p->object = obj;
	p->color = color;
	p->npoints = 0;
	++rep->npolys;
	return p;
}

void add_point(OBJECT *obj, POLY *p, int vertnum)
{
	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	p->points[p->npoints++] = &(rep->verts[vertnum]);
}


static void del_rep(REP *rep)
{
	if (rep == NULL) return;

	while (rep->npolys--)
		if (rep->polys[rep->npolys].points)
			free(rep->polys[rep->npolys].points);
	if (rep->polys) free(rep->polys);
	if (rep->verts) free(rep->verts);
	free(rep);
}

void delete_rep(OBJECT *obj) /* needs testing */
{
	REP *rep = obj->current_rep;

	if (rep == NULL || obj->replist == NULL) return;
	if (rep == obj->replist)
		obj->replist = rep->next;
	else
	{
		REP *r;
		for (r = obj->replist; r->next != NULL; r = r->next)
			if (r->next == rep)
				break;
		if (r->next == NULL) return; /* wasn't in list */
		r->next = rep->next;
	}
	del_rep(rep);
}

void delete_obj(OBJECT *obj)
{
	REP *rep = obj->replist;
	REP *next;

	while (rep)
	{
		next = rep;
		rep = next->next;
		del_rep(next);
	}
	free(obj);
}

void set_obj_flags(OBJECT *obj, unsigned int val)
{
	obj->oflags = (val & OBJ_FLAG_MASK)
		| (obj->oflags & (~OBJ_FLAG_MASK))
			| IS_OBJECT;
}

unsigned get_obj_flags(OBJECT *obj)
{
	return obj->oflags & OBJ_FLAG_MASK;
}

long get_object_bounds(OBJECT *obj, long *x, long *y, long *z)
{
	if (x) *x = obj->sphx; 
	if (y) *y = obj->sphy; 
	if (z) *z = obj->sphz;
	return obj->sphr;
}


void compute_obj(OBJECT *obj) /* for current rep only! */
{
	int i;

	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	for (i = 0; i < rep->npolys; ++i)
		compute_normal(&rep->polys[i]);

	find_bounding_sphere(obj, rep);
}

void compute_all_obj(OBJECT *obj) /* for all reps */
{
	int i;

	REP *rep = obj->replist;
	if (rep == NULL) return;

	obj->sphr = 0;
	while (rep)
	{
		obj->current_rep = rep;
		for (i = 0; i < rep->npolys; ++i)
			compute_normal(&rep->polys[i]);

		find_bounding_sphere(obj, rep);
		rep = rep->next;
	}
}


/* object list management routines */

OBJLIST *new_objlist()
{
	OBJLIST *p;

	p = malloc(sizeof(OBJLIST));
	if (p)
	{
		p->prev = p->nnext = NULL;
		p->oflags = OBJLIST_HEADER;
	}
	return p;
}

void add_to_objlist(OBJLIST *list, OBJECT *obj)
{
	if (list == NULL || obj == NULL) return;
	if (list->nnext == NULL) /* first in list */
		obj->nnext = NULL;
	else
	{
		list->nnext->prev = obj;
		obj->nnext = list->nnext;
	}
	list->nnext = obj;
	obj->prev = (OBJECT *) list;
}

void remove_from_objlist(OBJECT *obj)
{
	if (obj == NULL) return;
	if (obj->nnext != NULL) obj->nnext->prev = obj->prev;
	obj->prev->nnext = obj->nnext;

	obj->nnext = obj->prev = NULL;
}

void del_objlist(OBJLIST *list)
{
	if (list)
	{
		while (list->nnext) {
			OBJECT *obj;
			obj = list->nnext;
			remove_from_objlist(list->nnext);
			delete_obj(obj);
		}
		free(list);
	}
}

OBJLIST *on_objlist(OBJECT *obj)
{
	if (obj == NULL) return NULL;
	for (obj = obj->prev; obj->prev; obj = obj->prev);
	return (OBJLIST *) obj;
}


/* Additional functions suggested by wendellj@microsoft.com */

OBJECT *first_in_objlist(OBJLIST *objlist)
{
	return objlist->nnext;
}

OBJECT *next_in_objlist(OBJECT *obj)
{
	return obj->nnext;
}

OBJECT *prev_in_objlist(OBJECT *obj)
{
	return obj->prev;
}

int is_first_in_objlist(OBJECT *obj)
{
	return obj->prev->prev == NULL;
}

int is_last_in_objlist(OBJECT *obj)
{
	return obj->nnext == NULL;
}

void get_obj_info(OBJECT *obj, int *nv, int *np)
{
	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	if (nv) *nv = rep->nverts;
	if (np) *np = rep->npolys;
}

void walk_objlist(OBJLIST *objlist, void (*fn)(OBJECT *))
{
	OBJECT *obj;
	OBJECT *next;
	/* be changed by the fn() ! */
	if (objlist == NULL) return;
	obj = objlist->nnext;
	while (obj != NULL)
	{
		next = obj->nnext; /* get ahead of time in case object is modified */
		fn(obj);
		obj = next;
	}
}

void get_vertex_world_info(OBJECT *obj, int vertnum, long *x, long *y, long *z)
{
	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	if (x) *x = rep->verts[vertnum].x;
	if (y) *y = rep->verts[vertnum].y;
	if (z) *z = rep->verts[vertnum].z;
}

void get_vertex_info(OBJECT *obj, int vertnum, long *x, long *y, long *z)
{
	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	if (x) *x = rep->verts[vertnum].ox;
	if (y) *y = rep->verts[vertnum].oy;
	if (z) *z = rep->verts[vertnum].oz;
}


void get_poly_info(OBJECT *obj, int polynum,
unsigned *color, int *nverts,
int *verts, int maxverts)
{
	int i, n;
	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	if (color) *color = rep->polys[polynum].color;
	n = rep->polys[polynum].npoints;
	if (nverts) *nverts = n;
	if (verts)
		for (i = 0; i < n && i < maxverts; ++i)
			verts[i] = (FP_OFF(rep->polys[polynum].points[i]) -
				FP_OFF(rep->verts)) /sizeof(VERTEX);
}


void set_poly_color(OBJECT *obj, int polynum, unsigned color)
{
	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	if (polynum < rep->npolys)
		rep->polys[polynum].color = color;
}

static long sqr(long x)
{
	return x*x;
}

/* find nearest object and vertex to [x,y,z] -- return distance */

long where_pt(OBJLIST *objlist, long x, long y, long z,
OBJECT **wobj, int *wvert)
{
	OBJECT *obj;
	long distance; /* the next best thing to being there!  :-) */
	REP *rep;

	if (wobj) *wobj = NULL;
	if (wvert) *wvert = 0;
	distance = 0;
	for (obj = objlist->nnext; obj; obj = obj->nnext)
	{
		int i;

		if (obj->oflags & (OBJ_INVIS|OBJ_NONSEL)) continue; /* invisible... skip */
		if (labs(x-obj->sphx) > obj->sphr) continue; /* outside of box */
		if (labs(y-obj->sphy) > obj->sphr) continue;
		if (labs(z-obj->sphz) > obj->sphr) continue;
		if (sqr(x-obj->sphx)+sqr(y-obj->sphy)+sqr(z-obj->sphz) >
			sqr(obj->sphr)) continue;
		rep = obj->current_rep;
		if (rep == NULL) continue;
		for (i = 0; i < rep->nverts; ++i)
		{
			long d;

			d = sqr(x-rep->verts[i].x)+sqr(y-rep->verts[i].y)+sqr(z-rep->verts[i].z);
			if (d < distance || distance == 0)
			{
				distance = d;
				if (wobj) *wobj = obj;
				if (wvert) *wvert = i;
			}
		}
	}
	return (long) floor(sqrt((double) distance));
}


/* find object that point is closest to center of */

OBJECT *best_collision(OBJLIST *objlist, long x, long y, long z)
{
	OBJECT *obj;
	OBJECT *bestobj = NULL;
	long mindist = 0x7FFFFFFF;
	long dist;

	if (objlist == NULL) return NULL;
	for (obj = objlist->nnext; obj; obj = obj->nnext)
	{ /* not selectable... skip */
		if (obj->oflags & (OBJ_INVIS|OBJ_NONSEL)) continue;
		if (obj->owner == NULL) continue; /* ignore if no segment */
		dist = sphere_pretest(obj, x, y, z); /* test object */
		if (dist < mindist)
		{
			mindist = dist; /* better fit: accept */
			bestobj = obj;
		}
	}
	return bestobj;
}


/* check collision of object (full) */

int test_collision(OBJECT *obj, long x, long y, long z)
{
	if (obj->oflags & OBJ_INVIS) return 0; /* invisible... skip */
	if (sphere_pretest(obj, x, y, z) == 0x7FFFFFFF) return 0; /* test object sphere; */
	if (obj->coll_eval) return obj->coll_eval(obj, x, y, z);
	return 1;
}


void highlight_obj(OBJECT *obj)
{
	int i;
	REP *p;

	if (obj == NULL) return;
	for (p = obj->replist; p; p = p->next)
	{
		for (i = 0; i < p->npolys; ++i) p->polys[i].color |= 0x8000;
	}
	obj->oflags |= OBJ_HIGHLIGHTED;
}


void unhighlight_obj(OBJECT *obj)
{
	int i;
	REP *p;

	if (obj == NULL) return;
	for (p = obj->replist; p; p = p->next)
	{
		for (i = 0; i < p->npolys; ++i) p->polys[i].color &= 0x7FFF;
	}
	obj->oflags &= ~OBJ_HIGHLIGHTED;
}


extern DSORT *vispolys; /* an array of pointers to visible polygons */

extern int npols;

static pt_in_poly(NPOLY *p, int x, int y)
{
	int i, v, have_left = 0, have_right = 0;
	NVERTEX **pp = (NVERTEX **)(p+1); /* pointers at end of struct */

	v = 0;
	for (i = 0; i < p->npoints; ++i) /* find if point in poly */
	{
		if (pp[i]->xs <= x) v |= 1;
		else if (pp[i]->xs >= x) v |= 2;
		if (pp[i]->ys <= y) v |= 4;
		else if (pp[i]->ys >= y) v |= 8;
		if (v == 15) break;
	}
	if (v != 15) return 0;
	for (i = 0; i < p->npoints; ++i)
	{
		float m, c;

		int n = (i == p->npoints-1) ? 0 : (i + 1); /* index of 'next' point */

		if (pp[i]->ys < y && pp[n]->ys < y) continue; /* above */
		if (pp[i]->ys > y && pp[n]->ys > y) continue; /* below */
		if (pp[i]->ys == y && pp[n]->ys == y) /* on same line */
		{
			if (pp[i]->xs < x && pp[n]->xs < x) return 0; /* left */
			if (pp[i]->xs > x && pp[n]->xs > x) return 0; /* right */
			return 1; /* [x,y] is on same line as an edge */
		}
		if (pp[n]->ys == y) continue; /* skip shared vtx-- bug fix */

		/* otherwise, this line crosses the scanline containing [x,y] */
		/* fast L/R pretest */
		if (pp[i]->xs < x && pp[n]->xs < x)
		{
			if (have_left) return 0; /* we're to the right */
			if (have_right) return 1; /* we're in between */
			have_left = 1;
			continue;
		}
		if (pp[i]->xs > x && pp[n]->xs > x)
		{
			if (have_right) return 0; /* we're to the right */
			if (have_left) return 1; /* we're in between */
			have_right = 1;
			continue;
		}
		/* check which side of line */
		m = ((float) (pp[n]->xs - pp[i]->xs)) /
			((float) (pp[n]->ys - pp[i]->ys));
		c = m*(y - pp[i]->ys) + pp[i]->xs;
		if (c < x)
		{
			if (have_left) return 0; /* we're to the right */
			if (have_right) return 1; /* we're in between */
			have_left = 1;
		}
		else if (c > x)
		{
			if (have_right) return 0; /* we're to the right */
			if (have_left) return 1; /* we're in between */
			have_right = 1;
		}
		else return 1; /* on it! */
	}
	return 0;
}

OBJECT *where_screen_pt(int *pol, int *vert, int x, int y)
{
	OBJECT *obj;
	POLY *p;
	set_screen_monitor(x, y);
	refresh_display();
	p = read_screen_monitor();
	if (p == NULL) return NULL;
	obj = p->object;
	if (obj == NULL) return NULL;
	if (pol) *pol = (FP_OFF(p) - FP_OFF(obj->current_rep->polys)) /sizeof(POLY);
	if (vert) *vert = 0;
	return obj;
}

OBJECT *locate_screen_pt(int *pol, int *vert)
{
	OBJECT *obj;
	POLY *p;
	int i;

	p = read_screen_monitor();
	if (p == NULL) return NULL;

	obj = p->object;
	if (pol) *pol = (FP_OFF(p) - FP_OFF(obj->current_rep->polys)) /sizeof(POLY);
	if (vert) *vert = 0;
	return obj;
}


void *get_object_owner(OBJECT *obj)
{
	return obj->owner;
}

void set_object_owner(OBJECT *obj, void *owner)
{
	obj->owner = owner;
}

void copy_world_to_object(OBJECT *obj)
{
	int i;
	REP *rep = obj->current_rep;
	if (rep == NULL) return;

	for (i = 0; i < rep->nverts; ++i)
	{
		rep->verts[i].ox = rep->verts[i].x;
		rep->verts[i].oy = rep->verts[i].y;
		rep->verts[i].oz = rep->verts[i].z;
	}
}

unsigned get_object_sorting(OBJECT *obj)
{
	return obj->oflags & OBJ_DEPTH_MASK;
}

void set_object_sorting(OBJECT *obj, unsigned depth_type)
{
	obj->oflags = (depth_type & OBJ_DEPTH_MASK)
		| (obj->oflags & (~OBJ_DEPTH_MASK))
			| IS_OBJECT;
}
