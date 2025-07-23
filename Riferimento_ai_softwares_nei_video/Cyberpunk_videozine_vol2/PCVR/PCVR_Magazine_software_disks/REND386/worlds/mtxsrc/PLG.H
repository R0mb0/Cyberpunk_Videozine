/* Header file for plg file routines */

/* Written by Bernie Roehl, March 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

extern int load_err;  /* set if an error was encountered during loading */
extern void set_loadplg_offset(long x, long y, long z);
extern void set_loadplg_scale(float x, float y, float z);
extern void set_loadplg_depthsort(int type);
extern OBJECT *load_plg(FILE *in);
extern OBJECT *load_multi_plg(FILE *in);
extern OBJECT *load_extra_rep(FILE *in, OBJECT *obj, long size);
extern save_plg(OBJECT *obj, FILE *out, int world_coords);
extern void set_loadplg_colormap(unsigned *map, int msize);
extern void strip_comment(char *buff);  /* also trim newline character(s) */

extern int load_err;   /* set if an error was encountered during loading */
extern int err_line;   /* line on which error occurred */

extern char *plg_errmsgs[];

/* End of plg.h */
