/* Definition for a generic 3-D pointing device interface */

/* Written by Dave Stampe Aug. 92 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

/* configuration structure: part of driver */
/* MUST corresp. to lefthand coord sys or negate scale! */
/* for non- ht devices, the scaling may be adjusted as desired */

 typedef struct _pconfig {
	long xres, yres, zres;     /* position res: mm/tick in <16.16>  */
	long maxx, maxy, maxz;     /* numeric range             */
	long minx, miny, minz;

	long xrres, yrres, zrres;  /* rotation res: deg/tick in <16.16  */
	long maxxr, maxyr, maxzr;  /* numeric range                */
	long minxr, minyr, minzr;  /* min, max: left-hand dir.     */

	int maxsx, maxsy;    /* limits on mouse-mode motion (writable) */

	int databits;     /* what data is available from device */
	int commands;     /* what sort of control is available  */
	int nullkey;			 /* button code for null keypress      */
	int flexnum;      /* number of flex parameters          */
	int delay;        /* millisec. read delay               */
	int idelay;       /* internal delay in ms               */
	int rrate;        /* max. reads per second possible     */
	int type;         /* suggested useage                   */
	char id[80];      /* id or more data                    */
	} pconfig;

/* databits: */

#define P_HASB1    0x0001   /* what buttons we can have  */
#define P_HASB2    0x0002   /* also mask for button bits */
#define P_HASB3    0x0004
#define P_HASX     0x0008   /* which axes we can read */
#define P_HASY     0x0010
#define P_HASZ     0x0020
#define P_HASRX    0x0040   /* what rotations are available */
#define P_HASRY    0x0080
#define P_HASRZ    0x0100
#define P_HASGEST  0x0200   /* gestural interface   */
#define P_HASFLEX  0x0400   /* fingers?             */
#define P_HASKEYS  0x0800   /* do we have a keypad? */
#define P_HASSCR   0x1000   /* capable of emulating XY mouse */


/* commands to driver (modes): */

#define P_CENTER    1   /* recenter without reinitializing */
#define P_SCREEN    2   /* screen mouse mode read     */
#define P_POINTER   4   /* any extended pointing mode */

/* type: bits specifying suggested uses */

#define P_NOPOS 0   /* just a keypad or something */
#define P_IS2D  1   /* 2D mouse, for example      */
#define P_IS2DP 2   /* 2D, but Z mapped by button */
#define P_IS3D  4   /* 3D mouse, for example      */
#define P_IS6D  8   /* 6D mouse, for example      */
#define P_IS3DG 16  /* 3D glove-- don't use rot   */
#define P_IS6DG 32  /* 6D glove-- use rotation    */
#define P_IS3RH 64  /* 3D (rotation) head tracker */
#define P_IS3TH 128 /* 3D (position) head tracker */
#define P_IS6H  256 /* full 6D head tracker       */

/* driver interface packet */

typedef struct _pt{
	long x, y, z;          /* location in scaled coordinates     */
	long dx, dy, dz;       /* position change from last read     */
	long rx, ry, rz;       /* scaled orientation around x, y, z  */
	long drx, dry, drz;    /* orientation change from last read  */
	unsigned buttons;      /* 16 bits: raw mouse buttons         */
	unsigned gesture;      /* glove gesture ID, or a mapping     */
	unsigned keys;         /* keypad return value                */
	int flex[16];          /* 16 words of flexion (i.e. fingers) */
	int changed;
	int wpos_valid;        /* set if world pos'n is valid        */
	MATRIX wpos;           /* world position/rotation            */
	} POINTER;

typedef struct _pb {
	 int   driver_type;            /* 0 = driver, 1 = internal */
	 pconfig *(*driver_pointer)(); /* address of driver entry  */
	 pconfig *pdata;
	 long xmult, ymult, zmult;    /* used to process reads    */
	 long xadd, yadd, zadd;
	 long xrmult, yrmult, zrmult;
	 long xradd, yradd, zradd;
	 int oldsx, oldsy;             /* mouse emulation */
	 POINTER oldp;
	 } pdrblock;


typedef pdrblock PDRIVER ; /* points to driver data block */

				/* loads driver, initializes   */
				/* return NULL if failure      */
				/* drfile is NULL for internal */
				/* type gives preferred mode   */
extern PDRIVER *pointer_init(int type, char *drfile);

				/* makes sure device is available, OK */
				/* returns *pconfig or NULL           */
extern pconfig *pointer_check(PDRIVER *p);

				/* reads pointer, scales data and        */
				/* returns bitwise OR of the following:  */
extern int pointer_read(PDRIVER *p, POINTER *pointer);

#define PNEW_POS  1   /* raw xyz change           */
#define PNEW_ROT  2   /* raw rot. change          */
#define PNEW_BUT  4   /* button pressed/released  */
#define PNEW_GEST 8   /* gesture change           */
#define PNEW_KEY  16  /* new key pressed/released */
#define PNEW_FLEX 32  /* new flexion              */

			/* recenters, recalibrates, etc */
extern void pointer_reset(PDRIVER *p);

			/* disconnects driver */
extern void pointer_quit(PDRIVER *p);

			/* changes device mode */
extern pconfig *device_command(PDRIVER *p, int command);

			/* sets scaling (+/- given value) */

extern void pointer_tscale(PDRIVER *p, long x, long y, long z);
extern void pointer_rscale(PDRIVER *p, long rx, long ry, long rz);


extern void pointer_abscale(PDRIVER *p, long xs, long ys, long zs,
	long rxs, long rys, long rzs);

			/* uses internal tick-resolution scaling for abs. devices */
extern void init_pointer(POINTER *p); /* presets pointer structure */

extern int last_pointer(PDRIVER *d,POINTER *p); /* copy of last read value */

			 /* mouse-emulation read: return change flags for button, pos'n */
extern int mouse_read(PDRIVER *p, int *x, int *y, unsigned *b);

			 /* mouse-emulation get last data: return change flags for button, pos'n */
extern int mouse_last(PDRIVER *p, int *x, int *y, int *b);

extern void set_mouse_limits(PDRIVER *p, int maxx, int maxy);

/* driver call equates: call *driver_pointer with this code */
/* all return *pconfig or integer */

#define DRIVER_INIT  0   /* rtns *pconfig, args = type    */
#define DRIVER_RESET 1   /* no rtn, no args               */
#define DRIVER_READ  2   /* rtns NULL if no data ready, else *pconfig */
						/* args = *pointer, mode */
#define DRIVER_CMD   3   /* args = mode, rtns *pconfig    */
#define DRIVER_CHECK 4   /* no args, rtns *pconfig        */
#define DRIVER_QUIT  5   /* no args, no rtn               */

extern PDRIVER *mouseptr_init();
 
/* End of pointer.h */

