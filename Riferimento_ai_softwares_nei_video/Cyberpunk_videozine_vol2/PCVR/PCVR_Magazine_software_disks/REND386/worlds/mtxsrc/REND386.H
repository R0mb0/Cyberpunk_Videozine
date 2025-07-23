/* Application header file for user with 3D renderer */

/* Part of the REND386 package by Dave Stampe and Bernie Roehl */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */


#ifndef SCRIDEF
#define SCRIDEF 1
struct Screeninfo {
	int xmin, ymin, xmax, ymax, xcent, ycent, colors, pages, bw;
	long aspect;
	char id[80];
	};
#endif

extern struct Screeninfo *screeninfo;

#ifndef MATRIXDEF
typedef long MATRIX[4][3];        /* 3x3 rotate plus 3 translate para's */
			/* rotate matrix is <3.29>, translate is <32.0> */
#define MATRIXDEF 1
#endif

/* renderer viewpoint/screen control structure */
/* viewoint in X, Y, Z coords */
/* pan, tilt, roll in (float*65536) formats */
/* zoom is equiv. to magnification from 90 deg. FOV (also float*65536) */
/* aspect sets how much to magnify Y more than X to fix up displays */
/* light source point in world coordinates */
/* left, right, top, bottom set edges of screen */
/* hither sets closest point: keep >16 for best range of world coords */
/* yon sets max. distance: keep it 1<<26 if not used */
/* rest is renderer workspace */


#ifndef VIEWDEF
#define VIEWDEF 1
typedef struct {
	/* VIEWPOINT */
	long ex, ey, ez;        /* <25.0>  location of eyepoint         */
	long pan, tilt, roll;   /* <16.16> viewing angles (deg) +/- 128 */
	long zoom;              /* <16.16> 1/tan(H FOV/2) 0.5 to 16     */
	long lx,ly,lz;          /* <25.0>  location of light source     */
	int  directional;       /* 0 for point, 1 for normal (not unit) */
	int  ambient;           /* ambient light: 0-256 (72 recc.)      */

	/* SCREEN DATA */
	long left,right;        /* <25.0> clipping planes */
	long top, bottom;
	long hither, yon;       /* <25.0> near and far clipping planes   */
	long aspect;            /* <16.16> x:y fixup factor (magnify Y by...) */

	/* RENDERING CONTROL */
	unsigned flags;         /* 16 bits of flags */

	/* ADVANCED SCREEN DATA */
	long x_offset, y_offset;   /* amount to move screen center in pixels */
	unsigned orientation;      /* used to mirror screen image */
#define NOFLIP 0x0000      /* bits used in orientation field */
#define XFLIP  0x0001
#define YFLIP  0x0002

	MATRIX eye_xform;

	char spare[200];        /* 100 bytes needed, plus 100 bytes spare */
	} VIEW;
#endif


/* View flags: */

#define WIREFRAME           0x0001
#define HIDE_HIGHLIGHTED    0x0002
#define HIDE_UNHIGHLIGHTED  0x0004
#define OBJ_COLLIDE         0x0008

#ifndef POLYDEF
#define POLYDEF 1
typedef void POLY;
#endif

#ifndef REPDEF
#define REPDEF 1
typedef void REP;
#endif


#ifndef OBJDEF
#define OBJDEF 1
typedef void *OBJECT;
#endif

#ifndef OBJLDEF
#define OBJLDEF 1
typedef void *OBJLIST;
#endif

typedef void SEGMENT;

/* Function prototypes: */

extern OBJECT *new_obj(int type, int nv, int np);
extern void add_vertex(OBJECT *obj, long x, long y, long z);
extern POLY *add_poly(OBJECT *obj, unsigned color, int npoints);
extern void add_point(OBJECT *obj, POLY *p, int vertnum);
extern void delete_obj(OBJECT *obj);
extern long get_object_bounds(OBJECT *obj, long *x, long *y, long *z);
extern void compute_obj(OBJECT *obj);
extern void set_obj_flags(OBJECT *obj, unsigned value);
extern unsigned get_obj_flags(OBJECT *obj);
extern void highlight_obj(OBJECT *obj);
extern void unhighlight_obj(OBJECT *obj);
extern void lock_rep(OBJECT *o, int number);
extern void unlock_rep(OBJECT *o);
extern void first_rep(OBJECT *obj);
extern int next_rep(OBJECT *obj);   /* return 1 if wrapping back to first */
extern void set_rep_size(OBJECT *obj, long size);
extern long get_rep_size(OBJECT *obj);
extern REP  *add_representation(OBJECT *obj, long size, int nv, int np);
extern void select_representation(OBJECT *obj, long size);
extern void delete_rep(OBJECT *obj);

/* Depth-sorting control: */
#define DEEPEST 0x0000          /* sort polys by deepest point */
#define ATBACK  0x0001          /* push this object's poly's waaaay back */
#define AVERAGE 0x0002          /* sort polys by average depth */

#define BYOBJECT   0x0100       /* sort by object */
#define BYPOLY     0x0000       /* put polys in world before sort */

extern unsigned get_object_sorting(OBJECT *obj);
extern void set_object_sorting(OBJECT *obj, unsigned depth_type);

extern unsigned get_default_depth_sort(void);
extern void set_default_depth_sort(unsigned value);

/* Values for object flags */
#define OBJ_NONSEL       0x0800 /* can't be selected (i.e. pointer) */
#define OBJ_INVIS        0x1000
#define OBJ_HIGHLIGHTED  0x2000
#define OBJLIST_HEADER   0x4000
#define IS_OBJECT        0x8000 /* required by renderer: it will set */

extern OBJLIST *new_objlist(void);
extern void add_to_objlist(OBJLIST *list, OBJECT *obj);
extern void remove_from_objlist(OBJECT *obj);
extern void del_objlist(OBJLIST *list);
extern OBJLIST *on_objlist(OBJECT *obj);
extern OBJECT *first_in_objlist(OBJLIST *objlist);
extern OBJECT *next_in_objlist(OBJECT *obj);
extern OBJECT *prev_in_objlist(OBJECT *obj);
extern int is_first_in_objlist(OBJECT *obj);
extern int is_last_in_objlist(OBJECT *obj);
extern void walk_objlist(OBJLIST *objlist, void (*fn)());
extern void get_obj_info(OBJECT *obj, int *nv, int *np);
extern void get_vertex_info(OBJECT *obj, int vertnum, long *x, long *y, long *z);
extern void get_vertex_world_info(OBJECT *obj, int vertnum, long *x, long *y, long *z);
extern void get_poly_info(OBJECT *obj, int polynum, unsigned *color, int *nverts, int *verts, int maxverts);
extern void set_poly_color(OBJECT *obj, int polynum, unsigned color);
extern void *get_object_owner(OBJECT *obj);
extern void set_object_owner(OBJECT *obj, void *owner);
extern void copy_world_to_object(OBJECT *obj);

extern void compute_view_factors(VIEW *v);

extern void fast_view_factors(VIEW *v);
void real_viewpoint(VIEW *v, long *x, long *y, long *z);

extern void initialize_screen_factors(VIEW *v);
		/* computes screen and viewport    */
		/* factors.  These stay constant   */
		/* over eye point changes          */
		/* setup viewport data, do once    */
		/* unless offset, zoom etc changed */


extern void *setup_render(unsigned K_of_mem, int maxpolys);  /* ptr to mem for temp use */
extern void reset_render(void);
extern void render(OBJLIST *objlist, VIEW *view);
extern void render_set_view(VIEW *view);
extern void subrender(OBJLIST *objlist);
extern int poly_cosine(POLY *pp, long lx, long ly, long lz, int spot);
extern void set_screen_monitor(int x, int y);
extern void clear_screen_monitor(void);
extern POLY *read_screen_monitor(void);

extern long where_pt(OBJLIST *objlist, long x, long y, long z, OBJECT **wobj, int *wvert);
extern OBJECT *best_collision(OBJLIST *objlist, long x, long y, long z);
extern int test_collision(OBJECT *obj, long x, long y, long z);
extern OBJECT *locate_screen_pt(int *pol, int *vert);
extern OBJECT *where_screen_pt(int *pol, int *vert, int x, int y);

extern SEGMENT *new_seg(SEGMENT *parent);
extern void seg_set_object(SEGMENT *s, void *app);
extern void *seg_get_object(SEGMENT *s);
extern char *seg_getname(SEGMENT *s);
extern void seg_setname(SEGMENT *s, char *name);
extern void seg_getposang(SEGMENT *s, long *rx, long *ry, long *rz);
extern void seg_getjointang(SEGMENT *s, long *rx, long *ry, long *rz);
extern void seg_getposxyz(SEGMENT *s, long *x, long *y, long *z);
extern void seg_getjointxyz(SEGMENT *s, long *x, long *y, long *z);
extern void abs_move_segment(SEGMENT *s, long tx, long ty, long tz);
extern void rel_move_segment(SEGMENT *s, long tx, long ty, long tz);
extern void abs_mat_segment(SEGMENT *s, MATRIX m);
extern void rel_mat_segment(SEGMENT *s, MATRIX m);
extern void abs_rotmat_segment(SEGMENT *s, MATRIX m);
extern void rel_rotmat_segment(SEGMENT *s, MATRIX m);
extern void abs_rot_segment(SEGMENT *s, long rx, long ry, long rz, int order);
extern void rel_rot_segment(SEGMENT *s, long rx, long ry, long rz, int order);
extern void move_rep(OBJECT *obj); /* move current rep of object  */
extern void set_move_handler(void (*move_handler_ptr)());
extern void full_update_segment(SEGMENT *seg);
extern void update_segment(SEGMENT *seg); /* scan till update needed */
extern SEGMENT *find_root_segment(SEGMENT *s);
extern SEGMENT *parent_segment(SEGMENT *s);
extern SEGMENT *child_segment(SEGMENT *s);
extern SEGMENT *sibling_segment(SEGMENT *s);
extern MATRIX *get_seg_jmatrix(SEGMENT *s);
extern MATRIX *get_seg_pmatrix(SEGMENT *s);
extern void detach_segment(SEGMENT *s);    /* assumes segment is updated! */
extern void attach_segment(SEGMENT *s, SEGMENT *to); /* assumes parent is updated! */
extern void delete_segment(SEGMENT *s, void (*delapp_fn)());
extern SEGMENT *find_segment_by_name(SEGMENT *s, char *name);
extern SEGMENT *copy_segment(SEGMENT *s, long dx, long dy, long dz, void *(*copy_fn)());

extern SEGMENT *get_root_segment(SEGMENT *s);
extern void seg_getrxyz(SEGMENT *s, long *rx, long *ry, long *rz);
extern int seg_get_flags(SEGMENT *s);
extern void seg_set_flags(SEGMENT *s, int f);

extern enter_graphics(void);
extern exit_graphics(void);
extern void clear_display(int page);
extern void vgabox(int left, int top, int right, int bottom, int color);

/* These next few routines are provided by the application programmer */
extern void user_setup_blitter();
extern void user_reset_blitter();
extern void user_render_poly(int number, int *pcoords, unsigned color, long maxz);
extern void user_text(int x, int y, int color, char *string);
extern void user_box(int x1, int y1, int x2, int y2, int color);
extern int user_poly_color(POLY *p, int pcolor, long maxz);

extern load_pcx(FILE *in, int page);
extern int save_pcx(FILE *out, int page);

typedef struct {   /* stereoscopic view factors */
	long phys_screen_dist;  /* eye-to-screen distance (mm); keep < 32000  */
	long phys_screen_width; /* viewport width on screen (mm)              */
	long pixel_width;       /* width of viewport in pixels                */
	long phys_eye_spacing;  /* spacing of eyes (mm) [usually 63]          */
	long phys_convergence;  /* convergence dist. (usually screen) (mm)    */
	long world_scaling;     /* world units per physical mm                */
	} STEREO ;

#define MONOSCOPIC 0 /* stereo types */
#define SWITCHED   1
#define SPLITLR    3
#define SEPARATE   5

#define LEFT_EYE   0
#define RIGHT_EYE  1

/* call fast_view_factors or view_from_matrix BEFORE these! */

	/* make a left or right eye view, cache */

extern void compute_stereo_data(STEREO *stereo, int eye, int xflip, int xdist, long yr,
			 long left, long top, long right, long bottom );

	/* create a new view from cyclopean view and cached data */

extern void make_stereo_view(VIEW *root, VIEW *nview, int eye);

	/* sufficient if only view point has changed and no twist or offset */
extern void update_stereo_view(VIEW *v, STEREO *s, int eye);

	/* makes a standard SWITCHED stereo screen */
extern void default_stereo_setup(VIEW *v, STEREO *s);

    /* high-resolution timer routines */
extern void tdelay(int msec);         /* replaces borland delay() */
extern long current_time(void);
extern void init_timer(void);
extern void set_current_time(long newtime);
extern int get_ticks_per_second(void);
extern volatile interrupts_occurred;

extern void *load_driver(char *dfile);
extern unsigned char get_video_driver_version(void);

extern void matrix_view_factors(VIEW *v,MATRIX m); /* set up from matrix xform */
extern void view_to_matrix(VIEW *v,MATRIX m);      /* view matrix to xform matrix */

/* For other matrix routines, you should now include intmath.h */

/* End of rend386.h */
