
Modified: 10 - 12 - 1990
	  Paul Gardner 408-297-9660

	  I wish to thank the original aurthor of this script file.

	  I took the liberty of modifing the UTC capture routine as
	  the original did not reliably capture and hangup on my
	  clone.

	  Added variables turn off the alarm sound at connect time.
	  Added calendar date set.

	  I may be one second off in the clock set. If so I will
	  correct it next go around.

	  I also included two batch files and two .com files in the zip
	  You may have to modify the batch files to match your hard
	  disk setup. The Blue.com sets the screen background blue
	  on ega and vga screens.

	  The com.files and rolex.scr should be installed in your root
	  directry and a path command set to the root.

USAGE:
	  The Rolex is available with EGA and VGA screens and
	  is executed by typeing rolex

	  The DOS time is set by executing either the bat file
	  timeset on none ega-vga computers or setrolex if ega-vga.

	  On AT type computers the cmos clock is also corrected
	  this may not be true on all clones so you may have to
	  continue research on yours

	  You must also edit the time zone setting in the .slt file
	  and recompile with cs if you are not in PDT.

		       Standard Time Differences
			for Various World Cities
		     Relative to Greenwich, England

Note: These differences are based on standard time for all cities listed.

	  Tokyo 	  9 hours     (Do not precede positive numbers with
	  Hong Kong	  8 hours      a plus sign during configuration.)
	  Beijing	  8 hours
	  Jakarta	  8 hours
	  Bombay	  5.5 hours
	  Karachi	  5 hours
	  Moscow	  3 hours
	  Nairobi	  3 hours
	  Riyadh	  3 hours
	  Cairo 	  2 hours
	  Johannesburg	  2 hours
	  Rome		  1 hours
	  Paris 	  1 hours
  --->	  GREENWICH	  0 hours	<---   (0 degrees longitude)
	  Dakar 	  0 hours
	  Reykjavic	  0 hours
	  Caracas	 -4 hours    (Use the minus sign during configuration.)
	  New York	 -5 hours
	  Chicago	 -6 hours
	  Mexico City	 -6 hours
	  Denver	 -7 hours
	  San Francisco  -8 hours
	  Anchorage	 -9 hours
	  Honolulu	 -10 hours

Oringinal Author:	Unknown
Original Notes:
	 FILES:
	 This archive should contain three files:  Timeset.doc (this
	 file), TIMESET.SLT (the source), and TIMESET.SLC (the
	 compiled version).

	 DESCRIPTION:
	 TIMESET is a script file written for TELIX v3.0 and is used
	 to set your DOS clock to the precise time from the Naval
	 Observatory in Washington DC.

	 WHY?
	 I wrote this script to replace a much larger program that I
	 had been using.  Who needs to keep a program larger than 100k
	 on the hard drive when a script less than 1k will do the job
	 just as well?

	 USAGE:
	 Using this script is simple.  Place TIMESET.SLC into the
	 directory that you keep your scripts in.  After bringing up
	 TELIX, hit alt-g.  When asked which script you want to run,
	 type TIMESET <enter>.	TIMESET will call the Naval
	 Observatory, get the precise time, and set your DOS clock to
	 it.  Then TIMESET will display the current time with a real
	 time clock on the screen.  This will let you gather up all of
	 the clocks in your house so you can set them.	When you are
	 done, just hit the space bar to exit.

	 DISCLAIMERS:
	 I wrote TIMESET primarily for my own use.  It probably has at
	 least a couple of examples of not-so-good programing
	 practices in it, but it works fine for me.

	 Note that the code is fairly well commented.  Specifically,
	 if you use TIMESET in a different time zone than mine, you
	 should be able to find the line where I adjusted from
	 Universal Time to my local time and make the proper
	 adjustments to suit you.  Also, this will become important
	 when it is time to make the transition to and from daylight
	 savings time.	Hmmm.  Is it spring forward, fall back.  Or is
	 it fall forward, spring back.	I dunno.  I can never
	 remember.  Anyway, it would have been a fairly easy job to
	 put something in the script to handle this, but I didn't.

	 Also note that you may find it necessary to put another line
	 in the script that will transfer the DOS time to the memory
	 of your built-in clock.  Setting your DOS time does not
	 necessarily mean that the time also goes into your hardware
	 clock.

	 I will not be liable for any damages or claims related in any
	 way to the use of this script.  I make no warranties and
	 specifically disclaim any implied warranties of this product.
	 Also, I make no claims of suitability of this product for any
	 purpose other than to take up space on your disk.

