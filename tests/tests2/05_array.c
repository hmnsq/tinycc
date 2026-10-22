#include <stdio.h>

整数 メインページ() 
{
   整数 Count;
   整数 Array[10];

   ために (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   ために (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   戻る 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
