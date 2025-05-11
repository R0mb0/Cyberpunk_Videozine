                           CPDownload 1.10
                     Copyright CompuProducts 1991
                   Authors: W. Teller, J. Tepperman
                   
License:

   We're not responsible for anything, good or bad that happens to you when you
use this program, no matter what you can prove to a judge, or even if we have
known about the problem before.  We are liable for damages only up to 1 cent,
if you can prove it to a judge.In other words, it is FULLY YOUR RISK when using
this program.  We are only responsible up to US$0.01, if you experience any
losses, in any way shape, or form, due to the use of the CPDownload 1.10
program or any other CompuProducts program you may or may not be using.

Us/We is reffering to CompuProducts Enterprises, and all its employees, 
including Jason H. Tepperman, and William Teller.

Note to Bobbie of Cheers: Thanks for enlightening us!


Introduction:

CPDownloads allows you to have an auto-download capibility (such as the one
Telix provides for Zmodem), for any external protocol which supports AutoDL
that you have installed in Telix.


Setup:

Run CPDS.  This program will search your Telix configuration file for all the
external protocols you have installed.  After it finds each one, it will prompt
you if you want to use it with the CPDownload program.  If this program 
supports auto-download (Puma does, for one), then select yes.  If not select
no.  After CPDS has finished finding all external protocols, it will ask you
if you wish to abort the program.  If you made any mistakes, reply yes, else 
answer no.  CPDS will then ask you for the AutoDownload strings, in other words
the strings which will be the signal to run the protocol (ie Puma for Puma).
CPDS will then create the configuration file, and you will be able to run CPD.


Running CPDownload:

Simply execute CPD.  It will display a copyright, read the configuration file
(if there is no configuration file, it will tell you), and disappear into the
background.  When the auto-download string is received (i.e. Puma for Puma),
it will spring into action, and execute the protocol (using the information
you have provided Telix in the Protocol Setup area).  If you type EXITCPD in
terminal mode, a window will pop up.  You may then exit CPD or exit the menu.

              şÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄş   
              ³  Note: EXITCPD must be typed in all caps. ³
              şÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄş 

From Bob and Jason: CompuProducts Ent. had seen numerous requests for this
                    feature posted on the Telix support conferences.  Because
                    of the relative simplicity of implementing this idea, we
                    wrote one, spruced it up, and released it to the public.
                    
 Version 1.10 Note: This version has some slight modifications (mostly in the
                    configuration section) which makes it easier to use. The
                    main change is in the registration: there is no requirement
                    to register.  Yes, we will still accept contributions for
                    the program, a US$5.00 "contribution" will remove the
                    unregistered notice.  Note: you do not *HAVE* to register
                    the program, however if you wish for the registration
                    banner to be removed you must.  This decision was made
                    on the basis of what we believe is the rather imminent
                    release of Telix 4.00 which will provide this feature.
                    (Hint: Our sources tell us that Telix 4.00 will be released
                           between May & July,1991, barring any new problems.
                           This estimate is based on the previous planned ship
                           date of Telix 4.00 (May 1990), how far behind we
                           believe the project has fallen behind schedule, the
                           speed at which we think Exis is working, and other
                           "implied" ship dates, particularly 1/1/91.)

