@echo off
:: MODIFY "tdisk" and "tdir" to fit your setup:

set bbsname=
set tdisk=H
set tdir=\telix

set test=AAAAAAAAAAAAAAAAAAAA
if .%test%==.AAAAAAAAAAAAAAAAAAAA goto OK

set tdir=
set tdisk=
set test=4DOS
if .%_CWD%==. set test=COMMAND
cls
echo Your system is out of environment space! You have two choices:
echo 1. Remove one to three of your environment variables
echo 2. Make environment larger for %test%.COM in your CONFIG.SYS file.
echo :
echo Example:
if .%_CWD%==. echo shell=c:\COMMAND.COM /e:512 /p
if not .%_CWD%==. echo shell=c:\4DOS.COM /e:1024 /s:dD: /p
echo :
echo and try again. Good luck!
echo :
goto end

:OK
set test=
set bbsname=%1%2%3%4%5%6%7%8%9
set telix=%tdisk%:%tdir%

:; Test for 4dos/COMMAND.COM, and use the correct commands to
:; switch to disc containing tdir.
if .%_CWD%==. goto old1
  pushd %telix%
  goto new1
:old1
  PUSHDIR
  %tdisk%:
  cd %tdir%
:new1

:; Enter the QuickDial script.
:: The 'o' parameter skips modem initialize.
telix o sqdial
cls
Echo Thanks for using Telix_Square!

:; Test for 4dos/COMMAND.COM, and use the correct commands to
:; go back to original drive and directory.
if .%_CWD%==. goto old2
  popd
  goto end
:old2
  POPDIR

:end
:; Remove the environment variables used.
set tdisk=
set tdir=
set telix=
set bbsname=
set sqrtime=
