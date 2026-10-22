#include <stdio.h>

целое основной()
{
   целое a[4][4];
   целое b = 0;
   целое x;
   целое y;

   для (x = 0; x < 4; x++)
   {
      для (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   для (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      для (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
