#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include "polygon.h"

extern int sky, ground, screencolor, draw_horizon;
VIEWPOINT *view_one;
int redraw;
FILE *debug;
int STEREO = 0;
struct time start, finish;
long total_redraw = 0;

void screen_redraw()
{
   Object *ObjectPtr;
   int i;

   total_redraw++;
       for (i=0, ObjectPtr = ObjectListStart.NextObject; i<NumObjects;
          i++, ObjectPtr = ObjectPtr->NextObject)
            XFormandProjectPObject (ObjectPtr, view_one);


        CurrentPageBase =    /* select other page for drawing to */
          PageStartOffsets[NonDisplayedPage = DisplayedPage ^ 1];
        if ( draw_horizon )
        {
          FillRectangleX ( 0,0,320,160,CurrentPageBase, sky );
          FillRectangleX ( 0,160, 320, 240, CurrentPageBase, ground );
        }
        else FillRectangleX (0,0,320,240, CurrentPageBase, screencolor );

        /* Sort the objects so we can draw them back to front */
        SortObjects();

        /* Draw all objects */
        for (i=0, ObjectPtr = ObjectListStart.NextObject; i<NumObjects;
          i++, ObjectPtr = ObjectPtr->NextObject)
          DrawPObject ( ObjectPtr, view_one );

        /* Flip to display the page into which we just drew */
        ShowPage(PageStartOffsets[DisplayedPage = NonDisplayedPage]);
        if ( STEREO ) sega_switch();
}


void wrapup()
{  union REGS regset;

   long secs1, secs2;

   gettime ( &finish );
   regset.x.ax = 0x0003;   /* AL = 3 selects 80x25 text mode */
   int86(0x10, &regset, &regset);

   secs1 = start.ti_hour*3600 + start.ti_min * 60 + start.ti_sec;
   secs2 = finish.ti_hour*3600 + finish.ti_min * 60 + finish.ti_sec;

   printf ( "\n\nFrame/sec = %ld", total_redraw/(secs2-secs1) );


   fclose(stderr);
   fclose(stdout);


}

void main()
{
   int Done = 0, i, c;
   PObject *ball_object, *ball_object2, *ball_object3;
   char ch;
   union REGS regset;
   int light_one, light_two, light_three;


  atexit(wrapup);
  freopen  ("error.fil", "w", stderr );
  freopen  ("error2.fil", "w", stdout );
  debug = fopen ( "debug.it", "w" );

  if((view_one = create_viewpoint (0.0,0.0,300.0,0,0,0))==NULL)
     { printf ( "View creation failed.\n"); exit(1); }

   InitializeObjectList();           /* set up the initial objects */


   ball_object2 = read_joint_file ( "test.jnt" );

   SetGraphicsMode();                /* set the screen to graphics mode */
   InitializePalette();

   initialize_lights();
   light_one = add_light ( view_one, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0 );
   light_two = add_light ( view_one, 0.0, 0.0, -1.0, 1.0, 0.0, 0.0 );
   light_three = add_light ( view_one, 0.0, 0.0, -1.0, 0.0, 0.0, 1.0 );

   turn_light_on ( light_one );
   turn_light_off ( light_two );
   turn_light_off ( light_three );

   SetAmbientIntensity ( 0.5, 0.5, 0.5 );
   TurnAmbientOff();

   draw_horizon = 0;
   sky = RGBToColorIndex(0.0, 0.0, 1.0);
   ground = RGBToColorIndex( 0.0, 1.0, 0.0 );

   /* Start off showing page 0 */
   ShowPage(PageStartOffsets[DisplayedPage = 0]);

   RecalcAllXforms = 1;
   gettime(&start);

   do {
      screen_redraw();



      AppendRotationX ( ball_object->XformToWorld, 850 );
      AppendRotationX ( ball_object2->XformToWorld, 450 );
      AppendRotationX ( ball_object3->XformToWorld, 50 );
      RecalcAllXforms = 1;



      while (kbhit()) {
        switch(c = getch()) {

        case 0x1B:
	       Done = 1;
           fclose(debug);
	       break;

        case 'r': rel_move_viewpoint ( view_one, 10, 0, 0 );
		      RecalcAllXforms = 1;
		      break;

	    case 'l': rel_move_viewpoint ( view_one, -10, 0, 0 );
		      RecalcAllXforms = 1;
		      break;

	    case 'u': rel_move_viewpoint ( view_one, 0, 10, 0 );
		      RecalcAllXforms = 1;
		      break;

	    case 'd': rel_move_viewpoint ( view_one, 0, -10, 0 );
		      RecalcAllXforms = 1;
		      break;

        case 'a': rel_move_viewpoint ( view_one, 0, 0,10 );
		      break;

        case 't': rel_move_viewpoint ( view_one, 0, 0, -10 );
		      break;

        case '1': if (get_light_onoff(light_one))
               turn_light_off ( light_one );
		      else
               turn_light_on ( light_one );
              RecalcAllXforms = 1;
              break;

        case '2': if (get_light_onoff(light_two))
               turn_light_off ( light_two );
		      else
               turn_light_on ( light_two );
              RecalcAllXforms = 1;
              break;

        case '3': if (get_light_onoff(light_three))
               turn_light_off ( light_three );
		      else
               turn_light_on ( light_three );
              RecalcAllXforms = 1;
              break;


        case 'B':
	    case 'b':
	       if (GetAmbientState())
                  TurnAmbientOff();
               else
                  TurnAmbientOn();
                  RecalcAllXforms = 1;
               break;

        case 0:
               switch (getch())
               {
                  case 0x4B:  rel_pan_viewpoint ( view_one, 100 );
                              break;

                  case 0x4D:  rel_pan_viewpoint ( view_one, -100 );
                              break;

                  case 0x48:  rel_tilt_viewpoint ( view_one, 100 );
                              break;

                  case 0x50:  rel_tilt_viewpoint ( view_one, -100 );
                              break;
                }

        default:
               break;
         }

      }

   } while (!Done);

   /* Return to text mode and exit */
   regset.x.ax = 0x0003;   /* AL = 3 selects 80x25 text mode */
   int86(0x10, &regset, &regset);

   destroy_viewpoint ( view_one );
   remove_lights();
   exit(1);

}

