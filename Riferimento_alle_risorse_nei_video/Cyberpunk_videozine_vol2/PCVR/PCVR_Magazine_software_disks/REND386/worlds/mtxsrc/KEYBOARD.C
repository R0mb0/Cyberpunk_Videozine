/* Keyboard routines */

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
#include <stdlib.h>  /* for atol(), only for debugging! */
#include <dos.h>
#include <time.h>    /* time(), ctime() */
#include <string.h>
#include <math.h>
#include <alloc.h>

#include "config.h"
#include "rend386.h"
#include "intmath.h"
#include "plg.h"
#include "segio.h"
#include "pointer.h"
#include "userint.h"
#include "splits.h"
#include "cursor.h"


extern char goodbye();

extern char *fix_fname(char *fname);

extern STEREO default_stereo;
extern manip_2D_avail;

extern int sl_xflip, sl_xoff;
extern long sl_left, sl_top, sl_right, sl_bottom;
extern int sr_xflip, sr_xoff;
extern long sr_left, sr_top, sr_right, sr_bottom;
extern float sl_xrot, sr_xrot;

int use_old_keys = 0;
extern long latitude,longitude,center_roll;
extern long center_x,center_y,center_z,center_d;

extern char *progname;

extern OBJECT *where_split_screen_pt(int *pol, int *vert, int x, int y);

extern int redraw, review, reframe, running, do_horizon;
extern OBJLIST *objlist;
extern int stereo_type;
extern int fancy_background, reflection_pool, show_logo, do_screen_clear;
extern VIEW default_view, orig_view, *current_view, *current_home_view;
extern VIEW real_view;
extern STEREO default_stereo;
extern SPLIT *split_tree;
extern unsigned lastkey;
extern unsigned paint;
extern int show_location, show_compass, show_framerate;


static int sstepsize = 10;	/* speed multipliers */
static int astepsize = 2;


long anglestep = 160000L;
long spacestep = 10L;

int spinmode = 0;
int flymode = 0;
int floormode = 0;
int animatemode = 1;

extern int old_angle_order;  /* in wparse.c */

/******************* MENU TEXT **************/

char *helptext[] = {
	"X calls up MAIN MENU",
	"O calls up OBJECT MENU",
	"P calls up PAINT MENU",
	"F calls up FIGURE MENU",
	"V calls up VIEW MENU",
	"M calls up MANIPULATE MENU",
	"D calls up DISPLAY OPTIONS MENU",
	"ARROWS drive around",
	"RIGHT SHIFT+ARROWS look around",
	"LEFT SHIFT+ARROWS  move up, sideways",
	"CTRL+ARROWS  set stereo offset",
	"J toggles mouse motion, U u-turns",
	"+ and - changes zoom",
	"R repeats last arrow key move 100x",
	"0-9 set step or angle size",
	"F1-F10 select viewpoint",
	"HOME returns to starting point",
	"Q or ESC quits, ? or H shows help",
	"I displays view information",
	"S sets/resets object spin mode",
	"C displays color palette",
	"A toggles animation on/off",
	NULL
};

char *mainmenu[] = {
	"Help",
	"Information",
	"View menu",
	"Paint menu",
	"Display menu",
	"Object menu",
	"Figure menu",
	"Mouse menu",
	"Quit",
	NULL
};

char *viewmenu[] = {
	"Information",
	"Spin about object",
	"Fly mode toggle",
	"fLoor mode toggle",
	"Return to start",
	"Move step size",
	"Turn step set",
	"Go to (x,y,z) location",
	"look Angle ",
	"View window size",
	"Hither clipping depth",
	"Yon clipping depth",
	"PCX screen dump",
	"Options",
#ifdef ENABLE_STATE_SAVELOAD
	"Write state to file",
	"eXecute world file",
#endif
	NULL
};

static char *paintmenu[] = {
	"Select Surface",
	"Choose Color",
	"Get poly color",
	"Paint Polys",
	"paint All",
	"Resurface",
	NULL
};

static char *surfmenu[] = {
	"Absolute",
	"Cosine-lit",
	"Metal",
	"Glass",
	NULL
};

static char *optmenu[] = {
	"aniMation on/off",
	"Background",
	"Reflection",
	"Screen clear",
	"Horizon",
	"Ambient light",
	"Directional light",
	"Position display",
	"Compass display",
	"Frame rate display",
	NULL };

static char *mousemenu[] = {
	"Move",
	"Rotate",
	"Twirl",
	"Grasp",
	"Ungrasp",
	NULL
};

static char *objmenu[] = {
	"Load object",
	"Save object",
	"Information",
	"Delete object",
	"Unselect all",
	"First representation",
	"Next representation",
	NULL
};

static char *figmenu[] = {
	"Load figure",
	"Information",
	"Select all",
	"Unselect all",
	"Hack off",
	"Join to",
	"Attach viewpoint",
	"Detach viewpoint",
	NULL
};


/************************ KEY SUPPORT **************/

#define F1  0x3B00
#define F2  0x3C00
#define F3  0x3D00
#define F4  0x3E00
#define F5  0x3F00
#define F6  0x4000
#define F7  0x4100
#define F8  0x4200
#define F9  0x4300
#define F10 0x4400

#define HOME      0x4700
#define END       0x4F00
#define PGUP      0x4900
#define PGDN      0x5100

#define LEFT      0x4B00
#define RIGHT     0x4D00
#define UP        0x4800
#define DOWN      0x5000

#define SHLEFT    0x4B01
#define SHRIGHT   0x4D01
#define SHUP      0x4801
#define SHDOWN    0x5001
#define ASHLEFT   0x3401
#define ASHRIGHT  0x3601
#define ASHUP     0x3801
#define ASHDOWN   0x3201

#define LSHLEFT   0x4B02
#define LSHRIGHT  0x4D02
#define LSHUP     0x4802
#define LSHDOWN   0x5002
#define ALSHLEFT  0x3402
#define ALSHRIGHT 0x3602
#define ALSHUP    0x3802
#define ALSHDOWN  0x3202

#define SHPGUP    0x4901
#define SHPGDN    0x5101

#define CTRLLEFT  0x7300
#define CTRLRIGHT 0x7400

#define CTRLHOME  0x7700
#define CTRLEND   0x7500
#define CTRLPGUP  0x8400
#define CTRLPGDN  0x7600

#define ESC       0x001B
#define TAB       0x0009

/*************** STATUS DISPLAYS ETC. ************/


void compute_vpoint(long *x, long *y, long *z, long dist)
{
	MATRIX n;

	*x = 0;
	*y = 0;
	*z = dist;

	view_to_matrix(&real_view, n);

	matrix_point(n,x,y,z);
}

static void center(char *s, int w)
{
	int n;

	if (strlen(s) == 0) return;
	n = (w - strlen(s)) /2;
	memmove(&s[n], s, strlen(s)+1);
	memset(s, ' ', n);
}

static int nobjs, nverts, npolys;

void gather_data(OBJECT *obj)
{
	int nv = 0, np = 0;

	get_obj_info(obj, &nv, &np);
	++nobjs;
	nverts += nv;
	npolys += np;
}

extern VIEW real_view;

disp_status(VIEW *v)
{
	char *text[10], a[80], b[80], c[80], d[80], e[80], f[80], g[80], h[80];
	int w, i;
	long x, y, z;
	real_viewpoint(v, &x, &y, &z);

	text[0] = a;
	text[1] = "";
	text[2] = b;
	text[3] = c;
	text[4] = d;
	text[5] = e;
	text[6] = f;
	text[7] = g;
	text[8] = h;
	text[9] = NULL;
	sprintf(a, "STATUS");

	sprintf(b, "X = %ld  Y = %ld  Z = %ld", x, y, z);
	w = strlen(b);

	if (old_angle_order)
		sprintf(c, "Pan = %ld   Tilt = %ld   Roll = %ld  ", v->pan/65536L, v->tilt/65536L, v->roll/65536L);
	else
		sprintf(c, "Tilt = %ld   Pan = %ld   Roll = %ld  ", v->tilt/65536L, v->pan/65536L, v->roll/65536L);

	if (strlen(c) > w) w = strlen(c);
	sprintf(d, "Zoom = %2.2f", v->zoom/65536.0);
	if (strlen(d) > w) w = strlen(d);
	sprintf(e, "Hither = %ld  Yon = %ld", v->hither, v->yon);
	if (strlen(e) > w) w = strlen(e);

	nobjs = 0, nverts = 0, npolys = 0;
	walk_split_tree(split_tree, gather_data);
	sprintf(f, "%d object%s, %d vertice%s, %d poly%s", nobjs,
	(nobjs == 1) ? "" : "s", nverts, (nverts == 1) ? "" : "s",
	npolys, (npolys == 1) ? "" : "s");
	sprintf(g, "Ambient light: %d", current_view->ambient);
	sprintf(h, "Memory Free: %ld", coreleft());

	if (strlen(f) > w) w = strlen(f);
	if (strlen(g) > w) w = strlen(g);
	if (strlen(h) > w) w = strlen(h);

	for (i = 0; text[i]; ++i) center(text[i], w);
	poptext(text);
	reframe = 1;
	redraw = 1;
	return 0;
}


void disp_palette(void)
{
	int i, j, page;
	page = cursor_hide();
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j++)
			user_box(j*10,i*8,j*10+9,i*8+8,i*16+j);
	cursor_show(page);
	reframe = 1;
}

void add_ext(char *name, char *ext)
{
	char *c;
	if(strchr(name, '.')) return;
	c = strchr(name, 0);
	*c++ = '.';
	*c++ = *ext++;
	*c++ = *ext++;
	*c++ = *ext++;
	*c = 0;
}

/*************** JOYSTICK NAVIGATION ***************/

extern long last_render_time;

static int b_spinmap[4] = { 
	1, 1, 1, 3 };

do_joy(joystick_data *joy)
{
	int x,y,b;
	long dist;
	long ang;
	int sscale;
	long mx=0, my=0, mz=0;
	MATRIX n;

	x = joy->x;
	y = joy->y;
	b = joy->buttons;
	dist = spacestep*sstepsize;
	ang = astepsize*anglestep;
	sscale = last_render_time;


	if (abs(x) < 10 && abs(y) < 10) return 0;

	if (x > 10) x -= 10;
	else
	{
		if (x > -10) x = 0;
		else x += 10;
	}
	if (y > 10) y -= 10;
	else
	{
		if (y > -10) y = 0;
		else y += 10;
	}
	if(spinmode) b=b_spinmap[b];
	;
	switch (b)
	{
	case 0:/* no buttons down */
		current_view->pan += (x * ang)/600*sscale;
		mz = -(y * dist * sscale)/120L;
		review = redraw = 1;
		break;

	case 1:/* first button down */
		current_view->tilt -= (y * ang)/400*sscale;
		current_view->pan += (x * ang)/300*sscale;
		review = redraw = 1;
		break;

	case 2:/* second button down */
		mx = -(x * dist * sscale)/120L;
		my = -(y * dist * sscale)/120L;
		review = redraw = 1;
		break;

	case 3:/* both buttons down */
		current_view->roll += (x * ang)/1000*sscale;
		current_view->zoom += (y*65536L) /4000*sscale;
		if (stereo_type != MONOSCOPIC)
		{
			compute_stereo_data(&default_stereo, LEFT_EYE, sl_xflip, sl_xoff,
			65536.0*sl_xrot, sl_left, sl_top, sl_right, sl_bottom);
			compute_stereo_data(&default_stereo, RIGHT_EYE, sr_xflip, sr_xoff,
			65536.0*sr_xrot, sr_left, sr_top, sr_right, sr_bottom);
		}
		review = redraw = 1;
		break;

	default:
		break;
	}
	if(b!=1)
	{
		if(flymode)
			std_matrix(n,current_view->tilt,current_view->pan,current_view->roll, 0, 0, 0);
		else std_matrix(n, 0, current_view->pan, 0, 0, 0, 0);
		matrix_point(n, &mx, &my, &mz);
		current_view->ex += mx;
		current_view->ey += my;
		current_view->ez += mz;
	}
	return 0;
}

/******************* SPINNING VIEW COMPUTE **************/

static l_x = 1000, l_y = 15000, l_z = -5000; /* light source */

long center_d = 10000;
long center_x = 0;
long center_y = 0;
long center_z = 0;
long latitude = 0;
long longitude = 0;
long center_roll = 0;

static long light_d = 1000000;

void polar_compute(void) /* for spin mode: recompute viewpoint based on */
{ /* view angle and distance so object centered  */
	MATRIX m,n;

	long x = 0;
	long y = 0;
	long z = -center_d;

	latitude = current_view->pan;
	longitude = current_view->tilt;
	center_roll = current_view->roll;

	std_matrix(n,longitude,latitude,center_roll,0,0,0);
	matrix_point(n,&x,&y,&z);
	current_view->ex = x + center_x;
	current_view->ey = y + center_y;
	current_view->ez = z + center_z;

	x = l_x;
	y = l_y;
	z = l_z;

	matrix_point(n,&x,&y,&z);
	current_view->lx = x;
	current_view->ly = y;
	current_view->lz = z;
}




/********************** KEY INTERPERTER *****************/

VIEW *all_views[10] = { 
	&default_view,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
VIEW *save_views[10] = { 
	&orig_view ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

int mouse_nav = 0;

extern PDRIVER *cursor_device;

int lastarrowkey = 0;
int oldkey = 0;
static int movemults[] = {
	1,2,3,5,7,10,13,17,22,28};
static int angmults[] = {
	1,1,1,1,2,2,2,3,4,5};

do_key(unsigned c)
{
	void joystick_calibration(joystick_data *), *what_area();
	void view_menu(void), mouse_menu(void), stereo_info(void);
	char buff[100];
	FILE *in, *out;
	long x, y, z;
	long mx=0, my=0, mz=0;
	int i, j;
	MATRIX m,n;

	if (check_key(c)) return 0;
	if(c<0x7f)if(isalpha(c)) c = toupper(c);
	oldkey = c;

	switch (c)
	{
	case LEFT:
	case SHLEFT:
	case ASHLEFT:
		current_view->pan -= astepsize * anglestep;
		goto arrow_exit;
	case RIGHT:
	case SHRIGHT:
	case ASHRIGHT:
		current_view->pan += astepsize * anglestep;
		goto arrow_exit;
	case UP:
		if (spinmode) current_view->tilt += astepsize * anglestep;
		else
			{
			mz = 2;
			/*current_view->ex += m_mult(sstepsize*spacestep*2, isine(current_view->pan));
			       current_view->ez += m_mult(sstepsize*spacestep*2, icosine(current_view->pan)); */
			goto move_arrow;
		}
		goto arrow_exit;
	case DOWN:
		if (spinmode) current_view->tilt -= astepsize * anglestep;
		else
			{
			mz = -2;
			/*       current_view->ex -= m_mult(sstepsize*spacestep*2, isine(current_view->pan));
			       current_view->ez -= m_mult(sstepsize*spacestep*2, icosine(current_view->pan)); */
			goto move_arrow;
		}
		goto arrow_exit;
move_arrow:
		{
			MATRIX n;

			if(flymode)
				std_matrix(n,current_view->tilt,current_view->pan,current_view->roll, 0, 0, 0);
			else std_matrix(n, 0, current_view->pan, 0, 0, 0, 0);
			if(mx) mx *= sstepsize*spacestep;
			if(my) my *= sstepsize*spacestep;
			if(mz) mz *= sstepsize*spacestep;
			matrix_point(n, &mx, &my, &mz);
			current_view->ex += mx;
			current_view->ey += my;
			current_view->ez += mz;
		}
arrow_exit:
		review = redraw = 1;
		lastarrowkey = c;
		break;

	case SHDOWN:
	case ASHDOWN:
		current_view->tilt += (astepsize * anglestep);
		goto arrow_exit;
	case SHUP:
	case ASHUP:
		current_view->tilt -= (astepsize * anglestep);
		goto arrow_exit;

	case LSHLEFT:
	case ALSHLEFT:
		mx = -1;
		/*current_view->ex -= m_mult(sstepsize*spacestep, icosine(current_view->pan));
		     current_view->ez += m_mult(sstepsize*spacestep, isine(current_view->pan));*/
		goto move_arrow;
	case LSHRIGHT:
	case ALSHRIGHT:
		mx = 1;
		/* current_view->ex += m_mult(sstepsize*spacestep, icosine(current_view->pan));
		     current_view->ez -= m_mult(sstepsize*spacestep, isine(current_view->pan)); */
		goto move_arrow;
	case PGUP:
	case LSHUP:
	case ALSHUP:
		my = 1;
		/*     current_view->ey += spacestep*sstepsize ; */
		goto move_arrow;
	case LSHDOWN:
	case ALSHDOWN:
	case PGDN:
		my = -1;
		/*     current_view->ey -= spacestep*sstepsize ;  */
		goto move_arrow;

	case CTRLPGUP:
		current_view->roll -= astepsize * anglestep>>2;
		goto arrow_exit;
	case CTRLPGDN:
		current_view->roll += astepsize * anglestep>>2;
		goto arrow_exit;

	case CTRLLEFT:
		if (sl_xflip) sl_xoff++;
		else sl_xoff--;
		if (sr_xflip) sr_xoff--;
		else sr_xoff++;
		goto stereo_recompute;
	case CTRLRIGHT:
		if (sl_xflip) sl_xoff--;
		else sl_xoff++;
		if (sr_xflip) sr_xoff++;
		else sr_xoff--;
		goto stereo_recompute;

	case '*':   /* level view */
		current_view->tilt = current_view->roll = 0;
		review = redraw = 1;
		break;
	case '+':
		if (stereo_type == MONOSCOPIC)
		{
			current_view->zoom *= 1.1;
			if(current_view->zoom > 16*65536L) current_view->zoom = 16*65536L;
			review = redraw = 1;
			break;
		}
		if(default_stereo.phys_screen_dist>30)
			default_stereo.phys_screen_dist *= 1.05;
		else default_stereo.phys_screen_dist *= 1.25;
		goto stereo_recompute; /* save some code (Dave) */
	case '-':
		if (stereo_type == MONOSCOPIC)
		{
			current_view->zoom /= 1.1;
			if(current_view->zoom < 32000L) current_view->zoom = 32000L;
			review = redraw = 1;
			break;
		}
		default_stereo.phys_screen_dist /= 1.05;
		if(default_stereo.phys_screen_dist<5)
			default_stereo.phys_screen_dist = 5;
		goto stereo_recompute;

	case '!':
		if (stereo_type != MONOSCOPIC)
		{
			default_stereo.phys_eye_spacing /= 1.05;
			if(default_stereo.phys_eye_spacing<5)
				default_stereo.phys_eye_spacing = 5;
			goto stereo_recompute;
		}
		break;
	case '@':
		if (stereo_type != MONOSCOPIC)
		{
			if(default_stereo.phys_eye_spacing>30)
				default_stereo.phys_eye_spacing *= 1.05;
			else default_stereo.phys_eye_spacing *= 1.25;
		}
		else break;

stereo_recompute:
		if (stereo_type != MONOSCOPIC)
		{
			compute_stereo_data(&default_stereo, LEFT_EYE, sl_xflip, sl_xoff,
			65536.0*sl_xrot, sl_left, sl_top, sl_right, sl_bottom);
			compute_stereo_data(&default_stereo, RIGHT_EYE, sr_xflip, sr_xoff,
			65536.0*sr_xrot, sr_left, sr_top, sr_right, sr_bottom);
		}
		review = redraw = 1;
		break;

	case '$':
		stereo_info();
		review = redraw = 1;
                set_goodbye();
		while(!goodbye());
		break;

	case 'U':
		current_view->pan += 180*65536L;
		review = redraw = 1;
		break;

	case HOME:
		*current_view = *current_home_view;
		review = redraw = 1;
		break;

	case '0':
		sstepsize = movemults[9];
		astepsize = angmults[9];
		break;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		sstepsize = movemults[c - '1'];
		astepsize = angmults[c - '1'];
		break;

	case 'Q':
	case ESC:
		popmsg("Really quit?");
		set_goodbye();
		while((i=goodbye())==0);
		if (toupper(i)=='Y') running = 0;
		else reframe = redraw = 1;
		break;

	case 'R':
		if (lastarrowkey)
			for (i = 0; i < 100; i++)
			{
				do_key(lastarrowkey);
				refresh_display();
				if(kbhit()) break;
			}
		break;

	case 'I':
		disp_status(&real_view);
		set_goodbye();
		while(!goodbye());
		reframe = redraw = 1;
		break;
	case 'C':
		disp_palette();
		set_goodbye();
		while(!goodbye());
		reframe = redraw = 1;
		break;
	case 'H':
	case '?':
		poptext(helptext);
		set_goodbye();
		while(!goodbye());
		reframe = redraw = 1;
		break;
	case 'X':
		main_menu();
		reframe = redraw = 1;
		break;
	case 'D':
		disp_options();
		reframe = redraw = 1;
		break;
	case 'O':
		obj_menu();
		reframe = redraw = 1;
		break;
	case 'F':
		fig_menu();
		reframe = redraw = 1;
		break;
	case 'P':
		painting();
		reframe = review = redraw = 1;
		break;
	case 'M':
		mouse_menu();
		reframe = review = redraw = 1;
		break;
	case 'V':
		view_menu();
		reframe = review = redraw = 1;
		break;
	case 'J':
		mouse_nav = !mouse_nav;
		break;
	case 'A':
		animatemode = !animatemode;
		break;
	case TAB:
		if(animatemode==0) animatemode = -1;
		break;
	case 'S':
		if(spinmode) spinmode = 0;
		else
			{
			OBJECT *newobj;
			float dist;
			if (can_point_2D() && manip_2D_avail)
			{
				int mx, my;
				refresh_display();
				popmsg("Click on object to spin about");
				tdelay(500);
				reframe = 1;
				refresh_display();
				move_till_click(cursor_device, 1, &mx, &my);
				newobj = where_split_screen_pt(NULL, NULL, mx, my);
				if(newobj)
					get_object_bounds(newobj, &center_x, &center_y, &center_z);
			}
			dist = (float)(center_x - current_view->ex) *
				(float)(center_x - current_view->ex) +
				(float)(center_y - current_view->ey) *
				(float)(center_y - current_view->ey) +
				(float)(center_z - current_view->ez) *
				(float)(center_z - current_view->ez);
#ifdef SQRTL
			center_d = sqrtl(dist);
#else
			center_d = (long) floor(sqrt((double) dist));
#endif
			spinmode = 1;
		}
		reframe = redraw = 1;
		break;
	case '^':
		save_pcx_file();
		break;
	case F1:
	case F2:
	case F3:
	case F4:
	case F5:
	case F6:
	case F7:
	case F8:
	case F9:
	case F10:
		i = (c- F1) >> 8;
		if(all_views[i])
		{
			current_view = all_views[i];
			current_home_view = save_views[i];
		}
		if (stereo_type != MONOSCOPIC)
		{
			compute_stereo_data(&default_stereo, LEFT_EYE, sl_xflip, sl_xoff,
			65536.0*sl_xrot, sl_left, sl_top, sl_right, sl_bottom);
			compute_stereo_data(&default_stereo, RIGHT_EYE, sr_xflip, sr_xoff,
			65536.0*sr_xrot, sr_left, sr_top, sr_right, sr_bottom);
		}
		reframe = redraw = 1;
		break;

	default:
		break;
	}
	return 0;
}


/*************** VIEW MENU *************/

void view_menu(void)
{
	char buff[100], *p;
	FILE *out;
	char d;

	switch (menu(viewmenu))
	{
	case 'I':
		do_key('I');
		break;
	case 'R':
		do_key (HOME);
		break;
	case 'P':
		do_key('^');
		break;
	case 'F':
		flymode = !flymode;
		popmsg(flymode ? "Fly mode" : "Ground mode");
		tdelay(350);
		break;
	case 'L':
		floormode = !floormode;
		popmsg(floormode ? "Floors used" : "Floors ignored");
		tdelay(350);
		break;
	case 'H':
		askfor("Enter hither value:", buff, 10);
		if (buff[0])
			current_view->hither = atof(buff);
		if (current_view->hither < 1) current_view->hither = 1;
		review = 1;
		reframe = redraw = 1;
		break;
	case 'Y':
		askfor("Enter yon value:", buff, 10);
		if (buff[0]) current_view->yon = atof(buff);
		review = 1;
		reframe = redraw = 1;
		break;
	case 'G':/* goto XYZ */
		askfor("X,Y,Z: ", buff, 25);
		if (buff[0])
			sscanf(buff, "%ld,%ld,%ld", &current_view->ex, &current_view->ey, &current_view->ez);
		reframe = review = redraw = 1;
		break;
	case 'A':/* look at angle */
		{
			long p, t, r;
			askfor("Pan,tilt,roll:", buff, 22);
			if (buff[0])
				sscanf(buff, "%ld,%ld,%ld", &p, &t, &r);
			current_view->pan = p*65536L;
			current_view->tilt = t*65536L;
			current_view->roll = r*65536L;
			reframe = review = redraw = 1;
		}
		break;
	case 'M':
		askfor("Move step: ", buff, 15);
		if (buff[0]) spacestep = atoi(buff);
		review = redraw = 1;
		break;
	case 'T':
		askfor("Turn angle step: ", buff, 15);
		if (buff[0]) anglestep = atof(buff) * 65536L;
		review = redraw = 1;
		break;
	case 'V':
		resize_viewport();
		reframe = review = redraw = 1;
		break;
	case 'O':
		disp_options();
		reframe = redraw = 1;
		break;
	case 'S':
		do_key('S');
		break;
#ifdef ENABLE_STATE_SAVELOAD
	case 'W':
		save_state();
		review = redraw = 1;
		break;
	case 'X':
		load_state();
		review = redraw = 1;
		break;
#endif
	default:
		break;
	}
}


void stereo_info(void)
{
	char b1[50]="", b2[50]="", b3[50]="", b4[50]="", b5[50]="", b6[50]="";
	char b7[50]="", b8[50]="", b9[50]="";
	char *b[10];
	SEGMENT *s;
	long x,y,z;

	float xo, xa, conv, ws;

	if(stereo_type==MONOSCOPIC) return;

	xa = (sl_xoff-sr_xoff)/2.0;
	ws = default_stereo.world_scaling/65536.0;
	xo=(default_stereo.phys_eye_spacing*default_stereo.phys_screen_dist*default_stereo.pixel_width) /
		(2.0*default_stereo.phys_screen_width*default_stereo.phys_convergence);
	conv =(default_stereo.phys_eye_spacing*default_stereo.phys_screen_dist*default_stereo.pixel_width) /
		(2.0*default_stereo.phys_screen_width*(xo+xa));

	b[0] = b1;
	sprintf(b1, "Stereo Parameters");
	b[1] = b2;
	sprintf(b2, "screen distance: %ld", default_stereo.phys_screen_dist);
	b[2] = b3;
	sprintf(b3, "screen width:    %ld", default_stereo.phys_screen_width);
	b[3] = b4;
	sprintf(b4, "pixel width:     %ld", default_stereo.pixel_width);
	b[4] = b5;
	sprintf(b5, "eye spacing:     %ld", default_stereo.phys_eye_spacing);
	b[5] = b6;
	sprintf(b6, "convergence distance:    %ld", default_stereo.phys_convergence);
	b[6] = b7;
	sprintf(b7, "world scaling:   %3.1f", ws);
	b[7] = b8;
	sprintf(b8, "added horizontal offset: %4.0f", xa);
	b[8] = b9;
	sprintf(b9, "effective convergence:   %4.0f", conv);
	b[9] = NULL;

	poptext(b);
}


/************* PROCESS SUPPORT ***********/

int nselected = 0;
SEGMENT *last_figure;

FILE *save_file = NULL;

int nsaved = 0;

void save_it(OBJECT *obj)
{
	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		if(nselected<2) save_plg(obj, save_file, 0); /* only one: save object coords */
		else save_plg(obj, save_file, 1); /* else save world coords */
	}
}

static long mxosize = 0;

void maxsize_it(OBJECT *obj)
{
	long s, j;
	if(obj)
	{
		s = get_object_bounds(obj, &j, &j, &j);
		if(s>mxosize) mxosize = s;
	}
}


void hilite_it(OBJECT *obj)
{
	set_obj_flags(obj, get_obj_flags(obj) | OBJ_HIGHLIGHTED);
	highlight_obj(obj);
}


void walk_segtree(SEGMENT *s, void (*f)())
{
	SEGMENT *p;
	OBJECT *obj;
	if ((obj = seg_get_object(s)) != NULL) f(obj);
	for (p = child_segment(s); p; p = sibling_segment(p))
		walk_segtree(p, f);
}

void select_tree(SEGMENT *s)
{
	SEGMENT *p;
	OBJECT *obj;
	if ((obj = seg_get_object(s)) != NULL) highlight_obj(obj);
	for (p = child_segment(s); p; p = sibling_segment(p))
		select_tree(p);
}

void count_tree(SEGMENT *s, int *nsegs, int *nverts, int *npolys)
{
	SEGMENT *p;
	OBJECT *obj;
	++*nsegs;
	if ((obj = seg_get_object(s)) != NULL)
	{
		int nv, np;
		get_obj_info(obj, &nv, &np);
		*nverts += nv;
		*npolys += np;
	}
	for (p = child_segment(s); p; p = sibling_segment(p))
		count_tree(p, nsegs, nverts, npolys);
}

static void zap_obj(OBJECT *obj)
{
	remove_from_objlist(obj);
	delete_obj(obj);
}


extern SEGMENT *body_seg;
extern SEGMENT *head_seg;
extern SEGMENT *wrist_seg;

static int bodyfound;

static void checkbody(SEGMENT *s)
{
	SEGMENT *p; /* recursive test if view attached to object */
	if (s == body_seg)
	{
		bodyfound = 1;
		return;
	}
	for (p = child_segment(s); p; p = sibling_segment(p)) checkbody(p);
}

void grab_it(OBJECT *obj)
{
	SEGMENT *s, *r;

	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		if((s=get_object_owner(obj))!=NULL) /* make sure no loops develop */
		{
			bodyfound = 0;
			checkbody(find_root_segment(s));
			if(bodyfound) return;

			while((r=parent_segment(s))!=NULL)
			{
				if(r==body_seg) return;
				s = r;
			}
			if(s==head_seg || s==wrist_seg) return; /* legal to detach? */
			attach_segment(s, body_seg);
		}
	}
}

void ungrab_it(OBJECT *obj)
{
	SEGMENT *s, *r;

	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED) /* selected? */
	{
		if((s=get_object_owner(obj))!=NULL) /* segment? */
		{
			while((r=parent_segment(s))!=NULL)
			{
				if(r==body_seg) goto got_it;
				s = r;
			}
			return;
got_it:
			if(s==head_seg || s==wrist_seg) return; /* legal to detach? */
			detach_segment(s);
		}
	}
}

static long centx, centy, centz;

void count_selected(OBJECT *obj)
{
	long x, y, z;
	SEGMENT *s;

	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		++nselected;
		get_object_bounds(obj, &centx, &centy, &centz);
		if((s=get_object_owner(obj))!=NULL)
		{
			last_figure = s;
			seg_getjointang(s,&x, &y, &z);
		}
	}
}


int nobjs = 0, nverts = 0, npolys = 0;

void gather_info(OBJECT *obj)
{
	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		int nv, np;
		++nobjs;
		get_obj_info(obj, &nv, &np);
		nverts += nv;
		npolys += np;
	}
}


long ptx, pty, ptz;
long oldx, oldy, oldz, oldcx, oldcy, oldcz, dx, dy, dz;

void move_it(OBJECT *obj)
{
	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		SEGMENT *s;
		if ((s = get_object_owner(obj)) != NULL)
		{
			rel_move_segment(s, ptx - oldx, pty - oldy, ptz - oldz);
			update_segment(s);
		}
	}
}

void twirl_it(OBJECT *obj)
{
	int i;
	long rx, ry, rz;

	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		SEGMENT *s;
		if ((s = get_object_owner(obj)) != NULL)
		{
			seg_getrxyz(s, &rx, &ry, &rz);
			abs_rot_segment(s, ptx+rx, pty+ry, ptz+rz, RYXZ);
			update_segment(s);
		}
	}
}

void rot_it(OBJECT *obj)
{
	int i;

	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		SEGMENT *s;
		if ((s = get_object_owner(obj)) != NULL)
		{
			rel_rot_segment(s, ptx, pty, ptz, RYXZ);
			update_segment(s);
		}
	}
}


void unhi_it(OBJECT *obj)
{
	set_obj_flags(obj, get_obj_flags(obj) & ~OBJ_HIGHLIGHTED);
	unhighlight_obj(obj);
}

void hack_it(OBJECT *obj)
{
	SEGMENT *s;
	if ((get_obj_flags(obj) & OBJ_HIGHLIGHTED) &&
		(s = get_object_owner(obj)) != NULL)
	{
		detach_segment(s);
		update_segment(s);
	}
}

SEGMENT *newparent = NULL;

void join_it(OBJECT *obj)
{
	SEGMENT *s;
	if ((get_obj_flags(obj) & OBJ_HIGHLIGHTED) &&
		(s = get_object_owner(obj)) != NULL)
	{
		attach_segment(s, newparent);
		update_segment(s);
	}
}

void nuke_it(OBJECT *obj)
{
	if ((get_obj_flags(obj) & OBJ_HIGHLIGHTED))
	{
		SEGMENT *s;
		if ((s = get_object_owner(obj)) != NULL)
			seg_set_object(s, NULL);
		remove_from_objlist(obj);
		delete_obj(obj);
	}
}

void next_it(OBJECT *obj)
{
	next_rep(obj);
}

void first_it(OBJECT *obj)
{
	first_rep(obj);
}

int check_moveobj(void)
{
	nselected = 0;
	last_figure = NULL;

	walk_split_tree(split_tree, count_selected);
	if (last_figure == 0)
	{
		popmsg("No movable objects selected!");
		tdelay(600);
		return 1;
	}
	return 0;
}

int check_obj(void)
{
	nselected = 0;
	last_figure = NULL;

	walk_split_tree(split_tree, count_selected);
	if (nselected == 0)
	{
		popmsg("No objects selected!");
		tdelay(600);
		return 1;
	}
	return 0;
}

void seg_info(int fig)
{
	char b1[50]="", b2[50]="", b3[50]="", b4[50]="", b5[50]="", b6[50]="";
	char *b[7];
	SEGMENT *s;
	long x,y,z;

	b[0] = b1;
	b[1] = b2;
	b[2] = b3;
	b[3] = b4;
	b[4] = b5;
	b[5] = b6;
	b[6] = NULL;
	nselected = 0;
	last_figure = NULL;
	walk_split_tree(split_tree, count_selected);
	sprintf(b6, "Object center:%ld, %ld, %ld", centx, centy, centz);
	if(fig && last_figure) last_figure = find_root_segment(last_figure);
	nobjs = nverts = npolys = 0;
	if(fig && last_figure)
	{
		count_tree(last_figure, &nobjs, &nverts, &npolys);
		sprintf(b1, "%d seg%s, %d vert%s, %d poly%s",
		nobjs, (nobjs == 1) ? "" : "s",
		nverts, (nverts == 1) ? "" : "s",
		npolys, (npolys == 1) ? "" : "s" );
	}
	else
	{
		walk_split_tree(split_tree, gather_info);
		sprintf(b1, "%d obj%s, %d vert%s, %d poly%s",
		nobjs, (nobjs == 1) ? "" : "s",
		nverts, (nverts == 1) ? "" : "s",
		npolys, (npolys == 1) ? "" : "s" );
	}
	if(last_figure==NULL)
	{
		sprintf(b2," No moveable objects selected");
		b[2] = b6;
		b[3] = NULL;
	}
	else
	{
		seg_getposxyz(last_figure, &x,&y,&z);
		sprintf(b2, "World pos'n: %ld %ld %ld", x, y, z);
		seg_getposang(last_figure, &x,&y,&z);
		sprintf(b3, "World angle: %4.1f %4.1f %4.1f", x/65536.0, y/65536.0, z/65536.0);
		if(last_figure==NULL || fig==0)
		{
			seg_getjointxyz(last_figure, &x,&y,&z);
			sprintf(b4, "Joint pos'n: %ld %ld %ld", x, y, z);
			seg_getjointang(last_figure, &x,&y,&z);
			sprintf(b5, "Joint angle: %4.1f %4.1f %4.1f", x/65536.0, y/65536.0, z/65536.0);
		}
		else
			{
			b[4] = b6;
			b[3] = b[2];
			b[2] = b[1];
			b[5] = NULL;
			sprintf(b5,"Root of figure:");
			b[1] = b5;
		}
	}
	poptext(b);
}



/************* MOUSE MANIPULATION MENU ***********/

extern PDRIVER *cursor_device;

POINTER pointer;
extern SEGMENT *light_seg, *light_seg2; /* used for moving lights */
extern long light2_x, light2_y ,light2_z;

void mouse_menu(void)
{
	void pointer_to_world();
	char buff[100], *p;
	char c, d;
	unsigned buttons;
	int click = 0;

	init_pointer(&pointer);

	switch(c = menu(mousemenu))
	{
	case 'M':
		refresh_display();
		if(check_moveobj()) break;
		if (!manip_2D_avail) break;
		pointer_read(cursor_device, &pointer);
		pointer_to_world(&pointer, &real_view, &ptx, &pty, &ptz);
		click = 0;
		while (click == 0)
		{
			if(light_seg2) seg_getposxyz(light_seg2, &light2_x, &light2_y, &light2_z);
			refresh_display();
			oldx = ptx;
			oldy = pty;
			oldz = ptz;
			click = PNEW_BUT & pointer_read(cursor_device, &pointer);
			if (!(pointer.buttons & 1)) click = 0;
			pointer_to_world(&pointer, &real_view, &ptx, &pty, &ptz);
			walk_split_tree(split_tree, move_it);
		}
		refresh_display();
		break;
	case 'R':
	case 'T':
		refresh_display();
		if(check_moveobj()) break;
		if (!manip_2D_avail) break;
		pointer_read(cursor_device, &pointer);
		oldcx = oldx = pointer.x;
		oldcy = oldy = pointer.y;
		oldcz = oldz = pointer.z;
		while ((pointer.buttons & 0x01) == 0)
		{
			if (toupper(c) == 'R')
			{
				ptx = 32768L*(pointer.y - oldy);
				pty = -32768L*(pointer.x - oldx);
				ptz = -32768L*(pointer.z - oldz);
			}
			else
			{
				ptx = 3270L*(pointer.y - oldcy);
				pty = -3270L*(pointer.x - oldcx);
				ptz = -3270L*(pointer.z - oldcz);
			}
			rotate_to_view(&real_view, &ptx, &pty, &ptz);
			if(toupper(c)=='R') walk_split_tree(split_tree, rot_it);
			else walk_split_tree(split_tree, twirl_it);
			oldx = pointer.x;
			oldy = pointer.y;
			oldz = pointer.z;
			refresh_display();
			pointer_read(cursor_device, &pointer);
		}

		while (pointer.buttons & 0x01) pointer_read(cursor_device, &pointer);
		refresh_display();
		break;
	case 'G':
		if(check_moveobj()) break;
		walk_split_tree(split_tree, grab_it);
		break;
	case 'U':
		if(check_moveobj()) break;
		walk_split_tree(split_tree, ungrab_it);
		break;
	default:
		break;
	}
}

static unsigned sortflag;

static void sortflag_it(OBJECT *obj)
	{
	set_object_sorting(obj, sortflag);
	}

int obj_menu(void)
{
	char buff[100], *p;
	FILE *in, *out;
	char c, d;
	long x, y, z;
        int i;

	nselected = 0;
	last_figure = NULL;

	switch (c=menu(objmenu))
	{
	case 'L':/* load PLG file */
		askfor("File to load? ", buff, 22);
		if (buff[0] == '\0')
		{
			redraw = 1;
			break;
		}
		strcpy(buff, fix_fname(buff));
		add_ext(buff,"plg");
		if ((in = fopen(buff, "r")) == NULL)
		{
			popmsg("Could not open file");
			set_goodbye();
			while(!goodbye());
		}
		else
			{
			OBJECT *obj;
			SEGMENT *s;
			long sx = 1, sy = 1, sz = 1;
#ifdef ENABLE_RESIZE_ON_LOAD
			askfor("Scale x,y,z: ", buff, 20);
			if (buff[0])
				sscanf(buff, "%ld,%ld,%ld", &sx, &sy, &sz);
			if (sx == 0) sx = 1;  if (sy == 0) sy = 1;  if (sz == 0) sz = 1;
#endif
			set_loadplg_offset(0,0,0);
			set_loadplg_scale(sx, sy, sz);
			obj = load_multi_plg(in);
			if (load_err) {
				popmsg(plg_errmsgs[-load_err]);
				reframe = redraw = 1;
				break;
			}
			select_representation(obj, 0L);
			add_obj_to_split_area(split_tree, obj);
			if ((s = new_seg(NULL)) == NULL)
			{
				popmsg("Warning -- out of memory!");
				set_goodbye();
				while(!goodbye());
			}
			else
				{
				seg_set_object(s, obj);
				set_object_owner(obj, s);
				mxosize = 0;
				walk_segtree(s, maxsize_it);
				compute_vpoint(&x, &y, &z, 500+mxosize*2);
				abs_move_segment(s, x, y, z);
				update_segment(s);
			}
		/*	if (spacestep < get_object_bounds(obj, &x, &y, &z)/5L)
				spacestep = get_object_bounds(obj, &x, &y, &z)/5L; */
			fclose(in);
		}
		reframe = redraw = 1;
		break;
	case 'S':
		refresh_display();
		if(check_obj()) break;
		if (askfor("Enter filename: ", buff, 20) == 0x1B) break;
		if (buff[0] == '\0')
		{
			reframe = redraw = 1;
			break;
		}
		nobjs = 0;
		add_ext(buff,"plg");
		if ((save_file = fopen(buff, "w")) == NULL)
		{
			popmsg("Could not create file");
			reframe = 1;
			set_goodbye();
			while(!goodbye());
			break;
		}
		nsaved = 0;
		walk_split_tree(split_tree, save_it);
		fclose(save_file);
		save_file = NULL;
		refresh_display();
		sprintf(buff, "Saved %d object%s", nselected, (nselected > 1) ? "s" : "");
		popmsg(buff);
		set_goodbye();
		while(!goodbye());
		fclose(out);
		break;
	case 'I':
		{
			seg_info(0);
			set_goodbye();
			while(!goodbye());
			break;
		}
	case 'D':
		refresh_display();
		if(check_obj()) break;
		sprintf(buff, "Delete %d object%s!  Are you sure?",
		nselected, (nselected > 1) ? "s" : "");
		popmsg(buff);
		reframe = 1;
/*		i = toupper(getch()); */
		set_goodbye();
		while(1)
		 {
		  i = goodbye();
		  i = toupper(i);
		  if(i) break;
		 }
/*		while((i=toupper(goodbye())==0); */
		if (i != 'Y') break;
		refresh_display();
		walk_split_tree(split_tree, nuke_it);
		refresh_display();
		break;
	case 'U':
		walk_split_tree(split_tree, unhi_it);
		refresh_display();
		break;
	case 'F':
		if(check_obj()) break;
		walk_split_tree(split_tree, first_it);
		break;
	case 'N':
		if(check_obj()) break;
		walk_split_tree(split_tree, next_it);
		break;
#ifdef ENABLE_DEPTHALTER
	case 'T':
		{
		if (check_obj()) break;
		sortflag = 0x0000;
		popmsg("sort by Object or Poly?");
		set_goodbye();
/*		i = toupper(getch()); */
/*		while((i=toupper(goodbye())==0); */
		while(1)
		 {
		  i = goodbye();
		  i = toupper(i);
		  if(i) break;
		 }
		if(i==1) goto gb;
		if (i == 'O') sortflag = BYOBJECT;
		if (!sortflag)
		 {
		  popmsg("sort by Deepest or Average?");
/*		i = toupper(getch()); */
/*		  while((i=toupper(goodbye())==0); */
		while(1)
		 {
		  i = goodbye();
		  i = toupper(i);
		  if(i) break;
		 }
		  if(i==1) goto gb;
		  if (i == 'A') sortflag |= AVERAGE;
		 }
		walk_split_tree(split_tree, sortflag_it);
           gb:
		reframe = redraw = 1;
		}
		break;
#endif
	default:
		break;
	}
	return 0;
}


/************** FIGURE MENU *************/

int fig_menu(void)
{
	char buff[100], *p;
	FILE *in, *out;
	char c, d;
	long x, y, z;
	int mx, my;

	refresh_display();

	switch (menu(figmenu))
	{
	case 'L':
		askfor("Figure file to read? ", buff, 15);
		if (buff[0] == '\0')
		{
			reframe = redraw = 1;
			break;
		}
		add_ext(buff,"fig");
		if ((in = fopen(buff, "r")) == NULL)
		{
			popmsg("Could not open figure file");
			set_goodbye();
			while(!goodbye());
		}
		else
			{
			SEGMENT *s;
			int c;
			while ((c = getc(in)) != '{')
				if (c == EOF)
				{
					popmsg("Early EOF!");
					  set_goodbye();
					while(!goodbye());
					break;
				}
			set_readseg_objlist(objlist);
			readseg_err = 0;
			if ((s = readseg(in, NULL)) == NULL)
			{
				popmsg(readseg_errmsgs[-readseg_err]);
				  set_goodbye();
				while(!goodbye());
			}
			else
				{
				mxosize = 0;
				walk_segtree(s, maxsize_it);
				compute_vpoint(&x, &y, &z, 1000+mxosize);
				abs_move_segment(s, x, y, z);
				update_segment(s);
			}
		}
		reframe = redraw = 1;
		break;
	case 'I':
		seg_info(1);
		set_goodbye();
		while(!goodbye());
		break;
	case 'S':
		if(check_moveobj()) break;
		walk_segtree(find_root_segment(last_figure), hilite_it); /* and down again */
		break;
	case 'U':
		walk_split_tree(split_tree, unhi_it);
		refresh_display();
		break;
	case 'H':
		if(check_moveobj()) break;
		refresh_display();
		walk_split_tree(split_tree, hack_it);
		break;
	case 'J':
		if (check_moveobj()) break;
		if (!can_point_2D()) break;
		if (!manip_2D_avail) break;
		refresh_display();
		popmsg("Click on new parent");
		reframe = 1;
		refresh_display();
		newparent = NULL;
		do
			{
			OBJECT *newobj;
			move_till_click(cursor_device, 1, &mx, &my);
			newobj = where_split_screen_pt(NULL, NULL, mx, my);
			if (newobj)
				if ((get_obj_flags(newobj) & OBJ_HIGHLIGHTED) == 0)
					newparent = get_object_owner(newobj);
		}
		while (newparent == NULL);
		walk_split_tree(split_tree, join_it);
		break;
	case 'A':
		if(check_moveobj()) break;
		connect_body(current_view, last_figure);
		break;
	case 'D':
		disconnect_body (current_view);
		if(!flymode)
		{
			current_view->roll = 0;
		}
		break;
	default:
		break;
	}
	return 0;
}



/***************** DISPLAY OPTIONS MENU ***************/

int disp_options(void)
{
	char buff[20];

	switch(menu(optmenu))
	{
	case 'M':
		animatemode = !animatemode;
		break;
	case 'B':
		fancy_background = !fancy_background;
		break;
	case 'R':
		reflection_pool = !reflection_pool;
		current_view->bottom = reflection_pool ? 160 : 200;
		break;
	case 'S':
		do_screen_clear = !do_screen_clear;
		popmsg(do_screen_clear ? "Will clear" : "Won't clear");
		do_screen_clear = !do_screen_clear;
		tdelay(600);
		refresh_display();
		refresh_display();
		refresh_display();
		do_screen_clear = !do_screen_clear;
		break;
	case 'D':
		current_view->directional = !current_view->directional;
		popmsg(current_view->directional ? "Spotlight" : "Point Source");
		tdelay(600);
		break;
	case 'H':
		do_horizon = !do_horizon;
		if (!do_horizon) reset_screens();
		popmsg(do_horizon ? "Horizon" : "No Horizon");
		tdelay(600);
		break;
	case 'A':
		askfor("Ambient light: ", buff, 15);
		current_view->ambient = atoi(buff) & 0x7F;
		break;
	case 'P':
		show_location = !show_location;
		if (!show_location) reset_screens();
		break;
	case 'C':
		show_compass = !show_compass;
		if (!show_compass) reset_screens();
		break;
	case 'F':
		show_framerate = !show_framerate;
		if (!show_framerate) reset_screens();
		break;
	default:
		break;
	}
	return 0;
}


/*************** PAINTING MENU OPERATIONS **********/

static unsigned stype[] = { 
	0, 0x1000, 0x2000, 0x3000 };

unsigned paint = 1;
static unsigned surface = 0x1000;
static unsigned paintcolor = 1;

void surf_it(OBJECT *obj)
{
	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		int nv, np, i;
		unsigned color;
		get_obj_info(obj, &nv, &np);
		for (i = 0; i < np; ++i)
		{
			get_poly_info(obj, i, &color, &nv, NULL, 0);
			set_poly_color(obj, i, (color & 0xCFFF) | (surface&0x3000) );
		}
	}
}

void color_it(OBJECT *obj)
{
	if (get_obj_flags(obj) & OBJ_HIGHLIGHTED)
	{
		int nv, np, i;
		get_obj_info(obj, &nv, &np);
		for (i = 0; i < np; ++i)
			set_poly_color(obj, i, 0x8000 | paint);
	}
}


unsigned int get_surface(void)
{
	reframe = 1;
	switch (menu(surfmenu))
	{
	case 'A':
		surface = stype[0];
		break;
	case 'C':
		surface = stype[1];
		break;
	case 'M':
		surface = stype[2];
		break;
	case 'G':
		surface = stype[3];
		break;
	default:
		return 1;
	}
	if (surface == 0) paint = paintcolor;
	else paint = (surface | ((paintcolor << 4) & 0x0FF0) + 10); /* hue, brightness *16 */
	refresh_display();
	while (bioskey(1)) bioskey(0); /* flush keyboard buffer */
	return 0;
}


int painting(void)
{
	int x, y, c, i;
	unsigned buttons;
	char buff[100];

	if (!can_point_2D()) return 3;

	reframe = 1;
	switch (menu(paintmenu))
	{
	case 'S':/* select surface */
		get_surface();
		break;

	case 'C':/* select color */
		if (!can_point_2D()) break;
		if (!manip_2D_avail) break;
		disp_palette();
		reframe = 1;
		do {
			move_till_click(cursor_device, 1, &x, &y);
		}
		while (y>128 || x>160);
		paintcolor = 16*(y/8) + x/10;
		if (surface == 0)
			paint = paintcolor;
		else
			paint = (surface | ((paintcolor << 4) & 0x0FF0) + 10); /* hue, brightness *16 */
		refresh_display();
		break;

	case 'G':
		refresh_display();
		do {
			if (kbhit()) break;
			while (move_2D(cursor_device, &x, &y, &buttons) == 0 && !kbhit());
			if (buttons & 0x01)
			{
				OBJECT *obj;
				int poly;
				obj = where_split_screen_pt(&poly, NULL, x, y);
				if (obj)
				{
					get_poly_info(obj, poly, &c, NULL, NULL, 0);
					c &= 0x7FFF;
					sprintf(buff,"Poly Color: 0x%04x", c);
					popmsg(buff);
					surface = c & 0xFF00;
					paintcolor = c & 0xFF;
					paint = c;
				}
				else popmsg ("No Poly Selected");
			}
			if(buttons!=1) refresh_display();
		}
		while (!(buttons&2));
		while (kbhit()) getch();
		break;

	case 'P':
		refresh_display();
		i = 0;
		while(1)
		{
			if (kbhit()) break;
			while (move_2D(cursor_device, &x, &y, &buttons) == 0 && !kbhit());
			if (buttons & 0x01)
			{
				OBJECT *obj;
				int poly;
				obj = where_split_screen_pt(&poly, NULL, x, y);
				if (obj)
				{
					set_poly_color(obj, poly, paint);
					refresh_display();
				}
			}
			else if (buttons & 0x02)
			{
				OBJECT *obj;
				int poly;
				i = 1;
				obj = where_split_screen_pt(&poly, NULL, x, y);
				if (obj)
				{
					get_poly_info(obj, poly, &c, NULL, NULL, 0);
					c &= 0x7FFF;
					sprintf(buff,"Poly Color: 0x%04x", c);
					popmsg(buff);
					surface = c & 0xFF00;
					paintcolor = c & 0xFF;
					paint = c;
				}
				else popmsg ("No Poly Selected");
			}
			else if (i) refresh_display();
		}
		while (kbhit()) getch();
		break;

	case 'R':
		refresh_display();
		if(get_surface()) break;
		walk_split_tree(split_tree, surf_it);
		refresh_display();
		break;

	case 'A':
		walk_split_tree(split_tree, color_it);
		refresh_display();
		break;
	default:
		break;
	}
	return 0;
}


/****************** MAIN MENU *************/

int main_menu(void)
{
	switch(menu(mainmenu))
	{
	case 'Q':
		do_key('Q');
		break;
	case 'I':
		do_key('I');
		break;
	case 'H':
		do_key('H');
		break;
	case 'O':
		do_key('O');
		break;
	case 'P':
		do_key('P');
		break;
	case 'F':
		do_key('F');
		break;
	case 'M':
		do_key('M');
		break;
	case 'D':
		disp_options();
		break;
	case 'V':
		view_menu();
		break;
	default:
		break;
	}
	return 0;
}


