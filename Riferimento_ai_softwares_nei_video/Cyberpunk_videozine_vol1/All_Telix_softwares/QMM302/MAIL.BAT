echo off
cd \modem\t3
if %1 / == / goto now
:go
cls
echo QMM AUTOPILOT waiting until  %1  to execute
wait %1
telix sqmmauto
goto go
:now
echo QMM AUTOPILOT executing now
telix sqmmauto
cd \qmail
deluxe
cd\
