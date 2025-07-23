/* 2D and 3D cursor handling  */
/* some manipulation routines */

#include <stdio.h>
#include <dos.h>
#include <fastgraf.h>

#include "3dstruct.h"
#include "rend386.h"
#include "f3dkitd.h"
#include "intmath.h"
#include "pointer.h"
#include "cursor.h"
#include "segio.h"
#include "plg.h"
#include "userint.h"

extern int manip_2D_avail;
extern int redraw, toolbar;

/***************** 2D (screen) cursor handling ************/

static int oldx = 160, oldy = 100;
static int cursor_flag = -1;
static int lastpage;
extern highest_color;

void cursor_move(int x, int y) /* move cursor if visible */
{
	oldx = x;
	oldy = y;
	if (cursor_flag == 0)
	{
		set_drawpage(lastpage);
		erase_cursor(lastpage);
		draw_cursor(x,y,-highest_color,lastpage);
	}
}

int cursor_hide() /* erase cursor */
{
	if (cursor_flag >= 0) erase_cursor(lastpage);
	--cursor_flag;
	return lastpage;
}

int cursor_forget() /* will be erased by redraw: ignore it! */
{
	--cursor_flag;
	return lastpage;
}

void cursor_show(int page) /* redisplay cursor */
{
	if (++cursor_flag == 0)
	{
		set_drawpage(page);
		lastpage = page;
		draw_cursor(oldx, oldy, -highest_color, page);
	}
}


int move_2D(PDRIVER *d, int *x, int *y, unsigned *b)
{
	int c;

	if (d == NULL) return 0;
	if (PNEW_POS & (c = mouse_read(d, x, y, b)))
		cursor_move(*x, *y);
	return c;
}


int move_till_click(PDRIVER *d, unsigned b, int *x, int *y) /* b is button mask */
{
	int s;
	unsigned c;

	if (d == NULL) return -1;
	while(1)
	{
		if (((s = move_2D(d, x, y, &c)) & PNEW_BUT) && (c & b)) break;
	}
	return s;
}


int can_point_2D()
{
	if (!manip_2D_avail)
	{
		popmsg("Mouse not available");
		tdelay(500);
		redraw = 1;
		return 0;
	}
	return 1;
}


int move_and_select_2D(PDRIVER *d)
{
	int x, y, c, j, rt;
	unsigned b;
	char buff[100];

	if (!(c = move_2D(d, &x, &y, &b))) return 0; /* no changes */

	b &= 1; /* only left button wanted */

	if (check_controls(x, y, b)) return 0;
	if (b != 0 && (c & PNEW_BUT)) /* new button: DOWN event */
	{
		OBJECT *obj;
		int savecolor;

		obj = where_screen_pt(NULL, NULL, x, y);
		if (obj)
		{
			//set_obj_flags(obj, get_obj_flags(obj) ^ OBJ_HIGHLIGHTED);

			if (obj->oflags & OBJ_HIGHLIGHTED)
			       unhighlight_obj(obj);
			else
				highlight_obj(obj);

			sprintf(buff, "%s",obj->obj_name);
			prprint(x-25,y-25,15,buff);
			tdelay(300);
			redraw = 1;
		}
		else
			{
			popmsg("NOT ON ANY OBJECT");
			tdelay(300);
			redraw = 1;
			refresh_display();
		}
		redraw = 1;
	}
	return 0;
}


/* find world coordinates of pointer based on given view */

void pointer_to_world(POINTER *p, VIEW *v, long *x, long *y, long *z)
{
	MATRIX n;
	*x = p->x;
	*y = p->y;
	*z = p->z;
	view_to_matrix(v,n);
	matrix_point(n,x,y,z);
	p->wpos[3][0] = *x;
	p->wpos[3][1] = *y;
	p->wpos[3][2] = *z;
	p->wpos_valid = 1;
}


/* rotate data to view alignment */

void rotate_to_view( VIEW *v, long *x, long *y, long *z)
{
	MATRIX n;
	view_to_matrix(v,n);
	matrix_rotate(n,x,y,z);
}


/***************** GLOVE CURSOR SUPPORT *************/

SEGMENT *wrist_seg = NULL; /* wrist-on-body segment */
/* also used to manip. objects */

static SEGMENT *glove_seg; /* wrist twist for presentation */
static SEGMENT *glove_joints[20]; /* joints on hand */

#define Y_GLV_OFFSET  0      /* needed as "body" is at neck level */
#define GLOVE_DIST    1000

#define SELECT_LENGTH 20	/* distance along last index finger segment */
/* to selection point */

int glove_update(PDRIVER *d, POINTER *p) /* read glove, update positions */
{
	int c;

	c = pointer_read(d, p);

	if ((c & (PNEW_POS | PNEW_ROT | PNEW_FLEX)) == 0) return 0;

	abs_move_segment(wrist_seg, p->x, p->y + Y_GLV_OFFSET, p->z + GLOVE_DIST);
	if (d->pdata->type&P_IS6DG)
		abs_rot_segment(wrist_seg, p->rx, p->ry, p->rz, RYXZ);
	else
		abs_rot_segment(glove_seg, -2000L*p->y, p->ry, -4000L*p->x, RYXZ);

	abs_rot_segment(glove_joints[1], 0L,30*65536L+18061L*p->flex[0],0L, RYXZ);
	abs_rot_segment(glove_joints[2], -20*65536L,90*65536L,-5*65536L+38700L*p->flex[1], RYZX);
	abs_rot_segment(glove_joints[3], 38700*p->flex[2],0L,0L, RYXZ);
	abs_rot_segment(glove_joints[4], 38700*p->flex[3],0L,0L, RYXZ);
	abs_rot_segment(glove_joints[5], 38700*p->flex[4],0L,0L, RYXZ);
	abs_rot_segment(glove_joints[6], 38700*p->flex[5],0L,0L, RYXZ);
	abs_rot_segment(glove_joints[7], 38700*p->flex[6],0L,0L, RYXZ);
	abs_rot_segment(glove_joints[8], 38700*p->flex[7],0L,0L, RYXZ);
	abs_rot_segment(glove_joints[9], 38700*p->flex[8],0L,0L, RYXZ);
	abs_rot_segment(glove_joints[10],38700*p->flex[9],0L,0L, RYXZ);

	redraw = 1;
	return 1;
}

extern OBJLIST *objlist; /* only needed during load */
extern void *split_tree;

int load_glove_cursor(SEGMENT *body_seg, PDRIVER *gd, char *glove_fname)
{
	int i;
	FILE *in;
	OBJECT *obj;

	if ((in = fopen(glove_fname, "r")) == NULL)
		return -1;
	set_readseg_objlist(objlist);
	set_readseg_seglist(glove_joints,20);
	if(!wrist_seg) wrist_seg = new_seg(NULL);
	attach_segment(wrist_seg, body_seg);

	if ((gd->pdata->type & P_IS6DG) == 0)
		abs_rot_segment(wrist_seg, 55*65536L, 0, 0, RYXZ); /* glove wrist pose */

	readseg_err = 0;
	glove_seg = readseg(in, wrist_seg);
	fclose(in);

	if (readseg_err || (glove_seg == NULL))
		return -2;
	for (i = 0; i < 11; i++) /* glove is a non-selectable object */
	{
		void *obj = seg_get_object(glove_joints[i]);
		set_obj_flags(obj, get_obj_flags(obj) | OBJ_NONSEL);
	}
	return 0;
}


/************* 3D/6D CURSOR SUPPORT ***********/

static SEGMENT *cursor_seg;

int load_3D_cursor(SEGMENT *body_seg, PDRIVER *gd, char *cursor_fname)
{
	int i;
	FILE *in;
	OBJECT *obj;

	if ((in = fopen(cursor_fname, "r")) == NULL)
		return -1;
	cursor_seg = new_seg(body_seg);
	obj = load_plg(in);
	fclose(in);

	if (obj)
	{
		seg_set_object(cursor_seg, obj);
		set_object_owner(obj, cursor_seg);
		set_obj_flags(obj, get_obj_flags(obj) | OBJ_NONSEL);
		add_obj_to_split_area(split_tree, obj);
		update_segment(cursor_seg);
		return 0;
	}
	else
		return -2;
}


int cursor_update3D(PDRIVER *d, POINTER *p) /* read pointer, update positions */
{
	int c;

	c = pointer_read(d, p);

	if ((c & (PNEW_POS | PNEW_ROT)) == 0) return 0;

	abs_move_segment(cursor_seg, p->x, p->y + Y_GLV_OFFSET, p->z + GLOVE_DIST);
	abs_rot_segment(cursor_seg, p->rx, p->ry, p->rz, RYXZ);

	redraw = 1;
	return 1;
}



/************* USED FOR 3D/6D MANIPULATION *************/

extern int have_ptr;

SEGMENT *manip_data(PDRIVER *d, long *x, long *y, long *z)
{

	if (!have_ptr)
	{
		*x = 0;
		*y = 0;
		*z = SELECT_LENGTH;
		matrix_point(*get_seg_pmatrix(glove_joints[4]), x, y, z);
		return wrist_seg;
	}
	else
		{
		seg_getposxyz(cursor_seg, x ,y ,z);
		return cursor_seg;
	}
}

