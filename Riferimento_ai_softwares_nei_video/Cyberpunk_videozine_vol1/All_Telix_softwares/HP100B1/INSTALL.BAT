REM %1 is Download
REM %2 is Upload
REM %3 is Misc.
REM %4 is Messages

REM Move Files
ECHO Moving Help Files.  Please Wait ...
COPY *.HLP %3 > NUL
ERASE *.HLP

ECHO Compiling (Deleting Source) and Sample Script Extensions.  Please Wait ...
ECHO CS.EXE must be in current directory or path.

CS TESTEXT.SLT > NUL
CS TESTEXTL.SLT > NUL

ERASE TESTEXT?.SLT
COPY TESTEXT?.SLC %3 > NUL
ECHO.
ECHO.
ECHO Host+Plus Installed!  Use [Alt-G] in Telix to run Host+Plus
ECHO.
ECHO Press any key to return to Telix ...
PAUSE > NUL
