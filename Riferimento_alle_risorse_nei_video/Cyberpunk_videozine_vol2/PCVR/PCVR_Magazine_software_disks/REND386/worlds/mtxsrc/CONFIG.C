#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <string.h>

FILE *devfile, *outfile, *batfile, *cfgfile, *lastfile, *datfile;
long configpos;

char videoname[40] = "vdx256.rvd";
char videonum [40] = "";
char deffiles [180] = "";

char batname[40] = "test.bat";
char cfgname[40] = "test.cfg";

int vcount = 0;
int scount = 0;
char stag[36];
char *vcompat[36];
char *vdefname[36];
char vtag[36];
char *vdescr[36];
char *sdescr[36];

char buff[256];
char *vsslines[50];
int nvss = 0;
int vidline = -1;

int lastvid = 0;
int lastst  = 0;
int vidloaded = 0;
int changed = 0;


#define TEXT   0
#define BLANK -1
#define BEGIN  1
#define END    2
#define VTYPE  3
#define STYPE  4
#define CONFIG 5
#define TYPE   6

int getbuff(FILE *f)    /* get line from data file, parse sections */
{
 int i;
 char *p;

 fgets(buff, 256, f);
 if(buff[0] == 0 || buff[0]=='\n') return BLANK;
 if(buff[0] != '@') return TEXT;
 p = strtok(buff, "@ \t\n");
 if(!strnicmp(p, "BEG", 3)) return BEGIN;
 if(!strnicmp(p, "end", 3)) return END;
 if(!strnicmp(p, "VID", 3)) return VTYPE;
 if(!strnicmp(p, "STE", 3)) return STYPE;
 if(!strnicmp(p, "CON", 3)) return CONFIG;
 if(!strnicmp(p, "TYP", 3)) return TYPE;
 return TEXT;
}


void add_default()
{
 printf("\n\nAdd default files and options to REND386 command line:\n");
 printf("Add any number of files {.WLD .FIG .PLG} seperated by spaces\n");
 printf("and/or any of these options (more documented elsewhere):\n");
 printf("-m Microsoft mouse disabled    -g Enable PowerGlove driver\n");
 printf("-r Reverse eyes on Sega driver -x Enable Sega driver\n");
 printf("-1 Force Sega to use COM1      -2 Force Sega to use COM2\n");
 printf("-b Forces monochrome colors\n");
 printf("\nEnter new command line: ");
 while(kbhit()) getch();
 fflush(stdin);
 fgets(deffiles,120,stdin);
 deffiles[strlen(deffiles)-1] = 0;
}


int get_vconfig()       /* read in all text groups that match, return 1 if error */
{
 int i,j;
 char *tag;

 if(!strchr(vcompat[lastvid], stag[lastst]))
  {
   printf("\n Incompatible video driver and stereo configuration selected!");
   delay(1500);
   return(1);
  }
 for(i=0;i<50;i++)
   if (vsslines[i])
    {
     free(vsslines[i]);
     vsslines[i] = NULL;
    }
 vidline = -1;
 nvss = 0;
 i = 0;

 fseek(datfile, configpos, SEEK_SET);
readnext:
 while(!feof(datfile))
  {
   while(!feof(datfile) && getbuff(datfile)!=TYPE);
   if(!feof(datfile))
    {
     tag = strtok(NULL, " \n\t");
     if(!tag) continue;
     if(!strchr(tag, vtag[lastvid])) continue;  /* check both exist in tag */
     if(!strchr(tag, stag[lastst ])) continue;
     else goto got_it;
    }
  }
 if(feof(datfile)) return (i==0);

got_it:
 while(getbuff(datfile)!=BEGIN && !feof(datfile));
 if(feof(datfile))
  {
   printf("\nError reading data file CFGDATA.DAT\n");
   exit(0);
  }

 while(1)
  {
   if(feof(datfile)) break;
   j = getbuff(datfile);
   if(j==BLANK) vsslines[i] = strdup("");
   else if (j!=TEXT) break;
   else
    {
     vsslines[i] = strdup(buff);
     if(!strnicmp(buff,"videodev", 8)) vidline = i;
    }
   i++;
   if(i>49) return 0;
  }
 goto readnext;
}


void modify_video()
{
 int i;
 char a[40], b[80];
 char x[100];

 if(get_vconfig()) return;
 if(vidline<0) return;
 sscanf(vsslines[vidline], "%s %[^\n]", a, b);
 printf("\n Video driver and mode set line: %s", b);
 printf("\n Old: %s", b);
 printf("\n New: ");
 scanf("%[^\n]", b);
 sprintf(x, "%s %s\n", a, b);
 free(vsslines[vidline]);
 vsslines[vidline] = strdup(x);
 vidloaded = 1;
}


int getmenu(char *str[], int n, int video)
{
 int i,j,k;
 char c[] = "A) ";

 for(i=0;i<n;i++)
  {
   if(video) k = (strchr(vcompat[i], stag[lastst]))  ? LIGHTGRAY : BLUE ;
   else      k = (strchr(vcompat[lastvid], stag[i])) ? LIGHTGRAY : BLUE ;
   textcolor(k);
   gotoxy( (i&1)?40:1, (i/2)+6 );
   c[0] = (i<9) ? i+'1' : i+'A'-9;
   if(video) c[2] = (i==lastvid) ? '*' : ' ' ;
   else      c[2] = (i==lastst)  ? '*' : ' ' ;
   if(strlen(str[i])>37) str[i][37] = 0;
   cprintf("%s%s", c, str[i]);
  }
 textcolor(LIGHTGRAY);
retry:
 i = toupper(getch());
 if(i==27) return -1;
 i = (i<'A') ? i-'1' : i -'A'+9;
 if(i<0 || i>n) goto retry;
 return i;
}


void select_video()
{
 int i;

 clrscr();
 printf("\n     		        VIDEO DRIVERS");
 printf("\n      		   ----------------------");
 printf("\n  Colored entries are incompatible with currently selected stereo mode\n");
 i = getmenu(vdescr, vcount, 1);
 if(i>=0)
  {
   lastvid = i;
   vidloaded = 0;
   changed = 0;
  }
}

void select_stereo()
{
 int i;

 clrscr();
 printf("\n     		        STEREO MODES");
 printf("\n      		   ----------------------");
 printf("\n  Colored entries are incompatible with currently selected video driver\n");
 i = getmenu(sdescr, scount, 0);
 if(i>=0)
  {
   lastst = i;
   vidloaded = 0;
  }
}


void add_ext(char *name, char *ext)
{
 char *c;
 if(strchr(name, '.')) return;
 c = strchr(name, 0);
 *c++ = '.';
 *c++ = *ext++;
 *c++ = *ext++;
 *c++ = *ext++;
 *c = 0;
}


int set_filenames()  /* returns 1 if to write */
{
 int i,j;

 if(!changed)
  {
   if(vdefname[lastvid][0])
    {
     strcpy(batname, vdefname[lastvid]);
     strcpy(cfgname, vdefname[lastvid]);
     add_ext(batname, "bat");
     add_ext(cfgname, "cfg");
     strupr(batname);
     strupr(cfgname);
    }
   else
    {
     strcpy(batname, "REND.BAT");
     strcpy(cfgname, "REND.CFG");
    }
  }

main_menu:
 clrscr();
 gotoxy(1,5);
 printf(" 		        SAVE, SET FILENAMES:\n");
 printf("        	        ---------------------------\n");
 printf("   		        1) Save REND386.CFG only\n");
 printf("   		        2) Save files %s, %s\n", batname, cfgname);
 printf("   		        3) Change .BAT Name\n");
 printf("   		        4) Change .CFG Name \n");
 printf("   		        5) Change both .BAT and .CFG\n");
 printf("   		        6) Return to Main Menu\n");

 i = getch();
 if(i==27) exit(0);
 if(i<'1' || i>'6') goto main_menu;
 switch(i)
  {
   case '1':
     strcpy(cfgname, "REND386.CFG");
     batname[0] = 0;
   case '2':
     return 1;
   case '3':
     printf("\nEnter new .BAT filename: ");
     scanf("%s", batname);
     add_ext(batname, "bat");
     strupr(batname);
     changed = 1;
     break;
   case '4':
     printf("\nEnter new .CFG filename: ");
     scanf("%s", cfgname);
     add_ext (cfgname, "cfg");
     strupr(cfgname);
     changed = 1;
     break;
   case '5':
     printf("\nEnter new filename for both .BAT and .CFG: ");
     scanf("%s", batname);
     strcpy(cfgname, batname);
     add_ext(batname, "bat");
     strupr(batname);
     add_ext(cfgname, "cfg");
     strupr(cfgname);
     changed = 1;
     break;
   case '6': return 0;
   default: break;
  }
 goto main_menu;
}


void write_files()
{
 int i,j;
 char line[256];

 if(vidloaded==0)
  if(get_vconfig()) return;

 if(set_filenames()==0) return;

 if(batname[0]!=0 && batname[0] != '.')
  {
   batfile = fopen(batname, "w");
   if(!batfile)
    {
     printf("\nCannot create batch file %s\n", batname);
     delay(1500);
     return;
    }
   fprintf(batfile, "rend386 /c %s %s %1 %2 %3 %4 %5 %6 \n", cfgname, deffiles);
   fclose(batfile);
  }
 printf("\nBatch file %s sucessfully created\n", batname);

 cfgfile = fopen(cfgname, "w");
 if(!cfgfile)
  {
   printf("\nCannot create configuration file %s\n", cfgname);
   delay(1500);
   return;
  }

 fprintf(cfgfile, "\n# Video and Stereo mode set by Config:");
 fprintf(cfgfile, "\n# Video Driver = %s", vdescr[lastvid]);
 fprintf(cfgfile, "\n# Stereo Mode =  %s\n", sdescr[lastst]);

 fprintf(cfgfile, "\n\ninclude devices.cfg   # devices control\n\n");

 for(i=0;i<50;i++)
   if(vsslines[i]) fprintf(cfgfile, "%s", vsslines[i]);

 fclose(cfgfile);
 printf("\nConfiguration file %s sucessfully created\n", cfgname);
 delay(1000);

 lastfile = fopen("lastcfg.dat", "w");
 if(lastfile)
  {
   fprintf(lastfile,"%d %d %s", lastvid, lastst, deffiles);
   fclose(lastfile);
  }
}


main()
{
 int i,j,k;
 char *c;

 for(i=0;i<50;i++) vsslines[i] = NULL;

 datfile = fopen("cfgdata.dat", "r");
 if(!datfile)
  {
   printf("\nCannot open data file CFGDATA.DAT\n");
   exit(0);
  }

 lastfile = fopen("lastcfg.dat", "r");
 if(lastfile)
  {
   fscanf(lastfile,"%d %d %[^\n]",
	  &lastvid, &lastst, deffiles);
   changed = 0;
   fclose(lastfile);
  }
 else
  {
   deffiles[0] = 0;
   lastvid = lastst = 0;
  }

 while(getbuff(datfile)!=STYPE && !feof(datfile));
 if(feof(datfile))
  {
   printf("\nError reading data file CFGDATA.DAT\n");
   exit(0);
  }

 while(!feof(datfile))
  {
   k = getbuff(datfile);
   if (k==BLANK) continue;
   if (k==END) break;
   if (k!=TEXT)
    {
     printf("\nError reading data file CFGDATA.DAT\n");
     exit(0);
    }
   stag[scount] = *(strtok(buff," \t,\n"));
   sdescr[scount++] = strdup(strtok(NULL, "\n"));
   if (scount>=20) break;
  }

 if(feof(datfile))
  {
   printf("\nError reading data file CFGDATA.DAT\n");
   exit(0);
  }
 while(getbuff(datfile)!=VTYPE && !feof(datfile));
 if(feof(datfile))
  {
   printf("\nError reading data file CFGDATA.DAT\n");
   exit(0);
  }

 while(!feof(datfile))
  {
   k = getbuff(datfile);
   if (k==BLANK) continue;
   if (k==END) break;
   if (k!=TEXT)
    {
     printf("\nError reading data file CFGDATA.DAT\n");
     exit(0);
    }
   vtag[vcount] = *(strtok(buff," \t,\n"));
   vcompat[vcount] = strdup(strtok(NULL," \t,\n"));
   vdefname[vcount] = strdup(strtok(NULL," \t,\n"));
   vdescr[vcount++] = strdup(strtok(NULL, "\n"));
   if (vcount>=36) break;
  }

 if(feof(datfile))
  {
   printf("\nError reading data file CFGDATA.DAT\n");
   exit(0);
  }
 while(getbuff(datfile)!=CONFIG && !feof(datfile));
 if(feof(datfile))
  {
   printf("\nError reading data file CFGDATA.DAT\n");
   exit(0);
  }

 configpos = ftell(datfile);

 if(lastvid >= vcount) lastvid = 0;
 if(lastst  >= scount) lastst  = 0;

main_menu:
 clrscr();
 gotoxy(1,5);
 printf(" 		        MAIN MENU\n");
 printf("        	        ---------------------------\n");
 printf("   		        1) Select Video Driver\n");
 printf("   		        2) Select Stereo Mode\n");
 printf("   		        3) Modify Video Driver\n");
 printf("   		        4) Default Files to Load\n");
 printf("   		        5) Write .CFG, .BAT Files\n");
 printf("   		        6) Quit\n");

 i = getch();
 if(i==27) exit(0);
 if(i<'1' || i>'6') goto main_menu;
 switch(i)
  {
   case '1': select_video();  break;
   case '2': select_stereo(); break;
   case '3': modify_video();  break;
   case '4': add_default();   break;
   case '5': write_files();   break;
   case '6': exit(0);
   default: break;
  }
 goto main_menu;
}







