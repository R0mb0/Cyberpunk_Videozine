echo off
cls
path >\BATCH\OLDPATH.BAT
path \ws5;\qmail;%path%
cd \modem\t3
if %1 / == / goto now
echo QMM AUTOPILOT waiting until  %1  to execute
wait %1
telix sqmmauto
goto qmail
:now
echo QMM AUTOPILOT executing now
telix sqmmauto
:qmail
cd \qmail
deluxe
cd\
\batch\oldpath

