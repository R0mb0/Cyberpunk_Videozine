/* Read a World Description File */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <alloc.h>
#include <dos.h>       /* delay() */
#include "3dstruct.h"
#include "config.h"
#include "rend386.h"
#include "tasks.h"
#include "plg.h"
#include "intmath.h"
#include "splits.h"
#include "pointer.h"
#include "cursor.h"
#include "segasupp.h"
#include "segio.h"
#ifdef ENCRYPT
#include "encrypt.h"
#endif

extern FILE *log_file;

extern SPLIT *split_tree;

extern int sl_xflip, sl_xoff, do_horizon ;
extern long sl_left, sl_top, sl_right, sl_bottom;
extern int sr_xflip, sr_xoff;
extern long sr_left, sr_top, sr_right, sr_bottom;
extern float sl_xrot, sr_xrot;

extern int running;

int old_angle_order = 0;  /* if non-zero, camera angles are pan,tilt,roll */

extern unsigned screen_clear_color,sky_color,ground_color;
extern int use_frame, redraw, review, reframe, do_screen_clear;
extern int frame_x, frame_y, frame_w, frame_h;
extern int flymode, floormode;
extern char framefname[];
extern STEREO default_stereo;
extern VIEW default_view;
extern unsigned char palette[];
extern int npalette;
extern OBJLIST *objlist;
extern TASK *tasklist;
extern VIEW *current_view;
extern SEGMENT *preconnect_view_seg;

extern char *fix_fname(char *fname);

long frame_number = 1; /* current frame number */

static int save_frames = 0; /* if non-zero, save a pcx file on "frame" */
static int key_wait = 0; /* if non-zero, wait for a keypress per frame */
static int frame_delay = 0; /* how long to delay on encountering "frame" */
static char pcx_pattern[100] = "f%d.pcx";

void *temp_mem = NULL; /* points to area to be used for temp storage */
long temp_size = 0;
unsigned int SKYGRAD, GROUNDGRAD, HORSTEP = 180L;

static int keep_around = 1; /* if non-zero, don't use temp for names */

OBJECT *where_split_screen_pt(int *pol, int *vert, int x, int y)
{
	extern OBJECT *render_check_monitor(int *pol, int *vert);

	render_monitor_point(x, y);
	refresh_display();
	return render_check_monitor(pol, vert);
}

/**************** NAMED LIST SUPPORT **************/

typedef struct _name NAMEREF;

struct _name {
	char *name;
	void *value;
	NAMEREF *next;
};

NAMEREF *add_name(NAMEREF **list, char *name, void *value)
{
	NAMEREF *p;
	/* check if temp usable */
	if (!keep_around && (temp_mem) &&
		(temp_size>(sizeof(NAMEREF)+strlen(name)+1)))
	{
		p = temp_mem;
		temp_mem = ((char *)temp_mem) + sizeof(NAMEREF);
		p->name = temp_mem;
		temp_mem = ((char *)temp_mem) + strlen(name) + 1;
		strcpy(p->name, name);
		temp_size -= sizeof(NAMEREF)+strlen(name)+1;
	}
	else /* use heap */
	{
		temp_mem = NULL;
		if ((p = malloc(sizeof(NAMEREF))) == NULL) return NULL;
		p->name = strdup(name);
	}
	p->value = value;
	p->next = *list;
	*list = p;
	return *list;
}

void del_namelist(NAMEREF *list)
{
	if (keep_around) return;
	if (temp_mem) return;
	while (list)
	{
		if (list->name) free(list->name);
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

unsigned int find_color(NAMEREF *list, char *name)
{

	if (isdigit(name[0])) /* handle dec/hex color */
		return strtoul(name, NULL, 0);
	if (name[0] == '&') return convert_color(&name[1], NULL);
	return (unsigned)find_name(list, name);
}



/****************** TASK AND CONTROL SUPPORT *************/

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
}
SPINDATA;


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
		if (key == p->key)
		{
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


extern void spinner(), sculspin();

struct {
	char *name;
	void (*fn)();
}
functions[] = {
	{ 
		"spinner", spinner 	}
	,
	{ 
		"sculspin", sculspin 	}
	,
	{ 
		"clickfn", clickfn 	}
	,
	{ 
		NULL, NULL 	}
};



/******************** POLYGON, PLANE NORMAL SUPPORT ***********/

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


/************* WORLD AND CONFIG FILE LOADING **********/

NAMEREF *areas = NULL;
NAMEREF *maps = NULL;
NAMEREF *surfdefs = NULL;
NAMEREF *objectlist = NULL;
NAMEREF *fixedolist = NULL;
NAMEREF *figurelist = NULL;

#ifdef ENABLE_STATEMACH
extern NAMEREF *statelist;
extern NAMEREF *varlist;
#endif

void dump_lists(void)
{
	if(temp_mem) return; /* no need to delete if using temp. RAM */

	del_namelist(areas);
	del_namelist(maps);
	del_namelist(surfdefs);
	del_namelist(objectlist);
	del_namelist(fixedolist);
	del_namelist(figurelist);
#ifdef ENABLE_STATEMACH
	del_namelist(statelist);
	del_namelist(varlist);
#endif
}


typedef struct _surface SURFACE;

struct _surface {
	unsigned color;
	char *value;
	SURFACE *next;
};

extern char loadpath[];

match(char *a, char *b)
{
	return !strnicmp(a, b, strlen(b));
}

SEGMENT *find_seg(char *name)
{
	char *p = NULL;
	OBJECT *o;
	SEGMENT *s;

	if (name[0]==0) return NULL;
	if ((p = strchr(name, '.')) == NULL)
	{
		if ((o = find_name(objectlist, name)) == NULL) goto try_seg;
		p = get_object_owner(o);
		return p;
	}
	else
		{
		*p++ = '\0';
try_seg:
		if ((s = find_name(figurelist, name)) == NULL) return NULL; /* no such figure */
		if (p==NULL) return s; /* root of figure */
		return find_segment_by_name(s, p);
	}
}


void walk_segtree(SEGMENT *s, void (*f)());
#ifdef FIGURE_MAPS
static SURFACE *map_list = NULL;

void remap_fig(SEGMENT *s)
{
	int np;
	SURFACE *p;
	unsigned color;
	void *v;
	OBJECT *obj = seg_get_object(s);

	if(!obj) return;
	get_obj_info(obj, NULL, &np);
	while (np--)
	{
		get_poly_info(obj, np, &color, NULL, NULL, 0);
		for (p = map_list; p; p = p->next)
			if (p->color == color)
			{
				if ((v = find_name(surfdefs, p->value)) != NULL)
					set_poly_color(obj, np, (unsigned) v);
				break;
			}
	}
}
#endif


void clean_equals(char *b)
{
	char *c=b, *d=b;

	if(!strchr(b,'=')) return;

	while(*b) /* scan string: */
	{
		if(*b==' ' || *b=='\t') /* if whitespace: */
		{
			d = b; /* record start */
			while (*b==' ' || *b=='\t') *c++ = *b++; /* copy till end of ws */
			if(*b=='=')
			{
				c = d; /* roll back position */
				*c++ = *b++; /* copy = */
				while (*b==' ' || *b=='\t') b++; /* skip trailing ws */
			}
		}
		else *c++ = *b++;
	}
	*c = 0;
}


void tokstr(char *c)
{
	char *s = strtok(NULL, " \t,\n#");
	if(s) sscanf(s, "%s",c);
}

void tokstrn(char *c)
{
	char *s = strtok(NULL, " \t,\n#");
	if(s) sscanf(s, "%s",c);
	else *c = 0;
}

void tokint(int *i)
{
	char *s = strtok(NULL, " \t,\n#");
	if(s) sscanf(s, "%d",i);
}

void tokhex(unsigned *i)
{
	char *s = strtok(NULL, " \t,\n#");
	if(s) *i = (unsigned int)strtoul(s, NULL, 0);
}

void toklong(long *i)
{
	char *s = strtok(NULL, " \t,\n#");
	if(s) sscanf(s, "%ld",i);
}

void tokfloat(float *i)
{
	char *s = strtok(NULL, " \t,\n#");
	if(s) sscanf(s, "%f",i);
}

void tokl16(long *i)
{
	float f;
	char *s = strtok(NULL, " \t,\n#");
	if(s)
	{
		sscanf(s, "%f", &f);
		*i = 65536L * f;
	}
}

char *toks(void)
{
	char *s = strtok(NULL, " \t,\n#");
	if (s) return "";
	else return s;
}

static int title_index = 0;
char *title[25] = { 
	NULL };


static char *commands[] = {
	"loadpath", "palette", "skycolor", "groundcolor", "screencolor",
	"screenclear", "ambient", "worldscale", "flymode", "light",
	"window", "key", "control", "viewframe", "start", "floormode",
	"hither", "yon", "eyespacing", "screendist", "attachview",
	"screenwidth", "convergence", "figure", "object", "stepsize",
	"task", "position", "rotate", "camera", "options",
	"include", "surfacemap", "surface", "surfacedef",
	"split", "splitpt", "area", "floor", "floorpts",
	"ceiling", "ceilingpts", "visfrom",
	"endsplits", "polyobj", "polyobj2", "videodev",
	"mousedev", "headdev", "glovedev", "ptrdev",
	"switchdev", "glovecursor", "ptrcursor", "segaport", "switchport",
	"pgloveport", "pglovetime", "stereoset", "stereotype",
	"stereoleft", "stereoright", "depthtype", "attach", "detach",
	"usemap", "fixedobj","collide",
#ifdef ENABLE_STATEMACH
	"animation", "state", "if", "do",
#endif
	"title", "mlight", "segment", "addrep",
	"anglestep",
#ifdef ENABLE_ANIMATION
	"pause", "frame", "savepcx",
#endif
	"version", "horizon", "skygrad", "groundgrad", "gradsize",
	NULL
};

enum com_codes {
	c_loadpath = 0, c_palette, c_skycolor, c_groundcolor, c_screencolor,
	c_screenclear, c_ambient, c_worldscale, c_flymode, c_light,
	c_window, c_key, c_control, c_viewframe, c_start, c_floormode,
	c_hither, c_yon, c_eyespacing, c_screendist, c_attachview,
	c_screenwidth, c_convergence, c_figure, c_object, c_stepsize,
	c_task, c_position, c_rotate, c_camera, c_options,
	c_include, c_surfacemap, c_surface, c_surfacedef,
	c_split, c_splitpt, c_area, c_floor, c_floorpts,
	c_ceiling, c_ceilingpts, c_visfrom,
	c_endsplits, c_polyobj, c_polyobj2, c_videodev,
	c_mousedev, c_headdev, c_glovedev, c_ptrdev,
	c_switchdev, c_glovecursor, c_ptrcursor, c_segaport, c_switchport,
	c_pgloveport, c_pglovetime, c_stereoset, c_stereotype,
	c_stereoleft, c_stereoright, c_depthtype, c_attach, c_detach,
	c_usemap, c_fixedobj, c_collide,
#ifdef ENABLE_STATEMACH
	c_animation, c_state, c_if, c_do,
#endif
	c_title, c_mlight, c_segment, c_addrep,
	c_anglestep,
#ifdef ENABLE_ANIMATION
	c_pause, c_frame, c_savepcx,
#endif
	c_version, c_horizon, c_skyg, c_groundg, c_gradsize,
};


static SURFACE *current_surface = NULL, *map;
static SPLIT *current_split = NULL;

static char ps[] = " \t\n,#";
static char st[] = "%s";

extern long spacestep, anglestep;

static int stop_it = 0; /* set non-zero if user hits a key during pause */

static int have_start = 0; /* non-zero if we've seen a "start" line */

static char default_map[100] = "";

read_world(FILE *in)
{
	char obuff[256];
	char inbuff[256], *buff, fname[100];
	char surfacemapname[100];
	char *args;
	char *pname;
	int i,cmd;
	while (fgets(inbuff, sizeof(inbuff), in))
	{
#ifdef ENCRYPT
		if (buff[0] == 26) decrypt_buffer(inbuff);
#endif
		if (stop_it) {
			stop_it = 0;
			break;
		}
		strcpy(obuff,inbuff);
		buff = strtok(inbuff,"#");
		for (buff = inbuff; isspace(*buff); ++buff);
		if(buff[0]==0) continue;
		clean_equals(buff);
		for (args = buff+1; isalpha(*args); ++args);
		args++;
		buff = strtok(buff," \t\n");

		for (cmd = 0; commands[cmd]; cmd++)
			if (!stricmp(commands[cmd], buff)) break;
		if (commands[cmd] == NULL) continue;

		switch(cmd)
		{
		case c_depthtype:
			{
			OBJECT *obj;
			SEGMENT *s;
			char oname[100];
			unsigned dtype;
			strcpy(oname, strtok(NULL,ps));
			dtype = atoi(strtok(NULL, ps));
			if ((s = find_seg(oname)) != NULL) { 
				obj = seg_get_object(s);
				if (obj)
					set_object_sorting(obj, dtype);					
				}
			}
			break;
		case c_attach:
			{
			SEGMENT *s, *par;
			long tx, ty, tz, rx, ry, rz;
			if ((s = find_seg(strtok(NULL,ps))) == NULL) break;
			if ((par = find_seg(strtok(NULL,ps))) == NULL) break;
			seg_getposang(s, &rx, &ry, &rz);
			seg_getposxyz(s, &tx, &ty, &tz);
			attach_segment(s, par);					
			abs_rot_segment(s, rx, ry, rz, RYXZ);
			abs_move_segment(s, tx, ty, tz);
			update_segment(s);
			}
			break;
		case c_detach:
			{
			SEGMENT *s;
			if ((s = find_seg(strtok(NULL, ps))) == NULL) break;
			detach_segment(s);
			update_segment(s);
			}
			break;
		case c_usemap:
			tokstrn(default_map);
			break;
		case c_version:
			{
			int ver = 4;
			tokint(&ver);
			if (ver > 5) {
				char tbuff[100];
				sprintf(tbuff, "Warning!  File is new version %d!", ver);
				if (running){
					popmsg(tbuff);
					tdelay(600);
					redraw=1;
					refresh_display();
				}
				else
					fprintf(stderr, "%s\n", tbuff);
				if (log_file)
					fprintf(log_file, "%s\n", tbuff);
				}
			}
			break;

			case c_horizon:
					 do_horizon = atoi ( strtok ( NULL, ps)) ;
			break ;
			case c_skyg:
					tokhex ( &SKYGRAD) ;
			break ;
			case c_groundg:
					tokhex ( &GROUNDGRAD) ;
			break ;
			case c_gradsize:
					HORSTEP = atoi ( strtok ( NULL, ps)) ;
			    /*		switch ( i)
					{
						case 1: HORSTEP = 50l ;
						break ;
						case 2: HORSTEP = 70l ;
						break ;
						case 3: HORSTEP = 80l ;
						break ;
						case 4: HORSTEP = 100l ;
						break ;
						case 5: HORSTEP = 120l ;
						break ;
						case 6: HORSTEP = 150l ;
						break ;
						case 7: HORSTEP = 190l ;
						break ;
						case 8: HORSTEP = 230l ;
						break ;
						case 9: HORSTEP = 300l ;
						break;
						default: HORSTEP = i;
						break ;
					}  */
			break ;
#ifdef ENABLE_ANIMATION
		case c_frame:
			{
				long f = 0L;
				if (!running) break; /* only valid while we're running */
				toklong(&f);
				if (f) frame_number = f;
				else ++frame_number;
				if (bioskey(1)) {
					unsigned key = getkey();
					if (toupper(key) == 'Q' || key == 0x1B) {
					      //	popmsg("ANIMATION","STOP ANIMATION?","-2",0);
						if (toupper(getkey()) == 'Y') {
							stop_it = 1;
							break;
						}
					}
					else
						do_key(key);
				}
				redraw=1;
				refresh_display();
				if (key_wait) bioskey(0);
				if (frame_delay) delay(frame_delay);
				if (save_frames) {
					extern int v_page;
					char buff[100];
					FILE *out;
					sprintf(buff, pcx_pattern, frame_number);
					if ((out = fopen(buff, "wb")) == NULL)
						break;
					cursor_hide();
					save_pcx(out, v_page);
					cursor_show(v_page);
					fclose(out);
				}
			}
			break;
		case c_pause:
			{
				int nticks;
				char *message;
				if (!running) break; /* only valid while we're running */
				tokint(&nticks);
				message = strtok(NULL, "");
				refresh_display();
				if (message){
					popmsg("ANIMATION");
					tdelay(600);
				}
				if (nticks)
					delay(nticks);
				else
					getkey();
				redraw = review = 1;
			}
			break;
		case c_savepcx:
			{
				extern int v_page;
				char buff[100], pattern[100];
				FILE *out;
				if (!running) break;
				tokstr(pattern);
				sprintf(buff, pattern, frame_number);
				if ((out = fopen(buff, "wb")) == NULL)
					break;
				else {
					char tbuff[100];
					sprintf(tbuff, "Could not open '%s'", buff);
					if (running){
						popmsg(tbuff);
						tdelay(600);
						redraw=1;
						refresh_display();
					}
					else
						fprintf(stderr, "%s\n", tbuff);
					if (log_file)
						fprintf(log_file, "%s\n", tbuff);
				}
				cursor_hide();
				save_pcx(out, v_page);
				cursor_show(v_page);
				fclose(out);
			}
			break;
#endif
		case c_stepsize:
			toklong(&spacestep);
			break;
		case c_anglestep:
			{
			float a;
			tokfloat(&a);
			anglestep = a * 65536L;
			}
			break;
		case c_loadpath:
			tokstr(loadpath);
			break;

		case c_options:
			{
				char oss[100] = "";
				char *os = &oss[0];
				int i;
				extern int fancy_background, reflection_pool, show_logo, do_screen_clear;
				extern int show_location, show_compass, show_framerate;
				extern int use_BW, spinmode;
				tokstr(os);
				i = isupper(*os);
				while(*os)
				{
					switch(toupper(*os))
					{
					case 'C':
						show_compass = i;
						break;
					case 'F':
						show_framerate = i;
						break;
					case 'P':
						show_location = i;
						break;
					case 'B':
						fancy_background = i;
						break;
					case 'R':
						reflection_pool = i;
						break;
					case 'M':
						use_BW = i;
						break;
					case 'H':
						do_horizon = i;
						break;
					case 'A':
						old_angle_order = i;
						break;
					case 'S':
						spinmode = i;
						break;
					}
					os = os+1;
				}
			}
			break;

	/*	case c_palette:
			{
				FILE *in;
				char *f;
				tokstr(fname);
				if ((in = fopen(f = fix_fname(fname), "rb")) != NULL)
				{
					npalette = fread(palette, 3, 256, in);
					fclose(in);
				}
				else {
					char buff[100];
					sprintf(buff, "Could not open '%s'", f);
					if (running)
						popmsg(buff);
					else
						fprintf(stderr, "%s\n", buff);
					if (log_file)
						fprintf(log_file, "%s\n", buff);
				}
			}
			break;  */

		case c_skycolor:
			tokhex(&sky_color);
			break;
		case c_groundcolor:
			tokhex(&ground_color);
			break;
		case c_screencolor:
			tokhex(&screen_clear_color);
			break;
		case c_screenclear:
			tokint(&do_screen_clear);
			break;
		case c_flymode:
			tokint(&flymode);
			break;
		case c_floormode:
			tokint(&floormode);
			break;
		case c_ambient:
			tokint(&(current_view->ambient));
			break;
		case c_worldscale:
			default_stereo.world_scaling = 65536.0 * atof(strtok(NULL,ps));
			break;
		case c_light:
			{
			char *p;
			default_view.lx = atol(strtok(NULL,ps));
			default_view.ly = atol(strtok(NULL,ps));
			default_view.lz = atol(strtok(NULL,ps));
			p = strtok(NULL, ps);
			if (isdigit(*p)) default_view.directional = atoi(p);
			else default_view.directional = !stricmp(p, "spot");
			}
			break;
		case c_mlight:
			{
				extern int light2_i, light2_s;
				extern long light2_x, light2_y,light2_z;
				extern SEGMENT *light_seg, *light_seg2;
				char parent[100];
				char *m;
				SEGMENT *p_seg;
				long rx=0, ry=0, rz=0;
				if(light_seg) break; /* don't redo it */
				light2_x = atol(strtok(NULL,ps)); /* get position of pivot */
				light2_y = atol(strtok(NULL,ps));
				light2_z = atol(strtok(NULL,ps));
				m = strtok(NULL, ps);
				if (isdigit(*m)) default_view.directional = atoi(m);
				else default_view.directional = !stricmp(m, "spot");
				sscanf(strtok(NULL,ps), "%d", &light2_i); /* intensity*128 */
				tokstrn(parent);
				if(parent[0]==0 || !stricmp(parent, "fixed")) break; /* mobile pivot? */
				light_seg = new_seg(NULL);
				if ((m=strchr(parent, '='))!=NULL)
				{
					*m++ = 0;
					add_name(&figurelist, parent, light_seg); /* record name */
				}
				else m = parent;

				p_seg = find_seg(m);
				if(p_seg)
				{
					attach_segment(light_seg, p_seg );
					abs_rot_segment(light_seg, rx, ry, rz, RYXZ);
					abs_move_segment(light_seg, light2_x, light2_y, light2_z);
					full_update_segment(p_seg);
				}
				else
				{
					abs_rot_segment(light_seg, rx, ry, rz, RYXZ);
					abs_move_segment(light_seg, light2_x, light2_y, light2_z);
					full_update_segment(light_seg);
				}
				break;
			}
#ifdef OLD
		case c_light:
			default_view.lx = atol(strtok(NULL,ps));
			default_view.ly = atol(strtok(NULL,ps));
			default_view.lz = atol(strtok(NULL,ps));
			sscanf(strtok(NULL,ps), "%d", &(default_view.directional) );
			break;
		case c_mlight:
			{
				extern int light2_i, light2_s;
				extern long light2_x, light2_y,light2_z;
				extern SEGMENT *light_seg, *light_seg2;
				char parent[100];
				char *m;
				SEGMENT *p_seg;
				long rx=0, ry=0, rz=0;

				if(light_seg) break; /* don't redo it */
				light2_x = atol(strtok(NULL,ps)); /* get position of pivot */
				light2_y = atol(strtok(NULL,ps));
				light2_z = atol(strtok(NULL,ps));
				sscanf(strtok(NULL,ps), "%d", &light2_s); /* spotlight flag */
				sscanf(strtok(NULL,ps), "%d", &light2_i); /* intensity*128 */
				tokstrn(parent);
				if(parent[0]==0 || !stricmp(parent, "fixed")) break; /* mobile pivot? */
				light_seg = new_seg(NULL);
				if ((m=strchr(parent, '='))!=NULL)
				{
					*m++ = 0;
					add_name(&figurelist, parent, light_seg); /* record name */
				}
				else m = parent;

				p_seg = find_seg(m);
				if(p_seg)
				{
					attach_segment(light_seg, p_seg );
					abs_rot_segment(light_seg, rx, ry, rz, RYXZ);
					abs_move_segment(light_seg, light2_x, light2_y, light2_z);
					full_update_segment(p_seg);
				}
				else
				{
					abs_rot_segment(light_seg, rx, ry, rz, RYXZ);
					abs_move_segment(light_seg, light2_x, light2_y, light2_z);
					full_update_segment(light_seg);
				}
				break;
			}
#endif
		case c_window:
			{
				int x, y, w, h;

				switch (sscanf(strtok(NULL,""), "%d,%d,%d,%d", &x, &y, &w, &h))
				{
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
			break;

		case c_key:
			{
				char fname[100];
				unsigned key, param;
				int i;
				key = strtoul(strtok(NULL,ps), NULL, 0);
				sscanf(strtok(NULL,ps), st, fname);
				param = atoi(strtok(NULL,ps));
				for (i = 0; functions[i].name; ++i)
					if (!stricmp(fname, functions[i].name))
					{
						KEY *k;
						if ((k = malloc(sizeof(KEY))) != NULL)
						{
							k->key = key;
							k->param = param;
							k->fn = functions[i].fn;
							k->next = keylist;
							keylist = k;
						}
						break;
					}
			}
			break;

		case c_control:
			{
				char fname[100];
				int x, y, w, h;
				unsigned mask, param;
				int i;

				x = atoi(strtok(NULL,ps));
				y = atoi(strtok(NULL,ps));
				w = atoi(strtok(NULL,ps));
				h = atoi(strtok(NULL,ps));
				mask = (unsigned)atol(strtok(NULL,ps));
				sscanf(strtok(NULL,ps), st, fname);
				param = (unsigned)atol(strtok(NULL,ps));

				for (i = 0; functions[i].name; ++i)
					if (!stricmp(fname, functions[i].name))
					{
						CONTROL *c;
						if ((c = malloc(sizeof(CONTROL))) != NULL)
						{
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
			break;

		case c_viewframe:
			{
				FILE *in;
				sscanf(strtok(NULL,ps), st, framefname);
				frame_x = atoi(strtok(NULL,ps));
				frame_y = atoi(strtok(NULL,ps));
				frame_w = atoi(strtok(NULL,ps));
				frame_h = atoi(strtok(NULL,ps));
				use_frame = 1;
			}
			break;

		case c_segment:
			{
				SEGMENT *this_seg, *p_seg;
				char parentname[60], *oname, *p;
				long tx = 0, ty = 0, tz = 0, rx = 0, ry = 0, rz = 0;
				;

				oname = NULL;
				tokstrn(parentname);
				tokl16(&rx);
				tokl16(&ry);
				tokl16(&rz);
				toklong(&tx);
				toklong(&ty);
				toklong(&tz);

				if ((p = strchr(parentname, '=')) != NULL)
				{
					oname = parentname;
					*p++ = '\0';
				}
				else
					p = parentname;
				p_seg = find_seg(p);
				if ((this_seg = new_seg(p_seg)) != NULL)
				{
					abs_move_segment(this_seg, tx, ty, tz);
					abs_rot_segment(this_seg, rx, ry, rz, RYXZ);
					full_update_segment(this_seg);
					if (oname) add_name(&figurelist, oname, this_seg);
				}
			}
			break;

		case c_start:
			have_start = 1;
			toklong(&default_view.ex);
			toklong(&default_view.ey);
			toklong(&default_view.ez);
			tokl16(&default_view.pan);
			tokl16(&default_view.tilt);
			tokl16(&default_view.roll);
			tokl16(&default_view.zoom);
			if(default_view.zoom<0.5*65536L) default_view.zoom = 0.5*65536L;
			break;

		case c_hither:
			default_view.hither = atol(strtok(NULL,ps));
			break;
		case c_yon:
			default_view.yon = atol(strtok(NULL,ps));
			break;
		case c_eyespacing:
			default_stereo.phys_eye_spacing = atol(strtok(NULL,ps));
			break;
		case c_screendist:
			default_stereo.phys_screen_dist = atol(strtok(NULL,ps));
			break;
		case c_screenwidth:
			default_stereo.phys_screen_width = atol(strtok(NULL,ps));
			default_stereo.pixel_width = atoi(strtok(NULL,ps));
			break;
		case c_convergence:
			default_stereo.phys_convergence = atol(strtok(NULL,ps));
			break;
		case c_attachview:
			{
				SEGMENT *p_seg;
				char parentname[60];
				tokstrn(parentname);
				preconnect_view_seg = find_seg(parentname);
			}
			break;

		case c_figure:
			{
				char filename[60], parentname[60], *oname, *p;
#ifdef FIGURE_MAPS
				char mappings[60];
#endif
				float sx = 1, sy = 1, sz = 1, rx = 0, ry = 0, rz = 0;
				long tx = 0, ty = 0, tz = 0;
				FILE *fig;
				parentname[0] = '\0';
#ifdef FIGURE_MAPS
				mappings[0] = '\0';
#endif
				oname = NULL;

				sscanf(strtok(NULL,ps), st, filename);
				tokfloat(&sx);
				tokfloat(&sy);
				tokfloat(&sz);
				tokfloat(&rx);
				tokfloat(&ry);
				tokfloat(&rz);
				toklong(&tx);
				toklong(&ty);
				toklong(&tz);
				tokstrn(parentname);
#ifdef FIGURE_MAPS
				tokstrn(mappings);

				map_list = find_name(maps, mappings);
#endif
				add_ext(filename, "fig");
				set_readseg_scale(sx, sy, sz);
				if ((p = strchr(filename, '=')) != NULL)
				{
					oname = filename;
					*p++ = '\0';
				}
				else
					p = filename;
				if ((fig = fopen(pname = fix_fname(p), "r")) != NULL)
				{
					SEGMENT *this_seg, *p_seg;
					p_seg = find_seg(parentname);
					set_readseg_objlist(objlist);
					readseg_err = 0;
					if ((this_seg = readseg(fig, p_seg)) != NULL)
					{
						abs_move_segment(this_seg, tx, ty, tz);
						abs_rot_segment(this_seg, rx*65536L, ry*65536L, rz*65536L, RYXZ);
						update_segment(this_seg);
					}
					fclose(fig);
					if (readseg_err) {
						if (running){
						     popmsg("ERROR READING FIG");
						     tdelay(600);
						}
						else
							fprintf(stderr, "%s in figure file '%s'\n", readseg_errmsgs[-readseg_err], pname);
						if (log_file)
							fprintf(log_file, "%s in figure file '%s'\n", readseg_errmsgs[-readseg_err], pname);
					}
#ifdef FIGURE_MAPS
					if(map_list) walk_segtree(this_seg, remap_fig);
#endif
					if (oname) add_name(&figurelist, oname, this_seg);
				}
				else {
					char buff[100];
					sprintf(buff, "Could not open '%s'", pname);
					if (running){
						popmsg(buff);
						tdelay(600);
					}
					else
						fprintf(stderr, "%s\n", buff);
					if (log_file)
						fprintf(log_file, "%s\n", buff);
				}
			}
			break;

		case c_fixedobj:
		case c_object:
			{
				char mappings[100], *p, filename[100], *oname, parentname[100], name[10], temp_filename[15];
				float sx = 1, sy = 1, sz = 1, rx = 0, ry = 0, rz = 0;
				long tx = 0, ty = 0, tz = 0;
				int dt = 0, cc = 0;
				MATRIX m;
				FILE *plg;
				OBJECT *obj;

				sscanf(strtok(NULL,ps), st, filename);
				tokfloat(&sx);
				tokfloat(&sy);
				tokfloat(&sz);
				tokfloat(&rx);
				tokfloat(&ry);
				tokfloat(&rz);
				toklong(&tx);
				toklong(&ty);
				toklong(&tz);
				tokint(&dt);
				tokstrn(mappings);
				tokstrn(parentname);
				tokint(&cc);
				tokstrn(name);
				if (cmd == c_fixedobj)
					strcpy(parentname, "fixed");
				strcpy(temp_filename,filename);
				add_ext(filename, "plg");
				set_loadplg_scale(sx, sy, sz);
				set_loadplg_depthsort(dt);


				map = find_name(maps, mappings);
				if (!map)
					map = find_name(maps, default_map);

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
				if ((plg = fopen(pname = fix_fname(p), "r")) != NULL)
				{
					while ((obj = load_multi_plg(plg)) != NULL)
						if (obj)
						{
						      strcpy(obj->obj_filename,p);
						      strcpy(obj->obj_name,name);
						      obj->sclx=sx;
						      obj->scly=sy;
						      obj->sclz=sz;
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

							if (oname)

								if (stricmp(parentname, "fixed")) add_name(&objectlist, oname, obj);
								else add_name(&fixedolist, oname, obj);
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

								p = find_seg(parentname);
								s = new_seg(p);
								seg_set_object(s, obj);
								set_object_owner(obj, s);
//								strcpy(obj->obj_filename,p);             //test
//								strcpy(obj->obj_name,name);
//								obj->sclx=sx;
//								obj->scly=sy;
//								obj->sclz=sz;
								if (cc==1)
								  obj->oflags=OBJ_COLLIDE;
								abs_rot_segment(s, rx * 65536L, ry * 65536L, rz * 65536L, RYXZ);
								abs_move_segment(s, tx, ty, tz);
								update_segment(s);
							}

						}
					if (load_err) {
						if (running){
							popmsg("ERROR IN .PLG");
							tdelay(600);
							redraw = reframe = 1;
							refresh_display();
						}
						else
							fprintf(stderr, "%s on line %d of file %s\n", plg_errmsgs[-load_err], err_line, pname);
						if (log_file)
							fprintf(log_file, "%s on line %d of file %s\n", plg_errmsgs[-load_err], err_line, pname);
					}
				}
				else {
					char buff[100];
					sprintf(buff, "Could not open '%s'", pname);
					if (running){
						popmsg("ERROR LOADING PLG IN .WLD");
						tdelay(800);
						redraw=reframe=1;
						refresh_display();
					}
					else
						fprintf(stderr, "%s\n", buff);
					if (log_file)
						fprintf(log_file, "%s\n", buff);
				}
				fclose(plg);

			}
			break;

		case c_addrep:
			{
				char mappings[100], *p, filename[100], *oname;
				float sx = 1, sy = 1, sz = 1, rx = 0, ry = 0, rz = 0;
				long tx = 0, ty = 0, tz = 0;
				int defsize = 0;
				MATRIX m;
				FILE *plg;
				OBJECT *obj, sobj;
				SEGMENT *s;

				sscanf(strtok(NULL,ps), st, filename);
				tokfloat(&sx);
				tokfloat(&sy);
				tokfloat(&sz);
				tokfloat(&rx);
				tokfloat(&ry);
				tokfloat(&rz);
				toklong(&tx);
				toklong(&ty);
				toklong(&tz);
				tokint(&defsize);
				tokstrn(mappings);

				add_ext(filename, "plg");
				set_loadplg_scale(sx, sy, sz);
				map = find_name(maps, mappings);

				if ((p = strchr(filename, '=')) == NULL) break;
				oname = filename;
				*p++ = '\0';
				if((s = find_seg(oname))!=NULL)
				{
					if(!(obj = seg_get_object(s))) break;
				}
				else
					{
					if(!(obj = find_name(fixedolist, oname))) break;
				}

				std_matrix(m, (long) (rx * 65536L), (long) (ry * 65536L),
				(long) (rz * 65536L), tx, ty, tz);
				if ((plg = fopen(pname = fix_fname(p), "r")) != NULL)
				{
					while ((obj = load_extra_rep(plg, obj, defsize)) != NULL)
						if (obj)
						{
							apply_matrix(obj, m);
							copy_world_to_object(obj);
							compute_obj(obj);
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
						}
					if (load_err && log_file)
						fprintf(log_file, "%s on line %d of file %s\n", plg_errmsgs[-load_err], err_line, pname);
				}
				else {
					char buff[100];
					sprintf(buff, "Could not open '%s'", pname);
					if (running)
						popmsg(buff);
					else
						fprintf(stderr, "%s\n", buff);
					if (log_file)
						fprintf(log_file, "%s\n", buff);
				}
				fclose(plg);
				full_update_segment(s); /* update world sphere coords */
			}
			break;

		case c_task:
			{
				char taskname[100], param[100];
				long period;
				int i;
				void *data;

				sscanf(strtok(NULL,ps), st, taskname);
				period = atol(strtok(NULL,ps));
				strcpy(param, strtok(NULL,"\n"));
				for (i = 0; functions[i].name; ++i)
					if (!stricmp(taskname, functions[i].name)) {
						add_task(&tasklist, functions[i].fn, period, param);
						break;
					}
			}
			break;

		case c_position:
			{
				OBJECT *obj;
				SEGMENT *s;
				char oname[100];
				long x, y, z;

				strcpy(oname, strtok(NULL,ps));
				x = atol(strtok(NULL,ps));
				y = atol(strtok(NULL,ps));
				z = atol(strtok(NULL,ps));
				if ((s = find_seg(oname)) != NULL) {
					obj = seg_get_object(s);
					abs_move_segment(s, x, y, z);
					update_segment(s);
					if (obj) {
						remove_from_objlist(obj);
						add_obj_to_split_area(split_tree, obj);
					}
				}
			}
			break;

		case c_rotate:
			{
				OBJECT *obj;
				SEGMENT *s;
				char oname[100];
				float rx, ry, rz;

				strcpy(oname,strtok(NULL,ps));
				rx = atof(strtok(NULL,ps));
				ry = atof(strtok(NULL,ps));
				rz = atof(strtok(NULL,ps));
				if ((s = find_seg(oname)) != NULL)
				{
					abs_rot_segment(s, rx * 65536L, ry * 65536L, rz * 65536L, RYXZ);
					update_segment(s);
				}
			}
			break;

		case c_camera:
			{
				int n;
				char *c;
				extern VIEW *all_views[], *save_views[];
				VIEW *v, *bv;

				tokint(&n);
				if (n < 1 || n > 10) break;
				if (all_views[n-1] == NULL)
					all_views[n-1] = (VIEW *) malloc(sizeof(VIEW));
				v = all_views[n-1];
				*v = default_view;
				toklong(&(v->ex));
				toklong(&(v->ey));
				toklong(&(v->ez));
				if (old_angle_order) {
					tokl16(&(v->pan));
					tokl16(&(v->tilt));
					}
				else {
					tokl16(&(v->tilt));
					tokl16(&(v->pan));
					}
				tokl16(&(v->roll));
				tokl16(&(v->zoom));
				toklong(&(v->hither));
				toklong(&(v->yon));
				bv = save_views[n-1] = (VIEW *) malloc(sizeof(VIEW));
				*bv = *v;
				save_views[n-1] = bv; /* save "home" copy */
				if (!have_start && n == 1) { /* if no start line yet, camera 1 is start */
					default_view = *v;
					if (default_view.zoom < 0.5*65536L) default_view.zoom = 0.5*65536L;
				}
			}
			break;

		case c_include:
			{
				char fname[100];
				FILE *in;
				char *f;
				strcpy(fname,strtok(NULL,ps));
				if ((in = fopen(f = fix_fname(fname), "r")) != NULL)
				{
					read_world(in);
					fclose(in);
				}
				else {
					char buff[100];
					sprintf(buff, "Could not open '%s'", f);
					if (running)
						popmsg(buff);
					else
						fprintf(stderr, "%s\n", buff);
					if (log_file)
						fprintf(log_file, "%s\n", buff);
				}
			}
			break;

		case c_surfacemap:
			{
				/* starts a new map of color numbers to surface names */
				strcpy(surfacemapname,strtok(NULL,ps));
				current_surface = NULL;
			}
			break;

		case c_surface:
			{
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
					p->color = strtoul(strtok(NULL,ps), NULL, 0);
					strcpy(buf2,strtok(NULL,ps));
					p->value = strdup(buf2);
				}
			}
			break;

		case c_surfacedef:
			{
				char sname[100], svalue[20];
				/* maps a surface name to an internal color value */
				strcpy(sname,strtok(NULL,ps));
				strcpy(svalue,strtok(NULL,ps));
				add_name(&surfdefs, sname, (void *) convert_color(svalue, NULL));
			}
			break;

		case c_split:
			{
				float x, y, z, nnx, nny, nnz;
				long nx, ny, nz;
				unsigned flags = 0;

				set_move_handler(split_move_handler);
				set_global_split_root(&split_tree);
				x = atof(strtok(NULL,ps));
				y = atof(strtok(NULL,ps));
				z = atof(strtok(NULL,ps));
				nnx = atof(strtok(NULL,ps));
				nny = atof(strtok(NULL,ps));
				nnz = atof(strtok(NULL,ps));
				tokhex(&flags);
				scale3(nnx, nny, nnz, &nx, &ny, &nz);
				current_split = add_split(&split_tree, x, y, z, nx, ny, nz, flags);
			}
			break;

		case c_splitpt:
			{
				float x1, x2, x3, y1, y2, y3, z1, z2, z3;
				long nx, ny, nz;
				unsigned flags = 0;

				set_move_handler(split_move_handler);
				set_global_split_root(&split_tree);
				x1 = atof(strtok(NULL,ps));
				y1 = atof(strtok(NULL,ps));
				z1 = atof(strtok(NULL,ps));
				x2 = atof(strtok(NULL,ps));
				y2 = atof(strtok(NULL,ps));
				z2 = atof(strtok(NULL,ps));
				x3 = atof(strtok(NULL,ps));
				y3 = atof(strtok(NULL,ps));
				z3 = atof(strtok(NULL,ps));
				flags = strtoul(strtok(NULL,ps), NULL, 0);
				points_to_normal(x1, y1, z1, x2, y2, z2, x3, y3, z3, &nx, &ny, &nz);
				current_split = add_split(&split_tree, x1, y1, z1, nx, ny, nz, flags);
			}
			break;

		case c_area:
			{
				long x, y, z;
				void *what_area();
				char areaname[100];
				AREA *a;

				x = atol(strtok(NULL,ps));
				y = atol(strtok(NULL,ps));
				z = atol(strtok(NULL,ps));
				sscanf(strtok(NULL,ps), st, areaname);
				add_name(&areas, areaname, a=what_area(split_tree, x, y, z));
				set_area_name(a, areaname);
			}
			break;

		case c_floor:
			{
				char aname[100];
				float aa, bb, cc, dd;
				long a,b,c,d;

				sscanf(strtok(NULL,ps), st, aname);
				aa = atof(strtok(NULL,ps));
				bb = atof(strtok(NULL,ps));
				cc = atof(strtok(NULL,ps));
				dd = atof(strtok(NULL,ps));
				scale4(aa, bb, cc, dd, &a, &b, &c, &d);
				add_floor(find_name(areas, aname), a, b, c, d);
			}
			break;

		case c_floorpts:
			{
				char aname[100];
				float x1, y1, z1, x2, y2, z2, x3, y3, z3;
				long a, b, c, d;

				sscanf(strtok(NULL,ps), st, aname);
				x1 = atof(strtok(NULL,ps));
				y1 = atof(strtok(NULL,ps));
				z1 = atof(strtok(NULL,ps));
				x2 = atof(strtok(NULL,ps));
				y2 = atof(strtok(NULL,ps));
				z2 = atof(strtok(NULL,ps));
				x3 = atof(strtok(NULL,ps));
				y3 = atof(strtok(NULL,ps));
				z3 = atof(strtok(NULL,ps));
				points_to_eqn(x1, y1, z1, x2, y2, z2, x3, y3, z3, &a, &b, &c, &d);
				add_floor(find_name(areas, aname), a, b, c, d);
			}
			break;

		case c_ceiling:
			{
				char aname[100];
				float aa, bb, cc, dd;
				long a, b, c, d;

				sscanf(strtok(NULL,ps), st, aname);
				aa = atof(strtok(NULL,ps));
				bb = atof(strtok(NULL,ps));
				cc = atof(strtok(NULL,ps));
				dd = atof(strtok(NULL,ps));
				scale4(aa, bb, cc, dd, &a, &b, &c, &d);
				add_ceiling(find_name(areas, aname), a, b, c, d);
			}
			break;

		case c_ceilingpts:
			{
				char aname[100];
				float x1, y1, z1, x2, y2, z2, x3, y3, z3;
				long a, b, c, d;

				sscanf(strtok(NULL,ps), st, aname);
				x1 = atof(strtok(NULL,ps));
				y1 = atof(strtok(NULL,ps));
				z1 = atof(strtok(NULL,ps));
				x2 = atof(strtok(NULL,ps));
				y2 = atof(strtok(NULL,ps));
				z2 = atof(strtok(NULL,ps));
				x3 = atof(strtok(NULL,ps));
				y3 = atof(strtok(NULL,ps));
				z3 = atof(strtok(NULL,ps));
				points_to_eqn(x1, y1, z1, x2, y2, z2, x3, y3, z3, &a, &b, &c, &d);
				add_ceiling(find_name(areas, aname), a, b, c, d);
			}
			break;

		case c_visfrom:
			{
				char aname[100], alist[100], *p;
				AREA *a, *b;

				sscanf(strtok(NULL,ps), st, aname);
				if ((a = find_name(areas, aname)) != NULL)
					for (p = strtok(NULL, ", "); p; p = strtok(NULL, ", "))
						if ((b = find_name(areas, p)) != NULL)
							add_visfrom(a, b);
			}
			break;

		case c_endsplits:
			current_split = NULL;
			break;

		case c_polyobj:
		case c_polyobj2:
			{
				char map[100], map2[100];
				OBJECT *obj;
				POLY *poly;
				unsigned color;
				int nv = 0;
				int i;
				long x[18], y[18], z[18];

				map[0] = '\0';
				set_loadplg_depthsort(0);
				nv = atoi(strtok(NULL,ps));
				tokstrn(map);
				if (cmd==c_polyobj2) tokstrn(map2);

				if (nv > 18) nv = 18;
				for(i=0;i<nv;i++)
				{
					x[i] = atol(strtok(NULL,ps));
					y[i] = atol(strtok(NULL,ps));
					z[i] = atol(strtok(NULL,ps));
				}

				obj = new_obj(0, nv, (cmd==c_polyobj2) ? 2 : 1);
				if (obj)
				{
					char *p;
					if ((p = strtok(NULL, ps)) != NULL)
						set_object_sorting(obj, atoi(p));
					if (map)
						color = (unsigned) find_color(surfdefs, map);
					poly = add_poly(obj, color, nv);
					for (i = 0; i < nv; i++)
					{
						add_vertex(obj, x[i], y[i], z[i]);
						add_point(obj, poly, nv-i-1);
					}
					if (cmd == c_polyobj2)
					{
						if (map2)
							color = (unsigned) find_color(surfdefs, map2);
						poly = add_poly(obj, color, nv);
						for (i = 0; i < nv; i++)
						{
							add_point(obj, poly, i);
						}
					}
					compute_all_obj(obj);
					if (current_split)
						add_obj_to_split_center(current_split, obj);
					else
						add_obj_to_split_area(split_tree, obj);
				}
			}
			break;

			/* CONFIG FILE LOAD STUFF */

			/* THESE DONE AFTER LOADING */

		case c_videodev:
			{
				extern char vdname[];
				extern int vdmode;

				sscanf(args, "%s %x", vdname, &vdmode);
			}
			break;

		case c_mousedev:
			{
				extern char mdname[];

				sscanf(args, st, mdname);
			}
			break;

		case c_headdev:
			{
				extern char hdname[];
				extern float hdo_x, hdo_y, hdo_z, hdo_rx, hdo_ry, hdo_rz;

				sscanf(args, "%s %f %f %f %f %f %f", hdname,
					      &hdo_x, &hdo_y, &hdo_z,
					      &hdo_rx, &hdo_ry, &hdo_rz);
			}
			break;

		case c_glovedev:
			{
				extern char gpdname[];
				extern int have_glove;
				extern float gpdo_x, gpdo_y, gpdo_z, gpdo_rx, gpdo_ry, gpdo_rz;

				have_glove = 1;
				sscanf(args, "%s %f %f %f %f %f %f", gpdname, &gpdo_x, &gpdo_y, &gpdo_z, &gpdo_rx, &gpdo_ry, &gpdo_rz);
			}
			break;

		case c_ptrdev:
			{
				extern char gpdname[];
				extern int have_ptr;
				extern float gpdo_x, gpdo_y, gpdo_z, gpdo_rx, gpdo_ry, gpdo_rz;

				have_ptr = 1;
				sscanf(args, "%s %f %f %f %f %f %f", gpdname, &gpdo_x, &gpdo_y, &gpdo_z, &gpdo_rx, &gpdo_ry, &gpdo_rz);
			}
			break;

		case c_switchdev:
			{
				extern char swdname[];
				sscanf(args, st, swdname);
			}
			break;

		case c_glovecursor:
			{
				extern char gpcursor[];
				sscanf(args, st, gpcursor);
			}
			break;

		case c_ptrcursor:
			{
				extern char gpcursor[];
				sscanf(args, st, gpcursor);
			}
			break;

			/* CONFIG: DONE IMMEDIATELY */

		case c_switchport:  /* synonym with no trademark problems */
		case c_segaport:
			{
				sscanf(args, "%x %x %x %x %x", &sega_address,
				&sega_mask, &sega_left, &sega_right, &sega_doff, &sega_port_image);
			}
			break;

		case c_pgloveport:
			{
				sscanf(args, "%x %x %x %x %x %x %x %x", &glove_in_port, &glove_out_port,
				&glove_write_mask, &glove_none_mask, &glove_latch_mask, &glove_clock_mask,
				&glove_clock_latch, &glove_data_mask, &port_image );
			}
			break;

		case c_pglovetime:
			{
				sscanf(args, "%d %d", &glove_bit_delay, &glove_byte_delay );
			}
			break;

		case c_stereoset:
			{
				float ws = 1.0;

				sscanf(args, "%ld %ld %ld %ld %ld %f", &(default_stereo.phys_screen_dist),
				&(default_stereo.phys_screen_width), &(default_stereo.pixel_width),
				&(default_stereo.phys_eye_spacing), &(default_stereo.phys_convergence), &ws);
				default_stereo.world_scaling = 65536.0 * ws;
			}
			break;

		case c_stereotype:
			{
				char sty[80];
				extern int stereo_type;

				sscanf(args, st, sty);
				if (match(sty, "OFF")) stereo_type = MONOSCOPIC;
				else if (match(sty, "SWITCH")) stereo_type = SWITCHED;
				else if (match(sty, "SEPARATE")) stereo_type = SEPARATE;
				else if (match(sty, "SPLIT")) stereo_type = SPLITLR;
			}
			break;

		case c_stereoleft:
			{
				sl_left = -1;
				sscanf(args, "%d %d %f %ld %ld %ld %ld %ld", &sl_xoff, &sl_xflip,
				&sl_xrot, &sl_left, &sl_top, &sl_right, &sl_bottom );
			}
			break;

		case c_stereoright:
			{
				sr_left = -1;
				sscanf(args, "%d %d %f %ld %ld %ld %ld %ld", & sr_xoff, &sr_xflip,
				&sr_xrot, &sr_left, &sr_top, &sr_right, &sr_bottom ) ;
			}
			break;

			/* ANIMATION PARSER */

#ifdef ENABLE_STATEMACH
		case c_animation:
			parse_ani(); 
			break;
		case c_state:
			parse_state(); 
			break;
		case c_if:
			parse_if(); 
			break;
		case c_do:
			parse_do(); 
			break;
#endif

		case c_title:
			if((args!=NULL)&&(args[0]!=0)&&(title_index<22))
			{
				char s[200];
				sscanf(args, "%s", s);
				if(strlen(args)>36) args[36] = 0;
				if(!stricmp(s,"memory"))
				{
					sprintf(s, "Memory Left: %ld", coreleft());
					args = s;
				}
				title[title_index++] = strdup(args);
				title[title_index] = NULL;
			}
			break;

		}

	}
	return 0;
}

static void dump_segment(SEGMENT *s, char *prefix, FILE *out)
{
	SEGMENT *p;
	char *name;
	long x, y, z;
	if ((name = seg_getname(s)) != NULL) {
		seg_getjointxyz(s, &x, &y, &z);
		fprintf(out, "position %s.%s %ld %ld %ld\n", prefix, name, x, y, z);
		seg_getjointang(s, &x, &y, &z);
		fprintf(out, "rotate %s.%s %f %f %f\n", prefix, name, x/65536.0, y/65536.0, z/65536.0);
	}
	for (p = child_segment(s); p; p = sibling_segment(p))
		dump_segment(p, prefix, out);
}

#ifdef ENABLE_STATE_SAVELOAD
int save_state(void) /* write world state to a .wld file */
{
	extern VIEW *all_views[];
	VIEW *v;
	char fn[20];
	FILE *out;
	OBJECT *obj; 
	SEGMENT *seg;
	NAMEREF *p;
	char *name;
	int i;
	askfor("Filename? ", fn, 15);
	if (fn[0] == '\0') return -1;
	if ((out = fopen(fn, "a")) == NULL) {
		popmsg("Could not write to file!");
		getkey();
		return -2;
	}
	fprintf(out, "\nframe\n");
	fprintf(out, "ambient %d\n", current_view->ambient);
	for (i = 0; i < 10; ++i)
		if (old_angle_order) {
			if ((v = all_views[i]) != NULL)
				fprintf(out, "camera %d %ld %ld %ld %f %f %f %f\n", i + 1,
				v->ex, v->ey, v->ez,
				v->pan/65536.0, v->tilt/65536.0, v->roll/65536.0,
				v->zoom/65536.0);
			}
		else {
			if ((v = all_views[i]) != NULL)
				fprintf(out, "camera %d %ld %ld %ld %f %f %f %f\n", i + 1,
				v->ex, v->ey, v->ez,
				v->tilt/65536.0, v->pan/65536.0, v->roll/65536.0,
				v->zoom/65536.0);
			}
#ifdef NOPE
	if ((v = all_views[0]) != NULL)
		fprintf(out, "start %ld %ld %ld %f %f %f %f\n",
		v->ex, v->ey, v->ez,
		v->pan/65536.0, v->tilt/65536.0, v->roll/65536.0,
		v->zoom/65536.0);
#endif
	for (p = objectlist; p; p = p->next)
		if ((seg = get_object_owner(p->value)) != NULL) {
			long x, y, z;
			seg_getjointxyz(seg, &x, &y, &z);
			fprintf(out, "position %s %ld %ld %ld\n", p->name, x, y, z);
			seg_getjointang(seg, &x, &y, &z);
			fprintf(out, "rotate %s %f %f %f\n", p->name, x/65536.0, y/65536.0, z/65536.0);
		}
	for (p = figurelist; p; p = p->next)
		dump_segment(p->value, p->name, out);
	fclose(out);
	return 0;
}

int load_state(void)
{
	char buff[500];
	FILE *in;
	long start_frame = 0;
	askfor("File? ", buff, 15);
	if (buff[0] == '\0') return -1;
	add_ext(buff, "wld");
	if ((in = fopen(buff, "r")) == NULL) {
		popmsg("Could not open file");
		getkey();
		return -2;
	}
	refresh_display();
	askfor("Start frame [1]? ", buff, 15);
	start_frame = atol(buff);
	refresh_display();
	askfor("millisecs/frame [zero]? ", buff, 8);
	frame_delay = atoi(buff);
	refresh_display();
	popmsg("Wait for key?");
	key_wait = toupper(getkey()) == 'Y';
	refresh_display();
	popmsg("Save frames?");
	if (toupper(getkey()) == 'Y') {
		save_frames = 1;
		refresh_display();
		askfor("Pattern? ", pcx_pattern, 15);
	}
	else
		save_frames = 0;
	refresh_display();
	if (start_frame) {
		long pos = ftell(in);
		while (fgets(buff, sizeof(buff), in)) {
			if (!strnicmp(strtok(buff, " \t"), "frame", 5)) {
				long f;
				toklong(&f);
				if (f >= start_frame) {
					fseek(in, pos, SEEK_SET);
					break;
				}
			}
			pos = ftell(in);
		}
	}
	return read_world(in);
}
#endif
