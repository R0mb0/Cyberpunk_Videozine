echo off
c:\system\curse > nul
clr
if exist %1.slt goto work
echo [31musage:  [33mtmake [pathname]file [35m(.slt must be the extent)[36m
goto done
:work
c:\telix\cs %1
echo .
if not exist c:\telix\%1.slc goto s1
c:\system\xt tcomp1 c:\system\sysmsgs
c:\bobstuf\ask "1 to do it, 2 not to [32m" 12
:s1
if errorlevel 2 goto savesrc
if not exist %1.slc goto savesrc
copy %1.slc c:\telix\%1.slc
:savesrc
if not exist d:\source\telix\%1.slt goto s2
c:\system\xt tcomp2 c:\system\sysmsgs
c:\bobstuf\ask "1 to do it, 2 not to [32m" 12
if errorlevel 2 goto done
:s2
copy %1.slt d:\source\telix\%1.slt
:done
