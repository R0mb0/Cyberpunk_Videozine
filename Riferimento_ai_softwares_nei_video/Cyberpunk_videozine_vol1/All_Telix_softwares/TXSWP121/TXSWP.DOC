







                                    TxSwp

                         The Telix Application Swapper














          TxSwp, Copyright 1991 Aquila Data Systems and Chris Curran.
                             All rights reserved.




















                           Aquila Data Systems, Inc.
                              304 Bayfield Drive
                              Brandon, FL  33511

                FAX       : (813)653/2408  Group II, III
                BBS Line 1: (813)653-2397  1200,2400,9600 v.32
                BBS Line 2: (813)685-4218  1200,2400,9600 v.32


     License    This version of TxSwp is NOT public domain or free software,
                but is being distributed as "shareware".

                Non-registered users of this software are granted a limited
                license to make an evaluation copy for trial use on a
                private, non-commercial basis, for the express purpose of
                determining whether TxSwp is suitable for their needs. At
                the end of this trial period, you should either register
                your copy or discontinue using TxSwp.

                What does all this really mean? If you use this program,
                then you should pay for your copy. That way Aquila Data
                Systems will be able to provide you support and updates.
                Registered users receive technical support (via our support
                BBS) and a version of the program that does NOT show the
                opening shareware registration screens.

                A TxSwp registration entitles you to use the program on any
                and all computers available to you, with the following
                restriction: If other people have access to this program or
                may use it, then you should purchase a site license.  See
                the following section for information about site licensing
                or quantity discounts.

                All users are granted a limited license to copy TxSwp only
                for the trial use of others and subject to the above
                limitations. This license does NOT include distribution or
                copying of this software package:

                    1. In connection with any other product or service.
                    2. For general use within a company or institution.
                    3. For any consideration or 'disk fee'.
                    4. For distribution in modified form; i.e., the file
                       containing this license information MUST be included,
                       along with the full TxSwp documentation.

                Operators of electronic bulletin board systems (Sysops) are
                encouraged to post TxSwp for downloading by their users, as
                long as the above conditions are met.



  Disclaimer    The software and accompanying written materials (including
                instructions for use) are provided "AS IS" without warranty
                of any kind. Further, Aquila Data Systems does not warrant,
                guarantee, or make any representations regarding the use, or
                the results of the use, of the software or written materials
                in terms of correctness, accuracy, reliability, currentness,
                or otherwise. The entire risk as to the result and
                performance of the software is assumed by you. If the
                software or written materials are defective you, and not
                Aquila Data Systems or its dealers, distributors, agents or
                employees, assume the entire cost of all necessary
                servicing, repair, or correction.

                No warranties of any kind, either express or implied,
                including but not limited to the implied warranties of
                merchantability and fitness for a particular purpose, that
                are made by Aquila Data Systems on this Aquila Data Systems
                product. No oral or written information or advice given by
                Aquila Data Systems, its dealers, distributors, agents or
                employees shall create a warranty or in any way increase the
                scope of this warranty, and you may not rely on any such
                information or advice. This warranty gives you specific
                legal rights. You may have other legal rights, which vary
                from state to state.

                Neither Aquila Data Systems nor anyone else who has been
                involved with the creation, production, or delivery of this
                product shall be liable for any direct, indirect,
                consequential, or incidental damages (including but not
                limited to damages for loss of business profits, business
                interruption, loss of business information, and the like)
                arising out of the use or inability to use such product even
                if Aquila Data Systems has been advised of the possibility
                of such damages. Because some states do not allow the
                exclusion or limitation of liability for consequential or
                incidental damages, the above limitation may not apply to
                you.


  Trademarks    All trademarks and copyrights belong to their respective
                holders.


    Ordering    A TxSwp registration licenses you to use the product on a
 Information    regular basis. Registration includes notification of updates
                and technical support (via our support BBS).

                Registering TxSwp costs $25 (plus 1.50 shipping). When
                received, we will send you the latest TxSwp diskette, with
                documentation on the disk. Alternatively, if you so specify,
                we will send you the next update of the program, when
                available. Florida residents should include 6% sales tax.
                Please use the form at the end of this document.


      Orders    Please send a check drawn on a US bank in US dollars.  We
     outside    can accept non-US currency; however, you must include an
      the US    additional $25 to cover conversion and collection costs.
                Please include an additional $10 to cover postage on orders
                delivered outside of the US.


   Corporate    All corporate, business, government or other commercial
        Site    users of TxSwp must be registered.  We offer quantity
Licenses and    discounts as well as site licensing.
    Quantity
   Purchases    Corporate site licensing agreements allow duplication and
                distribution of specific numbers of copies within the
                licensed institution. Duplication of multiple copies is not
                allowed except through execution of a licensing agreement.
                Site license fees are based upon estimated number of users.

                Note that with a site license, only one copy of the program
                will be sent.  You will be responsible for distributing
                additional copies.

                Please call or write for more information.

                ALL PRICES AND DISCOUNTS ARE SUBJECT TO CHANGE WITHOUT
                NOTICE. Discounts are not cumulative; they apply to single
                orders of like products only. Unit prices are the same as
                for individual users.


     WARNING    YOU MAY NOT USE TxSwp WITHIN YOUR ORGANIZATION WITHOUT A
                PRIOR PURCHASE OR LICENSE ARRANGEMENT.


 Development    C compiler     : TurboC++ v1.0     (Borland)
  Tools Used    Assembler      : TASM v2.0         (Borland)
                Linker         : TLink v3.0        (Borland)
                Debugger       : TDebug v2.0       (Borland)
                Editor         : Qedit 2.10a       (SemWare)
                C Lib          : CodeRunneR        (Microsystems Software)
                Version Control: PVCS for DOS      (Sage Software)

     Program    TxSwp v1.21
        Name    Telix Application Swapper


 What is it?    TxSwp is a program that allows you to load Telix as if it
                were a TSR. This is NOT a multi-tasker; Telix is simply
                swapped in and out as desired. The *only* time Telix is
                actually running is when it is being viewed.


      System    TxSwp will run on the IBM PS/2, PC/AT, PC/XT, PC, PC/Jr, and
Requirements    on IBM compatible computers including the Compaq, NCR,
                Tandy, and WYSE PC's.  MINIMUM requirements are:

                  - 512k of memory.
                  - PC-DOS 3.0 or greater or MS-DOS 3.0 or greater.
                  - Either a color or a monochrome monitor with 80-column
                    display.
                  - 25k of disk space, or ~1.5meg if swapping to disc.


      Memory    Now for the next question in everyone's mind - how much
Requirements    memory is this going to cost me? (drum roll please)...8k!
                And if you have EMS memory (LIM 3.x-4.x), TxSwp can run out
                of it, leaving only a 1k DOS footprint!

                How can this be? Because TxSwp uses a new and advanced
                technique (patent pending) to "swap" Telix in and out of
                memory as needed. The complete state of the machine is saved
                (including COMM ports), and then Telix is loaded.

                The memory/disc space requirements of TxSwp are as follows
                (assuming you use the default memory settings):

                    1.  ~1.5meg of XMS memory, or
                    2.  ~1.5meg of LIM memory, or
                    3.  A disc drive with ~1.5meg of free space, or
                    4.  Any combination of the above.

                TxSwp is able to "scatter" it's data requirements among the
                different stowage mediums available at load time. In other
                words, it can use some XMS, some LIM and send the rest to
                disc.

                XMS memory is preferred, then LIM, then lastly the disc
                drive. Note that TxSwp can directly access XMS (extended
                memory) if it is available. This type of memory is the
                cheapest to add to a PC (no extra boards are needed to
                install or control this type of memory), and also the
                fastest performing memory you can add to your PC. Street
                prices for memory are now about $50 to $75 per meg
                (depending on type and speed).

                Also note that if you use extended memory, you'll need to
                include HIMEM.SYS in your CONFIG.SYS file (make it the first
                entry).

                If a disc drive is used (and most will need to), then disc
                caching software is recommended. I personally use HyperDisk
                version 4.21 and find it to be one of the best. I have my
                machines on UPS's, so I also enable the disc write caching
                of HyperDisk, which tremendously decreases application swap
                time.

                If you're using this on a 10mhz 286 with 512k RAM and a
                ST-225, please don't tell me how slow TxSwp is at swapping;
                it is you who are slow to swap...<g>...


  Installing    Installing TxSwp is as simple as coping TxSwp.EXE to your
       TxSwp    Telix directory. You do not HAVE to store TxSwp.EXE in your
                Telix directory, but it is recommended.


    Starting    To start TxSwp, simply type in TxSwp at your DOS prompt,
       TxSwp    followed by any optional command line parameters (see
                below). Do NOT start TxSwp if you have "shelled to DOS" from
                another application - this will leave "holes" in your
                memory.

                After TxSwp has been loaded, you may "hotkey" into Telix.
                Repeating the hotkey will "toggle" you between your current
                application and Telix.

                NOTE: With the exception of Windows 3.0, TxSwp can "pop-up"
                      over almost any application - even hi-res graphics
                      applications.


Command Line    The available command line options are as follows:
     Options
                  ?   Display HELP screen. The help screen may be displayed
                      before, or after TxSwp is loaded.

                  /D  The path that TxSwp should change to when Telix is
                      started.

                      Example:    TxSwp /de:\tlx

                                  Changes to disc "E:", directory "\TLX" and
                                  then loads Telix (when the HotKey is
                                  pressed).

                  /E  Forces TxSwp to NOT use any available EXPANDED memory
                      (LIM 3.x-4.x) for swapping.

Command Line      /K  The HotKey that will be used to activate Telix. A
     Options          HotKey is selected by entering HotKey specifiers,
      (cont)          followed by a dash ('-') and then the identifier key.
                      Available HotKey specifiers are:

                          L   Left
                          R   Right
                          A   Alt
                          C   Ctrl
                          S   Shift

                      HotKey specifiers may be combined in any manner,
                      except 'L' and 'R' - these two specifiers are mutually
                      exclusive.

                      A HotKey identifier is any single key. Function keys
                      may be used as identifiers by using the key name (i.e.
                      "F5").

                      Examples:
                        LCS-1         Left-Ctrl-Shift-1
                        RCS-1         Right-Ctrl-Shift-1
                        LCA-1         Left-Ctrl-Alt-1
                        LCAS-1        Left-Ctrl-Alt-Shift-1
                        LC-F9         Left-Ctrl-F9
                        RC-F11        Right-Ctrl-F11
                        LCAS-F9       Left-Ctrl-Alt-Shift-F9
                        RCS-Q         Right-Ctrl-Shift-Q

                  /L  Force TxSwp to NOT to load itself into EXPANDED
                      memory (LIM 3.x-4.x). If EXPANDED memory is detected,
                      TxSwp will attempt to load itself into EMS, leaving
                      about a 1k footprint in DOS (compared to 8k).

                      NOTE: Some combinations of CONFIG.SYS, AUTOEXEC.BAT
                            and QEMM v5.x will not work in this environment.

                  /M  The amount of memory needed (in k) for Telix. The
                      default is all available memory. Reducing the amount
                      of memory required will reduce the size of the swap
                      file.

                      Example:    TxSwp /m384

                                  Loads TxSwp, and allocates 384k for Telix
                                  usage.

                  /S  TxSwp will use the current drive for swapping (if disc
                      swapping is needed). If you do not have sufficient
                      space on the current drive, or, have a RAM drive with
                      sufficient space, use this option to specify a
                      different swap drive.

                      Example:    TxSwp /sg

                                  Loads TxSwp, and swaps to drive G: if
                                  needed.

Command Line      /U  Unload TxSwp from memory. This option requires that
     Options          TxSwp is the LAST TSR that has been loaded. If other
      (cont)          TSR's are loaded AFTER TxSwp, they will need to be
                      removed before TxSwp can perform an unload.

                  /X  Forces TxSwp to NOT use any available XMS memory for
                      swapping.






  To register your copy of TxSwp, please fill out the following form and
  send it along with a check or money order.


  Remit/Send To:  Aquila Data Systems, Inc.
                  304 Bayfield Drive
                  Brandon, FL  33511


---------------------------------------------------------------------------
TxSwp Order Form
---------------------------------------------------------------------------

Name (to register to): ________________________________________________

   Address to ship to: ________________________________________________

                       ________________________________________________

                       ________________________________________________

            Telephone: ________________________________________________

                 Date: __________________


---------------------------------------------------------------------------
QUANTITY         DESCRIPTION                      UNIT PRICE          TOTAL
---------------------------------------------------------------------------

________         TxSwp                            US $ 25.00       ________

                                    Florida Residents add 6%       ________

                                                    Shipping          $1.50

                                         Additional Shipping       ________

                                                       Total       ________

                            Check/Money Order enclosed for US $ ___________

---------------------------------------------------------------------------

      Version Number of TxSwp: ___________________________

          Place obtained from: ___________________________

Type of Computer _________________________________________

Type of Operating System _________________________________

Type of video card/monitor _______________________________

Additional Comments: ___________________________________________________

________________________________________________________________________

________________________________________________________________________
