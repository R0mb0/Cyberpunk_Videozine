

























                     ENHANCED JMODEM FILE TRANSFERS

                                 using

                        THE TELIX SALT LANGUAGE

                                   by

                          Michael K. Bozovich

                                03/20/89





    -----PHILOSOPHY------------------------------------------------------


    When I first began using the Jmodem protocol, I was blown away!
    I had been using Zmodem and thought that there was no way to beat
    it's file transfer rate.  At the same time, I was dismayed by the
    limitation of one file per transfer.  After considering this dilemma,
    I set out to to enhance the capabilities of the basic Jmodem driver
    in the hopes that the use of this advanced protocol would become
    widespread.  This set of scripts is at least a step in the right
    direction. . .


    This set of TELIX 3.11 script files will allow the seamless (almost)
    integration of the JMODEM protocol into the TELIX program.




    -----PROGRAMS--------------------------------------------------------



    The files in this package should consist of:


          JXFER.DOC          // These instructions.

          JUP.SLT            // Source code for the upload stub.
          JUP.SLC            // Compiled upload stub.

          JDOWN.SLT          // Source code for the download stub.
          JDOWN.SLC          // Compiled download stub.

          JXFER.SLT          // Source code for the "inner workings".
          JXFER.SLC          // Compiled "inner workings".

          JSIZE.C            // Source code for the "kludge".
          JSIZE.EXE          // Compiled "kludge".

          JMODEM.COM         // The Jmodem driver.
          JMODEM.DOC         // The Jmodem Documentation.




    -----INSTALLATION----------------------------------------------------


    A. The first step in integrating Jmodem is to tell TELIX the following
       in the "File transfer protocols" Setup screen:

          1.  Key               -  Whatever you like. (I use "J".)
          2.  Protocol Name     - "Jmodem"
          3.  Upload Filename   - "JUP"
          4.  Download Filename - "JDOWN"
          5.  BAT or Script     - "Script"
          6.  DL Name           - "N"


    Your screen should resemble this:

    ีอต File transfer protocols ฦออออออออออออออออออออออออออออออออออออออออออธ
    ณ                                                                      ณ
    ณ External           Key   Protocol    Upload   Download  BAT or   DL  ณ
    ณ Protocols                Name       Filename  Filename  Script  Name ณ
    ณ                                                                      ณ
    ณ A.................  J    Jmodem        JUP    JDOWN     Script   N   ณ
    ณ                                                                      ณ
    ณ B.................                                                   ณ
    ณ                                                                      ณ



    B. The next step is making sure that all of the necessary files are where
       they belong:

          1.  The following files belong in the "Script directory".
              This is where you told TELIX to look for script files.
              (Option "C" in the filename/path setup.)

                              JUP.SLC
                              JDOWN.SLC
                              JXFER.SLC

          2.  These files must reside somewhere in the DOS PATH.
              If they are not there, don't say I didn't tell you!

                              JMODEM.COM
                              JSIZE.EXE


    C. That's all there is to it.  You can begin using JMODEM with
       TELIX as though it came with the package!


    -----USAGE-----------------------------------------------------------

    These script files provide much more versatility than the standard
    "BATCH file" method of adding an external protocol.  These are some
    points to consider:

          1.  UPLOAD -

              Although some BBS's don't support it (yet), for those that
              do, you can now use JMODEM to Batch Upload as many filespecs
              as you can fit in the "upload box".  You are free to use
              wildcards as well.  All I ask (and the script file requires!),
              is that you include ONE OR MORE SPACES between multiple
              filespecs.

          2.  DOWNLOAD -

              Although TELIX doesn't allow multiple filespecs to be
              entered in the "download box", the JDOWN script file
              will accept them without a hitch.  This was accomplished
              by supplying an emulation of the "download box".  This
              WILL NOT WORK if you didn't tell TELIX to not prompt
              for the download file name as instructed above!

              You MAY NOT use wildcards in your download filespecs.
              If you attempt to do so, the script will gripe about
              it and grind to a halt.  Sorry. I will include this
              feature as soon as JMODEM recognizes the name of the
              incoming file.

          3.  PERFORMANCE LOGGING -

              In addition to the features described above, this set
              of scripts will create and maintain a log file of all
              attempted JMODEM transfers.  If you have defined a
              TELIX environment variable as described in the TELIX
              documentation, the file will be placed there.  If not,
              the file will be written indiscriminately to whatever
              drive and subdirectory you happen to be in at the time.

              This file is named JMODEM.LOG (catchy, eh?), and is
              based on the log file produced by the DSZ.COM program.

              Here is a sample:

                          TELIX JMODEM File Transfer Log

     S   7504   2400 bps      0 cps     17s 03-19-89 *ABORTED* \config.sys
     R   8388   2400 bps    247 cps     34s 03-19-89 COMPLETED c:\dl\any.zip
     S  15112   2400 bps      0 cps     17s 03-19-89 *ABORTED* a:\autoexec.bat
     R  26796   2400 bps    245 cps    109s 03-19-89 COMPLETED f:\dl\foo.zip
     R  18208   2400 bps    247 cps     74s 03-19-89 COMPLETED .\bar.zip

              - The first field indicates whether a (S)end or a (R)eceive
                was attempted.

              - The second field is the number of bytes transferred.


              - The third field is the baud rate used for the transfer.

              - The fourth field is a measure of the approximate trans-
                fer speed in characters per second.  Actual transfer
                rates will be greater than those reported.  This rate
                is set to zero if the transfer was aborted.

              - The fifth field is an approximation of the transfer
                time in seconds.  Since this time includes the time
                required to load the JMODEM driver from disk, it's
                accuracy depends largly on the speed of the drive
                used.  Actual transfer times will be less than those
                reported.

              - Field six is the date the transfer was attempted.

              - Field seven indicates whether the transfer met
                with success.

              - Finally, field eight is the complete specification
                of the file involved.

          4.  PATH SUPPORT -

              The pathnames used in uploading/downloading work ex-
              actly as described in the TELIX documentation.  Here
              is a review:

              - If you specify a path in the filespec, the script
                will respect your wishes.

              - If you do not specify a path, the script will use
                the one you specified in 'setup'.

              - If you did not specify a path in 'setup' (shame!),
                the file will end up/come from the current directory.

              - When uploading, if any single file is not found,
                the script will note it in the log and continue
                with the next file.  The fact is not noted on the
                terminal.

              - When downloading, if any single file already exists,
                the script will make an entry of "*ABORTED*" in the
                log and continue with the next file.  This fact is
                noted on the terminal.  NOTE: This works differently
                than the method advertised in the JMODEM.DOC file.
                This is strictly MY DOING and IS NOT A BUG in JMODEM!

          5.  SOURCES OF TROUBLE -

                This set of scripts uses up AT LEAST TWO file handles
                at ANY GIVEN POINT during execution.  The Jmodem driver
                may use up more during IT'S execution.  If you are ex-
                periencing problems, try beefing up "FILES=" in your
                CONFIG.SYS.

                If you are still having problems, go back and re-check
                your installation.  If you do it 'by the numbers' and
                STILL can't get it to work as advertised, you are wel-
                come to contact me as described later in this document.



    -----TECHNICAL INFO--------------------------------------------------


          For those interested, here is an overview of how this system
          works:

              A. JUP.SLC -

                 This script simply calls JXFER.SLT with a parameter
                 indicating UPLOAD.

              B. JDOWN.SLC -

                 This script draws a "download box" similar to the
                 one provided by TELIX.  The difference is that you
                 can specify as many filespecs as you wish.  After
                 the script obtains the file(s) to download, it checks
                 for wild cards in the list.  If any are found, it
                 prints a diagnostic and aborts.  If the user followed
                 instructions, it calls JXFER.SLC with a parameter
                 indicating DOWNLOAD.

              C. JXFER.SLC -

                 This script does all the work involved with the file
                 transfer/logging functions.  Based on the parameter
                 received, it determines whether it is going to Send
                 or Receive files.  It then proceeds to get the comm
                 port number from TELIX and checks for prior existance
                 of the log file.  If the log file is not found, it is
                 created and the header is written.  Next, the first of
                 two loops is entered.  These loops are best described
                 using pseudo code:


                   while (there are still files to transfer)
                      {
                      strip off a file name and qualify it with
                      regards to drive/path information;

                      if (uploading)
                         while (this filespec has wildcards)
                            {
                            get the first/next matching file;
                            upload it;
                            make a log entry;
                            }
                      else
                         if (file already exists)
                            print diagnostic;
                         else
                            {
                            download it;
                            make a log entry;
                            }
                      }


              D. JSIZE.EXE - (The kludge)

                 This program was necessary to overcome a limitation
                 of the SALT language.  Basically, it is impossible
                 to determine the size of a file in between calls
                 to the wild card expansion.  Since I need to call
                 the logging function for every file transferred, and
                 the log needs the file size, I came up with this
                 workaround using a simple "C" program.  The program
                 writes a 7 byte file that contains the size in bytes
                 of the file passed on the command line.  The script
                 program later picks up this information and uses it
                 in the log entry.  This temporary file is named
                 "JSIZE.$$$" and is erased just before JXFER.SLC re-
                 turns control to the terminal.

              E. ERRORS -

                 I have implemented absolutely NO error checking
                 where opening/closing/reading/writing of files
                 are concerned.  The files that could be affected
                 by this are associated with the logging function
                 and are in no way associated with the actual trans-
                 fer of files.

              If you want more details, check out the source code
              listings.  They are generously commented.



    -----DETAILS---------------------------------------------------------


          1.  While I have invested quite a bit of time in both
              creating and testing these programs, I make ABSOLUTELY
              NO GUARANTEE that they will work with your setup!
              I also REFUSE TO BE HELD LIABLE for any problems they
              may cause you.  Use them at your own risk.

          2.  While I DO NOT request money for this work, I will
              cheerfully accept any donations.  Let your conscience
              be your guide.

          3.  If you are at the end of your rope and are contemplating
              suicide, you may contact me at the following address:

                      MICHAEL K. BOZOVICH
                      P.O. Box 878
                      Godfrey, IL 62035-0878

              I will do what I can to help.

          4.  I hereby dedicate these programs to the Public Domain.
              Distribute them as far and wide as you are able.  All I
              ask is that you distribute this set of files EXACTLY AS
              YOU RECEIVED THEM!  Adhering to this simple request will
              seriously reduce the chances of my contracting an ulcer.
              It will also give me faith to perhaps provide similar
              functionality to other comm programs...

          5.  Above all else, ENJOY the Jmodem protocol!

