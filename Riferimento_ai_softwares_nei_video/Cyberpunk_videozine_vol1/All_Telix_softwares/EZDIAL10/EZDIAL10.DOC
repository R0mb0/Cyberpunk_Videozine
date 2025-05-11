                        EZ DIALER 1.00

         Dialing Scripts for PC Pursuit and Telix 3.0


                         July 5 1988





























































EZ DIALER 1.0                                      PAGE i

                       COPYRIGHT NOTICE

EZ DIALER is Copyright (c) 1988 by Rich Smith


*************************************************************
                          DISCLAIMER

EZ DIALER is provided AS IS without any warranty, either
expressed or implied. This includes without limitation the
fitness to a particular purpose or application.
The author shall not be liable for any damages, whether
direct or indirect from this program failing to operate as
desired by the user.
In no event shall the author be liable to the user for any
damages of any kind resulting from the use of this program.
Use of this program by the user constitutes acceptance of
these terms.
*************************************************************

                       <<<SHAREWARE>>>

EZ DIALER is distributed as Shareware. You are encouraged to
copy and distribute UNMODIFIED copies of this program.
While no monetary compensation is requested for version 1.0,
the author reserves the right to change this for future
releases.


Telix is a trademark of PTel.
PC Pursuit and Telenet are trademarks of Telenet Communication
Corp.



The following files makeup the EZDIAL10.ARC.....

PCP.SLT      ........ The script that logons onto Telenet
MENU.SLT     ........ The menu and dialer for the Cities
BYE.SLT      ........ Hangup script
NEWCITY.SLT  ........ Disconnect from the outdial modem
PCPBBS.SLT   ........ Dials PC Pursuit BBS for direct connect
EXEC.SLT     ........ Dials EXEC-PC BBS for direct connect
FILES.TXT    ........ List of files in EZDIAL10.ARC
and 31 .FON DIALING DIRECTORIES




























EZ DIALER 1.00                                    PAGE 1

INTRODUCTION

   On Saturday, I downloaded Telix 3.0. I had heard very good
things about Telix 2.12, although it was one of few comm
programs I had not tried out. After reading the docs for 3.0,
I wanted to give it a try. That's when I found the problem.
   Nearly all of my telcom is done on PC Pursuit, and as any
one who uses it knows, it is a real pain without some sort of
"automation". Since Telix 3.0 had just been released and it
appeared not to be compatible with script files from previous
versions, I had to try to create scripts of my own to allow
me to fairly try Telix 3.0.
   The "SALT" script language included with Telix 3.0 seems
to be a very powerful language. Not being a programmer
(actually I shudder at the word), it was an uphill battle to
just get a workable set of scripts to use.
   These first attempts are presented here. They have been
tested for quite a few hours (thanks to a long 4th of July
weekend), and have worked well. There is not much error
trapping, so one must take care and pay some attention.
   I plan to improve and polish these scripts in the future
and feedback is very welcome. You may leave E-Mail on the
EXECPC BBS (414-964-5160) or on my BBS at (408) 757-
0135 (which is PC-Pursuitable).

SETTING UP EZ DIALER

   To install EZ DIALER on your system.....

              1. Copy the 6 .SLT files from this archive into
                 the Script directory as defined in your Telix
                 setup.

              2. If you don't have a complete set of dialing
                 directories, copy those into the directory
                 with your other Telix files.

              3. Put your local Telenet number in the TELIX.FON
                 dialing directory. Enter PCP.SLC as the script
                 file for this number. You should set your line
                 for whatever baud your Telenet is and set
                 format as N-8-1. I put this number as number 1
                 in the directory and use the quick-dial window
                 to get going quickly.

              4. Edit your TELIX.KEY file to include "@MENU" AS
                 F9 and "@NEWCITY" AS F10.

              5. Using your favorite text editor, enter your PC
                 Pursuit User ID and Password into MENU.SLT,
                 EXEC.SLT, and PCPBBS.SLT.

              6. Use CS.EXE to compile the scripts.

              7. Dial the Telenet number and follow the
                 instructions below to use the scripts.







EZ DIALER  1.0                                      PAGE 2







Operating Instructions

   Once a successful logon to the local Telenet number is
achieved, you will be presented with a menu of the PC Pursuit
nodes. The list also includes EXEC-PC BBS and the PC PURSUIT
BBS which are both direct connect on PC Pursuit.
   Keyin the dialing code for the desired city and the script
will dial until a connect is made. If you wish to interrupt
this dialing, hit the ESC key, answer 'Y' to the 'Abort
script?' question, and tap F9 at the '@' prompt from Telenet.
If the '@' prompt doesn't appear just hit the 'ENTER' key and
it should come around.
   Once connected to the outdial modem for the connected city,
EZ DIALER will load the dialing directory for that city. You
may then dial and work within that city. When you are ready to
try another city, just it the ESC key out of the dialing
directory and hit F10, wait a couple of seconds then hit the F9
key for the city menu. You may then enter a new dialing code
and continue.
   EZ DIALER will expect to find a dialing directory for any
city you connect with, using the dialing code and the .FON
extension. (ie. TXHOU.FON for Houston).


Notes

   EZ DIALER was written out of the immediate need for an
automated way to use Telix 3.0 with PC Pursuit. Having heard a
lot of good things about Telix, I wanted to try it. I've given
most of the Shareware comm programs at least a shot and still
haven't found the one that 'grabs' me. But since nearly all of
my comm time is spent on PC Pursuit, dialing scripts are an
absolute must!!!
   These scripts are not extremely polished, do not have a lot
of 'bells and whistles' and at this time don't have much error
trapping. One must exercise a little care upon entering the
dialing codes, and try not to select one of the cities that
still isn't on line. You'll have to ESCape out of that dialing
and reload the menu.
   The scripts have now been through a few days of testing and
use, and do not cause problems in and of themselves, but I'm
sure I haven't done everything possible to them. As I continue
to try Telix 3.0, I'm sure I'll be polishing the scripts up
some and adding more features and security.
   Not being much of a programmer, I'm still using the try and
see method of learning SALT. As I get better at it EZ DIALER
will get better also.