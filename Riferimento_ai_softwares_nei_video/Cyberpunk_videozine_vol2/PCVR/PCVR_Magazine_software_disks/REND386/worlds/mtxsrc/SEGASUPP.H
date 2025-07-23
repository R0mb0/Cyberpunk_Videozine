/* Prototypes for Sega and Powerglove (and timer) support */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

extern void init_SG_interrupt(void (*sega_switcher)(), /* NULL if no sega/video   */
			void (*glove_handler)(), /* NULL if no glove driver */
			int glove_tc);           /* 1.19*uS (test interval) */

/*
 sega_switcher is called just before the vertical retrace
 use NULL if no video synchronization desired

 glove_handler is called once or more per screen time
 use NULL if not required

 glove_tc is period in timer clocks (1.19 * microseconds) desired between
 glove_handler calls.  If sega_switcher is also used, this will be an
 integer number per screen time.  Use 6500 for best results, as this
 gives the least glitches (2xscreen for 72 Hz, 3xscreen for 60 Hz VGA cards
*/

/***** GLOVE DATA SPECIFICATIONS **************

x =   X position, 3mm per number
y =   Y position, 3mm per number
z =   distance,  14mm per number
rot = wrist twist. 0 is up 1 is slightly CW, 5 is down,
      11 is slightly CCW.
      About 30 to 40 degrees per count.

 Note: exact scaling of all above change with distance! Closer is higher res.

 fingers = packed 2-bit values, 0 is open, 3 is (tight) fist:
    Bit format: TtIiMmRr  for Thumb, Index, Middle, and Ring fingers.

 keys: $FF or $80 is no key. Responds with 0 to 9 for keys "0" thru "9"
      $82 = START, $83 = SEL, $0A = "A", $0B = "B", 0 is "Center"
			Up,down,left,right are $0D,$0E,$0C,$0F respectively.

 gstat1, gstat2 are dummies
 rxflags is valid ONLY after glove_ready returns 2.

 nmissed is number of reads since last glove_read call

 **********************************************/

#define G_NOKEY 0xFF
#define G_START 0x82
#define G_SEL   0x83
#define G_AKEY  0x0A
#define G_BKEY  0x0B
#define G_UP    0x0D
#define G_DOWN  0x0E
#define G_LEFT  0x0C
#define G_RIGHT 0x0F

#define G_RECENTER 0

typedef struct glove_data {
	signed char x,y,z,rot,fingers,keys,gstat1,gstat2,rxflags;
	unsigned int nmissed;  /* number of samples missed */
	} glove_data;

/* prototypes */

extern void getglove(glove_data *);	/* get data packet from glove */
extern int  glove_ready(void);		/* returns 0 if not ready     */
									/*         1 if data ready    */
									/*         2 if rxflags also valid */
#define DEGLITCH   1
#define NODEGLITCH 0

extern void glove_init(int gdeg);   /* sets up glove, enters hires mode    */
                                    /* gdeg switches deglitching on or off */

extern int glove_read(glove_data *g);  /* reads glove data, with de-glitching */

extern void glove_int_handler();       /* int handler: pass as argument to SGinit */

/* gesture recognition */

#define G_FLAT      0       	/* std. gesture classification */
#define G_THUMB_IN  1
#define G_INDEX_IN  2
#define G_MIDDLE_IN 3
#define G_RING_IN   4
#define G_PINCH     5
#define G_FIST      6
#define G_THUMB_OUT 7
#define G_POINT     8
#define G_BADFINGER 9
#define G_RING_OUT  10
#define G_UNKNOWN   11

extern long gesture_time;              /* # of glove-reads (1/20 sec) gesture seen */
extern unsigned char gesture_type;     /* mapped gesture type */
extern unsigned char gesture_map[];    /* use to map std. gestures to subset */
															/* so gesture_time is valid */

/**************** SEGA SUPPORT ****************/

extern int left_page;     /* video page with current left image */
extern int right_page;    /* video page with current right image */
extern int has_switched;  /* = 3 once both switched in */

extern void init_switch_driver(char *sdname);

extern void switch_sega(int to_go);     /* video, glasses switcher: pass to SGinit */

extern void sega_off(void);        /* turn off glasses at exit (longer life) */

extern void select_sega_port(int port);

/************** SEGA/GLOVE PARAMETERS *************/

extern int glove_in_port;
extern int glove_out_port;
extern int port_image;

extern int glove_data_mask;
extern int glove_write_mask;

extern int glove_none_mask;
extern int glove_latch_mask;
extern int glove_clock_mask;
extern int glove_clock_latch;

extern int glove_bit_delay;
extern int glove_byte_delay;

extern int sega_address;
extern int sega_port_image;
extern int sega_mask;

extern int sega_left;
extern int sega_right;
extern int sega_doff;

/* End of segasupp.h */
