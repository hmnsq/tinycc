#include <stdio.h>

số_nguyên main()
{
   số_nguyên a[4][4];
   số_nguyên b = 0;
   số_nguyên x;
   số_nguyên y;

   cho (x = 0; x < 4; x++)
   {
      cho (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   cho (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      cho (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
