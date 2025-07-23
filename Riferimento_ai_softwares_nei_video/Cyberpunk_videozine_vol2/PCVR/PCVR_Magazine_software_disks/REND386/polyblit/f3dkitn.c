#include <bios.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int dpaddr = 0;        /* video write base */

unsigned long l_hold, r_hold;	      /* used to hold old x data for edge */

int l_clip = 0;     	/* clipping rectangle for polys and lines */
int r_clip = 319;       /* max. 0,319,0,199			  */
int t_clip = 0;
int b_clip = 199;

typedef struct lp {           /* set of points for clipping or line dwg */
		    int x1, y1, x2, y2;
		  } lpoints;




extern void far vsync();                /* pause till vert. retrace */
extern void far vga_reg(int reg); 	/* load VGA register:  */
					/* reg = reg# + 256*value */

extern void far load_color(int color);  /* load VGA color register */
extern void far set_vmode(int mode);    /* set video mode thru BIOS */
extern void far set_vpage(int page);    /* set video page thru BIOS */


#define PUT 0		/* defines of VGA write modes */
#define AND 1           /* for use with setup_hdwe()  */
#define OR  2
#define XOR 3

extern void far setup_hdwe(int mode);  /* setup VGA for bunch of line */
				       /* or poly draws: once per set */

extern void far reset_hdwe();  /* reset VGA to BIOS state after drawing */

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

			/* line draw using lpoint structure   */
void vgalines(lpoints *points, int color);

			/* Fast Cohen-Sutherland line clipper */
			/* modifies data in points, returns   */
			/* 0 if not clipped, 1 if clipped,    */
			/* -1 if undrawable                   */
			/* 2 - 10 uS per call                 */
int clipper (lpoints far *points);

			/* does C-S clipping and draws line   */
			/* returns same codes as C-S clipper  */
int clipline (lpoints *points, int color);

#define NO_HOLD  0      /* values for hold in tpoly() */
#define L_HOLD   1
#define R_HOLD   2
#define HOLD_ALL 3
#define HOLD 0x8000     /* use in x1 or x2 to continue poly side */

			/* draws trapeziodal poly slice FAST   */
			/* x1 is top left, x2 is top right,    */
			/* y1 is top, y3 is bottom.  Clipping  */
			/* is performed.  l_incr and r_incr    */
			/* set slope of sides.		       */
			/* if x1 or x2 = HOLD, continues that  */
			/* side from last tpoly call.  Use     */
			/* bits in hold to ensure that needed  */
			/* side data is good in previous tpoly */
extern int far tpoly(int x1,int x2, long l_incr, long r_incr,
							 int y1, int y3);

			       /* compute (x1-x2)/(y1-y2) << 16 */
			       /* used for tpoly...             */
			       /* returns x1-x2 if y1==y2       */
extern long far compute_slope(int x1, int x2, int y1, int y2);

void set_gmode();              /* enters 320x200x16 mode, clears screen */
void restore_gmode();          /* enters 320x200x16 mode w/o  clearing screen */
void exit_gmode();             /* exits to text mode */

int set_drawpage(int page);		/* set page for drawing on (0-7)   */

			 /* set displayed page: uses BIOS   */
			 /* call, so DON'T use in interrupt */
			 /* routines! If WAIT is 1, will    */
			 /* sync with vert. retrace (pause) */
int set_vidpage(int page, int wait);


			       /* draw and fill 3-sided polygon    */
			       /* 5800 polys/sec for 24x24         */
poly3(int x1, int y1, int x2, int y2, int x3, int y3, int color);

				/* N-sided poly fill (unclipped)    */
				/* 3800 30x30 polys/sec             */
				/* args: ptr to x and y arrays      */
polyn(int *xp, int *yp, int count, int color);



/************* GRAPHICS MODE CONTROL SUPPORT **************/

void set_gmode()		/* enters 320x200x16 mode, clears screen */
{
 set_vmode(0x0D);
}


void restore_gmode()		/* enters 320x200x16 mode w/o  clearing screen */
{
 set_vmode(0x8D);
}


void exit_gmode()		/* exits to text mode */
{
 set_vmode(0x02);
}


int set_drawpage(int page)      /* set page for drawing */
{
 if(page>7) return(-1);
 dpaddr = 8192*page;
 return(0);
}


int set_vidpage(int page, int wait)  /* set visible page, wait for vsync */
{
 if(page>7) return(-1);
 set_vpage(page);
 if(wait) vsync();
}


/******************* LINE DRAWING SUPPORT ***************/

void vgalines(lpoints *l, int color)
{
 vgaline(l->x1, l->y1, l->x2, l->y2, color);
}


int clipline(lpoints *l, int color)
{
 register int i;

 if ((i=clipper(l))==-1) return(i);
 vgaline(l->x1, l->y1, l->x2, l->y2, color);
 return(i);
}



/*************** 3-SIDED POLYGON DRAW AND FILL ***************/

poly3(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
 register int i;
 long s12, s23, s13;

 if(y2<y1)   	/* sort by vert pos'n */
  {
   i = y1;
   y1 = y2;
   y2 = i;
   i = x1;
   x1 = x2;
   x2 = i;
  }

 if(y3<y1)
  {
   i = y1;
   y1 = y3;
   y3 = i;
   i = x1;
   x1 = x3;
   x3 = i;
  }

 if(y3<y2)
  {
   i = y2;
   y2 = y3;
   y3 = i;
   i = x2;
   x2 = x3;
   x3 = i;
  }

 if(y1==y2&&y2==y3) return;

 load_color(color);

 if(y1==y2)		/* case = 2 (flat top) */
  {
   if(x2<x1)
    {
     i = x1;
     x1 = x2;
     x2 = i;
    }
   s23 = compute_slope(x2,y2,x3,y3);
   s13 = compute_slope(x1,y1,x3,y3);
   tpoly(x1,x2,s13,s23,y1,y3);
  }
 else if(y2==y3) 	/* case = 1 (flat bottom)*/
  {
   if(x3<x2)
    {
     i = x2;            /* sort bottom sides */
     x2 = x3;
     x3 = i;
    }
   s12 = compute_slope(x1,y1,x2,y2);
   s13 = compute_slope(x1,y1,x3,y3);
   tpoly(x1,x1,s12,s13,y1,y3);
  }
 else
  {
   s12 = compute_slope(x1,y1,x2,y2);
   s23 = compute_slope(x2,y2,x3,y3);
   s13 = compute_slope(x1,y1,x3,y3);

   if(s12>s13) 	/* case = 4 (3rd point on right) */
    {
     tpoly(x1,x1,s13,s12,y1,y2);
     tpoly(0x8000,x2,s13,s23,y2,y3);
    }
   else         /* case = 3 (3rd point on left)  */
    {
     tpoly(x1,x1,s12,s13,y1,y2);
     tpoly(x2,0x8000,s23,s13,y2,y3);
    }
  }
}



/******************* N-SIDED CONVEX POLY DRAW AND FILL **************/

/* draw n sided poly-- MUST BE CONVEX   */
/* max. 20 vertices: must be preclipped */
/* ABSOLUTELY NO CLIPPING ! */



#define WSIZE 60  		/* number of entries in array */
#define YTOX WSIZE              /* offset from Y to X data    */
int work[WSIZE+WSIZE];		/* left, right point lists */
				/* y first, then x */

polyn(int*xp, int *yp, int count, int color)
				/* does multisided convex polys      */
{                               /* by "walking" left and right edges */
 register int i;
 int j,y;

 int top,bot;
 int tlx,tly,trx,try;
 int blx,bly,brx,bry;

 long sl,sr;

 int *ls;
 int *rs;
 int *w;

 if(count<2) return;
 if(count==3)                 /* do 3-sided poly if possible */
  {
   poly3(*xp,*yp,*(xp+1),*(yp+1),*(xp+2),*(yp+2),color);
   return;
  }

 if(count > WSIZE/3)return;            /* 3 copies of data needed */

 memcpy(&work[0],yp,sizeof(int)*count);
 memcpy(&work[YTOX],xp,sizeof(int)*count);
 memcpy(&work[count],yp,sizeof(int)*count);
 memcpy(&work[YTOX+count],xp,sizeof(int)*count);
 memcpy(&work[count+count],yp,sizeof(int)*count);
 memcpy(&work[YTOX+count+count],xp,sizeof(int)*count);

 y = 1000;
 w = &work[0];
 for(i=0;i<count;i++)         /* find topmost, leftmost point */
  {
   if(*w <= y)
    {
     ls = w;
     y = *w;
     j = i;
    }
   w++;
  }
 if(j==count-1 && work[0] == y)    /* need to continue search for left? */
  {
   w = ls+1;
   for(i=0;;i++)
    {
     if(i==count)return;
     if(*w == y) ls = w++;
     else break;
    }
   ls -= count;     /* put back in buffer start */
  }

 w = ls+1;
 while(1)           /* find topmost, rightmost point */
  {
   if(*w == y)
    {
     rs = w;
     break;
    }
   w++;
  }
 rs += count;

 y = *ls;               /* find end of left points */
 w = ls+1;
 while(1)
  {
   if(*w < y)
    {
     *w = -1;
     break;
    }
   y = *w++;
  }

 y = *rs;               /* find end of right points */
 w = rs-1;
 while(1)
  {
   if(*w < y)
    {
     *w = -1;
     break;
    }
   y = *w--;
  }

 load_color(color);

bothnew: 		          /* top set of points */
 tly = *ls;
 tlx = *(ls+YTOX);
 trx = *(rs+YTOX);
 try = *rs;

 bly = *(ls+1);                     /* bottom set of points */
 blx = *(ls+YTOX+1);
 brx = *(rs+YTOX-1);
 bry = *(rs-1);

 if(bly==-1 || bry == -1)return;

 top = tly;
 bot = (bry<bly) ? bry : bly ;

 sl = compute_slope(tlx,tly,blx,bly);   /* draw first trapezoid */
 sr = compute_slope(trx,try,brx,bry);
 tpoly(tlx,trx,sl,sr,top,bot);

next_slice:
 if(bly==bry)		/* both edges ended */
  {
   ls++;                                /* next left */
   if(*ls==-1) return;
   while(*ls==*(ls+1)) ls++;   /* skip duplicates */
   if(*ls==-1) return;

   rs--;                                /* next left */
   if(*rs==-1) return;
   while(*rs==*(rs-1)) rs--;   /* skip duplicates */
   if(*rs==-1) return;

   goto bothnew;
  }

 if(bot==bry)           /* right edge ended */
  {
   rs--;                     /* next right */
   if(*rs==-1) return;
   while(*rs==*(rs-1)) rs--;   /* skip duplicates */
   if(*rs==-1) return;

   trx = *(rs+YTOX);
   try = *rs;

   brx = *(rs+YTOX-1);
   bry = *(rs-1);

   if(bry == -1)return;

   top = try;
   bot = (bry<bly) ? bry : bly ;

   sr = compute_slope(trx,try,brx,bry);
   tpoly(0x8000,trx,sl,sr,top,bot);
   goto next_slice;
  }

 else			/* left edge ended  */
  {
   ls++;                     /* next left */
   if(*ls==-1) return;
   while(*ls==*(ls+1)) ls++;   /* skip duplicates */
   if(*ls==-1) return;

   tly = *ls;
   tlx = *(ls+YTOX);

   bly = *(ls+1);                     /* bottom set of points */
   blx = *(ls+YTOX+1);
   if(bly == -1)return;

   top = tly;
   bot = (bry<bly) ? bry : bly ;

   sl = compute_slope(tlx,tly,blx,bly);
   tpoly(tlx,0x8000,sl,sr,top,bot);
   goto next_slice;
  }
}



