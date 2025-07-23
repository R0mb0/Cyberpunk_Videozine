/* Matrix math, assembly by Dave Stampe */
/* Protoypes for matrix and integer math routines */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

/* Contact: broehl@sunee.waterloo.edu or dstampe@sunee.waterloo.edu */

extern long isine(long angle);
extern long icosine(long angle);
extern long arcsine(long x);
extern long arccosine(long x);
extern long arctan2(long y, long x);

	/* Create rotation/translation "matrix" from angle data.  */
	/* Can only be used after setup_render() has been called */
extern void std_matrix(MATRIX m,
		long rx, long ry, long rz,
		long tx, long ty, long tz);

#define RXYZ 1		/* matrix rotation types */
#define RYXZ 0          /* ONLY RYXZ guaranteed to be tested */
#define RXZY 2
#define RZYX 5
#define RZXY 4
#define RYZX 6

extern void multi_matrix(MATRIX m, long rx, long ry, long rz,
												 long tx, long ty, long tz, int type );

	/* multiplies upper left 3x3 submatrices A and B giving C */
extern void matrix_mult(MATRIX a, MATRIX b, MATRIX c);

	/* multiplies matrices: A*B->C */
extern void matrix_product(MATRIX a, MATRIX b, MATRIX c);

	/* rotate & translate XYZ by matrix */
extern void matrix_point(MATRIX m, long *xp, long *yp, long *zp);

	/* rotate XYZ by matrix */
extern void matrix_rotate(MATRIX m, long *xp, long *yp, long *zp);

	/* generate inverse of rotate matrix (transpose) */
	/* ONLY WORKS FOR ORTHOGONAL MATRICES */
extern void matrix_transpose(MATRIX a, MATRIX b);

	/* generate inverse of rotate/translate matrix */
extern void inverse_matrix(MATRIX a, MATRIX b);

		/* use "matrix" to compute world coords from object coords for obj */
extern void apply_matrix(OBJECT *obj, MATRIX m);

		/* move bounds sphere only */
extern void matmove_osphere(OBJECT *obj, MATRIX m);

		/* move all of rep's polys, vertices */
extern void matmove_rep(REP *rep, MATRIX m);

		/* create identity matrix */
extern void identity_matrix(MATRIX m);

		/* copy matrix */
extern void matrix_copy(MATRIX s, MATRIX d);

	/* copies upper left 3x3 submatrix, zeros translation part (bottom row) */
extern void matrix_rot_copy(MATRIX s, MATRIX d);

	/* perform multiplication of <3.29> matrix elements */
extern long m_mult(long a, long b);

	/* returns (ax+by+cz)>>29) */
extern long dot_prod_29(long a, long b, long c, long x, long y, long z);

	/* returns (ax+cz+d)/-b) */
extern long plane_y(long a, long b, long c, long d, long x, long z);

	/* returns >65536 if not in sphere     */
	/* else ((D/R)^2)<<16 ratio to find    */
	/* closest to center (choose smallest) */
extern long sphere_pretest(OBJECT *obj, long x, long y, long z);

	/* makes matrix that will xform Z axis to given vector */
extern void vector_to_matrix(MATRIX m, long x, long y, long z);

extern void matrix_to_angle(MATRIX m, long *rx, long *ry, long *rz);

extern void cross_column(MATRIX m, int col);

extern long big_dist(long x1, long y1, long z1,
				 long x2, long y2, long z2);

extern int find_normal(long x1, long y1, long z1,
		long x2, long y2, long z2,
		long x3, long y3, long z3,
		long *xn, long *yn, long *zn);

											 /* rescale matrix: do every 1000 mults or so */
extern void fix_matrix_scale(MATRIX m);

extern long scale_16(long s, long a, long x);  /* s*(x+a) */
extern long calc_scale_16(long a, long b, long s);  /* 2s/(a-b) */

/* End of intmath.h */
