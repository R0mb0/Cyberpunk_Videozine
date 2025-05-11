        LOGGIT -- TELIX USE FILE ANALYZER







                        LOGGIT -- TELIX USE FILE ANALYZER
                              (C) 1988 by Vic Baron
                           Version 3.1 -- Apr 12, 1989
        ____________________________________________________________



                                TABLE OF CONTENTS


        Overview...................................................1

        Command Line Options.......................................1

        Pathnames..................................................1

        Conventions................................................1

        Starting LOGGIT............................................2

        Selecting Date Range.......................................2

        Scan Criteria..............................................2

        Up/Download analysis.......................................3

        Output Modes...............................................3

        Batch Files................................................4

        Cautions...................................................4

        Shareware Concept..........................................5

        Appendix A.................................................6

        Appendix B.................................................7

        Appendix C.................................................8
        LOGGIT -- TELIX USE FILE ANALYZER




                                     LOGGIT

                             Telix Use Log Analyzer


        OVERVIEW

        LOGGIT is a screen oriented, menu driven program that is designed
        to provide an analysis of the Telix logfile. It will provide  the
        user with several different analysis options and output.


        COMMAND LINE OPTIONS

        The  only  command line option that LOGGIT supports is  /t  which
        will disable the default file integrity check. It will,  however,
        accept  input  from  a program such as Key-Fake.  Key-fake  or  a
        similar  program may be used in a batch file to pass commands  to
        LOGGIT thereby creating an automated analysis procedure.

        PATHNAMES

        LOGGIT  supports the standard DOS conventions for  pathnames  for
        all  files  and may be run from any directory as long  as  it  is
        included  in  your PATH. If a pathname is not specified  for  the
        input and output files, the default is the current directory.

        CONVENTIONS

        When asking for input, as in a filename, LOGGIT will display  the
        default value in  angle brackets <>. Thus, hitting return without
        any input will use the data contained within the brackets.

        On  the occasions that a yes or no input is required LOGGIT  will
        display  (y/N)  or (Y/n) indicating the default  value  in  upper
        case.

        In  using the menus, the default value is the selection  that  is
        highlighted  when  the menu is first presented.  Pressing  return
        will  select  the  highlighted function.  The  selection  may  be
        changed in two ways, either by using the cursor keys to highlight
        another  selection  or  by entering the first  character  of  the
        selection.

        Ctl-C  or  Ctl-Break will exit from any part of  LOGGIT  but  may
        leave  incomplete files on the disk if the file output  mode  was
        selected.








                                        1
        LOGGIT -- TELIX USE FILE ANALYZER




        STARTING LOGGIT

        Running LOGGIT is as simple as entering LOGGIT  at the DOS prompt
        and  pressing <return>. You will then be presented with a  series
        of menus which will define the input file and the scan  criteria.
        At  the top center of the screen will be a message  window  which
        will  prompt  you for the correct response. The menus  and  their
        options  should  be  self explanatory  but  a  brief  description
        follows:

        Enter Input filename <TELIX.USE>

        Hitting  <return>  at  this prompt will default  to  the  current
        directory  and  the  TELIX.USE file.  For  any  other  selection,
        maintained  in  the  format  of the  TELIX.USE  file,  enter  the
        complete  pathname  of  the input file. Your  selection  will  be
        displayed in the Input Window in the upper left of the screen.

        SELECTING DATE RANGE

        Next  is  displayed the menu which allows the  selection  of  the
        range of dates upon which LOGGIT will operate.

        Alldates <default>-- compile data from the first date entered  in
        the file to the last entry.

        Select dates -- allows the  selection of START and END dates as a
        range  for compiling the data. LOGGIT will start  compiling  data
        from the start date specified and will continue compiling data UP
        TO but not including the END date. Dates are entered in the  form
        MM-DD-YY.  To scan from a specified start date to the end of  the
        file, you could enter any date that is beyond the end of the data
        in the file. LOGGIT will continue to compile data until it reach-
        es the end date or the end of the file.

        SCAN CRITERIA

        The  next  menu  presented tells LOGGIT whether  to  scan  for  a
        specific BBS or to compile data on all calls made.

        Allcalls <default> -- compile data on all calls made. LOGGIT will
        tally   all  calls,  keeping  track  of  time   online,   average
        time/call,total calls to each number, total of uploads, downloads
        and aborts. The output will be sorted by name and the  individual
        results will be displayed as in appendix A.

        Individual  --  compile data on the specified  BBS.  LOGGIT  will
        tally  all  calls  to  the specific BBS  keeping  track  of  time
        online,total  calls,  average time/call, uploads,  downloads  and
        aborts.





                                        2
        LOGGIT -- TELIX USE FILE ANALYZER


        UP/DOWNLOAD ANALYSIS

        If  the Individual mode has been selected, a submenu  of  choices
        will appear allowing you to further define the analysis.

        Detailed  <default>  -- Compile the individual  up  and  download
        activity  for  the  selected BBS,  showing  the  date,  protocol,
        filename  and  transfer speed in CPS. A sample of the  output  is
        shown in appendix B.

        Summary  --  Accumulate and display the totals for  the  selected
        BBS.

        PcPursuit  --  Compensates for inaccuracy in Telix  logfile  when
        accessing  PCP.  Use this mode for a more  accurate  time  online
        calculation for your PCPursuit main number.

        OUTPUT MODES

        If  Allcalls or Individual Detailed has been selected,  the  next
        menu presented is the output mode menu, allowing three  different
        types of output.

        Screen <default> -- Sends all output to console. This is the only
        output  mode  available  when using  the  Individual  Summary  or
        Individual PcPursuit modes.

        Printer -- Sends all output to standard printer port.

        File -- Sends all output to data file.


        If File is selected you are prompted for an output filename.

        Enter output filename <TELIX.RPT>

        Pressing <return> will use the default file TELIX.RPT or you  may
        enter any valid DOS filename. LOGGIT will check for the existence
        of the selected file and if present will allow you the option  to
        overwrite the file.

        If the Individual mode has been selected, you are now prompted to
        enter  the BBS name to analyze. The input is CASE  SENSITIVE  and
        all  that need be entered is enough of the BBS name to  make  the
        search unique. LOGGIT will attempt to locate the BBS name entered
        and,  if  unable to find it, will display an  error  message  and
        request another name.

        LOGGIT  will now scan the file and compile the data according  to
        the  parameters that have been selected. The message window  will
        display  an "Analyzing -- Please Wait" message. When the scan  is
        completed  the  data will be output to the file  or  the  printer
        directly.  If  the  screen  mode has been  chosen,  you  will  be
        prompted to strike a key to page the output.



                                        3
        LOGGIT -- TELIX USE FILE ANALYZER




                              DISTRIBUTION PACKAGE

        The files in the distribution package are:

        LOGGIT.EXE               LOGGIT executable
        LOGGIT.DOC               Docs for LOGGIT
        LOGGIT.HIS               LOGGIT History file

        BATCH FILE OPERATION

        LOGGIT may be run from a batch file if you use a program such  as
        KEY-FAKE. Some sample batch files are described in appendix C.

        CAUTIONS

        Due  to  power failures and improper use of  the  program,  TELIX
        Version 3.11 has, on occasion, entered some strange entries  into
        the  TELIX.USE  file. LOGGIT makes every attempt to  catch  these
        errors  and instruct the user to correct them before  proceeding.
        The usual error is the combining of two lines of the log onto one
        line.  These  errors are easy to spot and correct. There  is  one
        particular  error, however, that can cause some strange  results.
        Occasionally, TELIX will insert an Elapsed Time Online entry into
        the  log  which  signifies the end of  the  connection  when  the
        connection  has not ended at all. This can produce  some  strange
        elapsed times and may even miss logging some up/downloads. If you
        notice some strange results, look closely at the TELIX.USE  file.
        Chances  are you'll find some subtle error in the file. This  can
        produce incorrect results but can do no harm at all.

        The built-in file integrity check may be overridden by the use of
        the command line switch /t.























                                        4
        LOGGIT -- TELIX USE FILE ANALYZER




                              THE SHAREWARE CONCEPT

        This  program is being distributed under the  shareware  concept.
        There  are many advantages to using this method of  distribution,
        some of which are:

        o    People can try programs before paying for them to
             determine if they are useful to their needs.

        o    Software authors can be supported directly by the
             users, which keeps software costs down.


        You are granted the right to use this program for a trial  period
        of  thirty  days, at which time you are requested to  stop  using
        it, or pay the registration fee.  You can register your copy  for
        $12 and receive the latest version on a 5.25" disk.


        Please remit to:

                                    Vic Baron
                                       GTX
                                54 Panorama Mall
                             Panorama City, CA 91402


                                    WARRANTY

        THE  AUTHOR MAKES NO WARRANTY OF ANY KIND, WHETHER WRITTEN,  ORAL
        OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION  THE  WARRANTIES  OF
        FITNESS  FOR  A PARTICULAR PURPOSE OR OF MERCHANTABILITY.  IN  NO
        EVENT  SHALL  THE AUTHOR BE LIABLE FOR SPECIAL  OR  CONSEQUENTIAL
        DAMAGES FROM THE USE OF THIS PROGRAM, EITHER IN BINARY OR  SOURCE
        FORM. THE USE OF THIS PROGRAM CONSTITUTES ACCEPTANCE OF THE TERMS
        AND  CONDITIONS OF THIS AGREEMENT. IF YOU DO NOT AGREE  TO  THESE
        TERMS, PLEASE DON'T USE THIS PROGRAM.

                              TECHNICAL INFORMATION

        This  program  was written and compiled  with  Borland's  TurboC,
        Version  2.0.  Many  specific functions were  created  in  C  and
        Assembly language.Extensive use was made of the fine CXL  Library
        functions by Mike Smedley.




        CXL            Copyright Mike Smedley
        TurboC         Copyright Borland International
        Telix          Copyright Exis,Inc and Colin Sampaleanu




                                        5

        LOGGIT -- TELIX USE FILE ANALYZER
        APPENDIX A

        Sample output for Allcalls --

        ================================================================
             BBS         TELEPHONE     Total Total  Avg   UP  DN   FILE
             NAME         NUMBER       CALLS TIME   TIME  LDS LDS ABORTS
        ================================================================
        A.M.U.L.E.T.           989-5054    3   0:26  8 min   2   0   0
        A.S.T.E. BBS           443-0242    1   0:16 16 min   1   0   1
        AAAExecpc              622-1138   54   8:55  9 min   5  20   3
        AAALaTelenet           624-2251    8   2:02 15 min   0   0   0
        AAALaTelenet24         622-1138   67   4:21  3 min   0   0   0
        AT&T Communicator      983-5090    1   0:00  0 min   0   0   0
        Albedo 0.39            822-8520    2   0:12  6 min   1   0   0
        BBS1-PC!               623-8451    2   1:02 31 min   2   2   0
         +   +   +   +   +   +   +   +   +   +   +   +   +   +   +  +

          +   +   +   +   +   +   +   +   +   +   +   +   +   +   +  +

         +   +   +   +   +   +   +   +   +   +   +   +   +   +   +  +

          +   +   +   +   +   +   +   +   +   +   +   +   +   +   +  +
        qhost                  547-1549    6   1:03 10 min   6   2   0
        sunrise omega          452-0350    1   0:01  1 min   0   0   0
        swap                   861-0925    1   0:05  5 min   0   0   0
        unix                   530-3013    1   0:00  0 min   0   0   0
        unk16            1-818-961-7903    2   0:12  6 min   0   0   0
        xanth West       1-818-710-9998    1   0:18 18 min   0   1   0

                         Start Date --------   12-01-88
                         End Date ----------   01-02-89
                         Total Calls -------   0399
                         Numbers Called ----   0122
                         Total Uploads -----   0090
                         Total Downloads ---   0103
                         Total Aborted -----   0009
                         Total Time Online -   054:48
                         Average Time/Call -    8 min



















                                        6

        LOGGIT -- TELIX USE FILE ANALYZER
        APPENDIX B

        Sample output for Individual - Detailed

        ================================================================
        Upload/Download Activity for:    AAAExecpc
        ================================================================
        88-12-01 Upload      External       YmOdem-g protocol.       CPS
        88-12-03 Upload      External       YmOdem-g protocol.       CPS
        88-12-10 Upload      External       ZmodemH protocol.        CPS
        88-12-11 Download    External       YmOdem-g protocol.       CPS
        88-12-11 Download    thelist2.zip   Zmodem protocol.     220 CPS
        88-12-14 Download    External       YmOdem-g protocol.       CPS
        88-12-15 Download    External       YmOdem-g protocol.       CPS
        88-12-16 Download    vircom.zip     YmodEm-g protocol.   192 CPS
        88-12-20 Upload      External       ZmodemH protocol.        CPS
        88-12-20 Download    pk361pat.zip   YmodEm-g protocol.   175 CPS
        88-12-20             ABORTED                                 CPS
        88-12-20 Download    dsz1220.zip    Zmodem protocol.     219 CPS
        88-12-20             superk.pak                          177 CPS
        88-12-20             cudmx.zip                           164 CPS
        88-12-21 Download    toots.gif      Zmodem protocol.     196 CPS
        88-12-22 Download    mnp.doc        Zmodem protocol.       0 CPS
        88-12-22 Download    mnemonic.txt   Zmodem protocol.     204 CPS
        88-12-22 Download    pcpchek.zip    Zmodem protocol.     226 CPS
        88-12-22 Upload      External       ZmodemH protocol.        CPS
        88-12-24 Download    ABORTED        YmodEm-g protocol.       CPS
        88-12-24 Download    dszreg.zip     Zmodem protocol.     221 CPS
        88-12-24             mn1221.zip                           23 CPS
        88-12-24             td1pat.zip                           93 CPS
        88-12-24             tc2pat_2.zip                         96 CPS
        88-12-24             noah2.zip                           116 CPS
        88-12-24 Download    External       YmOdem-g protocol.       CPS
        88-12-28 Download    ABORTED        YmodEm-g protocol.       CPS
        88-12-28 Download    External       Dszmodem protocol.       CPS

                         Start Date --------   12-01-88
                         End Date ----------   01-02-89
                         Total Calls -------   0129
                         Total Uploads -----   0005
                         Total Downloads ---   0020
                         Total Aborted -----   0003
                         Total Time Online -   015:20
                         Average Time/Call -    7 min


        Sample output for Individual - Summary

        ================================================================
             BBS         TELEPHONE     Total Total  Avg   UP  DN   FILE
             NAME         NUMBER       CALLS TIME   TIME  LDS LDS ABORTS
        ================================================================
        Execpc                 622-1138   54   8:55  9 min   5  20   3





                                        7

        LOGGIT -- TELIX USE FILE ANALYZER
        APPENDIX C

        Sample Batch Files
        This  batch  file  will  automatically  scan  the  default  file,
        TELIX.USE  scanning  Allfiles  for Alldates with  output  to  the
        console.


        REM Batch file for complete scan

        key-fake 13 "A" "A" "S"
                 |   |   |   |_____Screen output
                 |   |   |_________Allfiles
                 |   |_____________Alldates
                 |_________________Use default input file

        loggit

        REM End of batch file




        This batch file will allow for entry of an input filename at  the
        command  line. Command would be..batch myfile.ext  <return>.  The
        <myfile.ext> will be substituted for LOGGIT'S default filename.


        REM Batch file for complete scan of specified file

        key-fake "%1" 13 "A" "A" "S"
                  |   |   |   |   |_____Screen output
                  |   |   |   |_________Allfiles
                  |   |   |_____________Alldates
                  |   |_________________Carriage return character
                  |_____________________Filename will be substituted

        loggit

        REM End of batch file

        Any of LOGGIT's input may be generated by key-fake or any similar
        program.  Use the unique character that starts each command in  a
        menu  and LOGGIT will recognize the input. Decimal 13 (c/r)  must
        be added to all filename inputs.













                                        8
