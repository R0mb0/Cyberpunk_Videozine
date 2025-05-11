
  ---------------------------------------------------------------------------
        deltaComm Development, Inc., PO Box 1185, Cary, NC  27512  USA

         (919)-460-4556 voice, (919)-460-4531 FAX, (919)-481-9399 BBS

          Telix Copyright (C) 1986-1994 by deltaComm Development, Inc.
  ---------------------------------------------------------------------------

  January 31st, 1994 --

       Note to Telix users:  This file supersedes the following patch
                             files.  If you see any of the following
                             files on your local BBS, they may not be
                             complete, and you should request that the
                             sysop remove them and replace them with
                             this comprehensive patch.   The files that
                             are being replaced are:

                             TLX321-U.ZIP    T320-321.ZIP   T312-321.ZIP
                             TLX322-U.ZIP    T315-321.ZIP

       In line with new deltaComm policy, minor updates, such as those from
       Telix 3.21 to 3.22, will no longer be charged for.  This patch file
       has been released to take your unbranded, registered copy of Telix
       3.11 or later and convert it to an unbranded, registered copy of 3.22.

       An UNBRANDED copy is one that is contained on your distribution disk as
       sent to you by Exis or deltaComm, in the appropriate ZIP file, such as
       TLX315-1.ZIP.  An UNBRANDED copy is one that has not had your name and
       serial number inserted into it with the BRANDTLX.EXE program.  The
       PATCH.EXE program requires to know the exact contents of the file prior
       to applying the patch, and the unbranded copy meets this requirement.
       After your name and serial number are inserted into a copy that you are
       using, the contents are different for each copy, and PATCH.EXE will be
       unable to account for the differences between the file *we* started
       with in generating the patch, and the file you start with to apply it.

       To apply this patch, please follow the directions below precisely:

         1) Locate your original registered Telix disk that was sent to you
            when you registered the program.  This disk will contain a serial
            number on the label.

         2) From your Telix directory, with the distribution diskette in your
            floppy drive, issue the following command.  Your screen will look
            somewhat like the following.  Please be sure to substitute the
            appropriate drive letter if your floppy is not in the a: drive:

            ------------------------------------------------------------------

            C:\TELIX> pkunzip -o a:TLX???-1.ZIP TELIX.EXE

            PKUNZIP (R)    FAST!    Extract Utility    Version 2.04g  02-01-93
            Copr. 1989-1993 PKWARE Inc. All Rights Reserved. Shareware Version
            PKUNZIP Reg. U.S. Pat. and Tm. Off.

            Searching ZIP: A:TLX321-1.ZIP

            Exploding: TELIX.EXE

            ------------------------------------------------------------------

            If you do not get a message from PKZip that it is exploding or
            otherwise decompressing TELIX.EXE, then you are not performing
            this step properly.

         3) From the DOS prompt in the Telix subdirectory, verify that the
            copy of Telix that you are attempting to patch is indeed the
            unbranded copy (one that has not had a serial number and name
            inserted into it) by attempting to run Telix.  You should receive
            the following message when you execute Telix:

------------------------------------------------------------------------------

This copy of Telix has not yet been 'branded' with your name and serial number.
Please run the BRANDTLX program to do this (if you installed Telix onto 360k
disks it will be on the second disk).  This will only have to be done once.

------------------------------------------------------------------------------

            If the copy of TELIX.EXE you are trying to patch runs normally
            when you execute it, instead of giving this message, this step was
            not performed correctly, and you will NOT be able to apply the
            patch yet.  Please insure that you unzipped the proper file from
            the registered disk with a serial number on the label, as
            described in step 2, and that the program gives the above message
            when you try to run Telix.

         4) Place the files PATCH.EXE and PATCH.RTP in the same directory as
            the unbranded TELIX.EXE, and run the program PATCH.EXE from that
            subdirectory.  Your screen will look somewhat like the following,
            but may differ depending on the revision of Telix you are
            patching:

ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
           PATCH  Version 1.12 - .RTPatch(R) Software Update System
       (C) Copyright Pocket Soft, Inc., 1991-1993.  All Rights Reserved.
                     < Pocket Soft, Inc.  (713) 460-5600 >
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ


ÄÄÄÄÄ Processing Patch File ÄÄÄÄÄ

Applying HISTORY File Patch for 'TELIX.EXE'

    Updating ...
    Updating to next version ...
    Updating to next version ...
    Updating to next version ...
    Updating to next version ...
    Updating to next version ...
    Updating to next version ...
    Updating to next version ...
    File successfully Updated!
    Deleting Old File


ÄÄÄÄÄ Patch File Processing Complete ÄÄÄÄÄ

ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

         5) The resultant copy of TELIX.EXE will be the latest release of v.
            3.22 and may then be branded and used.  BRANDTLX.EXE may be found
            in the appropriate TLX3??-2.ZIP file on the distribution diskette
            and may be extracted with a command similar to step 2 above.


ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
                      Questions and answers about patching:
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ


         Q: Why can't I patch the version I'm using now?  Why do I have to dig
            up my old disk?

         A: To make a patch file, Pocket Soft's .RTPatch takes two copies of a
            file and compares them for differences; the differences between
            the older file and the newer one are written to a patch file that
            PATCH.EXE can apply.  However, if your older file isn't *exactly*
            the same as the older file we used to generate the patch, then
            PATCH.EXE will not know how to apply the changes.  Therefore, to
            assure that the file you are patching is exactly the same as the
            file we used to build the patch, you have to use a copy that
            hasn't been modified to contain your name and serial number.

------------------------------------------------------------------------------

         Q: I can't find my original distribution disk, so I can't apply the
            patch.  What do I do now?

         A: Because the patch program requires an unbranded copy of TELIX.EXE
            in order to work (for reasons described above), you will need to
            obtain a new distribution diskette from deltaComm.  A nominal fee
            of $10 is required to cover the cost of materials and shipping.
            The disk you receive will be the latest version. Send your $10 to:

            deltaComm Development, Inc., PO Box 1185, Cary, NC  27512

------------------------------------------------------------------------------

         Q: I applied the patch, but now I can't brand Telix with my serial
            number -- BRANDTLX says that the format of a serial number is
            different than the one I have.  (i.e. "My serial number is
            A1002111 but BRANDTLX.EXE wants five more digits than were on the
            screen in my older copy of Telix).

         A: The serial number displayed on the opening screen of Telix is not
            the complete serial number -- it is only the first eight digits out
            of fourteen total.  The complete serial number is found ONLY on
            your original distribution diskette, and is 14 characters long.
            If you cannot find your serial number on the disk label, please
            call our customer service department at 919-460-4556 between the
            hours of 9 am and 9 pm Eastern time.  Upon verification of your
            identity, your complete serial number will be given to you over
            the phone.

------------------------------------------------------------------------------

         Q: Why is the patch file so huge? I thought v3.22 was a minor update.

         A: The patch to go from 3.21 to 3.22 only is very much smaller than
            the patch you have here.  This patch file is designed to patch
            *any* unbranded, registered copy from 3.11 to 3.21 into v3.22, and
            the size of this patch is the sum of all of the patches required
            to make each step.  If you are, for example, patching v3.15, the
            parts of the file for users of v3.11 and v3.12 are useless to you.
            In this case, the program will first patch your 3.15 into a 3.20,
            then that 3.20 into a 3.21, then that 3.21 into a 3.22, all behind
            the scenes.  We believe that one easy-to-use patch file for all
            versions, though larger, is easier to understand than several
            smaller patch files for specific versions (there would be fifteen
            individual patch files if we did it that way, quite confusing!).

------------------------------------------------------------------------------

          Q: I get the following error message when applying the patch:

             error ept0036: Original file not found. However, a file of the
                            same name was found. No update done since file
                            checksums do not match.

          A: PATCH was unable to locate an exact match for the original file
             to be updated. However, PATCH was able to locate a file with the
             same name as the original file. However, the file found did not
             have either the same size or checksum as the actual original file
             that PATCH is seeking in order to perform the update.

             Programs known to cause PATCH.EXE to generate this error are
             Stacker and DoubleSpace, some disk caches, some CD-ROM drivers,
             and some anti-viral software. Anythin loaded in your CONFIG.SYS
             and AUTOEXEC.BAT can potentially cause this error. Each can cause
             the checksum of the file you have to differ from the checksum of
             the file we used to build the patch.

             Please try to remove these items from memory if PATCH gives you
             this error, and then start over at step 2.  The best way to do
             this is to boot from a bootable floppy drive that has NO
             CONFIG.SYS or AUTOEXEC.BAT.

             It is crucial for you to unzip the unbranded TELIX.EXE from your
             floppy again after you reboot without these programs loaded.
             Virus checkers that use file signatures may have modified the
             copy on your hard disk, and those modifications may still be
             present, even if the virus checker is no longer in memory. If it
             is DoubleSpace or Stacker causing the error, you may have to use
             another machine without a disk-doubler to apply the patch.

------------------------------------------------------------------------------

          Q: How can I "unbrand" my copy of Telix?

          A: This cannot be done. You must find your original distribution
             diskette (or purchase an update disk) in order to apply the free
             patch files.

------------------------------------------------------------------------------

