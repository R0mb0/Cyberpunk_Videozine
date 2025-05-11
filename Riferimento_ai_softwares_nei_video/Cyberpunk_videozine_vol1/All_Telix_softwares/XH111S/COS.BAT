@echo off
set opt=
if exist cs.msg del cs.msg >nul
:start
 if "%1"=="" goto end
 if %1==x set opt=-s2048 xhost
 if %1==X set opt=-s2048 xhost
 if %1==s set opt=-s2048 setup
 if %1==S set opt=-s2048 setup
 if %1==a set opt=-s2048 add
 if %1==A set opt=-s2048 add
 if %1==D set opt=door
 if %1==d set opt=door
 if %1==E set opt=-s2048 editor
 if %1==e set opt=-s2048 editor
 if %1==u set opt=-s2048 edit
 if %1==U set opt=-s2048 edit
 if "%opt%"=="" set opt=%1
 echo.
 echo Compiling with options: %opt% >> cs.msg
 cs %opt% >>cs.msg
 echo. >>cs.msg
 shift
 goto start
:end
type cs.msg
