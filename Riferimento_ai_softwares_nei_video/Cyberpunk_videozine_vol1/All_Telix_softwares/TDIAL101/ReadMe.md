



        TDIAL 1.01





        a product of
        CLASSIC SOFTWARE











































        Copyright 1988 by CLASSIC SOFTWARE



                                                                  < 2 >








                                   WARRANTY

         CLASSIC SOFTWARE makes no warranties, expressed or implied,
         including, but not limited to, merchantability or fitness for
         any particular purpose.  In no event shall CLASSIC SOFTWARE
         be liable for indirect or consequential damages arising from
         the use of the software programs.




































         TRADEMARKS

         Telix is a trademark of PTEL.



                                                               < 3 > 


                                   SHAREWARE

         This product is being released as Shareware. Another way of
         putting it, is that this software is being submitted to you
         for your approval.

         If you like the TDIAL program and use it, that is, it rates
         your approval, please register and pay for it. If TDIAL does
         not rate your approval then please don't use it.

         The registration fee for TDIAL is $10.  A check or money order
         for that amount may be sent to:

                                Claude Dill
                                CLASSIC SOFTWARE
                                230 Hibberd Dr.
                                Centerville, Ohio 45458.



                                                               < 4 >





         TDIAL -- TELIX -- PC PURSUIT


         TDIAL is a script to be used to interface TELIX 3.00 to the
         PC Pursuit system.  It is a high speed dialer that handles
         all the dialing chores from the initial connection to the
         local PC Pursuit number, through the selection and dialing
         of the target city, and on to the dialing of the remote
         cities BBS's.


         Telix, a product of PTEL, is an excellent communications
         program. If you have not yet tried it, you owe it to your-
         self to do so. It has all the features you would expect of
         a modern communications program plus the best script lan-
         guage I have seen. This program is written with the SALT
         script language that is a part of Telix. One final note on
         Telix, it supports INTERNAL Zmodem file transfers. For PC
         Pursuit operation Zmodem is by far the most reliable, and
         in most cases, the fastest protocol available.


         PC Pursuit is a service of Telenet that offers, for modem
         addicts, an alternative to high long distance bills.  For
         a flat $25 per month you may dial in excess of 25 cities
         nationwide during evening hours and weekends.



                                                               < 5 >


         What TDIAL Does


         TDIAL is a script program that must be run after starting
         Telix.  An excellent way of starting both Telix and running
         this script is with the following DOS command (assuming you
         are in the directory where Telix is located).

              TELIX STDIAL

         Alternately you may run Telix and then use <ALT-G> to run
         the TDIAL script.

         Either way Telix will be loaded and the script TDIAL will
         be executed.  The script will then do the following:

               1. Dial your local Telenet number using Telix's dialer

               2. Once connected to Telenet offer you a menu of cities
                  to choose from, or alternately, if you choose, auto-
                  matically start a loop dial on previously selected
                  cities.

               3. Once connected to a remote city TDIAL will offer you
                  a menu of BBS's to choose from, or alternately, im-
                  mediately start a loop dial on the boards you have
                  preselected.

               4. Once connected to a remote BBS, TDIAL turns control
                  over to Telix. If you have selected a script for the
                  BBS connected to, it will be executed.

               5. After terminating the call you can by hitting ALT-D
                  dial other BBS's in the present remote city or by
                  pressing a hot key automatically disconnect from
                  the present remote city and be presented with the
                  menu from which to dial another loop of cities.

         For TDIAL to function properly you will have to properly con-
         figure Telix. The following section describes the configur-
         ation procedure. It is highly recommended that you print it
         out before starting.



                                                               < 6 >


         INSTALLING TDIAL -- CONFIGURING TELIX


         It is assumed that you have already setup and used Telix
         using the documentation provided by PTel with Telix.

         The following steps will enable TDIAL to work properly with
         TELIX 3.00.

         1. Copy all files from this archive to your Telix directory.

         2. Un-arc either MENU-12.ARC or MENU-24.ARC depending on
            your modem speed and Telenet in-dial.

         3. Run Telix.

         4. From within Telix hit <ALT-D> then <RET> for dialing menu.

         5. From Dialing Menu select <O> for other.

         6. From "other" dialing menu select <L> for load.

         7. Type in CITY

         8. Type in <E> for edit.

         9. Type in <1> (number one) then <RET> to edit first entry.

        10. Change "Phone number" entry to your local Telenet number.

        11. Hit return key for other questions.

        12. Type <O> for other again.

        13. Type <E> (or just hit return) to EDIT_LD.

        14. Position menu bar over ! (exclamation mark) and hit return.

        15. Type in your id and password for PC Pursuit in the follow-
            ing format:  ,yourid,password.
            example = ,itsme,123xyz

        16. After hitting return, be sure and hit <S> to save.

                          <<<<* CAUTION *>>>>

            There is now a file on your disc called TX.LD that has
            your PC PURSUIT ID and PASSWORD in it. This file is in
            no way encrypted or compiled and can be read by using
            the TYPE command. If others have access to your system
            you may not wish to use this program.



                                                               < 7 >


        17. <ESC> to exit dialing menu.

        18. Hit <ALT-O> for setup.

        19. Position menu bar over Modem and Dialing and hit return.

        20. Setup as per the following. Note B would be ATDP if
            your local phone has pulse dialing. Note C is a 2
            second delay (your system may work with less delay).
            A,C,E as per your modem. K,L could be shorter or longer.
            N should be off. G seems to be the most common no connect
            strings from the pursuit modems.

ีอต Modem and dialing parameter setup ฦออออออออออออออออออออออออออออออออออออออธ
ณ                                                                            ณ
ณ A - Init string ......... ATZ^M~~~AT S7=45 S0=0 V1 X4^M~                   ณ
ณ B - Dialing prefix 1 .... ATDT                                             ณ
ณ C - Dialing prefix 2 .... ~~~~                                             ณ
ณ D - Dialing prefix 3 .... ATDT                                             ณ
ณ E - Dialing suffix ...... ^M                                               ณ
ณ F - Connect string ...... CONNECT                                          ณ
ณ G - No connect strings .. NO CARRIER             BUSY                      ณ
ณ                           ERROR                  NO DIALTONE               ณ
ณ H - Hang-up string ...... ~~~+++~~~ATH0^M                                  ณ
ณ I - Auto answer string .. ~~~+++~~~ATS0=1^M                                ณ
ณ J - Dial cancel string .. ^M                                               ณ
ณ                                                                            ณ
ณ K - Dial time ........... 45                                               ณ
ณ L - Redial pause ........ 3                                                ณ
ณ M - Auto baud detect .... Off                                              ณ
ณ N - Drop DTR to hangup .. Off                                              ณ
ณ                                                                            ณ
ณ                                                                            ณ
ณ Change which setting?       (Return or Esc to exit)                        ณ
ิออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออพ

        21. Hit return to exit this screen.

        22. Save option changes by hitting <W> on main setup screen.

        23. To create a hot key for running TDIAL, either from DOS
            rename TELIX.KE to TELIX.KEY (this makes <F9> the hot
            key) or if you already have a TELIX.KEY file (meaning
            you have redefined your keyboard or created some Macros)
            add a definition for a selected key of:

              @TDIAL

        24. TDIAL relies on your modem to properly reflect the state
            of the DATA CARRIER signal. For that reason your modem
            must NOT have DATA CARRIER forced on.


                                                               < 8 >
         USING TDIAL


         To use TDIAL turn on your modem and boot telix with the fol-
         lowing command:

         TELIX STDIAL

         or from within Telix hit <ALT-G> and type in TDIAL

         If you get a message saying that TDIAL was not found, then
         most probably TDIAL.SLC is not in your script directory.
         (Use <ALT-O> to check for Script Pathname). Assuming Telix
         does find the TDIAL script it should show the version number
         on the screen and dial your local Telenet indial node.

         Upon connection to Telenet, TDIAL will sound a two tone
         sequence to alert you, then Telix will display a menu of
         available DIRECT CONNECTS and cities to choose from. You
         may select up to 10 DIRECT CONNECTS and cities, in any
         order, to loop dial on.

         Note that when Telix makes a connection the dial menu
         displays CONNECTED HIT ANY KEY. You may hit a key at this
         time if you wish, but it is not neccessary. After a slight
         pause Telix will continue as though you had hit a key.

         When a connection is made one of two things will happen.
         If it is a DIRECT CONNECT, Telix will signal with its
         alarm and you will be placed into the terminal mode.
         If the connection made was with a remote city, TDIAL will
         signal with a 3 tone sequence, and then Telix will display
         the BBS directory for the remote city. You may then select
         up to 10 entries to loop on. In either case TDIAL exits.

         You may continue to use Telix to dial numbers in the remote
         city for as long as you wish. When you are ready to call a
         new city, hit the "hot key".  As distributed the "hot key"
         is the <F9> key. Once the "hot key" has been pressed TDIAL
         will be run again (alternately if you do not have a "hot
         key" set up you may hit a <ALT-G> and type in TDIAL).
         When TDIAL is rerun it senses that carrier is active and
         does a disconnect from the remote city and uses Telix to
         display the selection of cities again.

         You must also do this restart following a connection to a
         DIRECT CONNECT.

         The <ESC> key will abort you out of the dialing menu and out
         of the TDIAL script.

         If while TDIAL is active, it detects a problem it will warn
         you with an error alarm -- a series of 8 beeps.




                                                               < 9 >

         AUTOMATING TDIAL


         You may further automate TDIAL by preselecting the cities
         you wish to loop dial each time you boot up Telix and TDIAL.
         You may also preselect for, each city, a set of boards to
         loop on. TDIAL as distributed is set up to, after connecting
         to Telenet, loop dial on Boston, San Francisco, and Wash-
         ington DC. After connecting to any one of these cities, it
         is set up to immediately start dialing a preselected series
         of boards.

         This preselecting is done, in both cases, from within Telix.
         to set up your choice of cities to loop on:

           1. Load the CITY menu into the Telix Dialer

           2. Edit entry number "one" TELENET

           3. Change the password entry to the entry numbers of
              the cities you wish to loop on (seperate entries
              with spaces).

         To set up your choice of boards within any given city:

           1. Load the CITY menu into the Telix Dialer

           2. Select Edit

           3. Choose the entry number for the city you are setting up

           4. Change the password entry to the entry numbers of
              the boards you wish to loop on (seperate entries with
              spaces).



                                                               < 10 >

         ADDING ENTRIES


         You may add entries to both the City directory and the in-
         dividual dialing directories as you wish, with but a few
         limitations.

           1. Entry number 1 in the CITY menu is for your local
              Telenet dialin.

           2. In the CITY menu entries number 2, 3, & 4 are reserved
              for DIRECT CONNECTS. You are free to select any three.

           3. The baud rate entry for all the cities should be the
              same as the baud rate selected for the TELENET
              dialin. If you are using 2400 baud and a remote city
              does not support 2400 you would still leave the baud
              rate entry at 2400. The 1200 baud for the remote city
              is selected with the D/*****/12! dialing entry.

           4. The dialing prefix for the TELENET entry must be "1".
              The dialing prefix for all the DIRECT CONNECTS and
              cities must be "2". The dialing prefix for the BBS
              entries should be "3". (Although "1" will probably
              work, by using "3" Racal-Vadic mode will be easier
              to implement at a later time. Using "3" also allows
              for people with a pulse dialin to set "1" to ATDP
              and keep "3" at ATDT).

           5. The baud rate for all remote BBS's must be the
              same as your TELENET entry. If you dial into PC
              Pursuit at 2400 baud, connect to a remote city, and
              then to a remote BBS and your baud rate for that BBS
              entry is 1200, Telix will down shift to 1200 and you
              will get garbage from the local Telenet dialin.

              (An additional word on dialing in to Telenet at 2400
              and connecting to remote boards at 1200. While in the
              terminal mode and during file transfers you will notice
              a jerkiness caused by the speed mismatch. Hopefully all
              of the outdial ports will soon have 2400 capabilities.)



                                                               < 11 >


         SOUNDS and BACKGROUND OPERATION


         The main reason for the different tone sequences at different
         times, is that I run Telix and TDIAL primarily as a back-
         ground task.  The tones summarized are as follows:

              1. A two tone sequence 660 then 880 means that TDIAL has
                 established a connection with TELENET.

              2. A three tone sequence 660,880, then 1100 means a
                 remote city has been reached.

              3. Telix's alarm tone will be sounded when connection has
                 been made with either a DIRECT CONNECT or a remote BBS.

              4. A series of eight beeps means that there is a problem.


         Using DOUBLEDOS I have found that Telix and TDIAL will run in
         a 205K partition (with a 10K scrollback buffer). Using DESQVIEW
         requires a partition of 190K.




                                                               < 12 >

         One last reminder that this is shareware and that if you use
         this program, please pay for it.

         The following page is a mailer that can be used for registering
         TDIAL. Or you may use a conventional envelope and mail to:

                       Claude Dill
                       Classic Software
                       230 Hibberd Dr.
                       Centerville Ohio 45458.

         All registrations will be acknowledged. Thank You.

         If you have problems and/or comments you can reach me on the
         PC Pursuit BBS.




          This mailer is provided as a convenience for registering TDIAL


          Your
               NAME   _______________________________________

               ADDRESS_______________________________________

               CITY STATE ZIP________________________________


          Please staple/tape check or money order for $10 to this section
          fold on fold NUMBER 1. Then fold on fold NUMBER 2 and staple/tape
          closed.



  ---------------------  FOLD NUMBER 1  -----------------------




















    -------------------  FOLD NUMBER 2  -----------------------

_________________________________                                     Place

_________________________________                                     Stamp

_________________________________                                     Here







                                         Claude Dill
                                         Classic Software
                                         230 Hibberd Dr.
                                         Centerville Ohio 45458





