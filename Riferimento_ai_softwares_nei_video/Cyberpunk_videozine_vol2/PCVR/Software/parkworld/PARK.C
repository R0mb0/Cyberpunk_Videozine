/* This program requires Release 4.01 of Rend386 to compile */


#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include "\rend4\rend386.h"
#include "\rend4\userint.h"
#include "\rend4\plg.h"
#include "\rend4\splits.h"
#include "\rend4\tasks.h"
#include "\rend4\pointer.h"
#include "\rend4\cursor.h"
#include "\rend4\segio.h"
#include "\rend4\intmath.h"
#include "\rend4\segasupp.h"
#include <gdc.h>

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
int 		stereo_type = MONOSCOPIC;

/* This variable declares the default startup view of the program.
   Files used: keyboard, world
*/
VIEW 		default_view =  {
				0,0,-1000,
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

/* These variable are used as the configuration settings for the glove
   pointer device, translation and rotation.
   Files used: world
*/
float 		gpdo_x = 1, gpdo_y = 1, gpdo_z = 2,
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
int 		use_glove = 0;

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
int 		have_glove = 0;

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
char            mdname[40] = "mouse";

extern SEGMENT *body_seg;
int head_device = 0,
    heavy = 0,
    weight = 0,
    total_pieces = 0;
joystick_data  joy_data;
int joy_return=0;
int use_joystick = 0,
    use_gdc = 0;
SEGMENT *glove_joints[20],
	*wrist_seg;

piece_struct pieces_places[100];
char *pieces[100];



////////////VICTORMAXX STUNTMASTER VARIABLES//////////
int use_stuntmaster = 0;
int x_stunt_value = 0,
    y_stunt_value = 0,
    stunt_position = 0,
    stunt_angle = 15;
joystick_data stunt_data;


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
    case 0x4800: current_view->tilt += 15*65536L;
		 redraw = 1;
		 break;

    /* Look down. Step by 1 angle value */
    case 0x5000: current_view->tilt -= 15*65536L;
		 redraw = 1;
		 break;

    /* Look to the left.  Step by 1 angle value */
    case 0x4B00: current_view->pan -= 15*65536L;
		 redraw = 1;
		 break;

    /* Look to the right.  Step by 1 angle value */
    case 0x4D00: current_view->pan += 15*65536L;
		 redraw = 1;
		 break;


    case 'b':
    case 'B': current_view->ex -= 250L * sine(current_view->pan);
	      current_view->ez -= 250L * cosine(current_view->pan);
	      redraw = 1;
	      break;

    case 'f':
    case 'F': current_view->ex += 250L * sine(current_view->pan);
	      current_view->ez += 250L * cosine(current_view->pan);
	      redraw = 1;
	      break;

    case 'r':
    case 'R': current_view->ex += 250L * cosine(current_view->pan);
	      current_view->ez -= 250L * sine(current_view->pan);
	      redraw = 1;
	      break;

    case 'l':
    case 'L': current_view->ex -= 250L * cosine(current_view->pan);
	      current_view->ez += 250L * sine(current_view->pan);
	      redraw = 1;
	  break;


  }



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



void check_stunt()
{
 int x1, x2, x3, x4, y1, y2, y3, y4;
 int x, y;

 joystick_read(&stunt_data); x1 = stunt_data.x; y1 = stunt_data.y;
 joystick_read(&stunt_data); x2 = stunt_data.x; y2 = stunt_data.y;
 joystick_read(&stunt_data); x3 = stunt_data.x; y3 = stunt_data.y;
 joystick_read(&stunt_data); x4 = stunt_data.x; y4 = stunt_data.y;

 x = (x1+x2+x3+x4)/4;
 y = (y1+y2+y3+y4)/4;


 if ((x > x_stunt_value) && (stunt_position != -1) && (y<y_stunt_value))
 {
   if (stunt_position == 0)
     current_view->pan -= stunt_angle*65536L;
   else
     current_view->pan -= 2*stunt_angle*65536L;
   stunt_position = -1;
 }
 else if ((y > y_stunt_value) && (stunt_position != 1)&&(x<x_stunt_value))
 {
   if (stunt_position == 0)
     current_view->pan += stunt_angle*65536L;
   else
     current_view->pan += 2*stunt_angle*65536L;
   stunt_position = 1;
 }
 else if ((x == x_stunt_value)&&(y == y_stunt_value))
 {
   if (stunt_position == -1)
   {
     stunt_position = 0;
     current_view->pan += stunt_angle*65536L;
   }
   else if (stunt_position == 1)
   {
     stunt_position = 0;
     current_view->pan -= stunt_angle*65536L;
   }
 }
 redraw =1;
}




/**************************************************************************
  This function performs the functions of the program.  The loop terminates
  when execution = 1.
**************************************************************************/
void main_loop(){
  int x, y;
  float thecos, thesin;


  while ( execution )
    {
      if (bioskey(1)) 	handle_key (getkey());
      if (redraw) 	refresh_display();

      if (use_gdc) gdc_UpdatePos();

      if (use_joystick)
      {
        joystick_read ( &joy_data );
        x = joy_data.x;
        y = joy_data.y;

        if ( x>10 ) x -= 10;
        else
        {
          if ( x > -10) x = 0;
          else x += 10;
        }
        if ( y > 10 ) y -= 10;
        else
        {
          if(y>-10) y = 0;
          else y+=10;
        }

        thecos = cosine ( current_view->pan );
        thesin = sine ( current_view->pan );

        switch ( joy_data.buttons )
        {
          case 0: current_view->pan += ( x/10 * 65536L );
                  current_view->ex  -= ( y * thesin * 2L );
                  current_view->ez  -= ( y * thecos * 2L );
                  redraw = 1;
                  break;

          case 1: current_view->ex += (x * 2L * thecos);
		  current_view->ez -= (x * 2L * thesin);
                  redraw = 1;
                  break;
        }
      }
      if (use_stuntmaster) check_stunt();
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


void get_stuntmaster()
{

  int x1, x2, x3, x4, y1, y2, y3, y4;
  char *stunt_text[] = {
			"",
			"Please put Stuntmaster on your head.",
			"Look straight ahead and press the",
			"reset button.",
			"",
			NULL
		      };


  joystick_init (&stunt_data, use_stuntmaster-1);

  poptext ( stunt_text );
  delay(10000);

  joystick_read ( &stunt_data ); x1 = stunt_data.x; y1 = stunt_data.y;
  delay(150);
  joystick_read ( &stunt_data ); x2 = stunt_data.x; y2 = stunt_data.y;
  delay(150);
  joystick_read ( &stunt_data ); x3 = stunt_data.x; y3 = stunt_data.y;
  delay(150);
  joystick_read ( &stunt_data ); x4 = stunt_data.x; y4 = stunt_data.y;
  delay(150);

  x_stunt_value = (x1+x2+x3+x4)/4;
  y_stunt_value = (y1+y2+y3+y4)/4;

  stunt_position = 0;
}




void main(int argc, char *argv[]){
  char *fname, *in_filename;
  FILE *in;
  int i;

  for (i=1; i <= argc; ++i)
  {

    if (argv[i][0] == '/' || argv[i][0] == '-')
    {
      switch(toupper(argv[i][1]))
      {
	case '?': printf ( "\n\nusage: park [-][/] ?hgs12");
		  printf ( "\n\n       ? = This help information");
		  printf ( "\n\n       g = Use Global 3D Controller on COM1");
		  printf ( "\n\n       i = Use Global 3D Controller on COM2");		  printf ( "\n\n       s = Use Shutter glasses interface on serial port");
		  printf ( "\n\n       1 = COM1 for Shutter glasses");
		  printf ( "\n\n       2 = COM2 for Shutter glasses");
		  printf ( "\n\n       h = Stuntmaster");
		  exit(0);
		  break;

	case 'G': use_gdc = 1; gdc_init(use_gdc);break;
	case 'i': use_gdc = 2; gdc_init(use_gdc);break;
	case 'S': stereo_type = SWITCHED;  break;
	case '1': select_sega_port(0x3FC); break;
	case '2': select_sega_port(0x2FC); break;
	case 'H': use_stuntmaster = 1;
	      clrscr();
	      printf ( "\n\n");
	      printf ( "Please remember that if you are using the Stuntmaster\n");
	      printf ( "your joystick must configured for joystick port 1\n");
	      printf ( "since the stuntmaster uses joystick port 0.\n");
	      printf ( "If you are not using the joystick for movement, you\n");
	      printf ( "don't need to do anything\n");
	      printf ( "\n\n");
	      printf ( "Because of the quality of the PC joystick port, the Stuntmaster's\n");
	      printf ( "head positioning mechanism will not always work.  If you find this\n");
	      printf ( "to be the case, simply run park without the -h and use the Stuntermaster\n");
	      printf ( "as a viewer only\n");
	      delay(4000);
	      break;
      }
    }
  }


  setup_render(50,1800);
  atexit(closeall);
  set_global_split_root ( &split_tree );
  initial_world_split ( &split_tree );
  set_move_handler ( split_move_handler );
  objlist = new_objlist();


  fname = "park.cfg";
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


 if ((in = fopen ( "park.wld", "r" )) == NULL )
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


  if ( !use_glove )
  {
     if ( stereo_type == SWITCHED )
      init_SG_interrupt ( switch_sega, NULL, 6500 );
  }



  use_joystick = 0;
  if ((joy_return = joystick_check()) == 0 )
  {
    popmsg ( "Joystick was not found" );
    delay ( 5000 );
  }
  else
  {
    if (!use_stuntmaster)
    {
      if ( joy_return & 1 ) joystick_init ( &joy_data, 0 );
      joystick_setscale ( &joy_data, 100 );
      use_joystick = 1;
    }
    else
    {
      if ( joy_return & 2 ) joystick_init ( &joy_data, 1 );
      joystick_setscale ( &joy_data, 100 );
      use_joystick = 1;
    }

  }
  if (use_stuntmaster) get_stuntmaster();

  main_loop();

  if (use_gdc) gdc_remove();
}

