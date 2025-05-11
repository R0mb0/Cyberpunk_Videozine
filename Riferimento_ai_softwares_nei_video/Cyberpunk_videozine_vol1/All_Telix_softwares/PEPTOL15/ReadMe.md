                            PEPTOOLS v1.5
                      Registration is US $15.00
                 plus US $2.50 (US$3.50 OverSeas) for
                        shipping and handling.

             To Order, Make check or money order out to:

                            Michael Gillum
                       20806 S. Western Ave. #1
                        Los Angeles Ca. 90501
                            (213) 787-9461

  -----------------------------------------------------------------

   Please send:

   PEPTOOLS Registration Number(s)..... $ 15.00 _______

               [Optional]   Source Code $  5.00 _______

                  Shipping and Handling $  2.50
                                         ($3.50 Overseas)

                                        Total   _______

   Disk Size:  5.25" ______   3.5" ______

                            [Please Print]

   Name   :______________________________________________________

   Address:______________________________________________________

           ______________________________________________________

           ______________________________________________________

   Phone (Day):(____)______-_______  Evening:(____)______-_______

  I currently have version ______

                  (will be automatically updated, if
                   different than the present version)

  Comments:_____________________________________________________

           _____________________________________________________

           _____________________________________________________

  [Optional]

  Computer Type:________________________________________________

  Modem Type And Speed:_________________________________________

  Color display [Y/N]: __

  Where did you hear about (or receive a copy of) PEPTOOLS?


  [ ] BBS   Name______________________  Ph #(____)______-_______
  [ ] Sig   Name________________________________________________
  [ ] CompuServe
  [ ] Friend
  [ ] Other ____________________________________________________

                   Please Allow 20 days for shipment






                     *  Telix PEP Tools  v1.5  *
                    TELIX v3.12 Script File Tools
                      Written by Michael Gillum
                      Last Updated: 03-12-91

The Telix PEPTOOLS v1.5 are provided as Shareware. Meaning you have
the right to try them out for a limited period of 30 days. After which
you should either register them with the author, or discontinue usage.
Registering the tools will provide you with:

 a) An unlimited version of PEPTOOLS.

    A few of the TOOLS such as SEDITOR, and ROBOLOG, and PInstall are
    limited versions. The limitations do not take away from the actual
    work-a-bility of these tools, but the registered versions support
    many more features. For example:

          SEDITOR, as is, does not support word-wrap or insert mode.
          These are additional features that will enhance its
          functionality, but do not limit its present usage.

          ROBOLOG, is for the most part complete. However, some
          modifications will be necessary to the scripts that are
          created with the "Learn" facilities. The registered version
          clears this up. With registration, the "Learn" facility is
          expanded and writes totally completed, totally functional
          scripts. This is not to say that the scripts created with
          the Un-registered version are not workable, only that there
          is some modification required for decision making process
          that have been kept out of the unregistered version.

          PINSTALL, as is, assigns the tools to predetermined keys (as
          shown on the screen). The registered version of PInstall
          allows for custom selecting of keys to use in the
          installation.

          Also. A few of the tools will check for color display (based
          on what is installed in Telix) and use these, but most are
          configured for Black & White display only. In the registered
          version, full-color support is activated for ALL tools that
          use the display screen.

 b) Notification, and access to any "fixes" free of charge.

 c) Upgrades at a very low cost.

 d) Registration will also provide you with unlimited technical
    support.

 e) A complete listing (reference manual) of instructions and syntax
    for using the "called" scripts, or "Utilities" in PEPTOOLS, (plus
    an extended version of the utilities) for scripts you may decide
    to write yourself. As is, the called scripts included are used by
    many of the TOOLS, most of these (and others) can be used just as
    easily by you.

 f) Access to the complete source code for all scripts, at a small,
    additional charge of $5.00. No source code is available without
    registration.

Even as is, the PEPTOOLS are quite a bargain, but as you can see,
registration greatly expands many of the ideas present in the
PEPTOOLS. I highly recommend registration of the tools (of course!)

Registration of PEPTOOLS costs a mere $15.00 payable in check, or
Money Order, payable to:

                            Michael Gillum
                       20806 S. Western Ave. #1
                          Torrance Ca. 90501
                            (213) 787-9461

An order form is provided in a separate document, for your convenience.

                              Contents:

 Documentation:  PEPTOOLS.DOC   SEDITOR.DOC   ROBOLOG.DOC   ORDER.DOC

                           Compiled Scripts
                           ----------------
                             ROBOLOG .SLC
                             SEDITOR .SLC
                             PINSTALL.SLC
                             VIEWFILE.SLC
                             LISTDIR .SLC
                             SEARCHER.SLC
                             TDIR    .SLC
                             DIALDIR .SLC
                             FILE_ERR.SLC
                             READCFG .SLC
                             GETATTR .SLC
                             LASTPOS .SLC
                             ASCIIUP .SLC
                             DATETIME.SLC
                             KEYS    .SLC
                             LOADKEYS.SLC
                             LOGOFF  .SLC
                             MEMEXTRC.SLC
                             BAUDDRAG.SLC
                             ANSISCRN.SLC

Here are a set of automated scripts that were basically designed to be
timesavers.

Installing PEPTOOLS
-------------------
For a custom installation of all the PEPTOOLS, execute first, a script
called "PInstall." This script does a couple things.

First, it creates a color config file for a few of the scripts by
reading both, the attributes from the screen, and then comparing those
with Telix's actual configuration, in "Telix.cnf."

Second, it installs all the tools to a Telix "key" file of which you
provide the name. This allows all the tools to be called by pressing a
function key (or Alt-function key), making usage much easier. Telix
defaults to a key file called "Telix.key" when first loaded. You can
either select this as your key file, or give it any name you wish.

As a rule, if you do not choose Telix.key as your "tools key file" I
would at least, add to Telix.key, two tools. First, "Keys" as this
shows what is stored in the active key file, and second, "Loadkeys"
since this makes loading other key files a lot easier than Telix does.


Summary of Scripts:
-------------------
  PInstall :  As mentioned above, this is the installation script for
              all the tools. This script should be executed first,
              even if you are not going to assign the tools to
              function keys because PInstall also creates a color
              config file for a couple of the tools.

  ROBOLog  :  Automated-Timed script executor, with built in Script
              Writer.

                *Documentation contained in a separate file.

  Seditor  :  An online editor that offers more flexibility than many
              of the "Line Type" editors encountered on many services.
              Seditor is small, 18 lines max, with 60 character right
              margin. Designed as an "on-the-fly" basic message editor
              to alleviate the need for loading a bulky, external
              editor from TELIX simply to compose a short message.

                *Documentation contained in a separate file.

  ViewFile :  Allows viewing any file. Saves you from having to load
              your editor just to view the contents of a file. Will
              handle files up to 175,00 bytes in size (approx 200
              pages). Also accepts (*) wildcard character, to specify
              a particular set of files.

  ListDir  :  Displays a "wide screen" disk directory for selected
              directories. You provide the search path. Dos wildcard
              character (*) is acceptable.

  Searcher :  Searcher v1.0 is a modem number seeker. You choose a set
              of prefixes and a low to high number, then Searcher will
              dial those prefixes and numbers searching for a modem.
              If a modem is found, the number is logged in a file
              named MODEMS.SRC. A log of prefixes with low and high
              numbers is kept for future reference in a file named
              SEARCHER.LOG.

              Searcher acknowledges a "carrier signal" as a modem
              number. Any numbers called that are busy, voice
              answered, or not answered at all are ignored. No log is
              kept of Non-Modem numbers. It is possible that Searcher
              will overlook some actual modem numbers due to either no
              answer, or a busy signal. Only one attempt per number is
              executed when dialing.

  Datetime :  Displays the date and time on the screen for approx, 5
              seconds.

  AsciiUp  :  Prompts you for a filename, then does an ASCII upload.
              Saves you from having to select a protocol simply to
              upload a message, etc. This will only work for ASCII
              (Text) uploads.

  Keys     :  Shows special key assignments for the Function, Alt-
              Function, Shift-Function, and Ctrl-Function keys of the
              presently loaded key file. Put this one in ALL your key
              files to show what's stored in your function keys.

  LoadKeys :  Loads selected Key Definition file. This script offers a
              more direct way of loading Key-Def files than TELIX
              v3.12. Simply type in the name, and it's loaded
              (provided it exists - of course!) LOADKEYS assumes all
              key definition files to have the extension of ".KEY"

              * Keep in mind, that if you load another Key file,
              unless you have defined a few of the "Tools" to those
              keys too, you will lose the present Key assignment until
              reloaded. (I recommend you at least assign F1 in all
              your Key files to KEYS.SLC to display available keys and
              existing assignments - also, I would assign to some key
              THIS script, LOADKEYS.SLC, so you will retain the
              ability to reload the "Tools")

  AnsiScrn :  Qwik display of many of the Ansi Control codes, and
              gives a few brief examples.

  DialDir  :  Displays Dialing Directory without pausing at the "Stat
              Bar" like Alt-D does. Instead, this script takes you
              directly to the Directory.

  LogOff   :  Gracefully logs you off from anywhere online (even the
              PUBLIC FORUMS, or CHAT situations). There are always
              many ways to "hang-up" the modem connection, but to use
              anything other than the method supported by your BBS
              (Alt-H, Power Off, etc;) is an injustice to the Sysop
              and his equipment. LOGOFF.SLC first issues a Ctrl-C (to
              exit you from most situations - ie:Forum, Chat, etc;),
              then issues "Bye" to the system.


      * Called Scripts *
      ------------------
        These scripts do little, or nothing by themselves, but play an
        important role in the support of other scripts.

        MemExtrc :  Grabs your user number from the dialing directory
                    entry. For use by scripts that automatically log
                    you onto a BBS, that require a user number, as
                    well as a password.

        BaudDrag :  This script determines the Baud you are using, and
                    sets a "Drag Factor" for slower (300-1200) Baud
                    rates. Used by scripts that wait for prompts to
                    occur from a host, so the quick looping involved
                    with checking the terminal for incoming characters
                    is closer matched with the speed of the modem. No
                    "Drag Factor" is set if baud is 2400 or greater.

        File_Err :  This script handles the display of an error
                    message for problems associated with opening files
                    used by various scripts.

        TDir     :  Handles the display of a files directory for other
                    scripts.

        GetAttr  :  Reads attributes from two spots on the screen (the
                    status bar line, to determine reverse color, and
                    one line above that, to determine general text
                    color) returning both.

        ReadCfg  :  Looks for a file named "PEPCOLOR.CFG" and loads
                    colors for a few of the scripts. PEPCOLOR.CFG is a
                    standard Ascii text file with 3 numbers in it. The
                    first designates standard text color, the second
                    designates reverse video color, and the third
                    designates bold color. PEPCOLOR.CFG is created by
                    PInstall, when first run.

        LastPos  :  Searches for the last occurrence of a character
                    within a string. Most notably used in the tools to
                    find the last position of the '\' character in
                    determining the correct path of a directory search
                    that includes a wildcard (*) character. As in:
                    "C:\Telix\upload\*.*".

SCRIPT EXECUTION
----------------
First, you should copy all the files with the extension ".SLC" to your
TELIX v3.12 directory so TELIX v3.12 can find them.

  ** TELIX v3.12 can also load scripts by pressing special keys. **

To execute any of these scripts press ALT-G and type the name of the
script you wish to start. Rather than use this method, however, I
recommend instead, that you assign the scripts to Function keys.
Assigning the scripts to Function keys is easy, and gives you access
to the tasks the scripts perform in "one-key stroke."

            * Note on assigning scripts to a keystroke *
              ----------------------------------------
     If you choose not to use the PInstall assignments, you can
     individually assign the tools to function keys yourself. By
     pressing ALT-K while in TELIX v3.12, you will be taken to the
     Keyboard assignment section. From here press 'E' for edit, then
     press the key you wish to assign to the execution of a particular
     script. When assigning a keystroke to an executable script file
     you have to begin the line with the '@' character. Simply type
     @[name of script] (no brackets) and the selected key will be
     assigned to execute that particular script. Next, press 'S' to
     save the assignments you have just made. (You will be prompted
     for a filename to save your keyboard definitions to) - I
     recommend you select the default file 'Telix.Key' since this is
     the keyboard file that is automatically loaded upon start-up of
     TELIX v3.12.

     As an example, (using KEYS.SLC to display the assigned Function
     keys,) here's a possible suggestion for key assignments to some
     of the TELIX v3.12 Tools:

 ============================================================================
 |                    Special Function Key Assignments                      |
 |=======[F1-10]==========[AltF1-10]========[ShfF1-10]========[CtrF1-10]=====
 | 1| @Keys           | @DialDir        |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 | 2| @LoadKeys       | @PInstall       |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 | 3| @Seditor        | @Searcher       |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 | 4| @ListDir        |                 |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 | 5| @ViewFile       |                 |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 | 6| @RoboLog        |                 |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 | 7| @AnsiScrn       |                 |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 | 8| @DateTime       |                 |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 | 9| @AsciiUp        |                 |                 |                 |
 |--|-----------------|-----------------|-----------------|-----------------|
 |10| @LogOff         |                 |                 |                 |
 ========================[Press any key to continue]=========================

A Note on Script Files
----------------------
   Just as "line-noise" reeks havoc with your terminal and connection,
   scripts (that are of a "log-on nature") can also suffer. In the
   event there is extreme line noise and the script is not functioning
   as intended, you can abort at anytime. Simply press "Esc" and
   answer "yes" to cancel the script completely. This will merely
   leave you wherever you were when the script was operating.

   All included Scripts are "safe." Meaning, none of them, if a
   problem does occur, will hinder or harm normal operations while
   on-line. The worst case scenario would be a "hanging" of the script
   due to either line-noise interference, or other unforeseen
   circumstances. Any Script can be aborted, at any time, simply by
   pressing "Esc" and choosing "cancel script" when prompted.


Tips on usage, and TELIX v3.12 ".KEY" files
--------------------------------------------
   Chances are, you have many BBS's you log onto. Generally, I keep a
   different ".KEY" file for different BBS's (sometimes, more than one
   per BBS). This allows me to keep "special keys" for each BBS
   separate.

                Loading a script from the command line
                --------------------------------------
Telix supports loading a script from the command, as you start-up
Telix. Sometimes, if you keep separate key files for assorted tasks,
you may want to load the script "Loadkeys" as you enter Telix. This
way, immediately you will be able to choose the keyfile you want to
start with (Telix does not support loading a key file from the command
line).
To do this (or to load ANY script as you start Telix) issue from the
Dos command line:

                       Telix s[scriptfile name]
       (leave the brackets off. There should be no spaces between the
       's' and the scriptfile name. For example:

                           Telix sloadkeys

       Would start Telix, and automatically execute the script called

                             "loadkeys".

All Scripts were written and compiled using SALT, the TELIX v3.12
script language provided as in integrated part of TELIX v3.12 itself.
TELIX v3.12 has one of the most powerful scripting languages I have
seen (aside from some of the more expensive packages, such as
CROSSTALK Mach IV) and is very similar in nature to the 'C' language.

                Comments are welcome, and appreciated.
   If you have further questions or discover any problems, contact:
                            Michael Gillum
                                  at
                             213-787-9461






                         *  ROBOLOG  v1.0  *
                TELIX Automated-Timed Script Execution
                  and Self-Generating Script Writer
                      Written by Michael Gillum
                        Last Updated: 03-06-91


ROBOLOG is a TELIX script that automatically runs other scripts at a
predetermined time. If you have: a) Services that you call for
information or mail on a regular basis, but, will either be out of
town or unable to access your computer; b) Long distance services that
could be called during "low-rate" charge periods, then ROBOLOG can
help.

By using script files to access these services, ROBOLOG can be set to
automatically execute those scripts. Up to 10 predetermined times, and
scripts may be configured.

                             For example:
   You are going out of town for a few days but you still want to
   be able to collect your mail from a BBS you call regularly -
   ROBOLOG will take care of it for you! Just tell it the times
   of day you want to call, and give it the names of the scripts
   you use for collecting mail, and away it goes.

                                 or:
   A service you use is not a local call, however, you don't want
   to stay up late hours when rates are lower to make the calls
   yourself. ROBOLOG will do it for you!

ROBOLOG has, built into it, an interactive Script Writer. You can dial
a number and while you are on line ROBOLOG "captures" your session.
When you hangup ROBOLOG then redisplays your session prompting you for
the areas that contain "Online Prompts" and responses. A basic script
is then created to get you through those areas.

The script file ROBOLOG creates is not like some of the others you
will find with other "Learn" utilities. ROBOLOG's script uses
"procedural" techniques. Like any "Learn" utility, changes, to some
extent, will have to be made to handle "special" circumstances such as
"polling, or looping" in situations that require decision making
capabilities. An example of this could be:

   A BBS you call has mail prompts that require you to enter
   responses such as 1,2,3,4 etc; to view your mail. Sometimes
   you have 3 messages, sometimes you have 20.

A "Learn" utility, like the one in ROBOLOG, makes all analysis based
on a situation at the time the script was created. Perhaps, tomorrow
the situation will be different. This is where ROBOLOG scripts differ
from others. Because of the "procedural" nature of ROBOLOG scripts,
changes are easier, and overall, keep the script understandable. Many
other "Learn" programs simply create a "straight line" type of script
that, when many changes are made, produce a programmers nightmare of
"spaggheti code."

If all you need is a script generated to get you past the usual
Identification and Password screens, then no changes should have to be
made. However, because ROBOLOG is primarily for Automated-Unattended
Mail and Message collection, the scripts need to do more than simply
"get you online." The script created by ROBOLOG takes you most of the
way there. ROBOLOG's script is complete as is, and works without
error, but "decision making" processes will need to be included, by
you, so the script can be totally effective.







                          *  SEDITOR v1.0  *
                       An Online Message Editor
                      Written by Michael Gillum
                        Last Updated: 03-13-91

SEDITOR is an easy to use, highly functional editor for the creation
of short messages either while online, or offline. SEDITOR is compact,
compared to using an external editor from TELIX simply to create a
message. Designed specifically for small messages, SEDITOR is limited
in the size of message it creates to 18 lines, of 60 characters each.

Because SEDITOR was written in TELIX's own scripting language, the
scope of providing a more complex, full-scale editor was redundant. If
you need to compose a lengthy document then obviously you need the
full capabilities of a more sophisticated editor - one that offers
such features as margin; tab; and paragraph settings; as well as the
ability to move large chunks of text. That was not the purpose in
design of SEDITOR. Think of SEDITOR as an "On-The-Fly" message
creator.

Some of the things SEDITOR will provide, however, that the broader
text processor won't:

        1) The ability to upload your message for you when you finish.

        2) An "online-time" checker (if you choose to activate it) to
           make sure you don't get kicked off line while you are
           working on your message.

        3) A "hold and view" (if a carrier is detected) feature that
           temporarily suspends the editor, in the current session,
           and returns you online to review the message you are
           responding to, or view other messages and online areas.

        4) A "Pause" feature (if you activate the online checker) for
           when you need to step away from the keyboard for a short
           period. The online checker continues to "hold" you online.

All of this, without the overhead of a bulky editor, right from inside
TELIX. If you choose not to upload at the time of creation, SEDITOR
will save the message for you, automatically putting it in the
directory TELIX uses to upload from (either choosen by you when you
install TELIX, or by default).


                            Using SEDITOR:
                            --------------
Using SEDITOR is easy. You simply call it as you do any script, (I
recommend you install it in one of your function keys so it's
accessable anytime, anywhere).

Once in the editor, you will see additional cursor movement
instructions at the bottom of the screen. SEDITOR is a "full-screen"
editor, so you have full control over cursor movement within the
editor. This exemplifies the precise reason for SEDITOR's creation.
Most online services offer very basic, limited, line by line editors.
You enter your message a line at a time, and if mistakes are made, you
have to redo the entire line, sometimes more if you leave out a word
or phrase. This is very time consuming, and frustrating.


                          The Online Checker
                          ------------------
As soon as you start SEDITOR, (if a carrier is detected - otherwise
this function is by-passed) you are asked if you want to "Retain
Online Status." Answering yes will activate a timer (preset to 2
minutes) that will automatically signal to the host, your presence
online, while you are creating a message. This prevents you from
losing your connection while writing.

If the online timer is activated you will see, in the top right corner
the present time, and when the next "check time" is due. Answering no
simply bypasses this feature.

*Note*
if your keyboard is idle, the check does not occur and could result in
your being disconnected anyway. The check is made ONLY if you are at
the keyboard and actually typing - or, if you need to be away from
your keyboard for over two minutes, then select F2-Pause. This
maintains the online checker regardless of keyboard idle time. (If you
do not choose the online checker function, or a carrier was not
detected at start-up, F2-Pause will not show as a choice on your
screen)


                            Hold and View
                            -------------
A feature of SEDITOR, while you are creating your message, is the
ability to drop you back online, for review of other messages, or
perhaps, to look again at the message you are responding to. To
activate, simply press F1 while in the editor. The editor window will
temporarily fold, and you will have full keyboard control online. When
you want to return to the editor, simply press Esc. If no carrier was
detected at start-up of Seditor, F1 will not be available as an
option.


                            Loading a file
                            --------------
You can load a file into Seditor by pressing F3 from the editor. Keep
in mind that Seditor only supports 18 lines of 60 characters each. If
you attempt to load a file not created in Seditor, lines will be
chopped at 60 characters, and only the first 18 lines will get loaded.
Basically, this funtion is to reload files created through Seditor,
but it is not limited to that.

Another possibility of usage of the "loader" is for messages you may
have created, and saved, but did not upload. By loading these back in
Seditor, you now have the capabilities of not only editing, but can
upload it directly from seditor.


                         Erasing the Session
                         -------------------
If while typing, you decide you want to start over again, with a
"clean slate" you have two choices. Either "Exit and Abort" the
message, then select "Enter another" or, a quicker method is to simply
choose F4-Erase. This selection clears the present session completely,
and gives you a "clean window" so you can begin again. Be careful,
however, pressing F3 does not give you the option to save, and
immediately destroys what you have already typed.


                           To Exit SEDITOR
                           ---------------
To exit SEDITOR, simply press Esc. If there is text entered, you will
be asked if you want to UpLoad it now, Save it for later UpLoading, or
Abort alltogether. That simple!


                 Uploading: The Immediate Dispatcher
                 -----------------------------------
If you choose to UpLoad it now, SEDITOR will drop you online while you
navigate to the proper section for "sending" your message. In the
lower left corner of the editor window, you will see instructions
flashing. When you are ready, and positioned, pressing F1 will send
your message. Pressing Esc will abort that session, not sending your
message. If you do decide not to send the message immediately, SEDITOR
will again, give you the option of saving messages for later
uploading.


                               Appendix 1
                               ----------
Just because SEDITOR is limited to 18 lines, 60 characters does not
necessarily hinder the creation of larger messages. With the ability
of SEDITOR to upload immediately, also allowing you the freedom of
moving around online even while you are creating messages, you have
the capability to upload the "first 18 lines" and continue with the
message in a new window then "add" the second 18 lines to the
previously uploaded message while still online. By doing this you can
essentialliy create as large a message as you need.


                              Appendix 2
                              ----------
The online checker maintains your presence online line by periodically
(every two minutes) sending a Space character, then a Backspace
character (retaining your original cursor position online) to emulate
a "keystroke" to the host system.

