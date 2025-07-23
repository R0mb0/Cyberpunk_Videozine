/* Written by Bernie Roehl, February 1992 */
/* Latest version (re)written Nov. 7 1992 */
/* by Dave Stampe for book release        */
/* Latest version (re)written Feb. 9 1993 */
/* by Bernie Roehl to add additional features */

/* Contact: broehl@sunee.waterloo.edu */
/* Dave Stampe : dstampe@sunee.uwaterloo.edu */
/*
   (c) 1992 by Dave Stampe and Bernie Roehl
   ATTRIBUTION:  If you use any part of this source code or the libraries
   in your projects, you must give attribution to REND386, Dave Stampe,
   and Bernie Roehl in your documentation, source code, and at startup
   of your program.  Let's keep the freeware ball rolling!
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>   /* toupper() */
#include <string.h>
#include <mem.h>     /* memmove() */
#include <dos.h>

#include "config.h"
#include "rend386.h"
#include "intmath.h"
#include "plg.h"
#include "segio.h"
#include "segasupp.h"
#include "splits.h"
#include "pointer.h"
#include "tasks.h"
#include "cursor.h"
#include "userint.h"
#include "f3dkitd.h"  /* for load_dac_colors() */

extern int animatemode;

extern unsigned _stklen = 10000; /* need lots of stack for recursion */
#define XFSC 536870912           /* 2**29 for shifting xform coeffs to <3.29> */

FILE *log_file = NULL;

/*************** VIEW DATA **************/

VIEW default_view = {
	0,0,-8000, /* ex,ey,ez */
	0,0,0, /* pan,tilt,roll */
	4*65536L, /* zoom */
	1000,15000,-5000, /* lx,ly,lz */
	0,63, /* point, ambient */
	0,319,0,200, /* left,right,top,bottom */
	1,100000, /* hither, yon */
	1/1.25*65536L, /* aspect ratio */
	0, /* flags */
	0,0, /* no offset */
	0 /* no flip */
}; /* don't init. matrix */

VIEW *current_view = &default_view;

VIEW orig_view; /* used for HOME     */
VIEW *current_home_view = &orig_view; /* camera being used */
VIEW real_view; /* camera xform data */


OBJLIST *objlist; /* the linked list of objects in the scene */

int running = 0; /* non-zero while we're in the main loop */
int redraw = 1; /* non-zero if we need a redraw */
int review = 1; /* non-zero if we need to recompute current view */
int reframe = 1; /* non-zero if we need to copy our frame back on-screen */
int v_page = 0; /* screen page swap variable */

/************* DRIVER INFORMATION **************/

extern struct Screeninfo *screeninfo;

char vdname[40] = "vd256.rvd";
int vdmode = 0x14;
int vd_loaded = 0;
extern highest_color;

char swdname[40] = "sega";

char mdname[40] = "mouse";
PDRIVER *cursor_device = NULL; /* primary mouse device   */
PDRIVER *menu_device = NULL; /* secondary mouse device */
int manip_2D_avail = 0; /* can do mouse manipulation */

char gpdname[40] = "pglove";
char gpcursor[40] = "./hand.fig";
float gpdo_x = 1, gpdo_y = 1, gpdo_z = 2, gpdo_rx = 1, gpdo_ry = 1, gpdo_rz = 1;
int have_glove = 0;
int have_ptr = 0;
PDRIVER *manip_device = NULL; /* extended manip. device (glove or pointer) */

char hdname[40] = "none";
float hdo_x = 0, hdo_y = 0, hdo_z = 0; /* relative pos'n to neck */
float hdo_rx = 0, hdo_ry = 0, hdo_rz = 0;
PDRIVER *head_device = NULL; /* head tracking device   */
int use_ht = 0;


MATRIX head_tracker_map = {
	XFSC, 0, 0, 0, XFSC, 0, 0, 0, XFSC, 0, 0, 0 };

int have_joystick = 0; /* non-zero if we have one or more joysticks */
joystick_data joy;

/************* STEREOSCOPIC DATA ***************/


STEREO default_stereo = {
	600 , 240, 320, 50, 600, 1*65536L };

int stereo_type = MONOSCOPIC;

int sl_xflip = 0, sl_xoff = 0;
long sl_left = -1, sl_top, sl_right, sl_bottom;
int sr_xflip = 0, sr_xoff = 0;
long sr_left = -1, sr_top, sr_right, sr_bottom;
float sl_xrot = 0, sr_xrot = 0;

/************ OPTIONS FLAGS ***************/

int use_BW = 0;
int swap_eyes = 0;
int use_glove = 0;

SEGMENT *preconnect_view_seg = NULL; /* if view is to be preconnected */

extern int floormode;
int do_horizon = 1;
extern int spinmode;
int fancy_background = 0; /* if set, we display a fancy background */
int reflection_pool = 0; /* if set, draw a "reflecting pool" at the bottom of the screen */
int have_logo = 0; /* if set, we have a logo */
int show_logo = 0; /* if set, show the logo (if we have one) */
int show_location = 1; /* if set, we display the current location on-screen */
int show_compass = 1; /* if set, we display the 3-D compass on-screen */
int show_framerate = 1; /* if set, we display the frames/second rate */
int do_screen_clear = 1; /* by default, we clear the screen on each frame */
int use_frame = 0; /* if set, draw a "frame" */


/************ MISC. COMMUNICTION *************/

int frame_x = 0, frame_y = 0, frame_w = 320, frame_h = 200; /* frame location */

extern SEGMENT *light_seg;
extern long light2_x, light2_y ,light2_z;

TASK *tasklist = NULL;

SPLIT *split_tree = NULL;

extern void *temp_mem;
extern long temp_size;

long floor_y = 0;
long old_floor_y = 0;

int npalette = 0; /* non-zero if we have a palette loaded */
unsigned char palette[256*3];

char framefname[100];

extern long spacestep;  /* "granularity" of motion */

unsigned lastkey = 0, nextolastkey = 0;
char *progname = "REND386";


/************** LOAD SUPPORT *************/

static char tempname[100];
char loadpath[100] = "";

char *fix_fname(char *name)
{
	if (loadpath[0] && !strchr(name, '\\') && !strchr(name, '/'))
		sprintf(tempname, "%s\\%s", loadpath, name);
	else
		strcpy(tempname, name);
	return tempname;
}

void *v_driver_pointer = NULL;

void load_video_driver(char *dfile)
{
	v_driver_pointer = load_driver(dfile);
	if (v_driver_pointer == NULL)
	{
		fprintf(stderr,"Cannot read video driver %s\n", dfile);
		exit(0);
	}
}



/**********  MAIN LOOP  ************/

void main_loop(void)
{
void wrap(void); /* wrap-up function, shuts everything down */
void joystick_calibration(joystick_data *joy), refresh_display(void);


	while (running)
	{
		int x, y;
		unsigned buttons;

		old_floor_y = floor_y;
		{
			AREA *a;
			long x,y,z;
			real_viewpoint(&real_view, &x, &y, &z);
			a = what_area(split_tree, x, y, z);
			if (a)
			{
				floor_y = floor_at(a, x, z);
				if (floor_y == 0x7FFFFFFFL) floor_y = old_floor_y;
			}
			else floor_y = old_floor_y;
		}

		if (mouse_joy(&joy)) do_joy(&joy);
		else
			{
			if (cursor_device)
				if (move_and_select_2D(cursor_device) == -1) do_key('X');
			if (have_joystick && joystick_read(&joy)) do_joy(&joy);
		}

		if (animatemode==-1) animatemode = 0; /* single step OFF */

		if (bioskey(1))
		{
			nextolastkey = getkey();
			while(bioskey(1)) getkey();
			do_key(nextolastkey);
			lastkey = nextolastkey;
		}

		if (floormode) current_view->ey += floor_y - old_floor_y;

		if (head_device && use_ht) head_update(0);

		if (use_glove)
		{
			POINTER gp;
			int g;

			if (!have_ptr)
			{
				glove_update(manip_device, &gp);
				switch(gp.gesture)
				{
				case G_FIST :
					g = GRASP_DO;
					break;
				case G_PINCH:
					g = ROTATE_DO;
					break;
				case G_POINT:
					g = SELECT_DO;
					break;
				default:
					g = FREE_DO;
					break;
				}
			}
			else
				{
				cursor_update3D(manip_device, &gp);
				switch(gp.buttons)
				{
				case 2:
					g = GRASP_DO;
					break;
				case 3:
					g = ROTATE_DO;
					break;
				case 1:
					g = SELECT_DO;
					break;
				default:
					g = FREE_DO;
					break;
				}
			}

			manip_do(manip_device,g);
		}

		if (animatemode)
		{
			run_tasks(tasklist);
#ifdef ENABLE_STATEMACH
			do_animations();
#endif
			if (light_seg) seg_getposxyz(light_seg, &light2_x, &light2_y, &light2_z);
		}

		if (redraw) refresh_display();
	}

}

/************** MAIN PROGRAM ***************/

void main(int argc, char *argv[])
{
	OBJECT *obj;
	void wrap(void); /* wrap-up function, shuts everything down */
	void joystick_calibration(joystick_data *joy), refresh_display(void);
	long x, y, z;
	FILE *in;
	int i;
	PDRIVER *dm;
	POINTER *p;
	char *fname; /* environment setup */

	if ((progname = strrchr(argv[0], '.')) != NULL) *progname = '\0';
	progname = argv[0];

	if (getenv("REND386"))
		strcpy(loadpath, getenv("REND386"));


	/* Create the MATRIX rep of your computer!!! */

	printf("Scanning System...");
	create_matrix();


	printf("Loading Up...");
	//title_screen();
	/* renderer setup */

	temp_mem = setup_render(55,1000); /* # of K, # of polys */
	temp_size = 55000L;
	atexit(wrap);
#ifdef ENABLE_STATEMACH
	create_default_segs(); /* for animations */
#endif
	set_global_split_root(&split_tree);
	initial_world_split(&split_tree);
	set_move_handler(split_move_handler);
	objlist = new_objlist();
	/* configuration file loading */
	i = 1;
	if ((!stricmp(&(argv[1][0]), "/C"))||(!stricmp(&(argv[1][0]), "-C")))
	{
		i = 2;
		fname = &(argv[2][0]);
	}
	else fname = "rend386.cfg";

	if ((in = fopen(fname, "r")) == NULL){}
	       //fprintf(stderr, "Note -- config file '%s' not found; using defaults.\n", fname);
	else
		{
		if (read_world(in))
			fprintf(stderr, "Error reading config file '%s'\n", fname);
		fclose(in);
	}
			/* preload video driver to set defaults */
	load_video_driver(vdname);
	screeninfo = screen_data();
	highest_color = screeninfo->colors-1;
	preset_default_colors();

	frame_x = screeninfo->xmin;
	frame_y = screeninfo->ymin;
	frame_w = screeninfo->xmax - screeninfo->xmin + 1;
	frame_h = screeninfo->ymax - screeninfo->ymin + 1;

			/* Default view is full-screen: */
	default_view.left = screeninfo->xmin;
	default_view.top = screeninfo->ymin;
	default_view.right = screeninfo->xmax;
	default_view.bottom = screeninfo->ymax;
	default_view.aspect = screeninfo->aspect;

	for (; i < argc; ++i)
	{
		if (argv[i][0] == '/' || argv[i][0] == '-')
		{
			switch(toupper(argv[i][1]))
			{
			case 'L':/* log file */
				{
				 char *lf;
				 if (argv[i][2]) lf = &argv[i][2];
				 else lf = argv[++i];
				 log_file = fopen(lf, "w");
				 if (log_file == NULL)
				  {
				   fprintf(stderr, "Could not open log file '%s'\n", lf);
				   exit(2);
				  }
				}
				break;
			case 'M':/* disable MS mouse */
				mdname[0] = 0;
				break;
			case 'R':/* swap eyes on Sega driver */
				swap_eyes = 1;
				break;
			case 'D':/* set conv. distance */
				default_stereo.phys_screen_dist = atol(argv[++i]);
				break;
			case 'S':/* set world scale */
				default_stereo.world_scaling = 65536.0*atof(argv[++i]);
				break;
			case 'E':/* set eye spacing */
				default_stereo.phys_eye_spacing = atol(argv[++i]);
				break;
			case 'X':/* turn on stereo */
				stereo_type = SWITCHED;
				break;
			case 'J':/* sort by object (default is polys) */
				set_default_depth_sort(get_default_depth_sort() | BYOBJECT);
				break;
			case 'P':/* depth sort-- deepest */
				set_default_depth_sort(get_default_depth_sort() & (~(BYOBJECT|AVERAGE|ATBACK)));
				break;
			case 'A':/* depth sort-- middle */
				set_default_depth_sort(get_default_depth_sort() | AVERAGE);
				break;
			case '1':/* com 1 for SEGA */
				select_sega_port(0x3FC);
				break;
			case '2':/* com 2 for SEGA */
				select_sega_port(0x2FC);
				break;
			case 'G':/* enable glove */
				use_glove = 1;
				if (!have_ptr) have_glove = 1;
				break;
			case 'H':/* enable head tracker */
				use_ht = 1;
				break;
			case 'B':/* force all colors to monochrome */
				use_BW = 1;
				break;
			}
		}

/*	       else
			{
			char *in_filename;



			in_filename = fix_fname(argv[i]);

			if ((in = fopen(in_filename, "r")) == NULL)
				fprintf(stderr, "Could not open '%s'\n", in_filename);
			else if (strstr(in_filename,".plg")) // check if plg or fig file
			{
				set_loadplg_offset(0,0,0);
				set_loadplg_scale(1,1,1);
				while ((obj = load_plg(in)) != NULL)
				{
					SEGMENT *s;
					add_to_objlist(objlist, obj);
					if ((s = new_seg(NULL)) == NULL)
						fprintf(stderr, "Warning: out of memory while loading an object\n");
					else
						{
						seg_set_object(s, obj);
						set_object_owner(obj, s);
						update_segment(s);
					}
//			if (spacestep < get_object_bounds(obj, &x, &y, &z)/5L)
//					spacestep = get_object_bounds(obj, &x, &y, &z)/5L;
				}
				if (load_err)
				{
					fprintf(stderr, "Load error: %s in file '%s'\n", plg_errmsgs[-load_err], in_filename);
					if (log_file)
						fprintf(log_file, "%s on line %d of file %s\n", plg_errmsgs[-load_err], err_line, in_filename);
					getkey();
				}
			}
			else if (strstr(in_filename,".fig")) // check if plg or fig file
			{
				SEGMENT *s;
				int c;
				set_readseg_objlist(objlist);
				readseg_err = 0;
				if ((s = readseg(in, NULL)) == NULL)
					if (readseg_err && log_file) {
						fprintf(log_file, "%s while reading figure file '%s'\n", readseg_errmsgs[-readseg_err], argv[i]);
						fprintf(stderr, "%s while reading figure file '%s'\n", readseg_errmsgs[-readseg_err], argv[i]);
					}
				else
					update_segment(s);
			}
			else
				{
				if (read_world(in)) {
					fprintf(stderr, "Error reading world file\n");
					if (log_file)
						fprintf(log_file, "Error while reading world file\n");
				}
			}
			fclose(in);
		}           */
	}


/*  Read in the Matrix World  */

	if ((in = fopen("matrix.wld", "r")) == NULL){
		fprintf(stderr, "Could not open 'MATRIX.WLD'\n");
		exit(1);
	}
	if (read_world(in)) {
		fprintf(stderr, "Error reading world file\n");
		exit(1);
		if (log_file)
		   fprintf(log_file, "Error while reading world file\n");
	}
	fclose(in);


	dump_lists(); /* get rid of temps used by world loader */

	/* end of world loading: now process the driver stuff */

	have_joystick = joystick_check();

	//wait_for_title();

	if (enter_graphics())
	{
		fprintf(stderr, "Could not enter graphics mode\n");
		exit(1);
	}
	vd_loaded++;

	frame_x = screeninfo->xmin; /* reload in case driver changed it */
	frame_y = screeninfo->ymin;
	frame_w = screeninfo->xmax - screeninfo->xmin + 1;
	frame_h = screeninfo->ymax - screeninfo->ymin + 1;

	/* Default view is full-screen: */
	default_view.left = screeninfo->xmin;
	default_view.top = screeninfo->ymin;
	default_view.right = screeninfo->xmax;
	default_view.bottom = screeninfo->ymax;
	default_view.aspect = screeninfo->aspect;


	initialize_screen_factors(current_view);
	fast_view_factors(current_view);

	if (npalette)
		load_DAC_colors(palette, highest_color+1, use_BW);

	if (use_frame)
	{
		FILE *in;
		char *f;
		use_frame = 0; /* we only set it back to 1 if we're successful */
		if (stereo_type == MONOSCOPIC)
			if ((in = fopen(f = fix_fname(framefname), "rb")) != NULL)
			{
				if (load_pcx(in, 3) == 0) use_frame = 1;
				copy_block(3, 0, 0, 0, frame_x, frame_y, frame_w, frame_h);
				copy_block(3, 0, 0, 1, frame_x, frame_y, frame_w, frame_h);
				copy_block(3, 0, 0, 2, frame_x, frame_y, frame_w, frame_h);
				fclose(in);
			}
		else {
			char tbuff[100];
			sprintf(tbuff, "Could not open '%s'", f);
			if (running)
				popmsg(tbuff);
			else
				fprintf(stderr, "%s\n", tbuff);
			if (log_file)
				fprintf(log_file, "%s\n", tbuff);
		}
	}

	init_body_links();

	if (stereo_type != MONOSCOPIC)
	{
		init_switch_driver(swdname);

		if (sl_left<0)
		{
			sl_left = default_view.left;
			sl_right = default_view.right;
			sl_top = default_view.top;
			sl_bottom = default_view.bottom;
		}
		compute_stereo_data(&default_stereo, 0, sl_xflip, sl_xoff, 65536.0*sl_xrot,
		sl_left, sl_top, sl_right, sl_bottom);

		if (sr_left<0)
		{
			sr_left = default_view.left;
			sr_right = default_view.right;
			sr_top = default_view.top;
			sr_bottom = default_view.bottom;
		}
		compute_stereo_data(&default_stereo, 1, sr_xflip, sr_xoff, 65536.0*sr_xrot,
		sr_left, sr_top, sr_right, sr_bottom);
	}

	orig_view = default_view;
	real_view = default_view;

	if (stricmp(hdname,"none") && use_ht)
	{
		extern PDRIVER *init_head_device(char *name, long x, long y, long z, long rx, long ry, long rz);
		head_device = init_head_device(hdname, hdo_x, hdo_y, hdo_z,
			hdo_rx*65536.0, hdo_ry*65536.0, hdo_rz*65536.0);
	}

	if ((dm=mouseptr_init(mdname))!=NULL)
	{
		cursor_show(v_page);
		manip_2D_avail++;
	}
	cursor_device = dm;
	menu_device = dm;

	if ((!use_glove) || have_ptr || stricmp(gpdname,"pglove"))
		/* not going to be using powerglove */
	{
		if (stereo_type==SWITCHED)
			init_SG_interrupt(switch_sega,NULL,6500);
		else init_timer();
	}

	if (use_glove && (!have_ptr))
	{
		extern SEGMENT *body_seg;
		PDRIVER *gd;
		extern PDRIVER *gloveptr_init(char *gname, long sx, long sy, long sz, long srx, long sry, long srz);

		gd = gloveptr_init(gpdname, gpdo_x*65536.0, gpdo_y*65536.0, gpdo_z*65536.0,
		gpdo_rx*65536.0, gpdo_ry*65536.0, gpdo_rz*65536.0);
		manip_device = menu_device = gd;
		if (gd) {
			set_readseg_scale(1.0,1.0,1.0);
			switch (load_glove_cursor(body_seg, manip_device, fix_fname(gpcursor))) {
			case 0:
				break; /* all is well */
			case -1:
				popmsg("Could not open glove cursor file");
				getkey();
				if (log_file)
					fprintf(log_file, "Could not open glove cursor file '%s'\n", fix_fname(gpcursor));
				have_glove = use_glove = 0;
				break;
			case -2:
				popmsg("Error while loading glove cursor");
				getkey();
				if (log_file)
					fprintf(log_file, "Error while loading glove cursor file '%s'\n", fix_fname(gpcursor));
				have_glove = use_glove = 0;
				break;
			default:
				popmsg("Unknown error loading glove cursor");
				getkey();
				if (log_file)
					fprintf(log_file, "Unknown error while loading glove cursor file '%s'\n", fix_fname(gpcursor));
				have_glove = use_glove = 0;
				break;
			}
		}
		else have_glove = use_glove = 0;
	}

	if (use_glove && have_ptr)
	{
		extern SEGMENT *body_seg;
		PDRIVER *gd;
		extern PDRIVER *gloveptr_init(char *gname, long sx, long sy, long sz, long srx, long sry, long srz);

		gd = gloveptr_init(gpdname, gpdo_x*65536.0, gpdo_y*65536.0, gpdo_z*65536.0,
		gpdo_rx*65536.0, gpdo_ry*65536.0, gpdo_rz*65536.0);
		manip_device = menu_device = gd;
		if (gd)
		{
			set_loadplg_offset(0, 0, 0);
			set_loadplg_scale(1, 1, 1);
			switch (load_3D_cursor(body_seg, manip_device, fix_fname(gpcursor))) {
			case 0:
				break; /* all is well */
			case -1:
				popmsg("Could not open 3D cursor file");
				getkey();
				if (log_file)
					fprintf(log_file, "Could not open 3D cursor file '%s'\n", fix_fname(gpcursor));
				have_glove = use_glove = 0;
				break;
			case -2:
				popmsg("Error while loading 3D cursor");
				getkey();
				if (log_file)
					fprintf(log_file, "Error while loading 3D cursor file '%s'\n", fix_fname(gpcursor));
				have_glove = use_glove = 0;
				break;
			default:
				popmsg("Unknown error loading 3D cursor");
				getkey();
				if (log_file)
					fprintf(log_file, "Unknown error while loading 3D cursor file '%s'\n", fix_fname(gpcursor));
				have_glove = use_glove = 0;
				break;
			}
		}
		else have_ptr = use_glove = 0;
	}

	if ((have_joystick) != 0)
	{
		joystick_calibration(&joy);
	}

	{
		extern char *title[];
		long j;

		if (title[0])
		{
			refresh_display();
			poptext(title);
			j = current_time();
			while ((current_time()-j) < 330)
			{
			 if (goodbye()) break;
			}
			while (kbhit()) getch();
			refresh_display();
		}
	}

	if (preconnect_view_seg)
		connect_body(current_view, preconnect_view_seg);

	running = 1;
	main_loop();
}


static char *closing_msg[] = {
	"MATRIX by: Todd Porter",
	"Thank you for using the MATRIX!!",
	"The MATRIX source code has been provided in hope",
	"that others would join in the effort in developing the",
	"system. I would also like to thank Bernie Roehl and Dave Stampe",
	"for providing the base rendering code (99% of the code <G>)",
	"Hope to hear from everyone!  I can be reached at:",
	"C$erve: 76505,1574",
	"Internet: porter@gate.net ---> preferred",
	NULL };


void wrap(void) /* end program */
{
	int i;

	if (have_joystick) joystick_quit();
	if (vd_loaded) exit_graphics();
	reset_render();

	for (i = 0; closing_msg[i]; ++i)
		fprintf(stderr, "%s\n", closing_msg[i]);

	if (log_file) fclose(log_file);
	exit(0);
}


void refresh_display()
{
	if (spinmode) polar_compute();

	initialize_screen_factors(current_view);

	body_centric_map(current_view, &real_view);
	screen_refresh(&real_view);

	redraw = 0;
}


load_logo(char *filename)
{
	char far *buffer;
	FILE *in;
	char *f;
	if ((in = fopen(f = fix_fname(filename), "rb")) == NULL) {
		char tbuff[100];
		sprintf(tbuff, "Could not open '%s'", f);
		if (running)
			popmsg(tbuff);
		else
			fprintf(stderr, "%s\n", tbuff);
		if (log_file)
			fprintf(log_file, "%s\n", tbuff);
		return 0;
	}
	if (load_pcx(in, 3)) { /* some sort of problem loading it in */
		fclose(in);
		return 0;
	}
	fclose(in);
	return 1; /* all is well... we have a logo */
}

int resize_viewport(void)
{
	int top, left, bottom, right;
	unsigned buttons;
	cursor_hide();
	clear_display(v_page);
	cursor_show(v_page);
	popmsg("Click top-left and drag");

	do {
		move_2D(cursor_device, &left, &top, &buttons);
		if(kbhit())
		 {
		  getch();
		  refresh_display();
		  return 1;
		 }
	}
	while (buttons == 0);
	while (buttons) {
		while (!move_2D(cursor_device, &right, &bottom, &buttons));
		clear_display(v_page);
		vgabox(left, top, right, bottom, 15);
	}
	if (right - left > 10) {
		current_view->left = left & (~0x0007); /* always on a 16-pixel boundary */
		current_view->right = (right & (~0x0007)) + 7;
	}
	if (bottom - top > 10) {
		current_view->top = top;
		current_view->bottom = bottom;
	}

	if (stereo_type == SWITCHED) /* makes sense for Sega only (no shift) */
	{
		compute_stereo_data(&default_stereo, 0, sl_xflip, sl_xoff, 65536.0*sl_xrot,
		current_view->left, current_view->top, current_view->right, current_view->bottom);
		compute_stereo_data(&default_stereo, 1, sr_xflip, sr_xoff, 65536.0*sr_xrot,
		current_view->left, current_view->top, current_view->right, current_view->bottom);
	}

	/* Make sure all pages are refreshed: */
	reset_screens();
	refresh_display();
	return 0;
}

int save_pcx_file(void)
{
	char filename[100];
	char far *buffer;
	FILE *out;
	refresh_display();
	askfor("File to save to? ", filename, 15);
	reframe = 1;
	if (filename[0] == '\0') return 1;
	refresh_display();
	if ((out = fopen(filename, "wb")) == NULL) {
		popmsg("Could not open file");
		reframe = 1;
		getkey();
		return 3;
	}
	cursor_hide();
	save_pcx(out, v_page);
	cursor_show(v_page);
	fclose(out);
	return 0;
}


int screendump(void) /* alt-F10 */
{
	char filename[30] = "scrn0000.pcx";
	char far *buffer;
	FILE *out;
	int i;

	for (i = 0; i < 30; i++) /* find a screendump number */
	{
		sprintf(filename,"scrn%c%d.pcx",
		stereo_type==SWITCHED ? 'L' : '_' , i+1);
		if ((out=fopen(filename,"rb"))==NULL) goto doit;
		fclose(out);
	}
	return 3;

doit:
	if(stereo_type!=SWITCHED)
	 {
	  if ((out = fopen(filename, "wb")) == NULL) return 3;
	  save_pcx(out, v_page);
	  fclose(out);
	  return 0;
	 }
	else
	 {
	  filename[4] = 'L';
	  if ((out = fopen(filename, "wb")) == NULL) return 3;
	  save_pcx(out, left_page);
	  fclose(out);
	  filename[4] = 'R';
	  if ((out = fopen(filename, "wb")) == NULL) return 3;
	  save_pcx(out, right_page);
	  fclose(out);
	  return 0;
	 }
}

/* Some support routines */


void joystick_calibration(joystick_data *joy)
{
	if (have_joystick == 0) return;
	if (have_joystick & 1) joystick_init(joy, 0);
	else if (have_joystick & 2) joystick_init(joy, 1);

	joystick_setscale(joy, 100);
	reframe = 1;
}

extern AREA *areas;

extern POINTER gloveptr;

char *gest[] = {
	"FLAT", "THUMB_IN", "INDEX_IN", "MIDDLE_IN",
	"RING_IN", "PINCH", "FIST", "THUMB_OUT", "POINT",
	"BADFINGER", "RING_OUT", "??????" };

void prprint(int x,int y, int color, char *t)
{
	int bk = (color>8) ? 0 : 15;

	printxyr(x,y,bk,t,0);
	printxyr(x+1,y+1,color,t,0);
}

int status_on_screen(void)
{
	char buff[100];
	AREA *a, *what_area();
	long floor_at(), ceiling_at();
	long x, y, z;

	if (show_location == 0) return 0;
	real_viewpoint(&real_view, &x, &y, &z);

	sprintf(buff, "Pos(x,z): %ld,%ld", x, z);
	prprint(2,3,15,buff);
	sprintf(buff, "Not in any area");
	a = what_area(split_tree, x, y, z);
	if (a)
	{
		char *p = area_name(a);
		if (p)
		{
			sprintf(buff, "Area: %s", p);
			prprint(2,15,15,buff);
		}
	}

	if (use_glove && manip_device) /* prevent pre-init call */
	{
		int sl;
		POINTER p;
		extern PDRIVER *manip_device;

		last_pointer(manip_device, &p);
		sl = p.gesture;
		if (sl<0 || sl>G_UNKNOWN) sl = G_UNKNOWN;
		sprintf(buff,"Glove: %s",gest[sl]);
		sl = strlen(buff)<<3;
		prprint(300-sl,3,15,buff);
	}
	return 0;

}

