
                              T E L I X A N A
                              
                              TELIX ANAlyser                               
                              
                                  RV 1.10
                                 
                      Written by Jacek H. Przychodzen
                            3rd, February 1990         
                        in Adelaide, South Australia.                

                           FidoNet Node 3:680/805
                     (Tell me what you think of this prog!)

            
    This program will analyse and report (SPECTACULARLY) on the
    TELIX.USE log file.
    It must be in the same directory that TELIX.USE is.
                            
1.  This is a SHAREWARE program.
    If you find this program usefull, please send a small contribution
    to encourage the programmer to release further work into public domain.
    
    Under no conditions whatsoever are you allowed to modify the
    program in any way, shape or form.
    
    This file TELIXANA.DOC must ALLWAYS be included in the archive if
    the program is distributed.
    
    The two files distributed are;
    
                    TELIXANA.EXE    Program proper
                    TELIXANA.DOC    This file

2. HISTORY
    This program was written in late January 1990 in response to the
    programmers need for analysing a telix use file.
    A similar program was downloaded from a bulletin board
    (Written in eastern states of Oz) which promptly crashed midway
    through the program.

    V 1.0 First released version of TELIXANA. It wen out to three
          bulletin boards when I have noticed a small bug.
          The number of calls does not add the first call made.
          
    V 1.1 Second version of Telixana, released a day later (!).
          Removes the bug from version 1.0.
          But to add some small bonus I have now added a feature.
          If you start TELIXANA with a command line parameter
          ie;
                    TELIXANA C:\TELIX\TELIX.USE
          
          You dont have to start it from the same directory where
          the log file is.
          Also you can open your old log files (if you archive them).
          ie;
                    TELIXANA C:\TELIX\TELIX.OLD

          If you dod not use the parameter, TELIXANA will try to open
          the file in the directory where you execute the program from.

    V 1.2 Oh, hassle, hassle! Put the wrong variable in the wrong place
          and watch the prog spit the dummy!
          Seems you could not sort the system list if you had more that
          23 calls to different systems.
          Fixed now.
    
3. COMPATABILITY WITH TELIX
    This program was tested with TELIX V 3.11 and TELIX V 3.12
    and found to be operational.
    
4. PROGRAM OUTPUT
    The following is the output of the program as generated from 
    a log file.
    Only the Top 23 Systems will be shown on screen.
    I find that to be satisfactory even for mederately heavy BBS users.
    However the program SHOULD cope with more (Up to 255).
        
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ SYSTEM                TimeON Calls DoLd UpLd
³      T E L I X    V 3.11       ³Nexus                   12:50    71    3    1
³      Usage File Analyser       ³The Realm               10:50    43    2    -
³             V 1.0              ³Phone Box               00:00     1    -    -
³ Writen by Jacek H Przychodzen  ³ADAM                    17:46    62  132   16
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´Key Board               01:00     5    4    1
³ # of records read : 3021       ³The Void                09:00    26    4    5
³                                ³Coffee Time             00:24     4    1    -
³ Date..............: 90-02-01   ³The Sepulchre           00:06     2    -    -
³                                ³Something               00:14     1    -    -
³ Total Connect time: 61:02      ³Midnight Caller         04:29     8    2    -
³ Total Calls       : 239        ³The Talisman BBS        04:07    12    1    -
³ Total Systems ....: 16         ³FullMetal Straight Jac  00:46     9    -    -
³                                ³Micro Byte PC Support   00:01     1    -    -
³ Uploads # ........: 24         ³Electronic Oracle       00:01     1    -    -
³                                ³The Clipboard           02:32     7    1    1
³ Downloads # ......: 150        ³Type Link               00:01     2    -    -
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ ESC  - Terminate program.      ³
³  F1  - Top 23 by Calls #.      ³
³  F2  - Top 23 by Call Duration.³
³  F3  - Top 23 by Upload.       ³
³  F4  - Top 23 by Download.     ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
              
    When the program finishes, pressing F1 to F4 will evoke any of the
    four SORT options.        
                
    PRINTER        
    Version 1 does not support a printer with the exception of the normal
    DOS PrtScr function.
    Your support and/or feedback will mean inclusion of this feature 
    if needed.
        

5. TIME
    All time is show by the program in HOURS:MINUTES, seconds are ommited.
    Any connect timess less than a minute are rounded up to a minute.
    
6. CREDITS
    Primarly go to EXIS Inc. without whose superb TELIX program this utility
    would not be created (A Duh!).
    
    If you consider this program of some use to you
    why not encourage the creator of this program
    by sending some miniscule portion of your wealth ?
    to;

                 Jacek H. Przychodzen
                 57B Park Tce.
                 Ovingham   S.A.   5089
                 South Australia
                                                    
    Thanx.
    And please give some feedback!
           