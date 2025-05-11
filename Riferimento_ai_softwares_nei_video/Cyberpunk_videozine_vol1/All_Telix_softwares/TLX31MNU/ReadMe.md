
                          T E L I X  R E L E A S E  3 . 1 0
                             Logitech 3-Button Mouse Menu

                              Written By Robert F. Rapp
                                  October 16, 1988

                                     Version 1.00


          Telix  lends  itself to mouse support, with its pop-up moving bar
          menus and the Lotus-style dialing directory.   It  has,  however,
          two  areas  of  weakness:  The command help menu, and the lack of
          any default prefix toggle, especially for call waiting. This menu
          provides, in a 3K menu, these capabilities.

          The mouse buttons follow the more-or-less accepted standards  for
          Logitech menus:

                    Left                          Enter
                    Middle                        Select (menu) Mark (dir)
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

          When  in  a  session, you can bypass the menu and use the L+R and
          ALL chords for up- and down- loading.  Just remember, fork up and
          fAll down.  (Is it apparent I'm an old time WordStar user?  We'll
          stretch mnemonics beyond belief!)

          Now  for  the  dialing directory. You can use the ALL (fAll down)
          chord to move down, one page of 15 entries at a  time.  Likewise,
          you can use the L+R (fork up) chord to move up a page of entries.

          To  dial  a  number, just move the mouse to highlight the desired
          number, move to Dial, and click the left button. If you  want  to
          dial  a queue, use the middle button, pressing it to select, then
          move  to the next choice, click the middle button, until you have
          the queue you want.  Then just press the left button,  and  Telix
          will start dialing the queue.  All other functions are  available
          by moving the mouse left or right and clicking the left button!



          Telix 3.10 Logitech Mouse Menu Version 1.00                Page 2


          That  is  it for the file TELIX.DEF and TELIX.MNU!  However, this
          does not address the lack of a default  prefix  toggle!   If  you
          always  use  call  waiting,  the place to put the *70W (for Touch
          Tone) is in the dialing prefixes.  However, if you are  like  me,
          you  may  have  need  for  a  way to toggle that on and off!  The
          second menu does that with the Disable  call  waiting  ON  &  OFF
          choices  on the menu overlay.  You will have to change the actual
          initialization strings that are in the  menu  to  your  own,  and
          recompile  the menu, unless you have a modem with nonvolatile RAM
          and two reset commands, ATZ0 and ATZ1.  You can use one  for  MNP
          on  and one for MNP off!  If you do this, the menu can be used as
          is, with the ATZ1 choice as Dialing prefix 1 and the ATZ0  choice
          as Dialing prefix 2.  Dialing prefix 3 is defined without a modem
          reset,  that  is,  as  ATDT,  with  or  without  the call waiting
          disabling command, per your choice!  If  you  wish  to  use  this
          menu,  rename  the  DEF and MNU file from TELIX_P.DEF and .MNU to
          TELIX.DEF and TELIX.MNU, after erasing the two files without this
          feature or moving them to another directory. In order for this to
          work properly, please note that Insert must be OFF (the default).

          The other mouse chords give you one other feature, without making
          you use the keyboard right after your hand is on the mouse. These
          are the L+M Y (yes) and R+M N (no) functions.

          Color  note:  If you use color, and close to the "default" colors
          for Telix, replace the BOLD statements in the TELIX.DEF file with
          the number 3.  This gives you nice cyan pop-ups with red-on-white
          moving bars.  After saving the changes, type (assuming the  mouse
          subdirectory is in your path)  NEWMENU TELIX, and you are done.

          You can also add Telix to CLICK.SRC with the line:
                    Telix menu               ;Telix 3.10
          After  saving  that,  issue the command  NEWCLICK and you are all
          set!!!

          Note that if you run a mouse menu equipped editor, or Hotkey, the
          other program's mouse driver will wipe out this one.  Not  a  big
          problem   with  Telix; write a batch file that summons the editor
          or Hotkey, and calls up the Telix mouse menu when it exits,  with
          the command MENU TELIX. Again, this only works really well if the
          mouse stuff is in your path.

          Note  also  that  the  printer  log toggle does nothing.  This is
          because  Telix  looks  for the scan code of Ctrl-@, not its ASCII
          value (which is NULL, ASCII  0).   You  cannot  assign  it  to  a
          function  key,  either, for the same reason.  I will keep working
          to fix this problem.  In the meantime, you will have to  use  the
          keyboard for that function!!

          Any comments, etc., direct to the Sysop  at  The  Anonymous  BBS,
          (414)   251-2580, 300/1200/2400/4800/9600 baud, 8N1 (the modem is
          a  Hayes  V-series).  I can also be reached as Rob Rapp, Exec-PC,
          (414) 964-5160, 1200/2400 baud, 8N1,  or  as  R.RAPP2  on  GEnie.
          Please  credit me if you adapt.  No particular reason - it's just
          nice.

          Enjoy.
                                     ++++ROB++++




