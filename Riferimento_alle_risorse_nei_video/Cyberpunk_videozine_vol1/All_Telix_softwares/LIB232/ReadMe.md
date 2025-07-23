






















                            The  L i b e r a t o r (TM)

                        PCBoard Automation System for Telix

                                   Version 2.32















                  Copyright (C) 1989, 1990 Liberation Enterprises

                               ALL RIGHTS RESERVED.




     COPYRIGHT NOTICE

      This program is not in the public domain.  All files that accompany The
      Liberator including this documentation are Copyright 1989, 1990
      Liberation Enterprises.  The Liberator is a Trademark of Liberation
      Enterprises.

     DISCLAIMER

      The Liberator and its documentation is distributed and sold AS IS,
      without warranty of any kind as to performance of merchantability,
      fitness for a particular purpose, or any other warranties, either
      express or implied.  Neither Liberation Enterprises nor its dealers or
      distributors shall be liable to the user/purchaser or any other person
      or entity with respect to any liability, loss, or damage caused or
      alleged to be caused directly or indirectly by the software or its
      documentation.

     LICENSE

      You are licensed to use this evaluation copy of The Liberator at no
      charge for a limited evaluation period.  Once you are satisfied that
      the program is useful to you, after a reasonable evaluation period (30
      days), you must register your copy.  To do so, complete the registra-
      tion form and mail it along with the fee as outlined on the form.  Re-
      distribution of The Liberator is encouraged, but must comply with the
      following:

      1. The Liberator may not be sold commercially or distributed with any
         other programs without written permission from Liberation Enter-
         prises.

      2. No charges other than reasonable overhead and/or copying fees may be
         levied for distribution of The Liberator ($10 or less).

      3. The program files and documentation must be distributed in their
         entirety and must remain absolutely unmodified.  Please do not
         distribute the program in an incomplete state.
     ----

      PCBoard is a registered trademark of Clark Development Company, Inc.  

      ProLogon, ProBank, and ProDoor are Copyright by Samuel H. Smith.

      Qmail and Deluxe are Copyright by Mark Herring of Sparkware.  Post
      Office Box 38216 Germantown, TN 38183-0216.

      Telix and SALT are trademarks of and Copyright by Exis Inc.  Post
      Office Box 130, West Hill, Ont., Canada  M1E 4R4.  Telix Support BBS
      (modem only): (416) 439-8293.









                                         2




     User-Supported Software: Try BEFORE you buy!

     User-supported software, such as The Liberator, is software that you try
     on your own computer for a limited 'evaluation period'.  During this
     period, you decide whether the program is useful to you, and make up
     your mind whether you wish to continue using it and pay for it, or stop
     using it and not pay.  Of course, another choice is not to pay and
     continue using the program anyway.

     Unfortunately, from previous experience, and from what I've heard from
     many developers, the third choice is the one a great majority of people
     make -- even for useful, quality products.  However, ulterior motives
     aside, it is definitely the wrong choice to make.  Especially from a
     user point of view.

     The reason is this.  There are many companies developing software for
     your computer.  Some of this software will be marketed in the tradition-
     al way, in which the developer pays thousands, or more likely millions
     of dollars for marketing, advertising, packaging, and distribution. 
     Initially these expenses may be paid from the developer's pocket: but it
     is inevitable that the extra expense be passed on to you in the price of
     the software.  Thus you end up not only paying for the software, but
     also for expensive ads in computer magazines, and flashy packaging which
     will probably end up in the garbage.  Worse than this, you may install
     the software and find that it does not do what the ad said it would do,
     or that they forgot to tell you about incompatibilies, etc.  The end-
     result?  You paid more, filled the pockets of advertisers, and got less
     -- or even something that may sit on your shelf collecting dust (we all
     have a few of these programs).

     On the other hand, some software is released under the premise that
     people don't need flashy advertisements or packaging to determine
     whether they are interested in a product.  The best advertising for a
     product should be the product itself, and this is the concept User-
     Supported Software employs.  There is no chance of misleading you into
     making a purchase with dazzling packaging or advertisements since all
     this is stripped away, and only the product remains.  However, in order
     to let you try the product, it must be made available... and this means
     that you already have the product before paying for it.

     Is this an invitation to steal the software?  Some people look at it
     that way.  But if you use common sense, you will realize that if you
     don't pay, eventually developers will be forced to add registration
     gimmicks (a new feature in this release of The Liberator), which almost
     always prevent you from evaluating the full product, though I did not
     choose that technique.  If gimmicks fail, there is no choice but to
     ensure customers pay ahead of time... leading to all the extra expense
     and problems of traditional distribution.  If traditional marketing
     isn't practical, the developer may be forced to shelve the product,
     since not many developers are willing to work hours on end, forever, for
     nothing.  If this happens, everyone loses.

     Thus, it has been left it up to you to decide.  Don't look upon
     registration as doing some sort of good deed... Register (the products
     you use) to do *yourself* a favour and keep the 'Try BEFORE you buy'
     concept strong!



                                         3



     The  L i b e r a t o r  v2.32                    Registration Form C-08.
     ------------------------------------------------------------------------
     Please print clearly.                [Office use] R#        D/R
     ------------------------------------------------------------------------

        Name: ___________________________________________________________

     Company: ___________________________________________________________

     Address: ___________________________________________________________

        City: _________________________   Prov./State: __________________

         ZIP: _________________________         Phone: (_____)___________

     Country: ___________________________________________________________


                 Quantity      Price per registration
                 ------------------------------------
                  1 - 10       $24.95
                 11 - 20        19.95
                 21 - 50        14.95
                   51+           9.95

     # of Copies _______  x  $________ per reg. = Sub Total $____________

                   Ont. residents, add Provincial Sales Tax  ____________

                   Outside North America add $3.00 shipping +____________

                                                      TOTAL $____________

     One registered copy is sent (one 360K disk), plus a license to install
     the # of copies registered.  Orders are accepted in Canadian or U.S.
     currency.  Please mail your check, or M.O. to [NOTE: Postage to Canada
     from the U.S. was 5 cents extra at release date.]:

             Liberation Enterprises, 3091 Eglinton Ave E., Suite 602,
                         Scarboro, Ont., CANADA  M1J 2G1.

     Where did you obtain The Liberator?

     ____________________________________________________________________

     What do you use The Liberator for mainly (most important feature)?

     ____________________________________________________________________

     ____________________________________________________________________

     What improvements or new features would you like to see added to the
     program in the future?  (Use back of page if necessary.)

     ____________________________________________________________________

     ____________________________________________________________________





                                 TABLE OF CONTENTS


     1.  INTRODUCTION  . . . . . . . . . . . . . . . . . . . . . . . . .    1
         1.1  Liberator v2.32 Features . . . . . . . . . . . . . . . . .    1
         1.2  How To Use The Tutorial  . . . . . . . . . . . . . . . . .    3

     2.  GETTING STARTED . . . . . . . . . . . . . . . . . . . . . . . .    4
         2.1  Liberator First Startup  . . . . . . . . . . . . . . . . .    4
         2.2  Registration Reminder Screen . . . . . . . . . . . . . . .    5
         2.3  BBS Configuration Files  . . . . . . . . . . . . . . . . .    5
         2.4  Editing Screen Entries . . . . . . . . . . . . . . . . . .    6
         2.5  Command Files  . . . . . . . . . . . . . . . . . . . . . .    7
         2.6  The Command File Manager . . . . . . . . . . . . . . . . .    8
         2.7  Print a BBS Configuration Form . . . . . . . . . . . . . .    8
         2.8  Dialing Directory Setup  . . . . . . . . . . . . . . . . .    8
         2.9  What are Protocols?  . . . . . . . . . . . . . . . . . . .    9
         2.10 What are Batch Protocols?  . . . . . . . . . . . . . . . .    9
         2.11 Enter Your Password  . . . . . . . . . . . . . . . . . . .   10
         2.12 Dial the BBS . . . . . . . . . . . . . . . . . . . . . . .   10

     3.  PCBOARD SETUP . . . . . . . . . . . . . . . . . . . . . . . . .   12
         3.1  Checking For Batch Transfer Support  . . . . . . . . . . .   12
         3.2  Checking the PCBoard Version Number  . . . . . . . . . . .   12
         3.3  Setting Up Protocols . . . . . . . . . . . . . . . . . . .   13
         3.4  Searching For Liberator Configurations . . . . . . . . . .   13
         3.5  Joining Conferences  . . . . . . . . . . . . . . . . . . .   14
         3.6  Turning Expert Mode On . . . . . . . . . . . . . . . . . .   14
         3.7  Viewing the available DOORS  . . . . . . . . . . . . . . .   14
         3.8  ProDoor Setup  . . . . . . . . . . . . . . . . . . . . . .   15
         3.9  Mail Door Setup  . . . . . . . . . . . . . . . . . . . . .   15

     4.  MAIL READER SETUP . . . . . . . . . . . . . . . . . . . . . . .   18
         4.1  Choosing a Reader  . . . . . . . . . . . . . . . . . . . .   18
         4.2  Configuring the Reader . . . . . . . . . . . . . . . . . .   18

     5.  LIBERATOR CONFIGURATION FILES . . . . . . . . . . . . . . . . .   19
         5.1  Installing A Pre-defined Configuration . . . . . . . . . .   19
         5.2  Configuration File Setup . . . . . . . . . . . . . . . . .   19
         5.3  PCBoard Setup Screen   . . . . . . . . . . . . . . . . . .   19
         5.4  PCBoard Prompts Screen . . . . . . . . . . . . . . . . . .   24
         5.5  Pro Utilities Screen . . . . . . . . . . . . . . . . . . .   24
         5.6  Mail Door Setup Screen . . . . . . . . . . . . . . . . . .   25
         5.7  Saving a Configuration File  . . . . . . . . . . . . . . .   27
         5.8  Cloning or Editing Configuration Files . . . . . . . . . .   27

     6.  LIBERATOR COMMAND FILES . . . . . . . . . . . . . . . . . . . .   28
         6.1  Running Command Files  . . . . . . . . . . . . . . . . . .   31
         6.2  Command File Abort Codes . . . . . . . . . . . . . . . . .   31
         6.3  Pausing Or Manually Aborting Command Files . . . . . . . .   31
         6.4  Creating New Command Files . . . . . . . . . . . . . . . .   32
         6.5  Editing Existing Command Files . . . . . . . . . . . . . .   32
         6.6  Deleting Command/Configuration Files . . . . . . . . . . .   32
         6.7  Renaming Command/Configuration Files . . . . . . . . . . .   32

     7.  LIBERATOR CONFIGURATION (Tools 'Configure' option)  . . . . . .   33

     8.  SETTING UP CUSTOM COMMANDS  . . . . . . . . . . . . . . . . . .   34
         8.1  Defining a PCBoard or ProDoor Command  . . . . . . . . . .   34
         8.2  Sending More Than One Command  . . . . . . . . . . . . . .   35




         8.3  Automatically Handled Prompts  . . . . . . . . . . . . . .   35
         8.4  Some Useful Commands . . . . . . . . . . . . . . . . . . .   35
         8.5  Running Other Telix Scripts  . . . . . . . . . . . . . . .   37
         8.6  Passing Parameters To Scripts  . . . . . . . . . . . . . .   37
         8.7  Replaceable Parameters?  . . . . . . . . . . . . . . . . .   38
         8.8  External Script Return Values - IMPORTANT  . . . . . . . .   38

     9.  FILE TRANSFERS  . . . . . . . . . . . . . . . . . . . . . . . .   39
         9.1  Sending Files (Uploading) To PCBoard . . . . . . . . . . .   39
         9.2  Comments On File Lists (//)  . . . . . . . . . . . . . . .   39
         9.3  Optional File List Items (Switches)  . . . . . . . . . . .   40
         9.4  Specifying Upload or Download Passwords (/u /d)  . . . . .   40
         9.5  Joining Specific Conferences (/#nnn) . . . . . . . . . . .   40
         9.6  Making File List Items Permanent (/P)  . . . . . . . . . .   41
         9.7  Using Switches On Separate Lines . . . . . . . . . . . . .   41
         9.8  Specifying A Drive/Directory . . . . . . . . . . . . . . .   42
         9.9  Upload Descriptions  . . . . . . . . . . . . . . . . . . .   42
         9.10 Backup Lists . . . . . . . . . . . . . . . . . . . . . . .   43
         9.11 Demonstration Upload List  . . . . . . . . . . . . . . . .   43
         9.12 Telix Batch Upload Limitation  . . . . . . . . . . . . . .   43
         9.13 Receiving Files (Downloading) From PCBoard . . . . . . . .   44
         9.14 Using LIST.COM to create Download Lists  . . . . . . . . .   44

     10. USING THE MASTER  . . . . . . . . . . . . . . . . . . . . . . .   45
         10.1  Creating a Master . . . . . . . . . . . . . . . . . . . .   45
         10.2  Using the Add Option  . . . . . . . . . . . . . . . . . .   45
         10.3  Using the Remove Option . . . . . . . . . . . . . . . . .   46
         10.4  Running the Master  . . . . . . . . . . . . . . . . . . .   46
         10.5  Using EXIT and REPEAT to Create Multiple Masters  . . . .   46
         10.6  The Master Queue  . . . . . . . . . . . . . . . . . . . .   47
         10.7  Using the Master To Link Command Files  . . . . . . . . .   49
         10.8  Command File Differences Under RunMaster  . . . . . . . .   49

     11. CONFIGURING LIBERATOR PROMPTS . . . . . . . . . . . . . . . . .   51

     12. ABORT CODES/REMEDIES  . . . . . . . . . . . . . . . . . . . . .   53




















                                         6




     The  L i b e r a t o r  v2.32                      Introduction - Page 1
     
     

                                 1.  INTRODUCTION


     Welcome, and thank you for your interest in The Liberator PCBoard
     Automation System for Telix!  The Liberator will carry out entire
     PCBoard sessions for you, totally unattended, right from dialing to 
     logoff.  All the major jobs you would normally do manually can be
     carried out by The Liberator, completely unattended, while you are doing
     something more productive and exciting.  You can even leave The
     Liberator on its own over a period of weeks, carrying out up to 100
     separate PCBoard sessions, at pre-specified times each day!

     1.1  Liberator v2.32 Features

     > Full automation for PCBoard, Qmail v2, v3, and v4 doors, MarkMail
       doors, MegaMail/NetMail/PCRelay doors, ProDoor, ProLogon and ProBank! 
       Full ProLogon support is built in, and since The Liberator can operate
       in ProDoor it can also handle ProLogon boards where the S)ystem
       command has been disabled, preventing use of PCBoard itself.

     > Designed for easy setup -- no knowledge of Telix SALT required.  Even
       a beginner can set up The Liberator with little difficulty.  Those not
       familiar with PCBoard and its doors can make especially good use of
       The Liberator and will be taken through all the necessary steps for
       setup.  Even PCBoard experts will be impressed with the number of
       tasks The Liberator knows how to do, its flexibility, and the speed
       with which it carries tasks out!

     > Completely unattended operation.  The Liberator is larger than other
       scripts mainly because it was designed to handle just about any error
       that might occur.  Dozens of individual prompts and messages are
       recognized, to allow the program to properly operate the BBS under
       just about any circumstances.

     > Seven PCBoard Mail Door types are directly supported in The Liberator,
       and ProDoor ZIPM or regular PCBoard message downloads can be carried
       out using The Liberator's Custom Commands (outlined below).  Carry out
       message uploads, personal message downloads, repeat downloading,
       regular message downloads, capture a SESSION.TXT file for use in your
       offline reader -- all supported in Qmail v2 doors, Qmail v3 doors, and
       MarkMail doors.  Pointer resets file uploads and current-session-only
       scanning of ALL conferences can also be performed if using a Qmail v3
       or v4 door.  Automatic packet maintenance is performed for all Mail
       Door types.

     > Transfer files to/from BBS's in any of *six* ways!  Plain old PCBoard
       file uploads and downloads are supported, for the very basic BBS. 
       However, for maximum speed and efficiency, PCBoard batch uploads and
       downloads (UB/DB) are supported, if available on your BBS, and ProDoor
       batch uploads and downloads are also supported if a ProDoor is
       available!  The Liberator will transfer as many files as you have time
       for, and automatically remove files from your list when successfully
       transferred.  If you don't have time to transfer a given file, it




     The  L i b e r a t o r  v2.32                      Introduction - Page 2
     
     

       remains on your list for the next session.  Join a different
       conference for each file, if necessary.  Specify multiple upload
       and/or download passwords, if necessary.  Multiple-line upload
       descriptions are also supported in ProDoor, and on PCBoard if avail-
       able.

     > Use the MakeList command to automatically create a Download List from
       the results of a user-defined command.  Set up any PCBoard or ProDoor
       commands to send to the BBS, such as F)ile Directories, L)ocate, N)ew
       files, or Z)ippy Scan commands, and MakeList will capture all files
       found and place them on your Download List to be used in the same
       session!  Send multiple commands in multiple conferences if desired,
       and the correct conference will be joined before downloading the file. 
       You can even manually edit the list, to remove specific files before
       downloading.

     > Carry out ProBank time deposits and withdrawals if a ProBank door is
       available on the BBS.  Set The Liberator to take some time out of the
       ProBank when you need some extra time for a job.  Have it deposit all
       your time at the end of a session, or configure how much time to put
       in.  The Liberator will also check your available online time and
       adjust your deposit to leave a specific amount of online time, if
       desired.

     > If the above isn't enough, you can also set up multiple customized
       commands to send to PCBoard and/or ProDoor, for the tasks that aren't
       directly supported.  Use Custom Commands for ProDoor ZIPM mail
       transfers, to capture mail from PCBoards without Mail Doors or a
       ProDoor, or any other PCBoard/ProDoor tasks.  For more complicated
       jobs you can even incorporate other SALT scripts into any session. 
       Some useful example scripts are included, along with an easy-to-
       understand SALT tutorial!

     > Interactive operation allows you to select jobs on the fly.  Customize
       the level of interaction, and even carry out parts of the session
       manually, if desired.  All of the jobs listed above can be turned
       on/off, or set for interactive mode for any given session.

     > Any special logon or logoff can also be handled, and actually fully
       incorporated into any given session.  Working iNet logon/logoff
       scripts are included, but just about any type of logon or logoff can
       be incorporated into any Liberator session with just a few keystrokes.

     > Set up a Master list of up to 100 sessions, using any combination of
       the jobs outlined above in each session.  Dialing delay times can be
       set and saved, and the entire Master list can be made to either repeat
       itself, or even exit to DOS when complete.  When a connection is made,
       the list is checked for other jobs to execute on the same BBS.  If any
       are found, they will all be executed without disconnecting!  A dialing
       queue is also used to give you the best chance of getting onto busy
       PCBoards.  If a connection is not established within a user-defined
       number of tries, the next job is started, and the current job is
       marked to be tried again between all successful jobs.




     The  L i b e r a t o r  v2.32                      Introduction - Page 3
     
     

     > Extra protection is built in for a situation when The Liberator can't
       locate its position on the BBS.  The program actually reads the screen
       just as you would, to determine where it is from any of eight key
       positions on PCBoard and in the various doors.  Any job listed above
       can be started from any of these eight locations.  If the current BBS
       prompt is not recognized, ENTER is sent and it looks again for a
       recognizable prompt, up to three times.  If a key prompt is not found
       after three tries, the program notifies you that a recognizable prompt
       could not be found and disconnects.  No more guessing as to what went
       wrong with a session.

     > Logons are also equipped with a similar type of prompt recognition/-
       recovery routine, but encompass all of the 16 logon prompts that are
       tracked, and not just the eight key prompts.  In the logon, if none of
       the 16 prompts are recognized within 10 seconds of establishing a
       connection, ENTER will be sent.  This is also repeated in another 15
       seconds, up to a total of three times if necessary.  This feature is
       essential for connecting to PCBoards which need ENTER to be hit before
       they start the logon.

     > And what feature listing would be complete without one of these: "Many
       more features!"  There truly are dozens more, but I hope that was
       enough to get you interested enough to carry on with the tutorial, to
       see the many other features available.

     1.2  How To Use The Tutorial

      This document is introductory for the most part, mainly for first time
      Liberator users or even first time BBS or PCBoard users.  It will take
      you through the steps necessary to set up Telix, PCBoard, a Mail Door,
      a Mail Reader, ProDoor and The Liberator itself, while you follow along
      and actually get something done!  It was not designed to waste your
      time, but to *save* you time since you participate and actually get
      useful things done as we go along instead of possibly fumbling around
      trying to figure it all out for yourself.

      The tutor is organized into lessons, and it is recommended that you at
      least browse each lesson section to get some idea what you'll miss if
      you skip it.  Even though you may be a Telix and/or PCBoard expert, you
      may still want to quickly follow along with these setup sections, since
      some of the information is specifically for setup of The Liberator.  Of
      course, the more you know, the more you will be able to skip and the
      faster the setup will be.

      Note that due to popular demand, a new document was provided in this
      release of The Liberator, called MAIL.DOC (see your distribution
      diskette or archive).  It is designed for the semi-experienced
      Telix/PCBoard user, and only covers the steps necessary to automate
      Mail Door runs.  If you want to get set up for automated mail runs
      quickly, and are already familiar with Mail Door operation, please
      refer to this document now, and refer back here later if you run into
      trouble.




     The  L i b e r a t o r  v2.32                   Getting Started - Page 4
     
     

                                 2. GETTING STARTED


      If you haven't installed The Liberator yet, locate the program files
      (INSTALL.EXE, *.SLC, .001, etc.), switch to the directory where they
      are located (e.g. CD \TEMP, or A:), then enter GO to run the installa-
      tion program.  The installation program will ask you what it needs to
      know, then install and start The Liberator if all goes well.

      If you followed the installation program's instructions properly, you
      should be looking at a prompt telling you to start reading the tutor
      (congratulations... you actually did!) and to press any key.  Since you
      are now exactly where you are supposed to be, please go ahead an press
      a key to start The Liberator.  [Use the LIBERATE command from DOS or
      <Alt-G>LIBERATE from Telix if not starting from the installation
      program.  Then proceed to section 2.3.]

      GO.BAT will now display a few lines showing you how to start The
      Liberator yourself.  Once you press a key, GO.BAT will simply enter the
      command 'LIBERATE' for you.  In the future, enter this command yourself
      to start The Liberator.

      If Telix starts properly but cannot find The Liberator, then you
      possibly gave the wrong 'Script directory' to the installation program,
      or don't have it defined properly in Telix.  If this happens, please
      see the file TELIX.DOC that accompanied The Liberator, to define a
      Script directory.  Once defined and saved, manually start the program
      by typing <Alt-G> (hold down the <Alt> key and tap the 'G' key) then
      enter LIBERATE.

     2.1  Liberator First Startup

      On the first startup, The Liberator automatically checks to ensure that
      you have a Script Directory defined, then checks itself to see that all
      its files are present in this directory, and that the size of each file
      is what it should be.  If it aborts due to no defined Script Directory,
      please see the file TELIX.DOC that accompanied The Liberator.  If it
      aborts due to a missing file, or incorrect file size, check the
      original disk/archive for the missing file, and re-install the program
      if necessary.

      Your modem will also be checked to ensure that the 'carrier detect' is
      not being forced on.  If you are notified that it is, please refer to
      TELIX.DOC (the one that accompanied The Liberator) for instructions on
      how to fix it, then manually restart the program using <Alt-G>LIBERATE.

      Next, if existing Command or Configuration Files from previous versions
      are found, the program will convert them for you automatically. 
      [Automation is the name of the game with The Liberator, and I hope you
      like the word 'automatic', since you'll hear it, and experience it a
      lot in this tutor...]




     The  L i b e r a t o r  v2.32                   Getting Started - Page 5
     
     

      After any conversion, you are then taken (automatically) to the main
      Configuration screen, but this screen is mainly displayed for users who
      are updating from a previous version of The Liberator and know what the
      options mean.  New users may also realize what some options are for,
      but for now hit <Esc>.  You can come back to this screen later if you
      want by referring to the "Liberator Configuration" section below for
      instructions.

     2.2  Registration Reminder Screen

      The next thing you will see is the opening title screen, reminding you
      that you are using an unregistered evaluation copy of the Liberator. 
      The screen displays the number of times the program has been used, but
      please note that The Liberator keeps track of this number for your
      interest only.  The program does not expire at a certain number, as it
      is felt that a simple reminder is all that is necessary.  Many people
      actually forget that they are only using an evaluation copy, and
      instead of crippling the program, I feel this screen is an adequate
      reminder.  If you decide to register, you will receive a 'key' file
      which causes the program to bypass this reminder.  The usual Telix
      screen colors are also used if a key file is present, giving the
      program a very integrated look.  See the registration form near the
      beginning of this document for more information on registering.

     2.3  BBS Configuration Files

      From the title screen, on the very first startup, you are automatically
      taken to create new Command and Configuration Files, and should now be
      looking at screen 1 of your first BBS Configuration.  If this is not
      your first startup, please select 'Create' from the main menu, by
      entering a 'C'.

      If you are prompted for a Configuration to use, hit the <Enter> key to
      Create a new one.  BBS Configurations (Configuration Files) are used to
      hold information regarding one specific PCBoard BBS.  Each PCBoard BBS
      that you intend to use The Liberator with will require at least one BBS
      Configuration.  As you can see, it holds information about you such as
      your name, and lots of information about the BBS such as doors,
      protocols, etc.  There are four Configuration screens altogether,
      (screen 4 is only available if a Mail Door is defined), and we'll cover
      all the configuration entries later.  If none of it makes any sense to
      you now, it will by the time we go to set up a full Configuration
      later.  For now, we'll just create the simplest one possible.

      Each item on the screen can be changed by selecting the number
      displayed in the left column.  Note that the numeric keypad sends
      different key codes, and is not presently supported.  The numbers on
      the top row of your keyboard must be used to enter digits.  Type a '1'
      now, and hit <Enter>.




     The  L i b e r a t o r  v2.32                   Getting Started - Page 6
     
     

     2.4  Editing Screen Entries

      When an entry is selected, it will be displayed in reverse video, right
      to the maximum limit of the item selected.  To change the contents,
      simply type over existing characters, or use any of the following keys
      for editing:

      <Ctrl-End>    Hold down the <Ctrl> key and tap the <End> key to remove
                    all characters from the cursor position to the end of the
                    entry.  This can be used to clear an entry, or remove a
                    number of characters quickly.
      <Ins>         Toggles insert/typeover mode.  Each item starts in
                    typeover mode when selected.  Press <Ins> once to change
                    to insert mode (characters are inserted at the cursor
                    position until the entry is filled). Press <Ins> once
                    more to change back to typeover mode.
      <Home>        Moves the cursor to the first character of the item.
      <End>         Moves the cursor to the position following the last
                    character of the item.
      <Left arrow>  Moves the cursor one position to the left.
      <Right arrow> Moves the cursor one position to the right.

      <Alt-F>       Hold down the <Alt> key and tap 'F' at any time (even
                    when editing an entry) to call up the Telix DOS functions
                    menu, which allows various DOS tasks to be carried out.
      <Alt-J>       You may also enter <Alt-J> (Jump to DOS) at any point in
                    The Liberator to temporarily exit to DOS.  Type EXIT at
                    the DOS prompt when you are ready to return to The
                    Liberator, and everything will be just as it was.

      To accept an item as displayed, hit the <Enter> key.  To abort any
      changes and return the item to its previous value, hit the <Esc> key.

      Now that you know how to change the entry, 'Name used on PCBoard' is
      exactly as it appears, and the name entered here will be sent to the
      BBS in the logon sequence.  Think of a local PCBoard, and enter the
      name you normally enter in the logon (if you haven't called any
      PCBoards yet, enter your own name).  Before you hit <Enter>, I would
      also like to demonstrate two new features in The Liberator v2.3:

      Hit <Alt-F> now and you will see the Telix DOS functions menu pop up,
      just as in Telix.  This menu can be called up at any time in The
      Liberator to allow common DOS tasks to be carried out.  You might use
      it to browse a text file such as this document, in the middle of
      editing an entry, or just when something pops into your mind that has
      to be taken care of right away (hit <Esc> to exit the menu).  As well,
      <Alt-J> will allow you to temporarily jump (shell) to DOS to carry out
      some task, or even run another program.  Once the DOS task is carried
      out, type EXIT at the DOS prompt and you will return exactly where you
      were when you hit <Alt-J>.  Hit <Enter> now, to enter your name.

      Item 2 'Telix Directory Numbers to Dial' is normally where you place
      actual dialing directory numbers, but you can also leave it blank to




     The  L i b e r a t o r  v2.32                   Getting Started - Page 7
     
     

      select the entries manually.  Leave it blank for this Configuration,
      and we'll select the BBS from the directory later.

      Believe it or not, this Configuration may now be usable simply after
      entering your name, and we'll test it out in a second.  Note beside the
      cursor at the bottom of the screen the reminder 'Enter = Save', and
      since we're finished for now, hit <Enter> to do just that.  A box will
      pop up prompting you for a name to save the file under.  Just call it
      PCBOARD, since it isn't set up for any specific BBS.  The information
      will then be saved in a file called PCBOARD.CFG, which will be created
      in your Script directory.  If you use the main menu 'Tools' option,
      explained below, you may have The Liberator save these Configurations
      in another directory if desired.

     2.5  Command Files

      The thing about the Configuration Files though, is that they don't
      actually specify what you want done on a BBS... they simply hold
      configuration information which gives The Liberator information about
      the BBS.  To define the actual jobs to carry out, we must set up a
      'Command File', and you should be looking at the Command File Editor
      now, since you are automatically taken there after creating a Con-
      figuration.

      Note that the name PCBOARD has been placed in the 'Configuration File'
      item for you.  If desired, many Command Files, each doing different
      tasks, can be set up to use the PCBOARD Configuration we just saved.

      'Capture File' is the drive, path, and filename used to capture the
      session.  The default name given is made up by extracting the drive/-
      directory from your current Telix capture file, then adding the name of
      the BBS Configuration and the extension .CAP.  You may change it to any
      other name by selecting/editing the item, if desired.

      Some items will display <N/A> (not applicable), since these items
      require doors #'s to be defined in the Configuration before they are
      usable, and we did not define any doors in PCBOARD.CFG.
      
      Skipping to the last item on the screen, 'Disconnect' controls whether
      to log off when the defined jobs complete, or to stay connected (or
      even to disconnect, then exit to DOS).  In this case, since we don't
      have any jobs defined, we will change Disconnect to 'No', which will
      cause the The Liberator only to open the capture file, logon, then
      leave you at the main board prompt.  Sort of an enhanced PCBOARD.SLT. 
      Select 'Disconnect' (14) and enter 'n' for No disconnect.

      The other Command File items are discussed later.  For now, we need
      some information from a PCBoard itself, so please hit <Enter> (Enter =
      Save), and enter the name PCBLOGON to save the file.  The file will be
      created in your Script directory under the name PCBLOGON.CMD.  Command
      Files may also be created in another directory using the Tools option,
      explained later.




     The  L i b e r a t o r  v2.32                   Getting Started - Page 8
     
     

     2.6  The Command File Manager

      You should then be taken to the main menu, or 'Command File Manager'. 
      You will see that entry 0 holds the MASTER, and you should also see the
      name PCBLOGON in one of the other entries, which is the Command File we
      just created.  There should also be a few others filled in, as a couple
      of Command Files are included with The Liberator.  These are mainly for
      demonstration of the interactive features of Command Files.

      The MASTER refers to a special file (maintained with Add/Remove) that
      is used to run multiple sessions on one or more PCBoards, one after the
      other without intervention from you.  The word MASTER is displayed in
      entry 0 whether you have created this Master list or not, but disregard
      it for now.  When you're ready to set up a Master to run multiple
      sessions, please refer to the section 'Using the Master'.

     2.7  Print a BBS Configuration Form

      Next, we must get set up to call a PCBoard.  The Telix dialing
      directory itself may need setting up, and we'll check this in a second. 
      When we do get connected, you will have to take some information down,
      such as PCBoard door numbers and 'protocols'.  If your BBS has a Mail
      Door, it will also need setting up if you have never used it.  How to
      do these things is all covered below, and is fairly simple, so don't
      worry about a lot of work.  To help you keep track of the information
      we need, you should print out the file BBS-CFG.FRM that accompanied The
      Liberator, if you have a printer connected.  Type <Alt-J> from the
      Command File Manager (jump to DOS), change to the directory where the
      file is located if necessary, then setup your printer and type COPY
      BBS-CFG.FRM PRN.  When the form is printed out, type EXIT to return to
      The Liberator.  If you do not have a printer, a blank piece of paper
      will do.

      Next, start the PCBLOGON Command File we created by typing the number
      beside it, and hitting <Enter>.  A screen should appear, which shows
      what is about to be carried out, and only the Capture File and Discon-
      nect options should be activated (along with a Dial Starting Time of
      'Now').  You are given 10 seconds to look the screen over and abort the
      file (you can increase/reduce or remove the delay entirely using the
      'Tools' option from the main menu.  Many of these details will be
      covered after we get the BBS set up).  Hit a key or wait 10 seconds for
      dialing to start.

     2.8  Dialing Directory Setup

      Since we didn't define any directory entries in the BBS Configuration,
      instead of dialing immediately, the Telix dialing directory is
      displayed to allow you to select one or more entries.  However, before
      we can actually place the call to a PCBoard, we must define the proper
      telephone numbers and some other information in the Telix dialing
      directory.  Even if you have entries set up, please follow along here,
      since there are specific items The Liberator needs set up properly.




     The  L i b e r a t o r  v2.32                   Getting Started - Page 9
     
     

      To add a new directory entry, get the phone number of a PCBoard handy
      and move the highlight bar to a blank directory entry (or select 'Add'
      to create a blank, then hit <End> and move to the blank entry).  Once
      on a blank entry, select 'Edit'.

      Enter a description of the PCBoard in 'Name' (e.g. Joe's PCBoard), and
      hit <Enter>, then enter the BBS's telephone number in the 'Phone
      number' item.  All the items down to 'Linked script' should be fine at
      their defaults, so move down by hitting <Enter> a few times, then enter
      "PCBoard" (without the quotes) in Linked script.  A linked script is
      automatically executed if you make a manual call (without The Liber-
      ator), and the defined script will be run to automatically log you on. 
      You must edit (include your name) and compile PCBOARD.SLT before using
      it, so later please see the instructions in this file if you haven't
      done so.  It is recommended you use the PCBOARD.SLT that accompanied
      The Liberator, since it performs a more complete logon (The Liberator
      has its own logon routines though, and normally doesn't require this
      file).  Set it up and compile it whenever you get a chance.

      *IMPORTANT*:  Even if you prefer not to use PCBOARD.SLT as a Linked
      Script, you must enter something (any character) in the 'Linked script'
      item or Telix will pause after connecting and The Liberator will miss
      the opening logon prompt.

      The 'Default terminal' should be set to ANSI-BBS and I recommend you
      use Zmodem as your default protocol, though it is up to you. 

     2.9  What are Protocols?

      [If you're familiar with protocols, skip this section.]  Protocols are
      used when transferring computer files (programs, etc.) to and from the
      BBS, and you might think of them as a language.  Let's say 1k-Xmodem is
      Spanish, Ymodem is Japanese, Zmodem French, etc.  As with people, the
      actual language being spoken is not really important as long as both
      people are using, and understand the language agreed upon.

      Likewise when you transfer a file, both Telix and the PCBoard at the
      other end must be speaking the same language, or using the same
      protocol, when transferring programs back and forth.  Like languages,
      some protocols are also more efficient than others.

      Zmodem is an efficient and reliable protocol to use, but remember that
      it must be available at the BBS before you can use it.  Ymodem (Batch)
      is also a good choice, then 1k-Xmodem if all else fails.  If you have
      an error-correcting modem (MNP, etc.) you may also use the -G protocols
      for some extra speed (Ymodem-g, G-1k-Xmodem), though I find transfers
      often abort using these protocols, with or without The Liberator.

     2.10  What are Batch Protocols?

      Some protocols also have the ability to transfer files a bunch at a
      time (a 'batch') while others can only send one file at a time.  Batch
      protocols normally allow 'wildcards' (as in DOS, * and ?), and/or




     The  L i b e r a t o r  v2.32                  Getting Started - Page 10
     
     

      several filenames to be specified, separated by spaces.  Once a batch
      transfer starts, the Telix transfer window will stay displayed on the
      screen continuously while one file is sent after the other.  Non batch
      protocols allow only one file to be specified at a time, which is
      slower.  The most common batch protocol is Zmodem, Ymodem (Batch) is
      another, as well as Ymodem-g.  Xmodem is not batch oriented, nor is 1k-
      Xmodem or G-1k-Xmodem.  The Liberator will take advantage of batch
      transfers in ProDoor, and on PCBoard if available.

     2.11  Enter Your Password

      Moving along, the rest of the directory entries up to 'Password' should
      be fine at their default values, so hit <Enter> a few times to move
      down.  In the 'Password' entry, <Enter> a password to use on the BBS
      and hit <Enter> twice more to save the entry.
      *IMPORTANT*: You MUST enter your password in ALL entries you intend to
      use The Liberator with, as this is where The Liberator looks for your
      password.  If no password is defined in an entry you connect to using
      The Liberator, the program will abort and disconnect.

     2.12  Dial the BBS

      Now that you have your entries set up properly, to carry out dialing,
      highlight the proper entry, or mark all appropriate entries with the
      space bar (making sure they are all PCBoard BBS's), then select 'Dial'
      on the bottom menu bar.  Once connected, control is returned to The
      Liberator where it will carry out the logon (The Liberator always
      disables any 'Linked scripts', such as the 'PCBoard' linked script
      discussed above).

      If you are logging on for the first time, you will have to abort the
      Command File by hitting <Esc>, then enter some information to get
      signed up on the PCBoard.  (Select "C)ontinue to logon as a new user"
      on the BBS by entering a 'C', then answer any questions.  When prompted
      for a password, make sure you enter the same one defined in your
      dialing directory.)  Otherwise, The Liberator will attempt to log on,
      and should only run into problems if your modem is not set up properly,
      or the Sysop [BBS System Operator] is using an old version of PCBoard,
      or has changed the format of some logon questions.

      If the logon does not take place at all (you see no text within 10
      seconds or so), then most likely your modem and/or Telix is not set up
      properly and you should refer to your modem documentation, and the
      Telix documentation.  Common problems include not having 'Echo' turned
      on in Telix, or on your modem, or having it turned on in both (double
      characters), or having the wrong baud rate set (you must use a baud
      rate that both your modem and the PCBoard support... start at 300 and
      work your way up if in doubt).  The comm. parameters should also be set
      in the Telix dialing directory to Parity None, Data bits 8, Stop bits
      1.

      If the BBS is using an old version of PCBoard, or has changed the
      format of some questions (prompts) PCBoard asks in the logon, The




     The  L i b e r a t o r  v2.32                  Getting Started - Page 11
     
     

      Liberator may not recognize one or more of the logon questions.  If the
      program cannot find a recognizable prompt within 10 seconds of a
      connection, it will send an <Enter>, then look again for 10 seconds,
      then send a few Ctrl-X's and Ctrl-K's to attempt to get the board's
      attention (aborts any bulletins, etc.), and tries again.  If after
      three tries a recognizable prompt is still not found, the program will
      notify you and abort.

      If this happens, abort The Liberator by hitting <Esc>, and logon
      manually.  Someone may have uploaded a working Configuration for this
      BBS (we'll check in a minute), so you may not have to worry about
      setting up all the prompts yourself.  If a working Configuration is not
      found, the section 'Configuring Prompts' will give you some pointers. 
      However, the main thing now is to get the PCBoard set up for use. 
      Configure any prompts later, after we disconnet, if necessary.




     The  L i b e r a t o r  v2.32                    PCBoard Setup - Page 12
     
     

                                 3.  PCBOARD SETUP


     3.1  Checking For Batch Transfer Support

      As mentioned above, some protocols allow files to be transferred in a
      'batch' or several at a time, one after the other.  The PCBoard UB/DB
      commands are used to enter several filenames (a batch) before the
      transfer starts.  Once all the filenames are entered, then the actual
      transfer starts and all files are sent one after the other without
      having to close the download window, and go back to the main menu to
      enter the next filename.

      If this doesn't make any sense now, you'll see what I mean when you go
      to download some files.  Suffice to say it is a faster way to transfer
      files than the conventional PCBoard method of entering one name,
      transferring the file, going back to the main menu, entering the next
      filename, transferring the file, etc.  On a test download of 10 small
      files, performing the transfer in non-batch mode took 5 minutes, while
      the same transfers in batch mode took just over 3 minutes.  Needless to
      say, if you are transferring hundreds of files each week, the savings
      in online time and/or long-distance fees could be substantial by taking
      advantage of batch transfers.

      The Liberator supports every type of file transfer PCBoard is capable
      of.  Regular non-batch transfers are of course supported, but also both
      the PCBoard UB (Upload Batch) and DB (Download Batch) commands are
      supported, if available, and the program also allows batch uploads and
      downloads in ProDoor if a ProDoor is available.

      To make use of PCBoard batch transfers, you must first check to ensure
      that your BBS supports them.  The UB/DB commands were relatively new at
      release of The Liberator v2.3, and your Sysop may not have upgraded to
      a new version of PCBoard yet.

     3.2  Checking the PCBoard Version Number

      An easy way to see if the UB/DB commands are available on your BBS, is
      to check the version number of PCBoard that your Sysop is using.  To do
      this, first press a key to get rid of The Liberator's 'Command File
      Complete' window.  (Note that if you were not at your computer, The
      Liberator would have sounded a pager every ten seconds until you
      returned and pressed a key.)

      Now, enter the I)nitial Welcome command at the PCBoard 'Command?'
      prompt by entering an 'I'.  Near the first line, you should see
      something similar to this:

      PCBoard (R) - Version 14.5/U

      All we need from this is the 14.5 (could also be 14.2, 15.0, etc).  You
      will later enter this version number in a Liberator Configuration, and
      The Liberator will then know if it is possible to perform file




     The  L i b e r a t o r  v2.32                    PCBoard Setup - Page 13
     
     

      transfers in batch mode.  If the BBS is using 14.5 or greater, both the
      UB and DB commands are available.  As well, multiple-line upload
      descriptions are supported by PCBoard 14.5 or greater, and The
      Liberator allows you to enter extended descriptions when available.
      Multi-line upload descriptions are also supported in ProDoor.  PCBoard
      14.2 supports the DB command, but not the UB command, so The Liberator
      will not make use of batch transfers here.  Batch transfers use
      different prompts than regular transfers, and The Liberator cannot
      handle both PCBoard methods at once.  See the 'File Transfers' section
      later, for further details on uploading or downloading files.  For now,
      simply make note of the PCBoard version on the BBS Configuration Form,
      or on a piece of paper.

      If the BBS is displaying the 'More' prompt, enter an 'N' for No more,
      and you will return to the PCBoard main menu.

     3.3  Setting Up Protocols

      Next, select T)rans. Protocol to view the available PCBoard protocols. 
      Then type <Alt-S> to view the Telix protocol menu and find a protocol
      that both Telix and the PCBoard have available.  Make a note of the
      letter used on the Telix protocol menu to select the protocol you
      prefer, then hit <Esc>.  Next, enter whichever letter is used on
      PCBoard to signify the same protocol.  This will be saved by PCBoard as
      your 'default' protocol.

      Note that with some error-correcting modems, the 'G' protocols (Ymodem-
      g, G-1k-Xmodem) are not reliable for uploading, so with The Liberator
      you can select a separate protocol for uploading, while using the
      faster 'G' protocol for downloading.  If this is desired, SET YOUR
      DEFAULT PROTOCOL ON PCBOARD TO 'N)one', take note of the actual letter
      used to select the non-'G' protocol you desire (e.g. 'Z' for Zmodem),
      as well as the letter used to select the 'G' protocol (e.g. E for
      Ymodem-g), on both the Telix protocol menu and the PCBoard protocol
      menu, then enter the information on a piece of paper or the BBS
      Configuration form.  The Liberator will use these letters later to
      select the proper protocols both from Telix, and from the PCBoard.  If
      you are only using one protocol for uploading and downloading, you can
      ignore the PCBoard letter used to select it, as long as it is set as
      your default protocol.

     3.4  Searching For Liberator Configurations

      Next, from the PCBoard main menu, type "Z Liberat A" (no quotes, and no
      'or' in Liberat in case it is misspelled 'Liberater') and hit <Enter>
      to perform a Z)ippy scan for Liberator Configurations.  A helpful
      Liberator user may have uploaded a working Configuration for this BBS,
      which will save us a bit of work (depending on the level of Sysop-
      customization on the BBS, it may save also save you some headaches
      trying to get the proper prompts).  The description should say 'Liber-
      ator Configuration for <BBS>' or something similar.  It doesn't matter
      what version of The Liberator the Configuration is for, since all older
      versions of these files can be automatically converted, if necessary.




     The  L i b e r a t o r  v2.32                    PCBoard Setup - Page 14
     
     

     3.5  Joining Conferences

      If you don't find anything, try entering a 'J' to see the conference
      menu (it may be longer than one screen; hit <Enter> after each screen-
      full).  You may need to J)oin a specific conference to get at the IBM
      or Communications files, etc.  Enter the appropriate conference number,
      then resend the Z)ippy Scan command, if necessary.  You may also want
      to write down the conference number and have The Liberator automatical-
      ly join this conference at startup.  If you had to join now to get a
      file, chances are you'll have to do the same later, so you might as
      well have The Liberator do it for you, so you won't forget.  Note that
      some conferences also require you to OPEN ProDoor before joining them. 
      Type OPEN and enter the ProDoor number if this is the case.

      The Zippy scan should also reveal The Liberator v2.32 itself, (LIB232.-
      ZIP) but if it doesn't it would be appreciated if you made a note to
      upload it to this BBS after we get The Liberator set up.  An Upload
      List has been provided to allow you to automatically upload The Liber-
      ator.  I.e. the program uploads itself!  Software such as The Liberator
      relies on users like yourself for distribution.

      If you didn't find a Configuration, don't despair.  They are normally
      very easy to set up and we'll go through a full setup below.  If the
      Z)ippy scan did turn one up, enter the PCBoard command "D <filename.-
      ext>", where <filename.ext> is the filename of the Configuration (e.g.
      BBSCFG.ZIP), then hit <Enter>.  If PCBoard prompts you for filename 2,
      hit <Enter> again, twice.  Then, hit <Alt-R> (receive; you can also use
      <PgDn>) to receive the file, and select the proper protocol from the
      Telix menu.  The download should only take a few seconds, and for now,
      we'll just leave the Configuration in your Download Directory, for use
      later when we set up The Liberator further.  Once you get a BBS
      Configuration working for the BBS, it would also be appreciated if you
      could make a note to upload it for others to make use of.  Please try
      to test all features before uploading it though.  Feel free to include
      your name for credit.

     3.6  Turning Expert Mode On

      Since The Liberator does not make use of PCBoard menus, you can also
      turn X)pert mode on by typing 'X'.  The PCBoard main menu will not be
      displayed when expert mode is on, which will speed up operations a
      little.  If you logon manually and get lost (which you may never have
      to do, with The Liberator at your disposal) you can simply type 'X'
      again to turn eXpert mode off.

     3.7  Viewing the available DOORS

      Now, type OPEN and hit <Enter> to get a listing of doors available on
      the BBS.  We are interested in Qmail v2/v3/v4, MarkMail, MegaMail,
      NetMmail, PCRelay, ProDoor, and/or ProBank, so please fill in these
      door #'s on the BBS Configuration form or a piece of paper, if found
      (only ONE Mail Door 'type' is supported per Configuration... if the
      board has multiple types, choose the one you like best).  If the board




     The  L i b e r a t o r  v2.32                    PCBoard Setup - Page 15
     
     

      supports door NAMES you may also use the names if desired (e.g. you
      enter QMAIL4, instead of the number 1, etc.)  If you cannot locate a
      door on the menu, but you are sure it exists, you may have to J)oin a
      specific conference first.  Exit the door menu by hitting <Enter>, then
      type 'J' and hit <Enter> to get a list of conferences, and join the
      most probable one then type OPEN again.  Keep J)oining conferences
      until you find the correct one (or try reading some of the B)ulletins,
      or leave a C)omment to the Sysop asking where it is, if all else
      fails), then make note of the conference for use setting up a BBS
      Configuration later.

      If no appropriate doors were found, hit <Enter> at the door menu to
      return to the main prompt, then type 'G' for G)oodbye to log off and
      proceed to the next section.  You can still make good use of The
      Liberator even if no doors at all are available.  If you located a
      ProDoor, and are using PCBoard v14.2 or less, please enter its number
      to OPEN it.  If only a Mail Door was located, skip to the 'Mail Door
      Setup' section below.

      PRODOOR NOTE:  Since the release of PCBoard v14.5, ProDoor's use has
      become somewhat redundant.  If you are setting up for a PCBoard v14.5
      (or greater) board, I recommend you leave ProDoor undefined in your
      Liberator Configuration, and simply enable PCBoard batch transfers. 
      Most of the 'extras' ProDoor had to offer are now duplicated in PCBoard
      14.5, so there isn't much sense wasting time opening the ProDoor to
      perform the same tasks.  However, if setting up for an older PCBoard
      (14.2 or less, or a ProLogon board), proceed with ProDoor set up.

     3.8  ProDoor Setup

      Once at the ProDoor main prompt, select 'D' and hit <Enter> to view the
      protocol menu, then type <Alt-S> to display the Telix protocol menu. 
      ProDoor frequently has extra protocols that are not available on
      PCBoard.  Find a protocol that both Telix and ProDoor support, then
      take note of the Telix protocol menu letter for the protocol you prefer
      and hit <Esc> (if using separate upload/download protocols, make note
      of both letters).  Then take note of the ProDoor menu letter used to
      signify the same protocol (again, if you wish to use separate protocols
      for uploading and downloading, please take note of both letters). 
      Enter the information on the BBS Configuration form, then hit <Enter> a
      couple of times to abort the ProDoor download.

     3.9  Mail Door Setup

      If the BBS has a Mail Door (Qmail/MarkMail only), OPEN the door by
      selecting its number from the door menu, and we'll go set it up for
      use.  If you are not looking at the door menu, type OPEN then hit
      <Enter>, and enter the appropriate number.  If using a MegaMail-type
      door, the set up in this section does not apply.  Please see your
      Offline Reader documentation for information on setting up these doors.

      Setting up a Mail Door is very easy, and in my opinion is much easier
      than learning the standard online way of messaging.  These doors




     The  L i b e r a t o r  v2.32                    PCBoard Setup - Page 16
     
     

      collect new messages on all the subjects (conferences) you're inter-
      ested in, then they compress all the messages found, usually in Phil
      Katz's ZIP format.  You then receive (download) a file which you can
      browse offline at your leisure, using a special reader program.  Not
      only does this save your limited online time, and possibly long-
      distance fees, but it's also more relaxing and allows you to be more
      thoughtful about your replies since there is no need to rush.

      If opening a Qmail door, once the door opens, take note of the Qmail
      major version number (for MarkMail, simply make note that a MarkMail
      door is being used).  The Qmail v2.xx, v3.xx, v4.xx doors operate quite
      differently and the major version # must be specified in The Liberator.

      The basic steps to setting up these doors is to select C)onfigure, then
      a) select the conferences (each conference covers a different subject)
      you are interested in, b) reset your 'last message read' pointers in
      each conference to the last 50 or 100 messages, so that you don't get
      thousands of old messages (e.g. if the 'high message' pointer is at
      500, set your 'last message read' pointer to 400 or 450... do this for
      each conference), and c) select a default protocol.  That's about all
      there is to it.  Most Mail Doors will even take you to the proper menus
      automatically, the first time you use them.

      There are other optional items that you may want to change, such as
      getting a listing of new files/bulletins in each packet, etc.  Take a
      look at the Configuration menu and configure the door as you like (if
      you don't see a menu, turn expert mode off by entering an 'X').  In 
      Qmail v3/4 doors, some extra options are available by entering OPT
      (enter a question mark to view the OPTions, then type a number to
      toggle it ON or OFF as you like).

      NOTE:  One important OPTion in the Qmail v3/4 doors is the 'Clear the
      keyboard input buffer' item, which must be turned OFF (do not clear the
      buffer).  If left ON, The Liberator's commands to the door may be
      erased, since it sends them very quickly, usually before the entire
      prompt has even been displayed.

      If you wish to use separate protocols for uploading and downloading,
      you must be using a Qmail v3/4 door. In this case, take note of the
      letters used on the door's protocol menu, to select the protocols you
      desire, and fill the information in on the BBS Configuration form.  If
      you are using a Qmail v2, MarkMail or other door, you must set a
      'default' protocol, and use the same protocol for both uploads and
      downloads.

      The Liberator also needs to know the official Packet ID of the BBS, in
      order to locate and maintain mail packets.  You can find out the Packet
      ID now by selecting 'D' from the main door menu to Download a mail
      packet (in Qmail v3/4 doors, first select 'Q)uit' to get out of the
      Configuration menu, and back to the main door menu).  The door will
      then start collecting messages from all the conferences you selected,
      and will display a screen of what it found.  It then asks if you want
      the packet, to which you reply 'Y' (yes).  The door will then start to




     The  L i b e r a t o r  v2.32                    PCBoard Setup - Page 17
     
     

      compress the packet, which may take a minute or two, and will prompt
      you to start your download when the packet is ready.

      Of course, if you are not using auto-Zmodem hit <Alt-R> (receive) and
      select the proper protocol when the door prompts you to start your
      download (later, The Liberator will take care of all this for you).  In
      the Telix download window you will see a file called SOMETHING.QWK (QWK
      for Qwik, since the original door used to be called the QwikMail
      Door... since changed to Qmail Door.  The QWK extension is just a
      renamed ZIP or ARC, etc).  The SOMETHING part of the filename is what
      we're interested in, since this is the Packet ID.




     The  L i b e r a t o r  v2.32                Mail Reader Setup - Page 18
     
     

                               4.  MAIL READER SETUP


     If you downloaded a mail packet and do not yet have an Offline reader
     program, you may want to download one from the BBS now.  Otherwise,
     that's about it for setting up the BBS, so logoff by entering 'G' for
     G)oodbye.  If you are not using a mail reader program, please proceed to
     the next section.  Setting up a mail reader is a fairly involved topic,
     and largely depends on the reader you select so I'll just cover the
     basic steps to get you going.  (This does not apply to MegaMail-type
     readers.  Please refer to your reader documentation for information.)

     4.1  Choosing a Reader

      First you need a reader if you don't have one.  At the writing of this
      document, the two popular readers were Qmail Deluxe by Mark Herring
      (author of the Qmail door) and EZ-Reader by Eric Cockrell.  Both will
      allow you to read QWK packets downloaded from either a MarkMail or
      Qmail door (and other doors using the same packet format), so it's up
      to you as to which reader you choose.

      EZ-Reader is Shareware, and you should be able to find a copy on your
      BBS by typing "Z READER A" from an appropriate conference (Zippy scan
      for "READER" in All areas)  You should also run into Mark Herring's
      Shareware reader, but you won't find Deluxe on your BBS, since it's for
      registered users only.  Mark's Shareware reader may be updated in the
      future to give you a better idea of what Deluxe is like, but at the
      writing of this document the Shareware reader and Deluxe bore little
      resemblance (DeLuxe is MUCH better than the Shareware reader).  The
      Shareware Qmail reader will allow you to get started though, and is
      useful for the registration form to order Deluxe.  Use your discretion,
      and talk to other mail reader users via your BBS (in an appropriate
      conference) for information as to which reader is best suited to your
      needs.  Download both, then logoff by typing 'G'.

     4.2  Configuring the Reader

      When you get your reader(s) installed (do this later), the usual steps
      are to define a message packet directory (where the reader will look
      for the QWK packets you download from the door... normally your Telix
      download directory, but The Liberator allows you to define another
      directory) a Reply directory (where the reader will create an <ID>.REP
      file containing your replies to upload back to the door), and an editor
      to enter replies and new messages to upload back to the door.  You must
      also define 'packer' commands, that the reader will use to uncompress
      QWK packets, and to compress your REP (replies) packet.

      Getting the reader to communicate properly with your favorite word
      processor or editor is normally where people run into problems. 
      However, if you follow your reader's documentation carefully you
      shouldn't run into problems.  Mail readers are a subject all their own,
      so I won't get into it any further, but you can surely get a lot of
      help in your reader documentation and on your BBS.




     The  L i b e r a t o r  v2.32              Configuration Files - Page 19
     
     

                         5.  LIBERATOR CONFIGURATION FILES


     Now that we have that out of the way, we can set up a BBS Configuration
     File properly.  If you did not find a BBS Configuration when we were
     logged on to the PCBoard above, you may skip down to 'BBS Configuration
     File Setup'.

     5.1  Installing A Pre-defined Configuration

      If you found a Liberator Configuration File on your BBS, type <Alt-J>
      from Telix terminal mode (or any Liberator prompt) to shell to DOS,
      switch to your Telix Download Directory and uncompress the file if
      necessary.  PKUNZIP <filename> for a .ZIP file, PKUNPAK <filename> for
      an .ARC file.  If you don't have these programs (pkzip/pkunpak), you
      know how and where to get them... they are available on just about any
      IBM-oriented BBS.

      Next, simply copy the CFG file (or files) into your Telix script direc-
      tory, or Configuration File directory, if you specified one (e.g. COPY
      *.CFG C:\TELIX\SCRIPTS).  Once the Configuration is in your script
      directory, type EXIT to return to Telix, and start The Liberator by
      typing <Alt-G> then entering LIBERATE.  From the main menu, select
      'Tools', then 'Convert files to v2.3 format'.  The new Configuration
      (and all your other files, but it will only take a second) will then be
      checked and converted to v2.3 format if necessary.

     5.2  Configuration File Setup

      BBS Configurations, once set up, can normally be forgotten.  You do not
      have to go through all these steps each time you want to set up a job
      to execute on a PCBoard.  Only one Configuration File need be setup for
      each PCBoard and you can then set up as many jobs as you like for that
      BBS without creating a new Configuration.

      If you are not in The Liberator's Command File Manager, start the
      program now by typing LIBERATE from DOS, or entering <Alt-G> LIBERATE
      from Telix terminal mode.  Once again, select 'C'reate to get started,
      and either enter a 0 if creating a new Configuration, or enter the
      number beside the pre-defined BBS Configuration, if you found one on
      the BBS.  If you found multiple configurations on the BBS, select the
      'main' one, or the one that looks like it is used for general use.

     5.3  PCBoard Setup Screen 

      'Name used on PCBoard' should be set to the name you used to log on to
      the PCBoard above.  Select this entry now by entering a '1' (on the top
      row, and not the numeric keypad).  Then, type the name used on the
      PCBoard (use <Ctrl-End> or the <Del> key to clear any trailing charac-
      ters from the entry), and hit <Enter>.

      'Telix Directory Numbers to Dial' is where you store Telix Dialing
      Directory entry numbers for the PCBoard.  If no numbers are entered,




     The  L i b e r a t o r  v2.32              Configuration Files - Page 20
     
     

      The Liberator will display the Telix dialing directory at runtime to
      allow you to select entries manually. However, to avoid having to
      select the entries each time, you may specify up to 10 Telix directory
      entries in this option (10 is the Telix maximum). Select the option
      now, and you will see a large editing box appear.  This box is used for
      all entries that exceed the length of the display window to the right
      of the screen.  If there were actual entry numbers in the option, they
      will be moved to the box for editing.

      Some options display reminders, such as the one here.  If you press
      <Alt-D>, the Telix dialing directory will be displayed to allow you to
      edit or view any entry.  Hit <Alt-D> now and move the dialing directory
      highlight bar to any valid PCBoard entry.  Select 'Edit' and just
      confirm that all the information is entered correctly, and that your
      password for this BBS is entered in the 'Password' option near the
      bottom (this is also required for operation of PCBOARD.SLC, and most
      Telix scripts).  Next, take note of the directory entry number to the
      left of the PCBoard name.  If there is more than one entry for this
      PCBoard, please confirm that your password is entered in each one, take
      note of all entries, then hit <Esc> or type 'X' to exit the dialing
      directory.

      Now type the directory entry number(s) in the box.  If more than one is
      to be used, separate each number with a space (e.g. 30 31 32) up to 10
      entries, or 64 characters which is the Telix maximum, then hit <Enter>.

      'PCBoard version' is the PCBoard software version number being used at
      the BBS, which we took down above.  Specify the full version number,
      and one decimal -- even if a 0 (e.g. 14.0).  New features were intro-
      duced in PCBoard 14.5, and The Liberator must know whether they are
      available before attempting to make use of them.  Note that if you
      enter a version 14.5 or greater, you will be asked if you wish to make
      use of Batch transfers.  If you answer 'Y'es, the file transfer prompts
      will be automatically adjusted for batch operation.  To change out of
      batch mode, select the item again, and answer 'N' when asked whether to
      perform batch transfers.

      'Redial attempts' holds the number of dialing attempts you want The
      Liberator to make before giving up.  Actually, The Liberator just
      passes the number defined here, and the entry numbers, to the Telix
      dialing routines, and Telix handles all dialing.  If you defined 3
      dialing directory entries in option 2 above, and set this option to '3'
      redial attempts, then each entry will be tried once.  If you have only
      a single entry defined and you set '3' redial attempts, the single
      entry will be tried three times (a TOTAL of 3 attempts will be made. 
      This is just the way Telix works, and not a function of The Liberator). 
      If you want to dial repeatedly, until a connection is established,
      leave this item at '0'.  Note that this 'Redial attempts' value is only
      used when calling this BBS by itself.  When calling multiple BBSes with
      the Master, a dialing queue is used, and you may set a separate lower
      number of redials if desired.




     The  L i b e r a t o r  v2.32              Configuration Files - Page 21
     
     

      'Response delay time' is used to make The Liberator slow down its entry
      of responses to questions.  Sometimes a PCBoard may not be fast enough
      to handle the speed with which The Liberator answers questions.  This
      can be remedied by setting a response delay.  Tenths of a second are
      used, so a delay of 1 is one tenth of a second, 5 is half a second,
      etc. Usually this item can remain at 0, but if you notice responses
      coming out too fast, or not at all, try setting a delay.

      'Backspace protection' is a new feature in The Liberator v2.3, and is
      used as protection against line noise.  Even though The Liberator
      answers questions very rapidly, sometimes line noise sneaks in before
      it responds to a question, or may sneak in while pausing for the
      Response Delay set above.  The result is something like this:

      Please enter your first name? !@$%^Sig Tingloff

      The garbage characters before the name are caused by noise on the
      telephone lines, and prevent proper entry of the response.  The
      Liberator defaults to sending five backspaces before entering each
      response, which would eliminate the line noise above.  If no line noise
      is present, the backspaces are sent anyway, but PCBoard ignores them so
      they don't do any harm (the MarkMail door does not ignore them, and
      actually complains vigorously, so backspace protection is automatically
      disabled there).  You can have up to 30 backspaces sent before each
      response, which should be enough to eliminate even the worst line
      noise.  The backspaces are sent very rapidly, and the response is
      entered immediately afterwards, so there isn't much chance of any noise
      sneaking through once the entry starts.  If for some reason you want to
      turn the feature off, you can do so by entering a zero here.

      'Language to use' is not implemented on most PCBoards, and may remain
      set at 1 if only one language is supported.  If more than one language
      is supported, enter the number for 'English', if available, so you
      won't have to reset all The Liberator's prompts for another language. 
      Some PCBoards also have a special language for 'scripts' such as The
      Liberator, which normally uses all the standard English PCBoard prompts
      (which is what The Liberator defaults to).  You should use this
      language if available.

      'PCBoard Graphics' (color) should stay at 'n' for No, unless is it
      essential to have color turned on for some reason.  Having graphics on
      slows things down, and this option may be removed entirely in the
      future, since having graphics on also sends special codes which
      sometimes confuse Telix's tracking routines.

      'Conference to Join at Startup' is used mainly for PCBoards which
      always force you to start at the 'Main' conference.  On some PCBoards,
      CRS for example, most IBM-specific files are only available from the
      IBM conference.  In a case such as this case, you should set The
      Liberator to join this conference at startup.  As well, you may have
      had to join a specific conference to find a DOOR when we were logged on
      above, and in this case you should enter the conference number here. 
      The conference NAME can also be used, if supported in the BBS.




     The  L i b e r a t o r  v2.32              Configuration Files - Page 22
     
     


      'Mail Door'  This entry holds the name or number of the Mail Door on
      the BBS.  If you found a Mail Door on the door menu, while on the BBS,
      enter its number here. The header (the line at the top of the screen)
      will then change from 'Screen 1 of 3' to 'Screen 1 of 4'.  If the
      PCBoard supports door NAMES you may also enter the name of the door
      (e.g. QMAIL4).

      'ProBank Door'  This door is used to deposit online time, to be used in
      a later session.  The Liberator allows you to withdraw time from the
      ProBank before starting a session, and can also deposit as much time as
      you like when the session completes.  Enter the ProBank door number
      here if your BBS has one.  The door NAME can be used if door names are
      supported on the BBS (e.g. BANK).

      'ProDoor'  This door is like another BBS within PCBoard and it supports
      many features that are not available on PCBoard.  The Liberator allows
      you to enter ProDoor for 'batch' file transfers (explained above) and
      to make use of the extra protocols and conferences that are usually
      available only in ProDoor.  As well, customized commands can be defined
      and sent by The Liberator in ProDoor to take advantage of the door's
      many enhanced commands.  Enter the ProDoor number here, if your BBS has
      one.  The door NAME can also be entered, if door names are supported on
      your BBS (e.g. PRODOOR).

      'Online time to save/Max online time'  Online time to save is also a
      new feature in The Liberator v2.3.  This refers to the actual online
      time you have available each day on the BBS.  The Liberator can read
      the time from the PCBoard/Qmail/ProBank/ProLogon/ProDoor main menu
      lines (assuming your Sysop is using the standard format), to determine
      how much time you have left.  If the time set in this option is
      reached, The Liberator cancels further jobs and logs off.  The option
      comes preset to save 5 minutes of online time, which leaves enough time
      to get on and get into the ProBank to get more time out.  You may want
      to perform one automated session per day, but also want to logon later
      in the day to do some work manually.  In this case, just set 'Online
      time to save' to the number of minutes you wish to save for you manual
      session. (Note that the online time will almost surely not be exactly
      what you set here, since the online time can only checked between major
      jobs, when The Liberator is at a prompt displaying your available time. 
      Allow some leeway).

      'Max online time' is the total number of minutes to stay online before
      logging off, regardless of how much online time you have left.  This is
      mainly used to limit the total connect time for long-distance calls,
      etc.  Again, the connection may not be broken exactly at the number of
      minutes you specify here.  The Liberator can only check the elapsed
      time when it has control of your computer (Telix has control during
      file transfers).  If you specify 30 minutes maximum, and if 25 had
      elapsed, The Liberator would still start a 50,000 byte file transfer,
      which may take longer than the specified time.  Once the transfer was
      complete, The Liberator would see it was past the allotted time and
      logoff...  Again, allow some leeway.




     The  L i b e r a t o r  v2.32              Configuration Files - Page 23
     
     

      'Telix/PCBoard Upload Protocol'  When this option is selected, a menu
      of the most common Telix protocols will be displayed to allow a visual
      selection of the desired protocol.  If the protocol you want is not on
      the menu, select 'O'ther and enter the Telix protocol letter you wrote
      down earlier (if you forgot the letter, hit <PgUp> to view the Telix
      protocol menu).  When the Telix protocol letter is entered, you will be
      prompted to enter the corresponding PCBoard letter for the same
      protocol.  If you are using your default PCBoard protocol enter an 'N'. 
      Otherwise enter the letter you wrote down earlier at the PCBoard
      protocol menu.

      'Telix/PCBoard Download Protocol'  This is normally set the same as the
      entry above, but if you are using an error-correcting modem and wish to
      use a 'G' protocol for downloads, enter the proper letters here.

      'Custom Logon/Logoff Scripts' This entry is used to handle special
      logons and/or logoffs that are not supported internally by The Liberat-
      or (The Liberator has built-in support for PCBoard logons).  You can
      use this option to handle iNet/Datapac logons/logoffs, or any other
      logon/logoff for which you have a working Telix script.  The logon
      script, if defined, is executed as soon as The Liberator establishes a
      connection, and the defined script should carry out whatever is
      necessary to get to the PCBoard CONNECT.  The Liberator will pick
      things up from there (The Liberator can also carry on after a partial
      PCBoard logon).  The logoff script, if defined, is executed as soon as
      PCBoard sends the 'Run Logoff Script' prompt, defined on CFG screen 2
      (normally 'Thanks for calling').  Support for iNet logons/logoffs is
      included with The Liberator.

      'Usage Log'  The Liberator makes extensive use of this file for
      stamping various status/error messages.  This can be helpful when
      trying to figure out what went wrong with a session, and the Usage Log
      should be the first place you look for error messages.  You are allowed
      to clear the entry, thereby turning off the Usage Log, but this is not
      recommended unless absolutely necessary, since many status/error
      messages would be lost. 

      'Upload Directory' This is the same as the Upload Directory defined
      within Telix, but if you want to use a different drive/directory for
      this BBS, then define it here.  When you request an upload (to send a
      file to the BBS), The Liberator will look for file(s) to upload in the
      directory defined here, unless you specify another path in your Upload
      List.  The exception to this is REP files (replies to upload to a Mail
      Door) and PTR files (pointer reset, for Qmail v3/4) which have
      separately defined directories on screen 4.

      'Download Directory' This is the same as above, but for downloads.  All
      files downloaded (received) from the BBS are placed in this directory. 
      The exception to this is QWK packets (containing messages from a Mail
      Door) which can be placed in a separate directory, defined on screen 4.

      That's it for screen 1, so please press the <Down arrow> or <PgDn> key
      to move to the next screen.  Note that the bottom line displays the




     The  L i b e r a t o r  v2.32              Configuration Files - Page 24
     
     

      up/down arrows to remind you how to change screens, if you forget. 
      <PgUp> / <PgDn> may also be used.  Note that <up> from screen 1 takes
      you to screen 3 (or 4, if a Mail Door is defined), and <down> from the
      last screen takes you to back to screen 1.

     5.4  PCBoard Prompts Screen

      Unless your Sysop has redefined the format of some prompts (e.g.
      changed 'What is your first name?' to 'Yo dude, what's your name?'), or
      is using a different language, you may never need to change anything on
      screen 2.  Prompts may also need changing if setting up for an older
      version of PCBoard (older than 14.0).  The Liberator operates by
      watching for these prompts/messages to come in, then enters the cor-
      responding response for what it thinks it found (most of the prompts
      the program watches for can be redefined by you).  For some prompts,
      The Liberator doesn't enter a response, but carries out some operation,
      such as starting a file transfer, etc.

      Note that some prompt descriptions are followed by an asterisk (*). 
      These are 'key' prompts, from which The Liberator can start any job. 
      There are eight key prompts altogether (4 on the next screen, 2 on Mail
      Configuration screen 4), and The Liberator can start any job from any
      of these prompts.  For example, if you are in the Qmail Door, you can
      start The Liberator online and select a Command File set up for a
      ProDoor batch transfer.  The Liberator will then check the prompt,
      realize it's in the Qmail door, Q)uit from the Qmail Door, OPEN the
      ProDoor, and start the transfer.  Same goes for any other job that you
      set up in The Liberator.  If you get a message '<< Unable to locate a
      recognizable prompt >>', then none of the eight key prompts could be
      located. Information on setting the prompts on screen 2, 3, and 4 is
      discussed in the section 'Configuring Prompts' below.

     5.5  Pro Utilities Screen

      ProLogon is a 'front door' program for PCBoard.  If your BBS is using
      it, you'll know -- it can totally change the face of PCBoard, and
      created a fairly major hurdle for this release of The Liberator
      (ProLogon is now automatically supported, if found on your BBS). 
      ProBank is a door used to deposit and withdraw online time.  ProDoor is
      a complete BBS inside a BBS.  If no Pro Utilities are available on your
      BBS (ProLogon, ProBank, ProDoor), then you will not need to configure
      anything on screen 3 either.  If you found a ProDoor when we were
      logged on, one thing to note on this screen if using ProDoor for file
      transfers, is item 3:

      'Transfer in ProDoor if how many files?'.  On some PCBoards, doors take
      quite a while to OPEN, and it may not be worth it to enter ProDoor just
      to transfer one or two files.  This is what item 3 is for: to limit the
      use of ProDoor to a certain number of files.  If a ProDoor is defined,
      before starting any file transfers, valid filenames are counted on both
      your Upload and Download Lists.  If the total number of files on both
      lists is equal to or greater than the number defined in item 3, the
      ProDoor will be OPENed and the transfer (which is a much faster 'batch'




     The  L i b e r a t o r  v2.32              Configuration Files - Page 25
     
     

      transfer) will take place there.  If there are less files than that
      defined in item 3, ProDoor will not be opened and the transfer will
      take place on PCBoard.

      If you want ALL your transfers to take place in ProDoor, regardless of
      how many files are on your list (assuming you have already defined a
      ProDoor on screen 1), enter a '1' in this option.  If you want all your
      transfers to take place on PCBoard (for example, using the 'DB'
      command), enter a '0' in item 3.  Otherwise, enter whatever number of
      files you feel it would be worthwhile to OPEN the ProDoor for.

      'Number of files per ProDoor batch' can be used to limit the number of
      filenames that are entered before transferring each batch.  If you set
      it to '5', then five filenames will be entered, these files will be
      transferred, then five more filenames entered, etc.  Normally you can
      leave this set to a high number, since The Liberator will usually
      automatically recognize when a batch is full.  However, if a batch is
      not started when prompted, set this number to 1 less file than the
      number of filenames entered.  As many batches as you have time for are
      carried out.

      Enter your ProDoor Upload/Download protocols in the same manner as your
      PCBoard protocols on screen 1, but using the ProDoor protocol letters
      you took down above in the door.  The rest of the items on this screen
      will need changing only if your Sysop has changed the standard prompts,
      or an old/very new version of ProDoor is being used.  If you have
      problems with any Pro Utilities, you will know which screen to come to
      for redefinition of prompts.  Also note the four 'key' prompts on this
      screen (the descriptions followed by an asterisk), from which any
      Liberator job can be started.

      Hit <Down arrow> to move to screen 4.  If no Mail Door was defined on
      screen 1, you will instead move back to screen 1, and may proceed to
      'Saving a BBS Configuration' below.

     5.6  Mail Door Setup Screen

      'Packet ID' is the ID of the mail packet that we obtained when we were
      in the Mail Door.  Enter the proper ID here.  If using a MegaMail-type
      door, the Node ID can be obtained through your Sysop, or try reading
      the B)ulletins on the BBS or asking a friend.

      'Door type' is the type of mail door being used on the BBS, which we
      noted earlier.  To change the type, select item 2 and enter the number
      which corresponds to the door being used on the PCBoard.  If you are
      setting up a pre-defined Configuration, this item should already be set
      to the proper type of door.  Selecting a different door type will
      automatically update the prompts, and you will lose any changes you had
      made to the prompts on the screen.

      'Perform Mail transfers last' is for use on PCBoards that don't allow
      you to Q)uit from the Mail door after use.  If you set this to 'y'
      (yes), the Qmail transfers will take place last, after all other jobs.




     The  L i b e r a t o r  v2.32              Configuration Files - Page 26
     
     

      'Number of message packets to keep' is the maximum number of packets to
      rename or 'renumber'.  If you set this to '5', The Liberator will keep
      your last five message packets for that board on hand by
      renaming/deleting older packets as new ones come in.  Up to 99 packets
      can be handled in this manner, and all renumbering will take place
      OFFLINE before dialing (assuming you aren't already online when you
      start The Liberator) to avoid wasting online time.  The Liberator
      allows two renumbering formats; the default being <packet-id>nn.QWK,
      where nn is a number from 1 to 99, and an alternate method of <packet-
      id>.Qnn, where the <packet-id> is left undisturbed.  The alternate
      method can be selected using the main menu 'Tools' option, and
      selecting 'Configure'.  If you don't want your packets renumbered, set
      this option to '0' and old packets will simply be deleted just before a
      new packet is downloaded.

      'Number of reply packets to keep' is the same as above, but for your
      reply packets.  Reply packets will also be maintained offline, after
      the connection is broken, if possible.

      'Mail Door Protocols'  The protocols in the next two options should be
      entered as defined when setting up the Mail Door.  Note that the 'Door
      Upload/Download Protocol' options (following the Telix protocols after
      the /) should both be set to 'None (default)' unless using a Qmail v3/4
      door and using separate upload and download protocols.  Other doors do
      not permit the use of separate upload/download protocols, and you must
      use the default protocol as you defined in the door.

      'SESSION.TXT pack command' is the command needed to add a file to your
      newly downloaded QWK packets.  The SESSION.TXT file was temporarily
      discontinued in the Qmail v3 door, and it simply contained the same
      screen that is displayed after your message packet is collected (where
      you are asked if you want the packet or not).  It shows the number of
      messages found in each conference, etc., and if this file exists in
      your QWK packet, your reader will display it when you open the packet
      for reading.  This can be useful to give you some idea what's coming in
      the packet.  The command to enter here is simply the name of the proper
      archiver, depending on the format of the packet.  For example, if your
      QWK packet comes in ZIP format, you would enter PKZIP (or whatever you
      renamed PKZIP.EXE to).  If your packet comes in ARC format, enter
      PKPAK, etc.  If a command is entered, The Liberator will capture the
      packet information screen to a file called SESSION.TXT, and will insert
      the file in the appropriate QWK packet when you disconnect from the
      BBS.

      'Message/Reply/PTR directories' must be set to the same directories
      defined in your reader.  If you set C:\QWK as your Message Packet
      Directory in your reader, then you must set the same directory here in
      the Configuration.  Same with the Reply packet directory, according to
      how your reader is set up.  Note that the PTR directory is only useful
      for those using Qmail v3/4 doors, which place a <packet-id>.PTR file in
      your packet containing information about your message pointers (Deluxe
      automatically extracts this file and places it in your 'Archive
      Directory' when you open the packet).  The file can later be uploaded




     The  L i b e r a t o r  v2.32              Configuration Files - Page 27
     
     

      to the door by The Liberator to reset your messages pointers quickly in
      a number of conferences.

      The rest of the items will only need changing if your Sysop has changed
      the standard prompts, so that's about it for BBS Configurations!  Refer
      to the section 'Configuring Prompts' for prompt configuration informa-
      tion, if necessary.

     5.7  Saving a Configuration File

      You can save the Configuration by hitting <Enter> when the cursor is
      next to the 'Enter = Save' prompt.  Hitting <Enter> (or <Esc>) here
      will call up the save window, where you can do one of three things:

      a) Hit <Esc> to abort saving the file.  Any changes you made are
         discarded and not written to disk.

      b) Enter a new name to save the file under.  If there is a <packet-id>
         for the BBS, this is a good choice for the Configuration name.  If
         not, just enter an abbreviated name that will remind you of the BBS. 
         The file will then be saved as <name>.CFG, where <name> is the name
         you enter.  Configuration Files are normally saved in your Script
         directory, but you may change this with the main menu 'Tools' option
         under 'Configure'.

      c) If you were editing a Configuration created previously (such as if
         are editing one we found one on the PCBoard), you can give the file
         a different name.  This will cause the file we started with to be
         left alone, and will create a new file using a different name. (e.g.
         you start by editing BBS.CFG, but save it as BBS1).  This can be
         useful to 'clone' previously created BBS Configurations and cut down
         on setup time.

      For our purposes, please save the file by typing in a name and hitting
      the <Enter> key, or by simply hitting <Enter> if you are editing a
      Configuration from the BBS.  You will then automatically move the
      'Create Command File' screen.

     5.8  Cloning or Editing Configuration Files

      To edit or just view a previously created Configuration, select 'Edit'
      from the main menu, type <Alt-E> to edit a Configuration, then select
      the file you want to view/edit from the menu.  If you found multiple
      pre-defined BBS Configurations on your BBS, use this method once we get
      back to the main menu, to set the rest of the Configurations up
      properly (you have to enter your name and the proper dialing directory
      entry #'s in each CFG). To edit a Configuration from the Command File
      Editor screen (the screen you are looking at now), select option 1
      'Configuration File' then hit <Alt-E>.  To clone a Configuration, use
      either of the above methods, make any changes you like, then simply
      save the file using a different name.




     The  L i b e r a t o r  v2.32                    Command Files - Page 28
     
     

                            6.  LIBERATOR COMMAND FILES


     Command Files define what jobs you want done on a BBS in a given
     session.  You may create up to 99 Command Files, to carry out an almost
     limitless variety of sessions on many different PCBoards.

     NOTE:  All options listed below can be set to interactive mode by
     entering a question mark in the option.  When the Command File is
     executed, you will be prompted for a response to any interactive
     options.  This allows the level of interaction, for any given Command
     File to be tailored to suit your needs.

     'Configuration File' can be thought of as the BBS itself; as this is how
     you tell The Liberator which BBS to execute the defined jobs on.  The
     actual jobs to carry out are defined below.  Note that the BBS Con-
     figuration we just saved has already been placed in option 1 for you,
     but you could select option 1 to use another Configuration (for another
     BBS... or even just a different setup for the same BBS) if you had
     Created others.  You can also edit the currently named Configuration at
     any time by selecting item 1 and hitting <Alt-E>.  You can even enter a
     question mark (?) in the option, as you can with any of the options
     below, to select the Configuration (BBS) at runtime.

     'Dial Starting Time' is the time you want this Command File to start
     running.  If you define a specific time, say 4am (04:00), then each time
     you select the Command File from the main menu, The Liberator will pause
     until 4am before dialing and carrying out the defined jobs.  Time is
     specified in 24 hour (military) format, so 12:00 is noon, 00:00 is
     midnight, 17:00 is 5pm, etc.  Just add 12 if entering a PM time (1pm +
     12 = 13:00... 1am = 01:00 -- do not add 12 for AM times).  When you
     select this option, the current time or the previously saved dial
     starting time will be displayed for editing.  Enter an 'N' (Now) as the
     *first* character (you needn't clear all the other characters) to cancel
     a dial starting time and have the Command File execute as soon as you
     select it.

     'Capture File' is the drive, path, and filename used to capture the
     session.  The default name given is made up by extracting the drive/-
     directory from your current Telix capture file, then adding the name of
     the BBS Configuration and the extension .CAP.  Feel free to change it to
     any name you like (you might want to get used to the default format,
     since it will most likely be forced in v3 of The Liberator, to allow
     capture file maintenance).  Capture Files are quite useful for determin-
     ing problems with sessions, such as capturing a prompt that your Sysop
     redefined and caused the program to hang.

     'Sound'  If set to 'n' (None), then no sound at all will be heard,
     including Telix alarms and PCBoard beeps.  Really there is no need to
     have sound turned on when The Liberator is operating, since it handles
     everything automatically, and has no need for intervention.  Should you
     choose not to disconnect from the PCBoard (via item 14), sound will be
     turned on and you will be paged when the Command File completes. 




     The  L i b e r a t o r  v2.32                    Command Files - Page 29
     
     

     However, if you prefer you can turn sound on for the entire automated
     session by selecting this item and entering 'y' (yes).

     'ProBank Withdrawal' is used to set the number of minutes to withdraw
     from the ProBank.  The number of minutes set here will be taken out of
     the bank before any jobs start, immediately after the logon completes
     (if you are already online when you start The Liberator, the logon is
     bypassed).  If no ProBank door is defined in the CFG named in item 1,
     ProBank withdrawals will not be available and the item will display
     <N/A>.  If you have not used the ProBank before, you will have to
     accumulate some time using 'ProBank Deposit' below before attempting a
     withdrawal.  You may use The Liberator immediately to deposit time;
     ProBank requires no manual setup.

     'Custom Command[s] 1' is used to send your own commands to PCBoard, or
     run another Telix SALT script in the middle of, or even as a Liberator
     session.  Custom Commands can be used to read mail from systems without
     a Mail Door, or to carry out some of the smaller jobs that The Liberator
     doesn't directly support (reading bulletins, etc).  The commands can be
     as simple or as complex as you desire.  There is a section devoted to
     Custom Commands later in the manual, with some example commands, that
     you should refer to when you're ready to set up one up.  Custom Commands
     are a powerful and very easy-to-use option, and are well worth looking
     into when you have time.

     If you don't have a Mail Door defined in the Configuration, you may skip
     the next three items.

     'Qmail Pointer Reset Upload' should be set to 'y' (yes) if you wish to
     send a PTR reset file to the Qmail door (Qmail v3/4 only).  If using
     Deluxe, the proper file can be found in your 'Archive Directory', and
     you may edit the file to reset multiple conferences, or simply upload it
     as is to reset your pointers to where they were before you downloaded
     your last packet.  If you can't find the <packet-id>.PTR file, simply
     unpack it from your last QWK packet (e.g. PKUNZIP <id>.QWK <id>.PTR ...
     if PKUNZIP doesn't work or gives an error, try PKUNPAK, or LHARC, etc). 
     PTR files are useful if you get a bad packet, but the door updated your
     pointers.  You simply have The Liberator upload the PTR file, and all
     your pointers will be back where they were before your last download.

     'Mail Replies Upload' should be set to Yes if you want to send your
     replies back to the Mail Door.  The reply file is created by your
     reader, and holds any replies or new messages you entered while reading
     the message packet.  When the reply packet is uploaded, the Mail Door
     extracts the replies inside and inserts them in the BBS message base, in
     the correct conference, addressed to the correct person.  If the upload
     is successful, the packet is automatically deleted or renamed by The
     Liberator depending on the number you set in 'Number of reply files to
     keep' in the Configuration.  If the proper reply file cannot be found
     (if you haven't created any replies ... or gave the wrong <packet-id> or
     'Reply directory' in the CFG), The Liberator will cancel the upload
     request when you start the Command File, thus you may leave this set to
     Yes if desired.




     The  L i b e r a t o r  v2.32                    Command Files - Page 30
     
     

     'Mail Download' has a few different settings.  If set to Yes, a regular
     download will take place according to how you configured the door.  This
     is the only item available in MegaMail-type doors.  If set to Personal,
     only messages addressed to you will be downloaded.  If set to Repeat,
     downloading will continue until the 'No Mail Found' prompt is received. 
     This can be useful when you have a lot of catching up to do, and must
     download several packets (each packet has a limit as to its size). 
     Sysops may also find Repeat downloading useful when picking up echomail
     from a large hub.  If more than one packet is downloaded, you will find
     them in the form <packet-id>.QW0, <packet-id>.QW1, etc.

     If you select 'y', 'p' or 'r', and are set up for a Qmail v3/4 door, you
     will be asked if you wish to scan ALL conferences.  At release of The
     Liberator v2.3 this was only available in the Qmail v3/4 doors, and it
     causes every conference on the BBS to be scanned for messages, and not
     just the ones you configured in the door.  Answer 'y'es if you want ALL
     conferences scanned.

     'Custom Command[s] 2' is similar to Custom Command[s] 1, except that if
     a ProDoor is defined in the CFG, the Custom Command[s] will be executed
     in ProDoor instead of on PCBoard.  This allows you to take advantage of
     ProDoor's enhanced commands.  If no ProDoor is defined, the command is
     sent on PCBoard.  As with Custom Command[s] 1, you can also specify a
     SALT script to execute in this option.  The MakeList script, included
     with The Liberator, is an example of what can be done with these Custom
     Commands and secondary SALT scripts.

     'Upload List' is the drive, path, and filename of a Liberator Upload
     List.  If a list is specified here, all valid files on the list will be
     uploaded to the BBS, including entering the description for the file.
     These lists are quite simple to create, and when you are ready to do so,
     please refer to the 'File Transfers' section later in this manual.

     'Download List' is similar to the Upload List option above, but the list
     consists of names of files to download.  When you are ready to create a
     Download List, please refer to the 'File Transfers' section, and the
     section 'Creating a Download List using LIST.COM'.

     'ProBank Deposit' is where you set the number of minutes to deposit in
     ProBank, if available.  The deposit takes place after all other jobs are
     complete.  When you set a deposit, you can enter more than your
     available time to deposit all your time if you wish.  The Liberator will
     take your remaining online time and adjust the deposit to leave the
     number of minutes you set in the 'Online time to leave' item in the
     Configuration.  Normally this is 5 minutes, which leaves enough time to
     get into the door and take some more time out.

     'Disconnect' controls whether you want to log off, or stay connected
     when the Command File completes.  You can also set this option to
     disconnect, then exit to DOS if desired by entering 'e' (Exit to DOS). 
     If set to No, to remain online, when the Command File completes The
     Liberator will page you with an alarm every 10 seconds until you return
     and hit a key.  If you don't return within about 3-5 minutes, the BBS




     The  L i b e r a t o r  v2.32                    Command Files - Page 31
     
     

     will timeout and break the connection.  Again, set this item to 'No'
     now, so that just a logon will performed, and will leave you at the
     PCBoard prompt.   
     What you should have now is a Command File that does nothing but log
     onto the BBS (specified by 'Configuration File'), open a Capture File,
     then stay connected to allow you to carry out whatever you want to do:
     basically a logon script that opens a capture file.

     Hit <Enter> to save it, and create a name that will remind you of what
     the Command File does.  For example, if the Configuration File was
     called 'BBS', you might type in 'BBSLOGON', or BBS-ON as the name.  The
     file will then be saved in your Script directory as <name>.CMD, where
     <name> is the name you entered in the window.

     That's it!  You have now created a Command File, which specifies the
     jobs you want done, and a working BBS Configuration (actually this
     largely depends on your Sysop and the prompts on your BBS) which
     specifies which PCBoard you want the Command File to execute on.  You
     can now create as many of these Command Files as you want for this BBS,
     by selecting Create from the main menu, and entering the number of the
     BBS Configuration we created above.

     6.1  Running Command Files

      To run Command Files, the one we just Created for example, simply type
      the number beside the name you want to run.  Run your logon Command
      File now by typing its number.  If you receive a message that the
      program was not able to recognize any prompts, please see the section
      on Configuring Prompts below.  You can also start The Liberator and run
      Command Files when already connected, but you must get to one of the
      eight 'key' prompts first (the key prompts are signified by an asterisk
      following the prompt description, in the Configuration).  

     6.2  Command File Abort Codes

      The Liberator was designed to handle many errors that occur during the
      operation of a Command File, and can normally salvage a session even if
      errors occur, but sometimes it is necessary to abort the Command File
      and log off the BBS.  If this happens, a message will be printed on the
      screen (which can be read from the capture file or by using the Telix
      <Alt-B> 'Scrollback' command before leaving Telix) along with a number
      in brackets, called an 'Abort Code'.  All abort code values and their
      meanings and possible remedies are listed in the section 'Abort Codes/-
      Remedies' at the end of the manual.

     6.3  Pausing Or Manually Aborting Command Files

      To pause a Command File, hit the <Esc> key.  A menu box will then
      appear called the Control Menu.  From here you can carry out a number
      of tasks, or select option 1 to abort the Command File.  The Liberator
      does not just dump you back to terminal mode immediately when you
      abort, but will first take care of any details that need cleaning up;
      such as message reply packet maintenance, or adding the SESSION.TXT




     The  L i b e r a t o r  v2.32                    Command Files - Page 32
     
     

      file to your QWK packet (both of these tasks normally takes place
      offline, after the Command File completes).  As well, any system
      variables such as the default colors, Upload/Download directories are
      put back at their proper values.  The Usage and Capture files are
      purposely not reset however, to allow the remainder of your session to
      be recorded in the same files.  These files should be closed manually
      when you disconnect.

     6.4  Creating New Command Files

      The main menu Create option is used to create new Command Files (and
      Configurations if necessary).  When you are ready to create a new
      Command File, select Create then simply select the BBS Configuration
      you wish to use from the menu.  There is no need to create a new BBS
      Configuration each time you want to set up a new job.  As many Command
      Files as desired can be created for an existing Configuration.  To
      create a new Configuration, select Create, then enter '0' (or hit
      <Enter>) from the Configuration menu.

     6.5  Editing Existing Command Files

      The main menu Edit option is used to modify or view an existing Command
      File (or Configuration File as explained in the Configuration section). 
      To edit a Command File, select Edit and simply enter the number beside
      the file of your choice.  You can clone Command Files in the same
      manner as Configurations, by Editing an existing file and just saving
      it under a different name.

     6.6  Deleting Command/Configuration Files

      The main menu Delete option is used to delete any Command File, and its
      accompanying Configuration as well if necessary.  You can also delete
      these files right from DOS if you like, by switching to your Script
      directory (or Command/Configuration directory if defined) and using the
      DEL command.  Make sure you don't delete a Configuration if other
      Command Files are set up to use it, or these Command Files will be
      unusable.

     6.7  Renaming Command/Configuration Files

      The main menu reName option (selected with 'N') is used to give a
      Command and/or Configuration File a new name.  Simply enter the new
      names when prompted.  To rename the Configuration only, hit <Enter>
      when prompted for a new Command File name, then enter the new name for
      the Configuration.  The name will also be updated inside the accompany-
      ing Command File, but other Command Files that used the old name will
      not be updated and should be changed manually if necessary.




     The  L i b e r a t o r  v2.32          Liberator Configuration - Page 33
     
     

              7.  LIBERATOR CONFIGURATION (Tools 'Configure' option)


     'Master redial attempts' is the same as the redial attempts you entered
     in the BBS Configuration, but this number is used for the queue when the
     'Master' is running (discussed below).

     'Display Command File Delay' is used to display what the Command File is
     about to carry out, to give you a chance to abort.  You may increase or
     reduce the 10 second default here.

     'Qmail Packet Renumbering Type' is only of interest if you are using a
     Mail Door.  The Liberator can maintain (renumber) your packets in two
     ways: by placing the numbers in the <packet-id> portion of the filename,
     or in the file extension (QWK/REP).  This is where you can change the
     method used, if desired.

     'Text Editor' is the drive, path, and filename of your text editor. 
     What is a Text Editor?  A Text Editor is a very common tool, much like a
     word processor, but used to create 'DOS text files' (sometimes called
     ASCII files), such as BAT files, and even files like this document. 
     Text files can be read from DOS with the TYPE command, and do not need
     to be loaded into a special program like a word processor to be printed
     or viewed.  The Liberator expects your File Lists (used for upload-
     ing/downloading) to be in 'text file' format: without word processor
     formatting codes.  If you don't have a Text Editor, perform a Z)ippy
     scan on your BBS in the appropriate conferences (e.g. "Z EDITOR A" or
     Z)ippy scan, for EDITOR, in All areas).  There are many good Shareware
     editors available.  The Liberator uses the editor defined here to allow
     you to edit File Lists from within the program.

     'Command File Directory' is initially set to your Script directory, but
     if you prefer to keep this directory uncluttered, you can tell The
     Liberator to put your Command Files elsewhere.   Define the drive/path
     of any valid directory here.

     'Configuration File Directory' is the same as above, but for your BBS
     Configurations.

     Type <Alt-S> to save any changes you made, or <Esc> to exit, when
     finished with this screen.




     The  L i b e r a t o r  v2.32                  Custom Commands - Page 34
     
     

                          8.  SETTING UP CUSTOM COMMANDS


     Custom Commands allow you carry out jobs on PCBoard or in ProDoor that
     are not supported internally by The Liberator.  They are something like
     the macros you assign to keys in Telix, but are more powerful, and more
     oriented to PCBoard.  You can use Custom Commands to capture and
     download messages from systems without a Mail Door, or to carry out some
     PCBoard/ProDoor jobs that are not supported internally by The Liberator. 
     You can also capture the results of PCBoard/ProDoor commands to a user-
     defined capture file by executing the example CAPCMD.SLT script from a
     Custom Command, or for more advanced capture, the MakeList script
     included with The Liberator.

     There are two types of entries you can make in the 'Custom Command[s] 1'
     (to save some typing, I'll call this 'CC1') and 'Custom Command[s] 2'
     ('CC2') items of a Command File.  The first requires that you know a
     PCBoard or ProDoor command, or multiple commands (some examples are
     given below, if you don't).  In this case, you enter the PCBoard/ProDoor
     command in CC1 or CC2  pretty much the same as you would enter them on
     PCBoard.  The Liberator sends the defined command[s] when you run the
     Command File.

     The second type of Custom Command entry requires you to have a Telix
     script that does the job you want done (such as the MakeList script, or
     one of your own), and in this case you enter the script's name in CC1 or
     2 preceded by the '@' character, as in a Telix macro.  The @SCRIPTNAME
     may be followed by 'parameters', as outlined below.

     8.1  Defining a PCBoard or ProDoor Command

      To have a PCBoard command carried out, simply enter the desired command
      in CC1 or 2.  To have a ProDoor command carried out, you must define
      the command in CC2 and make sure a ProDoor is defined in the BBS
      Configuration being used (the Custom Command help screen will tell you
      to enter a 'ProDoor' command if a ProDoor is defined in the Configura-
      tion).  CC1 is always carried out on PCBoard, but The Liberator will
      OPEN the ProDoor first for CC2, if a ProDoor is defined in the BBS
      Configuration being used.  If no ProDoor is defined, CC2 is carried out
      on PCBoard.

      You should 'stack' your commands where possible, but you can also embed
      the command with <Enter>s (Carriage Return, or CR for short) if
      necessary.  Command stacking means that you enter all command options
      on one line.  For example, on PCBoard you can carry out a Zippy scan by
      typing a 'Z' then hit <Enter> and enter the text you want to scan for,
      hit <Enter> again then enter the file areas to scan, and hit <Enter>
      once more... then type NS (non-stop) and hit <Enter> again if the
      'More' prompt comes up.  Or you can enter the whole shot on one line:

      Z <text to scan for> <file areas> NS




     The  L i b e r a t o r  v2.32                  Custom Commands - Page 35
     
     

      This is how you should do it whenever possible in a Custom Command.  If
      you must use <Enter>(s) in your command, you may specify them right in
      the command as a control character (<Enter> is Ctrl-M).  To specify any
      control character, precede the character with a caret (^).  <Enter>
      would be ^M, which is made up of TWO characters (^ and M) and not by
      holding down the Ctrl key and hitting M.  You can also cause half
      second delays within the command entry if necessary by using a tilde
      (~).  Two tildes equal a 1 second pause.

     8.2  Sending More Than One Command

      Use the vertical bar (|) to separate full commands.  If a vertical bar
      is encountered, a CR (<Enter>) is automatically sent and The Liberator
      pauses until it one of the eight 'key' prompts defined in the BBS
      Configuration appear.  You needn't specify ^M before a vertical bar
      unless you actually want two <Enter>s sent.

     8.3  Automatically Handled Prompts

      While sending the commands you define, or while waiting for one of the
      eight key prompts, the following prompts are automatically handled by
      The Liberator, if encountered:

      Prompt             Defined on CFG Screen         Response
      More (PCBoard)               2                   NS   (non-stop)
      Scan Message Base            2                   N    (no)
      Pause                        2                   ^M   <Enter>
      ProDoor More                 3                   NS   (non-stop)

      This is useful in case you forget to specify 'NS' (non-stop) in your
      command, or if you use a J)oin conference command and the 'Scan message
      base' prompt appears, etc.  Note that the final command must eventually
      finish at one of the eight 'key' prompts, or The Liberator will not be
      able to start the next job.

     8.4  Some Useful Commands

      The below commands are for use in CC1 or 2, and should be executed on
      PCBoard v14, or inside a ProDoor where specified.

      To carry out file oriented commands (commands which normally produce
      filenames such as F)ile Directories, N)ew Files, L)ocate, or Z)ippy
      scans), precede the command with "@MakeList <listname>" to have the
      MakeList script capture all the resulting files, remove extraneous
      text, and place the result in <listname>.  <Listname> can then be used
      for downloading in the same session, or saved for later use.  MakeList
      also allows you to send commands repeatedly in a number of conferences. 
      See MAKELIST.DOC for more info and some examples... it is a powerful
      external command and is worth looking into.

     J <conf>| Precede any of the below commands with this to J)oin a
               specific conference first (note the vertical bar is used as a
               command separator).  If sending the command in ProDoor, or if




     The  L i b e r a t o r  v2.32                  Custom Commands - Page 36
     
     

               conference NAMES are supported on your PCBoard, you may also
               use the name (e.g. 'IBM' instead of '2').  For example: "J 2
               Q|R S D" joins conference 2 (note the 'Q' for 'Quiet mode'
               which suppresses the NEWS bulletin) then sends a message read
               command as explained below.

     For the below commands to work properly, Zmodem must be your default
     PCBoard protocol (set with the PCBoard T)rans. Protocol command), and
     you must have auto-Zmodem downloads turned on in Telix.  This is due to
     the fact that Zmodem downloads start automatically.  The Liberator will
     not start other types of transfers, when requested from Custom Commands.

     R S D     Read all messages Since the last message read in current
               conference only, then Download the result.  The file contain-
               ing the messages will be placed your Download Directory as
               defined in the BBS Configuration. [Note: You may substitute
               the 'D' with a 'Z' on PCBoard 14.5 and above, to have the
               message file compressed before the transfer starts.

     R Y S D   Same as above, but selects only mail addressed to you.

     R F Y S D Same as above, but selects messages left by you as well.

     R A D     Read all messages above the last message last read, in All
               conferences selected, then Download the result.  Substitute
               the 'S' in the commands above with an 'A' to scan All
               conferences selected, instead of just the current conference.

     ZIPM A|D Z S   To get the extended conferences (older PCBoards
         support only a limited number of conferences), use this ProDoor
         command in CC2 to ZIP (compress) messages in all selected conferen-
         ces, then Download.  Substitute the 'A' after the ZIPM (stands for
         All selected conferences) with specific conference names/numbers, if
         desired.  E.g.  ZIPM 1 5 LIBERATE|D S Z scans only conferences 1, 5,
         and LIBERATE.

      The below commands are better suited for use with the CapCmd script
      (explained below) that was included with The Liberator, but you can use
      them directly as well.  You may also precede the commands below with J
      <conf>| to Join a specific conference (e.g. J 2 Q|B 2 5 NS):

     B 2 5 NS  Read bulletins 2 and 5 in NonStop mode.  You should have a
               Capture File defined in the Command File when this command is
               used, then simply read the capture file when offline.  To have
               the bulletins placed in a specific file, use the @CapCmd
               command, as outlined below.

     NEWS NS   Re-displays the conference NEWS file in NonStop mode.  This
               can be useful if you J)oin a conference in Quiet mode or if
               you used The Liberator's 'Conference to Join at Startup'
               option, which also uses Quiet mode and suppresses the NEWS
               display.




     The  L i b e r a t o r  v2.32                  Custom Commands - Page 37
     
     

     I NS      Display I)ntial welcome in NonStop mode.  Shows the PCBoard
               version number, and usually contains the board's technical
               info and system phone numbers.

     8.5  Running Other Telix Scripts

      If using the above method of entering the command directly isn't
      appropriate or possible, you can also call a SALT script for more
      complicated jobs.  A couple of example scripts were provided for this
      purpose, and will show you how to get started to create your own simple
      scripts (also see the SALT tutor (SALT.DOC) included with The Lib-
      erator).  SALT is not complicated at all, if you ignore the advanced
      features and make use of the simpler ones.

      To have a script executed from a Custom Command, simply precede the
      scripts' filename with '@' (e.g. @SCRIPTNAME).  Note that the extension
      of the script is not necessary if .SLC is used.  To call the compiled
      CAPCMD.SLC script, you would use @CAPCMD in a Custom Command.

     8.6  Passing Parameters To Scripts

      As well, you can pass 'parameters' (command line options) to the script
      if it is set up to accept them.  The Liberator separates the rest of
      the Custom Command line after the @SCRIPTNAME into two portions. 
      Portion one (parameter 1) is the first 'word' after @SCRIPTNAME, up to
      the next space.  This is normally used for filenames, since they don't
      contain spaces.  Portion two (parameter 2) is the rest of the line
      after the space following parameter 1.  Example:

      @SCRIPTNAME <parm1_nospace> <parm 2 remainder of line>

      The CapCmd script included with The Liberator takes two command line
      parameters like so:

      @CapCmd <capfname> <command to send>

      <capfname> being the name of the file you want to use as a temporary
      capture file, and <command to send> being the actual command to send to
      PCBoard/ProDoor.  For example, to have this script capture bulletin 6
      to the file C:\TEMP\B6.CAP, you would use the following Custom Command:

      @CapCmd C:\TEMP\B6.CAP B 6 NS

      Or to capture another conference's news file to a file on drive B:
      called NEWS1.CAP, the Custom Command could be defined like so:

      J 1 Q@CapCmd B:NEWS1.CAP NEWS NS

      As you can see above, @SCRIPT need not be the first item in a Custom
      Command.  However, @SCRIPT must always be the last item, since any text
      following the script name is separated into parameters, and passed to
      the script.  Note that no '^M' or '|' followed the J 1 Q command above
      (^M means <Enter>, | means <Enter> then wait for a 'key' prompt).  This




     The  L i b e r a t o r  v2.32                  Custom Commands - Page 38
     
     

      is because when '@' is not the first character in the Custom Command,
      it causes the same effect as a vertical bar, or in other words <Enter>
      is sent, then we wait for a key prompt before starting the script.

      Note that CapCmd does NOT automatically handle the prompts outlined
      above, so make sure you specify Non Stop (NS) in your commands.  CapCmd
      also does not interpret the special characters ^ ~ @ | as The Liberator
      does.

     8.7  Replaceable Parameters?

      These are very simple and useful.  You can replace either parameter 1
      or 2, when passing parameters to any script, with:

      %u  (or %U) which The Liberator then substitutes with the name entered
          in the 'Upload List' item of the same Command File.  Whatever name
          is in 'Upload List' is then passed to the script.  If nothing at
          all is defined in Upload List, then a default name is created in
          the form <cmd_file_name>.UL.  The actual name of the Command File
          replaces <cmd_file_name>, .UL stands for Upload List. (E.g. if
          executing BBSCAP.CMD, the name BBSCAP.UL is used if %u is used as a
          parameter and no Upload List is defined in the Command File).
      %d  (or %D) is substituted as above, but with the name defined in the
          'Download List' item.  If no Download List is defined, a default
          name is created as outlined above, but with the extension .DL (for
          Download List).

      Example: @MakeList %d N S A NS

      The above would call the script MAKELIST.SLC, sending the name of the
      current Download List, and the command "N S A NS".  Replaceable
      parameters can be used when passing parameters to any script.  They are
      useful when the actual name of the Up/Download List isn't known when
      you define the Custom Command... for example, if the Up/Download List
      item is set for interaction with a question mark.

     8.8  External Script Return Values - IMPORTANT

      The return value of a called script (sent via the SALT return()
      statement) is significant, and is tested by The Liberator.  If 0 or 1
      is returned, the Command File will continue with any other defined
      jobs, as usual.  Any other value signifies to abort, and causes the
      Command File to abort disconnect.  This can be useful when programming
      your own scripts, as you will be able to 'tell' The Liberator to abort
      the Command File via a return(2); return(3); return(-2); etc.  You can
      tell The Liberator all went well by either not using a return at all,
      or by using return; return(0); or return(1); from the main().  The
      value -1 should never be returned via the return statement, as in SALT
      this signifies that the called script was not found, or there wasn't
      enough memory to load it.

      Whatever value is returned from scripts called via Liberator Custom
      Commands is stamped in the usage log, for later reference.




     The  L i b e r a t o r  v2.32                   File Transfers - Page 39
     
     

                                9.  FILE TRANSFERS


     The Liberator can transfer files in any of six ways, depending on the
     BBS.  The slow, plain old PCBoard uploads and downloads are supported on
     any BBS, and will be used where nothing else is available.  PCBoard
     'batch' uploads and downloads can be taken advantage of for extra speed,
     if your BBS supports them.  Batch transfers are discussed in the
     sections 'What are Protocols?' and 'Setting Up PCBoard'.  As well,
     ProDoor batch uploads and downloads can also be carried out, if your BBS
     has a ProDoor.  You can even have The Liberator count the number of
     files on your lists and make a decision whether to OPEN the ProDoor, or
     carry the transfer out on PCBoard.

     9.1  Sending Files (Uploading) To PCBoard

      To have file uploaded, you create a list of filenames with your Text
      Editor (Text Editors are described above in the section 'Installing The
      Liberator', if you don't know what they are), by typing the filename
      and description in, pretty much as you would do when you were on
      PCBoard.  Each file you want to upload is specified along with a
      description on the SAME line.  One file/description per line.  For long
      multi-line descriptions, if supported on your BBS, you may enter up to
      500 characters per line... but do not use more than one line per
      description.

      There is no limit as to the number of files you can place on your File
      Lists.  The Liberator will transfer as many files as you have time for,
      and will automatically remove files from your list after the transfer
      is carried out successfully!  Any files that are not transferred are
      left on the list for next time (sometimes The Liberator 'comments out'
      lines in your list... this is explained below).  A line from an Upload
      List might look like this:

      LIB232.ZIP The Liberator PCBoard Automation System.

      This line would cause The Liberator to search in the defined Upload
      Directory (defined in each Configuration on screen 1) for the file
      LIB232.ZIP, and if found, the upload request is sent to the BBS.  If
      the BBS gives the okay, the description "The Liberator PCBoard
      Automator for Telix." is entered, and the transfer is started when
      prompted.

     9.2  Comments On File Lists (//)

      Lines can also be 'commented out' of your list, which means they are
      ignored, by using two forward slashes (//) at the beginning of the
      line.  You may use this feature to place permanent comments in your
      lists, or to temporarily remove filenames without actually deleting the
      line from your list.  The Liberator itself sometimes inserts "//
      (error)" at the beginning of a line to comment out a file, depending on
      the error that occurred when attempting the transfer. (Error) is
      substituted with the actual reason that the line was commented out. 




     The  L i b e r a t o r  v2.32                   File Transfers - Page 40
     
     

      Comments remain on the list permanently, and should be removed manually
      when necessary.  Lines that start with a space, or a vertical bar (|)
      are also treated as comments, but these lines are removed from the list
      when encountered.

     9.3  Optional File List Items (Switches)

      You can also add other items to each line if you have special needs,
      such as joining specific conferences, specifying an upload or download
      password, or if you don't want the line removed from the list when the
      transfer is successfully carried out.  As well, you may specify a drive
      and/or directory path if the file is not located in your Upload
      Directory as defined in the BBS Configuration being used.  The full
      format for each line is:

      [/u-|/d-pass][/#nnn][/P] [d:][\path\]FILENAME[.ext] <Description> 

      The items in square brackets simply denote optional items, and the
      square brackets should not actually be included if you use these items. 
      The vertical bar (|) means to use one or the other (either a /u-pass or
      /d-pass... subtitute 'pass' with a password).  The filename must be
      separated from other items on the line by at least one space.  Switches
      may appear in any order, and can be separated by a space if desired,
      but '/' must be the *first* character on the line for switches to be
      recognized.  Switches must precede the filename, or they will not take
      effect, and will be considered as part of the <Description>.  All of
      the optional items are explained below, in the same order as they
      appear on the line above.

     9.4  Specifying Upload or Download Passwords (/u /d)

      Some PCBoards require entry of a specific password before uploading or
      downloading.  If a specific file, or all files on your File List
      requires the entry of a password in order to send or receive the file,
      use the /u switch for Upload passwords, or the /d switch to specify
      Download passwords.  When the switch is found, the password following
      the switch stored in memory and will be entered if the 'Password'
      prompt, defined on CFG screen 2, appears when entering a filename.  Any
      character other than a space or tab may be used to separate the switch
      from the password (/u=pass /u:pass, etc.)  Use whichever character you
      prefer.

     9.5  Joining Specific Conferences (/#nnn)

      '/#nnn' is an optional conference to join before uploading the file. 
      Substitute 'nnn' with the actual conference number. Conference NAMES
      may also be used if supported where you are performing the transfer.
      ProDoor supports conference NAMES, and some newer PCBoards do as well
      (e.g. /#IBM).  All files below, and including the line with the /#
      switch are uploaded to the specified conference (you need not specify
      the switch again, until you want to join a different conference).  If
      you ALWAYS join a specific conference before uploading or downloading
      files, rather than place a /# in your File List each time, specify the




     The  L i b e r a t o r  v2.32                   File Transfers - Page 41
     
     

      conference in the 'Conference to Join at Startup' option on CFG screen
      1 of the appropriate Configuration.

      Once a /# switch is used, The Liberator keeps the current conference in
      memory, and will not re-join the same conference if the same switch is
      specified again, while still in this conference.  As well, the con-
      ference is not joined until a valid filename is found on the list.  If
      /# is specified, and no valid filenames follow, the conference will not
      be joined.

     9.6  Making File List Items Permanent (/P)

      The '/P' switch causes the line on which it is found to be 'permanent'. 
      Usually, once a file is successfully up/downloaded, the line is
      automatically removed from the list to avoid duplicate up/downloads the
      next time the list is used.  Other switches, and lines starting with a
      blank (space or tab) or (|) are also normally removed when encountered. 
      To override this, use the /P switch, and the line will remain on the
      list.  This can be useful when you wish to upload the same file, using
      the same File List, to multiple BBS's, or keep a switch permanently on
      your list (e.g. /#2 /P).  /P can be used for Download Lists as well. 
      Note that lines starting with the comment switch (//) also are con-
      sidered permanent, and must be removed manually.  Comments may also be
      placed after other switches:  /u-Mypassword // This is a comment.

     9.7  Using Switches On Separate Lines

      All the switches listed above can be used by themselves on a line which
      does not specify a filename, if desired.  As mentioned above, the /u
      and /d switches are read then stored in memory for use if the 'Pass-
      word' prompt appears.  When a /# switch is encountered it is stored in
      memory and will take effect for the next valid file.  The /P switch, if
      used without a filename causes the current line, along with the current
      conference, to remain on the list.  For example:

     /#2
     // (file not found) FILENAME.EXT This file was removed earlier
      This is an invalid line because of the leading space
     /u=up-password // This is the upload password
     /P
     NOEXIST.ZIP File does not exist
     | This line is ignored because of the vertical bar

      If the above were your entire Upload List, conference 2 would not be
      joined since no valid filenames follow the request.  Only once a valid
      filename was found, would conference 2 be joined.  The /P switch, if
      specified on a line without a filename, causes the current conference
      to be placed permanently on the list, at that position.  Once The
      Liberator had processed the above Upload List, it would look like this:

     // (file not found) FILENAME.EXT This file was removed earlier
     // This is a comment (lines starting with // are never removed)
     /u=up-password // This the upload password




     The  L i b e r a t o r  v2.32                   File Transfers - Page 42
     
     

     /#2 /P
     // (file not found) /#2 NOEXIST.ZIP File does not exist

      Note how the current conference is also placed with a file, if it
      removed with an // (error).  This occurs with any file that is removed,
      to ensure that the proper conference is not lost, should you rearrange
      the list later.

     9.8  Specifying A Drive/Directory

      [d:][\path\]FILENAME[.ext] is an optional drive, path and extension,
      which can be specified for any file on your Upload List, if the file is
      not located in the Upload Directory specified in the Configuration.  If
      the file is not found in the directory specified, The Liberator will
      then search the defined Upload Direcory, and upload the file if it is
      found there.  No particular extension is assumed, and if you do not add
      an extension, The Liberator will simply add a period (.) as the
      extension.  The . is added since ProDoor usually adds a 'default'
      extension [.ZIP, etc.] if no period follows the filename, which may
      cause an error locating the file.

     9.9  Upload Descriptions

      <Description> should be replaced with a description of the file you are
      uploading.  When online, The Liberator enters the description character
      by character, just as if you were typing it yourself (but perhaps
      faster).  The description isn't typed in as fast as other respones,
      since The Liberator pauses (for 1/10 of a second) and checks whether
      the description has 'overflowed' after entering each character.  If you
      are performing the upload in ProDoor, or on a PCBoard that supports
      multi-line upload descriptions, don't concern yourself with what text
      will end up on what line.  The BBS itself will take care of this using
      'word wrapping' within the margins, much like your word processor does. 
      The Liberator simply enters all the characters you give in the descrip-
      tion (the entire description MUST be specified on the same line in your
      Upload List... up to 500 characters per line are permitted), and the
      BBS takes care of line-wrapping.  You may force text to the next
      description line by using ^M (two characters... ^ and M) in your
      description.  It is *not* necessary to use ^M's to move to the next
      description line though.

      When creating your Upload List, if your text editor keeps wrapping your
      descriptions to the next line, look for a way to set the margins.  Set
      the margins to 0 left 500 right if possible, or simply to the maximum
      width within 500 characters.  The description you give must be at least
      15 characters in length, or The Liberator will not attempt the upload,
      and will automatically 'comment out' the line from your list.  The
      minimum description limit on PCBoard was 10 characters at release date,
      but ProDoor has a minimum of 15 so I used this number to keep things
      consistent (PCBoard usually follows ProDoor in any case, and will
      probably increase its 10 char. minumum in the future).




     The  L i b e r a t o r  v2.32                   File Transfers - Page 43
     
     

      If the description is too long and overflows (each BBS may be set up to
      accept a different number of characters for a description), The
      Liberator will stop sending characters and attempt to backspace over
      any that overflowed.

     9.10  Backup Lists

      Before your original File List is modified, it is copied to a file of
      the same root name, but with the extension .BAK.  For example, if the
      Upload List was called TEST.UL, you could find the list in its original
      condition in TEST.BAK.  This also applies to Download Lists.

     9.11  Demonstration Upload List

      To demonstrate how to upload to a BBS, I'll assume you found a PCBoard
      that doesn't have The Liberator v2.32 in its library, and that you want
      to help me distribute the program, so are going to have the program
      automatically upload itself (how's THAT for assumptions...).

      An Upload List to automatically upload The Liberator was provided, and
      will also use multiple-line descriptions if available on the BBS.  All
      you have to do is 'Create' or 'Edit' a Command File from the main menu
      and include the name LIB232.UL (and drive/path if not in the current
      directory) in the 'Upload List' option of the Command File.  Of course,
      before use it does require you to have the file LIB232.ZIP in your
      Upload Directory.  Sorry about that... it's one of the things I
      couldn't take care of automatically.

      For example, assuming the Upload List itself (LIB232.UL) was in the
      C:\TELIX Directory, you would enter "C:\TELIX\LIB232.UL" (without the
      quotes) in the Upload List option of an appropriate Command File, then
      copy LIB232.ZIP into your Upload Directory.  The Upload List can then
      be used as many times as necessary, since the /P switch is specified
      along with the filename.  Load the file LIB232.UL into your Text
      Editor, and set the margins to 0 left 500 right (or as wide as
      possible) to edit the file, if necessary.  Some further instructions
      and information were placed directly in the file, to help you get
      familiar with automated uploading.

     9.12  Telix Batch Upload Limitation

      Note that when performing batch uploads, each filename in the batch is
      separated by a space, and passed to Telix on one line in order to carry
      out the upload itself (e.g. FILE1.ZIP FILE2.ZIP FILE3.ZIP).  However,
      from SALT scripts, there is a limit of 64 characters for the entire
      batch of filenames.  This means that only about 3 or 4 filenames can be
      specified at once for batch uploads... enough filenames to fill the 64
      character limit.  You needn't let this concern you, since The Liberator
      keeps track of how many characters are already in this line, and will
      stop entering names and transfer the batch when a filename is too big
      to fit within the 64 character limit.  A new batch is then started
      until filenames fill up the 64 character limit again.  This continues
      until the list is complete or you run out of time.  The 64 character




     The  L i b e r a t o r  v2.32                   File Transfers - Page 44
     
     

      limit is mentioned only for your interest, in case you wondered why not
      as many files are entered in a batch when uploading.

     9.13  Receiving Files (Downloading) From PCBoard

      Downloads are performed much like uploads, but a description need not
      be entered along with the filename.  Any characters following the first
      space after the filename are ignored in Download Lists.  The same
      switches apply for joining a conference, or specifying permanent lines,
      as outlined above for Upload Lists.  Use your Text Editor, the MakeList
      script, or a program that copies lines from one text file to another,
      such as Vernon Buerg's LIST.COM, to create your Download Lists.  Once
      the list is created, you simply supply the list's location/filename in
      the 'Download List' option of any Command File to have the downloads
      carried out (e.g. C:\TELIX\DOWNLOAD.LST)

     9.14  Using LIST.COM to create Download Lists

      If you obtain, or are currently using Vern Buerg's LIST v6.4a or
      greater, you can read PCBoard file listings quickly and easily -- and
      create a Liberator Download List at the same time.  Complete file
      listings can be downloaded from most BBSes, and contain all the files
      in a specific file area, or all the files on the BBS.  As well, Mail
      Doors such as the Qmail Door can be set up to send new files listings
      along with a message packet.  In Deluxe, you use the A)rchive New Files
      command to save the entire new files list to a file called <packet-
      id>.NEW, which can be browsed with LIST to create a Download List.  You
      can also use the MakeList script along with a F)ile Directories, N)ew
      Files, L)ocate, or Z)ippy Scan command to capture file listings (see
      MAKELIST.DOC for info).

      With LIST, you can view PCBoard listings using the up/down arrow,
      PgUp/PgDn, Home/End cursor keys.  Then, when you see a file you want to
      place on your Download List, mark the line by moving it to the top of
      the screen then hitting <Alt-M>, or the bottom of the screen then
      hitting <Alt-B>.  If several consecutive lines are to be marked,
      perform a second <Alt-M> or <Alt-B> on the last line in the series. 
      Marked lines will be marked in reverse video.

      Then dump the line(s) to your Download List by typing <Alt-D>.  For the
      first line(s) dumped, you must enter the name of your Download List
      (LIST always prompts for a filename when <Alt-D> is pressed).  From
      this point on, you then use <Alt-O> to dump, which means to 'dump to
      the last filename used'.  Using this method will ensure that, a) the
      filename is spelled correctly and, b) that the file actually exists on
      that board.  Not to mention that it is easier than typing the names
      manually!




     The  L i b e r a t o r  v2.32                 Using The Master - Page 45
     
     

                               10.  USING THE MASTER


      The Master itself is very simple.  It's just a list of Command File
      names that you create with Add and Remove on the main menu.  This list
      is processed by the RunMaster script to run multiple Command Files in a
      number of different ways.  The Command Files defined on the Master list
      can be executed on the same BBS without disconnecting, for a 'linked'
      type job, on a variety of BBS's, without intervention.  The Master is a
      very powerful feature if used to its full extent.  Some example
      scenarios and uses for the Master are covered below.

     10.1  Creating a Master

      First, you must have at least two Command Files that actually do
      something.  The Master does not accept interactive options (they are
      automatically turned 'off' when the Master is running, and does not
      allow a Command File to remain online at completion, so you can't use
      the logon script we created above since, with disconnect enabled, it
      doesn't do anything but logon then logoff...  The reason interactive
      options are automatically disabled, and disconnect enabled, is that it
      is assumed you will not be present when you run the Master, and thus
      would not be able to provide input for these items.  If you plan to be
      present, you may simply select the Command Files from the Command File
      Manager.

      If you don't yet have at least two Command Files setup to do real jobs
      then you aren't in need of a Master yet and can return here later.

     10.2  Using the Add Option

      The main menu Add option is used to create or add to the Master.  When
      you select Add, you can add one of four things: a Command File, a Delay
      time, an EXIT command, or a REPEAT command.

      To add a Command File, simply type its entry number as displayed on the
      menu.  To add a Delay time, which allows you to pause execution of
      specific Command Files until a specific time, enter a 'D', then enter
      the desired time.  The time is expected in 24 hour format, so 00:00 is
      midnight, 12:00 is noon, and you just add 12 to PM times (e.g. 1pm + 12
      = 13:00).  To enter an EXIT command, which causes The Liberator to exit
      to DOS thereby ending execution of the Master list, enter an 'E'.  To
      enter a REPEAT, which causes all Command Files to be placed back in the
      queue (explained below) and the list to be re-started, enter an 'R'.

      Once you choose what you wish to Add, all these items can be placed at
      any position on the Master list.  When you enter your selection, you
      will be prompted to hit <Enter> to append the selected item, or <Alt-I>
      to insert it at another position.  If you hit <Enter>, the item is
      added to the end of the Master.  If you hit <Alt-I> (Insert), the
      Master is displayed and you are asked which position to insert the item
      into.  If you type a number, the item is placed into that entry, and
      other entries are pushed down by one entry.




     The  L i b e r a t o r  v2.32                 Using The Master - Page 46
     
     

     10.3  Using the Remove Option

      To remove any item on the Master list, select the main menu Remove
      option.  Once selected, the Master will be displayed and you simply
      enter the number beside the item you wish to remove.  You then have the
      option of removing a sequence of entries, or just the one entered.  Hit
      <Enter> to remove just the one entered, or type another number and all
      entries between and including the numbers entered will be removed.

     10.4  Running the Master

      You can run the Master in two ways.  From the Command File Manager,
      simply select entry '0' as you would to run a Command File.  You may
      also execute the RunMaster script directly as you would run any other
      script: type <Alt-G> then enter RUNMASTR from within Telix, or simply
      type RUNMASTR from DOS to execute the RUNMASTR.BAT file that was
      created by the installation program.  Note that RUNMASTR.BAT simply
      types in "Telix sRunMastr" for you.  You can run any Telix script from
      DOS in this manner, by preceding the script name (in this case,
      RUNMASTR.SLC), with the letter 's'.  The .SLC extension is assumed by
      Telix and isn't necessary.

      When RunMaster starts, it will display the Master list and prompt you
      for an entry number to start at.  If you don't enter a response within
      15 seconds (if you aren't present), or if you hit <Enter>, the Master
      starts at entry 0 and continues until the end, or until an EXIT or
      REPEAT command is reached.  If an EXIT is reached, RunMaster ends and
      exits to DOS, or back to the calling program/batch file.  If a REPEAT
      is encountered, the Master is re-started wherever it was originally
      started.  So if you started at entry 20, RunMaster would go back and
      rerun every job from 20 back to the REPEAT.  This is useful when you
      will be away for a number of days, etc., and is normally used in tandem
      with one or more Dialing delay times.  REPEAT continues to re-run the
      jobs indefinitely, until you manually abort by hitting <Esc>.

     10.5  Using EXIT and REPEAT to Create Multiple Masters

      Since you can start the Master at any position, and since both EXIT and
      REPEAT commands cause the current Master run to end or restart when
      encountered, you can actually create many different runs using only one
      Master.  For an example of this, look at the Master below:

     0  CMD1
     1  CMD2
     2  CMD3
     3  *EXIT*
     4  *12:00*
     5  CMD1
     6  CMD4
     7  *REPEAT*
     8  CMD5
     9  CMD3




     The  L i b e r a t o r  v2.32                 Using The Master - Page 47
     
     

      There is a possibility of many different runs using the above Master. 
      If you tell RunMaster to start at entry 0 (the default), then CMD1,
      CMD2 and CMD3 are executed, then we exit to DOS, which ends the Master
      run.  If you tell RunMaster to start at entry 4, all jobs are delayed
      until 12 noon.  At noon CMD1 and CMD4 execute, then the REPEAT is en-
      countered which causes the Master to repeat at its STARTING point...
      which was entry 4: the dialing delay.  So, that's another run with CMD1
      and CMD4 being executed repeatedly at 12 noon each day.  If you start
      at entry 8, CMD5 and CMD3 are carried out, then the Master completes
      and returns to Telix, or the calling SALT script (the Command File
      Manager, or a script of your own).  As well, you could start at entry 1
      to have just CMD2 and CMD3 carried out, etc.  The possibilities are
      almost endless.

     10.6  The Master Queue

      When the Master starts execution, all jobs to be run are placed in a
      'queue'.  The queue keeps track of the Command Files that have not
      completed successfully -- initially all of them.  Each Command File in
      the queue will be dialed for the total number of attempts, as defined
      in each Configuration in the 'Redial attempts' item (0 = until connect,
      as usual).  However, rather than dialing each job for its total redial
      attempts all at once, RunMaster also adds a 'Master redial attempts',
      which causes each job to be dialied only a few times, then, if a
      connection is not established, cycle on to the next job.  The
      unsuccessful job is left in the queue to be tried again later, and the
      running total of attempts is incremented each time the job is tried. 
      'Master redial attempts' is initially set to 3, and is set with the
      'Tools' Configure option.

      Assuming the Master redial attempts is set to 3, job 1 was set to
      redial 5 times only and all others were set to '0' (until connect), the
      current time is 11am, and you started the example Master below at entry
      0, here is an illustration of how the queue behaves:

     0  CMD1
     1  CMD2
     2  *12:00*
     3  CMD3
     4  *EXIT*

      At startup, all jobs, including the Delay time and the EXIT, are placed
      in the queue.  The first job in the queue (CMD1) will be dialed 3 times
      (3 because of the Master redial attempts), and if no connection is
      established, the next job in the queue is dialed 3 times.  If no
      connection is established on CMD2, we then run into the Dial delay, but
      it's only 11:02am.  Will we now just sit here until Noon, leaving CMD1
      and CMD2 in limbo?  I hope not... RunMaster is smarter than that!  CMD3
      will not start until 12:00, since it is after the Delay time, but if
      other jobs are still in the queue up until that time, they are tried
      repeatedly until they complete successfully.  [If 12 noon is reached,
      and CMD1 and CMD2 are still in the queue, RunMaster simply starts
      trying all three of them from 12 noon on].




     The  L i b e r a t o r  v2.32                 Using The Master - Page 48
     
     

      If the job CMD1 is dialed a second time, and no connection is
      established, it will be removed from the queue, since it's 'Redial
      attempts' was assumed to be set to 5... and after 2 tries by RunMaster,
      the job would have been tried a total of 6 times (3 the first, 3 the
      second).  As soon as the running total for each job reaches the 'Redial
      Attempts' set in the Configuration, the job is removed from the queue. 
      If Redial attempts is set to 0, the job remains in the queue until
      completed or until it aborts due to an error.

      Okay, now lets assume job CMD1 is gone, since the redials expired, CMD2
      was tried and tried again (it is set to dial until it connects), and 
      at 11:45 we finally get connected and carry out CMD2, but the session
      takes longer than expected... CMD2 finishes successfully and is removed
      from the queue, but it's now 12:30!  The 12 noon delay has already
      passed, so does RunMaster wait until 12 noon the next day?  No. 
      RunMaster has planned for just such an occasion.  Delays are good for
      up to one hour after the specified time, to allow for overruns as il-
      lustrated above.  If CMD2 had executed until 1:01, then the delay would
      be activated, and RunMaster would wait until 12 noon the next day.

      Once the Delay time has passed, it is also removed from the queue, then
      we start trying CMD3... and get 3 busy signals and run straight into
      that *EXIT*.  Do we now exit to DOS?  No.  RunMaster also watches for
      this type of disaster.  *EXIT* and *REPEAT* commands only take effect
      once the queue is empty.

      Above, it was assumed that the jobs that did get connected actually
      completed successfully, but what if they didn't?  If you take a peek at
      the section 'Abort Codes/Remedies' at the end of the manual, you'll see
      that The Liberator keeps very good track of errors that occur, and
      actually returns a different value, called an Abort Code, for each
      error.  RunMaster checks this number and determines whether to remove
      the Command File or not.

      If a -1 is returned, the entire Master is aborted, since this means
      Number One (LIBERATE.001) couldn't be found, or there wasn't enough
      memory to load it... Number One carries out all the Command Files, so
      it would be pretty hopeless trying other jobs.  If a zero, or any value
      up to 26 is returned, the Command File is removed from the queue, since
      re-running the job after any of these return values would not be ap-
      propriate.  If 27 is returned (operator abort), then the Master Control
      Menu is called up to allow you to determine what to do next (the menu
      is self-explanatory, and if you see it you'll know what to do).

      If 28 is returned, which means 'connection lost', or 29 which means the
      logon was bad (you got connected to a bad node, etc), then the Command
      File remains in the queue.  These two return values are closely watched
      however, to avoid re-connecting to a BBS for hours on end.  If 3 of
      these return values are returned from the same Command File consecu-
      tively, the file is removed from the queue.  Of course if value 30 is
      returned, which means 'unable to establish a connection' (busy
      signals), then the file is left in the queue to be tried again. 
      Between each successful Command File, all jobs in the queue starting




     The  L i b e r a t o r  v2.32                 Using The Master - Page 49
     
     

      from the beginning are tried again, to maximize your chances of getting
      onto a busy BBS.

     10.7  Using the Master To Link Command Files

      What if you have the Master below setup, and the files that start with
      BBS1 use a Configuration that is set up to call one BBS, while the
      files that start with BBS2 are setup to call another?

     0  BBS1-1
     1  BBS2-A
     2  BBS1-2
     3  BBS2-B
     4  BBS1-3
     5  *04:00*
     6  BBS1-4

      Before RunMaster passes a job to LIBERATE.001 (the script which runs
      all your Command Files), it first gets the Telix dialing directory
      entry numbers you defined in the Command File's accompanying BBS
      Configuration, and checks all other jobs in the master queue (up to a
      REPEAT or EXIT) for BBS Configurations with at least one of the same
      entry numbers defined.  If it finds another job with a CFG that has an
      entry number the same (assumed to be carried out on the same BBS), it
      instructs LIBERATE.001 NOT to disconnect when the Command File
      completes.  Thus, no matter which Command File in the Master above gets
      connected first, the other Command Files for the same BBS will be
      executed without disconnecting.  For example, if BBS1-3 got connected
      first (entry 4), then RunMaster will have already found that BBS1-1
      (entry 0) was to be executed on the same BBS, and instructed Number One
      not to disconnect.

      When entry 4 completes, entry 0 will be executed, then entry 2, since
      it is also set up for the same BBS.  Entry 6 is only started without
      disconnecting if it is between 4 and 5 AM (note the *04:00* Delay time
      above).  Otherwise, we finally disconnect from BBS1 and start executing
      the BBS2 series.  If all BB2 Command Files finish before 04:00, then a
      delay window (menu) will be displayed on the screen until 4am.  You can
      select a number of options from this window, or even Shell to DOS until
      the Delay time is reached, if you are present at the time.  If any jobs
      are still in the queue at 4am, then the delay is removed from the
      queue, and entry 6 joins in on the dialing.  So, you needn't worry
      about placing the files in any specific order and attempt to fumble
      with the Disconnect option for Master entries.  Just Add entries as you
      like, and RunMaster will sort everything out for you!

     10.8  Command File Differences Under RunMaster

      Command Files behave differently when the Master is running, since it
      is assumed you are not present when the each job is started (if you
      plan to be present, you can start each job yourself and don't need the
      Master). 




     The  L i b e r a t o r  v2.32                 Using The Master - Page 50
     
     

      The 'Display Command File Delay' set in the main configuration is
      temporarily set to zero, to avoid a delayed display screen.  As
      explained above, the 'Master redial attempts' is used instead of the
      usual 'Redial attempts' set in each BBS Configuration.  As well, any
      'Dial Starting Time' set in the Command File itself is set to 'Now'
      (use the Master Dial delays to set Master starting times) and any
      Command File items set for interactive response are turned off.  As
      explained above, the disconnect option is controlled by RunMaster, so
      you needn't worry about changing this for the Master.




     The  L i b e r a t o r  v2.32              Configuring Prompts - Page 51
     
     

                        11.  CONFIGURING LIBERATOR PROMPTS


     If The Liberator gives you the message << Unable to locate a recog-
     nizable prompt >>, or if some operation fails, such as a file transfer
     is not started when prompted, then either The Liberator is sending
     responses too fast and you must set a 'Response Delay' or the PCBoard/-
     Door is not using the standard prompts (or is using old/very new
     versions of these programs) and you must tell The Liberator the format
     of the prompt being used.  (Keep the response delay in mind if you check
     the prompt and find out that it matches what The Liberator was looking
     for.)

     To check for a bad prompt, refer to your capture file (if still in Telix
     you can also check the scrollback buffer with <Alt-B>) to see where the
     problem occurred.  Take a good look at where the session failed and
     write down the last prompt/message exactly, including all spaces and
     punctuation (case is not important).  To illustrate, let's assume the
     first name prompt had been changed to the format below, and was not
     recognized:

     Please enter your Name now:

     You would first write down the above text, including the colon, as soon
     as it was found that this is where the program failed.  Next, start The
     Liberator, select 'Edit' then <Alt-E>, and select the appropriate BBS
     Configuration from the menu.  Once the CFG file is loaded, since this
     was a PCBoard prompt, you would move to screen 2, the PCBoard Prompts
     screen, by hitting <Down arrow>.  If the program had failed at a
     ProLogon, ProBank, or Prodoor prompt, you would move to screen 3.  If it
     failed in the Mail Door, you would move to screen 4.

     Once at the proper screen, view the prompt descriptions and select the
     prompt that needs changing.  They are all fairly self-explanatory.  For
     the example above, prompt 3 'Name', on the PCBoard Prompts screen would
     be what needed changing.  If the defined prompt looks the same as what
     the BBS sent, go back to screen 1 and try setting a Response delay of 5
     or 10 in option 4.  In this example, you would see that The Liberator
     expects the prompt in the standard format of:

      First name? <<

     (Note the << is used to show trailing spaces.)  Since the BBS prompt in
     the example was actually different than what The Liberator was expect-
     ing, you would select number 3 'Name' from screen 2, hit <Ctrl-End> to
     clear the entry, then enter the last few characters of what the BBS
     actually sent.  Up to twenty characters may be specified for any given
     prompt.  It is important that you make sure to enter enough from the BBS
     prompt/message to separate the prompt from regular text.  Punctuation is
     helpful here, as are trailing spaces, or anything else that will help
     The Liberator separate this text from the other text streaming in from
     the BBS.  "Name now: " would probably be adequate from the example
     prompt (without the quotes of course).  If you simpy defined "Name" as




     The  L i b e r a t o r  v2.32              Configuring Prompts - Page 52
     
     

     the prompt, then The Liberator would enter your name even if the word
     'name' happened to show up in the opening bulletins, so try to use
     enough to distinguish the prompt.

     You'll see that all the prompts have a double arrow following them, and
     this is to show any trailing spaces.  The trailing space isn't man-
     datory, but it does help to distinguish the prompt from other text, and
     normally also allows for a 0 Response Delay.

     Once you have the new prompt typed in, <Enter> it, then hit <Enter>,
     save the Configuration and re-try your Command File.
     One thing to watch when configuring prompts, is that you don't enter
     something that is likely to change.  For example, in the prompt "(115
     min. left) Main Board Command?" it would not be wise to enter the '115',
     since this changes according to how much time you have left.  Some
     prompts also pull double duty and are used for more than one operation. 
     For example, the 'Begin File Transfer' prompt on screen 2 signals The
     Liberator to start both PCBoard uploads and downloads.  Thus, you would
     not want to enter something like "Download time:" as the message to
     watch for, since the message will change to "Upload time:" when you
     perform an upload.

     The 'Pause' prompt, defined on screen 2, is used both on PCBoard and in
     ProDoor.  PCBoard uses 'Press (Enter) to continue?', while ProDoor uses
     'Press (Enter) to continue:' (with a colon instead of a question mark). 
     The last character is left out of the prompt, so it will be recognized
     in both formats.

     Another prompt that pulls double duty is the 'Enter file description'
     prompt, again on screen 2.  The text here signals The Liberator to start
     typing the file description, when uploading a file.  However, the same
     text must also work in ProDoor, so I chose text that is used in both
     places as the default.




     The  L i b e r a t o r  v2.32             Abort Codes/Remedies - Page 53
     
     

                             12.  ABORT CODES/REMEDIES


     If a Command File aborts, a message such as this will be printed on the
     screen, and stamped in the Usage Log:

     BBS1-A Command File Aborted (1).

     The number in the brackets is an abort code, and it is set to a specific
     number depending on the reason for the abort.  All abort codes and their
     possible remedies are listed here.  Note that The Liberator makes
     extensive use of the defined Usage Log, and you should also look here
     for any status/error messages to help debug a session.

     -1 Number One (LIBERATE.001), or another necessary module was not found,
        or there was not enough memory to load it.
      0 No fatal errors.  This doesn't mean that absolutely everything went
        off without a hitch, but only that no errors were serious enough to
        warrant aborting the Command File.  The Liberator can recover from
        many errors, and any of these may still have occurred.  Check the
        Usage File for error/status messages that are not covered here.
      1 Bad Command File.  This means that the Command File could not be
        found, or it was not the proper version, or there was a disk error
        attempting to read it.  If the file was not found, select 'Tools'
        from the main menu, then 'Configure' and check the 'Command File
        Directory'.  Change to the directory where the file can be found, or
        copy the file into the defined directory.  If the file was an older
        version, use the Tools 'Convert' option.  If there was a disk error,
        try again or try 'Edit'ing the file, and re-saving it.
      2 Bad Configuration File.  Same as number 1 above, but the BBS Con-
        figuration was bad.  See number 1 for possible remedies.
      3 Nothing to do.  Once the Command File was checked, no jobs remained
        to be carried out.  This could occur by saving a Command File but
        forgetting to define any jobs, or if for example, you requested only
        an upload, and your Upload List was not found.  Once the upload was
        cancelled, no jobs would remain to carry out.
      4 Master running, and no entry #'s to dial.  You cannot run Command
        Files with RunMaster that are set for interactive dialing directory
        selection (no entry numbers defined).  When you run the Master, it is
        assumed you are not present and thus you would not be able to select
        the entries to dial.
      5 Invalid entry number(s) to dial.  This occurs if, for example, you
        enter 56 as an entry, but your directory only goes up to 30.  This
        can occur when you delete entries, or sort your directory, etc. 
        Check the defined entry numbers by 'Edit'ing the BBS Configuration,
        selecting item 2 from screen 1, and hit <Alt-D> to compare the
        entries to your dialing directory.  Redefine as necessary.
      6 No password in Dialing Directory entry.  The entry connected to did
        not have a password defined (due to the way Telix works, The
        Liberator unfortunately does not know if a password is defined until
        AFTER connecting...).  To remedy, 'Edit' the appropriate BBS
        Configuration, select 'Telix Directory Numbers to Dial' from screen
        1, and take note of and check each entry by hitting <Alt-D> to view




     The  L i b e r a t o r  v2.32             Abort Codes/Remedies - Page 54
     
     

        the Telix Directory.  Highlight the appropriate entry(s) and type 'E'
        for Edit.  Check near the bottom in the 'Password' entry, and enter
        your PCBoard password in the entry.
      7 Custom Logon Script not found/returned abort code.  The defined Logon
        script was not found, or it returned a value other than 0 or 1.  If
        the file was not found, check the BBS Configuration to ensure the
        name was entered correctly, and if so, then type <Alt-J> to shell to
        DOS and copy the *compiled* script (run CS.EXE if necessary) into
        your Script directory.  Type EXIT when done, and retry the Command
        File.  If the script returned an abort code, it should have informed
        you as to the reason.  Check your Telix Usage Log.
      8 Bad password (not accepted by PCBoard).  The password you entered in
        the dialing directory was rejected 3 times by the BBS.  Check the
        appropriate Telix Dialing directory entry by hitting <Alt-D>, moving
        the highlight bar to the proper entry, and typing 'E' for Edit.  Hit
        <Enter> to move down to the 'Password' entry and change fix the
        password as necessary.  Try a manual logon to confirm the correct
        password has been entered.
      9 Script called in Custom Command returned abort code.  As mentioned in
        the Custom Commands section, if a script run from a Custom Command
        (using @SCRIPT), returns a value other than 0 or 1, this signals an
        abort to The Liberator, and thus you received this abort code.  The
        script that sent the abort code should inform you as to the reason. 
        If it gave no reason and appeared to complete normally, check the
        main() function of the script for return() statements.  Anything
        other than return, return(0), or return(1) will cause The Liberator
        to abort the Command File.  Edit out the offending return() and
        recompile the script.
     10 Unable to locate a recognizable BBS prompt.  Before starting each
        job, The Liberator reads the screen and attempts to figure out where
        it is from any of eight key positions on PCBoard.  The eight
        locations are signified in each BBS Configuration with an asterisk
        (*) immediately following the prompt description.  If none of the
        positions are found, <Enter> is sent a couple of times and some other
        responses, in an attempt to get to a key location or get a recog-
        nizable prompt up.  If after three tries the program still can't
        figure out where it is, it aborts with this value.  See the section
        on 'Configuring Prompts' above for a fix.
     11 BBS time up.  The number of online minutes set in 'Online time to
        save' (option 12, BBS Configuration screen 1) was reached, causing
        further jobs to be aborted.  The Liberator can read the available
        online time from all the major PCBoard and door prompts (assuming the
        standard format is being used) and checks the available online time
        before starting each job.  If it is less than or equal to the time
        set in the BBS time up option, mentioned above, further jobs are
        cancelled and The Liberator logs off.  Reset the 'Online time to
        save' to a lower amount, or set to zero to turn off time checking.
     12 Maximum online time up.  When a Command File begins, a timer is
        started, and if the number of minutes set in 'Max Online time' is
        reached (option 12, BBS Configuration screen 1), further jobs are
        cancelled and the program logs off.  Increase the number of maximum
        minutes to remedy.




     The  L i b e r a t o r  v2.32             Abort Codes/Remedies - Page 55
     
     

     27 Operator abort.  <Esc> was hit to call up the Control Menu, and
        option 1 'Abort' was selected.
     28 Connection lost.  The connection with the BBS was unexpectedly lost. 
        There are dozens of reasons this might occur, including line noise,
        or a bad prompt somewhere when The Liberator is not using its prompt
        recognition/recovery routines.  Check the capture file or scrollback
        buffer <Alt-B> for the actual cause.
     29 Logon unsuccessful.  This occurs if a key prompt is not reached
        within three minutes after a connection, or if none of the sixteen
        logon prompts can be found after three attempts at getting one up.
     30 Max redials reached or operator aborted dialing.  It doesn't know
        which, since Telix returns the same value for both.  In any case, a
        connection was not established.











                MAIL.DOC Copyright (C) 1990 Liberation Enterprises.
                       Liberator Quick Set Up for Mail Doors


     This document was designed to allow you to automate your mail runs as
     quickly as possible, and it covers Qmail v2-4, MarkMail, and MegaMail-
     type door set up.  Items covered are (very briefly) how to get started
     in The Liberator with Command and Configuration Files, what items need
     setting up for automating mail runs, most of the common problems and
     their remedies, and some specific information on MegaMail-type doors,
     setting up for Multiple Mail doors on the same board, and Qmail v4 doors
     using the SET command.  If all goes well, you'll have it done in less
     than 15 minutes.

     To simplify things, it is assumed that you have Telix set up properly,
     and have already downloaded a mail packet manually from whichever door
     you're using.  If not, dig into your reader documentation first, or the
     larger Liberator manual for door/reader set up information.  None of
     these items are explained here (other than unusual items, specific to
     automated runs), and it is assumed you are familiar with your reader and
     the Mail Door itself.  If not, you probably will not be able to automate
     your runs very successfully... and 15 minutes could easily turn into
     frustrating hours.

     In order for The Liberator to get your mail from ANY door, you must
     first set up what is called a 'BBS Configuration File'.  To do so,
     please start The Liberator now using the LIBERATE command from DOS, or
     <Alt-G>LIBERATE from Telix.  From the main menu, select 'C'reate (if
     it's your first startup, Create is selected automatically... after a
     File Check and some other things... follow along and ad lib).  If
     prompted for a 'Configuration' to use, hit <Enter>.

     You should now be looking at a screen which allows entry of your name,
     and some other info about the BBS.  If not, hit <Esc> until you exit the
     program (to Telix terminal mode), and start over...

     Type 1 and hit <Enter> to select 'Name used on PCBoard', type in your
     name and hit <Enter> again.  Select item 2, and enter the Telix
     directory entry number(s) of the BBS you want to call.  If you don't
     know the entry numbers, hit <Alt-D> and your directory will be displayed
     (hit <Esc> to exit the directory once you note the entry #'s).  If more
     than one entry is to be specified, separate each with a space.

     *IMPORTANT*:  You must enter something in the 'Linked script' item of
     any Telix directory entries you use The Liberator with.  If the Linked
     script item is left blank, Telix will pause after connecting, and the
     opening question on the board will slip by the tracking routines.  I
     usually enter PCBOARD.SLC in this directory item, but you can enter any
     character at all, and Telix will then bypass the pause after connecting. 
     As well, your PCBoard password must be placed in each directory entry,
     near the bottom.  Telix passes this password to The Liberator once a
     connection is established.  If The Liberator aborts due to no password,
     check all entries defined.

     If the board you call has more than one language available, enter the




     The  L i b e r a t o r  v2.32                          MAIL.DOC - Page 2
     
     

     number used on the BBS to select 'English' in item 7 (if there is a
     'Standard PCBoard prompts' language #, use it instead).  If you must
     join a conference to access the Mail Door, enter the proper conference #
     (or NAME if available) in item 9.  Next, enter the Mail Door's number
     (or NAME) in item 10.
     The rest of the items on this screen can be looked up in the larger
     manual if desired.  Most are usually fine at their defaults, but if you
     run into problems, look into the manual (or experiment... most items are
     fairly self-explanatory).

     Note the reminder at the bottom of the screen, then hit <Up Arrow> to
     'Change screens' and move to screen 4 - the Mail Door set up screen.

     Item 1, 'Packet ID' is different on each board, and you can find the
     packet or node ID by looking at the packet I mentioned at the opening of
     this document... you must have manually downloaded a packet first in
     order to get the proper ID.  The ID is found in the base part of the
     filename.  If the packet is named THEBBS.QWK, the ID you must enter is
     THEBBS.

     Item 2 must be set to whatever type of door you are setting up for. 
     Select item 2, and you'll get a menu of the types available.  After you
     select the proper type, the prompts are automatically adjusted to the
     DEFAULT prompts used in that type of door (MegaMail type doors don't
     require prompts at all).  This doesn't mean that the prompts will
     actually match... because your Sysop may have re-defined the prompts. 
     However, if the prompts are still at their defaults, they will work, and
     you won't have to worry about configuring prompts.
     If The Liberator 'hangs' at a certain prompt, the most likely cause is
     that it has been redefined in the door and is not matching what is
     defined here in the Configuration.  In Qmail v4 doors, The Liberator
     uses the 'Extended prompts for scripting' which cannot be redefined.    
     See the section on configuring prompts in LIBERATE.DOC for more info on
     setting up prompts, if necessary.

     Assuming you have the door's default protocol set up as Zmodem, you
     won't have to worry about configuring protocols.  If did set up a
     different protocol in the door, select items 6 and 7, and enter the
     proper protocol from the menu.  Leave the 'Door protocol letter' set to
     'N' to use your door default.  Different up/download protocols are
     currently only available in the Qmail v3/4 doors, and information on why
     and how you would want to define separate protocols can be found in
     LIBERATE.DOC.

     The SET / NET items are specific to the Qmail v4 door, and are explained
     below under 'Qmail v4 setup'.

     Items 10-12 must be set to the same directories your Offine Reader has
     been set up for.  If you have your reader set up to create your replies
     file in the C:\REP directory, then you must also define this directory
     in item 10, or The Liberator will not be able to locate your reply
     packets.  Likewise with the message packet directory, according to where
     your reader looks for these files.  The *filenames* are not needed, as




     The  L i b e r a t o r  v2.32                          MAIL.DOC - Page 3
     
     

     The Liberator constructs the proper filename using the 'Packet ID' and
     'Mail System' type.  For example, if you set the Packet ID to "RMPCB",
     and the door type to Qmail v4, and your reply packet directory to
     C:\MSG\, then The Liberator will look for a file called C:\MSG\RMPCB.REP
     (REP being the proper file extension for Qmail).  If you set up for a
     MegaMail door, the extension .UL will be substituted for .REP, and so
     forth (the filenames are constructed internally at run-time, and are not
     displayed on this screen).  The Liberator maintains your packets, both
     message and reply, and will rename and/or delete older packets before
     new ones come in, or after they go out.  Items 4 and 5 control the
     number of backup packets you wish to keep on hand.  It is recommended
     you keep these items set to 1 or more.

     That's it for the BBS Configuration, so hit <Enter> at the 'Enter =
     Save' prompt, then enter a name to save it under.  A good choice for a
     name is the Packet ID, since it will help remind you which board/ID the
     Configuration is set up for.

     You are then taken to the 'Command File Editor' which is where you
     define:  a) the board to call (the Configuration File to use) and b) the
     jobs you want done on that board.  For our purposes, set items 8 and 9
     both to 'Yes' by selecting each and entering 'Y'.  You may also want to
     select 'Disconnect' and have The Liberator 'Exit to DOS' when it
     completes.  Select item 14 and enter 'E' to do so.
     This allows whatever batch file that called The Liberator to continue
     processing when the Command File completes, and may be used to start
     your Offline Reader, by placing the appropriate command in the batch
     file you use to start The Liberator.  See the LIBERATE.BAT file for more
     information.

     That's it for this Command File, so hit <Enter> then type a name to save
     the file under... The name you enter will be displayed on the main menu,
     so make sure you enter a name that will remind you what the job does. 
     For example, you may want to call it 'BBSMAIL', where BBS is an
     abbreviation of the board's name.

     Once the file is saved, you are taken to the main menu, and can try it
     out by entering the number beside the name.  If the board you call is a
     relatively 'standard' PCBoard, and your Sysop hasn't redefined any
     prompts, everything should go off without a hitch (The Liberator also
     automatically supports ProLogon).  A few common problems are discussed
     below, if you do run into a snag.  If you are setting up for multiple
     doors on the same board, or for different SET's of a Qmail v4 door, you
     can use the 'E'dit option to clone the job/Configuration you just
     Created.  Select Edit from the main menu, enter the job's entry number,
     then from the 'Command File Editor' select item 1 and hit <Alt-E> to
     load the Configuration for editing.  Make any changes, such as the new
     'Packet ID' and/or SET number, then simply save the Configuration under
     a different name.  (Hit <Enter> to save the file, then type in a new
     name before hitting <Enter> again... you might change the name BBS to
     BBS-2, etc).  When you return to the Command File Editor, the new name
     will be placed in item 1 for you, and you should then hit <Enter> and
     save the Command File under a different name also.




     The  L i b e r a t o r  v2.32                          MAIL.DOC - Page 4
     
     

     Setting up jobs (Command Files) separately from the Configuration Files
     may seem like a lot of trouble, but there is method behind the madness. 
     By isolating the Configurations from the jobs, you can set up many jobs
     which all use the same Configuration.  Each time you 'Create' a new job
     from the main menu, you will be asked which BBS Configuration you wish
     to use, and you may select the same Configuration over and over, as long
     as you want the job to run on the same board (and with the same Packet
     ID, and other info).  For example, you might have 10 different Command
     Files for one BBS... each one doing a different combination of tasks,
     but all using the same Configuration: one for downloading files, one for
     mail, one for mail and downloads, one for mail and uploads... etc.

     You will immediately see the advantage of having separate Command and
     Configuration Files if your Sysop redefines something on the board, and
     you must change your Liberator setup (i.e. if a door number, or prompt
     changes).  Only the Configuration File will need changing, and all your
     Command Files (of which there are usually about 10 times as many for
     each board) can remain unmodified, since they don't contain any
     information about the BBS other than the name of the Configuration File! 
     If this is a little unclear, you'll get the idea when the time comes,
     and will be glad you don't have to edit 15 files every time a change is
     made on the board.


     Problems/Remedies
     -----------------

     The FIRST thing to check whenever any type of problem occurs is the
     Usage Log (defined in each Configuration, but defaults to LIBERATE.USE). 
     The Liberator stamps many status/error messages in this file which are
     not displayed on the screen.  Many problems can be solved by looking at
     this file.  Below some common problems are outlined as questions, with
     the solution following:

     It doesn't maintain the mail packets, and/or keeps cancelling the job? 
     Check your Mail Door type, message/reply packet directories, and Packet
     ID on Configuration screen 4, and make sure everything is set up
     properly.  If you define any of this improperly, The Liberator will not
     be able to locate your packets, and the packet maintenance will not take
     place, and/or the Mail Door activity may be automatically cancelled. 
     See the Usage Log first, as it may show you what The Liberator IS
     looking for, according to what you set up.

     Why doesn't it dial when I select a job?  Your modem is forcing on the
     'Carrier Detect', which means it's telling The Liberator you're
     connected when you really aren't...  The Liberator skips dialing since
     it thinks you are already online (you can start The Liberator online, at
     any of the eight 'key' prompts).  See the file TELIX.DOC that
     accompanied The Liberator for a remedy.  It's usually easy to fix once
     you know what you're looking for.

     Can't connect properly after dialing?  Almost surely a Telix/modem setup
     problem.  See the Telix documentation and your modem manual until you




     The  L i b e r a t o r  v2.32                          MAIL.DOC - Page 5
     
     

     can connect manually (using <Alt-D>).  All The Liberator does is hit
     <Alt-D> for you and select the proper entry numbers.  Control is then
     turned over to Telix completely, until after the connection is
     established.

     Won't logon properly... gets stuck at a certain prompt?  The first thing
     to try is a 'Response Delay' which is set on Configuration screen 1. 
     (Select 'Edit' then hit <Alt-E> and enter the proper number to edit a
     Configuration).  Sometimes The Liberator answers questions faster than
     the board can accept them, and a response delay of 5 (half-second) or 10
     (1 second) usually solves this.  If not, in all probability, your Sysop
     has re-defined the prompt, and The Liberator comes out of the box to
     look for the default prompts.  Take note of the prompt on the BBS, then
     Edit your Configuration, and hit <Up Arrow> or <Down Arrow> to page
     through the Configuration screens.  PCBoard prompts are defined on
     screen 2, Pro Utilities prompts on screen 3, and Mail Door prompts on
     screen 4 (only available in a Mail Door is defined on screen 1).

     Once inside the Mail Door, it gets stuck at the 'Press a key' prompt? 
     Turn Expert mode on, and the prompt will not be displayed.

     Even though the prompts match, it isn't sending any commands to the
     door?  In the Qmail v3/4 doors, there is a C)onfiguration OPTion which
     'flushes the buffer'... which means that if The Liberator answers a
     question too fast (stored in the door's 'buffer'), the door ignores it
     and clears the buffer assuming it was line noise.  Toggle the buffer
     flushing OPTion OFF (you may also want to toggle ON 'Delaying extended
     prompts for 1 second' as it assures the buffer is already cleared before
     The Liberator receives the prompt).  If in a MarkMail door, or older
     Qmail door, try setting a 'Response delay' of, say 5 or 10, in your
     Liberator Configuration File for that BBS.

     Why does it send my reply packet 3 times?!  In Qmail/MarkMail doors, The
     Liberator looks for the 'Successful Upload' prompt, and if it doesn't
     show up after the transfer completes, it assumes the upload was bad, and
     tries again, up to 3 times total.  This feature may save your session
     one day, but it requires that the proper prompts be defined.  Take note
     of what message the door sends after a successful up/download, and
     define it properly in your BBS Configuration.

     Why does it try to download mail, even when there is none!!?  You
     probably have 'Repeat' downloading turned on in your Command File,
     and/or the 'No Mail Found' prompt (screen 4) is not matching what the
     board is sending.  Repeat downloading can be useful when you fall behind
     and must get more than one packet... but it only quits once the prompt
     for 'No new messages' is found.  If this isn't the problem, you may have
     Repeat downloading turned on in the door itself.  Qmail v3/4 doors offer
     this feature, but it should be OFF for Liberator runs.  If you wish to
     use Repeat downloading, define it in your Command Files by selecting
     'Mail download' (item 9) and entering an 'r'.

     Telix's file transfer window comes up, but the file doesn't get
     transferred?  Wrong protocol defined either in the door or in your




     The  L i b e r a t o r  v2.32                          MAIL.DOC - Page 6
     
     

     Configuration.  Both The Liberator and the door must be set up for the
     same protocol.  See Configuration screen *4* to change The Liberator's
     Mail Door protocols... the protocols on screen 1 are for PCBoard
     transfers only and the ones on screen 3 for ProDoor transfers only.


     Net/MegaMail/PCRelay Info
     -------------------------

     The Liberator uses completely separate routines to handle these doors,
     since they operate quite differently from Qmail/MarkMail.  All The
     Liberator does, is first construct the proper filenames, using the
     information provided on the Mail Door setup screen, as follows:

     Message (incoming) packet - <message_directory><node_id>.<up_ext>
       Reply (outgoing) packet - <reply_directory><node_id>.<dn_ext>

     For NetMail, <up_ext> is OUT and <dn_ext> is IN
     for MegaMail <up_ext> is UL  and <dn_ext> is DL
     for PCRelay  <up_ext> is RLY and <dn_ext> is RLY
      but <node_id> is substituted as IN for the message (incoming) packet.

     If the proper reply file is not found, the door activity is
     automatically cancelled before dialing.  In these doors, you cannot
     download without first uploading a packet, so The Liberator cancels both
     if your reply packet is not found.  Before dialing, message (incoming)
     packet maintenance takes place, as usual, if a packet is found.

     Once in the door, The Liberator looks for the name of the outgoing
     packet, then sends your reply file.  It then looks for the name of the
     incoming file, and receives it to the directory defined in the BBS
     Configuration as the 'Message packet directory'.  When the session
     completes, if the upload was successful (judged by whether you received
     a packet or not), your reply file is renamed and/or deleted in the
     after-session packet maintenance.


     Multiple Mail Door Setup
     ------------------------

     To have The Liberator download mail from multiple doors on the same BBS,
     you must define a separate Configuration for each door, defining the
     door's number (or name if available) and the proper Packet ID, along
     with the other usual information.  Each door's Packet ID can be
     determined by performing a manual download.

     Once you get all the door #'s/Packet ID's, use 'Create' from the main
     menu to get started, set everything up in the Configuration, save it
     using the Packet ID for a name, then save a Command File (make sure you
     set the Mail upload/download items to Yes) using the same name.  Repeat
     this for each door, but rather than re-Creating a new set each time,
     select 'Edit' for the second setup, and simply change the info in the
     first CFG to match the second door (i.e. the door number and Packet ID). 




     The  L i b e r a t o r  v2.32                          MAIL.DOC - Page 7
     
     

     All the other info should remain the same, since it's being executed on
     the same BBS.

     When finished, save CFG #2 under a *different* name, and The Liberator
     will create a new Configuration using that name (effectively cloning and
     editing them all at once).  After the first setup, all you should have
     to change for each subsequent door is the Mail Door number, and Packet
     ID for each Configuration--just don't forget to enter a *different* name
     when saving the secondary files, or you'll overwrite your original! 
     [Note that the Configuration is accessible from the Command File screen
     by selecting item 1, and hitting <Alt-E>.]

     Once the necessary files are created, 'Add' them to the Master and run
     the Master by selecting 0 from the main menu.  The jobs will all be
     carried out, from door to door, without disconnecting!  See the section
     'Using the Master' in LIBERATE.DOC for more information.


     Qmail v4 setup
     --------------

     Define the proper door number (door name preferred if available... e.g.
     QMAIL4) on Configuration screen 1, then hit <Up Arrow> to move to the
     Qmail screen.  There, set the proper Packet ID according to the SET you
     have in mind.  If configuring for SET 1, the usual Packet ID is used
     (for example, BBSID).  If configuring for SET 2, a number will usually
     follow the packet ID (BBSID2), and so on.  Define the SET number (e.g.
     1, 2, 3, etc.), and a default NETwork if desired (optional) in item 9. 
     For more information on SET and NET, view the help available in the
     door.  Of course your protocols/directories must be set according to how
     you have the door and your Offline Reader configured.  The v4 Qmail door
     has a C)onfiguration OPTion to send the SESSION.TXT file, so there's no
     need to define a pack command.  The extended prompts are used, and The
     Liberator makes sure they are turned on each time it opens the door by
     sending the PROMPTS command.

     If using multiple SET's, you must set up a Command/Configuration File
     for each SET, making sure to define the proper Packet ID and SET # in
     each Configuration.  Note that you needn't Create the CFG from scratch
     each time... simply 'E'dit the last SET's Configuration, change the SET
     # and Packet ID, then save the Configuration under a different name
     (e.g. BBS-1.CFG, BBS-2.CFG, etc).  Set up a job for each Configuration,
     then Add them to the Master, and it will carry out the different SET's,
     including packet maintenance, without leaving the door or disconnecting.













                                  M a k e L i s t

                                   Version 1.01

                                Add-on Command For
                                The Liberator v2.3

                     Copyright (C) 1990 Liberation Enterprises

                               All rights reserved.

                                        ~~~
     DESCRIPTION:  MakeList (MAKELIST.SLC) is a compiled Telix SALT script
     that will send user-defined commmands to a BBS, then capture the results
     of the commands to any file.  Its purpose is to allow you to capture the
     results of a Locate, New Files, or Zippy Scan command from either
     PCBoard or ProDoor.  The resulting text is then automatically formatted
     for use as a Liberator Download List and can be used for downloading in
     the same session.  If desired, you may also manually edit the list prior
     to downloading.  You define the BBS command(s) to send, and File List
     name in one of the Custom Command(s) options of a Liberator v2.3 Command
     File (preferably Custom Command 2).  MakeList will not work with earlier
     versions of The Liberator.

     Standard conventions are used in this document to help illustrate
     syntax:

     o  Text inside two angle brackets <label> is used as a reference to a
        certain items.  Do not type in the <label> itself, but instead
        substitute it with actual text as defined below.
     o  Square brackets [] surround optional items.  You can leave these
        items out if desired, but do not include the brackets if used.
     o  A vertical bar | means OR, when more than one option is available. 
        The actual options to use will be on either side of the bar.  Do
        not specify the actual |.
     o  n1, n2, etc., signifies a number (1,2,10,50, etc).
     o  Three periods ... means that more items of the same form may
        follow.

     Now, hopefully this line below will make some sense, and not look like
     secret code:

     USAGE:  @MakeList <list> <command> [/d|/e][/#n1[,n2]...][/Edit]

     Each item is explained below.  Note that <list> MUST be the first item  
     specified, but following items may appear in any order.  <command> must
     be separated from other options by either a space or a foward slash (/). 
     If you precede <command> with a switch, make sure you leave a space
     between the two.  If you follow <command> with a switch, no space is
     necessary since MakeList will recognize the / as a switch.  Note that




          The  L i b e r a t o r  v2.32               MAKELIST.DOC - Page 2
          
          

     with some program's command line switches, you may substitute the slash
     (/) with a hyphen (-), but this was not implemented in MakeList.

     @MakeList = The '@' character, when used in a Liberator Custom Command,
                 means to run a script.  @MakeList (or @makelist @MAKELIST)
                 tells The Liberator to run the script MAKELIST.SLC, which
                 should have accompanied this document.  The script must be
                 located in the current directory, or in the directory
                 defined with the Telix <Alt-O> command as your 'Script
                 Directory'.  If you don't have a script directory defined in
                 Telix, it is highly recommended that you do so immediately,
                 then copy MAKELIST.SLC (and The Liberator) into the defined
                 directory.

     <list>    = Name of file to capture results of <command> to.  The
                 filename can be specified in two forms:

                 [d:][\path\]LISTNAME[.ext] -- An actual filename (drive,
                 path and extension optional) or:

                 %D (or %d) -- Causes The Liberator to use the file named in
                 the "Download List" option of the currently executing
                 Command File.  If you specify %D without defining a filename
                 in the Download List option of the same Command File, The
                 Liberator will construct a filename, comprised of the name
                 of the current Command File, plus the extension .DL (for
                 Download List).

     <command> = PCBoard/ProDoor command(s) to send to the BBS (F)ile
                 Directories, N)ew Files, L)ocate, Z)ippy Scan, etc.)  If you
                 define the @MakeList command line in Custom Command 1, then
                 <command> will be sent to PCBoard (unless you are already in
                 ProDoor for some reason).  If you define the command in
                 Custom Command 2, and a ProDoor is defined in the CFG file,
                 ProDoor will be opened and the script will execute there,
                 allowing you to take advantage of ProDoor commands, and
                 batch transfers (this is a function of The Liberator, and
                 occurs with all Custom Commands).  It is recommended that
                 you use Custom Command 2 whenever possible with MakeList.

                 To specify a Ctrl (control) character within <command> (such
                 as Carriage Return which is Ctrl-M), precede the character
                 with a caret (^).  A vertical bar (|) in <command> causes a
                 ^M (<Enter>), then waits for one of the eight Liberator
                 'key' prompts defined in each Configuration.  Use either the
                 | or ^M to specify more than one command if desired.  A
                 tilde (~) may also be used to specify a half-second pause. 
                 See the examples below for uses of these characters in
                 <command>.  ^M is always sent after the final character of
                 <command>, so you need not specify the final carriage
                 return.  If you do specify a trailing ^M, then two carriage
                 returns will be sent.




          The  L i b e r a t o r  v2.32               MAKELIST.DOC - Page 3
          
          

                 The "More" (PCBoard) and "ProDoor More" prompts (defined in
                 each Liberator Configuration) are automatically handled by
                 MakeList by sending NS (Non-Stop) when found.  The "Pause"
                 prompt is also handled as usual by sending a carriage
                 return.  Most times you will add an NS (non-stop) to the end
                 of <command> to avoid the 'More' prompt, but if you forget,
                 MakeList will handle these prompts for you.  If MakeList
                 hangs at either of these prompts due to a different prompt
                 format, you may reconfigure both directly in the board's
                 Liberator CFG File, since MakeList gets the prompts directly
                 from the Configuration.

     /d|/e       All text resulting from <command> is captured and inserted
                 at the BEGINNING of <list> if it already exists. (This is to
                 allow quick editing, and so newly listed files will be
                 downloaded first.)  To change this, use the /d or /e switch
                 (or /E /D if you prefer).  /d causes <list> to be Deleted if
                 it is found, /e causes captured text to be appended to the
                 End of <list>, if it already exists.

     /#n1[,n2] = Specifies conference(s) to execute <command> in.  This
                 option, if used, must start with the '/#' characters, and NO
                 SPACES are permitted until all conferences are specified. 
                 You may use as many conference numbers as will fit in the
                 Custom Commmand (64 character maximum), each separated by a
                 comma, or omit this option entirely to execute <command>
                 only in the current conference.  If more than one conference
                 is specified, <command> will be sent to the BBS in each of
                 the conferences.  Commas are only necessary when more than
                 one number is specified, and remember not to use a space
                 before or after the comma.  Note that sometimes the "Scan
                 message base" question is asked after joining a conference. 
                 MakeList is designed to handle this prompt, and it gets the
                 prompt's format directly from the Liberator CFG file
                 currently being used ('Scan Message Base' is defined on the
                 PCBoard Prompts screen).

                 The correct conference numbers will be maintained in <list>
                 so The Liberator will obtain files from the correct con-
                 ference when <list> is used for downloading.  Note that if
                 the @MakeList command is defined in Custom Command 2, AND if
                 a ProDoor is defined (or if your PCBoard supports conference
                 names) then you may also use the conference names as well. 
                 (E.g. /#IBM,5,TELIX)

     /Edit    =  Run your Text Editor when complete to manually remove or
                 rearrage text in <list>.  MakeList automatically filters out
                 most extranneous text, other than file descriptions, but if
                 you want to look over the list before MakeList returns
                 control to The Liberator, use this switch.  You must use the
                 The LibTools Configure option to define your editor before
                 using this option.  Case isn't important (/EDIT or /edit
                 will work fine as well), but the '/' is necessary.  Your




          The  L i b e r a t o r  v2.32               MAKELIST.DOC - Page 4
          
          

                 editor will be called in the form <editor_name> <list>, so
                 if it accepts a filename on the command line, <list> will be
                 automatically loaded.  If your editor doesn't accept a
                 filename on the command line, you will have to load the file
                 manually, but MakeList will change to the proper directory
                 before running the editor so you can locate the file easily.

                 Before actually running the editor, MakeList will prompt you
                 to press a key, and if you are not present will sound a
                 pager every ten seconds until you arrive.  If you don't
                 arrive within two minutes, manual editing will be aborted
                 and MakeList will return to The Liberator, where the Command
                 File will continue as defined.

     /Cap        This switch causes text resulting from <command> to also be
                 placed in the currently defined Capture File (if any).  If
                 this switch is not specified, the text will only be placed
                 in <list>.

     EXAMPLES:

     Please note that the examples below are for use in Custom Command 1 or 2
     of a Liberator v2.3 Command File, and the leading @ is necessary in each
     example (specifies to run a script).  It is recommended that you use
     Custom Command 2 whenever possible.

     @MakeList

      If you don't give any parameters at all, then MakeList will construct a
      default <list> named <cmd_fname>.DL (<cmd_fname> is the current Command
      File), and its default <command> of N S A NS (New files, Since last
      time on, All areas, Non stop).  The commmand will execute in the
      current conference only, and text will be inserted at the beginning of
      <cmd_fname>.DL if it already exists.  Your editor will not be called
      for manual editing.

     @MakeList C:\TELIX\PCBOARD.DL

      Opens the file C:\TELIX\PCBOARD.DL, then sends the default <command> of
      N S A NS to the BBS, in the current conference.  If C:\TELIX\PCBOARD.DL
      already exists, then the captured lines are inserted at the BEGINNING
      of the file so they will be downloaded first.  See the next example to
      change this.

     @MakeList %D L *.GIF A /e /#1,10,0 /Edit

      Joins conference 1 (note the conference '/#' option used above), then
      sends the command L *.GIF A to the BBS (Locate GIF files, All areas),
      then conference 10 is joined (note the comma, and no space) and the L
      *.GIF command is resent... then conference 0 is joined (the MAIN
      conference) and the command is sent once again.  Text resulting from
      all three commands is captured to the currently defined Download List
      (note %D used as <list> above), and is placed at the END of the file if




          The  L i b e r a t o r  v2.32               MAKELIST.DOC - Page 5
          
          

      it already exists (due to the /e switch... /E has the same effect). 
      The defined Editor is then run to allow you to edit the list before
      files are downloaded, to remove unwanted files, etc.  When downloading
      commences, the correct conferences will be re-joined as necessary. 
      Since no NS (non-stop) was given in <command>, MakeList would enter NS
      (Non Stop) if a 'More' prompt did appear while the BBS was displaying
      the located files.

     @MakeList TMPLIST /d /#2 Z^M~~Liberator^M1 2 U NS

      This command is a little complicated, so let's break it down:

      TMPLIST /d means capture to the file TMPLIST (note how / switches can
      appear anywhere after <list>), but delete the file first, if it already
      exists (due to the /d switch... /D has the same effect).  Since no
      drive or path is given before TMPLIST, the file will be created in the
      current directory, wherever that happens to be.  This is why it is
      preferable to specify the path when possible.  Next, we have /#2 which
      will cause conference 2 to be joined.  Then we have the command to
      execute: 

      Z^M~~Liberator^M1 2 U NS

      This is the actual <command> to send to the BBS, and it needn't be this
      complicated, but ^ ~ are illustrated here.  First the "Z" would be sent
      to the BBS (Zippy scan), followed by a carriage return (the <Enter>
      key) because ^M signifies Ctrl-M or Carriage Return (CR).  Next, a 1
      second pause will take place due to the two ~~ characters (each ~
      causes a half-second pause).  This gives PCBoard a chance to come up
      with the next prompt, which asks what text you want to scan for. 
      "Liberator" would then be sent, along with another CR.  Then PCBoard
      asks what areas to scan, and the final "1 2 U NS" are sent, which means
      to scan file areas 1, 2, and the recent Uploads area.  NS is stacked on
      the end to avoid the 'More' prompt.  A ^M is always appended to the end
      of <command>, so you need not specify the final CR.

      Of course, this whole command can (and should) be specified without any
      CR's.

     @MakeList %d Z Liberator U NS|N S A NS|L Telix A NS /#1,2

      The above would be sent as three complete commands:

        Z Liberator U NS
        N S A NS
        L Telix A NS

      ...since the vertical bar (|) causes a ^M (<Enter>), then waits for one
      of the eight Liberator 'key' prompts before sending any more of <com-
      mand>.  Since more than one conference was specified, all three
      commands would be sent in each of the defined conferences.











              NEW-FEAT.DOC Copyright (C) 1990 Liberation Enterprises.
                    Features introduced in The Liberator v2.3.

     This document is not just a quick listing, but items are explained in
     some detail to allow veteran Liberator users to attempt to avoid
     printing the larger manual.  Things are covered more fully in the larger
     manual, but this document lists all the important new features, and will
     give you a good idea how to make use of them. After a few days of
     exploring, (or if you run into a problem) you should then selectively
     browse the larger manual (esp. the section 'Using The Master', and the
     'Custom Command', 'File Transfers' sections).

     Registration Gimmicks?

      There is now a Registered Version of The Liberator, for a number of
      reasons.  The distribution (unregistered) version of the program now
      has evaluation copy reminder screens -- not to annoy you, but simply
      because I feel that without such reminders, people actually forget to
      register.  In the registered version, the reminders are removed.  As
      well, each registered copy comes with a serial number, which makes it
      easier for myself, and vendors to control sales of the program.  The
      serial numbers were actually the initial reason to create a registered
      version, but with a registered version created, the reminder screens
      became an obvious addition to the unregistered version.

      Color configuration is also possible with the registered version of The
      Liberator v2.3, so send away for your registered copy today!

     10-14-90  Release 2.32.  Maintenance release.  Due to code (and time)
               restraints, this release of The Liberator was cut short and
               not all features planned were added.  If you made a suggestion
               for improvement, and it did not show up in this release,
               please look for it in v3.0, which is going back into
               development immediately.  Version 3.0 was started months ago,
               but in mid-development many changes were made to PCBoard
               (ProLogon, PCBoard v14.5, multiple Qmail doors, etc) and it
               became necessary to pull v2.2 out of the archives to support
               the new items, as v3 could not have been released in time. 
               Version 2.32 was meant only to fill the gap, and meet your
               needs until the rest of version 3 can be completed.  Though it
               is realized that improvements could be made in certain areas
               of v2.3, it is felt that time would be better spent moving
               back to v3 immediately, instead of attempting to modify the
               obsolete v2 code any further.

               Having said this, if you are not registered *please* do not
               wait for v3 to be released before you send in your support for
               the program (assuming your evaluation of v2.3 is successful
               and you continue using the program).  Version 3 may be quite a
               while coming, and your support is needed today to allow it to
               be developed.  All v1.x and v2.x registrants will be eligible
               for low-cost upgrading to v3 at a sizeable discount to full
               registration, so you really can't lose by sending your
               registration today.




     The  L i b e r a t o r  v2.31                      NEW-FEAT.DOC - Page 2
     
     

     Version 2.32 New Features and Fixes:

     + Qmail v4, NetMail, MegaMail, and PCRelay support added.  See MAIL.DOC,
       also new in v2.32, for information on setting up for the various Qmail
       doors.  Qmail PTR (pointer reset) files are now automatically
       maintained along with the REP file.

     + The RunMaster program has changed quite a bit from v2.31.  While
       running the Master list, RunMaster now keeps track of how many dialing
       attempts have been made per board, and removes each job from the queue
       when the total dial attempts reaches the 'Redial Attempts' number, set
       in each BBS Configuration (screen 1, item 4).  If 'Redial attempts' is
       set to 0, the job remains in the Master queue indefinitely (until it
       completes or aborts due to an error).  If it is set to any other
       number, the job is dialed in increments of 'Master Redial Attempts',
       until the total is reached.  Thus, 'Redial attempts' works as it
       normally does, but RunMaster cycles to the next job every 3 attempts,
       and keeps a running total for each job (3 being whatever you have set
       in 'Master redial attempts' using the Tools item).  When only one job
       remains in the queue (when all others have completed or aborted), any
       remaining redial attempts for that job are carried out all at once,
       instead of dialing in increments of the 'Master redial' value.

       Once you see it in operation it will become pretty clear what this all
       means.  It was added only for those who want to put a limit on the
       number of attempts certain jobs make.  If you have your 'Redial
       attempts' item in each Configuration set to 0 (until connect) then
       none of the above will apply, and each job will remain in the queue
       until it completes, or aborts due to an error.

     + Two abort code values allow a Command File to remain in the Master
       queue.  Namely values 28 (connection lost) and 29 (bad logon attempt). 
       There was extra protection built into RunMaster v2.31 for these abort
       values, which was supposed to remove the Command File from the queue
       after 3 contiguous returns of either value on any given Command File. 
       However, this protection was not working properly, and RunMaster
       continued to keep these jobs in the queue even after 3 bad returns. 
       If your online time had expired at a BBS for the day, (which causes a
       bad logon attempt, or Abort Code 29), RunMaster did not remove the job
       from the queue after 3 attempts, which meant the board could be called
       back many times.

       This has been fixed, and any bad logon attempt (logging onto a 'down'
       node, etc.) or << Connection Lost >> in the middle of a session,
       causes RunMaster to start a counter for that job, and it will properly
       remove the job after 3 bad returns.  Note that 3 attempts are allowed,
       in case the connection is inadvertantly lost due to line-noise, etc.,
       or in case of simply attempting to log onto one 'down' node of a
       multi-node BBS system.  For these cases, the 2nd or 3rd retry may save
       your session.  If not, the job is removed from the Master queue and
       will not be tried again until the next Master run.

     + Master Dial delays were sometimes not working properly when used in




     The  L i b e r a t o r  v2.31                      NEW-FEAT.DOC - Page 3
     
     

       tandem with REPEAT commands.  If all jobs in the queue completed
       within one hour, the delay was not observed (due to the fact that
       Master Dial delays are good for up to an hour, to allow for over-
       runs... see the manual for more details).  This has now been fixed,
       and the one hour leeway does not apply immediately after a REPEAT. 
       The one hour leeway still applies for all other cases.

     + Added support for PCBoard v14.5 batch protocol entry.  If you have The
       Liberator set up for PCBoard 14.5/batch mode (file transfers using the
       UB/DB commands), and your 'default' PCBoard protocol on the BBS was
       set to 'None', PCBoard asks for a protocol to use, just after The
       Liberator finishes entering filenames.  Previously, The Liberator
       ignored this prompt, and simply sent a CR (PCBoard assumes 'N'one as
       the protocol if this is done).  However, you may now enter specific
       protocol letters in your BBS Configurations (see CFG screen 1), to
       select specific PCBoard protocols at this prompt.  This allows you to
       specify separate protocols for batch uploading and downloading, if
       necessary.  Thus, The Liberator now supports online protocol selection
       for regular PCBoard (non-batch) transfers, ProDoor transfers, and
       PCBoard 14.5 batch transfers.

     + MakeList now works a bit differently, in order to save online time. 
       Previously, if a Capture File was active when MakeList was called, any
       text resulting from the MakeList commands was automatically inserted
       in the capture file after creating the Download List.  Now, MakeList
       only inserts the text in the Capture File if you specify the new /CAP 
       switch (case insignificant... /cap works too).

     + Upload descriptions are now truncated at 45 characters for PCBoard
       14.2 (or lower) uploads.  Previously, The Liberator sent all
       characters and just looked for an overflow, but this caused problems
       the odd time on some boards.

     + An attempt to upload a file that already existed at the BBS always
       used to result in that filename being 'commented out' of your Upload
       List.  However, this caused problems with /P ermanent files that are
       meant to be uploaded to many BBS's (for example, the demo Liberator
       Upload List).  Now, the file is only commented out if the /P ermanent
       switch is NOT specified with the file.

     + Periods are no longer automatically appended to filenames without
       extensions, on File Lists.  If you entered the filename "TEST" on a
       Download List, The Liberator would append a "." and send the request
       for "TEST.".  This was to prevent the board from applying its default
       extension (usually .ZIP), but I feel it will be more useful to
       actually LET the default be applied.  This means you needn't enter the
       .ZIP extension on your File Lists, if your BBS assumes .ZIP as the
       default extension.  But it also means that if you actually WANT the
       file "TEST" (not TEST.ZIP) that you must append a period yourself on
       the list.  This is the case for manual transfers as well though, so
       should be no surprise to anyone.

     + Fixed a problem when transferring files in batch mode.  On secondary




     The  L i b e r a t o r  v2.31                      NEW-FEAT.DOC - Page 4
     
     

       batches, the first filename was entered twice.

     + I disabled the automatic enabling of auto-Zmodem in an earlier
       release, but have re-enabled this ONLY if the protocol you set up for
       is Zmodem (internal Telix).  Thus, just before a transfer, The
       Liberator checks which protocol you have set up, and if it is internal
       Zmodem, the current status of auto-Zmodem is saved, auto-Zmodem is
       turned on, the transfer is carried out (by Telix automatically, as is
       the best way with internal Zmodem), then auto-Zmodem is restored to
       its original value.  This means that you need not keep auto-Zmodem
       turned on all the time, for example, if you use DSZ's Zmodem for some
       types of transfers.

     + For those using high-speed modems and/or computers, a 5 second delay
       was added before checking for a carrier after the connection is
       established.  This should fix the << Connection Lost >> message that
       showed up on some systems.  Some modems tell Telix no carrier exists,
       even though one does, if Telix checks too soon after the connection is
       established.  Previously, The Liberator used to delay checking the
       carrier for 1 second, but this was apparently not enough on some
       modems.  Now, it waits for 5 seconds before checking for a carrier,
       but during this 5 seconds any logon questions are still answered, if
       encountered.

     + Most logon prompts are now 'freed up' (not tracked anymore) after they
       are encountered.  For example, as soon as your name is entered, the
       'Name' prompt will not be tracked further.  This takes away some of
       the safeguarding, but was quite necessary.  Many words show up in the
       opening bulletins, and if The Liberator is still tracking these
       prompts at that time, it will re-send the response, which will then be
       processed at the next prompt (whatever it happens to be).  An example
       of this was seen on one board recently, where the word "password"
       showed up in the opening bulletins about 3 times.  In this
       circumstance, The Liberator would re-send your password and a CR each
       time, resulting in (at least) a few extra CR's, or (at worst..
       depending you your password) sending erroneous commands to PCBoard.

     + The "Prompt not found" timeout during the logon is now 10 seconds
       while waiting for the first prompt, and 15 seconds between prompts
       that follow.  This allows a little more time for slower baud rates
       and/or slow NEWS items.

     + The default format of some prompts was changed, in order to support
       PCBoard 14.5 better.  Most prompts should work on PCBoard 14.2 OR
       14.5, which will hopefully get more people up and running without
       playing with prompts.  The default prompts all work fine on CRS, or
       any board where the default PCBoard prompts are being used, or are
       available through a 'Language #' as on CRS's language 3 - Default PCB
       Prompts.

     + Added support for the 'Is this correct?' prompt, which is displayed
       after entering your name on some (very few) boards.  I have no idea
       why the world needs this prompt (Sysops must explicitly request that




     The  L i b e r a t o r  v2.31                      NEW-FEAT.DOC - Page 5
     
     

       it be displayed), but added support in any case.  The prompt is
       HARDCODED in, so if your Sysop not only enables the prompt, but also
       changes its format, The Liberator will not support the prompt.  In
       this case, you could modify PCBOARD.SLT and use it as a 'Custom Logon
       Script' if necessary, but I feel it would be more useful to simply ask
       your Sysop to remove the prompt or change it back to its default
       format.

     + Hardcoded in support for a prompt which (thus far) I've only seen on
       CRS.  There, if you upload a file that already exists, it asks whether
       to over-write the existing file.  If this prompt is found The
       Liberator sends an 'N' (No), and marks the file as a duplicate as
       usual.

     + Hardcoded in support for yet another prompt... The "Proceed with
       logoff" prompt is now handled by sending a 'Y'.  However, since the
       prompt is hardcoded in, if the Sysop not only enables this prompt but
       also changes its format from the default, you will have to create a
       Custom Logoff script to use on that board (better yet, ask your Sysop
       to disable the prompt or set it back to its default format so others
       don't have to go through the same extra work).

     + Added '0=None' to the Tools' Configure item 'Qmail Packet Renumbering
       type'.  If you select this item, The Liberator will not perform any
       maintenance at all on your Mail Packets.

     + Added a 'Send ESC' item to the Control Menu.  The Control Menu is
       displayed if you hit ESC in the middle of a job, in order to pause or
       abort the Command File.  If you actually need to send an ESC code to
       the BBS, select 'Send ESC' when the Control Menu is displayed.

     + The Liberator now scans the TELIX.CNF file in a more reliable way, in
       order to get the Telix screen colours (registered users only). 
       However, in order to scan the file more reliably, it now takes a
       second or two longer to read the file.  To compensate for this extra
       time, the file is now only scanned if its modification date changes
       (you update it using the Telix Configuration 'Write setup to disk'
       item).   Previously the file was read every time you started The
       Liberator.

       This should shave a second or so off the startup time, for startups
       when TELIX.CNF has not changed... but it will add a second or so to
       the startup time when TELIX.CNF _has_ changed.

     + If no capture file was defined, the program attempted to open a
       capture file using the name of your usual capture directory (e.g. if
       your default capture was C:\TEMP\TELIX.CAP it would try to open
       C:\TELIX\).  This has also been fixed.

     + If you had another problem, and it no longer exists... it was also
       fixed.  Sorry, but a couple of other minor things were fixed and not
       taken down.




     The  L i b e r a t o r  v2.31                      NEW-FEAT.DOC - Page 6
     
     




     The  L i b e r a t o r  v2.31                      NEW-FEAT.DOC - Page 7
     
     

     05-11-90  Release 2.31.  Maintenance release.  First release of v2.3
               distributed widely.  Also see v2.30 new features below for
               major new features if upgrading from v2.2.

     Version 2.31 New Features:

     + Two new switches are available for your File Lists, which allow upload
       and download passwords to be specified.  Not many PCBoards implement
       passwords for file transfers, but for those using boards that do:

       /u-pass may be used to specify an upload password.  The hyphen may be
               substituted with any character except a space or tab (e.g.
               /u:pass /u=pass, etc.), and 'pass' should be substituted with
               the actual password.  When the switch is found on your Upload
               List, the specified password is stored in memory, and will be
               sent if the PCBoard sends the 'Password' prompt (defined on
               CFG screen 2) after entering a filename to upload.  If the
               board prompts for a password before a password switch is
               found, your regular PCBoard password is entered, as defined in
               the Telix directory.
       /d-pass is the same as above, but is used to specify a download
               password.

       Note that as with any switch, you may specify more than one on the
       same line.  If you wish to permanently leave a password switch on your
       list, use the /P ermanent switch, or a comment (commented lines are
       considered permanent items):

       /u-pass /P
       /u-pass // This is a comment.

       If you don't use either of the above, the password switches are
       treated as temporary, and will be removed from your list after being
       read.  See below for information on other File List switches/items.

     + If The Liberator is unable to OPEN a door twice from ProDoor, it now
       QUITs back to PCBoard and tries to open the door again from there. 
       Some boards (CRS for example) don't allow doors to be opened from
       ProDoor, and this feature can save the session for these instances.

     + This isn't a Liberator new feature, but just some great news.  The
       Telix Support BBS is now running PCBoard, and Qmail, MarkMail doors!
       As everyone may know, this isn't the easiest BBS to get through to,
       but now you can have The Liberator carry out the session for you!  If
       you normally logon to the support board to get new files, use the
       Liberator's @MakeList command in a Custom Command to get the new file
       list and capture it to a Download List.  See MAKELIST.DOC for more
       info.

     Version 2.31 Bug fixes:

     + Major problems with the RunMaster job linker fixed.  The program would
       not enable disconnect when it should have, because it thought it had




     The  L i b e r a t o r  v2.31                      NEW-FEAT.DOC - Page 8
     
     

       found another job for the same BBS when in fact it hadn't.  For
       example, if entries 1 and 10 were compared, they erroneously matched
       due to the 1 in both... if any trailing blanks existed after the
       directory number in the CFG, this also cause a bad match.  Both fixed.

     + The problem with the cursor being relocated, after connecting and
       displaying the logon box, has been corrected.

     + 'Dial Starting Time' items within Command Files were not being
       disabled when the Master was running, and Master delay times were
       being started too early.  Both fixed.

     + Unable to enter ? in Qmail download item of Command Files.

     + Increased the timeout, when opening a door, to 10 minutes... Previous-
       ly it was at 3 minutes, then 5 minutes, but one popular board is
       sometimes not even able to get the door open in this time, so the
       delay was increased... I hope 10 does it.

     + Auto-Zmodem downloads is not longer automatically turned on by The
       Liberator, as it caused problems for those using external Zmodem
       (DSZ).  If your Liberator Zmodem downloads no longer start automati-
       cally as they used to, go into Telix, select <Alt-O>, then 'Terminal
       options', then turn 'Zmodem auto- downloads' ON and Write your setup
       to disk.

     + The installation program now only ensures that your copy of Telix has
       a greater date/size than Telix v3.11.  Previously, it checked for the
       exact Telix v3.12 release date/size (according to my copy of TELIX.EXE
       from Exis), but apparently there are copies with different dates
       floating around out there.

     + The problem with the modem init string being displayed over the title
       screen has been fixed... I think.  I was never able to duplicate the
       problem but think I found the cause.

     + Entries are no longer cleared to the defaults when selecting re-edit
       (up/dn arrow) from the Command File save window.

     + The proper directory is now extracted from your default Capture
       File/Usage Log when offering defaults.  Previously the Telix directory
       was offered.  Now, the directory from the current capture file is
       extracted and used.  The Telix directory is only used if no directory
       is specified on the current capture file.

     + 'Delete source files?' prompt was being displayed 4 lines below the
       cursor after re-defining the CMD/CFG directory and copying files to
       the newly defined directory.
     + <Alt-J> to Jump to DOS didn't work from the Tools menu.

     + 'Unrecognized script variable' when leaving RunMaster fixed.

     + RunMaster, and the Command File Manager now check for ^Z, and will not




     The  L i b e r a t o r  v2.31                      NEW-FEAT.DOC - Page 9
     
     

       display it as a job to select in the Master.  The ^Z would be intro-
       duced by some editors, when people manually edited MASTER.CMD.

     + Problem recognizing the end of PCBoard batch downloads fixed. 
       Previously, you had to hit <Enter> to get The Liberator (actually a
       Telix problem) to see the Command? prompt.

     04-23-90  Release 2.30.


     Version 2.30 New Features:

     + The 'Master' now runs quite a bit differently than it used to.  A
       'Master Redial Attempts' item has been added to the Liberator Main
       Configuration, and the number defined here is now used when running
       Command Files with RunMaster.  If a connection is not established
       within the number of attempts set in 'Master Redial Attempts', the job
       remaines in a 'queue' to be tried again later!  Unsuccessful jobs
       remain in this queue selectively (for example, if a job aborts due to
       'Nothing to do', it is removed from the queue), and each is tried
       again between any successful jobs.  The Liberator now keeps very good
       track of why a given job was aborted (see 'Abort Codes/Remedies' in
       LIBERATE.DOC), and only keeps jobs in the queue when appropriate.

     + RunMaster now also checks if there are multiple jobs to be carried out
       on the same BBS.  If it finds any, all are carried out without
       disconnecting!  To detect whether a job is to be run on the same BBS,
       The Liberator checks each Configuration defined for each job in the
       queue, and compares Dialing Directory entry numbers with the current
       job.  If at least one entry number matches on any other job in the
       queue, disconnect is disabled and both jobs will take place without
       disconnecting.  When the second job is started, the queue is checked
       again for another job to run on the same BBS, etc.  When no further
       jobs are found, disconnect is enabled.

     + The 'Dial Starting Time' option of each Command File is now automati-
       cally disabled when the Master is running, and you may specify
       starting times right in the Master list itself. Combined with the
       queue, and the ability to carry out multiple jobs without disconnect-
       ing, you can now do some pretty involved stuff with the Master.  If
       you skip reading the new manual, I recommend you at least see the
       section on the Master (near the end) for some examples of how the
       queue, multiple jobs on the same BBS, the EXIT command, the REPEAT
       command, and Master Dialing delays now behave.

     + Support for the PCBoard UB (Upload Zmodem Batch) and DB (Download
       Zmodem Batch) commands has been added!  Since this was a fairly new
       PCBoard feature at release of The Liberator v2.3, the PCBoard version
       # being used on the BBS must be specified in each BBS Configuration. 
       PCBoard v14.5 or greater must be specified before The Liberator will
       attempt any PCBoard batch transfers (ProDoor batch transfers are still
       available if your BBS is older).  As well, multiple-line upload
       descriptions are now supported when performing PCBoard batch uploads.




     The  L i b e r a t o r  v2.31                     NEW-FEAT.DOC - Page 10
     
     

     + ProDoor batch transfers have been cleaned up and now should operate
       without any special configuration.  The program now automatically
       recognizes a full 'batch' in both upload and download mode.  If you
       specify more characters in your upload descriptions that the BBS can
       handle, The Liberator will also detect this.

       Only as many filenames as Telix can handle per batch will be entered
       for the batch uploads.  Telix has a maximum of 64 characters per batch
       for a batch upload specification, so The Liberator may need to perform
       more than one batch upload to transfer all the files on your Upload
       List.  Previously, the 64 character limit was not known, and The
       Liberator would enter many filenames, attempt to pass them to Telix...
       but Telix only accepted the first 64 character's worth resulting in
       some files not being transferred.  Now, the (undocumented) 64
       character limit is observed.  Simply create your Upload Lists as
       usual... The Liberator handles all this automatically, and it is only
       mentioned for your interest, in case you wonder why The Liberator
       sends more than one batch when uploading.

     + File uploads are now carried out before downloads, to allow the
       remainder of jobs in the session to take advantage of any extra time
       or download bytes awarded for the uploads.

     + The format of Joining conferences has been changed in Up/Download
       Lists from a '*J nnn', which used to be placed AFTER the filename, to
       a 'switch' in the format /#nnn, which must be placed BEFORE the
       filename.  Also, a /P switch is now supported in File Lists, and this
       causes the line to be 'Permanent'.  As you know, The Liberator
       normally removes filenames from your list once the transfer is
       successfully completed.  To override this, use /P at the beginning of
       the line (this can be used to download, or upload the same file a
       number of times... for example, to download an online publication
       daily, etc).  Example:

       /P /#2 TEST.ZIP This is an Upload test.

       The above, if used in an Upload List, causes The Liberator to J)oin
       conference 2 (due to the /#2 ), request an upload of TEST.ZIP, and
       type in the description 'This is an Upload test.'. The file remains on
       the list permanently, due to the /P switch.

       File List switches may also be used separately, on a line by themself. 
       In this case, they affect the next valid filename on the list.  For
       example, if you wanted to leave a permanent 'Join conference' switch
       on your list, you could place:

       /#2/P

       ...at the top of your list, and the line remains permanent, and will
       cause conference 2 to be joined before uploading the next valid
       filename.  The current conference is also stored in memory, and The
       Liberator will not try to re-join the same conference, if a second /#2
       is found later on the list!  Please see the section 'File Transfers'




     The  L i b e r a t o r  v2.31                     NEW-FEAT.DOC - Page 11
     
     

       in LIBERATE.DOC for more information.

     + Since The Liberator allows up to 500 characters per line in your File
       Lists, you may take advantage of lengthy file descriptions, which are
       sent to PCBoard/ProDoor when uploading the file.  In previous
       releases, if the description 'overflowed', (if the PCBoard/ProDoor
       only accepted a portion of the description you defined) it made quite
       a mess of the next filename entry.  Now, The Liberator watches for
       overflows, and will attempt to backspace over any overflowed charac-
       ters.

     + The Liberator is now considerably more aware of its surroundings, and
       is much more flexible.  The program is now capable of reading the
       screen, much as you would, and can determine its position from any of
       *eight* key locations on PCBoard and in the various doors.  The
       Liberator can start any job from any of these eight locations.  If it
       cannot locate its position, it prints a message on the screen and
       sends a CR to the BBS to attempt to get a recognizable prompt up! 
       This continues for 3 attempts.
       The eight 'key' locations can be recognized in each Liberator BBS
       Configuration by an asterisk (*) following the prompt description.

     + The Liberator also uses extra protection for logons.  If none of the
       sixteen logon prompts are are detected within 10 seconds of a connec-
       tion, The Liberator now displays a message on the screen and sends a
       CR to attempt to get a prompt up.  This is takes place up to three
       times if necessary, and if after three CR's no recognizable prompts
       are detected, the program disconnects.  This feature can be essential
       for boards that require a CR to be sent before the logon begins.

     + Doors are now opened from any point where it is possible (PCBoard,
       ProDoor or ProLogon).  Previously, The Liberator was programmed to
       start every job from PCBoard, but now PCBoard itself need not even
       appear!

     + The above new features have permitted full ProLogon support (in
       theory... largely untested due to the lack of ProLogon boards in my
       area).  Since the program can now start any job from the ProLogon
       menu, or from any of the other key locations, it should have no
       problems if the ProLogon menu shows up between any major task.  This
       is actually quite necessary, since ProLogon is very configurable and
       behaves differently from BBS to BBS.

     + Default prompts are now instantly available for Qmail v2, Qmail v3 and
       MarkMail doors.  You simply specify a Mail Door type on the Qmail
       screen of either Qmail v2, Qmail v3, or MarkMail.  The prompts are
       automatically adjusted for the type of door you select.

       The Qmail Configuration screen has been moved from screen 3 to screen
       4, and only appears if a Mail Door is defined.  This allows you to
       quickly get to the Mail Door items by hitting <Up arrow> from screen
       1, which takes you to the last screen.




     The  L i b e r a t o r  v2.31                     NEW-FEAT.DOC - Page 12
     
     

     + You may now specify both a PTR reset upload, and a regular REP upload
       for Qmail v3 doors.  Previously, only one or the other could be
       specified.

     + A new Mail Door feature called 'Repeat Downloading' has also been
       added.  With Repeat Downloading selected, The Liberator carries out
       repeated packet downloads, until the 'No new messages' prompt is
       found.  This is useful for the occasions when you get behind on the
       mail, or if you are a Sysop picking up mail from a large hub. 
       Supported in all door types.

     + You may also perform 'Personal mail only' downloads in any Qmail v2/v3
       or MarkMail door.  In Qmail v3 doors, you may specify to scan ALL
       conferences for either regular downloads or Personal downloads.

     + SESSION.TXT information was previously 'clipped' from the capture
       file, to insert in your mail QWK packets, but now the information is
       duplicated for the SESSION.TXT file, and also remains in the capture
       file.

     + The 'User Command' options, available in each Command File, have been
       changed to 'Custom Commands'.  With Custom Commands, you may carry out
       jobs not supported internally by The Liberator, such as downloading
       mail from a BBS without a Mail Door, etc.

       A new 'special' character has been made available for use in your
       Custom Commands, and it is the vertical bar (|).  If you specify a
       vertical bar at any point in your command, it causes The Liberator to
       send a CR (<Enter>) then to wait for one of the eight 'key' prompts
       mentioned above.  The usual ^ to specify a Control character, ~ for a
       half-second pause, and @ to run a Telix script are still supported in
       Custom Commands.

       While sending Custom Commands, The Liberator now automatically handles
       a number of common PCBoard/ProDoor prompts that tend to show up
       frequently when sending commands ('More', 'Pause', 'Scan message
       base', etc).

       You have always been able to execute other Telix scripts within
       Liberator sessions, by using Custom Commands, but now you may also
       pass 'parameters' to scripts, which could specify certain filenames,
       etc.  The MakeList and CapCmd Custom Commands, (explained below) are a
       good example of what can be done with these parameters.

     + The new MakeList Custom Command allows you to capture the results of
       PCBoard/ProDoor commands to your Download List for use in the same
       session!  Define one or more F)ile Directory, L)ocate, N)ew Files, or
       Z)ippy Scan commands, and MakeList will send them for you, in multiple
       conferences if desired, and place all resulting filenames/descriptions
       on your Download List.  The correct conferences are maintained in the
       list, and will be re-joined when downloading takes place!  You can
       even have MakeList execute your Text Editor to manually edit the List
       before downloading takes place.  See MAKELIST.DOC for full instruc-




     The  L i b e r a t o r  v2.31                     NEW-FEAT.DOC - Page 13
     
     

       tions on using this powerful command.

     + A new feature called 'Backspace protection' has been added.  Before
       The Liberator sends any response to the BBS, it first sends a user-
       defined number of backspaces to eliminate any line noise.  These
       backspaces do no harm if no line noise was present, but can be very
       important if any was...

     + The questions asked when Command File items were set for interaction
       (with a ?) have been removed, and the program now uses the Command
       File Display screen.  This will give you a picture of the entire
       session, and not only the item(s) set for interaction.  You may now
       also call up the DOS functions menu or shell to DOS while on this
       screen, using <Alt-F> or <Alt-J>.

     + You may now perform interactive selection of the entry numbers to
       dial!  If you leave the 'Telix Directory Numbers to Dial' item (on CFG
       screen 1) blank, then The Liberator will display the Telix dialing
       directory and allow manual selection of entries.  Make sure you select
       only PCBoard entries, or The Liberator will not be able to automate
       the session properly.  Please note that Configurations set up like
       this are not usable when the Master is running.  All interactive items
       are always disabled when while the Master executes.

     + The Liberator does not simply abort now when you hit <Esc>, but
       instead pauses the Command File and displays a menu, from which you
       can carry out DOS tasks, or perform capture/usage file operations. 
       When ready to continue, simply hit <Enter> and the Command File will
       pick up where it left off.  Or, to abort the Command File, select
       abort from the menu.  If you abort, as always, The Liberator will not
       simply dump you in terminal mode, but will carry out any housekeeping
       duties, such a Qmail packet maintenance, before returning you to
       terminal mode.

     + It is now much easier to enter characters manually, while online, than
       it was previously.  Previously, each character many have had to be
       tried several times before it was accepted, but the cause was found
       and eliminated.  The only time you may have to hit a key more than
       once, is when attempting Telix <Alt> key or function key tasks.

     + Support has been added for door NAMES as well as numbers.  PCBoard
       v14.5 and greater, and ProDoor/ProLogon allows the use of a door name,
       instead of the number.  For example, QMAIL would be entered instead of
       3, or whatever the door number was.  If your Sysop has set up for door
       NAMES, simply put the proper name in your Configuration File.  Door
       NAMES are more stable, and will tend not to change as much as door
       numbers.

     + Support has also been added for PCBoard conference NAMES.  The
       Liberator has always supported conference NAMES in ProDoor, but only
       recently have conference names been supported on PCBoard.  If your
       PCBoard supports conference names, you can use the name in the
       'Conference to Join at startup' item, or in your Up/Download Lists.




     The  L i b e r a t o r  v2.31                     NEW-FEAT.DOC - Page 14
     
     

     + The 'Conference to Join at Logon' item, available in each Configura-
       tion, has been changed to 'Conference to Join at Startup'.  Previous-
       ly, this conference would only be joined if an actual logon took place
       (which doesn't happen if you start The Liberator online...).  Now, the
       conference is always joined before starting the first job, but you
       must be at a PCBoard or ProDoor prompt before you start The Liberator.

     + The Liberator performs 'online' time checking, in which it actually
       reads the prompts to determine how much online time you have left. 
       Both standard time prompts are recognized, including (120 min. left)
       ...or... (10 used, 110 min. left) formats, which show up at most
       'main' menus.  The Liberator has used this time checking (undocu-
       mented... used to adjust ProBank deposits) since v2.0, but now you may
       turn the feature off, or even set a specific number of minutes to
       save; after which, The Liberator will cancel further jobs and logoff. 
       Your BBS must be using one of the formats listed above to make use of
       this feature.  Time checking is configured on screen 1 of each
       Configuration in the 'Online time to save' item, and defaults to 5
       minutes.  This means when the main prompt reaches (5 min. left), The
       Liberator will cancel further jobs and logoff.

       Note that if The Liberator cannot make sense of the current prompt (it
       isn't using either format), then time checking is automatically
       disabled, but you may also manually disable it if necessary by
       entering 0 in the 'Online time to save' item.

     + The 'Response Delay', set in each Command File now uses a 'real time'
       delay instead of the the system (processor) clock, which changes from
       machine to machine.  You may have to adjust your delays, now that real
       time is used.

     + Some problems were encountered in earlier releases, when using
       alternate Command Processors (4DOS) or when SHARE.EXE was loaded.  As
       well, there was a problem with OS/2 when certain operations took
       place.  All of these have been fixed (I hope).  Now, The Liberator
       does not use a Command Processor at all, and all DOS tasks are carried
       out by internal SALT functions.  The only time a command processor is
       required is to add a SESSION.TXT file to a newly downloaded QWK
       packet, or to call your Text Editor.  As well, the use of temporary
       files was virtually eliminated (and now observes SHARE where used),
       which was the cause of the SHARE violation.

     + An external script is provided (CAPCMD.SLT), to allow you to capture
       the results of any PCBoard/ProDoor command (B)ulletin, NEWS, etc.) to
       a specified file.  To use it, simply compile the script, copy it to
       your script directory, then place the command: @CAPCMD <capture_file>
       <BBS command>
       in Custom Command[s] 1 or 2 of any Command File.  See 'Custom
       Commands' in LIBERATE.DOC for more info.

     + QWK/REP mail packet maintenance can now take place in two ways.  The
       Liberator originally started by placing numbers in the <ID> part of
       the packet name, when renumbering older packets (e.g. <ID>nn.QWK), but




     The  L i b e r a t o r  v2.31                     NEW-FEAT.DOC - Page 15
     
     

       due to problems Deluxe had with the <ID> being lost, the numbers were
       moved to the extension part of the filename (e.g. <ID>.Qnn).  Now, you
       may choose whichever method you desire.  The default has been changed
       back to the original method of numbers in the <ID>.  If this causes
       problems with your Deluxe setup, select 'Tools' from the main menu,
       then 'Configure', and set the packet maintenance entry to '2'.

     + On the Command File Display screen (displayed before each job starts),
       options that are activated are now displayed in 'bold' while options
       that are not activated are displayed in 'normal' color.  This allows
       for easier viewing of which jobs are set to be executed.

     + Use of the DOS funtions menu has been expanded from just the Tools
       menu.  You may now call up the DOS Functions menu with <Alt-F>, or
       Jump (shell) to DOS with <Alt-J> at any location in The Liberator.  If
       you are in the middle of defining a Custom Command, and forget how to
       do something, simply hit <Alt-J>, to 'Jump (shell) to DOS, then TYPE
       or LIST the manual to the screen, then type EXIT when you are ready to
       return to The Liberator, and everything will be just as it was.

     + <Alt-F> (DOS functions menu), or <Alt-J> ('shell' to DOS), may be used
       while The Liberator is waiting for a dial starting time.  This allows
       you to gain control of your computer while The Liberator waits,
       without exiting The Liberator.

     + All new manual!  All you Liberator veterans may not be too excited
       about the new format of the manual, but for beginners it should prove
       to be quite an improvement.  Previously, much was left up to the user
       to figure out, simply because it was not directly related to setting
       up The Liberator.  Now, the documentation covers just about everything
       from proper Telix/modem setup, to PCBoard, ProDoor, and Mail Door/Rea-
       der setups (someone has to explain it... and I figured it would be
       more useful to new users, and Sysops who normally have to answer all
       these questions, to have the info in one place).

     + A small SALT tutorial was added, to help you automate jobs that cannot
       be handled by simple Custom Commands.  Many useful things can be
       carried out with the simple, easy-to-use functions covered in this
       tutor.

     + The Command File Manager menu has been changed somewhat, and, along
       with most other menus, will now not display all numbers up to 99, even
       when empty.  This speeds menu displays up a fair amount, if there are
       only a few entries to be displayed.

     + You can now edit a Configuration without first selecting a Command
       File.  Simply select 'E'dit from the main menu, then hit <Alt-E> and
       select the desired CFG from the menu.

     + The reName item now also updates the Command File with the proper
       Configuration name, if the Configuration is also renamed.  Renaming
       Configurations still remains risky though, since other Command Files
       may be set up with the old name, and these are not automatically




     The  L i b e r a t o r  v2.31                     NEW-FEAT.DOC - Page 16
     
     

       changed.

     + The name of the currently executing Command File is now displayed on
       the status line, if turned on in Telix.  The Liberator will check
       whether the status line is on the top line, the bottom line (only for
       25 line displays), or turned off.

     + A divider line is now placed in your Capture File, when a Liberator
       automated session begins.  This line displays the version of The
       Liberator, the Command File name, and the system date/time at the
       start of the session, as well as helps to distinguish one session from
       another.

     + On the first startup, the program now automatically selects 'C'reate
       when you reach the main menu.  This is mainly done for beginners, and
       it will only happen the first time you start the program.  The
       Liberator 'Main Configuration' screen is also displayed on the first
       startup.

     + On the first startup, or when selecting 'File Check' from the LibTools
       menu, The Liberator now checks your modem to ensure that the 'carrier
       detect' is not being forced on.  Many scripts, including The Liber-
       ator, will not operate properly with your modem in this state. 
       Instructions on fixing the problem can be found in the file TELIX.DOC
       that accompanied The Liberator.

     + The default Qmail QWK/REP/PTR directories have been changed from
       C:\DELUXE\ to your current up/download directories.  When creating new
       Configurations, see screen 4 if you use special directories, other
       than your normal up/download dirs.

     + Defaults are now offered for certain options, such as Usage Log,
       Capture File, and Up/Download List.  The defaults offered will most
       likely be forced in The Liberator v3, to allow for various new
       features I will be adding.  However, in this release you may change
       the default, if desired.

     + If the file extension is missing for any filename on your Up or
       Download Lists, a dot (.) is now added when sending it to the BBS. 
       This is done to prevent ProDoor from using its 'default' extension
       (usually .ZIP) on files without extensions.  For example, if the file
       TEST was specified in a ProDoor download, ProDoor would look for
       TEST.ZIP.  If TEST. is specified (with a trailing dot), the default
       extension is not added.

     + Each filename in your File Lists is sent through a filter, before the
       name is sent to the BBS.  Only valid DOS characters will pass through
       the filter.  This will eliminate any garbage characters that got onto
       your list.

     + In previous releases of The Liberator, each line on a File List could
       start at any position (leading blanks were ignored).  However, in this
       release, if a line starts with a blank it is ignored and removed from




     The  L i b e r a t o r  v2.31                     NEW-FEAT.DOC - Page 17
     
     

       the list.  This was done to allow more selective, error-free process-
       ing of your File Lists.

     + ProDoor did everyone the favour of changing the default format of its
       MAIN prompt.  Now, older ProDoors use '] Command? ', while newer ones
       use ') Command? '.  Rather than cause you the hassle of finding which
       one is used, and plugging it into your Configurations, I simply added
       both to each Configuration. (Getting close to 50 prompts in each CFG
       now, and this type on nonsense doesn't help any.)

       PCBoard also found it necessary, for some reason unknown to me, to use
       different prompts for 'batch' transfers than it does for non-batch
       transfers.  Rather than include both sets of prompts (there's no room
       left on the PCBoard Prompts screen), the prompts are automatically
       adjusted by The Liberator, depending on which type of transfer you
       select.  This means a limitation of only being able to perform one
       type of transfer on PCBoard--batch, or non-batch.  You cannot carry
       out both with the same Configuration (for example, perform a batch
       download, and a non-batch upload).

     + Custom Commands are now ignored if containing only spaces.

     + PCBoard 'Name' prompt added to each Configuration.  Previously, The
       Liberator simply entered your name a second or so after entering the
       'Graphics' question... but on some BBSes there is no graphics question
       so a name prompt had to be added.

     + Default 'Sound' item in each Command File now defaults to 'None' (no
       sound), since it is never really necessary to have sound turned on. 
       If you set The Liberator to complete without disconnecting, it will
       page you to return when it is finished.

     + The 'Minimum # of files per batch transfer' item, in the Pro Utilities
       screen has been changed to 'Transfer in ProDoor if how many files?'. 
       This more clearly states the purpose of the item.  As well, now files
       on both the Upload and Download Lists are counted, then compared to
       this item.

     + The 'Logged off board' prompt, on CFG screen 2 has been changed to a
       more appropriate 'Run Logoff Script', since this is mainly what it is
       used for.

     + The proper 'ProDoor batch full' prompt is now used, and The Liberator
       will recognize when the end of a batch entry and carry out the
       transfer.  As many new batches as necessary are started.

     + The Qmail 'Ready to receive' prompt has been re-defined to a format
       used for both REP and PTR uploads.  The 'Send .PTR' prompt was
       removed.

     + ProDoor 'More' prompt added (defined on Pro Utilities screen). 
       ProDoor uses a different format for the 'more' prompt, so it was
       necessary to define different 'more' prompts for both. 











               SALT.DOC Copyright (C) 1990 Liberation Enterprises.
                   An introduction to Telix's script language.


     This is not a comprehensive SALT tutor, and if you are seeking such you
     won't find it here (a more extensive tutor will most likely be released
     in the future).  If you understand the logon scripts provided with
     Telix, then you will probably be wasting your time reading this.  This
     document was designed for beginners, and simply explains some basics of
     SALT, for Telix v3, and some easy-to-use but useful functions. 
     Everything is explained in simple terms, to enable non-programmers or
     new Telix users to write usable scripts.  You will also be shown how to
     make use of the SALT manual.

     Learning SALT is usually the only major obstacle people run into with
     Telix.  As I'm sure you are aware, SALT is one of, if not the most
     powerful 'script' language available for any communications program. 
     Unfortunately, extra power usually translates into a more involved
     learning process--the more power (or features) you have, the more there
     is to learn.  However, you need not learn the entire language and study
     the entire SALT manual to create useful scripts.  There are a few SALT
     statements and functions listed below, that will enable you to automate
     fairly complex tasks, without getting into any major programming.  The
     functions are:

     capture();     Open, close, or pause a capture file.  Specify the name
                    of the capture file between double quotes (e.g.
                    capture("TELIX.CAP").  If you don't specify a path,
                    Telix creates the file in the same directory as
                    TELIX.EXE.  See CAPCMD.SLT for example usage of
                    capture().
     cputs();       Put a 'string' of text out the communications port
                    (cputs is 'c' for communications port (modem), 'put'
                    for... put, 's' for string.  A string is just a bunch of
                    characters grouped together between double quotes; a
                    sentence (e.g. "This is a string").
     delay_scr();   Pause the script from running for a certain amount of
                    time.  This is similar to delay(), but it allows the
                    screen to be updated with incoming characters for the
                    duration of the delay.  Delays can be used to wait for a
                    prompt, etc.
     dos();         Gives you access to DOS from within a Telix script. 
                    'Access to DOS' means you can carry out a simple DOS
                    command, such as COPY, DEL, etc., or you can even run
                    another program if necessary.  The command must be
                    placed between double quotes.  Examples:
                      dos("DEL TEST.FIL"); ...or... dos("123.EXE");
     goto <label>   A script or program normally runs from top to bottom, or
                    from the first statement to the last.  To change this,
                    and skip immediately to another section of the script,
                    you use 'goto's.
     hangup();      Breaks the connection by hanging up.
     return();      End the current 'function' right where we are, and
                    return to the 'caller'.  The 'caller' depends on where
                    the return() is found.  If you return() from the main()




     The  L i b e r a t o r  v2.32                         SALT.DOC - Page 2
     
     

                    function that all scripts start at, then you return to
                    the calling script (The Liberator, etc.) or to Telix
                    terminal mode.  The Liberator tests any value you
                    return() from your script's main() function.
     waitfor();     Wait for some text to come in from the BBS, or until a
                    specified number of seconds elapses.  Combined with
                    cputs(), this is a very useful function and can automate
                    many tasks.

     Two other useful functions are:

     send();        Send a file to the BBS (upload)
     receive();     Receive a file from the BBS (download)

     You can write many useful scripts using just these functions.  However,
     your scripts wouldn't be capable of making any intelligent decisions
     using just the above... For example, waitfor() allows you to wait for a
     specified number of seconds for a certain message or prompt to come in
     from the BBS; but what if the message doesn't come in?  You don't want
     to answer a question if the question hasn't even been asked, so you
     must have some way to test whether the text came in or not.  This is
     where these two statements come into play:

     if()       Tests whether something is TRUE (successful) or FALSE
                (unsuccessful).
     while()    Does something 'while' a certain condition is TRUE.

     What's all this about TRUE and FALSE?  How do these things 'test'
     whether something is successful (TRUE) or unsuccessful (FALSE)?  There
     is just a simple rule that they follow, which says that: "TRUE is
     anything that is not zero".  The number 1 is TRUE, since it is not
     zero, the letter 'A' must be TRUE since it is not zero... 1 + 1 (one
     plus one) is TRUE, since it's end result is not zero, etc.  "FALSE is
     anything that does end up to be zero"... 0 itself is FALSE, 1 - 1 (one
     minus one) is FALSE since its end result is zero.

     This doesn't have to make sense... (and it certainly didn't for me at
     first) that's just the way it is.  Anything that results in a zero
     value is considered FALSE, anything that results in a non-zero value is
     considered TRUE.  If something is FALSE, it is also known as unsuccess-
     ful, or 'not' successful.  'Not' is used in SALT to refer to something
     that is not TRUE: if it's "not TRUE", it must be FALSE, or zero.  I'm
     attempting to burn this into your memory since it is used all over the
     place in SALT and is important to pick up.  The true/false rule makes
     scripts 'smart' enough to carry out meaningful decisions.  Almost
     everything in SALT evaluates to TRUE or FALSE and can be tested with
     if() and while().  Just using TRUE and FALSE was enough to create The
     Liberator, and many of the other programs you use.

     If I had some money, how much do I have?  I have TRUE amount of money
     (it must be TRUE since it isn't zero...).  To test the value in SALT, I
     could use:

     if (money)




     The  L i b e r a t o r  v2.32                         SALT.DOC - Page 3
     
     

     ...which is the same as saying "if money is TRUE"...  Of course, it
     wouldn't do much good just to know this unless I was going to do
     something with the information, like this:

     if (money)
      spend();

     This is how if() operates.  'If' whatever is between the brackets ends
     up to be TRUE (not zero), then the next statement (up to the first
     semicolon) is carried out: spend(); in this case.  Then we move happily
     along (by the way, scripts execute from top to bottom, unless told
     otherwise).  If whatever is between if()'s brackets evaluates to FALSE
     ('money' would be FALSE if it was equal to zero) then the statement
     immediately following the if() is *skipped*.  [Don't try to compile
     these examples... they're just nonsense used for demonstration.  Some
     usable examples are given later.]

     if (this_is_TRUE)
      then_do_this();

     The next line following an if() or while() is normally indented to show
     that it may not get executed if the result is FALSE, and depends on the
     if().  [Note that the SALT compiler doesn't care whether you indent or
     not... in fact you could place an entire SALT script all on one line an
     it will compile just fine.  Indending, and placing statements on
     different lines is done solely for the benefit of people who read the
     script.  It makes scripts easier to follow and debug.]

     Note also that the if() is not followed by a semicolon.  This is
     because if() executes the next statement UP TO the first semicolon.  If
     you use if(); then the semicolon is found immediately, and the if is
     useless.  The SALT script compiler (CS.EXE) gives a warning if you
     specify if(); or while(); like this, with no statement to execute
     before the semicolon.

     While() works in the same way as if(), but instead of only executing
     the next statement once, then moving along, it keeps running it over
     and over again until whatever is between the brackets ends up to be
     FALSE.  Since it runs the next statement more than once, while() is
     said to cause a 'loop' (you needn't remember this... it's just a
     programming term).  For example, just spend()ing ONCE is no fun while()
     we still have some money left, so:

     while (money)  // while money is TRUE, or non-zero
      spend();      // spend() some, then go back and check
                    // again in the while()
     // once the while() is FALSE, (when money is equal to zero), then
     // we exit the 'loop' and continue with any following statements

     You could also reverse this by using the word 'not'.  This would be an
     appropriate while() loop to execute after the above spend()ing spree:

     while (not money)  // while money is 'not' TRUE (not TRUE is 0...FALSE)




     The  L i b e r a t o r  v2.32                         SALT.DOC - Page 4
     
     

      work();           // go to work, then check again

     Now, I suppose you're wondering where all this is leading to... 
     Believe it or not, if you understand the above it's only a matter of
     time until you can write your own Liberator.  There isn't much more to
     The Liberator than 'if this, do that, else do this'... 'while this, do
     that', etc.  This is how all programs work.  Everything must be planned
     for and tested with statements like if() and while().  Since computers
     basically have the intelligence of lightbulbs... making a program
     appear 'smart' is a lot of work, and may require many of if/while's--
     each testing a different condition which you must anticipate ahead of
     time.  If you don't anticipate something, and if that something
     happens, the computer will not automatically handle it for you. 
     Computers know absolutely nothing about what task is actually going on,
     and basically shouldn't be considered as 'intelligent' any more than
     your toaster would be (okay... they're a *little* smarter than
     toasters, but not much).

     What if you want to do two or more things if() something is TRUE (or
     'not' TRUE)?  This is what those curly brackets are for:

     if (learning_SALT)  // if learning_SALT is TRUE
      {                  // do whatever is between {}
       read();
       practice();
      }

      or more appropriately:

     while (learning_SALT) // while learning_SALT is TRUE
      {                    // do whatever is between {}
       read();
       practice();
       experiment();
      }
     // once learning_SALT is false, the script continues here

     Now for some useful stuff to put between all these brackets.  The
     functions listed at the beginning of this document will replace the
     dummy functions I demonstrated with in actual scripts.  Don't panic,
     but I want you to take a look in the SALT manual just for a second or
     two.  If you don't have the manual printed out, you can pretty well
     forget learning anything useful in SALT, unless you have an incredible
     memory, or are multitasking, etc. and can easily browse the manual on
     disk while viewing your script... While programming any script, it is
     essential to be able to quickly check the syntax (format) and 'return
     values' of functions.

     Look up waitfor() (all functions are listed alphabetically) and check
     the 'Summary':

     waitfor (str <waitstr>, int <timeout>);




     The  L i b e r a t o r  v2.32                         SALT.DOC - Page 5
     
     

     This is not actually how you use the function.  You don't type in 'str
     <waitstr>', etc.  These items are used as placeholders, to show you
     what is expected, and where it is expected (commas always separate
     arguments).  'str' refers to a 'string' (a bunch of letter, numbers,
     symbols: a sentence) 'int' is an 'integer' (a number without a decimal
     point: 1, -5, 10, 5000, etc).  The angle brackets surround <descrip-
     tions>, to give you some idea what the 'str' (string) or 'int'
     (integer) is used for.  Above, 'str <waitstr>' would be replaced with
     the string (text) you want to wait for.  Strings must be enclosed in
     double quotes:

     "This is a string of text that could replace str <waitstr>."

     <timeout> would be replaced with the number of seconds you want to wait
     before 'timing out' (giving up).

     E.g.  waitfor("First name?", 10); // wait 10 seconds for "First name?"

     Also, check what waitfor() has to say under 'Return Value'.   As you'll
     see, it 'returns' TRUE if the string is found, and FALSE if it isn't
     found... which makes it very convenient to test with an if() or
     while().  Remember, if() and while() test the END RESULT of whatever is
     between their brackets, and if you stick a function such as waitfor()
     there, then the end result is the 'return value' of waitfor().  The
     'return value' is always the end result of a function.  Don't worry
     about how it actually 'returns' this value, or even what a return value
     is.  For now, just accept that most functions have return values that
     can be tested with if() or while():

     if ( waitfor("First name?", 10) )
      cputs("John Smith^M");

     The above may look complex, but it's really not.  The outer set of
     brackets go with the if(), the inner go with the waitfor().  '^M' (two
     characters, ^ and M) signifies Ctrl-M which is a Carriage Return or the
     same as hitting <Return> or <Enter>.  If any of your 'strings' don't
     get <Enter>ed in your scripts, add ^M to the end of the string, before
     the closing quote (").

     Is this too easy?  Now, what is stopping you from applying what you
     know about waitfor(), and the SALT manual, to the other SALT functions
     I pointed out at the beginning?  Nothing at all... that's the whole
     idea.  If you understand the above, and understand what purpose looking
     up a function in the SALT manual serves, then there really isn't much
     more you need to know about SALT.  It will only be a matter of time
     until you memorize waitfor()... then cputs()... and so on until you can
     create SALT scripts in your sleep.  The only complicated part of
     programming in SALT is trying to keep all the arguments straight (does
     int <timeout> come first, or str <waitstr> in waitfor()... etc).  This
     is why I said it will be almost impossible to get anywhere in SALT
     without instant access to the SALT manual.  After over a year of
     constant SALT programming, I still refer to the SALT manual frequently,
     just to check what goes where, and what is returned.




     The  L i b e r a t o r  v2.32                         SALT.DOC - Page 6
     
     

     EXAMPLES:

     Many useful tasks can be carried out by simply waitingfor() a question
     or message, and cputs()ing the reply or carrying out some other
     function, such as receive()ing files, or opening a capture() file, etc. 
     You needn't use the track()/track_hit() functions, demonstrated in the
     logon scripts, unless you absolutely have to track more than one prompt
     at once.

     Here's an example how to use waitfor() effectively:

     main()
     {
      if (not waitfor("First name?", 10))
       goto ERROR;
      cputs("Your Name^M");

      // this type of thing can handle many tasks.  It means: 'if
      // "First name?" DOESN'T come in within 10 seconds, jump down
      // to the label ERROR below.  Otherwise put the string "Your
      // Name^M" out the comm. port' (send it to the BBS).  Remember, 'not'
      // means 'not TRUE' (FALSE), which is what waitfor() returns if
      // <waitstr> is not found.

      // ... Continue on here with the same type of thing for the next
      // question or operation...  You can handle just about anything
      // with something like the above.  Replace the cputs() with what-
      // ever you want to do.

      if (waitfor("Command?", 10))  // logon complete?
       return;                      // end the script here to avoid ERROR:

      ERROR:                        // labels used by 'goto's end with
                                    //  a colon (:)
       hangup();                    // hangup() the modem
     }

     I created the script below for use on a local BBS, using a few of the
     functions outlined at the beginning.  The script OPENs Mark Herring's
     DeLuxe update door, hits a key at the end of each page while() the news
     is being displayed, then selects and downloads my new copy of Deluxe
     (note that you must be a registered Deluxe user to take advantage of
     the update door, so please don't ask your Sysop for access if you are
     not a registered Deluxe user).  Once compiled, I put the scripts' name
     in Custom Command 1 of a Liberator Command File (e.g. @SPUD-DL), and
     have the whole process carried out automatically--The Liberator does
     the dialing/logon/logoff, and SPUD-DL handles the download:


     ///////////////////////// SPUD-DL.SLT ///////////////////////////////
     main()
     {
      cputs("OPEN 48^M");  // open door 48; replace w/proper door# for




     The  L i b e r a t o r  v2.32                         SALT.DOC - Page 7
     
     

                           // your BBS
      // translation: put the string "OPEN 48<Enter>" out the comm.
      // port (same as typing it manually online).  Note the double quotes
      // around OPEN 48^M, which must always surround strings.

      if (not waitfor("Deluxe Update Door", 120))
       return(0);

      // translation: wait 120 seconds for the string "Deluxe
      // Update Door" to come in from the BBS.  If it doesn't come in,
      // return() a 0 to 'the caller' (if called from a Custom Command, 
      // 'the caller' is The Liberator).  You can break it down to
      // three SALT functions: if(), waitfor(), and return().  A
      // return() from main() always ends the script at that point.

      while (waitfor("Press any key to continue...", 8))
       cputs("^M");

      // translation:  wait 8 seconds for the string "Press any key to
      // continue..." to come in, and 'while' the string keeps coming
      // in, put an <Enter> (^M) out the communications port.  This
      // can also be broken down to three functions: while(),
      // waitfor(), cputs().  When 8 seconds go by without receiving
      // the string, waitfor() will return FALSE (zero), thus ending the
      // while() loop and continuing below.
      
      cputs("ALL^M"); // select ALL files for downloading (Door option)
      delay_scr(20);  // delay for 20/10th's of a second, or 2 seconds
      cputs("DOWNLOAD^M"); // send the door command to start the download

      if (waitfor("Begin your Zmodem download now...", 200))
       receive('Z', "");

      // if the prompt "Begin your Zmodem download now..." comes in 
      // within 200 seconds, then we start the download with the
      // receive().  Otherwise we ignore the receive and continue
      // below.  See the SALT manual for send/receive protocol
      // letters.  Also note that the Zmodem protocol passes the
      // filename (the BBS sends it with the file), so we don't have 
      // to specify it in the receive() function--hence the "" where 
      // the filename should be.  Receive() continues below when the
      // download completes...

      waitfor("Command? ", 10); // pause for 10 seconds or until prompt
      cputs("QUIT^M");          // then exit the door and...
      waitfor("Command? ", 120);// waitfor PCBoard prompt to let The
                                // Liberator continue.
     }
     /////////////////////////////////////////////////////////////////

     The script above is included with The Liberator, so you needn't type it
     in if you have an update door on your BBS and want to make use of it. 
     Of course, you should change the door number in the "OPEN 48" to the




     The  L i b e r a t o r  v2.32                         SALT.DOC - Page 8
     
     

     correct door on your BBS.  Simply type OPEN manually at a PCBoard
     prompt to view available doors and see if your BBS has a Deluxe update
     door.  You must have registered Mark Herring's Shareware reader, and
     have a Deluxe serial number before making use of the door.  If the door
     doesn't let you in, leave a C)omment to your Sysop with your Deluxe
     serial number.

     I called the script SPUD-DL.SLT, for SParky (Mark Herring's nickname)
     Update Door-DownLoad script.  All scripts, as I'm sure you are aware,
     must be compiled before use with the 'CS.EXE' (Compile Script) program. 
     Type 'CS SPUD-DL' to compile this one.

     You can use the above techniques to automate just about any job
     (waitfor a prompt, if not found 'goto' somewhere else, or 'return',
     otherwise enter the response).  I hope that if you are confused by any
     of the above, that you'll take the time to review it and experiment
     with some of the functions listed.  Learning the above basics of SALT
     will give you considerably more enjoyment from Telix.

     Another Telix automator allows you to create scripts using something
     like the above limited functions, but implements it so that the scripts
     can only be interpreted by the automator itself and are useless to
     Telix.  The syntax of the functions is different (dropping a bracket
     here, adding a colon there), but just as time-consuming as learning the
     actual SALT functions, in my opinion.  I think you're better off
     spending your time gaining some control over SALT itself, so that you
     are not dependant on The Liberator to run your scripts for you.  This
     gives you the chance to automate tasks on BBS's that The Liberator
     doesn't support, plus gives you more use of Telix itelf.

     For PCBoard BBS scripts though, you might as well plug the scripts you
     create into a Custom Command and take advantage of The Liberator's
     logon/logoff, dialing delay, Master, etc.  Having The Liberator execute
     other SALT scripts is very simple.  See the section on Custom Commands
     in LIBERATE.DOC for more information.

     If you absolutely have to waitfor() more than one prompt at one time,
     you must use the track()/track_hit() functions, which are demonstrated
     in PCBOARD.SLT and other logon scripts.  However, if possible start
     with only the functions pointed out above, to avoid getting over-
     whelmed.  There are quite a few functions in SALT, and I still keep the
     manual within arm's length to look up functions I don't use very often. 
     You truly won't get anywhere in SALT, without using the SALT manual,
     unless you can somehow memorize the syntax/return values for every
     function you use.  Keep the manual handy for reference, now that you
     know how to use it.  Look up functions for reference when you need
     them.

     One thing I'd also like to demonstrate, is how to define your own
     'functions' in SALT.  It is almost so easy that it's not worth
     explaining, since all you have to do is think up a name, and stick the
     function in your script, just as you create the main() function.  The
     reason I want to demonstrate functions is to save you the inevitable




     The  L i b e r a t o r  v2.32                         SALT.DOC - Page 9
     
     

     frustration of forgetting to put a ^M after your string, within
     cputs().  To avoid having to specify ^M for each string, we simply
     create a new cputs() function:

     ///////////////////// Start of script ///////////////////////////
     main()
     {
      cputs_cr("Will <Enter> be sent after this string?");
     }

     cputs_cr(str string)
     {
      cputs(string);
      cputs("^M");   // Yes, cputs_cr() never forgets the ^M...
     }
     ////////////////////// End of script ////////////////////////////

     The above is one script consisting of two separate functions: main()
     and cputs_cr() (cputs with a CR or carriage return).  You could call
     cputs_cr() 'knurts()' if you wanted to... but normally we try to make
     the name remind what the function does.  Cputs_cr() accepts 1 str
     (string) and chooses to call it 'string'.  You could also call 'string'
     anything you wanted to:

     cputs_cr(str salt_is_easy)
     {
      cputs(salt_is_easy);
      cputs("^M");
     }

     Once you stick cputs_cr() in any of your Telix scripts, you can then
     use it just as you would cputs, but without having to remember the ^M! 
     If you wanted to pause the entry of 'string' for certain time before
     cputs()ing it, you could also pass a delay to cputs_cr() like so:

     main()
     {
      cputs_cr("This is a string", 5);
     }
     cputs_cr(str string, int delay_time)
     {
      delay_scr(delay_time);  // delay_scr() pauses the script
      cputs(string);
      cputs("^M");
     }

     Using functions() can really cut down on your typing, and can make
     scripts much easier to work with -- and more reliable.

     Before coming to a close, there's also one other item, that while it
     wasn't used in any of the scripts demonstrated here, it is used in the
     logon scripts provided with Telix and can be fairly confusing to
     beginners.  What I'm referring to the equality test ==, or two equals




     The  L i b e r a t o r  v2.32                        SALT.DOC - Page 10
     
     

     signs.  Why use two instead of just one?  Well, in SALT one equal sign
     is used to actually ASSIGN a value to a specific item.  If you wanted
     to set the 'variable' stat to the number 10, you would use:

         stat = 10;

     To *test* whether stat was EQUAL TO the number 10, you use two equals
     signs:

         if (stat == 10)
          prints("This is printed if stat is equal to 10");

     If you used 'if (stat = 10)' then Telix would actually ASSIGN 10 to the
     variable stat, then of course the if() would be TRUE since 10 is a TRUE
     value (non zero).  This is one to watch for in your scripts.  Telix
     doesn't give a warning if you use the wrong number of equals signs,
     since you may have a good reason for one or two in any situation... it
     assumes you know what you're doing.  If something is getting carried
     out when it shouldn't, first check for a semicolon following the if();
     or while(); and if that's not the problem see if you inadvertanly used
     the assigment operator (=) instead of the equality test (==).

     That's it for now.  I know you probably still have many questions, but
     I hope it was informative and allows you to make some use of Telix
     SALT!











               SYSOP.DOC Copyright (C) 1990 Liberation Enterprises.
             Category and description information for Disk Librarians.
                      Program Information for PCBoard Sysops.


     * Sysops/Disk Librarians please note that this release of The Liberator
     does have counters, which display the number of times the program has
     been used, but that it does not 'expire' at a certain number.  The
     information is dislpayed only to give the user some idea how useful the
     program has been.

                                GENERAL INFORMATION

        Program name:   The Liberator [PCBoard Automation System for Telix].
             Version:   2.32.
     Developer/Price:   Liberation Enterprises; $24.95 registration.
     Online filename:   LIB232.xxx (xxx for compression type; ZIP).  If
                        posting the docs and program files separately, please
                        use the format LIB232-1.xxx, LIB232-2.xxx.
            Category:   MS-DOS Communications Programs/Utils.  Preferably in
                        the same area as Telix itself (TLX312-?.ZIP).
        Requirements:   MS-DOS 2.0 or greater/compatible computer, 2-360K
                        drives, or 1-1.2 Meg drive.  Hard drive recommended. 
                        Telix v3.12 or greater. Telix, with The Liberator
                        fully loaded requires about 250K of RAM.
         Description:   The Liberator v2.3 automates PCBoard BBS sessions. 
                        Totally unattended operation, right from dialing to
                        logoff.  Upload and download files on PCBoard or in
                        ProDoor, send/collect messages from Qmail v2/v3/v4,
                        MarkMail, MegaMail, NetMail, PCRelay doors, deposit/-
                        withdraw time in the ProBank, and even set up your
                        own Custom Commands for special jobs.  User-friendly
                        interface; no knowledge of Telix SALT necessary. 
                        Telix v3.12 or greater required.


                                 SYSOP INFORMATION
                                 -----------------
     Thank you for helping to distribute The Liberator on your BBS! 
     This program will help you and your users to make the most of PCBoard
     and all its major DOOR programs.  Absolute beginners right up to PCBoard
     experts can make excellent use of the program.  The more Liberated users
     you have calling your BBS, the more total users you will be able to
     handle before expanding to more nodes!  Busy signals are irrelevant,
     since The Liberator will dial overnight, or while the user is at work,
     for as long as it takes, with no complaints!

     How The Liberator Can Help You as a PCBoard Sysop:

     + Support for PCBoard, ProDoor, Qmail v2/3/4 doors, MarkMail doors,
       NetMail, MegaMail, PCRelay, ProLogon, and ProBank are built in, plus
       'plug-in' iNet support (the program also allows the user to carry out
       any other type of logon/logoff, with the proper scripts).  Custom
       commands/scripts can also be incorporated into sessions to enable just
       about any job to be automated, such as getting mail automatically




     The  L i b e r a t o r  v2.32                         SYSOP.DOC - Page 2
     
     
     

       without a Mail Door, capturing specific bulletins, NEWS, etc.  Support
       for multiple sessions without disconnecting, and/or calling multiple
       PCBoards without intervention is also built in.

     + The automatic installation program not only helps ensure The Liberator
       is installed properly, but also checks each file's date/time/size and
       calculates a checksum for each file to detect corruption (correct
       checksums were hardcoded in the installation program at release date,
       for comparison).  This is not a foolproof way to detect tampering, or
       a bad upload, but it does cut down substantially on the chances of it
       going unnoticed.

       If you wish to check the program before posting it for downloading,
       simply switch to the directory where the unpacked Liberator v2.32
       files are (*.SLC, *.00?, INSTALL.EXE) and type:
       "INSTALL /check" (without the quotes).

     + A tutorial is provided to carry new users through not only the steps
       necessary to set up The Liberator, but also: how to set up PCBoard,
       explaining what protocols, conferences, DOORS are, etc., how to set up
       a Mail Door and Offline Reader program, ZIP files, and lots of other
       useful information.  This information will hopefully cut down on the
       number of questions you have to answer from new users, and get them up
       and running in the fastest possible time.

     + All your users will become PCBoard experts instantly with The Liber-
       ator!  The program wastes no time reading PCBoard menus and help
       screens, and trying to figure out what to do next.  The Liberator
       types as fast as the fastest touch typist, and knows PCBoard and its
       doors inside out.  'Idle time' can be virtually eliminated.

     + Fast error-free sessions get Liberated users on and off in the fastest
       time possible, enabling you to handle more total users.  Qmail
       v2/v3/v4, MarkMail, and MegaMail-type doors are fully supported, which
       should help encourage users to do their messaging offline. 
       Instructions on setting up these doors, and general information on
       setting up an offline reader are included in the tutorial.

     + Dial Starting times can be set and saved for each automated Liberator
       session, so users can carry out sessions outside the peak hours (4am),
       meaning less of a 'prime time' crunch on your BBS.

     + Since The Liberator allows users to perform uploads almost effortless-
       ly (and automatically, while doing something more interesting, or
       sleeping), the program can help to encourage more uploads from users.

     + Transfer your Echomail automatically!  Many Sysops use The Liberator
       to transfer their mail every day.  The 'repeat downloading' feature
       (Qmail/MarkMail only) is especially useful to Sysops who collect large
       amounts of mail requiring more than one download.  PCRelay and NetMail
       are also supported, with automatic packet maintenance.

     + Collect files for your BBS automatically!  Define commands to send to
       another PCBoard (F)ile Directories, N)ew Files, L)ocate, Z)ippy Scan,
       etc.) and The Liberator will create a Download List from the resuls of




     The  L i b e r a t o r  v2.32                         SYSOP.DOC - Page 3
     
     
     

       the commands, to be used in the same session!  Download every file on
       the list, or run your editor to selectively remove filenames before
       the download.  You can even send multiple commands in multiple
       conferences, and the correct conference will be joined before
       downloading!

     + The Liberator is supported on many popular networks, including (at 
       release date):  EchoNet, HyperLink, NorthAmeriNet, Intelec, InterLink,
       RIME, and SmartNet.  If you are asked anything about the program, just
       refer the user to myself (Wayne Duff) for help.  I monitor echoed
       Communications, Shareware, and/or Telix support conferences from all
       the above networks (and any network gating with any of the above). 
       InterLink, NorthAmeriNet, RIME, SmartNet, and the Telix Support BBS
       also have Liberator support conferences, for direct support.

     A Note On Prompts

     Do the standard PCBoard prompts need changing?  As a Sysop, you can help
     users automated faster, and with the least amount of work, by using the
     standard PCBoard prompts as defined by Clark Development or the DOOR
     developer (this applies to any script/automator, and not just The Lib-
     erator).  Most of the prompts The Liberator watches for are easily
     configurable through the Command File Manager interface provided, if
     necessary.  However, due to the complete support of PCBoard and its
     doors, The Liberator watches for almost 50 prompts/messages altogether. 
     Some of which are very hard to get, as they are only displayed in
     unusual circumstances.

     Getting all these prompts, if you had changed all of them, and plugging
     them into The Liberator would be a fairly large job... especially for a
     newcomer.  Other scripts (Telix or otherwise) which don't have an
     interface may require re-programming, which not all script users are
     able to do.  Thus, on behalf of all script users and automation in
     general, it would be appreciated if as a Sysop you could take these
     factors into consideration, and weigh the benefits before changing any
     standard PCBoard prompts.  If you have few automated script users on
     your BBS today, it may not create any major difficulties to redefine a
     few prompts/messages, but I feel it will be beneficial to at least weigh
     the options, and be aware of script users.

     Some Sysops have taken these factors into consideration and provided a
     PCBoard Language called "Standard PCBoard Prompts".  Users can then plug
     this language number into their Liberator Configurations, or into their
     other scripts, and will have a standard set of prompts that can be
     counted on.  The Liberator comes 'out of the box' using the default
     PCBoard 14.5 prompts, and the standard prompts for the various door
     programs, so this can certainly be very helpful to users.

     I hope the program helps you and your users to make the most out of your
     PCBoard.  Why not sit back and let The Liberator do the work for you!











               TELIX.DOC Copyright (C) 1990 Liberation Enterprises.
                 Telix/modem setup instructions for The Liberator.


     Telix comes with its own documentation, so the entire Telix setup will
     not be duplicated here.  However, there are certain things which must be
     defined properly in Telix for The Liberator, and some of your other
     Telix scripts to operate properly.

     Obtaining Telix v3.12

      First and foremost, you must be using Telix v3.12 or greater, since The
      Liberator takes advantage of some new SALT features in this release. 
      The installation program checks the date of your TELIX.EXE file to
      confirm the proper version, and will notify you if you have an earlier
      release of Telix.  If you do, you must get v3.12 and install it as per
      Telix's instructions, then continue here.  You should be able to find
      Telix v3.12 on your favorite local BBS.  The Telix files are normally
      called TLX312-1.ZIP, TLX312-2.ZIP and TLX312-3.ZIP, though the ZIP
      extension may vary.  Try a L)ocate command of "L TLX312*.*" (no
      quotes).  If you cannot locate Telix v3.12 in your area, the Telix
      Support BBS in Toronto always has the latest release available for
      downloading.  The phone number is (416) 439-8293.

     Configuring Telix

      To configure the various options outlined below, you must get to the
      Telix Configuration menu by typing <Alt-O> from Telix terminal mode.

     Turning On The Status Line

      The Telix status line is a line on the bottom or top of the screen,
      which starts with 'Alt-Z for help', then lists some other information. 
      If you already see this line, skip to the next section.

      If The Liberator aborted due to the fact that your modem was forcing on
      the 'carrier detect', you must turn the Telix status line on until we
      get this problem fixed (you may turn it back off afterwards, if
      desired).  The Liberator also makes use of the status line, if turned
      on, by placing the name of the Command File currently running where the
      'Alt-Z for help' would normally be, so you may want to leave it turned
      on anyway.  Select 'Terminal Options' from the configuration menu, then
      item 'D - Status line', then 'Top' or 'Bottom' as you prefer, to turn
      it on.  Hit <Enter> or <Esc> to return to the main configuration menu
      when done, then exit this menu as well.

     Setting Up Your Modem

      Now, check the right hand side of the status line.  It should have the
      word 'Offline' displayed.  If it states 'Online', your modem has not
      been initialized properly (assuming you are not connected to another
      modem.  If you are, please log off and re-check the status line).  If
      you are using a 1200 baud modem, most likely you will have to change
      the 'DIP' switch (a small bank of switches, sometimes located inside
      the modem case) that controls the 'carrier detect'.  See your modem




     The  L i b e r a t o r  v2.32                         TELIX.DOC - Page 2
     
     
     

      manual for the correct switch.  If you don't have a manual, usually
      switch #6 is used to enable carrier detect.  If switch 6 doesn't do the
      trick, try each switch (returning it to its original position when
      done) until you see 'Offline' displayed.  Once you find the correct
      switch, leave it set to the position where 'Offline' is displayed.

      If you are using a 2400 baud modem or greater, normally you must add a
      special command to your Telix modem init string.  'Modem and dialing', 
      option 'A - Init string' is where we place this command, so select it
      and add '&C1' to the end of the string (e.g.  ATZ^M~~~ATV1 X4 &C1).

      Now, exit from the Configuration menu and check the status line again
      to ensure that it displays 'Offline'.  If you defined a new Init
      string, type <Alt-M> and select 'M' to re-initialize your modem.  If
      the status line still doesn't, display 'Offline' please refer to your
      modem documentation, and look up 'Carrier detect enable' or something
      similar.  If you don't have a manual for your modem, please see the
      section on 'Getting help from your BBS' in the file LIBERATE.DOC. 
      Someone else is bound to be using the same modem and can help you out. 
      The Liberator (and most other Telix scripts, including the Host Mode)
      will not operate properly while carrier is being forced on.

     Setting The Proper Directories

      Another common Telix script problem is that no script directory is
      defined.  To check this, select 'Filenames and paths' from the con-
      figuration menu.

      From here, you should first define the drive and/or directories where
      Telix should place files you receive (download) from BBS's and where
      Telix should look for files that you want to send (upload) to the BBS. 
      If you are using floppy drives, you may want to set both to B:. 
      Otherwise, set them to whatever directories you wish (make sure the
      defined directories exist, and remember to create them before use if
      they don't).

      The Liberator allows you to define separate upload/download directories
      for each PCBoard, but will offer the directories defined here as the
      default.  A trailing backslash is also required by some scripts, but
      The Liberator adds one when necessary if you forget.  You may want to
      use one anyway, just to be on the safe side for other scripts (e.g.
      C:\DOWNLOAD\, C:\TELIX\UPLOADS\, etc).

      Next, define your Script directory by selecting option 'C'.  The script
      directory refers to where Telix should look for your compiled scripts
      (*.SLC), and likewise The Liberator.  Even if you have your scripts in
      the same directory as the Telix program, please define the directory
      anyway (e.g. C:\TELIX\ or C:\TELIX\SCRIPTS\, etc).

      The default usage and capture names are not used by The Liberator, but
      the drive/directory of the default usage log/capture file is extracted
      when offering defaults.  If you prefer to keep your capture files in a
      directory called C:\TEMP, then simply add this directory to you Telix
      capture name (e.g. C:\TEMP\TELIX.CAP), and The Liberator will also
      create capture files in the C:\TEMP directory.




     The  L i b e r a t o r  v2.32                         TELIX.DOC - Page 3
     
     
     

      Option 'H' is offered as your default Liberator Text editor, but you
      may also define a separate editor in The Liberator if desired.

     Saving Your Setup

      That's it for the Telix setup, as far as most scripts are concerned, so
      please hit <Enter> to get back to the main configuration menu, if
      necessary, then select 'Write setup to disk' so that you don't lose the
      changes when you exit Telix.

