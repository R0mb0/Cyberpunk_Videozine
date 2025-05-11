/**
 *
 *  Module:       writefon.c
 *  Version:      2.0
 *  Description:  routines to write telix 3.0 fon file
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
#include  <stdio.h>
#include  "tlx30.h"
#include  "tlxsort.h"


static  void      WriteFonHeader ( fon_header *th, FILE *fil );


/*<f>*/
/**
 *
 *  Function:     void WriteFonFile()
 *  Description:  write fon file to disk
 *  Returns:      nothing
 *
**/
void WriteFonFile(name, th, te)
char      *name;
fon_header *th;
fon_entry  *te;
{
  FILE      *fil;
  int       result;

  fil = ffopen(name, "wb");

  WriteFonHeader(th, fil);

  result = fwrite(te, sizeof(fon_entry), (size_t)th->num_entries, fil);

  if (result != th->num_entries)
    quitf("error writing fon file %s", name);

  fclose(fil);

  return;
}


/*<f>*/
/**
 *
 *  Function:     static void WriteFonHeader()
 *  Description:  write telix 3.0 fon header
 *  Returns:      nothing
 *
**/
static void WriteFonHeader(th, fil)
fon_header *th;
FILE      *fil;
{
  int       result;

  result = fwrite(th, sizeof(fon_header), 1, fil);

  if (result != 1)
    quitf("error writing fon file header");

  return;
}

