	TITLE	GLOVEDEL - Powerglove timing and i/o support
	NAME	GLOVEDEL

	; SPECIAL VERSION FOR COMBO HMD/GLOVE/SEGA UNIT

	COMMENT	$

	Name:		GLOVEDEL

		Written and (c) by Dave Stampe 24/4/92
		Not for commercial use, so get permission
		before marketing code using this stuff!
		For private PD use only.


	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
		$

		.MODEL large

EXTRN	_glove_in_port		; GLOVE INTERFACE SPECS
EXTRN	_glove_out_port         ; SET UP IN C CODE

EXTRN	_glove_none_mask
EXTRN	_glove_data_mask
EXTRN	_glove_latch_mask
EXTRN	_glove_clock_mask
EXTRN	_glove_clock_latch

EXTRN	_glove_bit_delay

EXTRN	_port_image
EXTRN _glove_write_mask

		.CODE

; bit delay macro for byte read, line toggle

bitdelay macro
	local _localloop
	mov	cx,_glove_bit_delay
_localloop:
	in	al,41h
	loop	_localloop
endm



 ;
 ; int timed_glove_delay(int count);  /* returns time in 1.1925 MHZ ticks */
 ;                                    /* to perform <count> delay steps   */
 ;				      /* call with timer at 18.2 Hz rate  */

		PUBLIC	_timed_glove_delay

count equ [bp+6]

_timed_glove_delay	proc	far

	push	bp
	mov	bp,sp
	push	cx
	push	dx
	mov	cx,count
	pushf
	cli

	mov	al,00
	out	43h,al		; latch counter
	nop
	nop
	in	al,40h          ; read count
	mov	ah,al
	in	al,40h
	xchg	al,ah
	mov	bx,ax

caloop: in      al,41h          ; do delay
	loop	caloop

	mov	al,00
	out	43h,al          ; read new count
	nop
	nop
	in	al,40h
	mov	ah,al
	in	al,40h
	xchg	al,ah
	sub	ax,bx           ; assumes default, count rollover at 65536
	neg	ax

	popf
	pop	dx
	pop	cx
	mov	sp,bp
	pop	bp
	ret

_timed_glove_delay	endp


 ;
 ; int glove_delay(int count);	/* performs <count> delay steps   */
 ;

		PUBLIC	_glove_delay

count equ [bp+6]

_glove_delay	proc	far

	push	bp
	mov	bp,sp
	push	cx
	push	dx
	mov	cx,count

gdel:	in	al,41h
	loop	gdel

	pop	dx
	pop	cx
	mov	sp,bp
	pop	bp
	ret

_glove_delay	endp



 ;
 ; int get_glove_byte();	/* reads a byte from glove */
 ;

		PUBLIC	_get_glove_byte

_get_glove_byte	proc	far

	push	bp
	mov	bp,sp
	push	si
	push	cx
	push	dx

	mov	dx,_glove_out_port
	mov	si,_glove_in_port

	mov	ax,_glove_clock_mask	; preset lines
	pushf
	cli
	mov	ah,BYTE PTR _glove_write_mask
	not	ah
	and	ah,BYTE PTR _port_image
	or	al,ah
	mov	BYTE PTR _port_image,al
	out	dx,al                   ; output data
	popf
	bitdelay

	mov	ax,_glove_clock_latch
	pushf
	cli
	mov	ah,BYTE PTR _glove_write_mask
	not	ah
	and	ah,BYTE PTR _port_image
	or	al,ah
	mov	BYTE PTR _port_image,al
	out	dx,al                   ; output data
	popf
	bitdelay

	mov	ax,_glove_clock_mask
	pushf
	cli
	mov	ah,BYTE PTR _glove_write_mask
	not	ah
	and	ah,BYTE PTR _port_image
	or	al,ah
	mov	BYTE PTR _port_image,al
	out	dx,al                   ; output data
	popf
	bitdelay

	mov	bx,8000h                ; clear accumulator

bitloop:
	xchg	si,dx                   ; add bit to accumulator
	in	al,dx
	xchg	si,dx
	test	al,BYTE PTR _glove_data_mask
	jz	z0
	or	bl,bh
z0:                                     ; next bit
	shr	bh,1
	jz	endbyte

	mov	ax,_glove_none_mask     ; pulse clock line
	pushf
	cli
	mov	ah,BYTE PTR _glove_write_mask
	not	ah
	and	ah,BYTE PTR _port_image
	or	al,ah
	mov	BYTE PTR _port_image,al
	out	dx,al                   ; output data
	popf
	bitdelay

	mov	ax,_glove_clock_mask
	pushf
	cli
	mov	ah,BYTE PTR _glove_write_mask
	not	ah
	and	ah,BYTE PTR _port_image
	or	al,ah
	mov	BYTE PTR _port_image,al
	out	dx,al                   ; output data
	popf
	bitdelay
	jmp	bitloop

endbyte:
	mov	ax,bx
	xor	ah,ah
	pop	dx
	pop	cx
	pop	si
	mov	sp,bp
	pop	bp
	ret

_get_glove_byte	endp


 ;
 ; void set_glove_bits(int data);   /* sets glove clock, data lines */
 ;                                  /* and does a bit delay         */

		PUBLIC	_set_glove_bits

bits equ [bp+6]

_set_glove_bits	proc	far

	push	bp
	mov	bp,sp
	push	dx
	mov	dx,_glove_out_port
	mov	ax,bits

	pushf
	cli
	and	al,BYTE PTR _glove_write_mask
	mov	ah,BYTE PTR _glove_write_mask
	not	ah
	and	ah,BYTE PTR _port_image
	or	al,ah
	mov	BYTE PTR _port_image,al
	out	dx,al                   ; output data
	popf

	push	cx
	bitdelay
	pop	cx

	pop	dx
	mov	sp,bp
	pop	bp
	ret

_set_glove_bits	endp

		end

