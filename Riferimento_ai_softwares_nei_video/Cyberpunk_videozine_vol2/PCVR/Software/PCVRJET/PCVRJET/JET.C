/* This program requires Release 4.01 of Rend386 to compile */
/* This program is COPYRIGHTED by Gradecki Publishing and PCVR */
/* ANY commercial distribution must be authorized by said companies */


#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include "rend386.h"
#include "userint.h"
#include "plg.h"
#include "splits.h"
#include "tasks.h"
#include "pointer.h"
#include "cursor.h"
#include "segasupp.h"
#include "segio.h"
#include "intmath.h"

#define to_rad(a) ((a) * 3.14159262 / 180.0)
#define sine(x)   sin(to_rad(x/65536L))
#define cosine(x) cos(to_rad(x/65536L))


/* Global variables */
/* This is our main object list.
   Files used:  keyboard, world, cursors
*/
OBJLIST  	*objlist;

/* This is the default values for stereo viewing.
   Files used:  keyboard, world, render
*/
STEREO 		default_stereo = {600,240,320,50,600, 1*65536L};

/* This variable indicates the type of viewing.
   Declared in file: render.c
   Files used: keyboard, gloveptr, world, render
*/
int         stereo_type = MONOSCOPIC;

/* This variable declares the default startup view of the program.
   Files used: keyboard, world
*/
VIEW 		default_view =  {
				0,0,0,
				0,0,0,
				9*65536L,
				1000,15000,-5000,
				0,319,0,199,
				1,100000,
				1/1.25*65535L,
				0
				};

/* This pointer points to the location of the default view
   Files used: keyboard, world, render
*/
VIEW     	*current_view = &default_view;

/* This pointer in the beginning of the split tree for the program.  We
   will only one however, that is not a requirement.
   Files used: keyboard, world, render, cursors, hdmanip
*/
SPLIT           *split_tree = NULL;

/* This variable holds a palette.
   Files used: world
*/
unsigned char 	palette[256*3];

/* This pointer is the start of a set of tasks.
   Files used: world
*/
TASK 		*tasklist = NULL;

/* This pointer holds a handle to the current video driver installed.
   Files used: main program
*/
void		*v_driver_pointer = NULL;

/* This variable holds a loadpath specified in the configuration file or
   in a world file.
   Files used: world
*/
char 		loadpath[100] = "";

/* This variable holds a temporary filename including a loadpath.
   Files used: main program
*/
static char 	tempname[100];


char 		framefname[100];

/* Delcares an extern function. */
extern void 	*screen_data();

/* This variable is used to hold information about the current screen setup.
   File used: gloveptr, mouseptr, render, userint
*/
extern struct 	Screeninfo *screeninfo;

/* This variable is used in the userint file.  Purpose ?
*/
PDRIVER 	*menu_device = NULL;
PDRIVER		*manip_device = NULL;

/* These variable are used as the configuration settings for the glove
   pointer device, translation and rotation.
   Files used: world
*/
float 		gpdo_x = 0.1, gpdo_y = 0.1, gpdo_z = 0.1,
		gpdo_rx = 1, gpdo_ry = 1, gpdo_rz = 1;

/* These varaiables are used as the configuration settings for the head
   tracker device, relative position to neck, and rotation. */
float 		hdo_x = 0, hdo_y = 0, hdo_z = 0; /* relative pos'n to neck */
float 		hdo_rx = 0, hdo_ry = 0, hdo_rz = 0;

/* These variables are used as the configuration settings for the STEREOLEFT
   command in a world file.  Check world.doc for description.
   Files used: world keyboard
*/
int 		sl_xflip = 0, sl_xoff = 0;
long 		sl_left = -1, sl_top, sl_right, sl_bottom;

/* These variables are used as the configuration settings for the
   STEREORIGHT command in a world file.  Check world.doc for description.
   Files used: world keyboard
*/
int 		sr_xflip = 0, sr_xoff = 0;
long 		sr_left = -1, sr_top, sr_right, sr_bottom;

/* These variables are used as the configuration settings for the rotation
   of the STEREORIGHT and STEREOLEFT commands in the world file.  Check
   world.doc for description.
   Files used: world keyboard.
*/
float 		sl_xrot = 0, sr_xrot = 0;

/* This variable indicates whether or not a glove is being used.
   0 = false.
   Files used: cursors hdmanip
*/
int 		use_glove = 1;

/* This variable indicates whether or not a head tracker is being used.
   0 = false.
   Files used: render
*/
int 		use_ht = 0;

/* This variable indicates whether or not a wide-angle dual VGA
   head mounted display system is being used.
   0 = false.
   Files used: render
*/
int 		use_wide = 0;

/* This variable indicates whether or not a monochrome system is being used.
   0 = false.
   Files used: render
*/
int 		use_BW = 0;

/* This variable is set to 1 if the eyes are to be switched when using
   the Sega 3D glasses.
   Files used: render
*/
int 		swap_eyes = 0;

/* This variable is set to display a fancy background
   Files used: keyboard render
*/
int 		fancy_background = 0;

/* This variable is set to draw a reflection pool at the bottom of the
   screen.
   Files used: keybaord render
*/
int 		reflection_pool = 0;

/* This variable is set to indicate we have a logo to display.
   Files used: render
*/
int 		have_logo = 0;

/* This variable is set to show our logo, if we have one.
   Files used: render keyboard
*/
int 		show_logo = 0;

/* This variable is set to show the current location on-screen.
   Files used: render keyboard
*/
int 		show_location = 0;

/* This variable is set to show the 3D compass on-screen.
   Files used: render keyboard
*/
int 		show_compass = 0;

/* This variable is set to display the frames/second rate on-screen.
   Files used: render keyboard
*/
int 		show_framerate = 0;

/* This variable is set to clear the screen on each frame.
   Files used: render world keyboard
*/
int 		do_screen_clear = 1;

/* This variable is set to draw a "frame".
   Files used: world render
*/
int 		use_frame = 0;

/* These variabels define the location of a "frame".
   Files used: world render
*/
int 		frame_x = 0, frame_y = 0, frame_w = 320, frame_h = 200;

/* This variable is set to the current display mode to use.
   Files used: render world
*/
int		vdmode = 0x14;

/* This variable is set to 1 if we need to recompute the current view.
   Files used: world keyboard
*/
int 		review = 1;

/* This variable is set to 1 if we need to copy our gram back on-screen.
   Files used: keyboard world colormap render rendrep
*/
int 		reframe = 0;


/* This variable is set if the shift key is used by the user.
   Files used: main program keyboard
*/
int 		shifted = 0;

/* This variable is used to hold the current visual page being used.
   Files used: render userint
*/
int		v_page = 0;

/* This variable is set if a glove is available.
   Files used: world cursors
*/
int 		have_glove = 1;

/* This variable is set if a pointer device is available.
   Files used: world cursors
*/
int 		have_ptr = 0;

/* This variable is set if we can do mouse manipulations.
   Files used: keyboard
*/
int 		manip_2D_avail = 0;

/* This variable is set to run the main execution loop.
   Files used: main
*/
int             execution = 1;

/* This variable is set to indicate a screen redraw is necessary.
   Files used: keyboard anim world cursors render hdmanip
*/
int		redraw = 1;

/* This variable is set if a horizon should be drawn.
   Files used: keyboard render colormap
*/
int		do_horizon = 1;

/* This variable is not necessary because it is define elsewhere and can
   be set with a world file.  It is the color the system paints the top
   half of the screen after it is cleared; if the do_horizon variable is
   set to 1.
   Files used: world render colormap
*/
extern 		sky_color;

/* This variable is not necessary because it is define elsewhere and can
   be set with a world file.  It is the color the system paints the bottom
   half of the screen after it is cleared; if the do_horizon variable is
   set to 1.
   Files used: world render colormap
*/
extern		ground_color;

/* This variable is not necessary because it is define elsewhere and can
   be set with a world file.  It is the color the system paints the screen
   after it is cleared; if the do_horizon variable is set to 0.
   Files used: world render colormap
*/
extern int      screen_clear_color;


/* This variable holds the highest possible color value.
   Files used: render colormap
*/
extern 		highest_color;

/* This variable is set to 0 if no palette is loaded and
   non-zero if a palette is loaded
   Files used: world
*/
int 		npalette = 0;

/* This variable holds the name of the current switcher driver.
   Files used: world
*/
char 		swdname[40] = "sega";

/* This variable holds the name of the current glove pointer driver.
   Files used: world
*/
char 		gpdname[40] = "pglove";

/* This variable holds the name of the current head tracker driver.
   Files used: world
*/
char 		hdname[40] = "none";

/* This variable holds the name of the glove pointer driver cursor figure.
   Files used: world
*/
char 		gpcursor[40] = "handsm.fig";

/* This variable holds the name of the current video driver.
   Files used: main program and world
*/
char            vdname[40] = "vd256.rvd";

/* This variable holds the name of the current mouse driver.
   Files used: world
*/
char            mdname[40] = "none";

int head_device = 0;
extern SEGMENT *body_seg;
joystick_data joy_data;
int joy_return = 0;
int jet_speed = 5;
int fire_distance = 100;
OBJECT *finger_tip, *palm, *but1, *but2, *but3, *yoke_obj;
SEGMENT *yoke;

/**************************************************************************
   This function is used by the file render.c to display various things
   on the screen to the user.  This is not needed by any program just
   an option.  However, render.c needs access to this function
***************************************************************************/
void status_on_screen()
{
}


/**************************************************************************
   This function concatenates the loadpath to the string name IF
   name is not "\\" and not "/" and loadpath is not empty.  It is used by
   the files: world.c.
**************************************************************************/
char *fix_fname(char *name)
{

	if (loadpath[0] && !strchr(name, '\\') && !strchr(name, '/'))
		sprintf(tempname, "%s\\%s", loadpath, name);
	else
		strcpy(tempname, name);
	return tempname;
}


/**************************************************************************
  This function is called when the user ends the graphics program.  It
  shuts done the graphics system and exits the renders and finally exits
  the progam.
**************************************************************************/
void closeall(){
  exit_graphics();
  reset_render();
  exit(0);
}

/**************************************************************************
  This function performs the updating of the screen after any object or
  perspective movements.  The majority of the work is done in the
  function screen_refresh in the file render.c
**************************************************************************/
void refresh_display(){

  initialize_screen_factors ( current_view );
  fast_view_factors ( current_view );
  screen_refresh ( current_view );

}


/**************************************************************************
   This function is from Rend386 demo2.c program and is used to get
   keyboard input from the user.
***************************************************************************/
unsigned getkey(){
  unsigned c;
  union REGS regs;

  regs.h.ah = 2;
  int86(0x16, &regs,&regs );
  shifted = (regs.h.al & 3);
  if ((c=bioskey(0)) & 0xff) c &= 0xff;
  else if ( shifted ) c |= 1;
  return c;
}



void prprint(int x,int y, int color, char *t)
{
	int bk = (color>8) ? 0 : 15;

	printxyr(x,y,bk,t,0);
	printxyr(x+1,y+1,color,t,0);
}




long test_x, test_y, test_z;
void test_object ( OBJECT *obj )
{
  long x, y, z;

  if (sphere_pretest ( obj, test_x, test_y, test_z) < 100 )
    remove_from_objlist ( obj );
}

OBJECT *exp1, *exp2, *exp3, *exp4, *exp5, *exp6;
SEGMENT *exp1s, *exp2s, *exp3s, *exp4s, *exp5s, *exp6s, *jet;
/**************************************************************************
**************************************************************************/
void do_explosion( long x, long y, long z )
{

  abs_move_segment ( exp1s, x, y, z );
  update_segment ( exp1s );
  get_object_bounds ( seg_get_object ( exp1s ), &test_x, &test_y, &test_z );
  walk_split_tree ( &split_tree, test_object );

  refresh_display();
  delay (100);

  abs_move_segment ( exp2s, x, y, z );
  update_segment ( exp2s );
  refresh_display();
  delay (100);

  abs_move_segment ( exp3s, x, y, z );
  update_segment ( exp3s );
  refresh_display();
  delay (100);

  abs_move_segment ( exp4s, x, y, z );
  update_segment ( exp4s );
  refresh_display();
  delay (100);

  abs_move_segment ( exp5s, x, y, z );
  update_segment ( exp5s );
  refresh_display();
  delay (100);

  abs_move_segment ( exp6s, x, y, z );
  update_segment ( exp6s );
  refresh_display();
  delay (100);

  remove_from_objlist ( exp1 );
  remove_from_objlist ( exp2 );
  remove_from_objlist ( exp3 );
  remove_from_objlist ( exp4 );
  remove_from_objlist ( exp5 );
  remove_from_objlist ( exp6 );
  refresh_display ();

}





/**************************************************************************
   This function handles keys pressed by the user.Handle any user keys.
**************************************************************************/
void handle_key ( unsigned int c ){
FILE *infile;

  switch ( c ) {
    case 'q':
    case 'Q':popmsg ( "Do you wish to quit? (y/n)" );
	     if ( toupper(getkey())== 'Y' ) execution = 0;
	     else redraw = 1;
	     break;

    /* Look up. Step by 1 angle value */
    case 0x4800: current_view->ex += 50 + 5L * sine(current_view->roll);
		 current_view->ez += 50+ 5L * cosine(current_view->roll);

		 rel_move_segment ( jet,
					     50+5L*sine(current_view->roll),
					     0,
					     50+5L*cosine(current_view->roll));
		 update_segment ( jet );
		 redraw = 1;
		 break;

    /* Look down. Step by 1 angle value */
    case 0x5000: current_view->ex -= 50 + 5L * sine(current_view->roll);
		 current_view->ez -= 50 + 5L * cosine(current_view->roll);
		 rel_move_segment ( jet,
				      -(50 + 5L*sine(current_view->roll)),
				      0,
				      -( 50 + 5L*cosine(current_view->roll)));
		 update_segment ( jet );
		 redraw = 1;
		 break;

    case 0x4B00: current_view->roll -= 65536L;
		 current_view->pan  -= 65536L;
		 redraw = 1;
		 break;

    case 0x4D00: current_view->roll += 65536L;
		 current_view->pan  += 65536L;
		 redraw = 1;
		 break;

    case 'b': do_explosion ( current_view->ex,
			     current_view->ey,
			     current_view->ez+fire_distance );
	      break;
  }
}


SEGMENT *but1_menu_seg, *but2_menu_seg, *but3_menu_seg;
POINTER gp;
void do_button1()
{
  long button1x, button1y, button1z;
  long button2x, button2y, button2z;
  long button3x, button3y, button3z;
  int key_pressed = 0;
  char buf[40];

  abs_move_segment ( but1_menu_seg, current_view->ex-25,
				    current_view->ey-10,
				    current_view->ez+55);
  update_segment ( but1_menu_seg );
  get_object_bounds ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button1" ) ), &button1x, &button1y, &button1z );
  get_object_bounds ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button2" ) ), &button2x, &button2y, &button2z );
  get_object_bounds ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button3" ) ), &button3x, &button3y, &button3z );



  while (!key_pressed)
  {

    refresh_display();
    glove_update( manip_device, &gp );
    update_segment ( body_seg );

    sprintf ( buf, "Jet Speed = %d", jet_speed );
    prprint(102,40,15, buf );

    sprintf(buf, "Increase 10" );
    prprint(90,62,15,buf);

    sprintf(buf, "Decrease 10" );
    prprint(90,84,15,buf);

    sprintf(buf, "Finished" );
    prprint(90,105,15,buf);


    if (sphere_pretest(finger_tip, button1x, button1y, button1z) < 100)
      jet_speed += 10;

    if (sphere_pretest(finger_tip, button2x, button2y, button2z) < 100)
      jet_speed -= 10;

    if (sphere_pretest(finger_tip, button3x, button3y, button3z) < 100)
      key_pressed = 1;

  }

  refresh_display();
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "menu1")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button1")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button2")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button3")));
  refresh_display();

}


void do_button2()
{
  long button1x, button1y, button1z;
  long button2x, button2y, button2z;
  long button3x, button3y, button3z;
  int key_pressed = 0;
  char buf[40];

  abs_move_segment ( but2_menu_seg, current_view->ex-25,
				    current_view->ey-10,
				    current_view->ez+55);
  update_segment ( but2_menu_seg );
  get_object_bounds ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button1" ) ), &button1x, &button1y, &button1z );
  get_object_bounds ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button2" ) ), &button2x, &button2y, &button2z );
  get_object_bounds ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button3" ) ), &button3x, &button3y, &button3z );



  while (!key_pressed)
  {

    refresh_display();
    glove_update( manip_device, &gp );
    update_segment ( body_seg );

    sprintf ( buf, "Fire Distance = %d", fire_distance );
    prprint(90,40,15, buf );

    sprintf(buf, "Increase 10" );
    prprint(90,62,15,buf);

    sprintf(buf, "Decrease 10" );
    prprint(90,84,15,buf);

    sprintf(buf, "Finished" );
    prprint(90,105,15,buf);


    if (sphere_pretest(finger_tip, button1x, button1y, button1z) < 100)
      fire_distance += 10;

    if (sphere_pretest(finger_tip, button2x, button2y, button2z) < 100)
      fire_distance -= 10;

    if (sphere_pretest(finger_tip, button3x, button3y, button3z) < 100)
      key_pressed = 1;

  }

  refresh_display();
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "menu2")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button1")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button2")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button3")));
  refresh_display();

}

void read_menus()
{
  FILE *in;

  if ((in = fopen("menu1.fig", "r")) == NULL)
  {
    popmsg("Could not load figure file");
  }
  else
  {
    set_readseg_objlist(objlist);
    if ((but1_menu_seg = readseg(in, NULL)) == NULL)
    {
	popmsg("Error reading menu1 figure file");
    }
    else
	update_segment(but1_menu_seg);
  }
  fclose ( in );

  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "menu1")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button1")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button2")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but1_menu_seg, "m1button3")));

  if ((in = fopen("menu2.fig", "r")) == NULL)
  {
    popmsg("Could not load figure file");
  }
  else
  {
    set_readseg_objlist(objlist);
    if ((but2_menu_seg = readseg(in, NULL)) == NULL)
    {
	popmsg("Error reading menu2 figure file");
    }
    else
	update_segment(but2_menu_seg);
  }
  fclose ( in );

  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "menu2")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button1")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button2")));
  remove_from_objlist ( seg_get_object ( find_segment_by_name ( but2_menu_seg, "m2button3")));


}




/**************************************************************************
  This function performs the functions of the program.  The loop terminates
  when execution = 1.
**************************************************************************/
void main_loop(){
  char buf[100];
  long button1x, button1y, button1z;
  long button2x, button2y, button2z;
  long button3x, button3y, button3z;
  long yokex, yokey, yokez;
  long dist;
  int on_yoke = 0;


  finger_tip = seg_get_object ( find_segment_by_name ( body_seg, "indextip" ));
  palm = seg_get_object ( find_segment_by_name ( body_seg, "palm" ));
  yoke = find_segment_by_name ( jet, "yoke_stick" );
  yoke_obj = seg_get_object ( yoke );
  but1 = seg_get_object ( find_segment_by_name ( jet, "button1" ));
  but2 = seg_get_object ( find_segment_by_name ( jet, "button2" ));
  but3 = seg_get_object ( find_segment_by_name ( jet, "button3" ));
  while ( execution )
    {
      if (bioskey(1)) 	handle_key (getkey());
      if (redraw) 	refresh_display();

      get_object_bounds ( yoke_obj, &yokex, &yokey, &yokez );
      yokey += 20;

      get_object_bounds ( but1, &button1x, &button1y, &button1z );
      get_object_bounds ( but2, &button2x, &button2y, &button2z );
      get_object_bounds ( but3, &button3x, &button3y, &button3z );

      glove_update( manip_device, &gp );
      update_segment ( body_seg );

      if (((dist = sphere_pretest ( palm, yokex, yokey, yokez)) < 300 ) && ((gp.gesture== G_FIST) || (gp.gesture==G_THUMB_OUT) ))
	  on_yoke = 1;
      else if (!((gp.gesture==G_THUMB_OUT)||(gp.gesture == G_FIST)))
	on_yoke = 0;


      if (! on_yoke )
      {
	if ((dist = sphere_pretest (finger_tip,button1x,button1y,button1z)) < 100 )
	  do_button1();
	else if ((dist = sphere_pretest (finger_tip,button2x,button2y,button2z)) < 100 )
	  do_button2();
	else if ((dist = sphere_pretest (finger_tip,button3x,button3y,button3z)) < 100 )
	  execution = 0;
      }

      if (( gp.gesture == G_FIST ) && (on_yoke))
      {
	if ( gp.dz > 0 )
	{
	  current_view->ex += jet_speed * sine(current_view->pan);
	  current_view->ez += jet_speed * cosine(current_view->pan);

	  rel_move_segment ( jet,
			     jet_speed*sine(current_view->pan),
			     0,
			     jet_speed*cosine(current_view->pan));
	  update_segment ( jet );
	  rel_move_segment ( body_seg,
			     jet_speed*sine(current_view->pan),
			     0,
			     jet_speed*cosine(current_view->pan));
	  update_segment ( body_seg );

	  redraw = 1;
	}
	else if ( gp.dz < 0 )
	{
	  current_view->ex -= jet_speed * sine(current_view->pan);
	  current_view->ez -= jet_speed * cosine(current_view->pan);
	  rel_move_segment ( jet,
			      -(jet_speed*sine(current_view->pan)),
			      0,
			      -(jet_speed*cosine(current_view->pan)));
	  update_segment ( jet );
	  rel_move_segment ( body_seg,
			     -(jet_speed*sine(current_view->pan)),
			     0,
			     -(jet_speed*cosine(current_view->pan)));
	  update_segment ( body_seg );
	  redraw = 1;
	}
	else if ( gp.dx > 0 )
	{
	      current_view->ex += jet_speed * cosine(current_view->pan);
	      current_view->ez -= jet_speed * sine(current_view->pan);
	      rel_move_segment ( body_seg, +jet_speed*cosine(current_view->pan),
					   0,
					   -jet_speed*sine(current_view->pan));
	      update_segment ( body_seg );
	      rel_move_segment ( jet, +jet_speed*cosine(current_view->pan),
					   0,
					   -jet_speed*sine(current_view->pan));
	      update_segment ( jet );
	      redraw = 1;
	}
	else if ( gp.dx < 0 )
	{
	      current_view->ex -= jet_speed * cosine(current_view->pan);
	      current_view->ez += jet_speed * sine(current_view->pan);
	      rel_move_segment ( body_seg, -jet_speed*cosine(current_view->pan),
					   0,
					   +jet_speed*sine(current_view->pan));
	      update_segment ( body_seg );
	      rel_move_segment ( jet, -jet_speed*cosine(current_view->pan),
					   0,
					   +jet_speed*sine(current_view->pan));
	      update_segment ( jet );
	      redraw = 1;

	}
      }
    }
}



/**************************************************************************
  This function is called to load video drivers.  The pointer
  v_driver_pointer is set to a handle representing the video driver.
  The variable v_driver_pointer is used by the files: main only.
**************************************************************************/
void load_video_driver ( char *dfile )
{
  v_driver_pointer = load_driver ( dfile );
  if ( v_driver_pointer == NULL )
  {
	fprintf ( stderr, "Bad video driver/n" );
	exit ( 1 );
  }
}


/**************************************************************************
**************************************************************************/
void get_jet()
{
  FILE *in;

  if ((in = fopen("jet.fig", "r")) == NULL)
  {
    popmsg("Could not load figure file");
  }
  else
  {
    set_readseg_objlist(objlist);
    if ((jet = readseg(in, NULL)) == NULL)
    {
	popmsg("Error reading jet figure file");
    }
    else
	update_segment(jet);
  }
  fclose ( in );
}

/**************************************************************************
**************************************************************************/
void get_explosions()
{

  FILE *in;

  set_loadplg_offset ( 0,0,0 );
  set_loadplg_scale ( 1,1,1 );


  if ((in = fopen ( "exp1.plg", "r" )) == NULL )
    {
      fprintf ( stderr, "Unable to open exp1 file.\n" );
      exit(1);
    }

  exp1 = load_plg ( in );
  if ( load_err != 0 )
    {
      fprintf ( stderr, "Error loading exp1.plg file.\n" );
      exit(1);
    }
  fclose ( in );

  if ((in = fopen ( "exp2.plg", "r" )) == NULL )
    {
      fprintf ( stderr, "Unable to open exp2 file.\n" );
      exit(1);
    }

  exp2 = load_plg ( in );
  if ( load_err != 0 )
    {
      fprintf ( stderr, "Error loading exp2.plg file.\n" );
      exit(1);
    }
  fclose ( in );

  if ((in = fopen ( "exp3.plg", "r" )) == NULL )
    {
      fprintf ( stderr, "Unable to open exp3 file.\n" );
      exit(1);
    }

  exp3 = load_plg ( in );
  if ( load_err != 0 )
    {
      fprintf ( stderr, "Error loading exp3.plg file.\n" );
      exit(1);
    }
  fclose ( in );

  if ((in = fopen ( "exp4.plg", "r" )) == NULL )
    {
      fprintf ( stderr, "Unable to open exp4 file.\n" );
      exit(1);
    }

  exp4 = load_plg ( in );
  if ( load_err != 0 )
    {
      fprintf ( stderr, "Error loading exp4.plg file.\n" );
      exit(1);
    }
  fclose (in);

  if ((in = fopen ( "exp5.plg", "r" )) == NULL )
    {
      fprintf ( stderr, "Unable to open exp5 file.\n" );
      exit(1);
    }

  exp5 = load_plg ( in );
  if ( load_err != 0 )
    {
      fprintf ( stderr, "Error loading exp5.plg file.\n" );
      exit(1);
    }
  fclose( in );

  if ((in = fopen ( "exp6.plg", "r" )) == NULL )
    {
      fprintf ( stderr, "Unable to open exp6 file.\n" );
      exit(1);
    }

  exp6 = load_plg ( in );
  if ( load_err != 0 )
    {
      fprintf ( stderr, "Error loading exp6.plg file.\n" );
      exit(1);
    }
  fclose ( in );


  add_obj_to_split ( &split_tree, exp1 );
  exp1s = new_seg ( NULL );
  seg_set_object ( exp1s, exp1 );
  set_object_owner ( exp1, exp1s );
  abs_rot_segment ( exp1s, 90*65536L, 0, 0, RXYZ );
  update_segment ( exp1s );
  remove_from_objlist ( exp1 );

  add_obj_to_split ( &split_tree, exp2 );
  exp2s = new_seg ( NULL );
  seg_set_object ( exp2s, exp2 );
  set_object_owner ( exp2, exp2s );
  abs_rot_segment ( exp2s, 90*65536L, 0, 0, RXYZ );
  update_segment ( exp2s );
  remove_from_objlist ( exp2 );

  add_obj_to_split ( &split_tree, exp3 );
  exp3s = new_seg ( NULL );
  seg_set_object ( exp3s, exp3 );
  set_object_owner ( exp3, exp3s );
  abs_rot_segment ( exp3s, 90*65536L, 0, 0, RXYZ );
  update_segment ( exp3s );
  remove_from_objlist ( exp3 );

  add_obj_to_split ( &split_tree, exp4 );
  exp4s = new_seg ( NULL );
  seg_set_object ( exp4s, exp4 );
  set_object_owner ( exp4, exp4s );
  abs_rot_segment ( exp4s, 90*65536L, 0, 0, RXYZ );
  update_segment ( exp4s );
  remove_from_objlist ( exp4 );


  add_obj_to_split ( &split_tree, exp5 );
  exp5s = new_seg ( NULL );
  seg_set_object ( exp5s, exp5 );
  set_object_owner ( exp5, exp5s );
  abs_rot_segment ( exp5s, 90*65536L, 0, 0, RXYZ );
  update_segment ( exp5s );
  remove_from_objlist ( exp5 );

  add_obj_to_split ( &split_tree, exp6 );
  exp6s = new_seg ( NULL );
  seg_set_object ( exp6s, exp6 );
  set_object_owner ( exp6, exp6s );
  abs_rot_segment ( exp6s, 90*65536L, 0, 0, RXYZ );
  update_segment ( exp6s );
  remove_from_objlist ( exp6 );

}


/**************************************************************************
**************************************************************************/
void get_x29_jet()
{
}



/**************************************************************************
**************************************************************************/
void get_1701_ship()
{
}

/**************************************************************************
**************************************************************************/
void set_1701_ship_flight_plan()
{
}

/**************************************************************************
**************************************************************************/
void set_x29_jet_flight_plan()
{
}

/**************************************************************************
**************************************************************************/
void get_glove()
{
  PDRIVER *gd;
  extern PDRIVER *gloveptr_init(char *gname, long sx, long sy,
		 long sz, long srx, long sry, long srz );

  gd = gloveptr_init ( gpdname, gpdo_x*65536.0, gpdo_y*65536.0, gpdo_z*65536.0,
		       gpdo_rx*65536.0, gpdo_ry*65536.0, gpdo_rz*65536.0 );

  manip_device = menu_device = gd;
  if(gd)
    load_glove_cursor ( body_seg, manip_device, gpcursor );
}




void main(int argc, char *argv[]){
  char *fname, *in_filename;
  FILE *in;

  setup_render(40,800);
  atexit(closeall);
  set_global_split_root ( &split_tree );
  initial_world_split ( &split_tree );
  set_move_handler ( split_move_handler );
  objlist = new_objlist();


  fname = "rend386.cfg";
  if ((in = fopen ( fname, "r" )) == NULL )
    {
      fprintf ( stderr, "Configuration file not found!" );
      exit(1);
    }
  else
    {
      if ( read_world(in))
	{
	    fprintf ( stderr, "Error reading configuration file!" );
	    exit(1);
	}
      fclose ( in );
    }

  in_filename = fix_fname(argv[1] );
  if ( strstr (in_filename, ".wld"))
    {
      if ((in = fopen ( in_filename, "r" )) == NULL )
	{
	  fprintf ( stderr, "Error opening world file.\n" );
	  exit(1);
	}
      if (read_world(in))
	{
	  fprintf ( stderr, "Error reading world file.\n");
	  exit(1);
	}
      fclose(in);
    }


  load_video_driver ( vdname );
  screeninfo = screen_data();
  highest_color = screeninfo->colors-1;
  preset_default_colors();

  frame_x = screeninfo->xmin;
  frame_y = screeninfo->ymin;
  frame_w = screeninfo->xmax - screeninfo->xmin+1;
  frame_h = screeninfo->ymax - screeninfo->ymin+1;

  default_view.left = screeninfo->xmin;
  default_view.top = screeninfo->ymin;
  default_view.right = screeninfo->xmax;
  default_view.bottom = screeninfo->ymax;
  default_view.aspect = screeninfo->aspect;


  if (enter_graphics()) {
    fprintf ( stderr, "could not enter graphics mode\n\n");
    exit(1);
    }

  screen_clear_color = 0;

  sky_color  = 1; ground_color = 2;

  initialize_screen_factors ( current_view );
  fast_view_factors ( current_view );


  if(stereo_type != MONOSCOPIC)
  {
   init_switch_driver(swdname);
   if(sl_left<0)
   {
	sl_left = default_view.left;
	sl_right = default_view.right;
	sl_top = default_view.top;
	sl_bottom = default_view.bottom;
   }
     compute_stereo_data(&default_stereo, 0, sl_xflip, sl_xoff, 65536.0*sl_xrot,
			 sl_left, sl_top, sl_right, sl_bottom);
   if(sr_left<0)
   {
	sr_left = default_view.left;
	sr_right = default_view.right;
	sr_top = default_view.top;
	sr_bottom = default_view.bottom;
   }
     compute_stereo_data(&default_stereo, 1, sr_xflip, sr_xoff, 65536.0*sr_xrot,
			 sr_left, sr_top, sr_right, sr_bottom);
  }


  set_readseg_scale ( 1,1,1 ); /* Must do or will get previous readseg scale */
  get_jet();

  body_seg = new_seg(NULL);
  set_readseg_scale ( 0.15, 0.15, 0.15 );
  get_glove();
  abs_move_segment ( body_seg, 0, 0, -1075 );
  update_segment ( body_seg );

  get_explosions();
  read_menus();

  main_loop();   /* start us off */
}
