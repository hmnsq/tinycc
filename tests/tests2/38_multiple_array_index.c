#include <stdio.h>

puur_naa_nka main()
{
   puur_naa_nka a[4][4];
   puur_naa_nka b = 0;
   puur_naa_nka x;
   puur_naa_nka y;

   for (x = 0; x < 4; x++)
   {
      for (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   for (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      for (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   ᬯᬮᬶ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
