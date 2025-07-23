/*  PLG file processing package
/*  by Dave Stampe 13/5/93
/*
/*  PLGX.EXE
/*  type PLG /? for instructions
/*
/*  center, size, scale, rotate, translate
/*  merge duplicate vertices (IRIT and NorthCad)
/*  renumber vertex comments in file
/*  attempts to preserve original comments in new file
/*
*/



#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXVERTS 2000
#define MAXPOLYS 2000
						  /* vertex, poly storage */
typedef struct { float x, y, z;         } VERT;
typedef struct { char color[20];
		 unsigned nverts;
		 unsigned vtx[20];       } POLY;

#define DEL 1e10	/* flags deleted vertex */

VERT v[MAXVERTS];       /* array of vertices */
int vmap[MAXVERTS];     /* maps vertices for combination */
POLY *p[MAXPOLYS];      /* pointers to polygons */
int nlines;             /* total lines in PLG file */
int nameline;           /* original file line numbers of PLG */
int vtxline;            /* sections: so comments will be in  */
int polyline;           /* the right places */

char fin[80] = "";      /* in, out filennames */
char fout[80] = "";

FILE *in, *out;

char plgname[100];      /* PLG object name */

int hasverts = 0;	/* when reading the #MULTI tag is valid */

int nverts, npolys;     /* old, new vertex counts to/from processing */
int overts, opolys;

char line[300];		/* line from PLG file */

float sx = 1.0, sy = 1.0, sz = 1.0; /* scale   */
float tx = 0.0, ty = 0.0, tz = 0.0; /* xlat    */
float rx = 0.0, ry = 0.0, rz = 0.0; /* rotate  */
float bx = 0.0, by = 0.0, bz = 0.0; /* box fit */
float clim = -1.0;                  /* combine delta */

int centerxz = 0;	/* action flags */
int centery = 0;
int gcenter = 0;
int ground = 0;
int info = 0;
int multi = 0;
int renverts = 0;
int reverse = 0;
int whole = 0;
int integrated = 0;

float maxx, maxy, maxz;		/* box size/center statistics */
float minx, miny, minz;
float sumx, sumy, sumz;

long plgpos;
int abssumverts;

read_plg()		/* reads data from PLG file, checks */
{
 int i,j,k;
 char *c;
 float x, y, z;
 POLY p1;
 POLY *pp;

 plgpos = ftell(in);		/* record for file rewind */

 if(!integrated)
  {
   maxx = maxy = maxz = -1e9;	/* initialize for object-by-object data */
   minx = miny = minz =  1e9;
   sumx = sumy = sumz =  0.0;
   abssumverts = 0;
  }
 nlines = 0;
 nameline = vtxline = polyline = -1;

 while(!feof(in))		/* read till name */
  {
   nameline = nlines++;
   fgets(line, 300, in);
   c=strchr(line,'#');
   if(c)
    {
     if(strstr(c,"#MULTI")) multi++;	/* detect multi-res type */
     *c = 0;
    }

   if(sscanf(line, "%s %d %d", plgname, &nverts, &npolys)==3) break;
  }
 if(feof(in))
  {
   nameline = -1;	/* EOF before new object */
   return 0;
  }

 overts = nverts;		/* process vertex count */
 opolys = npolys;
 if(integrated>=0) abssumverts += nverts;

 for(i=0;i<nverts;i++)  	/* read vertices */
  {
   while(1)
    {
     if(feof(in))
      {
       fprintf(stderr, "Early EOF in input file\n");
       fcloseall();
       exit(-1);
      }

     fgets(line, 300, in);	/* delete comments */
     nlines++;
     c=strchr(line,'#');
     if(c)
      {
       *c = 0;
      }

     j=sscanf(line, "%f %f %f", &x, &y, &z);	/* get vertex */
     if(j==0 || j==EOF) continue;
     if(j<3)
      {
       fprintf(stderr, "Syntax error on line %d of input file\n", nlines);
       fcloseall();
       exit(-1);
      }
     if(j==3) break;
    }
   if(vtxline<0) vtxline = nlines;
   v[i].x = x;  v[i].y = y; v[i].z = z;
   sumx += x;  sumy += y;  sumz += z;
   if(x>maxx) maxx = x;			/* box statistics */
   if(y>maxy) maxy = y;
   if(z>maxz) maxz = z;
   if(x<minx) minx = x;
   if(y<miny) miny = y;
   if(z<minz) minz = z;
  }

 for(i=0;i<npolys;i++)		/* read polygons */
  {
   while(1)
    {
     if(feof(in))
      {
       fprintf(stderr, "Early EOF in input file\n");
       fcloseall();
       exit(-1);
      }

     fgets(line, 300, in);
     nlines++;
     c=strchr(line,'#');	/* skip comments */
     if(c)
      {
       *c = 0;
      }

     c = strtok(line," \t");
     if(c==NULL || c[0]==0 || c[0]=='\n') continue;
     else break;
    }

   if(vtxline<0) vtxline = nlines;
   strcpy(p1.color, line);		/* color as string */
   c = strtok(NULL," \t");
   p1.nverts = atoi(c);
   if(p1.nverts<1)
    {
     fprintf(stderr, "Syntax error on line %d of input file\n", nlines);
     fcloseall();
     exit(-1);
    }
   if(p1.nverts>20)	/* max. 20 vertices for REND386 */
    {
     fprintf(stderr, "Too many vertices in poly on line %d of input file\n", nlines);
     fcloseall();
     exit(-1);
    }
   for (j = 0; j < p1.nverts; ++j)	/* read vertex indices */
    {
     c = strtok(NULL," \t");
     k = atoi(c);
     if(k<0 || k>nverts)
      {
       fprintf(stderr, "Bad vertex number on line %d of input file\n", nlines);
       fcloseall();
       exit(-1);
      }
     p1.vtx[j] = k;
     pp = (POLY *) calloc(sizeof(POLY), 1);
     if(!pp)
      {
       fprintf(stderr, "Out of memory at line %d of input file\n", nlines);
       fcloseall();
       exit(-1);
      }
     memcpy(pp, &p1, sizeof(POLY));	/* store new poly */
     p[i] = pp;
    }
  }
 return 1;
}


char *trcomments(char * line)	/* extract comments from line */
{
 char *c;		/* c == line if nothing but comments or blank */

 c=strchr(line,'#');
 if (!c) c = line+strlen(line);
 while(c>line && isspace(*(c-1))) c--;	/* include leading space */
 return c;
}


write_plg()     /* writes PLG file, tries to preserve comments */
{
 int i,j,k, ln;
 int vtxn, plyn;
 char *c;
 char lbuff[300];

 fseek(in, plgpos, SEEK_SET);	/* rewind to get PLG comments */

 for(ln=0;ln<nameline;ln++)	/* copy leading comments */
  {
   fgets(line, 300, in);
   fputs(trcomments(line), out);
  }

 k = sprintf(lbuff,"%s %d %d",     /* name line with comments */
	   plgname, nverts, npolys);
 fgets(line, 300, in);
 ln++;
 c=strchr(line,'#');
 strcpy(lbuff+k, trcomments(line));
 fputs(lbuff, out);

 for(;ln<vtxline-1;ln++)	/* lines to start of vertices */
  {
   fgets(line, 300, in);
   fputs(trcomments(line), out);
  }

 vtxn = 0;
 for(i=0;i<overts;i++)     /* lines containing vertices */
  {
   while(1)
    {
     fgets(line, 300, in);
     ln++;
     if(trcomments(line) == line)
      {
       fputs(trcomments(line), out);
       continue;	/* blank/comment line */
      }
     else break;
    }
   if(v[i].x == DEL)	/* maark vertices deleted by combining */
    {
     if(!renverts) k = 0;
     else k = sprintf(lbuff, "# DELETED\t ");
    }
   else
    {
     if(maxx-minx>1 || maxy-miny>1 || maxz-minz>1)
      {
       if(fabs(v[i].x)<0.01) v[i].x = 0.0;   /* delete tiny numbers */
       if(fabs(v[i].y)<0.01) v[i].y = 0.0;   /* for better formatting */
       if(fabs(v[i].z)<0.01) v[i].z = 0.0;
      }
     if(!renverts)
       k = sprintf(lbuff,"% 6g % 6g % 6g ", v[i].x, v[i].y, v[i].z);
     else
       k = sprintf(lbuff,"% 6g % 6g % 6g\t #VTX %d\t ", v[i].x, v[i].y, v[i].z, vtxn);

     if(vtxn != i)	/* renumber poly vertices too */
      {                 /* after recombination */
       int j,k;
       for(j=0;j<opolys;j++)
	{
	 if(p[j]==NULL) continue;
	 for(k=0;k<p[j]->nverts;k++)
	   if(p[j]->vtx[k]==i) p[j]->vtx[k] = vtxn;
	}
      }
     vtxn++;
    }
   strcpy(lbuff+k, trcomments(line));	/* add comments to vertex line */
   fputs(lbuff, out);
  }

 for(;ln<polyline-1;ln++)	/* lines to start of polyss */
  {
   fgets(line, 300, in);
   fputs(trcomments(line), out);
  }

 for(i=0;i<opolys;i++)     /* lines containing polys */
  {
   while(1)
    {
     fgets(line, 300, in);
     ln++;
     if(trcomments(line) == line)
      {
       fputs(trcomments(line), out);
       continue;	/* blank/comment line */
      }
     else break;
    }
   if(p[i] == NULL)
    {
     k = sprintf(lbuff, "# DELETED ");	/* mark deleted polys */
    }
   else
    {
     k = sprintf(lbuff,"%s % 3d", p[i]->color, p[i]->nverts);
     for(j=0;j<p[i]->nverts;j++)
       k += sprintf(lbuff+k, "% 3d", p[i]->vtx[j]);
     free(p[i]);
    }
   strcpy(lbuff+k, trcomments(line));
   fputs(lbuff, out);
  }
}
		 /* ascii to color number for information */

unsigned convert_color(char *s, char **ptr)
{
 int hue, value;
 if (isdigit(*s)) return (unsigned) strtoul(s, ptr, 0);
 if (ptr) for (*ptr = s; isalnum(**ptr) || **ptr == '_'; ++*ptr);
 if (!strnicmp(s, "shaded", 6))
  {
   sscanf(s, "shaded_%d_%d", &hue, &value);
   return 0x1000 | ((hue & 0x0F) << 8) | (value & 0xFF);
  }
 else if (!strnicmp(s, "metal", 5))
  {
   sscanf(s, "metal_%d_%d", &hue, &value);
   return 0x2000 | ((hue & 0x0F) << 8) | ((value & 0x1F) << 3);
  }
 else if (!strnicmp(s, "glass", 5))
  {
   sscanf(s, "glass_%d_%d", &hue, &value);
   return 0x3000 | ((hue & 0x0F) << 8) | ((value & 0x1F) << 3);
  }
 return 0;
}


print_info()	/* info on poly object */
{
 int i;
 unsigned c;
 int hasabs = 0;
 int hasstd = 0;
 int hasmap = 0;

 if(multi) printf("PLG file type: MULTI resolution\n");
 printf("PLG file name: \t%s\n", fin);
 printf("PLG object name: \t%s\n", plgname);
 printf("Vertices: \t%d\n", nverts);
 printf("Polygons: \t%d\n", npolys);

 for(i=0;i<npolys;i++)
  {
   c = convert_color(p[i]->color, NULL);
   if(c & 0x8000)
    {
     if((c&0x0FFF)>hasmap) hasmap = c & 0x0FFF;
    }
   else if ((c&0xFF00)==0) hasabs++;
   else hasstd++;
  }

 printf("Color types: \n");
 if(hasabs) printf("\tDirect palette mapped colors\n");
 if(hasstd) printf("\tCosine lit, glass, metal types\n");
 if(hasmap) printf("\tSurface mapped, 1 to %d\n", hasmap);

 printf("Bounding box: (%g, %g, %g) - (%g, %g, %g)\n",
   minx, miny, minz, maxx, maxy, maxz);
 printf("Centered at: (%g, %g, %g)\n", (maxx+minx)/2.0,
		      (maxy+miny)/2.0,(maxz+minz)/2.0  );
 printf("Size: (%g, %g, %g)\n", maxx-minx, maxy-miny,maxz-minz );
 printf("\n");
}


reverse_order()   /* reverse order of all poly vertex lists */
{
 int i, j, k, n;

 for(i=0;i<npolys;i++)
  {
   n =p[i]->nverts;
   for(j=0;j<n/2;j++)
    {
     k = p[i]->vtx[j];
     k = p[i]->vtx[j] = p[i]->vtx[n-j-1];
     p[i]->vtx[n-j-1] = k;
    }
  }
}


mmult(float A, float B, float C,	/* matrix to vertex apply */
      float D, float E, float F,
      float G, float H, float I,
      float *x, float *y, float *z)
{
 float xx = *x, yy= *y, zz = *z;

 *x = A*xx + B*yy + C*zz;
 *y = D*xx + E*yy + F*zz;
 *z = G*xx + H*yy + I*zz;
}


process_plg()		/* pocess all polys in object */
{
 int i, j, k;

 float ox, oy, oz;
 float snx, csx, sny, csy, snz, csz;
 float cx, cy, cz;

 if (reverse) reverse_order();	/* reverse visibility */

 if(gcenter)	/* center of gravity */
  {
   cx = sumx/abssumverts;
   cy = sumy/abssumverts;
   cz = sumz/abssumverts;
  }
 else
  {
   cx = (maxx+minx)/2.0;	/* box center */
   cy = (maxy+miny)/2.0;
   cz = (maxz+minz)/2.0;
  }

 if(centerxz || centery || ground)   /* precenter or shift vertices */
   for(i=0;i<nverts;i++)
    {
     v[i].x -= cx;
     v[i].z -= cz;
     if(centery) v[i].y -= cy;
     if(ground)  v[i].y -= miny;
    }

 if(rx+ry+rz > 0.0001)		/* rotation */
  {
   float x,y,z;

   snx = sin(rx/57.296);	/* precompute for speed */
   csx = cos(rx/57.296);
   sny = sin(ry/57.296);
   csy = cos(ry/57.296);
   snz = sin(rz/57.296);
   csz = cos(rz/57.296);

   for(i=0;i<nverts;i++)
    {
     x = v[i].x;
     y = v[i].y;               /* rotate in Y, X, Z order */
     z = v[i].z;
     mmult(csy, 0, sny, 0, 1, 0, -sny, 0, csy, &x, &y, &z);
     mmult(1, 0, 0, 0, csx, -snx, 0, snx, csx, &x, &y, &z);
     mmult(csz, -snz, 0, snz, csz, 0, 0, 0, 1, &x, &y, &z);
     v[i].x = x;
     v[i].y = y;
     v[i].z = z;
    }
  }

 if(bx)     /* compute box scaling */
  {
   if(maxx-minx>0.0001) sx = bx/(maxx-minx); else sx = 1.0;
   if(maxy-miny>0.0001) sy = by/(maxy-miny); else sy = 1.0;
   if(maxz-minz>0.0001) sz = bz/(maxz-minz); else sz = 1.0;
  }

 if(sx!=1.0 || sy!=1.0 || sz!=1.0)   /* scale object */
   for(i=0;i<nverts;i++)
    {
     v[i].x *= sx;
     v[i].y *= sy;
     v[i].z *= sz;
    }

 if(tx || ty || tz)   /* translate object */
   for(i=0;i<nverts;i++)
    {
     v[i].x += tx;
     v[i].y += ty;
     v[i].z += tz;
    }

 if(whole)   /* integerize object */
   for(i=0;i<nverts;i++)
    {
     v[i].x = floor(v[i].x);
     v[i].y = floor(v[i].y);
     v[i].z = floor(v[i].z);
    }

 if(clim>0.0)               /* delete duplicte vertices */
  {
   int nvtx = nverts;
   float x,y,z;

   for(i=0;i<nverts;i++) vmap[i] = -1;

   for(i=0;i<nverts;i++)
    {
     if(v[i].x == DEL) continue;
     x = v[i].x;
     y = v[i].y;
     z = v[i].z;

     for(j=i+1;j<nverts;j++)   /* duplicate test */
      {
       if ( v[j].x == DEL) continue;
       if ( fabs(x-v[j].x)<clim &&
	    fabs(y-v[j].y)<clim &&
	    fabs(z-v[j].z)<clim   )
	     {
	      v[j].x = DEL;
	      vmap[j] = i;
	      nvtx--;
	     }
      }
    }
   nverts = nvtx;

   if(nverts != overts)
     for(i=0;i<npolys;i++)    /* update polygons */
      {
       if(p[i]==NULL) continue;
       for(j=0;j<p[i]->nverts;j++)
	 if((k=vmap[p[i]->vtx[j]])>=0) p[i]->vtx[j] = k;
      }
  }
}


syntax()
{
 fprintf(stderr,"\n");
 fprintf(stderr,"\n");
 fprintf(stderr,"\n");
 fprintf(stderr,"\n");
 fprintf(stderr,"\n");
 fprintf(stderr,"\n");
 fprintf(stderr,"\n");
 fprintf(stderr,"\n");
 fprintf(stderr,"\n");
}


int add_extension(char *fname, char *ext)
{
 int i,j;

 if(fname[0] == 0) return(-1);	     /* error: no string */
 for(i=0;i<70;i++)
  {
   if(fname[i] == '.') return(1);    /* already has valid extension */
   if(fname[i] == 0)
    {
     fname[i] = '.';                 /* add default extension */
     fname[i+1] = ext[0];
     fname[i+2] = ext[1];
     fname[i+3] = ext[2];
     fname[i+4] = 0;
     return(0);
    }
  }
 return(-1);			/* error: string too long */
}


int obj = 0;

void main(int argc, char *argv[])
{
 int i,c;

 if(argc<2) syntax();

 for (i = 1; i < argc; ++i)
  {
   if (argv[i][0] == '/' || argv[i][0] == '-')
    {
     switch(toupper(argv[i][1]))
      {
       case 'C':/* center overall */
		centerxz = 1;
		centery = 1;
		break;
       case 'G':/* ground and center */
		ground  = 1;
		centerxz = 1;
		centery  = 0;
		break;
       case 'I':/* information on object */
		info = 1;
		break;
       case 'F':/* reverse vertex order */
		reverse = 1;
		break;
       case 'N':/* renumber vertices in comments */
		renverts = 1;
		break;
       case 'W':/* integer (whole) numbers only */
		whole = 1;
		break;
       case 'Y':/* all objects in file are one for size/center */
		integrated = 1;
		break;
       case 'Z':/* avg. center */
		gcenter = 1;
		break;
       case '?':/* syntax */
		syntax();
		exit(0);
		break;

       case 'S':/* scale PLG */
		c=sscanf(argv[++i],"%f,%f,%f",&sx,&sy,&sz);
		if (c<3) sy = sz = sx;
/*		if(sx<0 || sy<0 || sz<0)
		 {
		  fprintf(stderr, "Negative scaling not allowed: will cause visibility errors\n");
		  fprintf(stderr, "Please use rotation instead\n");
		  exit(-1);
		 } */
		break;
       case 'T':/* translate PLG */
		c=sscanf(argv[++i],"%f,%f,%f",&tx,&ty,&tz);
		break;
       case 'R':/* rotate PLG */
		c=sscanf(argv[++i],"%f,%f,%f",&rx,&ry,&rz);
		break;
       case 'B':/* abs box size PLG */
		c=sscanf(argv[++i],"%f,%f,%f",&bx,&by,&bz);
		if (c<3) by = bz = bx;
		break;

       case 'O':/* object in file to process */
		obj = 1;
		if(isdigit(argv[i+1][0]))
		   c=sscanf(argv[++i],"%d",&obj);
		break;
       case 'V':/* vertex recombine */
		clim = 0.0001;
		if(isdigit(argv[i+1][0]))
		   c=sscanf(argv[++i],"%f",&clim);
		break;
       case 'D':/* default size box */
		{
		 float ds = 1000.0;
		 if(isdigit(argv[i+1][0]))
		     c=sscanf(argv[++i],"%f",&ds);
		 bx = by = bz = ds;
		}
		break;
      }
    }
   else
    {
     if(!fin[0]) strcpy(fin,argv[i]);      /* copy in, out filename */
     else        strcpy(fout,argv[i]);
    }
  }
 if(fin[0]==0 || fout[0]==0) syntax();
 add_extension(fin, "plg");
 add_extension(fout, "plg");
 if((in=fopen(fin,"r"))==NULL)
  {
   fprintf(stderr, "Can't open %s for input.\n", fin);
   exit(-1);
  }
 if(fout[0])
  if((out=fopen(fout,"w"))==NULL)
    {
     fprintf(stderr, "Can't open %s for output.\n", fout);
     exit(-1);
    }

 maxx = maxy = maxz = -1e9;
 minx = miny = minz =  1e9;
 sumx = sumy = sumz =  0.0;
 abssumverts = 0;

 i = 0;

 if(integrated)
  {
   while(!feof(in))
    {
     read_plg();
     if(nameline<0) break;
    }
   fseek(in,0,0);
   integrated = -1;
  }

 while(!feof(in))
  {
   i++;
   read_plg();
   if(nameline<0) break;
   if(info) print_info();
   if(obj==0 || obj == i) process_plg();
   if(fout[0]) write_plg();
  }
 fcloseall();
 fprintf(stderr, "Sucessful completion.\n");
 exit(0);


}
