





          TlxSort v1.1 by Paul Roub
          Sort Telix v3.0-3.1 phone directories

          This program  and its sources are Copyright (C) 1988 by Paul Roub and
          may not be sold for profit without the express written consent of the
          author.  Redistribute them (in their entirety) as you wish,  provided
          no fee is charged and all materials are present and unmodified.

          O.K.,  enough legal crap.  By the way,  I didn't write ALL  of this -
          the  header   formats  are   copied  verbatim  from  the  description
          distributed by Exis,  makers of  Telix.   Thanks for  circulating it,
          Colin.

          If you  find bugs in the source,  or ideas for improvements (of which
          I have a few),  let me know.  If you find  the program  really useful
          and otherwise  wonderful for some reason,  a $5 contribution wouldn't
          hurt anyone.  Not that I'll  starve  without  it,    but  you'll feel
          better  <grin>,    and  I  can  continue  my valiant effort to pay my
          MasterCard bill.

          TlxSort sorts Telix v3.0-3.1  phone  directories  (currently  by name
          only).    Note  that  leading  blanks  and/or  the  word 'the' at the
          beginning of  an entry  name will  be ignored,   and  blank or 'null'
          entries will be put at the end.  The simplest syntax is:

               tlxsort

          which will  sort TELIX.FON,   and  write the  sorted directory to the
          same file.  Up to three parameters may be given,  which are:

               tlxsort [-d] [input file name] [output file name]

          If both file names are given,  the first is used as  the name  of the
          input file,   and  the second is used as the name of the output file.
          If only one is  given,   it is  the input  file and  TELIX.FON is the
          output file.

          The  '-d'  switch  tells  TlxSort  to eliminate null entries (entries
          whose 'BBS name' fields  are  all  blank-filled  or  empty)  from the
          output file.

          Note  that  the  source  is  included  for your viewing pleasure.  As
          before,  I only ask that you send bug fixes or comments to me.   It's
          written for  Microsoft C  5.0+ or Quick C.  The pack() #pragma should
          be the only  big  portability  problem  --  it  makes  sure  that the
          compiler doesn't  pad structure  definitions with filler bytes.  That
          is to say,  a structure with,  say,  3 characters and an integer will
          take up  PRECISELY 5  bytes   --  by default,  MSC will pad things so
          that integers appear at even addresses.  If compiler doesn't do this,
          you can just delete the #pragmas.

          Under Microsoft C,  just say:

               cl -Ox -AC tlxsort.c read_fon.c writefon.c misc.c






          or for Quick C

               qcl -Ox -AC tlxsort.c read_fon.c writefon.c misc.c

          contributions should be sent to:

               Paul Roub
               690 Anderson Court
               Satellite Beach, FL  32937

          I can also be reached through the FidoNet TELIX echo,  or by
          NetMail to me at 1:135/47.

