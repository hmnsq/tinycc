#include <stdio.h>

整数 メインページ()
{
   整数 Count = 0;

   ために (;;)
   {
      Count++;
      printf("%d\n", Count);
      もし (Count >= 10)
         break;
   }

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
