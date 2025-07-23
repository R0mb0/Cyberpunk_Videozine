@ECHO off
ECHO off
REM   Batch file for BiModem
REM
BIPATH bimodem.pth
IF ERRORLEVEL 1 GOTO no_path
REM Remove the above 2 lines if you're using a Host mode.
BIBAT bimodem.cfg
IF ERRORLEVEL 1 GOTO no_cfg
BIMODEM /Pbimodem.pth /Cbimodem.cfg /B%1 /L%2
REM Remove all this stuff >>>>>>>>>>^^^^^^^^^
REM			  if you're calling this BATCH file from a F key.
:no_path
ECHO BIMODEM.PTH is missing.
REM Remove the above 2 lines if your'e using a Host mode.
:no_cfg
ECHO BIMODEM.CFG is missing or No Carrier Detected.
:end
