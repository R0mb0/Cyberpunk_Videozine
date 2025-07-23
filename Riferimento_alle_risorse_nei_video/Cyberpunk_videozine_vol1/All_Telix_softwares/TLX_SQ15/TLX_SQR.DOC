           TELIX-SQUARE package by Inge Vabekk (soft-ACE).
 
     NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.!
   ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
   บ                      THIS IS VERSION 1.5.                   บ
   บ I will appreciate your feedback,  whether you are satisfied บ 
   บ or not!  Messages can  be sent  to me  via private  mail at บ
   บ Oslo Hard Disco,  tel. (472) 73 12 47,  in MIX/Hjelp, or at บ
   บ Thunderball Cave, tel.(472) 56 70 17/18, in the XBoard con- บ
   บ ference. I occasionally also call other systems, but if you บ
   บ live far from Oslo,  you can call another  MBBS system with บ
   บ MIX connection to Oslo Hard Disco, or a PCBoard system with บ
   บ PCrelay connection. Route the mail to ->CAVE.               บ
   วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ
   บ The scripts for MBBS and PCBoard have been tested and found บ
   บ to work satisfactory. The RBBS script is supplied, but is   บ
   บ not completed. If you use RBBS and you can do some improve- บ
   บ ments on the scripts, please do so. However I will appreci- บ
   บ ate to be informed, so that I can make the improvements     บ
   บ available to other users as well.                           บ
   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
     NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.! NB.!

   ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
   บ    VERSION UPDATES:  Please read the file TLX_SQR.NEW.      บ
   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ  G E N E R A L   D E S C R I P T I O N  บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

  The following  describes a set of  utility programs and scripts for
  use with the communication program TELIX. This set contains several
  SALT scripts  (SALT is the  programming language for TELIX),  batch
  files, and programs, all written in C.

  All SALT scripts are supplied with source code.

  The TELIX program itself,  and the compile program CS.EXE,  are the
  obvious prerequisites to use this utility.  You should use the 3.12
  version until rev 4.0 comes out.  The CS compiler  is supplied with
  TELIX.
  A little warning: If you're not familiar with SALT, HAVE THE MANUAL
  AT HAND, AND USE IT!


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ             F E A T U R E S             บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

  The Telix_Square package gives you the following advantages:

  * Easy logging in to any MBBS,  RBBS or  PCBoard system. Later ver-
    sions are planned to include other systems as well.
    Note that the scripts only work with systems that can use English
    commands, and have prompts in English. Some Sysops choose to only
    use the native language. This will NOT work except for MBBS which
    allows the sript to change the language after logging in. For PCB
    systems, if there is no choice of language, the LOGON script will
    fail.
  * You can call  several BBSes without user intervention,  according
    to a BBS call list.
  * Continued execution of aborted call lists.
  * Timed execution start.  You may specify a start time for starting
    the calls,  after which all the  BBSes in your list are called in
    the normal sequence.
  * Automatic upload and download of messages.
  * Support of several offline mail readers and doors: MegaMail, Mark
    Mail, PCBoard, ProDoor (ZIPM) and XBoard (for MBBS and PCBoard).
  * Automatic upload and download of files.
  * Automatic updating of the BBS file lists.
  * Separate directories for download of mail packets and normal file
    download (if wanted).
  * Ability to save global parameters in memory,  so that each script
    can find them without  disc access.  Some scripts  are started by
    pressing a softkey (f-key). Since all necessary parameters are in
    a global area, no extra initialization is necessary.
  * Automatic selection  of files for  upload and download.  Your own
    directories, as well as the BBS file lists, are being checked be-
    for you're online, to minimize you phone bills.
  * While on-line, the BBS name is displayed in the status bar.
  * Automatic logoff from the BBS you're calling  (can be switched on
    and off - current setting is displayed in the status line)
  * Automatic exit from Telix  when all BBSes  in your list have been
    called (can be switched on and off - current setting is displayed
    in the status line)
  * Choice of using DSZ for uploads and downloads.
  * Supports voice calls.
  * Easy, straightforward installation.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ         H O W   T O   S T A R T         บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

  Installing the software is easy. Since you're reading this note you
  have already unpacked the TLX_SQ*.ZIP file, so you're half through.
  But before you proceed,  make sure that all default directories are
  defined  in the Telix  configuration  (menu entered  with  ALT-O in
  TELIX).  Your editor of choice  (for ASCII editing)  should also be
  defined there.

  Execute the TINST.EXE program using the command

  TINST <Telix directory>.

  <Telix directory>  is the directory  which contains  the  TELIX.CNF
  configuration file.  The installation procedure  reads vital infor-
  mation from that file and will not be able to complete without it.

  After some files have been copied to your Telix directories and the
  scripts have been compiled,  your favourite editor  is scheduled to
  edit your  NAME.DAT file.  The parameters required  should be quite
  obvious, but if in doubt, read the NAME.DAT description below.

  The install program  should now work with DOS revisions before 3.3,
  since it has been converted to a program.  However,  I haven't been
  able to try, so if it doesn't, please give me a note.

  The files copied to the Telix main directory are as follows:

  NAME.DAT     -Contains your name, address, default password etc.

  WISH.LST     -Here's where you list files that you want to download
                from the BBSes you call. This file is updated automa-
                tically each time you run the Telix_Square system.
                For the format of this file, check the description of
                DNLOAD.SLT.

  PUSH.LST     -Here's where you enter the names of files you want to
                upload to BBSes.  For the format of this file,  check
                the description of UPLOAD.SLT. Also check out program
                PPUSH,  which helps you to build a PUSH.LST file from
                a BBS list file.

  All Telix_Square files are described below. Check that you have all
  of them. Mark an entry in your phone directory with the script name
  LOGON, exit from Telix again, and call that BBS by typing
  
  c:\> fone <BBS name>
  
  If it calls the BBS and logs in without problems, you're well under
  way. You can now mark other entries with LOGON as well. However, if
  you know that the system is *not* MBBS, PCBoard or RBBS, you should
  log in manually or use other scripts.  If you have the LOG file on,
  please send me a copy of you login sequence,  and I'll see if I can
  include support for that system.


NOTE:
  The file FONE.BAT is a sample command file to start Telix using the
  Telix_Square scripts.  This file must also be modified to suit your
  own needs. Also, move it to the directory where you keep your other
  .BAT files (should be in your path).

  If you're using 4DOS  from J.P Software,  FONE.BAT should work fine
  without any additional software. If you're using the standard shell
  COMMAND.COM, you also need the programs  PUSHDIR and POPDIR,  which 
  are PC Magazine programs that can be found on nearly any BBS. Since
  the programs are quite small, I have taken the liberty to add  them
  to the TLX_SQ*.ZIP file.  It's a separate ZIP file that must be un-
  packed manually.  The programs  PUSHDIR.COM and POPDIR.COM  must be
  moved to a directory that's included in your PATH.
  If you have 4dos or another PUSH/POPD program system,  you can just
  delete them, or change the command file to use your own versions.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ          B A T C H   F I L E S          บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

FILENAME     DESCRIPTION
ฤฤฤฤฤฤฤฤ     ฤฤฤฤฤฤฤฤฤฤฤ

FONE.BAT     Sample batch file to start TELIX.
             You may specify the complete  or part of the name of the
             BBS  you want to call.  Telix starts  the script  QDIAL,
             which in turn starts  the program  FINDIAL$  to scan the
             TELIX.FON directory to find all entries corresponding to
             the name you specified.
 
             If no such name is given,  you'll be asked  to specify a
             name.  If the name is preceded by a '@' sign, it's taken
             to be a file  containing the names of the BBSes you want
             to call.
                       
             EXAMPLES:  c:\> Fone Oslo Hard  to call Oslo Hard Disco.
                        c:\> Fone @BBSes     to call BBSes  listed in
                                             the file BBSES.

             If you want to  use another phone directory,  the option 
             /Fphonedir can be added to the  TELIX run command.  This
             can be done by copying FONE.BAT to a different file, and
             add the parameter there.  Or you can use the FDIR option
             in the file NAME.DAT  to define another directory as the
             default.

Timed start: If you want dialling to start at a specific time,  enter
             the start time into the environment variable SQRTIME be-
             fore you start TELIX:

             c:\> set sqrtime=17:00
             c:\> fone <BBS>

             The above  statements  make the script wait until  17:00
             before it starts calling. FONE.BAT deletes this variable
             after Telix returns, so you will have to specify it once
             more for the next timed execution.
             The format for the time must be  EXACTLY as shown above:
             Two digits for the hour, a colon, and two digits for the
             minute. Characters in addition to these will be ignored.

Aborted calls: Whenever you have to abort the calling sequence in the
             middle of a list of BBSes to call,  you may continue the
             sequence by using the special name CONT:
             
             c:\> fone cont
             
             The script will then attempt to call ONLY the BBSes that
             were NOT called during the previous session.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ          C    P R O G R A M S           บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

FINDIAL$.EXE Program  to search the  TELIX.FON  directory to find the
             dial numbers of the BBSes you specify.
             The dial strings (one for each BBS found) are written to
             files named DIALx.STR, where x is a sequential number.
             For each successful connection made, the file is deleted
             to make sure it's not  re-used.  A successful connection
             is recognized by the fact that the download command file
             was deleted (no new download needs to be performed).


DUPECHK$.EXE Program to check for potential duplication  of the files
             listed in PUSH.LST, the upload specifications file.  For
             each BBS you call this program finds  what files the BBS
             already has.  These files are  NOT  copied to the upload
             command file for that BBS. When a file has been success-
             fully uploaded the file name is added to the file list.

             You should have one file list for each BBS you call. The
             name of this file is derived from the BBS name  by using
             the first eight alphabetic characters  (maximum).  There
             must of course be at least one legal character. 
             From time to time you should  download the complete file
             list from the BBSes you're calling, to make sure it's up
             to date.  If you use WISH.LST  to specify the file list,
             you should delete it from the list MYPROGS.LOG after the
             download, or you may have trouble to do it again later.


HAVEIT$.EXE  Program to check if a  BBS file list contains  the files
             listed in the WISH.LST file.  Files listed  in  the  log 
             file DOWNLOAD file are removed before this comparison is
             done. 

             The program is used  automatically by the scripts in the
             TELIX_SQR package.  However, if you want to do a similar
             check manually, make sure that:
             
                1. The file WISH.LST is in the current directory.
                2. The subdirectory  CAT  contains the file list that
                   you want to check.
                   
             Then type "Haveit$ <bbs name>".  Type that just like the
             FINDIAL$ program would have shortened it, for instance
             
             Don't write "Haveit$ Oslo Hard Disco"
             but  write  "HAVEIT$ OSLOHARD" .

             The file OSLOHARD.DL (for the above example) is created,
             and contains up to 50 filenames to be downloaded.

             There's always a possibility that a file name may not be
             found, and that certain strings  may be accepted as file
             names even if they are not. For instance, names starting
             with a left parenthesis "("  will not be included in the
             download list.


CRDIR.EXE    Help program to create a directory.  The only reason for
             using a program here is that the SALT  language does not
             have a "crdir" function, and using DOS commands gives an
             annoying flicker on the screen.  With a program this can
             be avoided.


PPUSH.EXE    Utility program to create a starting PUSH.LST. Use a BBS
             file list to extract files names and their descriptions.
             use PPUSH bbslist > outputfile.  The pushlist created is
             'outputfile'. If you don't specify a name, the output is
             displayed on your screen.
             You may edit this file as you wish. When using DUPECHK$,
             names of non-existing files  will not be written  to the
             <BBS>.UL file.


FINDCNF.EXE  Utility program for the installation. Now deleted.


TINST.EXE    Installation program  which  searches  the configuration
             file TELIX.CNF for keywords needed  for the installation
             procedure,  copies files  to directories defined in that
             file, and makes sure that the script files are compiled.
             Make sure that an editor has been defined in your  TELIX
             configuration, because it's scheduled by this program to
             edit your personal setup files.
             This program is NOT copied to your TELIX directory since
             it's only needed for the installation.


COMPILE.EXE  Program for quick and easy compile of SALT scripts. Move
             to the directory of your SALT scripts, type COMPILE, and
             all of them will be compiled.  Needs to have the CS com-
             piler in the same directory or in your PATH.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ         D I A L   S C R I P T S         บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

QDIAL.SLT    Script for quick and easy dialing. This script is called
QDIAL.SLC    when TELIX is started from the FONE.BAT command file. If
             a BBS name (or a file name) was specified in the command
             string, this is used to select BBSes to call.
             The script schedules the program  FINDIAL$ to search the
             TELIX.FON directory for the entry number(s).

             This method relieves you of some "pain in the neck"; you
             are now completely free to modify and sort you phone di-
             rectory, without having to worry about changing dialling
             numbers inside your scripts.
             
             Type 6 (six)  or more characters for the BBS name to put
             ALL matches found into the dial list.
             If you specify less than 6,  you'll have to confirm each
             match.  However, if there are more than one BBS with the
             same name,  you normally have to confirm only the first.
             Answer Y and ENTER for BBSes  you want to call,  or just
             ENTER to skip.

NOTE:        It will sometimes be necessary to abort dialling. When a
             dial list is being used, some BBSes may have been called
             already.
             You can call  the remaining  BBSes in the list by typing
             the special name CONT  as the BBS name,  whether you are
             using the batch file FONE.BAT:
             
             c:\> fone cont
             
             or whenever you are prompted for the name.


RING.SLT     This script is used to perform the actual calling of the
RING.SLC     numbers in your dial list. Not to be used by operator.


SSL.SLT      This script is used to  save the status line and restore
SSL.SLC      it later.



              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ  L O G O N  &  R E G I S T R A T I O N  บ
              ณ              S C R I P T S              บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

LOGON.SLT    This is the main logon script.  It searches  for typical
LOGON.SLC    strings used in the following BBS systems:

               MBBS,  RBBS,  PCBoard. Others added in future.

             When a BBS answers your call,  the LOGON script searches
             incoming strings and replies to the requests coming from
             the BBS. When the logon sequence is complete,  LOGON has
             (based on the texts from the BBS) decided which BBS type
             it's connected to. The control is then passed to another
             script, specially made for that type of BBS.
             I intend to add detection of other BBS types in addition
             to those mentioned above.

             The scripts named like a BBS type are BBS type specific.
             Other scripts  are general,  and perform their operation
             regardless of BBS type  (they may use different internal
             routines).  Information  stored  by LOGON  and the type-
             specific scripts are used to distinguish  between diffe-
             rent promts and replies.

             The scripts for up/download of mail and files are called
             automatically.  However, after they have done their job,
             they can be re-used  to have more files or mail up/down-
             loaded in the same session because the information saved
             by LOGON is still available.
             Softkeys f8-f11 are set up to schedule these scripts.


MBBS.SLT     Completes the logon to an MBBS system.    
MBBS.SLC     This script is normally called from LOGON.SLC when a ty-
             pical MBBS logon sequence is found (actually there is no
             such sequence;  MBBS is assumed if the OTHER strings are
             not found).

             This script sets the menu language to English.

             If you are not registered as a user on the  BBS  you are
             calling,  MBBSREG is called to complete the registration
             automatically.

             If the FILTer is on, it will be switched off.

             Unread messages are  GRABbed and downloaded to the down-
             load directory using the protocol defined in your  Telix
             telephone directory.


MBBSREG.SLT  Called from  MBBS.SLC  to register you as a new user the
MBBSREG.SLC  first time you are using an MBBS system.
             This reduces your online time a LOT  -  specially if you
             are new to BBSing.


PCB.SLT      Completes the logon to PCBoard (ProLogon).
PCB.SLC      This script is normally called from LOGON.SLC when a ty-
             pical PCBoard/ProLogon logon sequence is found.

             This script sets the menu language to English.

             If you are not registered as a user on the  BBS  you are
             calling,  PCBREG is called to complete the  registration
             automatically.

NOTE:        When you have contacted a PCBoard Bulletin Board system,
             you have to  find out what  DOOR  you can use for either
             MarkMail, MegaMail or XBoard.  In the TELIX phone direc-
             tory,  add the information to the entry name for the BBS
             in the following format:

             name of the bbs     D:<door>

             where <door> is the door number to open. If you are con-
             nected to a PCBoard system  and want  to use the  "ZIPM"
             method for downloading mail, you won't have to specify a
             door (the right door will be chosen for you).  Otherwise
             you MUST specify a door to use MarkMail or MegaMail,  or
             the script will probably fail.

             Example:

                Thunderball Cave     D:11 (door 11 is MegaMail door).


PCBREG.SLT   Called from  PCB.SLC  to register you as a new user on a
PCBREG.SLC   BBS using the PCBoard software. This reduces your online
             time significantly, specially if you're new to BBSing.

             Some questions  may have to be  answered manually due to
             significant differences between PCBoard systems.


RBBS.SLT     Completes the logon to an RBBS system.    
RBBS.SLC     This script is normally called from LOGON.SLC when a ty-
             pical RBBS logon sequence is found.

             If you are not registered as a user on the  BBS  you are
             calling,  RBBSREG is called to complete the registration
             automatically.


RBBSREG.SLT  Called from RBBS.SLC to register you as a new user the
RBBSREG.SLC  first time you're using a BBS using the RBBS software.
             This reduces your online time a LOT,  specially if you
             are new to BBSing.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ  U P & D O W N L O A D   S C R I P T S  บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

MAILUP.SLT   Script for ASCII upload of mail. This script relies upon
MAILUP.SLC   a special format, equal to the format used by the XBoard
             mail system for ASCII upload.

             If you have XBoard:  The XBoard offline reader/editor is 
             used to create the mail files. ÿThey will be in a format 
             tailor-made ÿfor ÿthis script. ÿThe script ÿshould ÿfind 
             these files using the information in this file. 

             If you do NOT have XBoard:  The MAILUP script expects to
             find the upload mail in  subdirectories under the upload
             mail directory.  These directories are created automati-
             cally if needed.  The names are constructed from the BBS
             name  by extracting  the first 8  alphabetic  characters
             (A-Z).  Fewer characters are used if the name of the BBS
             is short.

             Each time you want to upload mail to a BBS:
             Copy all mail destined for a BBS to its "own" directory.
             Each message must be placed in its own file. The name of
             the message files must be "MAIL", and the extension must
             be ".Mx", where x is a number from 1 to 99.  The message
             files will be uploaded in ascending sequence.
             The format of the files  is the same as for XBoard,  but
             here's a copy of the description:

             Line 1:   Conference name.
             Line 2:   Name of receiver 
             Line 3:   No. of the replied message or 0 (not a reply) 
             Line 4:   Topic or subject of message
             Line 5:   YES if the message should be relayed to other 
                       BBSes, otherwise no.
             Line 6:   YES if private message, otherwise NO.
             Line 7->: The message.

             Don't worry about  long messages.  The script will split 
             them for you if necessary. 

             SPECIAL:
             You can use a few code words in your mail package. These
             are (can be placed anywhere in the line):

             !END   - the previous line was the last line of the mail
                      packet. The message is terminated.
             !TAG   - Same as above, but your taglines will be added.
                      See the NAME.DAT file for tagline details.
             !SPLIT - The mail packet will be split here. The current
                      line (the line  containing this word) will  NOT
                      be sent.
             !INCL  - If you specify  a filename with this expression
                      (must be separated with a space) that file will
                      be inserted here with your mail package. If you
                      wish, you may write for instance !INCLUDE file,
                      which will include 'file' with you mail. 
                      Include files can NOT be nested; any code words
                      you specify will taken as part of the text.

             The code words can be written in lower or upper case, or
             the case can be mixed.


UPLOAD.SLT   Script for file upload. Files you want to upload must be
UPLOAD.SLC   listed in the file PUSH.LST, which must be in the  TELIX
             main directory.

             PUSH.LST must contain the following information:
              
             F:filename 
             D:desciption of file. May be several lines.
             D:description (cont).
             F:filename     (next file)
             D:description
             X:filename     (this file is NOT uploaded!)  

             Any line starting with something other than F: or D:  is
             ignored,  and so are all lines until  a D: or F: line is
             read. Thus you may exclude a file from the download list
             by changing F: to for instance X: .

             If you do NOT  want to upload any files,  just delete or
             rename the PUSH.LST file.
             
             Files to be uploaded  must either be in the up- or down-
             load directory,  or you must specify  the full directory
             path for the file.

             NOTE:
             The PUSH.LST file does not care to which BBS you want to
             upload the files.  The program DUPECHK$ is used to build
             a new command file with the name <BBS>.UL, which is used
             for the actual upload.  <BBS> is the "short" name of the
             BBS. See under DUPECHK$ for description.
             DUPECHK$ can be run manually to have the  <BBS>.UL  file
             built.  It will then NOT be changed until the actual up-
             load has taken place.  So, before you call the BBS,  you
             can add some new commands to the file. The commands are:

             Command             Meaning
             #:<conference>      Join <conference> before proceeding.
             +:<conference>      Join <conference> permanently before
                                 proceeding. This means that the next
                                 mail packet will include this conf.
             -:<conference>      Resign <conference> permanently. For
                                 PCB systems  the  next file will  be
                                 uploaded to this conference, but the
                                 mail scan will be switched off.
                                 For MBBS systems, however,  you will
                                 be resigned immediately. It's a good
                                 rule to always switch to another one
                                 before uploading the next file.


DNLOAD.SLT   Script  for  file download.  You must have a file called
DNLOAD.SLC   WISH.LST, which is read by the separate program HAVEIT$.
             This program reads the file list for ÿthe ÿcurrent ÿBBS, 
             extracting files that are also found there.  You are re-
             sponsible for maintaining this list file. 
             The WISH.LST  file just contains filenames.  You may use
             a file list  from one or several  BBSes to produce  this
             file. Delete all files you do NOT want.
             The list can be quite long,ÿbut longer lists take longer
             to process. However, this is usually done before you are
             on-line, ÿso the time shouldn't be critical.
             Anyway, ÿonly the first  10 ÿfiles will be requested for 
             download in each run. 

             If you edit this list  from a file catalog  you need NOT 
             remove initial spaces  or a single character before each 
             filename. Thus the following list would be accepted: 

             I file.one
              c file.two
               x file.333

             NOTE:
             The WISH.LST file does not care  from which BBS you want
             the files.  The program  HAVEIT$  is used to build a new
             command file with the name  <BBS>.DL,  which is used for
             the download. <BBS> is  the "short" name of the BBS.
             See under DUPECHK$ for description.
             HAVEIT$  can be run manually to have the  <BBS>.DL  file
             built. It will NOT be modified until the actual download
             has  taken place.  So, before you call the BBS,  you can
             add some new commands to the file. The commands are:

             Command             Meaning
             #<conference>       Join <conference> before proceeding.
                                 (used  when a file is only available
                                 in a certain conference)
             +<conference>       Join <conference> permanently before
                                 proceeding. This means that the next
                                 mail packet will include this conf.
             -<conference>       Resign <conference> permanently. For
                                 PCB systems  the  next file will  be
                                 attempted downloaded  from this con-
                                 ference area. For MBBS systems, how-
                                 ever, you'll resign immediately.
                                 It's a good rule to always switch to
                                 a new conference  before downloading
                                 the next file.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ         O T H E R   S C R I P T S       บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

GRABMAIL.SLT Script used automatically after you have logged on using
GRABMAIL.SLC the LOGON script to a BBS.  This script  performs a GRAB
             on an MBBS system,  and a ZIPM command on PCBoard.  This
             is used to fetch any mail you have not read before. This
             mail is packed  in the ZIP  or ARC format,  and you must
             unpack it and read it manually,  or by using  the XBoard
             offline reader.  You must also upload messages manually,
             or use the MAILUP script included in this package.


MEGAMAIL.SLT Script used automatically after you have logged on using
MEGAMAIL.SLC the LOGON script to a  PCBoard BBS  and opened the Mega-
             Mail door.  MegaMail commands are used  to send any mail
             you may have prepared, and to fetch new mail.  This mail 
             is in a format appropriate to the MegaMail reader.
 

TAGLINE.SLT  This script is used to send your tagline, trigged either
TAGLINE.SLC  by softkey F7, or by the text "!TAG" (quotes not needed)
             in your upload mail (when using ASCII upload). Note that
             you may have three lines for a tagline, where "taga" and
             "tagc" are sent if you're connected to a PCBoard system.
             If you're connected to  any other type of system,  lines
             "taga" and "tagb" are sent. See the NAME.DAT file.


GETNAME.SLT  This script is used to read the NAME.DAT file to get all
GETNAME.SLC  predefined variables for your setup.  This includes your
             name, address, and several other parameters which remain
             fairly constant for your installation.

             The "global" constants  are maintained and stored by the
             "GLOBAL" script, which is described below.


GLOBAL.SLT   This script is not available for calling by the user. It
             is used  to store constants  and variables used by other
             scripts,  so it's vital  for the proper operation of the
             system.


JOINCONF.SLT This script is not available for calling by the user. It
JOINCONF.SLC can only be called from other scripts.  Obviously, it is
             used to change to another conference whenever necessary.
             The script keeps track of the conference you're in,  and
             avoids switching to the current conference.


LOGOFF.SLT   This script toggles the Quick Logoff flag to YES and NO.
LOGOFF.SLC   When you press  Alt-Q  while  being online,  the flag is
             toggled from YES to NO and back again. Each time the new
             status is displayed:
             (sonl) means Stay Online - script does not log off.
             (LGOF) means Log Off     - the script logs you off.

EXIT.SLT     This script toggles the Exit flag to  Exit and  No Exit.
EXIT.SLC     When you  press  Alt-X  while  being online,  instead of
             trying to exit from Telix, the flag is toggled from YES
             to NO and back again.  Each time the new status is dis-
             played:
             (noex) means No Exit - Telix remains active.
             (EXIT) means Exit    - the script makes Telix terminate.

DISPLAY.SLT  This script is used to display the various flag settings
DISPLAY.SLC  for your Telix_Square package. Can be executed any time,
             and is called automatically by LOGOFF and EXIT.


PASSWORD.SLT This script is used to  send the current password to the
PASSWORD.SLC current BBS. You can define any softkey (f1-f12) to trig
             this script.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ           D A T A   F I L E S           บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

NAME.DAT     This name file  is needed  for all the scripts  used for
             logging on to the BBSes.  The data is read by the script
             GETNAME.SLT which copies each line into the global area.
             Each line  starts with a code word,  making the order of
             entries unimportant.
             The code word is a sequence of  alphanumeric characters.
             Both upper and lower case are accepted. Only the first 6
             characters are significant.

             Edit the file to contain your own data:

             code   contents
             -----  --------
             name:  Your user name (TWO WORDS)
             addr:  Your home address
             mail:  Your postal address
             htel:  Home phone number (include long-distance code!)
             htel:  Work phone number (include long-distance code!)
             ldcod: Local area code (may be same as above!)
             passw: Your 'default' password
                    (When you log on to a BBS the default password is
                    overwritten with the password defined for the BBS
                    you're calling.)
             state: Your country
          
             If you want received mail  to be stored into a directory
             different from the download directory for files, include
             it in the NAME.DAT file:

             dmail: MAIL  directory.  If not  specified, the mail  is
                    downloaded to the file D/L directory specified in
                    the Telix configuration.

             There is even more information. See the list below.
             The information can be entered in any order,  but do not
             forget the code name and a colon.  Codename and informa-
             tion must be on one line:

             work:  Present occupation.
             alias: Future: Login name for special systems.
             modem: Your modem brand and model.
             cpu:   The brand and model of CPU you're using.
             fdir:  Name of Telix' Phone directory.
             mdir:  Mail download directory.
             dsz:   For use only with DSZ. Specify parameters here to
                    make Telix_Square use DSZ for up/download instead
                    of using internal routines. 
             taga:  First part of tagline.
             tagb:  Second part of tagline.
             tagc:  Second part of tagline, only for PCBoard systems.

             Some of the above information, for instance your occupa-
             tion,  is used for automatic registration on some BBSes.
             Specify all to get automatic registration.

             Softkey default settings.
             You can set the default softkeys f1 to f12 by entries in
             the NAME.DAT file:

             f1:    Setting for key f1
             f2:    Setting for key f2
             :
             f12:   Setting for key f12.

             I suggest  that you define some of these keys to contain
             the names of some of the Telix_Square scripts as sugges-
             ted in the sample NAME.DAT file.

FILELIST.BBS This file is used to keep the name  of the file list for
             each BBS you're calling. When you enter the name of this
             file in your WISH.LST file this file will be downloaded,
             but the name will NOT be added to your DOWNLOAD list. So
             to avoid having it downloaded again you should delete it
             from the WISH.LST.
             If you prefer to have the name appended  to the DOWNLOAD
             file, you can delete it from the FILELIST.BBS file.  You
             can even delete FILELIST.BBS altogether.  Note, however,
             that no error message will be given if it's not found.

             Format of FILELIST.BBS (example):

             name of BBS 1 = BBS1LIST.ZIP
             name of BBS 2 = BBS2LIST.ZIP
             etc.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ            U S I N G   D S Z            บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

  The program DSZ may be used for uploads and downloads. This program
  is said to be slightly more efficient than Telix's own routines. My
  own testing gives better result with internal protocols however.
  Anyway, if you want to do so, add one entry in the NAME.DAT file:

  dsz: port 1 pa7300 pB3000 pv9

  (the above are  examples only;  you may want to  set the parameters
  differently).

  Do NOT include the speed (baud rate).  DSZ will not change it. Also
  do not include any file/directory specifications.  These are set as
  required by Telix_Square for each file to send or receive. 
  Note  that you must give  the port number.  Telix_Square could have
  supplied this number, but by defining the number here, non-standard
  settings can be supported (for instance port 3, IRQ 5: portx 3e8,5)

  The transfer protocol  is assumed to be defined in the phone direc-
  tory for the current BBS. Telix_Square uses the corresponding lower
  case character as a parameter to DSZ.  If you are not using Zmodem,
  this method may be insufficient.  Please send me a note if you must
  use a protocol that does not work. If you specify DSZ in your NAME.
  DAT file, the script will try to use it no matter what protocol you
  have selected.  So take care to avoid using DSZ with protocols that
  are not supported by it.

  The unregistered version of DSZ  does not accept a directory speci-
  fication for file downloads. Although you should register shareware
  that you're using,  I'll let this be up to you and your conscience.
  Therefore Telix_Square changes current directory before downloading
  files, to make sure that the files are stored where you want them.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ     S O F T K E Y   O V E R V I E W     บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

  The following function keys  (softkeys)  are defined  by the script
  package when supplied. All other keys can be defined as you wish.

  KEY       function
  ---       --------
  Alt-Q     When offline: Schedules the Qdial (Quick Dial) script.
            When online:  Toggles the Automatic Quick Logoff switch.

  Alt-X     When offline: Normal: Exit from Telix.
            When online:  Toggles the Automatic Exit switch. When the
            Exit switch is set,  Telix will exit  automatically after 
            the last BBS in the call list has been called.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ       K N O W N   P R O B L E M S       บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

  Scripts for connection to  RBBS systems are supplied,  but they are
  incomplete, and may not work.  I've still  decided to  supply them,
  because by using the same methods  as those used in the PCBoard and
  MBBS scripts,  you may be able  to modify them and make  them work.
  If you do,  I'll be grateful  if you make them available  to me and
  other Telix_square users as well.


              ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท
              ณ           D I S C L A I M E R           บ
              ิอออออออออออออออออออออออออออออออออออออออออผ

  I hereby donate the Telix_Square package to the Public Domain.  The
  scripts and programs  are supplied  in full,  and I've attempted to
  make them all clean and easy to read, with plenty of comments.

  Later versions may NOT be Public Domain, however.  But then sources
  will not be distributed with the package.

  You are free to change the scripts  and/or  programs in any way you
  want, and to give  modified or unmodified versions to others.  How-
  ever,  I urge you  to make it clear  whether you are distributing a
  modified or unmodified version.

  In any case I take no responsibility for the way the package works,
  whether it is modified or not.  This is solely your own responsibi-
  lity.  Also, although I will be available for questions and help, I
  can and will not offer any form of guarantee.  I am NOT responsible
  for any damages caused by the scripts or programs, whether they are
  or are not used according to the directions.

  A BIG thank you to Exis Inc. and Colin Sampaleanu who made all this
  possible by making such a superb communication program.

  Good luck, and happy BBSing.

  Inge  Vabekk
   (soft-ACE)

