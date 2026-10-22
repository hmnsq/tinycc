#include <stdio.h>

整数 メインページ()
{
   整数 x, y, z;

   ために (x = 0; x < 2; x++)
   {
      ために (y = 0; y < 3; y++)
      {
         ために (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
