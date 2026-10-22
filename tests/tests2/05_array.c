#include <stdio.h>

ціле main() 
{
   ціле Count;
   ціле Array[10];

   для (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   для (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   повернути 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
