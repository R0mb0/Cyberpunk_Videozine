/**
 *
 *  Module:       misc.c
 *  Version:      1.1
 *  Description:  miscellaneous functions
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
#include  <stdarg.h>
#include  <stdio.h>
#include  <stdlib.h>

#include  "tlx30.h"
#include  "tlxsort.h"


/*<f>*/
/**
 *
 *  Function:     FILE *ffopen()
 *  Description:  open file - quit if it can't be opened
 *  Returns:      FILE pointer
 *
**/
FILE *ffopen(name, mode)
char      *name;
char      *mode;
{
  FILE      *res;

  res = fopen(name, mode);

  if (res == NULL)
    quitf("can't open file %s", name);

  return(res);
}


/*<f>*/
/**
 *
 *  Name:         quitf()
 *  Description:  prints message to stderr,  exits with return code 1
 *  Returns:      nothing
 *
**/
void quitf(str, ...)
char      *str;
{
  va_list   arg_ptr;

  va_start(arg_ptr, str);
  vfprintf(stderr, str, arg_ptr);
  va_end(arg_ptr);

  fputc('\n', stderr);

  exit(1);
}


/*<f>*/
/**
 *
 *  Name:         void *mmalloc()
 *  Description:  malloc() with memory check: aborts if insufficient memory
 *  Returns:      pointer to allocated block
 *
**/
void *mmalloc(size)
size_t    size;
{
  void      *res;

  if ((res = malloc(size)) == NULL)
    quitf("\n\nInsufficient memory");

  return(res);
}

