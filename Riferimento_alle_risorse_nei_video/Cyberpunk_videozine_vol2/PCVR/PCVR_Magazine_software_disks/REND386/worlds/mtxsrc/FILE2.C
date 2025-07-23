// copyright (c) 1994
// programmed by:  Todd Porter

// This code is very dirty!!  I have not had any time to clean it up.  Please
// don't laugh its the best I could do right now!!

// These are the routines for reading the system data and creating the
// virtual representations.


#include <stdio.h>
#include <dir.h>
#include <dos.h>
#include <string.h>


struct ffblk ffblk;    //dir info structs

struct mystuct {             //this is in devel.
char dirname[13];
};

struct drive {
  int drivename;
  struct mystuct drive_dir[100];
};

struct drive drives[20];

int done, n = 99, count2=0, j, i;  //misc vars. needs to be better placed

int dirs_arry[30];      // holds # of dirs on each drive indexed in the array
			// ie 0=drive a:, 1=drive b: ...

int save, disk;        //more junk  I just havn't had time to clean up
int count, disks;
int q,total_drives=0;

char fname[10];
int disk_drive; //holds the filename


void write_wld(void)  //writes out the world file
{
  char *fname;
  int x=2200,y=0,z=2200,temp=0,temp2=0,dd=0;
  double result1,result,result2;
  FILE *wld_file;

  fname="matrix.wld";
  setdisk(save);
  if ((wld_file = fopen(fname,"w")) == NULL) {
    printf("Could not write the world file!\n");
    exit(1);
  }
  fprintf(wld_file,"# Your computer and data in the Matrix\n");
  fprintf(wld_file,"# copyright (c) 1994 Todd Porter\n");
  fprintf(wld_file,"# Programmed by:  Todd Porter\n\n\n");
  fprintf(wld_file,"worldscale 1.0\nhither     10\nyon        1000000\n");
  //fprintf(wld_file,"start 0,0,-10000 0,0,0 2\ngroundcolor 0\nskycolor 0\nscreenclear 1\n");
  fprintf(wld_file,"start 1528,1000,491 25,15,0 2\n");
  fprintf(wld_file,"skycolor 0\ngroundcolor 0\n\n");
  fprintf(wld_file,"ambient 76\n\n\n\nsurfacedef bmrimmed 0xae7f\nsurfacedef blrimmed 0xbeaf\n");
  fprintf(wld_file,"surfacedef gr       0xbdef\nsurfacedef purple   0xc1ea\n\n\n");
  fprintf(wld_file,"surfacemap system\nsurface 1 blrimmed\n\nsurfacemap drive\nsurface 1 gr\n\n");
  fprintf(wld_file,"surfacemap dir\nsurface 1 purple\n\n\n");
  fprintf(wld_file,"object grid   1,1,1   0,0,0 0,0,0 256 . fixed\n");
  fprintf(wld_file,"object matrix 1,1,1 -90,0,0 2500,0,2500 0 system fixed 0 System\n");

  // do the drive data objects
  // This code is all hard coded,  Will update to constants as time provides
  // It is also kinda scrambled and hard to follow.  Was in a hurry when I
  // made it - but it works!!!


  if (total_drives <= 9) {
    for(i=0;i<=total_drives+1;i++) {
      for(j=1;j<4;j++) {
	fprintf(wld_file,"object box    1,1,1   0,0,0    %d,%d,%d   256 drive fixed 0 %c:\\\n",x,y,z,drives[dd].drivename);
	i++;      //loosing last drive name when doing this.
	x+=250;
	dd++;
	if(i>=total_drives+1) break;
      }
      x=2200;
      z+=250;
      if(i>=total_drives) break;
    }
    }

  // do the directories for each drive
  // Real scrambled!!  Be careful in here!!!

  x=z=2205;
  temp=0;
  for(i=0;i<=total_drives;i++) {

   x=(2205+(250*temp));
   if(i>0) {
     result2=(i%3);
     if(result2==0) {
       x=2205;
       z=2205+(250*(i/3));
       temp2=(250*(i/3));          //added for z pos hold
       y=0;
       temp=0;
     }}
    for(j=1;j<=dirs_arry[i];j++) {       // was j=1
      fprintf(wld_file,"object pyr    1,1,1   0,0,0   %d,%d,%d 256 dir fixed 0 %c:\\%s\n",x,y,z,drives[i].drivename,drives[i].drive_dir[j].dirname);
      x+=20;

      result=j%5;
      result1=j%25;

      if(result==0 && result1 ==0) {
	x=(2205+(250*temp));
	z=2205+(temp2);      //added temp2 to keep z pos
	y+=20;
      }

      if(result==0 && result1 !=0) {
	x=(2205+(250*temp));
	z+=20;
      }

    }
    x=2205;
    if ((i%3)==0)
      z=2205+250*(i/3);
    temp++;
  }
 fclose(wld_file);
}



void setup_dir(void)
{
   // This is where it reads in all the directories from each drive.  I don't
   // know the right code to do this so I had to just search for all *. files
   // this is wrong and I would love to hear the correct way.


   done = findfirst("\\*.",&ffblk,FA_DIREC);
   while (!done)
   {

      count++;
      dirs_arry[disk]=count;

      printf("  %s\n", ffblk.ff_name);
      // drive_dir[count2].drive_number=disk;
      strcpy(drives[total_drives-1].drive_dir[count].dirname,ffblk.ff_name);
      count2++;
      done = findnext(&ffblk);
   }
   printf("There are %d directories on drive %d.\n\n",dirs_arry[disk],disk);
   count=0;
}


void create_matrix(void)
{


/****  Call this function to setup and write the MATRIX.WLD file ******/


   for(q=0;q<=30;q++)        // intitialize the arrays to 0
     dirs_arry[q]=0;


   // save original drive
   save = getdisk();

   // number of logical drives
   disks = setdisk(save);


  printf("%d logical drives on the system\n\n", disks);

  // get the drive letters available
   printf("Available drives:\n");
   for (disk = 0;disk < 15;++disk)
   {
      setdisk(disk);
      if (disk == getdisk()) {
	 printf("%c: drive is available\n", disk + 'a');
	 //itoa(disk+'a',disk_drive,10);
	 disk_drive=(disk+'a')-32;
	 drives[total_drives].drivename=disk_drive;
	 total_drives++;
	 if (((disk + 'a') != 'a') && ((disk + 'a') != 'b'))
	   setup_dir();
      }
   }
   printf("Total drives are %d\n\n",total_drives);
   write_wld();
   setdisk(save);
}
