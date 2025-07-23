*
* Here's version 1.1 of the 68HC11EVB power glove code. The only change
* is that a port of Dave Stampe's hysterisis deglitching code has been
* added. The routines are activated by sending a "+" and deactivated by
* a "-". 
* 
* Please let me know your results...
*
*    -Ron Menelli       12/10/92
*

*/**********************************************************************
* 
*  Originally "power.c" (c) manfredo 9/91 (manfredo@opal.cs.tu-berlin.de)
*  Developed on an ATARI 1040ST with TC 1.1 using a logic analyzer to get
*  the correct timings.
* 
***********************************************************************/
*/*********************************************************************
*		      ported to PC compatibles by
*			     Greg Alt 10/91
* 
*			    galt@peruvian.utah.edu
*			 or galt@es.dsd.com
* 
***********************************************************************/
*/*********************************************************************
*
* Substantially rewritten by Dave Stampe (c) 1991: PWRFILT.C
*  No cash, no warranty, no flames.
*  This stuff works great, so gimme credit.
*
* Goals <achieved> were:
*
*  Higher speed, smaller code.
*  Polled operation is now possible.
*  Graphics test (VGA)
*  Noise reduction added, gets rid of 99.5% of noise with NO DELAY!
*
*  This runs on a 486/25 with an i/o card. 
*  Someone should adapt it for the usual printer port adapter.
*  It was compiled with Turbo C++ 2.0 but will probably
*  work on any Turbo C directly. MSC will need library calls checked.
*
*
* dstamp@watserv1.uwaterloo.ca			17/10/91
***********************************************************************/
*
*
* 68HC11 version by Ron Menelli, 10/23/91
*
* A million thanks to the above people for taking this project as far
* as it has gone! This version runs on the MC68HC11 processor, specifically
* Motorola's MC68HC11EVB board. The assembler I used was Matt Dillon's
* DASM for the Amiga - this code will have to be converted a bit to be
* used on Motorola's freeware assembler.
*
* As it stands, this code is a direct port of Dave Stampe's code minus
* the IBM specific stuff (VGA, for example). The way this code works is
* by sending the data received from the Power Glove over the serial port
* at 9600 baud. By sending single character commands, the serial port
* action can be controlled as follows:
*
*       Send    Action
*       ====    =========
*        C      Start continuous mode - send every time the glove is read.
*               The data is sent with a certain byte preceding it as a
*               flag marking the beginning. The format I have used is:
*
*                   A0 X Y Z rot fingers keys
*
*                   ^
*                   +--- Flag character (A0 used for old time's sake!)
*
*        R      Start request mode - send the 6 byte data packet when
*               requested by user. Format is the same as above, minus
*               the flag character.
*
*        ?      In request mode, this causes the controller to report
*               the current glove data.
*
*        +      Turns on hysterisis deglitching mode (new for 1.1)
*
*        -      Turns off hysterisis deglitching mode (new for 1.1)
*
* Please send me any suggestions you have regarding improvements to this
* code!
*
* -Ron Menelli  menelli@tellabs.com
*

EVB     EQU     0               * *** Change to 1 for EVB version!!!


    ORG         $F800           * start of 68HC811E2 EEPROM space.

*
* Macro definitions
*

* Delay 3us (made a macro because a subroutine would be too slow)

*    MAC DELAY3US
*
*        NOP
*        NOP
*        NOP
*
*    ENDM

* Set Clock = 0, Latch = 0

*    MAC C0L0
*
*        LDAB    #0
*        STAB    PORTA
*
*    ENDM

* Set Clock = 0, Latch = 1

*    MAC C0L1
*
*        LDAB    #GLATCH
*        STAB    PORTA
*
*    ENDM

* Set Clock = 1, Latch = 0

*    MAC C1L0
*
*        LDAB    #GCLOCK
*        STAB    PORTA
*
*    ENDM

* Set Clock = 1, Latch = 1

*    MAC C1L1
*
*        LDAB    #GCLOLAT
*        STAB    PORTA
*
*    ENDM

*
* RAM allocation
*

BITCNT      EQU     $0000
BYTECNT     EQU     $0001
GLOVEFLAG   EQU     $0002       * Flag byte for continuous mode
GLOVEDATA   EQU     $0003       * 7 byte array
UNREADY     EQU     $0009
MODEFLAG    EQU     $000A       * Mode flag - continuous or request
OX          EQU     $000B       * The following are for hysterisis calculations
OY          EQU     $000D
TMP         EQU     $000F
DEGLFLAG    EQU     $0011       * Deglitching mode flag

*
* Port A definitions
*
* bit 0 - Data in
* bit 4 - Clock out
* bit 5 - Latch out
*

PORTA		EQU		$1000
PACTL		EQU		$1026
GDATA		EQU		$01
GCLOCK		EQU		$10
GLATCH		EQU		$20
GCLOLAT		EQU		$30

*
* Serial port definitions
*

BAUD        EQU     $102B
SCCR1       EQU     $102C
SCCR2       EQU     $102D
SCSR        EQU     $102E
SCDR        EQU     $102F

*
* Timing constants (for an 8Mhz crystal)
*

D2BYTES     EQU     30          * 96us
D2SLOW      EQU     700         * ~= 2100us

*
* Variables for hysterisis
*

XHYST       EQU     2
YHYST       EQU     2

*
*Variables for deglitching
*

XACC        EQU     8
YACC        EQU     8
XXTEND      EQU     2
YXTEND      EQU     1

* Other stuff

CONTMODE    EQU     0           * Continuous mode
REQMODE     EQU     1           * Request mode
CONTCHAR    EQU     'C          * Character to request cont. mode
REQCHAR     EQU     'R          * Character to request request mode
QUERYCHAR   EQU     '?          * Character to request a data packet
*                                 Only valid in request mode
DEGLCHAR    EQU     '+          * Character to request deglitching mode
NDGLCHAR    EQU     '-          * Character to turn off deglitching mode
FLAGCHAR    EQU     $A0         * Flag indicating beginning of packet in
*                                 continuous mode

*
* ***********************
* * Program begins here *
* ***********************
*

INIT:       LDS     #$00FF      * Initialize stack pointer

            LDAA    #0          * Disable pulse accumulator on port A
            STAA    PACTL

            LDAA    #$01        * Set EVB to serial receive normally
            STAA    $4000

            LDAA    #$30        * Set serial port for 9600 baud
*                                 (using 8 MHz XTAL)
            STAA    BAUD
            LDAA    #$0C        * Transmit & receive enable
            STAA    SCCR2

            LDAA    #FLAGCHAR   * Set up flag character in buffer
            STAA    GLOVEFLAG

            LDAA    #CONTMODE   * Start in continuous mode
            STAA    MODEFLAG

            LDAA    #$FF        * Start in deglitching mode
            STAA    DEGLFLAG

            JSR     INITVAR     * Initialize deglitching variables

INITGLOVE:  JSR     HIRES       * Set hi-res mode

*
* *********************
* * Main program loop *
* *********************
*

MAIN:       LDAA    #0          * Zero the retry counter
            STAA    UNREADY
            LDX     #D2SLOW     * Wait a while
            JSR     DELAY

CHECKRDY:   JSR     GETBYTE     * Check to see if glove is ready
            CMPA    #$A0        * Is it A0 (the start of the sequence?)
            BEQ     READDATA    * Yes, read the rest of the data sequence

            INC     UNREADY     * Increment retry counter
            BEQ     INITGLOVE   * If 256 tries, initialize the glove again

            LDX     #D2SLOW     * Wait and try again
            JSR     DELAY
            BRA     CHECKRDY

READDATA:   LDY     #GLOVEDATA
            JSR     GETGLOVE    * Read glove data into buffer

            LDAA    DEGLFLAG    * Check to see if we're supposed to deglitch
            BEQ     CHECKSER    * No - go on to keypresses

            LDY     #GLOVEDATA
            JSR     DOHYST      * *** Do hysterisis deglitch

CHECKSER:   LDAA    SCSR        * Check serial port receive status
            ANDA    #$20
            BEQ     CHECKMODE

            LDAA    SCDR        * Character received - check it

            CMPA    #QUERYCHAR  * Is it the query character?
            BNE     NOTQRYCH    * No - skip this
            LDAA    MODEFLAG    * Yes - check to see what mode we're in
            CMPA    #REQMODE    * If not in request mode, skip this
            BNE     CHECKMODE
            LDY     #GLOVEDATA  * Send 6 bytes over the serial port
            LDAB    #6
            JSR     SENDSER     * This does our pausing for us (6.25 ms)
            BRA     MAIN        * No need to continue checking
            
NOTQRYCH:   CMPA    #CONTCHAR   * Is it the cont. mode activator?
            BNE     NOTCONTCH   * No - skip this
            LDAA    #CONTMODE   * Yes - set continuous mode
            STAA    MODEFLAG
            BRA     CHECKMODE

NOTCONTCH:  CMPA    #REQCHAR    * Is it the request mode activator?
            BNE     NOTREQCH    * No - skip this
            LDAA    #REQMODE    * Yes - set request mode
            STAA    MODEFLAG
            BRA     WAIT        * No need to continue checking

NOTREQCH:   CMPA    #DEGLCHAR   * Is it the deglitching on character?
            BNE     NOTDEGCH    * No - skip this
            LDAA    #$FF        * Yes - set the deglitching flag
            STAA    DEGLFLAG
            BRA     WAIT

NOTDEGCH:   CMPA    #NDGLCHAR   * Is it the deglitching off character?
            BNE     CHECKMODE   * No - skip this
            LDAA    #0          * Yes - clear the deglitching flag
            STAA    DEGLFLAG
            BRA     WAIT

CHECKMODE:  LDAA    MODEFLAG    * Check the mode flag
            CMPA    #CONTMODE   * Is it continuous mode?
            BNE     WAIT        * No - wait and start the loop again
            LDY     #GLOVEFLAG  * Send data (6 + Flag) over serial port
            LDAB    #7
            JSR     SENDSER     * This provides approx. 7.29 ms of delay
*                               * at 9600 baud
            JMP     MAIN

WAIT:       LDX     #D2SLOW     * Wait a while before continuing
            JSR     DELAY
            JMP     MAIN

*
* **************************************
* *          Delay subroutine          *
* * (Delay proportional to value in X) *
* **************************************
*

DELAY:      DEX
            BNE     DELAY
            RTS

*
* *******************
* * Set hi-res mode *
* *******************
*

HIRES:      
* C1L0   Dummy read 4 dummy bits from glove
        LDAB    #GCLOCK
        STAB    PORTA

*            C1L1
        LDAB    #GCLOLAT
        STAB    PORTA

*            DELAY3US
	NOP
	NOP
	NOP
*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA


*            DELAY3US
	NOP
	NOP
	NOP
*            C0L0
        LDAB    #0
        STAB    PORTA

*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA

*            DELAY3US
	NOP
	NOP
	NOP

*            C0L0
        LDAB    #0
        STAB    PORTA

*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA

*            DELAY3US
	NOP
	NOP
	NOP

*            C0L0
        LDAB    #0
        STAB    PORTA

*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA

*            DELAY3US
	NOP
	NOP
	NOP

*            C0L0
        LDAB    #0
        STAB    PORTA

*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA


*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA

            LDX     #2402       * Delay 7212us
            JSR     DELAY

*            C1L1
        LDAB    #GCLOLAT
        STAB    PORTA

            LDX	    #752        * Delay 2260us
            JSR	    DELAY

            LDAA    #7
            STAA    BYTECNT
            LDY	    #HRCODE     * Send the 7 byte code
BYTELOOP:   LDAA    #8
            STAA    BITCNT
            LDAA    0,Y
BITLOOP:    LSLA
            BCC	    BITOFF
*            C1L1
        LDAB    #GCLOLAT
        STAB    PORTA

*            C0L1
        LDAB    #GLATCH
        STAB    PORTA

*            C1L1
        LDAB    #GCLOLAT
        STAB    PORTA

            BRA	    NEXTLOOP
BITOFF:	    
* C1L0
        LDAB    #GCLOCK
        STAB    PORTA

*            C0L0
        LDAB    #0
        STAB    PORTA

*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA

NEXTLOOP:   
* DELAY3US
	NOP
	NOP
	NOP

            DEC	    BITCNT
            BNE	    BITLOOP

            LDX	    #D2BYTES
            JSR	    DELAY
            INY
            DEC	    BYTECNT
            BNE	    BYTELOOP

            LDX	    #296        * Delay 892us
            JSR	    DELAY

*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA

            LDX	    #20000      * Delay a "long time"
            JSR	    DELAY
            RTS

*
* Glove initialization bytes
*

HRCODE:     FCB    $06,$C1,$08,$00,$02,$FF,$01

*
* *******************************************
* *        Get the 6 byte data packet       *
* * (Places data in buffer pointed to by Y) *
* *******************************************
*

GETGLOVE:   JSR     GETBYTE     * Get each byte consecutively
            STAA    0,Y         * and store in memory
            INY
            LDX     #D2BYTES
            JSR     DELAY

            JSR     GETBYTE
            STAA    0,Y
            INY
            LDX     #D2BYTES
            JSR     DELAY

            JSR     GETBYTE
            STAA    0,Y
            INY
            LDX     #D2BYTES
            JSR     DELAY

            JSR     GETBYTE
            STAA    0,Y
            INY
            LDX     #D2BYTES
            JSR     DELAY

            JSR     GETBYTE
            STAA    0,Y
            INY
            LDX     #D2BYTES
            JSR     DELAY

            JSR     GETBYTE
            STAA    0,Y
            LDX     #D2BYTES
            JSR     DELAY

            JSR     GETBYTE     * Throw away last two bytes
            LDX     #D2BYTES
            JSR     DELAY
            JSR     GETBYTE
            RTS

*
* ************************
* * Initialize variables *
* ************************
*
INITVAR:    LDD     #0          * Set all variables to 0
            STD     OX          * First hysterisis variables
            STD     OY
            RTS

*
* *****************************
* * Get a byte from the glove *
* *    (Returns byte in A)    *
* *****************************
*

GETBYTE:    
* C1L0                Pulse the latch line
        LDAB    #GCLOCK
        STAB    PORTA

*            C1L1
        LDAB    #GCLOLAT
        STAB    PORTA

*            DELAY3US
	NOP
	NOP
	NOP

*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA


            LDAA    #8
            STAA    BITCNT

GETLOOP:    LSLA                * Read 8 bits sequentially
            LDAB    PORTA
            ANDB    #GDATA      * Mask off other bits
            ABA                 * Assemble the data byte
*            C0L0
        LDAB    #0
        STAB    PORTA

*            C1L0
        LDAB    #GCLOCK
        STAB    PORTA

            DEC     BITCNT
            BNE     GETLOOP

            RTS

*
* *****************************
* *    Hysterisis deglitch    *
* * (Y points to data buffer) *
* *****************************
*
DOHYST:     LDAA    5,Y         * Check for center button
            BNE     NOCENTER
            JSR     INITVAR     * If so, clear variables

NOCENTER:   CLRA
            LDAB    0,Y         * Begin hysterisis for X
            BPL     NOXTNDHX    * Sign extend B reg. into D
            COMA
NOXTNDHX:   STD     TMP
            SUBD    OX
            CPD     #XHYST
            BLE     HYSTX1
            LDD     TMP
            SUBD    #XHYST
            STD     OX
HYSTX1:     LDD     OX
            SUBD    TMP
            CPD     #XHYST
            BLE     HYSTY1
            LDD     TMP
            ADDD    #XHYST
            STD     OX

HYSTY1:     CLRA
            LDAB    1,Y         * Begin hysterisis for Y
            BPL     NOXTNDHY    * Sign extend B reg. into D
            COMA
NOXTNDHY:   STD     TMP
            SUBD    OY
            CPD     #YHYST
            BLE     HYSTY2
            LDD     TMP
            SUBD    #YHYST
            STD     OY
HYSTY2:     LDD     OY
            SUBD    TMP
            CPD     #YHYST
            BLE     HYSTDONE
            LDD     TMP
            ADDD    #YHYST
            STD     OY

HYSTDONE:   LDAA    OX+1        * Put values back
            STAA    0,Y
            LDAA    OY+1
            STAA    1,Y
            RTS

*
* ***********************************************
* * Send an X byte packet over the serial port  *
* * (Y contains the address of the data buffer, *
* *  B contains the number of bytes to send)    *
* ***********************************************
*

SENDSER:    LDAA    SCSR        * Check status register for Tx ready
            ANDA    #$80
            BEQ     SENDSER     * Try again if not ready

            LDAA    0,Y         * Send byte to the serial port
            STAA    SCDR

            INY                 * Move to next data byte
            DECB
            BNE     SENDSER     * Send next byte if not done

            RTS


    ORG     $FFFA               * Reset vectors for standalone board

    	FDB    $F800
	FDB	$F800
	FDB	$F800



