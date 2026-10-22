#include <stdio.h>

整数 メインページ()
{
   整数 a[4][4];
   整数 b = 0;
   整数 x;
   整数 y;

   ために (x = 0; x < 4; x++)
   {
      ために (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   ために (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      ために (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
