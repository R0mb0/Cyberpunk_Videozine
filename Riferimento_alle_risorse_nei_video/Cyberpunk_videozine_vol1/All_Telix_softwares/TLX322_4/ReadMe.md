
























     Host+

     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Program Reference Manual











                Copyright (C) 1986-94 deltaComm Development, Inc.

                              ALL RIGHTS RESERVED.




                            deltaComm Development, Inc.

                      P.O. Box 1185, Cary, NC  27512   USA

            (919)-460-4556 / (919)-460-4531 fax / (919)-481-9399 BBS


     Telix v3.22 - Host+                                    COPYRIGHT    ii





                                Copyright Notice





     Telix is Copyright (c) 1986-1994 by deltaComm Development, Inc.

     Host+ is Copyright (c) 1989-1994 by deltaComm Development, Inc.

     This document is Copyright (c) 1988-1994 by deltaComm Development, Inc.

     No parts of Telix or this document may be copied in part or in whole,
     except as provided in the License in the following pages.





                                   Disclaimer

     deltaComm Development, Inc., makes no warranty of any kind, either
     express or implied, including but not limited to implied warranties of
     merchantability and fitness for a particular purpose, with respect to
     this software and accompanying documentation.

     IN NO EVENT SHALL DELTACOMM DEVELOPMENT, INC., BE LIABLE FOR ANY DAMAGES
     (INCLUDING DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
     LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING OUT OF THE
     USE OF OR INABILITY TO USE THIS PROGRAM, EVEN IF DELTACOMM DEVELOPMENT,
     INC., HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.





                                   Trademarks

     Telix is a trademark of deltaComm Development, Inc.

     Many product names found throughout this manual are trademarks of var-
     ious companies.


     Telix v3.22 - Host+                                   COPYRIGHT    iii







                                C O N T E N T S

     1.   INTRODUCTION....................................................1
         1.1  Host+ Description...........................................1
         1.2  Machine Requirements........................................2
         1.3  Host+ Files.................................................2

     2.   Getting Started.................................................7
         2.1  Installing Host+............................................7
         2.2  First Time Configuration....................................8
         2.3  First Time Logon............................................9

     3.   Program Features - Sysop Online................................11
         3.1  Fast Logon.................................................11
         3.2  Status Box Toggle..........................................11
         3.3  Help Screen Toggle.........................................11
         3.4  Chat Mode Toggle...........................................11
         3.5  User Control...............................................12
         3.6  Local shell to DOS.........................................12
         3.7  Screen Image...............................................12
         3.8  Capture Log................................................13
         3.9  Hangup.....................................................13

     4.   Program Features - Sysop Offline...............................15
         4.1  Local Mode.................................................15
         4.2  Configure Host+............................................15
         4.3  User Editor................................................15
         4.4  File Compressor............................................15
         4.5  Text Editor................................................15
         4.6  Exit.......................................................15

     5.   User Commands..................................................17
         5.1  Access Levels..............................................17
         5.2  Message System.............................................17
         5.3  File System................................................19
         5.4  Page the Sysop.............................................21
         5.5  Bulletin Listings..........................................21
         5.6  Your Settings..............................................22
         5.7  Comment to Sysop...........................................22
         5.8  Expert Mode................................................22
         5.9  Run a Door.................................................22
         5.10 Goodbye....................................................22
         5.11 System Log.................................................22
         5.12 Shell to DOS...............................................23
         5.13 Shut down Host+............................................23


     Telix v3.22 - Host+                                     Contents    iv



     6.   Customizing Host+..............................................25
         6.1  Configuring the Modem......................................25
         6.2  Configuring the Colors.....................................26
         6.3  Configuring Bulletins......................................26
         6.4  Configuring Doors..........................................27
         6.5  Configuring Archives.......................................30
         6.6  Configuring Macros.........................................31
         6.7  Configuring Events.........................................32
         6.8  Configuring User Options...................................33
         6.9  Configuring the File Bases.................................34
         6.10 Configuring the Message Areas..............................35
         6.11 Configuring the Upload Items...............................36
         6.12 Configuring General Info...................................36
         6.13 Configuring BBS Data.......................................38
         6.14 Restoring and Saving Configs...............................38
         6.15 Creating Colorful Screens..................................39

     7.   Adding Files...................................................43
         7.1  Adding Files with ADDFILES.EXE.............................43
         7.2  Manually Changing Files....................................46
         7.3  Manually Moving/Removing Files.............................47

     8.   The User Editor................................................49
         8.1  User Fields................................................49
         8.2  User Fields you Cannot Edit................................51

     9.   The Files Compressor...........................................53
         9.1  Compressing the User File..................................53
         9.2  Compressing the File Base..................................53
         9.3  Compressing the Message Bases..............................54
         9.4  Running from a Batch File..................................54
         9.5  Repairing Damaged Files....................................55

     10.  Using Doorway.EXE..............................................57
     11.  Security.......................................................59

     12.  Registered Utilities...........................................61
         12.1 The Files Editor...........................................61
         12.2 The Menu Editor............................................62
         12.2.1   Making New Menu Screens................................64
         12.2.2   Customizing Menu Commands..............................65
         12.3 The External User Editor...................................68

     13.  Appendix A - Installing Doors..................................71
     14.  Appendix B - Example Events....................................73
     15.  Appendix C - Product Support...................................77
     16.  Appendix D - File Formats......................................79
         D.1  HOSTDOOR.SYS...............................................79
         D.2  Custom Converters..........................................83

     17.  Appendix E - External Archive Testing..........................87

     18.  Index..........................................................89


     Telix v3.22 - Host+                                 Introductions    1



     1.   INTRODUCTION



     1.1  Host+ Description
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Host+ is a remote system that may be used as a complete BBS.  It is
     fast, friendly, extremely flexible, and powerful enough to be
     customized for each person's tastes. Even novice computer users may
     have it up and running in minutes.

     Host+ has been written for the Telix communications program using SALT
     (Script Application Language for Telix) -- a powerful and extensive
     communications script language.

     Here are some of the advanced features you will find in Host+:

        ş Fully working message bases, file bases, ability to drop to DOS,
          and support for user added doors.

        ş May be configured to run multiple conferences for files and
          messages.

        ş A FSME (Full Screen Message Editor) that allows quoting of
          messages. Messages may be up to 99 lines long.  A Line Message
          Editor is included for those whose machines do not support ANSI.

        ş Add any file from any drive to the files base with the
          ADDFILES.EXE program. Accepts 1000 files per directory and 100
          tagged files with full mouse support.

        ş A file management program, or file compressor (HPCOMP.EXE)
          controls all message, file, and user databases.

        ş 10 user levels.  You decide each level's access to features and
          on line time. The trash can list allows you to have a text file
          of names you don't want on your system.

        ş Host+ keeps track of the user's time on per day. A user that has
          60 minutes a day and uses 45 on the first call will only have 15
          minutes left.

        ş Program up to 5 different events at any time of the day.  The
          special event time of "every" will run an event after each call.
          Special Event programs allow the event to abort both the Host+
          and Telix programs.

        ş New status log file (HOSTPLUS.LOG) supplies complete information
          on what happens while users are online with Host+.  It logs
          bulletins read, doors opened, events run, total minutes used on
          the system by each caller, if carrier was lost, time running out,
          and no input in five minutes.


     Telix v3.22 - Host+                                 Introductions    2



        ş Support for user added doors.  Host+ supports PCBoard 14.x, QBBS,
          RBBS, and GAP/DOORWAY doors.

        ş Support for Marshall Dudley's DOORWAY program for greater control
          over the shell to DOS from remote.

        ş Support for external protocols that have been added to Telix by
          you (except for Bimodem and HS/Link).

        ş Support for up to 10 different archive programs.  Default
          programs supported are ZIP, PAK, ARC, ARJ, and LZH.  You may add
          support for more.

        ş Full keyboard macro support.  You may reassign all keys on the
          keyboard, including those used by Host+.



     1.2  Machine Requirements
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Host+ requires a minimum of 350k memory and requires Telix 3.12 or
     later and DOS version 3.22 or later.  A hard drive is highly
     recommended.


     1.3  Host+ Files
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Host+ comes with a number of files and creates more in its operation.
     Following is a list of files included with Host+ and comments about
     their being required for operation:

          HINSTALL.EXE        This is the installation program. Once used
                              it may be deleted.

          HOSTPLUS.DAT        This contains the Host+ program files in a
                              compressed format.  HINSTALL extracts the
                              files and puts them in the correct
                              directories.  You may delete this file
                              following installation.

          HOSTPLUS.SLC        This is the main program script.  It is the
                              script which you call in order to run Host+.

          HOSTPLUS.OVL        This contains the screen overlays for Host+.

          HPUTILS.SLC         Utilities script, it contains the Configure
                              Program and the User Editor Program. It is
                              called by the HOSTPLUS.SLC program. It may
                              also run in Telix by typing HPUTILS after
                              pressing Alt-G. It will be placed in your
                              script directory by HINSTALL.


     Telix v3.22 - Host+                                 Introductions    3



          HPMSGED.OVL         Message Editor script overlay, contains all
                              of the message editor routines. It will be
                              placed in your script directory by HINSTALL.
                              HPMSGED.OVL may be deleted if you do not wish
                              to use the message editor or have no message
                              base.

          HPMENUS.DAT         This is the file which contains all of the
                              menus for each of the levels as well as the
                              sections. It will be placed in your Host+
                              data directory by HINSTALL.

          HPCOMP.EXE          This is the file which does all the data file
                              compression.  It will be placed in your Telix
                              directory.

          *.HP                Door Converter overlays, contain all the
                              information to convert to the different BBS
                              systems. They will be placed in your Host+
                              data directory. Current converters: GAP.HP,
                              PCB14.HP, QBBS.HP.  If you do not want to
                              have support for a specific BBS type, then
                              you may delete the converter for that BBS.

          HOSTPLUS.LNG        This file holds all of the BBS commands in
                              English. Future versions will be able to run
                              in other languages.

          HOSTPLUS.LIB        This library file holds all of the command
                              overlays used in the configuration program.



     Files created and maintained by Host+ throughout its operation (and
     held in the Host+ data files directory) include:



          HPUSER.DAT          This is the file that holds all of the user
                              information.

          HOSTPLUS.LOG        This is the log of what each user does when
                              on the system.

          HPFBASE.DAT         This holds the number and name of each files
                              base.

          HPFILES.*           This is the file that holds all of the file
                              database information.  The file extension is
                              the number of the database.

          HPMBASE.DAT         This holds the number and name of each
                              message base.


     Telix v3.22 - Host+                                 Introductions    4



          HPINDEX.*           This file holds the message pointers for each
                              user for each message base. The file
                              extension is the number of the database.

          HPHEADER.*          This is the header information for each
                              message in the message base. The file
                              extension is the number of the message base.

          HPMSG.*             This holds the actual messages for the
                              message base. The file extension is the
                              number of the message base.

          HPDOORS.DAT         This file contains all of the information you
                              enter when you configure to run a door
                              program.

          HPBLTS.DAT          This file contains all of the information you
                              enter when you configure bulletins.

          HOSTPLUS.CFG        This file holds all of the other
                              configuration information you enter when you
                              customize Host+.

          HOSTPLUS.KEY        This file holds all of the Macros you create.



     Files created as an option, and which may be deleted if not needed
     are:

          ADDFILES.EXE        The ADDFILES program for addling files to the
                              files base. It should be placed in the Telix
                              directory.

          HSHELL.BAT          This batch file is supplied in the Telix
                              documentation. If in the Telix directory it
                              will be run if a online user does a shell to
                              DOS. It will override all other shell
                              options. The order in which the shell options
                              take precedence is:

                              HSHELL.BAT
                              DOORWAY.EXE
                              CTTY COMx

          TRASHCAN.DAT        If this ASCII text file is found in the Host+
                              data directory it will determine if any name
                              given by a new user is acceptable. (See
                              Security and Legal)

          *.ANS               These files are the BBS ANSI graphics files
                              you create. You may make a LOGON, NEWUSER,
                              BBSINFO, NEWS, and LOGOFF file.  (See
                              Customizing Host+)


     Telix v3.22 - Host+                                 Introductions    5



          *.ASC               These are the ASCII versions of the ANSI
                              graphics files you created.  Have these made
                              for those users who don't have ANSI available
                              to them.

          HPLOGON.SLC         If this compiled Salt file exists in your
                              Telix Script Directory, Host+ will run the
                              script during the logon process just before
                              the prompt for message check.  This script
                              may call a quote of the day program, message
                              to next caller door, or whatever your script
                              writing abilities permits.


     Telix v3.22 - Host+                               Getting Started    7





     2.   Getting Started



     2.1  Installing Host+
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The proper way to run Host+ is to either have your Telix directory
     listed in your DOS path statement or listed as an environment variable
     (SET TELIX=C:\TELIX\) in your AUTOEXEC.BAT.  Make these changes and
     reboot your computer.

     If you have made the changes above, place the files HINSTALL.EXE and
     HOSTPLUS.DAT in any directory on your hard drive and run HINSTALL. If
     not, place the files in the directory that holds TELIX.EXE and run
     HINSTALL.

     HINSTALL will ask you if you wish \TELIX\HOST to be the directory
     where Host+ will keep its data files. If you want to change this do it
     now. HINSTALL will then expand and place the different files into
     their correct directories.

     If HINSTALL finds any data files from previous versions of HOST+
     (Formerly Host Software Products' Host3, versions 4.1, 4.2, 4.3, 4.4,
     or 5.0) it will convert them. It will then place the newly converted
     data files into the data directory.  It will ask if you want to delete
     the old files that are no longer needed by Host+ before deleting.

     HINSTALL will not bother any key DOS files like CONFIG.SYS or
     AUTOEXEC.BAT.

     If you are upgrading from a previous version of Host+ from Host
     Software Products, you will need to repack all the message, file, and
     user data bases when you first start Host+.  To do this, press Alt-F
     at the opening menu of Host+.  Then press F6 to pack all bases.
     Should there be a problem in the conversion, you can run HPREPAIR.EXE
     to fix the database.

     Following the installation process, you may erase HINSTALL.EXE and
     HOSTPLUS.DAT.

     Configuration and customization of Host+ require that Host+ be loaded
     and running.   To load and run Host+, type Alt-G from within Telix's
     terminal mode and type "HostPlus" as the name of the script to
     execute.   Host+ is now operating and waiting for a call.   Before you
     may actually accept calls, you will want to modify some of the
     defaults options of the Host+ configuration.


     Telix v3.22 - Host+                               Getting Started    8



     2.2  First Time Configuration
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     From the Host+ main menu, press Alt-O for the Configuration menu.  You
     will be presented with a long column of options.  To select an option,
     you may either move the cursor bar to the item or press the letter of
     the alphabet that is listed out to the side.

     Here are some of the things you may want to attend to when first
     starting the program.  You will notice that the modem picks up the
     line when you go into the configure menu. This is to keep Host+ from
     answering a call while you are working.

     Host+ comes configured to test archives that use the ARC, PAK, ZIP,
     ARJ, and LZH archive methods. Your archive programs must be found on
     the DOS path for this to work. If these files are not present on your
     system, you may obtain them from the Telix Support BBS.

     Under General Items you will want to put your own password in place of
     the word "Password".  The system password allows callers who have co-
     sysop access to shell to DOS. It also allows the sysop to shut  the
     system down from a remote system.

     You may wish to put your name in place of Sysop at selection F.  If
     you plan to make local logons under your own name, then your name
     needs to go here so you will get any mail addressed to the Sysop.

     Under User Items, Item A asks if you want to log off new users.  This
     is a good security practice to follow once you have your board in
     normal operation.  It needs to be turned off now or the first test of
     your system with a live caller will be very, very short.

     User Item B sets the file ratio for your users.  Putting a zero (0)
     means that no file ratio will be enforced.  Putting any other number
     here means that the user will have to maintain a file ratio of uploads
     to downloads.  For example, if you want to require that one file be
     sent up for each 5 files taken, then put a 5 here.

     User Item D sets the access level that you want new callers to have.
     Items E-N set how much time each access level gets on line each day.

     Under Upload Items, set item A to the name of the drive and directory
     where you want uploads to go.  If you do not want to users to see the
     uploads that are available, set item C to the level you want.

     Host+ should now be ready to run under its minimal configuration.
     Host+ is very powerful and may be completely customized.  Complete
     details regarding customization of all options are in this reference.
     First, however, you may wish to see Host+ in operation.


     Telix v3.22 - Host+                               Getting Started    9



     2.3  First Time Logon
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Now you are ready to take a peek inside of Host+. From the main menu
     of Host+ press Alt-L for a Local logon.  You will see the prompt  "Can
     you support ANSI color graphics?"  answer with a Y and a carriage
     return.

     You will then be asked the familiar series of questions that are asked
     of any person logging on to a BBS for the first time.  Your answers
     are being stored in the user database.  When you are finished, you
     will be asked if you wish to check for messages in the message base.
     Press "Y" to see the display.

     Now you are at the main user menu.  At the top of the screen will be a
     status line showing your name, address, access level, and password.
     Press Alt-Z to toggle that display. It will now show you the sysop
     commands that are available. (See Sysop Commands for complete
     description).

     If you left the defaults in place, you will have four minutes
     remaining online.  Press F4 a few times and watch your access level
     raise on the status bar at the top of the screen.  Press enter and the
     screen will recycle.  The user display should now show that have
     increased time on line.

     Keep pressing F4 until your access level is a 9. Host+ will ask if you
     really want to raise to a Sysop level, say yes. Press enter to recycle
     the page and you will see that you have more time.  You will also see
     the higher access menu that is available to callers with access above
     level 7.

     Now you may experiment inside the program using the list of sysop and
     menu commands listed on the next few pages.  To shell to DOS, just
     press Alt-J.  You may try out the message menu by leaving a test
     message.  You may wish to add a file (see the section on adding files
     to Host+).

     When you exit the local logon, press F2 for the user editor and edit
     your listing to upgrade yourself to sysop level.  (see The User Editor
     for more information).

     You are now ready to have someone call and log on as a remote user to
     test out your modem.  You are also ready to add files, screens,
     bulletins and doors.  For complete information on these functions, see
     Customizing Host+.


     Telix v3.22 - Host+                             Program Features    11



     3.   Program Features - Sysop Online

     As sysop, you are in control of what happens in Host+ at all times.
     At the top of the screen is a status box showing what is happening in
     Host+.  You may toggle this box on and off by pressing Alt-8.  The
     status box will show you the name of the person on line, their city
     and state, password, access level, date last on the system, the baud
     rate, chat mode status and if the person has requested a chat in your
     absence.

     You may toggle the Status Box into a help screen by pressing Alt-Z.
     This will list some of the more commonly used sysop commands.


     3.1  Fast Logon
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You may skip the opening screen by entering the following information
     at the "Can you support ANSI?" prompt:

     Y{First and Last names{Password

     "Y" is if you can support ANSI graphics; if not, use an "N" instead.
     The brackets must be present with no spaces.  To speed up local
     logons, you may create a macro that will hold all this information.
     See the section on Macros to find out how.


     3.2  Status Box Toggle
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-8:    Turns the status box of Host+ on or off. Having it off will
               increase the size of the viewable area onscreen.


     3.3  Help Screen Toggle
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-Z:    Allows the sysop to change between the status and help
               boxes.


     3.4  Chat Mode Toggle
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     F1:       This toggles the caller's ability to request chats.  If chat
               is on, an alarm will sound when the user requests a chat.
               When chat is off, no alarm will sound and the user will be
               given the option of leaving a message.  You may force chat
               on or off at any time by pressing F1.  When chat is forced
               on, the status box at the top will show "chat on" in a
               different color.

          (See Customizing Host+ more detail on Chat Hours).


     Telix v3.22 - Host+                             Program Features    12



     3.5  User Control
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     F3:  Lower Access
     F4:  Raise Access
     F5:  Lower Time
     F6:  Raise Time
     F10: Chat with User

     You may temporarily lower a user's access level by pressing F3 for
     each level you wish to remove.  The new level will only be in effect
     for that call only. Host+ will restore the old level at log off.

     You may temporarily raise a user's access level by pressing F4 for
     each level you wish to add.  The new level will be in effect for that
     call only.  Host+ will restore the old level at log off.

     You may temporarily lower the user's time on line by pressing F5 for
     each five minutes you wish to remove.  The time you take away will be
     in effect the entire day.  At midnight, Host+ will reset the time to
     normal.

     You may temporarily raise the user's time on line by pressing F6 for
     each five minutes you wish to add.  The extra time you give will be
     available to the user for that entire day.  At midnight, Host+ will
     reset the time to normal.

     Press F10 to initiate a chat with the user.  You may carry on a key
     board conversation as long as you like without effecting the user's
     time on line.  Press escape to exit chat.


     3.6  Local shell to DOS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-J:    You may shell to DOS at any time unless there is a file
               transfer or door running.  The user will be prompted to wait
               while the sysop is in DOS and Host+ will not accept any user
               commands until you return.  The user will not lose any
               online time while you are in DOS.


     3.7  Screen Image
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-I:    You may capture an image of the screen to a file by pressing
               Alt-I (just like you do in Telix).  The name of the text
               file is HOSTPLUS.IMG.


     Telix v3.22 - Host+                             Program Features    13




     3.8  Capture Log Access
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-C:    When you turn on the capture log, it will capture everything
               the user does to a capture file (HOSTPLUS.CAP).  This
               capture file will become extremely large very quickly as it
               contains all information printed to the screen.


     3.9  Hangup
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-H:    If you wish to terminate a call in the middle of a session,
               press Alt-H and the modem will hang up.


     Telix v3.22 - Host+                             Program Features    15




     4.   Program Features - Sysop Offline


     4.1  Local Mode
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-L:    This allows you to run Host+ in local mode.  All the menu
               commands will work for you (with some exceptions, see Menu
               Commands below).


     4.2  Configure Host+
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-O:    This runs the HPCONFIG program that sets up Host+ for
               initial running and allows you to customize the program. See
               Customizing Host+ for more on this program.


     4.3  User Editor
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     F2:       This brings up the user editor.  Note that there must be at
               least one user, otherwise the user editor will not work. If
               you have already made your local logon (see First Logon) you
               will have become the first user in the user database. (See
               The User Editor for more information).


     4.4  File Compressor
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-F:    This will run the database files compressor (HPCOMP.EXE) for
               use on User, Message, and Files databases.  See The Files
               Compressor for more information on running this program.


     4.5  Text Editor
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-A:    This will run the Text Editor you have selected to use in
               Telix.  If you have not selected a text editor in Telix,
               this command will not work.


     4.6  Exit Host+
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alt-X:    This allows you to Exit Host+ back to Telix.


     Telix v3.22 - Host+                                User Commands    17




     5.   User Commands


     5.1  Access Levels
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     There are two sets of menus in Host+:  Lower and Higher access menus.

     Users with access levels of 0-6 will see lower access screens for Main
     Menu, and Files Menu.  Access levels of 7-9 will be shown the higher
     access menus for Main Menu and Files Menu.  The Message Menu is the
     same for all levels.

     Registered Users of Host+ will receive the HPMENUS program. It allows
     you to draw your own menus and set the access level to any menu
     function. You may also change the letter that starts any function, and
     add three external functions.  See the section on Registered Programs.


     5.2  Message System
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The (M)essage System option opens the Message Base menu for users with
     access levels 0 and higher.  Here is the listing of all user commands
     under the Message System menu.

     (A)rea

     This will show the list of message areas you have defined for Host+
     and allow the user to choose one.   For more information on setting up
     multiple message areas, see Customizing Host+

     (R)ead

     This shows the user a list of commands to use when reading the message
     base.

          (A)gain        :    Read current message again.
          (N)ext         :    Read next message.
          (P)revious     :    Read previous message.
          (R)eply        :    Reply to current message.
          (K)ill         :    Kill current message (allowed only
                              to the sender, receiver, or level 9
                              user).
          (Q)uit         :    Quit reading messages.

     The user may jump ahead or go back in the message base by entering the
     number of the message they wish to access.  For instance, if there are
     112 messages in the base and you are at #1, you can enter 112 and go
     to the last message.  Then you can press "P" for previous and read the
     messages in reverse order.

     (W)rite Message


     Telix v3.22 - Host+                                User Commands    18



     This allows the user to write a message to another user (either Public
     or Private).

     How to Write Messages or Reply to Messages

     Writing new messages or replying to existing messages calls the editor
     in Host+.  Here is the step by step listing of functions:

     Name

     Host+ will first ask for the name of the person you are writing. To
     abort the message at this point, just press a carriage return.  Sysops
     may leave global messages that will appear with the user's name
     instead of "all" by entering @user.

     Title

     Host+ will next ask for the title (or subject) of your message. To
     abort at this point, press a carriage return and the message will
     abort.

     (P)ublic or (R)eceiver

     If you want the message to be private, press "R" for receiver only.
     Level 9 users (sysop) may read all messages.  You may wish to post
     this information to your users.

     Full Screen Editor

     You are given three options for entering messages: Full Screen Editor,
     Line Editor, and Upload message.

     Uploaded Messages

     If you wish to upload a prepared message, press "U" for upload. Local
     logons will be asked for the path and name of the file on the hard
     drive. On-line users will be asked to upload the message using an
     ASCII upload.

     Line Editor

     If you do not want the full screen editor, press "N" for the line
     editor.  You can then enter your message line by line.  You may only
     edit a line when you are on it.  Once you have entered the line, it
     cannot be edited.  Pressing enter twice will give you a menu with the
     following options:

          (A)bort        :    Kill the message
          (S)ave         :    Save the message
          (R)edraw       :    Redraws the screen
          (C)ontinue     :    Continues the message at the point
                              you left off
          (O)riginal     :    Allows you to quote the message to
                              which you are replying.


     Telix v3.22 - Host+                                User Commands    19



     Pressing "O" will cause the original message to be displayed with line
     numbers to the left.  You will be asked what line number to start for
     the quote.  When you enter that number, you will be asked for the line
     number to end the quote.  If you want the whole message, press enter.

     Full Screen Editor

     Press "Y" for the Full Screen Editor. This allows you to move about
     the message editing and writing as you wish.  Press Ctrl-Z at any time
     to get a help screen displayed with the following information:

          ^D Move one char left    ^F Move one character right
          ^R Move one line up      ^C Move one line down
          ^E Line beginning        ^X Line ending

          ^Y Delete Line           ^V Overtype/Insert Mode
          ^T Redraw Screen         ^O Original (quoting)

     You may also use the cursor keys, the backspace, home, end, delete,
     page up and down if you are using a 101 key enhanced keyboard.

     Ctrl-O will call up the original message on the screen.  You may
     select to quote the whole message and then edit the quote on screen
     using your cursor controls.  Otherwise, you can just quote the portion
     you want by telling Host+ what lines to include.

     Pressing <ESC> will call up a menu along the bottom of the screen with
     the following options (just like the line editor):

          (A)bort             :    Kill the message
          (S)ave              :    Save the message
          (R)edraw            :    Redraws the screen
          (C)ontinue          :    Continues a message at the
                                   point you left off
          (O)riginal          :    Allows you to quote the
                                   message to which you are
                                   replying.

     (Q)uit to Main Menu

     This allows the user to go back to the main menu.



     5.3  File System
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ


     The (F)ile System option opens the File Base menu for users with
     access levels 1 or higher.  The following file commands are available
     to users of the file menu.   Differences in access levels are
     explained.

     (A)rea


     Telix v3.22 - Host+                                User Commands    20



     This will show the list of file areas you have defined for Host+ and
     allow the user to choose one.   For more information on setting up
     multiple file bases, see Customizing Host+.   This command is
     available to all users.

     (F)iles List

     This shows the user a listing of the files that are available for
     users at their level.  The list includes file name, file size, file
     date, and a two line description of the file.

     (X)tended File list

     This allows the user to see an expanded listing of the files available
     that includes the all the information listed above plus the
     approximate time for the transfer and the name of the person who
     uploaded the file.

     (U)pload

     Allows user to upload a file (if not already in the file database) to
     the system. The user may use any protocol (except for Bimodem) that
     has been defined in Telix.

     The user will be asked for the name of the file.  They do have to
     include the file extension (ZIP, ARC, PAK, LZH, and etc).  If they
     have not defined a protocol as their default (see main menu (Y)our
     defaults), they will be shown a list of protocols available and asked
     to choose one.

     Local uploads inside Host+ are available to the sysop.  See Adding
     Files to Host+.

     (D)ownload

     Lets the user Download files from Host+.  If you have specified it in
     HPCONFIG, Level 1 users may only download a specified limit. (see
     Customizing Host+) )

     The user will be asked for the name of the file.  The default file
     extension is .ZIP. If they have not defined a protocol as their
     default (see main menu (Y)our defaults), they will be shown a list of
     protocols available and asked to choose one.  They will then be asked
     if they wish to hang up after the transfer.

     Higher access users (above level 6) may download any file on any
     drive.  This makes it easy to send a file that is not in the file
     database to a user.  Just temporarily upgrade them to a level 7 or 8
     and type in the full drive and path to the file.

     (V)iew Archive

     Lets the user look inside the archive file to see the list of all
     compressed files and technical data.  Higher Level Access users may


     Telix v3.22 - Host+                                User Commands    21



     view any file on the system.  Lower Level Access users may only view
     those files in the file listings.

     (E)xtract Archive

     Lets the user extract files from an archive.  The user is first asked
     for the name of the archive.  Then they are asked if Host+ needs to
     show the list of files in the archive.  The file is then extracted
     from the archive and zipped (using PKZIP), into a temporary file
     called TEMPARC.ZIP.  The user is given the filename for downloading.
     The file is deleted when the user hangs up.

     Higher Level Access users may extract any file on the system.  Lower
     Level Access users may only extract those files in the file listings.

     (S)how a Directory Listing (Higher Access Only)

     Allows user to do a listing of the files in any directory on any
     drive.  For instance, "\telix\*.cap" would show all the capture files
     in the telix directory. Pressing enter at the directory prompt will
     give you the file list for the upload directory.

     (C)hange File (Higher Access Only)

     This option allows the sysop to manually change the file information
     in the database. (see Adding Files to Host+)

     (R)emove File (Higher Access Only)

     This option allows the sysop to remove a file from the database.  It
     also allows the sysop to erase the file from the drive. (see Adding
     Files to Host+)

     (Q)uit to Main Menu

     This allows the user to go back to the main menu.

     5.4  Page the Sysop
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The (P)age Sysop option will, if chat is on, ring a bell to alert you
     that the user wants to chat. If chat is off, it will show a message
     saying that you are not available and give them the option of leaving
     a private message.   To answer a page, press the space bar and the
     chat screen will come up.


     5.5  Bulletin Listings
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The (B)ulletin listings option sends the user to a list of bulletins
     they can select to view.


     Telix v3.22 - Host+                                User Commands    22



     5.6  Your Settings
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     (Y)our Settings lets the user change their address, city, zip, state,
     choose a default protocol, turn the pause function on or off, enable
     disable ANSI, change password and change colors.


     5.7  Comment to Sysop
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     (C)omments To Sysop will allow the user to write a private message to
     the "Sysop" (If you have defined your name in place of the Sysop it
     will be sent to you.  See either Start Up Configuration or Customizing
     Host+ (Section: General Options, Comments Sent To).


     5.8  Expert Mode
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The (X)pert function allows the user to change their expertise level,
     to one of three levels:

     Novice              Gives a menu of commands.
     Intermediate        Gives command letters on the input line.
     Expert              No help whatsoever!


     5.9  Run a Door
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Run (D)oors sends the caller to a list of the doors that are available
     to users in their access level.  They select the door to run from that
     list.


     5.10 Goodbye (Logoff)
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     (G)oodbye logs off the user from the system.


     5.11 System Log
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     System (L)og shows the user the daily usage log. Ctrl-P will pause the
     display, and Ctrl-X will abort.  The user may also select to continue
     or abort at the "(Y/n):" prompt.

     This command is only available from the higher access menus.


     Telix v3.22 - Host+                                User Commands    23



     5.12 Shell to DOS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     (S)hell to DOS lets the user shell to DOS. They will be prompted for
     the system password. If they fail to enter it, they will not be
     allowed to shell. Host+ will either use CTTY or DOORWAY.EXE to control
     the shell to DOS.

                                   IMPORTANT!

     There is no way for Host+ to check on the status of the carrier. If
     the carrier is lost while a user is in DOS (via remote) then the
     system will hang!. The only solution if this happens is to reboot the
     computer.  You may avoid this problem by using the shareware program
     DOORWAY.EXE (see Using Marshall Dudley's Doorway).


     5.13 Shut down Host+
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The (Z) command is not listed on the menu, and is available only to
     level 9 users from the main menu.  It allows the system to be shut
     down by remote.  The user will be prompted for the system password. If
     they fail to give it, the program will continue running.


     Telix v3.22 - Host+                            Customizing Host+    25



     6.   Customizing Host+

     Host+ allows you to customize its operations in many ways by running
     HPCONFIG by pressing Alt-O from the main menu.  You can add bulletins,
     different archive programs, doors, multiple conferences, and more.
     The following is a listing of the configuration menu and how to
     customize each item.

     When you have changed an item in the configuration, remember to press
     "X" at the main config menu to save your changes.


     6.1  Configuring the Modem
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A    Modem Answer String

          This is the string which is sent to the modem when a RING is
          detected. The default is "ATA^M" and should work for most modems.
          If it does not work for your modem try turning on Modem Auto
          Answer Mode.

     B    Answer On Ring Number

          This allows you to determine how many rings Host+ will wait
          before answering an incoming call. You may choose from 1 to 9
          rings. The default is set for 1 ring.

     C    Modem Pickup String

          This is the string which is sent to the modem when going offhook
          (in conjunction with Pickup Modem in Local and Utils). This
          string "ATM0H1^M" will make the modem pickup the line.

     D    Pickup Modem In Local

          This option decides if Host+ will pickup the phone (go offhook)
          when doing a local log on. Having this turned on would cause any
          callers to get a busy signal when you are in the local mode.

     E    Pickup Modem In Utils

          This option decides if Host+ should pickup the phone (go offhook)
          when running any of the utility programs.

          Some modems may go offhook and leave the speaker on.  The M0
          command turns off the speaker on most modems.  If your speaker is
          left on, check your manual for the proper command.



     F    Modem Auto Answer Mode


     Telix v3.22 - Host+                            Customizing Host+    26



          This option uses your modem's Auto Answer Mode instead of letting
          Host+ answer the incoming call.  The default is set to Off and
          should only be changed to On if Host+ is unable to answer
          incoming calls.


     6.2  Configuring the Colors
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This option allows you to configure the color of each screen element
     used on the Sysop side in Host+.  You control the colors for boxes,
     help and titles, options, highlights, items, Sysop Chat, and User
     Chat.  Select the item you wish to change and you will be shown a
     color palette box.  Use the Cursor keys to move to the color selection
     you desire.  As you move the cursor, the screen element you are
     changing will change colors on screen. When you find the color you
     like, press enter.

     You may go back to the Default Colors that came with Host+ by pressing
     "H" for "Use default colors".  You may also set Host+ to work in
     monochrome by pressing "I" for "Use Black & White color".


     6.3  Configuring Bulletins
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You may create Bulletin screens to be viewed by users.  Use this
     section for news, board policies, game door standings, and any number
     of things. Bulletins may be in either ASCII or ANSI formats.

     A    Add a Bulletin

          When you press "A", HPCONFIG will prompt you to input the full
          path and filename of the bulletin file.  If you had the file
          BULL1.ANS in the C:\TELIX\BLTS directory you would input
          C:\TELIX\BLTS\BULL1.ANS as the filename. Once you have input the
          filename press Enter.  You may abort the process by pressing
          Escape at any time.

          Now HPCONFIG will ask for the description you want shown to the
          user when they view the bulletin list.  Put a brief description
          of the bulletin here.

          Next HPCONFIG will ask for the access level of the bulletin.  If
          you wish to limit the users who may view that specific bulletin,
          then you would put that access code here.  If you want it
          available to all, put in a 0.

          The bulletin is now in the system and available to be seen by
          users.

     B    Delete a Bulletin


     Telix v3.22 - Host+                            Customizing Host+    27



          When you press "B" you will be asked for the number of the
          bulletin you wish to delete.  It will then ask you to confirm the
          deletion with a Y/N prompt.  When you answer "Y", the bulletin
          will be removed from Host+. The program will not remove the
          bulletin file from your drive.  You will have to do that yourself
          in DOS.

     C    Edit a Bulletin

          If you want to come back and make changes in an entry, you may do
          that here.  The program will take you through each of the options
          (filename, description, and access) and ask what you want to
          change.  To abort the process just press Escape.

     D    Jump to a Bulletin

          This option will allow you to jump to specific bulletin by
          entering its number.

     X    Exit To Main Menu

          This option will exit you back to the Main configuration menu.
          Remember to press "X" at the Main configuration menu to save your
          changes to disk.


     6.4  Configuring Doors
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A door is when a user is allowed to exit Host+ and run another program
     on your computer.  It is as if a door is opened from Host+ allowing
     the user access to other parts of your computer.

     There are many doors available in the BBS world that do a multitude of
     things:  Playing games, voting on questions, viewing ANSI screens,
     storing time, and so forth.  In addition, there are door programs like
     Marshall Dudley's DOORWAY.EXE that allow users to run IBM character
     based business programs like spreadsheets, word processors, or
     databases.

     Host+ will accept four types of program files: EXE, COM, BAT, and
     Telix's SALT SLC. It directly supports door programs written for
     PCBoard 14.x, GAP, QBBS, RBBS, and Remote Access BBS programs. It will
     also support Marshall Dudley's DOORWAY program.

     Setting up doors require some patience because there is no standard
     way of installing a door.  You have to figure out how to install a
     door and then configure it with HPCONFIG.  In Appendix "A" are
     outlined several examples of door installations.  You may also get
     help from a local sysop who has doors on his board and has undergone
     the same process.

     Once you have followed the door's installation procedure you are ready
     to configure the door for Host+.  Be sure to write down any command


     Telix v3.22 - Host+                            Customizing Host+    28



     line switches that you will need to start the program because you will
     asked to supply them to HPCONFIG.

     A    Add a Door

          Once you press "A" HPCONFIG will prompt you for the full path and
          filename to the door program.   For instance, a game door called
          GOLF.EXE in the \DOOR\GAME directory would be entered as:

          C:\DOOR\GAME\GOLF.EXE

          When you have input the filename press Enter.

          HPCONFIG will next ask you for the command line.  If you need to
          pass parameters to the program put it here.  For instance,
          GOLF.EXE requires the name of its configuration file called
          GOLF.CFG to run.  You would put GOLF.CFG on the command line.
          There are system variables that you can place on the command line
          to pass current information to your door program:

          %C   Comm Port Number    :    Current Comm Port Number
          %P   Port Address        :    Current Comm Port Address
          %I   IRQ Line            :    Current Comm Port IRQ
          %B   Baud Rate           :    Current Baud Rate
          %D   DTE Rate            :    Current DTE Rate
          %M   Minutes Left        :    Minutes User Has Left
          %S   Seconds Left        :    Seconds User Has Left
          %L   Location Of File(s) :    Location the Door

          When finished with the command line (or if there were not any
          parameters needed) press Enter.

          Now HPCONFIG will ask for the description you want shown to the
          user in the list of available doors.  Put a brief description of
          the door here.

          Next HPCONFIG will ask for the access level you wish the door to
          have.  If you wish to limit the users who may operate that
          specific door then you would put that access code here.  If you
          want it available to all, put in a 0.

          The last thing HPCONFIG will ask is what (if any) converter is
          needed for the door.   Each BBS door program requires its own
          special system file. QBBS/RBBS doors need DORINFO1.DEF, PCBoard
          14.x requires PCBOARD.SYS, Gap and Doorway want DOOR.SYS, and so
          forth.

          Host+ writes its own system file (called HOSTDOOR.SYS) and then
          converts it to match the BBS program you chose.  It will then
          write this system file into the directory with the door's program
          file.  In our example above, it would write the file into the
          C:\DOOR\GAME directory.


     Telix v3.22 - Host+                            Customizing Host+    29



          If the door is written for Host+ or does not require a system
          file then choose the "No Converter" option.

          Once you are through with configuring the door, remember to save
          your changes by pressing "X" at the Main configuration menu.  You
          will then want to log on to Host+ in local mode and test the door
          out.  You are configuring two programs at once (the door and the
          bbs) so, be prepared to repeat the process.

          If you have made a mistake you can easily edit the information by
          choosing the "Edit a Door" option. If it still doesn't work check
          to make sure you have installed the door correctly.

     B    Delete a Door

          When you press "B" you will be asked for the number of the door
          you wish to delete.  It will then ask you to confirm the deletion
          with a Y/N prompt. When you answer "Y", the door will be removed
          from Host+.  The program will not remove the door's program files
          from your drive.  You will have to do that yourself in DOS.

     C    Edit a Door

          If you wish to come back and make changes in an entry you can do
          that here. The program will take you through each of the options
          (filename, description, access, and converter) and ask what you
          want to change.

     D    Jump to a Door

          This option will allow you to jump to specific door entry.

     X    Exit To Main Menu

          This option will exit you back to the Main configuration menu.
          Remember to press "X" at the Main configuration menu to save your
          changes to disk.


     Telix v3.22 - Host+                            Customizing Host+    30




     6.5  Configuring Archives
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     When a user uploads a file, you will want to test the archive to make
     sure that it has arrived in good condition.  Host+ also allows users
     to view archives and extract files from archives while on line.

     Host+ comes configured to work with  ZIP, PAK, ARC, LZH, and ARJ
     archives.  If your favorite archive program is not on the list, you
     may add it here.  Host+ will accept up to 10 archives at one time.

     Before adding an archive program not covered by Host+, you will need
     to know the three letter file extension that the program uses for the
     files it has compressed.  You will also need the View, Extract, and
     Test commands for the program.

     To add an archive program, place the scroll bar (using Up/Down arrow
     keys) on an open line and press return.  HPCONFIG will then allow you
     to edit each of the options in turn. Pressing Escape will allow you to
     keep that option unchanged.  Below is a list of the five options:

          Extension      :    This is the acceptable extension
                              for this archive.
          Program name   :    This is the file to run to work
                              with this archive; note that the
                              file must be in your path.
          Test Line      :    This is the command line sent to
                              the file (Program) in order to run
                              a test on the archives.
          View Line      :    This is the command line sent to
                              the file (Program) in order to view
                              the files in the archives.
          Extract Line   :    This is the command line sent to
                              the file (Program) in order to
                              extract files from the archives.


     Test Uploaded Archives

     Host+ will test the archives of newly uploaded files.  In most cases,
     this switch should be left on.

     Delete Bad Archives

     If a file fails the archive test, Host+ will delete it.  Choosing to
     turn this function Off will cause the file added to the database as a
     private upload to the sysop.   The database will carry a warning
     message for the sysop about the failed test.



     External Script


     Telix v3.22 - Host+                            Customizing Host+    31



     You may substitute your own archive testing program for Host+'s
     internal routines.  This program has to be called by a script. See
     Appendix D for a script outline.


     6.6  Configuring Macros
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You may redefine any key in Host+.  The keys used by Host+ may be
     reassigned to any other key by using the following Keywords:

     Macro Keywords      Default Key



               $TOGGLECHAT              F1
               $USEREDIT                F2
               $LOWERACCESS             F3
               $RAISEACCESS             F4
               $TOGGLESTATUS            ALT-8
               $CHATMODE                F10
               $EXITHOST                ALT-X
               $DOSSHELL                ALT-J
               $TEXTEDIT                ALT-A
               $HOSTCONFIG              ALT-O
               $HOSTHELP                ALT-Z
               $HANGUP                  ALT-H
               $FILECOMPRESS            ALT-F
               $LOCALMODE               ALT-L
               $LOWERTIME               F5
               $RAISETIME               F6
               $SCREENIMAGE             ALT-I
               $CAPTURELOG              ALT-C


     Display Key

     When you press "A" HPCONFIG will ask you to press any key you wish to
     have displayed.  If a macro is assigned to that key, it will be
     displayed.  If not, there will be a no macro assigned message that
     will let you know that the key is available to store a macro.

     Edit Key

     When you press "B" HPCONFIG will then ask you to press the key
     combination you wish to edit.  Enter the information you wish the key
     combination to carry and then press Enter.  Note that only ASCII
     characters (no ALT keys) may be used in macro's. Control characters
     may be used by placing a carat "^" in front of the character.  For
     example, a Return would be "^M", a tab is "^I" etc. To save any macros
     you have made, choose the Save Macros option by pressing "X".


     Telix v3.22 - Host+                            Customizing Host+    32



     Since you will be doing many local logons to test different parts of
     Host+, here is a simple macro that will speed up the process using
     Host+'s Quick Logon feature.

     Press "B" for edit, and then press Alt-1.  Then enter the following
     combination:

     y{Your Name{your password^M

     For example:  y{Jeff Woods{Hello^M

     Save the macro by pressing "X".  The next time you make a local logon,
     press Alt-L for the logon and then press Alt-1.  Host+ will print out
     the quick logon and then skip the opening screen to take you directly
     into the program.

     The Quick Logon feature may be used by any user.  It is used it here
     to give you a working example of a macro.


     6.7  Configuring Events
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Host+ will stop and run any program you choose at any time of your
     choosing. This is called a timed event.  Up to 5 different events can
     be programmed to be run by Host+.

     You may use any program with an extension of EXE, COM, BAT, or SLC. In
     addition, there are two internal programs that can be run as events:
     EXITHOST and EXITTELIX.   EXITHOST will exit Host+ back into Telix.
     EXITTELIX will exit Host+, exit Telix and return to DOS.

     Persons who use Host+ with FrontDoor will have to be careful with
     event scheduling.  Call the Telix Support BBS for special
     documentation on attaching FrontDoor.

     The easiest way to learn how to configure events is to configure
     "EXITTELIX". Set it up to run and watch Host+ return to DOS.  There
     are some sample event programs and batch files listed in Appendix B.

     Configure Event

     HPCONFIG will first ask for the time you wish the event to occur.

     Host+ will either want time entered in 24 hour (military) or 12 hour
     time depending on the format you have set in Telix. (In Telix see:
     Alt-O, General Settings, Section L: Time Format)

     To make an event happen each time a user logs off the system, type in
     the word "EVERY" instead of an actual time.  Press Enter to move to
     the next topic or press Escape to abort.

     You will then be asked if you want the event to be sliding.  A sliding
     event waits for the user to complete their call before the event is


     Telix v3.22 - Host+                            Customizing Host+    33



     run.  A non-sliding event occurs exactly at the time you specify. If a
     caller is on line when a non-sliding event is due to occur, Host+
     notifies them that their time is being shortened due to the event.
     Host+ will hang up on them just before the event is due to occur.

     Next you will be prompted for the program name.  Enter the full syntax
     for the program file and any parameters that need to be passed to the
     program. For instance, C:\BATCH\EVENT.BAT <argument>.  Press Enter and
     your event will be logged.

     Press "X" to exit to the main menu.  Remember to save your changes to
     disk.


     6.8  Configuring User Options
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A    Log Off New Users

          The default (on) will log off all new users after they finish
          filling out the questionnaire.  Turn off this switch to give
          access to all users on first call.

     B    Number Of Downloads

          This is the ratio of downloads to uploads that a user must
          maintain.  For example, if you wish users to maintain a 5:1 files
          ratio, place a 5 here.  If you set the number to a '0', then
          there will be no upload/download ratio enforced.

     C    Access 1 Download Limit

          This is the limit (in Kilobytes) that users with access level 1
          may download per logon.  This does not effect the other user
          levels.

     D    New User Access Level

          Here you can choose the access level that you will give to new
          users to your system.  If you are logging off new users, your
          choice should be "0".



     E    Time per access level 0

          This is the amount of time you allow level 0 users to have on the
          board. This should be set at 0 if you are hanging up after the
          initial questionnaire is filled out.  The old default on Host44
          from Host Software Products was 4 minutes.

     F-N  Time per access level 1-9


     Telix v3.22 - Host+                            Customizing Host+    34



          Here you may set the number of on line minutes allotted to each
          access level. The defaults are set in 10 minute increments, but
          you may choose any time limits you like.

     X    Exit To Main Menu

          This option will exit you back to the Main configuration menu.
          Remember to press "X" at the Main configuration menu to save your
          changes to disk.


     6.9  Configuring the File Bases
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You have one default file base called the Main File Base.  You can add
     an additional 9 bases in the shareware version and 999 bases in the
     registered version.  The shareware version can hold up to 99 files per
     base while the registered version allows 999.

     A file base is a data base of files available on your system.  The
     files for a certain database do not have to be placed in the same
     drive or directory; however, doing so will keep things organized.

     A    Add a File Base

          When you press "A" you will be asked to name the new files base.
          Type in the name and press Enter.  You will then be asked what
          level of users will be allowed access to that files base.  If
          all, enter 1, otherwise enter the access level you desire.
          Default menus do not allow users with an access level of 0 to go
          to the files base.

     B    Delete a File Base

          When you press "B" you will be prompted for the name of the files
          base to delete.  You then will be requested to confirm the
          deletion.  Please note that the files in that data base are not
          removed from your drive by this operation. You will have to do
          that using DOS or a DOS shell.

     C    Edit a File Base

          If you wish to come back and make changes in an entry later you
          can do that here.  Press "C" and you will be allowed to edit the
          information.

     D    Jump to a File Base

          This option will allow you to jump to specific file base entry.

     X    Exit To Main Menu


     Telix v3.22 - Host+                            Customizing Host+    35



          This option will exit you back to the Main configuration menu.
          Remember to press "X" at the Main configuration menu to save your
          changes to disk.


     6.10 Configuring the Message Areas
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You have one default message base called the Main Message Base.  You
     may add an additional 9 bases in the shareware version and 999 bases
     in the registered version.  The shareware version will hold 90
     messages while the registered version will hold 29,999 messages.

     A message base is a data base that tracks messages that are available
     to be read on your system.

     A    Add a Message Base

          When you press "A" HPCONFIG will ask for a description.  Enter
          here the name of the new message base and press Enter.  You will
          then be asked for the access level to the message base.  If you
          want all users to have access to the messages, enter 1.
          Otherwise, enter the access level you desire and press Enter.
          Access level 0 users are not allowed into the message bases by
          the default menus.

          You will then be asked if you want to echo the messages.  An echo
          is when you send messages written on your system to another
          system or a network of systems.  Host+ has been written to be
          compatible with echo networks like FidoNet, RIME, ILink, etc.
          The required UTI (Universal Text Interface) programs to allow
          Host+ to interface with networks will be released as separate
          programs and will be available from the Telix Support BBS.  When
          you are set up for echoes, press "Y" otherwise enter "N" for no
          and press Enter.

     B    Delete a Message Base

          When you press "B" HPCONFIG will ask for the number of the
          message base to be deleted.  Enter the number and you will be
          prompted to confirm the deletion.  The messages in that message
          base will be deleted from your hard drive.

     C    Edit a Message Base

          If you wish to edit the name, access, or echo flag of a message
          base, press "C" and you will be presented with those choices for
          changing.

     D    Jump to a Message Base

          This option will allow you to jump to specific message base
          entry.


     Telix v3.22 - Host+                            Customizing Host+    36



     X    Exit To Main Menu

          This option will exit you back to the Main configuration menu.
          Remember to press "X" at the Main configuration menu to save your
          changes to disk.


     6.11 Configuring the Upload Items
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A    Host Upload Directory

          Press "A" and HPCONFIG will ask for the full path name to the
          drive and directory where uploaded files from users will be
          stored.  For example, C:\TELIX\UPLOADS.  It is a good idea to set
          aside a directory just for uploads to ease the process of
          scanning the files for virus and processing. Registered Users can
          use HPFEDIT (files editor) to later move the files from the
          upload directory to another files base and directory.  Shareware
          Users will have to make the transfer manually (See Manually
          Adding Files)

     B    Upload File Base

          Press "B" and HPCONFIG will ask for the number of the files base
          where you wish Uploads to be listed.

          Shareware Users should enter a 0.  This adds uploaded files to
          the file database where the user is located at the time of the
          upload.  For a complete discussion of this, see Manually Adding
          Files under the heading Adding Files to Host+.

          Registered users can follow the common BBS practice of having a
          separate file base for new uploads.  Enter an unused number for
          the Uploads Data Base.  Use the Files Editor to move files from
          the upload file base to other bases. (See Registered Programs).

     C    Level of Uploads

          This is the access level to which a file is set when uploaded by
          a user. If set to a 1 then all access levels will be able to see
          newly uploaded files.  If you want to limit access to new
          uploads, set this level to a higher number.

     X    Exit To Main Menu

          This option will exit you back to the Main configuration menu.
          Remember to press "X" at the Main configuration menu to save your
          changes to disk.

     6.12 Configuring General Info
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A    System Password


     Telix v3.22 - Host+                            Customizing Host+    37



          This is the password that allows the sysop to shell to DOS and do
          a system shutdown when calling in from a remote.  Pick a good
          password and don't give it to anyone!

     B    Screen Blank Time Limit

          This option allows you to set the number of minutes Host+ will
          wait before blanking the main call screen.

     C    Time Chat is to come on

          This is the time that you would like the "Chatting Times" to
          start. Chat will come on at this time. (Chat may also be forced
          on or forced off at any time by pressing F1).   When you press
          "C" you will be prompted for the time you wish this function to
          be enabled.  The time format will depend on how you have time set
          in Telix.  Telix may be configured for 24 hour (military) time or
          12 hour time.

     D    Time Chat is to go off

          This is the time that you would like the "Chatting Times" to end.
          When you press "D" you will be prompted for the time you wish
          chat to end.

     E    User Logon Alarm

          If you would like an alarm to sound when someone logs on to your
          system, choose On.  If you like to sleep at night, choose Off.

     F    User Comments Sent To

          This is the name of the person who will receive any user
          comments.  The default is Sysop. Changing this to your name will
          allow you to logon to the board using your name and receive the
          comments.  If you leave the setting at the default, then you will
          have to log on to Host+ under the name of Sysop in order to read
          user comments.

     G    DOORWAY Command Line

          This is the command line string sent to DOORWAY.EXE (if used)
          when a user does a online shell to DOS. Note that the option can
          contain any of the System Variables. See Appendix B, System
          Variables for more information. This default setting will work
          fine for simple shells to DOS.  (See Using Doorway)

     H    Telix Config File

          This option contains the name of the TELIX configuration file
          being used. This should be changed only if you are using Host+
          with a separate Telix configuration file. Since Host+ uses
          information found in the file it is important that this is set
          correctly.


     Telix v3.22 - Host+                            Customizing Host+    38



     X    Exit To Main Menu

          This option will exit you back to the Main configuration menu.
          Remember to press "X" at the Main configuration menu to save your
          changes to disk.

     6.13 Configuring BBS Data
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This is where you enter information about the BBS you will create.
     The information will be used by Host+ and any QWK mail packet door
     that you use.

     A    BBS Name

          The name of your BBS (40 character limit)

     B    BBS Telephone

          The phone number of your BBS

     C    BBS City/State

          The Location of your BBS

     D    BBS Net/Node

          Your QWK door ID for hookup with E-mail networks

     E    BBS Sysop Name

          Your Name


     6.14 Restoring and Saving Configs
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Reset Default Options

     If chosen this option will reset all of the configuration options to
     their original default values.

     Save changes to disk

     After you have finished making your changes in HPCONFIG, press "X" to
     save those changes to disk before exiting the program.

     Exit Config Program

     Press "Z" to leave HPCONFIG.  Make sure you save your changes before
     exiting.  "Z" will not save changes by itself.


     Telix v3.22 - Host+                            Customizing Host+    39



     6.15 Creating Colorful Screens
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You can create colorful screens for use in Host+ by using TheDraw or
     other ANSI drawing programs.  You can greet the user at Logon, give
     the latest news, greet new users with the board policies, and say
     goodbye.  You need to follow the following guidelines when making
     screens:

     Input Buffer

     The input buffer for these files is set at 255 characters per line.
     Screen writes will be smoother if the input buffer is evenly divisible
     by 80. (E.G. 80, 160, or 240.)  This is because most screens are 80
     columns wide.  A buffer of 240 writes fairly quickly even on XT
     machines.

     Screen Size

     You really don't have all 25 lines of the screen available to you. It
     is best to draw your screen from Line 2 Column 2 to Line 21 column 79.
     Line 25 is taken up by most comm program's status line.  Lines 23 and
     24 holds the prompts for the next action. The last column sometimes
     holds screen information that would interfere with your graphic.

     Block save your screen from position 1,1 to 21,80 and it should work
     perfectly.

     ANSI/ASCII

     Save your screens in both ANSI and ASCII. This way users who do not
     have ANSI enabled may still see a screen.

     The File Names

     Use the following file names for your screens and place them in your
     \TELIX\HOST directory. Note that *.ANS files are ANSI and *.ASC files
     are ASCII:

          LOGON     This file is displayed when a user logs on
                    the system.

          NEWS      This file is displayed after the user has logged on the
                    system for the first time each day.  See The NEWS.*
                    File for tips on making this file.

          BBSINFO   This file is displayed every time the user logs on to
                    the system.  It follows the news screen and may be used
                    for any number of things.

          LOGOFF    This file is displayed when the user logs off the
                    system.


     Telix v3.22 - Host+                            Customizing Host+    40



          NEWUSER   This file is displayed to all new users.  Its a good
                    idea to put board policies here.

     Examples: LOGON.ANS, NEWS.ASC, NEWS.ANS, or LOGOFF.ASC.

     The NEWS.* File

     The news file may be made in an ASCII editor.  If you want color, you
     may construct separate pages in TheDraw and then concatenate the files
     using DOS's copy command. (e.g. COPY FILE1 + FILE2 NEWS.ANS). The
     easiest method is using a program written for BBS's that construct
     bulletin screens. One well known program of this type is FLASH30 by
     Qsoft.  News files may be made many pages long.  Host+ will pause the
     screen after a page of lines has been sent and wait for the user to
     ask Yes or No before proceeding.





     Global Variables

     Host+ has several global variables that may be inserted into any user
     created screen, bulletin, or message.  Global variables are preceded
     by the "at" symbol (@).  The three text variables are:

          @user     displays the current user's full name
          @frst     displays the current user's first name
          @mins     displays the current user's number of minutes remaining
                    online

     There are also six global color codes based on the colors set by the
     user in the Your Defaults area:


          @C1  :    Displays the first color defined by the user
          @C2  :    Displays the second color defined by the user
          @C3  :    Displays the third color defined by the user
          @C4  :    Displays the fourth color defined by the user
          @C5  :    Displays the fifth color defined by the user
          @C6  :    Displays the sixth color defined by the user

     For example: @C1Would display this line of text in color.

     In making your design, you should realize that anything positioned to
     the right of a text variable will change position depending upon the
     number of characters that replace the variable.  For instance,
     "Tristin Andrew" uses many more character spaces than "Joe Blow", so
     the line of text would look differently for each.  This is how the
     lines of text would look:

     @user     the Global Variable

     Joe Blow     the Global Variable


     Telix v3.22 - Host+                            Customizing Host+    41



     Tristin Andrew     the Global Variable

     You can experiment with these variables in the message base.  Just
     write a message using the global variables, save it, and read the
     message.

     Note that the color variables are for use on ANSI screens only.  You
     will need to edit them out of ASCII versions of the same screen
     because the codes can be seen by ASCII viewers.  Users of the
     registered HPMENUS.EXE program should use their ANSI editor for colors
     and not color variables as ASCII versions of the menu are created by
     the program and would display the codes to ASCII users.


     Telix v3.22 - Host+                              File Management    43




     7.   Adding Files to Host+

     A files data base is a collection of information about files available
     to your users.  You may define up to 10 files data bases in the
     shareware version and 999 files data bases in the registered version.
     In addition, you are limited to 99 files per files base in the
     shareware version and 999 files in the registered version.

     Its possible to have both A:\FILE1.ZIP and C:\TELIX\UPLOAD\FILE2.ZIP
     in the same files database; however, it is a good idea to group your
     files together in one directory and database if you plan to offer a
     lot of files.

     You may have databases available to one set of users and not another.
     For instance, special files could be kept in an area defined for
     access level 6 and above.  Users below level 6 would never see the
     area from the menu. (See Customizing Host+)

     You may also set access levels for each file.  A file with access
     level 6 could be in the same files database with a file set at access
     level 0. A user with an access level of 5 would not see the access 6
     file.

     Files may be password protected so that only special users can get a
     certain file.

     Host+'s ADDFILES.EXE program will allow you to add files to any
     database while off line.  You may also add files manually while in
     local logon mode.  Registered Users can easily edit database entries
     off line with the Files Editor.


     7.1  Adding Files with ADDFILES.EXE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ADDFILES.EXE allows you add files from any drive or directory to any
     files database.  You view all files available and tag the ones you
     want added.

     ADDFILES.EXE should be in your Telix directory. If the Telix directory
     is in your DOS path statement, ADDFILES.EXE may be run from any
     directory. Otherwise, you will have to start the program from the
     Telix directory each time.  This external program should not be run
     when shelled to DOS from a local logon of Host+.

     Choosing the Drive and Directory

     Addfiles opens with a window on the left side of the screen that shows
     all of the files and sub-directories located in your current
     directory.  To change directories, move the cursor bar to the
     directory you want and press the enter key or use the left button of
     your mouse.  To change drives, press F2, and you will be presented
     with a prompt for the name of the drive.


     Telix v3.22 - Host+                              File Management    44



     Choosing Files

     Once you are in the proper drive and directory, move the cursor bar to
     the file you want to add and press the spacebar or the right button of
     the mouse. A check (û) will appear next to the file.  Move through the
     directory checking all the files you want.  You may change drives and
     directories anytime during this process and Addfiles will remember all
     file tags.

     Adding Files

     When you have tagged all the files you wish to add, press F1 to begin
     adding files.  You will be presented with a new screen and menu. The
     bottom half of the menu is for entering information about the file.
     The top half of the menu lists your menu choices and the current data
     base.  Be sure you are in the right file data base before you starting
     saving files.  It is not easy to correct an addition to the wrong
     database if you don't have a copy of the Files Editor.

     F3  Change Current File Base

     Press F3 and you will be presented with a window to change the
     database by entering the database's number.  If you do not remember
     the number of the database, press F1 at this window and a listing of
     the files databases will be presented to you.  You may change data
     bases at any time in your Addfiles session.

     Here is the information you are asked to provide ADDFILES.EXE on each
     file:

          File Name

          This is the complete drive, path, and filename of the file.  It
          should already be in place.

          File Description

          You are given two lines to describe what the files does.

          File Uploader

          This defaults to sysop.  You may change the name to any name you
          wish.

          File Access

          This is the access you wish the file to have.  If you want all
          users to have access to the file, enter "1".

          File Password

          If you want the file protected by a password, enter that word
          here.


     Telix v3.22 - Host+                              File Management    45



          File Date

          Addfiles will put today's date in this field.  You can change it
          if you wish.

     F1  Add file to the data base

     Once you have entered all the information about the file, double check
     it to make sure it is correct.  Make sure you are adding it to the
     correct database. Press F1 to save this data to the database and
     advance to the next file.

     When you have saved all the files you had checked, ADDFILES will
     return you to the opening menu.

     Once the data is saved, you can change your entries by making a local
     logon and using (C)hange File from the files menu (See Manually
     Changing Files). Registered users can use the wonderful Files Editor.

     F2  Skip to next file

     Pressing F2 will skip to the next file that you have chosen to be
     added.  You will not save the current file to disk, but ADDFILES will
     hold it for you during the session should you want to come back.

     F10 Exit

     Exits ADDFILES.EXE.



     It is possible to add files, change file listings, and remove files
     from any files database while in local logon.  This is best used by
     Shareware users of Host+.  Registered users have the Files Editor for
     these functions.

     SPECIAL NOTE: Shareware Users should not have a Special Upload Files
     Base defined or they will have problems when manually adding and
     moving files.  Any file you manually add will go to the Upload files
     base and not the files base you are in at the time.

     For example, you are in the Main File Base and manually add FILE.ZIP.
     After you are through, you will *not* find the file listed in the Main
     File Base.  It will be found in the Uploads File Base.  The only way
     to move the file to into the Main File Base back would be to add it
     with ADDFILES or using the Files Editor program available to
     Registered Users.  Simply put, if you define an Uploads Files Base,
     you will have to make all of your file additions with ADDFILES.EXE.
     You will not be able to add files manually unless you want them to be
     in the Uploads File Base.

     To move user uploads from the Upload File Base to another Base you
     will have to move the files out of the Upload Directory to another
     directory and then run ADDFILES to add the files to another file base.


     Telix v3.22 - Host+                              File Management    46



     Then run the Files Compressor on the Upload File Base with the Kill
     Files Not Found option. You may not wish to put up with all of this to
     have an Upload File Base.  It is up to you.


     7.2  Manually Changing Files
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To Add A File Manually

     Select the file database to which you want to add files by pressing
     "A" for Area change.

     Select "U" for upload.  At the prompt asking what file to upload,
     enter the full drive, path, and filename of the file.  Entering just
     the filename with no path will cause Host+ to act like you are making
     a remote upload and ask for your protocol.  If this happens, press "N"
     for None to abort.

     If you have defined a special uploads directory (not a files base, a
     directory), you can add files from there without entering the complete
     drive and path.  A very simple files setup is just one directory that
     has been defined for uploads and holds all your host zip files.

     You can add multiple files to the database at one time. If you have
     several files to upload, just enter the drive, directory and "*.*",
     like so:

          C:\DOS\ZIPS\*.*

     Host+ will then process each file one at a time and prompt you for
     information.





     Testing

     If you have Host+ configured to test all new archive files (the
     default setting), Host+ will first test the archive to see if it has
     CRC errors.

     Description

     Host+ will ask you to supply a two line description of the file.

     Access level

     You cannot set the access level for an individual file while making a
     manual file addition.  You have to use ADDFILES for this.  Registered
     Users can add an access level later using the Files Editor.

     Password Protect


     Telix v3.22 - Host+                              File Management    47



     To require a password for the file, select yes and enter the password.

     To change the listing for a particular file, press "C" from the files
     menu and then supply the name of the file.  You do not need to give
     the full path and name of the file as it is in the database.

     You will then be taken through a series of prompts asking if you wish
     to change the drive\path\filename of the file, the description, and
     the password of the file (if any).


     7.3  Manually Moving/Removing Files
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You may remove a file by pressing R from the files menu and then
     supplying the name of the file.  Host+ will prompt you to confirm that
     you wish to delete the file from the data base.  Answer yes and the
     file will be removed.

     You will then be given the option to erase the file from the directory
     on your drive.  To erase the file, press y and it will be removed.

     To change the file to another file database you must first remove the
     file from the existing data base, change to another files area, and
     then add the file to the new file data base.  You may wish to shell to
     DOS and physically move the file to another directory on your drive.


     Telix v3.22 - Host+                              User Management    49




     8.   The User Editor

     After someone has logged on to your board, information about their
     account is stored in the user file HPUSER.DAT.  To edit that
     information you turn to the User Editor.

     There are two user editors.  One is available to shareware users and
     is located inside of HPUTILS.SLC.  The other is available only to
     registered users and is called HPUEDIT.EXE. (See 'Registered
     Programs'). The following are instructions for using the shareware
     version:

     You may access the user editor in two different ways.  In Host+, you
     can start the user editor from the sysop menu by pressing F2.  In
     Telix, you can run the script HPUTILS.SLC and choose the user edit
     option.

     To open a new user account, the user has to logon and fill out the
     questionnaire. You may also make a local logon and enter the
     information about the user yourself.  Registered users can pre-
     register new users with HPUEDIT.EXE.

     Here is how you move around the USER EDITOR:

          Page Down      : This moves you to the next user
          Page Up        : This moves you to the previous user.
          Home           : This moves you to the top of the page.
          End            : This moves you to the bottom of the page.
          Up Arrow       : This will move you up one field.
          Down Arrow     : This will move you down one field.

     To Edit A Field

     You may select a field to edit by either moving the cursor or by
     selecting the letter out to the left hand column.  Press Enter to edit
     the field.  When you are through, press Enter again.  To abort the
     process, press Escape.  To save your changes, press "X" for Save User.
     To exit the editor, press "Z".  Be sure you have saved any changes
     before exiting the editor.


     8.1  User Fields you Can Edit
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     User Fields you can Edit

     You can move around the editor screen and edit any of the following 9
     fields:



     User's Full Name


     Telix v3.22 - Host+                              User Management    50



     This is the user's full name.  When editing, be sure that you do not
     leave any extra spaces after the last name or Host+ will want those
     spaces given as part of the last name.

     User's Password

     The user fields are sensitive to open spaces. If you change a users
     password, be careful that there are no spaces following the password.
     Otherwise, the user will have to input a space following the password.

     User's Access

     Most of the time, you will be editing the new user's access level
     after verifying their application to the board.  Just enter their new
     access level here and press "X" to save.

     User's Status Flag

     The three legal entries for this field are:  "A" (active), "D"
     (delete), and "B" (blacklist).

     Putting a Status Flag of "D" for delete will remove the User's Account
     from active status.  The user will be unable to logon.  The file will
     remain visible to you in the user editor until the next time the Files
     Base Compressor is used. (See Files Base Compressor, below)

     Putting a Status Flag of "B" for blacklist will temporarily place the
     User's Account on inactive status until you choose to change it.

     User's Phone Number

     This is the user's phone number.

     User's Street Address

     This is the user's street address.

     User's Location

     This is the user's city and state.

     User's Zip

     This is the user's zip code.

     Comment About User

     This is a place to put in a comment.


     Telix v3.22 - Host+                              User Management    51



     8.2  User Fields you Cannot Edit
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Here is a listing of information shareware users can see but not edit.
     Editing of this information is limited to registered users with the
     program HPUEDIT.EXE.

     Date User Last on

     This shows when the user was last on

     Users Total Downloads

     Shows how many downloads the user has made

     Users Total Uploads

     This shows how many uploads the user has made **

     *Users ANSI Status

     Shows if ANSI is turned on

     *Users Pause Status

     This shows if screen pause is activated

     +Users Experience Level

     Shows the level of menus the user has chosen









     (*) can be edited by the user at the Main Menu prompt (Y)our Defaults.

     (+) can be edited by the user at the Main Menu prompt (X)pert Menus.

     (**) an edit here can award a specific user more downloads or require
     more uploads!


     Telix v3.22 - Host+                                  Maintenance    53




     9.   The Files Compressor

     The Files Compressor (HPCOMP.EXE) should be in your Telix Directory.
     If the directory is in the DOS path you may start the program from any
     directory. The program can be run from the Sysop Commands Menu by
     pressing Alt-F or as an event from a batch file using command line
     switches for automatic operation.  Do not run when shelled to DOS from
     a local logon in Host+

     Here is a what the Files Compressor does:

          Resorts Files: After you have made changes in your files base, or
                         user base they will not be in order.  Running the
                         compressor will resort them.

          Delete Record: When you delete a file, message, or user in one of
                         the bases, the record still remains.  Running the
                         compressor removes record from the chain and
                         rebuilds the data base.

          Packs Bases:   Deletes users who have allowed their accounts to
                         lapse by being inactive on the board.  Deletes old
                         messages and private messages that have been read.
                         Removes file listings for files that are no longer
                         on the drive.


     9.1  Compressing the User File
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To pack the user base, press F1 from the main menu.  You will be asked
     if you wish to delete users who haven't connected in a number of days.
     The program default is 30, but you can change that by typing in
     another number.

     The program will then delete records of users who haven't called and
     users that you have marked for deletion.  It will resort the file
     alphabetically and write a new file to disk.  If any problems are
     encountered, you will be prompted to run HPREPAIR.EXE (see below)


     9.2  Compressing the File Base
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You have a choice of two actions when packing the file bases.  You can
     either compress a single file base by pressing F2 or you can pack all
     files bases by pressing F3.  Here are your options:

     Sort By Date or Name

     To sort the files alphabetically, choose "N" for name.  To sort by
     date press "D" and the files will be sorted in ascending order with
     the oldest file first.


     Telix v3.22 - Host+                                  Maintenance    54



     Reverse Sort

     This switch reverses the sort routine making it sort in descending
     order. If you have chosen a name sort, then choosing reverse will sort
     the files from Z-A.  If you have chosen a Date sort the files will be
     sorted from the newest to the oldest files.

     Kill files not found

     This switch causes the program to run a check on each file to see if
     it is actually on the drive and in the directory. If the file is not
     found, then it will be removed from the database.


     9.3  Compressing the Message Bases
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You have a choice of two actions when packing the message bases.  You
     can either compress a single message base by pressing F4 or you can
     pack all message bases by pressing F5.   You will be given two
     options:

     Kill Private

     This option will delete all private mail which has been read.

     Days to allow

     This option will delete all messages (x) days old. The default setting
     is 30 days, but you can change it to whatever you like.


     9.4  Running from a Batch File
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You can set up HPCOMP to run from a batch file using command line
     switches.  Host+ can be set to run that batch file at a certain time
     as an event.  For instance:

          HPCOMP /U D:90

     Would run HPCOMP.EXE and compress the User Base, deleting all users
     who haven't called in 90 days.  You can only run either a User Base,
     Files Base or Message Base compression at one time.  HPCOMP will not
     let you combine operations.  Here are the command line switches:

          U         Compress User File
                    M:(x)     (X) Days since last call


          F         Compress Message Base
                    K         Kill Private
                    D:(x)     (X) Days to allow
                    B:(x)     (X) Message Base To Compress


     Telix v3.22 - Host+                                  Maintenance    55




          F         Compress File Database
                    D         Sort by Date
                    R         Reverse Sort
                    K         Kill files not found
                    B:(x)     (X) File Base To Compress

     B:(x) switches determine the number of the base that is to be
     compressed. If the B switch is left out or set to 0 then HPCOMP will
     compress all bases. If B is set to a number then it compresses only
     that base.

     Here are some command line examples:

     HPCOMP /M K D:30              Compress all message bases, kill private
                                   messages that have been read and
                                   messages over 30 days old.

     HPCOMP /F K B:4               Compress file base #4 and kill all files
                                   not found

     HPCOMP /U D:90 /M K D:30 /F K You cannot combine switches on a command
                                   line.  This example would only compress
                                   the user base, the switches for message
                                   base and files base would be ignored.

     9.5  Repairing Damaged Files
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The Files Compressor monitors the integrity of your data bases.
     Should it find a corrupted database, it will write a file for that
     data base with a .REP extension.  HPCOMP will then tell you to run a
     program called HPREPAIR.EXE.  Exit the Files Compressor and run it
     immediately.

     HPREPAIR will attempt to repair HPUSER.REP (the user base),
     INDEXxxx.REP (the message and file pointers for each user),
     HPMSGxxx.REP/HEADERxx.REP (the messages) and FILESxxx.REP (the files
     base).

     It is a good idea to run daily backups of all your Host+ files in case
     HPREPAIR is unable to fix them.  Many sysops run backups of their
     systems automatically as part of a daily event.  Use several different
     sets of backup diskettes so that you will be assured of having a good
     set.

     Troubleshooting

     Note -- This is a worst case scenario.  We include this here as a
     backup to HPREPAIR and to save you a call to the Telix Support BBS.

     Should HPREPAIR be unable to fix a message base, there is another way
     to fix it:


     Telix v3.22 - Host+                                  Maintenance    56



     Go to the message base configuration menu and print screen the
     description of all your bases.  Exit Host+.

     Backup all your HPINDEX.*, HPMSG.*, AND HPHEADER.* files from your
     host directory to another diskette *or* use a better set from a backup
     diskette. Delete those files from your hard drive along with
     HPMBASE.DAT.

     Restart Host+ and you will see HPMBASE created on the start up.  Open
     the configuration program and reinstall your bases using that printout
     from the print screen.  Shell to dos and restore the files you backed
     up.

     Run HPCOMP.  It may crash on the index, requiring HPREPAIR.  After
     that, it should work in most cases.

     If not, delete the HPINDEX.* files, and run HPCOMP again.  It will
     crash because there aren't any index files.  Run HPREPAIR and it will
     create new ones from the *.rep files created by HPCOMP.  Compact once
     more.  Your bases will be restored, but your users will have had their
     message read pointer reset to 0.


     Telix v3.22 - Host+                                Using DOORWAY    57




     10.  Using Doorway.EXE

     DOORWAY.EXE, by Marshall Dudley, is a shareware program that allows an
     online user to Shell to DOS and not only run all of the DOS commands
     but also to run almost any IBM character based program online.
     DOORWAY redirects the input and output of the program to the comm port
     as well as to the console allowing the user and the sysop to control
     the program.

     Without DOORWAY.EXE in your Telix directory, Host+ will use DOS's CTTY
     for the shell.  Many programs will not run in CTTY and CTTY does not
     feed screens to the console so that you can see what the remote user
     is doing.

     When running DOORWAY.EXE under Telix/Host+ there might not be enough
     RAM  to allow certain programs to run.  To find out your available RAM
     from the local mode, press Alt-J to shell to DOS and then run Doorway
     in local. The command line for this operation is:

          Doorway Local /s:* /c:dos.

     Once doorway is up, run DOS's CHKDSK command.  This will tell you the
     available RAM.  Remember to type exit to return to your original
     prompt.

     Do not run CHKDSK from a remote!  Do this only in local mode.

     Note that beginning with Telix v. 3.22, much of the used RAM can be
     swapped out to EMS, XMS, or disk, to free it up for use in the DOS
     shell.   If you need more available memory, turn on swapping in Telix,
     under ALT-O/General.

     To use DOORWAY.EXE with Host+, you must be running ANSI.SYS (Or any
     ANSI program with the exception of FANSI-Console) and you need to
     place the DOORWAY.EXE program in your Telix directory. Once a user
     shells to DOS then DOORWAY.EXE will run using the default command line
     that is already installed in Host+'s configuration.

     The user can now use any DOS commands they want. To keep their
     communications program from interfering with certain commands (Like
     the function keys and ALT-key combinations) they will need to activate
     the DOORWAY mode on their end.   Doorway is supported by many
     communication programs.  Telix users can turn on Doorway mode by
     pressing Alt-= (by holding down Alt and pressing Equal).

     With Doorway activated on the user end, all the keyboard output will
     go directly out the comm port to the remote computer.

     Once finished in DOS the user types "EXIT" to return to Host+.  If
     they have invoked their terminal into DOORWAY mode they will need to
     turn it off once they have returned to Host+.


     Telix v3.22 - Host+                                Using DOORWAY    58



     Doorway monitors the carrier. If the carrier is lost it will either
     reboot or return to the Host+ program. Which option depends on how you
     have set the Doorway command line.  The default is set to return to
     Host+.


     Telix v3.22 - Host+                        Security/Legal Issues    59



     11.  Security and Legal Issues

     Host+ provides you with several features to help maintain security for
     your computer.  If your host is strictly private, you can put that
     message on your welcome screen and use the log off feature to bump the
     caller off the board.

     If you are using Host+ as a general purpose BBS, you may  occasionally
     have someone violate your BBS rules.  You can temporarily remove their
     account from service by changing their account flag in the User Editor
     from Active to Blacklist.

     You may have the misfortune to come in contact with a person so
     laboriously vile that you wish to never see them on your board again.
     To ban their name for all time, put them in the trashcan file.

     Create an ASCII file called TRASHCAN.DAT with your favorite editor.
     Place one name per line.  Here is an example format:

     Joe Blow
     Jiminy Cricket
     John Hacker

     When that person calls back and inputs their name, Host+ will post a
     message that their name is not acceptable on the board.  Persons who
     try to "hack" your board by entering it illegally or causing damage to
     your computer are in violation of The Electronics and Communications
     Privacy Act of 1986.  Copies of this act are available from most
     Bulletin Boards.

     The act also holds that you may be held liable by someone who thinks
     they are leaving a private message on your board only to have it read
     (by accident or otherwise) by others.  To protect yourself, you need
     to post a warning that messages are not private on your board.  Below
     is an example of boiler plate legal language in use on some BBS's.
     This is shown as an example only and not as legal advice. Consult your
     lawyer for language suitable to your situation.

     NO PRIVACY WARNING

     Pursuant to the Electronic and communications privacy Act of 1986, 18
     USC 2510 et seq., notice is hereby given that there are no facilities
     provided by this system for sending or receiving private or
     confidential communications.  All messages shall be deemed readily
     accessible to the general public.


     Telix v3.22 - Host                          Registered Utilities    61




     12.  Registered Utilities

     The following utilities do not come with the shareware evaluation copy
     of Telix.   They are supplied on the registered disk you are sent when
     you purchase Telix.


     12.1 The Files Editor
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Once you have added files with ADDFILES.EXE or manually, you can make
     changes quickly with the files editor. This program allows you to edit
     your file entries, copy or move file entries among files bases, or
     move files from one directory to another.

     The filename for the program is HPFEDIT.EXE and it should be located
     in your Telix directory.

     The opening screen looks like the ADDFILES.EXE program.  The top of
     the menu shows the current database name and number, plus the current
     record number of the file.   The bottom of the menu holds all the
     different information fields for the file.  A complete listing of
     actions can be obtained by pressing F1 for help.

     To edit a file, change to the files database you wish to work in by
     pressing F3 and the database number.  If you don't remember the
     database number, press F1 for help.  A screen showing all the database
     files will come up and you will be prompted again for the data base
     number.

     Once you are in the proper file database, you can scroll through the
     base by pressing page up and page down.  Once you are at your file,
     use the enter key to jump from field to field. You can change
     everything: File Name, File Description, File Uploader, File Access,
     File Password, and File Date.  When you are finished with your
     changes, press F2 to save the file info.

     Here is a listing of all the actions available to you in the FILES
     EDITOR:

     F1  Help Screen

     The help screen listing these commands.

     F2  Save File Info

     Once you are through editing a listing, press F2 to save it before you
     move to the next file.



     F3  Change File Base


     Telix v3.22 - Host                          Registered Utilities    62



     Press F3 and you will be presented with a window to change the
     database by entering the database's number.  If you do not remember
     the number of the database, press F1 at this window and a listing of
     the files databases will be presented to you.

     F5  Copy File to Another Base

     To copy the current record to another files base, press F5 and you
     will be prompted for the number of the files base.  If you cannot
     remember it, press F1 for a listing of files bases.

     F6  Move File to Another Base

     To move the current record to another files base, press F6 and you
     will be prompted for the number of the files base. If you cannot
     remember it, press F1 for a listing of the files bases.

     If you are also moving the actual file to another directory at the
     same time, make the move with Alt-M first and then move the record.

     Alt-M   Move File to Another Directory

     To move the actual file from its current directory to another
     directory, press Alt-M.  You will be prompted for a full drive and
     path to the new directory. To aid in multiple file moves, the drive
     and path you enter are saved for the session.

     F7  Delete File from Base

     Pressing F7 will cause the File Access level to be changed to "D" for
     Deleted.  You will still see the record in the files editor, but it
     will not be visible to your users.  The record will remain until the
     files database has been compressed using the Files Compressor (See
     Using the Files Compressor).

     F10  Exit File Base Editor

     Exits the program.


     12.2 The Menu Editor
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     HPMENUS.EXE should be found in your Telix directory. If the Telix
     directory is in the DOS path, you can start this program from any
     directory. Do not run the program when shelled to DOS during a local
     logon of Host+.

     HPMENUS lets you personalize all Host+ menus. You can limit the access
     to each menu function, personalize the menu keys, add up to three
     different external functions for each menu, and replace all internal
     functions with external ones.


     Telix v3.22 - Host                          Registered Utilities    63



     You can also change the look of the menus by creating new ANSI screens
     and importing them into HPMENUS.

     Here is the listing for all command keys in HPMENUS.  It is followed
     by instructions on making new Menu Screens and customizing Menu
     Commands.

     F1: Help Screen

     The Help Screen listing these commands.

     F2: Load Default Menu

     This pulls up the default menu that came with Host+.  You can
     reinstall it to Host+ by pressing F5.  You can copy it to disk by
     pressing F4.

     F3: Load Menu From File

     Pressing F3 brings up a window for you to enter the name of the file
     you wish to load into HPMENUS.  For instance, you have drawn a new
     Lower Access Main Menu screen in a file C:\TDRAW\PICS\MAINLOW.ANS. You
     would enter the entire file name and press enter. The file will come
     up on screen.  For less typing, open HPMENUS in the directory with
     your menu screens and enter only the filename and extension.

     F4: Save Menu to A File

     This action will save the menu on your screen to a data file so that
     you can edit it.

     F5: Save Menu to Data File

     This installs the new screen or the default screen into Host+.

     F7: Switch Menu Types

     Pressing F7 will bring up a choice of menu areas for editing. (Main,
     Message, or Files).

     F8: Switch Menu Level

     Pressing F8 will bring up a choice of high or low access menu areas.



     F9: Configure Menu Keys

     This will take you to the key editor for the current menu. Here you
     can personalize the menu keys, limit the access to each menu function,
     add up to three different external functions for each menu, and
     replace all internal functions with external ones.  The Menu Key area
     has its own Command Set:


     Telix v3.22 - Host                          Registered Utilities    64



               F1   The Help Menu
               F2   Load Default Menu
               F3   Save Menu to Host+
               F10  Quit

     F10: Exit Program

     Be sure you have saved any changes before exiting.


     12.2.1   Making New Menu Screens

     You can create your own menu screens for Host+ using any ANSI editor
     such as TheDraw, ANSI Write, or others. You are limited to a screen
     display of 16 lines and 8000 characters; however, it is recommended
     that you limit the screen to 11 lines for faster screen rights and
     better fit on the screen.

     Creating new menus follows a three step process:

     1.  Saving Default Menus to disk files for editing
     2.  Editing Default Menus to create new screens
     3.  Importing the new designs into Host+ via HPMENUS

     1. Saving Default Menus

     Open HPMENUS and you will be presented with the Lower Access Main
     Menu.  Press F4 to save this screen to a file for editing.  You will
     be asked to supply a file name (e.g.  C:\TDRAW\PICS\MENULOW.ANS)>

     To see the High Access Main Menu screen, press F8.  You will be given
     two choices: Higher Access Menu and Lower Access Menu.  Choose the
     Higher Access Menu.  The Higher Access Main Menu will come up on the
     screen. Press F4 to save this screen to another file.

     To see the File Menu or the Message Menu, press F7.  You will be given
     three choices: Main Menu, File Menu and Msg Menu. Move the cursor to
     your choice and press enter.  Save those menus to separate files using
     the F4 key.  Remember to save both the Higher and Lower Access
     versions to files. Then exit HPMENUS by pressing F10.



     2. Create New Menus

     Now, open your favorite ANSI editor and load one of the files you just
     saved from HPMENUS.  Create your new design around the Menu Commands.
     Your design does have to fit in a special limited space. Users who
     have screen pausing in effect will get (Y/n)? prompts if your screen
     scrolls over 24 lines.  Host+ will insert three lines at the top of
     your design, so move the menu to the top of the screen when editing.
     Although you are allowed 16 lines by the program, practice has shown
     that 11 lines fits the screen better. If possible, leave line 11 blank
     so that there will be a space between the menu and the Host+ prompt.


     Telix v3.22 - Host                          Registered Utilities    65



     When you are finished, block save the new menu screen saving no more
     than 16 lines.  Select no screen preparation,  240 characters per
     line, and the fastest screen write.  You can experiment with other
     options later.

     When you use Clear Screen, HPMenus will not create an ASCII version of
     your menu for your ASCII users.  If that is not a problem, Clear
     screen will provide a cleaner look; but, it does erase the status
     window at the top of the screen.  You must leave 5 lines clear at the
     top of the design if you use Clear Screen.  Host+ wants those lines
     for the status window and will hold them there, scrolling other lines
     under it. To bring the status window back up, Hit Chat (F1) twice.
     When the user calls up another menu, the status window will be erased
     again.

     Characters per line that are evenly divisible by 80 are best for
     smooth screen writes. This is because screens are usually 80 columns
     wide.  Fastest writes are from buffers of 240 characters per line.

     Animation is tricky with the limitations of 8000 characters per
     screen. Animation uses lots of control characters.  If you do try
     animation, keep it very simple.  A slow screen write can be irritating
     to users.

     Use your imagination and have fun!  Personalized menus make a board
     truly "yours".  For more help, download the file HPMENUS.ZIP from the
     Telix Support BBS for a collection of sample menu files.

     3. Importing New Screens

     Exit your ANSI editor and reopen HPMENUS.  Call up the menu type that
     you are going to replace using the F7 key.  Call up the menu access
     level you want with the F8 key.

     Now, Press F3 to load your new menu.  Give the filename and press
     Enter. The file will be loaded.  Check to make sure it has written
     cleanly to the screen.  If there are problems, exit and re-edit the
     file.

     If the screen looks good, press F5 to save it to Host+.  Your new menu
     screen is now installed.  You may want to run Host+ now and see how
     the menu works.

     12.2.2   Customizing Menu Commands

     This area will allow you to change all the allowable keys that are
     used in Host+.  By changing the key to a different one you can
     completely redesign the Host+ "Look and Feel".  You can input any
     standard letter character as long as the letter is not already be in
     use in the current menu.

     To enter the Key Editor, press F7 for the selection of Menu Types and
     choose the Menu (Main, Files, or Message) that you wish to edit. Once
     that menu appears on the screen, press F9 to edit its keys.


     Telix v3.22 - Host                          Registered Utilities    66



     You will be presented with all the Menu Commands available for the
     menu you have selected.  Each command is listed first by its
     description and then the key that activates the command.  Out to the
     side is the access level for that command and a script that may be run
     instead of the command.  Using cursor keys, move down the list to the
     item you wish to change.

     Here is the list of Commands in the Key editor:

               F1:  Brings up the Help Screen.
               F2:  Load default key assignments.
               F3:  Save key assignments to Host+.
               F10: Quit to Menu Configuration.

     You can do the following in the Key Editor:

     Change the letter that activates the Menu Command

     You can change any letter on any menu.  Just make sure that you don't
     use the same letter for two functions in the same menu.  Here is an
     example of a letter change:

     To change (A)rea Change in the Files Menu to (O)ther File Areas you
     would first press enter until your cursor was over the "A".  Press the
     letter "O".  Now press F3 to save your change.

     You will have to edit your Files Menus (both Lower and Higher Access)
     to reflect the change from "A" to "O" and then install them into Host+
     with Menu Edit.

     If you wish to restore the Default Menu Commands, press F2 to load the
     commands and then F3 to save them to disk.

     Turn off a Menu Command

     You can completely remove a function from use by replacing the key
     assignment with a space (blank).  Here is an example:

     The System Shutdown command is "Z".  It is not listed on any menu, but
     it is an active command.  A person with the system password can press
     "Z", enter the password, and turn off the system from remote.  To
     remove the "Z" command: move the cursor to the letter "Z" on the Main
     Menu and press delete, then press F3 to save your change to disk.

     If you wish to restore the Default Menu Commands, press F2 to load the
     commands and then F3 to save them to disk.

     Change the access to a Menu Command

     You can change the access to any Menu Command.  Here is an example:

     The co-sysop levels (7 and 8 access code) have access to nice features
     like *.* downloads and directory listings.  They also have access to
     the Shell to Dos.  To move that access up to Level 8 only, move the


     Telix v3.22 - Host                          Registered Utilities    67



     cursor to the access code for Shell to DOS.  Enter an "8" and press
     enter. Then press F3 to save your change to disk.

     If you wish to restore the Default Menu Commands, press F2 to load the
     commands and then F3 to save them to disk.

     Replace a menu command with a SCRIPT to call another function

     You can replace any Menu Command with a SALT Script to call another
     function.  This does require considerable skill in the writing of SALT
     script.  Most BBS add-on programs require a system file (DORINFO.DAT,
     PCBOARD.SYS, DOOR.SYS and others) in order to operate.

     Host+ does write the file HOSTDOOR.SYS when it calls a script.  If you
     know how to write a converter, you can convert HOSTDOOR.SYS into the
     system file your door needs.  A format for serious programmers is
     provided in the Appendices.

     Add up to three extra functions to each menu

     You can also add simple doors to your menus with the external
     functions. Just enter the Letter for the command and the SALT Script
     that you want run.  Host+ will write the HOSTDOOR.SYS file when an
     external function is called.  Serious programmers can convert this
     file into a system file for use with other bbs doors.

     Here is a very simple, but necessary, function you can add to the
     message menu.  Registered users can get the file HTYPEF.SLC from the
     Telix Support BBS to do the following exercise instead of using
     DOORWAY.

     In the security and legal section above, we discussed the need for a
     privacy statement to be posted prominently for users to read.  Using
     Marshall Dudley's DOORWAY, we can allow users to call that statement
     for viewing from the Message Menu.

     First, compile this SALT script using Telix's CS.EXE.  Call the script
     PRIVACY.SLT.

     Main()
     {
      Dos("C:\TELIX\DOORWAY.EXE local /s:* /i:C:\PRIVATE", 0);
     }

     Inside the quotes is a DOORWAY command line.  Any DOS command would
     work inside the "quotes".  Here is what the command line does:

     Local is for running doorway in local mode so you can test it with a
     local logon.  Once you test this out, change this command to either
     COM1 or COM2 and recompile.

     /s:* is for running doorway without a sys file


     Telix v3.22 - Host                          Registered Utilities    68



     /i:C:\PRIVATE is for showing a text file. You do not have to give the
     full path if the file is located in the same directory with DOORWAY.

     The PRIVATE file contains the privacy warning text.  At the bottom of
     the file you should add the line:

     $:PRESS [ENTER] TO RETURN

     Be sure that the $ sign is in the first column on the left hand side.
     You can color the text in TheDraw, but you must then edit the file
     with a text editor to insure that the $ is on the extreme left of the
     screen; Otherwise, DOORWAY will not recognize the $ command.

     Now, enter the HPMENUS program and call up the MESSAGE MENU. Press F9
     to edit the keys.  Using the cursor keys, move to the first external
     function and enter the letter "P" for Privacy Statement.  Enter the
     file name PRIVACY.SLC for the name of the script.  You will also want
     to edit your menu screens to include the (P)rivacy Warning command.

     Make a local logon and press P at the message menu.  DOORWAY should
     run in local mode and call up the text of your message.  When you
     press a carriage return, DOORWAY returns control to Host+.  Now re-
     edit your PRIVACY.SLT script to replace the LOCAL command with the
     appropriate comm port command (COM1 or COM2) and you are done.

     12.3 The External User Editor
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The HPUEDIT.EXE program should be in your Telix directory; you can
     start it from anywhere if that directory is in the path. When you call
     the user editor from Host+ (F2) you will get this registered version
     instead of the shareware version.

     HPUEDIT.EXE is the full screen external user editor program that lets
     you to edit all of the information that is available on a user.  That
     includes information the shareware version would not allow you to
     edit. The following keys have functions in HPUEDIT.EXE:

     F1 Help Screen

     Brings up a the listing of menu commands

     F2 Saves the current user

     Before moving to the next record, you must save the changes you have
     made by pressing F2.

     F3 Print user information

     When you press F3 you are prompted to print the information for the
     current user or all users.

     F4 Search Users


     Telix v3.22 - Host                          Registered Utilities    69



     To find a particular user, press F4 and enter their name.  HPUEDIT
     will advance to the first listing holding that name.

     F5  Create New User

     You can pre-log new users by pressing F5 and then entering all the
     information.  You primarily need the user's name, password, access,
     and activity flag for the account to work.  Information on address and
     the like is optional.

     F10 Exit Program

     Before exiting the program, make sure you have saved the changes by
     pressing F2 on the user's record.


     Telix v3.22 - Host+                              Installing Doors   71




     13.  Appendix A - Installing Doors

     A.1  Simple Setup
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Here's an example of the simplest setup for a PCBoard door such as
     HiDice.

          Your filename is:        C:\DOORS\HIDI\HIDICE.EXE
          The command line is:     HIDICE.CFG
          The converter is:        PCBoard 14.x

     Many doors want some type of configuration file.  Here is what a
     typical one looks like:

     C:\DOORS\HIDI\PCBoard.sys
     Jeff Woods
     deltaComm Online
     000000

     The first line is where the PCBOARD.SYS file will be found. Host+ will
     write the PCBOARD.SYS file into the directory given in the filename,
     in this case: C:\DOORS\HIDI\.  Getting the directory wrong is a common
     mistake.

     When the door is called, Host+ writes PCBOARD.SYS to C:\DOORS\HIDI. It
     then changes to that directory and starts the program by issuing the
     line:

     C:\DOORS\HIDI\HIDICE.EXE HIDICE.CFG.

     A.2  Using a Fossil Driver
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Some doors need a fossil driver active in RAM before they can operate.
     Fossil drivers are used by most BBS programs to monitor the
     communications interrupt in memory and are available from almost any
     BBS.  The two main programs in use are called BNU and X00. You put the
     fossil driver in memory before you start your door and remove it when
     you are through by calling your door from a batch file.

     Locate the batch file in the same directory as the door program.  This
     way, Host+ will send the system file to the same directory as the
     program.  Be sure and use full path and filenames in your batch file
     to avoid DOS calling another copy of COMMAND.COM and eating up memory.

     Here is a sample Host+ configuration:

     Filename    :  C:\DOORS\CARDS\BLACKJAK.BAT
     Command Line:  Blank
     Converter   :  RBBS

     Here is the batch file:


     Telix v3.22 - Host+                              Installing Doors   72



     rem This is Blackjak.bat
     rem Starting fossil driver
     C:\MISC\BNU.COM /F
     rem now start the program
     C:\DOORS\CARDS\JACK.EXE JACK.CFG
     rem when the program is over, remove fossil driver
     C:\MISC\BNU.COM /U
     :end

     A.3  Using Scripts as Doors
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You can run Telix scripts as doors and even pass them parameters.

     For instance, there is a script available to registered users of Host+
     on the Telix Support BBS called HTYPEF.SLC.  This script will type a
     file on the screen of the local and the remote.  This is how you would
     configure it in Host+ to show a file called AFILE.ANS:

     Filename :          C:\TELIX\SCRIPT\HTYPEF.SLC
     Command Line:  C:\TELIX\HOST\AFILE.ANS
     Converter:          none

     Script writers need to know that anything you put in the command line
     is sent to the script as a SINGLE string.  A door with the command
     line as:

     "THIS IS A TEST"

     would be passed to a script as a single string.  A script can use this
     string by having it's main function set up like so:

     main(str commandline)
     {
     ...
     }

     The string commandline could be set to use one of the internal
     parameters. For instance, %C will expand to tell the Comm port in use:

     "THIS IS A TEST %C"

     Could expand to:

                 "THIS IS A TEST 1"


     Telix v3.22 - Host+                               Example Events    73




     14.  Appendix B - Example Events

     Most sysops run events to do maintenance on their BBS files.  They run
     batch files to backup their drive, run maintenance programs for the
     various game doors, scan new files for virus, pack data bases, and any
     number of things.

     It is a good idea to run your event at some time other than midnight
     because this is one of the busier times for callers.  An event time
     like 4am is not likely to inconvenience users.

     Listed here are some sample events and batch files.

     B.1  Checking Uploads for Virii
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You will want to check all new files that have been uploaded to your
     board before you make them available for users.  This set of batch
     files uses PKzip and McAfee's ViruScan to do just that. The file
     assumes that all uploads are sent to a directory called C:\BBS\UPLOAD;
     that there is an empty directory called \TEMP; that you have a zip
     comment file called ziphead.asc. The batch files are called EVENT.BAT
     and SCANNER.BAT.  These batch files are set to run every time someone
     logs off your board.  This is written for ZIP files only.  You can
     modify it to work with Archive programs popular in your area.

     rem This is EVENT.BAT
     rem
     if exist C:\BBS\UPLOAD\*.ZIP goto send
     goto end
     :send
     XCOPY C:\BBS\UPLOAD\*.ZIP \TEMP /m
     if not exist C:\TEMP\*.ZIP goto end
     md \TEMP\$$$
     cd \TEMP
     for %%a in (*.zip) do call SCANNER.BAT %%a
     rd \TEMP\$$$
     for %%a in (*.zip) do PKZIP %%a -z < \TELIX\HOST\ZIPHEAD.ASC
     COPY C:\TEMP\*.ZIP C:\BBS\UPLOAD
     DEL C:\TEMP\*.* < ECHO Y
     ATTRIB -A C:\BBS\UPLOAD\*.ZIP
     HPCOMP /F K B:4
     cd \TELIX
     :end

     Line 3 checks to see if there are any files in your upload directory.
     If there are no files, the batch file ends.

     Line 6 uses XCOPY to send all files that have not had the archive bit
     set on to a sub-directory called TEMP.

     Line 7 is a test to see if there are any new files; if TEMP is empty
     the batch file ends.


     Telix v3.22 - Host+                               Example Events    74



     Line 8 creates a new directory for use by SCANNER.BAT. Line 10 sends
     each new file in turn to SCANNER.BAT for processing.

     Line 12 inserts your own zip comment file in the place of any file
     that was present.  If you don't want to have a zip comment, create a
     blank file called ZIPHEAD.ASC and this will serve to wipe out the
     comment.

     Line 13 copies all the files back to \BBS\UPLOAD.  Line 14 deletes all
     the files in \TEMP.

     Line 15 sets the archive bits of all the files in \BBS\UPLOAD to off.

     Line 16 starts up the Files Compressor and resorts all the files to
     include the new ones.  If you are a registered user, you may want to
     have it compress only the Uploads file base.

     Here is SCANNER BAT:

     PKUNZIP %1 *.COM *.EXE *.OVL C:\TEMP\$$$\
     if errorlevel 1 goto end
     SCAN C:\TEMP\$$$
     if errorlevel 1 goto bad
     if errorlevel 0 goto end
     :bad
     md C:\XXX
     copy %1 C:\XXX
     del %1
     del C:\BBS\UPLOAD\%1
     echo ** %1 carries virus ** >>C:\TELIX\HOST\HOST.LOG
     echo ** File removed!!!  ** >>C:\TELIX\HOST\HOST.LOG
     :end
     del C:\TEMP\$$$\*.* < ECHO Y

     Line 1 unzips the file name passed to it by EVENT.BAT.  It unzips
     files that commonly hold virus into the directory C:\TEMP\$$$ that was
     created by EVENT.BAT

     Line 2 checks to see if any of those files existed in the archive.
     PKzip gives an error level of 1 if no files are found. If the files
     aren't found, the batch file ends.

     Line 3 calls VIRUSCAN to scan the files.  An error level of 1 or
     higher means bad files were found.  An error level of 0 means the
     files are ok and the batch file branches to the end where the files
     are deleted and control is passed back to EVENT.BAT.

     Lines 7 - 12 create a directory called \XXX and moves the bad files to
     it. The bad files are also erased from \TEMP and \BBS\UPLOAD. A
     warning is inserted in the HOSTPLUS.LOG file.

     We have included these batch files so that you can get started with an
     important event right off the bat.  Later, you may wish to find a file
     on the BBS's called CHECKOUT.  This program does essentially the same


     Telix v3.22 - Host+                               Example Events    75



     functions as the batch file, but does it much faster.  It also handles
     all kinds of archive formats.

     B.2 Backing up the BBS Files
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You can back up all of your important BBS files each day on to a
     diskette. This is good for saving your Users list and other databases
     against corruption. It is a good idea to rotate the disks out of your
     floppy each day and have several sets.

     An easy batch file line for this event is:

     XCOPY C:\TELIX\HOST\*.* A:

     You can combine this with other actions in a once per day event

     B.3 Compressing the Data Bases
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     After you back up your data, its a good idea to compress the files.
     You may be already compressing the Filebases in EVENT.BAT whenever a
     new upload is made.  Since you may go a day or two without an upload,
     its a good idea to compress them at least once a day.

     Here are some sample batch lines:

     HPCOMP U D:90
     HPCOMP M D:30 B:0 K
     HPCOMP F B0 K

     Line 1 compresses the User base and deletes all callers who haven't
     logged on in 90 days.  Line 2 compresses all the Message bases, kills
     all messages over 30 days old, and kills all private messages that
     have been read.  Line 3 compresses all Files bases in alphabetical
     order and kills any entries where the files are not present.


     Telix v3.22 - Host+                              Product Support    77




     15.  Appendix C - Product Support


     Host+ is a relatively large and complicated program. In order to
     support Telix, Host+, and to provide a means of distribution, a BBS
     (Bulletin Board System) for Telix support has been set up.

     The Telix Software Support BBS is available 24 hours a day at 919-481-
     9399. The Support BBS accepts calls from 300 baud to 9600 baud and
     beyond, including v.32/v.32bis calls, and HST calls at 14,400 baud. If
     you have a Host+ question or problem, or have found a bug in Host+,
     give the support BBS a call. The latest versions of Telix and Host+
     may also be found on the support BBS.

     If you're calling about a problem, try to be as specific as possible
     when describing the problem. Include any relevant details, such as
     your machine's configuration, Telix version number, Host+ version
     number, resident software installed, steps taken before the problem
     happens, and any other things you feel are important. It is very hard
     to answer vague questions such as, "Host+ doesn't work on my PC. Do
     you know why?".

     At the current time, the support BBS is open to all callers. Since it
     is extremely busy, it is almost certain that in the future it will be
     restricted to registered users of Telix. Registered users will also
     receive mailed notices of major updates to the program.


     Telix v3.22 - Host+                                 File Formats    79




     16.  Appendix D - File Formats

     D.1  HOSTDOOR.SYS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This file is written out when Host+ runs a door program. It contains
     information pertaining to both the user's status and also to the
     status of certain variables in Host+.  This information is intended
     for people who are able to program in SALT to help them customize door
     converters and attach programs to the menus.

     The following is the file format of the HOSTDOOR.SYS file and then a
     short description of the different variables and their use.

     NOTE:  Each of the Positions given are actual locations in the data
     file, as referenced by the Fseek() function in SALT. These positions
     might not be exactly the same (but should be) in any other language.

     The following is information on the data type formats used in the
     HOSTDOOR.SYS file.

          Str  String of [Total] size, can be read in with the FREAD()
               function, and written with FWRITE().

          Chr  String of 1 character size, can be read in with the FREAD()
               function, and written with FWRITE().

          Uint Unsigned integer stored in the Intel format, that is Low
               Byte/High Byte format.  Unsigned integers can be read in as
               a string and the converted to a integer variable using the
               following code:

               (Unsigned Char [Total = 1] integers)
               x = SubChr(temp, 0);
               (Unsigned Integer [Total = 2] integers)
               x = SubChr(temp, 0) + SubChr(temp, 1) * 256;
               (Unsigned Long Int [Total = 3] integers)
               x = SubChr(temp, 0) + SubChr(temp, 1) * 256 + SubChr(temp,
               2) * 65536;

          Sint Signed integer stored in the Intel format, that is Low
               Byte/High Byte format.  Signed integers can be read in as a
               string and the converted to a integer variable using the
               following code:

               (Signed Integer [Total = 2] integers)
               x = SubChr(temp, 0) + SubChr(temp, 1) * 256;
               if (x > 32767)
               x = x - 65536;


     Telix v3.22 - Host+                                 File Formats    80



     HOSTDOOR.SYS

     Position  Total     Type Data Name
     ÄÄÄÄÄÄ         ÄÄÄÄ ÄÄÄÄ ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
     0         2    Str  Host Version Number
     2         64   Str  Host Data Directory
     66        1    Uint Status Bar Location
     67        1    Uint System Color 1
     68        1    Uint System Color 2
     69        1    Uint System Color 3
     70        1    Uint System Color 4
     71        1    Uint System Color 5
     72        1    Uint Auto Baud Detect
     73        1    Uint Local Mode
     74        5    Str  Baud Rate
     79        5    Str  DTE Rate
     84        1    Uint Com Port
     85        2    Uint Com Port Base
     87        1    Uint Com Port IRQ
     88        1    Uint Error Correcting Connection
     89        6    Str  User Log On Time (Seconds)
     95        6    Str  Seconds Remaining This Call
     101       3    Str  User Number
     104       1    Chr  User Access Level
     105       20   Str  User Name
     125       35   Str  User Location
     160       18   Str  User Phone
     178       10   Str  User Password
     188       10   Str  User LastOn
     198       1    Uint User ANSI
     199       1    Uint User Pause
     200       1    Uint User Experience
     201       1    Str  User Protocol
     202       3    Uint User Uploads
     205       3    Uint User Downloads
     208       1    Uint User ANSI 1
     209       1    Uint User ANSI 2
     210       1    Uint User ANSI 3
     211       1    Uint User ANSI 4
     212       1    Uint User ANSI 5
     213       1    Uint User ANSI 6
     214       2    Sint Minutes Credited/Removed from time
     216       2    Uint Current Message Base Number
     218       2    Uint Current File Base Number


     Telix v3.22 - Host+                                 File Formats    81



     This is a list of all information in the data file and a brief
     description of each:

          Host Version   A string (of 2 length) that contains the version
                         number of Host+.  It's a constant (it will only
                         change when a new version is released) and for
                         Host+ is set to 10.

          Host Data Dir  The name of the directory where Host+ keeps all of
                         its data files (such as HPUSER.DAT, HPFILES.1,
                         etc).  This is for doors that have their own data
                         files and wish to keep them in the data directory
                         (which they really should, just keeps everything
                         orderly).

          Status Bar     This is an integer showing the current position of
                         the Host+ status bar. If the status bar is off,
                         this will be '1', if on this will be '4'. This is
                         given so that any script doors may be able to
                         write to the screen without disturbing the status
                         information.

          Color1
          Color2
          Color3
          Color4
          Color5         These 5 integers are the five system colors that
                         have been chosen by the sysop for the system sided
                         options. These colors are provided only for the
                         ability for the door programs to make themselves
                         "Blend" into Host+ in operation and to provide a
                         more constant interface of the doors and Host+.

          Com Port       A integer that gives the actual port number
                         (1,2,3,4 and etc)

          Com Port Base  The actual address base for the com port given in
                         an decimal form. For instance, 3f8 would be 1016.

          Com Port IRQ   The IRQ number for the Com Port in use.

          AutoBaud       This is an integer that indicates if Host+ should
                         change the baud rate on a call (Locked DTE Rate).
                         If a '0', Host+ leaves the baud rate alone (the
                         DTE is locked), a '1' tells Host+ to change the
                         rate.

          Local Mode     A '1' means that Host+ is in a Local Test Mode
                         (sysop has done a local logon). A '0' means there
                         is a user online.

          Baud Rate      This is the baud rate that the caller is using.
                         In the case of high speed modems like the
                         USRobotics HST, this rate may not match the rate


     Telix v3.22 - Host+                                 File Formats    82



                         that the local modem is running.  If a door makes
                         a baud change, the DTE Rate should be the rate
                         that is used.  Any attempt to change the baud rate
                         of a High Speed modem to a rate that is different
                         from the DTE Rate will cause a loss of the
                         carrier.

          DTE Rate       This is the actual operating speed of the modem.
                         It  should always be given preference over the
                         Baud Rate  See above for more details.

          Error Correct  This is an integer that indicates if there is an
                         MNP (Error Correction) connection established.

          Logon Time     This is an integer containing the time the user
                         logged on the system. The integer is given in
                         seconds from midnight.

          Seconds Left   This is the time the user has left on the system
                         based in seconds.

          User Number    This is the current caller's User Number held in
                         the user data file. It is used to locate the user
                         information quickly.  This is NOT an actual
                         location in the data file, but is a reference
                         number that is used to calculate the data's true
                         location in the file.

          Access Level   This is an integer which represents the users
                         access on Host+. It can be a number between 0 and
                         9.

          User Name      This is the user's full name.

          User Location  This is a combination of the user's city and state
                         and State  they are calling from in the format
                         "CITY, STATE".

          User Phone     This is the user's phone number. There is no
                         special format for the phone number. It is input
                         as a string of 18 characters in length.

          User Password  This is the user's password.

          User LastOn    This is the date the user was laston. The format
                         of the date is "MM-DD-YY".

          User ANSI      This is an integer representing the user's current
                         ANSI status. A '1' means ANSI is on, and a '0'
                         means that ANSI is off.  The ANSI_x variables will
                         contain the ANSI color the user has chosen
                         regardless of this line's status. This variable
                         should always be checked before using ANSI color.


     Telix v3.22 - Host+                                 File Formats    83



          User Pause     This is an integer representing the status of the
                         pause function. If it is a '1' then Pause is on
                         and the screen should be paused every 23 lines.  A
                         '0' is off and the screen should not be paused.

          User Exper.    This is an integer representing the user's current
                         help level. A '0' is the Novice level, '1' is
                         Intermediate, and '2' is Expert.

          User Protocol  This is the user's current default protocol.

          User Uploads   This is an string which contains the total number
                         of uploads the user has made to the system.

          User Downloads This is an integer which contains the total number
                         of downloads the user has made from the system.

          ANSI_1
          ANSI_2
          ANSI_3
          ANSI_4
          ANSI_5
          ANSI_6         These six integers contain the colors chosen by
                         the user as their default color. They should be
                         used where a specific color is not required. Note
                         that these will contain the color number even if
                         the User has specified ANSI to be off. The program
                         should ALWAYS reference the User ANSI variable to
                         check if ANSI is on or off!

          Mins. Cred/Rem A Signed Integer in the amount of minutes that
                         should be credited or removed from the users time.
                         Credited time numbers from 1 to +32,767 and
                         Removed time numbers from -1 to -32,768

          Msg Base #     An integer that holds the number for the current
                         Message Base.

          File Base #    An integer that holds the number for the current
                         File Base.




     D.2  Custom Converters
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This section gives a brief listing of the "Special" format for a Host+
     Door converter.  It is given for those of you who would like to write
     your own converter.

     The converters are standard Telix scripts with a few "Extra" specific
     details about the script. Following the description is a small example
     (no actual code) for a converter script. The compiled script must have


     Telix v3.22 - Host+                                 File Formats    84



     a extension of HP, and should be placed in the HOST data directory. If
     you have a converter you have written please share it with us!

     1.   The first (not counting notes) compilable line must be a string              _____
          definition (global) of 12 characters in length giving the name of
          the BBS system the door was written to serve.  Here is the
          format:

          STR ConverterName[12] = "PCBOARD";

          It is not necessary for the actual string to have an exact 12
          characters but it must not be more than 12 characters.

     2.   The script must have two passed variables declared in main(). The
          first variable is a string that contains the path where the
          converted data file will be placed.  The second variable is an
          integer defining if the data file should be created, or should be
          erased. Since the converter must do both it is important that it
          knows which to do. Here is an example:

          main(Str Path_Name, Int EraseFiles)

          If you attempt to run the converter from outside of Host+ it will
          not run.

     3.   The converter must create / erase the data file based upon the
          value of the passed integer.  If the integer is a '0' then the
          script must create the data file. If the integer is a '1' it must
          erase it.

          The following page holds a short template for a script. It does
          not have any specific code except for the initial variable
          declaration and the branching based on EraseFiles. This example
          is to show the initial variables and the Main() variable
          declarations.


     Telix v3.22 - Host+                                 File Formats    85



     ////////////////// EXAMPLE CONVERTER //////////////////////

     Str ConverterName[12] = "EXAMPLE";
                              // define all other needed global
                              // variables here

     Main(Str Path_Name, Int EraseFiles)
     {
                              // define all needed local vars here
      If(EraseFiles)
       {
        EraseTheFile();            // run user function to delete data file
        Return;                    // return to Host+
       }
      GetData();                   // run user function, get data from .SYS
     file

      WriteData();            // run user function, write data to .SYS file

      Return;                 // return to Host+
     }

     ///////////////// END OF EXAMPLE CONVERTER ////////////////





     NOTE: This is not intended to be a lesson in writing scripts. If you
     are not proficient at writing scripts then please do not attempt to
     write your own converter. It is possible to destroy important
     information if you make a mistake.

     This information is intended solely for those people who are
     programmers. If you want/need a converter and are not able to write
     your own, we will be more then happy to help you out!


     Telix v3.22 - Host+                      External Archive Testing   87




     17.  Appendix E - External Archive Testing

     There are several attractive archive testing programs on the BBS
     market. We have left an option open to substitute one of those for
     Host+'s internal archive test routines.  During Beta test, several
     Beta users started work on scripts to mesh with their favorite archive
     program.  None were finished by release date, but you should be able
     to find them soon on the Host Software Products Support BBS.

     If you are a script writer, here are some tips for writing your own.
     Be sure an upload any successful script you write to share with
     others!

     You must start this function with a SALT script.  The script requires
     a single parameter, and MUST return a integer value of -1, 0, or 1.
     An example of the main entrance code would be:

     main(str filename)
     {
     ...
     return(xxx);
     }


     Filename would contain the name of the file just uploaded and ready
     for testing.  You could then use SALT's RUN function to start the
     program and pass the string FILENAME as the parameter.  Your archive
     test program must exit with a DOS ERRORLEVEL that gives the result of
     the test.  You must then translate that ERRORLEVEL to one of three
     return codes to pass back to Host+.

     Here are the codes:

          -1   Archive failed the test. Erase if Host+ is set to erase bad
               archives.

          0    Archive Can't Be Tested, save and notify sysop with message.

          1    Archive Tests Ok.


     Telix v3.22 - Host+                                        Index    89



                                          Chat with User..............12
     18.  Index                           Checking Uploads for Virii..73
                                          Co-sysop access..............8
     *.HP.........................3       Colors......................26
     @frst.......................40       Comment to Sysop............22
     @mins.......................40       Comments Sent To............37
     @user.......................40       Compress a single file base.53
     Access level, files.........46       Compress a single message base     
     Access Levels...............17           54
     Add a Bulletin..............26       Compressing the File Base...53
     Add a Door..................28       Compressing the Message Bases54
     Add a File Base.............34       Compressing the User File...53
     Add a Message Base..........35       Configure Event.............32
     ADDFILES.EXE.............4, 43       Configure Host+.............15
     Adding an archive program...30       Configuring Archives........30
     Adding Files................43       Configuring BBS Data........38
     Adding menu commands........67       Configuring Bulletins.......26
     Alarm.......................37       Configuring Doors...........27
     Alt-=.......................57       Configuring Events..........32
     Alt-8.......................11       Configuring General Info....36
     Alt-A.......................15       Configuring Macros..........31
     Alt-C.......................13       Configuring the Colors......26
     Alt-F................7, 15, 53       Configuring the File Bases..34
     Alt-G........................7       Configuring the Message Areas35
     Alt-I.......................12       Configuring the Modem.......25
     Alt-J................9, 12, 57       Configuring the Upload Items36
     Alt-L................9, 15, 32       Configuring User Options....33
     Alt-O................8, 15, 25       Copying files...............62
     Alt-X.......................15       Create New User.............69
     Alt-Z....................9, 11       Creating Colorful Screens...39
     Alt-I.......................12       Ctrl-O......................19
     ANSI........................39       Ctrl-Z......................19
     ANSI drawing programs.......39       Ctrl-P......................22
     ANSI editor.................64       Ctrl-X......................22
     ANSI graphics................5       CTTY.....................4, 23
     ANSI.SYS....................57       Custom Converters...........83
     Answer On Ring Number.......25       Customizing Menu Commands...65
     Archive testing..............8       Data directory...............7
     ASCII.......................39       Default colors..............26
     AUTOEXEC.BAT.................7       Default file base...........34
     Backing up..................75       Default message base........35
     BBS City/State..............38       Delete a Bulletin...........26
     BBS Name....................38       Delete a Door...............29
     BBS Net/Node................38       Delete a File Base..........34
     BBS Telephone...............38       Delete a Message Base.......35
     Black & White...............26       Deleting bad archives.......30
     Blacklist...................59       Deleting files..............62
     BNU.........................71       Disabling a command.........66
     Bulletin Listings...........21       Door converter..............83
     Bulletins...................26       Doors.......................27
     Capture Log.................13       DOORWAY Command Line........37
     Changing menu letters.......66       DOORWAY mode................57
     Chat hours..................37       DOORWAY.EXE..4, 23, 27, 37, 57
     Chat Mode Toggle............11       Download....................20


     Telix v3.22 - Host+                                        Index    90



     Download limits.........20, 33       Host+ Files..................2
     Echo........................35       HOSTDOOR.SYS............28, 79
     Echo networks...............35       HOSTPLUS.CAP................13
     Echomail....................35       HOSTPLUS.CFG.................4
     Edit a Bulletin.............27       HOSTPLUS.DAT.................2
     Edit a Door.................29       HOSTPLUS.IMG................12
     Edit a File Base............34       HOSTPLUS.KEY.................4
     Edit a Message Base.........35       HOSTPLUS.LIB.................3
     Enhanced keyboard...........19       HOSTPLUS.LNG.................3
     Environment variable.........7       HOSTPLUS.LOG.................3
     Events......................32       HOSTPLUS.OVL.................2
     EVERY event.................32       HOSTPLUS.SLC.................2
     Example Events..............73       HPBLTS.DAT...................4
     Exit........................15       HPCOMP.EXE...............3, 15
     Exit To Main Menu...........29       HPCONFIG................15, 25
     EXITTELIX event.............32       HPDOORS.DAT..................4
     Expert......................22       HPFBASE.DAT..................3
     Expert Mode.................22       HPFILES.*....................3
     Extracting an archive.......21       HPHEADER.*...................4
     F1......................11, 53       HPINDEX.*....................4
     F10.........................12       HPLOGON.SLC..................5
     F2...............9, 15, 49, 53       HPMBASE.DAT..................3
     F3......................12, 53       HPMENUS.....................17
     F4...................9, 12, 54       HPMENUS.DAT..................3
     F5......................12, 54       HPMENUS.EXE.............41, 62
     F6..........................12       HPMSG.*......................4
     FidoNet.....................35       HPMSGED.OVL..................3
     File areas..................20       HPREPAIR....................55
     File Compressor.............15       HPREPAIR.EXE.............7, 53
     File Description............44       HPUEDIT.EXE.................68
     File Formats................79       HPUSER.DAT...................3
     File management.............43       HPUTILS.SLC..............2, 49
     File ratio...............8, 33       HSHELL.BAT...................4
     File System.................19       Installing Doors............71
     Files Compressor............53       Installing Host+.............7
     Files Editor............43, 61       Intermediate................22
     Files included...............2       Jump to a Bulletin..........27
     Fossil drivers..............71       Jump to a Door..............29
     FrontDoor...................32       Jump to a File Base.........34
     Full Screen Editor......18, 19       Jump to a Message Base......35
     Full screen external user editor     Legal Issues................59
         68                               Level of Uploads............36
     Getting some sleep..........37       Line Editor.................18
     Global color codes..........40       Listing of files............20
     Global messages.............18       Listing of files, expanded..20
     Global Variables............40       Local logon...............8, 9
     Goodbye.....................22       Local Mode..................15
     Hangup......................13       Local uploads...............20
     Hardware.....................2       Log Off New Users...........33
     Help screen.................11       Logoff......................22
     Help Screen Toggle..........11       Lower Access................12
     Higher access menus.........17       Lower access menus..........17
     HINSTALL.EXE.................2       Lower Time..................12
     Host Upload Directory.......36       Machine Requirements.........2


     Telix v3.22 - Host+                                        Index    91



     Macros......................31       Security, file..............47
     Mail doors..................38       SET TELIX....................7
     Making New Menu Screens.....64       Shell to DOS8, 9, 12, 23, 37, 57
     Manually Changing Files.....46       Shut down Host+.............23
     Memory requirements..........2       Sliding events..............32
     Menu Editor.................62       Sorting, file bases.........53
     Menus.......................17       Sorting, file lists.........53
     Message areas...............35       Status box..................11
     Message Base menu...........17       Status Box Toggle...........11
     Message System..............17       Status line..................9
     Modem Answer String.........25       Support.....................77
     Modem Auto Answer Mode......25       Swapping....................57
     Modem Pickup String.........25       Sysop commands...........9, 11
     Monochrome..................26       Sysop level..................9
     Moving files................62       Sysop Name..................38
     Netmail.....................35       System hangs................23
     New callers..................8       System Log..................22
     New User Access Level.......33       System password......8, 23, 36
     New user account............49       System shutdown..........8, 37
     News file...................40       Telix Config File...........37
     Novice......................22       Telix Software Support BBS..77
     Pack all files bases........53       TEMPARC.ZIP.................21
     Pack all message bases......54       Testing archives.............8
     Packing.....................53       Text Editor.................15
     Packing the file bases......53       TheDraw.................39, 64
     Packing the message bases...54       Time limits.................33
     Packing the user file.......53       Time per access.............33
     Paging the sysop............21       Timed event.................32
     Passwords, file.............47       Trashcan file...............59
     Pickup Modem In Local.......25       TRASHCAN.DAT.................4
     Pickup Modem In Utils.......25       Turning off a command.......66
     Previous versions............7       Universal Text Interface....35
     Print user information......68       Upgrading from Host3.........7
     Privacy Act.................59       Upload......................20
     Private mail............18, 59       Upload File Base............36
     Quoting a message.......18, 19       Upload limitations..........36
     Raise Access................12       Uploading a message.........18
     Raise Time..................12       Uploads, access to..........36
     RAM requirements.........2, 57       User Commands...............17
     Reading messages............17       User editor......9, 15, 49, 68
     Redefining keys.............31       User Fields.................49
     Repairing Damaged Files.....55       User options................33
     Reset Default Options.......38       User records, deleting......53
     Restoring and Saving Configs38       User settings...............22
     RIME........................35       User status.................50
     Running a door..............22       Using a Fossil Driver.......71
     Saving a message........18, 19       Using Doorway.EXE...........57
     Screen Image................12       Using Scripts as Doors......72
     Screen input................39       UTI.........................35
     Screen saver................37       Viewing an archive..........20
     Screen Size.................39       Virus checking..............73
     Scripts as doors............72       Writing messages............18
     Search Users................68       X00.........................71
     Security.................8, 59








     Telix v3.22                                   License    iii



                                       LICENSE


     Telix is Copyright (c) 1986-1994 by deltaComm Development, Inc.

     Telix is not, nor has ever been, public domain or free software.

     The commercial, registered version of Telix may not be duplicated other
     than for backup purposes. A registered copy of Telix must be treated like a
     book, in that the same registered copy of Telix may not be used in more
     than one computer at the same time, just as a book may not be read by more
     than one person at the same time (without making an illegal copy).

     Users are granted a limited license to use the User Supported, trial
     version of Telix for a limited evaluation period of up to 45 days, in order
     to determine if it suits their needs. Any other use of Telix or use past
     this period requires registration.

     All users are granted a limited license to copy the User Supported version
     of Telix only for the purpose of allowing others to try it, subject to the
     above restrictions as well as these:

          Telix must be distributed in absolutely unmodified form, including ALL
          program, documentation, and other files.

          Telix may not be included with any other product for any reason
          whatsoever without a license from deltaComm Development, Inc.

          No charge or payment may be levied or accepted for Telix.

     Bulletin Board system operators may post the unregistered, User Supported
     version of Telix on their BBS for downloading by their users without
     written permission only if the above conditions are met, and only if no
     special fee is necessary to access the Telix files (a general fee to access
     the BBS is ok).

     Distributors of User Supported and Public Domain software MUST obtain
     written permission from deltaComm Development, Inc., before distributing
     Telix and must follow the above conditions, as well as other detailed at
     the time of request for a distributor's license.

     Liquidated damages assessed and collectible from distributors of User
     Supported and Public Domain software found to be distributing Telix
     without a current distributor's license in writing from deltaComm shall
     be $2 US (Two United States Dollars) *per unauthorized distributed copy*.


     Telix v3.22                                    License    iv

                       Telix Ordering/Registration Information

     Registering (buying) Telix allows you to use the product after the trial
     period. Registered Telix users get the current version of Telix on disk
     along with their own serial number, an optional printed manual, mailed
     notification of major Telix updates, and priority when calling the Telix
     Software support BBS (we guarantee no support to unregistered users). Most
     importantly, registered users know they are helping to make sure that high-
     quality software like Telix continues to be sold in this low-cost way.

     Telix registration costs $44 US / $59 CDN, and includes a 'registered' copy
     of Telix on disk. A commercial version is available for $59 US / $79 CDN.
     An evaluation disk with the current copy of Telix on it is also available
     for $10 US / $12 CDN. This is to be used to try out Telix, and does not
     include registration (the right to use Telix after the evaluation period).
     The fee covers the cost of diskette(s) and handling.

     Registered users will receive access to our online service, featuring many
     thousands of megabytes of shareware for download, access to internation
     echo mail, Internet mail, Reuters news services, weather services, stock
     quotes and more. A one year subscription to deltaComm Online, including
     access to all of the above features and more, is included with your order.

     Payment may be in the form of check, money order, or with a VISA or
     Mastercard. We also accept corporate purchase orders for amounts of $44 US
     and over. All US dollar checks must be drawn on a US bank, and all Canadian
     dollar checks must be drawn on a Canadian bank. Note that we quote
     equivalent prices in both $US and $CDN, but as we are a US company all
     credit card orders will be billed in $US, and your card statement will show
     any conversion between currencies.

     To place an order, please use the order form on the following page, or call
     us toll free from North America at (800) TLX-8000, or at (919)-460-4556
     with your VISA or Mastercard ready.

     Previously registered owners of Telix may use the 3.22 evaluation release
     at no charge, or may use the posted patch files to upgrade registered 3.12
     or later copies with serial numbers to the latest minor revision.  Users
     who have registered but do not have serial numbers (some versions of 3.11
     and prior) will need to purchase an update disk for $10 US.

     Shipping is $10 for a single copy, shipped via Second Day Air within the
     United States, and via Air Mail to other areas.

     Please call 800-859-8000 or 919-460-4556 for shipping price on orders for
     multiple copies of Telix.


     Telix v3.22                                     License    v



                          Quantity and Corporate Purchases

     The order form on the following may be used to purchase multiple copies of
     Telix, with discounts as follows:

                           1 -  10 copies     no discount
                          11 -  20 copies    10% discount
                          21 -  50 copies    15% discount
                          51 - 100 copies    22% discount
                         101 - 200 copies    30% discount
                         201 - 999 copies    40% discount
                         1000 copies plus    50% discount

     Multiple copy purchases are simply bulk purchases and include that many
     copies of Telix on disk (with optional printed manuals), as with single
     registrations. We also have available site licenses (at a slight reduction
     in price), which are based on a fixed number of copies, but in which the
     site performs the diskette duplication from master disks and labels
     supplied by us.

                                International Orders

     Telix is commercial software in Western Europe.  Telix users Telix users
     in Western Europe wishing to register must obtain Telix from our
     European distributor, ELSA GmbH, Aachen, Germany.  A German language
     version of Telix is available, and other languages are forthcoming.
     Please use the appropriate *.REG form included with this version of Telix.

     Locally owned and operated registration sites are currently in place in
     Great Britain and Germany, with others forthcoming.  Please see the file
     EUROPE.DOC for complete details about other sites that are available.

     A locally owned and operated registration site is available for users in
     Australia and New Zealand.  Use the order form in AUSSIE.REG for pricing
     and ordering information.


     Note: All prices, discounts, and registration sites are subject to change
     without notice. Discounts apply only to separate orders, they are not
     cumulative.


     Telix v3.22                                    License    vi

          If ordering from Australia or Europe, please order from your local
          dealer, using the appropriate form (*.REG) included with Telix.

          Telix version 3.22                                     #940131-322
          ------------------------------------------------------------------
          Remit to: deltaComm Development, PO Box 1185, Cary, NC  27512  USA
          ------------------------------------------------------------------
          Quan       Item                              US/CDN        Price

          ___  Telix Registration................   @ $44/$59 ea   $________
                (includes serial #, registration +
                  program and manual on disk)

          ___  Telix Commercial Version..........   @ $59/$79 ea   $________
                (same as above, plus 360 page
                  typeset manual & retail packaging)

          Disk media:  5.25" [  ]     3.5" [  ]     Low Density [  ]

                                                 Volume Discount   $(______)

          Single Copy Shipping/Handling is:   ------>   Shipping   $________
          USA:           : $10, via Second Day Air
          Elsewhere      : $10, via Air Mail

          Call 800-859-8000 for multiple copy shipping rates

                                                        Subtotal   $________

           N. Carolina residents please add State Sales Tax (6%)   $________

                                                           TOTAL   $________

          ------------------------------------------------------------------
          Payment by: ( ) Check or MO  ( ) VISA/MC  ( ) PO # ____________

              Name_______________________________________________________

           Company_______________________________________________________

           Address_______________________________________________________

                  _______________________________________________________

                      Visa/MC orders will be charged in US currency
              The following information is needed for VISA/MC card payments

             Phone(______)________________  Other(______)________________

            Card #_______________________________  Expiry date___________

          Name of cardholder_____________________________________________

          Signature______________________________________________________
                        (VISA/MC orders may also call voice: 800-TLX-8000
                        (VISA/MC orders may also fax:        919-460-4531































     T E L I X

     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     SALT Programming Manual












             Copyright (C) 1986-1994 by deltaComm Development, Inc.


                              ALL RIGHTS RESERVED.



                           deltacomm Development, Inc.

                    P.O. Box 1185, Cary, NC   27512   USA

             (919)-460-4556 / (919)-460-4531 fax (919)-481-9399 BBS
     Telix v3.22 - SALT Programming                         COPYRIGHT    ii







                                COPYRIGHT NOTICE



     Telix is Copyright (c) 1986-1994 by deltaComm Development, Inc.

     This document is Copyright (c) 1988-1994 by deltaComm Development, Inc.

     No parts of Telix or this document may be copied in part or in whole,
     except as provided in the License included with Telix.





                                   DISCLAIMER

     deltaComm Development, Inc., makes no warranty of any kind, either
     express or implied, including but not limited to implied warranties of
     merchantability and fitness for a particular purpose, with respect to
     this software and accompanying documentation.

     IN NO EVENT SHALL DELTACOMM DEVELOPMENT, INC., BE LIABLE FOR ANY DAMAGES
     (INCLUDING DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
     LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING OUT OF THE
     USE OF OR INABILITY TO USE THIS PROGRAM, EVEN IF DELTACOMM DEVELOPMENT,
     INC., HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.


     
                                   TRADEMARKS

     Telix and SALT are trademarks of deltaComm Development, Inc.
     Telix v3.22 - SALT Programming                         Contents    iii



     

                                 C O N T E N T S



     1.  The Telix SALT Language.....................................1
     1.1  What Can be Accomplished With SALT?........................1
     1.2  About This Manual..........................................1
     1.3  Notation...................................................1
     1.4  Creating SALT Programs.....................................1

     2.  Syntax......................................................3
     2.1  Comments...................................................4

     3.  Program Structure...........................................5
     3.1  Variables..................................................5
     3.2  Expressions and Operators..................................7
     3.3  Functions..................................................9
     3.4  Statements................................................10
       3.4.1  The Expression statement..............................11
       3.4.2  The If statement......................................11
       3.4.3  The While statement...................................13
       3.4.4  The Do...While statement..............................13
       3.4.5  The For statement.....................................14
       3.4.6  The Return statement..................................15
       3.4.7  The Break statement...................................15
       3.4.8  The Continue statement................................16
       3.4.9  The Goto statement....................................17

     4.  Built-in Functions.........................................19
     4.1  Quick Listing of Functions by Type........................20
     4.2  Complete Function Reference...............................22

     5.  System Variables...........................................97

     6.  Appendix A - ASCII Character Set..........................114
     7.  Appendix B - Extended Key Scan Codes......................115
     8.  Appendix C - Color Values.................................116
     9.  Index.....................................................117

     Telix v3.22 - SALT Programming                       Introduction    1





     1.  THE TELIX SALT LANGUAGE

     Telix has a built-in programming language called SALT (Script Applica-
     tion Language for Telix). SALT will allow you to perform almost any
     communications related applications with Telix. SALT looks similar to
     the C language, however if you have used almost any programming lan-
     guage (such as Pascal, BASIC, etc.), you should feel quite at home
     with SALT. While SALT was designed to be easy to learn, it is like
     most programming languages quite complete, so it is recommended that
     you read this chapter thoroughly and study the examples provided, as
     well as the sample SALT scripts included with Telix.


     1.1  What Can be Accomplished With SALT?
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Like a program in any programming language, a SALT program (also
     called a 'script') is typically used to perform a needed task or func-
     tion. The task can range from the very simple to the very complicated.
     For example, a SALT script can be linked to a dialing directory entry,
     so that when you have established a connection to that service, it au-
     tomatically sends your i.d. and password to the remote service. A much
     more complicated SALT script is used as the basis for the Host Mode
     included with Telix.


     1.2  About This Manual
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This manual is basically a reference to the SALT programming language.
     It is by no means a tutorial on programming in general. It is assumed
     that the reader of this manual is at least familiar with general pro-
     gramming concepts.


     1.3  Notation
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Throughout this manual, certain words in examples and in the text will
     be surrounded by angle brackets and italicized, for example,
     <expression>. These words are not to be taken as literal text. they
     stand for something else, such as a word, a group of words, or even
     several lines of text. What these italicized words stand for will be
     explained as they come up.


     1.4  Creating SALT Programs
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A SALT script is basically a sequence of instructions for Telix to
     follow, using a specific syntax. You may use any text editor to pro-
     duce this script file, as long as its output is normal ASCII text
     (this means that if you use your word processor, you must usually ex-
     plicitly tell it to write out the file using ASCII format and to not
     embed any special codes in the file). You may give any name you wish
     Telix v3.22 - SALT Programming                       Introduction    2



     to a SALT source file, although we recommend that you always use the
     extension .SLT for clarity.

     Once you have written your script file and saved it to disk, it must
     be compiled. The program CS.EXE included with Telix reads your
     'source' script file, and compiles it to a form which Telix can under-
     stand. The compiled script can then be loaded more quickly by Telix,
     and is also usually smaller.

     To compile a script source file, type

          cs <pathname>

     while at the DOS prompt and then press Enter (or Carriage Return). The
     CS.EXE program must be in the current directory or on the DOS PATH.
     <pathname> is the name of the file to compile, and may include the
     drive and directory as well as the filename. The output file is writ-
     ten to the same name except that the extension .SLC is used.

     When the script compiler finds an error in your source file, it will
     abort the compile process and give you the line number on which the
     error occurred, as well as the type of error. The error should then be
     fixed and the source re-compiled. This is repeated until the compiler
     detects no more errors in your source file.

     The compiled script can then be run in Telix using several methods. It
     may be run using the 'Run script' command, as a command-line option
     when running Telix from DOS, as a linked script to a dialing directory
     entry, or from another script. The first three methods are described
     in the Telix manual, while the last is described later in this manual.
     Telix v3.22 - SALT Programming                             Syntax    3





     2.  SYNTAX

     Case is not important in command, function, and variable names. The
     only time case matters is inside a string constant (e.g., "Hello" is
     not the same string as "hello"). Whitespace (such as the space, the
     tab, the Carriage Return, or the Line Feed character) is not impor-
     tant. The script compiler does not care where you place items, so that
     you may arrange the program as you see fit. For example,

          if (value == 1)
            prints("value is equal to 1!");
          else
            prints("values is not equal to 1.");

     is equivalent to

          if (value == 1) prints("value is equal to 1!");
          else            prints("value is not equal to 1");

     or even to

          if(value==1)prints("value is equal to 1!");else prints("value is
          not equal to 1.");

     The only time whitespace matters is when it would split up key-words
     or function name, or in a string. For example, the key-word 'while'
     must not be split up if it is to be recognized. The same applies to
     other key-words or function names. As well, there must be space be-
     tween the letters of a command and other letters. For example, 'while'
     is not the same as 'whileabc'. In the interest of clarity, it is rec-
     ommended that you try to make your code easy to understand, by indent-
     ing where appropriate, and by using space effectively. There is no
     reason, for example, to put more than one statement on a line, even if
     it is perfectly legal. A good example of program style can be found by
     looking at the sample scripts included with Telix.

     A string constant is a sequence of ASCII characters enclosed in
     quotes, for example, "Hello", "Good-bye", or "Telix". It is often nec-
     essary for a string constant to include special characters that can
     not easily be typed from the keyboard, or can not be easily displayed.
     This is done with something called the escape character, which is the
     caret ('^') symbol. When the SALT compiler is reading a string con-
     stant and comes to the '^' symbol, it replaces it with a certain ASCII
     code based on the character following the ^. Translations are as fol-
     lows:

          ^c        'c' is a letter. The Control representation of whatever
                    letter 'c' is, is inserted into the text. Therefore ^M
                    represents Ctrl-M, ^j represents Ctrl-J, etc. Whether
                    the letter 'c' is upper or lower case is not signifi-
                    cant. Note that what is really happening here is that
                    64 is being subtracted from the value of 'c', so for
                    example, the Escape character can be represented as ^[.
          ^^        An actual caret ('^') symbol is placed into the text.
     Telix v3.22 - SALT Programming                             Syntax    4



          ^"        An actual double quote symbol ('"') is placed into the
                    text. If a string must contain a double quote symbol,
                    this is how it has to be done. If the plain '"' symbol
                    were to be used, the compiler would think that the
                    string was terminated at that point. For example, the
                    string "He said, ^"Hello^"." is translated to 'He said,
                    "Hello".'.
          ^'        An actual single quote symbol (''') is placed into the
                    text.
          ^nnn      'nnn' is up to 3 digits representing the ASCII value of
                    the character which should be placed into the text. A
                    maximum of three digits is read, or up to the first
                    non-digit character. For example, the compiler would
                    read in the string "S^65LT" and output the string
                    "SALT", since 65 is the ASCII value of 'A'. Note that
                    if nnn is less than 3 digits you may have to pad it
                    with one or two leading zeros if there are digits imme-
                    diately following it in the string, so that the wrong
                    value is not read in. For example the string "^79 Park
                    Avenue" would translate to "O Park Avenue" since 79 is
                    the ASCII value of 'O'. If you actually wanted Ctrl-G
                    (ASCII code 7) followed by "9 Park Avenue", you would
                    use the string "^0079 Park Avenue".

     An integer constant is a sequence of digits representing an integer
     value in the range -2147483648 to 2147483647. An integer constant must
     start with a digit from 0 to 9 or the negative sign (-) followed by a
     digit. The following are all valid integer constants:

          10
          -400067
          999

     An integer constant may also be entered in hexadecimal form (base 16,
     where each digit may be from '0' to '9' or 'a' to 'f', to represent 16
     values). Hex values must be preceded by '0x' for the compiler to in-
     terpret them as such, and case is not important. The following are all
     valid integer constants enter in hexadecimal form:

          0xff00
          0Xa2
          0x7D
          0x1AbCdEf


     2.1  Comments
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A comment in a source file is text that does not affect what the pro-
     gram does, and is meant purely for explaining or describing something.
     In a SALT source file, whenever the symbol // is encountered on a
     line, all the characters from that point on until the end of the line
     are considered to be a comment and are ignored. For example:

          prints("Hello");       // This line will print "Hello"
     Telix v3.22 - SALT Programming                  Program Structure    5





     3.  PROGRAM STRUCTURE

     A SALT script has the following format:

          <global_variable_definition>
               ...
          <global_variable_definition>

          <function_definition>

          <global_variable_definition>
               ...
          <global_variable_definition>

          <Function_definitions>

               ...

     and so on. Basically a script file consists of definition of global
     variables (variables which are available to any part of the script
     file after which they are defined, and function definitions (functions
     are lines of code clustered together in a group, so that they can be
     called by a name). A script file does not have to have any global
     variables or functions, but to run it must at least have one function
     called 'main'. The following, for example, is a complete script file:

          main()

          {

           prints ("hello");

          }

     When compiled and run, this script would print the string "hello" to
     the screen.


     3.1  Variables
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A variable is a location in memory where something is stored. The con-
     tents of a variable can be changed by program code (hence the name).
     In SALT, there are two types of variables, integer variables, and
     string variables. The former holds an integer value (e.g., 485624, or
     -627), while the latter holds a text string (e.g. "Telix", or
     "SCRIPT"). Depending on where it is defined, a variable is either
     global or local. If a variable is global, it means that it can be used
     by any part of the script after the point where it is defined. If a
     variable is local, it means that it can only be used by the part of
     the script to which it is 'local', for example, the function inside
     which it is defined. A variable name can be up to 31 digits long, and
     may include the letters 'A' to 'Z' or 'a' to 'z', the digits '0' to
     '9', or the underscore character (_). The name may not start with a
     Telix v3.22 - SALT Programming                  Program Structure    6



     digit. For example, 'his_name2' and '_his_name2' are legal as variable
     names, while '2his_name' is not.

     An integer variable is defined in the form

          int <varname>;

     where <varname> is the name to be given to the variable. An alternate
     definition is

          int <varname1>, <varname2>, ..., <varnameN>;

     which allows you to define more than one integer variable in one
     statement. An original value can be assigned to the integer variable
     by using the form

          int <varname> = <int_const>;

     where <int_const> is an integer constant. Similarly, an original value
     can be assigned in the multiple definition above by placing the as-
     signment before the comma. Some examples are:

          int maximum;
          int start = 0;
          int level, i, count = 20, loop;

     A string variable is defined in the form

          str <varname>[<max>];

     where <varname> is the name to be given to the variable. <max> is the
     maximum number of characters that the string can hold, and must be in
     the range of 0 to 32767. An alternate definition is

          str <varname>[<max>], <varname2>[<max>], ..., <varnameN>[<max>];

     which allows you to define more than one string variable in a state-
     ment. An original value can be assigned to the string variable by us-
     ing the form

          str <varname>[<max>] = <str_const>;

     where <str_const> is a string constant. Similarly, an original value
     can be assigned in the multiple definition above by placing the as-
     signment before the comma. Some examples are:

          str password[80];
          str password[40] = "mypass", name[30];

     The string length field may be left empty if an original value is
     specified, in which case the length of the string variable is assumed
     to be that of the assigned text, e.g.

          str name[] = "John";

     If a variable is outside of a function, it is global. If it is defined
     inside a function, it is local to that function and will only be rec-
     Telix v3.22 - SALT Programming                  Program Structure    7



     ognized there. If a variable defined inside a function uses the same
     name as a global variable, any reference to that name while in the
     function will access the local variable. After the function has com-
     pleted, the local variable is removed and a reference to that name
     will access the global variable.


     3.2  Expressions and Operators
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     An expression is a mixture of symbols which resolves to a value when
     evaluated. In other words, an expression is basically a formula. An
     expression can consist of constants, variables, function calls, and
     operators. An expression can be very simple, or very complicated. For
     example, some expressions are:

          10 + 3 - 5
          9 * 7 / 63 - 30
          result = 10 * max(a, b)
          month >= 10
          200
          command == "bye"
          prints("Hello")

     In an expression, the data being acted upon are constants, variables,
     and functions calls, while the operators (+, *, etc.) are the symbols
     that do things with the data. There are many different operators, of
     which there are two basic types. Binary operators (such as +, *, /)
     perform a calculation on the expression on either side of them. Unary
     operators appear before a single expression and work on that. The fol-
     lowing table lists the operators available in SALT:

            Symbol      (Un/Bin)ary          What it is/does
              -            unary             Arithmetic negation
              !            unary             Logical NOT
             not           unary             Logical NOT (alternate)
              ++           unary             Increment
              --           unary             Decrement
              *            binary            Multiplication
              /            binary            Division
              %            binary            Remainder (Mod)
              +            binary            Addition
              -            binary            Subtraction
              <            binary            Less than
              >            binary            Grater than
              <=           binary            Less than or equal to
              >=           binary            Greater than or equal to
              ==           binary            Equality
              !=           binary            Inequality
              &            binary            Bitwise AND
              |            binary            Bitwise OR
              ^            binary            Bitwise Exclusive OR
              &&           binary            Logical AND
             and           binary            Logical AND (alternate)
              ||           binary            Logical OR
              or           binary            Logical OR (alternate)
              =            binary            Assignment
     Telix v3.22 - SALT Programming                  Program Structure    8




     Note that the hyphen symbol can be either an arithmetic negation or a
     subtraction depending on its use. Note that '!' is equivalent to
     'not', '&&' is equivalent to 'and', and '||' is equivalent to 'or'.
     The first form is preferred as you do not have to leave whitespace
     around it for the compiler to recognize it, but beginners may have an
     easier time remembering the second form. Also, do not confuse the '='
     (assignment operator) with the '==' (equality operator). The former is
     used to assign a value to a variable, while the latter is used to com-
     pare two values. Assuming you have the two expressions, <expr1> and
     <expr2>, <expr1> = <expr2> would assign one to the other, while
     <expr1> == <expr2> would test the two to see if they are equal. For
     example

          num = 10

     would assign the value 10 to the variable called 'num', while

          num == 10

     would resolve to a value of non-zero (TRUE) if num was equal to 10,
     and 0 (FALSE) if num was not equal to 10. There is also a difference
     between the Logical operators and the Bitwise operators. The Logical
     operators (such as and, &&, or, ||, etc), work with TRUE or FALSE val-
     ues and result in a TRUE or FALSE value, while the Bitwise operators
     (&, |, ^) work with the actual bits of the data they are handling. The
     Bitwise operators almost never have to be used in a Telix script, un-
     less it is needed to get at the actual bits in a data byte.

     Every operator resolves to a value, which is the result of the opera-
     tion performed (e.g, 10 * 7 would resolve to 70). The conditional or
     equality operators such as ==, >, <=, etc., resolve to  a 0 (FALSE))
     or non-zero (TRUE) value based on the results of the expression. Even
     the assignment operator = resolves to a value. The result of the ex-
     pression

          num = 10

     would be 10.

     All the operators have something called precedence, which is their im-
     portance, and determines the order in which they are evaluated. For
     example, 7 + 3 * 9 is equal to 34, because 3 * 9 is evaluated first,
     and then added to 7 (* has a higher precedence than +). All the opera-
     tors are listed below in order of decreasing precedence. All the oper-
     ators on the same line have the same precedence, and are resolved in
     the order that they are encountered.
     Telix v3.22 - SALT Programming                  Program Structure    9



          -  !
          ++  --
          *  /  %
          +  -
          <  >  <=  >=
          ==  !=
          &
          |
          and  &&
          or  ||
          =

     If a certain evaluation order is required that does not follow these
     rules of precedence, parentheses may be used. Thus, 99 + 1 * 10 equals
     109, while (99 + 1) * 10 equals 1000.

     If you are writing an expression of any sort, and are not sure of the
     exact precedence of the operators you are using, use parentheses!


     3.3  Functions
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A function is a way of grouping together some lines of code. A Telix
     script consists of one or more functions. There are quite a few advan-
     tages to having functions:

          One function can be called from another, to do a certain task.
          The calling function does not have to know anything about the
          called function other than what it does. This allows a script to
          be split up into modular units, and makes code writing and debug-
          ging easier.

          As mentioned above, what a function does it private. This means
          that data variables defined in a function are local to that func-
          tion, and therefore you do not have to worry about another part
          of the script unintentionally modifying them.

          A library of functions can thus be built. Later, you do not have
          to re-write old code.

     Functions are defined in the following format:

          <funcname>(<arg1>, <arg2>, ..., <argN>)

          {
           <variable_def>
               ...
           <variable_def>

           <statement>
               ...
           <statement>
          }
     Telix v3.22 - SALT Programming                 Program Structure    10



     <funcname> is the name of the function. It follows the same rules of
     other identifiers in SALT. There can only be one function that uses a
     given name, however.

     <arg1> through <argN> are the declarations of the arguments
     (parameters) that have been passed to the function by its caller
     (sometimes, to accomplish its task, a function needs to have some val-
     ues passed to it). Each argument is defined in the form <type> <name>
     where <type> is 'int' or 'str', and <name> is the name it should be
     called by. At present, a function is not allowed to have more than 12
     values passed to it.

     <variable_def> is a variable definition, as described in the above
     section on that topic. Any number of variables may be declared at this
     part of the function. All such variables will be local variables and
     available only to this function.

     <statement> is an actual line of code. There may be as many lines of
     statements in the function as needed. The format of a statement is de-
     scribed below. First though, here is an example of a complete func-
     tion:

          max ( int a, int b )

          {

           int result;

           if (a > b)
            result = a;
           else
            result = b;

           return result;

          }

     This function returns the larger (maximum) of the two values passed to
     it. It could have been written much more simply (without the use of
     the variable), but was written this way so that all the function ele-
     ments would be there.


     3.4  Statements
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A statement is the basic element of code. A statement ALWAYS ends with
     a semicolon character (;). In any location where a statement is ac-
     ceptable, you may use a group of statements, by enclosing them all in
     curly braces (more on this below). There are many types of statements,
     including: expression, if, while, do...while, for, return, break, con-
     tinue, and goto statements. Each type has several different parts.
     Telix v3.22 - SALT Programming                 Program Structure    11



     3.4.1  The Expression statement

     The 'expression' statement is the simplest and most common type of
     statement. Its format is

          <expression>;

     where <expression> is any expression. Example are:

          result = 20;
          password = "Beef";
          pause(20);
          num = 20 * max(a, b);

     Do not forget the semicolon character at the end of the statement. If
     you do, the compiler will think that the next statement is part of the
     current one, and will report some unexpected error.


     3.4.2  The If statement

     An 'if' statement is used when a statement or group of statements
     should be evaluated only if a condition is true. The format for an
     'if' statement is as follows:

          if (<expression>)
            <statement>

     <statement> is any statement as described above and below (that is, an
     expression, if, while, do...while, for, return, break, or continue
     statement), and will only be executed if <expression> evaluates to
     non-zero. By using curly braces around them, a whole group of state-
     ments may be conditionally evaluated. Some examples are:

          if (result == -1)
            prints("ERROR!");

          if (num_tries > maximum)
            return 0;

          if (month > 10 && day < 20)
           {
            clear();
            prints("In range.");
            return 1;
           }

     An alternate form of the if statement is:

          if (<expression>)
            <statement1>
          else
            <statement2>

     In this case, if <expression> evaluates to non-zero (TRUE),
     <statement1> is executed, otherwise <statement2> is executed. Again,
     Telix v3.22 - SALT Programming                 Program Structure    12



     multiple statements may be used instead by grouping them in curly
     braces. Some examples are:

          if (stat == -1)
            prints("Error status returned.");
          else
            prints("Function finished without problems.");

          if (level < 10)
           {
            alarm(1);
            prints("Warning!");
           }
          else
            prints("Everything's ok.");

     Since the statement to be executed conditionally can be of any type,
     that means that any number of if statement can be nested if needed.
     For example:

          if (num < 10)
            if (!error)
              if (read != 0)
                return 1;

     This also means that something like the following is legal:

          if (value == 10)
            do_this();
          else if (value == 100)
            do_that();
          else if (value == 1000)
            do_something_else();
          else
            do_whatever();

     What is really happening here is that each if statement is being
     nested after the else portion of the previous one. The above example
     could also be written as:

          if (value == 10)
            do_this();
          else
            if (value == 100)
              do_that();
            else
              if (value == 1000)
                do_something_else();
              else
                do_whatever();

     Any amount of nesting is theoretically legal, but the compiler does
     have a limit due to memory constraints.

     While you may write the code in any way which suits you, it is recom-
     mended that you use indenting, for clarity. Indenting your code at the
     proper places makes it a lot easier to read.
     Telix v3.22 - SALT Programming                 Program Structure    13



     A very common error to watch out for is accidentally placing a semi-
     colon after the parenthesis ending the expression. For example, if the
     following is run:

          if (num == 10);
            prints("Num is equal to 10);

     the string would always be printed, no matter what num was equal to.
     This is because the semicolon after the parenthesis ending the expres-
     sion signifies the end of the statement. In the above case, it would
     just be a null (empty) statement.


     3.4.3  The While statement

     The while statement is used to loop continuously while a certain con-
     dition is true. It has the form

          while (<expression>)
            <statement>

     <statement> would continue to be repeated over and over while
     <expression> evaluated to non-zero (TRUE). Note that if the expression
     evaluates to 0 (FALSE) from the beginning, the statement will never be
     executed. Again, multiple statements may be used by surrounding them
     in curly braces. A few examples are:

          while (stat != -1)
            stat = myfunc();

          while (num < 100)
            {
             printn(num);
             prints("");
             num = num + 1;
            }

          while (1)
            {
             if (func1())
               return 0;

             func2();
            }

     Again, be careful to not place a semicolon after the parenthesis end-
     ing the expression.


     3.4.4  The Do...While statement

     The do...while statement is similar to the while statement and has the
     form:

          do
            <statement>
          while (<expression>);
     Telix v3.22 - SALT Programming                 Program Structure    14




     <statement> will be executed at least once and will continue to be ex-
     ecuted repeatedly until the expression becomes 0 (FALSE). A few exam-
     ples are:

          do
            stat = func1();
          while (stat != -1);

          do
           {
            prints("hello");
            num = num + 1;
           }
          while (num < 100);


     3.4.5  The For statement

     The for statement is used to loop continuously while a certain condi-
     tion is true. The advantages over the while statement is that a count
     variable can be initialized and incremented quite easily. The for
     statement has the form:

          for (<expression1>; <expression2>; <expression3>)
            <statement>

     The first expression is the one that should initialize the count vari-
     able. For example, if you wanted to count from 1 to 100, and were
     keeping the count in a variable called 'num', the first expression
     would be 'num = 1'. The second expression is the conditional test. As
     long as it evaluates to non-zero (TRUE), the statement will be exe-
     cuted. Following the above example, this expression would be
     'num < 100'. The third expression is the one that is used to increment
     the count variable. For the above example, it would therefore be
     'num = num + 1'. This for statement differs in format from that in
     most other languages, but doing it this way is actually gives the pro-
     grammer a lot of power and flexibility. Note that any of the expres-
     sions can be left empty, in which case they evaluate to non-zero
     (TRUE). Some examples are:

          for (count = 0; count < 100; count = count + 1)
           {
            printn(count);
            prints("");
           }

          for (c = 1000; c > 0; c = c - 1)
            do_this(c);

     The following would execute an infinite loop:

          for (;;)
            prints("Hello!");

     Note that there is really no restriction on what the expressions are.
     For example, the following is quite legal:
     Telix v3.22 - SALT Programming                 Program Structure    15



          for (c = num = 0; c < 100 && stat != -1; c = c + 1)
            {
             stat = func(num);
             num = func2();
            }

     The statements would only be executed if c was smaller than 100 and
     stat didn't equal -1.


     3.4.6  The Return statement

     At some time, every function must be exited. If the end of the func-
     tion is reached, control will automatically return to the calling
     function. Very often however, it is necessary to leave a function
     somewhere while only halfway through it, perhaps based on a condi-
     tional test. As well, it is often necessary that a function returns a
     value to the caller. The format of the return statement is:

          return <expression>;

     If the return statement is encountered anywhere in the function, con-
     trol immediately returns to the function that called this function.
     The expression is the value that should be returned. If no expression
     is supplied, a dummy value is returned. The expression should match
     they type of value that the caller of this function is expecting. That
     is, if an 'int' type is expected, the expression should resolve to an
     integer value. If a 'str' type is expected, the expression should re-
     solve to a string value. Due to memory constraints, a local string
     variable may NOT be returned from a function. Some examples are:

          return;
          return 1;
          return level;
          return (sum + 25);
          return "hello";
          return (func() + 20);

     Notice that when a complex expression is returned it is usually sur-
     rounded by parentheses. This is done only for clarity and is not nec-
     essary. Also, it should be clear that what is returned is not the ex-
     pression but what it evaluates to.


     3.4.7  The Break statement

     Often while using a looping statement (while, do...while, for), it is
     necessary to break out of (exit) the loop. The break statement serves
     this purpose. When the break statement is encountered, execution of
     the smallest while, do...while, or for loop is terminated, and execu-
     tion continues immediately after the terminated loop statement. It is
     an error for a break statement to appear outside of a loop. The format
     of the break statement is:

          break;

     For example, assuming you had the following code:
     Telix v3.22 - SALT Programming                 Program Structure    16



          int num = 0;
          while (1)
           {
            num = num + 1;
            if (num > 100)
              break;
           }
          prints("Done");

     Ordinarily, since there will always be a non-zero (TRUE) value in the
     conditional part of this while statement, it would execute forever.
     However, when the 'num' variable is > 100, the break statement is exe-
     cuted to exit from the loop, at which point the next statement would
     be executed (the function call to prints).


     3.4.8  The Continue statement

     The continue statement is used within a loop (while, do...while, or
     for statement). The continue statement has the form:

          continue;

     It is illegal for a continue statement to appear outside of a loop
     body. When a continue statement is encountered, program control is im-
     mediately transferred to the end of the body of the innermost en-
     closing while, do...while, or for statement. The effect in a while or
     do...while statement is that the condition part of the while or
     do...while statement is evaluated, and the next iteration of the loop
     occurs. For example:

          num = 0;
          while (num < 100000)
           {
            num = num + 1;
            if (num > 100)
             continue;
            prints("Hello");
           }

     The effect of the continue statement in the above loop would be that
     'Hello' would only be printed while 'num' was smaller or equal to 100,
     as the continue statement is executed when num is bigger than 100,
     which causes the rest of the loop body to be skipped. An example for
     statement would be:

          for (num = 0; num < 100000; num = num + 1)
           {
            if (num > 100)
             continue;
            prints("Hello");
           }

     The effect in this case would be the same. While 'num' is smaller or
     equal to 100, the entire loop body executes. If 'num' is greater than
     100 however, the continue statement is executed. This causes the rest
     of the loop body to be skipped, so the 'Hello' is then not printed.
     Telix v3.22 - SALT Programming                 Program Structure    17



     3.4.9  The Goto statement

     The goto statement is used to branch (jump) from one place to another,
     within a function. The use of goto statements is considered bad style.
     They can make code very hard to understand, and are in fact almost
     never necessary. For example, Telix is written mainly in the C lan-
     guage, which has a goto statement, yet except for a few pieces of pre-
     written code, the goto statement was never used nor needed. On the
     other hand, used very sparingly and properly, it can sometimes make
     some code clearer and perhaps faster. The goto statement consists of
     two parts, the 'label' or marker, which is where execution will jump
     to, and the actual goto itself. A label is defined in the form

          <identifier>:

     where <identifier> follows the same rules as for variable names. Note
     that a colon follows the name, not a semicolon. The colon character
     must immediately follow the label name, with no intervening spaces. A
     label does not have to be on a line by itself, and is not considered a
     statement by itself. The goto takes the form

          goto <label>;

     where <label> is a label elsewhere in the function defined as de-
     scribed above. Execution of the script will immediately continue fol-
     lowing the label.

     An example is:

          start:
          prints("Hello");
          goto start;

     This would print the word "hello" over and over, forever. There is no
     restriction on the placement of a label, so the above can be written
     as:

          start: prints("Hello");
          goto start;

     As mentioned above, there are usually better ways than using a goto
     statement. For example:

          int i = 0;
          do
           i = i + 1;
          while (i < 100);

     is clearer than the equivalent:

          int i = 0;
          loop:
           i = i + 1;
           if (i < 100)
            goto loop;
     Telix v3.22 - SALT Programming                 Program Structure    18



     One good use of a goto statement is to get out of a deeply nested
     while statements, without having to do a lot of extra checking.
     Telix v3.22 - SALT Programming                Built-in Functions    19



     4.  BUILT-IN FUNCTIONS

     Telix's SALT has quite a large number of built-in functions. These
     functions are called just as you would call your own SALT functions.
     Each function does a certain task (print something to the screen, ma-
     nipulate strings, access disk files, etc.). Each function is called
     with parameters in a certain format and returns an integer or string
     value (the return value does not have to be used and is often a dummy
     variable).

     The following pages contain a quick listing of the functions by type
     followed by a complete description of each function, in alphabetical
     order. The complete reference contains for each function, a summary of
     the calling format, a description of what it does, and the return
     value of the function are all given. An example of actual usage of the
     function is often given. Note that the examples are fragments of pro-
     gram code for the most part, and may not explicitly declare all needed
     variables. So that you may find related functions, each function de-
     scription has a 'See Also' section, which lists related functions.
     Telix v3.22 - SALT Programming                Built-in Functions    20






     4.1  Quick Listing of Functions by Type
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Video Operations

     box, cursor_onoff, clear_scr, getx, gety, gotoxy, printc, printn,
     prints, printsc, pstra, pstraxy, scroll, status_wind, update_term

     String Handling

     copychrs, copystr, delchrs, gets, getsxy, inschrs, itos, setchr,
     setchrs, stoi, strcat, strchr, strcmpi, strlen, strlower, strmaxlen,
     strpos, strposi, strupper, subchr, subchrs, substr

     Character Handling

     isascii, isalnum, isalpha, iscntrl, isdigit, islower, isupper,
     tolower, toupper

     Comm Port Operations

     carrier, cinp_cnt, cgetc, cgetct, cputc, cputs, cputs_tr, flushbuf,
     get_baud, get_datab, get_parity, get_port, get_stopb, hangup,
     set_cparams, set_port

     File and File I/O Operations

     fclearerr, fclose, fdelete, ferror, feof, fflush, fgetc, fgets,
     fileattr, filefind, filesize, filetime, fnstrip, fopen, fputc, fputs,
     fread, frename, fseek, ftell, fwrite

     Keyboard Operations

     inkey, inkeyw, keyget, keyload, keysave, keyset

     Date/Time and Timer Operations

     curtime, date, tsec, tday, thour, time, time_up, timer_free,
     timer_restart, timer_start, timer_total, tmin, tmonth, tyear

     File Transfers, Capture, Printer, and Usage Log

     capture, printer, receive, send, transtab, usagelog, ustamp

     Script Management

     call, calld, delay_scr, is_loaded, load_scr, unload_scr

     Input String Matching

     track, track_addchr, track_free, track_hit, waitfor
     Telix v3.22 - SALT Programming                Built-in Functions    21



     Other Functions

     alarm, chatmode, delay, dial, dos, dosfunction, exittelix, helpscreen,
     loadfon, newdir, redial, redirect_dos, run, send_brk, set_defprot,
     set_terminal, show_directory, terminal, tone
     Telix v3.22 - SALT Programming                Built-in Functions    22






     4.2  Complete Function Reference
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ




     ALARM
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     alarm(int <seconds>);

     ş  Description

     The alarm functions sounds an alarm for a a duration in seconds given
     by <seconds>.

     ş  Return Value

     The <seconds> argument is returned.

     ş  See Also

     tone, _alarm_on, _sound_on

     ş  Example

     while (!inkey())
       alarm(1);



     BOX
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     box(int <x>, int <y>, int <x2>, int <y2>, int <style>, int <hollow>,
     int <color>);

     ş  Description

     The box function is used to create a box on the screen. The box will
     have an upper left hand corner of <x>,<y> and a lower right hand cor-
     ner of <x2>,<y2>. The box must fit within the confines of the screen.
     <color> is the color to use in drawing the box. If <hollow> is a non-
     zero (TRUE) value, the inside of the box is not cleared. <style> se-
     lects what kind of box to draw, as follows:
     Telix v3.22 - SALT Programming                Built-in Functions    23



          0    Spaces
          1    Single lines
          2    Double lines
          3    Single vertical lines, double horizontal lines
          4    Double vertical lines, single horizontal lines

     If <style> is any other value, that character is used to construct the
     sides of the box.

     ş  Return Value

     None.

     ş  See Also

     scroll

     ş  Example

     box(10, 10, 70, 20, 1, 0, 112);    // draw box in inverse color


     CALL, CALLD
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     call(str <scriptname>, <arg1>, <arg2>, <arg3>, ...);

     calld(str <scriptname>, <arg1>, <arg2>, <arg3>, ...);

     ş  Description

     The call function is used when one script file must call (jump into
     and then return from) another. <scriptname> is the name of the script
     file to call. If no extension is given, .SLC is assumed. <arg1>
     through <argn> are the arguments or parameters to be passed to the
     'main' function of the called script. The value returned is the value
     returned by the 'main' function of the called script, and can be an
     integer or a string value, although the called script can not return
     string variables local to itself. If the script file to be called is
     already in memory because it was previously loaded and made resident,
     or it is still executing from a previous call, it is not released but
     instead the memory image is used. This means that global variables
     will have whatever values a previous run through left in them.

     The calld function is exactly the same as the call function, except
     that even if an image of the indicated script file is already in mem-
     ory, a new copy is still loaded from disk. This ensures that global
     variables within the script will be set as defined in the source file,
     and that there will be enough stack space, but requires more memory
     and is slower.

     ş  Return Value

     An integer or string value representing the value returned by the main
     function of the called script file. This value must not be a string
     Telix v3.22 - SALT Programming                Built-in Functions    24



     variable defined within the called script, for memory reasons. if the
     indicated script can not be found or loaded, a value of -1 is re-
     turned. If the called script is aborted by the user, a value of -1 is
     returned.

     ş  See Also

     load_scr, unload_scr, is_loaded

     ş  Example

     stat = call("TEST");
     if (stat == -1)
      prints("Called script could not be loaded or was aborted!");




     CAPTURE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     capture(str <filename>);

     ş  Description

     The capture function is used to open, close, pause, and unpause the
     Telix capture file. Depending on what the string variable <filename>
     contains, different actions will take place.

     If <filename> contains a valid filename (which can include a path),
     Telix opens and starts capturing data to that file.

     If <filename> is "*CLOSE*", and the capture file is currently open, it
     is closed.

     If <filename> is "*PAUSE*", and the capture file is currently open, it
     is paused.

     if <filename> is "*UNPAUSE*", and the capture file is currently open
     and paused, it is unpaused.

     If <filename> is an empty string (""), Telix takes the same action as
     if the user had pressed Alt-L while in terminal mode (which will de-
     pend on whether the capture file is currently open or closed).

     ş  Return Value

     A value of -1 is returned if there is a problem performing the indi-
     cated function, otherwise a non-zero (TRUE) value is returned.

     ş  See Also

     printer, capture_stat, _capture_fname
     Telix v3.22 - SALT Programming                Built-in Functions    25



     ş  Example

     if (capture("TELIX.CAP") == -1)
      prints("Error opening capture file!");
        ...
     capture("*PAUSE*");
     capture("*UNPAUSE*");
     capture("*CLOSE*");




     CAPTURE_STAT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     capture_stat();

     ş  Description

     The capture_stat function returns an integer value representing the
     current status of the capture file, as follows:

               0    Capture File is closed
               1    Capture File is open
               2    Capture File is open and paused

     ş  Return Value

     An integer values as described above.

     ş  See Also

     capture, usage_stat




     CARRIER
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     carrier();

     ş  Description

     The carrier functions returns a non-zero (TRUE) value if the Carrier
     Detect signal coming from the modem is on (high), otherwise it returns
     a zero (FALSE) value. Note that some modems by default override the
     real state of the signal and always send a high. For this function to
     work, the modem must be told to supply the real signal. This function
     may be used to check if Telix is connected to a remote service over
     the modem, as the Carrier Detect signal should be on if there is a
     connection. Note that if you are connecting two computers via a null-
     Telix v3.22 - SALT Programming                Built-in Functions    26



     modem cable, the value returned will depend on the wiring of the cable
     being used.

     ş  Return Value

     non-zero (TRUE) or zero (FALSE) based on the state of the Carrier De-
     tect signal.

     ş  Example

     if (carrier())
      prints("We are online.");


     CGETC, CGETCT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     cgetc();

     cgetct(int <timeout>);

     ş  Description

     The cgetc function returns the first character waiting in the received
     data communications buffer. If there are no characters in the buffer,
     a value of -1 is returned. The cinp_cnt function may be used to see if
     there are any chars waiting in the buffer.

     The cgetct functions returns a character from the communications port,
     waiting up to <timeout> tenths of a second for it to arrive. If a
     character is already waiting in the communications buffer, it is imme-
     diately returned. If no character is received within the timeout pe-
     riod, a value of -1 is returned.

     ş  Return Value

     An integer value as described above.

     ş  See Also

     cinp_cnt

     ş  Example

     if (cinp_cnt())
      chr = cgetc();
     if ((chr = cgetct(100)) == -1)
      prints("Timeout!");
     Telix v3.22 - SALT Programming                Built-in Functions    27






     CHATMODE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     chatmode(int <echo_remote>);

     ş  Description

     The chatmode function enters the chat mode as if the user had pressed
     Alt-Y while in terminal mode, If <echo_remote> is non-zero (TRUE),
     characters typed by the remote user are echoed back to him/her, other-
     wise they are not. The echo feature is for use in Host Mode
     implementations.

     ş  Return Value

     None.




     CINP_CNT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     cinp_cnt();

     ş  Description

     The cinp_cnt function returns the number of characters waiting in the
     received data communications buffer.

     ş  Return Value

     An integer value as described above.

     ş  See Also

     cgetc

     ş  Examples

     if (cinp_cnt() > 10)   // if more than 10 chars waiting
      handle_stuff();       //   do action
     while (!cinp_cnt())    // loop until no chars available
      ;
     if (cinp_cnt())        // if something available, get it
      c = cgetc();
     Telix v3.22 - SALT Programming                Built-in Functions    28






     CLEAR_SCR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     clear_scr();

     ş  Description

     The clear_scr function clears the screen and places the cursor in the
     upper left corner at position 0,0.

     ş  Return Value

     None.

     ş  See Also

     scroll




     COPYCHRS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     copychrs(str <source>, str <target>, int <pos>, int <count>);

     ş  Description

     The copychrs function copies a number of characters from one string
     into another, Characters from the string <source> are copied into the
     string <target> at the position <pos> (note that SALT string offsets
     start at 0, not 1 as in some languages). until <count> characters are
     copied. Only as many characters as will fit in <target> are copied.

     This function is very similar to substr, except that it is not string
     oriented, and does not stop copying characters when a 0 value is en-
     countered.

     The substr function copies a portion of one string to another. Char-
     acters from position <pos> in string <source> are copied until into
     string <target> (note that SALT string offsets start at 0, not 1 as in
     some languages). Characters are copied until a 0 (NULL) value is en-
     countered (normally at the end of every string), or <max> characters
     are copied. A 0 (NULL) is always copied at the end of the target
     string. The 0 does not count as part of the <max>. Only as many char-
     acters as will fit in <target> are copied.

     ş  Return Value

     None.
     Telix v3.22 - SALT Programming                Built-in Functions    29



     ş  See Also

     copystr, subchrs, substr




     COPYSTR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     copystr(str <source>, str <target>, int <pos>, int <count>);

     ş  Description

     The copystr function copies one string into another at a certain po-
     sition. Characters in string <source> are copied into string <target>
     at position <pos> (note that SALT string offsets start at 0, not 1 as
     in some languages). Characters are copied until a 0 (NULL) value is
     encountered (normally at the end of every string), or <max> characters
     are copied. A 0 (NULL) is always copied at the end of the target
     string. The 0 does not count as part of the <max>. Only as many char-
     acters as will fit in <target> are copied.

     ş  Return Value

     None.

     ş  See Also

     copychrs, substr, subchrs




     CPUTC
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     cputc(int <character>);

     ş  Description

     The cputc function sends <character> to the communications port. This
     is the ASCII value of the character to be sent.

     ş  Return Value

     A non-zero (TRUE) value is returned unless the character can not be
     sent for some reason, in which case a value of -1 is returned.

     ş  See Also

     cputs
     Telix v3.22 - SALT Programming                Built-in Functions    30



     ş  Example

     cputc('A');
     cputc(27);          // send Escape to the comm port
     cputc('^M');        // send Ctrl-M (Carriage Return)
     cputc(inkeyw());




     CPUTS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     cputs(str <outstr>);

     ş  Description

     The cputs function sends the passed string out over the modem port. A
     Carriage Return and Line Feed are NOT added after the string.

     ş  Return Value

     None.

     ş  See Also

     cputs_tr

     ş  Example

     cputs("Good-bye");
     str password[] = "mypass";
     cputs(password);




     CPUTS_TR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     cputs_tr(str <outstr>);

     ş  Description

     The cputs_tr function sends the passed string out over the modem port,
     but pays attention to two output string translation characters,  ^ and
     ~, described in the Telix manual. This function is really only useful
     for sending the modem control strings that the user has defined in the
     Configuration Menu.

     ş  Return Value

     None.
     Telix v3.22 - SALT Programming                Built-in Functions    31



     ş  See Also

     cputs

     ş  Example

     cputs_tr(_modem_init);
     cputs_tr("good-bye~yes^M");




     CURSOR_ONOFF
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     cursor_onoff(int <state>);

     ş  Description

     The cursor_onoff functions turn the blinking cursor on or off (makes
     it disappear or reappear), depending on whether state is non-zero
     (TRUE) or zero (FALSE).

     ş  Return Value

     None.




     CURTIME
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     curtime();

     ş  Description

     The curtime function returns the current date/time as the number of
     seconds since Jan 1, 1970. A date/time value in this format is used by
     many SALT functions.

     ş  Return Value

     An integer value as described above.

     ş  See Also

     date, time, tyear, tmonth, tday, thour, tmin, tsec

     ş  Example

     // Print the current date
     Telix v3.22 - SALT Programming                Built-in Functions    32



     int t;
     str s[64];

     t = curtime();
     date(t, s);
     prints(s);




     DATE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     date(int <timeval>, str <buffer>);

     ş  Description

     The date function writes out a date in <buffer> in the form mm/dd/yy,
     dd/mm/yy, or yy/mm/dd (which is based on the system variable
     _date_format). <timeval> is the date, represented as the number of
     seconds since Jan 1, 1970. Time values in this form are returned by
     the curtime and filetime functions, among others.

     ş  Return Value

     None.

     ş  See Also

     time, curtime, filetime

     ş  Example

     str s[16];
     printsc("The current date is ");
     date(curtime(), s);
     prints(s);


     DELAY, DELAY_SCR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     delay(int <duration>);

     delay_scr(int <duration>);

     ş  Description

     The delay function pauses Telix for a length of time specified in
     tenths of a second by <duration>. During this pause, everything is
     shut off except the asynchronous reception of characters from the comm
     port.
     Telix v3.22 - SALT Programming                Built-in Functions    33



     The delay_scr function pauses only the execution of the current script
     file for the indicated duration. During that time, characters coming
     in from the serial port are printed on the terminal screen, while user
     keystrokes are also processed.

     ş  Return Value

     The <duration> argument is returned.




     DELCHRS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     delchrs(str <s>, int <pos>, int <num>);

     ş  Description

     The delchrs function is used to remove or delete a number of charac-
     ters in a string at a certain position. <s> is the string to handle.
     <pos> is the position at which <num> characters will be deleted (note
     that the first characters in a SALT string has the position 0). Re-
     maining characters in the string are be shifted left.

     ş  Return Value

     None.

     ş  See Also

     inschrs

     ş  Example

     // remove all but the first and last characters in a string

     str s[] = "0123456789";
     delchrs(s, 1, strlen(s) - 2);




     DIAL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     dial(str <dialstr>, int <maxtries>, int <no_link>);

     ş  Description

     The dial function dials the entries specified in <dialstr>. The en-
     tries should be entered in the same format as used when typing entries
     in the dialing directory. If <dialstr> is empty (""), the dialing di-
     Telix v3.22 - SALT Programming                Built-in Functions    34



     rectory is displayed. <maxtries> is the maximum number of dialing at-
     tempts. For example, if the string contains one entry, and <maxtries>
     is equal to 5, Telix will attempt to dial the number 5 times. If five
     entries are indicated, and <maxtries> is equal to 5, each number will
     only be attempted once.  If <maxtries> is 0, dialing will continue un-
     til a connection is established. If an entry is connected to, and has
     a linked script file attached, that script will be run, unless
     <no_link> is non-zero (TRUE).

     ş  Return Value

     If there was a connection, the dial function returns the entry number
     of the entry which was connected to (or 1 if a manual number was di-
     aled). If there was no connection established, 0 is returned. If the
     <dialstr> has a bad format, -1 is returned.

     Also, when a connection is successfully established, the entry number
     of the entry connected to is placed in the system variable
     _entry_enum, while the name of the entry connected to is placed in the
     system variable _entry_name.

     ş  See Also

     redial
     _entry_enum, _entry_name

     ş  Example

     int stat;
     dial("10 15", 0);
     dial("m967-1111", 5);
     stat = dial(number_list, 0);




     DOS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     dos(str <command>, int <mode>);

     ş  Description

     The dos function calls the DOS command interpreter (usually COM-
     MAND.COM, and gives it the passed command string. If the <command>
     string is empty (""), Telix will drop into a DOS shell, as if the Alt-
     J command had been executed. Make sure that if you specify a command
     or program that expects user input you are on hand to give it. The
     <mode> argument specifies several options, as follows:

          0    Original screen is restored when command is completed.
          1    When command is completed, the user is prompted to press a
               key and screen is restored as soon as it is pressed.
          2    Original screen is not restored when command is completed
     Telix v3.22 - SALT Programming                Built-in Functions    35



     This function is very similar to the run function. It should be used
     when an internal DOS command is needed or a DOS shell is needed, oth-
     erwise run is preferable as it uses less memory and executes faster.

     ş  Return Value

     The dos function returns a -1 if the command processor can not be
     found or there is not enough memory to load it, otherwise a 0 is re-
     turned.

     ş  See Also

     run, dosfunction

     ş  Example

     dos("copy a:*.* c:", 1);




     DOSFUNCTION
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     dosfunction();

     ş  Description

     The dosfunction function calls up the 'DOS Functions' menu, as if the
     user had pressed Alt-F while in terminal mode.

     ş  Return Value

     None.

     ş  See Also

     dos, run




     EXITTELIX
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     exittelix(int <returncode>, int <hangup>);

     ş  Description

     The exittelix function closes any currently open log file, and exits
     Telix to DOS, as if the user had pressed Alt-X while in terminal mode.
     The <returncode> argument is the value that should be returned to DOS.
     This value can be read by whatever called Telix (e.g., a batch file
     Telix v3.22 - SALT Programming                Built-in Functions    36



     using the errorlevel command). The <hangup> option affects what hap-
     pens if Telix is online. If it is set to non-zero (TRUE), Telix will
     hang-up before returning to DOS, otherwise the connection will not be
     disturbed.

     ş  Return Value

     Since this functions causes Telix to terminate, there is never any re-
     turn from it.

     ş  Example

     exittelix(0, 1);
     exittelix(100, 0);


     FCLEARERR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fclearerr(int <fh>);

     ş  Description

     The fclearerr function clears the error flag assigned to the open file
     represented by file handle <fh>. It also clears the End Of File flag
     for that file as well.

     ş  Return Value

     None.

     ş  See Also

     ferror, feof

     ş  Example

     int f;
     f = fopen("test.dat", "r");
        ...
     if (ferror(f))
      fclearerr(f);


     FCLOSE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fclose(int <fh>);

     ş  Description

     The fclose functions closes the file represented by the file handle
     <fh>, which must previously been opened for reading or writing with
     Telix v3.22 - SALT Programming                Built-in Functions    37



     the fopen function. If the file was opened for writing, any data which
     is still buffered and waiting to be written out to disk is written be-
     fore the file is closed.

     ş  Return Value

     A return value of -1 indicates a problem closing the file.

     ş  See Also

     fopen

     ş  Example

     int f;
     f = fopen("test.dat", "w");
        ...
     fclose(f);


     FDELETE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fdelete(str <filename>);

     ş  Description

     The fdelete function is used to delete a disk file from within a
     script. <filename> is the name of the file to delete. A full drive and
     path may be specified as part of the filename, and case is not signif-
     icant, but wildcard characters (* or ?) may NOT be part of the file-
     name.

     ş  Return Value

     A value of -1 is returned if there is a problem deleting the file, 0
     otherwise.

     ş  See Also

     frename

     ş  Example

     fdelete("C:\UTIL\TLX\TELIX.CAP");    // delete an old capture file




     FEOF
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     feof(int <fh>);
     Telix v3.22 - SALT Programming                Built-in Functions    38



     ş  Description

     The feof function determines if the file position for the open file
     represented by the file handle <fh> is at the end-of-file position.

     ş  Return Value

     A non-zero (TRUE) value is returned if the file position is at the end
     of the file.

     ş  See Also

     ferror

     ş  Example

     int f, chr;
     f = fopen("test.dat", "r");
     while ((chr = fgetc(f)) != -1)    // print contents of file
      printc(chr);
     if (feof(f))
      prints("Reached end of file.");
     else
      prints("Error reading file");


     FERROR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     ferror(int <fh>);

     ş  Description

     The ferror function checks the error flag for a file represented by
     the file handle <fh>. The error flag stays set until it is cleared
     with fclearerr or the file is closed.

     ş  Return Value

     A non-zero (TRUE) value is returned if the file's error flag is set.

     ş  See Also

     fclearerr, feof

     ş  Example

     int f;
     f = fopen("test.dat", "r");       // open file only for reading
     fputs("This should set the error flag!", f);
     if (ferror(f))
      prints("Error writing to file!");
     Telix v3.22 - SALT Programming                Built-in Functions    39



     FFLUSH
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fflush(int <fh>);

     ş  Description

     The fflush function flushes the buffer associated with the file rep-
     resented by file handle <fh>. If the file is opened for writing, any
     characters in the buffer are written. If the file is opened for read-
     ing, the buffer is cleared.

     ş  Return Value

     A value of -1 is returned if there is a problem flushing the buffer.

     ş  See Also

     fopen, fclose


     FGETC
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fgetc(int <fh>);

     ş  Description

     The fgetc function returns the next character from the file rep-
     resented by the file handle <fh>. The file must have been opened for
     reading or from reading and writing, using the fopen function.

     ş  Return Value

     Returns the character read if successful, or -1 if the end of the file
     has been reached or an error is encountered.

     ş  See Also

     fopen, fputc

     ş  Example

     int f;
     f = fopen("test.dat", "r");
     while (!feof(f))        // print all the characters in the file
      printc(fgetc(f));
     Telix v3.22 - SALT Programming                Built-in Functions    40



     FGETS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fgets(str <buffer>, int <n>, int <fh>);

     ş  Description

     The fgets function reads characters from the open file indicated by
     the file handle <fh> into the string variable <buffer>. Reading stops
     when a newline (Line Feed) character is read, and end-of-file is en-
     countered, a read error occurs, or <n> characters have been read. The
     Line Feed character (and the Carriage Return that usually precedes it
     on MS-DOS systems) is not kept as part of the string.

     Important: The SALT implementation of the fgets() function differs
     from the C language function of the same name. While both implemen-
     tations read until the Line Feed character, C keeps that character as
     part of the input string, while SALT doesn't. This change was made be-
     cause in almost every case, the Line Feed is not needed, and would
     otherwise have to be manually stripped by the script after every read.

     ş  Return Value

     A value of -1 is returned if there is a read error, or if there is an
     end-of-file before any characters can be read.

     ş  See Also

     fopen, fputs

     ş  Example

     int f;
     str s[100];
     f = fopen("test.dat", "r");
     while (!feof(f))         // print out contents of text file
      {
       fgets(s, 100, f);
       printsc(s);
      }


     FILEATTR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fileattr(str <filespec>);

     ş  Description

     Under the MS-DOS file system, files have a certain attributes which
     can determine their functions or the way certain things behave. For
     example if a file has the 'hidden' bit set as part of its attribute
     Telix v3.22 - SALT Programming                Built-in Functions    41



     byte, when you do a DOS dir command, the file is not shown. Similarly,
     if a file has the read only bit set, you may not overwrite it.

     The fileattr function returns an integer value representing the at-
     tributes of a specified file. <filespec> is the name of the file and
     may include a drive and directory portion, as well as the DOS wildcard
     characters * and ?.

     The value returned is a total of the following attributes.

          1    Read only file.

          2    Hidden file. The file is not listed when the DOS dir command
               is executed.

          4    System file. The file is not listed when the DOS dir command
               is executed.

          8    Volume label. This is the volume name of the disk.

          16   Subdirectory. This is a subdirectory name.

          32   Archive bit. This is set by DOS whenever a file has been
               written to and is then used by some backup software to check
               if a file has been modified since last backed-up.

     Each of these values is a certain bit in a byte. To test for the ex-
     istence of an attribute, the bitwise AND operator should be used. For
     example, the following fragment would check if the read only bit in an
     attribute is set:

     if (attrib & 1)
      ...

     If <filespec> is blank (""), then the attributes of the last file
     found with the filefind function is returned. Note that calling file-
     size or filetime in the meantime with a non-blank filename would in-
     stead make this call return the attributes of files found with those
     functions, as they use the same buffer.

     ş  Return Value

     An integer value representing the combined attributes of the indicated
     file is returned, or a value of -1 is returned if the indicated file
     could not be found.

     ş  See Also

     filefind, filesize, filetime

     ş  Example

     int attr;
     str filename[64];
     gets(filename, 64);
     attr = fileattr(filename);
     if (attr & 6)      // system _and_ hidden added together
     Telix v3.22 - SALT Programming                Built-in Functions    42



      prints("This file is marked as hidden and system");


     FILEFIND
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     filefind(str <filespec>, int <attrib>, str <buffer>);

     ş  Description

     The filefind function is used to search for the existence of one or
     more files or disk directories. Filefind puts in <buffer> the name of
     the first file matching <filespec>, which may include a drive and path
     as well as a filename, and may use the DOS wildcard characters * and ?
     (e.g., "*.*", "C:\TELIX\TELIX.EXE", "SCRIPTS\TEST??.*"). <attrib> is
     the attribute (also see fileattr) which files must match. The at-
     tribute is obtained by adding certain values as follows:

          0    Normal files and read only files
          2    Hidden files
          4    System files
          8    Disk volume label
          16   Subdirectory

     If the attribute is 0, only normal (and read-only) files are found. If
     the volume label is selected, only volume labels will be returned. Any
     other selected attribute or combination (addition) of attributes re-
     sults in those files and all normal files being matched.

     When a matching file, directory, or volume name is found, it is put in
     <buffer> (note that the drive and path portion of filespec are not
     copied), and a non-zero (TRUE) value is returned. The size, date/time,
     and attributes of the matched file can be seen with the filesize,
     filetime, and fileattr functions, respectively.  If no files matching
     the file specification are found, a zero (FALSE) value is returned.

     If <filespec> is blank (""), then filefind searches for the next
     matching file. Note that this will not work after an intervening call
     to filesize, filetime, or fileattr with a non-blank filename, as the
     same buffer is used for searches and to keep data.

     ş  Return Value

     A non-zero (TRUE) value is returned if a file matching the speci-
     fication was found, otherwise a value of zero (FALSE) is returned.

     ş  See Also

     filesize, filetime, fileattr

     ş  Example

     // show all normal files in the current directory
     str buf[16], fspec[16] = "*.*";
     while (filefind(fspec, 0, buf) != 0)
     Telix v3.22 - SALT Programming                Built-in Functions    43



      {
       prints(buf);    // show file found
       fspec = "";     // so we can continue searching for files
      }


     FILESIZE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     filesize(str <filespec>);

     ş  Description

     The filesize function returns the size in bytes of the specified file.
     <filespec> is the name of the file and may include a drive and direc-
     tory portion, as well as the DOS wildcard characters * and ?.

     If <filespec> is blank (""), then the size of the last file found with
     the filefind function is returned. Note that calling filetime or
     fileattr in the meantime with a non-blank filename would instead make
     this call return the size of files found with those functions, as they
     use the same buffer.

     ş  Return Value

     An integer value representing the size of the indicated file is re-
     turned, or a value of -1 is returned if the indicated file could not
     be found.

     ş  See Also

     filefind, filetime, fileattr

     ş  Example

     str filespec[24] = "*.*", buf[12];
     int size;
     siz = filesize("TELIX.EXE");   // get size of file TELIX.EXE
     // Add up size of all files int he current directory
     siz = 0;
     while (filefind(filespec, 0, buf) != 0)   // until no more files
      {
       siz = siz + filesize("");   // get size of last filefound file
       filespec = "";              // make sure filespec is "" on sub-
                                   // sequent calls to filefind to
                                   // continue searching for files
      }


     FILETIME
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     filetime(str <filespec>);
     Telix v3.22 - SALT Programming                Built-in Functions    44



     ş  Description

     The filetime function returns the date/time of the specified file.
     <filespec> is the name of the file and may include a drive and di-
     rectory portion, as well as the DOS wildcard characters * and ?.

     The values returned represents the file's modification date as the
     number of seconds since Jan 1, 1970. A date/time in this form can be
     used by the date, time, tyear, tmonth, tday, thour, tmin, tsec, and
     other functions.

     If <filespec> is blank (""), then the date/time of the last file found
     with the filefind function is returned. Note that calling filesize or
     fileattr in the meantime with a non-blank filename would instead make
     this call return the time/date of files found with those functions, as
     they use the same buffer.

     ş  Return Value

     An integer value representing the date/time of the indicated file is
     returned, or a value of -1 is returned if the indicated file could not
     be found.

     ş  See Also

     filefind, filesize, fileattr

     ş  Example

     int time;
     str s[16];

     time = filetime("TELIX.EXE");
     if (time == -1)
      prints("'TELIX.EXE" could not be found!");
     else
      {
       printsc("TELIX.EXE was created at ");
       time(time, s);
       printsc(s);
       printsc(" on ");
       date(time, s);
       printsc(s);
      }

     // this example assumes both files exist
     if (filetime("FILE1") < filetime("FILE2"))
      prints("FILE1 is older than FILE2");
     else
      prints("FILE1 is newer than FILE2");
     Telix v3.22 - SALT Programming                Built-in Functions    45



     FLUSHBUF
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     flushbuf();

     ş  Description

     The flushbuf function flushes (throws away) any characters that may be
     waiting in Telix's remote input buffer. One use for this command is to
     get rid of unwanted line noise.

     ş  Return Value

     None.


     FNSTRIP
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fnstrip(str <filename>, int <specifier>, str <target>);

     ş  Description

     The fnstrip function allows specific parts of a filename to be ex-
     tracted. In the MS-DOS operating system, a filename can consist of up
     to four parts, the drive, the path, the name, and the extension (e.g.,
     C:\TELIX\TELIX.FON). fnstrip processes the filename specified in
     <filename>, and depending on the value of <specifier>, places any com-
     bination of these four parts in the <target> string. Legal values for
     <specifier> and their results are as follows:

          <specifier>    Filename portion copied

               0         Full file name
               1         All except the drive
               2         Drive, name, and extension
               3         Name and extension
               4         Drive, path, and name (no extension)
               5         Path and name (no extension)
               6         Drive and name (no extension)
               7         Name only (no extension)
               12        Drive and path only
               13        Path only
               14        Drive only

     ş  Return Value

     None.

     ş  See Also

     filefind
     Telix v3.22 - SALT Programming                Built-in Functions    46



     ş  Example

     str filename[64], shortname[16];
     gets(filename, 64);                 // ask for a filename
     fnstrip(filename, 3, shortname);    // keep only name & extension


     FOPEN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fopen(str <name>, str <mode>);

     ş  Description

     The fopen function is used to open a disk file for reading and/or
     writing. The file to be opened is given by <name>. <mode> is a string
     indicating for what use the file should be opened. Legal values for
     mode are:

          "r"       Opens for reading
          "w"       Opens for writing (truncates any existing file with the
                    same name)
          "a"       Opens for appending (writing at the end of the file).
                    Creates the file if it doesn't exist.
          "r+"      Opens for reading and writing. Initial position at the
                    beginning of the file (the file must already exist).
          "w+"      Opens for reading and writing. If the file exists its
                    contents are destroyed.
          "a+"      Opens for reading and appending. Creates the file if it
                    doesn't exist.

     If a file is opened for both reading and writing (when "r+", "w+", or
     "a+" are used as the mode), an fseek operation is necessary before
     switching from one to the other.

     ş  Return Value

     The fopen function returns a 'handle' which is an integer number by
     which this file is to be referred to until it is finally closed. A
     value of 0 is returned if the file can not be opened (because it
     doesn't exist, because a disk error occurred, or because there are no
     more file handles available). Only up to 8 files may be opened at a
     time. It is therefore very important to close open files if they are
     no longer needed and when a script is done, or else all available file
     handles will become used up.

     ş  See Also

     fclose

     ş  Example

     int f;
     f = fopen("data.txt", "r");    // open the file for reading
     if (f == 0)
     Telix v3.22 - SALT Programming                Built-in Functions    47



      prints("Error opening file!");


     FPUTC
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fputc(int <c>, int <fh>);

     ş  Description

     The fputc function writes a character to the file indicated by the
     file handle <fh>. <c> is the character to write.

     ş  Return Value

     The character written is returned, unless there is an error, in which
     case a value of -1 is returned.

     ş  See Also

     fputs, fgetc

     ş  Example

     int f, i;
     str teststr[] = "This is a test string";
     f = fopen("test.dat", "w");
     for (i = 0; i < 21; ++i)           // write out string to file
      fputc(subchr(teststr, i), f);     // character by character


     FPUTS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fputs(str <s>, int <fh>);

     ş  Description

     The fputs function writes a string to the file represented by file
     handle <fh>. The string must be 512 bytes in length or less (all
     strings end in a zero (0) value, the use of which is usually trans-
     parent; characters are written until this 0 is encountered. The 0 is
     not written).

     ş  Return Value

     A 0 value is returned if the write is successful, a non-zero value if
     it is not.

     ş  See Also

     fputc, fgets
     Telix v3.22 - SALT Programming                Built-in Functions    48



     ş  Example

     int f, i;
     f = fopen("test.dat", "w");
     for (i = 0; i < 100; ++i)      // write out "Hello" and a new-
      fputs("Hello^M^J", f);        // line one hundred times


     FREAD
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fread(str <buf>, int <count>, int <fh>);

     ş  Description

     The fread function reads up to <count> bytes from the file represented
     by file handle <fh>. Characters are written to the <buf> variable,
     which must be large enough.

     ş  Return Value

     The number of bytes actually read is returned, which may be less than
     <count> if an error occurs or and end-of-file is encountered.

     The ferror and feof functions should be used to distinguish an error
     from an end-of-file condition.

     ş  See Also

     fwrite

     ş  Example

     int f;
     str buffer[40];
     f = fopen("test.dat", "r");
     fseek(f, 1000, 0);       // goto offset 1000 in file
     fread(buffer, 40, f);    // and read 40 bytes of data


     FRENAME
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     frename(str <oldname>, str <newname>);

     ş  Description

     The frename function is used to rename a disk file. <oldname> is the
     original name of the file, while <newname> is what it should be re-
     named to. A full drive and path may be included in the original name,
     but should not be placed before the new name. The renamed file will
     stay in the original drive and directory. Case is not significant.
     Telix v3.22 - SALT Programming                Built-in Functions    49



     ş  Return Value

     If successful, frename returns a 0 value, otherwise a non-zero value
     is returned.

     ş  See Also

     fdelete

     ş  Example

     frename("\TELIX\TELIX.CAP", "OLDTLX.CAP");


     FSEEK
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fseek(int <fh>, int <offset>, int <origin>);

     ş  Description

     The fseek function sets the position of the file pointer in the file
     represented by the file handle <fh>. The file position is where the
     next read or write will take place. <offset> is the signed offset from
     the location specified by <origin>. Legal values for <origin> are:

          0:   Beginning of file.
          1:   Current position.
          2:   End of file.

     The pointer can be positioned anywhere in the file, and even past the
     end of the file (which will extend it). It is illegal to try to posi-
     tion the pointer before the beginning of the file however.

     ş  Return Value

     If successful, fseek returns a 0 value, otherwise a non-zero value is
     returned.

     ş  See Also

     ftell

     ş  Example

     int f;
     f = fopen("test.dat", "r");
     fseek(f, 0, 0);       // go to offset 0 in file
     fseek(f, 1000, 0);    // go to offset 1000 in file
     fseek(f, -5, 1);      // go back 5 places in file
     fseek(f, 0, 2);       // go to the end of the file
     Telix v3.22 - SALT Programming                Built-in Functions    50



     FTELL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     ftell(int <fh>);

     ş  Description

     The ftell function returns the current file position in the file rep-
     resented by file handle <fh>. This is generally the position where the
     next read or write operation will take place. Note however that for a
     file opened in Append mode, the value returned will not necessarily
     return the position of the next write, since Append mode will force
     writes to the end of file regardless of the current file position.

     ş  Return Value

     An integer value as described above. A -1 value is returned if an er-
     ror occurs.

     ş  See Also

     fseek


     FWRITE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     fwrite(str <buf>, int <count>, int <fh>);

     ş  Description

     The fwrite function writes bytes to the file represented by the file
     handle <fh>. <count> number of bytes are written from <buf>.

     ş  Return Value

     The number of bytes actually written are returned, which may be less
     than <count> if an error occurred.

     ş  See Also

     fread

     ş  Example

     int f;
     str buffer[] = "1234567890123456789012345";
     f = fopen("test.dat", "w");
     fwrite(buffer, 25, f);       // write test pattern to file
     Telix v3.22 - SALT Programming                Built-in Functions    51



     GET_BAUD
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     get_baud();

     ş  Description

     The get_baud function returns an integer value which is the current
     baud rate in use on the current communications port (300 through
     115200).

     ş  Return Value

     As described above.

     ş  See Also

     get_parity, get_datab, get_stopb, get_port

     ş  Example

     prints("The current baud rate is ");
     printn(get_baud());
     prints("");


     GET_DATAB
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     get_datab();

     ş  Description

     The get_datab function returns the data bits setting in use on the
     current communications port (7 or 8).

     ş  Return Value

     As described above.

     ş  See Also

     get_baud, get_parity, get_stopb, get_port


     GETENV
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     getenv(str <varname>, str <target>);
     Telix v3.22 - SALT Programming                Built-in Functions    52



     ş  Description

     The getenv function may be used to access the DOS Environment and get
     the value assigned to an Environment Variable. <varname> is the name
     of the environment variable to be searched for, and <target>  is the
     string variable where whatever is assigned to the environment variable
     should be placed.

     ş  Return Value

     A non-zero (TRUE) value is returned if the function is successful,
     otherwise a zero (FALSE) values is returned (if the environment vari-
     able didn't exist);

     ş  Example

     // Get and print whatever is assigned to the TELIX env. variable
     str value[64];
     if (getenv("TELIX", value))    // if env. variable exists
      prints(value);                // print value


     GET_PARITY
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     get_parity();

     ş  Description

     The get_parity function returns an integer value which represents the
     current parity setting in use on the current comm port.

     ş  Return Value

     Returned values are as follows:

               0    No parity
               1    Even parity
               2    Odd parity

     ş  See Also

     get_baud, get_datab, get_stopb, get_port


     GET_PORT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     get_port();
     Telix v3.22 - SALT Programming                Built-in Functions    53



     ş  Description

     The get_port function returns the number (1 through 8) of the current
     communications port being used.

     ş  Return Value

     As described above.

     ş  See Also

     get_baud, get_datab, get_parity, get_stopb

     ş  Example

     prints("Currently using COM");
     printn(get_port());
     prints("");


     GET_STOPB
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     get_stopb();

     ş  Description

     The get_stopb function returns the stop bits setting in use on the
     current com port (1 or 2).

     ş  Return Value

      As described above.

     ş  See Also

     get_baud, get_datab, get_parity, get_port


     GETS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     gets(str <buffer>, int <max>);

     ş  Description

     The gets function allows the user to enter a complete string, and use
     the arrow keys to edit it while it is being entered. <buffer> is the
     string variable where the string should be put, while <max> is the
     maximum number of characters the user may enter (from 0 to 80). The
     user may edit the string as it is being entered, with the Left-Arrow,
     Right-Arrow, Ctrl-Left-Arrow, and Ctrl-Right-Arrow keys as it is being
     entered, and insert mode may be toggled on/off with the INS key.
     Telix v3.22 - SALT Programming                Built-in Functions    54



     String entry is over when the user presses Enter (Carriage Return on
     some computers). The user may press Esc to abort string entry, in
     which case the resulting string will have a length of 0.

     ş  Return Value

     The number of characters entered by the user are returned. If the user
     pressed Esc to abort string entry, a value of -1 is returned.

     ş  See Also

     getsxy

     ş  Example

     int n;
     str password[8];
     printsc("Enter a password? ");
     n = gets(password, 8);

     GETSXY
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     getsxy(str <targets>, int <max>, int <x>, int <y>, int <color>);

     ş  Description

     The getsxy function is similar to the gets function, but the x,y lo-
     cation of string entry may be specified, as well as a color attribute.
     <buffer> is the string variable where the string should be put, while
     <max> is the maximum number of characters the user may enter (from 0
     to 80). The cursor will be moved to <x>,<y>, and text entered will use
     a color as described by <color>.

     The user may edit the string as it is being entered, with the Left-Ar-
     row, Right-Arrow, Ctrl-Left-Arrow, and Ctrl-Right-Arrow keys as it is
     being entered, and insert mode may be toggled on/off with the INS key.
     String entry is over when the user presses Enter (Carriage Return on
     some computers). The user may press Esc to abort string entry, in
     which case the resulting string will have a length of 0.

     ş  Return Value

     The number of characters entered by the user are returned. If the user
     pressed Esc to abort string entry, a value of -1 is returned.

     ş  See Also

     gets

     ş  Example

     int n;
     str filename[64] = "C:\TELIX\TELIX.EXE";
       // allow use to enter filename in black on white
     Telix v3.22 - SALT Programming                Built-in Functions    55



       // at current cursor position
     n = getsxy(filename, 64, getx(), gety(), 112);


     GETX, GETY
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     getx();

     gety();

     ş  Description

     The getx function returns the current column (horizontal x axis) po-
     sition of the cursor on the screen.

     The gety function returns the current row (vertical y axis) position
     of the cursor on the screen.

     ş  Return Value

     Returned values will range from 0 for the leftmost column to 79 for
     the rightmost column, for the getx function.

     Returned values range from 0 for the upper edge of the screen to 24
     for the lower edge, for the gety functions..

     ş  See Also

     gotoxy


     GOTOXY
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     gotoxy(int <xpos>, int <ypos>);

     ş  Description

     The gotoxy function positions the cursor at the screen coordinates
     given by <xpos> and <ypos>. Note that 0,0 is the upper left corner. On
     a 80x25 text screen, the lower right corner would be 79,24.

     ş  Return Value

     None.

     ş  See Also

     getx, gety
     Telix v3.22 - SALT Programming                Built-in Functions    56



     ş  Example

     gotoxy(0, 0);      // go to the top left corner

     gotoxy(79, 24);    // go to the bottom right corner


     HANGUP
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     hangup();

     ş  Description

     The hangup function tries to hang-up the modem, exactly as if the user
     had pressed Alt-H while in terminal mode. This is accomplished by
     first dropping (turning off) a signal called the DTR line, and if that
     is unsuccessful, sending the hang-up string defined in the configu-
     ration menu.

     ş  Return Value

     A non-zero (TRUE) value is returned if the hang-up is  successful,
     otherwise a zero (FALSE) value is returned.


     HELPSCREEN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     helpscreen();

     ş  Description

     The helpscreen function displays the help/status screen, as if the
     user had pressed the appropriate key while in terminal mode.

     ş  Return Value

     None.


     INKEY, INKEYW
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     inkey();

     inkeyw();
     Telix v3.22 - SALT Programming                Built-in Functions    57



     ş  Description

     The inkey function returns a character from the keyboard, but does not
     wait for a key to be pressed.

     The inkeyw function returns a character from the keyboard, and waits
     for a key to be pressed if the keyboard buffer is empty.

     Note that Telix while executing a script file checks the keyboard be-
     tween every command to see if the user wants to abort the script. For
     these commands to work, this keyboard checking must be disabled. This
     is done by setting the _scr_chk_key system variable to a non-zero
     (FALSE) value (that variable is further described in the section on
     system variables).

     ş  Return Value

     inkey returns the first character in the keyboard buffer, or a value
     of 0 if the keyboard buffer is empty.

     inkeyw waits until a key has been pressed if none is available in the
     keyboard buffer, and returns that value.

     Both of these functions also return extended key code values which are
     not part of the ASCII character set (for example, the code for Alt-D).
     These values are described in the Appendix.

     ş  Example

     chr = inkey();


     INSCHRS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     inschrs(str <source>, str <target>, int <pos>, int <num>);

     ş  Description

     The inschrs function is used to insert characters from one string into
     another at a specific position, shifting existing characters to the
     right. Characters are taken from <source> and placed in <target>, at
     an offset indicated by <pos>. Note that string offsets are numbered
     starting at 0, so the first character would have an offset of 0, the
     second 1, etc. Only <num> characters are inserted, and existing char-
     acters are shifted to the right (and are lost if they shift past the
     space allocated for the string).

     ş  Return Value

     None.

     ş  See Also

     copystr, copychrs
     Telix v3.22 - SALT Programming                Built-in Functions    58



     ş  Example

     str test[24] = "Good-bye";
     // add "Hello" to the front of the existing string
     inschrs("Hello ", test, 0, 6);


     ISALNUM - ISUPPER
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     isalnum(int <c>);   Test for alphanumeric ('A'-'Z', 'a'-'z', or '0'-
                              '9'

     isalpha(int <c>);   Test for letter ('A'-'Z' or 'a'-'z')

     isascii(int <c>);   Test for ASCII value (0-255)

     iscntrl(int <c>);   Test for Control character (0-31 or 127)

     isdigit(int <c>);   Test for digit ('0'-'9')

     islower(int <c>);   Test for lower case ('a'-'z')

     isupper(int <c>);   Test for upper case ('A'-'Z')

     ş  Description

     The functions listed above test an integer value and return a non-zero
     (TRUE) value if the test condition is satisfied, or a zero (FALSE) if
     it is not.

     Except for isascii, these functions give valid results only for in-
     teger values in the ASCII character set, that is, values for which
     isascii is true.

     ş  Return Value

     A non-zero (TRUE) value is returned if the test condition is sat-
     isfied, a 0 (FALSE) value otherwise.


     IS_LOADED
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     is_loaded(str <filename>);

     ş  Description

     The is_loaded function is used to determine if a SALT script, in-
     dicated by <filename> is currently loaded into memory. The script can
     be in memory if it was explicitly loaded with the load_script func-
     tion, or is still in memory because it previously was run and did not
     Telix v3.22 - SALT Programming                Built-in Functions    59



     finish executing. If filename does not include an extension, ".SLC" is
     automatically added.

     ş  Return Value

     A non-zero (TRUE) values is returned if the indicated script file is
     in memory, otherwise a zero (FALSE) value is returned.

     ş  See Also

     load_scr, unload_scr

     ş  Example

     if (!is_loaded("TESTSCR"))   // make sure script is in memory
      load_scr("TESTSCR");


     ITOS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     itos(int <value>, str <s>);

     ş  Description

     The itos function writes out the digits of the supplied integer value
     to <s>.

     ş  Return Value

     None.

     ş  See Also

     stoi

     ş  Example

     int chr;
     str s[16];
     chr = inkeyw();       // get a user keystroke
     itos(chr, s);         // and print out ASCII value of character
     prints(s);


     KEYGET
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     keyget(int <key>, int <table>, str <buffer>);
     Telix v3.22 - SALT Programming                Built-in Functions    60



     ş  Description

     The keyget function is used to look at what text is assigned to a key.
     <key> is an integer value representing the key (as described in the
     appendix). Any macro text assigned to this key will be placed in
     <buffer>. Telix keeps two key macro definition tables in memory at all
     times, a user key table, and a terminal key table, loaded in whenever
     the current terminal is changed. If <table> is 0, the key is assumed
     to be in the user table. If <table> is 1, the key is assumed to be in
     the terminal table.

     ş  Return Value

     None.

     ş  See Also

     keyset, keyload, keysave

     ş  Example

     str s[100];
     prints("Text currently assigned to the F1 key in user table is:");
     keyget(0x3b00, 0, s);
     prints(s);


     KEYLOAD
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     keyload(str <fname>, int <table>);

     ş  Description

     The keyload function is used to load a keyboard macro definition file
     into Telix. <fname> is the name of the definition file (if no exten-
     sion is given, .KEY is assumed). Telix always keeps two definition ta-
     bles in memory, a relatively constant user table, and a terminal table
     which changes with each different terminal and holds the proper key
     assignments for that terminal. If <table> is 0, then the definitions
     are loaded into the user table. If <table> is 1, the definitions are
     loaded into the terminal table.

     ş  Return Value

     A value of -1 is returned if there are problems loading the key file,
     otherwise a non-zero (TRUE) value is returned.

     ş  See Also

     keysave, keyget, keyset

     ş  Example

     keyload("SPECIAL", 0);
     Telix v3.22 - SALT Programming                Built-in Functions    61





     KEYSAVE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     keysave(str <fname>, int <table>);

     ş  Description

     The keysave function is used to save the current macro key text def-
     initions to a disk file. <fname> is the file to save the definitions
     to, and if no extension is given, ".KEY" is added. Telix always keeps
     two key definition tables in memory, a relatively constant user table,
     and a terminal table which changes with each different terminal and
     holds the proper key assignments for that terminal. If <table> is 0,
     then the definitions from the user table are saved. If <table> is 1,
     the definitions from the terminal table are saved.

     ş  Return Value

     A value of -1 is returned if there is a problem writing to the file,
     otherwise a non-zero (TRUE) value is returned.

     ş  See Also

     keyload, keyget, keyset


     KEYSET
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     keyset(int <key>, int <table>, str <text>);

     ş  Description

     The keyset function is used to assign text to a key. <key> is an in-
     teger value representing the key (as described in the appendix).
     <text> is what to assign to this key. Telix always keeps two key defi-
     nition tables in memory, a relatively constant user table, and a ter-
     minal table which changes with each different terminal and holds the
     proper key assignments for that terminal. If <table> is 0, the key
     definition in the user table is affected. If <table> is 1, the key
     definition in the terminal table is affected.

     ş  Return Value

     None.

     ş  See Also

     keyget, keyload, keysave
     Telix v3.22 - SALT Programming                Built-in Functions    62



     ş  Example

     // Assign a name to the F1 key in the user table
     // Note that if the terminal table also holds a
     // definition for that key it will take precedence
     keyset((0x3b00, 0, "Joe Smith");


     LOADFON
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int loadfon(str <filename>);

     ş  Description

     The loadfon function loads the given dialing directory file. The com-
     plete name must be given, including any extension (e.g. .FON) or the
     disk drive/directory if the file is not in the current directory.

     ş  Return Value

     A non-zero (TRUE) value is returned if the dialing directory file is
     successfully loaded. If some sort of error occurs (file does not ex-
     ist, file reading error, etc.) a zero (FALSE) value is returned.


     LOAD_SCR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     load_scr(str <filename>);

     ş  Description

     When a script is run (either by the user manually running it from ter-
     minal mode, or from within another script), it is usually loaded from
     disk. The load_scr function is used to load a script into memory ahead
     of time, providing a savings in time when the script must be run re-
     peatedly. <filename> is the name of the script file to load, and if no
     extension is given, ".SLC" is assumed.

     ş  Return Value

     If there is a problem loading the script file (it is not there or
     there is not enough memory),a value of -1 is returned. Otherwise a
     non-zero (TRUE) value is returned.

     ş  See Also

     unload_scr, is_loaded

     ş  Example

     int stat;
     Telix v3.22 - SALT Programming                Built-in Functions    63



     stat = load_scr("TEST");     // load TEST.SLC


     NEWDIR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     newdir(str <directory>);

     ş  Description

     The newdir function is used to change the current drive and/or di-
     rectory. The <directory> argument should be the drive and/or directory
     to change to.

     ş  Return Value

     A non-zero (TRUE) value is returned if the function is successful,
     otherwise a zero (FALSE) values is returned (if the drive or directory
     is illegal or doesn't exist).

     ş  See Also

     dos, run

     ş  Example

     newdir("C:\TELIX");


     PRINTC
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     printc(int <chr>);

     ş  Description

     The printc function prints the character represented by the ASCII
     value <chr> to the terminal screen.

     ş  Return Value

     <chr> is returned.

     ş  See Also

     prints, printsc, printn

     ş  Example

     printc('A');

     printc(7);            // print ASCII value 7 (BELL sound)
     Telix v3.22 - SALT Programming                Built-in Functions    64



     printc(keyinw());     // print user keypress


     PRINTER
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     printer(int <state>);

     ş  Description

     The printer function is used within a script file to turn the printer
     on or off, as if the user had pressed the appropriate key in terminal
     mode. If <state> is a non-zero (TRUE) value, echoing to the printer is
     turned on, otherwise echoing is turned off

     ş  Return Value

     None.

     ş  See Also

     capture

     ş  Example

     printer(1);         // turn on printer log


     PRINTN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     printn(int <num>);

     ş  Description

     The printn function prints the passed integer number to the terminal
     screen. The cursor is NOT advanced to the beginning of the next line.

     ş  Return Value

     The value of the passed integer is returned.

     ş  See Also

     prints, printsc, printc

     ş  Example

     printsc("Current baud rate is ");
     printn(get_baud);
     Telix v3.22 - SALT Programming                Built-in Functions    65



     PRINTS, PRINTSC, PRINTSC_TRM
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     prints(str <outstr>);

     printsc(str <outstr>);

     printsc_trm(str <outstr>);

     ş  Description

     The prints function prints the passed string at the current cursor po-
     sition on the screen, followed by a Carriage Return and Line Feed
     (which places the cursor at the beginning of the next line).

     The printsc function prints the passed string at the current cursor
     position on the screen. The cursor is not advanced to the next line,
     hence the 'c', which stands for continuous.

     The printsc_trm function is similar to the above, except that out-
     putted characters pass through the current terminal emulator, so ter-
     minal escape sequences may be included in output strings.

     ş  Return Value

     None.

     ş  See Also

     printn, printc

     ş  Example

     prints("Hello");

     printsc("Hello^M^J");    // same effect as above

     printsc_trm("^[[H");     // go to top left corner in VT102 emulation


     PSTRA, PSTRAXY
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     pstra(str <s>, int <color>);

     pstraxy(str <s>, int <x>, int <y>, int <color>);

     ş  Description

     The pstra (Print STRing with color Attribute) function is used to
     print a string to the screen, similar to the prints/printsc functions.
     This function is much faster however, and should be used when speed is
     important. As well, it allows a color to be specified for the text.
     Telix v3.22 - SALT Programming                Built-in Functions    66



     <s> will be printed to the screen at the current cursor position using
     a color as specified by <color>.

     The pstraxy function is similar to the above, but allows you to spec-
     ify where to print the string. The string is printed at <x>,<y>, with
     0,0 being the upper left corner of the screen.

     Note that prints goes through a basic TTY type terminal emulator, so
     strings printed using it may contain the basic cursor control code,
     while pstra writes directly to the screen, ignoring these sequences.

     ş  Return Value

     None.

     ş  See Also

     prints, printsc

     ş  Example

     pstraxy("Enter name:", 10, 10, 112);   // print in inverse text


     RECEIVE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     receive(int <protocol>, str <name>);

     ş  Description

     The receive function is used to receive (download) one or more files
     from another system. <protocol> is the letter used to select the ap-
     propriate protocol from the actual download menu in Telix (e.g., 'X'
     for Xmodem), as follows:

               'A'       ASCII
               'K'       Kermit
               'M'       Modem7
               'S'       SEAlink
               'T'       Telink
               'X'       Xmodem
               '1'       Xmodem-1k
               'G'       Xmodem-1k-g
               'Y'       Ymodem
               'E'       YmodEm-g
               'Z'       Zmodem

     If an external protocol is defined, <protocol> may also be the key
     used to select it. <name> is the name the file should take. For pro-
     tocols which pass the name, such as SEAlink, Zmodem, Ymodem (batch),
     and others, the name field should be an empty string, "". If a down-
     load directory has been defined in the Configuration Menu, received
     files will go there, unless the <name> string explicitly includes a
     path to another drive/directory.
     Telix v3.22 - SALT Programming                Built-in Functions    67



     ş  Return Value

     A value of -1 is returned if the transfer was aborted, except if the
     Carrier (connection) was lost, in which case a value of -2 is re-
     turned.

     ş  See Also

     send, _down_dir

     ş  Example

     int result;

     result = receive('X', "TEST.EXE");
     if (result < 0)
      prints("File transfer failed!");


     REDIAL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     redial(str <dialstr>, int <maxtries>, int <no_link>);

     ş  Description

     The redial function dials the entries specified in <dialstr>. The en-
     tries should be entered in the same format as used when typing entries
     in the dialing directory. If <dialstr> is empty (""), the redial queue
     is presented to the user, as if Alt-Q was pressed while in terminal
     mode. <maxtries> is the maximum number of dialing attempts. For exam-
     ple, if the string contains one entry, and <maxtries> is equal to 5,
     Telix will attempt to dial the number 5 times. If five entries are in-
     dicated, and <maxtries> is equal to 5, each number will only be at-
     tempted once. If <maxtries> is 0, dialing will continue until a con-
     nection is established. If an entry is connected to, and has a linked
     script file attached, that script will be run, unless <no_link> is
     non-zero (TRUE).

     ş  Return Value

     If there was a connection, the redial function returns the entry num-
     ber of the of the entry which was connected to (or 1 if a manual num-
     ber was dialed). If there was no connection established, 0 is re-
     turned. If the <dialstr> has a bad format, -1 is returned.

     Also, when a connection is successfully established, the entry number
     of the entry connected to is placed in the system variable
     _entry_enum, while the name of the entry connected to is placed in the
     system variable _entry_name.

     ş  See Also

     dial
     _entry_enum, _entry_name
     Telix v3.22 - SALT Programming                Built-in Functions    68



     ş  Example

     int stat;
     str number_list[] = "1 4 27";
     redial("10 15", 0);
     redial("m967-1111", 5);
     stat = redial(number_list, 0);


     RUN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     run(str <filename>, str <comline>, int <mode>);

     ş  Description

     The run function executes the indicated file. The indicated file must
     either be in the current directory, be on the DOS PATH, or must in-
     clude the full path to the file (i.e., specify the drive and/or direc-
     tory). Make sure that if you run a program that expects user input you
     are on hand to give it. The <comline> parameter is the command line
     which should be passed to the called program. The <mode> argument
     specifies several options, as follows:

          0    Original screen is restored when program is completed.
          1    When program is completed, the user is prompted to press a
               key and screen is restored as soon as it is pressed.
          2    Original screen is not restored when program is completed

     This function is similar to the dos function. Because it uses less
     memory and loads faster, it is preferable to that function unless a
     DOS Batch file has to be run, or an internal DOS command must be spec-
     ified, in which case the dos function has to be used.

     ş  Return Value

     The run function returns a -1 if the file can not be run (because it
     can not be found or there is not enough memory). Any other value is
     the value returned by the called program (usually 0), but a positive
     value may also result when the called program is aborted.

     ş  See Also

     dos, dosfunction

     ş  Example

     run("CS", "test", 1);
     Telix v3.22 - SALT Programming                Built-in Functions    69



     SCROLL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     scroll(int <x>, int <y>, int <x2>, int <y2>, int <lines>, int
     <color>);

     ş  Description

     The scroll function is used to scroll or clear a region of the screen.
     The area to handle is defined by <x>,<y> as the upper left corner, and
     <x2>,<y2> as the lower right corner (the upper left corner of the
     screen is 0,0). If the <lines> parameter is a positive value, text
     within the region is scrolled up that many lines. If <lines> is a neg-
     ative value, text within the region is scrolled down that many lines.
     If <lines> is equal to 0, the entire region is cleared. Empty lines
     scrolled into the region will have a color of <color>.

     ş  Return Value

     None.

     ş  See Also

     box

     ş  Example

     scroll(0, 0, 79, 24, 10, 7);      // scroll screen up 10 lines


     SEND
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     send(int <protocol>, str <name>);

     ş  Description

     The send function is used to send (upload) one or more files to an-
     other system over the comm port. <protocol> is the letter used to se-
     lect the appropriate protocol from the actual download menu in Telix
     (e.g., 'X' for Xmodem) as follows:
     Telix v3.22 - SALT Programming                Built-in Functions    70



               'A'       ASCII
               'K'       Kermit
               'M'       Modem7
               'S'       SEAlink
               'T'       Telink
               'X'       Xmodem
               '1'       Xmodem-1k
               'G'       Xmodem-1k-g
               'Y'       Ymodem
               'E'       YmodEm-g
               'Z'       Zmodem

     If an external protocol is defined, <protocol> may also be the key
     used to select. <name> is the file(s) to send. <name> may include the
     DOS wildcard characters * and ?, in which case all matching files will
     be sent (however the protocol used must be capable of sending more
     than one file at a time, e.g., SEAlink, Zmodem, Ymodem (batch), etc.).
     If an upload directory has been defined in the Configuration Menu,
     Telix will look there for files specified to be sent, unless the
     <name> string explicitly includes a path to another drive/directory.

     ş  Return Value

     A value of -1 is returned if the transfer was aborted, except if the
     carrier (connection) was lost, in which case a value of -2 is re-
     turned.

     ş  See Also

     receive, _up_dir


     SEND_BRK
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     send_brk(int <duration>);

     ş  Description

     The send_brk function sends a sustained break signal over the modem
     port, for a period of time, specified in tenths of a second, by
     <duration>.

     ş  Return Value

     None.


     SET_CPARAMS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     set_cparams(int <baud>, int <parity>, int <data>, int <stop>);
     Telix v3.22 - SALT Programming                Built-in Functions    71



     ş  Description

     The set_cparams function is used to set the communications parameters
     in use on the current communications port. Allowable <baud> values are
     300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, and 115200. <parity>
     is an integer number which stands for the parity to use. Allowable
     values are 0, 1, and 2, which stand for None, Even, and Odd parity,
     respectively. <data> is the data bits setting to use; allowable values
     are 7 or 8. <stop> is the stop bits setting to use; allowable values
     are 1 or 2. Note that some combinations of settings are illegal.

     ş  Return Value

     If all the settings are legal values, a non-zero (TRUE) value is re-
     turned, otherwise a value of -1 is returned.

     ş  See Also

     set_port

     ş  Example

     set_cparams(2400, 0, 8, 1);

     set_cparams(9600, get_parity(), get_datab(), get_stopb());

     SET_DEFPROT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     set_defprot(int <protocol>);

     ş  Description

     The set_defprot function is used to set the default file transfer pro-
     tocol presented to the user when a file transfer is requested.
     <protocol> is the letter used to select the appropriate protocol at
     the file transfer menu (see the description of the receive function
     for possible options).

     ş  Return Value

     None.

     ş  See Also

     receive, send

     ş  Example

     set_defprot('Z');      // Select Zmodem as default protocol
     Telix v3.22 - SALT Programming                Built-in Functions    72



     SETCHR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     setchr(str <buf>, int <pos>, int <c>);

     ş  Description

     The setchr function puts the character <c> at position <pos> in the
     string indicated by <buf>.

     ş  Return Value

     The character <c> is returned.

     ş  See Also

     setchrs, subchr

     ş  Example

     int i;
     str s[100];
     for (i = 0; i < 10; ++i)     // set first 10 characters to 'A'
      setchr(s, i, 'A');


     SETCHRS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     setchrs(str <buf>, int <pos>, int <c>, int <count>);

     ş  Description

     The setchrs function is used to set a range of characters in a string
     to the same value. <buf> is the string in which characters will be
     set, starting at an offset indicated by <pos> (note that the first
     character in a SALT string has an offset of 0, the second, 1, and so
     on). <count> characters will be set to the value of <c>.

     ş  Return Value

     None.

     ş  See Also

     setchr, subchrs

     ş  Example

     str s[100];
     // zero out an entire string
     setchrs(s, 0, 0, strmaxlen(s));
     // set the first ten characters to 'A'
     Telix v3.22 - SALT Programming                Built-in Functions    73



     setchrs(s, 0, 'A', 10);


     SET_PORT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     set_port(int <port>);

     ş  Description

     The set_port function is used to select a communications port to use.
     Allowable values for <port> are 1 through 8.

     ş  Return Value

     If the new port can be successfully initialized, a non-zero (TRUE)
     value is returned, otherwise a value of -1 is returned.

     ş  See Also

     set_cparams


     SET_TERMINAL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     set_terminal(str <terminal_name>);

     ş  Description

     The set_terminal function is used to switch the current terminal being
     emulated. <terminal_name> is the name of the new terminal to use, as
     follows:

          "TTY"
          "ANSI-BBS"
          "ANSI"
          "VT102"
          "VT52"
          "AVATAR"

     ş  Return Value

     A value of -1 is returned if there is a problem switching to the in-
     dicated terminal emulator, otherwise a non-zero (TRUE) value is re-
     turned.

     ş  Example

     set_terminal("VT102");
     Telix v3.22 - SALT Programming                Built-in Functions    74



     SHOW_DIRECTORY
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     show_directory(str <filespec>, int <cecho>, int <carrier>);

     ş  Description

     The show_directory function displays a files directory listing to the
     screen and optionally echoes it to the comm port. The <filespec> is
     the file mask to use (e.g., "*.*"), and may also include a drive
     and/or directory, just like the DOS 'dir' command. If the <cecho>
     argument is non-zero (TRUE), the listing is also be echoed to the comm
     port. If the <carrier> argument is non-zero (TRUE) and the listing is
     being echoed to the comm port, the carrier signal is monitored in case
     the connection is lost (which aborts the display). The user is
     prompted to press a key after every screen full of data.

     ş  Return Value

     None.

     ş  See Also

     dos, dosfunction

     ş  Example

     show_directory("*.DOC", 0, 0);


     STATUS_WIND
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     status_wind(str <message>, int <duration>);

     ş  Description

     The status_wind function is used to display a status message,
     <message>, in a pop up window. <duration> is the time in tenths of
     seconds to display the window, after which it is removed, and the pre-
     vious contents of that screen area are restored.

     ş  Return Value

     None.

     ş  See Also

     box, pstra, pstraxy

     ş  Example

     status_wind("File not found!", 10);
     Telix v3.22 - SALT Programming                Built-in Functions    75





     STOI
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     stoi(str <s>);

     ş  Description

     The stoi function assumes that <s> is a string which contains an in-
     teger number, written out. It processes the string digit by digit and
     returns that value. For example, stoi("123") would return the integer
     value 123. Processing stops at the first non-digit character. If an
     empty or invalid string is parsed, a value of 0 is returned.

     ş  Return Value

     An integer value as described above.

     ş  See Also

     itos

     ş  Example

     str s[] = "123";
     if (stoi(s) == 123)
      prints("This will always be printed!");


     STRCAT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     strcat(str <string1>, str <string2>);

     ş  Description

     The strcat function concatenates (adds or appends) one string to the
     other. <string2> is added to the end of <string1>. If <string1> is not
     large enough only as many characters as will fit are added.

     ş  Return Value

     None.

     ş  Example

     str s[80] = "hello";
     strcat(s, "good-bye");
     if (s == "hellogoodbye")
      prints("This will always be printed");
     Telix v3.22 - SALT Programming                Built-in Functions    76



     STRCHR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     strchr(str <s>, int <pos>, int <c);

     ş  Description

     The strchr function is used to search for a character within a string.
     <s> is the string to search, and <pos> is the starting position of the
     search, and <c> is the character (ASCII value) to search for. If the
     character, its offset is returned, otherwise a value of -1 is re-
     turned. Note that the first character in a string has an offset of 0,
     not 1 as in some languages.

     ş  Return Value

     An integer value as described above.

     ş  Example

     // Count how many times a certain char occurs in a string

     int i, count = 0;
     str s[] = "abcabcabcabcabc";

     i = 0;
     do
      {
       i = strchr(s, i, 'a');
       if (i != -1)
        count = count + 1;
      }
     while (i != -1);


     STRCMPI
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     strcmpi(str <string1>, str <string2>);

     ş  Description

     The strcmpi function is used to compare two strings (in a similar man-
     ner to the ==, >, and < operators, but ignoring the case of the
     strings). The strings are compared character by character until a dif-
     ference is found or the end of either string is found, and an integer
     value is returned as follows:
     Telix v3.22 - SALT Programming                Built-in Functions    77



          0         <string1> is equal to <string2>

          < 0       <string1> is less than <string2>

          > 0       <string1> is greater than <string2>

     ş  Return Value

     An integer value as described above.

     ş  Example

     if (strcmpi("HeLLo", "hEllO");
      prints("This will always be printed");


     STRLEN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     strlen(str <s>);

     ş  Description

     The strlen function returns the number of characters in the string
     <s>. Since strings are terminated with a 0 (NULL) character, this
     function really counts the number of characters before a 0 is en-
     countered.

     ş  Return Value

     An integer value representing the length of a string.

     ş  See Also

     strmaxlen

     ş  Example

     str teststr[] = "This is a test string";
     printsc("The length of 'teststr' is ");
     printn(strlen(teststr));


     STRLOWER
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     strlower(str <s>);

     ş  Description

     The strlower function processes the string <s> and changes each upper
     case character to lower case. Other characters are left unchanged.
     Telix v3.22 - SALT Programming                Built-in Functions    78



     ş  Return Value

     None.

     ş  See Also

     strupper


     STRMAXLEN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     strmaxlen(str <s>);

     ş  Description

     The strmaxlen function returns the maximum number of characters that
     string <s> can hold. This is the same value as used when the string is
     defined elsewhere in the program (e.g. if the string was defined as
     'str hello[16];', a value of 16 would be returned). All strings are
     really one character larger than defined, as the last character is al-
     ways a terminating 0 (NULL). However, since this value can not be
     changed, it is not counted as part of the length of a string.

     ş  Return Value

     An integer value as described above.

     ş  See Also

     strlen


     STRPOS, STRPOSI
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     strpos(str <string1>, str <substr>, int <start>);

     strposi(str <string1>, str <substr>, int <start>);

     ş  Description

     The strpos function is used to search for one string within another.
     <string1> is scanned for <substr>, starting at the offset (position)
     indicated by <start>. If the sub-string is found, its offset is re-
     turned, otherwise a value of -1 is returned. Note that the first char-
     acter has an offset of 0, not 1 as in some languages.

     strposi is a case insensitive version of the above.

     ş  Return Value

     An integer value as described above.
     Telix v3.22 - SALT Programming                Built-in Functions    79



     ş  Example

     str teststr[] = "cat dog cat dog";
     int i = 0, num = 0;

     while (1)           // loop as long as needed
      {
       i = strpos(teststr, "cat", i);
       if (i == -1)
        break;
       i = i + 1;        // make sure we don't find the same one
       num = num + 1;    // increment count
      }

     prints("'cat' was found ");
     printn(num);
     prints(" times.");


     STRUPPER
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     strupper(str <s>);

     ş  Description

     The strupper function processes the string <s> and changes each lower
     case character to upper case. Other characters are left unchanged.

     ş  Return Value

     None.

     ş  See Also

     strlower


     SUBCHR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     subchr(str <s>, int <pos>);

     ş  Description

     The subchr function returns the character found at position <pos> in
     string <s>. Note that an integer (representing the ASCII value of the
     character) is returned, not a string. <pos> may be anywhere within the
     string length as defined. Note that positions start from 0. The 1st
     character in a string is at position 0, the 40th at position 39, etc.
     A string defined with a length of 10 would have valid positions of 0
     to 9, with position 10 always returning the 0 value that terminates
     all strings.
     Telix v3.22 - SALT Programming                Built-in Functions    80



     ş  Return Value

     An integer value as described above.

     ş  See Also

     setchr, subchrs

     ş  Example

     // This will print out the contents of a test string, extracting
     // each character individually, and stopping when a 0 is reached
     // which marks the end of all proper strings

     int i;
     str s[] = "This is a test string";
     for (i = 0; subchr(s, i) != 0; ++i)
      printc(subchr(s, i));


     SUBCHRS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     subchrs(str <source>, int <pos>, int <count>, str <target>);

     ş  Description

     The subchrs function copies a number of characters from one string
     into another, Characters from position <pos> in <source> are copied
     into string <target> (note that SALT string offsets start at 0, not 1
     as in some languages). <count> characters are copied. Only as many
     characters as will fit in <target> are copied.

     This function is very similar to substr, except that it is not string
     oriented, and does not stop copying characters when a 0 value is en-
     countered.

     ş  Return Value

     None.

     ş  See Also

     substr, subchr, copystr, copychrs


     SUBSTR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     substr(str <source>, int <pos>, int <max>, str <target>);
     Telix v3.22 - SALT Programming                Built-in Functions    81



     ş  Description

     The substr function copies a portion of one string to another. Char-
     acters from position <pos> in string <source> are copied until into
     string <target> (note that SALT string offsets start at 0, not 1 as in
     some languages). Characters are copied until a 0 (NULL) value is en-
     countered (normally at the end of every string), or <max> characters
     are copied. A 0 (NULL) is always copied at the end of the target
     string. The 0 does not count as part of the <max>. Only as many char-
     acters as will fit in <target> are copied.

     ş  Return Value

     None.

     ş  See Also

     subchrs, copystr, copychrs

     ş  Example

     str s[] = "horse cat dog", s2[16];
     substr(s, 6, 3, s2);
     if (s2 == "cat")
      prints("This will always be printed");


     TDAY - TYEAR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     tday(int <timeval>);

     thour(int <timeval>);

     tmin(int <timeval>);

     tmonth(int <timeval>);

     tsec(int <timeval>);

     tyear(int <timeval>);

     ş  Description

     These functions all extract time information from <timeval>, which is
     a date and/or time of day. If <timeval> represents a date, it is the
     number of seconds from Jan 1, 1970 to that date. If <timeval> repre-
     sents a time of day, it is the number of seconds from midnight to that
     time. If it is both, the two above values are simply added together.
     Among others, the curtime and filetime functions return time/date in-
     formation in this format.

     tday returns an integer value from 1 to 31 representing the day por-
     tion of the date stored in <timeval>.
     Telix v3.22 - SALT Programming                Built-in Functions    82



     thour returns an integer value from 0 to 23 representing the hour por-
     tion of the time stored in <timeval>.

     tmin returns an integer value from 0 to 59 representing the minutes
     portion of the time stored in <timeval>.

     tmonth returns an integer value from 1 to 12 representing the month
     portion of the date stored in <timeval>.

     tsec returns an integer value from 1 to 59 representing the seconds
     portion of the time stored in <timeval>.

     tyear returns an integer value from 1970 to 2019 representing the year
     portion of the date stored in <timeval>.

     ş  Return Value

     An integer value as described above.

     ş  See Also

     curtime, filetime

     ş  Example

     int t;
     t = curtime();
     printsc("This is month number ");
     printn(tmonth(t));
     printsc(" in the year ");
     printn(tyear(t));
     prints(".");


     TERMINAL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     terminal();

     ş  Description

     The terminal function when called allows Telix to process characters
     coming in from the serial port and print them on the terminal screen,
     and process user keystrokes. If a function has nothing to do (for ex-
     ample while using the track function), it can call terminal to make
     sure characters and user keystrokes are processed. Note that if a user
     script wants to process every incoming character (e.g., with the cgetc
     function, the terminal function should never be called).

     ş  Return Value

     None.
     Telix v3.22 - SALT Programming                Built-in Functions    83



     ş  See Also

     track

     ş  Example

     // This will wait forever for either of two strings
     // to come in from the comm port, and then stop.
     int t1, t2, stat;
     t1 = track("hello", 0);
     t2 = track("good-bye", 0);
     while (1)           // loop forever
      {
       terminal();       // The call to terminal() lets any characters
                         // that come in be looked at by Telix's
                         // internal routines for a match with.
                         // Incoming chars are also printed on the
                         // terminal screen and user keystrokes are
                         // handled
       stat = track_hit(0);
       if (stat == t1 || stat == t2)   // exit if one of the strings
        break;                         // came in
      }

     track_free(t1);     // stop Telix for looking for more matches
     track_free(t2);


     TIME
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     time(int <timeval>, str <buffer>);

     ş  Description

     The time function writes out a time in <buffer> in the form hh:mm:ss,
     with hh being the hour in either 12 or 24 hour format based on the
     _time_format). <timeval> is the time, represented as the number of
     seconds since midnight. Time values in this form are returned by the
     curtime and filetime functions, among others.

     ş  Return Value

     None.

     ş  See Also

     date, curtime, filetime

     ş  Example

     str s[16];
     printsc("The current time is ");
     time(curtime(), s);
     prints(s);
     Telix v3.22 - SALT Programming                Built-in Functions    84





     TIME_UP - TIMER_TOTAL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     time_up(int <thandle>);

     timer_free(int <thandle>);

     timer_restart(int <thandle>, int <time>);

     timer_start(int <time>);

     timer_total(int <thandle>);

     ş  Description

     The timer functions are used to set and keep track of a timer vari-
     able.

     The timer_start function is used to start a timer. This timer can
     later be used to check if a certain period of time has elapsed from
     when the timer was started. This function returns an integer value
     called a timer handle, that is used to refer to this timer in the fu-
     ture. The <time> parameter is the time from the present (in tenths of
     a second) after which the timer should be considered elapsed (for use
     with the time_up function). If the time_up function will not be used,
     then this parameter can be anything.

     The time_up function returns a non-zero (TRUE) value if the timer rep-
     resented by timer handle <thandle> has elapsed, otherwise a 0 (FALSE)
     value is returned. The period of time after which a timer will elapse
     is specified in the timer_start function.

     The timer_total function returns the total time (in tenths of a sec-
     ond) since the timer represented by timer handle <thandle> was started
     or restarted.

     The timer_restart function performs the same things as timer_start,
     except that it restarts an existing timer, represented by timer handle
     <thandle>.

     The timer_free function frees a timer variable when it is no longer
     needed. <thandle> is the timer handle of the timer to free, and should
     originally have been returned by the timer_start function. After a
     timer has been freed it should no longer be referred to.

     ş  Return Value

     timer_start returns an integer number representing a 'handle' by which
     a timer will be referred to.

     time_up returns a non-zero (TRUE) or 0 (FALSE) value depending on
     whether a timer has elapsed or not.
     Telix v3.22 - SALT Programming                Built-in Functions    85



     timer_total returns an integer value representing the elapsed time
     since a timer was started.

     timer_restart does not return any significant value.

     timer_free does not return any significant value.

     ş  See Also

     delay

     ş  Example

     int t;
     t = timer_start(100);    // delay for 10 seconds
     while (!time_up(t))
      ;
     timer_free(t);
     // start a timer and loop forever, printing the elapsed time
     // in tenths of seconds
     t = timer_start(0);
     while (1)
      {
       printn(timer_total(t));
       prints("");
      }


     TOLOWER
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     tolower(int <chr>);

     ş  Description

     If the character <chr> is an uppercase character, the tolower function
     returns the lowercase equivalent. Otherwise <chr> is returned un-
     changed. Note that <chr> is an ASCII value, not a string.

     ş  Return Value

     An integer value as described above.

     ş  See Also

     toupper


     TONE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     tone(int <frequency>, int <length>);
     Telix v3.22 - SALT Programming                Built-in Functions    86



     ş  Description

     The tone function makes Telix emit a sound of <frequency> for a period
     of time represented by length (in hundredths of a second).

     ş  Return Value

     None.

     ş  See Also

     alarm
     _sound_on

     ş  Example

     tone(659, 14);


     TOUPPER
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     tolower(int <chr>);

     ş  Description

     If the character <chr> is an lowercase character, the toupper function
     returns the uppercase equivalent. Otherwise <chr> is returned un-
     changed. Note that <chr> is an ASCII value, not a string.

     ş  Return Value

     An integer value as described above.

     ş  See Also

     tolower


     TRACK - TRACK_HIT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     track(str <trackstr>, int <mode>);

     track_addchr(int <chr>);

     track_free(int <handle>);

     track_hit(int <handle>);
     Telix v3.22 - SALT Programming                Built-in Functions    87



     ş  Description

     The track and related functions are used to keep track of and wait for
     certain strings to come in over the comm port, similar in nature to
     the waitfor function. However the latter function can only wait for
     one specific string, while with the track functions can handle more
     strings at the same time (currently up to 16), and they may arrive in
     any order (or not arrive at all).

     The track function tells Telix to keep track of (watch for) the string
     indicated by <trackstr> to come in over the comm port. If <mode> is 0,
     case is significant, if <mode> is 1, case is not significant. The for-
     mer is faster and should be used when the many strings are being
     watched for. Track returns an integer value called a 'track handle'
     which is later used with the track_hit function to check if this
     string came in.

     When track is called, Telix doesn't loop endlessly waiting for the
     string to come in, but instead returns back to the script. As char-
     acters come in, Telix checks to see if any of the strings to be
     tracked have been matched, and marks those that have. A script can at
     any time call the track_hit function to see if the string represented
     by <handle> was received. If track_hit returns a non-zero (TRUE)
     value, then that string was received, otherwise it wasn't. If <handle>
     is 0, then track_hit will return the lowest numbered handle of any
     strings that came in, or 0 if none did. The marker on a handle is
     cleared once track_hit has indicated that the appropriate string was
     received.

     While a script is executing, Telix is not in terminal mode, and there-
     fore does not have access to incoming characters, to scan for matching
     strings. Therefore, the terminal function must periodically be called
     to allow Telix to get a look at incoming characters. This function is
     described in the appropriate place in this manual. Alternately, if a
     script must process these characters itself (with a function like
     cgetc), and therefore can not call the terminal function, they must
     still be passed by the track routines for string matching to work. The
     track_addchr function is used for this. When it is called, Telix
     treats the character represented by <chr> as if it had been received
     from the terminal handler, and uses it to scan for matching strings.

     The track_free function is used to tell Telix to stop tracking a cer-
     tain string. <handle> is a track handle returned by a previous call to
     the track function. It is very important that when a certain string no
     longer needs to be tracked, track_free is called, as tracking a large
     number of strings can slow down Telix execution. If <handle> is 0,
     Telix will stop tracking all strings.

     ş  Return Value

     track_addchr and track_free do not return a value. The other functions
     return integer values as described above.

     ş  See Also

     waitfor
     Telix v3.22 - SALT Programming                Built-in Functions    88



     ş  Example

     // Log-on to a BBS, answering two prompts in any order.
     // This will wait forever, so for actual use would have
     // to be changed a bit. See sample scripts for examples.

     int stat, t1, t2;
     t1 = track("Name? ", 0);
     t2 = track("Password? ", 0);

     while (1)         // loop as long as needed
      {
       terminal();     // call terminal function to allow Telix
                       // to look at incoming characters for
                       // matches and let Telix process user
                       // keystrokes
       stat = track_hit(0);       // see if any matches
       if (stat == t1)            // name prompt
         cputs("Joe Smith^M");    // send name and continue looping
       if (stat == t2)            // password prompt
        {
         cputs("mypass^M");       // send password
         break;                   //   and get out of loop
        }
      }

     track_free(t1);              // free track handles
     track_free(t2);


     TRANSTAB
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     transtab(str <filename>, int <table>);

     ş  Description

     The transtab function is used to load or clear the incoming or out-
     going character translation table. <table> stands for the translate
     table to manipulate, with 0 being the incoming, and 1 being the out-
     going.

     If <filename> is empty (""), Telix will prompt for the name of a
     translate table to load into memory.

     If <filename> is a valid name for a Telix translate table (saved from
     the translate table menu in Telix), it is loaded into memory.

     If <filename> is "*CLEAR*", the current translate table in memory is
     cleared, and Telix will no longer translate incoming characters.

     ş  Return Value

     A value of -1 is returned if there is a problem loading the indicated
     translate table, otherwise a non-zero (TRUE) value is returned.
     Telix v3.22 - SALT Programming                Built-in Functions    89



     ş  Example

     transtab("TELIX.XLT", 0);


     UNLOAD_SCR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     unload_scr(str <filename>);

     ş  Description

     The load_scr function can be used by a script file to load another
     script into memory ahead of time (before it is run). The unload_scr
     function should then be used to unload or take out this script when it
     is no longer needed. <filename> is the name of the script file to un-
     load, and if no extension is given, ".SLC" is assumed. Note that a
     script that is currently executing or that is nested (has called the
     current script) must not be unloaded, since Telix is still executing
     it or will return to it eventually!

     ş  Return Value

     If there is a problem unloading the script file, a value of -1 is re-
     turned. Otherwise a non-zero (TRUE) value is returned.

     ş  See Also

     load_scr, is_loaded

     ş  Example

     int stat;
     stat = load_scr("TEST");     // load TEST.SLC
         ...                      // do other things
     unload_scr("TEST");          // take TEST.SLC out of memory


     UPDATE_TERM;
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     update_term();

     ş  Description

     The update_term function is called to make sure Telix updates certain
     things relating to the video and terminal page. For example, changes
     made to the _back_color and _fore_color system variables will not take
     effect until this function is called. As well Telix may sometimes take
     up to 15 seconds to update the status bar (and in some cases while
     scripts are running, won't update it at all). Calling this function
     ensures that the status bar is updated.
     Telix v3.22 - SALT Programming                Built-in Functions    90



     ş  Return Value

     None.

     ş  Example

     int temp;               // reverse current terminal colors
     temp = back_color;
     back_color = fore_color;
     fore_color = temp;
     update_term();


     USAGELOG
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     usagelog(str <filename>);

     ş  Description

     The usagelog function is used to manipulate the Telix usage log fa-
     cility.

     If <filename> is an empty string (""), Telix will ask for the filename
     to open the usage log to, as if the user had pressed Alt-U in terminal
     mode.

     If <filename> contains a valid filename, the usage log is opened to
     that file. The standard usage log is usually called "TELIX.USE".

     If <filename> is "*CLOSE*", and the usage log is currently open, it is
     closed.

     ş  Return Value

     A value of -1 is returned if there is a problem performing the indi-
     cated operation, otherwise a non-zero (TRUE) value is returned.

     ş  See Also

     ustamp, usage_stat
     _usage_fname

     ş  Example

     usagelog("TELIX.USE");


     USAGE_STAT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     usage_stat();
     Telix v3.22 - SALT Programming                Built-in Functions    91



     ş  Description

     The usage_stat function returns an integer value representing the cur-
     rent status of the Usage Log. If the Usage Log is currently open, a
     non-zero (TRUE) value is returned, otherwise a value of zero (FALSE)
     is returned.

     ş  Return Value

     An integer values as described above.

     ş  See Also

     usagelog, capture_stat


     USTAMP
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     ustamp(str <text>, int <new_entry>, int <add_nl>);

     ş  Description

     The ustamp function is used to place (stamp) text into the Telix usage
     log. If the usage log is currently not open, this function call is
     simply ignored. <text> is the entry that should be placed into the us-
     age log. If <new_entry> contains a non-zero (TRUE) value, the current
     date/time is placed ahead of the text, otherwise it is assumed that
     this is a continuation of a previous entry and no date/time is added.
     If <add_nl> (add new line) is a non-zero (TRUE) value, a Carriage Re-
     turn and Line Feed character are added after the entry. This is usu-
     ally the case unless something else must be added on the same line.

     ş  Return Value

     A value of -1 is returned if there is a problem writing to the usage
     log, otherwise a non-zero (TRUE) value is returned.

     ş  See Also

     usagelog

     ş  Example

     ustamp("Calling user subroutine... ", 1, 0);
     if (user_sub == -1)
      ustamp("Failed!, 0, 1);
     else
      ustamp("Successful", 0, 1);
     Telix v3.22 - SALT Programming                Built-in Functions    92



     VGETCHR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     vgetchr();

     ş  Description

     The vgetchr function is used to read the character (including color
     information) at the current cursor position on the video screen. The
     return value contains the character in the first (low) byte, and the
     color of the character in the higher (second) byte. Each component may
     be extracted using the & and / operators as shown in the example be-
     low. Basically, if 'c' is the returned character/color value, the
     character alone may be obtained by using the expression

          (c & 255)

     while the color value is

          (c / 256)

     ş  Return Value

     An integer value as described above.

     ş  See Also

     vgetchrs, vgetchrsa, vputchr

     ş  Example

     int chr;
     chr = vgetchr();      // Get char/color at current cursor position
     printsc("The character was ");
     printc(chr & 255);    // get character by masking out color byte
     printsc(" with a color value of ");
     printn(chr / 256);     // shift color byte


     VGETCHRS, VGETCHRSA
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     vgetchrs(int <x>, int <y>, str <buf>, int <pos>, int <num>);

     vgetchrsa(int <x>, int <y>, str <buf>, int <pos>, int <num>);

     ş  Description

     The vgetchrs and vgetchrsa functions are used to read multiple char-
     acters starting from a spot on the screen into a specified variable.
     The first function saves only the characters (a sequence of bytes)
     while the second saves both the characters and color attributes (a se-
     ries of double bytes). <x>,<y> is the spot on the screen to start
     Telix v3.22 - SALT Programming                Built-in Functions    93



     reading characters. <buf> is the string variable to put characters
     into, starting at an offset of <pos> in the variable. Note that each
     character read in with vgetchrsa will take up two bytes in the string
     variable, since the color attribute is also saved. Note also that
     these functions do not put a 0 (NULL, or end of string character) at
     the end of the sequence of characters they grab. If the characters re-
     turned by vgetchrs are to be manipulated as a string a 0 must be added
     at the end with the setchr function.

     ş  Return Value

     None.

     ş  See Also

     vgetchr, vputchrs, vputchrsa

     ş  Example

     // copy 20 characters starting from 10,10 on the screen to 20,20
     // Don't keep color attributes
     str buffer[20];
     vgetchrs(10, 10, buffer, 0, 20);
     vputchrs(20, 20, buffer, 0, 20);

     // copy a 20 by 10 grid of characters with a left hand corner of
     // 10,5 to 40,7, and keep color attributes
     str buffer[400];   // 20 wide * 10 tall * 2 bytes per character
     int y;
     for (y = 5; y < 15; y = y+1)         // read chars in a loop
      vgetchrsa(10, y, buffer, 2 * 20 * (y - 5), 20);
     for (y = 7; y < 17; y = y+1)         // now write them in a loop
      vputchrs(10, y, buffer, 2 * 20 * (y - 7), 20);


     VPUTCHR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     vputchr(int <chr>);

     ş  Description

     The vputchr function is used to place a character on the screen at the
     current cursor position, specifying color information at the same
     time. <chr> is the character to place on the screen. the low byte con-
     tains the ASCII value of the character, while the second byte contains
     the color value. In general, a if 'c' is the character, and 'color' is
     the color to use, the proper value is obtained with the expression

          (c + color * 256)

     ş  Return Value

     None.
     Telix v3.22 - SALT Programming                Built-in Functions    94



     ş  See Also

     vgetchr

     ş  Example

     // Place an inverse 'X' in the left top corner of the screen
     gotoxy(0, 0);
     vputchr('X' + 112 * 256);


     VPUTCHRS, VPUTCHRSA
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     vputchrs(int <x>, int <y>, str <buf>, int <pos>, int <num>, int
     <attr>);

     vputchrsa(int <x>, int <y>, str <buf>, int <pos>, int <num>);

     ş  Description

     The vputchrs and vputchrsa functions are used to write multiple char-
     acters from a spot in a string variable onto the screen at a certain
     position. The first function assumes that the string contains charac-
     ters only, and writes them to the screen using a color attribute of
     <attr>, as described in Appendix C. The second function assumes that
     each character in the string is immediately followed by a color value
     (a series of double bytes). <x>,<y> is the spot on the screen to start
     writing characters. <buf> is the string variable to read characters
     from, starting at an offset of <pos> in the variable. Note that each
     character written with vputchrsa will take up two bytes in the string
     variable, since the color attribute is also there, so the offset
     should reflect this.

     ş  Return Value

     None.

     ş  See Also

     vputchr, vgetchrs, vgetchrsa

     ş  Example

     // copy 20 characters starting from 10,10 on the screen to 20,20
     // Don't keep color attributes
     str buffer[20];
     vgetchrs(10, 10, buffer, 0, 20);
     vputchrs(20, 20, buffer, 0, 20);

     // copy a 20 by 10 grid of characters with a left hand corner of
     // 10,5 to 40,7, and keep color attributes
     str buffer[400];   // 20 wide * 10 tall * 2 bytes per character
     int y;
     for (y = 5; y < 15; y = y+1)         // read chars in a loop
     Telix v3.22 - SALT Programming                Built-in Functions    95



      vgetchrsa(10, y, buffer, 2 * 20 * (y - 5), 20);
     for (y = 7; y < 17; y = y+1)         // now write them in a loop
      vputchrs(10, y, buffer, 2 * 20 * (y - 7), 20);


     VRSTRAREA
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     vrstrarea(int <vhandle>);

     ş  Description

     The vrstrarea function is used to restore a previously saved portion
     of the screen. <vhandle> is the video information handle returned by a
     previous call to vsavearea, which saved the screen area.

     Note, it is very important that <vhandle> is a valid handle, returned
     by a previous call to vsavearea, or unpredictable results will happen.

     ş  Return Value

     None.

     ş  See Also

     vsavearea


     VSAVEAREA
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     vsavearea(int <x1>, int <y1>, int <x2>, int <y2>);

     ş  Description

     The vsavearea function is used to save a rectangular portion of the
     screen (to be later restored). <x1>,<y1> is the upper left corner of
     the area to save, while <x2>,<y2> is the lower right corner. Charac-
     ters (and their colors) currently on the screen in this rectangle are
     saved in a buffer, and a 'handle' is returned, which must be stored
     and used in the subsequent call to vrstrarea to restore the saved
     area. If not enough memory exists to save the video bytes, a value of
     -1 is returned instead.

     Note that Telix has only a limited amount of space for allocating to
     video buffers of this type. At one time, only about as much area as
     would amount to a full screen should be saved with calls to this func-
     tion.

     It is also very important that for every call to this function, there
     is a subsequent call to vrstrarea. If this is not done, memory will
     become used up until no more is left.
     Telix v3.22 - SALT Programming                Built-in Functions    96



     ş  Return Value

     An integer value representing a 'handle' to the saved area.

     ş  See Also

     vrstrarea

     ş  Example

     int vhandle;
     vhandle = vsavearea(0, 0, 79, 24);  // save the current screen
     myfunc();                           // call a function
                                         // which modifies screen
     vrstrarea(vhandle);                 // restore previous screen

     WAITFOR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     waitfor(str <waitstr>, int <timeout>);

     ş  Description

     The waitfor function is used to wait for the given string to come in
     over the serial port. Timeout is the maximum amount of time, in sec-
     onds, to wait for the string. Case is not significant, and the string
     must be no longer than 40 characters.

     ş  Return Value

     A non-zero (TRUE) value is returned if the string is received from the
     serial port in the given time, otherwise a zero (FALSE) value is re-
     turned.

     ş  See Also

     track

     ş  Example

     if (waitfor("name?", 180))
      prints("The string 'name?' came in from the comm port.");
     else
      {
       prints("The string 'name?' did not come in from the");
       prints("comm port in 3 minutes!");
      }
     Telix v3.22 - SALT Programming                  System Variables    97



     5.  SYSTEM VARIABLES

     Telix has quite a large number predefined built-in variables. They are
     called System Variables and are used to store many preferences. There
     are both string and numeric system variables, and they are accessed
     just as you would access any other variable. To help distinguish them
     apart from normal variables, and to avoid confusion, they all start
     with an underscore (_) character.

     The following pages contain descriptions of all the system variables.
     For each variable, a summary and a description are given. An example
     of actual usage of the variable will often be given.

     The variables are listed in alphabetical order. So that you may find
     related variables (and built-in functions), most variable descriptions
     have a 'See also' section, which lists related variables and func-
     tions.
     Telix v3.22 - SALT Programming                  System Variables    98



     _ADD_LF
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _add_lf;

     ş  Description

     If the _add_lf system variable is set to non-zero (TRUE), a Line Feed
     character is automatically added after every Carriage Return character
     that comes in.


     _ALARM_ON
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _alarm_on;

     ş  Description

     If the _alarm_on system variable is set to non-zero (TRUE), alarms are
     enabled in Telix. Note that if the _sound_off system variable is set
     to zero (FALSE), alarms will not be heard no matter what the state of
     this variable.

     ş  See Also

     alarm
     _sound_on


     _ANSWERBACK_STR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _answerback_str[19];

     ş  Description

     The _answerback_str system variable holds the string which Telix will
     send when a Ctrl-E (ENQ) character is received while in terminal mode.
     If this string is empty, nothing is sent. Note that if Compuserve B
     transfers are enabled, the answerback string will not be sent, since
     CIS B uses the Ctrl-E as part of the transfer process. Maximum length
     is 19 characters.


     _ASC_RCRTRANS - _ASC_STRIPH
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _asc_rcrtrans;
     Telix v3.22 - SALT Programming                  System Variables    99



     int _asc_remabort;

     int _asc_rlftrans;

     int _asc_scpacing;

     int _asc_scrtrans;

     int _asc_secho;

     int _asc_sexpand;

     int _asc_slftrans;

     int _asc_slpacing;

     int _asc_spacechr;

     int _asc_striph;

     ş  Description

     _asc_rcrtrans determines what Telix does with Carriage Return char-
     acters during ASCII receives. 0 = do nothing; 1 = strip; 2 = add Line
     Feed afterwards.

     _asc_remabort is the character which when received from the remote
     side during an ASCII transfer is a signal to abort the transfer.

     _asc_rlftrans determines what Telix does with Line Feed characters
     during ASCII receives. 0 = do nothing; 1 = strip; 2 = add Carriage Re-
     turn before.

     _asc_scpacing is the time in milliseconds which Telix should wait be-
     fore transmitting each character during ASCII sends.

     _asc_scrtrans determines what Telix does with Carriage Return char-
     acters during ASCII sends. 0 = do nothing; 1 = strip; 2 = add Line
     Feed afterwards.

     If _asc_secho is set to non-zero (TRUE), Telix will echo each char-
     acter during ASCII sends.

     If _asc_sexpand is set to non-zero (TRUE), Telix will expand blank
     lines to a space character, during ASCII sends.

     _asc_slftran determines what Telix does with Line Feed characters dur-
     ing ASCII sends. 0 = do nothing; 1 = strip; 2 = add Carriage Return
     before.

     _asc_slpacing is the time in tenths of seconds which Telix should wait
     before transmitting each line during ASCII sends.

     _asc_spacechr is the character which Telix should wait for during
     ASCII sends, before transmitting each line (0 means no wait).
     Telix v3.22 - SALT Programming                 System Variables    100



     If _asc_striph is set to non-zero (TRUE), Telix will strip the high
     (most significant) bit of each character in an ASCII transfer.


     _AUTO_ANS_STR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _auto_ans_str[48];

     ş  Description

     The _auto_ans_str system variable holds the string that should be sent
     to the modem to make it automatically answer the phone when it rings.
     This string is used by the Host Mode script, among others. The string
     will possibly include translation characters as described in the Telix
     manual in the section by that name, and should be sent to the modem
     with the cputs_tr function. Maximum length is 49 characters.

     ş  See Also

     _mdm_init_str


     _BACK_COLOR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _back_color;

     ş  Description

     The _back_color system variable contains the background color which
     should be used for text in terminal mode. Allowable values are from 0
     - 15. Note that changes to this variable may not be reflected until
     the screen is cleared.

     ş  See Also

     _fore_color


     _CAPTURE_FNAME
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _capture_fname[64];

     ş  Description

     The _capture_fname system variable holds the default capture file
     filename. The maximum length is 64 characters.
     Telix v3.22 - SALT Programming                 System Variables    101



     ş  See Also

     capture
     _usage_fname


     _CISB_AUTO
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _cisb_auto;

     ş  Description

     The _cisb_auto system variable controls whether Compuserve Quick B
     auto file transfer are allowed. If this variable is set to a 0 (FALSE)
     value, requests by the remote (Compuserve) to transfer files using the
     Quick B protocol will be ignored.

     ş  See Also

     _zmod_auto


     _CONNECT_STR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _connect_str[19];

     ş  Description

     The _connect_str system variable holds the string which Telix should
     scan for when dialing, and should take to mean that a connection has
     been established. For Hayes type modems it is usually set to
     "CONNECT". Maximum length is 19 characters.

     ş  See Also

     _no_connect1 - _no_connect4


     _DATE_FORMAT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _date_format;

     ş  Description

     The contents of the _date_format system variable determines what for-
     mat Telix uses for date strings it produces, as follows:
     Telix v3.22 - SALT Programming                 System Variables    102



                    0    mm/dd/yy
                    1    dd/mm/yy
                    2    yy/mm/dd

     ş  See Also

     _time_format
     date


     _DEST_BS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _dest_bs;

     ş  Description

     The _dest_bs system variable controls whether a backspace character
     received by Telix in Terminal Mode erases the character to the left of
     the cursor, or just moves the cursor on top of it on top of it without
     erasing it. If this variable is 0 (FALSE), Telix will treat the
     backspace as non-destructive, and destructive otherwise.

     ş  See Also

     _swap_bs


     _DIAL_PAUSE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _dial_pause;

     ş  Description

     The _dial_pause system variable holds (in seconds) the amount of time
     to wait between the end of one dialing attempt and the beginning of
     another. Most modems don't need more than a 1 second pause.


     _DIAL_TIME
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _dial_time;

     ş  Description

     The _dial_time system variable holds the amount of time Telix should
     wait for a connection when dialing, in seconds (e.g. 30).
     Telix v3.22 - SALT Programming                 System Variables    103



     ş  See Also

     _dial_pause


     _DIALPOST
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _dialpost[19];

     ş  Description

     The _dialpost system variable holds the string (the dialing postfix)
     which should be sent to the modem after the number, when dialing. For
     Hayes type modems, it is usually just a Carriage Return. Maximum
     length is 19 characters. This string will possibly include some trans-
     lation characters, as described in the Telix manual, and should be
     sent to the modem with the cputs_tr function.

     ş  See Also

     _dialpref, _dialpref2, _dialpref3, _redial_stop


     _DIALPREF
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _dialpref[19];

     str _dialpref2[19];

     str _dialpref3[19];

     ş  Description

     The _dialpref system variable holds the string which should be sent to
     the modem before the number, when dialing. For Hayes type modems, it
     is usually set to "ATDT". Maximum length is 19 characters. This string
     will possibly include translation characters, as described in the
     Telix manual, and should be sent to the modem with the cputs_tr func-
     tion.

     The _dialpref2 and _dialpref3 variables are the other two dialing pre-
     fixes that may be defined in Telix.

     ş  See Also

     _dialpost, _redial_stop
     Telix v3.22 - SALT Programming                 System Variables    104



     _DIR_PROG
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _dir_prog[15];

     ş  Description

     The _dir_prog system variable holds the name of the disk directory
     program that should be run when the user selects the 'Files directory'
     option of the DOS Functions menu. If this variable is left empty (""),
     the DOS 'dir' command is used. Maximum length is 15 characters.


     _DISP_FREE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _disp_free

     ş  Description

     If the _disp_free system variable is set to non-zero (TRUE), Telix
     will display the amount of free space available on the drive when the
     user presses Alt-R to download a file.


     _DOWN_DIR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _down_dir[64];

     ş  Description

     The _down_dir system variable holds the default download directory
     name. When a file is downloaded (received), if the user specifies a
     drive and/or directory in the name, the file is put there. However, if
     only a name is specified, the file is placed in the directory in-
     dicated by _down_dir. The maximum length is 64 characters, and this
     string should end with the backslash character, '\'.

     ş  See Also

     _up_dir, receive


     _EDITOR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _editor[64];
     Telix v3.22 - SALT Programming                 System Variables    105



     ş  Description

     The _editor system variable holds the name of the editor that should
     be run when the user presses Alt-A. The editor should either be on the
     DOS Path, in which case only the name needs to be given, or else the
     entire pathname (drive, directory, name) must be given. The maximum
     length is 64 characters. If a batch file is to be run the .BAT exten-
     sion must be given.


     _ENTRY_ENUM
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _entry_enum;

     ş  Description

     The _entry_enum variable is set by the dialing routines. When a con-
     nection is established while dialing, the entry number of the dialing
     directory entry connected to is stored here. If a manual number is
     connected to, the value 0 is stored here.

     ş  See Also

     _entry_name
     dial, redial


     _ENTRY_NAME - _ENTRY_PASS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _entry_name[29];

     str _entry_num[17];

     str _entry_pass[14];

     ş  Description

     The _entry_name system variable is set by the dialing routines. When a
     connection has been established the name portion of the dialing direc-
     tory entry connected to is copied here, for use by script files. The
     maximum length is 29 characters.

     The _entry_num system variable is set in the same way, and holds the
     phone number of the entry connected to. The maximum length is 17 char-
     acters.

     The entry_pass system variable is set in the same way, and holds the
     password from the entry connected to. This may be used to perform lo-
     gons. The maximum length is 14 characters.
     Telix v3.22 - SALT Programming                 System Variables    106



     ş  See Also

     _entry_enum
     dial, redial


     _EXT_FILESPEC;
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _ext_filespec[64];

     ş  Description

     This variable is for use by scripts implementing external protocols.
     When an external protocol has been defined as called by a script, this
     variable is first loaded with the filespec (file specification) typed
     by the user at the transfer menu. The appropriate script is then run.
     The script can for example pass this name to a program which imple-
     ments the actual protocol. Note that some file transfer protocols do
     not require the user to supply the name on downloads, in which case
     this variable is left empty.


     _FORE_COLOR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _fore_color;

     ş  Description

     The _fore_color system variable contains the foreground color which
     should be used for text in terminal mode. Allowable values are from 0
     - 15. Note that changes to this variable may not be reflected until
     the screen is cleared.

     ş  See Also

     _back_color


     _IMAGE_FILE;
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _image_file[64];

     ş  Description

     The _image_file system variable holds the full name of the file that
     screen images are saved to when the user presses Alt-I while in ter-
     minal mode. If this file already exists, data is appended to it.
     Telix v3.22 - SALT Programming                 System Variables    107



     _LOCAL_ECHO
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _local_echo;

     ş  Description

     The _local_echo system variable controls whether or not characters
     typed in terminal mode are echoed on the screen. If _local_echo is set
     to non-zero (TRUE), characters are echoed, otherwise they are not.


     _MDM_HANG_STR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _mdm_hang_str[19];

     ş  Description

     The _mdm_hang_str system variable holds the string that should be sent
     to the modem to hang it up when the user presses Alt-H. Note that this
     string will only be sent to the modem if Telix can't first hang-up the
     modem by turning off a signal on the serial port called the DTR line.
     This string may contain translation characters as defined in the Telix
     manual, and should be sent to the modem with the cputs_tr function.
     Maximum length is 19 characters.

     ş  See Also

     _mdm_init_str, _auto_ans_str


     _MDM_INIT_STR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _mdm_init_str[49];

     ş  Description

     The _mdm_init system variable holds the string that should be sent to
     the modem when Telix starts-up. It is usually used to make sure cer-
     tain settings in the modem are right. This string may contain transla-
     tion characters as defined in the Telix manual, and should be sent to
     the modem with the cputs_tr function. Maximum length is 49 characters.

     ş  See Also

     _auto_ans_str, _mdm_hang_str
     Telix v3.22 - SALT Programming                 System Variables    108



     _NO_CONNECT1 - _NO_CONNECT4
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _no_connect1[19];

     str _no_connect2[19];

     str _no_connect3[19];

     str _no_connect4[19];

     ş  Description

     These system variables contain the strings that Telix should scan for
     when dialing, and take to mean that a connection has not been estab-
     lished (i.e., the number was busy or there was no answer). The maximum
     length for each string is 19 characters.

     ş  See Also

     _connect_str


     _QDBAR_ON
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _qdbar_on;

     ş  Description

     If the _qdbar_on system variable is set to non-zero (TRUE), the quick
     dialing bar is shown first when Alt-D is pressed; otherwise the user
     is taken directly to the dialing directory screen.


     _REDIAL_STOP
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _redial_stop[19];

     ş  Description

     The _redial_stop system variable holds the string that should be sent
     to the modem to stop a dialing attempt. It usually just holds a Car-
     riage Return character. This string may contain translation characters
     as described in the Telix manual, and should be sent to the modem with
     the cputs_tr function. Maximum length is 19 characters.

     ş  See Also

     _dialpref, _dialpref2, _dialpref3, _dialpost
     Telix v3.22 - SALT Programming                 System Variables    109



     _SCR_CHK_KEY
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _scr_chk_key;

     ş  Description

     Between every command while executing a script file, Telix checks the
     keyboard buffer to see if the user has requested an abort. This how-
     ever gets in the way of the inkey function among others. As well, it
     is sometimes necessary to stop the user from being able to abort the
     script. If _scr_chk_key is set to zero (FALSE), Telix will no longer
     check for user aborts requests during script execution. Setting it
     back to non-zero (TRUE) will turn the checks back on. When modifying
     this variable in a script file, it is a good idea to save the old
     state in a scratch variable and restore it when done.

     ş  See Also

     inkey


     _SCRIPT_DIR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _script_dir[64];

     ş  Description

     The _script_dir system variable holds the full path of the directory
     where Telix should look for compiled script files when a script is se-
     lected to be run. When a script is selected to be run, Telix uses this
     procedure: if the name includes the drive and/or directory, only that
     path is searched. If the name includes only the filename, the current
     directory is first searched for the script file, and then the direc-
     tory pointed to by the _script_dir variable. This string should end in
     the slash character, '\'. The maximum allowed length is 64 characters.

     ş  See Also

     _telix_dir, _up_dir, _down_dir


     _SOUND_ON
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _sound_on;
     Telix v3.22 - SALT Programming                 System Variables    110



     ş  Description

     If the _sound_on system variable is set to non-zero (TRUE) sound is
     enabled in Telix, otherwise all sound is shut off.

     ş  See Also

     _alarm_on


     _STRIP_HIGH
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _strip_high;

     ş  Description

     The _strip_high system variable controls what Telix does with the high
     (most significant) bit of incoming characters while in terminal mode.
     If this variable is set to s non-zero (TRUE) value, Telix will strip
     the high bit of incoming characters.


     _SWAP_BS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _swap_bs;

     ş  Description

     The _swap_bs system variable controls what Telix sends when the
     Backspace key is pressed. If this variable is 0, Telix will send a
     Backspace character when Backspace is pressed, and a DEL character
     when Ctrl-Backspace is pressed. If this variable is set to 1, Telix
     will reverse these codes.

     ş  See Also

     _dest_bs


     _TELIX_DIR;
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _telix_dir[64];

     ş  Description

     The _telix_dir system variable holds the full path to reach the Telix
     program's base directory (e.g. 'C:\TELIX\'). Changing this variable is
     not recommended, as if a wrong value is used, Telix will probably not
     Telix v3.22 - SALT Programming                 System Variables    111



     be able to find many needed files. The maximum length is 64 charac-
     ters.

     If this variable is changed, it is imperative that a backslash char-
     acter, '\', is found at the end. Telix builds paths to many files by
     appending certain names to this string. If the slash is missing, it
     will cause many problems.

     ş  See Also

     _script_dir, _up_dir, _down_dir


     _TIME_FORMAT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _time_format;

     ş  Description

     The _time_format system variable determines what format Telix uses for
     time strings it produces. If _time_format is 0, Telix will use a 12
     hour format, otherwise a 24 hour format will be used.

     ş  See Also

     _date_format
     time


     _UP_DIR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _up_dir[64];

     ş  Description

     The _up_dir system variable holds the default upload directory name.
     When a file is to be ed (sent), if the user specifies a drive and/or
     directory in the name, the file is taken from there. However, if only
     a name is specified, the file is searched for in the directory in-
     dicated by _up_dir. This variable should end with a slash character,
     '\'. The maximum length is 64 characters.

     ş  See Also

     _down_dir
     send
     Telix v3.22 - SALT Programming                 System Variables    112



     _USAGE_FNAME
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     str _usage_fname[64];

     ş  Description

     The _usage_fname system variable holds the default Usage Log filename.
     The maximum length is 64 characters.

     ş  See Also

     _capture_fname
     usagelog


     _ZMOD_AUTO
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _zmod_auto;

     ş  Description

     The _zmod_auto system variable controls whether or not Zmodem auto-
     downloads are allowed. If Telix is in terminal mode and receives an
     auto download request Telix will ignore it if this variable is set to
     a 0 (FALSE) value (however, the user can still receive the file by
     manually selecting the Zmodem protocol from the Alt-R menu).

     ş  See Also

     _cisb_auto


     _ZMOD_RCRASH
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _zmod_rcrash;

     ş  Description

     The _zmod_rcrash system variable controls whether the Zmodem receive
     Crash Recovery (resume) option is on. If this variable is set to a
     non-zero (TRUE) value, Telix will try to resume aborted transfers dur-
     ing a Zmodem download.

     ş  See Also

     _zmod_scrash
     Telix v3.22 - SALT Programming                 System Variables    113



     _ZMOD_SCRASH
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     int _zmod_scrash;

     ş  Description

     The _zmod_scrash system variable controls whether the Zmodem send
     Crash Recovery (resume) option is on. If this variable is set to a
     non-zero (TRUE) value, Telix will try to tell the other side to resume
     aborted transfers during a Zmodem upload.

     ş  See Also

     _zmod_rcrash
     Telix v3.22                                          Appendix A    114



     6.  APPENDIX A - ASCII CHARACTER SET

     The ASCII character set consists if 128 characters, with each char-
     acter having an ASCII value, in the range of 0 to 127. The IBM PC uses
     the IBM Extended ASCII set, which adds a further 128 values, to pro-
     vide extra symbols. The following table lists the regular ASCII char-
     acter set. The first column contains the ASCII control characters,
     which can not normally be printed, and are given by name.

     Dec Hex Ctrl Name    Dec Hex Chr   Dec Hex Chr     Dec Hex Chr
       0  00  ^@  NUL      32  20         64  40  @      96  60  `
       1  01  ^A  SOH      33  21  !      65  41  A      97  61  a
       2  02  ^B  STX      34  22  "      66  42  B      98  62  b
       3  03  ^C  ETX      35  23  #      67  43  C      99  63  c
       4  04  ^D  EOT      36  24  $      68  44  D     100  64  d
       5  05  ^E  ENQ      37  25  %      69  45  E     101  65  e
       6  06  ^F  ACK      38  26  &      70  46  F     102  66  f
       7  07  ^G  BEL      39  27  '      71  47  G     103  67  g
       8  08  ^H  BS       40  28  (      72  48  H     104  68  h
       9  09  ^I  HT       41  29  )      73  49  I     105  69  i
      10  0a  ^J  LF       42  2a  *      74  4a  J     106  6a  j
      11  0b  ^K  VT       43  2b  +      75  4b  K     107  6b  k
      12  0c  ^L  FF       44  2c  ,      76  4c  L     108  6c  l
      13  0d  ^M  CR       45  2d  -      77  4d  M     109  6d  m
      14  0e  ^N  SO       46  2e  .      78  4e  N     110  6e  n
      15  0f  ^O  SI       47  2f  /      79  4f  O     111  6f  o
      16  10  ^P  DLE      48  30  0      80  50  P     112  70  p
      17  11  ^Q  DC1      49  31  1      81  51  Q     113  71  q
      18  12  ^R  DC2      50  32  2      82  52  R     114  72  r
      19  13  ^S  DC3      51  33  3      83  53  S     115  73  s
      20  14  ^T  DC4      52  34  4      84  54  T     116  74  t
      21  15  ^U  NAK      53  35  5      85  55  U     117  75  u
      22  16  ^V  SYN      54  36  6      86  56  V     118  76  v
      23  17  ^W  ETB      55  37  7      87  57  W     119  77  w
      24  18  ^X  CAN      56  38  8      88  58  X     120  78  x
      25  19  ^Y  EM       57  39  9      89  59  Y     121  79  y
      26  1a  ^Z  SUB      58  3a  :      90  5a  Z     122  7a  z
      27  1b  ^[  ESC      59  3b  ;      91  5b  [     123  7b  {
      28  1c  ^\  FS       60  3c  <      92  5c  \     124  7c  |
      29  1d  ^]  GS       61  3d  =      93  5d  ]     125  7d  }
      30  1e  ^^  RS       62  3e  >      94  5e  ^     126  7e  ~
      31  1f  ^_  US       63  3f  ?      95  5f  _     127  7f DEL
     Telix v3.22                                          Appendix B    115



     7.  APPENDIX B - EXTENDED KEY SCAN CODES

     The following chart lists keyboard scan codes for special non-ASCII
     keys, as returned by inkey and inkeyw, and used by the keyget, keyset,
     keyload, and keysave SALT functions. Normal keys which are within the
     ASCII set are listed in the preceding appendix.


     Key      Normal        w / Ctrl        w / Alt       w / Shift
            Dec     Hex    Dec     Hex    Dec     Hex    Dec     Hex
     ---------------------------------------------------------------
     F1     15104  3b00    24064  5e00    26624  6800    21504  5400
     F2     15360  3c00    24320  5f00    26880  6900    21760  5500
     F3     15616  3d00    24576  6000    27136  6a00    22016  5600
     F4     15872  3e00    24832  6100    27392  6b00    22272  5700
     F5     16128  3f00    25088  6200    27648  6c00    22528  5800
     F6     16384  4000    25344  6300    27904  6d00    22784  5900
     F7     16640  4100    25600  6400    28160  6e00    23040  5a00
     F8     16896  4200    25856  6500    28416  6f00    23296  5b00
     F9     17152  4300    26112  6600    28672  7000    23552  5c00
     F10    17408  4400    26368  6700    28928  7100    23808  5d00
     ---------------------------------------------------------------
     1                                    30720  7800
     2                                    30976  7900
     3                                    31232  7a00
     4                                    31488  7b00
     5                                    31744  7c00
     6                                    32000  7d00
     7                                    32256  7e00
     8                                    32512  7f00
     9                                    32768  8000
     0                                    33024  8100
     ---------------------------------------------------------------
     Up     18432  4800
     Down   20480  5000
     Left   19200  4b00    29440  7300
     Right  19712  4d00    29696  7400
     Home   18176  4700    30464  7700
     End    20224  4f00    29952  7500
     PgUp   18688  4900    33792  8400
     PgDn   20736  5100    30208  7600
     Ins    20992  5200
     Del    21248  5300
     ---------------------------------------------------------------
     Telix v3.22                                          Appendix C    116



     8.  APPENDIX C - COLOR VALUES

     Several SALT functions, such as pstra, use color attribute values. A
     character on the text screen has a foreground color, and a background
     color. Possible colors are numbered as follows:

                         Black          00
                         Blue           01
                         Green          02
                         Cyan           03
                         Red            04
                         Magenta        05
                         Brown          06
                         Light Grey     07
                         Dark Grey      08
                         Light Blue     09
                         Light Green    10
                         Light Cyan     11
                         Light Red      12
                         Light Magenta  13
                         Yellow         14
                         White          15

     To obtain a color attribute value for a color combination, the formula
     is

          color attribute value =

                foreground color value + (16 * background color value)

     Therefore, a Yellow character on a Blue background would have a color
     attribute value of 30 (14 + (16 * 1)).

     Telix v3.22 - SALT Programming                            Index    117


                                          _time_format.................111
                                          _up_dir......................111
     9.  INDEX                            _usage_fname.................112
                                          _zmod_auto...................112
     _add_lf.......................98     _zmod_rcrash.................112
     _alarm_on.....................98     _zmod_scrash.................113
     _answerback_str...............98     Alarm.........................22
     _asc_rcrtrans.................98     Box...........................22
     _asc_remabort.................99     Call..........................23
     _asc_rlftrans.................99     Calld.........................23
     _asc_scpacing.................99     Capture.......................24
     _asc_scrtrans.................99     Capture_stat..................25
     _asc_secho....................99     Carrier.......................25
     _asc_sexpand..................99     Cgetc.........................26
     _asc_slftrans.................99     Cgetct........................26
     _asc_slpacing.................99     Chatmode......................27
     _asc_spacechr.................99     Cinp_cnt......................27
     _asc_striph...................99     Clear_scr.....................28
     _auto_ans_str................100     Copychrs......................28
     _back_color..................100     Copystr.......................29
     _capture_fname...............100     Cputc.........................29
     _cisb_auto...................101     Cputs.........................30
     _connect_str.................101     Cputs_tr......................30
     _date_format.................101     Cursor_onoff..................31
     _dest_bs.....................102     Curtime.......................31
     _dial_pause..................102     Date..........................32
     _dial_time...................102     Delay.........................32
     _dialpost....................103     Delay_scr.....................32
     _dialpref....................103     Delchrs.......................33
     _dialpref2...................103     Dial..........................33
     _dialpref3...................103     Dos...........................34
     _dir_prog....................104     Dosfunction...................35
     _disp_free...................104     Exittelix.....................35
     _down_dir....................104     Fclearerr.....................36
     _editor......................104     Fclose........................36
     _entry_enum..................105     Fdelete.......................37
     _entry_name..................105     Feof..........................37
     _entry_num...................105     Ferror........................38
     _entry_pass..................105     Fflush........................39
     _ext_filespec................106     Fgetc.........................39
     _fore_color..................106     Fgets.........................40
     _image_file..................106     Fileattr......................40
     _local_echo..................107     Filefind......................42
     _mdm_hang_str................107     Filesize......................43
     _mdm_init_str................107     Filetime......................43
     _no_connect1.................108     Flushbuf......................45
     _no_connect2.................108     Fnstrip.......................45
     _no_connect3.................108     Fopen.........................46
     _no_connect4.................108     Fputc.........................47
     _qdbar_on....................108     Fputs.........................47
     _redial_stop.................108     Fread.........................48
     _scr_chk_key.................109     Frename.......................48
     _script_dir..................109     Fseek.........................49
     _sound_on....................109     Ftell.........................50
     _strip_high..................110     Fwrite........................50
     _swap_bs.....................110     Get_baud......................51
     _telix_dir...................110     Get_datab.....................51

     Telix v3.22 - SALT Programming                            Index    118


     Get_parity....................52     Strmaxlen.....................78
     Get_port......................52     Strpos........................78
     Get_stopb.....................53     Strposi.......................78
     Getenv........................51     Strupper......................79
     Gets..........................53     Subchr........................79
     Getsxy........................54     Subchrs.......................80
     Getx, gety....................55     Substr........................80
     Gotoxy........................55     Tday..........................81
     Hangup........................56     Terminal......................82
     Helpscreen....................56     Thour.........................81
     Inkey.........................56     Time..........................83
     Inkeyw........................56     Time_up.......................84
     Inschrs.......................57     Timer_free....................84
     Is_loaded.....................58     Timer_restart.................84
     Isalnum.......................58     Timer_start...................84
     Isalpha.......................58     Timer_total...................84
     Isascii.......................58     Tmin..........................81
     Iscntrl.......................58     Tmonth........................81
     Isdigit.......................58     Tolower.......................85
     Islower.......................58     Tone..........................85
     Isupper.......................58     Toupper.......................86
     Itos..........................59     Track.........................86
     Keyget........................59     Track_addchr..................86
     Keyload.......................60     Track_free....................86
     Keysave.......................61     Track_hit.....................86
     Keyset........................61     Transtab......................88
     Load_scr......................62     Tsec..........................81
     Loadfon.......................62     Tyear.........................81
     Newdir........................63     Unload_scr....................89
     Printc........................63     Update_term...................89
     Printer.......................64     Usage_stat....................90
     Printn........................64     Usagelog......................90
     Prints........................65     Ustamp........................91
     Printsc.......................65     Vgetchr.......................92
     Printsc_trm...................65     Vgetchrs......................92
     Pstra.........................65     Vgetchrsa.....................92
     Pstraxy.......................65     Vputchr.......................93
     Receive.......................66     Vputchrs......................94
     Redial........................67     Vputchrsa.....................94
     Run...........................68     Vrstrarea.....................95
     Scroll........................69     Vsavearea.....................95
     Send..........................69     Waitfor.......................96
     Send_brk......................70
     Set_cparams...................70
     Set_defprot...................71
     Set_port......................73
     Set_terminal..................73
     Setchr........................72
     Setchrs.......................72
     Show_directory................74
     Status_wind...................74
     Stoi..........................75
     Strcat........................75
     Strchr........................76
     Strcmpi.......................76
     Strlen........................77
     Strlower......................77































     T E L I X

     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     SIMPLE Programming Manual











                Copyright (C) 1986-94 deltaComm Development, Inc.

                              ALL RIGHTS RESERVED.




                           deltaComm Development, Inc.

                      P.O. Box 1185, Cary, NC  27512   USA

            (919)-460-4556 / (919)-460-4531 fax / (919)-481-9399 BBS
     Telix v3.22 - SIMPLE Programming                       COPYRIGHT    ii







                                Copyright Notice





     Telix is Copyright (c) 1986-1994 by deltaComm Development, Inc.

     SIMPLE is Copyright (c) 1990-1994 by deltaComm Development, Inc.

     This document is Copyright (c) 1990-1994 by deltaComm Development, Inc.

     No parts of Telix or this document may be copied in part or in whole,
     except as provided in the License in the following pages.





     Disclaimer

     deltaComm Development, Inc., makes no warranty of any kind, either
     express or implied, including but not limited to implied warranties of
     merchantability and fitness for a particular purpose, with respect to
     this software and accompanying documentation.

     IN NO EVENT SHALL DELTACOMM DEVELOPMENT, INC., BE LIABLE FOR ANY DAMAGES
     (INCLUDING DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
     LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING OUT OF THE
     USE OF OR INABILITY TO USE THIS PROGRAM, EVEN IF DELTACOMM DEVELOPMENT,
     INC., HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.



     Trademarks

     Telix is a trademark of deltaComm Development, Inc.

     SIMPLE is a trademark of deltaComm Development, Inc.

     SALT is a trademark of deltaComm Development, Inc.

     Many product names found throughout this manual are trademarks of var-
     ious companies.
     Telix v3.22 - SALT Programming                         Contents    iii










                                 C O N T E N T S



     1.  The Telix SIMPLE Language........................................1
         1.1  What Can Be Accomplished With Simple?.......................1
         1.2  Comparing SIMPLE to SALT....................................1
         1.3  Creating SIMPLE Scripts.....................................1

     2.  Syntax...........................................................3

     3.  Program Structure................................................5
         3.1  .i.Variables................................................5
         3.2  System Variables............................................5

     4.  Built-in Functions...............................................7

     5.  Program Control.................................................25
         5.1  The Waitfor Command........................................25
         5.2  The If Command.............................................26
         5.3  The Whenever Loop..........................................30

     6.  Index...........................................................33
     Telix v3.22 - SIMPLE Programming                     Introduction    1





     1.  The Telix SIMPLE Language


     Telix has a built-in programming language called SALT (Script
     Application Language for Telix).  SALT is extremely powerful, and much
     of that power is due to its semblance to the C programming language.
     Along with that power comes a degree of difficulty, however.  For
     those not comfortable in a structured programming environment such as
     SALT, a second scripting language, SIMPLE (Salt IMPLEmentation) is
     also provided.

     Simple takes a loosely structured program resembling a stream of
     English sentences and transforms it into SALT for you. No programming
     experience is necessary.  Its SIMPLE!



     1.1  What Can Be Accomplished With Simple?
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     SIMPLE scripts can be used to automate logins to bulletin boards,
     automate repetitive tasks such as mail transfers, or can be programmed
     to watch for multiple strings, offering up the proper response to each
     no matter the order in which they arrive.  SIMPLE offers you much of
     the power of SALT without the learning curve.



     1.2  Comparing SIMPLE to SALT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     SALT's complexity allows it to do much more than SIMPLE can.  For
     example, the Host+ bulletin board that comes with Telix was written
     primarily in SALT, but such a task would not be possible in SIMPLE.
     SALT offers access to most screen-related functions in Telix; SIMPLE
     offers only a pair of commands to place information on the screen.
     SALT offers full color control; SIMPLE does not.  Other differences
     make SALT the preferable language for complex scripts.

     If your copy of Telix is registered, the SIMPLE compiler, CSS can
     leave a copy of the translated script on your hard drive in SALT
     source format.  SIMPLE is primarily a tool for helping you to master
     SALT, and study of these translations are an excellent way to get
     started.



     1.3  Creating SIMPLE Scripts
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A SIMPLE script is basically a sequence of instructions for Telix to
     follow, using a loosely defined syntax.  You may use any text editor
     to produce this script file, as long as its output is normal ASCII
     text (this means that if you use your word processor, you must
     Telix v3.22 - SIMPLE Programming                     Introduction    2





     explicitly tell it to write out the file using ASCII format and not to
     embed any special codes in the file).  You may give any name you wish
     to a SIMPLE script, although we recommend that you always use the
     extension .SIM for clarity.  For example, a script to log on to the
     Telix Support BBS might be called TELIX.SIM.

     Once you have written you script file and saved it to disk, it must be
     compiled.  The program CSS.EXE included with Telix reads your "source"
     script and compiles it into a form which Telix can understand.  The
     compiled script can be loaded more quickly by Telix, and is also
     smaller.

     To compile a SIMPLE script file, type:

          CSS <SIMPLEname> <SALTname>

     <SIMPLEname> is the name of the script we are trying to compile, and
     <SALTname> is the optional name of the SALT source file to create.
     <SALTname> may only be used with registered versions of Telix.

     CSS knows the naming conventions of Telix, and expects that an input
     file ends in .SIM and an output file ends in .SLT, so you may simply
     type:

          CSS TELIX TELIX

     If you do not supply an output name, CSS assumes the output name is
     the input name followed by .SLC.  The simplest way to compile
     TELIX.SIM is:

          CSS TELIX

     The CS.EXE SALT compiler must be in the DOS path in order to use CSS.

     When the script compiler finds an error in your source file, it will
     abort the compile process and give you the line number on which the
     error occurred, as well as the type of error.  The error should then
     be fixed and the source recompiled.  This is repeated until the
     compiled detects no more errors in your script file.

     The compiled script can then be run in Telix using several methods.
     It may be run using the 'Run Script' command, as a command line
     parameter to Telix, as a linked script to a dialing directory entry
     (i.e. automatically, when you connect to a system), or from another
     script.  The first three methods are described in the Telix manual,
     while the last is described later in this manual.
     Telix v3.22 - SIMPLE Programming                           Syntax    3





     2.  Syntax


     Case is not important in command, function, and variable names. The
     only time case matters is inside a string constant (e.g., "Hello" is
     not the same string as "hello"). Whitespace (such as the space, the
     tab, the Carriage Return, or the Line Feed character) is not impor-
     tant. The script compiler does not care where you place items, so that
     you may arrange the program as you see fit. For example,

          If Online Then Send String25
          Else Dial "11" MaxOf 23 RunScript

     is equivalent to

          If Online Then
            Send String25
          Else
            Dial "11" MaxOf 23 RunScript

     or even to

          If
          Online
          Then
          Send
          String25
          Else
          Dial
          "11"
          MaxOf
          23
          RunScript

     The only time whitespace matters is when it would split up key-words
     or function name, or in a string. For example, the key-word 'whenever'
     must not be split up if it is to be recognized. The same applies to
     other key-words or function names. As well, there must be space be-
     tween the letters of a command and other letters. For example,
     'whenever' is not the same as 'wheneverabc'. In the interest of
     clarity, it is recommended that you try to make your script easy to
     understand, by indenting where appropriate, and by using space ef-
     fectively. There is no reason, for example, to put more than one
     statement on a line, even if it is perfectly legal. Another poor
     example above, however, is one where a complete line is broken up for
     no good reason.  A good example of program style can be found by
     looking at the sample SIMPLE scripts included with Telix.

     A string constant is a sequence of ASCII characters enclosed in
     quotes, for example, "Hello", "Good-bye", or "Telix".  String
     constants and their use are discussed later.
     Telix v3.22 - SIMPLE Programming                 Program Structure   5






     3.  Program Structure

     A SIMPLE script has no set format beyond a few easy-to-follow rules.
     These rules will be discussed as the apply to the individual commands
     when necessary.  Otherwise, simply add commands to your script to do
     whatever is necessary.

     It is highly recommended that you read this manual sequentially, as
     each command builds on the last.  By the end of the manual we will
     have worked into more complex examples, and will actually construct a
     script to log on to the Telix Support BBS.


     3.1  Variables
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A SIMPLE script may use up to 255 string "variables", or groups of
     characters that you can change as you see fit.  You need not do
     anything special to use a string.  Just use the word "StringXX"
     wherever you need the string, where XX is the number the string.  All
     SIMPLE strings are exactly 80 characters in length.  These will be
     referred to as StringXX variables throughout this documentation.
     Examples of StringXX use might be as follows:

     To create string number 20, and make it contain the phone number of
     the Telix BBS, you might have a line:

     Assign String20, "1-919-481-9399"

     Note that you do not have to use all 80 characters of a string.
     SIMPLE knows where to end a string if you don't fill it up.

     To create a string that contains today's date, you could simply use:

     Date String15

     If you need to use either the quote character itself in a string, or
     the carat symbol (the shitfed-6), both have special meaning in Telix,
     and must be dereferenced.  To dereference the character, precede it
     with a carat.  Examples of this are:

     Assign String1, "A quote, ^", needs a carat in front."

     Assign String2, "A carat, ^^, is represented by two carats."


     3.2  System Variables
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     SIMPLE has four system variables which may be used as part of certain
     statements.  Their use will be explained in greater detail as part of
     the commands that may access them.  These variables are:
     Telix v3.22 - SIMPLE Programming                 Program Structure   6





     BBSNumber:     This variable will contain the dialing directory entry
                    number after dialing and connecting to a system.  It
                    changes only when a connection is made.

     TransferStatus:This variable will contain the result code of a file
                    transfer performed in SIMPLE. The values of these
                    results will be explained later in the documentation as
                    part of file transfers.

     ReturnCode:    This variable is explained in detail under the If
                    directive in chapter 5.

     BBSPassword:   This variable contains your password for the system you
                    last connected to, as read from the dialing directory.
                    This variable makes it possible to write a script that
                    doesn't have to be recompiled every time you change
                    your password.  The script can just use this variable
                    instead of a String variable.  All you need to do when
                    changing your password is to edit the dialing directory
                    within Telix, and insert the new password.
     Telix v3.22 - SIMPLE Programming                Built-in Functions   7






     4.  Built-in Functions



     ALARM
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Alarm <integer>

     ş  Description

     The Alarm function causes an alarm sound (similar to the connect alarm
     of Telix) to ring for <integer> seconds.

     ş  Example

     Alarm 5



     ASSIGN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Assign <String1>, <String2>

     ş  Description

     The Assign function assigns the value of <String2> to <String1>.
     Neither string need be defined prior to an assign.  Either string may
     be a StringXX variable, and <String2> may be a literal string in
     quotes.  The comma between the two strings is required.

     ş  Example

     Assign String24, "Telix Support BBS"

     Assign String40, String24
     Telix v3.22 - SIMPLE Programming                Built-in Functions   8





     BEGIN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Begin

     ş  Description

     The Begin command denotes the start of a group of code that belongs
     together.  It is typically used to keep a group of code together in
     conjunction with If statements (see If).  Every Begin command must
     have a corresponding End command.  Begin and End commands may be
     nested within each other.

     It is recommended that indentation be used to help keep track of the
     Begin and End pairs.

     ş  See Also

     End

     ş  Example

     if Online then
       Begin
         Assign String4, "TELIX.REP"
         Alarm 3
       End


     The use of the If statement will be discussed shortly.  The example
     above is primarily to illustrate the Begin and End pairs.
     Telix v3.22 - SIMPLE Programming                Built-in Functions   9





     CAPTURELOG
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     CaptureLog (<String>/Off/On/Pause/Unpause)

     ş  Description

     The CaptureLog function controls the status of the Telix Capture file,
     in much the same was as Alt-L does from the keyboard in Telix.  You
     may turn on the capture log by passing a StringXX or constant string,
     pause, unpause, or turn off the capture file entirely.  Only one of
     these actions may be performed per CaptureLog command.  CaptureLog On
     opens the capture log to the default Telix log name.

     ş  Examples

     CaptureLog "TEMP.CAP"
     CaptureLog Pause
     CaptureLog Unpause
     CaptureLog Off

     CaptureLog On
     CaptureLog Off

     Assign String16, "TELIX.CAP"
     CaptureLog String16
     CaptureLog Off


     CHANGEDIR
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     ChangeDir <String>

     ş  Description

     The ChangeDir function provides access to the DOS "CD" command.  You
     may change to any valid directory with this command.  Invalid
     directories are simply ignored, and Telix will remain in the current
     directory.  <String> may be either a StringXX variable or a literal
     string in quotes.

     ş  Examples

     Assign String64, "D:\TELIX\DOWN"
     ChangeDir String64
     ChangeDir "C:\TELIX"
     Telix v3.22 - SIMPLE Programming               Built-in Functions   10





     CLEARSCREEN
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     ClearScreen

     ş  Description

     The ClearScreen function acts as if you had pressed Alt-C from within
     Telix.  It clears the screen of all characters other than the status
     line (if on).  ClearScreen does not accept any parameters.

     ş  Example

     ClearScreen



     DATE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Date <String>

     ş  Description

     The Date function places the current date into <String>.  <String>
     must be a StringXX-type variable.

     ş  Example

     Date String16
     Telix v3.22 - SIMPLE Programming               Built-in Functions   11





     DIAL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     dial <String> [From <String>] [MaxOf <Integer>] [RunScript]

     ş  Description

     The Dial function allows nearly complete access to the Telix dialing
     directory.  Telix can be told to dial several entries, or from a
     specific dialing directory, and can be told whether or not to run a
     linked script.

     Dial must be passed at least one parameter, a StringXX variable or
     string constant in quotes containing numbers to dial.  This string may
     contain either a list of entries by number, or a manual number
     preceded with a lowercase "m".

     If you wish, you may tell Dial from which directory these numbers are
     to be read, with an optional From directive.  From must be passed a
     StringXX or literal string constant in quotes, containing the name of
     the directory to load.  If you use a From directive, it will be valid
     throughout the rest of the script.  To avoid confusion, it is best to
     either always use From, or never use it.  If From is not used, the
     currently loaded  directory shall be the source.

     You may tell Telix to limit the number of dialing attempts to make by
     using an optional MaxOf directive.  MaxOf must be followed by an
     integer number of attempts to make.  MaxOf must come after From if
     From is present.

     You may tell Telix to execute the script linked to the dialing
     directory.  The default is not to execute such a script.  By placing
     the optional directive RunScript at the end of the Dial command, Telix
     will execute that linked script, and return control to your SIMPLE
     script upon completion.

     ş  Return Value

     The Dial function places a return value into the system variable
     ReturnCode as follows:

     If there was a connection, ReturnCode shall be the entry number in the
     dialing directory of the system connected to (or 1 for a manual
     number).

     If there was no connection established, a zero shall be placed into
     ReturnCode.

     If the string passed to dial did not contain a string that dial could
     interpret as a valid list of numbers to dial, -1 will be placed into
     ReturnCode.
     Telix v3.22 - SIMPLE Programming               Built-in Functions   12





     The use of the ReturnCode is discussed in detail as part of the If
     statement.

     ş  Examples

     The first example dials entries 1, 5, and 6 from LONGDIST.FON until it
     connects to one of them or the user presses escape.

     The second example dials the Telix Support BBS manually, up to 50
     times.

     The third example dials entries 1, 5, and 6, after loading TELIX.FON.
     If a connection is made, any script linked to the entry will be
     executed.

     Assign String24, "1 5 6"
     Assign String64, "D:\TELIX\FON\LONGDIST.FON"

     Dial String24 From String64

     Dial "m1-919-481-9399" MaxOf 50

     Dial String24 From "TELIX.FON" RunScript
     Telix v3.22 - SIMPLE Programming               Built-in Functions   13





     DOS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Dos <String> [Pause]

     ş  Description

     The Dos function allows you to shell to DOS to execute the program
     specified in <String>.  <String> may be a StringXX variable or a
     literal string in quotes.  If you wish Telix to pause prior to
     returning, simply place the optional directive Pause after the command
     to execute.

     ş  Return Value

     The Errorlevel that DOS returns after running the command is placed in
     the system variable ReturnCode.  Use of the ReturnCode is discussed
     with the If statement.  Please see your DOS manual for more
     information regarding the DOS Errorlevel.

     ş  Examples

     Assign String64, "C:\WP51\WP.EXE"
     Dos String64
     Dos "D:\UTIL\QEDIT.EXE" PauseScreen
     Telix v3.22 - SIMPLE Programming               Built-in Functions   14





     DOWNLOAD
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Download <String> [With Protocol]

     ş  Description

     The Download function acts just as if you had pressed PgDn and entered
     a protocol and filename.  It will download the file (or files if a
     batch protocol is used) indicated by <String>.  <String> may be a
     StringXX variable or a string constant in quotes.

     The Download command uses the protocol specified by the With
     directive.  If no protocol is specified, Telix will prompt for the
     protocol. Protocols allowed following the With directive are:

                         Kermit
                         Modem7
                         SeaLink
                         Telink
                         Xmodem
                         1K-Xmodem
                         G-1K-Xmodem
                         Ymodem
                         Ymodem-G
                         Zmodem

     External protocols are not available from SIMPLE.

     Remember that downloads usually need to be triggered on the remote
     site before you can receive the file.  You will usually need to Send a
     start command prior to using the Download command.  The Send command
     is described elsewhere in this manual.

     ş  Examples

     Assign String64, "D:\TELIX\DOWN\WORK\TELIX.QWK"

     Send "D;Z" Enter
     Send Enter
     Download String64 with Zmodem

     Send "D;G" Enter
     Send Enter
     Download "C:\TELIX\DOWN\TLX320-1.ZIP" With Ymodem-G
     Telix v3.22 - SIMPLE Programming               Built-in Functions   15





     EMULATE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Emulate <Protocol>

     ş  Description

     The Emulate function tells Telix to change the terminal emulation it
     is using to that specified by <Protocol>.  Allowable Emulations that
     can be passed to the Emulate command are:

                         TTY
                         ANSI-BBS
                         VT52
                         VT102
                         ANSI
                         AVATAR

     ş  Examples

     Emulate VT102
     Emulate ANSI-BBS

     END
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     End

     ş  Description

     The End command denotes the end of a group of code that belongs
     together.  It is typically used to keep a group of code together in
     conjunction with If statements (see If).  Every End command must have
     a preceding Begin command.  Begin and End commands may be nested
     within each other.

     It is recommended that indentation be used to help keep track of the
     Begin and End pairs.

     ş  Example

     if Online then
       Begin
         Send "U" Enter
         Upload "TELIX.REP" with Zmodem
       End
     Telix v3.22 - SIMPLE Programming               Built-in Functions   16





     ERASEFILE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     EraseFile <String>

     ş  Description

     The EraseFile function deletes the file specified in <String> from the
     disk.  Be careful using this command as deleted files are usually
     unrecoverable.  <String> may be a StringXX variable or a literal
     string in quotes.

     ş  Example

     Assign String24, "D:\WINDOWS\TELIX.TTF"
     EraseFile String24
     EraseFile "C:\TELIX\QWIK\TELIX.QWK"

     EXITSCRIPT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     ExitScript

     ş  Description

     The ExitScript function halts execution of the script.  It is exactly
     like pressing Escape while a script is running, and answering "Yes".

     ş  Example

     ExitScript


     EXITTELIX
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     ExitTelix

     ş  Description

     The ExitTelix function halts execution of the script, and exits Telix
     altogether.  It is exactly like pressing Alt-X and answering "Yes."

     ş  Example

     ExitTelix
     Telix v3.22 - SIMPLE Programming               Built-in Functions   17





     HANGUP
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Hangup

     ş  Description

     The Hangup function disconnects you from any system you might be
     connected to at the time.  It is exactly like pressing Alt-H from
     within Telix.

     ş  Example

     Hangup


     INPUT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Input <StringXX>, Nx

     ş  Description

     The Input function gets up Nx characters from the keyboard and places
     them into <StringXX>.  Nx is any integer value from 1 to 80, and
     <StringXX> must be a StringXX-type variable.

     No prompting is made by SIMPLE.  If you wish to prompt the user for
     the data, you will want to put the prompt up yourself, using the Show
     command, described later.

     An example of the Input routine below allows the user to input up to
     40 characters, placing them into String22:

     ş  Example

     Input String22, 40
     Telix v3.22 - SIMPLE Programming               Built-in Functions   18





     MESSAGE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Message <String>

     ş  Description

     The Message command places <String> into a centered box on the screen
     for exactly three seconds.  It is very much like what you would see in
     Telix when pressing Alt-E, for example, but it allows you to specify
     the message in the box.  <String> may be a StringXX variable or a
     literal string in quotes.

     ş  Example

     Message "Disconnecting from the Telix Support BBS"


     PRINTER
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Printer [On] [Off]

     ş  Description

     The Printer command toggles the printer mode on and off, just as Ctrl-
     @ does in Telix.  You must specify the state you wish the log to be
     in, On or Off.

     ş  Example

     Printer On

     Printer Off
     Telix v3.22 - SIMPLE Programming               Built-in Functions   19





     RUNSCRIPT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     RunScript <String>

     ş  Description

     The RunScript function loads the script specified in <String> and
     executes it.  When this new script terminates, your script will
     continue from this position.  <String> may be either a StringXX
     variable or a literal string in quotes.

     ş  Return Value

     RunScript places the value returned by the called script into the
     system variable ReturnCode. All SIMPLE scripts will return a zero.
     SALT scripts may return varying values.

     ş  Example

     RunScript "AXSTOOLS.SLC"


     SEND
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Send <String> [Enter]

     ş  Description

     The Send function sends the data contained in <String> out the comm
     port, and also to the screen.  If the keyword Enter follows <String>
     then a carriage return will be sent as well.  <String> may be a
     StringXX variable or a string constant in quotes.

     ş  Examples

     Assign String14, "Telix Support"

     Send String14
     Send "Chatting with Sysop" Enter
     Telix v3.22 - SIMPLE Programming               Built-in Functions   20





     SHELL
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Shell

     ş  Description

     The Shell function jumps to MS-DOS and allows you to execute other
     programs manually.  This is the same as pressing Alt-J within Telix.
     To return to your script from DOS, simply type "exit" at the DOS
     prompt.

     You must return to the directory you started in if things are expected
     to function properly.  If you "exit" back to Telix while in another
     directory, the current directory that scripts use will be incorrect
     and files might not be found where they should be.  Be careful using
     the Shell command.

     ş  Example

     Shell


     SHOW
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Show <String> [Enter]

     ş  Description

     The Show function places the data contained in <String> on the screen.
     If the keyword Enter follows <String> then a carriage return will be
     displayed as well.  <String> may be a StringXX variable or a string
     constant in quotes.

     Show is very similar to Send, but the data is not sent over the comm
     port.  Be careful not to confuse Show and Send.

     ş  Examples

     Assign String14, "Telix Support"

     Show String14
     Show "Chatting with Sysop" Enter
     Telix v3.22 - SIMPLE Programming               Built-in Functions   21





     SOUND
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Sound Nx, Ny

     ş  Description

     The Sound function causes tone of frequency (pitch) Nx to be played on
     the PC speaker for Ny tenths of a second.  You may want to experiment
     with values for Nx to determine acceptable frequencies.

     Script execution will not continue until the time has elapsed.

     ş  Examples

     Sound 200, 30

     Sound 500, 10


     TIME
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Time <String>

     ş  Description

     The Time function places the current time into <String>.  <String>
     must be a StringXX-type variable.

     ş  Example

     Time String16
     Telix v3.22 - SIMPLE Programming               Built-in Functions   22





     UPLOAD
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Upload <String> With Protocol

     ş  Description

     The Upload function acts just as if you had pressed PgUp and entered a
     protocol and filename.  It will upload the file (or files if a batch
     protocol is used) indicated by <String>.  <String> may be a StringXX
     variable or a string constant in quotes.

     The Upload command uses the protocol specified on the command line by
     the With operator.  If a protocol is not specified, Telix will prompt
     for the protocol.  Protocols allowed following the With directive are:

                         Kermit
                         Modem7
                         SeaLink
                         Telink
                         Xmodem
                         1K-Xmodem
                         G-1K-Xmodem
                         Ymodem
                         Ymodem-G
                         Zmodem

     External protocols are not available from SIMPLE.

     Remember that uploads usually need to be triggered on the remote site
     before you can send the file.  You will usually need to Send a start
     command prior to using the Upload command.

     ş  Examples

     Assign String64, "D:\TELIX\DOWN\WORK\TELIX.REP"

     Send "U;Z" Enter
     Send Enter
     Upload String64 with Zmodem

     Send "U;G" Enter
     Send Enter
     Upload "C:\TELIX\DOWN\TLX320-1.ZIP" With Ymodem-G
     Telix v3.22 - SIMPLE Programming               Built-in Functions   23





     USAGELOG
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     UsageLog [On] [Off]

     ş  Description

     The UsageLog command toggles the Telix usage log on and off, just as
     Alt-U does in Telix.  You must specify the state you wish the log to
     be in, On or Off.

     ş  Example

     UsageLog On

     UsageLog Off


     WAIT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     ş  Summary

     Wait Nx

     ş  Description

     The Wait function forces the script to pause for Nx seconds.

     ş  Example

     Wait 60
     Telix v3.22 - SIMPLE Programming                  Program Control   25






     5.  Program Control

     SIMPLE scripts would be less than useful if there wasn't a way to
     cause the lines to execute out of order or in repetitive blocks.
     There are three commands that can cause a SIMPLE script to take on a
     much higher degree of functionality, and thus complexity.  We will
     start with the easier ones, and then move on to the more advanced
     ones.


     5.1  The Waitfor Command
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Often when automating logons to online systems, you must enter
     information in response to a certain prompt, but it is not known
     exactly when that prompt will be ready for your input.  Waitfor
     simulates exactly what you would do when logging onto a system.  It
     waits for the prompt to appear, and then does what you tell it.

     ş  Summary

     WaitFor <String> [MaxOf Nx] Then <Command>

     <String> may be a literal string in quotes, or a StringXX variable.
     Case is not significant, and String must be no more than 40
     characters.

     The optional MaxOf directive tells the WaitFor command how long to
     wait before giving up.  Nx is a number of seconds to wait.  If MaxOf
     is defined, and Nx seconds elapse without <String> being received,
     SIMPLE skips <Command> and continues with the next command after that.

     <Command> is any valid built-in function from Chapter 4, including
     blocks surrounded by Begin and End.

     ş  Example

     Clark Development's PCBoard BBS prompts the user for various inputs,
     always in the same order.  It will prompt you for your color
     preference, your first name, your last name, and your password.  You
     can use the WaitFor command in a short SIMPLE script to automate this
     process as follows:

     Assign String1,   "Jeff"
     Assign String2,   "Woods"
     Assign String101, "first name"
     Assign String102, "last name"

     Waitfor "you want graphics" MaxOf 30 Then Send "Y Q" Enter

     Waitfor String101 MaxOf 10 Then
       Send String1 Enter
     Telix v3.22 - SIMPLE Programming                  Program Control   26





     Waitfor String102 MaxOf 10 Then Send String2 Enter
     Waitfor "ssword" MaxOf 10 Then Send BBSPassword Enter



     5.2  The If Command
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The If conditional is one of the most powerful, and thus complex
     functions of SIMPLE.  It has several options and is relatively
     freeform, but it must follow certain conventions.

     Following the explanation of the If statement, our examples will
     become more complex, as we build on what you have learned so far.

     The general purpose of an If statement is to test to see if a certain
     condition is true, and to execute certain commands if so, or
     optionally, certain commands if not.

     ş  Summary

     If [Not] <Condition> Then <Command> [ElseIf <Command>] [Else...]

     <Condition> is the quality you wish to test for being true or false.
     Conditions may be comparing strings for equality to each other,
     checking for the existence of a certain file on the disk, or for
     checking to see if a certain condition exists, such as if Telix is
     connected to a system.  You can check for the opposite condition by
     preceding <Condition> with the optional directive Not.

     The Then keyword is required for all If statements, and must follow
     the <Condition>.

     <Command> is the action that could be performed based on the result of
     the Condition.  <Command> may be any of the built-in functions of
     SIMPLE, and can even be a group of instructions marked by Begin and
     End.

     Else and ElseIf statements will be explained shortly.



     There are five predefined conditions that can be used:

     1.  Online     You may check the state of the carrier detect signal to
                    determine if you are connected to another system or
                    not.  The format of the Online conditional is:

                    If [Not] Online [=Yes] [=No] Then <Command>

                    "Yes" and "No" are optional and are only included for
                    clarity.  Examples of the Online conditional are:

                         If Online Then
     Telix v3.22 - SIMPLE Programming                  Program Control   27





                           Begin
                             Download "TELIX.QWK" With ZModem
                             EraseFile "TELIX.REP"
                           End

                         If Not Online Then
                           Dial "m1-919-481-9399" MaxOf 50

                         If Online=No Then Dial "5"


     2.  Exist      You may check for the existence of a file on the disk
                    prior to attempting an action on that file.  The format
                    of the Exist conditional is:

                    If [Not] Exist <String> Then <Command>

                    <String> may be a StringXX variable or a string
                    constant in quotes.  Examples of the Exist conditional
                    are:

                         Assign String1, "D:\TELIX\QWK\TELIX.REP"

                         If Exist String1 Then
                           Upload String1 With Zmodem

                         If Not Exist String1 Then
                           If Online Then
                             Begin
                               Download String1 With Zmodem
                               EraseFile "ANYFILE"
                             End

                    As you can see, our examples are becoming a bit more
                    complex as more commands are introduced.

     3.   BBSNumber You may check the value of this system variable to
                    determine which dialing directory entry number you last
                    connected to.  The format of the BBSNumber conditional
                    is:

                    If [Not] BBSNumber = Nx Then <Command>

                    <Nx> is any integer number.  For example, if you know
                    that the Telix Support BBS is entry # 1 in the current
                    dialing directory, and you wish to find out if we are
                    currently online with this particular system, you could
                    nest two If statements together:

                         If Online Then
                           If BBSNumber = 1 Then
                             Begin
                               EraseFile "TELIX.QWK"
                               Download "TELIX.QWK" With Zmodem
     Telix v3.22 - SIMPLE Programming                  Program Control   28





                             End

                    Note that the <Command> executed for "If Online"
                    encompasses all of the rest of the above example
                    through the End statement.  This is the reason for the
                    indentation as above.  It reminds us which lines
                    comprise the <Command> to execute if <Condition> is
                    true.

     4.   ReturnCode     

                    You may check the results of any of three other SIMPLE
                    commands with the ReturnCode system variable.  Two of
                    them we have covered, the third we shall shortly.  The
                    three commands you can check for success are Dos, Dial,
                    and RunScript.

                    The format of the ReturnCode conditional is as follows:

                    If [Not] ReturnCode = Nx Then <Command>

                    <Nx> is any integer number.  For example, if you know
                    that the program Foo.EXE returns a DOS Errorlevel of 1
                    if today is a Saturday, and an Errorlevel of 0 for
                    every other day of the week, you might want to try
                    something like the following, which would call the
                    Telix BBS to download a mail packet on Saturdays only.
                    Again, we shall try to integrate what we have learned
                    thus far into more and more complex examples:

                         Dos "Foo.EXE"
                         If ReturnCode = 1 Then
                           Begin
                             Dial "m1-919-481-9399" Maxof 50          Runsc
                         ript
                             Send "QMAIL4 D;Y"
                             Download "TELIX.QWK" With Zmodem
                             Hangup
                           End
     5.   TransferStatus

                    You may check the result of the Upload or Download
                    commands with the TransferStatus system variable.  The
                    format of a TransferStatus conditional is as follows:

                    If [Not] TransferStatus = Nx Then <Command>

                    Nx is any integer number.  The following example will
                    try to send a mail packet to the Telix BBS and if not
                    successful, will try again.  The example assumes that
                    we are already logged on and ready to upload.

                         Send "TELIX.REP" With Zmodem
     Telix v3.22 - SIMPLE Programming                  Program Control   29





                         If TransferStatus = 0 Then
                           Send "TELIX.REP" With Zmodem



     An optional Else or ElseIf command may be appended to any If statement
     to further control the flow of the program.  ElseIf and Else
     statements may be nested within one another, and infinitely deep.

     ElseIf statements indicate another If condition is to be checked in
     the case of the first If being false.  Else statements indicate the
     end of an If chain.

     The following is perfectly valid, and quite common:

                         If Online Then
                           Begin
                             Send "U;Z" Enter
                             Upload "Telix.REP" with Zmodem
                             If TransferStatus = 0 Then
                               Download "Telix.QWK" with Xmodem
                             ElseIf
                               Upload "Telix.REP" With Zmodem
                             Else
                               Hangup
                           End
                         Else
                           Dial "11"



     Note the nesting and indentation of each individual command beneath
     the If that it is a part of.  Clear, concise indentation can go a long
     way to making your scripts easier to read and write.
     Telix v3.22 - SIMPLE Programming                  Program Control   30





     5.3  The Whenever Loop
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The Whenever loop is the most powerful, and thus most complex function
     of SIMPLE.  It has several options and is relatively freeform, but it
     must follow certain conventions.

     The purpose of a Whenever loop is best explained in terms of WaitFor.
     Please be sure you understand Waitfor before continuing here.

     One of the inherent problems of WaitFor is that the order the prompts
     come in must be fixed.  One particular bulletin board can randomly
     prompt your for your birthday as verification of who you really are.
     Such a prompt renders the WaitFor command fairly useless.

     Whenever is the answer to this problem.  You may set up a group of up
     to sixteen different strings and can define the proper actions SIMPLE
     should take whenever that particular prompt comes in.  The order of
     the prompts will not matter.  If your prompt comes in, then the
     defined action will occur.  The general format of a Whenever Loop is
     defined below.

     ş  Summary

     WhenLoop
         Whenever <String> Then <Command>
         Whenever <String> Then <Command>
         Whenever <String> Then <Command>
         ....
     EndWhen

     A Whenever Loop begins with the keyword WhenLoop.

     Immediately following WhenLoop must follow a series of up to sixteen
     Whenever directives.  A whenever directive defines the <String> to
     watch for, and the <Command> to execute when the <String> is received.
     The keyword Then must appear between the two, exactly as above.

     <String> may be a StringXX variable or a string constant in quotes.
     Case is not significant, and <String> may be no longer than 40
     characters.

     Whenever <String> is received, <Command> will be executed.  The power
     of the Whenever loop lies in the fact that absolutely any SIMPLE
     construct may be used here as the <Command> (other than another
     Whenever loop).  Waitfor, If, or any built-in function from chapter 4
     may be used.

     The keyword EndWhen must follow the last Whenever directive.

     The keyword QuitWhen is used to exit from a given WhenLoop at the
     proper time.
     Telix v3.22 - SIMPLE Programming                  Program Control   31





     Using the example of a BBS which can randomly prompt for your date of
     birth during the login, lets write a script to log on to that system,
     enter the mail door, download a mail packet, and log off.

     ş  Example

     WhenLoop
       Whenever "language t"   Then Send "2"         Enter
       Whenever "first name"   Then Send "Jeff"      Enter
       Whenever "last name"    Then Send "Woods"     Enter
       Whenever "ssword"       Then Send BBSPassword Enter
       Whenever "birthday"     Then Send "03/25/66"  Enter
       Whenever "new mail"     Then Send "N Q"       Enter
       Whenever "rd Command"   Then Send "MAILDOOR"  Enter
       Whenever "mail Command" Then
         Begin
           Send "D;Y" Enter
           Waitfor "ready to Send Telix.QWK" MaxOf 300 Then
             Download "TELIX.QWK" With Zmodem
           If TransferStatus = 0 Then
             Begin
               Message "Download Not Successful!"
               Sound 200, 2
             End
           Else
             Begin
               Wait(20)
               Send "G;Y" Enter
               Hangup
               QuitWhen
             End
         End
     EndWhen

     This entire script would log you onto the BBS, and would answer the
     random birthday prompt if it appeared.

     The last Whenever directive specifies to the script that it is to do
     everything within the outermost Begin/End.  Note that the final
     whenever is in response to a prompt that indicates we are in the mail
     door.  If we are in the mail door, we send a command to start the
     download of a mail packet.  When the packet is ready, we actually
     attempt download.  Upon checking the result of the transfer, we either
     log off and exit the WhenLoop (we did what we wanted), or we make a
     beep and go back to the whenloop, which will trigger again on the mail
     Command prompt, and try to download again.

     Study the example above carefully, as it is very typical of a complete
     SIMPLE script.  Be careful when using WhenLoops as the above script
     can try over and over to download a packet.  If there is a problem
     downloading due to the BBS, you could run up quite a bill.  Advanced
     automation scripts should probably be in SALT, which allows greater
     control.
     Telix v3.22 - SIMPLE Programming                            Index   33





     6.  Index

     Alarm................................................................7
     Assign...............................................................7
     BBSNumber........................................................6, 27
     BBSPassword..........................................................6
     Begin................................................................8
     CaptureLog...........................................................9
     Carrier detect......................................................26
     ChangeDir............................................................9
     Changing your password...............................................6
     ClearScreen.........................................................10
     Compiling a script...................................................2
     Date................................................................10
     Dereferencing........................................................5
     Dial................................................................11
     Dos.................................................................13
     Download............................................................14
     Else................................................................29
     ElseIf..............................................................29
     Emulate.............................................................15
     End.................................................................15
     EndWhen.............................................................30
     EraseFile...........................................................16
     Exist...............................................................27
     ExitScript..........................................................16
     ExitTelix...........................................................16
     Hangup..............................................................17
     If..................................................................26
     Input...............................................................17
     Linked script.......................................................11
     Message.............................................................18
     Online..............................................................26
     Printer.............................................................18
     QuitWhen............................................................30
     ReturnCode...............................................6, 11, 13, 28
     RunScript...........................................................19
     SALT source..........................................................1
     Send................................................................19
     Shell...............................................................20
     Show................................................................20
     Sound...............................................................21
     Strings..............................................................5
     System variables.....................................................5
     Time................................................................21
     TransferStatus...................................................6, 28
     Upload..............................................................22
     UsageLog............................................................23
     Variables............................................................5
     Wait................................................................23
     WaitFor.............................................................25
     Whenever............................................................30
     WhenLoop............................................................30































     T E L I X

     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Reference Manual











                   Copyright (C) 1986-94 deltaComm Development, Inc.

                                ALL RIGHTS RESERVED.




                              deltaComm Development, Inc.

                        P.O. Box 1185, Cary, NC  27512   USA

              (919)-460-4556 / (919)-460-4531 fax / (919)-481-9399 BBS


     Telix v3.22                                  COPYRIGHT    ii





                                  Copyright Notice



     Telix is Copyright (c) 1986-1994 by deltaComm Development, Inc.

     SALT is Copyright (c) 1988-1994 by deltaComm Development, Inc.

     SIMPLE is Copyright (c) 1990-1994 by deltaComm Development, Inc.

     Host+ is Copyright (c) 1988-1994 by deltaComm Development, Inc.

     This document is Copyright (c) 1988-1994 by deltaComm Development, Inc.

     No parts of Telix or this document may be copied in part or in whole,
     except as provided in the License in the following pages.





                                     Disclaimer

     deltaComm Development, Inc., makes no warranty of any kind, either express
     or implied, including but not limited to implied warranties of
     merchantability and fitness for a particular purpose, with respect to this
     software and accompanying documentation.

     IN NO EVENT SHALL DELTACOMM DEVELOPMENT, INC., BE LIABLE FOR ANY DAMAGES
     (INCLUDING DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
     LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING OUT OF THE
     USE OF OR INABILITY TO USE THIS PROGRAM, EVEN IF DELTACOMM DEVELOPMENT,
     INC., HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.





                                     Trademarks

     Telix is a trademark of deltaComm Development, Inc.

     Many product names found throughout this manual are trademarks of various
     companies.


     Telix v3.22                                   License    iii



                                       LICENSE


     Telix is Copyright (c) 1986-1994 by deltaComm Development, Inc.

     Telix is not, nor has ever been, public domain or free software.

     The commercial, registered version of Telix may not be duplicated other
     than for backup purposes. A registered copy of Telix must be treated like a
     book, in that the same registered copy of Telix may not be used in more
     than one computer at the same time, just as a book may not be read by more
     than one person at the same time (without making an illegal copy).

     Users are granted a limited license to use the User Supported, trial
     version of Telix for a limited evaluation period of up to 45 days, in order
     to determine if it suits their needs. Any other use of Telix or use past
     this period requires registration.

     All users are granted a limited license to copy the User Supported version
     of Telix only for the purpose of allowing others to try it, subject to the
     above restrictions as well as these:

          Telix must be distributed in absolutely unmodified form, including ALL
          program, documentation, and other files.

          Telix may not be included with any other product for any reason
          whatsoever without a license from deltaComm Development, Inc.

          No charge or payment may be levied or accepted for Telix.

     Bulletin Board system operators may post the unregistered, User Supported
     version of Telix on their BBS for downloading by their users without
     written permission only if the above conditions are met, and only if no
     special fee is necessary to access the Telix files (a general fee to access
     the BBS is ok).

     Distributors of User Supported and Public Domain software MUST obtain
     written permission from deltaComm Development, Inc., before distributing
     Telix and must follow the above conditions, as well as other detailed at
     the time of request for a distributor's license.

     Liquidated damages assessed and collectible from distributors of User
     Supported and Public Domain software found to be distributing Telix
     without a current distributor's license in writing from deltaComm shall
     be $2 US (Two United States Dollars) *per unauthorized distributed copy*.


     Telix v3.22                                    License    iv

                       Telix Ordering/Registration Information

     Registering (buying) Telix allows you to use the product after the trial
     period. Registered Telix users get the current version of Telix on disk
     along with their own serial number, an optional printed manual, mailed
     notification of major Telix updates, and priority when calling the Telix
     Software support BBS (we guarantee no support to unregistered users). Most
     importantly, registered users know they are helping to make sure that high-
     quality software like Telix continues to be sold in this low-cost way.

     Telix registration costs $44 US / $59 CDN, and includes a 'registered' copy
     of Telix on disk. A commercial version is available for $59 US / $79 CDN.
     An evaluation disk with the current copy of Telix on it is also available
     for $10 US / $12 CDN. This is to be used to try out Telix, and does not
     include registration (the right to use Telix after the evaluation period).
     The fee covers the cost of diskette(s) and handling.

     Registered users will receive access to our online service, featuring many
     thousands of megabytes of shareware for download, access to internation
     echo mail, Internet mail, Reuters news services, weather services, stock
     quotes and more. A one year subscription to deltaComm Online, including
     access to all of the above features and more, is included with your order.

     Payment may be in the form of check, money order, or with a VISA or
     Mastercard. We also accept corporate purchase orders for amounts of $44 US
     and over. All US dollar checks must be drawn on a US bank, and all Canadian
     dollar checks must be drawn on a Canadian bank. Note that we quote
     equivalent prices in both $US and $CDN, but as we are a US company all
     credit card orders will be billed in $US, and your card statement will show
     any conversion between currencies.

     To place an order, please use the order form on the following page, or call
     us toll free from North America at (800) TLX-8000, or at (919)-460-4556
     with your VISA or Mastercard ready.

     Previously registered owners of Telix may use the 3.22 evaluation release
     at no charge, or may use the posted patch files to upgrade registered 3.12
     or later copies with serial numbers to the latest minor revision.  Users
     who have registered but do not have serial numbers (some versions of 3.11
     and prior) will need to purchase an update disk for $10 US.

     Shipping is $10 for a single copy, shipped via Second Day Air within the
     United States, and via Air Mail to other areas.

     Please call 800-859-8000 or 919-460-4556 for shipping price on orders for
     multiple copies of Telix.


     Telix v3.22                                     License    v



                          Quantity and Corporate Purchases

     The order form on the following may be used to purchase multiple copies of
     Telix, with discounts as follows:

                           1 -  10 copies     no discount
                          11 -  20 copies    10% discount
                          21 -  50 copies    15% discount
                          51 - 100 copies    22% discount
                         101 - 200 copies    30% discount
                         201 - 999 copies    40% discount
                         1000 copies plus    50% discount

     Multiple copy purchases are simply bulk purchases and include that many
     copies of Telix on disk (with optional printed manuals), as with single
     registrations. We also have available site licenses (at a slight reduction
     in price), which are based on a fixed number of copies, but in which the
     site performs the diskette duplication from master disks and labels
     supplied by us.

                                International Orders

     Telix is commercial software in Western Europe.  Telix users Telix users
     in Western Europe wishing to register must obtain Telix from our
     European distributor, ELSA GmbH, Aachen, Germany.  A German language
     version of Telix is available, and other languages are forthcoming.
     Please use the appropriate *.REG form included with this version of Telix.

     Locally owned and operated registration sites are currently in place in
     Great Britain and Germany, with others forthcoming.  Please see the file
     EUROPE.DOC for complete details about other sites that are available.

     A locally owned and operated registration site is available for users in
     Australia and New Zealand.  Use the order form in AUSSIE.REG for pricing
     and ordering information.


     Note: All prices, discounts, and registration sites are subject to change
     without notice. Discounts apply only to separate orders, they are not
     cumulative.


     Telix v3.22                                    License    vi

          If ordering from Australia or Europe, please order from your local
          dealer, using the appropriate form (*.REG) included with Telix.

          Telix version 3.22                                     #940131-322
          ------------------------------------------------------------------
          Remit to: deltaComm Development, PO Box 1185, Cary, NC  27512  USA
          ------------------------------------------------------------------
          Quan       Item                              US/CDN        Price

          ___  Telix Registration................   @ $44/$59 ea   $________
                (includes serial #, registration +
                  program and manual on disk)

          ___  Telix Commercial Version..........   @ $59/$79 ea   $________
                (same as above, plus 360 page
                  typeset manual & retail packaging)

          Disk media:  5.25" [  ]     3.5" [  ]     Low Density [  ]

                                                 Volume Discount   $(______)

          Single Copy Shipping/Handling is:   ------>   Shipping   $________
          USA:           : $10, via Second Day Air
          Elsewhere      : $10, via Air Mail

          Call 800-859-8000 for multiple copy shipping rates

                                                        Subtotal   $________

           N. Carolina residents please add State Sales Tax (6%)   $________

                                                           TOTAL   $________

          ------------------------------------------------------------------
          Payment by: ( ) Check or MO  ( ) VISA/MC  ( ) PO # ____________

              Name_______________________________________________________

           Company_______________________________________________________

           Address_______________________________________________________

                  _______________________________________________________

                      Visa/MC orders will be charged in US currency
              The following information is needed for VISA/MC card payments

             Phone(______)________________  Other(______)________________

            Card #_______________________________  Expiry date___________

          Name of cardholder_____________________________________________

          Signature______________________________________________________
                        (VISA/MC orders may also call voice: 800-TLX-8000
                        (VISA/MC orders may also fax:        919-460-4531


     Telix v3.22                                  Contents    vii




                                C O N T E N T S

     1.  Introduction.....................................................1
         1.1  Program Description.........................................1
         1.2  The Telix Philosophy........................................1
         1.3  Machine Requirements........................................2
         1.4  Telix Files.................................................2
         1.5  Start-Up Directory..........................................3

     2.  Getting Started..................................................5
         2.1  Configuring Telix with MODEMCFG.EXE.........................5
         2.2  Starting a Telix Session....................................6
         2.3  Terminal Mode...............................................7
             2.3.1  The Help/Status Screen................................7
             2.3.2  The Status Line.......................................8
         2.4  Communications Parameters...................................8
         2.5  Using Telix Menus...........................................9
         2.6  Entering and Editing Strings................................9
         2.7  Output String Translation..................................10
         2.8  Ending a Telix Session.....................................10

     3.  Program Features................................................11
         3.1  Hang-Up....................................................11
         3.2  Capture File...............................................11
         3.3  Printer....................................................11
         3.4  Usage Log..................................................11
         3.5  Scroll-Back................................................13
         3.6  Keyboard Definitions/Macros................................13
         3.7  DOS Shell..................................................14
         3.8  DOS Command................................................15
         3.9  Editor.....................................................15
         3.10  DOS and File Functions....................................15
         3.11  Screen Image..............................................16
         3.12  The Translate Table.......................................16
         3.13  Chat Mode.................................................17
         3.14  Clear Screen..............................................18
         3.15  Local Echo................................................18
         3.16  Add Line Feeds............................................18
         3.17  Break Signal..............................................18
         3.18  DOORWAY Mode..............................................18
         3.19  Miscellaneous Functions...................................19
             3.19.1  Sending Modem Strings...............................19
             3.19.2  Setting the Screen Size.............................19

     4.  The Dialing Directory...........................................21
         4.1  The Display................................................21
         4.2  Editing an Entry...........................................23
         4.3  Adding Entries.............................................23
         4.4  Clearing Entries...........................................24
         4.5  Finding an Entry...........................................24
         4.6  Dialing....................................................24


     Telix v3.22                                 Contents    viii




         4.7  Other Functions............................................25
             4.7.1  Inserting Blank Entries..............................25
             4.7.2  Deleting Entries.....................................26
             4.7.3  Revising Long Distance Codes.........................26
             4.7.4  Creating a Dialing Directory.........................26
             4.7.5  Loading a Dialing directory..........................26
             4.7.6  Printing the Dialing directory.......................26
         4.8  Automatic Queue Redial.....................................27
         4.9  The Quick Dial Bar.........................................28

     5.  File Transfers..................................................29
         5.1  Downloading (Receiving) Files..............................29
         5.2  Uploading (Sending) Files..................................30
         5.3  File Transfer Protocols....................................32
         5.4  Which One to Use...........................................33

     6.  Telix Configuration Menu........................................35
         6.1  Screen and Color Settings..................................35
         6.2  Terminal Options...........................................36
         6.3  General Settings...........................................38
         6.4  Modem and Dialing settings.................................40
         6.5  Filenames and Path Settings................................43
         6.6  ASCII Transfers............................................44
         6.7  Protocol options...........................................45
         6.8  Kermit Transfers...........................................48
         6.9  Comm Port Setup............................................48
         6.10  Saving Changes and Leaving................................49

     7.  Terminal Emulation..............................................51
         7.1  TTY........................................................51
         7.2  ANSI-BBS...................................................51
         7.3  ANSI.......................................................51
         7.4  VT102......................................................52
         7.5  VT52.......................................................53

     8.  Using Script Files..............................................55
         8.1 The Scripting Languages.....................................55
         8.2 SALT........................................................55
         8.3 SIMPLE......................................................56
         8.4 Learning a Script...........................................56

     9.  Host Mode.......................................................59

     10. Command Summary.................................................65
     11. Troubleshooting.................................................67
     12. Product Support.................................................79
     13. External Protocols..............................................81
     14. File FormatS....................................................83

     15. Index...........................................................85


     Telix v3.22                                          Introduction    1




     1.  INTRODUCTION


     1.1  Program Description
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix is a full-featured communications program for PCs running the
     PC/MS-DOS operating system, that is able to meet the needs of almost
     any user. Telix features include:

        ş An extensive range of built-in file transfer protocols, including
          Zmodem, Compuserve Quick B, Xmodem, Xmodem-1k, Xmodem-1k-g, Ymo-
          dem (TRUE), Ymodem-g, Kermit, SEAlink, Telink, Modem7, and ASCII.
          Telix allows up to five 'external' protocols to be defined and
          called from within Telix. In this way, almost any kind of file
          transfer is possible from within Telix.

        ş Powerful multiple dialing directories, holding up to 1000 entries
          each. An entry contains many pieces of information required for
          communicating with remote services, such as the phone number and
          communications parameters.

        ş Automatic queue redialing for hard-to-reach numbers.

        ş Reliable DEC VT100/102 and VT52 terminal emulation. Keys may be
          redefined by the user.

        ş Extensive SALT script language which allows Telix to perform au-
          tomated logons and many more complicated functions. As an example
          of the power of script files, the Telix Host Mode is written in
          the SALT script language.

        ş Full access to DOS including a DOS shell, a DOS Command option,
          and full path support.

        ş A very advanced Host mode which can be run as a standalone
          bulletin board system.

        ş A Chat Mode, keyboard macros, a scroll-back buffer, session cap-
          ture, usage log, translate table, and a variety of other fea-
          tures, detailed in this manual. Above all however, Telix is FAST,
          and has a powerful, friendly, user interface.


     1.2  The Telix Philosophy
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     When Telix was written, a basic idea was kept in mind. It was felt
     that a powerful program could be simple to operate, with no loss of
     speed in order to achieve this ease of use.


     Telix v3.22                                          Introduction    2



     1.3  Machine Requirements
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix will run on an IBM PC, XT, AT, PS/2, or true compatible with one
     hard drive and one floppy drive, or two floppy drives, and with at
     least 205k of free memory. This is memory available after DOS has been
     loaded. For a few functions, such as the DOS Shell, more memory is
     helpful. Telix will support up to 8 defined comm ports (COM1 through
     COM4 are predefined), any number of disk drives, and a printer con-
     nected to the parallel port.

     To get full use of Telix your modem must meet certain standards as
     well, especially for the Host Mode script. The Carrier Detect signal
     should not be forced high (on) by the modem, so that Telix can tell
     when you are online. This is usually controlled by the setting of a
     dip switch on the modem, or a modem command (often &C1). The DTR (Data
     Terminal Ready) signal should not be ignored by the modem (&D2 in many
     cases, or switch controlled).


     1.4  Telix Files
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix comes with a number of files and creates more in its normal op-
     eration. Some files included in the Telix package are:

          TELIX.EXE           The Telix program itself
          TELIX.DOC           The Telix program reference manual
          MODEMCFG.EXE        The Telix modem configuration program
          TELIX.MDM           Data file for MODEMCFG
          CS.EXE              The SALT script language compiler
          CSS.EXE             The SIMPLE script language compiler
          SALT.DOC            The SALT script language reference
          SIMPLE.DOC          The SIMPLE script language reference
          QDHOST.SLT          The QDHost Mode script file (source)
          QDHOST.SLC          The QDHost Mode script file (compiled)
          QDCONFIG.SLT        QDHost Mode configuration script (source)
          QDCONFIG.SLC        QDHost Mode config. script (compiled)
          HOSTPLUS.DAT        Compressed HOSTPLUS advanced BBS
          HOSTPLUS.DOC        The HOSTPLUS program reference manual
          HINSTALL.EXE        The HOSTPLUS installation program
          *.KEY               The various key definition files for the ter-
                              minals supported by Telix

     If your copy of Telix came in PKZip format then these files should be
     accompanied by a PKZip authenticity verification number of MUP129
     bearing a deltaComm message. If your .ZIP files do not carry the PKZip
     authenticity stamp, you should question their integrity, or upgrade to
     PKZip 1.10 to insure that the AV stamps are there. PKZip 1.02 or
     earlier cannot display AV information.

     Files (optionally) created and used by Telix include:

          TELIX.FON           The default dialing directory file


     Telix v3.22                                          Introduction    3



          TELIX.LD            The Long Distance Codes file
          TELIX.CAP           The default session capture file
          TELIX.IMG           The screen image save file
          TELIX.KEY           The default user key macros definition file
          QDHOST.CNF          The Host Mode configuration file

     Telix at one time or another can have a number of files open, espe-
     cially during Host Mode and a few other instances. If Telix tells you
     it is having problems opening files then it is probable that including
     the line:

          files=20

     in your CONFIG.SYS file could clear up the problem. This allows DOS to
     open more files (the default is 'files=8'). For more information on
     the CONFIG.SYS file see your DOS manual.


     1.5  Start-Up Directory
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     When you run Telix it will remember the disk directory you ran it
     from. After this point, even if you have changed the current directory
     with the 'Change directory' command, Telix will know that it should
     look for its program files on the start-up directory. Some files will
     also be written on this directory unless you specify another.

     If you set the environment variable 'TELIX', Telix will have another
     (even better) way of knowing where to look for its files. The command
     form at the DOS prompt is:

          set TELIX=pathname

     where pathname is a the legal DOS pathname of the directory in which
     the Telix files are located. Do not leave any space between the '='
     and the arguments. For example, if you used 'set TELIX=C:\TELIX\',
     Telix would know to look for its files in the Telix directory on drive
     C. This way, no matter where you run it from, Telix will always be
     able to find its files. To reset this environment variable to nothing
     the command is:

          set TELIX=

     For more information on environment variables see your PC/MS-DOS man-
     ual.


     Telix v3.22                                       Getting Started    5





     2.  GETTING STARTED



     2.1  Configuring Telix with MODEMCFG.EXE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix has a complete setup program that will create or modify your ex-
     isting configuration to work best with your modem, and will modify
     your modem settings to work best with Telix. To run the configuration
     program, from the DOS prompt type:

          MODEMCFG

     The files TELIX.MDM and MODEMCFG.EXE must be in the same subdirectory
     as TELIX.EXE for proper use. If INSTALL.EXE was used properly, or all
     .ZIP files were extracted into the same subdirectory, this will be the
     case. The TELIX.MDM modem information file will be updated on the
     Telix BBS regularly to handle changes in modem strings and to add new
     modems and models.

     Throughout the menus of MODEMCFG.EXE, you may use the arrow keys to
     move in a given direction, Tab and Shift-Tab to move right or left,
     Home, End, PgUp and PgDn to move up or down, or press the first letter
     of the menu item to move to the next item beginning with that letter.

     A menu will be shown from which you should select the manufacturer of
     your modem. If your modem manufacturer is not one of the options, se-
     lect generic, or contact deltaComm to have it added.

     Under each manufacturer is a list of their modems. Again pick the ap-
     propriate modem.

     You will be shown a list of the settings for the modem itself, includ-
     ing any switch settings if known. Please write down the switch set-
     tings as you will need them later. When asked if you wish to configure
     your modem, answer by pressing the 'Y' key. MODEMCFG will ask you for
     your comm port as well. Please refer to your modem manual for this in-
     formation.

     If all goes well a successful configuration message will be shown. If
     there is a problem, insure the proper comm port is specified and try
     again. If the problem persists, contact deltaComm.

     A similar setup procedure will take place for TELIX.CNF, the configu-
     ration file for Telix itself. MODEMCFG will only change the values
     pertinent to the performance of the modem in existing configurations.
     Any existing color values or preferences will be left intact. If
     TELIX.CNF does not exist, MODEMCFG will create it.


     Telix v3.22                                       Getting Started    6



     The exit screen of MODEMCFG contains final instructions on how to make
     best use out of the setup that has been written for you. Please make a
     note of these for later referral.

     You are now ready for your first Telix session.


     2.2  Starting a Telix Session
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To start the Telix program type the following while at the DOS prompt:

          Telix [O][Q][B][D] [Sfilename] [Cfilename] [Ffilename]

     The letters in the square brackets are optional command line switches
     affecting what Telix will do upon start-up. The square brackets should
     not be entered. The order and case of the options does not matter but
     they must be separated by at least one blank.

     Specifying the 'O' option upon start-up tells Telix that you are al-
     ready online (connected to a host systems), and that it should not try
     to initialize the modem.

     The 'Q' option in the command line chooses quiet mode for the current
     session. When quiet mode is on Telix will not sound any alarms (e.g.,
     when a file transfer is over), no matter what the default setting for
     alarms is. This is useful for those late night sessions. Any bell
     characters sent by the remote system are still sounded however.

     Specifying 'B' in the command line forces Telix to use the PC's BIOS
     for all screen write operations, whatever the default setting for
     screen writes might be. This is useful when you want to run Telix in a
     multi-tasking environment such as Topview or MS Windows for just one
     session. Note that Telix is DESQview aware, so you do not have to use
     this mode for DESQview.

     The 'D' option forces Telix to drop RTS during disk writes for those
     systems exhibiting frequent errors at rhythmic intervals while
     downloading.  This is called slow handshaking.

     The 'S' option indicates that a script file (explained elsewhere) is
     to be run immediately upon start-up. The 'S' should be followed imme-
     diately (no blanks) by the name of the script file to execute.

     The 'C' option indicates that another Telix configuration file than
     the standard TELIX.CNF should be used. If it doesn't exist, it will be
     created. In this way, you may have multiple configurations for Telix.
     The name of the configuration file should immediately follow the 'C',
     and should include the extension.

     The 'F' option indicates that another dialing directory (FON) file
     than the default TELIX.FON should be loaded at start-up. The name
     should immediately follow the 'F'. Note that another dialing directory


     Telix v3.22                                       Getting Started    7



     file may also be loaded from within Telix (in the dialing directory
     screen).


     Upon starting, Telix will display a title screen for a period of 25
     seconds or until you press a key. Please read the message on the title
     screen carefully. After you are past the title screen, you will be in
     'terminal mode' unless Telix can't find the configuration file
     (usually  TELIX.CNF), in which case it will ask you a few questions
     about your machine and modem, and then will write a configuration file
     for you.


     2.3  Terminal Mode
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Immediately after starting Telix, and for most of the time while using
     it, you will be in Telix's terminal mode. While in this mode any nor-
     mal (ASCII) characters you type will be sent to the modem port, and
     any incoming characters will be printed on the screen. It is from the
     terminal mode that most Telix commands are initiated. Most commands
     are selected by pressing two keys at the same time. For example, to
     access the dialing directory, you would press Alt-D. That is, while
     holding down the Alt key, you press the D key.


     2.3.1  The Help/Status Screen

     While in terminal mode, pressing the Alt-Z sequence will switch you to
     a help screen showing you a summary of all the available commands. If
     the key for a command is pressed while the help screen is still on,
     the screen will be turned off and the command will be executed.

     On the bottom of the help/status screen is some information regarding
     some current settings and the status of the current connection, as
     follows (in slightly compressed form).

         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸
         ³ Time..10:39:00   Online .... No      ³ Capture...Off       ³
         ³ Date..06-29-91                       ³ Printer...Off       ³
         ³ Baud..2400       Terminal .. VT102   ³ Script....None      ³
         ³ Comm..N,8,1      Port ...... COM1    ³ Reg. Key..TELIX.KEY ³
         ³ Echo..Off        Add LF .... Off     ³ Dial Dir..TELIX.FON ³
         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾

     Items included are: the current time and date, the connect status, the
     elapsed time for the call in progress, the current communications
     parameters, the state of the capture file and printer, the currently
     executing script file (if there is one),  the current dialing direc-
     tory, the current keyboard macro definition file, and a few other
     items.


     Telix v3.22                                       Getting Started    8



     2.3.2  The Status Line

     Telix has an optional status line which may be displayed at the bottom
     or top of the screen (it may be controlled via the Telix Configuration
     Menu, or toggled on/off by pressing Alt-8 in terminal Mode). The sta-
     tus line displays the current communications setting such as baud rate
     and parity, the state of the Capture file, whether or not the printer
     is on, the currently executing script file (scripts are explained
     elsewhere), and whether Telix is On-line or Off-line. The following is
     an example of a status line, and what each section can contain:

     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
     ³ The Status Line example screen display can not be shown in the DOC  ³
     ³        file format Telix manual, due to width limitations.          ³                                                                     ³
     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ




     2.4  Communications Parameters

     Pressing Alt-P allows you to change the Communications Parameters.
     This is the format in which Telix sends data over the modem, and ex-
     pects to receive it in. After pressing Alt-P a window is displayed
     with the current parameters at the top, and the options in the rest of
     the window. To change a value press the letter or number of the set-
     ting you want.

                     ÕÍµ Comm Parameters ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸
                     ³                                    ³
                     ³ Current: 2400,N,8,1,COM1           ³
                     ³                                    ³
                     ³  Speed         Parity         Data ³
                     ³                                    ³
                     ³ A: 300         J: None        Q: 7 ³
                     ³ B: 1200        K: Even        R: 8 ³
                     ³ C: 2400        L: Odd              ³
                     ³ D: 4800        M: Mark        Stop ³
                     ³ E: 9600        N: Space            ³
                     ³ F: 19200                      S: 1 ³
                     ³ F: 38400                      T: 2 ³
                     ³ F: 57600       O: N-8-1            ³
                     ³ F: 115200      P: E-7-1            ³
                     ³                                    ³
                     ³ 1: COM1  3: COM3  5: COM5  7: COM7 ³
                     ³ 2: COM2  4: COM4  6: COM6  8: COM8 ³
                     ³                                    ³
                     ³ Choice, or <Enter> to exit?        ³
                     ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾

     There are a number of parameters that can be changed. The baud rate is
     the speed that you want to communicate at (it should really be called
     bps rate, which stands for bits per second). 1200 baud and 2400 baud
     are the two most common speeds in use, and represent about 120 and 240


     Telix v3.22                                       Getting Started    9



     characters per second, respectively. Baud rates all the way up to
     115200 are supported by Telix, however a fast PC is needed for the
     higher rates (a stock 4.77 MHz XT can handle 9600 and possibly 19200
     baud, higher rates need an AT class computer). Parity is a form of er-
     ror checking. Allowable parities are None, Even, and Odd. Data bits is
     the number of bits (a bit is a one or a zero in a computer) in each
     character. Allowable values are 7 and 8. Finally, the number of stop
     bits parameter can be set to either 1 or 2. The most common format for
     BBS use is a baud rate of 1200 or 2400, 8 data bits, no parity, and 1
     stop bit. On many large networks such as Compuserve, the data format
     used is E71.

     The communications parameters menu also allows you to select the com-
     munications port you want to use. Note that by default only the first
     four comm ports are defined (the last four are duplicates of COM1).

     Changing any parameters changes them only for the duration of the cur-
     rent communications session. If you want a set of parameters to be the
     default when you start Telix, use the Telix Configuration Menu, Alt-O.


     2.5  Using Telix Menus
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Whenever Telix must ask you to select an item from a group of options,
     it uses the same basic type of menu. The options will be arranged ver-
     tically for a vertically oriented menu, and next to each other for a
     horizontally oriented menu. There are two ways to select the item that
     you want. Each menu option has one of its letters in bold text; press-
     ing that letter will select the corresponding option. As well, one op-
     tion in the menu is always highlighted in inverse video. The arrow
     keys on the PC's keypad will move the highlight up and down or left
     and right. When the highlight is over the option you want to select,
     press Carriage Return, or Enter.


     2.6  Entering and Editing Strings
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     While using Telix, you will often have to enter a string of charac-
     ters, for example a filename, or a list of numbers to dial. Telix
     gives you full editing powers when you enter a string. As you type
     characters, you may use the Backspace key to delete previously entered
     characters. The Left and Right arrow keys allow you to move back and
     forth in the string to edit what you have entered. By default, any
     characters you enter overwrite any that are already there. Pressing
     the Ins key will place Telix in insert mode, and any existing charac-
     ters are pushed ahead as you type. Pressing Ins once more places you
     back in overwrite mode.  Home and End place the cursor at the
     beginning or end of the string, respectively. Finally, pressing the
     Ctrl-Left and Ctrl-Right arrow keys allows you to move back and forth
     in the string by increments of a word.


     Telix v3.22                                      Getting Started    10



     2.7  Output String Translation
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     In quite a few instances while using Telix, the user must specify a
     string to be sent out over the modem port. Sometimes this string must
     contain characters which can not be printed on the screen, for exam-
     ple, control characters, and even pauses. There has to be a way of in-
     dicating these special characters, and it is done through the use of
     special characters called translation characters. When these transla-
     tion characters are encountered in an output string they are trans-
     lated into other characters. The default translation characters are:

          ^    when this character is encountered in an output string
               it will make the following character a control charac-
               ter. For example, ^A will send out the code for Con-
               trol-A. A few common control characters are ^M, which
               is the Carriage Return character, ^J, which is the Line
               Feed character, and ^[, which is the Esc character. To
               send out the ^ character itself, use two ^ characters,
               as explained above.

          ~    when this character is encountered it will make Telix
               pause for 1/2 a second. Note that the only way to send
               a ~ character out is to use the sequence ^~ using two ~
               characters in a row will simply make Telix pause twice.

     There is one thing to keep in mind. These characters are only trans-
     lated on strings sent out to the modem, for example, the dialing pre-
     fix, the hang-up string, a keyboard macro, the modem initialization
     string, and a few other cases.


     2.8  Ending a Telix Session
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To exit the Telix program, press Alt-X. Telix will ask you if you re-
     ally want to exit. Press 'Y' to confirm the exit, 'N' or Esc to return
     to Telix.

     If Telix detects that you are still on-line (connected to another com-
     puter), it will also present a third option, 'Hang-Up'. If this option
     is selected, Telix will make sure that the connection is broken before
     exiting.


     Telix v3.22                                     Program Features    11





     3.  PROGRAM FEATURES


     3.1  Hang-Up
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-H will make Telix attempt to hang-up the modem. Unless
     this is disabled in the configuration Menu, Telix first attempts to
     hang up the modem by turning off a signal on the RS-232 port called
     the DTR line. This works with most modems. If this doesn't work, Telix
     then sends the hang-up string defined in the Configuration Menu to the
     modem. If this still doesn't work and Telix detects that you are still
     online, Telix will warn you. If Telix is consistently telling you that
     hang-ups fail even when they work, your modem is almost certainly
     overriding the Carrier Detect signal. See the appendix on common prob-
     lems for the solution to this.


     3.2  Capture File
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix allows you to capture (record) data coming in from the comm port
     and printed on the terminal screen, to a disk file. To open the cap-
     ture file, press Alt-L. You will be prompted for the filename to save
     the log to. Press Return to use the default filename. All data is
     added to the end of the file if it exists already. To turn off the log
     press Alt-L again and select the "Close" option. To temporarily pause
     capturing data to the file, press Alt-L and select the "Pause" option.
     While capturing is paused, any characters received are not saved to
     the file. To then un-pause capturing, press Alt-L and select the
     "Unpause" option.


     3.3  Printer
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The printer may be toggled on and off by pressing Ctrl-@ to record in-
     formation coming in from the comm port and printed on the terminal
     screen. If Telix hangs when printer logging is turned on, the printer
     is turned off, and should be turned on to proceed.


     3.4  Usage Log
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix allows a usage log to be opened, which keeps track of calls you
     make and file that you transfer. This is handy for keeping a record of
     your long distance calls, for example. The Usage Log is toggled on and
     off with the Alt-U key. If it is currently closed, you are prompted
     for the name to open it to (TELIX.USE is the default). If it is cur-
     rently opened, then it is closed. You may also set the Usage Log to be
     opened by default at Telix start-up (via the Configuration Menu).


     Telix v3.22                                     Program Features    12



     Following is a sample portion of a log:

          91-03-17  00:12:41  Telix Usage Log Created.
          92-12-24  00:12:41  Telix Usage Log Opened.
          92-12-24  00:13:06  Connected with : TBoard
          92-12-24  00:13:06  ++ At phone #  : 241-0241
          92-12-24  00:13:06  ++ Settings    : 2400,N,8,1
          92-12-24  00:14:53  Hangup command selected.
          92-12-24  00:16:25  Connected with : Telix Support BBS
          92-12-24  00:16:25  ++ At phone #  : 1-919-481-9399
          92-12-24  00:16:25  ++ Settings    : 2400,N,8,1
          92-12-24  00:17:17  Download using Telink protocol.
          92-12-24  00:17:19  ++ File : D:\DL\ZTC100.ZIP
          92-12-24  00:41:09  ++ Chars per second : 165
          92-12-24  00:41:11  ++ File : D:\DL\SRC100.ZIP
          92-12-24  00:58:26  ++ Chars per second : 165
          92-12-24  00:58:28  ++ File : D:\DL\OPT100.ZIP
          92-12-24  01:22:54  ++ Chars per second : 165
          92-12-24  01:23:11  Hangup command selected.
          92-12-24  01:23:12  Exiting Telix.
          92-12-24  01:23:12  Telix Usage Log Closed.

     The log is quite simple in form and easy to understand. Lines that
     start with '++' are a continuation of previous lines. Here is a
     listing of possible entries:

          Key       Log Entry
          ----      -----------------------------------------------
          Alt-U     Telix Usage Log Created.
                    Telix Usage Log Opened.
                    Telix Usage Log Closed.

          Alt-D     Connected with : (entry name)
                    ++ At phone #  : (phone number)
                    ++ Settings    : (comm settings)

          Alt-R     Download using (name) protocol.
                    ++ File : (pathname)
                    ++ Chars per second : (CPS)
                    ++ Transfer aborted.

          Alt-S     Upload using (name) protocol.
                    ++ File: (pathname)
                    ++ Chars per second : (CPS)
                    ++ Transfer aborted.

          Alt-H     Hangup command selected.
          Alt-X     Exiting Telix.

     The entries on the right are related to the commands shown on the
     left. Note that a script file has the ability to stamp text into the
     Usage Log, so other entries are possible.


     Telix v3.22                                     Program Features    13



     3.5  Scroll-Back
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To review past screens of characters press Alt-B. You will be in the
     Scroll-Back display. You will be able to move through the last one
     thousand to 64 thousand characters received (depending on the setting
     in the Configuration Menu) by using the arrow keys to scroll line by
     line, the Home and End keys to go to the beginning and end of the
     buffer, and the PgUp and PgDn keys to scroll through the buffer a page
     at a time.

     To find a certain string in the buffer press 'F'. Telix will prompt
     for the string to search for. If the string is found the line contain-
     ing it will be placed at the top of the screen. To search for the same
     string as last time press Return when asked for the search string.

     To save the screen image to a file press 'I'. Telix will prompt you
     for the file to save the image to. If the file already exists, the
     screen image will be appended to it. To print out a screen image to
     your printer press Shift-PrtSc.


     3.6  Keyboard Definitions/Macros
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix will let you assign text to a key so that it is sent to the comm
     port when that key is pressed. This is usually called a keyboard
     macro, and is useful in saving keystrokes (for example, you can assign
     your name to a key). Telix actually keeps two key definitions tables
     in memory at all times (each table holds the text assigned to each
     key), the user table and the terminal table. The terminal table is
     used for terminal emulation key assignments. When Telix is told to
     start emulating a certain terminal, it loads into this table defini-
     tions specific to that terminal. Therefore, for each terminal there is
     a key definition file which is loaded as needed. The user table on the
     other hand is relatively constant. You might want to assign your name
     to the Atl-1 key for example. This kind of definition would be put in
     the user table.

     When a key is pressed, Telix follows this procedure: If there is a
     definition for that key in the terminal key table, send that text;
     otherwise if there is a definition in the user table for that key,
     send the text; otherwise if the key represents an ASCII value, send
     that value; otherwise if the key is a Telix command (like Alt-D), per-
     form that command.

     The keyboard definition/macro editor is entered with the Alt-K key se-
     quence from terminal mode. Telix will ask you if you want to access
     the user or the terminal key definition table. Unless you wanted to
     modify the keys for a specific terminal, you would always select the
     user table. Telix will present the following menu:

               Load  Save  Clear  Display  displayKey  Edit  eXit


     Telix v3.22                                     Program Features    14



     To load definitions from a previously saved key definition file into
     memory, select the 'Load' option. Telix will ask for the name of the
     key definition file (and use the extension '.KEY' if none is speci-
     fied). Current key assignments will be cleared. The standard key defi-
     nition file is "TELIX.KEY" and is loaded at start-up if it exists.

     To save the current key definitions to a disk file, select the 'Save'
     option. Telix will ask what file to save them to, and use the exten-
     sion '.KEY' if none is specified.

     Selecting 'Clear' will clear all the current key definitions in this
     table.

     Selecting 'Display' will show what text is assigned to each key.

     Selecting 'displayKey' will allow you to look at what is assigned to
     one specific key, by pressing it when prompted.

     To actually enter or edit the text assigned to a key, select 'Edit'.
     Telix will print the existing definition and allow you to edit it. En-
     ter the characters that you want the key to send when pressed. Control
     characters and pauses can be included in the definition in the manner
     described previously in the manual under Output String Translation.
     Remember that if you make any changes they will be lost when you exit
     Telix unless you use the 'Save' option as described above, to save
     them to disk.

     Telix also allows you to run a script file when a certain function key
     is pressed. If a function key definition has an '@' character as its
     first character Telix will assume the rest of the definition is the
     name of a script file, and will try to execute it. For example press-
     ing the function key whose definition is '@logon' would run the script
     file called LOGON.SLC. If you really want to send out an '@' character
     as the first character in the key definition, then use two of them in-
     stead. e.g., the definition '@@Hello' would send out '@Hello'.


     3.7  DOS Shell
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-J will let you jump to a DOS shell. You will see the DOS
     prompt and will be able execute any DOS command, for example 'dir'. If
     there is enough memory left, you can even run programs. There is an
     option described later in the configuration section that allows you to
     free up most of the computer's memory when shelling to DOS.  To exit
     the DOS shell type 'exit' and press Return. You will be back in Telix
     with the screen undisturbed from before your jump to the shell. In
     order to run the DOS shell, there must be enough memory left, and
     Telix must be able to find the file called COMMAND.COM. If either of
     these requirements is not met, Telix will tell you so. (The file
     COMMAND.COM is the DOS command interpreter. It is usually pointed to
     by the DOS environment variable COMSPEC. See your DOS manual for more
     information). If you run a serial port related program in the shell,
     there is a good chance that it will re-initialize the com port and


     Telix v3.22                                     Program Features    15



     another piece of information called the com interrupt vector. If this
     happens, Telix will notice and re-initialize the port to the old
     values when you return from the shell.


     3.8  DOS Command
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-V allows you to enter one DOS command or filename to run.
     This command is then executed and control is returned to Telix. As can
     be seen this is similar to the DOS shell, but is useful when you have
     only one command to enter. There are many uses for this command. For
     example, if your file viewing utility is called 'List', you could
     press Alt-V and then enter 'List TELIX.DOC'. This would load your file
     view utility and let you look at the TELIX.DOC file. After you termi-
     nated this program you would be back in Telix. Any DOS command is le-
     gal, for example 'copy a:*.ZIP c:', or 'ren data dat1'. If for some
     reason you might want Telix to pause after the command is finished,
     add a ';' character to the end of the command string, for example
     'type TELIX.DOC;'. This stops the last screen-full typed from
     scrolling by too quickly when control returns to Telix.


     3.9  Editor
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-A will allow you to run your favorite editor from within
     Telix. In order to do this you must go to the Configuration Menu and
     supply the full name and path of your editor in the 'Filenames and
     paths' area. As well, there must be enough memory left, and if you
     specified a batch file to be run, Telix must be able to find the DOS
     command processor COMMAND.COM.


     3.10  DOS and File Functions
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-F will display a menu of some common DOS operations. For
     convenience, a few commands available elsewhere have been included.

                           ÕÍµ DOS Functions ÆÍÍÍÍÍÍ¸
                           ³                        ³
                           ³ Jump to DOS shell      ³
                           ³ Files directory        ³
                           ³ Change drive/directory ³
                           ³ Delete file            ³
                           ³ DOS command            ³
                           ³ Run editor             ³
                           ³ Exit                   ³
                           ³                        ³
                           ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾


     Telix v3.22                                     Program Features    16




          Jump to DOS Shell

          This performs the same function as the Alt-J command.

          Files Directory

          Telix will prompt you for the optional filespec, for example,
          *.DOC. If you want to list all the files in the current directory
          then just press Return. Telix will then do one of two things. If
          you have defined a directory program to use (in the Configuration
          Menu), Telix will run it. Otherwise Telix will use its own inter-
          nal directory program, which is similar to the DOS 'dir' command
          but also displays the time it would take to transfer each file
          shown. The time is correct for the current default upload file
          transfer protocol.

          Change Drive/Directory

          The current directory is displayed and you are asked to enter a
          new one. You can enter a new drive, a new directory, or both.
          This will become the current directory. Note that this is
          slightly different from the DOS 'chdir' command.

          Delete File

          You are asked to enter the filename of the file to delete.

          DOS Command

          This performs the same function as the Alt-V command.

          Run Editor

          This performs the same function as the Alt-A command.


     3.11  Screen Image
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-I saves an image of the screen to the Telix Screen Image
     file. This file is usually called TELIX.IMG, but can be renamed in the
     Configuration Menu. If the file exists, the image is added to the end
     of it.


     3.12  The Translate Table
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Sometimes it is necessary for certain incoming or outgoing characters
     to be changed to another value or stripped altogether. For this pur-
     pose, Telix keeps in memory an incoming and an outgoing character
     'translate table'. For every character in the ASCII set, the table de-
     fines what it should be changed to. By default, no character transla-


     Telix v3.22                                     Program Features    17



     tion is performed, as for each character, the new value is defined to
     be the same as the old one. The translate table facility is entered by
     pressing Alt-W while in terminal mode. Telix will ask whether you want
     to work with the incoming or outgoing table, and then display the
     translate table screen with the following menu at the bottom:

                      Load  Clear  Save  Edit  Other  eXit

     Most of the screen is used to display translation values. Each column
     holds on the left the original character (ASCII value), and on the
     right the new character. Only half the ASCII set can be displayed on
     one screen. Select the 'Other' option to toggle the display to show
     the other half of the character set.

     The 'Load' option is used to load a previously saved translate table
     definition file. Telix will ask for the filename, including extension.

     The 'Clear' option is used to reset all values in the translate table
     in memory, so that no translation is performed.

     The 'Save' option is used to save the current translate table defini-
     tion to a disk file. Telix will ask for the file name to save the
     table to. You must include the extension if needed (a common extension
     for this purpose is '.XLT").

     The 'Edit' option is used to actually edit the translate table. Telix
     will ask for the old ASCII value, and the new one. If the new value of
     a character is defined as 0, that character is completely striped.

     It is sometimes useful to have an incoming and/or outgoing translate
     table load automatically when Telix is run. If the file TELIXIN.XLT
     exists at Telix start-up, it is assumed to be a default incoming char-
     acter translate table, and is loaded into that slot. Similarly, if the
     file TELIXOUT.XLT exists at start-up, it is assumed to be the default
     outgoing translate table, and loaded.


     3.13  Chat Mode
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Normally while using Telix with a remote host, your characters are not
     echoed by Telix. When you type a character, it is sent to the remote
     host, which checks it and then sends it back to you, and only then is
     it printed on your screen. However if two users want to chat with each
     other this becomes a problem, because each user's software expects the
     other side to echo the characters back, and since it doesn't, nothing
     is printed. Telix has a special Chat Mode to deal with this.

     When you press Alt-Y Telix enters Chat Mode. Any characters you type
     are printed on your screen immediately, without having to be echoed by
     the other side. As well, it takes only a Carriage Return to advance to
     a new line, a Line Feed character is not needed immediately af-
     terwards. Telix also splits the streams of text. Any characters you
     type are displayed on the bottom half of the screen, while the char-


     Telix v3.22                                     Program Features    18



     acters coming from the remote side are displayed on the top half of
     the screen. When you wish to exit Chat Mode, press the Esc key.


     3.14  Clear Screen
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To clear the screen press Alt-C. The screen will be cleared to the de-
     fault colors, and the cursor will be placed in the upper left-hand
     corner.


     3.15  Local Echo
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-E will toggle local echo on and off. If local echo is on,
     characters you type are printed on the screen. If local echo is off
     characters you type are not printed on the screen, they must be sent
     back to you by the remote host to be printed by the screen. Most hosts
     are set up so that local echo should be off; they will do the echoing.
     This is called a full duplex host. Often however when talking to an-
     other user, or when talking to a half duplex host, local echo must be
     turned on to see the characters you type.


     3.16  Add Line Feeds
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     When a line of characters is received from a remote system, it is usu-
     ally terminated by a Carriage Return followed by a Line Feed charac-
     ter. If the Line Feed character is missing lines will overwrite each
     other. If this seems to be happening when you are connected to a re-
     mote host then you must make Telix add Line Feeds to each incoming
     Carriage Return. Pressing Shift-Tab will toggle the adding of Line-
     Feed characters. If this option is on, every time a Carriage Return is
     received, a Line Feed is added immediately after it.


     3.17  Break Signal
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Some hosts require the use of a special modem signal called a Break
     signal, to do certain tasks like end transmissions. To make Telix send
     a Break signal to the remote host press Ctrl-End.


     3.18  DOORWAY Mode
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-= while in Terminal Mode will toggle DOORWAY mode on/off.
     DOORWAY mode is used by the DOORWAY utility by Dudley Marshall, and
     several other applications. While in DOORWAY mode, when a key is
     pressed Telix simply sends its raw scan code out the serial port, as
     returned by the PC's BIOS keyboard function. Note that since for any


     Telix v3.22                                     Program Features    19



     key except Alt-=, Telix just sends the value to the serial port, you
     must first switch out of DOORWAY mode to perform any Telix function.


     3.19  Miscellaneous Functions
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Pressing Alt-M while in Terminal Mode will cause Telix to display the
     Misc. Functions menu

                          ÕÍµ Misc. Functions ÆÍÍÍÍÍ¸
                          ³                         ³
                          ³ Send Modem Init string  ³
                          ³ Send Auto-Answer string ³
                          ³ 80x25 screen            ³
                          ³ 80x43 screen            ³
                          ³ 80x50 screen            ³
                          ³ eXit                    ³
                          ³                         ³
                          ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾

     3.19.1  Sending Modem Strings

     To re-send the Modem Init string defined in the Modem and dialing page
     of the configuration Menu, select the first option of the Misc. Func-
     tions Menu.

     To send the Modem Auto-Answer string defined in the Modem and dialing
     page of the configuration Menu, select the second option of the Misc.
     Functions Menu. If this string is properly defined, the modem will be
     placed in auto-answer mode.

     3.19.2  Setting the Screen Size

     The third through fifth options of the Misc. Functions Menu deal with
     setting the screen size (height). These options are valid only on EGA
     and/or VGA systems. Note that a standard EGA system can switch only
     between 25 and 43 lines, and can not handle 50. Note that some VGA
     cards can switch only between 25 and 50 lines, and can not handle 43.
     Trying to use one of these options on a system not equipped with an
     EGA or VGA video card is not allowed.


     Telix v3.22                                The Dialing Directory    21




     4.  THE DIALING DIRECTORY


     Telix allows you to keep telephone numbers in files called dialing di-
     rectories. A dialing directory is variable sized and can hold from 1
     to 1000 entries. Besides the number, many other fields of information
     are stored, such as the communications parameters needed to talk to
     the service. All the fields are described below. The default dialing
     directory file is called TELIX.FON, but you can have as many di-
     rectories as you want and load them as needed.

     To access the dialing directory press Alt-D while in terminal mode. A
     small window will appear, asking you to enter the entries to dial or
     to press Return to see the dialing directory. For the moment just
     press Return. This first window is simply a very quick way to dial
     your most commonly called numbers. Once you have pressed Return the
     dialing directory will appear.


     4.1  The Display
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Most of the screen is taken up by a window showing 15 (or more, de-
     pending on the screen mode) of the possible 1000 entries in the dial-
     ing directory. On the bottom of the screen is a menu of options, shown
     here:

       Dial  List  Toggle  Find  Manual  Redial  Add  Edit  Clear  Unmark
                                     Other

     This menu works in a similar manner to the other menus found in Telix,
     as described in the section 'Using Telix Menus'. In addition, since
     dialing is such a common function, if any numeric key is pressed, it
     is assumed that the 'List' function is wanted and this number is car-
     ried over as the first digit entered for that function. At the same
     time you may view the dialing directory. To scroll through the direc-
     tory one entry at a time, use the Up and Down arrow keys. Use PgUp to
     go back one page, and PgDn to go forward one page. Press Home to go to
     the beginning of the directory, and End to go to the end of the di-
     rectory. It should be emphasized that whenever the line 'Scroll with
     Up, Down, Home, End, PgUp, and PgDn' is displayed, you may scroll
     through the directory.

     For each entry, many items are stored. All the fields can not be dis-
     played at the same time; you may toggle which fields are shown on the
     screen by selecting the Toggle command. Each entry contains informa-
     tion under the following headers:

          Name

          The name of the remote service (i.e., Compuserve, Genie, Telix
          Software Support BBS, etc.).


     Telix v3.22                                The Dialing Directory    22



          Number

          The phone number which Telix should dial to reach the remote ser-
          vice.

          Line Format

          The communication parameters (such as baud rate, parity, etc.)
          needed to talk to this service.

          Script

          A script file may be linked to each entry in the dialing direc-
          tory. When Telix connects to this service, that script file is
          then run, and may for example automatically log-on, entering your
          name and password as needed, for greater convenience and speed.

          LastCall

          The date of the last successful call you made to this remote ser-
          vice.

          Total

          The total number of successful calls you've made to this number.

          Terminal

          The terminal Telix should start emulating when a connection has
          been reached to this number.

          P (Protocol)

          The first letter of the protocol which should be set as the de-
          fault if a connection is reached to this number.

          E (Echo)

          Whether local echo should be on or off when a connection is
          reached with this number.

          L (Add Line Feeds)

          This controls whether the Add Line Feeds setting should be on or
          off when a connection is reached with this number.

          H (Strip High Bit)

          Whether Telix will strip the high (most significant) bit of in-
          coming characters in terminal mode.


     Telix v3.22                                The Dialing Directory    23



          BD (Backspace Destructive)

          Whether a received backspace sequence is destructive (that is, if
          the character backspaced over should also be erased).

          BK (Backspace Key Value)

          What value the Backspace key sends, either Backspace, or Del.

          DP (Dialing Prefix Number)

          This (advanced) setting is used to tell Telix what Dialing Prefix
          to use when dialing this entry. One use for it is to turn on or
          off MNP (error correcting) support in modems, to avoid delays
          when the number called does not support it anyway.

          Password

          This field may hold a password for the remote service represented
          by this entry. The password may be used by a script file to auto-
          matically perform a log-on operation. Please note that this field
          is not encrypted, so if security is a problem, do not store your
          passwords in the dialing directory!


     4.2  Editing an Entry
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To edit the currently highlighted dialing directory entry select Edit
     from the dialing directory menu. A window will appear with the old
     contents of the entry. You may edit each field, starting with the
     first (name). To leave the contents of a filed as-is, press Enter. You
     may move up and down in the list of fields by using the Tab and Shift-
     Tab keys. Pressing Esc one or more times will get you out of the edit
     window without any changes being made.

     Once all the fields have been edited, Telix will ask you if the Last
     Call and Total Calls fields should be cleared. Answer Yes or No as
     needed. Telix will then ask for confirmation before writing any
     changes to disk.


     4.3  Adding Entries
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To add a blank entry to the end of the dialing directory, select  'Add
     from the dialing directory menu. A dialing directory may hold up to
     1000 entries.


     Telix v3.22                                The Dialing Directory    24



     4.4  Clearing Entries
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To clear an entry or a range of entries select Clear from the dialing
     directory menu. Telix will ask you to select the range of entries to
     clear, by moving the highlight bar and pressing Enter. After confirm-
     ing your choice, Telix will clear the selected entries back to empty
     entries.


     4.5  Finding an Entry
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To search for a particular entry in the dialing directory select Find
     from the dialing directory menu. You will be asked to give the string
     to search for. If Telix finds the entry with that string in it, that
     entry will be highlighted. If while searching for the string Telix
     reaches the end of the directory, it will wrap around to the beginning
     and continue the search. If the string still can not be found Telix
     will say 'Sorry, string not found'. If you want to search for the same
     string as last time, just press Return when asked for the search
     string.


     4.6  Dialing
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix allows you to dial a group of dialing directory entries repeat-
     edly until a connection is established, or you abort the attempt. Se-
     lecting the Dial function from the dialing directory menu will make
     Telix commence dialing in sequence all the currently marked entries.

     You may also dial a user-entered list of entries, by selecting the
     List function from the dialing directory menu. Telix will ask you to
     enter up to 10 entries to dial in sequence (to make List dialing even
     more convenient, you may also select the List function by pressing a
     numeric key while in the dialing directory menu; this number is then
     carried over and entered as the first digit in the string you are
     asked to enter). While you are entering the list of entries to dial
     you may also scroll through the directory as described above. If you
     specify more than one entry to dial, each should be separated by a
     space.

     Sometimes you may want to dial a number that is not in the dialing di-
     rectory. To do this select the Manual option of the dialing directory
     menu, which stands for 'manual dial'. You will be asked to enter a
     number to be sent to the modem. Whatever you supply will be sent out
     exactly as is, except for Long Distance codes (see below), which are
     still valid.


     Telix v3.22                                The Dialing Directory    25



     4.6.1  Long Distance Codes

     A Long Distance code is an advanced dialing option which adds some
     flexibility. There are four Long Distance code characters: !, @,  $,
     and +, which when encountered while dialing expand to user-defined
     strings (see section below on revising Long distance codes).

     If Telix is dialing a number from a dialing directory entry, and one
     of the Long Distance code characters is encountered in the number,
     Telix will instead send whatever string has been assigned to that
     code. For example, a dialing directory entry could contain the phone
     number '!967-1111'. If the string '9,,' was assigned to the ! LD code
     character, Telix when dialing this entry would first send the 9 fol-
     lowed by the commas, and then send the rest of the digits.

     LD codes may also be used with the List dial function. When you place
     one of them in front of or behind an entry number to dial, it will be
     expanded to a string. For example you could have the exclamation sign
     '!', be expanded to '9,', or any string you specify. You may place up
     to 3 Long Distances codes in front and one Long Distance code after
     each entry number. For example, specifying the entry '+21!' would send
     the string for the '+' Long Distance code, followed by the number from
     entry 21, followed by the string for Long Distance code '!'. The
     string

          10 +15 20!

     entered at the prompt would dial entry 10, then entry 15 with a Long
     Distance code in front of it, and finally entry number 20, with a Long
     Distance code after it. These numbers are redialed repeatedly until a
     connection is reached. To learn about the redial window see the Redial
     function below.


     4.7  Other Functions
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Selecting Other from the dialing directory menu will present a menu of
     secondary functions, dealing with the deletion or insertion of entries
     in the dialing directory, with revising Long Distance Codes, and with
     the handling of dialing directories (Telix allows you to have as many
     dialing directories as needed and switch among them at will).


     4.7.1  Inserting Blank Entries

     To insert blank entries in the dialing directory, select Insert from
     the dialing directory Other menu. Entries will be inserted at the cur-
     rent position of the highlight bar. Telix will ask how many entries to
     insert and will ask for confirmation before proceeding.


     Telix v3.22                                The Dialing Directory    26



     4.7.2  Deleting Entries

     To delete an entry or a range of entries in the dialing directory se-
     lect the Delete option from the dialing directory Other menu. The
     range to delete is selected by moving the highlight bar. After con-
     firming your choice, the entries will be deleted and any following en-
     tries will move up to where the deleted entries were.


     4.7.3  Revising Long Distance Codes

     To revise the Long Distance codes, select the option called Edit_LD
     from the dialing directory Other menu. There are four Long Distance
     code characters: ! @ - +. As described in the section on dialing, when
     you place one of them in front of or behind a number to dial, it will
     be expanded to a string. After selecting this option you will be shown
     a menu of the available long distance codes. Selecting an LD Code will
     let you modify the text currently assigned to it. After you have made
     your changes, you must save them to disk with the Save Changes option,
     if you want to use them every time you run Telix.


     4.7.4  Creating a Dialing Directory

     To create a blank dialing directory (which can later be modified), se-
     lect the option called Create from the dialing directory screen's
     Other menu. Telix will ask you for the name the new directory should
     use. Any legal DOS filename is suitable, and there is no default ex-
     tension. Telix will then create the blank directory on disk. The cur-
     rent dialing directory is not be affected and will stay in memory.


     4.7.5  Loading a Dialing directory

     To load another dialing directory select the Load option form the di-
     aling directory screen's Other menu. Telix will ask for the name of
     the new directory and then load it into memory. Telix assumes a de-
     fault extension of .FON, so if the directory you want to load does not
     have one, include a period at the end (e.g., TELIX.)  The new
     directory becomes the default directory for the rest of the session or
     until you load another one.


     4.7.6  Printing the Dialing directory

     Selecting the Print option from the dialing directory screen's Other
     menu allows you to print out the current dialing directory, to the
     printer, the serial port, or any device or disk file. Telix will ask
     you for the device or file to print to. Enter the name or press Return
     to use the PRN device (printer). Since these are DOS devices, Telix
     has no way of knowing, for example, things such as whether or not your
     printer is online. So if Telix seems to lock-up here, make sure your
     printer is on and it is set to online.


     Telix v3.22                                The Dialing Directory    27




     4.8  Automatic Queue Redial
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     When Telix has one or more numbers to dial, it redials repeatedly un-
     til a connection is made. To keep you informed of the status of the
     redial Telix displays a status window, and alerts you when a connec-
     tion is established. The status window is similar to the figure below.

         ÕÍµ Redial ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸
         ³                                                            ³
         ³ Redial started at 20:15:33    Press: T to change dial time ³
         ³ Attempt #10       20:19:27           D to delete from list ³
         ³                                                            ³
         ³ This attempt: Dialing My Favorite BBS ... 22               ³
         ³       number: 967-1111                                     ³
         ³ Last Attempt: Busy                                         ³
         ³                                                            ³
         ³     Press Space to cycle to next number, Esc to exit.      ³
         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾

     Information included in the status window is the time redial was
     started, the time the current attempt was started, the status of the
     last attempt, the status of the current attempt, and a countdown timer
     for the current attempt.

     If you are dialing all the marked entries with the dialing directory
     Dial command, when a connection is reached, the mark is taken off the
     entry connected to, so that when you later select the Dial function
     again, only the remaining entries are dialed. If you are dialing a
     list of entries selected with the List dialing directory command, when
     a connection is established the entry connected to is taken out of the
     list, so that when you later select the Redial command from the dial-
     ing directory or the Alt-Q command from terminal mode, only the re-
     maining entries will be shown.

     While redialing, you have the option of changing the time that Telix
     waits for a connection, and also the option of deleting a number from
     the list to dial, by pressing 'T' and 'D' respectively.

     Normally, when a connection has been reached, Telix sounds an alarm to
     alert you of this. If a script file is linked to the entry however,
     the alarm is skipped so that the script may immediately proceed. It is
     thus the responsibility of the linked script to alert the user of the
     fact that a connection has been reached.

     Pressing Alt-Q while in the terminal mode or selecting 'Redial last'
     from the dialing directory menu will allow you to redial one or more
     numbers that you entered previously using the 'List' command, so that
     you do not have to re-enter them. You will be shown the list and asked
     to edit it until you are satisfied, and then to press Return.


     Telix v3.22                                The Dialing Directory    28



     4.9  The Quick Dial Bar
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     You may have noticed that after you press Alt-D an inverse bar is dis-
     played on the bottom of the screen, asking you to select the entries
     to dial or press Return to see the Dialing directory. Up to now, you
     have just pressed Return to go on to the Dialing Directory, but this
     bar is a quick way to dial commonly called directory entries whose
     numbers you have memorized. You may enter a list of entries to dial
     just as if you had used the List command of the dialing directory
     menu. This saves the dialing directory from having to be displayed on
     the screen if you already know the entry or entries you want to dial.
     The Quick Dial Bar can also be used to dial a number manually. To do
     this just preface the number with an 'm'. For example, 'm967-1111'
     would dial 967-1111, just as if you had used the Manual dial option of
     the Dialing Directory. Either lowercase or uppercase 'm' is accepted.
     The use of the Quick Dial Bar may be disabled via the Configuration
     Menu.


     Telix v3.22                                       File Transfers    29





     5.  FILE TRANSFERS


     Sending files from one computer to another is one of the most useful
     things you can do with your modem. Telix supports a full assortment of
     the most popular file transfer protocols, including Xmodem, Xmodem-1k,
     Xmodem-1k-g, Zmodem, Compuserve Quick B, Kermit, Ymodem, Ymodem-g,
     SEAlink, Telink, Modem7, and ASCII. Telix's file transfers are very
     fast, surpassing most programs in speed by a respectable margin. All
     file transfers use a 10 Kbyte buffer, and full error detection is
     standard.

     Telix allows you to define up to five external protocols, which are
     completely integrated into the file transfer menus.  When you select
     one of these protocols, Telix executes a DOS batch file or Telix
     script file, which must then call the appropriate external driver for
     the protocol. In this way, you may add virtually any file transfer
     protocol to Telix. Adding external protocols is defined in the section
     on the Configuration Menu.


     5.1  Downloading (Receiving) Files
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To start downloading (receiving) a file from a remote host, you must
     usually inform the remote host of the files that you want it to send
     to you before starting the transfer on the Telix side. You must then
     start the download on the Telix side. Pressing the Alt-R key will dis-
     play a menu asking which file transfer protocol you would like to use:

                             ÕÍµ Download file ÆÍ¸
                             ³                   ³
                             ³  Which Protocol?  ³
                             ³                   ³
                             ³  ASCII            ³
                             ³  CIS Quick B      ³
                             ³  Kermit           ³
                             ³  Modem7           ³
                             ³  SEAlink          ³
                             ³  Telink           ³
                             ³  Xmodem           ³
                             ³  1k-Xmodem        ³
                             ³  G-1k-Xmodem      ³
                             ³  Ymodem (Batch)   ³
                             ³  YmodEm-g         ³
                             ³  Zmodem           ³
                             ³  Quit             ³
                             ³                   ³
                             ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾

     If any external protocols are defined, they are also shown as part of
     the menu.


     Telix v3.22                                       File Transfers    30



     If you have selected Xmodem, Xmodem-1k, Xmodem-1k-g, or ASCII, as the
     protocol, Telix will ask you for the filename to save the file to.
     Telix always watches what you type while online, and will often know
     the name of the file you want to transfer, in which case this name
     will be displayed and all you have to do to accept it is press Return.
     Any legal DOS filename is valid, including a path. If the filename you
     supply already exists, Telix will ask you to confirm your choice or
     give another filename. If you select any other protocol, the remote
     sender of the file will supply the name to save the file to. If you
     have entered a download directory name in the Configuration Menu,
     Telix will automatically save download files there if you don't spec-
     ify another path. Telix has automatic incoming file protection. If the
     name is supplied by the host and exists already the file is renamed by
     using numerals in the extension, as needed.

     During the transfer, a full status window is displayed showing the
     elapsed time, the number of bytes received, and an approximate Charac-
     ter Per Second rating, which can give an idea of the effective speed
     of the transfer.  Batch protocols will also display the expected file
     size and file transfer time. For ASCII transfers, a status window is
     not displayed, only a single status line at the top of the screen. To
     abort a file transfer at any time press the Escape key.


     5.2  Uploading (Sending) Files
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     To start uploading (sending) a file to a remote host you must also
     usually inform the host of the file you will be sending it before
     starting the upload on the Telix end. To start the upload on the Telix
     end press the Alt-S key. This will display a menu asking you which
     file transfer protocol you want to use to send the file. After you
     have selected the protocol, you will be asked for the file(s) to send
     by a dialog box:

     ÕÍµ Upload Files ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸
     ³                                                                   ³
     ³  ÕÍµ Path/Directory ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸  ³
     ³  ³ D:\TELIX\                                                   ³  ³
     ³  ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾  ³
     ³                                                                   ³
     ³  ÕÍµ Filelist ÆÍÍ¸  ÕÍµ Tagged Files ÆÍÍÍÍÍÍÍÍÍ¸  ÕÍµ Drives ÆÍ¸  ³
     ³  ³ ..\           ³  ³                          ³  ³     C:     ³  ³
     ³  ³ DOWN\         ³  ³                          ³  ³     D:     ³  ³
     ³  ³ SALT\         ³  ³                          ³  ³     X:     ³  ³
     ³  ³ 1.FON         ³  ³                          ³  ³     Y:     ³  ³
     ³  ³ ANSI.KEY      ³  ³                          ³  ³     Z:     ³  ³
     ³  ³ TELIX.CNF     ³  ³                          ³  ³            ³  ³
     ³  ³ TELIX.EXE     ³  ³                          ³  ³            ³  ³
     ³  ³ TELIX.FON     ³  ³                          ³  ³            ³  ³
     ³  ³ TELIX.KEY     ³  ³                          ³  ³            ³  ³
     ³  ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾  ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾  ÔÍÍÍÍÍÍÍÍÍÍÍÍ¾  ³
     ³                                                                   ³
     ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾


     Telix v3.22                                       File Transfers    31



     This is a complex dialog, and deserves more detailed attention.  Once
     mastered, this dialog will greatly streamline the uploading process.
     There are four separate windows in the dialog.  The selected dialog
     will have a bar at the top, highlighting the name of the window.   You
     may move from one window to the next using Tab and Shift-Tab to move
     forward or backward, respectively.  In any window, pressing Up-Arrow
     or Down-Arrow move the highlight bar in that direction if possible.
     Pressing F10 closes the dialog and uploads the files selected.

     Tagged Files:  This window contains a list of all of the files Telix
                    is to upload.  It will be blank when the dialog first
                    appears.  You may select files to be included in this
                    list as described below.  Files already listed may be
                    removed from this window by highlighting the file and
                    pressing Enter or Space.

     Path/Dir:      This window is where the currently displayed upload
                    path will be displayed.   You may add files to the
                    Tagged Files List from this window by typing in the
                    exact name of the file.   You may use the wildcard
                    characters ? and * (see your DOS manual, for more
                    information about wildcard characters).  You may change
                    the currently displayed upload path by entering a new
                    path here.

     Filelist:      This window contains the files in the currently
                    displayed upload path.   This window may contain a
                    maximum of approximately 700 files.  Files listed in
                    this window may be added to the Tagged Files List by
                    highlighting the file and pressing Enter or Space.  If
                    you wish to add or remove all files in this window
                    (both those on and off the screen) to or from the
                    Tagged File List, you may do so with F3 and F4
                    respectively.

     Drives         This window contains a list of all available disks in
                    your system, except for floppy drives.   Users of
                    removable disks such as Bernoulli boxes may have to
                    load a cartridge to upload a file.  You may change the
                    drive on which the Filelist is read from by selecting a
                    new drive from this window.

     During the file transfer, a full status window is displayed, unless
     you are using ASCII protocol, in which case only a status line is dis-
     played. Information shown is the expected time the transfer will take,
     the time remaining, the number of bytes to send, the number of bytes
     left, and an approximate Character Per Second rating, which can give
     an idea of the effective speed of the transfer. To abort a transfer at
     any time press the Escape key.


     Telix v3.22                                       File Transfers    32



     5.3  File Transfer Protocols
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Xmodem  -   Xmodem is often called the "lowest common denominator"
     protocol, and is the father protocol of many others. Xmodem sends
     files in blocks of 128 characters at a time. When the receiving com-
     puter is satisfied that the block has arrived intact, it signals so
     and waits for the next block. Error checking is a checksum or a more
     sophisticated Cyclic Redundancy Check. Telix supports both and will
     automatically use the right one. During a download, Telix will attempt
     to use the CRC, but will switch to checksum if it seems the host does
     not support CRC. The Xmodem protocol also needs a setup of no parity,
     8 data bits, and 1 stop bit. If your communications parameters are
     different from these when you start an Xmodem transfer, Telix will
     switch to the required setup for the transfer, and back to the origi-
     nal setup after it is finished. In the Configuration Menu, you may en-
     abled Relaxed Xmodem timing. This is for use with remote services that
     can not tolerate strict timing during Xmodem transfers.

     Xmodem-1k  -  This is a small variation of the above that uses blocks
     that are 1 Kilobyte (1024 bytes) in size. This protocol is still mis-
     takenly called 'Ymodem' by many programs, but people are gradually
     moving over to the proper name.

     Xmodem-1k-g  -  This is a variation of the above that is meant for er-
     ror-free channels such as error correcting modems or null modem cable
     links between two computers. It achieves great speed by sending blocks
     one after another without waiting for acknowledgment from the re-
     ceiver. Because of this however, it can not re-send blocks in case of
     errors (and thus the need for an error-free link). If an error is de-
     tected by the receiver, the transfer is aborted. This protocol is
     still mistakenly called 'Ymodem-g' by many programs, but people are
     gradually moving over to the proper name.

     Compuserve Quick B  -  This protocol is used only on the Compuserve
     Information Service. It is quite fast and specially suited for the
     networks used in accessing CIS, which have large turnaround delays.
     This is a windowed protocol, which basically means that unless errors
     are detected, data is being sent at all times. A CIS Quick B transfer
     is totally controlled by Compuserve. After telling CIS what file(s) to
     send, the user does nothing. Telix, in terminal mode, then detects the
     command from CIS which tells it to start the transfer (note that CIS
     Quick B transfer must be enabled in the Configuration Menu, or they
     will not work).

     Zmodem  -  This advanced protocol is very fast and very reliable, and
     offers many features. It can arguably called the most popular protocol
     in use today. Zmodem can transfer a group of files in one batch, and
     keeps the exact file sizes and dates. Zmodem can detect and recover
     from errors quickly, and can resume an interrupted transfer at a later
     time (this feature, called Crash Recovery, may be toggled in the
     'Protocol options' page of the Configuration Menu). Zmodem is also
     very well suited for satellite links and packet switched networks.


     Telix v3.22                                       File Transfers    33



     SEAlink -  SEAlink is an advanced version of Xmodem developed by Sys-
     tem Enhancement Associates. It is a sliding window protocol  SEAlink
     is 15 to 25 percent faster than regular Xmodem. SEAlink passes a
     file's name, size, and date when transferring it, and can be used to
     send more than one file at a time.

     ASCII  -  in an ASCII transfer, it is as if the sender is actually
     typing the characters and the receiver is just recording them. There
     is no form of error detection used. Usually only ASCII files can be
     sent in this way, as binary files contain characters which would foul-
     up the screen.

     Ymodem  -  This protocol is a variation on Xmodem, which allows for
     multiple files to be sent per transfer. While transferring files, it
     keeps the correct name, size, and date, and may use 128 or 1024 byte
     block sizes.

     Ymodem-g  -  This protocol is a variation on the above, which achieves
     very high transfer rates by sending blocks one after another without
     waiting for acknowledgment. This however means than an error-free link
     such as an error-correcting modem or null modem cable between two com-
     puters is needed. If an error is detected by the receiver, the trans-
     fer is aborted.

     Telink  -  This protocol is mainly found on Fido BBS systems. It is
     basically the Xmodem protocol using CRC checking with an extra block
     sent ahead of the file telling its name, size, and date. This protocol
     allows more than one file to be sent at a time.

     Modem7 -  Modem7 is a close cousin to Xmodem that passes the filename
     before starting the transfer, thus taking away some of the user's
     work. It is common on CP/M systems. This protocol allows more than one
     file to be sent at a time.

     Kermit  -  The Kermit protocol was developed to make it easier for
     computers of different types to send files to each other. Almost any
     computer using Kermit can be set up to send files to another computer
     using Kermit (the same can be said of Zmodem however). Various options
     in the Kermit protocol implemented in Telix can be tailored to the
     user's needs in the Configuration Menu, option 'Kermit transfers'.
     This implementation of Kermit does not include a Kermit "server" func-
     tion, and cannot use "SEND", "GET", or other server commands.

     5.4  Which One to Use
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix supports a large number of built in file transfer protocols. To
     this can be added external protocols. It can get confusing to decide
     which one to use. When both sides of the connection only support one
     protocol, then obviously that is the one to use, no matter what its
     deficiencies. Otherwise some protocols are a better choice than oth-
     ers. On Compuserve, CIS Quick B should be used. For most purposes,
     Zmodem is the best all around protocol. It is very fast and very reli-
     able. Ymodem-g and Xmodem-1k-g are slightly faster. However these two


     Telix v3.22                                       File Transfers    34



     protocols need an error-free link. After that, Ymodem, SEAlink, and
     Xmodem-1k are quite fast and pretty reliable. The last choice would be
     Xmodem and its close cousins Telink and Modem7. ASCII transfers are
     suitable only for text files and do not perform any error detection or
     correction, so they are to be avoided if possible.


     Telix v3.22                             Telix Configuration Menu    35





     6.  TELIX CONFIGURATION MENU


     Telix has many features which can be customized. These include things
     like the screen setup, the communications parameters, filenames and
     paths, and many other items. The default values for these parameters
     are stored in a file called TELIX.CNF, the configuration file. Telix
     will automatically read this file upon starting up. The first time you
     use Telix, this file is created for you with some standard default
     values. Pressing Alt-O while in terminal mode brings up the Telix Con-
     figuration Menu, which allows you to change all these default set-
     tings.

                       ÕÍµ Configure Telix ÆÍÍÍÍÍÍÍÍÍÍÍÍ¸
                       ³                                ³
                       ³ Change which default settings? ³
                       ³                                ³
                       ³     Screen and color           ³
                       ³     Terminal Options           ³
                       ³     General settings           ³
                       ³     Modem and dialing          ³
                       ³     Filenames and paths        ³
                       ³     ASCII transfers            ³
                       ³     Protocol options           ³
                       ³     Kermit transfers           ³
                       ³     Comm port setup            ³
                       ³     Write changes to disk      ³
                       ³     Exit                       ³
                       ³                                ³
                       ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾

     The first seven options are parameter screens, the last two deal with
     leaving the Configuration Menu.


     6.1  Screen and Color Settings
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen allows you to set various video related options. You will
     be shown a menu listing the various parts of the screen displays (such
     as menu foreground colors). If you pick one of these items you will be
     allowed to scroll through the possible colors for it by using the ar-
     row keys. When you have selected the right colors, press Enter. If you
     want to leave the colors menu without selecting one press Esc.

     Another setting on the Screen and Colors menu is the 'Screen write
     mode'. If you pick this option you will be asked in which way you want
     Telix to write to the screen. This depends on the video adapter pre-
     sent in your system. The first option is a direct screen write. This
     is the fastest mode, and should be used if you have a monochrome
     adapter, an EGA adapter, or another video adapter that never gets
     snow. The second option is a direct screen write with port checks.


     Telix v3.22                             Telix Configuration Menu    36



     This method is slightly slower. You should use this method if you
     screen gets snow on it or it flickers while executing the DOS 'dir'
     command. One card with which you should use this is the color/graphics
     adapter. Don't use this option if your video card doesn't need it, as
     it may interfere with communications. The final method is a screen
     write with BIOS calls. You should use this method with applications
     like Topview or DoubleDOS. This method is quite slow however. Note
     that you do not need this mode to run Telix under DESQview, since
     Telix is DV aware.

     Another setting on this menu is 'Default screen size'. This allows you
     to pick an alternate default screen size of 80x43 or 80x50. Note that
     these modes require an EGA or VGA card. Note also that many EGA cards
     can not do 80x50, and some VGA cards can not do 80x43.

     When you have finished picking the colors, select the 'Keep changes &
     exit' option if you want to keep the color changes you have made, or
     the 'exit' option if you want to discard them.


     6.2  Terminal Options
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen contains settings related to Telix operation while in
     terminal mode (with some extending to other areas of Telix). To select
     a setting to change type the letter beside it. Telix will then allow
     you to change the old setting. Press Esc at this point to exit without
     changing anything. Options include:

     A    Default Communications Parameters

          These include comm port, bps (baud) rate, data bits, parity, and
          stop bits. Note that the current settings will not change, only
          the defaults for the next time you load Telix.  Alt-P changes the
          current settings.

     B    Emulate Before Translation

          Some European systems override characters used by many terminal
          emulations to signal color changes and other items that don't
          show up on the screen as characters.  Normally a received
          character is passed through the translation tables before being
          examined to see if it is such a character.   This option allows
          the emulation to occur first, and then only translates those
          characters not seen as emulation commands.

     C    Default Terminal Type

          Allowable terminals are "TTY", "ANSI-BBS", "VT102", "VT52",
          "ANSI", and "AVATAR". Note that the current terminal will not be
          changed, only the terminal used the next time you run Telix.


     Telix v3.22                             Telix Configuration Menu    37



     D    Status Line

          Telix allows a status line to be displayed at the top or bottom
          of the screen. The status line shows some useful information.
          Valid options are Top, Bottom or None. While in Terminal Mode the
          status line may also easily be toggled on or off by pressing
          Alt-8.

     E    Default Local Echo

          This controls whether or not Telix should echo on the screen any
          characters you type while in Terminal mode. This is usually off
          for BBS use. Local echo on is often also called Half Duplex,
          while local echo off is called Full Duplex.

     F    Add Line Feeds

          This controls whether or not Telix should add line feeds to
          incoming Carriage Returns characters while in terminal mode. If
          you are connected to a remote system and lines are overwriting
          each other, this should be on, otherwise it should be off.

     G    Strip High Bit

          Telix can strip the high (most significant) bit from incoming
          data bytes while in terminal mode. This is sometimes useful be-
          cause it allows the high/parity bit of incoming text to be ig-
          nored.

     H    Received Backspace Destructive

          This setting controls how Telix treats incoming backspace charac-
          ters. If backspace characters are destructive, Telix backs up
          over the previous character and erases it, otherwise the existing
          character is not erased.

     I    Backspace Key Character

          Normally, Telix sends Backspace when the Backspace key is
          pressed, and DEL when Ctrl-Backspace is pressed. This option al-
          lows these settings to be swapped.

     J    XON/XOFF Software Flow Control

          This controls whether or not Telix should use the XON/XOFF soft-
          ware handshaking protocol while in terminal mode and during ASCII
          file transfers. This should usually be on.

     K    CTS/RTS Hardware Handshaking

          Hardware handshaking is used with high speed modems and null mo-
          dem cable links to regulate the flow of data. If the modem sup-
          ports Hardware handshaking this should be on. If a null modem ca-


     Telix v3.22                             Telix Configuration Menu    38



          ble is being used and these signals are valid over the cable,
          this should be on.

     L    DSR/DTR Hardware Handshaking

          Hardware handshaking is used with high speed null modem cable
          links to regulate the flow of data. If a null modem cable is be-
          ing used and these signals are valid over the cable, this should
          be on. Often a null modem cable will allow one type of hardware
          handshaking to be used, but not the other.

     M    Compuserve Quick B Transfers

          Compuserve Quick B file transfers are initiated by Compuserve,
          which sends a few special characters (Ctrl-E and Ctrl-P). Telix,
          upon detecting these characters while in terminal mode, starts
          the transfer. If another Host is sending these characters and
          causing problems, this option allows CIS Quick B recognition to
          be turned off.

     N    Zmodem Auto-Downloads

          Telix, while in Terminal Mode, can detect the packet from another
          computer sending files using the Zmodem protocol, and automati-
          cally begin a Zmodem download on the local end. This option al-
          lows this feature to be disabled.

     O    Answerback string

          Some systems require that the terminal program send an identifi-
          cation string when an ENQ (Ctrl-E) character is received. You may
          define such an 'answerback' string here. If this string is empty,
          nothing is sent. As well, note that the answerback string is not
          sent if Compuserve Quick B transfers are enabled (above), as
          Ctrl-E is used as part of that protocol.


     6.3  General Settings
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen allows you to change some general default settings, in-
     cluding:

     A    Sound

          If this is off Telix will not make ANY sounds.

     B    Alarm Sound

          If this is off Telix will not make ANY alarm sounds, but will
          still beep when it receives the bell code from the remote host,
          unless the sound option is also off.


     Telix v3.22                             Telix Configuration Menu    39



     C    Keep Aborted Downloads

          If this is on, Telix will keep files which were aborted during a
          download. Otherwise Telix will delete these files.

     D    Show Free Space for Downloads

          This setting controls whether or not Telix will display the free
          space on the disk when you start a download. The option to turn
          it off is provided because the free space display takes a few
          seconds for large hard disks.

     E    Quick Dial Bar

          When you press Alt-D to access the dialing directory, Telix nor-
          mally first displays the Quick Dial Bar at the bottom of the
          screen, which allows you dial entries without having to view the
          dialing directory. If you would rather go directly to the dialing
          directory when you press Alt-D, set this option to Off.

     F    Confirm Hang-Up

          Setting this option to on will make Telix ask for confirmation
          before hanging up, when Alt-H is pressed.

     G    Default Usage Log Setting

          If this option is set to on, Telix will open the default Usage
          Log (as specified on the Filenames and Paths screen) at program
          start up. Otherwise the usage log must be manually turned on if
          needed.

     H    Scroll-Back Buffer Size

          This setting controls the size of the Telix Scroll-Back buffer
          (in kilobytes). For changes to this setting to take effect you
          must save the changes to disk and restart Telix.

     I    Capture File Buffer Size

          This is the size of the disk buffer that Telix should use for the
          Capture file when it is opened. Values from 0 to 4 Kilobytes are
          allowed. A larger buffer size means the disk is accessed less of-
          ten.

     J    Date Format

          This is the format that Telix should use when displaying dates.
          Allowed formats are MMDDYY, DDMMYY, and YYMMDD.


     Telix v3.22                             Telix Configuration Menu    40



     K    Date Separator Character

          This is the character that Telix will print between parts of the
          date when displaying a date. The default character is the hyphen
          (-).

     L    Time Format

          This is the format that Telix should use when displaying times.
          Allowed formats are 12-hour and 24-hour.

     M    Time Separator Character

          This is the character that Telix will print between parts of the
          time when displaying a time. The default character is the colon
          (:).

     N    Enhanced Keyboard Support

          This option allows you to turn off Telix's support for the en-
          hanced (101) keyboard. This should normally be left on, unless
          there seems to be a keyboard problem.

     O    Shell: 16550 Buffer

          This option allows you to specify whether the buffer on the
          16550a comm chip should be left on or off during a DOS shell. If
          it is installed in your PC, Telix normally recognizes and enables
          the buffer on this chip at all times, for greater efficiency, but
          there are still a few comm application that users might want to
          run from the shell which can not handle the chip with the buffer
          turned on.

     P    Shell: Swap to EMS/XMS/Disk

          This option allows you to specify whether Telix will attempt to
          remove most of itself from memory when executing DOS function
          calls.  The default is off for backwards compatibility, but most
          users should be able to turn this on without problems.



     6.4  Modem and Dialing settings
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen contains settings that Telix uses to control the modem and
     its output. The default configuration that Telix comes with is set up
     for Hayes compatible modems. These modems use the 'AT' command set. By
     changing these settings Telix can work with almost any modem. The pa-
     rameters are:


     Telix v3.22                             Telix Configuration Menu    41



     A    Modem Initialization String

          This string will be sent to the modem when Telix first starts.
          Different modems might need different strings. The default string
          is set up for Hayes compatible modems. It is:

               ATZ^M~~~AT S7=45 S0=0 V1 X4^M

          where:

               AT        is the modem attention code
               Z         resets the modem to default state
               ^M        sends the terminating Carriage Return character to
                         the modem.
               ~~~       pauses to give the modem time
               AT        is the modem attention code.
               S7=45     makes the modem wait 45 seconds for a connection.
               S0=0      turns off auto answer.
               V1        makes the modem respond with words.
               X4        makes the modem give extended result codes.
               ^M        sends the terminating Carriage Return character to
                         the modem.


     B    Dialing Prefix 1

          A Dialing prefix is what Telix sends to the modem when dialing,
          before the number, for example, 'ATDT' for Hayes compatible
          modems. There are three dialing prefixes allowed, and in the di-
          aling directory you may chose which one to use for each entry.
          One use for this is if your modem support MNP, to define two pre-
          fixes which turn MNP support on and off, thus avoiding the delay
          when you call a system that doesn't support MNP.

     C    Dialing prefix 2

     D    Dialing prefix 3

     E    Dialing Postfix

          The string Telix should send after the number when dialing. On
          Hayes compatible modems this is just a Carriage Return character,
          '^M'.

     F    Connect String

          The string which the modem sends upon establishing a connection.
          e.g., 'CONNECT'

     G    No connect strings

          Up to four strings which the modem sends when it has failed to
          make a connection while dialing, for example 'NO CARRIER',
          'BUSY', etc.


     Telix v3.22                             Telix Configuration Menu    42



     H    Hang-up string

          This is the string Telix should send to the modem to make it hang
          up. The default string works for Hayes compatible modems and is:

               ~~~+++~~~ATH0^M

          where

               ~~~       pauses Telix for 1 1/2 secs.
               +++       escapes the modem into command mode.
               ~~~       pauses Telix for 1 1/2 secs.
               AT        is the modem attention code.
               H0        tells the modem to hang up.
               ^M        sends the terminating Carriage Return character to
                         the modem.


          Before sending this string to the modem Telix always tries to
          hang-up the modem by a faster way that works with MOST modems.
          This is done by dropping (turning off) a special signal called
          the DTR (Data Terminal Ready) line on the RS-232 port. If drop-
          ping the DTR makes the modem hang-up then the hang-up string is
          not sent to the modem.

     I    Auto Answer String

          This is the string that Telix should send to the modem upon
          entering Host Mode. This string should allow the modem to
          automatically pick up the phone when it rings, and initialize it
          in any other ways that might be necessary.

     J    Dial Cancel String

          The string Telix should send to the modem to cancel the current
          dialing attempt. On most modems all that is necessary is a Car-
          riage Return character, "^M".

     K    Dial Time

          The amount of time Telix should wait for a connection while di-
          aling. This should usually be set to be greater than the amount
          of time the modem waits for the connection.

     L    Redial Pause

          The number of seconds Telix should wait between attempts while
          redialing.

     M    Auto Baud Detect

          If this option is on and Telix dials a number, it will check the
          modem connect message for a baud rate indication. If the baud is
          different than was specified for the entry being dialed, Telix


     Telix v3.22                             Telix Configuration Menu    43



          switches to the new baud rate. This option only works with Hayes
          compatible modems. This option must not be enabled when you have
          told the modem to maintain a constant or locked baud rate between
          the computer and the modem, as is often done with high-speed, er-
          ror correcting modems, or modems supporting MNP (e.g. USR HST,
          Hayes V-Series, etc.).


     6.5  Filenames and Path Settings
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen allows you to change several filename and pathname de-
     faults, including:

     A    Download Directory

          The disk directory in which Telix should save files which are
          downloaded (received). The user can override this by giving a
          full pathname when prompted.

     B    Upload Directory

          The disk directory where Telix should look for files to be up-
          loaded. The user can override this by giving a full filename when
          prompted.

     C    Script Directory

          The directory in which Telix should look for script files when
          trying to execute them. The user can override this by using a
          full pathname in front of the filename when specifying it.

     D    Default Capture File

          The default name Telix should use when opening the capture file.
          The user can override this.

     E    Default Usage Log

          The default name Telix should use when opening the Usage Log. The
          user can override this.

     F    Directory Program

          The name of the disk directory program the Telix should run when
          you select the 'Files directory' command. If you do not specify a
          program here Telix will use an internal routine that also dis-
          plays the amount of time it will take to transfer each file in
          the directory. An example of a program you could specify here is
          'dir/p', which would use the DOS dir command with pauses at each
          page full, to display the directory.


     Telix v3.22                             Telix Configuration Menu    44



     G    Screen Image File

          The file that Telix should save screen images (generated with the
          Alt-I command) to. the default name is TELIX.MSG.

     H    Editor Pathname

          The name of your editor, including the extension of the name
          (EXE, COM, or .BAT for batch files), for example, C:\EDITOR.COM.
          The indicated file must either be in the current directory, in a
          directory included in the DOS Path, or the name must include the
          full path. You need to set this parameter only if you want to run
          your editor using the Alt-A, Run Editor command.


     6.6  ASCII Transfers
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen allows you to customize Telix ASCII file transfers to your
     needs, so that Telix may work with almost any system. Available set-
     tings are:

     A    Strip High Bit

          If this parameter is on, the high (most significant) bit of each
          character sent for uploads, or received for downloads, is
          stripped. This can be used to ignore parity. On the other hand,
          the upper 128 characters in the IBM extended ASCII character set
          are then converted to the lower value.

     B    Remote Abort Character

          This is the character which when received during an ASCII upload
          or download, is taken to mean that the remote end wants to abort
          the transfer. One possible value might be 24 (Ctrl-X).

     C    Local Echo

          If this is on, Telix will echo characters locally while upload-
          ing. This should normally be off.

     D    Expand Blank Lines

          If this is on, when Telix is sending a file and it encounters a
          blank line, it will add a space to that line. This is very useful
          for systems that assume a blank line means "end of file", or for
          uploading a message on most bulletin boards.

     E    Pace Character

          This is the ASCII value of the character that Telix should wait
          for before sending each line. If this value is 0, Telix will not
          wait for any character.


     Telix v3.22                             Telix Configuration Menu    45



     F    Line Pacing

          This is the amount of time (in 1/10 seconds), that Telix should
          wait before sending each line. This delay is often not necessary,
          but for some bbs's for example, it's vital.

     G    Character Pacing

          This is the time delay (in milliseconds) that Telix should wait
          between each character. As the PC's hardware clock does not have
          enough resolution, this is a software loop based delay. There-
          fore, a value of 1 here will delay a 4.77 MHz XT approximately 1
          millisecond, and faster PCs for a proportionally smaller time pe-
          riod.

     H    Upload CR Translation

          This is what Telix should do with Carriage Return chars when up-
          loading ASCII files. The three options are to do nothing, to
          strip them, or to add a Line Feed character afterwards.

     I    Upload LF Translation

          This is what Telix should do with Line Feed characters when up-
          loading ASCII files. The three options are to do nothing, to
          strip them, or to add a Carriage Return before each.

     J    Download CR Translation

          This is exactly the same as setting E (above), but applies when
          downloading ASCII files.

     K    Download LF Translation

          This is exactly the same as setting F (above), but applies when
          downloading ASCII files.


     6.7  Protocol options
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen allows you to configure external protocols, as well as a
     few other settings.

     An external protocol is simply a file transfer protocol that is imple-
     mented outside of Telix. You specify the name of the protocol, the key
     used to select it on the file transfer menu, and define how it is to
     be called. You may optionally define a string which will trigger an
     automatic download much like the auto zmodem transfer capability built
     into Telix.  Items 'A' through 'E' are the definitions for the five
     external protocols allowed. When you select a definition to edit,
     Telix will ask a series of questions:


     Telix v3.22                             Telix Configuration Menu    46



          Key

          The key that should be pressed to select this protocol when the
          file transfer menu is displayed.

          Protocol Name

          The name Telix will display on the file transfer menu for this
          protocol.

          Upload Filename

          This is the name of the DOS batch file or Telix script file to
          call when the user selects an upload using this protocol. If this
          filename begins with an "@" symbol, Telix will create an ASCII
          text file "FILELIST" containing the list of specified or tagged
          files, one file per line.  Many external protocols can accept
          such a file as a parameter, and thus limits on the number of
          files that can be passed on a DOS command line may be
          circumvented.

          Download filename

          This is the name of the DOS batch file or Telix script file to
          call when the user selects a download using this protocol.

          BAT or Script

          This controls whether the above two filenames are DOS batch files
          or Telix script files.

          DL Name

          This option controls whether or not Telix should ask for the name
          of the file when performing a download using this protocol. In
          many protocols, the sender passes the name of the file(s) to the
          receiver, so Telix shouldn't ask for the download name.

          Trigger String

          This option is a place to enter a string which when received is
          indicative of a file being received by the protocol.   Telix can
          thus automatically detect an incoming file and move to download
          it without need of your intervention.   This string must be
          consistent, unique, and positively identify the occurance of an
          incoming file.   Check your external protocol documentation to
          determine if the protocol supports a trigger string.   This
          option should be left blank if there is no trigger available for
          the protocol.

     See the Appendix titled External Protocols for information about what
     information is passed to the batch or script files when an external
     transfer is selected.


     Telix v3.22                             Telix Configuration Menu    47



     Other settings on this page are:

     F    File Transfer Disk Buffer Size

          This allows you to set the size of the disk buffer used by Telix
          during file transfers from 1k to 10k (kilobytes) in size. A
          larger value is more efficient with floppy disk systems, while a
          smaller value can get around problems with disk controllers or
          Extended memory use on some hard-disk systems.

     G    Relaxed Xmodem Timing

          This option controls whether or not Telix should use relaxed tim-
          ing when performing an Xmodem transfer. When calling some ser-
          vices, this option must be turned on because they can not toler-
          ate strict timing.

     H    Filename Guessing

          This option controls Telix's use of filename guessing. When you
          selected a file transfer to be performed, telix can often guess
          the name of the file to be transferred, based on your past
          keystrokes. This option may be turned off here. As well, you may
          specify that Telix gives only guesses which it is almost certain
          are filenames, or gives its 'Best try', which may include guesses
          with extra characters which are not necessarily part of the file-
          name.

     I    Zmodem Receive Crash Recovery

          When an aborted Zmodem transfer must be resumed, this option
          should be turned on. While this option is on, if a file being
          downloaded using Zmodem already exists on the disk (and is
          shorter than the file the sender has), Telix will tell the sender
          to send only the bytes needed to complete the file. This option
          should be used with care. The possibility exists that a file with
          the same name but different contents exists on each system, in
          which case you do not want only some of the data transferred.

     J    Zmodem Send Crash Recovery

          When this option is on, during a Zmodem upload of files, Telix
          will try to tell the sender to resume aborted transfers. This op-
          tion should be used with care, as some systems do not support
          crash recovery, and will behave unpredictably.

     K    Allow Zmodem 32 bit CRCs

          Real speed freaks may turn off the use of 32 bit CRC error check-
          ing (still quite reliable 16 bit CRCs are used instead), to get
          on the order of a quarter to a half of a percent speed increase
          in Zmodem transfers.


     Telix v3.22                             Telix Configuration Menu    48



     L    Zmodem Window Size

          Zmodem normally sends data in streaming mode, never pausing un-
          less the other side requests a re-send due to an error being de-
          tected. In some environments, a pause for acknowledgments can be
          more efficient. The window size (in kilobytes) is the maximum
          amount of data the protocol should seed before waiting for a re-
          ply. A value of 0 indicates streaming mode should be used.

     M    Zmodem File Type

          This option allows you to specify whether the file being trans-
          ferred with the Zmodem protocol is Binary, ASCII, or Either. Bi-
          nary means that Telix will make sure no end-of-line conversion is
          done on files received or sent. ASCII means that on a download,
          as long as the other side doesn't override this, Telix will as-
          sume the file being received is a text file and will make sure
          the end of each line has a Carriage Return followed by a Line
          Feed, by adding the CR if the file has only LFs at the end of
          each line. An ASCII setting when sending will make Telix tell the
          other system to do end-of-line conversion, although the other
          system  may override this. Finally, a setting of Either (the de-
          fault), will make Telix assume the file is binary, unless the
          other system indicates otherwise. DO NOT use a setting of 'ASCII'
          for file that are not ASCII text files, as binary files will be
          corrupted by this option.


     6.8  Kermit Transfers
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen allows you to configure Telix's implementation of the Ker-
     mit protocol to your needs. The options will not be described here,
     due to the fact that the Kermit protocol is relatively complicated,
     and if you must change one of these parameters, you should generally
     already know what it means.


     6.9  Comm Port Setup
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This screen allows you to configure/define the communications ports.
     Telix supports definitions for 8 comm ports. By default, the first
     four comm ports are defined to the standards for COM1 through COM4.
     The last four comm ports are by default duplicates of COM1. For each
     port you may define the base address (in hexadecimal) of that port, as
     well as the interrupt request number (irq) to use. Unless you are ab-
     solutely sure about your information, do not modify these values!
     Wrong values could cause unexpected and possibly disruptive results.


     Telix v3.22                             Telix Configuration Menu    49



     6.10  Saving Changes and Leaving
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Any modified settings can be saved to the configuration file (so that
     they will be remembered when you next use Telix) by selecting the
     Write Setup to Disk option. If you want to keep any changes just for
     the current session, then exit the Configuration Menu using the Exit
     option.


     Telix v3.22                                   Terminal Emulation    51





     7.  TERMINAL EMULATION

     A video display terminal is basically a relatively dumb computer which
     is linked up to another computer (over a cable or modem link) and dis-
     plays what that computer sends to it. A mainframe or mini computer has
     a large amount of processing power and can drive a number of terminals
     at the same time.

     There are many different terminal types. Each one follows its own
     codes for controlling how information is displayed on the screen. For
     example, there are sequences to clear the screen, move the cursor,
     scroll the display, and so on. Most terminals also have special keys
     which send special sequences back to the main computer.

     Telix can emulate several terminals. While in terminal mode, you may
     change the terminal type Telix is currently emulating by pressing Alt-
     T. The default terminal can also be set in the 'Terminal settings'
     page of the Configuration Menu. Following are the choices Telix of-
     fers:


     7.1  TTY
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A TTY (Teletype) terminal is very stupid. It basically displays all
     the values it receives, except for about 5 or 6 Control codes (such as
     Carriage Return), which move the cursor and ring the bell. Telix does
     not have any special key definitions for this terminal type.


     7.2  ANSI-BBS
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This is a subset of the real ANSI terminal type defined by the Ameri-
     can National Standards Institute. Many BBS programs, when told to do
     so, can send sequences supported by this terminal to make screen dis-
     play more interesting and colorful. This emulation supports some known
     bugs in the DOS ANSI.SYS driver that are not part of the ANSI standard
     per se.

     The ANSI.KEY file contains definitions for the arrow keys, and is au-
     tomatically read when this terminal is selected. These definitions are
     supported by some full screen editors, for example.


     7.3  ANSI
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     This is the real ANSI terminal type defined by the American National
     Standards Institute. Many BBS programs, when told to do so, can send
     sequences supported by this terminal to make screen display more in-


     Telix v3.22                                   Terminal Emulation    52



     teresting and colorful. This conforms to the ANSI committee defini-
     tions of ANSI.


     7.4  VT102
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The DEC VT102 terminal is one of the most popular (and most emulated)
     terminals in existence. It was developed by Digital Equipment Corpora-
     tion. The VT102 terminal has a large number of functions. Telix sup-
     ports all of these except for 132 column mode and double height mode.
     As well, Telix only emulates double width mode, by adding a space af-
     ter every character.

     Telix fully supports both normal and application cursor mode in VT em-
     ulation. The VT102 keyboard layout used by Telix is stored in the
     VT102.KEY file, which is automatically read by Telix when VT102 termi-
     nal emulation is selected. Once Telix has loaded this into memory, the
     definitions can be edited through the use of the Alt-K
     (Keyboard/macros) function.

     The default keyboard layout is best suited for the (newer) 101-key
     style keyboards with separate arrow and numeric keypads, and functions
     keys across the top. In this layout, press F1 to F4 to simulate the
     VT's PF1 to PF4. With the NumLock key down, the PC's numeric keypad
     will simulate the VT's numeric keypad, while the arrow keys on the
     PC's numeric keypad (with the NumLock up) or the separate arrow keypad
     (at all times) will simulate the VT's arrow keys. Note that Telix will
     only recognize the separate arrow keypad if you turn on the 'Enhanced
     Keyboard' setting on the General Options screen of the Configuration
     Menu.

     Another keyboard layout is available that is possibly better suited to
     older style keyboards with function keys on on the left side and no
     separate arrow keypad and numeric keypad. To make use of this alter-
     nate layout, while at the DOS prompt type:

          ren VT102.KEY VT102101.KEY
          ren VT102OLD.KEY VT102.KEY

     This layout is similar to one used by many comm programs, in which the
     normal function keys (F1-F10) represent the left side of the VT's nu-
     meric keypad, while the shifted function keys (Shift-F1 - Shift-F10)
     represent the right side, as follows:


     Telix v3.22                                   Terminal Emulation    53



         Telix function Keys                  DEC VT102 Keypad

       F1  - F10     SF1  - SF10

     ÚÄÄÄÄ¿ ÚÄÄÄÄ¿  ÚÄÄÄÄ¿ ÚÄÄÄÄ¿       ÚÄÄÄÄ¿ ÚÄÄÄÄ¿ ÚÄÄÄÄ¿ ÚÄÄÄÄ¿
     ³PF1 ³ ³PF2 ³  ³PF3 ³ ³PF4 ³       ³PF1 ³ ³PF2 ³ ³PF3 ³ ³PF4 ³
     ÀÄÄÄÄÙ ÀÄÄÄÄÙ  ÀÄÄÄÄÙ ÀÄÄÄÄÙ       ÀÄÄÄÄÙ ÀÄÄÄÄÙ ÀÄÄÄÄÙ ÀÄÄÄÄÙ
     ÚÄÄÄÄ¿ ÚÄÄÄÄ¿  ÚÄÄÄÄ¿ ÚÄÄÄÄ¿       ÚÄÄÄÄ¿ ÚÄÄÄÄ¿ ÚÄÄÄÄ¿ ÚÄÄÄÄ¿
     ³ 7  ³ ³ 8  ³  ³ 9  ³ ³ -  ³       ³ 7  ³ ³ 8  ³ ³ 9  ³ ³ -  ³
     ÀÄÄÄÄÙ ÀÄÄÄÄÙ  ÀÄÄÄÄÙ ÀÄÄÄÄÙ       ÀÄÄÄÄÙ ÀÄÄÄÄÙ ÀÄÄÄÄÙ ÀÄÄÄÄÙ
     ÚÄÄÄÄ¿ ÚÄÄÄÄ¿  ÚÄÄÄÄ¿ ÚÄÄÄÄ¿       ÚÄÄÄÄ¿ ÚÄÄÄÄ¿ ÚÄÄÄÄ¿ ÚÄÄÄÄ¿
     ³ 4  ³ ³ 5  ³  ³ 6  ³ ³ ,  ³       ³ 4  ³ ³ 5  ³ ³ 6  ³ ³ ,  ³
     ÀÄÄÄÄÙ ÀÄÄÄÄÙ  ÀÄÄÄÄÙ ÀÄÄÄÄÙ       ÀÄÄÄÄÙ ÀÄÄÄÄÙ ÀÄÄÄÄÙ ÀÄÄÄÄÙ
     ÚÄÄÄÄ¿ ÚÄÄÄÄ¿  ÚÄÄÄÄ¿ ÚÄÄÄÄ¿       ÚÄÄÄÄ¿ ÚÄÄÄÄ¿ ÚÄÄÄÄ¿ ÚÄÄÄÄ¿
     ³ 1  ³ ³ 2  ³  ³ 3  ³ ³ E  ³       ³ 1  ³ ³ 2  ³ ³ 3  ³ ³ E  ³
     ÀÄÄÄÄÙ ÀÄÄÄÄÙ  ÀÄÄÄÄÙ ³ N  ³       ÀÄÄÄÄÙ ÀÄÄÄÄÙ ÀÄÄÄÄÙ ³ N  ³
     ÚÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄ¿ ³ T  ³       ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄ¿ ³ T  ³
     ³     0     ³  ³ .  ³ ³ R  ³       ³     0     ³ ³ .  ³ ³ R  ³
     ÀÄÄÄÄÄÄÄÄÄÄÄÙ  ÀÄÄÄÄÙ ÀÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÙ ÀÄÄÄÄÙ

     The arrow keys are also defined to send the proper sequences.


     7.5  VT52
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The DEC VT52 is another relatively common terminal type, that is con-
     siderably simple than the VT102. Telix's key definitions for the VT52
     are stored in the VT52.KEY file.


     Telix v3.22                                   Using Script Files    55





     8.  USING SCRIPT FILES

     8.1 The Scripting Languages
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Telix has an incredibly powerful built-in 'script' or command lan-
     guage, called SALT (Script Application Language for Telix). In the
     simplest terms, a script file is a sequence of commands for Telix to
     follow, written using a certain format. Script files can do many use-
     ful things like automatically logging on to a host, setting up special
     parameters, performing unattended file transfers, and many other
     tasks. A script file can be linked to a dialing directory entry so
     that it is run automatically when that entry is connected to, and sup-
     plies the needed logon information.

     Like any real programming language, SALT has a large number of fea-
     tures. Because of this, programming in SALT is not easy for the begin-
     ner who has no knowledge of any programming concepts. However SALT
     scripts can be used to different degrees. The advanced user can pro-
     gram complex applications, while even a novice can modify the sample
     scripts include with Telix, and run scripts supplied by others.

     For advanced users, a separate 100+ page manual describes SALT and its
     syntax. The rest of this section describes how to create, run and
     compile the various forms of scripts.  All forms of scripts must be
     compiled by one of the two compilers (CS.EXE or CSS.EXE) and all
     scripts are executed with the ALT-G command.

     8.2 SALT
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Before a SALT script can be used, it must be 'compiled'. The CS.EXE
     program included with Telix takes the ASCII 'source' scripts that the
     user writes, and compiles or converts them to a form that is easier
     for Telix to process, usually takes less space, and loads more
     quickly. SALT scripts may actually use any name. However in standard
     practice the extension 'SLT' is used for SALT source scripts, and the
     same name with the extension 'SLC' is used for the compiled version.

     If you have an already compiled SALT script (ending with the extension
     'SLC' (for example, the QDHOST.SLC Host Mode script file), it is very
     easy to execute. While in terminal mode, press Alt-G. Telix will ask
     for the name of the script file to run. If you supply no extension,
     'SLC' is assumed. If a special directory where script files are to be
     found has been defined, Telix will look there for script files, unless
     a path is given. To define this script directory use the Telix Con-
     figuration Menu. Telix will then load the script file and follow its
     instructions. To abort a script while it is executing, press the Esc
     key. Sometimes you may have to press Esc twice, the first time to
     abort the current function, and the second time to abort the script
     itself.


     Telix v3.22                                   Using Script Files    56



     You may have used your text editor to modify one of the sample scripts
     included with Telix (most simply require inserting your name in a
     clearly marked location near the top). You now need to compile the
     script file. To do this, the CS.EXE program is used. While at the DOS
     prompt, type 'CS', followed by a space and the name of the script file
     you want to compile (the extension 'SLT' is assumed if none is given).
     CS will scan through the source file and produce the compiled version,
     using the same base name but the extension 'SLC'. If a syntax error is
     discovered while compiling the script file, CS will report it and
     abort. In that case the error should be fixed and CS run again. From
     within Telix, you may quickly run CS either by using the DOS Command
     function (Alt-V), or from the DOS Shell (Alt-J).

     Remember, every time you make a change to the source file, you must
     re-compile it, otherwise Telix will still run the old compiled ver-
     sion. This sounds tedious, but in practice once a script is developed
     it doesn't change very often.

     8.3 SIMPLE
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     For those users not comfortable in a structured programming
     environment, Telix provides a Salt IMPLEmentation, or SIMPLE scripting
     language.  SIMPLE is a non-structured language that is converted to
     the more complex SALT for the user prior to actually compiling it.
     SIMPLE scripts need to be compiled with the CSS.EXE program.  While at
     the DOS prompt, type 'CSS', followed by a space and the name of the
     SIMPLE script file you want to compile.  The extension .SIM is assumed
     if none is given.  CSS will scan through the source file and produce a
     compiled .SLC file.  If a syntax error is discovered while compiling
     the script, CSS will report it and abort.

     Simple requires that the CS.EXE SALT compiler reside in the DOS path.
     A complete listing of all SIMPLE scripting commands and structures is
     available in SIMPLE.DOC or in the printed manual.

     8.4 Learning a Script
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Some operations you will perform in Telix are highly repetitive, such
     as logging onto an online service.   The user name, password, and
     other information is always entered in the same order, the same way,
     every time you call.  You can use the Script Learn function to create
     an automatic log-on script to do this for you each call.

     To learn a sequence of responses to prompts, toggle the learn mode on
     from telix Terminal mode by pressing ALT-9.  Enter the name of the
     script to learn when prompted.   .SLT is assumed to be the filename
     extension if one is not given.

     Telix will record your responses to the various prompts of the online
     service until learning mode is turned off with ALT-9 again.   When
     turned off, Telix saves the learned script.   Remember, the learned
     script must be compiled prior to use.


     Telix v3.22                                   Using Script Files    57




     It is important while learning a script to remember to wait for the
     complete prompt to be displayed before responding.  Unpredictable
     results can be exhibited if a fast typist or a user familiar with a
     service types ahead of the prompts.

     Learned scripts, while useful, are not always completely accurate, and
     may not work without editing.   If the prompt being responded to
     contains information that can vary (such as the number of minutes left
     online), then the .SLT file may need to be edited prior to being
     compiled.  An example is the prompt on the Telix support BBS, which
     usually reads much like the following:

     (4 used, 86 left) Main Board Command?

     If there are not exactly 86 minutes remaining on your next call, a
     learned script containing this prompt will not function properly.
     The line in the learned script:

     waitfor("(4 used, 86 left) Main Board Command", 30);

     should thus be edited to read:

     waitfor("Main Board Command", 30)

     for proper operation of the learned script.

     Script learning is only available in registered versions of Telix.


     Telix v3.22                                            Host Mode    59





     9.  HOST MODE


     Telix allows you to set up your computer as a remote host, so that
     others may call your system and perform operations like transferring
     files and chatting. In short it is like having a small BBS on your
     system, without all the setup work. Telix provides two such host
     modes, both implemented in Telix's powerful SALT script language.
     QDHOST is a 'Quick and Dirty' host mode containing the basic features
     of a remote host, including password security and remote shells to
     DOS.   A more powerful host, HOSTPLUS, is also provided, offering the
     functionality of a full-featured BBS with multiple message bases and
     file areas, multiple security levels and individual password security
     and user levels.   The operation of HOSTPLUS is described in
     HOSTPLUS.DOC, or in a separate section of the printed documentation.

     There are a few requirements to running Host Mode. Your modem must be
     able to pick up the phone when it rings. Your modem must not be set to
     override (always keep on) the Carrier Detect signal it supplies, so
     that Telix can tell when it is connected to a caller. Telix must also
     be able to hang up the modem by dropping (turning off) the DTR line on
     the RS-232 port. If one of these requirements is not met you probably
     cannot run QDHost.

     To run the QDHOST script, press Alt-G while in Terminal mode, and then
     enter 'QDHOST' as the script file name. The script 'QDHOST' will then
     be run. Several Host Mode configuration settings are kept in a file
     called 'QDHOST.CNF'. The first time you run the Host Mode script, it
     will not find this file, and automatically run the host Mode configu-
     ration script 'QDCONFIG', which will created the needed file and allow
     you to change the default values. At any time in the future, you
     should run QDCONFIG when you need to configure the Host Mode. QDCONFIG
     will present you with the following parameters:

     A    Level One Access Password

          The password that callers must successfully enter to be admitted
          to the Host Mode and have Level One access.  Level one access
          allows only files contained in the specified QDCONFIG download
          directory to be downloaded.

     B    Level Two Access Password

          This is the password that callers must successfully enter to be
          admitted to QDHOST and have Level Two (Sysop) access.  Level two
          access allows the caller to download any file on the system by
          giving the path.

     C    DOS Shell Password

          This is the password that users of QDHOST have to enter to use
          the Remote DOS Shell option.


     Telix v3.22                                            Host Mode    60



     D    Shut Down Host Mode Password

          This is the password that callers must enter to shut down QDHOST,
          when they press Ctrl-Z.

     E    Host Download Directory

          Level 1 access callers will only be able to download (have Telix
          send them) files that are in this directory. As well, the 'F'iles
          command will show them only the contents of this directory. Do
          not under any circumstances define this directory to the same
          name as the directory you run Telix in. If you did that, callers
          could download the QDHOST configuration file, which is stored
          there, and see your passwords. Level 2 access callers may specify
          any download path, but this is the default.

     F    Host Upload Directory

          Level 1 access callers will only be able to upload (send to
          Telix) files into this directory. Level 2 access callers can
          specify any path, but files will go here by default.

     G    Connection Type

          This can be either 'Modem' or 'Direct'. Use 'Modem' if your host
          system is being accessed through a modem, or 'Direct' if two
          computers are hard-wired. This stops Telix from trying to ini-
          tialize a non-existent modem. or trying to determine the caller's
          baud.

     H    Locked Modem Rate

          For error correcting modems, QDHOST needs to know if the DTE rate
          (the speed Telix communicates with your modem) is constant from
          call to call, no matter what speed the user calls in at. Set this
          value to the fixed DTE rate (usually 9600 for 2400MNP modems, and
          19,200 or 38,400 for 9600+ baud modems). If your modem is not er-
          ror correcting or you are unsure what the value should be, set
          this value to zero.

     There is one other important parameter which must be properly set for
     QDHOST operation. This is the Auto Answer string, which is defined in
     the 'Modem and dialing' page of the Configuration Menu. This string is
     sent to the modem when Telix enters QDHOST, and should make the modem
     able to pick up the phone when it rings. The default string is set up
     for Hayes compatible modems. It is:

               AT X1 S0=1^M

     where

               AT        is the modem attention code.


     Telix v3.22                                            Host Mode    61



               X1        tells the modem to reply with extended result
                         codes. This means the modem indicates the caller's
                         baud rate.
               S0=1      tells the modem to answer after one ring.

               ^M        sends the terminating Carriage Return character.

     There are two optional text files which are displayed to callers if
     they exist, called LOGO.MSG, and WELCOME.MSG. They are described be-
     low.

     Once QDHOST has been configured, it can actually be run. Telix will
     make a note in the QDHOST audit file QDHOST.LOG and then will imme-
     diately send the Host Mode init string to the modem. Telix then waits
     for a caller. While in QDHOST on the local side, the user can always
     press Esc to exit Host Mode, or End to terminate the current caller.
     He can also enter commands for the remote caller, so that a novice
     caller can be helped along by the host operator. Also, at any time,
     the current caller will be automatically terminated if there is inac-
     tivity for five minutes, or the connection is lost. This is all noted
     in the host audit file. If the caller has only access level one, ref-
     erences to other disk directories than the ones defined in QDCONFIG
     are ignored, and all operations take place in those directories. As
     well, Telix protects your files from being accidentally overwritten by
     the caller.

     When the Carrier Detect signal turns on Telix knows a caller is on-
     line. At this point Telix will try to determine the caller's baud
     rate. Most Hayes compatible modems can be initialized to send the
     string 'CONNECT baud' where baud is the baud rate of the caller, when
     they sense a connection. If Telix sees this string it will switch to
     the appropriate baud. If this string is not received within a few sec-
     onds of the connection, Telix will leave the baud rate at whatever it
     was. Also, it should be mentioned that Telix can not determine the
     caller's other settings like parity, data bits, and stop bits. These
     must already be matching Telix's settings.

     At this point, if the file LOGO.MSG exists in the Telix directory, it
     is displayed to the caller. It should basically identify the system.
     Then Telix will ask the caller for his/her name. The name must be at
     least five letters long and is only used when indicating the caller in
     the Host Mode audit file. If a password has been defined Telix will
     ask the caller for it. The caller has three tries to complete the
     password. All password attempts, successful or failed, are written to
     the Host audit file. If the caller enters the Level One access pass-
     word, he may manipulate only the disk directories defined in QDCONFIG.
     Any other directories can not be accessed. If he enters the Level Two
     access password, the caller may use full pathnames in all file speci-
     fications. The level 2 password should only be kept for yourself or
     those you completely trust, as a Level 2 caller can access any files
     on your system.

     If there is a file called WELCOME.MSG in the Telix directory, it is
     then shown to the caller. This file can contain further identification


     Telix v3.22                                            Host Mode    62



     or news, that you only want valid callers to see. After each 23 lines
     the caller is prompted to press any key to continue. As well, the
     caller may press Ctrl-S to pause at any time, and Ctrl-C or Ctrl-K to
     abort the listing. After the WELCOME.MSG file is displayed the caller
     is presented with a menu of options:

             Files  Type  Upload  Download  Shell  Chat  Goodbye ?

     The action to be taken is selected by entering its first letter. Case
     does not matter. As mentioned already, the host operator is free to
     enter any keystrokes for the caller.

     The Files option allows the caller to list the files in the current
     disk directory. The caller must press a key after each screen. The
     output is not echoed on the local screen. If the caller has access
     level two s/he is prompted for a filespec, which may include the * and
     ? wildcard characters (see your DOS manual), so that the contents of
     other directories than the 'Host download dir' may be listed.

     The Type option allows the caller to view any ASCII file in the Host
     Download Directory, or in any directory for access Level 2 callers.
     The same format and commands are available during this command as for
     the displaying of the optional message file WELCOME.MSG.

     The Upload option allows the caller to send a file to the host. The
     caller is shown the following menu (here slightly compressed so it
     could fit):

     Modem7 SEAlink Xmodem 1k-Xmodem G-1k-Xmodem Ymodem Ymodem-g
     Which protocol?

     and should select the appropriate protocol by its first letter (or 'E'
     for Ymodem-g). If appropriate the caller is also asked for the file-
     name. The transfer is then initiated. Level 1 callers may only upload
     files into the 'Host Upload Directory' defined with QDCONFIG.

     The Download command allows a caller to receive a file from the host.
     The caller must select the protocol as described above, and then must
     tell Telix the file(s) to send. The transfer is then initiated. Level
     1 access callers may only download files from the 'Host Download Di-
     rectory' defined with QDCONFIG.

     The Shell command is a very powerful but also very dangerous command.
     It allows the caller to run a DOS shell on your system, except that
     the caller receives the output, and the caller enters the keystrokes.
     This command is basically similar to entering 'CTTY COMx' at the DOS
     prompt. The remote side has complete control of your system. This is
     obviously very dangerous, as the caller can format disks, delete
     files, or perform any other operation. To provide security, a password
     must be entered to use the remote DOS shell. Be very careful of whom
     you give this password to, as they can do anything they want with your
     system. As well, don't leave it at the default that Telix comes with.
     There are a few limitations in the remote DOS shell. The caller will
     see program output only if the programs use standard DOS output. Pro-


     Telix v3.22                                            Host Mode    63



     grams that write directly to the video screen will work, but will not
     be seen by the remote caller. As well, programs that use non-DOS meth-
     ods of getting keystrokes will not receive the callers keystrokes. Fi-
     nally, under some systems, if the caller presses Backspace at the DOS
     prompt when the current line is empty, DOS will hang on the Host ma-
     chine. As these are functions of DOS, there is nothing that can be
     done about these limitations.

     A potentially powerful feature of the shell function is the ability to
     override the use of CTTY and use your own redirector, such as Dudley
     Marshall's DOORWAY.EXE. Do not confuse DOORWAY.EXE with Telix's
     DOORWAY mode.  If the file RSHELL.BAT exists in the same as
     QDHOST.SLC, QDHost will run that batch file instead of using CTTY, and
     return to QDHOST when it is complete. DOORWAY.EXE is an excellent
     alternative to CTTY when both users need to see the screen, or when
     programs that write directly to the screen (such as Word Perfect) must
     be run from remote. The following is a sample RSHELL.BAT for use with
     the Doorway program:

          DOORWAY com1 /M:100 /O: /V:D^U /C:DOS

     Note that the com port must specified by number in the batch file.
     However, CTTY only supports COM1 and COM2, while Doorway can support
     up to COM4.  If you receive the message that you cannot shell due to
     DOS limitations, DOORWAY.EXE can be used as an alternative.  The
     latest version of DOORWAY including complete DOORWAY.EXE documentation
     is available on the Telix support BBS.

     The Chat command allows the caller to chat with the host operator.
     When the caller presses 'C' the host operator is paged for 20 seconds.
     Press the Space bar to chat with the caller, or any other key not to.
     Accepting the chat will place you in Chat Mode, exactly as if you had
     used the Alt-Y command. The caller's keystrokes are echoed back to
     him/her however, so that he/she can see them.

     Finally, the Goodbye command allows the caller to log off the host. An
     entry noting the time and date is made in the host audit file, and
     Telix then waits for a new caller.

     The caller may also use one other command that is not displayed in the
     menu. This is to shut down QDHost Mode. If the caller presses Ctrl-Z
     and successfully enters the shut down Host password defined in the
     Configuration Menu, the QDHost Mode is shut down and Telix returns to
     whatever it was doing before QDHost was initiated.


     Telix v3.22                                      Command Summary    65





     10. COMMAND SUMMARY

               ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
               ³ Major Functions                                           ³
               ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
               ³ Alt-B         Scroll Back                                 ³
               ³ Alt-D         Dialing Directory                           ³
               ³ Alt-F         DOS and File Functions                      ³
               ³ Alt-G         Run Script File (Go)                        ³
               ³ Alt-J              Jump to DOS Shell                      ³
               ³ Alt-K         Keyboard Definitions                        ³
               ³ Alt-L         Capture File                                ³
               ³ Alt-M         Misc. Functions                             ³
               ³ Alt-O         Configuration Menu                          ³
               ³ Alt-P         Comm Parameters                             ³
               ³ Alt-Q         Queue Redial Last Numbers                   ³
               ³ All-R         Download (receive) Files                    ³
               ³ Alt-S         Upload (Send) Files                         ³
               ³ Alt-T         Terminal Emulation                          ³
               ³ Alt-U         Usage Log                                   ³
               ³ Alt-W         Translate Table                             ³
               ³ Alt-X         Exit Telix                                  ³
               ³ Alt-9         Learn a Script                              ³
               ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ


               ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
               ³ Secondary Functions                                       ³                                                           ³
               ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
               ³ Alt-A         Run Editor                                  ³                                                           ³
               ³ Alt-C         Clear Screen                                ³                                                           ³
               ³ Alt-E         Local Echo on/off                           ³                                                           ³
               ³ Alt-H         Hang-up Modem                               ³                                                           ³
               ³ Alt-I         Screen Image                                ³                                                           ³
               ³ Alt-T         Translate Table                             ³                                                           ³
               ³ Alt-V         DOS Command                                 ³                                                           ³
               ³ Alt-Y         Chat Mode                                   ³                                                           ³
               ³ Alt-8         Toggle Status Line on/off                   ³                                                           ³
               ³ Alt-=         Toggle DOORWAY Mode on/off                  ³                                                           ³
               ³ Ctrl-@        Printer Log on/off                          ³                                                           ³
               ³ Ctrl-End      Send Break Signal                           ³                                                           ³
               ³ Shift-Tab     Add Line-feeds on/off                       ³                                                           ³
               ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ


     All of these commands should be entered while in terminal mode. Many
     will prompt you for further courses of action.


     Telix v3.22                                Questions and Answers    67





     11. TROUBLESHOOTING


     Problem:

     Telix and the modem do not seem to be able to detect busy signals.

     Solution:

     Some modems (especially older 1200 bps units) do not have the capabil-
     ity to detect busy signals. Assuming yours does, you'll still probably
     have to edit the default modem Init String. The X1 that Telix uses in
     the string to be compatible with all modems does not enable busy de-
     tection in most modems. Try a value like X3, X4, or higher.

     Problem:

     When the QDHost Mode script is run Telix always thinks that a caller
     is online and immediately asks for the caller's name or Telix always
     says that a Hang-up operation failed even when it did in fact success-
     fully hang-up the modem.

     Solution:

     Your modem is almost certainly overriding the true state of the Car-
     rier Detect signal. This is the factory default on most modems, but
     should be disabled. For proper operation, Telix needs to see this sig-
     nal on when connected to another computer, and off when not. If your
     modem has dip switches, as do most 1200 bps units and all US Robotics
     external Couriers, switch number 6 usually controls this and must be
     in the up position. If your modem does not seem to have any dip
     switches (look carefully, sometimes the front needs to be popped off),
     it is probably controlled solely by software commands, as are most
     2400 bps units. Just a few examples of these are the Hayes 2400, ATI
     2400etc., GVC 2400, and many others. For these modems, adding &C1 in
     the modem Init String (before the final ^M (Carriage Return is a good
     spot)) will configure the modem properly.

     Problem:

     When trying to use a multi-tasking system like MS Windows, Topview, or
     DoubleDOS, with Telix in the background, window displays bleed through
     to the active partition.

     Solution:

     In the Telix Configuration Menu, select the 'Screen and colors set-
     tings' option, then select as the Screen Write Mode, 'BIOS calls used
     for writes'. Screen updating will be slower but will not bleed
     through.


     Telix v3.22                                Questions and Answers    68



     Problem:

     When redialing Telix does not seem to know when a connection has been
     reached.

     Solution:

     Telix knows when a connection has been reached in one of two ways:
     when it receives a Connect string from your modem, or when the Carrier
     Detect signal turns on (if it was off). Make sure that the Connect
     string is properly defined in the Configuration Menu, or that your mo-
     dem does turn on the Carrier Detect signal regardless of whether or
     not there is a connection.

     Problem:

     Telix doesn't work with a certain modem.

     Solution:

     Telix is set by default to use the Hayes 'AT' modem command standard.
     There are modems that are not Hayes compatible however, and use other
     commands to dial, hang up, and perform other tasks. Make sure that if
     your modem is not Hayes compatible Telix has been properly configured
     to its commands.

     Problem:

     When trying to use the DOS Shell, or another function that uses DOS,
     Telix warns that it can not find a file called COMMAND.COM, and aborts
     the function.

     Solution:

     The file COMMAND.COM is the DOS command interpreter. Telix must be
     able to find it to use many DOS functions. The location of COMMAND.COM
     is stored in an environment variable (explained in your DOS manual)
     called COMSPEC. COMSPEC is set at boot-up, but if you boot of a floppy
     and then change to another floppy or a hard disk, it will not point to
     the right place anymore. In short, make sure that COMSPEC always
     points to the location of COMMAND.COM, or that COMMAND.COM is in the
     current directory.

     Problem:

     When calling some systems, especially large ones such as Compuserve or
     the Source, all incoming characters look like garbage.

     Solution:

     The communications parameters are probably wrong. Most of these sys-
     tems need a setting of Even parity, 7 data bits, and 1 stop bit. This
     is different from the normal standard of N81 used for most bulletin
     boards.


     Telix v3.22                                Questions and Answers    69



     Problem:

     When running Telix, it reaches the "initializing modem" screen but
     won't go any further.

     Solution:

     Unfortunately, the solution here is not simple, and requires some
     knowledge of hardware. If you are not comfortable with configuring or
     jumpering your hardware, please contact a qualified computer consul-
     tant or service shop. The problem is likely that two devices in the
     computer wish to use the same part of the computer at the same time
     (called using the same interrupt). This will be the case with internal
     modems on COM3 or COM4, when you have other serial devices (mice,
     Sound Blaster cards, network interface cards, or other interrupt
     driven devices). By default, COM1 shares an interrupt with COM3, and
     COM2 shares with COM4. Only one device may use an interrupt at a time.
     You should try to place your internal modem on an unused interrupt
     (IRQ 5 is free in most AT or 386 class systems), and then tell Telix
     under the Configuration menu that COM3 or COM4 now uses IRQ5.

     Problem:

     During transfers with a high speed modem, many CRC and/or timeout er-
     rors occur.

     Solution:

     First ensure that CTS/RTS hardware flow control is enabled  and that
     DSR/DTR hardware flow control is disabled both in Telix under the Con-
     figuration menus in the Terminal Options section and in your modem
     (refer to your modem manual for instructions on setting up your modem
     properly, or use the MODEMCFG.EXE program). If this fails, it may sim-
     ply be hardware limitations.  Sometimes such hardware limitations can
     be circumvented by running Telix with the /D parameter.

     Many high-speed modems, especially in a multitasking (Windows,
     DESQview, TopView, etc.) environment or on XT or slower AT-class ma-
     chines are simply too fast for the hardware, and may need some help to
     prevent lost characters. A UART (Universal Asynchronous Receiver-
     Transmitter) is a chip found on every serial card or internal modems.
     Most serial cards or internal modems come stock with 8250 or 16450
     chips that are not rated for high speed modems. A replacement chip
     called the NS16550AN will likely eliminate such problems.

     Problem:

     When I run Telix from my menu program it tells me "Unable to find/open
     ANSI.KEY" and goes back to the menu program.

     Solution:

     ANSI.KEY is a file required for Telix operation, but due to the menu
     not changing to the Telix directory, Telix cannot find this file.


     Telix v3.22                                Questions and Answers    70



     Telix expects to find all of it's system files in the current
     directory or in the directory pointed to by the TELIX environment
     variable.

     An environment variable is a setting that DOS can look at (or other
     programs, like Telix) to find out certain information it needs.

     By placing the command:

     SET TELIX=C:\TELIX

     in your AUTOEXEC.BAT (modified for your own Telix path, of course)
     Telix will then know to look there for all of it's files if they are
     not in the current directory. There should be no spaces in the command
     as above, other than between SET and TELIX.

     Problem:

     I have call waiting on my phone line and whenever someone calls me
     while I'm online, I get disconnected.

     Solution:

     Call waiting is usually disableable on outgoing calls only.    Contact
     your operator or phone company to determine if it can be disabled, and
     if so, what the codes are in your area.  In many areas, it is *70, so
     we will use that as an example.

     First, check your modem manual to insure that the modem is capable of
     dialing all the necessary characters like * or #. If not, you will
     have to do this by hand on your phone before each call, or ask the
     operator if there are alternatives (often 1170 will work, but it takes
     longer).

     If your modem CAN dial the needed characters, or you are told of a
     suitable substitute, edit the dialing prefixes under Telix's Config:

     ALT-O - Modem and Dialing - Options B,C,D

     Insert after each "DT" (or DP if on pulse dialing) the appropriate
     call waiting cancel string.   Note that often a comma is necessary as
     a pause to get a second dial tone.  Once this is saved permanently to
     your Telix config ("W"rite setup to disk), you're set.  Most often
     these will be:

     ATDT*70,

     Problem:

     I have a new 14,400 bps modem, but Telix doesn't support 14,400 as a
     speed option.

     Solution:


     Telix v3.22                                Questions and Answers    71



     This is one of the great misconceptions about high speed modems, so
     you're not along in wondering this.  Let me try to detail why it
     doesn't matter, and at the same time give you a bit of an idea what's
     going on behind the scenes when you call another modem...

     The link to get from your computer to the other computer looks much
     like this:

     Telix <--> Your modem <--> Their modem <--> Their computer

         DTE rate        DCE rate         DTE rate
          38,400          14,400           57,600

     As you can see, it is really a series of three links;  one between
     your computer and your modem, one between the two modems, and one
     between their modem and their computer.   What might surprise you is
     that each of these three rates can be, and often are, completely
     different, as above.   So you know, DCE stands for Data Communications
     Equipment (i.e. a modem to modem link) and DTE is Data Terminal
     Equipment (i.e. terminal to modem link). You are not concerned with
     the final link, the remote DTE rate. That is up to the remote site,
     and does not matter at all to you. Once the data leaves your modem,
     and is received by theirs, it is out of your hands.

     Your modem likely has either MNP-5 or v.42bis data compression built
     in.  For transferring non-.ZIP files, these modems can be extremely
     efficient in compressing the data before sending it -- sometimes as
     much as 4 times compression (25% of the original size).

     If the modems can take 1000 characters from Telix, and then turn it
     into perhaps as little as 250 characters with compression, your modem
     still transmits at 14,400 and would need 1000 characters from the comm
     program to transmit a mere 250 characters. In order to keep the DCE
     link flowing with data non-stop, Telix has to send data to your modem
     at 4 times the speed the modem is talking to the other modem (in the
     best case, which almost never happens).  Thus, the DTE (Telix to modem
     rate) must be higher than the DCE (modem to modem rate) by a good
     margin, or the modems will sit idle frequently, waiting for the comm
     program to supply it with enough data.   Since you have no way of
     knowing how much the data will be compressed, or at what speeds the
     two modems will actually connect up at, you should ALWAYS leave the
     DTE rate on your end (the link between Telix and your modem as
     specified in the Telix configuration) locked in, or fixed, at that
     high rate that can accommodate the most efficient case, since that
     most efficient case can occur at any time.

     That's why you're always advised by MODEMCFG.EXE to set the comm
     program's speed, as well as all dialing directory entries (no matter
     how fast the board actually is), to a speed higher than the 9,600 or
     14,400 you really have.    Typically, you'll be told to use 19,200 or
     38,400 (nowadays, typically 38,400, and even some will say 57,600).
     But the important thing is, that speed is constant.   Your DTE
     (program to modem rate) always stays the same, so that when that most
     efficient case comes along, you're ready.


     Telix v3.22                                Questions and Answers    72



     Problem:

     When trying to transfer a file, telix just sits there saying "Waiting
     to send." or "Waiting to receive" but nothing ever happens.

     Solution:

     When a user is downloading, the other system is by definition
     uploading to him. BOTH systems must know exactly what is happening at
     every given moment, and this is especially true at the beginning of
     the transfer.

     First the downloader must tell the remote system (the one to be
     downloaded FROM) that s/he requests a download. On most systems, this
     is accomplished with the "D"ownload command.

     The sending system will then ask the downloader to choose a protocol.
     You may choose any one that Telix supports, but we recommend Zmodem if
     it is available, and 1K-Xmodem (sometimes labeled Ymodem) if Zmodem is
     not available. In any case, the important thing to remember is that
     BOTH the sender and the receiver must be using the same protocol, and
     it must be agreed upon in advance.

     Perhaps before choosing a protocol, you will be asked what files you
     wish to download. Then the system may tell you that it is ready to
     send the files. If you have selected Zmodem, and have Zmodem auto-
     downloads on in Telix (the default) you should not have to do anything
     more.   Telix will sense the Zmodem transfer coming and go into ZModem
     receive mode. Sometimes this will appear as "garbage" like an up
     arrow, a bunch of asterisks, and numbers like 0's and 8's.  This is a
     signal to start!

     The most important thing to remember when downloading is that first
     you have to tell the other system what to send and how to send it, and
     let it get started.   As soon as the other system starts, you
     generally have about 30 to 60 seconds to start your receive with the
     SAME protocol.  It is crucial that both sides know that a transfer is
     taking place.   You cannot start yours early, or the other side will
     never send the file.

     Thus, don't hit Alt-R (or PgDn) until you are *sure* the other side is
     ready to send, and ready for you to tell it that you are ready to
     receive (ALT-R does this automatically).

     Problem:

     When trying to compile a script I get the message "Unable to open
     file" even though I know the script is present.

     Solution:

     Some OEM versions of DOS 2.11 (notably, the Tandy DOS burned into the
     1000 HX) are incompatible with the compiler used in these cases. This
     does not apply to Telix itself.


     Telix v3.22                                Questions and Answers    73



     It is highly recommended that you upgrade your DOS if possible.   For
     users with the DOS burned into the ROM of the machine, you may boot
     from a system floppy of a higher DOS system to compile scripts.

     Problem:

     When I start a download, the transfer window disappears very fast,
     with a message that looks like "Unable to open file", and no transfer
     takes place.

     Solution:

     Telix expects to be able to open a new file in the subdirectory you
     have defined for the Download Directory under ALT-O/Filenames and
     Paths. If this subdirectory does not exist, that will cause this
     message to appear:

     "Unable to open file!"

     This is a sure sign that you need to check your configuration in this
     area, and either create the defined subdirectory from the DOS prompt
     with the MKDIR command, or to change the configuration under ALT-O/F
     to reflect the location of an existing path.

     Problem:

     When I transfer a file, sometimes letters flash in the lower right
     corner of the transfer window.

     Solution:

     This is completely normal, and signifies a "flow" control, or a signal
     to Telix or the modem to slow down or stop momentarily.   It signifies
     that things are in good working order.

     Problem:

     How do I telix to operate reliably under Microsoft Windows?

     Solution:

     TELIX.PIF included with Telix is a Program Information File for
     Windows that should allow best operation of Telix under Microsoft
     Windows.   Windows doesn't offer the best of communications handlers,
     though, and for best communications results under Windows, we
     recommend a Windows-based program.  deltaComm is currently programming
     a Windows comm program expected to be released in the first half of
     1994.

     Problem:

     My modem requires compatible software to use the MNP features of my
     modem, or it says it needs RPI compatible software.  Is Telix
     compatible in this way?


     Telix v3.22                                Questions and Answers    74



     Solution:

     No, it is not, and there is little likelihood that we will support RPI
     or software MNP in the near or distant future.   RPI is an attempt by
     Rockwell and the modem manufacturers to create a cheaper modem (by
     about $5) by pushing off some of the hardware implementation into
     software.   We disagree with this for the sole reason that software
     cannot be as efficient as hardware (esp. when coprocessed), and that
     these functions truly belong on the hardware for efficiency and speed.
     Most comm developers we know feel the same way and without our support
     the manufacturers will have to go back to putting these functions on
     the hardware -- where they belong.

     Our recommendation is to take the modem back to the place of purchase,
     and don't leave until you get a REAL MNP/v.42bis modem at exactly the
     same price, because what you bought was not what you thought you did,
     and the only way the industry will stop these shenanigans is for the
     ones being taken advantage of to stand up for themselves and do
     something about it.

     Problem:

     We have our modems on a network and we need a network version of Telix
     in order to access them.  Does Telix have network support built in?



     Solution:

     Networking a comm program, or using a modem across the network as a
     resource requires two things.

     1) The network must be NETBIOS compliant.

     2) The comm program must use the BIOS (Int-14) for comm routines.
     Telix normally bypasses the slower BIOS and writes directly to the
     comm port for speed considerations, making it incompatible with
     networks.

     However, we have developed a version of Telix which uses the Int-14
     calls, and it is now available as a separate product.   please call
     our sales staff for more information about Telix for Networks.

     Problem:

     When I run QDHost it says "Either the upload or download directory as
     defined in the Host config does not exist" and then aborts.   What
     now?

     Solution:

     If you receive this message when running the QDHost mode then you need
     to do the following:


     Telix v3.22                                Questions and Answers    75



     From Telix Terminal mode (the blank screen that you are at after the
     opening screen goes away), press ALT-G, and type "QDCONFIG".  The
     QDCONFIG.SLC script must exist in the same directory as QDHOST (i.e.
     in the script directory as defined under ALT-O/Filenames).

     You will then see a menu that pops up something like this:

     A: Level 1 password       : pass1
     B: Level 2 password       : pass2
     C: Remote Shell password  : shell
     D: Shut down host pass    : shut
     E: Host download directory: C:\TELIX\HSTFILES\     <------
     F: Host upload directory  : C:\TELIX\HSTFILES\     <------
     G: Connection type        : Modem
     H: Modem locked at >= 9600: No

     I: Exit without saving changes.
     J: Exit and save changes to disk.


     The indicated lines are the ones that need to be changed.  You can
     either Exit without saving and then do MKDIR with the above paths:

     MKDIR C:\TELIX\HSTFILES

     or, better, is to change options E and F above to paths that you know
     already exist (NEVER set these equal to your Telix subdirectory!), and
     then "Exit and Save Changes to Disk".  For more information concerning
     DOS paths, please consult your DOS manual.

     Problem:

     When calling from our office we have to use a credit card number, but
     the whole number won't fit in the dialing directory.  How can
     telephone credit cards be used with Telix?

     Solution:

     The MODEM is going to be your bottleneck here. Most modems cannot take
     as many characters at once as a comm program can send out. The vast
     majority of modems have a 40 character command string limit, which
     must include the <ENTER> at the end, and the ATDT (or ATDP) at the
     beginning.  Spaces, dashes, and any directives for MNP and such in the
     dialing prefixes also count.

     Telix can, with the use of long distance codes, send much more than
     this, but the modem will not likely respond to this, since anything
     past 40 characters is simply ignored (and this includes your <ENTER>
     at the end).

     Many long distance companies have gone to 13 character card codes to
     protect you against fraud, and this is a good idea.   However, it does
     limit you via your modem (again, Telix is not the limitation here).


     Telix v3.22                                Questions and Answers    76



     In the number you wish to dial, rather than making the number in the
     directory read:  "1-919-481-9399"

     Save space (it's STILL tight) and make it read:  "1-919-481-9399!"

     The exclamation point tells Telix to append the contents of that code,
     and the code can be edited to include any sequence you wish, under
     Alt-D/Other/Edit LD codes.

     Problem:

     Telix seems to be grossly optimistic when estimating the length of
     time it will take to transfer a file.  Its usually about four times
     slower than Telix thinks it will be.  Why is this?

     Solution:

     Previous versions of Telix merely estimated transfers based on the
     speed that Telix dialed at (the DTE), even though this could be up to
     four times greater than the actual connect speed.

     Telix 3.22 now makes its best attempt to read the actual connect speed
     (DCE), but needs a little cooperation from the modem.  Telix cannot
     determine the DCE on its own -- it must rely on the modem to report
     it.

     Telix must accept the rate that the modem offers -- it has no way to
     "validate" it.  The best way to demonstrate this is to dial a number
     without using the dialing directory.  Type ATDT and the number, and
     press Enter.   Watch for the first string that displays.   It will be
     something like:

          CONNECT 14400/ARQ/V42BIS/LAP-M

     If you have a vanilla 2400:

          CONNECT 2400

     If the dialing directory had been used, Telix would have read the
     connect rate as 14400 in the first case and 2400 in the second.
     (Telix reads the connect rate as the first number to follow the
     connect string on the same line as the connect string).  Some modems,
     however, (notably newer v.32bis modems) can be configured to return
     very detailed information like this:

          CARRIER 14400

          PROTOCOL: LAP-M

          CONNECT 57600/V32BIS/V42BIS

     Now, if your connect string was "CONNECT", the value is not the 14400
     you wanted, but the 57600 you didn't want.  In this case, you need to
     find the command in the modem manual that disables extended result


     Telix v3.22                                Questions and Answers    77



     codes (often the S95 or S44 registers)  and reverts to the simple
     CONNECT 14400/ARQ/V42BIS string as above -- then Telix will get the
     connect string you wanted.

     Another option above (but not for all such modems) is to change the
     connect string to match the word right before the number.  Above,
     you'd change the connect string to CARRIER.   This one won't always
     work, and it is best to disable extended result codes if you want
     correct estimates.

     Some modems do not return a correct response string at all, such as
     the older US Robotics HST Dual Standard 1441 (v.32/ 9600) modems.
     They return 9600 even if the connect was at 14400, and your estimates
     in such cases will err by the difference.


     Telix v3.22                                      Product Support    79





     12. PRODUCT SUPPORT


     Telix is a relatively large and complicated program. In order to sup-
     port Telix and to provide a means of distribution, a BBS (Bulletin
     Board System) for Telix support has been set up.

     The Telix Software Support BBS is available 24 hours a day at 919-481-
     9399. The Support BBS accepts calls from 300 baud to 9600 baud and be-
     yond, including v.32/v.32bis calls, and HST calls at 14,400 baud. If
     you have a Telix question or problem, or have found a bug in Telix,
     give the support BBS a call. The latest version of Telix may also be
     found on the support BBS.

     If you're calling about a problem, try to be as specific as possible
     when describing the problem. Include any relevant details, such as
     your machine's configuration, Telix version number, resident software
     installed, steps taken before the problem happens, and any other
     things you feel are important. It is very hard to answer vague ques-
     tions such as, "Telix doesn't work on my PC. Do you know why?".

     At the current time, the support BBS is open to all callers. Since it
     is extremely busy, it is almost certain that in the future it will be
     restricted to registered users of Telix. Registered users will also
     receive mailed notices of major updates to the program.


     Telix v3.22                                   External Protocols    81





     13. EXTERNAL PROTOCOLS



     While Telix supports a very large number of protocols internally, it
     also allows users to define up to 5 external protocol implementations,
     for the utmost in flexibility.

     External protocols are defined in the 'Protocol options' page of the
     Configuration Menu. Basically, based on this configuration, when the
     user selects a transfer with this protocol, Telix will either run a
     specified DOS Batch file, or a TELIX SALT script file.


     13.1 Batch File Method
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     If a Batch file has been configured to be executed when the external
     protocol is selected, TELIX will execute it and pass to it 3 parame-
     ters (with the third sometimes being blank). The first parameter is
     the baud rate. This is accessed within the DOS batch file as %1. The
     second parameter is the comm port number. This is accessed as %2. The
     third parameter is the reply the user gave when asked what file(s) to
     transfer. If this is a download and this protocol has been defined to
     not need a download name, this parameter will be blank. If this is an
     upload via an external protocol defined as an "@" protocol (see
     Configuration, Protocols), this parameter will be "FILELIST",
     otherwise, will be the list of files to send. This parameter is
     referred to as %3 in the Batch file.

     It is now the responsibility of the Batch file to call a driver pro-
     gram for the protocol, using the supplied info. For example, assuming
     Telix didn't have built-in Zmodem support, a batch file called SZB.BAT
     could be defined to perform Zmodem uploads using the commonly avail-
     able DSZ program with the following command in it.

          DSZ port %2 speed %1 sz %3

     This would tell DSZ what files to transfer, and also would specify the
     proper baud rate and comm port.

     If DSZ were an "@" protocol, the command would be:

          DSZ port %2 speed %1 sz @%3

     13.2 Script File Method
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Alternately Telix can run a SALT script file when the user selects an
     external protocol. The script should be compiled ahead of time (as ex-
     plained elsewhere in this manual). The user's reply to the question of
     what files to transfer is stored in the system variable _ext_filespec.


     Telix v3.22                                   External Protocols    82



     The script file is free to implement the protocol in whatever way it
     wants to, such as calling an external driver program using the 'RUN'
     function, or by actually performing the transfer itself.


     Telix v3.22                                         File Formats    83





     14. FILE FORMATS


     For programmers who wish to write dialing directory handling utili-
     ties, a text file describing the dialing directory format used by
     Telix is available on the Telix Software Support BBS as T3FONFIL.DOC.


     Telix v3.22                                                Index    85



                                             Auto baud detect........42, 61
                                             Auto-downloads..............38
     15. INDEX                               AUTOEXEC.BAT................70
                                             Automatic log-on....21, 55, 56
     +++.........................42          Automatic Queue Redial......27
     ^...........................10          Backspace...................37
     ~...........................10          Backspace Key Character.....37
     ~~~.........................42          Batch Ymodem................33
     14,400......................70          Baud detect.................42
     16550a chip.............40, 69          Baud rate............8, 36, 61
     Aborted downloads...........39          BIOS.........................6
     Add.........................23          BIOS calls..................36
     Add Line Feeds..........18, 37          Blank Lines.................44
     Alarm Sound.................38          Bleedthrough, screen........67
     Alt-=.......................18          Break Signal................18
     Alt-8........................8          Buffer size.................47
     ALT-9.......................56          BUSY........................41
     Alt-A.......................15          Busy signal detection.......67
     Alt-B.......................13          Busy strings................41
     Alt-C.......................18          Call waiting................70
     Alt-D....................7, 21          Capture.....................11
     Alt-E.......................18          Capture file................43
     Alt-F.......................15          Capture File Buffer Size....39
     Alt-G.......................55          Carrier Detect...............2
     Alt-H.......................11          Character Pacing............45
     Alt-I...................16, 44          Character translation.......16
     Alt-J.......................14          Chat Mode...............17, 63
     Alt-K.......................13          Chdir.......................16
     Alt-L.......................11          Checksum....................32
     Alt-M.......................19          CIS Quick B.................38
     Alt-O.......................35          Clear.......................24
     Alt-P........................8          Clear Screen................18
     Alt-Q.......................27          Comm parameters..............8
     Alt-R.......................29          Comm port setup.............48
     Alt-S.......................30          Command line switches........6
     Alt-T.......................51          COMMAND.COM.............14, 68
     Alt-U.......................11          Compuserve Quick B..........38
     Alt-V.......................15          Compuserve Quick B protocol.32
     Alt-W.......................17          COMSPEC.....................14
     Alt-X.......................10          CONFIG.SYS...................3
     Alt-Y...................17, 63          Configuring Telix...........35
     Alt-Z........................7          CONNECT.....................41
     ANSI........................51          Connect status...............7
     ANSI-BBS....................51          Connect String..............41
     ANSI.KEY....................69          Connection..................42
     Answerback string...........38          Connection detection........68
     ASCII....................7, 30          Connection Type.............60
     ASCII Transfer Setup........44          CR Translation..............45
     ASCII transfers.............33          CR/LF.......................18
     AT..............40, 41, 42, 60          Crash recovery..............47
     ATDT........................41          CRC.........................32
     Audit file..................61          CRC Error...................69
     Auto answer.................41          Create (dialing directory)..26
     Auto Answer string..........42          Credit card number..........75


     Telix v3.22                                                Index    86



     Ctrl translation char.......10          Duplex..................18, 37
     Ctrl-C......................62          Echo........................44
     Ctrl-End....................18          Echo, local.................37
     Ctrl-K......................62          Echo locally................18
     Ctrl-S......................62          Edit........................23
     CTS/RTS handshaking.........37          Edit_LD.....................26
     CTTY COMx...................62          Editor......................15
     Data bits................9, 36          Editor Pathname.............44
     Data Terminal Ready.........42          Elapsed time.................7
     Date Format.................39          Emulation vs. Translation...36
     Date Separator Character....40          Ending a Telix Session......10
     Default Capture File........43          Enhanced Keyboard Support...40
     Default d/l path............43          Environment variable.....3, 14
     Default Local Echo..........37          Exiting Telix...............10
     Default screen size.........36          Expand blank lines..........44
     Default Script dir..........43          External protocols..29, 45, 81
     Default terminal............36          File transfer buffer........29
     Default u/l directory.......43          File Transfer Disk Buffer
     Default Usage Log...........43              Size....................47
     Delete......................26          File Transfer Protocols.....32
     Delete File.................16          File Transfers..............29
     DESQview....................36          Filename Guessing...........47
     Destructive backspace.......37          Files Directory.............16
     Dial Cancel String..........42          Files=.......................3
     Dial Time...................42          Find........................24
     Dialing directory...........21          Flow control............37, 73
       Adding....................23          Free space..................39
       Clearing..................24          Function keys...............13
       Deleting..................26          Garbage characters..........68
       Dialing...................24          Handshaking.................37
       Editing...................23          Hang-up.....................39
       Finding an Entry..........24          Hang-up string..........11, 42
       Inserting.................25          Hanging-up..................11
       LD Codes..................26          Hardware.....................2
       Long Distance Codes.......24          Help/Status Screen...........7
       Other Functions...........25          High bit................37, 44
       The Display...............21          Home........................13
     Dialing Postfix.............41          Host Download Directory.....60
     Dialing Prefix..............41          Host Mode................2, 59
     Direct screen write.........35          Host problems...........67, 74
     Directory program.......16, 43          Host shell password.........59
     Disk buffer size............47          Host Upload Directory.......60
     DOORWAY Mode................18          Insert......................25
     DOS 2.11....................72          Inserting entries...........25
     DOS and File Functions......15          Int-14......................74
     DOS Command.................15          Keep Aborted................39
     DOS Shell............2, 14, 62          Kermit protocol.............33
     DOS Shell Password..........59          Kermit Transfers............48
     DoubleDOS...................36          Keyboard definitions........13
     Download Directory..........43          Keyboard macros.............13
     Downloading Files...........29          LD Codes....................26
     Drive/Directory.............16          Learning a Script...........56
     DSR/DTR handshaking.........38          Level One Access........59, 61
     DTR..............2, 11, 42, 59          Level Two Access........59, 61


     Telix v3.22                                                Index    87



     LF......................18, 37          Screen dump file............44
     LF Translation..............45          Screen Image............13, 16
     Line Feed...............18, 37          Screen image file.......13, 44
     Line Pacing.................45          Screen size.................19
     Linked scripts..............55          Screen write mode...........35
     Load (dialing directory)....26          Script Directory............43
     Local echo..............18, 44          Script files.............6, 55
     Locked Modem Rate...........60          Scripting...................55
     Lockups, causes.....11, 63, 69          Scroll-Back.................13
     Long distance Codes.........26          Scroll-Back size............39
     Machine Requirements.....2, 72          SEAlink protocol............33
     Menus, using.................9          Send Files..................30
     Microsoft Windows...........73          Sending modem strings.......19
     Misc. Functions.............19          Session Capture.............11
     MNP.........................73          Settings, comm...............8
     Modem init string...........41          Shift-Tab...................18
     Modem Setup.................40          Show Free Space.............39
     Modem7 protocol.............33          Shut Down Host..............60
     MODEMCFG.EXE.................5          SIMPLE......................56
     Network support.............74          Slow handshaking.............6
     NO CARRIER..................41          Snow........................36
     No connect strings..........41          Sound.......................38
     Online.......................6          Split screen................17
     Output String Translation...10          Status Line..............8, 37
     Pace Character..............44          Stop bits................9, 36
     Pacing..................44, 45          String editing...............9
     Parameters, comm.............8          String entering..............9
     Parity...................9, 36          String translation..........10
     Partial files...............39          Strip High Bit..........37, 44
     Pause capture...............11          Swapping....................40
     Pause translation char......10          Telink protocol.............33
     PgDn........................13          TELIX.......................70
     PgUp........................13          Telix Configuration Menu....35
     Printer.....................11          Telix files..................2
     Printing (dialing directory)26            TELIX.CAP..................3
     PRN.........................26            TELIX.FON..................2
     Protocol options............45            TELIX.KEY..................3
     QDCONFIG....................59            TELIX.LD...................3
     QDHOST.LOG..................61          Telix Software Support BBS..79
     Queue Redial................27          TELIX.CNF................6, 35
     Quick B.....................38          TELIX.FON................6, 21
     Quick Dial Bar..........28, 39          TELIX.IMG...................16
     Quiet........................6          TELIX.MSG...................44
     RAM requirements.............2          TELIX=.......................3
     Receive Files...............29          Terminal....................51
     Redial......................27          Terminal, default...........36
     Redial Pause................42          Terminal emulation..........51
     Redial time.................42          Terminal options............36
     Relaxed Xmodem..............47          Time Format.................40
     Remote DOS shell............62          Time Separator Character....40
     RPI.........................73          Timeout error...............69
     RSHELL.BAT..................63          Topview.....................36
     SALT........................55          Transfer buffer.............29
     Screen dump.................16          Transfer problems...69, 72, 73


     Telix v3.22                                                Index    88



     Translate Ctrl char.........10
     Translate pause char........10
     Translate table.............16
     Trigger String..............46
     TTY.........................51
     Unable to open file.........73
     Upload Directory............43
     Uploading Files.............30
     Usage Log...........11, 39, 43
     VT102.......................52
     VT52........................53
     WELCOME.MSG.................61
     Windows.....................73
     Xmodem protocol.............32
     Xmodem-1k protocol..........32
     Xmodem-1k-g protocol........32
     XON/XOFF handshaking........37
     Ymodem protocol.............33
     Ymodem-g protocol...........33
     Zmodem 32 bit CRC...........47
     Zmodem auto-downloads.......38
     Zmodem File Type............48
     Zmodem protocol.............32
     Zmodem Receive Crash Recovery
         47
     Zmodem Send Crash Recovery..47
     Zmodem Window Size..........48
