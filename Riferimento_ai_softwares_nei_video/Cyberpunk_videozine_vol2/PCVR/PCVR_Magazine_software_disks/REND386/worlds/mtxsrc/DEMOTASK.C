/* Animation routines for sample virtual world */

/* Written by Bernie Roehl, July 1992 */

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
#include <string.h>
#include <stdlib.h>
#include "rend386.h"
#include "intmath.h"
#include "tasks.h"

#include "demo.h"

extern int redraw;

#define MAXSPINCOLORS 100

typedef struct {
	OBJECT *obj;
	int np; /* number of polys in obj */
	int ncolors;
	unsigned colors[MAXSPINCOLORS];
} SPINDATA;

extern void *objectlist;
extern void *find_name();

void spinner(int cmd, char *init, long now, long period)
{
	char *colorlist, *q;
	SPINDATA *data, **dataptr;
	int i, color;
	switch (cmd) {
		case 0:
			if ((data = malloc(sizeof(SPINDATA))) == NULL) return;
			dataptr = find_task_data(get_current_task());
			*dataptr = data;
			data->ncolors = 0;
			if ((colorlist = strchr(init, ';')) != NULL) {
				*colorlist++ = '\0';
				for (colorlist = strtok(colorlist, ","); colorlist; colorlist = strtok(NULL, ","))
					if (data->ncolors >= MAXSPINCOLORS)
						break;
					else
						data->colors[data->ncolors++] = strtoul(colorlist, NULL, 0);
			}
			data->obj = find_name(objectlist, init);
			if (data->obj) get_obj_info(data->obj, NULL, &data->np);
			break;
		case 1:
			dataptr = find_task_data(get_current_task());
			data = *dataptr;
			if (data == NULL) return;
			if (data->obj == NULL) return;
			color = (now/period) % data->ncolors;
			for (i = 0; i < data->np; ++i)
				set_poly_color(data->obj, i, data->colors[(color+i) % data->ncolors]);
			redraw = 1;
			break;
		default:
			break;
	}
}


typedef struct {
	SEGMENT *seg;
	long rx,ry,rz;
} SCULDATA;

extern SEGMENT *find_seg(char *name);

void sculspin(int cmd, char *init, long now, long period)
{
	SCULDATA *data, **dataptr;
	OBJECT *obj;
	char *parms;
	float rx, ry, rz;

	switch (cmd) {
		case 0:
			if ((data = malloc(sizeof(SCULDATA))) == NULL) return;
			dataptr = find_task_data(get_current_task());
			*dataptr = data;
			data->rx = data->ry = data->rz = 0;
			if ((parms = strchr(init, ';')) != NULL) {
				*parms++ = '\0';
				sscanf(parms, "%f,%f,%f", &rx, &ry, &rz);
				data->rx = rx * 65536L;
				data->ry = ry * 65536L;
				data->rz = rz * 65536L;
			}
			data->seg = find_seg(init);

/*			obj = find_name(objectlist, init);
			if (obj)
				data->seg = get_object_owner(obj); */
			break;
		case 1:
			dataptr = find_task_data(get_current_task());
			data = *dataptr;
			if (data == NULL) return;
			if (data->seg == NULL) return;
			rel_rot_segment(data->seg, data->rx, data->ry, data->rz, RYXZ);
			update_segment(data->seg);
			redraw = 1;
			break;
		default:
			break;
	}
}
