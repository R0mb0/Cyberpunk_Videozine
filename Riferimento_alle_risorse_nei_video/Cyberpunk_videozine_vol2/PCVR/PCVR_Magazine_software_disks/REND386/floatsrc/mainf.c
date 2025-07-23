/* Mainline for testing 3D graphics routines */

/* Copyright 1992 by Bernie Roehl and Dave Stampe */

/* Written by Bernie Roehl and Dave Stampe, December 1991 */
/* Changed to support integers  by Dave Stampe */

/* REWRITTEN BACK TO FLOAT FOR EXAMPLE PURPOSES */

/* try args of: bishban.plg 0 800 -4000 0 0 0 2700 5200
   to see hither, yon clipping
   normally, use: bishban.plg 0 800 -4000 0 0 0 16 100000
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <alloc.h>
#include <string.h>

#include "3dstrucf.h"

static OBJECT *objlist = NULL;    /* the linked list of objects in the scene */

extern void render(OBJECT *objlist, VIEW *view, int v_page);
extern void dump_obj(OBJECT *obj);
extern OBJECT *load_object(FILE *in);
extern save_object(OBJECT *obj, FILE *out);
extern void compute_view_factors(VIEW *view);
extern void setup_render();
extern void reset_render();

extern POLY *vispolys[];  /* array of pointers to visible polygons */
extern int npols;       /* number of entries in vispolys */


static VIEW default_view;

char *progname = "3dview";

static VALUE prompt(char *s, long scale)
	{
	char c, buff[100];
	int i = 0;
	setcolor(1);
	outtextxy(0, 3*textheight(s), s);
	while ((c = bioskey(0) & 0x7F) != '\r')
		if (isdigit(c) || c == '.' || (i == 0 && c == '-')) {
			buff[i++] = c;
			buff[i] = '\0';
			outtextxy(textwidth(s), 3*textheight(s), buff);
			}
	buff[i] = '\0';
	return atof(buff)*scale;
	}

int debug = 0;
int wireframe = 0;

static int currmode = 0;  /* non-zero for polar mode */
static void polar_compute();

void main(int argc, char *argv[])
	{
	FILE *in;
	OBJECT *obj;
	int v_page = 0;
	if (argc < 2) {
		fprintf(stderr, "Usage: %s file [ex [ey [ez [pan [tilt [roll [hither [yon]]]]]]]]\n", progname);
		exit(0);
		}
	while (argc > 1 && argv[1][0] == '-') {
		if (!stricmp(argv[1], "-d")) ++debug;
		if (!stricmp(argv[1], "-w")) ++wireframe;
		if (!stricmp(argv[1], "-m")) ++currmode;
		--argc;
		++argv;
		}

	setup_render();
	atexit(reset_render);

	if ((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Could not open '%s'\n", argv[1]);
		exit(1);
		}
	while ((obj = load_object(in)) != NULL) {
		obj->next = objlist;
		objlist = obj;
		}
	fclose(in);
	default_view.lx = objlist->sphx + 2 * objlist->sphr;
	default_view.ly = objlist->sphy + 2 * objlist->sphr;
	default_view.lz = objlist->sphz + 2 * objlist->sphr;
	default_view.ex = objlist->sphx + 2 * objlist->sphr;  /* default viewing location */
	default_view.ey = objlist->sphy + 2 * objlist->sphr;
	default_view.ez = objlist->sphz + 2 * objlist->sphr;
	default_view.zoom = 3.0;
	default_view.aspect = 1.25;
	default_view.pan = -135;
	default_view.tilt = -25;
	default_view.roll = 0;
	default_view.hither = 1.0; default_view.yon = objlist->sphr * 4;
	default_view.top = 10.0; default_view.bottom = 190.0;
	default_view.left = 10.0; default_view.right = 310.0;

	if (argc > 2) default_view.ex = atof(argv[2]);
	if (argc > 3) default_view.ey = atof(argv[3]);
	if (argc > 4) default_view.ez = atof(argv[4]);
	if (argc > 5) default_view.pan = atof(argv[5]);
	if (argc > 6) default_view.tilt = atof(argv[6]);
	if (argc > 7) default_view.roll = atof(argv[7]);
	if (argc > 8) default_view.hither = atof(argv[8]);
	if (argc > 9) default_view.yon = atof(argv[9]);

	if (default_view.hither < 1) default_view.hither = 1;
	if (currmode) polar_compute();
	if (enter_graphics()) {
		fprintf(stderr, "Could not enter graphics mode\n");
		exit(1);
		}
	do {
		v_page ^= 1;  /* swap pages */
		compute_view_factors(&default_view);
		render(objlist, &default_view, v_page);
		set_vidpage(v_page,0);
		setactivepage(v_page);
		} while (do_key());
	exit_graphics();
	}

#define PGUP      0x4900
#define PGDN      0x5100
#define LARROW    0x4B00
#define RARROW    0x4D00
#define UP        0x4800
#define DOWN      0x5000

unsigned getkey()
	{
	unsigned c;
	if ((c = bioskey(0)) & 0xFF)
		c &= 0xFF;
	return c;
	}

void show_help(char **helptext)
	{
	int i;
	exit_graphics();
	clrscr();
	for (i = 0; helptext[i]; ++i) puts(helptext[i]);
	bioskey(0);
	enter_graphics();
	}

void change_stuff()
	{
	char buff[100];
	setcolor(1);
	sprintf(buff, "Change hither, yon, zoom?");
	outtextxy(0, 2*textheight(buff), buff);
	switch (getkey()) {
		case 'y': default_view.yon = prompt("New yon value:",1); break;
		case 'z': default_view.zoom = prompt("New zoom value:",1); break;
		case 'h':
			default_view.hither = prompt("New hither value:",1);
			if (default_view.hither < 1) default_view.hither = 1;
			break;
		}
	}

static VALUE distance = 1000;
static VALUE ldistance = 10000;
static ANGLE latitude = 0, longitude = 0;
static VALUE polarx, polary, polarz;

#define to_rad(a) ((a) * 3.14159262 / 180.0)

void polar_compute()
	{
	default_view.ex = distance * cos(to_rad(latitude)) *
				     sin(to_rad(longitude)) + polarx;
	default_view.ey = distance * sin(to_rad(latitude)) + polary;
	default_view.ez = -distance * cos(to_rad(latitude)) *
				      cos(to_rad(longitude)) + polarz;
	default_view.lx = ldistance * cos(to_rad(latitude+60)) *
				     sin(to_rad(longitude+70)) + polarx;
	default_view.ly = ldistance * sin(to_rad(latitude+60)) + polary;
	default_view.lz = -ldistance * cos(to_rad(latitude+60)) *
				      cos(to_rad(longitude+70)) + polarz;
	default_view.pan = -longitude;
	default_view.tilt = -latitude;
	}

char *helptext[] = {
"                                 HELP",
"",
"            You are currently in three-axis (X, Y, Z) mode",
"",
"     x, y and z change the X, Y and Z coordinates of the eyepoint",
"  (left-handed system; at origin X is right Y is up and Z is forwards)",
"",
"p  changes the pan (azimuth) angle; a positive angle pans to the right",
"t  changes the tilt (elevation) angle; a positive angle tilts upwards",
"r  changes the roll (twist) angle; a positive angle twists clockwise",
"",
"             c  changes zoom, hither and yon",
"             w  toggles wireframe mode on and off",
"             m  sets polar (longitude/latitude) mode",
"             ?  displays this help screen",
"            ESC exits",
"",
"          [Press any key to return to graphic display]",
NULL};


int lastr = 0;

do_key()
	{
	char buff[200];
	char c;
	if (currmode)
	 {
	  return do_key_polar();
	 }
	/* otherwise, do three-axis version */
	setcolor(1);
	sprintf(buff, "[%3.2f,%3.2f,%3.2f] pan = %d, tilt = %d, roll = %d",
		default_view.ex, default_view.ey, default_view.ez,
		(int) floor(default_view.pan), (int) floor(default_view.tilt),
		(int) floor(default_view.roll));
	outtextxy(0, 0, buff);
	sprintf(buff, "zoom = %3.2f, hither = %3.2f, yon = %3.2f; press ? for help",
		default_view.zoom, default_view.hither, default_view.yon);
	outtextxy(0, textheight(buff), buff);
	switch (getkey()) {
		case 0x1B: return 0;
		case 'w': wireframe = !wireframe; break;
		case 'c': change_stuff(); break;
		case 'm': currmode = !currmode;
		 if (currmode)
		   {
		    distance = sqrt(default_view.ex*default_view.ex +
				    default_view.ey*default_view.ey +
				    default_view.ez*default_view.ez );
		    polarx = 0 /* default_view.ex */ ;
		    polary = default_view.ey;
		    polarz = 0 /* default_view.ez */ ;
		    polar_compute();
		   }
		  break;

		case 'x': default_view.ex = prompt("Enter x-coordinate:",1); break;
		case 'y': default_view.ey = prompt("Enter y-coordinate:",1); break;
		case 'z': default_view.ez = prompt("Enter z-coordinate:",1); break;
		case 'p': default_view.pan = prompt("Enter pan value:",1); break;
		case 't': default_view.tilt = prompt("Enter tilt value:",1); break;
		case 'r': default_view.roll = prompt("Enter roll value:",1); break;
		case '?': default: show_help(helptext); break;
		}
	return 1;
	}

char *polarhelp[] = {
"                                 HELP",
"",
"    Your are currently in Polar Coordinate mode (longitude and latitude)",
"",
"     up arrow increases longitude     down arrow decreases longitude",
"     left arrow increases latitude    right arrow decreases latitude",
"     PgUp increases roll              PgDn decreases roll",
"                 d  sets distance from origin",
"",
"                 c  changes zoom, hither and yon",
"                 w  toggles wireframe mode on and off",
"                 m  sets three-axis (x, y, z) mode",
"                 ?  displays this help screen",
"                ESC exits",
"",
"             [Press any key to return to graphic display]",
NULL};


int rcount = 0;


do_key_polar()
	{
	char buff[100];
	int c;

	setcolor(1);
	if(rcount)
	 {
	  rcount--;
	  c = lastr;
	  goto dit;
	 }
/*	sprintf(buff, "long = %3.2f, lat = %3.2f, roll = %3.2f, dist = %3.2f",
		longitude, latitude, default_view.roll, distance);
/*	outtextxy(0, 0, buff);
	sprintf(buff, "zoom = %3.2f, hither = %3.2f, yon = %3.2f; press ? for help", default_view.zoom, default_view.hither, default_view.yon);
	outtextxy(0, textheight(buff), buff);
*/
	c = getkey();
	if(c!=0xFF && c != 'r') lastr = c;
dit:	switch (c) {
		case 0x1B: return 0;
		case 'w': wireframe = !wireframe; break;
		case 'c': change_stuff(); break;
		case 'm': currmode = !currmode; break;
		case 'd': distance = prompt("Enter distance value:",1); break;
		case LARROW:  if ((longitude -= 10) < -360) longitude += 360; break;
		case RARROW: if ((longitude += 10) > 360) longitude -=360; break;
		case UP:    if ((latitude += 10) > 360) latitude -= 360; break;
		case DOWN:  if ((latitude -= 10) < -360) latitude += 360; break;
		case PGUP:  if ((default_view.roll += 10) > 360) default_view.roll -= 360; break;
		case PGDN:  if ((default_view.roll -= 10) < -360) default_view.roll += 360; break;
		case '?': default: show_help(polarhelp); break;
		case 'r': rcount = 100; break;
		}
	polar_compute();
	return 1;
	}

static void *ecalloc(int n, int sz)
{
	void *p;
	if ((p = calloc(n, sz)) == NULL)
		{
		fprintf(stderr, "Can't calloc(%d,%d)\n", n, sz);
		exit(3);
		}
	return p;
}


int load_err = 0;  /* set if an error was encountered during loading */

OBJECT *load_object(FILE *in)
{
	OBJECT *obj;
	char tbuff[1000];
	char objname[100];
	int nv, np, i, need_bounds;

	do
		{
		if (fgets(tbuff, sizeof(tbuff), in) == NULL) return NULL;
		} while (tbuff[0] == '\n');

	switch (sscanf(tbuff, "%s %d %d %f,%f,%f,%f", objname, &nv, &np,
		&obj->sphx, &obj->sphy, &obj->sphz, &obj->sphr))
		{
		case 3: need_bounds = 1; break;
		case 7: need_bounds = 0; break;
		default: load_err = -2; return NULL;
		}

	if ((obj = ecalloc(1, sizeof(OBJECT))) == NULL)
		{
		load_err = -2;
		return NULL;
		}

	obj->verts = ecalloc(nv, sizeof(VERTEX));
	obj->polys = ecalloc(np, sizeof(POLY));
	obj->nverts = nv; obj->npolys = np;
	for (i = 0; i < nv; ++i)
		{  /* load in vertices */
		do
			{
			if (fgets(tbuff, sizeof(tbuff), in) == NULL)
				{
				load_err = -4;
				return NULL;
				}
			} while (tbuff[0] == '\n');
		if (sscanf(tbuff, "%f %f %f", &obj->verts[i].ox,
			&obj->verts[i].oy, &obj->verts[i].oz) != 3)
			{
			load_err = -5;
			return NULL;
			}

	obj->verts[i].x = (obj->verts[i].ox);
	obj->verts[i].y = (obj->verts[i].oy);
	obj->verts[i].z = (obj->verts[i].oz);
	}

	for (i = 0; i < np; ++i)
		{  /* load in polygons */
		int j;
		char *p;

		do
			{
			if (fgets(tbuff, sizeof(tbuff), in) == NULL)
				{
				load_err = -6;
				return NULL;
				}
			} while (tbuff[0] == '\n');
	if ((p = strtok(tbuff, " \t")) == NULL)
		{
		load_err = -7;
		return NULL;
		}
	sscanf(p, "%d", &obj->polys[i].color);
	obj->polys[i].color %= 16;  /* only 16 colors allowed right now */
	if ((p = strtok(NULL, " \t")) == NULL)
		{
		load_err = -8;
		return NULL;
		}
	obj->polys[i].npoints = atoi(p);
	obj->polys[i].points = ecalloc(obj->polys[i].npoints, sizeof(VERTEX *));
	for (j = 0; j < obj->polys[i].npoints; ++j)
		{
		if ((p = strtok(NULL, " \t")) == NULL)
			{
			load_err = -9;
			return NULL;
			}
		obj->polys[i].points[j] = &obj->verts[atoi(p)];
		}
	if ((p = strtok(NULL, " \t")) != NULL)  /* if normal was specfied */
		sscanf(p, "%f,%f,%f", &obj->polys[i].normalx,
			&obj->polys[i].normaly, &obj->polys[i].normalz);
	else
		compute_normal(&obj->polys[i]);
   }

	if (need_bounds) find_bounding_sphere(obj);
	load_err = 0;
	return obj;
}
