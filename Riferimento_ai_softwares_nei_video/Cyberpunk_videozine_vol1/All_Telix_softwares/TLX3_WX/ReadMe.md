
To add WXmodem (Windowed Xmodem) to Telix 3.0, put the two enclosed
batch files in your Telix subdirectory.  Then, in Telix, use ALT-O to
bring up the Configuration Menu and use "P" for Protocols.  Make an
entry for WXmodem like this:

External    Key   Protocol       Upload      Download    BAT or     DL
Protocols           Name        Filename     Filename    Script    Name

A,B,C or D   W   WX-Modem       WXS.BAT      WXR.BAT     Batch      Y


Don't forget to "Write setup to disk" and have WXFER.COM in your path!

Hope this helps!

 - Jim Anderson, Sysop, THE MONTANA CAFE, (406) 721-7314, 24 hrs, 300-9600










    Here's the first version of WXFER!  It is actually WXTERM, changed
    around to take command-line parameters, monitor carrier, and give
    return codes--the things needed to make it work in DCS.

    The command line is relatively simple--
    -s          sends a file
    -r          receives a file
    -r!         receives a file and will overwrite it if it exists
    speed       specifies communications speed
    port        specifies communications port
    -c          requires carrier

    The defaults are port 1, speed 1200, and carrier detect NOT required.
    Here is an excerpt from our new transfer.dcs:

    To receive a file (user upload):

    if Protocol = "W"
       then begin
            Let CommandLine = " port "+*Port+ " -c speed "+*Baud+" -r! ",FullFilePath
            Execute "C:\SYSFILES\WXFER.COM" + CommandLine
            end-if

    To send a file (user download):

    if Protocol = "W"
       then begin
            Let CommandLine = " port "+*Port+ " -c speed "+*Baud+" -s ",*FileSpec
            Execute "C:\SYSFILES\WXFER.COM" + CommandLine
            end-if


    Some example command lines:

    "WXFER port 1 -c speed 2400 -s c:\dcs\dcs4-12.arc"
    "WXFER speed 2400 -r! test.arc"


    Lemme know how it works!





                                                Marty
                                                April 17, 1987
