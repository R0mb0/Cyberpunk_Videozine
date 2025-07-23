/**
 *
 *  Module:       tlx30.h
 *  Version:      1.1
 *  Description:  Telix 3.0-3.1 fon file structures
 *  Author:       Paul Roub - yeah,  right...
 *
 *  Revision History:
 *     7-13-88 : hacked together,  added typedef's and pragma's
 *
 *      This program and its sources are Copyright (C) 1988 by Paul Roub
 *      and may not be sold for profit without the express written
 *      consent of the author.  Redistribute them (in their entirety) as
 *      you wish,  provided no fee is charged and all materials are
 *      present and unmodified.
 *
**/

/*<f>*/
#pragma pack(1)


/*
 *  the following is copied directly from the TELIX format description
 *  from PTel
 */


/*
   TELIX communications program v3.0 dialing directory file format.
   Copyright (c) 1988 PTel, Post Office Box 130, West Hill, Ont. M1E 4R4

   A Telix 3.0 dialing directory file is variable sized, and can hold from
   1 to 1000 entries (1000 is an arbitrary limit which might be raised, so
   do not get too dependent on it).  A dialing directory file consists of
   one ddf_header structure followed by a dd_entry structure for each
   entry iu the dialing directory.  All data is stored in Intel format. 
   This means that when integers and longs are written to disk, they are
   written in the order low byte to high byte.  Since all Intel chips
   (like the 8088 and 80x86 used in PCs) store data in this fashion, this
   is of concern only if you are trying to access a directory file from a
   computer using another microprocessor, like the Mac's 68000.

   The 2 structures follow, in C format.
   All structures are packed.  No padding should be used by the compiler
   to align data on even addresses.  For example, if using the MS C
   compiler, use the -Zp switch!
*/

struct ddf_header
{
 long id;                 /* should be hex 2e2b291a */
 int  ddf_vers;           /* currently 1 */
 int  num_entries;        /* # of entries in directory, from 1 to 1000 */
 char pencrypted;         /* currently 0, will be used for encryption */
 char spare[55];
};

struct dd_entry
{
 char     name[25],       /* entry name */
          number[17],     /* phone number */
          baud,           /* baud rate, see below */
          parity,         /* parity: 0 = none, 1 = even, 2 = odd */
          data,           /* number of data bits, 7 or 8 */
          stop,           /* number of stop bits, 1 or 2 */
          script[12],     /* linked script file name */
          lastcall[6];    /* last call date, stored in ASCII, w/o slashes */
 unsigned totcalls;       /* total successful calls to this entry */
 char     terminal,       /* terminal type to use, see below */
          protocol,       /* default protocol; first letter */
          toggles,        /* bit 0: local echo - 0 = off, 1 = on */
                          /* bit 1: add LFs    - 0 = off, 1 = on */
                          /* bit 2: BS trans   - 0 = destructive, 1 = not */
                          /* bit 3: BS key     - 0 = sends BS, 1 = sends DEL */
                          /* bit 4: Strip high bits - 0 = off, 1 = on */
          filler1,
          filler2,
          dprefnum,       /* dialing prefix number to use when dialing */
          password[14];   /* password for this entry */
};


/*
   ASCII string fields like the name, number, password, etc. are stored in
   C format, but include the terminating 0 only if there is room. For example,
   if an entry name is 25 characters long it will completely fill up the field,
   and no terminating zero will be added. This was done for space reasons, but
   means that if you manipulate the directories you must take care. C program-
   mers for example should use the strncpy function instead of the strcpy func-
   tion to access these fields, and must make sure to add a terminating zero.

   baud field:     0 =  300, 1 =  1200, 2 =  2400, 3 =  4800,
                   4 = 9600, 5 = 19200, 6 = 38400, 7 = 57600, 8 = 115200

   terminal field: integer number from 0 - n equivalent to that entry
                   in menu shown when Alt-T function invoked
*/



/*
 *  typedefs for TlxSort
 */
typedef struct ddf_header fon_header;
typedef struct dd_entry   fon_entry;

#pragma pack()
