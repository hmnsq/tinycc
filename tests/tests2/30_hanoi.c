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

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRUE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FALSE 0

/* This is the number of "disks" on tower A initially. Taken to be 64 in the
 * legend. The number of moves required, in general, is 2^N - 1. For N = 64,
 * this is 18,446,744,073,709,551,615 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N 4

/* These are the three towers. For example if the state of A is 0,1,3,4, that
 * means that there are three discs on A of sizes 1, 3, and 4. (Think of right
 * as being the "down" direction.) */
ਪੂਰਨ A[N], B[N], C[N]; 

ਖਾਲੀ ਹਨੋਈ(ਪੂਰਨ,ਪੂਰਨ*,ਪੂਰਨ*,ਪੂਰਨ*);

/* Print the current configuration of A, B, and C to the screen */
ਖਾਲੀ PrintAll()
{
   ਪੂਰਨ i;

   ਲਿਖੋ("A: ");
   ਲਈ(i=0;i<N;i++)ਲਿਖੋ(" %d ",A[i]);
   ਲਿਖੋ("\n");

   ਲਿਖੋ("B: ");
   ਲਈ(i=0;i<N;i++)ਲਿਖੋ(" %d ",B[i]);
   ਲਿਖੋ("\n");

   ਲਿਖੋ("C: ");
   ਲਈ(i=0;i<N;i++)ਲਿਖੋ(" %d ",C[i]);
   ਲਿਖੋ("\n");
   ਲਿਖੋ("------------------------------------------\n");
   ਵਾਪਸ;
}

/* Move the leftmost nonzero element of source to dest, leave behind 0. */
/* Returns the value moved (not used.) */
ਪੂਰਨ Move(ਪੂਰਨ *ਸਰੋਤ, ਪੂਰਨ *dest)
{
   ਪੂਰਨ i = 0, j = 0;

   ਜਦੋਂ (i<N && (ਸਰੋਤ[i])==0) i++;
   ਜਦੋਂ (j<N && (dest[j])==0) j++;

   dest[j-1] = ਸਰੋਤ[i];
   ਸਰੋਤ[i] = 0;
   PrintAll();       /* Print configuration after each move. */
   ਵਾਪਸ dest[j-1];
}


/* Moves first n nonzero numbers from source to dest using the rules of Hanoi.
   Calls itself recursively.
   */
ਖਾਲੀ ਹਨੋਈ(ਪੂਰਨ n,ਪੂਰਨ *ਸਰੋਤ, ਪੂਰਨ *dest, ਪੂਰਨ *ਵਾਧੂ)
{
   ਪੂਰਨ i;
   ਜੇ(n==1){
      Move(ਸਰੋਤ,dest);
      ਵਾਪਸ;
   }

   ਹਨੋਈ(n-1,ਸਰੋਤ,ਵਾਧੂ,dest);
   Move(ਸਰੋਤ,dest);
   ਹਨੋਈ(n-1,ਵਾਧੂ,dest,ਸਰੋਤ);	
   ਵਾਪਸ;
}

ਪੂਰਨ ਮੁੱਖ()
{
   ਪੂਰਨ i;

   /* initialize the towers */
   ਲਈ(i=0;i<N;i++)A[i]=i+1;
   ਲਈ(i=0;i<N;i++)B[i]=0;
   ਲਈ(i=0;i<N;i++)C[i]=0;

   ਲਿਖੋ("Solution of Tower of Hanoi Problem with %d Disks\n\n",N);

   /* Print the starting state */
   ਲਿਖੋ("Starting state:\n");
   PrintAll();
   ਲਿਖੋ("\n\nSubsequent states:\n\n");

   /* Do it! Use A = Source, B = Destination, C = Spare */
   ਹਨੋਈ(N,A,B,C);

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
