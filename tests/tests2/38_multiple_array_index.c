#include <stdio.h>

цяло main()
{
   цяло a[4][4];
   цяло b = 0;
   цяло x;
   цяло y;

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

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
