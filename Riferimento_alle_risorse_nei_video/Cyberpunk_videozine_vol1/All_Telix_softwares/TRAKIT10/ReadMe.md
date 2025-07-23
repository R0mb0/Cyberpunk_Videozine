






















                             /                                            
   TrackIt!                //                                             
                         ///           ษออออออออออออออออออออออออออป
   Version 1.0         ////            บ Program Reference Manual บ
                     // //             ศออออออออออออออออออออออออออผ
                   //  //                                                 
                 //   //                                                  
               //    //                                                   
             //     //////////                                            
           //             //                                              
         ////////////   //                                                
                 //   //                                                  
               //  //                                                     
             //  //                                                       
           // //                                                          
         // //                                                            
       ////                                                               
     ////                                                                 
   ///                                                                    
 //                                                                       
/          Copyright (C) 1994 by Michael S. Hogg, All Rights Reserved.    

























                    License Agreement, Disclaimer, and Legal Stuff

          Every precaution has been taken to ensure that no harm or damage
          will occur on systems running TrackIt!. However, by using this
          software the user assumes all responsibility for any damages or
          other loss of data that may occur from the use or inability to
          use TrackIt!. NO WARRANTIES ARE IMPLIED OR EXPRESSLY STATED.

          TrackIt! and this documentation are copyrighted materials. All
          rights to these materials are reserved, and are protected under
          United States and International Copyright Laws. No part of these
          materials may be reproduced or modified in any way without the
          prior express written consent of Michael S. Hogg.

          TrackIt! is a Shareware product. It is NOT freeware or public
          domain. After a reasonable trial period (not to exceed 14 days),
          you must register TrackIt! in order to legally use it. In return
          for your registration, you will be provided a key to register
          this and any future versions. Please see "Registering" for more
          information.

          An unlimited license to make and distribute unregistered copies
          of this software is granted. Absolutely no modifications to the
          files contained in the software package, including this
          documentation file, may be made before distribution. No fee may
          be charged by anyone other than Michael S. Hogg beyond the actual
          cost of providing these copies without the prior written consent
          of Michael S. Hogg.
           
          TRACKIT! IS PROVIDED ON AN "AS IS" BASIS WITHOUT WARRANTY OF ANY
          KIND EXPRESSED OR IMPLIED. IN NO EVENT WILL MICHAEL S. HOGG BE
          LIABLE TO YOU FOR ANY DAMAGES, INCLUDING ANY LOST PROFITS, LOST
          SAVINGS OR OTHER INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT
          OF THE USE OF OR INABILITY TO USE THE PROGRAM, EVEN IF MICHAEL S.
          HOGG HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES, OR  
          FOR ANY CLAIM BY ANY OTHER PARTY.

          Use of TrackIt! constitutes acceptance of the stated terms and
          conditions. Michael S. Hogg reserves all rights which are not
          expressly granted.
               
          SALT and Telix are trademarks of deltaComm Development. Use of
          Telix(tm) for longer than 45 days without appropriate payment to
          deltaComm Development for Telix is a violation of International
          Copyright Law.

          ----------------------------------------------------------------

          Note to CompuServe Users's:

          If you downloaded TRACKIT! from CompuServe, please rename the
          archive to TRKIT!10.ZIP before uploading it elsewhere.







          TrackIt! v1.0                                                  ii







                                   C O N T E N T S




          License Agreement, Disclaimer, and Legal Stuff...............  ii

          Introduction.................................................   1

          Quick Start Guide............................................   2

          Using TrackIt! - Detailed Guide..............................   4

            How TrackIt! Works.........................................   4

            How to Start TrackIt!......................................   4

            Using the Edit Box.........................................   5

            The Track String...........................................   5

            The Reply String...........................................   6

            Setting Maximum Hits.......................................   6

            Testing Tracks Offline.....................................   7

          Advanced Features - The @ Command Set........................   8

          The Configuration File - Basic Settings......................  10

          The Configuration File - Advanced Settings...................  11

          Tips and Tricks..............................................  12

            How to get unlimited tracks................................  13

            Working Around 20 Character Reply String...................  14

          Companion Scripts, Uploading & Downloading...................  15

          Registering TrackIt!.........................................  16

          How to Contact the Author....................................  17

          Acknowledgements.............................................  18

          Registration Form............................................  19










          TrackIt! v1.0                                                 iii






                                     Introduction

          Welcome to TrackIt! This script represents a new approach to
          taking advantage of Telix's tracking commands. You will no longer
          have to worry about SALT programming to generate high speed track
          scripts for your favorite BBS's. You will no longer have to worry
          about a sixteen track limit per board. You won't have to worry
          about recompiling a new script if a BBS changes one of the
          prompts. You will never have to edit, or even look at code again.
          TrackIt! will do all the work for you, and at a lightning fast
          speed!

          TrackIt! is a product born of necessity. To my knowledge, there
          isn't another high quality Track learner available for Telix.
          There are several script learners available, but they are slow.
          The other alternative was manually writing and compiling a Track
          script for each board you called. Both the script learners, and
          the manual method would require you to edit and recompile the
          scripts if a BBS changed a single prompt. This was unacceptable.

          I have tried to design TrackIt! to be easy enough for the novice
          user, and yet powerful enough to satisfy hard core users. Since
          TrackIt! doesn't work like most of the popular script learners
          available now, it will probably take a little getting used to.
          Once you try it out on one or two BBS's you will begin to see why
          TrackIt! is far superior to those other script learners. For
          those of you who call long distance, TrackIt! is the script you
          need to insure fast, fail-safe mail runs!































          TrackIt! v1.0                                                   1






                                  Quick Start Guide

          Installing:

          TrackIt! works from within your Telix script directory. Simply
          place all the files into that one directory. Use ALT O,F to see
          if you have a script directory defined in Telix's configuration
          menu. If you do not, then the same directory which contains
          TELIX.EXE is where you should unpack the distribution files.


          Starting TrackIt!:

          Load Telix. Go to the dialing directory. For every BBS you wish
          to use TrackIt! with, simply list TRACKIT! as your linked script
          file. Call the BBS.


          Bringing up the edit box:

          When you come to a prompt, do NOT type anything. Instead, press
          the HOME key. An edit box will appear. The first line in the edit
          box is the prompt (20 chr max) you were at when you hit home. The
          second line, is where you place your reply to that prompt. The
          last line is the maximum number of times to recognize the track.


          How to use the edit box:

          When you bring up the edit box with the home key, you start out
          at the Reply String. The red arrow will indicate this. To move to
          one of the other fields, simply use the TAB key. If the edit box
          is covering part of the screen you need to see, you can move the
          edit box itself with the arrow keys. When you are satisfied with
          all the fields, you can use HOME or END to exit from the edit
          box. If you use HOME, then TrackIt! will assume you are at that
          prompt now, and send the Reply String. If you use END, it will
          assume you are NOT at that prompt, and simply return you to
          terminal mode. Please note, if you use HOME to exit, it will
          count as a hit toward the maximum hits. See "Setting Maximum
          Hits" for more information.


          Reply String:

          Simply enter what you would normally enter at the prompt in this
          field. RETURNs will show up as a musical note, and ESCs will show
          up as a back arrow. If you know this prompt will appear more than
          once while you are online, and you will want a different reply
          the second or third time, then use a PIPE to separate the
          replies. You may use the INSERT key to generate the pipe.
          Multiple replies are sent sequentially. The first time the track
          is HIT (or is seen by TrackIt!) the first reply is sent, second
          time, second reply, etc.. if it's hit more times than there are
          replies, then the last reply is always sent. However, you must
          have Maximum Hits set high enough to recognize multiple replies.



          TrackIt! v1.0                                                   2







          If you know the prompt will appear again, but are not sure what
          reply you will want at that time, then simply leave Maximum Hits
          set to one. When you see the prompt the second time, press HOME
          again, and TrackIt! will go to that track automatically. Then you
          may use INSERT (pipe) and put your second reply. Make sure you
          update the Maximum Hits though, or this will not work.

          If you don't know how many times the prompt will appear, or know
          it will appear quite often (such as "Press a key" etc..), then
          set the Maximum Hits to ZERO. Doing this will cause TrackIt! to
          always recognize that prompt, and send the reply.

          Once you set a track, it will take effect immediately.


          Ending TrackIt!:

          After you have entered all the prompts you wish to track, you may
          end TrackIt! by pressing the END key.


          Now that you have entered all the prompts and replies, hang up
          and call the same BBS again. This time, just set back and watch.
          If the BBS should happen to give you a prompt this time that it
          didn't before, simply use the HOME key and add that prompt. The
          order the prompts are in doesn't matter.

          The Quick Start Guide only represents the very basics of
          TrackIt!. There are several commands you may use in the tracks to
          perform various task. An example would be @PASS as a reply. This
          command would send whatever you have your password set to in the
          dialing directory. 

          Most people prefer to see a program work before they take time to
          read the documentation that comes with it. That is why I included
          the Quick Start Guide. Now that you have had time to see the
          basics of TrackIt!, please take time to read the rest of the
          Reference Manual so that you can take full advantage of this
          program.



















          TrackIt! v1.0                                                   3






                           Using TrackIt! - Detailed Guide

          How TrackIt! Works:

          TrackIt! is a new concept in automating telecommunications. It
          could be called a "Tracking System for Telix". For every BBS you
          use TrackIt! with, it will create a "track file". This track file
          is used to store the "tracks" for the BBS. A track is the
          information TrackIt! keeps for different BBS prompts. This
          information consists of the following three "fields": Track
          String, the prompt; Track Reply, the response(s) to the prompt;
          and Maximum Hits, how many times TrackIt! should recognize the
          prompt. Each track file can hold up to sixteen tracks. TrackIt!
          will make up to ninety-nine track files for each BBS, giving you
          over fifteen hundred tracks available for each board name you
          use. Using some advanced techniques, you can have an unlimited
          number of tracks per BBS. Please see "Tips and Tricks" for more
          information on unlimited tracks.

          In order to view, add, edit, or delete tracks, TrackIt! uses a
          built in track editor called "The Edit Box". For a track to be
          considered defined by TrackIt!, it must have a Track String.
          Whenever you are not in the edit box, all defined tracks are
          active. For more information on the edit box, please see "Using
          The Edit Box".

          Anytime there is a match between a defined track and text coming
          in the com port (including what you type), TrackIt! will send the
          appropriate response. This is called a "Hit". Unless Maximum Hits
          is set to zero, after the Maximum Hits for a track is exceeded,
          the track is deactivated (not recognized any more).


          How to Start TrackIt!:

          You may start TrackIt! one of two ways. If you list TRACKIT! as
          the linked script for a BBS in your dialing directory, then it
          will start as soon as you get a carrier. However, if you need to
          edit an existing BBS's track file, or make a new one while
          offline, then you can start TrackIt! using the ALT-G command, and
          entering "TRACKIT!".


















          TrackIt! v1.0                                                   4







          When you start TrackIt! with ALT-G, you will be prompted for the
          board name to edit. To determine the board name, you need to
          understand how TrackIt! does it. TrackIt! uses the board name
          listed in the dialing directory. It takes the first eight
          characters of the name, and then strips any spaces and periods.
          Here are some examples: 

          Dialing Directory Name            How TrackIt! would refer to it
          ----------------------            ------------------------------
          The BBS                           thebbs
          The One B.B.S.                    theone    
          B.B.S. World                      bbsw
          deltaComm BBS                     deltacom
          - Generic BBS -                   -generi

          It's important that you understand how this works. If you create
          a new track file while offline with the intention of using it
          linked to a BBS in the dialing directory, you need to make sure
          the board name you give TrackIt! to create is going to match what
          TrackIt! will look for when run as a linked script. So if you
          want to create a track file for "B.B.S. World" while offline, you
          have to name it "bbsw" for TrackIt! to use that track file when
          calling B.B.S. World.


          Using the Edit Box:

          The edit box lets you view, enter, edit, and delete existing
          tracks in a track file. Once TrackIt! is activated, use the HOME
          key to bring up the edit box. To move the box to a different
          position on the screen, use the four ARROW KEYS. To scroll
          through the defined tracks for the current track file, use the
          PGUP and PGDN keys. To clear the current track, use the DEL key.
          To move to a different field within the box, use the TAB key. To
          exit the edit box, and send the current reply, use the HOME key
          again. To exit the edit box without sending anything, use the END
          key. Using the HOME key to exit will count as a "hit".


          The Track String:

          The prompt you want to respond to is called The Track String.
          This string must match exactly to what the BBS will send. It is
          case sensitive. This string can be a maximum of twenty characters
          long. This string is used to determine if this track is "hit". If
          this string matches text coming across the com port, then it is a
          "hit". Here are some examples:

          Text coming in com port       Defined Track String    Hit or not
          --------------------------    --------------------    ----------
          Enter your name or handle?    name or handle?         IS a hit
          Enter your Name or Handle?    name or handle?         NOT a hit
          Press ENTER to continue:      ENTER                   IS a hit
          Press ENTER to continue:      <ENTER>                 NOT a hit
          Press ENTER to continue:      enter                   NOT a hit



          TrackIt! v1.0                                                   5







          The Reply String:

          What you would like to send when a hit occurs is called The Reply
          String. When you enter the reply string, ENTER will show up as a
          musical note, and ESC will show up as a back arrow. To enter
          multiple replies, you must separate them with a PIPE symbol (|).
          You can enter the pipe manually, or use the INSERT key to
          generate the symbol. When more than one reply for the same track
          string is defined, TrackIt! will use how many times that track
          has been hit in order to determine which reply to send. It
          operates sequentially. The first time the track is hit, the first
          reply is sent, second time, second reply, etc... If the number of
          hits exceeds the number of defined replies, the last reply will
          always be sent. You can define as many replies for each track as
          you can fit into the reply string. This string is set to twenty
          characters max. If this isn't long enough for your needs, then
          see "Tips and Tricks" on how to work around this problem. If
          there is a demand for it, I may make the reply string longer in
          future versions.

          A tilde (~) may be used any where in the reply string for a one
          second delay. Some boards will not work if the information is
          sent too fast.


          Setting Maximum Hits:

          Maximum Hits is the maximum number of times TrackIt! will
          recognize a track before it is deactivated. If this number is set
          to zero, then it will recognize that track until the program is
          ended, or a new track file is loaded. This number is important.
          The more tracks you have active at one time, the slower the
          response will be. Therefore, you want to deactivate tracks as
          soon as you know they will not be needed any more. This will keep
          TrackIt! working at an optimum speed. For instance, generally the
          password prompt a BBS sends will only be sent once, so you would
          want to set Maximum Hits to one for that prompt. After it is hit
          once, the reply string is sent, and the track is deactivated.
          However, with tracks that you have set to use multiple replies,
          make sure that the Maximum Hits is set at least to the number of
          replies you have defined or to zero, else all of the replies will
          not be used. Sometimes you don't know how many times a prompt
          might appear ("[pause]", "press a key..", etc), so in this case,
          using zero as the Maximum Hits would be appropriate.


          Ending TrackIt!:

          You can end TrackIt! at any time by pressing the END key while
          not in the edit box. If you started TrackIt! as a linked script,
          then TrackIt! will automatically end when the carrier is lost.







          TrackIt! v1.0                                                   6







          Testing Tracks Offline:

          A good way to see how TrackIt! works is to play around with it
          offline. Start TrackIt! using the ALT-G command. When TrackIt!
          ask you for the board name, press ENTER. When board name is left
          blank, TrackIt! will use "TESTBBS" as the board name.

          Use the home key and define one or two tracks, setting Maximum
          Hits to zero. Now press the END key. Type in one of the Track
          Strings you defined a minute ago, and the Reply string should be
          sent automatically. Press ENTER and CTRL-J a couple times, then
          type in the other Track String.

          Use this method to get the feel of TrackIt!. Define some more
          tracks, trying out multiple responses, or using different Maximum
          Hits settings. When you are done, use END key to exit TrackIt!










































          TrackIt! v1.0                                                   7






                        Advanced Features - The @ Command Set

          TrackIt! offers a set of commands you can imbed into your tracks.
          These commands all start with the "at" symbol (@). All of the
          commands that are used in reply strings can be used with multiple
          reply sets. The commands are NOT case sensitive. It doesn't
          matter if you type them in capital letters, lower case, or a mix.

          @logon

          This command can be used as the Track String for track number
          ONE. If it's not used with track one, it will not work. When
          used, the track will be considered hit as soon as TrackIt! is
          run, and the Reply String will be sent. When using TrackIt! as a
          linked script, TrackIt! isn't run until you have a carrier. This
          command is useful for systems that require characters to be sent
          as soon as a connection is made, such as CompuServe. On some
          systems, you may want to add a couple tilde's (~) as the first
          characters of the reply string for this to work properly.


          @pass

          This command can be used in the Reply String. It will send what
          ever you have your password set to in the dialing directory for
          the board you are currently calling. If @pass is used by itself,
          a RETURN is automatically sent after the password. If you need to
          put a delay or any other characters after the password, put the
          characters after @PASS and it will send your password and
          anything else you have after the command. This command is useful
          if you change your passwords often.


          @end

          This command can be used in the Reply String. It will exit
          TrackIt!. This command is useful for writing log on tracks that
          get you to the main command prompt.


          @<script> <param>

          This command can be used in the Reply String. The "at" symbol
          followed by a script name will allow you to execute an external
          script from within TrackIt!. Do not include an extension with the
          script name, TrackIt! automatically adds ".slc" to the name. 

          The <param> is optional. If used, it will pass the parameter to
          the called script. This parameter could be a filename or anything
          else you wanted. Here's an example using the param field:

                              @up bbs.rep 

          When the external script ends, TrackIt! will pick up where it
          left off. This command is useful for doing uploads, specialized
          downloads, or anything else you may want to do online.



          TrackIt! v1.0                                                   8







          @link <#>

          This command can be used in the Reply String. This command loads
          in the next Track File. When used, all current tracks are
          deactivated, and a new set is loaded in. TrackIt! names the track
          files with the extension ".!##". The number ranges from one to
          ninety-nine. You always start out using ".!01". 

          When the @link command is executed, TrackIt! will load in the
          track file specified. For example, "@link 20" would load track
          twenty (".!20") into memory. 

          When the @link command is executed without a number specified,
          TrackIt! will increment one to the next track file. For example,
          if you were on track ".!01" and executed "@link", ".!02" would be
          loaded into memory. If executed again, ".!03" would be loaded,
          etc.. If you are on track ".!99" and execute @link without
          specifying a number, then ".!01" would be loaded.


          @clear #

          This command will deactivate the track specified regardless of
          the maximum hits setting for the track. For example, "@clear 3"
          will deactivate track 3 of the current track file.

































          TrackIt! v1.0                                                   9






                       The Configuration File - Basic Settings

          TrackIt!'s configuration file is designed to be easily customized
          to your needs. It's set up as a straight ascii text file. You can
          use any ascii text editor to change the config file, such as
          DOS's "edit".

          The first number in the file should be "1" or "0". This number
          tells TrackIt! if it should automatically update the file with
          the last X and Y coordinates you had The Edit Box. If the number
          is zero, TrackIt! will not update the config file. If the number
          is one, TrackIt! will update the config file.

          The next number in the file is the default X coordinate for The
          Edit Box. It represents the left side of the box. The number
          should be between 0 and 39.

          The next number in the file is the default Y coordinate for The
          Edit Box. It represents the top of the box. The number should be
          between 0 and 11.

          The next number in the file is the background color of The Edit
          Box. This number should be between 0 and 7.

          The next number in the file is the foreground color of The Edit
          Box. This number should be between 0 and 15.

          The next number in the file is the arrow color of The Edit Box.
          This number should be between 0 and 15.

          The next number in the file is the editing background color. This
          number should be between 0 and 7.

          The next number in the file is the editing foreground color. This
          number should be between 0 and 15.


          COLOR CODES:  0 Black                 8 Dark Grey           
                        1 Blue                  9 Light Blue          
                        2 Green                10 Light Green         
                        3 Cyan                 11 Light Cyan          
                        4 Red                  12 Light Red           
                        5 Magenta              13 Light Magenta       
                        6 Brown                14 Yellow              
                        7 Light Grey           15 White               














          TrackIt! v1.0                                                  10






                      The Configuration File - Advanced Settings

          When using high speed modems, Telix will sometimes miss one or
          two characters coming across the com port, and they wont be
          processed through the tracking routines. TrackIt! has a built in
          inactivity timer. This timer is active when nothing is coming in
          over the com port and no keys are being pressed. After X seconds
          elapse, TrackIt! will look at the last twenty characters and re-
          send them through the track processing routines. This process is
          called "re-tracking", and is transparent to the user. After X re-
          tracks, TrackIt! will hang up the modem.

          TrackIt! offers a feature called AutoPrompting. The feature will
          automatically call the Edit Box for you when X seconds elapse
          without any key presses or anything coming from the com port.
          This feature is off by default. I originally added this feature
          to see how good it would work, but I personally didn't like it.
          So instead of taking it out all together, I made it so it can be
          activated via the config file. This option could be useful when
          making several track files for different BBS's. However, if you
          do use the AutoPrompting feature, the re-tracking will be
          disabled.

          The number following the editing foreground color in the config
          file tells TrackIt! if it should use AutoPrompting. One is on,
          zero is off.

          The next number is the delay used to activate the AutoPrompting.
          If AutoPrompting is off, this number must still be present, but
          the value wont matter. If on, the number is in tenths of a
          second. (ie, 10 is 1 second);

          The next number is the delay TrackIt! should use for every tilde
          (~) in a reply string. The default is 10 (one second). The number
          is in tenths of a second.

          The next number is how long TrackIt! should allow inactivity
          before doing a re-track. Again, the number is in tenths of a
          second. The default is 50. (5 seconds) 

          The next number is the maximum number of re-tracks TrackIt!
          should allow before hanging up the modem.


          After you have made all the track files for all the BBS's you
          plan on using TrackIt! with, I would recommend changing the re-
          track delay to twenty. If you do this, you may also want to set
          the maximum re-tracks before hang up a little higher.











          TrackIt! v1.0                                                  11






                                   Tips and Tricks

          Up to this point in the documentation, I have attempted to
          present the information in a way that a novice could understand.
          However, for this section: you will have to be comfortable with
          TrackIt! and understand everything up to this point; and you will
          have to know a little about the basics of the SALT programming
          language. This section is not required to be able to use
          TrackIt!, so if you do not know anything about SALT, and do not
          care to learn, then proceed to the next section.

          The true power behind TrackIt! lies in its flexibility and "open
          architecture" design. You can call TrackIt! from your own scripts
          and have it execute as it does when using it from the dialing
          directory. You can have TrackIt! call your scripts when a certain
          track is hit. You can have TrackIt! load into memory a new set of
          tracks, or stop execution at a certain prompt and return to the
          original script. In this section, I will try to demonstrate some
          of these features.

          Since this is the first release of TrackIt!, I have only included
          two entries for this section. Play around with TrackIt! and see
          what you can come up with, it's my belief that there is no limit
          to what you can automate online using TrackIt!. If you think of
          any other little "power tricks" I can add to this section, then
          let me know. 

































          TrackIt! v1.0                                                  12







          How to get unlimited tracks:

          When TrackIt! goes to read or write the track files, it changes
          to the directory defined by SALT's _script_dir environment
          variable. Using this information, we can have TrackIt! execute a
          script that will change the value of _script_dir. Then have it
          set up to use the @link command. Make sure AutoPrompting is OFF.
          You can have ninety-nine track files per board per directory. The
          tracks are limited only by the number of directories you feel
          like making.

          Example SALT:  CD.slt
                         
                         main()
                         { _script_dir="c:\telix\scripts2";
                         }

          Track File   : c:\telix\scripts\unlim.!01
          Example Track: Track String: command prompt:
                         Reply String: @cd
                         Maximum Hits: 2

          Track File   : c:\telix\scripts2\unlim.!01
          Example Track: Track String: command prompt:
                         Reply String: x|@link
                         Maximum Hits: 2

          Track File   : c:\telix\scripts2\unlim.!02
          Example Track: Track String: command prompt:
                         Reply String: m
                         Maximum Hits: 1

          In the above example when "command prompt" is seen for the first
          time TrackIt! will execute the script "CD". This script will
          change to the new directory and return to TrackIt!. Now TrackIt!
          will sit there until the inactivity timer forces a re-track.
          Since TrackIt! hasn't reset the tracks, this will count as the
          SECOND hit for the track. So this time, @link will be executed.
          @link will cause TrackIt! to reset all the tracks and load
          "c:\telix\scripts2\unlim.!01". Then it will wait, do the re-track
          again, and then execute the new reply string.

          You can repeat this process all you want, but keep in mind that
          every time you do this, you are working out of a new directory.
          You will need to make sure you have any other scripts you will
          call in the directory TrackIt! is working out of when you call
          them.

          *NOTE: You can have an unlimited number of Tracks defined for
          each BBS. However, this does NOT mean that all of them will be
          active at the same time. You can have only sixteen tracks active
          in memory at one time. If you are calling a board with an
          extensive number of prompts, then use the @link command. Make !01
          get you to point A, !02 get you to point B, etc... There should
          never be any reason to need more than sixteen tracks ACTIVE at
          one time. 


          TrackIt! v1.0                                                  13







          Working Around 20 Character Reply String:

          Chances are that you will rarely need a reply string that is
          longer than twenty characters, even when using multiple replies.
          However, in the event that you do need more than twenty
          characters for a reply string, then there is a simple solution to
          this problem.

          The solution is to have the track call an external script to send
          your reply. For example, if you have a reply string that sends
          "main" on the first hit, a long string on the second hit, and
          "off" on the third hit, you could define your reply string like
          this: "main|@A|off". When the track is hit the second time
          TrackIt! will attempt to execute the script named "a.slc". The
          source for the script could be very simple. For example:

                             File: A.slt

                             main()
                             { cputs("This would be the long reply...^M");
                             }

          If the twenty character limit on the reply string is going to be
          a major problem for you, then let me know. If there is a big
          enough demand for it, I may lengthen the reply string in future
          versions.
































          TrackIt! v1.0                                                  14






                                  Companion Scripts

          The most powerful feature of TrackIt! is it's ability to call
          external scripts. Included with your TrackIt! package are some
          companion scripts written by Bruce Thomas. These scripts are an
          excellent example of what can be done with TrackIt!. I encourage
          you as a user to write and distribute your own companion scripts
          for TrackIt!.





                               Uploading & Downloading

          Downloading in TrackIt! can be done two different ways. The
          easiest way is to set the auto-start Zmodem download to ON in
          your Telix configuration menu. The other way is to define a
          track. In the reply string you can have TrackIt! call an external
          script to do the download for you. For example, to call a script
          called DOWN.SLC, your reply string would look like this, "@down".

          To upload in TrackIt!, you have to call an external script.
          Define a track to look for the upload prompt, then use the
          @<script> <param> command in the reply string.

          The companion scripts written by Bruce Thomas include both upload
          and download scripts, and the source code. Scripts are included
          that use internal or external protocols.






























          TrackIt! v1.0                                                  15






                                 Registering TrackIt!

          The most important thing you as a user can do is register
          TrackIt!. You are granted a fourteen day license, as an
          evaluation period, to use TrackIt!. After the evaluation period,
          you are expected to register TrackIt!, or discontinue use. If you
          use TrackIt! past the evaluation period without registering, then
          you are violating U.S. and International Copyright Law.

          Registration for TrackIt! is only $10. In return for your
          registration you will be mailed a registration key to remove all
          the registration reminders from the program. You will also have
          an account made for you on TrackIt's support board, Salt Water
          BBS.

          I have a lot of ideas of things to add to future versions of
          TrackIt!. However, I will only support TrackIt! for as long as
          the users are supporting TrackIt!. Therefore, it's to your best
          interest as a user to not only register TrackIt!, but once
          registered, to not give out your registration key.


                                    -- Discount --

          If you already have a registered version of Record or SLearn, but
          you would rather have a registered version of TrackIt!, I will
          offer you a 25% discount. Enclose the ORIGINAL cancelled check
          you used to register Record or SLearn with your TrackIt!
          registration, and get $2.50 off TrackIt!. I'm sorry, but I cannot
          accept photocopies or the registration letter as a substitute.



                                TrackIt!'s Support BBS

          TrackIt! does have a support board. Unregistered users only have
          access to download the latest version of TrackIt!. Registered
          users will have access to the message base, and the TrackIt!
          companion scripts file area. I may be releasing a couple NON-
          Shareware companion scripts to go along with TrackIt!. If I do,
          these scripts will be available to registered users only.

          Support board for TrackIt!:  Salt Water BBS
                                       (804) 989-5113
                                       Sysop: Bruce Thomas

          To get the latest version of TrackIt! from the support board, use
          the following information to log onto the BBS.

                          First Name: Long
                           Last Name: Distance
                            Password: trackit!

          When you get to the main menu, type GRAB and the latest version
          will be sent via ZMODEM. I will post information concerning new
          versions on the Telix conference on Fidonet.



          TrackIt! v1.0                                                  16






                              How to Contact the Author

          I strongly encourage and welcome user feedback. Without feedback,
          I don't know what users would like to see added or changed. For
          example, if this documentation isn't clear and concise enough for
          you, then tell me how I can improve it. If the program is lacking
          in any way, then let me know. Please remember when pointing out
          any problems with the program, try to be as detailed as you can.
          Do not say something general like "it just doesn't work right." 

          If you have any comments or suggestions, and a little extra
          pocket change, then I would appreciate a picture postcard of
          where you live with the comments or suggestions on it.


          U.S. Mailing Address: Michael S. Hogg
                                PO Box 8055
                                Hampton, Va. 23666


          Online contact points: Fidonet.......... Telix Conference
                                 Fidonet Mail..... Michael Hogg 1:271/160
                                 Salt Water BBS... Use comment to sysop
                                 MajorNet......... Freebird@ORN



































          TrackIt! v1.0                                                  17






                                   Acknowledgements

          Before TrackIt! was written, I was writing a different track
          script for each BBS that I called. Bruce Thomas suggested that I
          write a track learner that would generate the same results
          without having to write and compile a script for each BBS.

          I would like to thank Bruce Thomas for suggesting this program be
          written. Also, for constantly nagging me to work on it. He has
          contributed many ideas and suggestions for TrackIt!, done the
          Beta testing, contributed a set of companion scripts for use with
          TrackIt!, and is currently running the support BBS for TrackIt!.

          I would also like to thank the makers of Telix for providing a
          quality terminal program with a powerful script language. I have
          seen no other terminal program offer the power and flexibility of
          Telix's SALT language.










































          TrackIt! v1.0                                                  18






                           TrackIt! Registration Form
                                 for Version 1.0

        Registrations are good for this version, and all future versions.

                                            Number of registrations  _____
    Pricing:

    $10 Per Registration........................................... $_____
    
    [ ] I'm enclosing the original cancelled check I used to
        register Record or SLearn to get $2.50 off TrackIt!       - $_____

    [ ] I admit voting for Bill Clinton. Due to the amount of
        money my vote cost you this past tax season, I'm enclosing
        an extra $5 as minor compensation.                        + $_____

    [ ] I have money to burn, and $10 means nothing to me, so I am
        enclosing a little extra.                                 + $_____


                                                              TOTAL $_____

    Make check or money order payable to Michael S. Hogg in U.S. funds.

    Please write for group discounts, government, corporate, or network
    license pricing.


    Name    ______________________________________________________________

    Company ______________________________________________________________

    Address ______________________________________________________________

            ______________________________________________________________

    City    ________________________________State _______ Zip ____________

    Where did you get TrackIt!? __________________________________________

       Mail to:

                 Michael S. Hogg
                 PO Box 8055
                 Hampton, Va 23666


    Comments, suggestions, constructive criticism:


    ______________________________________________________________________

    ______________________________________________________________________

    ______________________________________________________________________

    ______________________________________________________________________
