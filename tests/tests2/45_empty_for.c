#include <stdio.h>

int main()
{
   int बिलांग_3 = 0;

   for (;;)
   {
      बिलांग_3++;
      printf("%d\n", बिलांग_3);
      if (बिलांग_3 >= 10)
         break;
   }

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
