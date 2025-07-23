	TITLE	GSPPT - 320x200x16 mode support
	NAME	GSPPT


	COMMENT	$

	Name:		GSPPT

		Written and (c) by Dave Stampe 9/11/91
		Not for commercial use, so get permission
		before marketing code using this stuff!
		For private PD use only.

		$

		.MODEL large
		.CODE

 ;
 ; void vsync();		/* waits for vert. sync pulse */
 ;
		PUBLIC	_vsync

_vsync	proc	far

	push	bp
	mov	bp,sp
	mov		dx,03DAh
	in		al,dx		; test if 0
	test		al,8
	je	short @11@218
@11@122:
	in		al,dx
	nop
	test		al,8            ; wait for 0
	jne	short @11@122
@11@218:
	in		al,dx
	nop
	test		al,8            ; wait for 1
	je	short @11@218
	pop	bp
	ret

_vsync	endp

 ;
 ; void setup_hdwe(int mode);	/* sets up VGA for line, poly draw */
 ;                              /* modes are: 0=PUT, 1=OR,         */
 ;				/*	      2=AND, 3=XOR         */

		PUBLIC	_setup_hdwe

_setup_hdwe	proc	far

	push	bp
	mov	bp,sp
	mov	dx,03CEH
	mov	ah,BYTE PTR [bp+6]      ; set write logic mode
	sal	ah,1
	sal	ah,1
	sal	ah,1
	mov	al,03h
	out	dx,ax
	mov	ax,0B05h                ; write mode = 3 (CPU byte is mask)
	out	dx,ax
	mov	ax,0007h                ; setup for FFh returned by read
	out	dx,ax
	mov	ax,0FF08h               ; all bits enabled
	out	dx,ax
	mov	ax,0FF01h
	out	dx,ax
	pop	bp
	ret

_setup_hdwe	endp

 ;
 ; void reset_hdwe()
 ;

		PUBLIC	_reset_hdwe

_reset_hdwe	proc	far

	push	bp
	mov	bp,sp
	mov	dx,03CEH
	mov	ax,0000         ; reset VGA to mode BIOS expects
	out	dx,ax
	mov	ax,0001
	out	dx,ax
	mov	ax,0003
	out	dx,ax
	mov	ax,0005
	out	dx,ax
	pop	bp
	ret

_reset_hdwe	endp

 ;
 ; int clr_page(int page, int color);	/* clear page to color */
 ;
 ;  /* returns 0 if OK, 1 if bad page */

		PUBLIC	_clr_page

_clr_page	proc	far

	push	bp
	mov	bp,sp
	dec	sp
	dec	sp
	push	di
	mov	ax,word ptr [bp+6]      ; compute page addr
	mov	cl,13
	shl	ax,cl
	mov	word ptr [bp-2],ax
	cmp	word ptr [bp+6],7       ; check for valid page
	jle	short @14@74
	mov	ax,65535
	jmp	short @14@482
@14@74:
	call	far ptr _reset_hdwe     ; reset to default VGA mode
	cld
	mov	dx,03CEh
	mov	al,0              	; set write color
	mov	ah,BYTE PTR [bp+8]
	out	dx,ax
	mov	ax,0F01h
	out	dx,ax
	mov	ax,0A000h
	mov	es,ax
	mov	cx,4000
	mov	al,[bp+8]               ; write pageful of color (8K)
	mov	di,[bp-2]
	rep	stosw
	mov	ax,0001h                ; reset VGA mode
	out	dx,ax
	xor	ax,ax
@14@482:
	pop	di
	mov	sp,bp
	pop	bp
	ret

_clr_page	endp

   ;
   ;	int copy_page(int source, int dest)
   ;
   ;	/* returns 0 if OK, 1 if bad page */

		PUBLIC	_copy_page

_copy_page	proc	far

	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
	push	di
	mov	ax,word ptr [bp+6]    	; compute source address
	mov	cl,13
	shl	ax,cl
	mov	word ptr [bp-2],ax
	mov	ax,word ptr [bp+8]	; compute dest. address
	shl	ax,cl
	mov	word ptr [bp-4],ax
	cmp	word ptr [bp+6],7
	jg	short @15@74            ; check for valid page #'s
	cmp	word ptr [bp+8],7
	jle	short @15@98
@15@74:
	mov	ax,65535
	jmp	short @15@506
@15@98:
	call	far ptr _reset_hdwe     ; default VGA state
	push	ds
	cld
	mov	dx,03CEh              	; read mode 0, write mode 1 (copy)
	mov	ax,0105h
	out	dx,ax
	mov	ax,0A000h
	mov	es,ax
	mov	ds,ax
	mov	cx,8000
	mov	si,[bp-2]
	mov	di,[bp-4]
	rep	movsb                   ; copy whole page (8K)
	mov	ax,0005h
	out	dx,ax
	pop	ds
	xor	ax,ax
@15@506:
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret

_copy_page	endp


 ;
 ; void vga_reg(int reg) 	/* integer: lsby=reg(0=color), msby=value */
 ;

		PUBLIC	_vga_reg

_vga_reg	proc	far

	push	bp
	mov	bp,sp
	mov	dx,03CEH
	mov	ax,WORD PTR [bp+6]
	out	dx,ax
	pop	bp
	ret

_vga_reg	endp



 ;
 ; void load_color(int color)    /* integer: color reg. load */
 ;

		PUBLIC	_load_color

_load_color	proc	far

	push	bp
	mov	bp,sp
	mov	dx,03CEH
	xor	al,al
	mov	ah,BYTE PTR [bp+6]
	out	dx,ax
	pop	bp
	ret

_load_color	endp


 ;
 ; void _set_vmode(int mode)    /* enters video mode thru BIOS */
 ;

		PUBLIC	_set_vmode

_set_vmode	proc	far

	push	bp
	mov	bp,sp
	mov	ah,0
	mov	al,BYTE PTR [bp+6]
	int	10h
	pop	bp
	ret

_set_vmode	endp


 ;
 ; void _set_vpage(int page)    /* sets video page thru BIOS */
 ;

		PUBLIC	_set_vpage

_set_vpage	proc	far

	push	bp
	mov	bp,sp
	mov	ah,5
	mov	al,BYTE PTR [bp+6]
	int	10h
	pop	bp
	ret

_set_vpage	endp


		end

