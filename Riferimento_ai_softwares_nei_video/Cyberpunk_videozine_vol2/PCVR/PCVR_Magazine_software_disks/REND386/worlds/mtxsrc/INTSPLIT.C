/* Splitting-tree assembly routines (should be private to splits.c) */

/* Written by Bernie Roehl, June 1992 */
/* Substantially upgraded by Dave Stampe, August '92 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
	 May be freely used to write software for release into the public domain;
	 all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
	 for permission to incorporate any part of this software into their
	 products!

	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
 */

#pragma inline

#include <dos.h>

#include "3dstruct.h"
#include "splitdef.h"
#include "splits.h"

int _which_side(SPLIT *s, long tx,long ty,long tz)
{
	int sign = -1; /* dot product: > , < , = zero */

	asm{
		.386
		push cx
		push di
		les bx,DWORD PTR s

		mov eax,DWORD PTR es:[bx].(SPLIT)nx
		mov edx,DWORD PTR tx
		sub edx,DWORD PTR es:[bx].(SPLIT)x
		imul edx
		mov ecx,eax
		mov edi,edx
		mov eax,DWORD PTR es:[bx].(SPLIT)ny
		mov edx,DWORD PTR ty
		sub edx,DWORD PTR es:[bx].(SPLIT)y
		imul edx
		add ecx,eax
		adc edi,edx
		mov eax,DWORD PTR es:[bx].(SPLIT)nz
		mov edx,DWORD PTR tz
		sub edx,DWORD PTR es:[bx].(SPLIT)z
		imul edx
		add ecx,eax
		adc edi,edx
		jl alldone
		neg WORD PTR sign
		or edi,ecx
		jnz alldone
		mov WORD PTR sign, di
	}
alldone:
	asm {
		pop di
		pop cx
		}
	return sign;
}


void *_fast_split_descent(SPLIT *tree, long x, long y, long z, char *type)
{
	asm {
		push si
		push cx
		les bx,DWORD PTR tree
		}
next:
	asm {
		or bx,bx
		jz endtree
		mov eax,DWORD PTR es:[bx].(SPLIT)nx
		mov edx,DWORD PTR x
		sub edx,DWORD PTR es:[bx].(SPLIT)x
		imul edx
		mov esi,eax
		mov ecx,edx
		mov eax,DWORD PTR es:[bx].(SPLIT)ny
		mov edx,DWORD PTR y
		sub edx,DWORD PTR es:[bx].(SPLIT)y
		imul edx
		add esi,eax
		adc ecx,edx
		mov eax,DWORD PTR es:[bx].(SPLIT)nz
		mov edx,DWORD PTR z
		sub edx,DWORD PTR es:[bx].(SPLIT)z
		imul edx
		add esi,eax
		adc ecx,edx
		jge right
		mov al,BYTE PTR es:bx.(SPLIT)left_type
		les bx,DWORD PTR es:bx.(SPLIT)left
		cmp al,ISSPLIT
		je next
		jmp endtree
		}
right:
	asm {
		mov al,BYTE PTR es:bx.(SPLIT)right_type
		les bx,DWORD PTR es:bx.(SPLIT)right
		cmp al,ISSPLIT
		je next
		}
endtree:
	asm {
		mov cl,al
		mov ax,bx
		mov dx,es
		les bx,DWORD PTR type
		mov es:bx,cl
		pop cx
		pop si
		}
	return; /* the return value is in DX:AX */
}

