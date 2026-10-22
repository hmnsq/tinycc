#include <stdio.h>

цео main()
{
   цео a[4][4];
   цео b = 0;
   цео x;
   цео y;

   за (x = 0; x < 4; x++)
   {
      за (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   за (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      за (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
