@ECHO off
ECHO off
REM   Batch file for BIMODEM
REM
BIPATH bimodem.pth
IF ERRORLEVEL 1 GOTO no_path
BIBAT bimodem.cfg
IF ERRORLEVEL 1 GOTO no_cfg
BIMODEM /Pbimodem.pth /Cbimodem.cfg
:no_path
ECHO BIMODEM.PTH is missing.
:no_cfg
ECHO BIMODEM.CFG is missing or No Carrier Detected.
:end
