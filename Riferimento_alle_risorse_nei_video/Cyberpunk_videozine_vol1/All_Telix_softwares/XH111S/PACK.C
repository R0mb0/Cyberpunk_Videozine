// PACK.C      by Andras Pattantyus
// Utility program for XHost 1.0

// Functions: - delete flagged users
//            - delete expired and received messages
//            - trim message base to maximum size
//            - remove descriptions of inexistant files from file lists
//            - pack the user level file

#include <stdio.h>
#include <dir.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define REC_LEN 320
char FLIST[] = "FILES.LST";

char record[512];
char host_dir[64], telix_dir[64];
char tempfile[12] = "XH$$$.TMP";
FILE *file, *file2, *tmpf;
struct ffblk Ffblk;

struct confrec{
       char fill1[2];
       char status;
       char name[20];
       char path[45];
       char fill2[3];
       int maxmsgs;
       char maxdays;
       char fill3[6];
       } conf;

int newdir(const char *path);

void Pack_Users();
void Pack_Messages( int confn );
void Pack_Files();
void Pack_Levels();
void packf();

void main( int argc, char *argv[])
{

 if (strncmpi("/F", argv[1], 2) == 0 && argc == 3)
    {
    if (*(argv[1]+2) != '0')
      {
       strcpy(record, strupr(argv[2]));
       newdir(record);
       if (findfirst(FLIST, &Ffblk, 0) == 0)
           packf();
        }
    else
        {
        strcpy(host_dir, strupr(argv[2]));
        Pack_Files();
        }
    }
 else if (strncmpi("/M", argv[1], 2) == 0 && argc == 3)
    {
     strcpy(host_dir, strupr(argv[2]));
     Pack_Messages(atoi(argv[1]+2));
    }
 else if (strncmpi("/U", argv[1], 2) == 0 && argc == 3)
   {
   strcpy(telix_dir, strupr(argv[2]));
   Pack_Users();
   }
 else if (strncmpi("/L", argv[1], 2) == 0 && argc == 3)
   {
    strcpy(host_dir, strupr(argv[2]));
    Pack_Levels();
    }
 else if (argc !=3)
   {
    printf("\nInvalid command line.\nOptions are: /F filedir, /U telixdir, /L hostdir, /Mconf# hostdir.\n");
    return;
    }
 else
    {
     strcpy(telix_dir, strupr(argv[1]));
     strcpy(host_dir, strupr(argv[2]));
     Pack_Files();
     Pack_Messages(0);
     Pack_Users();
     Pack_Levels();
     }
}

void Pack_Levels( )
{
 long newpos;
 int x;
 newdir(host_dir);
 rename("LEVELS.DAT", tempfile);

 file = fopen(tempfile, "rb");
 file2 = fopen("LEVELS.DAT", "wb");

 memset(record, '\0', 320);

 fwrite(record, 320, 1, file2);  // write index to new file
 fwrite(record, 190, 1, file2);

 for (x = 1; x <= 255; ++x)
    {
    newpos = getw(file);
    if (newpos > 0)
       {
       fseek(file, newpos, SEEK_SET);
       fread(record, 37, 1, file);
       fseek(file2, 0L, SEEK_END);
       newpos = ftell(file2);
       fwrite(record, 37, 1, file2);
       fseek(file2, (x-1)*2, SEEK_SET);
       putw(newpos, file2);
       fseek(file, x*2, SEEK_SET);
       }
    }
 fclose(file);
 fclose(file2);
 unlink(tempfile);
}

void Pack_Messages( int confn )
{
// find all .IDX... Trim to max, remove msgs older than MaxDays.
// 30 days in seconds = 30*(24*(60*60)) = 2592000
//
char start, confnum;
long last, timedif, length;
FILE *datfile, *oldfile, *confdat;
char oldfname[12], *text;

struct msgrec{
       char status;                       int num;
       long date_time;
       long mstart;
       long mend;
       int ref;
       char to[26];
       char from[26];
       char subject[26];
       char fill[33];
       } line;

newdir(host_dir);

if ((confdat = fopen("CONFS.DAT", "rb")) != NULL)
    {
     confnum = 0;
     text = 0;
     if ((text = (char *) malloc(16384)) == NULL)
        {
         printf("Not enough memory to allocate buffer!\n");
         exit(1);  /* terminate program if out of memory */
        }
     while (fread(&conf, sizeof(struct confrec), 1, confdat) == 1)
          {
           ++confnum;
           if ((confn == 0 || confn == confnum) && conf.name)
              {
              strcpy(oldfname, "000");
              itoa(confnum, record, 10);
              strcpy(oldfname + 3 - strlen(record), record);
              strcat(oldfname, ".IDX");
              if (strlen(conf.path) == 0)
                 strncpy(conf.path, host_dir, 45);

              newdir(conf.path);

              if ((conf.status&1) && findfirst(oldfname, &Ffblk, 0) == 0)
                 {
                 file = fopen(oldfname, "rb");
	  // first check if it needs to be packed

// - Each message:
//   Status[1] Number_Chars[2] Date_Chars[4] Start_Chars[4] End_Chars[4]
//   Ref[2] To[26] From[26] Subject[26] reserved[33]

                 fseek(file, 128L, SEEK_SET);
	         fread(&line, sizeof(struct msgrec), 1, file);
	         last = line.num;
	         timedif = line.date_time;
	         fseek(file, -128L, SEEK_END);
	         fread(&line, sizeof(struct msgrec), 1, file);
	         last = line.num - last + 1;   // last now == # of messages
                 timedif = line.date_time - timedif;

	         fclose(file);
	         rename(oldfname, tempfile);
                 file2 = fopen(tempfile, "rb");
	         if (last > conf.maxmsgs && conf.maxmsgs > 0)
	             fseek(file2,(long) ((last-conf.maxmsgs)*128 + 128), SEEK_SET);
	         else                  // goto first message
	             fseek(file2, 128L, SEEK_SET);
	         file = fopen(oldfname, "wb");
                 fwrite(&line, sizeof(struct msgrec), 1, file); // header
	         oldfname[4] = '\0';
	         strcat(oldfname, "MSG");
                 oldfile = fopen(oldfname, "rb");
                 datfile = fopen("MSG.$", "wb");
                 start = 0;
                 while(fread(&line, sizeof(struct msgrec), 1, file2) == 1)
	            {
                    if (((time(NULL) - line.date_time > conf.maxdays*86400L)
                        && conf.maxdays > 0) || (line.status&2) ||
                        ((line.status&1) && (line.status&4)))
                        {
                        if (start) // if we have already written to file
                           {
                           line.mstart = 0;
                           line.mend = 0;
                           line.status = line.status | 2; // set deleted
                           }
                        else
                            continue;
                        }
                    fseek(oldfile, line.mstart, SEEK_SET);
                    length = line.mend - line.mstart;
                    start = 1;
                    if (length > 16384)
		       length = 16384;
		    fread(text, length, 1, oldfile);
		    line.mstart = ftell(datfile);
		    fwrite(text, length, 1, datfile);
		    line.mend = ftell(datfile);
		    fwrite(&line, sizeof(struct msgrec), 1, file);
		    }

                 fclose(oldfile);
	         fclose(datfile);
	         unlink(oldfname);
                 rename("MSG.$", oldfname);
	         fclose(file);
                 fclose(file2);
                 unlink(tempfile);
               }
             }
        }
    }
fclose(confdat);
free(text);
}

void Pack_Files( )
{
FILE *tmp1;
int confnum = 0, i;
struct ffblk ffblk2;
struct dirrec{
	char level;
	char flags;
	char name[30];
	char path[45];
	char endbyte;
	char CRLF[2];
	};

 struct dirrec dir;
 newdir(host_dir);

 if ((tmp1 = fopen("CONFS.DAT", "rb")) != NULL)
     {
     // get new rec, read
     while (fread(&conf, sizeof(struct confrec), 1, tmp1) == 1)
          {
          ++confnum;
          if (conf.name)
             {
              itoa(confnum, record, 10);
              i = strlen(record);
              strcpy(record, "000");
              itoa(confnum, record + 3 - i, 10);
              strcat(record, ".DIR");
              printf(record);
              if (strlen(conf.path) == 0)
                 strncpy(conf.path, host_dir, 45);

              newdir(conf.path);
	      file = fopen(record, "rb");
	      strset(record, '\0');
	      fread(record, 19, 1, file);

	      if (stricmp(record, "* xHost Data File *") == 0)
	         {
	         fseek(file, 317L, SEEK_SET);

	         while(fread(&dir, sizeof(struct dirrec), 1, file) > 0)
		    {
		     if (newdir(dir.path) == 0)
		        {
                         if (findfirst(FLIST, &ffblk2, 0) == 0)
                             packf();
                         }
       	             }
                  }
              fclose(file);
             }
         }
     }
 fclose(tmp1);
 }
void Pack_Users( )
{
  int read, c;
  newdir(telix_dir);
  rename("USERS.DAT", tempfile);

  file = fopen(tempfile, "rb");
  file2 = fopen("USERS.DAT", "wb");

  read = 0;

  while((c = fgetc(file)) >= 0)  // load names from file
    {
     read = ftell(file);
     if ((c&1) == 0)
        {
	 fread(record, REC_LEN-1, 1, file);
	 fputc(c, file2);
	 fwrite(record, REC_LEN-1, 1, file2);
	}
     else
        {
         ++read;
	 fseek(file, REC_LEN-1, SEEK_CUR);
	 }
     }
  fclose(file);
  fclose(file2);
  unlink(tempfile);
}
void Pack_Obj( )
{
  int read, c;

  rename("USERS.DAT", tempfile);

  file = fopen(tempfile, "rb");
  file2 = fopen("USERS.DAT", "wb");

  read = 0;

  while((c = fgetc(file)) >= 0)  // load names from file
    {
     read = ftell(file);
     if ((c&1) == 0)
        {
	 fread(record, REC_LEN-1, 1, file);
	 fputc(c, file2);
	 fwrite(record, REC_LEN-1, 1, file2);
	}
     else
        {
         ++read;
	 fseek(file, REC_LEN-1, SEEK_CUR);
	 }
     }
  fclose(file);
  fclose(file2);
  unlink(tempfile);
}
///////////////////////////////////////////////////////////////////////////////
// Path's drive must be uppercase
newdir( const char *path)
{
char *path2, drive, *direc;
path2 = strdup(path);

if (path2[strlen(path2) - 1 ] == '\\')
    path2[strlen(path2) - 1] = '\0';

if (path2[1] == ':')
   {
    drive = path2[0];
    direc = path2 + 2;
    setdisk(drive - 65);
    }
else
    direc = path2;
errno = chdir(direc);
free(path2);
return errno;
}

void packf( )
{
 struct ffblk ffblk2;
 rename(FLIST, tempfile);

 if ((file2 = fopen(tempfile, "rt")) != NULL)
    {
     tmpf = fopen(FLIST, "wt");

     strnset(record, '\0', 512);
     while (fgets(record, 512, file2) > 0)
	   {
           record[12] = '\0';
	   if (findfirst(record, &ffblk2, 0) == 0)
              {
              record[12] = ' ';
              fputs(record, tmpf);
              }

           strnset(record, '\0', 512);
	   }

     fclose(tmpf);
     }
fclose(file2);
unlink(tempfile);
}
