*
*
* HEXMON.ASM:  Monitor program for 6811 with Hexadecimal Protocol
*
*	       by Fred G. Martin (fredm@media.mit.edu)
*
*	       from a protocol "HEXLOBO" originally written by
*	       Randy Sargent and Fred Martin	
*
*
* VERSION HISTORY
*
* HEXLOBO.ASM
* V1.0	8/7/91   FGM, RS
* changed from old ASCII scheme to hex I/O
* NOTE:  high bit of incoming character is stripped!
*
* HEXLOBO2.ASM
* V2.0	10/8/91  FGM
* added 'q' command to read hex word
* added code to store min and max values with timestamps
*
* HEXMON21.ASM
* V2.1	10/22/91 FGM
* added zero page locations of raw analog vals;
* fixed min/max bug of previous version
* changed max/min timestamping to only occur when new value is greater
*   or less than previous
*
* HEXMON30.ASM
* V3.0	10/23/91	FGM
* changed min/max stuff to be thresholds rather than exact min or maxes;
* added bit mask to enable taking of threshold.
*
* HEXMON31.ASM
* V3.1 10/28/91		FGM
* changed minimum so that sensed value must be less than threshold,
* not less or equal to it.
*
* HEXMON40.ASM		FGM
* V4.0 3/23/92
* added 16-bit pulse width modulation motor control
* added 'z' write-word command

* 6811 equates
EEPROM	EQU	$F800		; start of eeprom

*********************************************************************
* Control Registers

BASE	EQU	$1000

PORTA	EQU	$1000	; Port A data register
RESV1	EQU	$1001	; Reserved
PIOC	EQU	$1002	; Parallel I/O Control register
PORTC	EQU	$1003	; Port C latched data register
PORTB	EQU	$1004	; Port B data register
PORTCL	EQU	$1005	;
DDRC	EQU	$1007	; Data Direction register for port C
PORTD   EQU     $1008	; Port D data register
DDRD    EQU     $1009	; Data Direction register for port D
PORTE	EQU	$100A	; Port E data register
CFORC	EQU	$100B	; Timer Compare Force Register
OC1M	EQU	$100C	; Output Compare 1 Mask register
OC1D	EQU	$100D	; Output Compare 1 Data register

* Two-Byte Registers (High,Low -- Use Load & Store Double to access)
TCNT	EQU	$100E	; Timer Count Register
TIC1	EQU	$1010	; Timer Input Capture register 1
TIC2	EQU	$1012	; Timer Input Capture register 2
TIC3	EQU	$1014	; Timer Input Capture register 3
TOC1	EQU	$1016	; Timer Output Compare register 1
TOC2	EQU	$1018	; Timer Output Compare register 2
TOC3	EQU	$101A	; Timer Output Compare register 3
TOC4	EQU	$101C	; Timer Output Compare register 4
TI4O5	EQU	$101E	; Timer Input compare 4 or Output compare 5 register

TCTL1	EQU	$1020	; Timer Control register 1
TCTL2	EQU	$1021	; Timer Control register 2
TMSK1	EQU	$1022	; main Timer interrupt Mask register 1
TFLG1	EQU	$1023	; main Timer interrupt Flag register 1
TMSK2	EQU	$1024	; misc Timer interrupt Mask register 2
TFLG2	EQU	$1025	; misc Timer interrupt Flag register 2
PACTL	EQU	$1026	; Pulse Accumulator Control register
PACNT	EQU	$1027	; Pulse Accumulator Count register
SPCR	EQU	$1028	; SPI Control Register
SPSR	EQU	$1029	; SPI Status Register
SPDR	EQU	$102A	; SPI Data Register
BAUD	EQU	$102B	; SCI Baud Rate Control Register
SCCR1	EQU	$102C	; SCI Control Register 1
SCCR2	EQU	$102D	; SCI Control Register 2
SCSR	EQU     $102E	; SCI Status Register
SCDR	EQU     $102F	; SCI Data Register
ADCTL	EQU	$1030	; A/D Control/status Register
ADR1	EQU	$1031	; A/D Result Register 1
ADR2	EQU	$1032	; A/D Result Register 2
ADR3	EQU	$1033	; A/D Result Register 3
ADR4	EQU	$1034	; A/D Result Register 4
BPROT	EQU	$1035	; Block Protect register
RESV2	EQU	$1036	; Reserved
RESV3	EQU	$1037	; Reserved
RESV4	EQU	$1038	; Reserved
OPTION	EQU	$1039	; system configuration Options
COPRST	EQU	$103A	; Arm/Reset COP timer circuitry
PPROG	EQU	$103B	; EEPROM Programming register
HPRIO	EQU	$103C	; Highest Priority Interrupt and misc.
INIT	EQU	$103D	; RAM and I/O Mapping Register
TEST1	EQU	$103E	; factory Test register
CONFIG	EQU	$103F	; Configuration Control Register


* Masks for serial port
PORTD_WOM	EQU	$20
BAUD1200	EQU	$B3
BAUD9600	EQU	$B0
TRENA		EQU	$0C	; Transmit, Receive ENAble
RDRF		EQU	$20	; Receive Data Register Full
TDRE		EQU	$80	; Transmit Data Register Empty

* ASCII definitions
CR		EQU	$0a

* motor control
MOTORS_OFF	EQU	$00	; rev 1 board

*****************************************************************
* zero page RAM definitions

	ORG	$00

st_hi	RMB	2
st_lo	RMB	2

a0n     RMB     1       ; analog 0 minimum threshold
a1n     RMB     1
a2n     RMB     1
a3n     RMB     1
a4n     RMB     1
a5n     RMB     1
a6n     RMB     1
a7n     RMB     1       ; analog 7 minimum threshold

a0x     RMB     1       ; analog 0 maximum threshold
a1x     RMB     1
a2x     RMB     1
a3x     RMB     1
a4x     RMB     1
a5x     RMB     1
a6x     RMB     1
a7x     RMB     1       ; analog 7 maximum threshold

a0ntime RMB     4       ; analog 0 minimum timestamp
a1ntime RMB     4
a2ntime RMB     4
a3ntime RMB     4
a4ntime RMB     4
a5ntime RMB     4
a6ntime RMB     4
a7ntime RMB     4

a0xtime RMB     4       ; analog 0 maximum timestamp
a1xtime RMB     4
a2xtime RMB     4
a3xtime RMB     4
a4xtime RMB     4
a5xtime RMB     4
a6xtime RMB     4
a7xtime RMB     4

* direct analog values (updated 1 kHz)
a0val	RMB	1
a1val	RMB	1
a2val	RMB	1
a3val	RMB	1
a4val	RMB	1
a5val	RMB	1
a6val	RMB	1
a7val	RMB	1

* bit mask to control taking of timestamps
* low bit is analog 0
* 1= take timestamp; 0= timestamp taken
tscontrol RMB	1

* motor control byte
* high bits control enable; low bits control direction
motctrl	RMB	1

* motor speeds: 16 bit values (modify with 'z' command)
speed1	RMB	2
speed2	RMB	2
speed3	RMB	2
speed4	RMB	2


**********************************************************************
*								     *
*			       MAIN CODE			     *
*								     *
**********************************************************************

	ORG	$F800

Start:
soft_reset:
	LDS	#$00ff

	LDX     #$1000

* it's a rev 1 board:  turn off the motors
	LDAA	#MOTORS_OFF
	STAA	PORTB,X

* initialize serial port
	BCLR	SPCR,X PORTD_WOM 	; turn off wired-or mode
	LDAA	#BAUD9600
	STAA	BAUD,X
	LDAA	#TRENA
	STAA	SCCR2,X

* turn on analog subsystem
	BSET    OPTION,X $80

* set up interrupts
* OC4:  1 kHz system interrupt
	BSET	TFLG1,X %00010000	; clear pending flag
	BSET	TMSK1,X %00010000	; enable interrupt (not IR)

* initialize system time
	CLRA
	CLRB
	STD	st_hi
	STD	st_lo

* set min and max values, motor defaults
	STD     a0n
	STD     a2n
	STD     a4n
	STD     a6n		; set past maximum to zero

	STAA	motctrl		; reset to off

* clear timestamp control byte
	STAA	tscontrol

	LDD     #$FFFF
        STD     a0x
        STD     a2x
        STD     a4x
        STD     a6x

	STD	speed1
	STD	speed2
	STD	speed3
	STD	speed4		; reset to full on

* turn on interrupts
	CLI

mainloop
        JSR     cmd_loop
        BRA     mainloop

*
*	COMMAND LOOP
*                    a digit is a hex char (upcase only)
*		     x means ignored but required
*               read byte
*                    r addr: x x x x add3 add2 add1 add0 -> r dig dig
*               write byte
*                    w addr: x x dat1 dat0 add3 add2 add1 add0 -> w
*               read word
*                    q addr: x x x x dig dig dig dig-> q dig dig dig dig
*		write word
*		     z addr: dat3 dat2 dat1 dat0 add3 add2 add1 add0 -> z
*		jump to 6811 subroutine
*		     j : pc pc b b xreg xreg xreg xreg -> j
*               reset
*                    s : x x x x x x x x -> s
*
*	if read get address: print @address: goto cmd_loop
*	if write get address,data: poke address,data: goto cmd_loop
*	if call get address: push 0 on pstack: pc=address: jsr execute:
*		print return value (srhi): goto cmd_loop
*	if continue then rts
*	if reset goto reset
*

cmd_loop:
	LDAA	#'>
	JSR	putchar
* get a cmd character
* a command is always 'a' or bigger
* and data is always smaller than 'a' (@-O)
cmd_get_type:
	JSR	getchar
	CMPA	#'a
	BLO	cmd_get_type
	PSHA	* save command type
* get 2 words of data
	JSR	getword		* data (lsb), new pc for call: y
	PSHX
	PULY
	JSR	getword		* address: x
* branch on cmd type
	PULA	* restore command type
	jsr	putchar		* echo back command type
  	CMPA	#'r
	BEQ	cmd_read_byte
	CMPA	#'w
	BEQ	cmd_write_byte
  	CMPA	#'q
	BEQ	cmd_read_word
	CMPA	#'z
	BEQ	cmd_write_word
	CMPA	#'s
	BEQ	soft_reset
	CMPA	#'j
	BEQ	cmd_jsr
	BRA	cmd_loop
cmd_jsr
* jsr to y:hi
* set x to x
* set b to y:lo
	XGDY	* b now has y:lo, a is y:hi
	LDY	#cmd_loop   * save return address
	PSHY
	PSHA	* push y:hi as low of jump address
	CLRA
	PSHA	* push 0 as hi of jump address
	RTS			* jump!

cmd_read_byte
	LDAA	0,X
	JSR	putbyte
	BRA	cmd_loop

cmd_read_word
	LDAA	0,X
	JSR	putbyte
	LDAA	1,X
	JSR	putbyte
	BRA	cmd_loop

cmd_write_byte
	XGDY	* move y to d.  low byte to poke is now in b
	STAB	0,X
	BRA	cmd_loop

cmd_write_word
	XGDY	* move y to d.
	STD	0,X
	BRA	cmd_loop


* get a byte into A.  munges B
getbyte
	JSR	getchar
        CMPA    #'A
        BLO     hibyteok
        SUBA    #'A-10
hibyteok
	ASLA
	ASLA
	ASLA
	ASLA
	TAB
	JSR	getchar
        CMPA    #'A
        BLO     lobyteok
        SUBA    #'A-10
lobyteok
	ANDA	#$0f
	ABA
	RTS

* get a word into X
getword
	JSR 	getbyte  * get hi byte first
	PSHA
	JSR	getbyte
	TAB
	PULA
	XGDX
	RTS

* get a character into A
getchar
	LDAA	SCSR
	ANDA	#RDRF
        BEQ	getchar
	LDAA	SCDR
        ANDA    #$7f
	RTS

* put a character from A.  munges B
putchar
	LDAB	SCSR
 	ANDB	#TDRE
	BEQ	putchar
	STAA	SCDR
	RTS

* Prints out byte in A in Hex
putbyte
	JSR	Hex2Ascii
        PSHB
	JSR	putchar
        PULB
	TBA
	JMP	putchar

******************************************************************************
*
*	Hex2Ascii:	converts byte to its 2-char ASCII hex equiv.
*
*			INPUT:  byte in A register
*			OUTPUT:	MSB is A, LSB is B
*
Hex2Ascii
	PSHA		* store it; work on B first
	ANDA	#$0F	* get LS nybble
	ADDA	#$30	* puts it in ASCII "0" to "?"
	CMPA	#$3A
	BMI	H2A1
	ADDA	#$07	* now it's "A" to "F"
H2A1	TAB		* done with LSB
	PULA
	LSRA		* shift that baby down
	LSRA
	LSRA
	LSRA		* into the lower nybble position
	ADDA	#$30	* puts it in ASCII "0" to "?"
	CMPA	#$3A
	BMI	H2A2
	ADDA	#$07	* now it's "A" to "F"
H2A2	RTS		* done

******************************************************************************
*
*	SystemInt	1 kHz system interrupt routine
*
*	    TIMER:	uses TOC4 for control
*
*
*	System interrupt performs the following tasks:
*
*	    0.  sets up for next interrupt
*	    1.  increment system time
*	    2.  decrement "process_ticks".  If zero, pokes
*		BRN (branch never) into pcode_run loop, so that
*		current process exits.
*	    3.  deals with LCD print.
*	    4.  does PWM stuff.
*	    5.  does shaft encoder stuff.
*
SystemInt:
* setup for next interrupt
	LDX	#$1000		* point to register base
	LDD	#2000		; 2000 cycles = 1 millisec.
	ADDD	TOC4,X		* add TOC5 to D
	STD	TOC4,X		* store back
	BCLR	TFLG1,X %11101111	* clear OC4 for next compare

* increment system time
	LDX	st_lo
	INX
	STX	st_lo
	BNE	si_noinc
	LDX	st_hi
	INX
	STX	st_hi
si_noinc:

* take analog conversions channels 0 to 3
        LDX     #$1000
        LDAA    #%00010000              ; 4 conversions only
        STAA    ADCTL,X

* wait till done
        BRCLR   ADCTL,X $80 *

        LDAA    ADR1,X                  ; analog 0
	STAA	a0val			; store in zero page
	BRCLR	tscontrol $01 a0xok	; if bit 0 clear, skip min/maxing

        CMPA    a0n                     ; past minimum
        BHS     a0nok
	BCLR	tscontrol $01
        LDD     st_hi
        STD     a0ntime
        LDD     st_lo
        STD     a0ntime+2
	BRA	a0xok
a0nok   LDAA    ADR1,X
        CMPA    a0x
        BLS     a0xok
	BCLR	tscontrol $01
        LDD     st_hi
        STD     a0xtime
        LDD     st_lo
        STD     a0xtime+2
a0xok

        LDAA    ADR2,X                  ; analog 1
	STAA	a1val			; store in zero page
	BRCLR	tscontrol $02 a1xok	; if bit 1 clear, skip min/maxing

        CMPA    a1n                     ; past minimum
        BHS     a1nok
	BCLR	tscontrol $02
        LDD     st_hi
        STD     a1ntime
        LDD     st_lo
        STD     a1ntime+2
	BRA	a1xok
a1nok   LDAA    ADR2,X
        CMPA    a1x
        BLS     a1xok
	BCLR	tscontrol $02
        LDD     st_hi
        STD     a1xtime
        LDD     st_lo
        STD     a1xtime+2
a1xok

        LDAA    ADR3,X                  ; analog 2
	STAA	a2val
	BRCLR	tscontrol $04 a2xok	; if bit 2 clear, skip min/maxing

        CMPA    a2n                     ; past minimum
        BHS     a2nok
	BCLR	tscontrol $04
        LDD     st_hi
        STD     a2ntime
        LDD     st_lo
        STD     a2ntime+2
	BRA	a2xok
a2nok   LDAA    ADR3,X
        CMPA    a2x
        BLS     a2xok
	BCLR	tscontrol $04
        LDD     st_hi
        STD     a2xtime
        LDD     st_lo
        STD     a2xtime+2
a2xok

        LDAA    ADR4,X                  ; analog 3
	STAA	a3val
	BRCLR	tscontrol $08 a3xok	; if bit 3 clear, skip min/maxing

        CMPA    a3n                     ; past minimum
        BHS     a3nok
	BCLR	tscontrol $08
        LDD     st_hi
        STD     a3ntime
        LDD     st_lo
        STD     a3ntime+2
	BRA	a3xok
a3nok   LDAA    ADR4,X
        CMPA    a3x
        BLS     a3xok
	BCLR	tscontrol $08
        LDD     st_hi
        STD     a3xtime
        LDD     st_lo
        STD     a3xtime+2
a3xok

* take analog conversions channels 4 to 7
        LDAA    #%00010100              ; 4 conversions only
        STAA    ADCTL,X

* wait till done
        BRCLR   ADCTL,X $80 *

        LDAA    ADR1,X                  ; analog 4
	STAA	a4val
	BRCLR	tscontrol $10 a4xok	; if bit 4 clear, skip min/maxing

        CMPA    a4n                     ; past minimum
        BHS     a4nok
	BCLR	tscontrol $10
        LDD     st_hi
        STD     a4ntime
        LDD     st_lo
        STD     a4ntime+2
	BRA	a4xok
a4nok   LDAA    ADR1,X
        CMPA    a4x
        BLS     a4xok
	BCLR	tscontrol $10
        LDD     st_hi
        STD     a4xtime
        LDD     st_lo
        STD     a4xtime+2
a4xok

        LDAA    ADR2,X                  ; analog 5
	STAA	a5val
	BRCLR	tscontrol $20 a5xok	; if bit 4 clear, skip min/maxing

        CMPA    a5n                     ; past minimum
        BHS     a5nok
	BCLR	tscontrol $20
        LDD     st_hi
        STD     a5ntime
        LDD     st_lo
        STD     a5ntime+2
	BRA	a5xok
a5nok   LDAA    ADR2,X
        CMPA    a5x
        BLS     a5xok
	BCLR	tscontrol $20
        LDD     st_hi
        STD     a5xtime
        LDD     st_lo
        STD     a5xtime+2
a5xok

        LDAA    ADR3,X                  ; analog 6
	STAA	a6val
	BRCLR	tscontrol $40 a6xok	; if bit 4 clear, skip min/maxing

        CMPA    a6n                     ; past minimum
        BHS     a6nok
	BCLR	tscontrol $40
        LDD     st_hi
        STD     a6ntime
        LDD     st_lo
        STD     a6ntime+2
	BRA	a6xok
a6nok   LDAA    ADR3,X
        CMPA    a6x
        BLS     a6xok
	BCLR	tscontrol $40
        LDD     st_hi
        STD     a6xtime
        LDD     st_lo
        STD     a6xtime+2
a6xok

        LDAA    ADR4,X                  ; analog 7
	STAA	a7val
	BRCLR	tscontrol $80 a7xok	; if bit 4 clear, skip min/maxing

        CMPA    a7n                     ; past minimum
        BHS     a7nok
	BCLR	tscontrol $80
        LDD     st_hi
        STD     a7ntime
        LDD     st_lo
        STD     a7ntime+2
	BRA	a7xok
a7nok   LDAA    ADR4,X
        CMPA    a7x
        BLS     a7xok
	BCLR	tscontrol $80
        LDD     st_hi
        STD     a7xtime
        LDD     st_lo
        STD     a7xtime+2
a7xok

* do pulse width modulation, 4 motors
* motor 1 (ls bit of low nybble is dir, ls bit of high nybble is on/off
pwm	LDX	motctrl		* upper nybble is on/off; lower is dir

	LDD	speed1
	LSLD
	BCC	pwmoff1
	ADDD	#1
	XGDX			* get output byte into D; save new speed in X
	EORA	#%00010000	* toggle motor 1 ctrl bit
	BRA	pwmset1
pwmoff1	XGDX
	ORAA	#%00010000	* set motor 1 ctrl bit
pwmset1	XGDX
	STD	speed1

	LDD	speed2
	LSLD
	BCC	pwmoff2
	ADDD	#1
	XGDX			* get output byte into D; save new speed in X
	EORA	#%00100000	* toggle motor 2 ctrl bit
	BRA	pwmset2
pwmoff2	XGDX
	ORAA	#%00100000	* set motor 2 ctrl bit
pwmset2	XGDX
	STD	speed2

	LDD	speed3
	LSLD
	BCC	pwmoff3
	ADDD	#1
	XGDX			* get output byte into D; save new speed in X
	EORA	#%01000000	* toggle motor 3 ctrl bit
	BRA	pwmset3
pwmoff3	XGDX
	ORAA	#%01000000	* set motor 3 ctrl bit
pwmset3	XGDX
	STD	speed3

	LDD	speed4
	LSLD
	BCC	pwmoff4
	ADDD	#1
	XGDX			* get output byte into D; save new speed in X
	EORA	#%10000000	* toggle motor 4 ctrl bit
	BRA	pwmset4
pwmoff4	XGDX
	ORAA	#%10000000	* set motor 4 ctrl bit
pwmset4	XGDX
	STD	speed4

	XGDX			* get control bits into A
	EORA	#$F0		* toggle speed bits
	STAA	PORTB		* do it

* fall through to BadInt

* bad interrupt?  return!
BadInt	RTI

	Org	$FFC0

	FDB	BadInt	* $FFC0: Reserved
	FDB	BadInt	* $FFC2: Reserved
	FDB	BadInt	* $FFC4: Reserved
	FDB	BadInt	* $FFC6: Reserved

	FDB	BadInt	* $FFC8: Reserved
	FDB	BadInt	* $FFCA: Reserved
	FDB	BadInt	* $FFCC: Reserved
	FDB	BadInt	* $FFCE: Reserved

	FDB	BadInt	* $FFD0: Reserved
	FDB	BadInt	* $FFD2: Reserved
	FDB	BadInt	* $FFD4: Reserved

	FDB	BadInt	* $FFD6: SCI Serial System

	FDB	BadInt	* $FFD8: SPI Serial Transfer Complete
	FDB	BadInt	* $FFDA: Pulse Accumulator Input Edge
	FDB	BadInt	* $FFDC: Pulse Accumulator Overflow
	FDB	BadInt	* $FFDE: Timer Overflow

	FDB	BadInt	* $FFE0: Timer Input Capture 4/Output Compare 5 (TI4O5)
	FDB	SystemInt * $FFE2: Timer Output Compare 4 (TOC4)
	FDB	BadInt	* $FFE4: Timer Output Compare 3 (TOC3) *BEEP*
	FDB	BadInt	* $FFE6: Timer Output Compare 2 (TOC2)

	FDB	BadInt	* $FFE8: Timer Output Compare 1 (TOC1)
	FDB	BadInt	* $FFEA: Timer Input Capture 3 (TIC3)
	FDB	BadInt	* $FFEC: Timer Input Capture 2 (TIC2)
	FDB	BadInt	* $FFEE: Timer Input Capture 1 (TIC1)

	FDB	BadInt	* $FFF0: Real Time Interrupt (RTI)
	FDB	BadInt	* $FFF2: /IRQ (External Pin or Parallel I/O) (IRQ)
	FDB	BadInt	* $FFF4: /XIRQ (Pseudo Non-Maskable Interrupt) (XIRQ)
	FDB	BadInt	* $FFF6: Software Interrupt (SWI)

	FDB	BadInt	* $FFF8: Illegal Opcode Trap ()
	FDB	BadInt	* $FFFA: COP Failure (Reset) ()
	FDB 	BadInt	* $FFFC: COP Clock Monitor Fail (Reset) ()
	FDB	Start	* $FFFE: /RESET
	END
*******************************************************************************
*******************************************************************************
