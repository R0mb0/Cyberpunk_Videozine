/**
 *
 *  Module:       tlxsort.c
 *  Version:      1.0
 *  Description:  sort Telix 3.0 phone directories
 *  Author:       Paul Roub
 *
 *  Revision History:
 *     7-13-88 : created
 *
 *      This program and its sources are Copyright (C) 1988 by Paul Roub
 *      and may not be sold for profit without the express written
 *      consent of the author.  Redistribute them (in their entirety) as
 *      you wish,  provided no fee is charged and all materials are
 *      present and unmodified.
 *
**/

/*<f>*/
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
  fon_entry *te;

  printf("TlxSort v1.0 -- Copyright (C) 1988 by Paul Roub\n\n");

  if (argc > 3)
    quitf("usage: tlxsort [input file name] [output file name]");

  --argc;
  ++argv;

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

  WriteFonFile(OutName, th, te);

  free(th);
  free(te);

  printf("%u entries sorted.\n", th->num_entries);

  exit(0);
}


/*<f>*/
/**
 *
 *  Function:     int fon_compare()
 *  Description:  comparison routines used by qsort - sorts files by
 *                name - not the exception:  if a one file has a
 *                blank name (""),  it goes after the other,
 *                regardless
 *  Returns:      -1 if first should come before second
 *                0 if first and second sort the same
 *                1 if first should come after second
 *
**/
int fon_compare(elem1, elem2)
const void *elem1, *elem2;
{
  const fon_entry *te1, *te2;

  te1 = elem1;
  te2 = elem2;

  if (! te1->name[0])
    return(1);

  if (! te2->name[0])
    return(2);

  return(strnicmp(te1->name, te2->name, 25));
}

