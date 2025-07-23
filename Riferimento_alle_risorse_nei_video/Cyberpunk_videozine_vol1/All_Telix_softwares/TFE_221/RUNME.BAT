echo off
cls
echo ³ TelixFonEd (TFE) v2.21 -- copyright (c) 1988-1991 by Paul Roub
echo ³                           All Rights Reserved
echo ³
echo ³ This archive (or disk) contains seven files:
echo ³         tfe.exe      - TelixFonEd program
echo ³         tfe.reg      - TFE registration form
echo ³         runme.bat    - this batch file
echo ³         ask.com      - utility used by this batch file
echo ³         tfe_hist.doc - TFE revision history
echo ³         tfe.doc      - documentation for TFE
echo ³         whatis.tfe   - a brief description of TFE
echo ³
echo ³ TFE is a full-screen editor for Telix version 3.0 (and higher) FON files
echo ³ (dialing directories).  The syntax of TFE is:
echo ³
echo ³               tfe [?] [-v{n}] [-c{name}] [-h] [filename[.ext]]
echo ³
echo ³ If no filename is given, TELIX.FON is assumed.  The user interface is fairly
echo ³ self-explanatory, but I recommend that you print out and read the documen-
echo ³ tation.
echo ³
echo ³ If you do not wish to print out the documentation at this time, type 'n' now.
echo ³ Otherwise, set your printer to the top of the page, then press 'y'.
ask ³ ¯¯¯¯¯ Print out the documentation now (y/n)?
if not errorlevel 1 goto end
cls
echo Printing readthis.now
copy readthis.now prn>nul
echo Printing tfe.reg...
copy tfe.reg prn>nul
echo Printing tfe_hist.doc...
copy tfe_hist.doc prn>nul
echo Printing tfe.doc...
copy tfe.doc prn>nul
:end
cls
echo Thank you for using TFE!

