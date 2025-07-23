/**
 *
 *  Module:       tlxsort.h
 *  Version:      2.0
 *  Description:  function prototype for TlxSort
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
extern  void      ReadFonFile ( char *name, 
                                fon_header **header_p, 
                                fon_entry **entry_p 
                              );
extern  void      *mmalloc    ( size_t size );
extern  void      quitf       ( char *fmt, ... );
extern  FILE      *ffopen     ( char *name, char *mode );
extern  void      WriteFonFile( char *name, fon_header *th, fon_entry *te);

