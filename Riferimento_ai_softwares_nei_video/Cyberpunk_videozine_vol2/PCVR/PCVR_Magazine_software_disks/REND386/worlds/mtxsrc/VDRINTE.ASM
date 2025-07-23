
	TITLE	DRIVER - Interface to BIN loadable drivers.
	NAME	VGALINE

	COMMENT	$

		Written and (c) by Dave Stampe 20/8/92
		Not for commercial use, so get permission
		before marketing code using this stuff!
		For private PD use only.


	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!

		This code supports both non-reentrant and
		reentrant functions.  Only vsync(), set_vpage(),
		and VGA_select() are reentrant (may be called from
		an interrupt routine) and must be written in assembler
		with .MODEL TINY FARSTACK or in C (tiny model, DS != SS) with
		NO C LIBRARY CALLS.

		All other routines may be written in tiny C and use library calls.

		$



		.MODEL large
		.CODE

		.386

public	_screen_data     ; the C callable stubs
public	_vsync
public	_setup_hdwe
public	_reset_hdwe
public	_clr_page
public	_copy_page
public	_copy_block
public	_clr_block
public	_fastpoly
public	_m_fastpoly
public	_set_gmode
public	_set_drawpage
public	_exit_gmode
public	_set_vpage
public	_clipline
public	_set_clip_rect
public	_printxyr
public	_erase_cursor
public	_draw_cursor
public	_vgaline
public	_vgapoint
public	_load_DAC_colors
public	_read_DAC_colors
public	_VGA_select
public	_vd_spare_1
public	_vd_spare_2
public	_vd_spare_3
public	_vd_spare_4
public	_vd_spare_5
public	_vd_spare_6
public	_vd_spare_7
public	_vd_spare_8

_screen_data:
	mov	ax,18
	jmp	nonreentrant
_vsync:
	mov	ax,20
	jmp	reentrant
_setup_hdwe:
	mov	ax,22
	jmp	nonreentrant
_reset_hdwe:
	mov	ax,24
	jmp	nonreentrant
_clr_page:
	mov	ax,26
	jmp	nonreentrant
_copy_page:
	mov	ax,28
	jmp	nonreentrant
_clr_block:
	mov	ax,30
	jmp	nonreentrant
_copy_block:
	mov	ax,32
	jmp	nonreentrant
_fastpoly:
	mov	ax,34
	jmp	nonreentrant
_m_fastpoly:
	mov	ax,36
	jmp	nonreentrant
_set_gmode:
	mov	ax,38
	jmp	nonreentrant
_exit_gmode:
	mov	ax,40
	jmp	nonreentrant
_set_drawpage:
	mov	ax,42
	jmp	nonreentrant
_set_vpage:
	mov	ax,44
	jmp	reentrant
_vgaline:
	mov	ax,46
	jmp	nonreentrant
_vgapoint:
	mov	ax,48
	jmp	nonreentrant
_set_clip_rect:
	mov	ax,50
	jmp	nonreentrant
_clipline:
	mov	ax,52
	jmp	nonreentrant
_printxyr:
	mov	ax,54
	jmp	nonreentrant
_draw_cursor:
	mov	ax,56
	jmp	nonreentrant
_erase_cursor:
	mov	ax,58
	jmp	nonreentrant
_load_DAC_colors:
	mov	ax,60
	jmp	nonreentrant
_read_DAC_colors:
	mov	ax,62
	jmp	nonreentrant
_VGA_select:
	mov	ax,64
	jmp	reentrant
_vd_spare_1:
	mov	ax,66
	jmp	nonreentrant
_vd_spare_2:
	mov	ax,68
	jmp	nonreentrant
_vd_spare_3:
	mov	ax,70
	jmp	nonreentrant
_vd_spare_4:
	mov	ax,72
	jmp	nonreentrant
_vd_spare_5:
	mov	ax,74
	jmp	nonreentrant
_vd_spare_6:
	mov	ax,76
	jmp	nonreentrant
_vd_spare_7:
	mov	ax,78
	jmp	nonreentrant
_vd_spare_8:
	mov	ax,80
	jmp	nonreentrant

extrn _v_driver_pointer

nonreentrant:
	push	bp
	push	ds
	mov	  bp,sp
	mov	  dx,ss                  ; save stack seg
	mov	  es,dx
	lds   bx,DWORD PTR _v_driver_pointer  ; get routine address
	push	ds                     ; new stack seg
	pop	  ss                     ; all int's disabled till next instr..
	mov	  sp,2000                ; stack internal to driver
	push	dx                     ; push old stack seg (bp=old stack ptr)
	push	DWORD PTR es:[bp+24]   ; up to 20 bytes of arguments
	push	DWORD PTR es:[bp+20]   ; copy adds 1 uS, but needed
	push	DWORD PTR es:[bp+16]   ; to keep ints from crashing
	push	DWORD PTR es:[bp+12]
	push	DWORD PTR es:[bp+8]
	push	cs                            ; push default return
	push	offset nrtnh
	push	ds
	add   bx,ax                           ; push as call address
	push	ds:[bx]
	retf                                ; "call"

nrtnh:
	add	sp,20
	pop	ss                              ; restore stack
	mov	sp,bp
	pop	ds
	pop	bp
	retf                                ; exit

reentrant:
	push	bp
	push	ds
	mov	bp,sp
	push	DWORD PTR ss:[bp+24]   ; up to 20 bytes of arguments
	push	DWORD PTR ss:[bp+20]   ; copy adds 1 uS, but needed
	push	DWORD PTR ss:[bp+16]   ; to keep ints from crashing
	push	DWORD PTR ss:[bp+12]
	push	DWORD PTR ss:[bp+8]
	push	cs                              ; push default return
	push	offset rtnh
	lds	bx,DWORD PTR _v_driver_pointer  ; get routine address
	push	ds
	add	bx,ax                           ; push as call address
	push	ds:[bx]
	retf                                    ; "call"

rtnh:	mov	sp,bp
	pop	ds
	pop	bp
	retf                                    ; exit


	end
