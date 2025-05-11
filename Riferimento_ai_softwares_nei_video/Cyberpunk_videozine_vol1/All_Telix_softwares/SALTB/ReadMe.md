        SALTB.EXE a Telix source code beautifier.
               Author: Leslie Satenstein (514)-682-5882
                       220 Croissant de l'Arcade
                          Laval, Quebec Canada
                                 H7W 4Y3

 Name:  SALTB.EXE

SALTB is a utility program which serves to reformat the source  
code of Telix SALT-language programs. It does it by removing or
adding spaces to line up statements, by indenting at each level
of nested conditionals, and by arranging code so that where  
possible, comments begin at a given column. The end result of  
the reformatting exercise is SALTB source code that looks so good 
on paper that someone who has to it could follow the logic by
following the indents, aligned comment fields etc. It doesnot
modify the logic of the program it reformats, but helps in the
reading of the source code.


Options: 

The program provides a few user options. These options control
the way SALTB will treat the program. The reader should be
cautioned that some options, such as shifting opening braces to
the next line (refer to example below) are not reversable. The
program once having moved a brace to the subsequent line, has no
logic incorporated to return the brace to the preceding line.

1.  Braces management. (P flag)

  "Statements following opening braces", and "opening braces" can 
  be made to appear on the subsequent lines instead of at the
  extreme right of the expression. An example is:

  if(expression){dothis();...} /* will be converted to */

  if(expression){
    dothis();
      ....
  }
             or

  if(expression)
  {
    dothis();
    .....
  }

formating expressions such as:
int i=5 ; //becomes

int     =   5;      //lined up to tab columns




2.   Action statements on subsequent lines. (B flag)

SALTB has an option to transfer action clauses to the subsequent 
line. It separates clauses from the preceding if, while, or for  
statement. The following example illustrates:

      for(i=0;i<25;i++)printc("^M^J");

           becomes

    for(i=0;i<25;i++)
      printf("^M^J");


3.  Indent Level Control. (I flag)

The amount of indentation is controllable within limits imposed 
on by the programme. The programme defaults to 4 characters.


4.  Comment Control (C flag)

  The C flag controls the starting column to the right of the
  saltb statement for the beginning of comments.


5.  Replacement control (R flag)

The output of the formatter can be an existing file. This file 
can be overwritten if desired. This privilege is accomplished  
via the R flag option. If the R flag is not specified, the  
program will prompt the user as to whether it should (or should 
not) overwrite the target file. When the R flag is specified,  
the program will not prompt the user, and will procede with the 
formatting. If the output file name is the same as the input  
file name the program will not destroy the input file until the 
new one is safely created.


6.   Syntax of SALTB-source code beautifier (SALTB.EXE).

    Command formats are:

  SALTB [Bn][-In][-Cnn][-Pn][-Rn][-Hn] tlxsrc[.slt] newfile[.slt]
  SALTB [Bn][-In][-Cnn][-Pn][-Rn][-Hn] <infile  >outfile.
  SALTB [Bn][-In][-Cnn][-Pn][-Rn][-Hn] tlxsrc[.slt] >outfile.

    [ ] refer to optional parameters that affect formatting.

When the csource file extension is omitted, a ".SLT" is appended.
When newfile[.slt] is omitted, output is to STDOUT. Similarly, if
no file is specified, input is from STDIN and output is to
STDOUT. Output file extension, if omitted is copied from the
input file name.

Parameter Values

-Bn   defines the treatment of if, while and for statements. When
      B1 (default) is specified, if, while and for statements are
      not modified by this formatter. When B0 (or just -b) is    
      specified, statements in the form:

      [if|for|while](test) action; /* are converted to*/

      [if|for|while](test)
          action;   /* are converted to*/

      while(clause) action;      /* becomes */

      while(clause)
        action;


-Cnn  defines the column to the right of c statements where
      comments should begin. -Cnn, if specified, must respect 
      0<nn <73. Default value is currently C41.

-Hn   controls insertion of program comment as header and trailer
      lines. The default is not to insert the comment header.

-In   is the indentation for each nesting level. Indent value be 
      0< n <9. Current default is 4.

-Pn   controls style of brace alignment. -P1 implies brace is    
      maintained where it is. With P0, the brace is put on the   
      following line under the reserved word. Default value is P0 
      or just -p.

-Rn   controls overwriting of output file. -R1 prompts for      
      permission. and is the default value.

For example: Indent by two's, output to printer: SALTB >PRN -
I2C33P0

Warning...Do not allow ">newfile.c" to be same as INPUT file name 
as destruction of input source file by output file will occur.

Defaults: -i4-b1-c41 -h0-p1-r1 ... Les. Satenstein. 10 Aug 1988.




                   Justification for SALTB.EXE
                   ===========================

Being a believer that a well formatted program goes a long way to
aiding the reader in understanding what the author intended to do
in his code, I became frustrated with some of the code which
appeared in print and seemed to me, to be difficult to read.

This program is free for personal use under one condition. That
condition is that you advise me if you like it and you are using
it for hobby purposes. Use for other purposes such as accompany-
ing hardware sales, inclusion into offerings by other software
companies, corporations, etc is prohibited without obtaining the
appropriate license.


Licensing fees are:

      $25.00  per first copy.
      $15.00  second and subsequent copy.
  $200.00 for unlimited copies within the same organizat-
    ion.


Limitations.

The program is a text processor, As a consequence of it's
limitations all commentary should be placed to the right of the
comment slashes.


Condition of Use.

This code is distributed on an as-is basis. I do not guarantee to
make enhancements to the program or fix reported bugs, but in the
spirit of good will, I am prepared to do so. I will not be
financially liable for damages caused by misuse of or errors
generated by this program. If you misuse it, don't blame the
program, programmer or the author.

If you appreciate this program and it's enhancements, Please drop
me a note. I thrive on "ATA-BOY",s and feel that my rework effort
below deserves at least one or two.

I have revised and corrected the program for those c programmers
who have pride in their workmanship, and want to deliver the c
program they write in a consistent style which gives the program
the appearance of a work of art.

One final condition. If you use this program and like it, you
must drop me a post card containing a message similar to the
following:
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³From  _____________________                        ÚÄÄÄÄÄÄ¿   ³
³      _____________________                        ³      ³   ³
³      _____________________                        ³      ³   ³
³      _____________________                        ÀÄÄÄÄÄÄÙ   ³
³                                                              ³
³                                                              ³
³                             Leslie Satenstein                ³
³                             220 Croissant de l'Arcade        ³
³                             Laval, Quebec                    ³
³                             Canada H7W 4Y3                   ³
³                                                              ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Attention: Leslie.            ³                              ³
³                                                              ³
³ Atta-boy. Well Done.                                         ³
³                               ³                              ³
³                                                              ³
³                               ³                              ³
³ Yours Truly                   ³                              ³
³                                                              ³
³ ____________________________  ³                              ³
³                                                              ³
³ P.S. Improvements could be....³                              ³
³                                                              ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
                                
lss. 10  August 1988            
                                
                                
                                