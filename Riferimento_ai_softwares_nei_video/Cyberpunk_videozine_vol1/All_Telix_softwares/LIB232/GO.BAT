Echo off
install /start
if errorlevel 1 goto DONE
cls
echo 
echo Starting The Liberator now.  To start The Liberator yourself, in the
echo future enter LIBERATE from a DOS prompt, or enter Alt-G LIBERATE
echo from Telix terminal mode.
echo 
pause
echo 
echo on
LIBERATE
:DONE
