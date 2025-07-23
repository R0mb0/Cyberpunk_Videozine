/* Cursor routines */

/* Written by Dave Stampe, August 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

extern void cursor_move(int x, int y);  /* move cursor if visible */
extern int cursor_hide(void);               /* erase cursor */
extern int cursor_forget(void);             /* will be erased by redraw: ignore it! */
extern void cursor_show(int page);      /* redisplay cursor */
extern int move_2D(PDRIVER *d, int *x, int *y, unsigned *b);
extern int move_till_click(PDRIVER *d, unsigned b, int *x, int *y); /* b is button mask */
extern int can_point_2D(void);
extern int move_and_select_2D(PDRIVER *d);
extern void pointer_to_world(POINTER *p, VIEW *v, long *x, long *y, long *z);
extern void rotate_to_view( VIEW *v, long *x, long *y, long *z);
extern int glove_update(PDRIVER *d, POINTER *p); /* read glove, update positions */
extern int load_glove_cursor(SEGMENT *body_seg, PDRIVER *gd, char *glove_fname);
extern int load_3D_cursor(SEGMENT *body_seg, PDRIVER *gd, char *cursor_fname);
extern int cursor_update3D(PDRIVER *d, POINTER *p); /* read pointer, update positions */
extern SEGMENT *manip_data(PDRIVER *d, long *x, long *y, long *z);

#define FREE_DO   0    		/* commands to manipulation */
#define GRASP_DO  1
#define ROTATE_DO 2
#define SELECT_DO 3

/* End of cursor.h */
