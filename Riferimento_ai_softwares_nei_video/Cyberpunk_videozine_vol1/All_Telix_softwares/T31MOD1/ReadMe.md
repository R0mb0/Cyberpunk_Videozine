

                              Telix Version 3.1
                            Opening Screen Bypass

This patch will modify the Telix version 3.1 program so it doesn't display the 
opening screen. An unpatch script is also included to restore the Telix to 
again display the opening screen.

This patch is not in any way intended to discourage users of Telix from 
registering their copy of Telix with its' writers. Telix is a GREAT program,
and its users are encouraged to contribute and register as requested by its' 
authors.

TO USE THE SCRIPT FILES:
~~~~~~~~~~~~~~~~~~~~~~~~
1. Make sure you make a backup copy of TELIX.EXE.
2. Copy the TMOD.BAT, REMOVE.SCR and RESTORE.SCR files to the same 
   directory/disk that contains the TELIX.EXE file.
3. Make sure DOS's DEBUG is in the same directory or is accessable by the DOS 
   PATH command.
4. At the DOS prompt, enter: TMOD REMOVE.SCR

   This will patch the Telix program to eliminate the opening screen, and Telix
   will go right to the modem initialization routine and be ready for use.

5. To restore Telix back to its original form: 
   At the DOS prompt, enter: TMOD RESTORE.SCR

DISCLAIMER
~~~~~~~~~~
The removal is accomplished by using a DEBUG script file (as is the 
re-install). I advise you to look over the script files and see what each does.
For those of you uneasy with running this, DON'T! This was written only because
I run a BBS that uses Telix as a Terminal program to call out - The longer I'm 
calling out, the longer MY BBS is down. So, every second counts. You run these
patches at your own risk, although I've run it four times, I can't and won't be
held responsible for what others might do to these files enroute to you.

===============================================================================
         Telix v3.1 is Copyrighted by Exis, Inc. and Colin Sampleanu
                    DEBUG is copyrighted by IBM/MicroSoft
===============================================================================
