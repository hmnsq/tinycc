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

#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdlib.h>

#परिभाषय TRUE 1
#परिभाषय FALSE 0

/* This is the number of "disks" on tower A initially. Taken to be 64 in the
 * legend. The number of moves required, in general, is 2^N - 1. For N = 64,
 * this is 18,446,744,073,709,551,615 */
#परिभाषय N 4

/* These are the three towers. For example if the state of A is 0,1,3,4, that
 * means that there are three discs on A of sizes 1, 3, and 4. (Think of right
 * as being the "down" direction.) */
पूर्णाङ्क A[N], B[N], C[N]; 

शून्य हनोई(पूर्णाङ्क,पूर्णाङ्क*,पूर्णाङ्क*,पूर्णाङ्क*);

/* Print the current configuration of A, B, and C to the screen */
शून्य PrintAll()
{
   पूर्णाङ्क i;

   प्रारूप_लिख("A: ");
   प्रति(i=0;i<N;i++)प्रारूप_लिख(" %d ",A[i]);
   प्रारूप_लिख("\n");

   प्रारूप_लिख("B: ");
   प्रति(i=0;i<N;i++)प्रारूप_लिख(" %d ",B[i]);
   प्रारूप_लिख("\n");

   प्रारूप_लिख("C: ");
   प्रति(i=0;i<N;i++)प्रारूप_लिख(" %d ",C[i]);
   प्रारूप_लिख("\n");
   प्रारूप_लिख("------------------------------------------\n");
   प्रत्यागम;
}

/* Move the leftmost nonzero element of source to dest, leave behind 0. */
/* Returns the value moved (not used.) */
पूर्णाङ्क Move(पूर्णाङ्क *source, पूर्णाङ्क *dest)
{
   पूर्णाङ्क i = 0, j = 0;

   यावत् (i<N && (source[i])==0) i++;
   यावत् (j<N && (dest[j])==0) j++;

   dest[j-1] = source[i];
   source[i] = 0;
   PrintAll();       /* Print configuration after each move. */
   प्रत्यागम dest[j-1];
}


/* Moves first n nonzero numbers from source to dest using the rules of Hanoi.
   Calls itself recursively.
   */
शून्य हनोई(पूर्णाङ्क n,पूर्णाङ्क *source, पूर्णाङ्क *dest, पूर्णाङ्क *अतिरिक्तः)
{
   पूर्णाङ्क i;
   यदि(n==1){
      Move(source,dest);
      प्रत्यागम;
   }

   हनोई(n-1,source,अतिरिक्तः,dest);
   Move(source,dest);
   हनोई(n-1,अतिरिक्तः,dest,source);	
   प्रत्यागम;
}

पूर्णाङ्क मुख्यम्()
{
   पूर्णाङ्क i;

   /* initialize the towers */
   प्रति(i=0;i<N;i++)A[i]=i+1;
   प्रति(i=0;i<N;i++)B[i]=0;
   प्रति(i=0;i<N;i++)C[i]=0;

   प्रारूप_लिख("Solution of Tower of Hanoi Problem with %d Disks\n\n",N);

   /* Print the starting state */
   प्रारूप_लिख("Starting state:\n");
   PrintAll();
   प्रारूप_लिख("\n\nSubsequent states:\n\n");

   /* Do it! Use A = Source, B = Destination, C = Spare */
   हनोई(N,A,B,C);

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
