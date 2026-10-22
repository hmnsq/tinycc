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

#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdlib.h>

#నిర్వచించు TRUE 1
#నిర్వచించు FALSE 0

/* This is the number of "disks" on tower A initially. Taken to be 64 in the
 * legend. The number of moves required, in general, is 2^N - 1. For N = 64,
 * this is 18,446,744,073,709,551,615 */
#నిర్వచించు N 4

/* These are the three towers. For example if the state of A is 0,1,3,4, that
 * means that there are three discs on A of sizes 1, 3, and 4. (Think of right
 * as being the "down" direction.) */
పూర్ణాంకం A[N], B[N], C[N]; 

శూన్య హనోయ్(పూర్ణాంకం,పూర్ణాంకం*,పూర్ణాంకం*,పూర్ణాంకం*);

/* Print the current configuration of A, B, and C to the screen */
శూన్య PrintAll()
{
   పూర్ణాంకం i;

   రాయి("A: ");
   కొరకు(i=0;i<N;i++)రాయి(" %d ",A[i]);
   రాయి("\n");

   రాయి("B: ");
   కొరకు(i=0;i<N;i++)రాయి(" %d ",B[i]);
   రాయి("\n");

   రాయి("C: ");
   కొరకు(i=0;i<N;i++)రాయి(" %d ",C[i]);
   రాయి("\n");
   రాయి("------------------------------------------\n");
   తిరిగి;
}

/* Move the leftmost nonzero element of source to dest, leave behind 0. */
/* Returns the value moved (not used.) */
పూర్ణాంకం Move(పూర్ణాంకం *ఆధారం, పూర్ణాంకం *dest)
{
   పూర్ణాంకం i = 0, j = 0;

   అయితే (i<N && (ఆధారం[i])==0) i++;
   అయితే (j<N && (dest[j])==0) j++;

   dest[j-1] = ఆధారం[i];
   ఆధారం[i] = 0;
   PrintAll();       /* Print configuration after each move. */
   తిరిగి dest[j-1];
}


/* Moves first n nonzero numbers from source to dest using the rules of Hanoi.
   Calls itself recursively.
   */
శూన్య హనోయ్(పూర్ణాంకం n,పూర్ణాంకం *ఆధారం, పూర్ణాంకం *dest, పూర్ణాంకం *అదనపు)
{
   పూర్ణాంకం i;
   ఒకవేళ(n==1){
      Move(ఆధారం,dest);
      తిరిగి;
   }

   హనోయ్(n-1,ఆధారం,అదనపు,dest);
   Move(ఆధారం,dest);
   హనోయ్(n-1,అదనపు,dest,ఆధారం);	
   తిరిగి;
}

పూర్ణాంకం ప్రధాన()
{
   పూర్ణాంకం i;

   /* initialize the towers */
   కొరకు(i=0;i<N;i++)A[i]=i+1;
   కొరకు(i=0;i<N;i++)B[i]=0;
   కొరకు(i=0;i<N;i++)C[i]=0;

   రాయి("Solution of Tower of Hanoi Problem with %d Disks\n\n",N);

   /* Print the starting state */
   రాయి("Starting state:\n");
   PrintAll();
   రాయి("\n\nSubsequent states:\n\n");

   /* Do it! Use A = Source, B = Destination, C = Spare */
   హనోయ్(N,A,B,C);

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
