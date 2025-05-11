USRobotics Courier HST Telix Modem Script Release 2.1 - 01/23/90
-------------------------------------------------------------------

(C) Copyright Andrzej Taramina 1988, 1989, 1990

The USRobotics logo, Courier, and HST are trademarks of
USRobotics, Inc.

Telix is the trademark of Colin Sampaleanu and Exis Inc.

DISCLAIMER

This script is copyrighted solely to prevent others from reaping
financial gain through its sale and/or use.  Permission has been
given to Colin Sampaleanu and the Exis Inc., to
distribute this script as part of the Telix program
package.  It may not be distributed as part of any other
computer communication hardware or software package without the
written permission of the author.  This script may be copied and
distributed freely by private individuals who wish to share it
with others as long as no specific charge is assessed for this
service other than minimal fees to cover the distribution medium
and the copying service itself.  Permission is hereby granted to
System Operators of active Bulletin Boards to post the TLX_HST
ARChive for public distribution.  Due to the easily modifiable
nature of scripts,  modified versions of the script
should bear a different name and have their origin clearly
identified.

If you like and use this script along with the Telix communications
package, please consider registering Telix with Colin/Exis if you
have not already done so.  Colin has spent many hours in developing
the best comm. program on the market (shareware or commercial) and
provides a high degree of support to his users....he is deserving of
our financial support.  This will allow for release 4.0 (in planning
at this moment) to be even better still!  Do your part to keep
the Shareware concept viable and thriving in the future!  Please
register Telix.


COMMERCIAL USES OF THE HST SCRIPT

The series of TLX_HST Telix Scripts may not be used for
marketing, demonstrations, advertising, problem diagnosis or
correction OR ANY COMMERCIAL or Business purposes by modem
manufacturers, their agents, dealers, resellers, or any company
or individual involved in the sale, marketing, or maintenance of
modems or other computing devices.  Commercial and/or business
uses of the TLX_HST script(s) requires formal licensing of this
product.  To obtain a commercial-use license for the TLX_HST
script(s), the author may be contacted at the address shown at
the end of this document or on one of the Bulletin Boards listed
at the end of the TLX_HST.1ST file included with this package.


TELIX RELEASE DEPENDENCY

This script will operate with TELIX 3.12 (and later
releases of TELIX).  Due to Telix Salt Script Language
dependencies, Release 2.1 of this script WILL NOT OPERATE under
pre-3.10 releases of Telix. It will also run under 3.11 as well.


OPERATIONAL SUMMARY

TLX_HST.SLC is intended as a configuration and setup help for the
USR HST modem, and although it facilitates much of the modem's
setup tasks, some knowledge of the HST's operation and
technology is required, as well as a basic understanding of
computer communications.

If you are using TLX_HST to set up your USR Courier HST for use
with Telix 3.12 or PCBoard 14.x, two menu options (TX and PC)
will perform all firmware configuration, leaving physical switch
changes up to the user (but correct switch settings are
displayed as part of the script's operation).

TLX_HST automatically detects the ROM release level of your modem.
If your USR HST modem is at ROM level 964 or 144x TLX_HST will allow
you access to special advanced functions on various menus.
These menu functions accesse HST features only available in
964 & 144x-level modems, such as data compression (MNP level 5),
settings for the new S-register 15, 4800/7200/9600/14400 link rate
settings, and the new modem configuration screen.  Advanced
Functions are NOT available for ROM releases prior to 964.


SETTING UP THE HST FOR TELIX OPERATION

Although TLX_HST eases the setup tasks, it can't do it all.  It is
likely that you will need to change the modem's switches from
their default factory settings to the setup recommended in the
menu's TX or PC options.  Unfortunately, TLX_HST can't quite
"reach out and touch switches"; you must do this yourself.  The
script makes you aware of this requirement.

Another very important part of the modem setup is the
configuration of Telix itself.  With release 3.1x of Telix,
this is done with the ALT-O command, which updates the
Telix configuration file. Later in this document there will be
some information to help you select the proper Telix
configuration parameters for the HST modem.

I recommend that you keep your HST manual handy while you
experiment with the script.  Bug reports or suggestions for
changes or improvements should be reported to the
Rose Media BBS in Toronto.


FRIENDLY WARNING

TLX_HST can make permanent changes to the modem's internal
configuration.  Once a setting has been changed, writing the
change to Non-Volatile RAM (NRAM) implements the change until
that setting is changed and written to NRAM again.  Changes to
NRAM are maintained even when the modem power is OFF.  If you
have a working set of modem settings and wish to experiment, do
not copy the changes to NRAM.  The next hardware reset or
power-off / power-on sequence will re-establish the last NRAM
settings.  A description of the HST's basic
internal operation is included in this document; you may wish to review it
to gain a better understanding of the modem's settings.


NRAM NOTES TO PCBOARD USERS

PCBoard software insists on having total control over modem
answer operations following RING detect.  To comply with this
requirement, TLX_HST sets the RAM value of register S0 to zero to
disable automatic call answering. This script also indicates
that switch 5 be left in the DOWN (ON) position, which disables
automatic call answering and leaves this feature entirely under
software control.



SUPPORT

I will attempt to correct problems with this script, as well as
keep it current with releases of the HST's firmware and Telix
software only as time allows.  This is a personal effort which I
am sharing, but for which I receive no remuneration (except from
commercial users of the script).  Please make no unreasonable
demands for support, especially for things that are not broken;
you got this for free and if it does not perform as you would
like it to, you have a God-given right not to use it.  You may
also chose to alter the script to meet your unique requirements.
If you do so, please do not distribute the modified version
under its original name.  You may contact me on a number of
bulletin boards, a list of which is contained towards the end of
the TLX_HST.1ST file included in this ZIP archive.



HST MODEM SETUP UNDER Telix 3.12

Setting up your modem for Telix use is quite simple.  In the Telix
configuratin (ALT_O), make sure that the following parameters are
specified:

MODEM & DIALING OPTIONS

Init String:         ATZ~~~AT&B1^M
Hang Up String:      ~~~+++~~~ATH0^M
Dial abort string:   ^M
Drop DTR to Hang Up: on

Note: Use of the ~ as delay character and ^M as carriage return
will insure proper script operation under Telix release 3.12.


TERMINAL OPTIONS

Baud:         34800
XON/XOFF:     off
CTS/RTS:      on
DSR/DTR:      off    (NOTE: if DSR is on the TLX_HST will hang!)


DIALING DIRECTORY ENTRIES

Set the baud rate, for dialing directory entries that support another
USR HST modem at the other end, to 38400 baud for the best speed.


That's it.  proper switch settings are:

1,2,6,7,10: UP
All others: DOWN





INTRODUCTION TO THE HST MODEM

This document discusses some of the unique features of the HST
modem and gives more specific information on using the HST with
Telix 3.12 for Bulletin Board operations.  It is not deeply
technical, but major differences between the HST and other, more
conventional modems are covered.


HIGH SPEED PROTOCOLS AND MODEM COMPATIBILITY

The HST is fast, which is probably why you bought it in the
first place.  Without going into a philosophical discussion,
suffice it to say that there are many 9600bps modems available
commercially, and most of these modems use totally incompatible
high-speed communications protocols.  Your HST will only
communicate at 9600bps with 9600 modems made by Hayes, Microcom,
etc. unless the modems support V.32 protocols and you own a
Dual-Standard HST.
Although a 9600bps standard exists, modems
adhering to it are few, far between, and still quite expensive.
You may not like this, but that's the way it is.  The HST will,
however, communicate at lower speed with all modems supporting
the 1200/2400 standards, including other modems incompatible at
the higher speeds.

Also, when connected to another HST, the effective
modem-to-modem speed ("link rate") may exceed the nominal
9600bps rate by 10 to 30%, depending on line conditions and the
ability of your computer to send/receive data at the higher
speed.  File transfer rates of 1100-1200 cps between two HST
modems (characters per second) are not uncommon.
With the new 1440/DS modems, you can exceed a nominal 14,400 bps
with file transferes exceeding 1700 cps if the modems at both ends
are 1440/DS's.


ERROR CORRECTION

At 9600+ bps, when communicating with another HST,  both modems
use sophisticated (and proprietary) error correction techniques
which insure that the data which was received is identical to
the data which was sent.  At lower speeds (1200/2400), the HST
relies on its built-in MNP firmware (Microcom Networking
Protocol) for error-free communications with other MNP-equipped
modems.  This effectively eliminates the need for conventional
"Software" error-correction implemented in software-only file
transfer protocols such as Xmodem, Xmodem/CRC, 1k-Xmodem (a.k.a.
Ymodem), Zmodem and many others.

To take advantage of the much faster and more efficient built-in
error correction, special file transfer protocols must be used.
These protocols do not perform any error-checking and
correction; they rely entirely on the modem to do so.  Such
protocols include Ymodem-G, Imodem, and the registered version
of Zmodem (DSZ, authored and copyrighted by Chuck Forsberg).

Remember that error-free transmissions take place ONLY if you
are connected to an HST (at 9600+ bps) or to an MNP-compatible
modem of any brand at 1200 or 2400bps.  If setup properly, the
HST will return a special "CONNECT xxxxx/ARQ" message upon
connect (where xxxxx is the connect speed)  which reflects the
fact that an error-free connection has been established with the
other modem.


FACTORS AFFECTING TRANSFER SPEED

There seems to be some widespread misunderstanding of the term
"Speed" as it applies to the HST and other "high-speed" modems.
How fast does it really go?  What is its limit?  More important,
what are the factors that limit the modem's speed?

It is all very simple, really.  One end of the modem talks to
the computer, while the other end talks to another modem.  The
speed you are really interested in is the LINK RATE, which is
the speed at which the two modems transmit data.

If the HST is setup to transmit/receive at the highest possible
link rate, the effective speed will depend on the following
physical factors:

1. The maximum speed that can be achieved by the other modem,
2. The maximum speed at which your computer can communicate with
   your HST modem and
3. The maximum speed at which the OTHER computer can communicate
   with ITS modem.

It is intuitively obvious that the effective modem-to-modem link
rate cannot possibly exceed the slowest of 1,2, or 3 above.
Unfortunately, you can only control item #2, the speed at which
your computer communicates with your HST modem.  This speed is
NOT determined by the modem, but by the following:

1. The type of computer and communications interface you are
   using and
2. The communications software you are using.


PHONE LINE NOISE

In an HST-HST connection, extraneous noise characters will not
appear on the computer's screen.  This led to the false belief
that error-correcting modems eliminate noise.  They do not.
The modem's built-in error-correction firmware (ie, MNP) insures
that the data which is received is the same as the data that was
sent in a manner similar to software-only error-corrction
protocols such as CRC (Cyclical Redundancy Check).  Thus, the
modem themselves initiate the retransmission of blocks of data
which were affected by line noise.  Although the computer does
not see it, noise affects transmissions just as negatively and
results in a slowing down of the data transfer.  On the HST
modem, erratic blinking of the RD/SD lights may be an indication
of poor line quality.


DATA FRAME OPTIMIZATION (MNP4) AND DATA COMPRESSION (MNP5)

With release level 964+ of the HST's ROM code, USR implemented
MNP level 4 (Data Frame Optimization) and MNP Level 5 (Data
Compression).  Although 964+-level HST modems are fully
downward-compatible with earlier releases of the ROM (ie, 961,
963), these features can only be used with other 964+-level (or
more recent) HST modems.

Control of MNP level 4 operation is available via S-register 15,
a new register implemented in release 964+ of the HST ROM.  If
bit 4 (decimal value 16) is ON in this register, MNP level 4 is
DISABLED.   MNP level 4 operation is only effective at speeds
of 1200bps and above.

Data Compression (MNP level 5) may be a mixed blessing,
depending mostly on the type of data being transferred by the
HST modem.  If your HST is used primarily for BBS communications
and your file transfers are mostly ARChived files (processed by
SEA's ARC, Vern Buerg's ARCA, or Phil Katz's PKZIP), data
compression by the modem is not only redundant, but it may
actually SLOW DOWN your file transfers.  Effectively, the MNP 5
data compression algorithms will attempt to replicate the work
already done by the ARC utility and will fail to reduce the size
of the data any further (it will likely INCREASE the size of
your ARC'ed files), resulting in increased transfer times.
Thus, the most efficient transfer or compressed files on
964-level HST modems occurs when data compression is turned off
(to disdable MNP5, use the AT&K0 command).

ASCII, Text, .EXE and .COM files may benefit greatly from data
compression, yielding transfer rates in the 1400-1900cps range.
To activate automatic data compression, use the AT&K1 command.


HARDWARE LIMITATIONS

How fast your computer can communicate with the modem is
influenced by many factors.  The HST modem itself can
communicate with the computer at a maximum rate of 38,400bps.
Earlier models of the IBM PC and compatibles utilized an
8088 processor running at 4.77Mhz, transmitted data internally
over an 8-bit wide data path, and their serial interfaces (to
which the modem is attached) also used an 8-bit processor chip.
So-called "Turbo" machines which use a
dual-speed 8088 or NEC V20 microprocessor, or some of the 8086
or V30 machines can achieve significantly faster serial speeds.
The new series of AT-class 80286 and 80386 based machines can
provide much faster serial speeds.

The original serial processor chip is usually an 8250, and is
rated at 9600 (some 8250s can run satisfactorily at 19200,
however).  The newer 16450, a plug replacement for the 8250, is
nominally rated at up to 38400.

Regardless of the speed of your computer and serial interface,
what's at the other end is just as important.  Running a 20Mhz
386 system and with serial interface set at 38400bps is of no
consequence if the system you are communicating with is limited
to a 9600bps serial speed.  The SLOWEST link in the entire
communication chain sets the pace for all the rest, folks.
Also, be aware that computer networks running multi-node
bulletin board systems have many other tasks to perform besides
communicating over telephone lines.  These other processes may
interfere with reliable communications at high speeds, and the
sysops may purposely slow down the serial interface speed to
prevent possible conflicts arising from this situation.  One of
the most common problems in this environment is an aborted upload
when concurrent disk updates on the network's file server take
precedence over communications interupts and cause loss of
incoming data.

Other factors which can negatively affect high speed
transmissions are not readily apparent at lower speeds.  A slow
hard disk, for example, can drop the effective data transfer
rate by a few percentage points.  You may want to try a RAM
disk, for example, which eliminates disk access as a limiting
factor to data transfer performance.


COMMUNICATIONS SOFTWARE

How fast your serial interface operates is a function of the
serial interface itself, since it has an upper speed limit, as
well as the communication software you use, since IT physically
sets the speed of your communications port.  In fact, the
communications software you use may be your worst enemy.

While many commercial communications packages are good and
offer an outstanding array of features, few of them measure up
to Telix in terms of raw data transfer performance, especially
with an HST-class modem.  A number of communications packages
limit the maximum serial rate to 9600bps, regardless of your
computer and serial interface's inherent abilities.  Telix
release 3.12 can set you serial speed all the way up to
38,400 bps.

Furthermore, some otherwise good communications packages offer a
very limited choice of transmission protocols which cannot take
advantage of your computer and communications hardware.  Not
providing protocols such as Ymodem-G and Imodem, or an easy
interface to external protocols such as DSZ, severely limits the
effectiveness of your communications setup.  Your choice of
Telix is a good one, offering internal ZModem and many others along
with the most powerful script language around...stick with it!

