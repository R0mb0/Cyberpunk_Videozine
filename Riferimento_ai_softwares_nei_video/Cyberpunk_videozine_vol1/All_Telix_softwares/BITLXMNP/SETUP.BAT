@echo off
echo off
IF NOT EXIST AT.COM GOTO no_at
IF %1.==. GOTO no
IF %1==1 GOTO init
IF %1==2 GOTO init
IF %1==3 GOTO init
IF %1==4 GOTO init
GOTO not1_4
:init
ECHO ÿÿÿ
ECHO 
ECHO You have requested to INITIALIZE your ATI 2400 etc modem at COM%1:
ECHO This will overwrite your current ACTIVE PROFILE and STORED PROFILE 1.
ECHO IF you do not want to do this ----
ECHO PRESS Ctrl-Break or Ctrl-C TO TERMINATE or Any Key TO CONTINUE.
PAUSE > NUL
ECHO ÿÿÿÿÿÿÿ
ECHO INITIALIZING COM %1
ECHO ÿÿÿ
ECHO ÿÿ
AT COM%1: B1E1L1M0N1PQ0V1W2X6Y0
IF ERRORLEVEL 1 GOTO fail
AT COM%1: &B1&C1&D2&E1&G0&I0&J0&K3&L0&N1&O0&P0&Q5&R0&S1&T5&X0&Y1
IF ERRORLEVEL 1 GOTO fail
AT COM%1: S00=000S01=000S02=043S03=013S04=010S05=008S06=002
IF ERRORLEVEL 1 GOTO fail
AT COM%1: S07=060S08=002S09=006S10=003S11=095S12=050S18=000S25=005S26=001
IF ERRORLEVEL 1 GOTO fail
AT COM%1: S36=001S37=000S38=020S40=000S41=000S46=013&W1
IF ERRORLEVEL 1 GOTO fail
ECHO ÿÿÿ
ECHO NO error was detected -- your ATI 2400 etc connected at COM %1 may
echo have been intialized.
GOTO end
:no_at
ECHO 
ECHO 
ECHO I can't seem to find the critical program (AT.COM) in this directory.
ECHO I don't feel like searching your paths for it.  I am getting out of
ECHO here.    AAAAAAAAHHHHHHGGGGA !!!!!!!  ---  Later!!
ECHO 
ECHO 
GOTO end
:no
ECHO 
ECHO You must specify your COM port number (1, 2, 3, or 4).
goto end
:not1_4
ECHO 
ECHO Your COM%1 is not supported by this program.
GOTO end
:fail
ECHO ÿ
ECHO ÿ
ECHO 
ECHO An ERROR (may be displayed above) was detected while initializing COM %1.
:end
ECHO ÿ
ECHO ÿ
