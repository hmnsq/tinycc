#include <stdio.h>

int main()
{
   int बिलांग_3;

   for (बिलांग_3 = 0; बिलांग_3 < 4; बिलांग_3++)
   {
      printf("%d\n", बिलांग_3);
      switch (बिलांग_3)
      {
         case 1:
            printf("%d\n", 1);
            break;

         case 2:
            printf("%d\n", 2);
            break;

         default:
            printf("%d\n", 0);
            break;
      }
   }

   return 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
