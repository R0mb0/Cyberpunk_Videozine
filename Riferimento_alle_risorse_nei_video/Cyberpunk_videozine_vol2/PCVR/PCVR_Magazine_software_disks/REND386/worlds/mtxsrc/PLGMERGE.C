/*  PLG file processing package
/*  by Dave Stampe 13/5/93
/*
/*  PLGMERGE.EXE
/*
/*  merges all PLGs in a file-- run PLGX to clean up
*/

#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int nlines;             /* total lines in PLG file */
int nameline;           /* original file line numbers of PLG */
int vtxline;            /* sections: so comments will be in  */
int polyline;           /* the right places */

char fin[80] = "";      /* in, out filennames */
char fout[80] = "";

FILE *in, *out;

char tvtxn[] = "tmpvtx.";
char tplyn[] = "tmpplg.";

FILE *tvtx, *tply;
int vtxlne, plylne;	/* lines in temp files */

char plgname[100];      /* PLG object name */

int nverts, npolys;     /* old, new vertex counts to/from processing */

int verts_in_file = 0;
int verts_base = 0;
int total_polys = 0;
int total_vertices = 0;

char line[300];		/* line from PLG file */
char oline[300];


read_name()   /* reads PLG till name found */
{
 int i,j,k;
 char *c;

 while(!feof(in))		/* read till name */
  {
   fgets(line, 300, in);

   if(feof(in)) return;	/* EOF before new object */

   if(sscanf(line, "%s %d %d", plgname, &nverts, &npolys)==3)
    if(strchr(plgname,'#')==NULL)	/* skip comments */
    {
     fputs("# Merged From: ", tvtx);
     fputs("# Merged From: ", tply);
     fputs(line, tvtx);
     fputs(line, tply);
     vtxlne++;
     plylne++;
     break;
    }
   fputs(line, tvtx);
   fputs(line, tply);
   vtxlne++;
   plylne++;
  }
}

read_vertices()	/* reads vertex secton of PLG object */
{
 int i,j,k;
 char *c;
 float x, y, z;

 verts_in_file = 0;

 while(nverts)
  {
   if(feof(in))
    {
     fprintf(stderr, "Early EOF in input file\n");
     fcloseall();
     exit(-1);
    }

   fgets(line, 300, in);	/* delete comments */
   j=sscanf(line, "%f %f %f", &x, &y, &z);	/* get vertex */
   if(j==3)
    {
     nverts--;           /* valid vertex count */
     verts_in_file++;
     total_vertices++;
    }
   fputs(line, tvtx);
   vtxlne++;
  }
}


read_polygons()	 /* reads polygons, renumbers verticess */
{
 int i,j,k;
 int nverts;
 char *c;
 char color[200];
 char *trcomment;
 char outline[200];
 char tc[20];

 for(i=0;i<npolys;i++)		/* read polygons */
  {
   while(1)      /* skip till valid poly line */
    {
     if(feof(in))
      {
       fprintf(stderr, "Early EOF in input file\n");
       fcloseall();
       exit(-1);
      }

     trcomment = NULL;

     fgets(line, 300, in);
     strcpy(oline,line);

     c=strchr(line,'#');	/* skip comments */
     if(c)
      {
       trcomment = c;
       *c = 0;
      }

     c = strtok(line," \t");
     if(c==NULL || c[0]==0 || c[0]=='\n')
      {
       fputs(oline,tply);
       plylne++;
      }
     else break;
    }

   strcpy(outline,c);

   c = strtok(NULL," \t");
   nverts = atoi(c);
   sprintf(outline+strlen(outline)," %d", nverts);
   if(nverts<1)
    {
     fprintf(stderr, "Syntax error on line %d of input file\n", nlines);
     fcloseall();
     exit(-1);
    }
   if(nverts>20)	/* max. 20 vertices for REND386 */
    {
     fprintf(stderr, "Too many vertices in poly on line %d of input file\n", nlines);
     fcloseall();
     exit(-1);
    }
   for (j = 0; j < nverts; ++j)	/* read vertex indices */
    {
     c = strtok(NULL," \t");
     k = atoi(c);
     if(k<0)
      {
       fprintf(stderr, "Bad vertex number on line %d of input file\n", nlines);
       fcloseall();
       exit(-1);
      }
     sprintf(outline+strlen(outline)," %d", k + verts_base);
    }
   if(trcomment) sprintf(outline+strlen(outline), " #%s", trcomment);
   else sprintf(outline+strlen(outline),"\n");

   fputs(outline,tply);
   plylne++;
   total_polys++;
  }
 return 1;
}



write_output()     /* writes PLG file, using temps */
{
 int i,j,k, ln;
 char lbuff[300];

 fprintf(out,"%s %d %d\n",     /* name line with comments */
	   plgname, total_vertices, total_polys);
 for(i=0;i<vtxlne;i++)
  {
   fgets(line, 300, tvtx);
   fputs(line, out);
  }
 for(i=0;i<plylne;i++)
  {
   fgets(line, 300, tply);
   fputs(line, out);
  }
}


syntax()
{
 fprintf(stderr,"PLGMERGE.EXE PLG file processor (c) 1993 by Dave STampe\n");
 fprintf(stderr,"USE: PLGMERGE <infile> <outfile>\n");
 fprintf(stderr,"  Merges all PLG objects in <infile> into one object.\n");
 fprintf(stderr,"  Preserves comments. Will write output to <infile> if\n");
 fprintf(stderr,"  <outfile is not supplied.  Will replace $ in <outfile>\n");
 fprintf(stderr,"  with <infile> for use with batch files.\n");
 fprintf(stderr,"  Run PLGX /I /V /N to clean up duplicate vertices later.\n");
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

 if(argc<2)
  {
   syntax();
   exit(-1);
  }

 for (i = 1; i < argc; i++)
  {
   if(fin[0]=='\0') strcpy(fin,argv[i]);      /* copy in, out filename */
   else        strcpy(fout,argv[i]);
  }

 if(fin[0]==0 && fout[0]==0) syntax();

 if(strchr(fout, '$'))	/* '$' in out name replaced by in name */
  {
   char t[100];
   char *p = strchr(fout, '$');
   *p++ = 0;
   strcpy(t, fout);
   strcat(t, fin);
   strcat(t, p);
   strcpy(fout,t);
  }

 add_extension(fin, "plg");
 if(!fout[0]) strcpy(fout, fin);

 if((in=fopen(fin,"r"))==NULL)
  {
   fprintf(stderr, "Can't open %s for input.\n", fin);
   exit(-1);
  }

 if((tvtx=fopen(tvtxn,"w"))==NULL)
  {
   fprintf(stderr, "Can't open %s for output.\n", tvtxn);
   exit(-1);
  }
 vtxlne = 0;

 if((tply=fopen(tplyn,"w"))==NULL)
  {
   fprintf(stderr, "Can't open %s for output.\n", tplyn);
   exit(-1);
  }
 plylne = 0;

 verts_base = 0;
 total_polys = 0;
 total_vertices = 0;

 while(!feof(in))
  {
   read_name();
   if(feof(in)) break;
   read_vertices();
   fprintf(tvtx,"\n");
   vtxlne++;
   read_polygons();
   fprintf(tply,"\n");
   plylne++;
   verts_base += verts_in_file;
  }

 fclose(in);
 fclose(tvtx);
 fclose(tply);

 if((tvtx=fopen(tvtxn,"r"))==NULL)
  {
   fprintf(stderr, "Can't open %s for input.\n", tvtxn);
   exit(-1);
  }

 if((tply=fopen(tplyn,"r"))==NULL)
  {
   fprintf(stderr, "Can't open %s for input.\n", tplyn);
   exit(-1);
  }

 if(fout[0])
  if((out=fopen(fout,"w"))==NULL)
    {
     fprintf(stderr, "Can't open %s for output.\n", fout);
     exit(-1);
    }


 write_output();
 fcloseall();
 fprintf(stderr, "Sucessful completion.\n");
 exit(0);
}
