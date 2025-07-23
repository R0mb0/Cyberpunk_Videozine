/**
 *
 *  Module:       tlxsort.c
 *  Version:      1.1
 *  Description:  sort Telix 3.0-3.1 phone directories
 *  Author:       Paul Roub
 *
 *  Revision History:
 *     7-13-88 :  created
 *    10-12-88 :  eliminated bug in sort function
 *                now ignores leading blanks and/or 'the' when sorting
 *                added '-d' switch to delete null entries
 *
 *      This program and its sources are Copyright (C) 1988 by Paul Roub
 *      and may not be sold for profit without the express written
 *      consent of the author.  Redistribute them (in their entirety) as
 *      you wish,  provided no fee is charged and all materials are
 *      present and unmodified.
 *
**/

/*<f>*/
#include  <ctype.h>
#include  <malloc.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#include  "tlx30.h"
#include  "tlxsort.h"


void      main( int argc, char **argv );
int       fon_compare(const void *elem1, const void *elem2);

static  char      *InName  = "telix.fon";
static  char      *OutName = "telix.fon";
static  char      Umsg[]   = "usage: tlxsort [-d] [input file name] [output file name]";


/*<f>*/
/**
 *
 *  Function:     void main()
 *  Description:  tlxsort main routine
 *  Returns:      nothing
 *
**/
void main(argc, argv)
int       argc;
char      **argv;
{
  fon_header *th;
  fon_entry *te, *ke;
  int     keep_count, ncount;
  char    *name;
  int     del_switch;

  printf("TlxSort v1.1 -- Copyright (C) 1988 by Paul Roub\n\n");

  if (argc > 4)
    quitf(Umsg);

  --argc;
  ++argv;

  if (argc && (**argv == '-'))
  {
    ++*argv;

    if (tolower(**argv) == 'd')
    {
      del_switch = 1;
      --argc;
      ++argv;
    }
    else
      quitf(Umsg);
  }

  if (argc)
  {
    InName = *argv;
    argc--;
    argv++;
  }

  if (argc)
  {
    OutName = *argv;
    argc--;
    argv++;
  }

  printf("Sorting %s to %s...\n", InName, OutName);

	ReadFonFile(InName, &th, &te);

  qsort(te, (size_t)th->num_entries, sizeof(fon_entry), fon_compare);

  if (del_switch)
  {
    keep_count = 0;
    ke = te;

    while (keep_count < th->num_entries)
    {
      name = ke->name;
      ncount = 0;

      while (isspace(*name) && (ncount < 25))
      {
        name++;
        ncount++;
      }

      /*
       *  if we've found ONE blank entry,  then all successive entries
       *  must also be blank,  so only keep the non-blanks we've seen
       *  so far
       */
      if ((ncount == 25) || (! *name))
        break;
      else
      {
        ke++;
        keep_count++;
      }
    }

    th->num_entries = keep_count;
  }

  WriteFonFile(OutName, th, te);

  free(th);
  free(te);

  printf("%u entries written.\n", th->num_entries);

  exit(0);
}


/*<f>*/
/**
 *
 *  Function:     int fon_compare()
 *  Description:  comparison routines used by qsort - sorts files by
 *                name - note the exception:  if a one file has a
 *                blank name (""),  it goes after the other,
 *                regardless.
 *                ignores leading "the's" and blanks
 *  Returns:      -1 if first should come before second
 *                0 if first and second sort the same
 *                1 if first should come after second
 *
**/
int fon_compare(elem1, elem2)
const void *elem1, *elem2;
{
  char      *name1, *name2;
  int       len1, len2;
  char      compbuf1[26], compbuf2[26];

  /*
   *  isolate the names for readability
   */
  name1 = ((fon_entry *)elem1)->name;
  name2 = ((fon_entry *)elem2)->name;

  /*
   *  eliminame leading blanks
   */
  for (len1 = 0; isspace(*name1) && len1 < 25; len1++, name1++)
    ;

  for (len2 = 0; isspace(*name2) && len2 < 25; len2++, name2++)
    ;


  /*
   *  bypass leading the's
   */
  if (! strnicmp(name1, "the", 3))
  {
    name1 += 3;
    len1 += 3;
  }

  if (! strnicmp(name2, "the", 3))
  {
    name2 += 3;
    len2 += 3;
  }

  /*
   *  eliminame leading blanks following "the"
   */
  while (isspace(*name1) && len1 < 25)
  {
    len1++;
    name1++;
  }

  while (isspace(*name2) && len2 < 25)
  {
    len2++;
    name2++;
  }

  /*
   *  if we've hit a 0 or blanked past 25,  it's a null entry,
   *  so it goes after anything
   */
  if ((! *name1) || (len1 >= 25))
    return(1);

  if ((! *name2) || (len2 >= 25))
    return(-1);


  /*
   *  else do a case insensitive compare,  using whatever's left
   *  of each after blank- and 'the'- stripping
   */
  memset(compbuf1, 0, sizeof(compbuf1));
  memset(compbuf2, 0, sizeof(compbuf2));

  strncpy(compbuf1, name1, 25 - len1);
  strncpy(compbuf2, name2, 25 - len2);

  return(stricmp(compbuf1, compbuf2));
}

