Characters typed within a pair of single or double quotes ("xyz) are nor-
mally ASCII-character keystrokes.  Numbers (nn) not in quote marks are
ASCII decimal codes, e.g. 13 (Enter), 26 (Ctl-Z), or 27 (Esc).  Numbers
preceded by @ area the extended ASCII decimal codes (128 - 255) generated
by the Alt keys, cursor keys, Ins and Del keys, and the function keys
(e.g., @61 is the F3 keystroke).  Use the 0 with programs that check the
keyboard buffer (it tells such programs that the buffer is clear, so that
the programs will treat the succeeding keystrikes separately.

EXAMPLE:	cd \lotus
		key-fake 0 13 0 13 0 13 0 13 0 13 "/FR"
		lotus

Keystroke sequence is limioted to 124 characters on one continuous line.
Keystrokes not supported by PC BIOS (e.g. Alt-Home) cannot be stored.

Use KEYTEST to get the ASCII values.




























T E L I X    M O U S E   S Y S T E M
-----------------------------------------------------------------
Program Reference Manual

Note : This document has been tailored for printing
	  (use 'TYPE TLX311M3.DOC > PRN')














                            





                         Brent Williams
                              
                        10 Sugar Millway
                     Toronto,   ON   M2L 1R4

     Telix v3.11 Mouse System           Registration Information




                             NOTICE

   
     The Telix v3.11 Mouse System, hereafter referred to as the
     TMS, is distributed to the public under the ShareWare
     software concept.  Use of this product for an extended
     period of time requires registration with the author.  This
     involves completing the form included in this file or in
	the file TLX311M3.ODR, and sending it along with a minimum
     registration fee of $5 to the address indicated on the form.
     Registered users receive though the mail full support of the
     product.  This includes a copy of the latest version of the
     TMS on a 5 1/4 inch disk, customization (whereby custom
     colours, button layouts, etc. can be received for no
     additional cost, should the customization be possible and
     reasonable), and any other shareware products released by
     myself that I feel may be of use to you, as well as a thank-
     you.

     TMS may not be included with any other product for any
     reason without the express consent of the author of TMS
     (Me!).

     TMS must be distributed in absolutely unmodified form,
     including ALL documentation, program and support files that
     were present when the package was received.

     No charge or payment may be demanded for this product,
     except only for the cost of the media it occupies, which is
     a maximum of 10 (ten) dollars Canadian currency.



















     Telix v3.11 Mouse System                          Order Form



     Telix v3.11 Mouse System
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
     Adr: Brent Williams. 10 Sugar Millway, Toronto, ON   M2L 1R4
     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Quan      Includes                      Cnd/US         Price

     ____      TMS on a 5 1/4 disk,      @     $5+          $____
               customization option
               (See below) & any other
               ShareWare releases of
               mine that may be of use.


                         Checks Accepted

     ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

     Name________________________________________________________

     Company_____________________________________________________

     Address_____________________________________________________

            _____________________________________________________

     Phone (_______)_______________ Bus. (_______)_______________

     Where did you obtain TMS?
        
            _____________________________________________________

     Comments/Suggestions for Improvement
            _____________________________________________________
   
            _____________________________________________________
   
            _____________________________________________________

     Requested Customization (Optional)
            _____________________________________________________

            _____________________________________________________

            _____________________________________________________





     Telix v3.11 Mouse System                            Contents




   
                              C O N T E N T S


   
     1         Introduction...................................1
     1.1       Program Description............................1
     1.2       Machine Requirements...........................1
     1.3       TMS Files......................................1
   
     2         Setting Up.....................................1
     2.1       Where to Use TMS...............................2
     2.3       Installing/Uninstalling TMS....................2
     2.3       The QuickDial Function.........................2
     2.4       Use With Other Mouse Systems...................2
     2.5       Button Conventions.............................3
     2.6       3-Button Mice..................................3
     2.7       Mouse Menu Colours.............................3
     2.8       EGA & VGA video modes..........................3

     3         The Main Menu..................................4
     3.1       Changes from Telix's...........................4
     3.2       Mouse Help.....................................4
     3.3       Mouse Speed....................................4
     3.4       Information....................................5
     3.5       The Printer On/Off Function....................5

     4         The Redial Menu................................5
     4.1       Commands.......................................5
     4.2       Exiting........................................5
     5         Future Enhancements............................5

     6         Trouble Shooting...............................6
















     Telix v3.11 Mouse System                              Page 1

                              1.0 Introduction

	1.1 Program Description

          The Telix v3.11 Mouse System is a comprehensive
          keyboard supplementer for use with Telix v3.11 from
          Exis Inc.  Some of it's features include:

               -    Full menu of all Telix v3.11 ALT commands.

               -    Simulation of almost all useful keys so that
                    your mouse may be used whether you are
                    changing the screen colours, editing a
                    dialling entry or scrolling through some     
                    text.
             
               -    On-Line help available directly from the main
                    mouse menu.

               -    It's much more than a front end for Telix
                    functions.  It's a useable and intuitive
                    program making for quick and easy Telix
                    control.

     1.2 Machine Requirements

          To use TMS your machine must meet the requirements for
          Telix itself, and also the machine must have an
          operational MicroSoft Mouse (or Compatible), an
          installed mouse driver and approximately 15K free RAM
          to hold TMS (TMS is actually a Terminate Stay Resident
          program).

          This means must have a total of at least 185K free RAM
          and a MicroSoft mouse or compatible (with the driver
          installed through either MOUSE.COM or MOUSE.SYS in your
          CONFIG.SYS file) to run TMS under Telix v3.11.

     1.3  TMS Files

          The TMS package includes ten files.  The functions
          of each file is described in the TLX311M3.ME file,
          which accompanies this archive.

               Note : Thanks to Ken Mason for providing many of  
                      the support files used in TMS, as well as  
                      suggesting improvements, many of which have 
                      been implemented in this version of TMS.

        
        
     
	Telix v3.11 Mouse System                                  Page 2

                         2.0 Setting Up

	2.1  Where to Use TMS

          TMS is designed only for use with Telix v3.11.
          Operation with most other packages (including DOS) is
          not recommended.  Most likely, the mouse will emulate a
          carriage return if any button (or both) are pressed,
          and movement will emulate the four cursor control
          buttons, but this may vary depending on the
          application.  As a general rule install TMS before
          using Telix and uninstall it when you exit back to DOS.
          (The batch file TLX.BAT is included which helps make
          this easier.)

     2.2  Installing/Uninstalling TMS
        
          TMS is installed simply by typing MENU TLX311M3.  The
          message 'Menu Installed' will be returned indicating
          successful installation.
        
          TMS is disabled by typing MENU OFF.  A message will
          indicate keyboard emulation off.  Note that the menu is
          not actually removed from memory, the included PC
          Magazine utilities INSTALL.COM and REMOVE.COM          
          accomplish this. 

     2.3  QuickDial Function

          Telix v3.11 has a function called QuickDial whereby you
          need only enter the numbers of entries in the dialling
          directory to call them.  Since it takes so little time
          to dial from the dialling directory itself, TMS assumes
          that this function has been turned off.  Operating TMS
          with this function active will work, though you will be
          missing out on some nice features of TMS.

     2.4  Use With Other Mouse Software

          If you run an editor which makes use of the mouse, or
          shell to DOS and run an application which makes use of
          the mouse, TMS will not be operational when you return
          to Telix.  To fix this problem, create a batch file
          which first turns off TMS, then calls the external
          application, then turns TMS back on.  Use this method
          for your editor should it use the mouse, and any other
          mouse programs you might use under Telix in the DOS
          shell.




     Telix v3.11 Mouse System                              Page 3

     2.5  Button Conventions

          The left and right buttons are used to call up menus
          and/or operate functions.  Both buttons always emulates
          ENTER or abort.  Cursor movement always emulates the
          cursor keys, except during the Telix ReDial function,
          in which they are disabled so that an accidental mouse
          movement won't abort the ReDial function.

     2.6  3-Button Mice

          The programming kit used to produce this package is
          produced by MicroSoft, and since MicroSoft sells only 2
          button mice it included support for 2 button mice only.

          3-button LogiTech and PC Mice work fine though; the
          third button simply has no effect on the program.  

     2.8  Mouse Menu Colours

          I chose the colours presently used in the mouse menus
          hoping that they would acceptable to all, but if you do
          not like them you can easily have them changed by
          registering (if you have not already), and dropping my
          a line or letter stating what colours you would like.
          I would be happy to send you a customized copy with
          those colours.  Due to the nature of the language used
          to program TMS they cannot be changed directly from
          within the program, nor as a run-time option.  I have
          not included copies with varying colour schemes in this
          archive to keep it down to a reasonable size.  But if
          any hacker wishes to break into the program and put
          purple dots all over the menus, he/she is welcome to do
          so, as long as the altered copy is not released to the
          public.

     2.8  EGA & VGA video modes

          Telix v3.11 supports EGA 43 and VGA 50 line modes.  But
          to allow for compatibility with all systems Telix v3.11
          and TMS menus use only the first 25 lines of the
          screen.  Note that TMS works just fine with 43 (which I
          myself use) and 50 line modes, but does not take
          advantage of the extra rows.








     Telix v3.11 Mouse System                              Page 4

          Note :    Though I have never experienced the problem,
                    it has been said that Telix messes with the  
                    font tables on EGA and VGA cards when the 43 
                    and 50 lines modes are used.  If you        
                    experience this problem, please note that
                    this is a function of Telix, not TMS, which
                    has does not adjust the screen modes or the
                    font tables. 


         3.0 The Main Menu

        ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
        ³ Main Mouse Functions:                                ³
        ³      The main mouse menu is called with the left     ³
        ³      mouse button                                    ³
        ³                                                      ³
        ³      The dial function is called with the right      ³
        ³      mouse button                                    ³
        ³                                                      ³
        ³      As mentioned, both buttons emulate an ENTER     ³
        ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

     3.1  Changes from Telix's Help function.

          For some inexplicable reason the author of Telix has
          not alphabeticalized (sp?!) the help menu.  Though TMS
          tries to work with Telix as seamlessly as possible, I
          have alphabeticalized the main mouse menu myself for
          easier use.
         
     3.2  Mouse Help
         
          Clicking on Mouse Help from the main menu calls up a
          brief summary of mouse operations under various
          conditions.  

     3.3  Mouse Speed

          The speed of the mouse (rate of change of on-screen
          pointer vs. movement of the mouse) can be changed using
          this function.  For most purposes the default speed is
          useable.  You can navigate the menus very quickly with
          a high speed, though this results in a very speedy
          cursor should you use the mouse for cursor movement.  I
          suggest using the default mouse speed for most
          purposes.





     Telix v3.11 Mouse System                              Page 5

     3.4  Information

          Clicking on this function brings up a brief description
          of TMS and the problems involved with releasing
          ShareWare.  *Please read* this before using TMS on a
          regular basis.

     3.5  Printer On/Off Function

          Telix v3.11 accepts the Ctrl-@ key combination as a
          toggle for printer capturing.  Unfortunately the kit
          with which TMS was developed does not support this key
          combination, therefore clicking on this function


     Telix v3.11 Mouse System - Page 5

          results in a small 'No can-do' message.  For the moment
          you must use the Ctrl-@ keyboard combination to toggle
          the printer.

                            4.0 The ReDial Menu

     4.1  Commands

          Clicking either button while Redialling numbers pulls
          up a small menu of functions.  They are relatively    
          self-explanatory so I won't go into the functions.

     4.2  Exiting

          Note that there are three ways to exit from the ReDial
          menu.  One exits to the Dialling Directory so you may
          re-select the numbers you wish to dial.  Another exits
          to terminal mode, and a third exits to the mouse menu
          so you may choose another function.
  
                         5 Future Enhancements
        
     This is the third Mouse Menu for Telix I have released. 
     Some enhancements which will soon be implemented include an
     auto-speed function, whereby operations involving mouse
     menus operate with a high mouse speed for quick response,
     and cursor movement operates with a lower mouse speed so the

     cursor doesn't begin to break dance while you try and    
     position it.  Naturally, new  releases will come out as Exis
     Inc. improves on Telix itself.  If you would like to see
     these and many more enhancements to TMS, please 'do your
     bit' by registering this package.


     Telix v3.11 Mouse System                              Page 6

                         6 Trouble Shooting

     If you have problems, check the following.

     1.   You are using Telix v3.11 and not an earlier (or later)
          version.

     2.   Telix is up and running.
   
     3.   Your mouse driver IS INSTALLED - this is a common
          error.  Without the mouse driver, not much will
          happen when you try and operate TMS.

     4.   You are pressing the right mouse buttons to get the
          operation you wish.  Blind guessing will probably
          just confuse you.
   
     5.   You have enough memory to install TMS.  Remember, you
          have to have at least 15K free ram to install it.

     6.   Check that your mouse is MicroSoft compatible.
          Logitech and others should work, though I won't
          guarantee it.

     7.   If problems continue and all of the above check out Ok,
          drop me a note through the mail explaining the problem
          and any information that might be relevant (ie DOS
          version, other TSRs present, total memory, computer
          make, etc.) and I will do my best to help you, either
          by suggesting a solution or sending you a modified
          version of TMS which will work with your system.
