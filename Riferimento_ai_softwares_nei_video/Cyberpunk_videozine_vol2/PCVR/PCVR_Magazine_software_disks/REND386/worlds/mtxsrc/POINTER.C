/* Pointer device driver interface routines */

/* Written by Dave Stampe, Aug. 1992 */

/* Copyright 1992 by Bernie Roehl and Dave Stampe.
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
#include <string.h>
#include "rend386.h"  /* for MATRIX definition */
#include "pointer.h"

extern long scale_16(long s, long a, long x); /* used to do scaling */
                                              /* (x+a)*s            */

extern long calc_scale_16(long a, long b, long s); /* computes scaling factor */
                                                   /* (a+b)/2/s          */

extern pconfig *mouse_driver(int op, POINTER *p, int mode);
extern pconfig *glove_driver(int op, POINTER *p, int mode);
extern pconfig *logitech_driver(int op, POINTER *p, int mode);
extern pconfig *pot_driver(int op, POINTER *p, int mode);
extern void *load_driver(char *m);

int logitech_port = 0;  /* used to pass logitech port */

PDRIVER *pointer_init(int type, char *drfile)
{
	pconfig *(*pd)(int op, POINTER *p, int mode);
	pdrblock *p;
	pconfig *d;
	if (drfile == NULL) return NULL;

	if (!stricmp(drfile, "mouse"))
	{
		p = malloc(sizeof(pdrblock));
		if (p == NULL) return NULL;
		d = mouse_driver(DRIVER_INIT, (POINTER *) type, 0);
		if (d == NULL) return NULL;  /* Added this check 2/27/93 --Bernie */
		p->driver_pointer = mouse_driver;
	}
	else if (!stricmp(drfile, "pglove"))
	{
			p = malloc(sizeof(pdrblock));
			if (p == NULL) return NULL;
			d = glove_driver(DRIVER_INIT, (POINTER *) type, 0);
			if (d == NULL) return NULL;  /* Added this check 2/27/93 --Bernie */
			p->driver_pointer = glove_driver;
	}
	else if (!strnicmp(drfile, "logitech", 8))
		{                                 /* select com2 based on trailing char. */
		logitech_port = (drfile[8]=='2') ? 1 : 0;
		p = malloc(sizeof(pdrblock));
		if (p == NULL) return NULL;
		d = logitech_driver(DRIVER_INIT, (POINTER *) type, 0);
		p->driver_pointer = logitech_driver;
		}
	else if (!strnicmp(drfile, "pots", 8))
		{                                 /* select com2 based on trailing char. */
		p = malloc(sizeof(pdrblock));
		if (p == NULL) return NULL;
		d = pot_driver(DRIVER_INIT, (POINTER *) type, 0);
		p->driver_pointer = pot_driver;
		}
	else
		{
		pd = load_driver(drfile);
		if (pd == NULL) return NULL;
		p = malloc(sizeof(pdrblock));
		if (p == NULL) return NULL;
		p->driver_pointer = pd =
			MK_FP(FP_SEG(pd), 16+FP_OFF(pd)); /* entry point */
		d = pd(DRIVER_INIT, (POINTER *) type, 0);
		if (d == NULL) return NULL;
	}

	p->pdata = d;
	p->xmult = p->ymult = p->zmult = 65536L;
	p->xadd = p->yadd = p->zadd = 0;
	p->xrmult = p->yrmult = p->zrmult = 65536L;
	p->xradd = p->yradd = p->zradd = 0;
	return p;
}

/* makes sure device is available, OK */
/* returns *pconfig or NULL           */

pconfig *pointer_check(PDRIVER *p)
{
	if (p)
		return (((pdrblock *)p)->driver_pointer) (DRIVER_CHECK, NULL, 0);
	else
		return NULL;
}

/* recenters, recalibrates, etc */
void pointer_reset(PDRIVER *p)
{
	if (p == NULL) return;
	(((pdrblock *)p)->driver_pointer) (DRIVER_RESET, NULL, 0);
}

/* reads pointer, scales data and        */
/* returns bitwise OR of the following:  */
int pointer_read(PDRIVER *p, POINTER *pt)
{
	POINTER *op = &((pdrblock *)p)->oldp;
	pdrblock *pd = (pdrblock *)p;
	int has = pd->pdata->databits;
	int changed = 0;
	int sx, sy;

	if (p == NULL || pt == NULL) return 0;
	if ((p->driver_pointer) (DRIVER_READ, pt, P_POINTER) == NULL)
	{
		memcpy( pt, op, sizeof(POINTER) ); /* handle no new data */
		pt->wpos_valid = 0;
		pt->changed = 0;
		op->changed = 0;
		return 0;
	}

	if (has & P_HASX)
	{
		pt->x = scale_16(pd->xmult, pd->xadd, pt->x);
		if ((pt->dx = pt->x - op->x) != 0) changed |= PNEW_POS;
	}
	else pt->x = 0;
	if (has & P_HASY)
	{
		pt->y = scale_16(pd->ymult, pd->yadd, pt->y);
		if ((pt->dy = pt->y - op->y) != 0) changed |= PNEW_POS;
	}
	else pt->y = 0;
	if (has & P_HASZ)
	{
		pt->z = scale_16(pd->zmult, pd->zadd, pt->z);
		if ((pt->dz = pt->z - op->z) != 0) changed |= PNEW_POS;
	}
	else pt->z = 0;

	if (has & P_HASRX)
	{
		pt->rx = scale_16(pd->xrmult, pd->xradd, pt->rx);
		if ((pt->drx = pt->rx - op->rx) != 0) changed |= PNEW_ROT;
	}
	else pt->rx = 0;
	if (has & P_HASRY)
	{
		pt->ry = scale_16(pd->yrmult, pd->yradd, pt->ry);
		if ((pt->dry = pt->ry - op->ry) != 0) changed |= PNEW_ROT;
	}
	else pt->ry = 0;
	if (has & P_HASRZ)
	{
		pt->rz = scale_16(pd->zrmult, pd->zradd, pt->rz);
		if ((pt->drz = pt->rz - op->rz) != 0) changed |= PNEW_ROT;
	}
	else pt->rz = 0;

	pt->buttons &= has&0x0007 ;
	if ((has&0x0007) && pt->buttons != op->buttons) changed |= PNEW_BUT;

	if ((has&P_HASGEST) && pt->gesture != op->gesture) changed |= PNEW_GEST;

	if ((has&P_HASKEYS) && pt->keys != op->keys) changed |= PNEW_KEY;

	if (has & P_HASFLEX)
	{
		int i;
		int n = pd->pdata->flexnum;

		for (i = 0; i < n; i++)
			if (pt->flex[i] != op->flex[i])
			{
				changed |= PNEW_FLEX;
				break;
			}
	}
	if (changed)
	{
		memcpy(op, pt, sizeof(POINTER));
		pt->wpos_valid = 0;
	}
	pt->changed = changed;
	op->changed = changed;
	return changed;
}


int mouse_read(PDRIVER *p, int *xp, int *yp, unsigned *bp)
{
	POINTER pt;
	POINTER *opt = &(p->oldp);
	int c = 0;

	if (p == NULL) return 0;
	if (!(p->pdata->databits & P_HASSCR)) return 0;

	(p->driver_pointer) (DRIVER_READ, &pt, P_SCREEN);

	if (p->oldsx != pt.x || p->oldsy != pt.y)
		c |= PNEW_POS;
	if (opt->buttons != pt.buttons)
		c |= PNEW_BUT;

	p->oldsx = pt.x;
	p->oldsy = pt.y;
	opt->buttons = pt.buttons ;

	if (xp) *xp = pt.x;
	if (yp) *yp = pt.y;
	if (bp) *bp = pt.buttons;

	opt->changed = c;

	return c;
}


int mouse_last(PDRIVER *p, int *xp, int *yp, int *bp)
{
	if (p == NULL) return 0;

	if (xp) *xp = p->oldsx;
	if (yp) *yp = p->oldsy;
	if (bp) *bp = (&(p->oldp))->buttons;
	return (&(p->oldp))->changed;
}

void set_mouse_limits(PDRIVER *p, int maxx, int maxy)
{
	if (p == NULL) return; /* NOTE: MODIFIES DRIVER */
	p->pdata->maxsx = maxx;
	p->pdata->maxsy = maxy;
	(p->driver_pointer) (DRIVER_CMD, (POINTER *) (P_SCREEN | P_CENTER), 0);
	mouse_read(p, NULL, NULL, NULL);
}

/* disconnects driver */
void pointer_quit(PDRIVER *p)
{
	if (p == NULL) return;
	(((pdrblock *)p)->driver_pointer) (DRIVER_QUIT, NULL, 0);
}

/* changes device mode */
pconfig *device_command(PDRIVER *p, int command)
{
	pconfig *pc;

	if (p == NULL) return NULL;
	pc = (((pdrblock *)p)->driver_pointer) (DRIVER_CMD, (POINTER *) command, 0);
	p->pdata = pc;
	return pc;
}

/* sets scaling (+/- given value, centered at 0) */

void pointer_tscale(PDRIVER *p, long x, long y, long z)
{
	long mx = p->pdata->maxx;
	long mn = p->pdata->minx;
	p->xmult = calc_scale_16(mx, mn, x);
	p->xadd = (mn-mx)/2;

	mx = p->pdata->maxy;
	mn = p->pdata->miny;
	p->ymult = calc_scale_16(mx, mn, y);
	p->yadd = (mn-mx)/2;

	if (p->pdata->type != P_IS2DP) /* use y scaling for pseudo-z axis */
	{
		mx = p->pdata->maxz;
		mn = p->pdata->minz;
	}
	p->zmult = calc_scale_16(mx, mn, z);
	p->zadd = (mn-mx)/2;
}


void pointer_rscale(PDRIVER *p, long rx, long ry, long rz)
{
	long mx = p->pdata->maxxr;
	long mn = p->pdata->minxr;
	p->xrmult = calc_scale_16(mx, mn, rx);
	p->xradd = (mn-mx)/2;

	mx = p->pdata->maxyr;
	mn = p->pdata->minyr;
	p->yrmult = calc_scale_16(mx, mn, ry);
	p->yradd = (mn-mx)/2;

	mx = p->pdata->maxzr;
	mn = p->pdata->minzr;
	p->zrmult = calc_scale_16(mx, mn, rz);
	p->zradd = (mn-mx)/2;
}

void pointer_abscale(PDRIVER *p, long xs, long ys, long zs,
	long xrs, long yrs, long zrs)
{
	p->xmult = scale_16(xs, 0, p->pdata->xres); /* set up to scale tick resolution */
	p->ymult = scale_16(ys, 0, p->pdata->yres);
	p->zmult = scale_16(zs, 0, p->pdata->zres);
	p->xrmult = scale_16(xrs, 0, p->pdata->xrres); /* some weirdness with rot. scaling */
	p->yrmult = scale_16(yrs, 0, p->pdata->yrres); /* as tick res. not really expressible */
	p->zrmult = scale_16(zrs, 0, p->pdata->zrres); /* in <16.16>: so set tickres>>16 or so */
	p->xadd = p->yadd = p->zadd = 0; /* look at PG y-rot for example */
	p->xradd = p->yradd = p->zradd = 0;
}


void init_pointer(POINTER *p) /* initialize pointer structure */
{
	memset( p, 0, sizeof(POINTER));
	p->wpos[0][0] = p->wpos[1][1] = p->wpos[2][2] = 536870912L;
}

int last_pointer(PDRIVER *d, POINTER *p) /* copy of last read value */
{
	memcpy(p, &(d->oldp), sizeof(POINTER));
	return(p->changed);
}
