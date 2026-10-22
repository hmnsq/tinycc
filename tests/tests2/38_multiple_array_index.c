#include <stdio.h>

ཧྲིལ main()
{
   ཧྲིལ a[4][4];
   ཧྲིལ b = 0;
   ཧྲིལ x;
   ཧྲིལ y;

   དོན་ལུ (x = 0; x < 4; x++)
   {
      དོན་ལུ (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   དོན་ལུ (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      དོན་ལུ (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
