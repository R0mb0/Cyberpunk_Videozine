/* Code for loading drivers at runtime */

/* Written by Dave Stampe, August 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

#include <stdio.h>
#include <stdlib.h>   /* exit() */
#include <dos.h>
#include <alloc.h>

void *load_driver(char *dfile)
{
	FILE *f;
	long s;
	void *d_mem, *d_ptr;

	f = fopen(dfile,"rb"); /* open driver file */
	if (f == NULL) return NULL;

	fseek(f, 0, SEEK_END); /* find length, get memory */
	s = ftell(f);
	d_mem = (char *) malloc(s+16);
	if (d_mem == NULL)
	{
		fprintf(stderr,"Cannot allocate memory for driver.\n");
		exit(0);
	}/* setup for segment aligned load */

	d_ptr = MK_FP(FP_SEG(d_mem),0);
	fseek(f, FP_OFF(d_mem), SEEK_SET);
	fread(d_mem, 1, s-FP_OFF(d_mem), f);

	fclose(f);

	return d_ptr;
}

extern void *screen_data(void);

unsigned char get_video_driver_version()
	{
	unsigned char *ptr;
	ptr = screen_data();
	if (ptr[22]) return 1;  /* if there's a string there, it's version 1 */
	if (ptr[23] == 0) return 1;  /* if there's all zeros there, it's version 1 */
	return ptr[23];  /* otherwise, the second byte is the version number */
	}
