

            
            
            
            
            











            

            
            
            
                 
                             TELIX UPLOAD MANAGER (TUM). 
                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
                 


                                    by David Crisp 
                  



                             Version  1.00 - August 1990 

























                                 TELIX UPLOAD MANAGER
                                 ~~~~~~~~~~~~~~~~~~~~
 





            Introduction: 
            ~~~~~~~~~~~~~ 


            TUM is intended to make the uploading of files easier, by 
            removing the need for typing the filename - and possibly the 
            full path - for each file to be sent. This can often be a 
            tedious business, especially when the names are complicated 
            or you wish to upload many files in one go. 

            TUM provides a quick and easy method of searching around the 
            directories on any drive and then "tagging" the file names 
            that you wish to upload as you go. You are initially shown a 
            display of the contents of your selected drive, listing the 
            sub-directories and files (including hidden ones). 
                
            By placing the moving bar against a file name and pressing 
            <ENTER>, that file is then placed in the list for transfer.  
            By placing the moving bar against a sub-directory name (shown 
            with a down arrow), the screen is then changed to display the 
            contents of that directory.  
     
            TUM can be used with the normal file transfer protocols that 
            are within TELIX, or with "external" ones that have been 
            configured in the Protocol Options menu.  The external 
            protocols on the whole are a very useful addition to Telix, 
            because they provide the ability to transfer an almost 
            unlimited number of files in one go. This is often referred 
            to as Batch transfer. Once the file transfer procedure has 
            commenced, all the files are sent sequentially without the 
            need for any user intervention. The internal batch modes in 
            Telix, such as ZModem and YModem only allow a limited number 
            of files to be uploaded in a single session. This number is 
            limited to the number of file names (plus paths if they are 
            not in the upload directory) which can be concatenated into a 
            64-character string. This can at times be a severe 
            limitation. 
     
            TUM also has the ability to work with Bimodem, by writing the 
            list of selected file names directly to the BIMODEM.PTH  
            file. Obviously, Bimodem must be one of the protocols 
            configured in the Protocol Options menu of TELIX. Use 
            <ALT-O> to select this function. 
     
            For purely informational purposes, TUM provides a counter 
            showing the number of files selected for transfer. 

    

     
            Installation:     
            ~~~~~~~~~~~~~ 
            

            The TUM100 archive should contain the following files: 
                 
                 TUM.SLC      Upload Manager (main program) - Compiled 
                 STARTUP.SLC  Installation/setup program - Compiled 
                 TUM100.DOC   This document. 

     
            1)   Copy the above files into your Telix Script Directory. 

            2)   To make TUM quick and easy to run on my system, I have 
                 used the keyboard macro facility of TELIX to assign TUM 
                 to the "PgUp" key. 
     
                 To do this from within TELIX:-

                 a)  Press <ALT-K>. 
                     You will see a display giving the option: 
                 
                     Regular or Terminal 
     
                 b)  Place selector bar over Regular and press <ENTER>. 
                     You will see another display with the options: 

                     "Load  Save  Clear  Display  Displaykey  Edit  Exit" 

                 c)  Place cursor bar over EDIT and press <ENTER>. 
                     You will see another display saying: 

                     "Press key to edit or Space bar to exit" 

                 d)  Press the <PgUp> key. 
                     You will be prompted to enter the keyboard macro, so 
                     type: 
                 
                     @TUM 
                 
                     and then press <ENTER>. 
                 
                 e)  Press the Space bar to quit. 
                 
                 f)  Select the Save option, and then press <ENTER> to 
                     save it to TELIX.KEY. 

                 g)  Press "X" to Exit the keyboard definition menu. 
                  




            Telix Upload Manager - Background Information: 
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 


            Telix Upload Manager (TUM) needs to be able to know some of 
            the contents of the TELIX config file  (TELIX.CNF). It 
            requires details such as :- 


                 a)  What external protocols the user has set up, 
                     including the names of the script/batch files needed 
                     to run them, and the "Key" letters used. 

                 b)  The default screen size (ie 25, 43 or 50 lines). 

                 c)  The drive and path that TUM will show the contents 
                     of at startup.  
                 
                 d)  The user defined screen colours.
     
            For speed of operation it was considered too slow to read 
            the configuration file each time TUM is run, so included 
            with this package is a separate script called "STARTUP".  
            This will read the configuration file and then store the 
            information into the Keyboard Table. The advantage of this 
            is that information held in the keyboard table is held in 
            memory, so it can be accessed faster. 
      
            The required information is stored in locations used by the 
            <CTRL-Left Arrow>, <CTRL-Right Arrow> and <CTRL-HOME> 
            keys. It is unlikely that any user will be using these key 
            combinations for other purposes. 
     
            Each time TUM is run, it looks at these locations. If this 
            script is being run for the first time these locations will 
            be empty, so "STARTUP" will be run automatically for you. 
     
            The <PgUp> key (along with the <ALT-S> key) originally 
            displayed the upload protocols and <PgDn> (together with 
            <ALT-R>) displayed the download protocols. The redefinition 
            of the "PgUp" key now overrides the previous action of this 
            key but leaves the other keys performing their original 
            task. 
     
            I would suggest that if it is necessary to upload more than 
            two or three files in one session, you should contemplate 
            using one of the advanced external protocols such as DSZ 
            Zmodem, Bimodem, Puma, Lynx etc, since these allow many 
            files to be transferred in one large batch. They do this by 
            having the ability to read a separate file containing a list 
            of the file names (including paths) to be transferred. 

              


            TUM will create a file called FILE.LST in the Telix 
            directory, which contains a list of all the files that have 
            been selected for upload. These names will contain the full 
            path if the file is not in the normal Telix upload 
            directory. If the file is in the upload directory, only the 
            filename will be in the file. 

            If you have configured Telix to work with Bimodem (using the 
            external protocols menu within the <ALT-O> menu) it is 
            essential that you use the key letter "B".  This is because 
            the script treats Bimodem somewhat differently from other 
            external protocols. With Bimodem, TUM will write directly to 
            a file called BIMODEM.PTH located in the Telix directory. I 
            suggest you ensure that Bimodem is configured to look for 
            its BIMODEM.PTH file in this directory. This can be done by 
            entering the configuration menu of Bimodem by either typing 
            "BICONFIG" (from the DOS prompt), or by selecting the 
            Configuration option from BIMENU. The essential entry will 
            be found under the heading "Filenames and Paths". Ensure 
            that the entry looks something like:-
            
                     c:\telix\BIMODEM.PTH
                     (filename must NOT be renamed) 

            The files FILE.LST and BIMODEM.PTH will remain in the TELIX 
            directory when the upload has finished and will then be over-
            written on the next occasion that TUM is used, so there is no 
            need to delete them unless you are short of space on your 
            disk. 

            Telix is restricted insofar as if you select one of the 
            internal batch type protocols such as Zmodem, Ymodem (batch) 
            etc, the number of files which can be transferred in a 
            single batch is limited to the number of filenames 
            (including drive/path and space characters) which can be 
            fitted into a single 64-character string. The only exception 
            to this is if the files are located in the user-defined 
            Telix upload directory. In this case, only the file names 
            need be used. TUM complies with this restriction by 
            automatically omitting the path when possible and hence 
            providing more space for filenames within the 64-character 
            string. Therefore if you have to upload quite a number of 
            files using an internal batch protocol, you will benefit by 
            placing these files in the Telix upload directory so that 
            more files can be sent in a single batch. 

            TUM will use the screen colours that you have previously
            defined when initially setting up Telix. This is to ensure
            that TUM will work equally with colour or mono PCs, and so
            blend in with your normal Telix environment.


     


            PLEASE NOTE: 
            ~~~~~~~~~~~~ 

            It is necessary that each time any further changes are made 
            to the entries in the Protocol Options Menu, or the default 
            screen size by using <ALT-O>, or the screen colours then 
            STARTUP is run to ensure that the Keyboard table entries are
            up to date. Otherwise TUM will try to use the old settings,
            and an error may happen. If you get strange results and you 
            cannot remember whether you have run STARTUP since your last
            alterations, run STARTUP anyway. It won't do any harm!! 

            For those with EGA and VGA monitors, Telix can be used in 43 
            or 50-line mode.  This can be achieved by setting up the 
            screen size using the <ALT-O> option and then selecting 
            "Screen and Colour settings". One of these options is to set 
            the "Default screen size". Using either of these two modes 
            can be very useful if you have directories containing large 
            numbers of files. For instance, the 50-line setting gives the 
            ability to display over 200 filenames. 

            If the screen size is changed during the Telix session using 
            the <ALT-M> key, TUM will display the wrong window size.  
            This is unavoidable since the screen size is not provided by 
            Telix, as a System variable. 


            External Protocols: 
            ~~~~~~~~~~~~~~~~~~~ 

            This script uses the ability of many external protocols to 
            provide "Batch" transfer. Batch transfer implies a process in 
            which more than one file can be sent consecutively, with no 
            user intervention once the upload procedure has commenced. 
            This can only be done by protocols having the ability to pass 
            the file name over the link. Protocols such as Xmodem do not 
            possess this ability. 

            With protocols such as DSZ, PUMA, BIMODEM, LYNX etc, batch 
            transfer is achieved by using a file containing a full list 
            of the filenames to be transferred. If this file name is 
            included in the command line which calls the transfer with a 
            preceding "@" symbol, the protocol knows that this is a 
            "List" file rather than a file to be transferred. An example 
            command line might look like:-

     
     
                 puma S @FILE.LST              or 
                 
                 dsz port 2 sz @FILE.LST 




            TUM will create this file (FILE.LST) in your TELIX directory 
            and it will be called by your External protocol script or BAT 
            files providing that either: 
            
            1)   the Script file contains the words "_ext_filespec" as 
                 part of the command line,  or 

            2)   the BAT file contains the "%3" string as part of the 
                 command line. 

            TUM will then pass the string "@FILE.LST" to your script or 
            BAT file instead of the file name which is normally passed 
            from the TELIX upload filename window. For further 
            information, consult the Appendix to the TELIX manual. 
     
            For BIMODEM, your Script or BAT file need not contain the 
            above strings since TUM writes directly to the BIMODEM.PTH 
            file in the Telix directory. 
                 
     
            Please Note: 
            ~~~~~~~~~~~~ 

            TUM will only work with external protocols supporting this 
            mode of batch transfer (i.e. those which accept the @FILE.LST 
            syntax). This may exclude modes such as JModem and CXMODEM. 
            However, all the other modes mentioned above support this 
            method, so you should have plenty of scope. 
 

            External Protocol Script files: 
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

            There is a set of script files available for running many of 
            the available External Protocols, which I can thoroughly 
            recommend; certainly they take a lot of the hassle out of 
            installing and running these protocols. They should be 
            available on your BBS. They are called: 

            TELIX 3.1x External Protocol Scripts 

            by  Ross Beresford ( See T3XPLIB2.ZIP) 




            Telix Upload Manager - Operation: 
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

            Initially TUM can be run by either pressing the <PgUp> key, 
            or by manually executing the script using the <ALT-G> key 
            and then typing: 

            TUM <Enter>. 

            If this is the first time that TUM has been run, it will call 
            the installation script STARTUP and save the configuration 
            information to the keyboard table. On future occasions it 
            will go straight to the protocol select menu. 
     

            STARTUP program: 
            ~~~~~~~~~~~~~~~~ 

            When the STARTUP program is run, you will initially be shown 
            a menu giving you the option of deciding which directory will 
            be displayed when TUM is first run.  The options are:
                 

            1)   Telix Upload Directory 

                       TUM will always startup displaying the contents of 
                       the Telix Upload directory. 
     
            2)   Final directory when TUM last used 

                       TUM will startup displaying the contents of the 
                       directory used when TUM was last run. This can 
                       be quite handy if you often upload from a directory 
                       which is not the normal Telix Upload directory. 
     
            3)  The Root directory of selected drive 

                       TUM will start by displaying the contents of the 
                       root directory of any drive you select. 
            
            If you have configured the Upload directory in Telix without 
            entering the drive (i.e.\TELIX\UPLOAD\) TUM will 
            automatically sense this and ask you for the associated 
            drive. 

            Once you have made your selection and confirmed that it is 
            correct, the screen will clear to display a message whilst 
            all the information is being processed and stored into the 
            keyboard table. 



                 
            If at any time you wish to change your default 
            drive/directory, the screen size or any of the external 
            protocols, run STARTUP again. Just go to the script window 
            in Telix using <ALT-G>. Doing so will not cause any harm 
            since it merely restores your current configuration to the 
            keyboard table. 

            Protocol Select Menu: 
            ~~~~~~~~~~~~~~~~~~~~~ 

            When TUM is run, the Protocol Select menu will appear. This 
            will be similar to the menu normally seen in Telix except 
            that a short description will be given explaining the 
            benefits (or otherwise) of each protocol. As in Telix, you 
            can either press the appropriate "key letter" for that 
            protocol (which is highlighted in white), or use the cursor 
            keys to move the red cursor bar to the required protocol and 
            then press <ENTER>. The screen will then clear to show a 
            display of the files and sub-directories of your selected 
            directory. You may quit by pressing the <ESC> key, or by 
            selecting the Quit option and pressing <ENTER> 

     
            Main File Select Window: 
            ~~~~~~~~~~~~~~~~~~~~~~~~ 

            This window shows the total contents of the selected drive or 
            directory. The displayed drive and directory is indicated at 
            the top of the screen, together with a count of the number of 
            files selected for upload. 
            
            The screen shows either: 

            1)  Sub-directories (Shown with a down arrow before the 
                 name). 
            
            or 
            
            2)  Files in the selected directory. 

            In both cases the names of files and directories will be 
            displayed even if they are hidden.
             
            By using the cursor keys (Up, Down, Left, Right) and the 
            <HOME> key, the red selector bar can be moved around the 
            screen to highlight any name. 
              
            If you highlight a directory name (shown with a down arrow) 
            and press <ENTER>, the screen will change to show the 
            contents of that directory. 



                 
            If you highlight a file name and press <ENTER>, that file 
            will be "tagged" as a selected file for upload. You should 
            see a symbol appear to the left of the file name. If you wish 
            to remove the file name from the transfer list, re-select 
            that file with the red bar and press <ENTER> again. The 
            "tagged" symbol will disappear. 

            If you highlight a sub-directory which is listed as  ".." and 
            shown with an up arrow and then press <ENTER>, the display 
            will change to show the contents of the directory one level 
            up towards the root.  Using this method it is very quick and 
            easy to move around the entire disk with the minimum of fuss, 
            purely by using the normal cursor keys, the <HOME>, and the 
            <ENTER> key. 

            To re-select another drive, press the <F2> key and the Drive 
            Select window will appear. This can often be a quick way to 
            get back the root directory if you are embedded within a 
            complex structure of sub-directories; just press <F2>, and 
            then re-select the same drive letter. You will always find 
            yourself at the root of the selected drive. 

            Once you have tagged all the file names which you wish to 
            upload, press the <F1> key and the upload procedure will 
            commence. 

            Should you try to do anything silly, such as selecting Upload 
            (by pressing F1) when no files are selected or other similar 
            things, TUM will beep and provide a message. 
                  
            To Quit without making any selection just press the <ESC> 
            key. 


            Drive Select Window: 
            ~~~~~~~~~~~~~~~~~~~~ 

            The user is given the option to select the Drive to be used. 
            You may either enter a letter such as "A", "B", "C" etc, or 
            just hit <ENTER> for the default drive which you have 
            defined. 

            If you wish to select files from more than one drive, don't 
            worry; the option of selecting another drive is given later. 
            When the drive has been selected, the screen will clear to 
            display the contents of the "Root" directory of that drive. 


     


            Acknowledgments: 
            ~~~~~~~~~~~~~~~~ 

            Thanks must be made to Terry Robertson (Golly BBS), John Nelson
            and Paul Coenraats for their comments and time spent beta 
            testing this program and documentation, and special thanks to 
            Ross Beresford whose expertise with the SALT language saved me
            from pulling my hair out on many occasions.





            Your comments: 
            ~~~~~~~~~~~~~~ 

            Below are a few ideas that I have for future versions of TUM: 


            1)   Tagging all the files in a directory for Upload by 
                 merely pressing one key (e.g F9). 
     
            2)   Un-Tagging all files in a directory by just pressing one 
                 key (e.g F10). 

            3)   Deleting or renaming the FILE.LST and BIMODEM.PTH files, 
                 so that they can be kept for reference purposes. 



            If you have any comments, favourable or otherwise, about this 
            program or you think of any features which you feel would 
            make this program better, please send them to me at: 


                David Crisp   (G4OAE)  on 

                Golly!  (Netmail 2:252/21)     +44 734 320812           




