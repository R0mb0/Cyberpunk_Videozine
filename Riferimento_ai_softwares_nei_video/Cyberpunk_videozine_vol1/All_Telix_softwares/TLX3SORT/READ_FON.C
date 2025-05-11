/**
 *
 *  Module:       read_fon.c
 *  Version:      2.0
 *  Description:  routines to read Telix 3.0 fon directory
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


static  fon_header *ReadFonHeader ( FILE *fil );


/*<f>*/
/**
 *
 *  Function:     void ReadFonFile()
 *  Description:  read specified file
 *  Returns:      pointers to header and entries (which we allocate)
 *
**/
void ReadFonFile(name, header_p, entry_p)
char      *name;
fon_header **header_p;
fon_entry **entry_p;
{
  fon_header *th;
  fon_entry  *te;
  FILE      *fil;
  int       result;

  fil = ffopen(name, "rb");

  th = ReadFonHeader(fil);

  te = mmalloc(th->num_entries * sizeof(fon_entry));

  result = fread(te, sizeof(fon_entry), (size_t)th->num_entries, fil);

  if (result != th->num_entries)
    quitf("error reading fon file %s", name);

  fclose(fil);

  *header_p = th;
  *entry_p = te;

  return;
}


/*<f>*/
/**
 *
 *  Function:     static fon_header *ReadFonHeader()
 *  Description:  read telix 3.0 phone header
 *  Returns:      pointer to (allocated) header
 *
**/
static fon_header *ReadFonHeader(fil)
FILE      *fil;
{
  int       result;
  fon_header *th;

  th = mmalloc(sizeof(fon_header));

  result = fread(th, sizeof(fon_header), 1, fil);

  if (result != 1)
    quitf("error reading fon file header");

  if (th->id != 0x2E2B291A)
    quitf("invalid phone file header");

  return(th);
}

