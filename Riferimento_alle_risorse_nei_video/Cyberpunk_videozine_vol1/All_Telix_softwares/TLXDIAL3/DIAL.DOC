DIAL is a command line dialer for TELIX. At the DOS prompt simply type DIAL 
followed by the name of a bbs in your TELIX phone directory and DIAL will 
automaticaly start TELIX & begin the dialing of the chosen telephone number.

DIAL allows several command line options to specify a dial time, the use of 
an alternate dialing directory, or to show a listing of all entry names in a 
dialing directory (without starting TELIX). 

Most importantly, a DOS shell is provided during delayed dialing 
(560K free on my machine) allowing you to perform other tasks. Upon return 
from a shell, DIAL will sense if a dialing time is past & prompt to dial 
now or abort, batch mode supresses this prompt and begins dialing immediately. 

A new switch that allows the user to tell TELIX to start a "script" has
been added.

Requires TELIX ver 3.x or compatible dialing directory.

REGISTRATION & LICENSE
^^^^^^^^^^^^^^^^^^^^^^
The registartion fee for DIAL is $10 US currency (or equivelent) payable to:

  P.SADOWSKI
  76 Park Edge Drive
  Buffalo, NY 14225 
  USA

Alternatively, GEnie subscribers may make a $10 "Gift Of Time" to 
GE MAIL Address   LOONEY.TUNES.

(See page 8080, or *GIFTOFTIME, on GEnie for Gift Of Time details.)

The author may be reached at the following email addresses:

LOONEY.TUNES                 (GEnie)
aa089@freenet.buffalo.edu   (Internet)
cn659@po.cwru.edu           (Internet)

DIAL is Copyright 1992, 1993 by Paul R. Sadowski (All rights reserved.)
and is licensed upon registration for personal non-commercial use only.
Commercial licenses available.

No warranties of any kind, including but not limited to actual, express,
or implied are recognized. The user accepts this program and documentation
on an AS-IS basis, and waives any claims against the author and program
distributors for any damages resulting from incompatiblities, program faults
or misuse.

Distribution of this program without this document, or in any altered form 
is prohibited.

USAGE DETAILS
^^^^^^^^^^^^^

The basic usage is "DIAL <ENTRY NAME>". This finds the first pattern match
to entry name in your default dialing directory TELIX.FON.

If your <ENTRY NAME> contains spaces, please surround the <ENTRY NAME>
with double quotation marks. Eg., DIAL "A BBS" 19:30 

(NOTE: DIAL simply starts TELIX and begins dialing. It WILL NOT exit
TELIX after your session is completed. You must do this yourself, or your
automated scripts must do it for you.)

The "entry name" MUST be the first parameter on the line.

DIAL searches for the first entry that matches ALL of the characters in 
entry name. For example, if you have the following dialing dir. entries :

        BIX
        CIS
        DELPHI
        GENIE

typing "dial genie" will find entry #4, GENIE, as will "dial GE" or
"dial gen" or "dial geni" or even "dial g" (Case is NOT considered).

However, with the following entries:

        BIX
        CIS
        DELPHI
        GENCO
        GENIE

you must specify the minimum number of distinct characters to reach GENIE :
"dial geni". Typing "dial gen" would find entry #4, GENCO as it's first
pattern match, not GENIE.

If no match is found, an error message will be displayed.


DELAYED DIALING
^^^^^^^^^^^^^^^
You can specify a time until which DIAL should wait to begin.
The form is: "DIAL <ENTRY NAME> <TIME>".

When delayed dialing is used, Time MUST be the second parameter on the line. 
If time is not used another switch may appear in that position.

DIAL uses a 24 hour, or military time format. Midnight being 00:00, 
noon being 12:00, 6pm being 18:00... etc. Thus, the valid time range is
00:00 -- 23:59. 

A leading zero MUST precede hour and minute designators of 9 or less. 
(Eg., 09:27, 02:02, 00:30) 

A colon MUST appear in the third position, seperating the hours and minutes.

If an invalid time is entered an error message is displayed.

Delayed dialing is principaly of use to those who have dialing scripts
attached to a dialing directory entry that fully automate their activities
on that service or BBS.

It is the responsibility of the script to exit TELIX and to control the
maximum number of dial retries upon a busy signal or other connect problems.
DIAL has nothing to do with what happens after the first dial attempt is
begun.


ALTERNATE DIALING DIRECTORIES
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
You may tell DIAL to start TELIX with a dialing directory other than the
default TELIX.FON, and to search that directory for a pattern match.
The form is: "DIAL <ENTRY NAME> </:drive\pathname\filename>".

(NOTE: if delayed dialing is used, <TIME> must be the second paramater.
</:\pathname\filename> and any other switches must follow <TIME>.)

You may specify a complete pathname -- such as, "c:\phones\mydir.fon", or
"\comm\dialing\sues.dir" -- or just a filename, such as "petes.fon". If you
do not include a file extension DIAL will assume the extension .FON. If
you have included a pathname DIAL will search only that drive & directory
specified. If the environment variable TELIX has been set and no pathname
is given DIAL will search the path specified by that variable. If that
variable is not set and no pathname is given DIAL searches only the current
directory.

The virgule '/' or reverse backslash followed by a colon is required.
Eg., "dial delphi 19:30 /:c:\telix\mydir\pauls.fon"

If DIAL can not find the specified file an error message is displayed.

LISTING ENTRIES
^^^^^^^^^^^^^^^
You may view the entry names in the default dialing directory, or any
dialing directory, without starting TELIX.

The form is: "DIAL </L>" or "DIAL </L> </:drive\pathname\filename>"

This is the ONLY case where entry name and/or time need not be given.

A two column listing of all entry names will be displayed. If any name
field in the dialing directory is blank, DIAL will display it as <<EMPTY>>.
(DIAL will not dial a blank entry.) If you have many entries in your
dialing directory you may wish to use the DOS MORE command to prevent the
entries from scrolling off your screen. (Eg., "DIAL /L|MORE")

FINDING FILES
^^^^^^^^^^^^^
TELIX uses the environment variable TELIX to find it's required files.
DIAL also uses this variable to find both TELIX and it's default dialing
directory. If you do not have this variable set, DIAL will search only
the current directory for TELIX.EXE. If it can't find it, an error message
will be displayed.

If you have both TELIX set and your TELIX diectory in your PATH, you may
run DIAL from whatever your current directory happens to be, as long as
either DIAL is in that directory or in your PATH. (It's easiest just to
place DIAL in your TELIX directory.)

MUST KNOW
^^^^^^^^^
DIAL "knows" each day as beggining at 00:00 and ending at 23:59; therefore,
when DIAL sees a time entry such as 02:30 (2:30 a.m.) before midnight
current time and after that time for this day, it thinks that time has passed 
and asks you if you want it to continue or not.
  
  Past that time for today. Continue anyway, Press Y or N : [N]?

Press 'Y' to continue (case is not observed), or 'N' or just return to
abort. 

DIAL does not currently distinguish between days of the week on the 
command line, but it does do so "internaly." So pressing 'Y' will have
DIAL display the next day of the week in its waiting message and act
appropriately when returning from a DOS shell -- ie., not dialing till
the stated time on the day indicated in its waiting message.

While waiting to dial a message similiar to the one below will be displayed.

    Waiting to dial <ENTRY NAME> on <DAY> at <TIME>.
    Press <ESC> to shell to DOS, <Q> to quit, <D> to Dial now.

    <<current time clock>>

At any time you may press the letter 'Q' to abort the dial, 'D' to cause
DIAL to begin dialing immediately, or press the <escape> key to start a
DOS SHELL to perform other work on your computer.

Type EXIT at the DOS prompt to return from the shell. 

DIAL has been kept small to preserve a useful amount of free memory when 
you do a DOS SHELL. On my machine, I have 560k free in the shell. Your free 
memory will depend on your DOS version and general configuration.

Upon returning from the shell DIAL will display the same screen message,
unless the designated dialing time has passed. In that event DIAL will
prompt you to either dial immediately or abort the dialing.

  Past dial time for <ENTRY NAME> at <TIME>. 
  Dial now, Press Y, or N to abort : [N]?

Simply press the letter 'Y' to dial, or the letter 'N' or just return
to cancel.


START A SCRIPT
^^^^^^^^^^^^^^

You may have DIAL tell TELIX to start a script by using the /S switch
with DIAL. 

Eg., DIAL <ENTRY NAME> /SCLOCK (You may use a complete pathname.)

All other switches remain valid.

Note that due to the design of TELIX the script will not actualy be run
untill after the chosen entry is dialed and its linked script, if any,
is run. This is a fault of TELIX and can not be compensated for.


BATCH MODE
^^^^^^^^^^
If you are running DIAL from a batch file you may want DIAL to assume
that you will answer YES to the exception prompts described above, if 
either should occur.

The form is: "DIAL <ENTRY NAME> <TIME> </B>"
                        or
             "DIAL <ENTRY NAME> <TIME> </B> </:....>"

(Switches /B & /: may be in any order AFTER <TIME>.)

If used, DIAL will not warn you of a past time <TIME> entry and will
automaticaly begin to dial if you should return from a shell past dial time.

You need not be running DIAL from a batch file to use this switch.


EXIT CODES
^^^^^^^^^^

DIAL returns the following exit codes which may be tested in batch files.
(See DOS manual, batch files, errorlevels.)

Normal Exit                      = 0
User Abort                       = 1
Unable to find dialing directory = 2
Unable to start TELIX            = 3
Unable to find Entry Name        = 4
Bad Dial Time                    = 5    


Copyright 1992, 1993 by P.R. Sadowski
All rights reserved.
