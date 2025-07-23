/* Prototypes for low-level graphics routines */

/* Written by Dave Stampe, Summer 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

#define MAIN_VGA  1  /* for multi-VGA only */
#define LEFT_VGA  2
#define RIGHT_VGA 4
#define ALL_VGA   7

extern void far VGA_select(int card);

extern void *far screen_data(void);

extern void far set_clip_rect(int l, int t, int r, int b);

extern void far vsync(void);                /* pause till vert. retrace */

extern void far set_vpage(int page);    /* set video page thru BIOS */


#define PUT 0		/* defines of VGA write modes */
#define AND 1           /* for use with setup_hdwe()  */
#define OR  2
#define XOR 3

extern void far setup_hdwe(int mode);  /* setup VGA for bunch of line */
				       /* or poly draws: once per set */

extern void far reset_hdwe(void);  /* reset VGA to BIOS state after drawing */

			 /* clear video page to solid color: 10 mS */
			 /* returns -1 if bad page #		 */
extern int far clr_page(int page, int color);

			/* copy one page to another for use as */
			/* background: 21 mS per call          */
			/* returns -1 if bad page #            */
extern int far copy_page(int source, int dest);

			/* fast VGA line draw: about 15600 24-pixel */
			/* vectors/sec (horizontal much faster)     */
extern void far vgaline(int x1, int y1, int x2, int y2, int color);

			/* VGA point set; no clipping */
extern void far vgapoint(int x, int y, int color);

			/* does C-S clipping and draws line   */
extern void far clipline(int x1, int y1, int x2, int y2, int color);

extern void far set_gmode(int mode);  /* enters graphics mode (some drivers accept argument), clears screen */
extern void far exit_gmode(void);     /* exits to text mode */

extern int far set_drawpage(int page);	/* set page for drawing on (0-7)   */

			/* N_SIDED POLY DRAW for up to 20-sided  */
			/* convex polygons.  Pass pointer to int */
			/* array with X, Y coords in that order  */
			/* and count.  No clipping, CCW order    */

extern void far fastpoly(int count, int far *pcoords, int color);

			/* same as fastpoly() but with color cycling */
			/* and masking (halftone).  Color cycles in  */
			/* its lowest 4 bits, up then down.  Bit 8   */
			/* has been added as a "sign" bit for the    */
			/* initial cycle direction. 0000000SHHHHCCC  */
			/* the mask is XOR'ed with the toggle every  */
			/* line for 2x8 halftone patterns            */
extern void far m_fastpoly(int count, int far *pcoords, int color, int gmask, int toggle);

			/* print text in foreground only-- */
			/* reversed = 1 for right-to-left  */
			/* with x now right side of text   */
extern void far printxyr(int x, int y, int color, char far *pstring, int reversed);

			/* draw "+" cursor on screen      */
			/* save s screen under cursor 	  */
extern void far draw_cursor(int x, int y, int color, int savebuff);

				 /* restores 8x8 area saved when   */
extern void far erase_cursor(int savebuff); /* cursor was drawn               */

			/* copy any byte-aligned rectangle  */
			/* this is evey 4 pixels for Y mode */
			/* but every 8 for 16-color mode    */
			/* x coords (left) are truncated to */
			/* left byte boundary: x size is    */
			/* bumped up to next full byte count */
extern int far copy_block(int spage, int sx, int sy,  /* source */
		      int dpage, int dx, int dy,  /* dest   */
		      int xs, int ys);            /* # lines, pixels */

			/* clear any byte-aligned block       */
			/* 15-30% slower than full page clear */
			/* left edge rounded down, right edge */
			/* rounded up to nearest byte boundary */
extern int far clr_block(int left, int top, int right, int bottom,
		       int page, int color);

			/* 3 entries each for n colors: RGB, 0->63 */
			/* load always starts with slot 0          */
			/* set pal=NULL for default (still give n) */
			/* bw=1 will transform palette into B&W    */
extern void far load_DAC_colors(char far *pal, int n, int bw);

extern void far read_DAC_colors(char far *pal, int n);

/* End of f3dkitd.h */
