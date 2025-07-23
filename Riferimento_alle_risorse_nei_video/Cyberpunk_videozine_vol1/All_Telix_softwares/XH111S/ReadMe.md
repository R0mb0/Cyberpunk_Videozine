








                   ÜÜ   ÜÜ  ÜÜ   ÜÜ                ÜÜ
                   ßÛÜ ÜÛß  ÛÛ   ÛÛ                ÛÛ
                    ßÛÜÛß   ÛÛ   ÛÛ ÛÛÛÛÛÛ ÛÛÛÛÛ ÛÛÛÛÛÛ
                     ÛÛÛ    ÛÛÛÛÛÛÛ ÛÛ  ÛÛ ÛÛÜ     ÛÛ
                    ÛÛ ÛÛ   ÛÛ   ÛÛ ÛÛ  ÛÛ   ßÛÛ   ÛÛ
                   ÛÛ   ÛÛ  ÛÛ   ÛÛ ÛÛÛÛÛÛ ÛÛÛÛÛ   ÛÛ

                              version 1.11


                       A Host Mode for Telix 3.15

                          by Andras Pattantyus



     CONTENTS:

     Introduction
     Disclaimer
     Licence
     Support
     Requirements
     How to Use the Manual
     Installation
     Quick Start-Up
     Configuring XHost
     Sysop Keyboard Commands
     Listing of Online Commands
     Access Levels and Security
     The Archive Handling System
     The User Editor
     The Message Editor
     Using PACK.EXE
     Installing Bimodem
     Installing Other External Protocols
     Files Used/Created by XHost

     This document is not formatted for printing.


                              Introduction
                              ÄÄÄÄÄÄÄÄÄÄÄÄ

     The big question for any would-be sysop is, of course, why use
     XHost? Here are XHost's major strengths. Keep in mind that it still
     still in its infancy, and more features will be added, according to
     user response.

     1) Perhaps the simplest factor: XHost is free. It isn't commercial,
     nor shareware, nor crippleware, nor half-gutted (like some of the
     competition). You get everything there is, for not even a penny.

     2) XHost is fast. If you are trying to run Host+ on an XT, enjoy
     the sluggish response to keyboard input. XHost was written on an
     XT, and I hacked away until it worked fast enough. Of course, it
     lacks some of the "sophistication" of Executive Host and Host+. My
     answer to that is some things should be left to real BBS packages,
     not Telix scripts. I don't see the need to push SALT to the limit,
     because invariably performance begins to deteriorate.

     3) Well, it's time to roll out all the features. Let's start with
     those that will appeal to high-end expectations:

     - up to 40 conferences (999 will be available once I figure out how
       to efficiently save the users' last read message.)
     - 65536 messages per conference
     - Full-screen message editor, with quote mode and message uploading
     - 255 Text files per conference
     - 255 Doors per conference
     - Door formats: DOOR.SYS, DORINFO1.DEF, PCBOARD.SYS, custom formats
     - 255 File directories per conference
     - No built-in limits to file list size
     - Utility to add files to list, with FILE_ID.DIZ support
     - Completely configurable menu system
     - 256 menus, including global commands
     - Menu editor provided; two menuing systems included.
     - Extensive user records
     - User record editor (first 200 users)
     - 255 user levels available, each with own time, byte and ratio
       limit (again, editable)
     - Batch downloads! For internal protocols, 5 files from one
       directory; for external ones, 25 files from any directory.
     - File transfer list can be edited
     - Compatible with bidirectional protocols (BiModem, HS/Link, etc.)
     - Upload testing
     - FILE_ID.DIZ importing (supports multi-line descriptions)
     - Compressed file menu: extract, read, list, add files
     - All compressed file formats supported

     4) While designing XHost, I also considered the users who don't
     really want to run a BBS, and only need a few of XHost's features.
     This is why I implemented the menu editor, and the following
     options:

     - toggle file lists
     - toggle upload testing
     - toggle user records (ie operate like QDHOST in terms of security)

     This allows you to set up a simple one-menu system which runs
     nicely, gives you batch transfers and any other feature you feel
     you require. The rest of XHost conveniently disappears.



                               Disclaimer
                               ÄÄÄÄÄÄÄÄÄÄ


     You use this set of scripts at your own risk. You are advised to
     consult the documentation (RTFM!), or to contact me whenever an
     uncertainty arises. Of course, you should avoid taking unnecessary
     risks when using this software. There is no way that it can be
     guaranteed that this script will work with your particular hardware
     and software setup (although if Telix 3.15 runs, this should run),
     or that it will do what you wish it would. Any dissatisfaction
     should be mentioned to me so that it may be remedied as soon as
     possible. All the scripts have been tested and are hopefully
     bug-free, but some could still have slipped through, especially if
     you are using a beta version of XHost.

     Obviously, I, Andras Pattantyus, cannot be held responsible for any
     problems or damages associated with using XHost, and unless you are
     comfortable with that idea, you should not use XHost.



                                Licence
                                ÄÄÄÄÄÄÄ

     XHost 1.11 is a free program. There are no restrictions attached to
     it, except what is said in the following paragraph.

     XHost 1.11 may be freely copied and distributed, as long as it is
     unmodified and all files are present, including all the scripts,
     documentation, and any other files originally in the archive; and
     as long as no charge is levied for distributing XHost.

     If the source code for XHost is used for any commercial purpose, an
     acknowledgement of its origins would be appreciated.


                                Support
                                ÄÄÄÄÄÄÄ

     Well, you're more or less on your own now. XHost is relatively
     stable, so most people shouldn't have trouble with it. And
     hopefully most glitches should be easy to fix by wading through the
     code.

     I can be reached by:

           Writing to 3agp3@qucdn.queensu.ca, which is my Internet
           address.

           Writing to 3agp3@qucdn.queensu.ca@internet.org on Fidonet.
           (Check on your BBS how to route messages to Internet)



                     Requirements for Running XHost
                     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     First of all, Telix 3.15 must run on your machine. Then, enough
     disk space must be available for all the script files (roughly
     150k). To run XHost from a single 360k floppy alongside Telix, you
     will have to delete some non-essential scripts: Setup (once it is
     done), ADD.SLC, SORT.SLC, GENP.SLC and possibly EDIT.SLC or
     EDITOR.SLC if you do not need them.

     In terms of memory, the more the better, especially if you plan
     on using the remote DOS shell or doors. It will run with about 300k
     free memory, but this does not leave much room for anything else.
     Note that XHost will use DOS commands to perform certain tasks (ie
     clearing the temp directory), so giving it the absolute minimum
     might cause problems. Using Telix 3.20 will solve this problem as
     it allows you to swap to disk/EMS/XMS during a shell.

     As for machine speed, XHost was initially written on an XT, so I
     have learned how to squeeze the most out of SALT. However, there is
     a limit to what can be done. The biggest problem is undoubtedly the
     full screen editor, which ran sluggishly on the XT; the speed was
     equivalent to roughly 120 cps. Other areas may also be slow, as I
     now program on a 386-40 :-); nevertheless, speed was always an
     important factor when I designed my procedures and I can say that
     XHost runs faster than all of the other host modes with comparable
     features now available.



                         How to Use the Manual
                         ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Most of the features are described in several different places. For
     a complete understanding of how something works, you may need to
     read the part under CONFIGURING XHOST, plus the part under LISTING
     OF ONLINE COMMANDS, and possibly elsewhere. If you are seriously
     thinking about running XHost, then it's a good idea to read through
     the whole document once.

     The best method for general troubleshooting is to glance at
     XHOST.LOG in your Telix directory. Virtually all attempts at
     opening files are logged, and it can be very obvious what went
     wrong when XHost tried something, and there may be a simple fix.
     Otherwise, by all means LET ME KNOW!



                              Installation
                              ÄÄÄÄÄÄÄÄÄÄÄÄ

     All files with an SLC extension must be placed inside your script
     directory (defined in Telix, Alt-O F C), and all other files must
     be copied to your XHost data directory (defined in XHost Setup,
     System, XHost directory).

     Here's how the files should be distributed:

     Misceallaneous files:

     FILE_ID.DIZ    XHost's description
     README.1ST     This file
     QDMENU.ZIP     This contains a MENU.DEF and MENU001.ASC for a
                    simple setup. Extract into the host directory if
                    you want to use them.
     XHvvv.NEW      Changes and bug fixes in this version


     In script directory:

     ADD.SLC        Adds files to FILES.LST in current directory
     DOOR.SLC       Information file converter for doors
     EDIT.SLC       User Editor
     EDITOR.SLC     Message Editor
     GENP.SLC       Generates rejection path list for Bimodem
     README.1ST     Start-up info
     SETUP.SLC      Setup script
     SORT.SLC       Sorts FILES.LST in all directories
     XHOST.SLC      Main host script
     XHOST.DOC      This file

     In Telix directory:

     PACK.EXE       Data file packer

     In XHost data directory:

     ARCS.CFG       Archiver configuration file
     BIMOD.ASC      Bimodem help file
     MENU.DEF       Menu definition file
     MENU000.ASC    Sysop menu
     MENU000.ANS
     MENU001.ASC    Main menu
     MENU001.ANS
     MENU002.ASC    File menu
     MENU002.ANS
     MENU003.ASC    Archive viewing menu
     MENU003.ANS
     MENU004.ANS    User setup menu
     MENU004.ASC
     PROTO.ASC      Protocol table

     Many more files can be used or will be created by XHost. See FILES
     USED/CREATED BY XHOST for more information.


                             Quick Start-Up
                             ÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The following steps are the fastest way to getting XHost to work on
     a system. The first obvious thing is to run SETUP.SLC.

     - Fill out System settings.
     - Look at the available options. The default settings will be
       adequate for most people, but it is possible to simplify XHost's
       operation through this menu.
     - Fill out Modem Config.
     - Define at least one conference.
     - Add file directories, text files and doors to the conferences.
     - Define levels 1, 10 and 255 for a new, regular and sysop user,
       respectively.
     - Install any external protocols you wish to use. Read the section
       INSTALLING OTHER EXTERNAL PROTOCOLS.
     - All the other settings will work fine with the default values.
     - Edit ARCS.CFG with a text editor to place the default compressed
       file format first (see THE ARCHIVE HANDLING SYSTEM).
     - Edit PROTO.ASC to add the external protocols you use.
     - You might want to create FIRST.ASC and LAST.ASC files for logins
       and logoffs, respectively.

     That's it! You are now set to run XHost. Simply press Alt-G in
     Telix and type XHOST, followed by Enter.


                           Configuring XHost
                           ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The SETUP script allows you to control most aspects of XHost's
     behaviour. Here is a rundown of all options and their descriptions:


     SAVE AND EXIT:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍ

        Does Precisely that. This saves the following data:

            Paths and names, options, modem settings, maximum number of
            conferences, level checks, protocols.

        Directories, text files, doors must be saved with F2 before
        leaving their window. The same applies to conferences, user
        levels and the menu editor.

        Note that pressing Escape from the first menu causes SETUP to end
        without any changes being saved.


     UNDER SYSTEM:
     ÍÍÍÍÍÍÍÍÍÍÍÍ

        - XHost Directory: The directory which contains all of XHost's
          data files, except the usage log and the user file (which are
          in the Telix directory).

        - Temporary Directory: This is used to receive all uploads and
          for archive manipulations. It must be an empty directory (or
          else it will very quickly become one) as it is regularly
          cleared.

        - Sysop's Name: The name of the system operator.

        - System Name: The name of the system being run.

        - System Password: A 12-character string that controls access to
          SETUP and the Sysop menu.


     UNDER OPTIONS:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍ

        The YES option is explained.

        - Capture All Calls:  All calls are captured to XHOST.CAP. Be
          aware that this file will rapidly gain size as all text sent
          to the user will be saved to disk.

        - Closed System:  New users are not allowed to register. They
          are shown PRIVATE.ext and then logged off.

        - Monitor Call Progress:  The call is displayed to the screen,
          or else the status screen is kept. (The message editor's output
          will always be displayed, and the status screen is restored
          once the user exits the message editor.)

        - Exit Telix after Call:  Telix is exited after each caller.
          (useful for front-end mailers)

        - Lock Sound ON:  Sound is always ON, regardless of sound hours.

        - Lock Sound OFF:  Sound is always OFF, regardless of sound
          hours.

        - Allow Aliases:  When registering, the user is asked for
          his/her real name.

        - Do NOT Use File Lists:  File descriptions are not required on
          uploads, and obviously filename validation is not done on
          downloads. The raw directory must then be used to list files
          in a directory. Set this to YES if you want a simple Host.

        - Do NOT Test Uploads:  Uploads are not tested for errors.
          Otherwise, uploads that fail the test are deleted. (See THE
          ARCHIVE HANDLING SYSTEM section for details on how testing is
          carried out.)

        - Do NOT Keep User Records:  This option allows you to forego
          rigorous user records in favour of flexibility. When this is
          ON, the caller is asked to enter a password, and the user
          records are searched for a match. The caller is then assigned
          the level and data that goes along with the password
          (analogously to how Telix's host.slc operates). Ultimately,
          the effect of this option is to render the following data
          fields useless:

             Real name, phone number, city, country, bytes left, bytes
             transferred, files transferred, last logon, time left,
             total calls. (See THE USER EDITOR for more details on the
             user file.)

          This way several users can call in by knowing one of the
          passwords in the user file. It spares them the hassle of
          registering, etc. and can reduce the user file's size. Note
          that the "Closed System" option is also incapacitated: anyone
          who knows a password can call in. This can also create
          confusion if there is a message base installed, as all users
          logging in with the same password will share the same set of
          last-message-read values.

          To use this option, run the user editor to enter a password,
          level and security flags for each record. Note that deleted
          records will still be ignored, and anybody matching a
          blacklisted record's password will be ejected. Finally, the
          ratio should be set to zero for all user levels.

        - Sound Hours: The hours at which sound is to come on, and at
          which it is turned off. They can extend past midnight, but
          military (24 hour) time must be used.


     UNDER MODEM CONFIG:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

        - Minimum baud:  The minimal baud rate required to access the
          system. This must be a baud rate that Telix can recognise.

        - Lock rate? (Y/N): Set this to YES if it is wished that the
          baud rate between Telix and the COM port stays constant (if
          Auto Baud Detect in Telix is Off, then this should be set to
          YES).

        - Null Modem? (Y/N): This is used if two machines are connected
          via a Null Modem cable. Carrier checking is not performed, and
          there is no time limit to calls.

        - Busy String: This is the string that XHost will send to the
          modem before it starts local mode or a quick logon. By
          default, it is ATS0=0|, which sets auto-answer off on
          Hayes-compatible modems. If you want your modem to pick up the
          line so that callers receive a busy signal, change this to
          ATH1|. Note that a vertical bar (|) is used to indicate a
          carriage return (^M), usually at the end of the init string.


     UNDER CONFERENCES:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

        A window with the first conference displayed will appear. XHost
        can use up to 40 conferences. The following commands can be
        used to view the different conferences:

        - Escape: Quit
        - Enter: Edit conference
        - PgUp/Dn: Up or down one conference
        - Ctrl-PgUp/Dn: Up or down 10 conferences
        - (+): Add a conference
        - Delete: Blank out current conference

       The following fields may be edited:

        - Name:  The conference's name.

        - Level:  The level required to access the conference.

        - Flags:  Flag set required to access the conference (see ACCESS
          LEVELS AND SECURITY).

        - Path:  The directory where the conference's data files
          (messages, and directory/text file/door lists) will be kept.
          By default, this is the same as the XHost directory. This
          field was provided for those who install many conferences, and
          would like to keep each one separate from the others.

        - Messages? (Y/N):  Whether messages are allowed in this
          conference or not.

          Max Messages: The maximum number of messages for the message
                        base (0 = No limit if messages set to "Yes").

          Max Days:  The maximum number of days to keep a message
                    (1-255). A 0 keeps messages indefinitely.

          Note that PACK.EXE must be run regularly to take advantage of
          these options. See USING PACK.EXE for more details.

        - Private? (Y/N):  Only users registered in this conference will
          be able to access it if this is set to Yes. A user can be
          registered into a conference by editing the "R:" flags in his
          user record. See THE USER EDITOR for more information on this.

        - File Directories:  Hit Enter to edit the list of file
          directories available in this conference.

          Editing the directories:

          A window displaying the first file directory will appear.
          Its name, path, level and flags required are editable. Note
          that you have to add (+) a directory to get started.

           - Name: The file directory's description
           - Path: The directory itself
           - Level: Level required to access the directory
           - Flags: Flags required to access the directory
                    (see ACCESS LEVELS AND SECURITY for a description of
                    how flags work).

           The following commands are available:

               - Escape: Return to conference window
               - Page Up/Down: Display the next/previous directory
               - Control-Page Up/Down: Jump by 10 directories
               - (+):  Add a directory to the end of the list
               - Delete:  Delete the current directory. Note that this
                 does not remove the directory entirely. Instead its
                 name and path are reset, which causes XHost to skip the
                 directory. To entirely remove a directory, use an
                 editor (as explained under Alt-A a bit later on).
               - Enter:  Edit the current directory
               - Alt-A:  *BEWARE!* Load the editor (as it is defined in
                 Telix Config, Alt-O F H) to edit the directory data
                 file. This is tricky because the file's record lengths
                 must be preserved; even though the records are CR/LF
                 delimited, the file is direct access and therefore any
                 improper deletion or insertion will render the data
                 incomprehensible to XHost. The only safe commands are
                 Delete line (Control-Y in most editors) and Duplicate
                 Line (using a block command or F4 in QEdit).

                 Use this command to remove or insert records (which
                 cannot be done in any other way). If you are not sure
                 of what to do, then either don't do it or backup and
                 fiddle around until you get it (this part isn't very
                 user friendly). The header of the data file displays
                 the format of each record; you must use the right
                 record type (directory, text file or door) for the
                 current file.

        - Text Files: The same commands as in File directories apply.
          Note that a filename entered without any extension (no period
          in filename) will be taken by XHost as a reference to a set of
          .ANS and .ASC files.
          "Text files" are just about identical to "bulletins". XHost's
          text file viewer allows users to view any text file in the
          file directories. One additional command is available:

               - Alt-T: This loads up the editor defined in Telix, with
                        the current text file as a parameter.

        - Doors: Again, the same commands apply, except that PATH must
          now be the full path and filename of the program to run. One
          extra command is available: Alt-O, used to access the Door
          Options window.

                 Door Options:

                  - Params: The parameters to be passed to the
                    program. Note that all programs (except scripts) are
                    executed using the SALT "run" function, and
                    therefore DOS piping/redirection may not be used.

                  - Time: The maximum time a user is to spend within the
                    door.

                  - Status: This is a set of On/off flags (much like the
                    security flags) which tell XHost how to prepare to
                    run the door.

                    Flag Descriptions:
                        1- Script: Tells XHost that the file should
                           be "called" as a script

                        2- ANSI Req'd: A user wishing to run this door
                           MUST have ANSI graphics turned ON

                        3- DOOR.SYS: A DOOR.SYS file will be generated
                           before the program is run

                        4- DORINFO1.DEF: A DORINFO1.DEF file will be
                           generated before the program is run (QBBS
                           doors)

                        5- PCBOARD.SYS: A PCBOARD.SYS file will be
                           generated before the program is run (PCBoard
                           14.x doors)

                        6- CVT-1.SLC
                        7- CVT-2.SLC
                        8- CVT-3.SLC: These are converters that you may
                        choose to install. Since more than one converter
                        may be used, you can create DOOR.SYS and then
                        convert it to the format of your choice, or use
                        one of the many programs available (ie
                        Doormaster) to do so.


     UNDER USER LEVELS:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

        This is where all user levels may be defined, along with the
        time and bytes per day each is allocated, and the ratio the user
        must respect. The ratio is checked against the number of bytes
        downloaded and uploaded. A ratio of 0 disables this checking,
        and otherwise its value indicates the number of bytes a user may
        download for every one that s/he has uploaded.

        The current access levels set in the menu definition file should
        be taken into account as this is done (changing the menus'
        access levels is possible using the menu editor). See the
        section titled LISTING OF ONLINE COMMANDS for this information.

        The following keys can be used:

        - Escape: Quit
        - Page Up/Down: Move up or down a level
        - Control-Page Up/Down: Move up or down by 10 levels
        - Home: Goto level 1
        - End: Goto level 255
        - Insert: insert a level before the current one (level 255 will
          be pushed out)
        - Delete: delete the current level (a new level 255 will be
          created)
        - Enter: Edit the level.


     UNDER PROTOCOLS:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

        All the available protocol keys are listed here. The internal
        protocols' characteristics may not be changed, but they can be
        disabled. All external protocol keys entered here must also be
        defined using the same key in Telix's configuration (Alt-O P).

        The following columns are displayed:

        - Key: The protocol's key, by which it can be selected for use.

        - On: Whether the protocol is active or not.

        - Batch: Whether the protocol can transfer more than one file at
          a time. This option allows internal protocols to send five
          files from the same directory, and external ones to send 25
          files from any directories.

        - External: Whether the protocol is external or not. When a
          configuration is saved, Setup marks all protocols that are not
          included with Telix as external, so it is not necessary to
          change this.

        - Bimodem: Whether the protocol can use Bimodem's new-format
          Intercommunications Log. Set this to "Y" if you have Bimodem
          1.24; for an older version, make sure that it does support
          this file format. If your version of Bimodem does not support
          this log file format, then it can still generate a DSZLOG
          file. This amounts to the same thing, except that a user will
          have to describe uploads after the transfer.

        Use Escape to exit.

        (See INSTALLING BIMODEM and INSTALLING OTHER EXTERNAL PROTOCOLS
        for more details).


     UNDER MENU EDITOR
     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

        The menu editor is used to add, remove and change the menus
        which XHost uses. The XHost distribution archive comes with
        five menus, numbered from 0 to 4: SysOp, Main, Files, Archives
        and Info & Setup. An alternate menu is provided in QDMENU.ZIP.
        Extract the contents of this file into your host directory if
        you wish to use a simple menu - much like the one in Telix's
        QDHOST (and delete the old MENU001.ANS).

        Use the cursor keys to move the selector around, and press Enter
        on the menu entry that you wish to change. Escape will end
        editing of an entry. The following commands are also available:

        - Alt-C: Clear the current menu's contents.

        - Alt-N: Use this to change the name of a menu. If a menu's name
                 is blank, XHost will not use it.

        - Alt-P: This allows you to load another menu. Pressing Enter
                 will display a list of all menus. Escape may be used to
                 abort menu selection. Typing "G" will load up the
                 global commands menu. Also, entering a NEW (not
                 accessed previously) menu's number will automatically
                 copy to it the current menu's contents.

         - F2: This saves the current menu.

         - Escape: Quit to main menu.

        Menu Commands:

          ! = Accepts arguments via Option
          # = Supports access by numbers

          1       Send menu                  41 !#   List Files
          2       Goodbye                    42      New Files
          3       Chat                       43      Locate string in FILES.LST
          4       Comment                    44      Upload
          7  !    Goto menu                  45      Download
          9  !    Run script                 46 !#   Raw (DOS) directory
          10      Shut XHost down            47      Add files to list
          11 !#   Text Files                 48      Move file
          12 !#   Doors                      55      Change PW
          14      Read Log                   56      Change default protocol
          15      DOS Command                57      Set scan prompt on/off
          16      Read messages              58      Set conferences to scan
          17      Write message              59      ANSI on/off
          21      List conferences           60      Expert mode on/off
          22  #   Scan conferences           61      Display user info
          23 !#   Join conference            62      Set screen length
          31      Choose archive
          32      Delete from archive
          33      List files in archive
          34      Delete EXTRACT.ext
          35      Extract file
          36      Add to EXTRACT.ext
          37      Type file inside archive
          38      Contents of EXTRACT.ext


          Notes
          ÄÄÄÄÄ

          - Menu 1 is always the first one sent to the user.

          - Most commands are described in the LISTING OF ONLINE
            COMMANDS section.

          - The Global menu has precedence over all the others.

          - "Run script" command requires an option. Then SCRnnn.SLC
            will be run, where nnn is the option. This is admittedly
            somewhat awkward, but it is certainly the easiest method to
            code. Also, a return code of 3 from the script will be
            considered a request to exit to DOS, of 2 to exit to Telix,
            and of 1 to end the call (0 = normal termination).

          - "Goto menu" also requires an option. This option indicates
            the menu that will be loaded; note that menu 0 is system
            password-protected.

          - "Access by number" refers to accessing an object (ie text
            file, door, file directory) by typing its number. This is
            done by setting the key to '#'. Take for example the
            following menu entry:

            Key: #  Level: 1  Flags: 0  Command: 41  Option: 0

            To list a file directory (command 41), the user would have
            to enter its number: 1 to list the first one, 2 to list the
            second, etc. This can also be done with the raw dir, text
            files, doors and conferences. Entering here an option
            different from 0 would cause the file directory of the same
            number as option to be displayed no matter which number was
            entered.

          - Due to the way XHost processes the menus, keys may be
            repeated within a menu. However, XHost will only find the
            first matching key that the user has access to; therefore
            this is useful to execute different commands for different
            user levels. For example:

            Key: T  Level: 10  Flags: 0  Command: 7  Option: 5
            Key: T  Level: 5   Flags: 0  Command: 7  Option: 6

            This would make all users with a level greater than 10 go to
            menu 5. Users with a level >= 5 and less than 10 would be
            sent to menu 6. All other users who type 'T' would be told
            that they had entered a bad command.



                        Sysop Keyboard Commands
                        ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

        The following commands are available at all times except when
        the user is in the editor.

         - Alt-A: Loads the user editor after saving the current user's
                  record. The user's data will be reloaded after.
         - Alt-D: Toggles the display on/off
         - Alt-F: Presents Telix's DOS Function menu.
         - Alt-L: Controls the status of the capture file.
         - Alt-S: Toggles the sound on/off
         - Alt-X: Hangs up on the user, and exits XHost.
         - Alt-Z: Cycles through the various help/info screens.

        These commands can be used when a user is online:

         - +/-:   Lowers or raises the current user's access Level by
                  one. This does not affect in any way the time, bytes,
                  or flags that the user has. To completely upgrade a
                  user, it is necessary to run the user editor (Alt-A)
                  and manually edit each field.
         - PgUp/PgDn: Lowers or raises the current user's time by 5
                  minutes.
         * Note:  Changes made to a user's access level and time left
                  will be saved to the user's record.

         - Alt-E: Toggles echo on/off. This is used to suspend output to
                  the caller.
         - Alt-H: Hangs up on the user, and returns to the status
                  screen.
         - Alt-Y: Chats with current user.

        These commands are available only at the status screen:

         - Alt-O: Run the Setup script. Note that XHost must be
           restarted for any changes in the System, Options, Modem or
           Protocol section to take effect.

         - L: Start local test mode. This simulates a logon by a caller.
           Note that file transfers (obviously) will not work
           properly.

         - Q: Quick logon. This allows a local logon by simply entering
           the system password. If the sysop's name is found in the user
           file, then the appropriate record is used. Otherwise (if the
           sysop's name is not on the list, if the system does not keep
           user records), a "sysop" user will be generated; this,
           however, will not work with doors (unless it does not require
           any info file) as no actual user record exists, and the door
           converter requires one. The initial menu is menu 0, which is
           the sysop menu in the default configuration.



                       Listing of Online Commands
                       ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

        This is a listing of the default menus and a short explanation
        of each command.

        Note: 1) Commands can be stacked from almost any prompt; ie:
        f v s xh110.zip will go from the main menu to the archive menu
        and select XH110.ZIP.

              2) Some commands are not included in the default menus.
        That is, they are defined in MENU.DEF but do not appear in the
        MENUnnn.ext files. These are marked with an asterisk.

        Format: Command, Key, Level, Security Flags

        GLOBAL COMMANDS
        ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

        Expert Mode, X, 1, 0
        - Toggles expert mode on and off (whether the current menu is
          sent before every command prompt or not)

        Goodbye, G, 1, 0
        - Displays LAST.ext and logs off user

        Send Menu, ?, 1, 0
        - Shows current menu to user. This also reloads the MENU.DEF
          file, so this must be used after a level change before any new
          commands can be accessed.

        Yell, Y, 1, 0
        - Attempts to page the system operator


        SYSOP MENU   (Need Flag 1 and system pw to access)
        ÍÍÍÍÍÍÍÍÍÍ

        Add to File list, F, 1, 1
        - In local mode, runs the ADD scripts to add files to a file
          list. For remote callers, it allows the same to be done via a
          simpler interface.

        DOS Shell, D, 1, 1
        - Allows a DOS Shell or a DOS Command to be executed. For DOS
          Shell, a SHELL.BAT file is first searched for, and one is
          created if it is not found.

          Note that DOS 5 is needed to use XHost's built-in shell
          procedures for COM 3 and 4 (there is no easy way to test for
          DOS 5's presence). The COMSPEC system variable needs to be set
          (ie have SET COMSPEC=C:\COMMAND.COM, or whatever your command
          interpreter is, in your AUTOEXEC.BAT file) for XHost's batch
          file to work. Also, running a program remotely is next to
          impossible unless a redirection program, such as DOORWAY, is
          used to channel I/O through the system's COM ports. It is
          highly recommended for effective DOS shelling. Users will also
          find that the system will leave little memory available to a
          DOS shell, due to the fact that Telix and XHost take up a good
          chunk of it. This can be fixed by using an external program,
          such as SHROOM, to unload Telix from memory before the shell.
          Telix 3.20 also fixes this problem by swapping itself to disk,
          EMS or XMS. (SHROOM and DOORWAY are shareware, copyright owned
          by their authors, and should be available on any major BBS.)

        Move File, M, 1, 1
        - Moves a file and its description (if available) from one file
          directory to another. The description and the file are
          copied to the new directory, then PACK /F [path] is used to
          remove the old description.

        Read Log, R, 1, 1
        - Displays the usage log (XHOST.LOG in the Telix directory).

        Shut Down, S, 1, 1
        - Allows termination of XHost script and exit from Telix.


        MAIN MENU
        ÍÍÍÍÍÍÍÍÍ

        ANSI Mode, A, 1, 0
        - This sets whether ANSI colour codes will be sent or not to the
          user.

        Comment, C, 1, 0
        - This allows the user to enter a private message to the system
          operator. It is saved in conference 1, even if conference 1
          does not allow messages.

        Doors, D, 10, 0
        - The Door menu. If DOORS.ext is found in the data directory,
          it is displayed. Otherwise, XHost generates a list of all
          available (ie that the user has appropriate access to)
          doors. A door is run by entering its number.

        File Menu, F, 10, 0
        - This loads up the File Menu (002).

        Info Menu, I, 1, 0
        - This brings up the Info & Setup menu (004).

        List Conferences, L, 5, 0
        - This displays a list of all the conferences the user has
          access to, unless CONFS.ext is found in the host directory,
          in which case it is sent instead.

        Read Messages, R, 5, 0
        - This allows the user to read messages in conferences
          with messages (as defined in Setup). The following subcommands
          are available to all users:

              (+) read forward
              (-) read backward
              (1-65536) jump to another message
              (Enter) read the next message

              (A) read the same message again
              (C) read messages non-stop
              (J) join a conference
              (L) set the last message read
              (Q) quit reading messages
              (R) reply to the current message
              (S) scan conferences for messages
              (W) write a new message

          The system will always start reading at the newest message. If
          no new messages exist, the user must specify a message number
          to start at; (+) and (-) cannot be used at that point.

          If the current message if to or from the user (or the user has
          the co-sysop flag [2]), then one extra command can be used:

              (E) edit the message's header. The user who wrote the
                  message can change the "To", "Subject", "Private" and
                  "Deleted" fields. The receiver may only change the
                  last two.

        Scan Conferences, S, 5, 0
        - This command has two modes: one is a quick scan, which
          displays the number of new messages in the conferences the
          user has selected to scan, the other allowing the user to also
          read these new messages before proceeding to the next
          conference.

        Switch Conference, Conference's number, 5, 0
        - This allows the user to join another conference, as long as
          s/he has access to the new conference.

        Text Files, T, 5, 0
        - This brings the user to the Text File Menu. At this point,
          XHost first checks for the presence of TXTnnn.ext in the
          data directory; if it is not found, it generates a list of all
          defined text files available to the user. It is also possible
          to view any accessible text file from this menu (a text
          file in any one of the directories available to the user). A
          text file can be displayed by typing its number (or name, if
          it is in a directory). As always, numbers and names can be
          stacked. For example, to show files 1, 2, and 5, one can enter
          "1 2 5". To display any one of them continuously, type a "c"
          (for continuous) after its designator: "1 c 2 5" will display
          the first text file non-stop and pause at each page for the
          others.

        Write Message, W, 5, 0
        - This allows the user to write a message in the current
          conference (if it allows messages). The default receiver is
          "All". Message entry may be aborted by entering a blank
          subject.

      * Sysop Menu, Z, 1, 1
        - This loads up the sysop menu. The system password is required;
          if is not defined, a blank system password allows access to
          this menu.



        FILE MENU   (level 10)
        ÍÍÍÍÍÍÍÍÍ

      * Add files, A, 10, 2
        - This command allows a co-sysop (flag 2) to update the file
          list in any directory that s/he has access to. The ADD script
          will be run for local callers, and XHost will use a simpler
          interface for remote callers.

        Download, D, 10, 0
        - This allows the user to transfer one or more files from the
          host system to the remote system. Internal protocols may be
          used to transfer up to five files from one directory, while
          external batch protocols are allowed to transfer up to 25.

          If only a filename is entered, it is searched for in all the
          directories of the current conference that the user has access
          to. Unless the user has the level required to bypass the file
          list (or the system runs without file lists), every match is
          checked for presence on the file list.

          A user with access to any path can enter a filename and path
          on downloads. Note that file list checking is still in effect
          (for users without the required level), even if the path is
          not defined within the conference.

          Finally, the user must have enough time and bytes available
          for each file; the download/upload ratio must also be
          respected (XHost will not allow a user to exceed his/her
          allotted ratio).

          The user also can manipulate the transfer list using the
          following commands, which are entered at the "File nn:"
          prompt:

             (L) list all files to be transferred.
             (D) delete a file from the list.
             (S) display transfer statistics.

          Once file selection has ended, the user may start, abort,
          continue the list (if applicable; ie batch protocols only), or
          ask XHost to hangup after the transfer.

        List Files, File directory's number, 10, 0
        - This allows the user to view the file list for each directory.
          At the "Which file directory" prompt, a "?" (question mark)
          will display a list of available file directories, or the file
          DIRnnn.ext (where nnn is the conference number) if it exists.

        New Files, N, 10, 0
        - This will search all the available directories in the current
          conference for files which have been uploaded after the user's
          last call.

        Raw Directory, R, 20, 0
        - This allows the user to view the DOS directory of any
          accessible file directory (Telix's "show_directory" command).

        Search File List, S, 10, 0
        - This allows the user to search all the accessible file
          directories in the current conference for a text string. ANY
          field may be searched (name, size, date, and description).

        Text Files, T, 10, 0
        - This brings the user to the Text File viewer.

        Upload, U, 10, 0
        - This allows the user to send files to the system. All
          directories of the current conference are searched to ensure
          that duplication does not occur.

          All files are received into the temporary directory. XHost
          then processes each received file by searching for duplicates,
          and then by running the test routine corresponding to the
          file's archive extension (if upload testing is not disabled).

          If the file passes the test, it is then moved to the current
          conference's first directory.

        View Archive, V, 10, 0
        - This loads up the Archive Menu (003).


        ARCHIVE MENU  (level 10)
        ÍÍÍÍÍÍÍÍÍÍÍÍ

        Select Archive, S, 10, 0
        - This is is used to select the archive that is to be
          manipulated. All directories of the current conference are
          searched, wildcards are accepted (though only the first match
          will be processed), and full paths may be specified by users
          who have the required access levels.

      * Add to Archive, A, 10, 1
        - This allows the sysop to add any file in one of the
          directories or any path to the EXTRACT compressed file.

        Contents of EXTRACT, C, 10, 0
        - This lists the contents of EXTRACT.

        Delete in Archive, D, 10, 0
        - This allows the user to delete a file from EXTRACT. Wildcards
          are allowed.

        Extract, E, 10, 0
        - This will extract the specified file(s) from the selected
          archive and add them to EXTRACT. EXTRACT.arc is created in the
          second file directory of the current conference, where it is
          assumed that the user can access it.

        Kill EXTRACT, K, 10, 0
        - This will delete the EXTRACT file.

        List Archive, L, 10, 0
        - This lists the files in the selected archive.

        Type in Archive, T, 10, 0
        - This allows the user to view a text file within the selected
          archive.


        INFO & SETUP MENU
        ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

        Change Password, P, 1, 0
        - This allows the user to change the password they use on the
          system.

        Default Protocol, D, 1, 0
        - This allows the user to change the protocol used for
          transfers. If the protocol is set to "N" (for none), the user
          must choose a protocol before each transfer.

        Height of Screen, H, 1, 0
        - This changes the number of lines after which the system sends
        a "More? (Y)es, (n)o, (c)ontinuous:" prompt. Setting this to
        zero disables these pauses.

        List Info, L, 1, 0
        - This displays information on the user.

        Scan Conferences upon logon, T, 1, 0
        - This allows the user to toggle whether s/he wants to scan
          the conferences that s/he selected right after loggin on.

        Select Conferences to Scan, S, 1, 0
        - This allows the user to select the conferences to scan when
          the "Scan" command is used.





                       Access Levels and Security
                       ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     There are two variables which control a user's access to any
     function within XHost: the access level and the security flags.
     While the former is easily understood, the latter may need to be
     clarified for some. The security flags are a set of eight bits
     (either on or off), and a function is available to the caller only
     if all the function's flags are present in the caller's set.

     For example:

       if John D. has flags 01100100
          and dir 1 has     01000000
       then John D. has access to dir 1.

       If dir 1 has         11100100
       then John D. is not be able to use it.

     Also, the first flag (starting from the left) is the Sysop flag,
     while the second one marks the co-sysop; the rest of the flags can
     be used for any purpose. A user with the co-sysop flag can
     extract from an archive into any directory, read private messages
     (except those addressed to "SYSOP" or the Sysop's name), and change
     any message's status, receiver and subject.

     Security flags have one purpose: to make special designation
     independent of access level. Therefore, any user can be a sysop or
     co-sysop, regardless of their access level. One also could, for
     example, define the third flag as the "Adult" flag, and set it to 1
     on all conferences and file directories which only adults should
     have access to. Then only users with this third flag also set to 1
     (hopefully all adults) would be able to access them.

     Users should note that the conferences themselves can be made
     private or public, and access can be controlled using the
     registration flags. See THE USER EDITOR for a description of how
     this works.



                      The Archive Handling System
                      ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     XHost is designed to handle any archive type that the system
     operator wishes to use, and any number of different types. This is
     because all archive type information is stored in ARCS.CFG in the
     XHost data directory. The format is as follows:

     .[Extension]
     [List command]
     [Extract]
     [Add]
     [Delete]
     [Test]
     .[Next Extension]
     ...

     as in:

     .ARJ
     ARJ l -y %1 %2
     ARJ e -y %1 %2
     ARJ a -y %1 %2
     ARJ d -y %1 %2
     ARJ t -y %1 %2

     It is a CR/LF delimited text file. The first line for an archive
     type is its extension. Following are the commands to list the
     contents, extract from, add to, delete from, and test the archive.
     This can continue until all archive types have been defined. Note,
     however, that accessing this file can be extremely slow on
     XT computers, so it should not be made too large. The
     parameters "%1" and "%2" represent the archive and the secondary
     filespec. All of the commands are called using the SALT "run"
     function, except for archive list, which necessitates the "dos"
     function, since %2 is replaced by a DOS redirection in order to
     capture the archiver's ouput.

     XHost already comes with four defined types: ARJ, ZIP, LZH and ARC.
     The first defined type is taken to be the default type: it is used
     as default extension for filenames and to create the EXTRACT file.

     The transfer system will test uploaded archives if that option is
     enabled in Setup. There are three possibilities:

     1- File's extension not found in ARCS.CFG: File cannot be tested
        but is still accepted.
     2- Test command returns -1: Archiver was not found or not enough
        memory was available to load it. XHost will say "File could not
        be tested" and it is still accepted.
     3- Test command returns a value greater than 0: Test is assumed to
        have failed, and archive is deleted. An option of moving bad
        archives to another directory is in the works.
     4- Test command returns 0: Archive has no errors, and is accepted
        as an upload.



                            The User Editor
                            ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The EDIT.SLC script allows the editing of individual user records.
     Each user record contains the following information:

        Status character, alias, password, level, security flags, real
        name, area code and phone number, city and state, country, page
        length, transfer protocol, bytes available for downloading,
        uploaded bytes, downloaded bytes, uploaded files, downloaded
        files, time of last logon, time left for today, total number of
        calls, comment, scanned conferences, registered conferences,
        last message read for all conferences.

     Not all the data can be edited, but most relevant fields are
     accessible. The more adventurous can always use a sector editor for
     the remaining data fields.

     The user editor has a user list on the left-hand side and the data
     corresponding to the highlighted user displayed on the right. The
     editor can access the first 200 users on file.

     The following commands are valid while in the user list:

     Esc: Quit the user editor.
     Tab or Right: Edit highlighted user.
     S: Search for a string in the users' names.
     Del: Delete the current user. This only sets his DELETED status
          flag. XHost will skip over this user record, but PACK.EXE must
          be run to completely remove it.
     A: Add a user.
     Up: Previous user.
     Down: Next user.
     Home: First User.
     End: Last User.
     PgUp: Up 20 users.
     PgDn: Down 20 users.

     Editing a user:

     Esc: Cancel edit, return to user list.
     F1: Help on editing keys.
     F2: Save current user, return to user list.
     Up, Down: Change fields.

     Status Flags:

     (1=On 0=Off)
     1: Deleted flag. The record cannot be accessed, and PACK will remove
        the user on its next run.
     2: KickOut. Blacklisted user.
     3: Scan Msgs. This is the scan-upon-logon flag.
     4: Expert mode flag.
     5: Color. ANSI mode on/off.
     6: Not used.
     7: Capture. Everything sent/received is saved to file.
     8: Not used.

     Security Flags:

     1: Sysop
     2: Co-sysop
     3-8: Definable

     Conference Flags:

     The last two lines of the data window show two sets of flags. These
     can be set to indicate which private conferences the user can
     access (the "registered in" flags) and which conferences the system
     will scan for mail (the "scanned" flags).

     The Registered flags allow you to set up conferences for a
     particular group of users. They duplicate the role of the security
     flags, but since each conference can be toggled for each user this
     provides much more flexibility than the 6 extra security flags.

     The Scanned flags were installed in anticipation of the day when
     XHost will be able to accept mail from Fidonet, RIME, etc. It's
     just a simple feature to install, although I can't imagine anybody
     using XHost on a system where it would be necessary.



                           The Message Editor
                           ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     The message editor provided with XHost can operate as a full screen
     ANSI editor or as a line editor. Word-wrapping is always in effect;
     the maximum line length is 72 characters per line, and up to 99
     lines may be used. It currently displays 22 lines of the message
     per screen.

     The full screen editor uses ANSI codes to scroll, insert and
     delete text. This enables it to be much faster than other editors,
     which constantly need to redraw the current line or part of the
     screen in order to insert and delete text.

     The full screen mode provides the following options:

     - Cursor keys: edit a line and change lines.
     - Control-D: cursor right
     - Control-E: cursor up
     - Control-S: cursor left
     - Control-X: cursor down
     - Control-C: page down
     - Control-R: page up
     - Control-U: upload message (using ASCII protocol). It will pasted
                  into the message from the current line on.
     - Control-O: quote from original message (if replying)
     - Control-V: toggle insert mode
     - Control-Y: delete line
     - Control-Z: displays a short help screen

     - Escape: message menu (where the user can save, quit, continue,
               use the full screen editor, edit a line, insert a line,
               delete a line).

     The quote function (Ctrl-O) inserts the selected lines at the next
     line in the text. All quoted text is preceded by "> ".


                             Using PACK.EXE
                             ÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     PACK is the program that will remove superfluous data from XHost's
     data files. It will:

          remove received private and deleted messages;
          remove old messages;
          trim a message base to its correct size;
          remove inexistant files from FILES.LST in the directories;
          pack the LEVELS.DAT file;
          and pack the USERS.DAT file.

     PACK's command line can be:

     User file:      PACK /U telixdir
                     ex: PACK /U C:\TELIX

     Level file:     PACK /L hostdir
                     ex: PACK /L C:\TELIX\HOST

     Message bases:  PACK /M[conf#] hostdir
                          /M0 hostdir  to pack all message bases
                     ex: PACK /M2 C:\TELIX\HOST

     File lists:     PACK /F filedir
                          /F0 hostdir  to pack all file lists
                     ex: PACK /F C:\FILES

     Note that only one option may be used at a time. To perform ALL of
     the above operations, use:

     PACK telixdir hostdir   as in PACK C:\TELIX C:\TELIX\HOST

     which will pack the user file, the level file, all conferences
     which have messages, and all the file directories of each
     conference.


                           Installing Bimodem
                           ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     XHost can use most of Bimodem's features, but installation is
     somewhat complicated. The batch files defined in Telix under
     external protocols can be only be used if the caller is uploading
     (ie sending to the host); for downloads, XHost will call the batch
     file HBIMOD.BAT which must reside in the Telix directory (or one
     included in the system's PATH).

     It might be practical to have a two Telix configuration file: one
     for normal use, and another with the modifications that XHost
     needs.

     Step 1: Install Bimodem in Telix (Alt-O P A/B/C/D)

             Set "download name" to HBIMOD, and "Bat or Script" to Bat.
             "Upload name" is the name of your batch/file script for
             uploads. Fill in the remaining fields, and set "ask for
             download name" to No.

     Step 2: Install Bimodem in XHost (XHost Setup, Option 6)

             Go to the first blank key, and enter THE SAME KEY that
             you entered in the Telix config. Set all other fields to
             "Y". It would also be practical to include it in the
             protocol menu (PROTO.ASC and PROTO.ANS).

     Step 3: Create HBIMOD.BAT in your Telix directory.

             Use your favourite editor to create this batch file, which
             will be used for downloads and uploads. It must:

             1 - change to correct drive and directory
             2 - run Bimodem with the necessary command line parameters.

               For example:

               C:
               CD\BIMOD
               BIMODEM /IC:\TEMP\BIMOD.LOG /U@C:\TEMP\FILES.LST %3

               - replace C:\TEMP with the path to the temp directory
               - %3 will become /Snnn /Tnnn, the time and byte limits
                 for Bimodem (passed by XHost) - you may wish to use
                 /L%1 and /B%2 to set the com port and baud rate.
               - Notes: If you don't care about statistics, the
                 /IC:\TEMP\BIMOD.LOG can be left out; otherwise it must
                 be named BIMOD.LOG and be in the temporary directory.
                 Also, the /I option may not be available for copies of
                 Bimodem that are older than v1.24. If such is the case,
                 then use SET DSZLOG=[filename] instead, as described
                 in INSTALLING OTHER EXTERNAL PROTOCOLS.

     Step 4: Configure Bimodem using BiMenu

     -> under filenames & paths:

        Rejection path: C:\TELIX\APATHS.LST
        - This file needs to be created once (use the provided GENP
        utility). It contains all the directories Bimodem will search
        search before accepting an upload, and it may reside in any
        valid directory (though GENP will create it in your Telix
        directory).

        Send paths:     C:\TEMP\PATHS.LST
        - This file will be created each time Bimodem is run to reflect
        the directories that the current user has access to. It is
        always created inside your temporary directory. If the user
        cannot bypass FILES.LST, then this file contains nothing, and
        the user is limited to what was entered within XHost at the file
        prompt. Otherwise, the user is free to add as many transfers as
        will fit into the time and byte limit set on the command line by
        XHost (the user may accomplish this by either adding downloads
        to his .PTH file before starting the transfer, or by using Alt-A
        during the transfer with a registered copy of Bimodem).

        Receive path    C:\TEMP\
        - Your temporary directory, where XHost expects to find all
        received files, so that it can move them into the upload file
        directory after verifying them.

     -> under general options:

        YES to Allow Remote Requests (otherwise user will not be able to
                                      upload)
        NO  to Allow full path+name (it is risky to leave this as YES)



                    Installing Other External Protocols
                    ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
                          (including HS/Link)

     XHost supports all external protocols which can write a DSZLOG
     transfer log file (if statistics are not required, then any
     protocol will work). Batch protocols MUST be able to process
     transfer lists as all filenames will be written to a text file in
     the temporary directory.

     Step 1: Install Protocol in Telix (Alt-O P A/B/C/D)

             Fill in all the fields.

     Step 2: Install Protocol in XHost (XHost Setup, Option 6)

             Go to the first blank key, and enter THE SAME KEY that
             you entered in the Telix config. Set all other fields
             appropriately. You should then add a line in the protocol
             menu for the one you are now installing.

     Step 3: Create all batch files/scripts to run protocol

             Your batch file/script must ensure the following:

             1 - the protocol puts all received files into your temp
                 dir. (for uploads)

             2 - the protocol is given the correct download name.
                 Batch protocols: @C:\TEMP\FILES.LST, others: %3

             Sample Batch File to run HS/Link:

             (Download)
             CD\HSLINK
             HSLINK @C:\TEMP\FILES.LST -UC:\TEMP

             (Upload)
             CD\HSLINK
             HSLINK -UC:\TEMP

            - C:\TEMP must be replaced by your temporary directory's
              name

     Step 4: Set DSZLOG if stats are required.

             The DSZLOG environment variable must be set or else XHost
             will not be able to properly update the users' statistics
             or keep an accurate log of system use. The simplest way to
             do this is to append to your AUTOEXEC.BAT the line:

             SET DSZLOG=[path][filename]
             as in
             SET DSZLOG=C:\TELIX\TRANS.LOG



                      Files used/created by XHost
                      ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     A .ext extension indicates that the filename with a ANS extension
     will be displayed to users with ANSI color set to ON, while the ASC
     version will be sent to others. If the ANSI file is not found, then
     the text (ASC) file will be sent to all users.


     in XHost directory:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

     May be modified using an editor:
     ARCS.CFG       Archiver configuration file
     BIMOD.ext      Text file explaining Bimodem procedure to users
     CONFS.ext      List of all conferences for users
     FIRST.ext      Logon screen
     LAST.ext       Logoff screen
     MENUnnn.ext    Menu screens, nnn = menu number
     POLICY.ext     "Policy of the Board" text file
     PRIVATE.ext    Text file to new users for closed systems
     PROTO.ext      List of transfer protocols

     Use Setup to modify these:
     CONFS.DAT      Conference data file
     LEVELS.DAT     Levels data file
     MENU.DEF       Menu definition file

     XHOST.CAP      Capture file if all calls are to be captured
     *.CAP          Capture file for one particular user, with *
                    representing the user's name (first eight
                    characters, blanks replaced by underscores).


     In the conference's path:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

     (nnn = conference number, 0 padded from the left)

     You can create these with an editor:
     DIRnnn.ext     List of all directories in conference for users
     DORnnn.ext     List of all doors in conference for users
     TXTnnn.ext     List of all text files in conference for users
                    (These files are optional; XHost will generate its
                    own list if they are not found.)

     These are generated by Setup:
     nnn.DIR        File directories
     nnn.DOR        Doors
     nnn.TXT        Bulletins
     nnn.MSG        Message data file
     nnn.IDX        Message index file


     in Telix dir:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍ

     XHOST.LOG      Log file (can be toggled in Setup)
     USERS.DAT      User data file

     in File Directories:
     ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

     FILES.LST      File list (unless disabled in Setup)

     Others:
     ÍÍÍÍÍÍÍ

     SHELL.BAT      Batch file used to call DOS shell
     XH$$$.TMP      Temporary file used for various tasks
     EXTRACT.arc    Archive containing user extracts (in dir #2)
                    The default archiver (first one defined in ARCS.CFG)
                    is used to create it.
