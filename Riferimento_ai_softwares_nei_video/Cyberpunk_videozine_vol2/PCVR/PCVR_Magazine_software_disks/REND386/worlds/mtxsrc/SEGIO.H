/* Header file for segment i/o routines */

/* Written by Bernie Roehl, May 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

extern int readseg_err;
extern char *readseg_errmsgs[];

extern void set_readseg_objlist(OBJLIST *olist);
extern void set_readseg_seglist(SEGMENT **ptr, int maxsegs);
extern void set_readseg_scale(float x, float y, float z);
extern SEGMENT *readseg(FILE *in, SEGMENT *parent);
extern writeseg(FILE *out, SEGMENT *s, int level);

/* End of segio.h */
