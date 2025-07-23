/* Load a PCX file in mode Y */

/* THIS CODE IS CURRENTLY MODE Y DEPENDENT!
   IT WILL NOT WORK IN OTHER MODES */

/* Written by Bernie Roehl, April 1992 based on code by Dave Stampe */

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

#include <stdio.h>
#include <dos.h>
#include <alloc.h>

#include "f3dkitd.h"  /* reset_hdwe() */

static int getbyte(int *c, int *count, FILE *in)
{
	if (feof(in)) return EOF;
	*c = getc(in) & 0xFF;
	if ((*c & 0xC0) == 0xC0) {
		*count = *c & 0x3F;
		if (feof(in)) return EOF;
		*c = getc(in) & 0xFF;
	}
	else
		*count = 1;
	return NULL;
}

static void putbyte(int c, int count, FILE *out)
{
	if (count == 0)
		return;
	if (count > 1 || (c & 0xC0) == 0xC0)
		putc(count | 0xC0, out);
	putc(c, out);
}

static unsigned char far *screen = MK_FP(0xA000, 0);

static void write_line(char far *buffer, char far *scr)
{
	int i, plane;
	char *add, *buff;

	for (plane = 0; plane < 4; ++plane)
	{
		outport(0x3C4, (1<<(plane+8))+2);
		add = scr;
		buff = &buffer[plane];
		for (i = 0; i < 80; ++i)
		{
			*add++ = *buff;
			buff += 4;
		}
	}
}

load_pcx(FILE *in, int page)
{
	int c, count;
	char buff[330];
	char *buffer = &buff[0];
	char *scr = &screen[16000*page];
	unsigned nread = 0;

	reset_hdwe();
	fseek(in, 128L, SEEK_SET); /* skip PCX header */
	while (getbyte(&c, &count, in) != EOF)
		while (count--)
		{
			*buffer++ = c;
			if (++nread == 320)
			{
				write_line(&buff[0],scr);
				buffer = &buff[0];
				nread = 0;
				scr += 80;
			}
		}
	return 0;
}

struct {
	unsigned char manu, hard, encod, bitpx;
	unsigned int x1, y1, x2, y2;
	unsigned int hres, vres;
	unsigned char palette[48];
	unsigned char vmode, nplanes;
	unsigned int bytesPerLine;
	char unused[128-68];
}
pccHeader =
{ 
	10, 5, 1, 8, 0, 0, 319, 199, 75, 75, { 
		0 	}
	, 0x13, 1, 320, 0 };

struct { 
	unsigned char r, g, b; 
}
palbuff[256];


/* NEED A FUNCTION FOR THIS IN VIDEO DRIVER */


static char get_pixel(unsigned int adr, int page)
{
	outport(0x3CE, ((adr&3)<<8)+4); /* select plane to read */
	return *(char *)(MK_FP((0xA000+(1008*page)),adr>>2));
}


save_pcx(FILE *out, int page)
{
	unsigned c, oldc, count;
	unsigned nput = 1;
	union REGS r;

	reset_hdwe();
	fwrite(&pccHeader, 128, 1, out);
	count = 1;
	oldc = get_pixel(0,page);
	while ((nput>>2) < 16000)
	{
		c = get_pixel(nput++, page);
		if (c != oldc)
		{
			putbyte(oldc, count, out);
			oldc = c;
			count = 1;
		}
		else if (++count >= 63)
		{
			putbyte(oldc, count, out);
			count = 0;
		}
	}
	putbyte(oldc, count, out);

	putc(0x0C, out);
	for (count = 0; count < 256; ++count)
	{
		r.x.ax = 0x1015;
		r.x.bx = count; /* write pallete */
		int86(0x10, &r, &r);
		putc(r.h.dh<<2, out);
		putc(r.h.ch<<2, out);
		putc(r.h.cl<<2, out);
	}
	return 0;
}

