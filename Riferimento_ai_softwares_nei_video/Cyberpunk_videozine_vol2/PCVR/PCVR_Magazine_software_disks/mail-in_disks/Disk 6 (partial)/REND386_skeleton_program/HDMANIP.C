/* Handles body/head/manipulator mappings */

/* Written by Dave Stampe, August 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

#include <stdio.h>
#include <dos.h>
#include "include/rend386.h"
#include "include/intmath.h"
#include "include/splits.h"
#include "include/segasupp.h"
#include "include/pointer.h"
#include "include/cursor.h"

#ifdef VIDEO_TRACKER
extern int start_video();
extern int read_head_tracker(long *x, long *y, long *z, long *t, long *p, long *a);
#endif

extern int use_glove;

extern int redraw;

static SEGMENT *rot_seg; /* used to rotate objects by center */

SEGMENT *body_seg; /* body-in-world base segment */
static SEGMENT *head_seg; /* head-on-body segment */
SEGMENT *eye_seg; /* eyes-in-head segment */

extern PDRIVER *head_device;

MATRIX h_recenter, ht_offset, ht_ioffset;

int head_update(int recenter) /* repositions head based on tracker data */
{
	POINTER hp;
	MATRIX m;
	int c;

	if (!head_device) return 0;
	c = pointer_read(head_device, &hp); /* read ht */

	if (recenter) /* use current pos'n as zero */
	{
		std_matrix(m, hp.rx, hp.ry, hp.rz, hp.x, hp.y, hp.z);
		inverse_matrix(m, h_recenter);
		matrix_product(ht_ioffset, h_recenter, h_recenter);
		c = PNEW_POS;
	}

	if (c & (PNEW_POS | PNEW_ROT)) /* compute new hpos */
	{
		std_matrix(m, hp.rx, hp.ry, hp.rx, hp.x, hp.y, hp.z);
		matrix_product(h_recenter, m, m);
		matrix_product(m, ht_offset, m);
		abs_mat_segment(head_seg, m);
		redraw = 1;
	}
	return 0;
}



void htrack_quit()
{
	pointer_quit(head_device);
}


PDRIVER *init_head_device(char *dfname, long x, long y, long z, long rx, long ry, long rz)
{
	MATRIX m;
	PDRIVER *p;
	POINTER pt;

	p = pointer_init(P_IS6H, dfname); /* setup glove device TEST */
	if (p == NULL) return NULL;

	init_pointer(&pt); /* so that defaults are OK */
	/* use abs. head motion */
	pointer_abscale(p, 65536L, 65536L, 65536L, 65536L, 65536L, 65536L);
	pointer_read(p, &pt);
	pointer_read(p, &pt); /* save current position */

	head_device = p;
	atexit(htrack_quit);

	identity_matrix(h_recenter);
	std_matrix(m, rx, ry, rz ,x, y, z);

	matrix_copy(m, ht_offset);
	/* matrix_copy(m, h_recenter); */

	inverse_matrix(m, ht_ioffset);
	inverse_matrix(m, h_recenter);

	head_update(1);

	return p;
}


/* do BEFORE loading, initializing devices */

void init_body_links() /* setup body-glove-head system */
{
	body_seg = new_seg(NULL);
	head_seg = new_seg(body_seg);
	eye_seg = new_seg(head_seg);
	rot_seg = new_seg(NULL); /* used by manipulation */

	abs_rot_segment(head_seg, 0*65536L, 0*65536L, 0, RYXZ);
	abs_move_segment(eye_seg, 0,100,100); /* eyes in head pos'n */
}


/* takes "view" corresp. to body location,           */
/* converts to centered eye view, updates cursors    */
/* sequence: update cursor/glove, read head tracker, */
/* body_centric_map(), manipulate object, and render */

void body_centric_map(VIEW *body, VIEW *v)
{
	MATRIX m;

	fast_view_factors(body);
	*v = *body;
	view_to_matrix(v,m);
	abs_mat_segment(body_seg,m);
	update_segment(body_seg);
	memcpy(&m, get_seg_pmatrix(eye_seg),sizeof(MATRIX));
	matrix_view_factors(v,m);
}


/************* SIMPLE 3D/6D OBJECT MANIPULATION *********/

static OBJECT *sel_obj;
static SEGMENT *work_seg;
static SEGMENT *old_parent;

extern SPLIT *split_tree;


static void unhi_it(OBJECT *obj)
{
	set_obj_flags(obj, get_obj_flags(obj) & ~OBJ_HIGHLIGHTED);
	unhighlight_obj(obj);
}


static MATRIX ogm;
static long oxp, oyp, ozp;
static long oxg, oyg, ozg;

#define FREE_DO   0
#define GRASP_DO  1
#define ROTATE_DO 2
#define SELECT_DO 3

static gmode = FREE_DO;

void manip_do(PDRIVER *p, int command) /* glove execution loop element */
{
	OBJLIST *list;
	OBJECT * obj;
	int s;
	long d,x,y,z;
	MATRIX f;
	MATRIX *m;

	POINTER pt;
	SEGMENT *wrist_seg = manip_data(p, &x, &y, &z);

	if (p==NULL) return;

	s = last_pointer(p, &pt);

newmode:
	switch(gmode)
	{
		case FREE_DO:
			switch(command)
			{
				case SELECT_DO:
					gmode = SELECT_DO;
					walk_split_tree(split_tree, unhi_it);
					sel_obj = NULL;
					redraw = 1;
					goto newmode;
				case GRASP_DO:
					if (sel_obj)
					{
						work_seg = get_object_owner(sel_obj);
						old_parent = parent_segment(work_seg);
						if (old_parent) detach_segment(work_seg);
						attach_segment(work_seg, wrist_seg);
						gmode = GRASP_DO;
						redraw = 1;
					}
					break;
				case ROTATE_DO:
					if (sel_obj)
					{
						work_seg = get_object_owner(sel_obj);
						if (work_seg == NULL) break;
						old_parent = parent_segment(work_seg);
						update_segment(work_seg);

						if (old_parent == NULL)
							get_object_bounds(sel_obj, &oxp, &oyp, &ozp); /* center of obj */
						else
						{
							m = get_seg_pmatrix(work_seg); /* else by origin ("joint") */
							oxp = (*m)[3][0];
							oyp = (*m)[3][1];
							ozp = (*m)[3][2];
						}

					abs_rot_segment(rot_seg, 0, 0, 0, RYXZ);
					abs_move_segment(rot_seg, oxp, oyp, ozp);
					update_segment(rot_seg);
					attach_segment(work_seg, rot_seg);

					oxg = x-oxp;
					oyg = y-oyp;
					ozg = z-ozp;
					vector_to_matrix(f, oxg, oyg, ozg);
					inverse_matrix(f, ogm);
					gmode = ROTATE_DO;
					redraw = 1;
				}
				break;
			default:
				break;
			}
			break;
		case SELECT_DO:
			switch(command)
			{
				case SELECT_DO:
					list = which_area_objlist(split_tree, x, y, z);
					if (list != NULL)
					{
						obj = best_collision(list, x, y, z);
						if (obj == NULL)
						{
							unhighlight_obj(sel_obj);
							sel_obj = NULL;
						}
					else
					{
						if (sel_obj != obj) unhighlight_obj(sel_obj);
						highlight_obj(obj);
						sel_obj = obj;
					}
					redraw = 1;
				}
			break;
		default:
			gmode = FREE_DO;
			goto newmode;
		}
		break;
	case GRASP_DO:
		switch(command)
		{
		case GRASP_DO:
			break; /* move is automatic */
		default:
			if (work_seg)
			{
				detach_segment(work_seg);
				if (old_parent) attach_segment(work_seg, old_parent);
				redraw = 1;
			}
			gmode = FREE_DO;
			goto newmode;
		}
		break;
	case ROTATE_DO:
		switch(command)
		{
		case ROTATE_DO:
			if (sel_obj && (s & PNEW_POS))
			{
				vector_to_matrix(f, x-oxp, y-oyp, z-ozp);
				matrix_product(f, ogm, f);
				f[3][0] = oxp;
				f[3][1] = oyp;
				f[3][2] = ozp;
				abs_mat_segment(rot_seg, f);
				update_segment(rot_seg);
				redraw = 1;
			}
			break;
		default:
			gmode = FREE_DO;
			redraw = 1; /* convert to real pos'n */
			detach_segment(work_seg);
			if (old_parent) attach_segment(work_seg, old_parent);
			goto newmode;
		}
		break;
	default:
		break;
	}
}


