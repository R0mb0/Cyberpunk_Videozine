             HYPE - A simple Hypertext system for the PC


HYPE is a simple hypertext demonstration for the IBM PC. It is
useful for on-line documentation, CAI etc., It is provided with
full source code to encourage experimentation.

Startup

1. Boot the system.
2. Insert the disk containing HYPE.COM in Drive A:
3. If the DOS prompt is not A>, type A: and press the ENTER key to switch
   to drive A:.
4. Type HYPE filename and press RETURN. "filename" is the name of
   file containing the marked text. For example, "HYPE poker.hyp"
   will display the sample file which was supplied with HYPE.
5. HYPE will display its opening screen and wait for you to press
   a key.
6. HYPE will display the text file one page at a time.  Concepts
   which have threaded text associated with them are displayed in
   reverse video. One threaded concept will be diaplayed with a
   special cursor called the button. On a color display the button
   is yellow text on a black background. On a mono screen the text
   under the button is underlined. You can move through the text
   with the following commands:

     ->      - right arrow - move to next highlighted area
     <-      - left arrow - move back to previous highlighted
                            area
     Esc     - exit the current window and return to the one
               below it. If the window is the main window (the
               large one which is opened at the beginning of the
               program) the program is terminated and control is
               returned to DOS.
     PgUp    - display the next page of text.
     PgDn    - display the previous page
     Enter   - display the text threaded to the concept under
               the button.
     F10     - quit the program and return to DOS


HYPE files

Text files for HYPE should be ASCII files which contain no
control characters. The file is threaded using embedded marks and
control commands.


Embedded marks

Text is marked by surrounding text strings with "\" characters.
Text surrounded by "\" 's is displayed on the screen in reverse
video. Marks may not extend beyond the end of a line. Embedded
blanks within marked text are significant. Marks are not case
sensitive, thus \expert system\ is equivalent to \Expert System\,
but no \expert    system\. The "\" characters will not be
displayed on the screen.


Control commands

HYPE commands lines begin with ".." starting in column one. The
following commands are available:

..label          - labels text. If the <Enter> key is pressed
		   with button over "label" the file will be
		   searched until a line beginning with ..label is
		   found.

..end(label)     - end of text associated with "label". When
		   <Enter> pressed with the button on "label",
		   text between ..label and ..end(label) will be
		   displayed. Labeled blocks of text may be
		   nested or overlap. If ..end(label) cannot be
		   found HYPE will read to the end of the file.
		   The first block processed has the default
		   label, "main". If ..main and ..end(main)
		   cannot be found, it will be possible to read
		   the entire file sequentially. Blocks of text
		   may have more than one label, but each lable
		   should have its own end statement.

..file(label) filename
		 - associates the file, filename with "label".
		   The file is read and its text, up to
		   ..end(label), is displayed along with any text
		   in the current file. "file" commands may be
		   nested, but no more than 15 files may be open
		   at once. If you want to use more files, it
		   will be necessary to recompile the program.

..window(label) text_color,back_color,org_x,org_y,size_x,size_y
		- set parameters for the window displaying the
		  text associated with "label". All parameters
		  are integers. This command is optional. If it
		  is not included, default values will be used
		  for the window parameters. The parameters are:
      text_color - color of displayed text
      back_color - background color. Legal values for color are:
		       0  - black             8  - dark gray
		       1  - blue              9  - light blue
		       2  - green             10 - light green
		       3  - cyan              11 - light cyan
		       4  - red               12 - light red
		       5  - magenta           13 - light magenta
		       6  - brown             14 - yellow
		       7  - light gray        15 - white
		   On most monochrome monitors blue text is
		   displayed as underlined text.
      org_x,
      org_y      - The upper left hand corner of the window. The
		    upper left of the screen is location 1,1.
		    org_x,org_y is the first position in which
		    text may be written. The frame ins not part
		    of the window. The upper left corner of the
		    frame is at location org_x-1,org_y-1.
      size_x,
      size_y      - The number of colums and rows in the window.

      You may change some window parameters and accept defualts
      for others by not including values for parameters in the
      parameter list. For example,

       ..window(expert systems) 4,15,,,45,10

      accepts the default origin for the window, but will produce
      red text on a white background in a 45 column by 10 row
      window.

Example text file

..main
The object of the game of poker is to win the
pot.   The pot is made up of all \bets\ made by
all players in any one deal.   Each bet means
that the player thinks or hopes he or she has
the \best hand\.   When every player has bet as
much as he or she wants to,  the players show
their hands and the best hand wins the pot.
..end(main)

..best hand
Here is a list of the rank of poker hands :
  straight flush
  four of a kind
  \full house\
  \flush\
  straight
  three of a kind
  two pairs
  one pair
  highest card
..end(best hand)

..flush
When  a  hand contains all cards of the  same
suit,  it's called a flush. A straight flush
is when all of the cards are in sequence.  In
a  five card poker hand a royal flush is when
one  hand contains the A,K,Q,J and 10 of  one
suit.
..end(flush)

..full house
..window(full house) 4,15
A  full house is three cards of one rank  and
two cards of another rank, such as 4-4-4-9-9.
..end(full house)

..bets
How betting works.
Before the cards are dealt,  some poker games
may  require each player to place an  initial
amount in the pot. This is called the "ante".
A betting interval begins when a player  bets
one  or  more chips.  Players after that  can
either "call" , "raise" or "fold".
..end(bets)



Good   luck  with HYPE.   We would be very interested in  hearing   of
your  experiments,   enhancements or even (gasp) bugs that you may  find.
Please write to us with your comments or questions.

     Bill and Bev Thompson
     C/O AI Expert Magazine
     500 Howard St.
     San Francisco, CA 94105

or  on  the AI Expert BBS on Compuserv.  Our id is BillandBev Thompson,
[76703,4324]. You can also contact us on BIX, our id is bbt.

   Bill and Bev Thompson
