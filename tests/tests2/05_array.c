#include <stdio.h>

整数 主要() 
{
   整数 Count;
   整数 Array[10];

   为 (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   为 (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   返回 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
