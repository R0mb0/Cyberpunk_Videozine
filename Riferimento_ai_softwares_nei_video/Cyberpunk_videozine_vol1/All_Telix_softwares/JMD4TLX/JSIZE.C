/******************************************************************
** JSIZE.C
**
** Syntax:  JSIZE <filename>
**
** Returns: Writes a temporary file named "JSIZE.$$$" containing the
**          integer size in bytes of the passed filename.
**
** Notes:   This kludge is necessary because TELIX does not allow you to
**          determine the size of a file by using the filesize() function
**          if you are between calls to filefind() without destroying the
**          buffer used in subsequent calls.  I wanted to do just that in
**          order to be able to log performance characteristics for each
**          JMODEM transfer.  Since I also allow the user to pass wildcards
**          and multiple filenames, here it is.  See the JLOG.SLT source
**          file for details regarding its use.  This file was compiled
**          using Microsoft C 5.10.
**
** Limits:  This will only work if the filesize is <= 9,999,999 bytes.
**          This should not present a problem.  If it does, you may have
**          take out a loan just to pay your phone bill!
**
** Author:  Michael K. Bozovich
**
** Date:    3-20-89
**
********************************************************************/

#include <io.h>
#include <stdio.h>

FILE *stream;
unsigned long bytes;

main(argc, argv)

int argc;
char *argv[];

{
  stream = fopen(argv[1], "r");            /* Open the file for reading  */
  bytes = filelength(fileno(stream));      /* Determine its size         */
  fclose(stream);                          /* Close it                   */

  stream = fopen("jsize.$$$", "w+");       /* Open temporary file - it   */
                                           /* is destroyed if it already */
                                           /* exists!                    */
  fprintf(stream, "%7lu", bytes);          /* Write the file size info   */
  fclose(stream);                          /* Close it and return        */
}

/* eof jsize.c */
