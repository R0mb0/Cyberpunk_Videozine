/*
 * Previewer or NFF files using VOGLE.
 * 
 * One and only real option -p<n> for the precision with which the cylinders
 * and cones are drawn (ie they are made up of approximating straight lines).
 * (Plus a -d<n> for debugging - but you won't want that will you?)
 *
 * Any comments queries etc to echidna@gondwana.ecr.mu.OZ.AU
 * or echidna@munnari.OZ.AU
 *
 */

#include <stdio.h>
#include <math.h>
#include "vogle.h"

/*
 * The viewing parameters....
 */
struct {
	float	Fx, Fy, Fz;
	float	Ax, Ay, Az;
	float	Ux, Uy, Uz;
	float	angle;
	float	hither, yon;
	int	xres, yres;
} view;

/*
 * Could have done something with the actual colours but didn't...
 * (they're currently ignored)
 */
struct	{
	float	r, g, b;
} bg, fc;

int	pr = 12;	/* Precision of cones and spheres */
int	line = 1;	/* Line number in nff file */
int	debug = 0;

FILE	*fp;

char	*filename;
char	buf[128];

main(argc, argv)
	int	argc;
	char	**argv;
{
	int	c;
	float	dum, Kd, Ks, Shine, T, i_of_r;

	if (argc < 2) {
		fprintf(stderr, "usage: %s [-p<n>] nfffile\n", argv[0]);
		exit(1);
	}
	
	for (c = 1; c < argc; c++) {
		if (strncmp(argv[c], "-p", 2) == 0)
			pr = atoi(&argv[c][2]);
		else if (strncmp(argv[c], "-d", 2) == 0) {
			debug = atoi(&argv[c][2]);
			fprintf(stderr, "debug: %d\n", debug);
		} else
			filename = argv[c];
	}
	

	if ((fp = fopen(filename, "r")) == (FILE *)NULL) {
		fprintf(stderr, "Couldn't open %s for reading.\n", filename);
		exit(1);
	}


	while ((c = getc(fp)) != EOF) {
		switch (c) {
		case '\t':
			break;

		case 'v':
			read_view();
			break;

		case 'l':	/* Lights - ignore them */
			read_three("%g %g %g\n", &dum, &dum, &dum);
			break;

		case 'b':	/* Background color */
			read_three("%g %g %g\n", &bg.r, &bg.r, &bg.r);
			break;

		case 'f':	/* Fill color and shading stuff */
			if (fscanf(fp, "%g %g %g %g %g %g %g %g\n", 
				&fc.r, &fc.b, &fc.b,
				&Kd, &Ks, &Shine, &T, &i_of_r) != 8)
				thunk("what happened");

			line++;
			break;
		case 'c':	/* Cylinder or Cone */
			read_cone();
			break;

		case 's':	/* Sphere */
			read_sphere();
			break;

		case 'p':	/* Polygon or polygonal patch */
			c = getc(fp);
			if (c == 'p')
				read_polypatch();
			else
				read_poly();

			break;

		case '#':	/* Comment */
			while ((c = getc(fp)) != '\n' && c != EOF)
				/* VOID */ ;

				if (c == EOF)
					exit(0);

				line++;

			break;

		default:
			sprintf(buf, "Unknown  key character '%c'.", c);
			thunk(buf);
		}
	}

	getkey();

	vexit();
}

/*
 * read_view
 *
 *	Read in the viewing parameters
 */
read_view()
{
	read_three("\nfrom %g %g %g", &view.Fx, &view.Fy, &view.Fz);
	read_three("\nat %g %g %g", &view.Ax, &view.Ay, &view.Az);
	read_three("\nup %g %g %g", &view.Ux, &view.Uy, &view.Uz);

	if (fscanf(fp, "\nangle %g", &view.angle) != 1)
		thunk("wanted a number for fov");

	line++;
	if (fscanf(fp, "\nhither %g", &view.hither) != 1)
		thunk("wanted a number for hither");

	line++;
	if (fscanf(fp, "\nresolution %d %d\n", &view.xres, &view.yres) != 2)
		thunk("wanted two numbers for resolution");

	line++;
	view.yon = 1.0e38;

	if (debug) {
		fprintf(stderr, "View is:\n");
		fprintf(stderr, "from %g %g %g\n", view.Fx, view.Fy, view.Fz);
		fprintf(stderr, "at %g %g %g\n", view.Ax, view.Ay, view.Az);
		fprintf(stderr, "up %g %g %g\n", view.Ux, view.Uy, view.Uz);
		fprintf(stderr, "angle %g\n", view.angle);
		fprintf(stderr, "hither %g\n", view.hither);
		fprintf(stderr, "resolution %d %d\n", view.xres, view.yres);
	}

	/*
	 * Open vogle .....
	 */

	prefsize(view.xres, view.yres);	/* If we can - do it */

	vinit(0);	/* Get device from environment variable VDEVICE */
	color(BLACK);
	clear();

	/*
	 * Set up view ....
	 */
	up(view.Ux, view.Uy, view.Uz);
	perspective(view.angle, 1.0, view.hither, view.yon);
	lookat(view.Fx, view.Fy, view.Fz, view.Ax, view.Ay, view.Az, 0.0);

	/*
	 * Set precision ...
	 */
	circleprecision(pr);
}

/*
 * read_sphere
 *
 *	Read in and draw a sphere.
 */
read_sphere()
{
	float	i, x, y, z, r, a;
	float	delta = 180.0 / pr;

	color(RED);

	read_four("%g %g %g %g\n", &x, &y, &z, &r);

	if (debug == 2 || debug == 5) 
		fprintf(stderr, "sphere: %g %g %g %g\n", x, y, z, r);

	pushmatrix();
		translate(x, y, z);
		/*
		 * create the longitudinal rings
		 */
		for (i = 0; i < 180; i += delta) {
			pushmatrix();
				rotate(i, 'y');
				circle(0.0, 0.0, r);
			popmatrix();
		}
		
		/*
		 * create the latitudinal rings
		 */
		pushmatrix();
			rotate(90.0, 'x');
			for (i = -90.0; i < 90.0; i += delta) {
				a = r * cos((double)i * PI / 180.0);
				z = r * sin((double)i * PI / 180.0);
				pushmatrix();
					translate(0.0, 0.0, -z);
					circle(0.0, 0.0, a);
				popmatrix();	
			}
		popmatrix();
	popmatrix();

}

/*
 * read_cone
 *
 *	Read in and draw a cone or a cylinder
 */
read_cone()
{
	float	apex_x, apex_y, apex_z, apex_r;
	float	base_x, base_y, base_z, base_r;
	float	len0, len1,  len_x, len_y, len_z;
	float	cosine, sine, dx1, dy1, dx2, dy2, delta;
	float	cx1, cy1, cx2, cy2;
	int	i;
	Matrix	m;

	read_four("%g %g %g %g\n", &base_x, &base_y, &base_z, &base_r);
	read_four("%g %g %g %g\n", &apex_x, &apex_y, &apex_z, &apex_r);

	if (debug == 2 || debug == 5) {
		fprintf(stderr, "cone: %g %g %g $g\n", base_x, base_y, base_z, base_r);
		fprintf(stderr, "cone: %g %g %g $g\n", apex_x, apex_y, apex_z, apex_r);
	}

	len_x = apex_x - base_x;
	len_y = apex_y - base_y;
	len_z = apex_z - base_z;

	if ((len0 = sqrt(len_x * len_x + len_y * len_y + len_z * len_z)) < 1.0e-20)
		warn("c: zero length cone or cylinder");

	len1 = sqrt(len_x * len_x + len_z * len_z);

	/*
	 * Draw the axis center line in YELLOW
	 */
	color(YELLOW);
	move(base_x, base_y, base_z);
	draw(apex_x, apex_y, apex_z);

	/*
	 * And the rest in GREEN...
	 */
	color(GREEN);

	pushmatrix();

		translate(base_x, base_y, base_z);

		identmatrix(m);

		if (len1 == 0.0) {
			cosine = 0.0;
			sine = 1.0;
		} else {
			cosine = len_z / len1;
			sine = len_x / len1;
		}

		/* rotate about y */
		m[0][0] = cosine;
		m[0][2] = -sine;
		m[2][0] = sine;
		m[2][2] = cosine;
		multmatrix(m);

		identmatrix(m);

		if (len0 == 0.0) {
			cosine = 0.0;
			sine = 1.0;
		} else {
			cosine = len1 / len0;
			sine = -len_y / len0;
		}

		/* rotate about x */
		m[1][1] = cosine;
		m[1][2] = sine;
		m[2][1] = -sine;
		m[2][2] = cosine;
		multmatrix(m);

		/*
		 * Draw the end circles...
		 */
		circle (0.0, 0.0, base_r);
		pushmatrix();
			translate(0.0, 0.0, len0);
			circle (0.0, 0.0, apex_r);
		popmatrix();



		/*
		 * Draw the logitudinal lines...
		 */
		delta = 2 * PI / pr;

		cosine = cos(delta);
		sine = sin(delta);

		cx1 = base_r;
		cy1 = 0.0;
		cx2 = apex_r;
		cy2 = 0.0;

		move(cx1, cy1, 0.0);
		draw(cx2, cy2, len0);

		for (i = 0; i < pr; i++) {
			dx1 = cx1;
			dy1 = cy1;
			cx1 = dx1 * cosine - dy1 * sine;
			cy1 = dx1 * sine + dy1 * cosine;
			dx2 = cx2;
			dy2 = cy2;
			cx2 = dx2 * cosine - dy2 * sine;
			cy2 = dx2 * sine + dy2 * cosine;
			move(cx1, cy1, 0.0);
			draw(cx2, cy2, len0);
		}
	popmatrix();
}

/*
 * read_poly
 *
 * 	Read in and draw a polygon.
 */
read_poly()
{
	float	x, y, z, xp, yp, zp, x0, y0, z0;
	int	i, nv;

	if (fscanf(fp, "%d\n", &nv) != 1)
		thunk("wanted an integer for number of verticies");

	line++;

	if (nv <= 0)
		thunk("p: silly value for number of verticies");
	
	color(CYAN);

	read_three("%g %g %g\n", &x0, &y0, &z0);

	if (debug == 3 || debug == 5) 
		fprintf(stderr, "poly: %g %g %g\n", x0, y0, z0);

	move(x0, y0, z0);

	xp = x0;
	yp = y0;
	zp = z0;

	for (i = 1; i < nv; i++) {
		read_three("%g %g %g\n", &x, &y, &z);

		if (debug == 3 || debug == 5) 
			fprintf(stderr, "poly: %g %g %g\n", x, y, z);

		draw(x, y, z);
		if (xp == x && yp == y && zp == z) {
			warn("p: point same as previous point");
			sprintf(buf, "%g %g %g = %g %g %g", xp, yp, zp, x, y, z);
			warn(buf);
		}

		xp = x;
		yp = y;
		zp = z;
	}
	/*
	 * Connect last to first...
	 */
	draw(x0, y0, z0);
}

/*
 * read_polypatch
 *
 *	Read in and draw a "poly patch" thingo (ie a polygon with
 *	vertex normals)
 */
read_polypatch()
{
	float	x, y, z, x0, y0, z0, xp, yp, zp, nx, ny, nz;
	int	i, nv;

	color(MAGENTA);

	if (fscanf(fp, "%d\n", &nv) != 1)
		thunk("wanted an integer for number of verticies");

	if (nv <= 0)
		thunk("pp: silly value for number of verticies");

	line++;
	
	read_six("%g %g %g %g %g %g\n", &x0, &y0, &z0, &nx, &ny, &nz);

	if (debug == 4 || debug == 5) 
		fprintf(stderr, "poly_patch: %g %g %g %g %g %g\n", x0, y0, z0, nx, ny, nz);

	if (nx == 0.0 && ny == 0.0 && nz == 0.0)
		warn("pp: zero length normal vector");

	xp = x0;
	yp = y0;
	zp = z0;

	move(x0, y0, z0);
	for (i = 1; i < nv; i++) {
		read_six("%g %g %g %g %g %g\n", &x, &y, &z, &nx, &ny, &nz);

		if (debug == 4 || debug == 5) 
			fprintf(stderr, "poly_patch: %g %g %g %g %g %g\n", x, y, z, nx, ny, nz);


		draw(x, y, z);

		if (nx == 0.0 && ny == 0.0 && nz == 0.0)
			warn("pp: zero length normal vector");

		if (xp == x && yp == y && zp == z) {
			warn("pp: point same as previous point");
			sprintf(buf, "%g %g %g = %g %g %g", xp, yp, zp, x, y, z);
			warn(buf);
		}

		xp = x;
		yp = y;
		zp = z;
	}
	/*
	 * Connect last to first...
	 */
	draw(x0, y0, z0);
}

/*
 * warn
 *
 *	Print a warning
 */
warn(s)
	char	*s;
{
	fprintf(stderr, "%s: line %d: %s\n", filename, line, s);
}

/*
 * thunk
 *
 *	Go thunk! (die)
 */
thunk(s)
	char	*s;
{
	fprintf(stderr, "%s: line %d: %s\n", filename, line, s);
	exit(1);
}

/*
 * We seem to be reading lots of sets of 3 or 4 or 6 numbers....
 */
read_three(f, a, b, c)
	char	*f;
	float	*a, *b, *c;
{
	int	n;

	if ((n = fscanf(fp, f, a, b, c)) != 3) {
		sprintf(buf, "expected to read 3 numbers with '%s' format but got %d\n", f, n);
		thunk(buf);
	}

	line++;
}

read_four(f, a, b, c, d)
	char	*f;
	float	*a, *b, *c, *d;
{
	int	n;

	if ((n = fscanf(fp, f, a, b, c, d)) != 4) {
		sprintf(buf, "expected to read 4 numbers with '%s' format but got %d\n", f, n);
		thunk(buf);
	}

	line++;
}

read_six(f, a, b, c, d, e, g)
	char	*f;
	float	*a, *b, *c, *d, *e, *g;
{
	int	n;

	if ((n = fscanf(fp, f, a, b, c, d, e, g)) != 6) {
		sprintf(buf, "expected to read 6 numbers with '%s' format but got %d\n", f, n);
		thunk(buf);
	}

	line++;
}
