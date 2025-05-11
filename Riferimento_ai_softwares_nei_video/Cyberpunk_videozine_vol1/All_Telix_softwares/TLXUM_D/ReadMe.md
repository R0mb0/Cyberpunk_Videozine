
     TO:  All who use UM
   FROM:  Kenneth Leung
   DATE:  May 1, 1990
SUBJECT:  Telix Upload Manager version D


     Requirements:  Telix v3.12 or later
                    TLXUM-D.SLC, UMCFG-D.SLC, TLXUMSRT.SLC,
                    F1-PROT.SLC, and F2-PROT.SLC must be in
                    the script directory.

____________________________________________________________

D i s c l a i m e r:
     The author makes no claims about these scripts except
that they do work on his computer and that they will take up
room on the user's disk. In the event of malfunction, the
author's liability shall be nil and the user accepts all
responsibilities for loss of data or real property.

____________________________________________________________

     Telix Upload Manager is a script to enhanced the Upload
function provided by Telix.  Instead of typing filenames,
you can "tag" them to upload.  In order to take the
advantage of UM, you can re-define PGUP and ALT-S, assign
these two macro keys to TLXUM-D; in order to do so, follow
these steps:

     1. Press ALT-K
     2. Select "REGULAR"
     3. Select "EDIT"
     4. Press PGUP (and/or ALT-S)
     5. Type "@TLXUM-D"
     7. Select "SAVE"

____________________________________________________________

     Due to the limitation of Telix itself, internal
protocols can only handle 64 characters long filename(s),
and can only upload files from ONE directory only.  If you
want to upload more files, or want to upload files from
different drives or directories (ie. A:\FILE1.ZIP,
C:\FILE2.ZIP, C:\TELIX\FILE3.ZIP at the same time), select
external protocols, such as DSZ's Zmodem or DSZ's Ymodem-G.

     If you choose to use external protocols, UM will create
a file call "TLXUM.UP" in the Telix's base directory.  After
the external protocol finishes uploading files, UM will
delete "TLXUM.UP".  Also, in order to use these external
protocols, F1-PROT.SLC and F2-PROT.SLC must be in the SCRIPT
DIRECTORY.  The original F1-PROT.SLC and F2-PROT.SLC are
scripts that run external protocols.  If you don't like the
parameter I set for DSZ's Zmodem and DSZ's Ymodem-G, or want
to run some other external protocols, please feel free to
modify the script (the source is included in TLXUM-D.ZIP)

     Once again, due to the limitation of SALT itself, it is
impossible to sort the file list in the "Tag-File Window";
therefore, I write a very simple script to run a directory
sort utility (such as Norton's DS "Directory Sort"), then UM
will re-scan the directory again.  This time, after the
sort, all files should appear in some sort of an order.

     About the estimated transfer time, it is based on the
efficiency of the protocol and the speed of your comm port.
Therefore, different protocols may have different estimated
transfer time for the same file.  However, it may not be
accurate if you lock your comm. port at a higher speed than
your modem.

____________________________________________________________

Fixes or Enhancements in Telix Upload Manager version D:
     1. UMCFG-D.SLC is now able to "quit" without modifying
        the current setup.
     2. UMCFG-D.SLC can now set the border color.  (Thanks
        to Ken Harwell)
     3. UMCFG-D.SLC will now refuse to save if "Bar Color
        (1)" and "Bar Color (2)" are the same.
     4. UM now look at "Telink" as a batch protocol.
     5. UM now support "Modem7".
     6. Allow more flexible movements for the scroll bar.
     7. Show current time.
     8. Estimate the time (in hours and minutes) for
        transferring files.  (Thanks to Jeff Woods)
     9. Show the size of the total tagged files (in
        Kilobytes).
    10. The name on external protocols can be changed by
        running UMCFG-D.SLC
    11. Add the ability of tag and un-tag files.
    12. The Tag-File Window now can hold 108 files, instead
        of 72.
    13. Now UM support a directory with more than 108 files.
        Press PGDN for the next 108 (or less) files.
        Pressing PGUP will put you back to the very first
        page.
    14. For internal batch protocols, it is possible to tag
        more than 4 files.
    15. Improve the speed of scroll bar in Tag-File Window.
    16. Now you can define different colors for "TITLE" and
        "HELP".
    17. Tagged filenames remain highlighted even after you
        have pressed [F3] or [F5].

____________________________________________________________

     If you have any comments, or have found any bugs, you
can send a E-mail to me in RelayNet's Telix Conference.

     Kenneth Leung
     201 W Hermosa Dr #B211
     Tempe, AZ 85282

Telix and SALT are trademarks of Exis Inc.
Norton is Copyright of Norton Computing Inc.
Telix is Copyright Exis Inc.
DSZ is Copyright Omen Technology Inc.
