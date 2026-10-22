/* example from http://barnyard.syr.edu/quickies/hanoi.c */

/* hanoi.c: solves the tower of hanoi problem. (Programming exercise.) */
/* By Terry R. McConnell (12/2/97) */
/* Compile: cc -o hanoi hanoi.c */

/* This program does no error checking. But then, if it's right, 
   it's right ... right ? */


/* The original towers of hanoi problem seems to have been originally posed
   by one M. Claus in 1883. There is a popular legend that goes along with
   it that has been often repeated and paraphrased. It goes something like this:
   In the great temple at Benares there are 3 golden spikes. On one of them,
   God placed 64 disks increasing in size from bottom to top, at the beginning
   of time. Since then, and to this day, the priest on duty constantly transfers
   disks, one at a time, in such a way that no larger disk is ever put on top
   of a smaller one. When the disks have been transferred entirely to another
   spike the Universe will come to an end in a large thunderclap.

   This paraphrases the original legend due to DeParville, La Nature, Paris 1884,
   Part I, 285-286. For this and further information see: Mathematical 
   Recreations & Essays, W.W. Rouse Ball, MacMillan, NewYork, 11th Ed. 1967,
   303-305.
 *
 *
 */

#समावेश <stdio.h>
#समावेश <stdlib.h>

#घोषणा TRUE 1
#घोषणा FALSE 0

/* This is the number of "disks" on tower A initially. Taken to be 64 in the
 * legend. The number of moves required, in general, is 2^N - 1. For N = 64,
 * this is 18,446,744,073,709,551,615 */
#घोषणा N 4

/* These are the three towers. For example if the state of A is 0,1,3,4, that
 * means that there are three discs on A of sizes 1, 3, and 4. (Think of right
 * as being the "down" direction.) */
पूर्णांक A[N], B[N], C[N]; 

व्योम Hanoi(पूर्णांक,पूर्णांक*,पूर्णांक*,पूर्णांक*);

/* Print the current configuration of A, B, and C to the screen */
व्योम PrintAll()
{
   पूर्णांक i;

   म_लिखो("A: ");
   क्रम(i=0;i<N;i++)म_लिखो(" %d ",A[i]);
   म_लिखो("\n");

   म_लिखो("B: ");
   क्रम(i=0;i<N;i++)म_लिखो(" %d ",B[i]);
   म_लिखो("\n");

   म_लिखो("C: ");
   क्रम(i=0;i<N;i++)म_लिखो(" %d ",C[i]);
   म_लिखो("\n");
   म_लिखो("------------------------------------------\n");
   वापस;
}

/* Move the leftmost nonzero element of source to dest, leave behind 0. */
/* Returns the value moved (not used.) */
पूर्णांक Move(पूर्णांक *source, पूर्णांक *dest)
{
   पूर्णांक i = 0, j = 0;

   जबतक (i<N && (source[i])==0) i++;
   जबतक (j<N && (dest[j])==0) j++;

   dest[j-1] = source[i];
   source[i] = 0;
   PrintAll();       /* Print configuration after each move. */
   वापस dest[j-1];
}


/* Moves first n nonzero numbers from source to dest using the rules of Hanoi.
   Calls itself recursively.
   */
व्योम Hanoi(पूर्णांक n,पूर्णांक *source, पूर्णांक *dest, पूर्णांक *spare)
{
   पूर्णांक i;
   अगर(n==1){
      Move(source,dest);
      वापस;
   }

   Hanoi(n-1,source,spare,dest);
   Move(source,dest);
   Hanoi(n-1,spare,dest,source);	
   वापस;
}

पूर्णांक मुख्य()
{
   पूर्णांक i;

   /* initialize the towers */
   क्रम(i=0;i<N;i++)A[i]=i+1;
   क्रम(i=0;i<N;i++)B[i]=0;
   क्रम(i=0;i<N;i++)C[i]=0;

   म_लिखो("Solution of Tower of Hanoi Problem with %d Disks\n\n",N);

   /* Print the starting state */
   म_लिखो("Starting state:\n");
   PrintAll();
   म_लिखो("\n\nSubsequent states:\n\n");

   /* Do it! Use A = Source, B = Destination, C = Spare */
   Hanoi(N,A,B,C);

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
