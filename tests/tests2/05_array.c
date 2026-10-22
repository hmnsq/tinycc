#include <stdio.h>

цяло main() 
{
   цяло Count;
   цяло Array[10];

   за (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   за (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   върни 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
