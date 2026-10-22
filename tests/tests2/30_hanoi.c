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

#ضمن <stdio.h>
#ضمن <stdlib.h>

#تعریف_کن TRUE 1
#تعریف_کن FALSE 0

/* This is the number of "disks" on tower A initially. Taken to be 64 in the
 * legend. The number of moves required, in general, is 2^N - 1. For N = 64,
 * this is 18,446,744,073,709,551,615 */
#تعریف_کن N 4

/* These are the three towers. For example if the state of A is 0,1,3,4, that
 * means that there are three discs on A of sizes 1, 3, and 4. (Think of right
 * as being the "down" direction.) */
صحيح A[N], B[N], C[N]; 

فراغ هانوی(صحيح,صحيح*,صحيح*,صحيح*);

/* Print the current configuration of A, B, and C to the screen */
فراغ PrintAll()
{
   صحيح i;

   چاپ_کن("A: ");
   لكل(i=0;i<N;i++)چاپ_کن(" %d ",A[i]);
   چاپ_کن("\n");

   چاپ_کن("B: ");
   لكل(i=0;i<N;i++)چاپ_کن(" %d ",B[i]);
   چاپ_کن("\n");

   چاپ_کن("C: ");
   لكل(i=0;i<N;i++)چاپ_کن(" %d ",C[i]);
   چاپ_کن("\n");
   چاپ_کن("------------------------------------------\n");
   أرجع;
}

/* Move the leftmost nonzero element of source to dest, leave behind 0. */
/* Returns the value moved (not used.) */
صحيح Move(صحيح *منبع, صحيح *dest)
{
   صحيح i = 0, j = 0;

   طالما (i<N && (منبع[i])==0) i++;
   طالما (j<N && (dest[j])==0) j++;

   dest[j-1] = منبع[i];
   منبع[i] = 0;
   PrintAll();       /* Print configuration after each move. */
   أرجع dest[j-1];
}


/* Moves first n nonzero numbers from source to dest using the rules of Hanoi.
   Calls itself recursively.
   */
فراغ هانوی(صحيح n,صحيح *منبع, صحيح *dest, صحيح *یدکی)
{
   صحيح i;
   إذا(n==1){
      Move(منبع,dest);
      أرجع;
   }

   هانوی(n-1,منبع,یدکی,dest);
   Move(منبع,dest);
   هانوی(n-1,یدکی,dest,منبع);	
   أرجع;
}

صحيح اصلی()
{
   صحيح i;

   /* initialize the towers */
   لكل(i=0;i<N;i++)A[i]=i+1;
   لكل(i=0;i<N;i++)B[i]=0;
   لكل(i=0;i<N;i++)C[i]=0;

   چاپ_کن("Solution of Tower of Hanoi Problem with %d Disks\n\n",N);

   /* Print the starting state */
   چاپ_کن("Starting state:\n");
   PrintAll();
   چاپ_کن("\n\nSubsequent states:\n\n");

   /* Do it! Use A = Source, B = Destination, C = Spare */
   هانوی(N,A,B,C);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
