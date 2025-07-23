
        TlxSort v1.0 by Paul Roub -- sort Telix v3.0 phone directories

        This program and its sources are Copyright (C) 1988 by Paul Roub
        and may not be sold for profit without the express written
        consent of the author.  Redistribute them (in their entirety) as
        you wish,  provided no fee is charged and all materials are
        present and unmodified.

        O.K.,  enough legal crap.  By the way,  I didn't write ALL of
        this - the header formats are copied verbatim from the
        description distributed by PTel,  makers of Telix.  Thanks for
        circulating it,  Colin.  If you find bugs in the source,  or
        ideas for improvements (of which I have a few),  let me know.  If
        you find the program really useful and otherwise wonderful for
        some reason,  a $5 contribution wouldn't hurt anyone.  Not that
        I'll starve without it,  but...

        TlxSort sorts Telix v.30 phone directories (currently by name
        only).  The simplest syntax is :

           tlxsort

        which will sort TELIX.FON,  and write the sorted directory to the
        same file.  Up to two parameters may be given,  that is:

          tlxsort [input file name] [output file name]

        If both are given,  the first is used as the name of the input
        file,  and the second is used as the name of the output file.  If
        only one is given,  it is the input file and TELIX.FON is the
        output file.

        Note that the source is included for your viewing pleasure.  As
        before,  I only ask that you send bug fixes or comments to me.
        It's written for Microsoft C 5.0+ or QuickC.  The pack() #pragma
        should be the only big portability problem -- it makes sure that
        the compiler doesn't pad structure definitions with filler bytes.
        If your compiler doesn't do this,  you can just delete the
        #pragmas.

        Under Microsoft C,  just say:

          cl -Ox -AC tlxsort.c read_fon.c writefon.c misc.c

        or under QuickC

          qcl -Ox -AC tlxsort.c read_fon.c writefon.c misc.c


        have fun!

        comments,  bug fixes,  or contributions should be sent to:

        Paul Roub
        690 Anderson Court
        Satellite Beach, FL  32937


        you might try E-Mail on the south or central FL Fido nets,  or on
        Compuserve to [71131, 157].

