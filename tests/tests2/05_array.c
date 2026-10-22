#include <stdio.h>

int main() 
{
   int बिलांग_3;
   int Array[10];

   for (बिलांग_3 = 1; बिलांग_3 <= 10; बिलांग_3++)
   {
      Array[बिलांग_3-1] = बिलांग_3 * बिलांग_3;
   }

   for (बिलांग_3 = 0; बिलांग_3 < 10; बिलांग_3++)
   {
      printf("%d\n", Array[बिलांग_3]);
   }

   return 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
