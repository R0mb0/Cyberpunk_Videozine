





                                                                     Page 1


                                    AUTOPUMA
                          Enhancement Script for Telix

     WHAT IS AUTOPUMA?

     Autopuma is a script that adds a number of trivial abilities to Telix,
     such as exiting or disconnecting if Telix has not been used,
     displaying incoming bells on the screen, and automatically starting
     MPt/Puma and Bimodem downloads when the host begins sending.


     WHY IS AUTOPUMA?

     Originally this script simply started Puma (since renamed to MPt)
     downloads anytime the Puma string was sent by the host, as Telix
     already does with Zmodem (hence the name, which I have never bothered
     to change).  But I also have a small BBS on the same machine that I
     use for downloads.  Often I would start a download from another BBS
     then have to leave before the download finished.  I'd either have to
     abort the download to bring up the  BBS, or leave with the download
     still going, and wait until I got back to bring up the BBS.  I had
     some kluges to bring up the board when the download finished, but they
     required I remember to trigger them before I started the download.

     Since I already had this script running "in the background" all the
     time anyway, I added the ability to monitor activity and bring up the
     BBS after Telix was left unattended for some amount of time.  Then I
     though it'd be nice if Telix brought up the board for an incoming
     call.  I gave it to a friend who asked for a few more things, then I
     needed more things...


     FILES INCLUDED:

          AUTOPUMA.SLC   AUTOPUMA script ("resident" portion).
          APCONFIG.SLC   Configuration script.
          APSMALL.SLC    Small version of AUTOPUMA.SLC.
          APSCNFG.SLC    Configuration script for APSMALL.SLC.
          BIMODXFR.SLC   Used by Autopuma to start Bimodem transfers.
          BIMODXMT.SLC   Bimodem upload script.
          BIMODRCV.SLC   Bimodem download script.
          BIMODEM.SLC    Script similar to that included with BIMOD124,
                         with minor changes to allow compatibility with
                         BIMODXMT/BIMODRCV.
          BIMODEM.SLT    BIMODEM.SLC script source.
          MPTXMT.SLC     MPt upload script.
          MPTRCV.SLC     MPt download script.
          PUMAXMT.SLC    Puma version of MPTXMT.
          PUMARCV.SLC    Puma version of MPTRCV.
          MPTXMT.SLT     MPTXMT.SLC script source.
          MPTRCV.SLT     MPTRCV.SLC script source.












                                                                     Page 2

          WHO.SLC        Tells who current/last connection was to.
          AUTOPUMA.DOC   This file.
          AUTOPUMA.WP5   WordPerfect 5.1 version of this file.

     The difference between the large and small versions is where the code
     for Autopuma's configuration window resides.  This code takes up about
     22K of RAM.  In the large version it resides in the AUTOPUMA.SLC
     script, which gives faster response when changing the configuration,
     but takes up memory you may need for things such as DOS shells and
     external protocols.

     In the small version the configuration window code is in the
     configuration script, making the resident portion smaller (and the
     configuration script larger).  However the configuration window will
     not respond as quickly as it does in the large version.

     Which version of Autopuma and the configuration script you use is up
     to you.


     INSTALLATION:

     Choose the version of AUTOPUMA.SLC and APCONFIG.SLC you want to use,
     and copy them to the same directory as your other Telix scripts.  If
     you use the small version of Autopuma rename APSMALL.SLC to
     AUTOPUMA.SLC, and APSCONFIG.SLC to APCONFIG.SLC.  If you've never used
     scripts before, press ALT-O from Telix and select "Filenames and
     paths."  Select "C" and enter the directory you want to keep scripts
     in.  Make sure you save it ("Write setup to disk") then get back to
     DOS and copy the appropriate versions of AUTOPUMA.SLC and APCONFIG.SLC
     to that directory.
      
     If you want Autopuma to run every time you run Telix, make a batch
     file (for instance "TLX.BAT") that contains:

             TELIX SAUTOPUMA

     and run this batch file instead of TELIX.EXE.  To take advantage of
     some Autopuma features you may eventually need to run Telix from a
     batch file anyway.  More on this later.

     You may also want to define a key combination to run the configuration
     script.  Press "ALT-K", select <R>egular key table, <E>dit, then
     choose a key combination (I use ALT-N), and define it as:
          @APCONFIG
     or "@APSCNFG" if you use the small version of the configuration
     script.


     USING AUTOPUMA:

     Run Autopuma, either from the DOS command line with:












                                                                     Page 3

             TELIX SAUTOPUMA

     or from within Telix by pressing ALT-G and giving AUTOPUMA as the
     script to run.

     Run the configuration script (APCONFIG) with ALT-G from within Telix. 
     This will bring up a window with Autopuma's available options.

     Options are:

       A - If phone rings once exit with....... 0

     If this is set to a non-0 value, and "RING" is received from the modem
     when there is no carrier, Autopuma will exit Telix with that
     errorlevel.  A batch file can use the errorlevel to bring up a BBS, or
     some other software to handle incoming calls.

       B - If phone rings twice exit with...... 0

     If this is set to a non-0 value, Autopuma will wait for two rings to
     come in from the modem, then exit from Telix with that errorlevel.  If
     a second ring does not come in within 7 seconds of the first then
     Telix will exit with the errorlevel given in option A if it has been
     set.

       C - Exit on inactivity.................. After 20:00 with 100

     If the time limit is not 0 and Telix detects no local or comm port
     activity within that time it will exit with given errorlevel.

       D - Time out even if carrier present?... No

     Usually Autopuma considers an active carrier as activity, and will not
     exit Telix if one is present even if nothing else is going on.  If
     this option is set to Yes, an active carrier alone will not be
     considered activity, and Autopuma will exit Telix and hang up on an
     active connection if nothing is received from the host and no local
     activity is detected within the time limit given in option C.

       E - Hang up if no activity for.......... 0:00

     If this is set to a non-0 value and no activity occurs within that
     time, Autopuma will drop any active carrier.

       F - Exit Telix on carrier loss.......... Off
                                                Once, with 100
                                                Always, with 100

     This will cause Telix to exit with the given errorlevel when the
     carrier is lost.  I use this when I start a download and I know I
     won't be around when it finishes to bring up the BBS (most decent
     BBSes can be told to hang up after a transfer).  If the option is set












                                                                     Page 4

     to "Once" and the exit is canceled, it will not reset, and the next
     time a carrier drops Telix will not exit.  If set to "Always" and the
     exit is canceled the option will reset, wait for another carrier, then
     try to exit again when it drops.

       G - Letter for MPT/Puma protocol........ P

     This is the letter you have assigned to the MPt protocol in the Telix
     "File transfer protocols" configuration.  If this is set and "Zmodem
     auto-downloads" is enabled in Telix, Autopuma will begin a receive
     with this protocol when a ^VPuma^V or ^VMPt^V string is received.

       H - Letter for Bimodem protocol......... B

     This is the letter you have assigned to the Bimodem protocol in the
     Telix "File transfer protocols" configuration.  If this is set and
     "Zmodem auto-downloads" is enabled in Telix, Autopuma will run the
     BIMODXFR script when the Bimodem handshaking string is received, which
     will prepare for a Bimodem transfer.  The delay controls how long
     BIMODXFR will wait for a response to the "Filenames to upload" prompt. 
     Bimodem transfers are discussed below.

       I - User defined string................. [none]

     This can be any string that, when received by Telix, should trigger
     some action.

       J - User defined command................ [none]

     This is the action that the user-defined string will trigger.  The
     available options are:

          EXIT [errorlevel]        Exits Telix with the errorlevel
          HANGUP                   Hangs up the phone
          SEND [text]              Sends text out the comm port
          LOAD [file]              Loads a configuration file
          SCRIPT [script]          Runs a SALT script
          DOS [command]            Runs a DOS command in a sub-shell

     Anything else is considered a DOS command and will be executed from a
     sub-shell.

       K - Visual bells........................ Off
                                                Always, 0.5 seconds
                                                If no sound, 0.5 seconds

     Autopuma can display "BELL!" in the center of the screen for a user-
     selectable duration anytime a bell is received.  Useful for
     environments where silence is required, but you still want to know
     about beeps.

       L - Seconds to delay before exit........ 0:10












                                                                     Page 5

     In most situations that trigger an exit from Telix, Autopuma will
     display a countdown timer before exiting to allow a chance to abort. 
     This sets the length of the delay.

       M - Show timer or clock on status line.. Neither
                                                Timer
                                                Clock Always
                                                Clock if no Timer

     If Telix status bar is enabled, Autopuma can display either the clock
     time or the length of time Telix has been inactive in the area that
     usually displays the script name.  "Timer" displays the timer if it's
     relevant, otherwise the script name.  "Clock Always" displays the
     current time.  "Clock if no Timer" will display the timer if relevant,
     otherwise the current time is displayed.


       N - Load options from disk.............. AUTOPUMA.CNF

     This allows you to recall previously saved Autopuma configurations
     from a saved file.

       O - Save options to disk................ AUTOPUMA.CNF

     This will save the current Autopuma settings to a disk file.

       P - Unload Autopuma

     This removes Autopuma from memory

     There are two other options available from this menu that are not
     displayed.  ALT-C will bring up a "color editor".  This allows you to
     set the colors Autopuma uses to display the configuration window.  The
     item to color is selected with up/down arrow, tab/shift tab, or
     home/end.  Colors are selected with left/right arrow or the first
     letter of the color.  The sample box will show what the colors will
     look like.  Selecting "Set to saved Telix colors" will set the colors
     to whatever was last saved in Telix "Screen and color" menu.  Note
     that these color settings are not saved anywhere.  The next time
     Autopuma loads it will revert to Telix' saved colors.  This feature
     may be removed in the future.

     The other is ALT-ESC.  By default Autopuma disables the ESC key's
     ability to abort scripts.  On some machines however this slows the
     script down, sometimes intolerably.  ALT-ESC will toggle the
     enabled/disabled state of the ESC key.  This may speed up Autopuma,
     but will prompt you with "Abort Script?" whenever the ESC key is
     pressed.  The state of the ESC key is saved to the Autopuma
     configuration file.
       

     MPT DOWNLOADS:












                                                                     Page 6

     In order for Autopuma to start an MPt or Puma download, you must have
     either PUMA.EXE 1.00, or MPT.EXE 1.10 or greater, and either batch
     files or SALT scripts for performing the transfer from Telix.  MPt and
     Puma scripts are provided, but you can use others if you have them. 
     The protocol must be installed in Telix in the Configuration Options'
     "Protocol Options" screen like this:

      Key   Protocol     Upload    Download   BAT or    DL
              Name      Filename   Filename   Script   Name
     -------------------------------------------------------
       P   Puma/MPt     mptxmt     mptrcv     Script    N


     BIMODEM TRANSFERS

     In order for Autopuma to start a Bimodem transfer, you must have
     BIMODEM.EXE 1.24 or greater, and either batch files or SALT scripts
     for performing Bimodem transfers from Telix.  The BIMODRCV.SLC and
     BIMODXMT.SLC scripts are provided, but you can use others if you have
     them.  The protocol must be installed in Telix in the Configuration
     Options' "Protocol Options" screen like this:

      Key   Protocol     Upload    Download   BAT or    DL
              Name      Filename   Filename   Script   Name
     -------------------------------------------------------
       B   Bimodem      bimodxmt   bimodrcv   Script    N


     The BIMODXFR.SLC script is also required by Autopuma for automatic
     Bimodem transfers.

     To explain why Autopuma initiates Bimodem transfers the way it does, a
     short explanation of how it handles MPt downloads is required.

     Autopuma begins an MPt receive when it receives the handshake string
     sent by an MPt protocol on the remote end that wants to send.  This
     string is different than the handshake sent by an MPt that wishes to
     receive, so there is no conflict.

     On the other hand, Bimodem can transfer files in both directions at
     the same time, so there is no distinct sender or receiver.  Because of
     this Bimodem has only one handshake string.  Autopuma can tell the
     host wants to initiate a transfer, but has no way of knowing if it
     should simply start a receive or if it should prompt for files to
     upload.

     The approach it takes is this:  If a Bimodem transfer is initiated by
     the remote computer, the user will be prompted to enter files to
     upload.  If there is no response within the time set in Autopuma's
     configuration, a download is assumed.  If files are entered an upload
     is assumed.  













                                                                     Page 7

     BIMODXMT.SLC and BIMODRCV.SLC will perform Bimodem transfers.  Both
     scripts require BIMODEM.EXE 1.24 or greater.  If a BIMODEM.PTH file
     exists in the Telix directory it will be used in the transfer.  After
     the transfer the scripts will ask if you want to delete BIMODEM.PTH. 
     If there is no response and the transfer returned a successful status,
     the file is deleted.  If the transfer failed, the file is retained.

     NOTE:  In the box Autopuma displays for entering filenames, strings of
     up to 241 characters can be entered.  The Bimodem scripts included in
     the Autopuma ZIP file will accept file lists this long, but other
     Bimodem scripts will not.  If you use different scripts to drive
     Bimodem the file list should not exceed the length of the window.

     BIMODEM.SLC is the same as the BIMODEM.SLC included in the Bimodem
     distribution ZIP file, except it ensures that the BIMODEM.CFG and
     BIMODEM.PTH files are created in the default Telix directory, which is
     where BIMODXMT and BIMODRCV expect to find them.  This will allow you
     to mark uploads (and on hosts that permit it, downloads) offline
     through BiMenu, then connect to the host and start the transfer,
     letting Autopuma start Bimodem automatically.


     AUTOPUMA AND ERRORLEVELS:

     To be useful, any option that forces Telix to exit with an errorlevel
     requires Telix to be run from a batch file that uses the "if
     errorlevel" command to test the errorlevel and perform the appropriate
     action.  For instance, if you want Telix to bring up a BBS if a call
     comes in, you need to set "A - If phone rings once exit with......" to
     a non-0 value (say, 100) and run Telix from a batch file that looks
     like this:

        rem run Telix with AUTOPUMA
        telix sautopuma
        rem if returned 100 run command to start BBS ("board" in this case)
        if errorlevel 100 board

     ENTERING VALUES IN THE CONFIG WINDOW:

     Values used as errorlevels cannot exceed 255.  Times cannot exceed
     99:59:59.

     If you need to enter characters into string values that are usually
     special (i.e. ENTER or ESC), press CTRL-V or CTRL-P, then the
     character.   Characters that must be entered this way are ENTER, ESC,
     all CTRL characters and any ANSI "ALT<number>" code.  The following
     keys perform these functions:

     ENTER:              save changes and quit editing
     ESC:                lose changes and quit editing
     Right arrow/CTRL-D: right one position
     Left arrow/CTRL-S:  left one position












                                                                     Page 8

     CTRL-right/CTRL-F:  right one word
     CTRL-left/CTRL-A:   left one word
     HOME:               beginning of string
     END:                end of string
     DEL:                delete character at cursor
     Backspace:          delete character left of cursor
     CTRL-DEL:           delete from cursor to end of word
     CTRL-Backspace:     delete from beginning of word to cursor
     CTRL-END:           delete from cursor to end of line
     CTRL-HOME:          delete from beginning of line to cursor
     INSERT:             toggle insert mode
     CTRL-P/CTRL-V:      insert special character
     CTRL-Y:             clear entire line
     CTRL-U:             undo all changes

     For numeric and time values:
     Grey '+':           increment value by one
     Grey '-':           decrement value by one

     For time values
     CTRL-Grey '+':      increment by one minute
     CTRL-Grey '-':      decrement by one minute
     ALT-Grey '+':       increment by one hour
     ALT-Grey '-':       decrement by one hour


     CONFIGURING VIA THE ENVIRONMENT:

     Autopuma can also be configured partially or entirely through the
     environment rather than a disk file.  The variable AUTOPUMA can be set
     to a string of options that tell Autopuma what to do.  The easiest way
     to create the configuration string is to configure Autopuma through
     the configuration window, save the configuration to a file, then copy
     the configuration file into your batch file (or wherever).  The config
     file is formatted as SET AUTOPUMA=<config string> to allow just that.
     If you want to edit or create the string yourself, the format is:


        SET AUTOPUMA=[option[:arg1][,arg2]...]...

     Options and their arguments are:

     R1X:<errorlevel>
          <errorlevel> is the errorlevel Telix should exit with when one
          ring is received.

     R2X:<errorlevel>
          <errorlevel> is the errorlevel Telix should exit with when two    
          rings are received.

     TOT:<time>,<errorlevel>













                                                                     Page 9

          <time> is the length of inactivity after which Autopuma will
          force Telix to exit.  <Errorlevel> is the errorlevel Telix will
          exit with.

     IC[:switch]
          IC tells Autopuma to ignore a carrier.  Autopuma will exit after
          inactivity (if that option is set) whether a carrier is present
          or not.  <switch> may be 0 (off) or 1 (on), or omitted, which is
          assumed to be 1.

     DCT:<time>
          Sets amount of inactivity after which Autopuma will hang up on a
          live connection.

     ECL[:switch]
          Tells Autopuma whether or not to exit when a carrier drops. 
          Switch can be:
             0 - do not exit
             1 - once
             2 - always
             If ECL is not followed by any value, 2 is assumed.

     ECLX:<errorlevel>
          <errorlevel> is the errorlevel Telix will return if it exits due
          to a carrier drop.

     PKEY:<letter>
          <letter> is the letter that has been assigned to the Puma/MPt
          protocol in Telix' "File transfer protocols" configuration.

     BKEY:<letter>
          <letter> is the letter that has been assigned to the Bimodem
          protocol in Telix' "File transfer protocols" configuration.

     BDLY:<seconds>
          <seconds> is the number of seconds that Autopuma will display the
          upload filename prompt box before it continues with what it
          assumes is a Bimodem receive.

     UDS:<string>
          <string> is the string that, if received by Telix, will cause the
          user-defined string to be executed.  The string can contain any
          characters, but the following characters have special meaning to
          Autopuma and must be quoted:

             " (double quote)
             ' (single quote)
             , (comma)
             ^ (caret)
             (space)














                                                                    Page 10

          Characters are quoted by either enclosing the character in double
          or single quotes, or immediately preceding the character with a
          caret (^).  The string Enter name (i.e., "Joe Smith") contains
          spaces, a comma, and quotes that must be quoted.  This can be
          done several ways:

             'Enter name (i.e., "Joe Smith")'
             <entire string in single quotes>

             "Enter name (i.e., ^"Joe Smith^")"
             <entire string in double quotes, with internal double quotes
             preceded by carets>

             Enter^ name^ (i.e.^,^ ^"Joe^ Smith^")
             <all spaces, quotes, and comma preceded by carets>

     Control characters can be represented by a caret followed by a letter,
     such as "^A" to represent CTRL-A.  Characters above ASCII 127 must be
     typed using ANSI.SYS' "ALT<keypad>" convention in an editor that
     accepts high ASCII characters.

     UDC:<string>
          <string> is the command that will be executed if the user-defined
          string is received by Telix.  It's entered and quoted the same as
          the user defined string.

     VB[:switch]
          Controls whether or not incoming bells are displayed.  <switch>
          can be:

             0 - bells are not displayed
             1 - bells are displayed only if sound is off
             2 - bells are displayed whether sound is off or not.
          If VB is not followed by any value, 1 is assumed.

     DLY:<time>
          <time> is the amount of time Autopuma will delay before exiting
          from Telix.

     ST:<switch>
          Controls whether Autopuma displays the clock or timer on Telix'
          status line.  <switch> may be:

             0 - display neither
             1 - display timer if relevant; otherwise nothing
             2 - display clock
             3 - display timer if relevant; otherwise clock.

     CLR:<border>,<text>,<highlight>,<inverse>
          Sets the colors Autopuma uses to display the configuration
          window.













                                                                    Page 11

             <border> - Configuration window border
             <text> - Normal configuration window text
             <highlight> - Highlighted text
             <inverse> - Inverse video

          Each color is a number calculated as (foreground + background *
          16).  Color values are:

             00 Black
             01 Blue
             02 Green
             03 Cyan
             04 Red
             05 Magenta
             06 Brown
             07 Light grey
             08 Dark grey
             09 Light blue
             10 Light green
             11 Light cyan
             12 Light red
             13 Light magenta
             14 Yellow
             15 White

          Since most machines display background colors 8 or higher as
          blinking versions of the lower colors, the color editor does not
          allow them to be used as background colors (neither does Telix). 
          However no checks are done on numbers read from the configuration
          file, so you can pick blinking colors this way if you want.

          Note that Autopuma doesn't save color settings in configuration
          files itself.  This option is used by scripts that communicate
          with Autopuma.

     CFN:<filename>
          This specifies the file from which Autopuma will read and write
          configuration information.  When this option is encountered in a
          configuration string, Autopuma reads the contents of that file
          and sets the configuration to it before continuing with the
          original configuration information.


     RENAMING AUTOPUMA

          If you want to name the AUTOPUMA.SLC to something else you must
          also set the environment variable APNAME to the new script name
          to allow APCONFIG to get the current settings.  Type at the
          command line or add to your batch file:

             SET APNAME=<name of autopuma script file>













                                                                    Page 12

     The WHO script:

     This is an unremarkable script that will tell you what entry in your
     dialing directory you are currently connected to.  However if AUTOPUMA
     has been loaded WHO will also tell you who you were just connected to,
     even if the connection has dropped.  Telix does not store this
     information once the connection is lost, but Autopuma does and WHO can
     ask Autopuma for it.  WHO also displays the information in Autopuma's
     current colors.


     DISCLAIMER:

     AUTOPUMA is provided on an "as is" basis without warranty of any kind,
     expressed or implied, including but not limited to the implied
     warranties of merchantability and fitness for a particular purpose.
     The person using the software bears all risk as to the quality and
     performance of the software.  Should the software prove defective, the
     user assumes the entire cost of all necessary repair, servicing, or
     correction.  The author will not be liable for any special,
     incidental, consequential, indirect or  similar damages due to loss of
     data or any other reason, even if the  author or an agent of the
     author has been advised of the possibility of such damages.  In no
     event shall the author's liability for any damages ever exceed the
     price paid for the license to use the software, regardless of the form
     of the claim. 


     REVISION HISTORY:

     Version 1.02, April 16:

          Added a version of Erik Labs BIMODEM.SLC script with
          modifications to make it compatible with BIMODXMT and BIMODRCV.

          Modified BIMODXFR and AUTOPUMA to allow BIMODXFR to exit
          gracefully if it was run some way other than from AUTOPUMA.

          Corrected problem in small version of Autopuma that would ignore
          "Exit on carrier loss" if it was set to "Once".

          Configuration script for small version was displaying it's
          initial "Please wait" message in black on black colors.  Fixed.

          Included separate Puma versions of the MPt script for Puma users.

          Renamed the Autopuma scripts a little to (hopefully) clarify the
          difference between the large and small versions.

     Version 1.01, April 12:














                                                                    Page 13

          Changed the name of the PUMA*.SLT scripts to MPT*.SLT, since that
          is the current name of the protocol.  AUTOPUMA remains AUTOPUMA,
          until I think of something better.

          MPt scripts will sound alarms when the transfer completes,
          similar to the alarm Telix uses when it's internal protocols
          complete a transfer.

          Added support for Bimodem protocol, and Bimodem scripts.

          Autopuma now reads default colors from TELIX.CNF on startup. 
          Removed color editor from menu, but left it accessible via ALT-C. 
          Colors are no longer saved in Autopuma configuration files.

          Eliminated unnecessary redrawing by the text entry function,
          reducing flicker.

          Time values were accepting times like "10:::::".  Though it
          wasn't doing any harm, it's been fixed.

          Text entry function did not allow most legal special characters
          to be used in file names.  Fixed.

     Version 1.00, March 16 1991:  Initial release.


     ANYTHING ELSE?

     There is no charge for private, non-commercial use of AUTOPUMA (but if
     you send a check anyway it won't go uncashed).  Comments, requests,
     and suggestions for a better name for this script can be left at:

             The Dead of Night BBS
             (703) 644-7667

     or mailed to:

             Donald Mehrtens
             5923 Minuteman Rd
             Springfield VA 22152

     or sent via CompuServe (which I don't check very often) to ID
     72361,1407.

     CAVEATS:

     There is no direct way to test if a local key has been struck without
     interfering with Telix's ability to process that key.  However most
     local Telix functions momentarily stop the script, and this can be
     detected.  This means individual keystrokes may not always register as
     activity to Autopuma, but any local activity that takes more than a













                                                                    Page 14

     couple of seconds will register, and characters coming in from the
     comm port will keep the timer resetting.

     If using the small version of Autopuma while running Telix under
     Windows, and the PIF file is set to "Detect Idle Time" Telix may take
     excessively long to bring up the configuration window.  On my Compaq
     386/20 it takes upwards of 2 minutes.  Make sure Detect Idle Time is
     off or use the large version of Autopuma under Windows if you have
     this problem.


     ACKNOWLEDGEMENTS:

     Thanks to Bob Price for his help and suggestions; To Lori Davis, for
     her help with this documentation (we programmers don't speak good
     English); and to Colin Sampaleanu for a great comm program.


     SALT Programmers, HELP!

     Is there any way for a script to determine its own name, as DOS batch
     files can do with %0 or C programs can do with argv[0]?

     Can a script find out how many and/or what types of arguments the
     main () function was actually passed, so that a script that needs
     arguments can GRACEFULLY exit if it wasn't given any?  Is there
     something similar to C's argc?

     As of v3.15 (possibly sooner) the SALT compiler has a "void" keyword. 
     What does it do?

     The script runs considerably slower if _scr_chk_key is set to 0 to
     disable the ESC key from prompting to abort the script.  Can anything
     be done about this?  Can the ESC key be prevented from aborting
     scripts without using _scr_chk_key?

     Is there any way to find out whether the cursor is on or off?

     Is there a cleaner way to find out if the status bar is on than to
     look on the screen for it with vgetchr/vgetstr?

     Is there a way to see if a local key has been hit without destroying
     the terminal() function's ability to process it, like cinp_count()
     does with the comm port?

     Despite the fact that Telix does not appear able to do anything with
     them, CS will happily compile a script that has no main() function. 
     Is this of any use?

     Can a script find out which dialing directory entries are marked?  Can
     a script mark and unmark entries?













                                                                    Page 15

     And does ANYBODY know ANYTHING about Telix 4.0?

























































