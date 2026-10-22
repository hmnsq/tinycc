#include <stdio.h>

số_nguyên main() 
{
   số_nguyên Count;
   số_nguyên Array[10];

   cho (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   cho (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   trả_về 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
