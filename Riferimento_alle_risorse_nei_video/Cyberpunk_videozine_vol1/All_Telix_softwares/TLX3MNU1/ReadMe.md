
                          T E L I X  R E L E A S E  3 . 0 0
                             Logitech 3-Button Mouse Menu

                              Written By Robert F. Rapp
                                    July 03, 1988

                                     Version 1.00


          Telix  lends  itself to mouse support, with its pop-up moving bar
          menus and the Lotus-style dialing directory.   It  has,  however,
          two  areas  of  weakness:  The command help menu, and the lack of
          point-and-shoot capabilities in the dialing directory.  This menu
          provides, in a 4K menu, these capabilities.

          The mouse buttons follow the more-or-less accepted standards  for
          Logitech menus:
                    Left                          Enter
                    Middle                        Select (menu)
                    Right                         Escape

          In addition, chords are defines as follows:
                    Left+Middle                   Y (for YES)
                    Right+Middle                  N (for NO)
                    Left+Right                    PgUp or AltS (page up in
                                                  dialing directory,
                                                  upload otherwise)
                    All buttons                   PgDn or AltR (page down in
                                                  dialing directory,
                                                  download otherwise)

          To  get  the  pop-up command menu, click the middle button twice.
          The first click will  give  you  the  usual  help  screen/session
          timer, the second will load the overlay pop-up menu.  It includes
          all  the commands on the help screen, but simply point and click.
          The default is the dialing  directory,  to  speed  access.   Just
          click the left button twice to bring up the short, then the full,
          dialing directory.

          If  the overlay pop-up DOES NOT appear, check your Screen & Color
          Configuration.  Change the "Page Use" option; try the BIOS method.
          That may well work.

          When  in  a  session, you can bypass the menu and use the L+R and
          ALL chords for up- and down- loading.  Just remember, fork up and
          fAll down.  (Is it apparent I'm an old time WordStar user?  We'll
          stretch mnemonics beyond belief!)

          Now  for  the  dialing directory. You can use the ALL (fAll down)
          chord to move down, one page of 15 entries at a  time.  Likewise,
          you can use the L+R (fork up) chord to move up a page of entries.
          Note  that  a  page  up on page 1 will wrap you around to page 10
          (the last page), and a page down chord on page 10 will  wrap  you
          around  to  page  1.   This is a feature not implemented in Telix
          from the keyboard.


                   Telix 3.00 Logitech 3-Button Mouse Menu V. 1.00


          Now, press the middle button.  You will see a pop-up overlay with
          the proper numbers for the page you are on.   Pressing  the  left
          button  once  (actually  any  button, but once you are out of the
          pop-up, the buttons revert to their defined values,  and  as  the
          left button is enter, it is good to get in the practice) will put
          the entry to be dialed on the dialing line.  This works no matter
          where  the  Lotus-style  line menu is.  (In order to access those
          functions, just press the  left  button  BEFORE  popping  up  the
          number  overlay,  pop  it  up,  select the range or whatever, and
          press  the  left  button  to execute, right to abort. Experiment;
          you'll get the hang of it more quickly that way than by reading.)
          If that's the only number you want to dial, press the left button
          again, and you're off!

          If  you  want to dial a queue, use the middle button, pressing it
          to select, then again to popup the overlay, then move and  select
          again,  until  you  have the queue you want.  Then just press the
          left button, and Telix will start dialing the queue.

          You will notice a "-" precedes all selected entries.  This is  to
          provide  another  feature not built into Telix, a default prefix.
          If you have one you use all the time,  like  *70W  or  1170W  for
          disable  call  waiting,  define the prefix "-".  It is ignored in
          all the other functions, like edit, delete, and the like, and  if
          it  is  undefined, it does not affect dialing at all.  If I could
          figure out how to use all four as selected defaults, I would, but
          one is better than none.

          The other mouse chords give you one last chance to abort an exit,
          without making you use the keyboard right after your hand  is  on
          the mouse.  These are the L+M Y (yes) and R+M N (no) functions.

          Color  note:  If you use color, and close to the "default" colors
          for Telix, replace the BOLD statements in the TELIX.DEF file with
          the number 3.  This gives you nice cyan pop-ups with red-on-white
          moving bars.  After saving the changes, type (assuming the  mouse
          subdirectory is in your path)  NEWMENU TELIX, and you are done.

          You can also add Telix to CLICK.SRC with the line:
                    Telix menu               ;Telix 3.00
          After  saving  that,  issue the command  NEWCLICK and you are all
          set!!!

          Note that if you run a mouse menu equipped editor, or Hotkey, the
          other program's mouse driver will wipe out this one.  Not  a  big
          problem  with  Telix; the Alt-V DOS command option can be used to
          call up the Telix  menu  again,  with  the  command  MENU  TELIX.
          Again,  this only works really well if the mouse stuff is in your
          path.


                   Telix 3.00 Logitech 3-Button Mouse Menu V. 1.00


          NOTE WELL:

          Because  of the change in the way Telix does directories (as large
          as needed), the checking involved in the  mouse  support  for  the
          dialing  directory  overlays  WILL  NOT  WORK  unless  you  do the
          following:

          Use the Add blank entry feature  to  pad  your  directory  to  150
          entries, NO MORE and NO LESS.  The menu will work unmodified then.
          If  you  have  more,  add  to  the  TELIX.DEF  file in pages of 15
          entries, and pad your directory with the Add  blank  option  to  a
          multiple  of  15.   Then  use NEWMENU as above, and all will work.
          Remember to add the labels for the added numbers as well!!




          Any comments, etc., direct to Rob Rapp, Exec-PC, (414)  964-5160,
          1200/2400  baud,  8N1.   Please  credit  me  if  you  adapt.   No
          particular reason - it's just nice.

          Enjoy.
                                     ++++ROB++++




