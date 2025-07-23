In HANOI.WLD, a robot solves the Towers of Hanoi puzzle.  In case you aren't
familiar with the Towers of Hanoi puzzle, the object is to transfer the
stack of disks from the first peg to the third peg in the smallest number of
moves, while observing the following rules:
* Each move consists of taking the top disk from one peg and dropping it
  onto one of the other pegs.
* You must never put a disk on top of a smaller disk.
 
Interesting notes:
The puzzle can in theory consist of any number of disks.  The smallest
number of moves is (2^n)-1, where n is the number of disks.  In HANOI.WLD,
there are 4 disks, so the puzzle is solved in 15 moves.  The puzzle can be
done in the smallest possible number of moves by following this recursive
algorithm:
 
move(int how_many, int from_peg, int to_peg)
{
  int other_peg = 3 - from_peg - to_peg;
 
  if ( how_many == 1 )
    /* actually move the disk */
  else {
    move(how_many - 1, from_peg, other_peg);
    move(1, from_peg, to_peg);
    move(how_many - 1, other_peg, to_peg);
  }
}
 
main()
{
  move(NUMDISKS, 0, 2);
}
 
Unfortunately, algorithms like this can't be implemented in VR BASIC, so for
HANOI.WLD I had to write out the whole sequence of 15 moves.
 
I hope you like it!  Send comments, questions, etc. to
Peter Campbell
CompuServe: 74150,3076
Internet:   74150.3076@compuserve.com
 
