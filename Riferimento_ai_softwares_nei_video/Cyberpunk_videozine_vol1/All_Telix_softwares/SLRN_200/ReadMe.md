





























          | SLEARN (SALT learn utility) v2.00
          |
          | A SALT script creator for Telix
          |
          | Copyright (c) 1990-1992 by Paul Roub
          | All Rights Reserved
          |
          | Documentation printed September 21, 1992







                                     Contents

     Introduction  . . . . . . . . . . . . . . . . . . . . . . . . . . .   1
          Contacting the author  . . . . . . . . . . . . . . . . . . . .   1
          ACKNOWLEDGEMENTS . . . . . . . . . . . . . . . . . . . . . . .   1
          Notes  . . . . . . . . . . . . . . . . . . . . . . . . . . . .   2

     Why use SLEARN? . . . . . . . . . . . . . . . . . . . . . . . . . .   3
          What's the problem?  . . . . . . . . . . . . . . . . . . . . .   3
          What's the solution? . . . . . . . . . . . . . . . . . . . . .   4
          System Requirements  . . . . . . . . . . . . . . . . . . . . .   4

     Setup and Installation  . . . . . . . . . . . . . . . . . . . . . .   5

     Using SLEARN  . . . . . . . . . . . . . . . . . . . . . . . . . . .   7
          Learning a Script  . . . . . . . . . . . . . . . . . . . . . .   7
          File Transfers (registered version only) . . . . . . . . . . .   7
          Saving your Script . . . . . . . . . . . . . . . . . . . . . .   8

     Command-Line Usage  . . . . . . . . . . . . . . . . . . . . . . . .   9

     Configuration Options . . . . . . . . . . . . . . . . . . . . . . .  11
          Comm port address  . . . . . . . . . . . . . . . . . . . . . .  11
          Comm port IRQ  . . . . . . . . . . . . . . . . . . . . . . . .  11
          Rows on screen . . . . . . . . . . . . . . . . . . . . . . . .  11
          Use status line  . . . . . . . . . . . . . . . . . . . . . . .  11
          Status line row  . . . . . . . . . . . . . . . . . . . . . . .  11
          Status line background color . . . . . . . . . . . . . . . . .  11
          Status line foreground color . . . . . . . . . . . . . . . . .  11
          Sound bells when SLEARN.EXE is run . . . . . . . . . . . . . .  11
          Default Background Color . . . . . . . . . . . . . . . . . . .  11
          Default Foreground Color . . . . . . . . . . . . . . . . . . .  11
          Enable CTS/RTS flow control  . . . . . . . . . . . . . . . . .  12
          Enable DSR/DTR flow control  . . . . . . . . . . . . . . . . .  12
          Enable XON/XOFF flow control . . . . . . . . . . . . . . . . .  12
          Note to users upgrading from SLEARN 1.10 . . . . . . . . . . .  12

     Registration  . . . . . . . . . . . . . . . . . . . . . . . . . . .  13







     SLEARN v2.00                                               Introduction

                                   Introduction

     Contacting the author
     ---------------------
     Hopefully, this documentation will tell you all you need to know about
     using SLEARN.  But if necessary, please direct further questions to me
     through the following means:

          Electronic mail:
               BIX:           proub
               Compuserve:    71131,157
               Fido Netmail:  1:135/110
               MCI Mail:      PROUB

          Messages to Paul Roub in the FidoNet TELIX echo

          US Mail to:

               Paul Roub
               P.O. Box 141583
               Coral Gables, FL 33114-1583

     When reporting a bug, please be specific as to the nature of the prob-
     lem -- what led up to it, what error message (if any) ensued, can you
     repeat it, etc.


     The author makes no claims as to the suitability of this product for
     any application.  In the event of malfunction, the author's liability
     shall be limited to a replacement or refund.


     SLEARN v2.00 was compiled using Borland C++ v3.1.  The editor used was
     Brief v3.0, without which I'd just as soon live in a cave and code on
     stone tablets.


     ACKNOWLEDGEMENTS:  Thanks to everyone who beta-tested this release for
     your feedback, time and assistance.  Thanks to Andrew Adler, Lloyd
     Burt, Craig Merwitzer and Bruce Wilson for testing and assistance above
     and beyond the call of duty.  Thanks also to Nick Anis and John Dvorak. 
     Special thanks to Lloyd Burt for more than I have space to list.









     SLEARN Documentation                                             Page 1







     SLEARN v2.00                                               Introduction

     Notes:
     ------
     You may distribute SLEARN freely (in fact, I would appreciate your
     doing so), provided that you distribute only the full, unmodified ar-
     chive (SLRN_200.ZIP), with its full name intact, containing the follow-
     ing files:  

          SLEARN.DOC
          SLRNHIST.DOC
          SLEARN.REG
          SLEARN.EXE
          SLEARN.SLT
          SLEARN.SLC
          SLCONFIG.SLC
          WHATIS.TFE
          READ.ME
          FILE_ID.DIZ

     If you downloaded SLEARN from Compuserve, please rename SL200.ZIP to
     SLRN_200.ZIP before distribution.  Feel free to distribute SLEARN in
     other archive formats (such as ARC, LHARC, PAK, etc.) -- but again, you
     must retain the full name, as in SLRN_200.LZH or SLRN_200.ARJ.

     If you're not sure whether you have the latest version of SLEARN, the
     following systems (among others) are always kept up to date:

          Shareware Online                             (305)271-4467
          AWARE EARTH                   (1:135/305)    (305)558-2170
          Miami Amateur Computer Club   (1:135/110)    (305)596-1854
          Telix Support BBS                            (416)439-8293
          BIX telecomm listings area
          Compuserve IBMCOM Forum

     If, after trying out SLEARN for 30 days, you wish to continue using it,
     you must fill out and send in the registration form at the end of this
     document.  You'll be supporting shareware, making possible future
     improved versions of this and other programs; you will also receive the
     latest registered version of SLEARN, including features not present in
     the Shareware version (see File Transfers, below).  For further
     details, see the Registration section at the end of this document.

     Is there something you don't like about SLEARN?  Something you think is
     missing?  A screw-up in the documentation, etc...  let me know!  We aim
     to please!







     SLEARN Documentation                                             Page 2







     SLEARN v2.00                                            Why use SLEARN?

                                 Why use SLEARN?

     What's the problem?
     -------------------
     I've said it before -- Telix is the best communications program you'll
     find.  Not even Telix is perfect, however.  Two common complaints go
     hand in hand: that Telix's script language (SALT) can be difficult for
     non-programmers to learn, and that Telix lacks a "learn" mode which can
     automatically create SALT scripts for you.

     For example, suppose you wanted to log on to a QuickBBS system.  You
     would connect to the BBS, wait until you saw the prompt

          Enter Your Name:

     then type your name, followed by a carriage return.  The system would
     then prompt you for your

          Password:

     which you would also type, followed by another carriage return.  

     Of course, you don't want to have to go through this every time you log
     onto that board -- the process will never change, and will get quite
     boring (just the type of thing you expect your computer to spare you
     from).  If you know SALT, Telix's script language, you could write a
     script to log on for you, such as:

          main()
          {
            waitfor("Your Name:", 30);    // wait for name prompt
            cputs("Paul Roub^M");         // if you're me, this works!

            waitfor("Password:", 30);     // wait for password prompt
            cputs(_entry_pass);           // send the password stored in
                                          //   this entry in the dialing
                                          //   directory
          }

     You would then compile this script, insert its name in your dialing
     directory as the "linked script" for this system, and off you'd go. 
     From now on, whenever you called this system, Telix would automatically
     run this script and log on for you.

     While this is nice, there are two drawbacks:  it gets tedious when you
     want to script more than a few prompts and responses, and some people
     find SALT difficult to get the hang of.  It would be nice if Telix had
     a "learn" mode.  A learn mode is a very useful feature, found in some
     communications programs, which "watches" you as you perform some task. 
     It notes what text is sent by the system you're connected to, what your

     SLEARN Documentation                                             Page 3







     SLEARN v2.00                                            Why use SLEARN?

     responses are, and the time elapsed between them.  Using this informa-
     tion, it writes a script which will wait for the same prompts and send
     the same responses.  You would invoke this learn mode, log onto the
     BBS, and the program would write the script FOR you!


     What's the solution?
     --------------------
     Now, Telix DOES have a learn mode.  It's called SLEARN, the SALT learn
     utility.  SLEARN will write your SALT scripts for you -- it will com-
     pile the scripts, include them in your dialing directory and even name
     them for you, all automatically!


     System Requirements
     -------------------
          IBM PC compatible

          MS-DOS 3.0 or above, or DR-DOS 5 or above

          Telix v3.11 or higher

          100K of free RAM, 175K for file transfers (registered version
               only)  NOTE: This is RAM above and beyond Telix's require-
               ments

          Hayes-compatible modem, up to 19,200 bps

          Any monitor and disk drive setup supported by Telix

          DSZ.EXE or DSZ.COM in DOS path (registered version only, and only
               if file transfers are being "learned")



















     SLEARN Documentation                                             Page 4







     SLEARN v2.00                                     Setup and Installation

                              Setup and Installation

     This manual assumes a basic understanding of .SLT (SALT script) versus
     .SLC (compiled SALT) files, as well as an understanding of terms such
     as "Logon Script" and "Dialing Directory".  If these terms are unfamil-
     iar to you, consult your Telix manual.  If you have any problems using
     SLEARN, and can't solve them with your DOS, SLEARN or Telix manuals,
     please feel free to contact me through the means listed at the end of
     this document.

     There are five essential files involved in using SLEARN.  These are:

          slearn.slt   - SALT script to run SLEARN from Telix
          slearn.slc   - Compiled version of slearn.slt
          slearn.exe   - The main SLEARN program
          slconfig.slc - SLEARN configuration management script
          slearn.cfg   - SLEARN configuration file (created by slconfig.slc)

     SLEARN.SLT, SLEARN.SLC, SLCONFIG.SLC and SLEARN.CFG should be kept in
     the directory you have defined as your Telix script directory.  If you
     haven't defined a script directory, simply place them in your main
     Telix directory.  SLEARN.EXE should be in a directory listed in your
     DOS PATH environment variable (consult your DOS manual for more infor-
     mation about environment variables and the PATH), or in the same direc-
     tory as SLEARN.SLT and SLEARN.SLC.

     NOTE:     If you are using Telix SE, you will not find SLEARN very
               useful, as Telix SE does not come with the program
               CS.EXE, needed to compile the SALT scripts created by
               SLEARN.  In this case, you will need to register your
               copy of Telix (see the Telix coupon in the Dvorak book
               for details), or find a BBS which has the Telix archives
               available (and use Telix SE to download them) to get the
               full version of Telix.

     By default, SLEARN will modify your Telix dialing directory
     (TELIX.FON).  However, if you will be using more than one dialing
     directory, you won't want to do this -- SLEARN always modifies
     TELIX.FON, whether or not it is the current dialing directory (Telix
     provides no way for a script or external program to check the name of
     the currently loaded dialing directory).  If you want to change this
     behavior, change this line (in SLEARN.SLT)

          int       UseSetScr = 1;
     to
          int       UseSetScr = 0;





     SLEARN Documentation                                             Page 5







     SLEARN v2.00                                     Setup and Installation

     If you make any changes to SLEARN.SLT, you will need to re-compile it
     for the changes to be effective.  To do this, go to your Telix script
     directory and enter the command:

          CS slearn

     at the DOS prompt.  This will create a new version of SLEARN.SLC, the
     compiled version of SLEARN.SLT.

     I recommend running SLCONFIG.SLC (through Telix's Alt-G command) when
     you first install SLEARN, in order to create and initialize SLEARN.CFG. 
     If you don't do this, SLEARN.SLC will automatically run the configura-
     tion script when you first run SLEARN -- a delay you probably won't
     want at that time!  See the section entitled "Configuration Options"
     for an explanation of the options available through SLCONFIG.




































     SLEARN Documentation                                             Page 6







     SLEARN v2.00                                               Using SLEARN

                                   Using SLEARN


     Learning a Script
     -----------------
     The easiest, most automatic way to use SLEARN is through the SLEARN.SLT
     script.  Just use TFE or Telix to insert 'slearn' in the Script field
     for that system's dialing directory entry.  Then, dial that system from
     Telix.  When Telix connects to the other system, it will automatically
     run SLEARN.  Alternatively, if you are already connected, SLEARN can be
     run via Telix's Alt-G (Run Script) command.

     Once SLEARN is running, simply go through the actions you wish to auto-
     mate, just as if you were using Telix.  That is, when (for example) the
     system asks for your name or password, just enter them as usual.  "Wri-
     ting" the SALT script is as easy as that!  As a bonus, if you have a
     password defined for the system you are connected to, you can just hit
     the F1 or F3 key to send your password for you (the SLEARN.SLC script
     will automatically tell SLEARN what your password is).


     File Transfers (registered version only)
     ----------------------------------------
     If you wish to automate file transfers, the program DSZ must be in your
     path (either DSZ.COM or DSZ.EXE).  Simply press PgUp (or Alt-S) to
     upload, or PgDn or (Alt-R) to download -- just as in Telix.  You will
     be presented with a menu of protocols, similar to that used in Telix,
     but with a more limited selection.  Select the protocol you wish to
     use, and input the filename(s) to transfer (if necessary), just as in
     Telix.  DSZ will be run to perform the transfer, after which SLEARN
     will continue.

     NOTE:     Keep in mind that SLEARN is not Telix.  You can receive and
               send text and files while using SLEARN, but you can not ac-
               cess the Telix dialing directory or any other Telix features;
               this means that none of these functions may be "learned".

     When you are done with the steps you wish to automate, hit Alt-X to
     tell SLEARN to write the SALT script for what you have just done, and
     return to Telix.











     SLEARN Documentation                                             Page 7







     SLEARN v2.00                                               Using SLEARN

     Saving your Script
     ------------------
     At this point, SLEARN will ask you whether you want to save the script
     you have just created.  If you answer "no", the script will be deleted. 
     Otherwise, SLEARN will ask you what name to use for the new script --
     hit ENTER alone to choose the default name, which SLEARN "guesses"
     based on the name of the system you're connected to.  SLEARN will then
     run CS.EXE to compile the script (it is important that CS.EXE be pres-
     ent either in your Telix script directory, or in a directory listed in
     your DOS PATH -- otherwise, SLEARN will not be able to locate and run
     the program).  And if you have not set "UseSetScr = 0" (as explained in
     the Setup and Configuration section), SLEARN will ask if you want to
     install the name of the new script as the logon script for this entry. 
     If you answer "yes", SLEARN will do so -- replacing the 'slearn' you
     had entered with the name of the new script.

     It is important that you have a "dummy" FON file named ZZZ.FON in your
     Telix directory.  If you do not have such a file, the SLEARN script
     will create one for you by copying TELIX.FON to ZZZ.FON.  This file is
     loaded into Telix when TELIX.FON is being modified, to avoid modifying
     a file which Telix is currently using.






























     SLEARN Documentation                                             Page 8







     SLEARN v2.00                                         Command-Line Usage

                                Command-Line Usage

     There may be times when you wish to use the SLEARN program itself,
     outside of Telix or without the use of the SLEARN.SLT script.  The
     SLEARN program takes the following parameters (all parameters in brack-
     ets are optional):

     slearn [-n <s>] [-b<n>] [-s<s>] [-w <s>] filename

     The parameters have the following effects:

     -n <s>    Sets entry name to <s>.  This option is used by SLEARN.SLT so
               that SLEARN can correctly note what board it is learning a
               script for.  This name is included near the top of the
               learned script file.  If the string is blank, no "Automatic
               logon script for..." line is included in the learned script. 
               If present, this name will also be displayed on SLEARN's
               status line while learning the script.

     -b<n>     Sets bps rate to <n>.  This tells SLEARN what speed your
               modem will use.  The default is 2400 bps.

     -s<s>     Sets parity, data, stop to <s>.  This option sets the parity,
               data bits, and stop bits parameters SLEARN will use when
               communicating.  This should be a three-character string, the
               first character being "N", "E", or "O" to represent No par-
               ity, Even parity, or Odd parity;  the next character will be
               7 or 8, depending on the number of data bits;  and the final
               character should be 1 or 2 to set the number of stop bits to
               use.  Common settings are "E71" and "N81" -- the default is
               "N81".

     -w <s>    Sets the password for this script.  This is useful for two
               reasons.  First of all, when running SLEARN you can send your
               password (followed by a carriage return) simply by pressing
               F1 or F3.  Second, whenever you send your password (by typing
               it or by F1 or F3), SLEARN recognizes it, and instead of
               including the literal password in the script, it uses Telix's
               _entry_pass variable, which is always set to the name of the
               system you are connected to (as stored in the dialing direc-
               tory).  This has two benefits:  (1) you can let other people
               have copies of the script without giving away your password;
               and (2) if you use more than one system with the same logon
               sequence, but a different password, you can use the same
               script for all of them -- the script will always send the
               appropriate password for each system.





     SLEARN Documentation                                             Page 9







     SLEARN v2.00                                         Command-Line Usage

     filename  Name of the SALT file to create.  This is the only parameter
               REQUIRED by SLEARN.  This is the filename of the script
               SLEARN will be learning.  If you specify a name without an
               extension, the extension .SLT will be used automatically.















































     SLEARN Documentation                                            Page 10







     SLEARN v2.00                                      Configuration Options

                              Configuration Options


     Rows on screen
          The number of lines on your screen, INCLUDING the status line (if
          any).

     Use status line
          Set this to 'y' (yes) if you use a on-screen status line in Telix.

     Status line row
          The row at which your Telix status line is displayed.  This has no
          effect if "Use status line" is set to 'n' (no).

     Status line background color
     Status line foreground color
          The colors used for your status line (if any).

     Sound bells when SLEARN.EXE is run
          Sounds control-G's (bells) when SLEARN is run.  This is normally
          used when SLEARN is run from a dialing directory entry, so that
          you'll know a connection has been made.  The reason I haven't just
          included an alarm() command in the SLEARN.SLT script is that
          during the time that the alarm is sounding, some characters may be
          received by Telix from the remote.  SLEARN will not see any of
          these characters, which may make creating a logon script for that
          board impossible.  Basically, the object is to get SLEARN itself
          running as soon as possible after a connection has been made, so
          that ALL prompts you may need can be processed by SLEARN.  This
          option probably won't be too useful from the DOS command line.

     Default Background Color
     Default Foreground Color
          The colors SLEARN should initially use for its terminal screen.

     Comm port address
     Comm port IRQ
          These tell SLEARN the exact nature of your serial port setup.

          IMPORTANT: You will probably never need to change these numbers. 
               SLCONFIG. when initially run, will calculate the correct val-
               ues based on information in TELIX.CNF.









     SLEARN Documentation                                            Page 11







     SLEARN v2.00                                      Configuration Options

     Enable CTS/RTS flow control
     Enable DSR/DTR flow control
     Enable XON/XOFF flow control
          These options enable various types of hardware and software "hand-
          shaking" -- used to control the flow of data between your com-
          puter, your modem and the modem you're connected to.  These op-
          tions are read from your Telix configuration file when SLCONFIG is
          run for the first time, so there should be no need to change them.


     Note to users upgrading from SLEARN 1.10
     ----------------------------------------
          You may have noticed that some of these configuration options are
          different than those use by SLEARN 1.10, and that a few of the old
          ones have gone away.  This was done in the interest of simplifying
          the setup of SLEARN.  Don't worry -- SLEARN 2.00 will understand
          your old configuration file, although I do recommend that you run
          the new SLCONFIG script at least once to "clean up" the config
          file.
































     SLEARN Documentation                                            Page 12







     SLEARN v2.00                                         Registering SLEARN

                                   Registration


          NOTE: SLEARN may NOT be used in a business or commercial
          environment without registration.

     SLEARN is distributed as shareware.  The advantage of this is that you
     get to try out the full, working program and see whether or not it
     suits your needs.  If you find SLEARN useful, you must register the
     program.  Registration has some benefits: you will receive the latest
     version of SLEARN on disk, along with inexpensive on-disk updates to
     future versions.  The registered version allows you to automate
     COMPLETE communications activities, including file transfers.  Com-
     ments, suggestions, and requests from registered users will of course
     have high priority.

     To register SLEARN, just fill out the registration form below; be sure
     to include your check or money order (in US Dollars), and mail it to
     the address below.  Basic registration is ten dollars, including ship-
     ping, handling, and the cost of a floppy disk (5 1/4", MS-DOS DS/DD,
     with the latest version of SLEARN).  Registered users of previous
     SLEARN versions can upgrade to the latest version for five dollars.  Of
     course, once you've registered one version of SLEARN, you've registered
     all future versions as well -- so you can simply download the latest
     version from a BBS.  I provide the upgrade service for those who can't
     find the latest version elsewhere.

     For a special price of only $15, you can register both SLEARN and TFE
     (TelixFonEd), receiving both on disk, along with a collection of Telix
     scripts, tips and utilities.

     Thank you for registering SLEARN.

     The registration form follows.

















     SLEARN Documentation                                            Page 13







     SLEARN v2.00                                         Registering SLEARN

     Please send this form, along with your check or money order for the
     appropriate amount of US dollars, to:

          Paul Roub
          P.O. Box 141583
          Coral Gables, FL  33114-1583


     I would like to register SLEARN in the following manner (check one):


     __ Regular registration (with the latest version on disk)        $10.00

     __ Previously registered user, upgrading to the latest version   $ 5.00

     __ Register SLEARN and TFE, plus bonus scripts and utilities     $15.00


     Name:               ___________________________________________________

     Company:            ___________________________________________________

     Street Address:     ___________________________________________________

     City, ST:           ___________________________________________________

     Zip:                _____________

     Home phone number (optional): (_____)-______________

     Work phone number (optional): (_____)-______________


     BIX, CIS, MCI or Netmail addresses (optional): ________________________


     Where did you find SLEARN?  ___________________________________________


     Comments and/or Suggestions:  _________________________________________

     _______________________________________________________________________

     _______________________________________________________________________

     _______________________________________________________________________

     _______________________________________________________________________



     SLEARN Documentation                                            Page 14














                              SLEARN version history


     Note that many of the changes listed here are due to users' input. 
     SLEARN has grown as others have told me what they need.  If you have a
     suggestion, please let me know.
                                                                       -paul


     Changes in version 2.00 (9/21/92)
     -  Added file transfer scripting -- DSZ.EXE or DSZ.COM must be in path. 
        Suppporting Zmodem, Ymodem, Ymodem-G, Xmodem, Xmodem-1K and
        Xmodem-1K-G.  (Registered version)
     -  Corrected comm port Address and IRQ "guessing" for ports higher than
        COM 2 -- this should eliminate any need for users to have to bother
        with this stuff.
     -  Now responding correctly to ANSI status inquiry from host -- this
        eliminates "No ANSI detected" on BBS end.  On boards such as Wild-
        cat! where the prompts are different if ANSI is detected, this can
        make all the difference.
     -  Eliminated "anonymous", "use password" entries from configuration. 
        More hassle that really didn't need to be there.
     -  Simplified COMM port configuration -- user just needs to enter Ad-
        dress (in hex) and IRQ, just like in the rest of the world.
     -  Config file handling is backwards-compatible -- old configs will be
        read and interpreted properly.

      
     Changes in version 1.10 (7/22/90)
     -  Added support for COM ports higher than 2, as well as nonstandard
        COM1 and COM2 configurations, through SLEARN.CFG.
     -  Added support for baud rates up to 115,200 bps.
     -  Added SLCONFIG script to manage configuration file; SLEARN.SLC calls
        it automatically if SLEARN.CFG is not found in the script directory.
     -  Added hardware (CTS/RTS and DSR/DTS) and software (XON/XOFF) flow
        control as configuration options.
     -  Added built-in ANSI emulation.
     -  Added 43- and 50-line mode support.
     -  SLEARN now inserts appropriate delays before non-prompted responses.
     -  Instead of a fixed (60 second) waitfor() period, SLEARN calculates a
        wait length based on twice the time actually elapsed when learning
        the script.  This should provide sufficient leeway for slower and
        faster days.
     -  showname() function now uses the status line colors and position
        defined in SLEARN.CFG, instead of always writing the name in black-
        on-white at line 24.
     -  F3 now sends password, as well as F1.
     -  Added strip-high-bit option.
     -  SLEARN.SLT now modifies TELIX.FON by itself -- SET_SCR.EXE is no
        longer needed.


     Changes in version 1.00 (1/17/89)
     -  Initial release.

