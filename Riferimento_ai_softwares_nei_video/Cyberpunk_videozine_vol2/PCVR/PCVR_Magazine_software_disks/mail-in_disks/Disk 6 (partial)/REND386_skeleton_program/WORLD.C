/* Read a World Description File */

/* Written by Bernie Roehl, July 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/rend386.h"
#include "include/tasks.h"
#include "include/plg.h"
#include "include/intmath.h"
#include "include/splits.h"
#include "include/pointer.h"
#include "include/cursor.h"
#include "include/segasupp.h"
#include "include/segio.h"

extern SPLIT *split_tree;

extern int sl_xflip, sl_xoff;
extern long sl_left, sl_top, sl_right, sl_bottom;
extern int sr_xflip, sr_xoff;
extern long sr_left, sr_top, sr_right, sr_bottom;
extern float sl_xrot, sr_xrot;

extern unsigned screen_clear_color,sky_color,ground_color;
extern int use_frame, redraw, review, reframe, do_screen_clear;
extern int frame_x, frame_y, frame_w, frame_h; /* frame location */
extern char framefname[];
extern STEREO default_stereo;
extern VIEW default_view;
extern unsigned char *palette;
extern int npalette;
extern OBJLIST *objlist;
extern TASK *tasklist;
extern VIEW *current_view;

extern char *fix_fname(char *fname);

char dummy[8192];

OBJECT *where_split_screen_pt(int *pol, int *vert, int x, int y)
{
	extern OBJECT *render_check_monitor(int *pol, int *vert);

	render_monitor_point(x, y);
	refresh_display();
	return render_check_monitor(pol, vert);
}

typedef struct _name NAMEREF;

struct _name {
	char *name;
	void *value;
	NAMEREF *next;
};

NAMEREF *add_name(NAMEREF **list, char *name, void *value)
{
	NAMEREF *p;
	if ((p = malloc(sizeof(NAMEREF))) == NULL) return NULL;
	p->name = strdup(name);
	p->value = value;
	p->next = *list;
	*list = p;
	return *list;
}

void del_namelist(NAMEREF *list)
{
	while (list) {
		if (list->name)
			free(list->name);
		free(list);
		list = list->next;
	}
}

void *find_name(NAMEREF *list, char *name)
{
	while (list) {
		if (!stricmp(list->name, name))
			return list->value;
		list = list->next;
	}
	return NULL;
}

char *find_value(NAMEREF *list, void *value)
{
	while (list) {
		if (list->value == value)
			return list->name;
		list = list->next;
	}
	return NULL;
}

void ticker()
{
	putchar('.');
}

typedef struct _key KEY;

struct _key {
	unsigned key;
	void (*fn)();
	unsigned param;
	KEY *next;
};

KEY *keylist = NULL;

typedef struct _control CONTROL;

struct _control {
	int x, y, w, h;
	unsigned buttonmask;
	void (*fn)();
	unsigned param;
	CONTROL *next;
};

CONTROL *controllist = NULL;

#define MAXSPINCOLORS 100

typedef struct {
	OBJECT *obj;
	int np; /* number of polys in obj */
	int ncolors;
	unsigned colors[MAXSPINCOLORS];
} SPINDATA;

NAMEREF *objectlist = NULL;

#define LSCALE 536870912.0

void scale3(float a, float b, float c,
	long *ap, long *bp, long *cp)
{
	float maxim; /* integerize normal */

	maxim = (a > 0) ? a : -a; /* BUG IN BC 3.0 fabs()! */
	maxim += (b > 0) ? b : -b;
	maxim += (c > 0) ? c : -c;
	if (maxim > 0.0001)
	{
		maxim /= LSCALE;
		*ap = a/maxim;
		*bp = b/maxim; /* normalize to <3.29> */
		*cp = c/maxim;
	}
}

void scale4(float a, float b, float c, float d,
	long *ap, long *bp, long *cp, long *dp)
{
	float maxim; /* integerize normal */

	maxim = (a > 0) ? a : -a; /* BUG IN BC 3.0 fabs()! */
	maxim += (b > 0) ? b : -b;
	maxim += (c > 0) ? c : -c;
	maxim += (d > 0) ? d : -d;
	if (maxim > 0.0001)
	{
		maxim /= LSCALE;
		*ap = a/maxim;
		*bp = b/maxim; /* normalize to <3.29> */
		*cp = c/maxim;
		*dp = d/maxim;
	}
}


/* facing normal, points should be in CW sequence */
/* for axis aligned (+) split directions, use:    */
/* x 0 0  x 100 0  x 0 100  for constant x */
/* 0 y 0  0 y 100  100 y 0  for constant y */
/* 0 0 z  100 0 z  0 100 z  for constant z */

void points_to_normal(float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3,
	long *ap, long *bp, long *cp)
{
	float v1x, v1y, v1z, v2x, v2y, v2z;
	float a, b, c; /* compute line equation */

	v1x = x2 - x1; 
	v1y = y2 - y1; 
	v1z = z2 - z1;
	v2x = x3 - x1; 
	v2y = y3 - y1; 
	v2z = z3 - y1;
	a = (v1y * v2z - v2y * v1z);
	b = (v1x * v2z - v2x * v1z);
	c = (v1x * v2y - v2x * v1y);

	scale3(a, b, c, ap, bp, cp);
}

void points_to_eqn(float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3,
	long *ap, long *bp, long *cp, long *dp)
{
	float v1x, v1y, v1z, v2x, v2y, v2z;
	float a, b, c, d; /* compute line equation */

	v1x = x2 - x1; 
	v1y = y2 - y1; 
	v1z = z2 - z1;
	v2x = x3 - x1; 
	v2y = y3 - y1; 
	v2z = z3 - y1;
	a = (v1y * v2z - v2y * v1z);
	b = (v1x * v2z - v2x * v1z);
	c = (v1x * v2y - v2x * v1y);
	d = -(a*x1 + b*y1 + c*z1); /* normalize to <3.29> */

	scale4(a, b, c, d, ap, bp, cp, dp);
}

void normal_to_plane(float x, float y, float z,
	float nx, float ny, float nz,
	long *ap, long *bp, long *cp, long *dp)
{
	float a, b, c, d; /* compute line equation  */
	/* given normal and point */
	a = nx; 
	b = -ny; 
	c = nz;
	d = -(a*x + b*y + c*z);

	scale4(a, b, c, d, ap, bp, cp, dp);
}


extern PDRIVER *menu_device;

void clickfn(int cmd, unsigned *msg)
{
	char buff[100];
	int x, y;
	unsigned buttons;
	if (cmd == 3) {
		sprintf(buff, "button %u", *msg);
		popmsg(buff);
		/*		do {
					mouse_read(&x, &y, &buttons);   NEEDS PTR DEVICE UPDATE
				}
				while (buttons & 1);
		*/ 	}
	else if (cmd == 2) {
		sprintf(buff, "key %u", *msg);
		popmsg(buff);
		getkey();
	}
	reframe = redraw = 1;
}

check_key(unsigned key)
{
	KEY *p;
	for (p = keylist; p; p = p->next)
		if (key == p->key) {
			p->fn(2, &p->param);
			return 1;
		}
	return 0;
}

check_controls(int x, int y, unsigned buttons)
{
	CONTROL *p;
	for (p = controllist; p; p = p->next)
		if (x >= p->x && y >= p->y && x < (p->x + p->w) && y < (p->y + p->h) && (buttons & p->buttonmask)) {
			p->fn(3, &p->param);
			return 1;
		}
	return 0;
}

match(char *a, char *b)
{
	return !strnicmp(a, b, strlen(b));
}

extern void spinner(), sculspin();

struct {
	char *name;
	void (*fn)();
} functions[] = {
	{ "ticker", ticker },
	{ "spinner", spinner },
	{ "sculspin", sculspin },
	{ "clickfn", clickfn },
	{ NULL, NULL }
};

NAMEREF *areas = NULL;
NAMEREF *maps = NULL;
NAMEREF *surfdefs = NULL;

typedef struct _surface SURFACE;

struct _surface {
	unsigned color;
	char *value;
	SURFACE *next;
};

extern char loadpath[];

read_world(FILE *in)
{
	char inbuff[256], *buff, fname[100];
	char surfacemapname[100];
	SURFACE *current_surface = NULL, *map;
	int i;
	SPLIT *current_split = NULL;
	while (fgets(inbuff, sizeof(inbuff), in)) {
		strip_comment(inbuff);
		for (buff = inbuff; isspace(*buff); ++buff);
		if (match(buff, "loadpath "))
			sscanf(buff, "%*s %s", loadpath);
		else if (match(buff, "palette ")) {
			FILE *in;
			sscanf(buff, "%*s %s", fname);
			if ((in = fopen(fix_fname(fname), "rb")) != NULL) {
				npalette = fread(palette, 3, 256, in);
				fclose(in);
			}
		}
		if (match(buff, "skycolor ")) /* can have optional r,g,b at end of line */
			sscanf(buff, "%*s %d", &screen_clear_color);
		else if (match(buff, "groundcolor ")) /* can have optional r,g,b at end of line */
			sscanf(buff, "%*s %d", &ground_color);
		else if (match(buff, "screenclear "))
			sscanf(buff, "%*s %d", &do_screen_clear);
		else if (match(buff, "ambient ")) {
			sscanf(buff, "%*s %d", &current_view->ambient);
			/* current_view->ambient = (0.3 * (r%256) + 0.59 * (g%256) + 0.21 * (b%256)) / 3; */
		}
		else if (match(buff, "worldscale ")) {
			float ws;
			sscanf(buff, "%*s %f", &ws);
			default_stereo.world_scaling = 65536.0 * ws;
		}
		else if (match(buff, "light "))
			/* light x,y,z r,g,b dx,dy,dz angle radius sampling sampling */
			sscanf(buff, "%*s %ld,%ld,%ld",
			&default_view.lx, &default_view.ly, &default_view.lz);
		else if (match(buff, "window ")) {
			int x, y, w, h;
			switch (sscanf(buff, "%*s %d,%d,%d,%d", &x, &y, &w, &h)) {
			case 4:
				default_view.bottom = y + h - 1;
			case 3:
				default_view.right = x + w - 1;
			case 2:
				default_view.top = y;
			case 1:
				default_view.left = x;
			default:
				break;
			};
		}
		else if (match(buff, "key ")) {
			char fname[100];
			unsigned key, param;
			int i;
			sscanf(buff, "%*s %x %s %u", &key, fname, &param);
			for (i = 0; functions[i].name; ++i)
				if (!stricmp(fname, functions[i].name)) {
					KEY *k;
					if ((k = malloc(sizeof(KEY))) != NULL) {
						k->key = key; 
						k->param = param;
						k->fn = functions[i].fn;
						k->next = keylist; 
						keylist = k;
					}
					break;
				}
		}
		else if (match(buff, "control ")) {
			char fname[100];
			int x, y, w, h;
			unsigned mask, param;
			int i;
			sscanf(buff, "%*s %d,%d,%d,%d %u %s %u",
			&x, &y, &w, &h, &mask, fname, &param);
			for (i = 0; functions[i].name; ++i)
				if (!stricmp(fname, functions[i].name)) {
					CONTROL *c;
					if ((c = malloc(sizeof(CONTROL))) != NULL) {
						c->x = x; 
						c->y = y; 
						c->w = w; 
						c->h = h;
						c->buttonmask = mask; 
						c->fn = functions[i].fn;
						c->param = param;
						c->next = controllist; 
						controllist = c;
					}
					break;
				}
		}
		else if (match(buff, "frame ")) {
			FILE *in;
			sscanf(buff, "%*s %s %d,%d,%d,%d", framefname, &frame_x, &frame_y, &frame_w, &frame_h);
			use_frame = 1;
		}
		else if (match(buff, "start ")) {
			float pan, tilt, roll, zoom;
			sscanf(buff, "%*s %ld,%ld,%ld %f,%f,%f %f",
			&default_view.ex, &default_view.ey, &default_view.ez,
			&pan, &tilt, &roll, &zoom);
			if (zoom == 0) zoom = 3;
			default_view.pan = pan * 65536L; 
			default_view.tilt = tilt * 65536L;
			default_view.roll = roll * 65536L; 
			default_view.zoom = zoom * 65536L;
		}
		else if (match(buff, "hither "))
			sscanf(buff, "%*s %ld", &default_view.hither);
		else if (match(buff, "yon "))
			sscanf(buff, "%*s %ld", &default_view.yon);
		else if (match(buff, "eyespacing "))
			sscanf(buff, "%*s %ld", &default_stereo.phys_eye_spacing);
		else if (match(buff, "screendist "))
			sscanf(buff, "%*s %ld", &default_stereo.phys_screen_dist);
		else if (match(buff, "screenwidth "))
			sscanf(buff, "%*s %ld,%d", &default_stereo.phys_screen_width,
			&default_stereo.pixel_width);
		else if (match(buff, "convergence "))
			sscanf(buff, "%*s %ld", &default_stereo.phys_convergence);

		else if (match(buff, "figure "))
		{
			char filename[60], parentname[60], *p;
			float sx = 1, sy = 1, sz = 1, rx = 0, ry = 0, rz = 0;
			long tx = 0, ty = 0, tz = 0;
			FILE *fig;
			parentname[0] = '\0';
			sscanf(buff, "%*s %s %f,%f,%f %f,%f,%f %ld,%ld,%ld %s ",
			filename, &sx, &sy, &sz, &rx, &ry, &rz, &tx, &ty, &tz, parentname);
			strcat(filename, ".fig");
			set_readseg_scale(sx, sy, sz);
			if ((p = strchr(filename, '=')) != NULL)
				*p++ = '\0';
			else
				p = filename;
			if ((fig = fopen(fix_fname(p), "r")) != NULL)
			{
				SEGMENT *this_seg;
				set_readseg_objlist(objlist);
				if ((this_seg = readseg(fig, NULL)) != NULL)
				{
					abs_move_segment(this_seg, tx, ty, tz);
					abs_rot_segment(this_seg, rx*65536L, ry*65536L, rz*65536L, RYXZ);
					update_segment(this_seg);
				}
				fclose(fig);
			}
		}

		else if (match(buff, "object "))
		{
			char mappings[100], *p, filename[100], *oname, parentname[100];
			float sx = 1, sy = 1, sz = 1, rx = 0, ry = 0, rz = 0;
			long tx = 0, ty = 0, tz = 0;
			int dt = 0;
			MATRIX m;
			FILE *plg;
			OBJECT *obj;

			parentname[0] = mappings[0] = '\0';
			sscanf(buff, "%*s %s %f,%f,%f %f,%f,%f %ld,%ld,%ld %d %s %s",
			filename, &sx, &sy, &sz, &rx, &ry, &rz, &tx, &ty, &tz, &dt, mappings, parentname);
			strcat(filename, ".plg");
			set_loadplg_scale(sx, sy, sz);
			set_loadplg_depthsort(dt);

			map = find_name(maps, mappings);

			if ((p = strchr(filename, '=')) != NULL)
			{
				oname = filename;
				*p++ = '\0';
			}
			else
			{
				oname = NULL;
				p = filename;
			}
			if ((plg = fopen(fix_fname(p), "r")) != NULL)
			{
				while((obj=load_plg(plg))!=NULL)
					if (obj)
					{
						if (map)
						{
							int np;

							get_obj_info(obj, NULL, &np);
							while (np--)
							{
								SURFACE *p;
								unsigned color;
								void *v;

								get_poly_info(obj, np, &color, NULL, NULL, 0);
								for (p = map; p; p = p->next)
									if (p->color == color)
									{
										if ((v = find_name(surfdefs, p->value)) != NULL)
											set_poly_color(obj, np, (unsigned) v);
										break;
									}
							}
						}

						if (oname) add_name(&objectlist, oname, obj);
						oname = NULL; /* so it's done once only */

						if (!stricmp(parentname, "fixed"))
						{
							std_matrix(m, (long) (rx * 65536L), (long) (ry * 65536L),
							(long) (rz * 65536L), tx, ty, tz);
							apply_matrix(obj, m);
							if (current_split)
								add_obj_to_split_center(current_split, obj);
							else
								add_obj_to_split_area(split_tree, obj);
						}
						else
							{
							SEGMENT *s, *p = NULL;
							OBJECT *o;

							if ((o = find_name(objectlist, parentname)) != NULL)
								p = get_object_owner(o);
							s = new_seg(p);
							seg_set_object(s, obj);
							set_object_owner(obj, s);
							abs_rot_segment(s, rx * 65536L, ry * 65536L, rz * 65536L, RYXZ);
							abs_move_segment(s, tx, ty, tz);
							update_segment(s);
						}
					}
			}
			fclose(plg);
		}

		else if (match(buff, "task ")) {
			char taskname[100], param[100];
			long period;
			int i;
			void *data;
			sscanf(buff, "%*s %s %ld %s", taskname, &period, param);
			for (i = 0; functions[i].name; ++i)
				if (!stricmp(taskname, functions[i].name)) {
					add_task(&tasklist, functions[i].fn, period, param);
					break;
				}
		}
		else if (match(buff, "position ")) {
			OBJECT *obj; 
			SEGMENT *s;
			char oname[100];
			long x, y, z;
			sscanf(buff, "%*s %s %ld,%ld,%ld", oname, &x, &y, &z);
			if ((obj = find_name(objectlist, oname)) != NULL)
				if ((s = get_object_owner(obj)) != NULL) {
					abs_move_segment(s, x, y, z);
					update_segment(s);
					remove_from_objlist(obj);
					add_obj_to_split_area(split_tree, obj);
				}
		}
		else if (match(buff, "rotate ")) {
			OBJECT *obj; 
			SEGMENT *s;
			char oname[100];
			float rx, ry, rz;
			sscanf(buff, "%*s %s %f,%f,%f", oname, &rx, &ry, &rz);
			if ((obj = find_name(objectlist, oname)) != NULL)
				if ((s = get_object_owner(obj)) != NULL) {
					abs_rot_segment(s, rx * 65536L, ry * 65536L, rz * 65536L, RYXZ);
					update_segment(s);
				}
		}
		else if (match(buff, "camera ")) {
			int n;
			long x = default_view.ex, y = default_view.ey, z = default_view.ez;
			float pan = default_view.pan, tilt = default_view.tilt, roll = default_view.roll;
			float zoom = default_view.zoom;
			float hither = default_view.hither, yon = default_view.yon;
			sscanf(buff, "%*s %d %ld,%ld,%ld %f,%f,%f %f %ld %ld",
			&n, &x, &y, &z, &tilt, &pan, &roll, &zoom, &hither, &yon);
			--n; /* camera 1 is on key 0 ... */
		}
		else if (match(buff, "attrib ")) {
			/* ignore for now */
		}
		else if (match(buff, "include ")) {
			char fname[100];
			FILE *in;
			sscanf(buff, "%*s %s", fname);
			if ((in = fopen(fname, "r")) != NULL) {
				read_world(in);
				fclose(in);
			}
		}
		else if (match(buff, "surfacemap ")) {
			/* starts a new map of color numbers to surface names */
			sscanf(buff, "%*s %s", surfacemapname);
			current_surface = NULL;
		}
		else if (match(buff, "surface ")) {
			SURFACE *p;
			/* maps a color number to a surface name */
			if ((p = malloc(sizeof(SURFACE))) != NULL) {
				char buf2[40];
				if (current_surface == NULL)
					add_name(&maps, surfacemapname, p);
				else
					current_surface->next = p;
				current_surface = p;
				p->next = NULL;
				sscanf(buff, "%*s %u %s %*s", &p->color, buf2);
				p->value = strdup(buf2);
			}
		}
		else if (match(buff, "surfacedef ")) {
			char sname[100], svalue[20];
			/* maps a surface name to an internal color value */
			sscanf(buff, "%*s %s %s", sname, svalue);
			add_name(&surfdefs, sname, (void *) strtoul(svalue, NULL, 0));
		}
		else if (match(buff, "split ")) {
			float x, y, z, nnx, nny, nnz;
			long nx, ny, nz;
			unsigned flags = 0;
			set_move_handler(split_move_handler);
			set_global_split_root(&split_tree);
			if (sscanf(buff, "%*s %f,%f,%f %f,%f,%f %u", &x, &y, &z,
			&nnx, &nny, &nnz, &flags) > 5)
			{
				scale3(nnx, nny, nnz, &nx, &ny, &nz);
				current_split = add_split(&split_tree, x, y, z, nx, ny, nz, flags);
			}
		}
		else if (match(buff, "splitpt ")) {
			float x1, x2, x3, y1, y2, y3, z1, z2, z3;
			long nx, ny, nz;
			unsigned flags = 0;
			set_move_handler(split_move_handler);
			set_global_split_root(&split_tree);
			if (sscanf(buff, "%*s %f,%f,%f %f,%f,%f %f,%f,%f %u", &x1, &y1, &z1,
			&x2, &y2, &z2, &x3, &y3, &z3, &flags) > 8)
			{
				points_to_normal(x1, y1, z1, x2, y2, z2, x3, y3, z3, &nx, &ny, &nz);
				current_split = add_split(&split_tree, x1, y1, z1, nx, ny, nz, flags);
			}
		}
		else if (match(buff, "area ")) {
			long x, y, z;
			void *what_area();
			char areaname[100];
			sscanf(buff, "%*s %ld,%ld,%ld %s", &x, &y, &z, areaname);
			add_name(&areas, areaname, what_area(split_tree, x, y, z));
		}
		else if (match(buff, "floor ")) {
			char aname[100];
			float aa, bb, cc, dd;
			long a,b,c,d;
			sscanf(buff, "%*s %s %f,%f,%f,%f", aname, &aa, &bb, &cc, &dd);
			scale4(aa, bb, cc, dd, &a, &b, &c, &d);
			add_floor(find_name(areas, aname), a, b, c, d);
		}
		else if (match(buff, "floorpts ")) {
			char aname[100];
			float x1, y1, z1, x2, y2, z2, x3, y3, z3;
			long a, b, c, d;
			sscanf(buff, "%*s %s %f,%f,%f %f,%f,%f %f,%f,%f",
			aname, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);
			points_to_eqn(x1, y1, z1, x2, y2, z2, x3, y3, z3, &a, &b, &c, &d);
			add_floor(find_name(areas, aname), a, b, c, d);
		}
		else if (match(buff, "ceiling ")) {
			char aname[100];
			float aa, bb, cc, dd;
			long a, b, c, d;
			sscanf(buff, "%*s %s %f,%f,%f,%f", aname, &aa, &bb, &cc, &dd);
			scale4(aa, bb, cc, dd, &a, &b, &c, &d);
			add_ceiling(find_name(areas, aname), a, b, c, d);
		}
		else if (match(buff, "ceilingpts ")) {
			char aname[100];
			float x1, y1, z1, x2, y2, z2, x3, y3, z3;
			long a, b, c, d;
			sscanf(buff, "%*s %s %f,%f,%f %f,%f,%f %f,%f,%f",
			aname, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);
			points_to_eqn(x1, y1, z1, x2, y2, z2, x3, y3, z3, &a, &b, &c, &d);
			add_ceiling(find_name(areas, aname), a, b, c, d);
		}
		else if (match(buff, "visfrom ")) {
			char aname[100], alist[1000], *p;
			AREA *a, *b;
			sscanf(buff, "%*s %s %s", aname, alist);
			if ((a = find_name(areas, aname)) != NULL)
				for (p = strtok(alist, ","); p; p = strtok(NULL, ","))
					if ((b = find_name(areas, p)) != NULL)
						add_visfrom(a, b);
		}
		else if (match(buff, "passage ")) {
		}
		else if (match(buff, "endsplits"))
		{
			current_split = NULL;
		}
		else if (match(buff, "polyobj "))
		{
			char map[100];
			OBJECT *obj;
			POLY *poly;
			unsigned color;
			int nv = 0;
			int i;
			long x[8], y[8], z[8];

			map[0] = '\0';
			set_loadplg_depthsort(0);
			sscanf(buff, "%*s %d %s %ld,%ld,%ld %ld,%ld,%ld %ld,%ld,%ld   \
															%ld,%ld,%ld %ld,%ld,%ld %ld,%ld,%ld   \
															%ld,%ld,%ld %ld,%ld,%ld ", &nv, map,
			&x[0], &y[0], &z[0], &x[1], &y[1], &z[1],
			&x[2], &y[2], &z[2], &x[3], &y[3], &z[3],
			&x[4], &y[4], &z[4], &x[5], &y[5], &z[5],
			&x[6], &y[6], &z[6], &x[7], &y[7], &z[7]);
			if (nv > 8) nv = 8;
			obj = new_obj(0, nv, 1);
			if (obj)
			{
				if (map)
					color = (unsigned) find_name(surfdefs, map);
				poly = add_poly(obj, color, nv);
				for (i = 0; i < nv; i++)
				{
					add_vertex(obj, x[i], y[i], z[i]);
					add_point(obj, poly, nv-i-1);
				}
				compute_obj(obj);
				if (current_split)
					add_obj_to_split_center(current_split, obj);
				else
					add_obj_to_split_area(split_tree, obj);
			}
		}

		/* CONFIG FILE LOAD STUFF */

		/* THESE DONE AFTER LOADING */

		else if (match(buff, "videodev"))
		{
			extern char vdname[];
 			extern int vdmode;
 			sscanf(buff, "%*s %s %x", vdname, &vdmode);
		}
		else if (match(buff, "mousedev"))
		{
			extern char mdname[];
			sscanf(buff, "%*s %s", mdname);
		}
		else if (match(buff, "headdev"))
		{
			extern char hdname[];
			extern float hdo_x, hdo_y, hdo_z, hdo_rx, hdo_ry, hdo_rz;
			sscanf(buff, "%*s %s %f %f %f %f %f %f", hdname, &hdo_x, &hdo_y, &hdo_z, &hdo_rx, &hdo_ry, &hdo_rz);
		}
		else if (match(buff, "glovedev"))
		{
			extern char gpdname[];
			extern int have_glove;
			extern float gpdo_x, gpdo_y, gpdo_z, gpdo_rx, gpdo_ry, gpdo_rz;
			have_glove = 1;
			sscanf(buff, "%*s %s %f %f %f %f %f %f", gpdname, &gpdo_x, &gpdo_y, &gpdo_z, &gpdo_rx, &gpdo_ry, &gpdo_rz);
		}
		else if (match(buff, "ptrdev"))
		{
			extern char gpdname[];
			extern int have_ptr;
			extern float gpdo_x, gpdo_y, gpdo_z, gpdo_rx, gpdo_ry, gpdo_rz;
			have_ptr = 1;
			sscanf(buff, "%*s %s %f %f %f %f %f %f", gpdname, &gpdo_x, &gpdo_y, &gpdo_z, &gpdo_rx, &gpdo_ry, &gpdo_rz);
		}
		else if (match(buff, "switchdev"))
		{
			extern char swdname[];
			sscanf(buff, "%*s %s", swdname);
		}
		else if (match(buff, "glovecursor"))
		{
			extern char gpcursor[];
			sscanf(buff, "%*s %s", gpcursor);
		}
		else if (match(buff, "ptrcursor"))
		{
			extern char gpcursor[];
			sscanf(buff, "%*s %s", gpcursor);
		}

		/* CONFIG: DONE IMMEDIATELY */

		else if (match(buff, "segaport"))
		{
			sscanf(buff, "%*s %x %x %x %x %x", &sega_address,
			&sega_mask, &sega_left, &sega_right, &sega_doff, &sega_port_image);
		}
		else if (match(buff, "pgloveport"))
		{
			sscanf(buff, "%*s %x %x %x %x %x %x %x %x", &glove_in_port, &glove_out_port,
			&glove_write_mask, &glove_none_mask, &glove_latch_mask, &glove_clock_mask,
			&glove_clock_latch, &glove_data_mask, &port_image );
		}
		else if (match(buff, "pglovetime"))
		{
			sscanf(buff, "%*s %d %d", &glove_bit_delay, &glove_byte_delay );
		}
		else if (match(buff, "stereoset"))
		{
			float ws = 1.0;
			sscanf(buff, "%*s %ld %ld %ld %ld %ld %f", &(default_stereo.phys_screen_dist),
			&(default_stereo.phys_screen_width), &(default_stereo.pixel_width),
			&(default_stereo.phys_eye_spacing), &(default_stereo.phys_convergence), &ws);
			default_stereo.world_scaling = 65536.0 * ws;
		}
		else if (match(buff, "stereotype"))
		{
			char st[80];
			extern int stereo_type;
			sscanf(buff, "%*s %s", st);
			if (match(st, "OFF")) stereo_type = MONOSCOPIC;
			else if (match(st, "SWITCH")) stereo_type = SWITCHED;
			else if (match(st, "SEPARATE")) stereo_type = SEPARATE;
			else if (match(st, "SPLIT")) stereo_type = SPLITLR;
		}
		else if (match(buff,"stereoleft"))
		{
			sl_left = -1;
			sscanf(buff, "%*s %d %d %f %ld %ld %ld %ld %ld", &sl_xoff, &sl_xflip,
			&sl_xrot, &sl_left, &sl_top, &sl_right, &sl_bottom );
		}
		else if (match(buff,"stereoright"))
		{
			sr_left = -1;
			sscanf(buff, "%*s %d %d %f %ld %ld %ld %ld %ld", & sr_xoff, &sr_xflip,
			&sr_xrot, &sr_left, &sr_top, &sr_right, &sr_bottom );
		}


	}
	return 0;
}

