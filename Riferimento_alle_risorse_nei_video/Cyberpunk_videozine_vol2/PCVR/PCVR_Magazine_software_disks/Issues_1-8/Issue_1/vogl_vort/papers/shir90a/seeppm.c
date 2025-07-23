#include <stdio.h>
#include <gl/gl.h>

main(argc, argv)
int argc;
char** argv;
{
    char p6[10];
    int nx, ny;
    int num;
    int i, j;
    unsigned char c;
    int ic;
    unsigned long pix[1000000];
    unsigned int sec;
    FILE* picfile;
    int scale;


    if (argc != 4)
    {
	fprintf(stderr, "usage: %s filename zoom time\n", argv[0]);
        exit(1);
    }
    picfile = fopen(argv[1], "r");
    scale = atoi(argv[2]);
    sec = atoi(argv[3]);

   fscanf(picfile, "%s%d%d%d",p6, &nx, &ny, &num); 
   printf("%s\n%d %d\n%d\n", p6, nx, ny, num);
   getc(picfile);
   for (j = ny-1; j >= 0; j--)
      for (i = 0; i < nx; i++)
   {
       c = getc(picfile);
       ic = (int) c;
       pix[j*nx + i] = ic;
       c = getc(picfile);
       ic = (int) c;
       pix[j*nx + i] += ic*256;
       c = getc(picfile);
       ic = (int) c;
       pix[j*nx + i]  += 256*256*ic;
   }
   prefsize(scale*nx, scale*ny);
   winopen(argv[1]);
   RGBmode();
   gconfig();
   rectzoom((float) scale,(float) scale);
   lrectwrite(0, 0, nx-1, ny-1, pix);
    
sleep(sec);
    gexit();
    return 0;
}

