









                       ±±±±±±±±Ü      ±±±±±±±±Ü      ±±±±±±±±Ü
                       ±±Ûßßß±±Û      ±±Ûßßß±±Û      ±±Ûßßß±±Û
                       ±±Û    ßß      ±±Û    ßß      ±±Û    ßß
                       ±±Û            ±±±±±±±±Ü      ±±±±±±±±Ü
                       ±±Û              ßßßß±±Û        ßßßß±±Û
                       ±±Û   ±±Ü      ±±Ü   ±±Û      ±±Ü   ±±Û
                       ±±±±±±±±Û      ±±±±±±±±Û      ±±±±±±±±Û
                        ßßßßßßßß       ßßßßßßßß       ßßßßßßßß











                   CSS - The SIMPLE Language PreProcessor for Telix

                          Version 1.1 Date: April 7th, 1991

                      Copyright 1991, by Host Software Products











                                Host Software Products
                                  15837 Windrose Way
                               San Diego, CA 92127-2066


                              Daniel E. Horn - President
          
                                                                    Page: 1

                                     WHAT IS CSS?


          CSS is a full scale PreProcessor for the SALT (Script Application
          Language  for Telix) and provides  an easy to  use and understand
          language called SIMPLE.  CSS compiles directly into SALT and then
          automatically compiles  the SALT script by running the CS program
          provided with the  Telix (C) communications program.   CSS allows
          the  user to write scripts  using the SIMPLE  language, which are
          fully compatible and executable under the Telix program,  but are
          easy to write and are completely understandable.

          The SIMPLE language  was written with the base user  in mind.  It
          is a  language  based upon  the English  sentence structure,  and
          functions named  according to their operations.   This provides a
          language easily remembered, and simple to work with.
          
                                                                    Page: 2

               This program  is distributed  under  the Shareware  concept.
          Non-Registered  users of CSS are granted a limited license to use
          it for a 4 week trial period, to determine its usefulness to you.
          ANY other use of CSS after that period is strictly prohibited.

                                    WHY REGISTER?

          *    Registration allows you to use CSS on a regular basis.

          *    Registered users will receive mailed notification of updates
               to the program.

          *    Registered users also  will receive top priority in any help
               or comments they have/need.

          *    Registered  users receive  copies of  the program  that have
               the register comment removed.

          *    The registered version also contains the ability to save the
               resulting SALT file to disk to view its contents.  As  well,
               resulting SIMPLE  scripts compiled  will no longer  have the
               notification delay in running.

          *    Registered users can join the beta test process,  and    can
               receive previous of any new software

          Registration  is US$20.00  plus  US$2.50 (US$3.50  overseas)  for
          shipping and handling and covers all the above features.


               To order, make check or money order payable:

                                        Host Software Products
                                        15837 Windrose Way
                                        San Diego, CA  92127-2066 USA
          
                                                                    Page: 3

                                Host Software Products
                                  15837 Windrose Way
                             San Diego, CA 92127-2066 USA

          -----------------------------------------------------------------

          Please Send:

          CSS 1.1 Registration. . . . . . . . . . . . US $20.00 _____

          Shipping and Handling include US $2.50 (US $3.50 Overseas)

          Disk Size:  5.25" _____   3.5" _____

          { Please Print }

          Name   : ________________________________________________________

          Address: ________________________________________________________

                   ________________________________________________________

                   ________________________________________________________

          Day Phone: (____)_____-______      Evening: (____)_____-______

          Comments: _______________________________________________________

                    _______________________________________________________

                    _______________________________________________________

          { Optional }

          Computer Type:___________________________________________________

          Color Display [Y/N]: ___

          Where did you hear about (and/or receive a copy of) CSS?

          {  } BBS Name ________________________ Ph.#(____)_____-______
          {  } Sig Name _______________________________________________
          {  } CompuServe
          {  } Friend
          {  } Other: _________________________________________________

          _________________________________________________________________
          
                                                                    Page: 4


               This program  evolved  from  an  idea from  talking  to  and
          hearing  complaints from people  who felt that  the SALT language
          was too difficult to use, too hard to remember, and  to "Big" for
          those  tiny little  scripts.   It  was  written originally  as  a
          project to test out a theory  of mine and eventually was expanded
          to its current  abilities.  CSS  is an  ongoing project and  will
          continue to be worked and expanded as time goes by.


                                      DISCLAIMER

          This  program is provided  as is,  and is to  be run  at your own
          risk.   There is NO  warranty of any  kind or form  covering this
          program.   Exis, Inc., Colin Sampaleanu,  Host Software Products,
          and the author, are not in any way responsible, or liable for any
          damages  of any  kind  that  may arise  from  the  usage of  this
          program, or that of any program or  files that are associated, or
          included with it.

          TELIX.EXE, CS.EXE, and SALT are copyright 1986, 1987, 1988, 1989,
          1990, 1991, by Exis Inc., and Colin Sampaleanu.
          Used with permission.
          
                                                                    Page: 5


                                      USING CSS

          Before  you can run a  SIMPLE script file  you must first compile
          the script  using CSS.   CSS  accepts a  single  filename on  the
          command line with  a default  extension of 'SIM',  and will  then
          process the file into the SALT language.  If there are any errors
          encountered during the compilation, CSS will report them and halt
          the process.  Following is  an example of how to invoke  CSS with
          the filename of LOGON.

            CSS logon

          CSS will attempt to  compile the SIMPLE script and  if successful
          will automatically run  CS.EXE.   If CS.EXE cannot  be found,  or
          there was not enough memory to run CS.EXE then CSS will abort the
          process with  the appropriate  error.   CS.EXE  should be  placed
          someplace  in  your  PATH statement  so  that  CSS  can find  it.
          Optionally the use of  the Environment variable CS can  be placed
          in the environment as follows:

            CS=C:\TELIX\SCRIPTS

          Where "C:\TELIX\SCRIPTS"  is the full path  where CS.EXE resides.
          This is useful if you keep  CS.EXE in a directory that is  not in
          your path.
          
                                                                    Page: 6


                                 THE SIMPLE LANGUAGE

          The SIMPLE  (Salt  Implementation) language  is  an easy  to  use
          language  made   up  of   functions  named  according   to  their
          operations.  The  SIMPLE language is compiled  directly into SALT
          via  CSS  and  then   compiled  into  a  script  using   CS  (run
          automatically  by CSS).  The language was written with the novice
          user  in  mind  and is  easy  to use.    Following is  a  list of
          functions currently supported by CSS,  the SIMPLE specifications,
          and a description of  each function.  The SIMPLE  language script
          is designed to  have a single function on each  line of the file.
          In certain cases, as with WAITFOR or WHENEVER, there are multiple
          functions on a single line.


                                       NOTATION

          Throughout the  following pages,  certain words  in the  text are
          notated by <expression> or  [expression].  Any words  in standard
          brackets are entirely optional statements and are not required by
          CSS to be included in the statement for compilation.  Expressions
          such as <Integer> are to be replaced with an actual integer (from
          -32,000 to +32,000)  in the code and should not  be placed in the
          actual script.   Words such  as <Sx> are  string expressions  and
          should be replaced  with either  a string constant  (ie group  of
          words  in quotations,  such as  "This is a  string") or  a string
          variable.  String  variables consist of the  word STRING followed
          by an  integer as in STRINGxx, where  'xx' is a number  from 1 to
          16. An example of a valid string variable would be STRING3, while
          STRING17 is invalid.

          _________________________________________________________________
          ALARM <Integer>

          Causes an alarm to ring of up to <Integer> seconds.

          Example:

          ALARM 2

          _________________________________________________________________
          WAIT <Integer>

          Causes the script to wait for up to <Integer> seconds.

          Example:

          WAIT 10
          
                                                                    Page: 7

          _________________________________________________________________
          SEND <Sx> [HITENTER]

          Sends the string <Sx> to the remote system, optional HITENTER can
          be  placed  following the  string and  SEND  will add  a Carriage
          Return (ie as if you pressed  ENTER) after the string.  Note that
          you can omit <Sx> and  just do SEND HITENTER and only  a Carriage
          Return will be sent.

          Example:

          SEND "John Smith" HITENTER

          _________________________________________________________________
          SHELL

          Do a  Shell to  DOS (Same  thing as  pressing  ALT-J from  within
          Telix).

          Example:

          SHELL

          _________________________________________________________________
          SOUND <Integer1>, <Integer2>

          Causes  a sound  of  <Integer1>  frequency,  for  a  duration  of
          <Integer2> tenths of seconds.

          Example:

          SOUND 200, 30

          _________________________________________________________________
          HANGUP

          Causes Telix  to hangup the phone.   (Same as pressing ALT-H from
          within Telix).

          Example:

          HANGUP

          _________________________________________________________________
          MESSAGE <Sx>

          Prints  the string <Sx> on the screen  surrounded by a box for 30
          seconds.

          Example:

          MESSAGE "Connected to BBS"
          
                                                                    Page: 8

          _________________________________________________________________
          PRINTER (ON/OFF)

          Turns the Printer capture ON or OFF depending on which  switch is
          used. (Same as pressing Ctrl-@ from within Telix).

          _________________________________________________________________
          TIME <Sx>

          Places the current time into the string variable <Sx>.  Note that
          <Sx> *MUST* be a string variable of STRING1 - STRING16.

          Example:

          TIME STRING2

          _________________________________________________________________
          DATE <Sx>

          Places the current date into the string variable <Sx>.  Note that
          <Sx> *MUST* be a string variable of STRING1 - STRING16.

          Example:

          DATE STRING11

          _________________________________________________________________
          INPUT <Sx>, <Integer>

          Gets up to <Integer> characters from the keyboard and places them
          into the string variable <Sx>.  Note that <Sx> *MUST* be a string
          variable of STRING1 - STRING16.

          Example:

          INPUT STRING7, 20

          _________________________________________________________________
          SHOW <Sx> [HITENTER]

          Prints the string <Sx>  to the screen.  Optional HITENTER  can be
          placed following the string  and SHOW will add a  Carriage Return
          (ie as if you pressed ENTER) after the string.  Note that you can
          leave <Sx>  out and  just do  SHOW HITENTER and  only a  Carriage
          Return will be printed.

          Example:

          SHOW "Hello" HITENTER
          
                                                                    Page: 9

          _________________________________________________________________
          ASSIGN <Sx1>, <Sx2>

          Assign the string <Sx2> to the string variable <Sx1>.   Note that
          <Sx1> *MUST* be a string variable of STRING1 - STRING16.

          Example:

          ASSIGN STRING1, "John Smith"

          _________________________________________________________________
          UPLOAD <Sx> [WITH <Protocol>]

          Uploads string filename <Sx> to the remote system (note that <Sx>
          must  be a valid filename), optional WITH <Protocol> can be added
          to the  end  and  the  upload  will  be  made  with  the  defined
          <Protocol>.   Note that  <Protocol>  *MUST* be  a valid  protocol
          name.  If it is not, Telix will  prompt you for the protocol when
          you attempt the upload.

          Examples:

          UPLOAD "TEST.ZIP"
          UPLOAD "FILELIST.ZIP" WITH Zmodem

          _________________________________________________________________
          DOWNLOAD <Sx> [WITH <Protocol>]

          Downloads string  filename <Sx> from the  remote system, optional
          WITH <Protocol> can be added to  the end and the download will be
          made with the defined <Protocol>.  Note that <Protocol> *MUST* be
          a valid protocol  name.  If it is not, Telix  will prompt you for
          the protocol when you attempt the download.

          Example:

          DOWNLOAD "TELIX1.ZIP" WITH Xmodem

          _________________________________________________________________
          WAITFOR <Sx> [MAXOF <Integer>] THENDO <Command>

          Waits  for the  string  <Sx> from  the com  port for  an optional
          <Integer> number of  seconds (If  no MAXOF <Integer>  is given  a
          default  of 30 seconds is used).   If the string <Sx> is received
          then the  <Command> (following THENDO)  is processed.   Note that
          <Command> can be any of the command functions in SIMPLE.

          Examples:

          WAITFOR "First Name: " THENDO SEND "John" HITENTER
          WAITFOR "Download: " MAXOF 50 THENDO SEND "NEWFILES.ZIP" HITENTER
          
                                                                   Page: 10

          _________________________________________________________________
          DIAL <Sx> [FROM <Sx>] [MAXOF <Integer>]

          Dials  the numbers  in the  string <Sx>  (format of  number space
          number  etc., ie  "1  2 3"),  optional  FROM <Sx>  allows  you to
          specify the phone  directory (string <Sx>) to dial from.  If FROM
          <Sx> is  not given  then it  will dial  from the  current dialing
          directory.  Optional  MAXOF <Integer> allows  you to specify  the
          total  number of  dialing  attempts before  quitting.   If  MAXOF
          <Integer> is not given  then it will  dial until a connection  is
          established.

          Examples:

          DIAL "1 5 2" MAXOF 30
          DIAL "6 13" FROM "INSTATE.FON"

          _________________________________________________________________
          BBSPASSWORD

          This  constant contains  (When a  connection is  established) the
          password defined for the dialing directory entry.  It can be used
          with the functions  SHOW, SEND,  MESSAGE, and ASSIGN.   The  most
          common use would be with SEND to send your password to the remote
          system.

          Example:

          WAITFOR "Password: " THENDO SEND BBSPASSWORD HITENTER

          _________________________________________________________________
          RUNSCRIPT <Sx>

          This will run  the script  name <Sx>, note  that the string  <Sx>
          must contain a valid script name.

          Example:

          RUNSCRIPT "LOGON.SLC"

          _________________________________________________________________
          DOS <Sx> [PAUSESCREEN]

          Runs  the command  given  in the  string  <Sx> in  DOS,  optional
          PAUSESCREEN will cause the  screen to pause once the  command has
          been run and will wait for a key to be pressed.

          Example:

          DOS "DIR /W" PAUSESCREEN
          
                                                                   Page: 11

          _________________________________________________________________
          STARTWHEN

          Starts a WHENEVER loop.  All commands following STARTWHEN must be
          WHENEVER commands until a following ENDWHEN command is given.

          Example:

          STARTWHEN
            WHENEVER "First" THENDO SEND STRING2 HITENTER
          ENDWHEN

          _________________________________________________________________
          WHENEVER <Sx> THENDO <Command>/<QUITWHEN>

          Continues to  wait for the string <Sx>.  Once the string <Sx> has
          been  received then  the  command  <Command>  is executed.    The
          <Command> can be  any of the SIMPLE functions.   If the <Command>
          is QUITWHEN then  the STARTWHEN  loop is aborted  and process  is
          continued after the ENDWHEN.  Note that if none of the WHENEVER's
          within a STARTWHEN  loop have  the command of  QUITWHEN then  the
          *LAST* WHENEVER  is assumed to be the final one and the loop will
          finish  after that string has been processed.   Note that you can
          use the BLOCKSTART/BLOCKEND commands  to do multiple commands for
          a single WHENEVER statement.

          Example:

          STARTWHEN
            WHENEVER "First" THENDO SEND "John" HITENTER
            WHENEVER "Last" THENDO SEND "Smith" HITENTER
          ENDWHEN

          _________________________________________________________________
          ENDWHEN

          Ends the WHENEVER loop, must be placed after a STARTWHEN and only
          WHENEVER statements (Up  to 12) can  be placed between  STARTWHEN
          and ENDWHEN.

          _________________________________________________________________
          CLEARSCREEN

          Clears the screen (just as if you pressed ALT-C).

          _________________________________________________________________
          USAGELOG (ON/OFF)

          Turns the Telix Usagelog on or off (depending on which switch is
          used.  (Same as pressing ALT-U from within Telix).
          
                                                                   Page: 12

          _________________________________________________________________
          EXITTELIX

          Causes the current script to terminate and exit Telix.   (Just as
          if you pressed ALT-X from within Telix).

          _________________________________________________________________
          ERASEFILE <Sx>

          Erases the file whose name is specified in the string <Sx>.

          Example:

          ERASEFILE "TEMP.DAT"

          _________________________________________________________________
          CHANGEDIR [<Sx>]

          Changes the current  directory to the directory  specified in the
          string  <Sx>.   Note that <Sx>  is not  required and  if left out
          Telix will prompt you for the directory you wish to change to.

          Example:

          CHANGEDIR "C:\UPLOADS"
          CHANGEDIR

          _________________________________________________________________
          BLOCKSTART

          This  command is  used to  specify a  block of  commands (between
          BLOCKSTART and BLOCKEND) that  should be executed.  For  use only
          with  the WHENEVER  and WAITFOR  commands, specifically  in cases
          where you wish to do more then one command per case.
 
          Examples:

          STARTWHEN
            WHENEVER "Command:" THENDO BLOCKSTART
             SEND "U TEST.ZIP" HITENTER
             UPLOAD "TEST.ZIP" WITH ZMODEM
             BLOCKEND
            WHENEVER "Download" THENDO DOWNLOAD "TEST.ZIP"
          ENDWHEN

          WAITFOR "Command" THENDO BLOCKSTART
            SEND "D TEMP.DAT" HITENTER
            DOWNLOAD "TEMP.DAT"
            BLOCKEND
          
                                                                   Page: 13

          _________________________________________________________________
          BLOCKEND

          Used with the BLOCKSTART  command to specify a block  of commands
          to be processed.  Used in WAITFOR and WHENEVER statements.

          _________________________________________________________________
          CAPTURELOG (<Sx>/OFF/PAUSE/UNPAUSE)

          Used to control the Telix capture log, following is a list of the
          toggles and their use:

          CAPTURELOG <Sx>    - Open capture log with the string containing
                               the name of the file.
          CAPTURELOG OFF     - Close/stop capture log currently opened.
          CAPTURELOG PAUSE   - Pauses the currently opened capture log.
          CAPTURELOG UNPAUSE - Unpauses a previously paused capture log.

          The  capturelog function  follows the  use of  the ALT-L  capture
          function in Telix.
          
                                                                   Page: 14


                             WHAT'S AHEAD IN THE FUTURE?

               o Addition of IF THENDO command control statements.

               o Support for up to 32 STRING variables.

               o Addition of GOTO statements.



                               THANKS AND APPRECIATION


               Much  of my thanks and  appreciation goes to  Jeff Woods who
          has  helped me with the layout and format of the SIMPLE language,
          and  provided encouragement and lots of good ideas.  The original
          idea started out  as an off the wall discussion  between Jeff and
          myself.

              I can't thank you enough Jeff!

               Special   thanks  to  Ben  Hoffman   for  his  work  on  the
          documentation.  He  pointed out  a few grammatical  errors and it
          made the docs look much better!

               Thanks Ben!


               Of  course,  as always,  thanks  goes  to Colin  Sampaleanu.
          Without all  the hard work and  effort he has put  into Telix and
          SALT, this work would be worthless!

               Thanks again Colin!
          
                                                                   Page: 15


                                WHAT'S NEW IN CSS 1.1?

               o Added BLOCKSTART/BLOCKEND commands to allow processing of
                 multiple commands in single WHENEVER/WAITFOR commands.

               o Added ERASEFILE command to allow the erasing of files.

               o Added CHANGEDIR command to allow the changing of the
                 current directory.

               o Added EXITTELIX command that allows the script to exit
                 Telix.

               o Added USAGELOG command to allow access to the Telix usage
                 log.

               o Added CLEARSCREEN command, to allow scripts to clear the
                 screen.

               o Added CAPTURELOG command to allow full access to Telix's
                 capture ability.

               o Fixed the track renumbering bug that caused CSS to
                 incorrectly number tracks when doing more then 12 tracks
                 in more then one WHENEVER loop.

               o Fixed bug that caused CSS not report internal compile
                 error's which may occur due to other bugs.

               o Increased CSS (but not CS!) compiling time, CSS 1.1 can
                 now compile from 50 to 200 lines of code into SALT code
                 per second.  (Actual speed varies due to processor speed
                 and type).
          
                                                                   Page: 16


                                    REGARDING DOCS

               We are always  looking for  people who are  good at  writing
          documentation.  If you feel you  can do a better job, then please
          do so and give us  the end result.  We will take all applications
          and choose the one  we feel is best.  If yours  is the one chosen
          you will receive a free registration to CSS (or upgrade if you're
          already registered), and mention in our docs!


                                  TECHNICAL SUPPORT

               If you have any bugs, comments, or suggestions for us on CSS
          please let us know.  You can reach us in the following ways:


               BEST WAY!-> PCRelay (RIME), HOST-BBS Conference

                           If your PCRelay Board does not carry our support
                           conference ask them to! Ask for:

                              HOST-BBS - RelayNet Master Number #203


                           Telix Support BBS: (416) 439-9399

                           PCRelay (RIME), Telix Conference
                           FIDO Net, Telix Conference
                           InterLink, Telix Conference

               BEST WAY!-> Call our Tech Support BBS at: (619) 674-1548

                           Or call us voice at: (619) 674-1549
                           Business Hours: Mon-Fri 11am-5pm Pacific Time

                           Or write us at:

                              Host Software Products
                              15837 Windrose Way
                              San Diego, CA  92127-2066 USA

          
