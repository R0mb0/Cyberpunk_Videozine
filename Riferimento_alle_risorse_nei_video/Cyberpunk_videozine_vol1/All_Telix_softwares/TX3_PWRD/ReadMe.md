This is a very simple Telix 3.0 script to set a function key to
return the password in the dialing directory field to the system
you are on-line with.  Setup is very simple:
 
   1:  Enter the Macro editor in Telix using the Alt-K sequence.
   2:  Select "E"dit Macro keys, and strike the key you wish to
       use to transmit the password.
   3:  Edit this key's macro to read:   @pw
   4:  Select "S"ave from the Macro editor menu.
   5:  Exit the Macro editor ("X").
   6:  Place the file PW.SLC in the path indicated as the script
       directory under Alt-O, Telix configuration.  Unless you   
       have changed this under the "Filenames and paths" option,
       this will be your root directory.

That's all there is to it.  The script is very simple, and the
script source is included if you wish to make it more detailed. 
I have supplied the script for use as an alternate to my TLX3-ALL
script on systems where the script may fail, or will not work.  

Any questions about this script, or the functioning of Telix 3.0
scripts may be directed to me on my BBS as listed below:

                       Jeffrey L. Woods, Sysop 
          Arizona State University's Computing Services BBS
                    3/12/24 (soon 9600), 24 hours
                             602-965-5670
    
                     Dedicated to the acquisition
                         of a sound education 