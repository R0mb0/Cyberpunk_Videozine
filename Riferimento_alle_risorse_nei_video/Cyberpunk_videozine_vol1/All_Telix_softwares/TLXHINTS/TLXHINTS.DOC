The following notes are based upon using TELIX Version 3.11 for several months
now.  These are things that I wish I had known when I started!  The executable
files required to use the hints are all contained in this file.

1.  Do you get a "+0" response when you logon to some boards and not to
others?
    Your problem is in having the CIS Auto-download turned on.  Certain
boards, notably TBBS and others, poll your communications program in the same
manner as Compuserve.  When CIS Auto-download is turned on, TELIX responds with
a "+0" to let Compuserve know that it is capable of CIS Quick-B protocol
transfers.
	You have two choices to eliminate the problem.
	a)  Shut off the CIS Auto-download by selecting Alt-O, T, L, N,
[ENTER], W, E.  The problem that this solution creates is that CIS will now not
recognize that you are capable of CIS Quick B transfers and you will have to
initiate the CIS transfers manually.  But even that can be overcome by placing
a "_cisb_auto=1" near the beginning of your CIS auto-logon script.  Or,
   	b)  Leave the CIS Auto turned on and insert a "_cisb_auto=0" near the
top of the log-on scripts for only those boards which poll and cause the "+0"
to be transmitted.

2.  Would you like to have more functions keys to define?
	If you have the extended keyboard (functions keys F1 through F12),
Telix will recognize F11 and F12, shifted F11 and F12, Control F11 and F12 and
Alternate F11 and F12 and allow you define them.  The hooker is that the F11
and F12 keys are not enabled by DOS.  If you use Fansi-Console, it will enable
all the extended keys.  If you don't care to use Fansi, the small TSR called
NEWKEYS.COM contained in this library will also enable the keys.  The source
for these files came from PC magazine and is included here as NEWKEYS.SCR which
I keyed in myself to preclude questions of copyright infringement.  Simply
include the "NEWKEYS.COM" command in your AUTOEXEC.BAT file and TELIX will give
you 8 more functions keys to define (assuming you have the extended keyboard.)


3.  Would you like to have TELIX come up in the 43 or 50 line mode on your EGA?
	This one I came across in the TELIX Conference on Fidonet.  Colin
Sampaleanu (author of TELIX) stated that there was no way to hard configure
TELIX to the 43 or 50 line modes.  HOWEVER -- if you were in the 43 ot 50 line
mode before you invoked TELIX, TELIX would sense the environment and come up in
that mode.  Two files, again from PC Magazine, are included in this library
which switch an EGA display to 43 and 50 lines, respectively. Simply call TELIX
via a batch file and include EGA43.COM or EGA50.COM as appropriate before
calling TELIX.  If you wish to be restored to the 25 line mode upon exit from
TELIX, them include EGA25.COM in your batch file after the call to Telix.  The
batch file might read
 EGA43.COM TELIX
 command_line_options
 EGA25.COM
Call it TX.BAT or whatever and it will solve a problem that vexed me for
several months.  The source for EGA25.COM, EGA43.COM and EGA50.COM is once
again included to preclude copyright problems.

4.  Finally -- would you like to have TELIX come up in the dialing directory --
ready to point-and-shoot-dial your favorite BBS?
	The following SALT script will do the trick:
main()
{
  dial("");
}
Compile it and use the script name as your start-up script.  E.g., if you
called it DIAL.SLC, then
  TELIX SDIAL
would bring up TELIX with the first screen of your dialing directory displayed.
You say you tried it and it doesn't work?  Aha!  One last thing -- you must
turn OFF the auto dialing bar in your configuration.  Use Alt-O, G, E, N,
[ENTER], W, E.  The logic of the terminology fails me, but that's what works!

Enjoy TELIX .... and register it -- I did.

			Jim Gaffney - El Paso, Texas
			CIS:  70515,1036
			GENIE:  JIMGAFF
			Rio Grande TP Board - (915) 592-4976
					300-9600 baud, 24 hr, 8/1/N
