	TITLE	FPBLIT - Fast poly filling blitter
	NAME	FPBLIT


	COMMENT	$

	Name:		FPBLIT

		Written and (c) by Dave Stampe 9/11/91
		Not for commercial use, so get permission
		before marketing code using this stuff!
		For private PD use only.

		$

	COMMENT	$

	Name:		tpoly

	Caller:		C:

			int tpoly(int x1, int x2, long l_incr, long r_incr,
				  int y1, int y3);

			x1 = left side start, x2 = right side start
			 if 0x8000, uses end of last poly's side for cont.
			y1 = top, y2 = 1+bottom of poly slice
			l_incr, r_incr = 2^16 times slope (add to x each line)

		$


		.MODEL large

		.CODE
				; big table more eff. than masking
				; start byte lookup table
stmask:		REPT	40
		db	0ffh,07fh,03fh,01fh,00fh,007h,003h,001h
		ENDM
				; end byte lookup table
fnmask:         REPT	40
		db      080h,0c0h,0e0h,0f0h,0f8h,0fch,0feh,0ffh
		ENDM


x1	equ	[bp+6]          ; arguments to _tpoly
x2	equ	[bp+8]
l_incr	equ	[bp+10]
r_incr	equ	[bp+14]
y1	equ	[bp+18]
y3	equ	[bp+20]

vline   equ	[bp-2]   	; video base addr. of line
lines	equ	[bp-4]		; number of lines to fill

	extrn	_l_hold         ; holds full res. L, R. point
	extrn	_r_hold

	extrn	_dpaddr		; page base address

   ;
   ;	tpoly(int x1,int x2, long l_incr, long r_incr, int y1, int y3)
   ;

		PUBLIC	_tpoly

_tpoly	proc	far

	.386
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
	push	di

	mov	ax,word ptr y3	       ; if(y3-y1<1)return(-1);
	sub	ax,word ptr y1
	cmp	ax,1
	jge	short continue
clipall:
	mov	ax,65535               ; return -1 on bad args
	jmp	exit

continue:
	cld
	mov	ax,0a000h              ; set video segment
	mov	es,ax

	mov	edx,DWORD PTR ds:_l_hold
	mov	ax,x1
	cmp	ax,8000h               ; old or new left side
	je	short nlload
	mov	dx,ax
	shl	edx,16
	add	edx,08000h             ; force left side to round up
nlload:
	mov	esi,DWORD PTR ds:_r_hold
	mov	ax,x2
	cmp	ax,8000h               ; old or new right
	je	short nrload
	mov	si,ax
	shl	esi,16
nrload:
	mov	ax,y3                   ; compute # lines
	sub	ax,y1
	mov	lines,ax
	mov	al,y1
	mov	bl,40                   ; compute starting line adr
	mul	bl
	add	ax,WORD PTR ds:_dpaddr
	mov	vline,ax

	mov	ebx,edx                 ; convert fixed-pt to integer
	sar	ebx,16
	mov	ecx,esi
	sar	ecx,16
	jl	short doneline          ; preclip left trap

	cmp	bx,0
	jl	short clipall
	cmp	cx,640
	ja	short clipall


nextline:
		; start of fast h line blitter:
		;  bx=left side, cx=right side, vline=line start

	mov	al,BYTE PTR cs:[bx+stmask]  ; left mask
	shr	bx,3                        ; left address

	mov	di,cx
	mov	ah,BYTE PTR cs:[di+fnmask]  ; right mask
	shr	cx,3                        ; right address

	mov	di,vline		    ; start address
	add	di,bx
	sub	cx,bx                       ; number of bytes-1
	je	short onebyte
	jc	short doneline              ; clip trap

	and	es:[di],al                  ; mask first byte
	inc	di
	dec	cx                          ; mask rest
	mov	al,0ffh                     ; rep faster than test and jmp
	rep	stosb                       ; for zero byte case
	and	es:[di],ah                  ; mask last byte
	jmp	short doneline

onebyte:
	and	al,ah
	and	es:[di],al		; single byte mask

doneline:
	mov	ax,40                   ; next line address
	add	vline,ax

	add	edx,DWORD PTR l_incr    ; step left, right edges
	add	esi,DWORD PTR r_incr
	mov	ebx,edx			; convert fixed pt to integer
	sar	ebx,16
	mov	ecx,esi
	sar	ecx,16

	dec	WORD PTR lines          ; done lines?
	jg	short nextline

   ;	sub	edx,DWORD PTR l_incr    ; DON'T unstep left, right edges
   ;	sub	esi,DWORD PTR r_incr    ; as this helps fill in gaps

donetri:                                   ; finished all drawing
	mov	DWORD PTR ds:_l_hold,edx   ; store edge points in case
	mov	DWORD PTR ds:_r_hold,esi   ; needed for next poly slice
exit:
	pop	di                         ; exit code
	pop	si
	mov	sp,bp
	pop	bp
	ret

_tpoly	endp


   ;
   ;	long compute_slope(int x1, int y1, int x2, int y2)
   ;

y1	equ	[bp+8]
y2	equ	[bp+12]
x1	equ	[bp+6]
x2	equ	[bp+10]

	PUBLIC	_compute_slope

_compute_slope	proc	far

	push	bp		; computes slope (dy incrementor)
	mov	bp,sp           ; with 16-bit underflow
	sub	sp,4
	.386
	xor	ecx,ecx
	mov	cx,y2
	sub	cx,y1
	je	short @5@386	; skip if zero divide (special case)
	mov	ax,x2           ; detected later by y1==y2 test
	sub	ax,x1
	cwd
	movsx	eax,ax  	; (x2-x1)/(y2-y1)
	movsx	edx,dx
	shl	eax,16
	idiv	ecx
	cmp    	eax,0   	; round up if pos (neg already rounded up)
	jle	short @5@386
	inc	eax
@5@386:                         ; return long value (286 style)
	mov	[bp-4],eax
	mov	dx,word ptr [bp-2]
	mov	ax,word ptr [bp-4]
	mov	sp,bp
	pop	bp
	ret

_compute_slope	endp


	end


