

        HSLSALT is a SALT script for Telix which makes running HS/Link
easy. There are a few things that must be done to configure the script
to your particular system, but other than that you should be ready to
go.

        First, you must have HSLINK.EXE installed on your drive. Be sure
which version you have, since the protocol is still in Beta testing, and
is in constant revision. This script will work with all up to beta8.

	Getting set up

	You will have to configure the script for your system The first
part you will need to change will be the string variables at the top of
the script. They look like this in the script as it is now:

int f;			str listloc[] = "c:\telix\list.txt";
int v;			str proto[] = "c:\telix\hslink.exe";
int select;		str comline_opt[] = "c:\new @c:\telix\list.txt";
int q;

Ignore the int variables. You will not need to change them. Look at the
str variables. The first, listloc[], is the complete path and filename
of the upload list file you wish to create. This list file is allowed by
HS/Link in place of a whole list of files on the command line. The
script will allow you to create this file, and add file names to it.
Change the part in the quotes to create this file wherever you want it.

	Next, you will have to change proto[]. This is the complete path
and filename where HS/Link is located. Be sure to include the .exe too.

	The next is comline_opt[]. This is the complete command line
string to pass to HS/Link. As it is listed above, the first part
"c:\new" is the location where downloaded files will be put. The second
part, "@c:\telix\list.txt", is the command line option to use an upload
list file in the telix directory called "list.txt".

	The upload list file is a straight ASCII file with one complete
path and filename on each line. This script will allow you to enter
names in this file whether online or off. If the file has not been
created, it will create it. Every time you run the script and add
filenames to the file, they will be appended to the existing file. If
you want to delete the file, the script allows you to select this option
from a menu. then a new file will be created next time you run the
script. In order for this to take place, you must edit one additional
part of the script before compiling it.

	Look for this part:

	if (select == "3")
		{
                dos("del c:\telix\list.txt",0);
		}
        if (select == "4")


	Edit the part that says "dos("del c:\telix\list.txt",0);"

All you have to do is make sure it points to the location of the list
file so that the script will be able to delete it when you want.

	Now all you should have to do is compile the script with the
SALT compiler, CS.EXE, and install it in Telix. I run the script from
the F8 key. You can assign the script to any hot key you want in Telix
by hitting Alt-K and editing the key file. To assign a script to a hot
key, just define the key as "@scriptname", where the scriptname is the
name of your script without the extension. Be sure the script is in the
defined script directory so that Telix can find it.

	That's all there is to this, and you should only have to do this
once. The script runs everything from a menu, and should be self
explanatory from there.

	Disclaimer:

	I make no promises about this script. It is only guaranteed to
take up room on your hard drive. I will not be responsible for any
damage it may cause to your data or system.


