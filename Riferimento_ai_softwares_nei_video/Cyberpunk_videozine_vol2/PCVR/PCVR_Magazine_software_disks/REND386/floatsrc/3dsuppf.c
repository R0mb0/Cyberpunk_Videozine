/* Miscellaneous support routines */

/* Copyright 1992 by Bernie Roehl and Dave Stampe */

/* Written by Bernie Roehl, December 1991 */
/* updated 10/1/91 D. Stampe (for render first stage clip) */

/* REWRITTEN BACK TO FLOAT FOR EXAMPLE PURPOSES */


#include <stdio.h>
#include <alloc.h>
#include <string.h>
#include <math.h>

#include "3dstrucf.h"

void find_bounding_sphere(OBJECT *obj)
{
	int i;
	VALUE minx, maxx, miny, maxy, minz, maxz;

	minx = maxx = obj->verts[0].x;
	miny = maxy = obj->verts[0].y;
	minz = maxz = obj->verts[0].z;

	for (i = 1; i < obj->nverts; ++i)
		{  /* find bounding cube */
		if (obj->verts[i].x < minx) minx = obj->verts[i].x;
		if (obj->verts[i].y < miny) miny = obj->verts[i].y;
		if (obj->verts[i].z < minz) minz = obj->verts[i].z;
		if (obj->verts[i].x > maxx) maxx = obj->verts[i].x;
		if (obj->verts[i].y > maxy) maxy = obj->verts[i].y;
		if (obj->verts[i].z > maxz) maxz = obj->verts[i].z;
		}

	/* compute center of cube */
	obj->sphx = (maxx - minx) / 2 + minx;
	obj->sphy = (maxy - miny) / 2 + miny;
	obj->sphz = (maxz - minz) / 2 + minz;
	/* farthest point from center is the radius of the bounding sphere */
	obj->sphr = 0.0;

	for (i = 0; i < obj->nverts; ++i)
		{
		VALUE r;

		r = (obj->verts[i].x - obj->sphx) * (obj->verts[i].x - obj->sphx) +
			(obj->verts[i].y - obj->sphy) * (obj->verts[i].y - obj->sphy) +
			(obj->verts[i].z - obj->sphz) * (obj->verts[i].z - obj->sphz);
		r = sqrt(r);
		if (r > obj->sphr) obj->sphr = r;
		}
}


			/* minimum value for cosine of the two vectors */
#define THRESHOLD cos(10*3.14159262/180.0)  		 /* 10 degrees */


/* Compute a polygon's normal and the intensity of the light upon it */

void compute_normal(POLY *p)
{
	VERTEX *v0, *v1, *v2;
	VALUE x1,x2,y1,y2,z1,z2;
	VALUE mag, illum;
	VALUE t1, t2, t3;
	int i = 0;
	VALUE nx, ny, nz;

	do
		{
		/* get 3 points */
		v0 = p->points[i]; v1 = p->points[i+1]; v2 = p->points[i+2];
		++i;
		/* compute vectors between them */
		x1 = v2->x - v0->x; y1 = v2->y - v0->y; z1 = v2->z - v0->z;
		x2 = v1->x - v0->x; y2 = v1->y - v0->y; z2 = v1->z - v0->z;
		/* compute the total magnitude */
		mag = sqrt(x1 * x1 + y1 * y1 + z1 * z1);
		mag *= sqrt(x2 * x2 + y2 * y2 + z2 * z2);
		/* compute cos of angle between vec1 and vec2 */
		mag = (x1 * x2 + y1 * y2 + z1 * z2)/mag;
		/* continue until we can't, or until angle is large enough */
		} while ((i + 2) < p->npoints && fabs(mag) < THRESHOLD);

	/* compute polygon normal */
	nx = y2 * z1 - z2 * y1;
	ny = z2 * x1 - x2 * z1;
	nz = x2 * y1 - y2 * x1;

	/* Now make normal unit length */
	mag = sqrt(nx * nx + ny * ny + nz * nz);
	p->normalx = nx / -mag;
	p->normaly = ny / -mag;
	p->normalz = nz / -mag;

}

