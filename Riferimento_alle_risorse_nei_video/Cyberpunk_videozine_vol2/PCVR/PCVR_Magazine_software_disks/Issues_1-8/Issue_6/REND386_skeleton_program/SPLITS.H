/* Functions related to splits and areas */

/* Written by Bernie Roehl, June 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

#ifndef SPLITDEF
#define SPLITDEF 1
typedef void SPLIT;
#endif

#ifndef AREADEF
#define AREADEF 1
typedef void AREA;
#endif

extern SPLIT *add_split(SPLIT **tree, long x, long y, long z,
			long nx, long ny, long nz, unsigned flags);
extern AREA *what_area(SPLIT *tree, long x, long y, long z);
extern void add_obj_to_area(AREA *a, OBJECT *obj);
extern void add_obj_to_split(SPLIT *tree, OBJECT *obj);

extern void split_move_handler(OBJECT *obj);
extern void initial_world_split(SPLIT **split_ptr);
extern void set_global_split_root(SPLIT **split_tree);
extern SPLIT **global_split_root;

extern OBJLIST *which_area_objlist(SPLIT *tree, long x, long y, long z);
extern OBJLIST *which_objlist(SPLIT *tree, long x, long y, long z);
extern void add_obj_to_split_area(SPLIT *tree, OBJECT *obj);
extern void add_obj_to_split_center(SPLIT *tree, OBJECT *obj);

extern void render_monitor_point(int x, int y);
extern OBJECT *render_check_monitor(int *poly, int *vert);
extern void render_objlist(OBJLIST *objlist);
extern void render_area(AREA *a);
extern void render_subtree(int type, SPLIT *ptr, VIEW *view);
extern void render_split(SPLIT *tree, VIEW *view);
extern void render_visareas(AREA *area);
extern void walk_area(AREA *a, void (*fn)());
extern void walk_split_tree(SPLIT *tree, void (*fn)());
extern void set_area_function(AREA *a, void (*fn)());
extern void call_area_fn(AREA *a);
extern void add_floor(AREA *area, long a, long b, long c, long d);
extern void add_ceiling(AREA *area, long a, long b, long c, long d);
extern long floor_at(AREA *a, long x, long z);
extern long ceiling_at(AREA *a, long x, long z);
extern int add_visfrom(AREA *from, AREA *to);

/* End of splits.h */
