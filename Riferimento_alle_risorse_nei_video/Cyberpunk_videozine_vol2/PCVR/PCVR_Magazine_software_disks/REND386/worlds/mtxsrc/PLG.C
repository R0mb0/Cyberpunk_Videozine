/* PLG file i/o */

/* Written by Bernie Roehl, March 1992 */
/* updated by Dave Stampe */

#include <stdio.h>
#include <stdlib.h>  /* atoi(), atol() */
#include <string.h>
#include <alloc.h>
#include <ctype.h>   /* isalnum() */
#include "rend386.h"
#include "plg.h"
#ifdef ENCRYPT
#include "encrypt.h"
#endif

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

int load_err = 0; /* set if an error was encountered during loading */
int err_line = 1; /* line on which error occurred */

char *plg_errmsgs[] = {
	"No error",
	"Bad syntax in header line",
	"Couldn't create new object",
	"Couldn't add representation",
	"Early EOF while reading vertices",
	"Bad syntax in vertex line",
	"Early EOF while reading polygons",
	"Missing vertex count in polygon line",
	"Missing vertex index in polygon line",
	"Couldn't add polygon",
	"Vertex number out of range",
	NULL };

static long xshift = 0, yshift = 0, zshift = 0;
static float xrescale = 1, yrescale = 1, zrescale = 1;
static int depthsort = 0;

static unsigned *cmap;
static int mapsize = 0;

long lx, ly, lz; /* DEBUG */

static unsigned mapcolor(unsigned orig)
{
	if ((orig & 0x8000) == 0) return orig; /* only map if top bit set */
	orig &= 0x7FFF; /* turn the top bit off */
	if (cmap == NULL) return orig; /* no map */
	if (orig > mapsize) return orig; /* color not in map */
	return cmap[orig]; /* map it */
}

void set_loadplg_colormap(unsigned *map, int msize)
{
	cmap = map;
	mapsize = msize;
}

void set_loadplg_offset(long x, long y, long z)
{
	xshift = x; 
	yshift = y; 
	zshift = z;
}

void set_loadplg_scale(float x, float y, float z)
{
	xrescale = x;
	yrescale = y; 
	zrescale = z;
}

void set_loadplg_depthsort(int type)
{
	depthsort = type;
}

void strip_comment(char *buff) /* also trim newline character(s) */
{
	char *p;
	if ((p = strchr(buff, '\n')) != NULL) *p = '\0'; /* trim newline */
	if ((p = strchr(buff, '#')) != NULL) *p = '\0'; /* trim comment */
	if ((p = strchr(buff, '*')) != NULL) *p = '\0'; /* future expansion */
	if(sscanf(buff,"%*s")==EOF) buff[0] = 0; /* dump tabs, etc */
}

static long default_size;
static int maxpolys;
static int maxverts;
static int multirep = 0;

static int load_in_plg_file(FILE *in, OBJECT **obj)
{
	char tbuff[1000], objname[100];
	int nv, np, i;
	char *p;
	long size = 0;
	int multi = (*obj) ? 1 : 0; /* multi-reps if not null object */

	multirep = 0;

	/* skip blank lines */
	do {
		if (fgets(tbuff, sizeof(tbuff), in) == NULL) return -1;
#ifdef ENCRYPT
		if (tbuff[0] == 26) decrypt_buffer(tbuff);
#endif
		++err_line;
		if (strstr(tbuff,"#MULTI")) multi++;
		if (multi) multirep++;
		strip_comment(tbuff);
	}
	while (tbuff[0] == '\0');

	if (sscanf(tbuff, "%s %d %d", objname, &nv, &np) != 3)
	{
		load_err = -1;
		return -1;
	}

	if (multi && (p = strchr(objname, '_')) != NULL)
	{
		*p++ = 0;
		size = atol(p);
	}
	else size = default_size; /* default: use largest detail always */

	if (*obj == NULL)
	{
		if ((*obj = new_obj(0, nv, np)) == NULL)
		{
			load_err = -2;
			return -1;
		}
		set_rep_size(*obj, size);
	}
	else
		{
		if (add_representation(*obj, size, nv, np) == NULL)
		{
			load_err = -3;
			return -1;
		}
	}

	maxpolys = np;
	maxverts = nv;

	for (i = 0; i < nv; ++i) /* load in vertices */
	{
		float x, y, z;
		/* skip blank lines */
		do
			{
			if (fgets(tbuff, sizeof(tbuff), in) == NULL)
			{
				load_err = -4;
				return -1;
			}
#ifdef ENCRYPT
			if (tbuff[0] == 26) decrypt_buffer(tbuff);
#endif
			++err_line;
			strip_comment(tbuff);
		}
		while (tbuff[0] == '\0');

		if (sscanf(tbuff, "%f %f %f", &x, &y, &z) != 3)
		{
			load_err = -5;
			return -1;
		}

		add_vertex(*obj, (lx = (long) (x*xrescale))+xshift,
		(ly = (long) (y*yrescale))+yshift,
		(lz = (long) (z*zrescale))+zshift);
		lx++;
	}

	for (i = 0; i < np; ++i) /* load polygons */
	{
		int j, npoints;
		unsigned color;
		POLY *poly;
		char *p;
		/* skip blank lines */
		do
			{
			if (fgets(tbuff, sizeof(tbuff), in) == NULL)
			{
				load_err = -6;
				return -1;
			}
#ifdef ENCRYPT
			if (tbuff[0] == 26) decrypt_buffer(tbuff);
#endif
			++err_line;
			strip_comment(tbuff);
		}
		while (tbuff[0] == '\0');

		color = convert_color(tbuff,&p);
		color = mapcolor(color);
		if ((p = strtok(p, " \t")) == NULL)
		{
			load_err = -7;
			return -1;
		}
		npoints = atoi(p);
		if ((poly = add_poly(*obj, color, npoints)) == NULL)
		{
			load_err = -9;
			return -1;
		}
		for (j = 0; j < npoints; ++j)
		{
			int vertnum;
			if ((p = strtok(NULL, " \t")) == NULL)
			{
				load_err = -8;
				return -1;
			}
#ifdef OLD
			if (atoi(p) < maxverts && atoi(p) >= 0)
				add_point(*obj, poly, atoi(p));
			else add_point(*obj, poly, maxverts-1);
#else
			vertnum = atoi(p);
			if (vertnum < 0 || vertnum >= maxverts) {
				load_err = -10;
				return -1;
			}
			add_point(*obj, poly, vertnum);
#endif
		}
	}
	compute_obj(*obj); /* will do current rep only */
	load_err = 0;
	return 0;
}

OBJECT *load_plg(FILE *in)
{
	OBJECT *obj = NULL;
	default_size = 0;
	load_err = 0;
	err_line = 1;
	if (load_in_plg_file(in, &obj)) return NULL;
	set_object_sorting(obj, depthsort);
	return obj;
}

OBJECT *load_multi_plg(FILE *in)
{
	OBJECT *obj = NULL;
	int ocount = 0;
	default_size = 0;
	load_err = 0;
	err_line = 1;
	while (load_in_plg_file(in, &obj) == 0)
	{
		ocount++;
		if (!multirep) break;
	}
	if (ocount == 0) return NULL;
	set_object_sorting(obj, depthsort);
	return obj;
}

OBJECT *load_extra_rep(FILE *in, OBJECT *obj, long size)
{
	int ocount = 0;
	default_size = size;
	load_err = 0;
	err_line = 1;

	while (load_in_plg_file(in, &obj) == 0)
	{
		ocount++;
		if (!multirep) break;
	}
	if (ocount == 0) return NULL;
	set_object_sorting(obj, depthsort);
	return obj;
}


save_plg(OBJECT *obj, FILE *out, int world)
{
	int nv, np, i; /* now saves all representations */
	char buff[100];

	first_rep(obj);
	do
		{
		get_obj_info(obj, &nv, &np);
		fprintf(out, "SAVED %d %d\n", nv, np);
		for (i = 0; i < nv; ++i)
		{
			long x, y, z;
			if (world) get_vertex_world_info(obj, i, &x, &y, &z);
			else get_vertex_info(obj, i, &x, &y, &z);
			fprintf(out, "%ld %ld %ld\n", x, y, z);
		}
		for (i = 0; i < np; ++i)
		{
			int j, n, verts[1000];
			unsigned c;
			get_poly_info(obj, i, &c, &n, verts, sizeof(verts)/sizeof(int));
			fprintf(out, "0x%04.4X %d", c & 0x7FFF, n);
			for (j = 0; j < n; ++j) fprintf(out, " %d", verts[j]);
			fprintf(out, "\n");
		}
	}
	while (!next_rep(obj));

	return 0;
}
