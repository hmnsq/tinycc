#include <stdio.h>

ཧྲིལ གཙོ()
{
   ཧྲིལ a[4][4];
   ཧྲིལ b = 0;
   ཧྲིལ x;
   ཧྲིལ y;

   ཆེད་དུ (x = 0; x < 4; x++)
   {
      ཆེད་དུ (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   ཆེད་དུ (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      ཆེད་དུ (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
