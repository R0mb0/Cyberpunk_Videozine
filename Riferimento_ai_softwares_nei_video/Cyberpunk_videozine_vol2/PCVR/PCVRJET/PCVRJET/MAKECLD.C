#include <stdio.h>
#include <stdlib.h>

void main()
{

 int i;
 FILE *outfile;
 int     scalex, scaley, scalez,
     rotx=0, roty=0, rotz=0;
 long int   transx, transy, transz;

 outfile = fopen ( "jet.wld", "a" );

 randomize();
 for (i=0;i<100;i++)
 {

   scalex = random(2)+1;
   scaley = random(2)+1;
   scalez = random(2)+1;
   transx = (long)random(320);*/
   transy = 10;
   transz = (long)random(320);

   fprintf ( outfile, "object cloud %d %d %d %d %d %d %ld %ld %ld 768\n",
					scalex,
					scaley,
					scalez,
					rotx,
					roty,
					rotz,
					transx,
					transy,
					transz   );

   printf ( "object cloud %d %d %d %d %d %d %ld %ld %ld 768\n",
					scalex,
					scaley,
					scalez,
					rotx,
					roty,
					rotz,
					transx,
					transy,
					transz   );
 }

 fclose ( outfile );
}
