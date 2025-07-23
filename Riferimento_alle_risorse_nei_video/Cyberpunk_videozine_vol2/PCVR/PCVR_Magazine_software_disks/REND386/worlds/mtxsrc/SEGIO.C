/* Segment file i/o */

/* Written by Bernie Roehl, March 1992 */

/* Copyright 1992 by Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl
   for permission to incorporate any part of this software into their
   products!

	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
 */

/* The format of a segment file is simple, and very C-like.  Each segment
   is bounded by { and }, and contains any combination of attributes and
   additional segments (which are children of the segment they appear in).
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "rend386.h"
#include "intmath.h"  /* for RYZ definition */
#include "plg.h"
#include "segio.h"

extern char *fix_fname(char *fname);

int readseg_err = 0;

char *readseg_errmsgs[] = {
	"No error",
	"Couldn't open plg file",
	"Error reading plg file",
	"Bad syntax",
	"Couldn't open map file",
	NULL };

#define match(a, b) (!strnicmp((a), (b), strlen(b)))

static OBJLIST *curr_objlist = NULL;

static char *boundstypes[] = { 
	"NONE", "SPHERE", "BOX", "CSG", NULL };

void set_readseg_objlist(OBJLIST *olist)
{
	curr_objlist = olist;
}

static SEGMENT **seg_array = NULL;
static int seg_array_size = 0;

void set_readseg_seglist(SEGMENT **ptr, int maxsegs)
{
	seg_array = ptr;
	seg_array_size = maxsegs;
}

static float seg_scalex = 1; /* for pos'n and rotate, just */
static float seg_scaley = 1; /* attach a parent, update,   */
static float seg_scalez = 1; /* then detach it again       */

void set_readseg_scale(float x, float y, float z)
{
	seg_scalex = x;
	seg_scaley = y;
	seg_scalez = z;
}

static unsigned cmap[1000];
static int cmapsize = 0;

static int process_attribute(char *buff, SEGMENT *seg)
{
	char filename[100];
	float sx = 1, sy = 1, sz = 1;
	long tx = 0, ty = 0, tz = 0;
	int depth = 0;
	FILE *in;
	cmapsize = 0;
	while (isspace(*buff)) ++buff;
	if (match(buff, "plgfile")) {
		OBJECT *obj;
		char mapfile[100];
		mapfile[0] = '\0';
		sscanf(buff, "plgfile = %s scale %f,%f,%f shift %ld,%ld,%ld sort %d map %s", filename, &sx, &sy, &sz, &tx, &ty, &tz, &depth, mapfile);
		if (mapfile[0]) {
			if ((in = fopen(fix_fname(mapfile), "r")) == NULL) {
				readseg_err = -4;
				return -1;
			}
			for (cmapsize = 0; cmapsize < sizeof(cmap)/sizeof(unsigned) && !feof(in); ++cmapsize) {
				char buff[100], *p;
				fgets(buff, sizeof(buff), in);
				strip_comment(buff);
				cmap[cmapsize] = (unsigned) strtoul(buff,&p,0); /* req so hex colors usable */
			}
			fclose(in);
		}
		set_loadplg_scale(sx*seg_scalex, sy*seg_scaley, sz*seg_scalez);
		set_loadplg_offset(tx*seg_scalex, ty*seg_scaley, tz*seg_scalez);
		set_loadplg_depthsort(depth);
		set_loadplg_colormap(cmap, cmapsize);
		if ((in = fopen(fix_fname(filename), "r")) == NULL) {
			readseg_err = -1;
			return -1;
		}
		if ((obj = load_multi_plg(in)) == NULL) {
			readseg_err = -2;
			fclose(in);
			return -2;
		}
		seg_set_object(seg, obj);
		set_object_owner(obj, seg);
		if (curr_objlist) add_to_objlist(curr_objlist, obj);
		fclose(in);
		return 0;
	}
	else if (match(buff, "pos")) {
		long tx, ty, tz;
		sscanf(buff, "pos = %ld,%ld,%ld", &tx, &ty, &tz);
		abs_move_segment(seg, tx*seg_scalex, ty*seg_scaley, tz*seg_scalez);
	}
	else if (match(buff, "rot")) {
		float rx, ry, rz;
		sscanf(buff, "rot = %f,%f,%f", &rx, &ry, &rz);
		abs_rot_segment(seg, (long) (rx * 65536L), (long) (ry * 65536L), (long) (rz * 65536L), RYXZ);
	}
	else if (match(buff, "name")) {
		char *p;
		if ((p = strchr(buff, '=')) == NULL) {
			readseg_err = -3;
			return -3;
		}
		do ++p;
		while (isspace(*p));
		seg_setname(seg, p);
	}
	else if (match(buff, "segnum")) {
		int j;
		sscanf(buff, "segnum = %d", &j);
		if (seg_array && j < seg_array_size) seg_array[j] = seg;
	}
	/* ignore anything we don't understand */
	return 0;
}

SEGMENT *readseg(FILE *in, SEGMENT *parent)
{
	SEGMENT *seg;
	char buff[256];
	int c, i = 0;
	if ((seg = new_seg(parent)) == NULL) return NULL;
	while ((c = getc(in)) != EOF) {
		switch (c) {
		case '#':
			while ((c = getc(in)) != EOF)
				if (c == '\n')
					break;
			break;
		case '{':
			readseg(in, seg);
			break;
		case '}':
			return seg;
		case ';':
			buff[i] = '\0';
			process_attribute(buff, seg);
			i = 0;
			break;
		default:
			if (i < sizeof(buff)-1) buff[i++] = c;
			break;
		}
	}
	return seg;
}

static void indent(FILE *out, int level)
{
	while (level--) fprintf(out, "\t");
}

writeseg(FILE *out, SEGMENT *s, int level)
{
	SEGMENT *p;
	void *q;
	long tx, ty, tz, rx, ry, rz;
	float frx, fry, frz;
	char *name;
	unsigned char btype;
	unsigned w;
	long lims[12];
	int depth;
	int i;
	indent(out, level);
	fprintf(out, "{\n");
	if ((name = seg_getname(s)) != NULL) {
		indent(out, level);
		fprintf(out, "name = %s;\n", name);
	}
	seg_getposxyz(s, &tx, &ty, &tz);
	seg_getposang(s, &rx, &ry, &rz);
	indent(out, level);
	fprintf(out, "pos = %ld,%ld,%ld;\n", tx, ty, tz);
	indent(out, level);
	fprintf(out, "rot = %f,%f,%f;\n", ((float) rx) /65536L, ((float) ry) /65536L, ((float) rz) /65536L);

	indent(out, level);
	if ((q = seg_get_object(s)) != NULL) depth = get_object_sorting(q);
	else depth = 0;
	fprintf(out, "plgfile = %s scale %f,%f,%f shift %ld,%ld,%ld sort %d;\n", name, frx, fry, frz, tx, ty, tz, depth);
	for (p = child_segment(s); p; p = sibling_segment(p))
		writeseg(out, p, level+1);
	indent(out, level);
	fprintf(out, "}\n");
	return 0;
}
