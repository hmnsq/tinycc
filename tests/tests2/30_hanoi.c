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

#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>

#ವ್ಯಾಖ್ಯಾನಿಸು TRUE 1
#ವ್ಯಾಖ್ಯಾನಿಸು FALSE 0

/* This is the number of "disks" on tower A initially. Taken to be 64 in the
 * legend. The number of moves required, in general, is 2^N - 1. For N = 64,
 * this is 18,446,744,073,709,551,615 */
#ವ್ಯಾಖ್ಯಾನಿಸು N 4

/* These are the three towers. For example if the state of A is 0,1,3,4, that
 * means that there are three discs on A of sizes 1, 3, and 4. (Think of right
 * as being the "down" direction.) */
ಪೂರ್ಣಾಂಕ A[N], B[N], C[N]; 

ಶೂನ್ಯ ಹನೋಯ್(ಪೂರ್ಣಾಂಕ,ಪೂರ್ಣಾಂಕ*,ಪೂರ್ಣಾಂಕ*,ಪೂರ್ಣಾಂಕ*);

/* Print the current configuration of A, B, and C to the screen */
ಶೂನ್ಯ PrintAll()
{
   ಪೂರ್ಣಾಂಕ i;

   ಬರೆ("A: ");
   ಗಾಗಿ(i=0;i<N;i++)ಬರೆ(" %d ",A[i]);
   ಬರೆ("\n");

   ಬರೆ("B: ");
   ಗಾಗಿ(i=0;i<N;i++)ಬರೆ(" %d ",B[i]);
   ಬರೆ("\n");

   ಬರೆ("C: ");
   ಗಾಗಿ(i=0;i<N;i++)ಬರೆ(" %d ",C[i]);
   ಬರೆ("\n");
   ಬರೆ("------------------------------------------\n");
   ಹಿಂತಿರುಗಿ;
}

/* Move the leftmost nonzero element of source to dest, leave behind 0. */
/* Returns the value moved (not used.) */
ಪೂರ್ಣಾಂಕ Move(ಪೂರ್ಣಾಂಕ *ಮೂಲ, ಪೂರ್ಣಾಂಕ *dest)
{
   ಪೂರ್ಣಾಂಕ i = 0, j = 0;

   ಆಗ (i<N && (ಮೂಲ[i])==0) i++;
   ಆಗ (j<N && (dest[j])==0) j++;

   dest[j-1] = ಮೂಲ[i];
   ಮೂಲ[i] = 0;
   PrintAll();       /* Print configuration after each move. */
   ಹಿಂತಿರುಗಿ dest[j-1];
}


/* Moves first n nonzero numbers from source to dest using the rules of Hanoi.
   Calls itself recursively.
   */
ಶೂನ್ಯ ಹನೋಯ್(ಪೂರ್ಣಾಂಕ n,ಪೂರ್ಣಾಂಕ *ಮೂಲ, ಪೂರ್ಣಾಂಕ *dest, ಪೂರ್ಣಾಂಕ *ಹೆಚ್ಚುವರಿ)
{
   ಪೂರ್ಣಾಂಕ i;
   ಆದರೆ(n==1){
      Move(ಮೂಲ,dest);
      ಹಿಂತಿರುಗಿ;
   }

   ಹನೋಯ್(n-1,ಮೂಲ,ಹೆಚ್ಚುವರಿ,dest);
   Move(ಮೂಲ,dest);
   ಹನೋಯ್(n-1,ಹೆಚ್ಚುವರಿ,dest,ಮೂಲ);	
   ಹಿಂತಿರುಗಿ;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಪೂರ್ಣಾಂಕ i;

   /* initialize the towers */
   ಗಾಗಿ(i=0;i<N;i++)A[i]=i+1;
   ಗಾಗಿ(i=0;i<N;i++)B[i]=0;
   ಗಾಗಿ(i=0;i<N;i++)C[i]=0;

   ಬರೆ("Solution of Tower of Hanoi Problem with %d Disks\n\n",N);

   /* Print the starting state */
   ಬರೆ("Starting state:\n");
   PrintAll();
   ಬರೆ("\n\nSubsequent states:\n\n");

   /* Do it! Use A = Source, B = Destination, C = Spare */
   ಹನೋಯ್(N,A,B,C);

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
