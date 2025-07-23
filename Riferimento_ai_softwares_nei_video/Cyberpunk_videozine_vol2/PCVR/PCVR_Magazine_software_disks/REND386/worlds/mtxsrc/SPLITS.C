/* Splitting-tree routines */

/* Written by Bernie Roehl, June 1992 */
/* Substantially upgraded by Dave Stampe, August '92 */

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
#include <alloc.h>  /* malloc() */
#include <string.h>

#include "rend386.h"
#include "intmath.h"
#include "splitdef.h"

/* from intsplit.c */

extern int _which_side(SPLIT *s, long tx,long ty,long tz);
extern void *_fast_split_descent(SPLIT *tree, long x, long y, long z, char *type);

static AREA *create_area(void)
{
	AREA *a;
	if ((a = malloc(sizeof(AREA))) == NULL) return NULL;
	a->floor_a = 0x7FFFFFFFL;
	a->floor_b = 1;
	a->floor_c = 0;
	a->floor_d = 0;
	a->ceiling_a = 0;
	a->ceiling_b = 1;
	a->ceiling_c = 0;
	a->ceiling_d = 0;
	a->fn = NULL;
	a->visfrom = NULL;
	a->ptr = new_objlist();
	a->has_tree = 0;
	a->name = NULL;
	return a;
}

SPLIT *add_split(SPLIT **tree, long x, long y, long z,
	long nx, long ny, long nz, unsigned flags)
{
	if (*tree == NULL) {
		if ((*tree = malloc(sizeof(SPLIT))) == NULL) return NULL;
		(*tree)->x = x; 
		(*tree)->y = y; 
		(*tree)->z = z;
		(*tree)->nx = nx; 
		(*tree)->ny = ny; 
		(*tree)->nz = nz;
		(*tree)->olist = new_objlist();
		(*tree)->left_type = (*tree)->right_type = ISAREA;
		(*tree)->left = create_area();
		(*tree)->right = create_area();
		(*tree)->flags = flags;
		return (*tree);
	}
	if (_which_side(*tree, x, y, z) < 0) {
		if ((*tree)->left_type == ISAREA) {
			free((*tree)->left);
			(*tree)->left = NULL;
		}
		(*tree)->left_type = ISSPLIT;
		return add_split(&((SPLIT *)(*tree)->left), x, y, z, nx, ny, nz, flags);
	}
	if ((*tree)->right_type == ISAREA) {
		free((*tree)->right);
		(*tree)->right = NULL;
	}
	(*tree)->right_type = ISSPLIT;
	return add_split(&((SPLIT *)(*tree)->right), x, y, z, nx, ny, nz, flags);
}

static SPLIT *what_split(SPLIT *tree, long x, long y, long z)
{
	int n;
	while (tree) {
		n = _which_side(tree, x, y, z);
		if (n == 0) break;
		if (n < 0) {
			if (tree->left_type != ISSPLIT) return NULL;
			else tree = tree->left;
		}
		else {
			if (tree->right_type != ISSPLIT) return NULL;
			else tree = tree->right;
		}
	}
	return tree;
}

AREA *what_area(SPLIT *tree, long x, long y, long z)
{
	char n;
	return _fast_split_descent(tree,x,y,z,&n);
}

void add_obj_to_area(AREA *a, OBJECT *obj)
{
	if (a) add_to_objlist(a->ptr, obj);
}

void add_obj_to_split_center(SPLIT *s, OBJECT *obj)
{
	if (s) add_to_objlist(s->olist, obj);
}

void add_obj_to_split(SPLIT *tree, OBJECT *obj)
{ /* area OR on split */
	SPLIT *s;
	long x, y, z;
	char t;
	get_object_bounds(obj, &x, &y, &z);
	if ((s = what_split(tree, x, y, z)) != NULL)
		add_to_objlist(s->olist, obj);
	else
		add_obj_to_area(_fast_split_descent(tree, x, y, z, &t), obj);
}

void add_obj_to_split_area(SPLIT *tree, OBJECT *obj)
{
	SPLIT *s; /* in area only */
	long x, y, z; /* use during move */
	char t;
	get_object_bounds(obj, &x, &y, &z);
	add_obj_to_area(_fast_split_descent(tree, x, y, z, &t), obj);
}

OBJLIST *which_area_objlist(SPLIT *tree, long x, long y, long z)
{
	char t;
	AREA *a;

	if (tree == NULL) return NULL;
	a = _fast_split_descent(tree, x, y, z, &t);
	if (a == NULL || t!=ISAREA) return NULL;
	return a->ptr;
}

OBJLIST *which_objlist(SPLIT *tree, long x, long y, long z)
{
	int n;

	if (tree == NULL) return NULL;

	while (tree)
	{
		n = _which_side(tree, x, y, z);
		if (n == 0) return tree->olist; /* center of split */
		if (n < 0)
		{ /* area left of split */
			if (tree->left_type == ISSPLIT) tree = tree->left;
			else return ((AREA *)(tree->left))->ptr;
		}
		else
			{ /* area right of split */
			if (tree->right_type == ISSPLIT) tree = tree->right;
			else return ((AREA *)(tree->right))->ptr;
		}
	}
	return NULL;
}


SPLIT **global_split_root = NULL;

void set_global_split_root(SPLIT **split_tree)
{
	global_split_root = split_tree;
}


void initial_world_split(SPLIT **split_ptr)
{
	set_global_split_root(split_ptr);
	add_split(split_ptr, 0x3FFFFFFF, 0, 0, 1, 0, 0, 0);
}


void split_move_handler(OBJECT *obj)
{ /* split tree move */
	if (global_split_root)
	{
		remove_from_objlist(obj);
		add_obj_to_split_area(*global_split_root, obj);
	}
}


static OBJECT *objhit = NULL;
static int polyhit = 0;
static int verthit = 0;
static int checkflag = 0;

void render_monitor_point(int x, int y)
{
	checkflag = 1;
	objhit = NULL;
	set_screen_monitor(x, y);
}

OBJECT *render_check_monitor(int *poly, int *vert)
{
	if (objhit)
	{
		if (poly) *poly = polyhit;
		if (vert) *vert = verthit;
	}
	checkflag = 0;
	clear_screen_monitor();
	return objhit;
}

void render_objlist(OBJLIST *objlist)
{
	if (objlist == NULL) return;
	subrender(objlist);
	if (checkflag)
	{
		OBJECT *t = locate_screen_pt(&polyhit, &verthit);
		if (t) objhit = t;
	}
}

void render_area(AREA *a)
{
	if (a == NULL) return;
	subrender(a->ptr);
	if (checkflag)
	{
		OBJECT *t = locate_screen_pt(&polyhit, &verthit);
		if (t) objhit = t;
	}
}

void render_subtree(int type, void *ptr, VIEW *view)
{
	void render_split(SPLIT *, VIEW *);
	switch (type)
	{
	case ISAREA:
		render_area(ptr);
		break;
	case ISOBJLIST:
		subrender(ptr);
		if (checkflag)
		{
			OBJECT *t = locate_screen_pt(&polyhit, &verthit);
			if (t) objhit = t;
		}
		break;
	case ISSPLIT:
	default:
		render_split(ptr, view);
		break;
	}
}

void render_split(SPLIT *tree, VIEW *view)
{
	long x, y, z;
	if (tree == NULL) return;
	real_viewpoint(view, &x, &y, &z);
	if (_which_side(tree, x, y, z) < 0)
	{
		render_subtree(tree->right_type, tree->right, view);
		subrender(tree->olist);
		if (checkflag)
		{
			OBJECT *t = locate_screen_pt(&polyhit, &verthit);
			if (t) objhit = t;
		}
		render_subtree(tree->left_type, tree->left, view);
	}
	else
		{
		render_subtree(tree->left_type, tree->left, view);
		subrender(tree->olist);
		if (checkflag)
		{
			OBJECT *t = locate_screen_pt(&polyhit, &verthit);
			if (t) objhit = t;
		}
		render_subtree(tree->right_type, tree->right, view);
	}
}


void render_visareas(AREA *area)
{
	AREA_REF *a;
	for (a = area->visfrom; a; a = a->next)
		render_area(a->area);
	render_area(area);
}

void walk_area(AREA *a, void (*fn)())
{
	if (a) walk_objlist(a->ptr, fn);
}

void walk_split_tree(SPLIT *tree, void (*fn)())
{
	if (tree == NULL) return;
	switch (tree->left_type) {
	case ISSPLIT:
		walk_split_tree(tree->left, fn); 
		break;
	case ISAREA:
		walk_area(tree->left, fn); 
		break;
	case ISOBJLIST:
		walk_objlist(tree->left, fn); 
		break;
	}
	switch (tree->right_type) {
	case ISSPLIT:
		walk_split_tree(tree->right, fn);
		break;
	case ISAREA:
		walk_area(tree->right, fn); 
		break;
	case ISOBJLIST:
		walk_objlist(tree->right, fn); 
		break;
	}
	if (tree->olist) walk_objlist(tree->olist, fn);
}

/* Area-related functions */

void set_area_function(AREA *a, void (*fn)())
{
	if (a) a->fn = fn;
}

void call_area_fn(AREA *a)
{
	if (a) if (a->fn) a->fn(a);
}


char *area_name(AREA *a)
{
	if (a) return a->name;
	else return NULL;
}


char *set_area_name(AREA *a, char *name)
{
	if (a) return a->name = strdup(name);
	return NULL;
}

int add_visfrom(AREA *from, AREA *to)
{
	AREA_REF *p;
	if (from == NULL || to == NULL) return -2;
	if ((p = malloc(sizeof(AREA_REF))) == NULL) return -1;
	p->next = from->visfrom;
	from->visfrom = p;
	p->area = to;
	return 0;
}

void add_floor(AREA *area, long a, long b, long c, long d)
{
	if (area == NULL) return;
	if (b == 0) b = 1;
	area->floor_a = a; 
	area->floor_b = b; 
	area->floor_c = c; 
	area->floor_d = d;
}

void add_ceiling(AREA *area, long a, long b, long c, long d)
{
	if (area == NULL) return;
	if (b == 0) b = 1;
	area->ceiling_a = a; 
	area->ceiling_b = b; 
	area->ceiling_c = c; 
	area->ceiling_d = d;
}

long floor_at(AREA *a, long x, long z)
{
	if (a == NULL || a->floor_a==0x7FFFFFFFL) return 0x7FFFFFFFL;
	/*	return a->floor_a * x + a->floor_c * z + a->floor_d; */
	/*	return dot_prod_29(a->floor_a, a->floor_c, a->floor_d, x, z, 1L); */
	return plane_y(a->floor_a, a->floor_b, a->floor_c, a->floor_d, x, z);
}

long ceiling_at(AREA *a, long x, long z)
{
	if (a == NULL) return 0;
	/*	return a->ceiling_a * x + a->ceiling_c * z + a->ceiling_d; */
	/*	return dot_prod_29(a->ceiling_a, a->ceiling_c, a->ceiling_d, x, z); */
	return plane_y(a->ceiling_a, a->ceiling_b, a->ceiling_c, a->ceiling_d, x, z);
}

/* DEBUGGING ONLY: */

static int count_objlist(OBJLIST *o)
{
	OBJECT *obj;
	int i = 0;
	if (o == NULL) return 0;
	for (obj = first_in_objlist(o); obj; obj = next_in_objlist(obj))
		++i;
	return i;
}

void dump_area(AREA *a, int level)
{
	int i;
	if (a == NULL) return;
	for (i = 0; i < level; ++i) printf("  ");
	printf("Area %c (%d objects)\n", (char) a->floor_a, count_objlist(a->ptr));
}

void dump_objlist(OBJLIST *o, int level)
{
	int i;
	if (o == NULL) return;
	for (i = 0; i < level; ++i) printf("  ");
	printf("Objlist with %d objects in it\n", count_objlist(o));
}

void dump_split_tree(SPLIT *tree, int level)
{
	int i;
	if (tree == NULL) return;
	for (i = 0; i < level; ++i) printf("  ");
	printf("Split %u: %ld,%ld,%ld %ld,%ld,%ld\n", tree->flags,
	tree->x, tree->y, tree->z, tree->nx, tree->ny, tree->nz);
	switch (tree->left_type) {
	case ISSPLIT:
		dump_split_tree((SPLIT *) tree->left, level + 1); 
		break;
	case ISAREA:
		dump_area((AREA *) tree->left, level + 1); 
		break;
	case ISOBJLIST:
		dump_objlist((OBJLIST *) tree->left, level + 1); 
		break;
	}
	switch (tree->right_type) {
	case ISSPLIT:
		dump_split_tree((SPLIT *) tree->right, level + 1); 
		break;
	case ISAREA:
		dump_area((AREA *) tree->right, level + 1); 
		break;
	case ISOBJLIST:
		dump_objlist((OBJLIST *) tree->right, level + 1); 
		break;
	}
}

