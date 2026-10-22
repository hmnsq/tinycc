#include <stdio.h>

정수 main()
{
   정수 a[4][4];
   정수 b = 0;
   정수 x;
   정수 y;

   위해 (x = 0; x < 4; x++)
   {
      위해 (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   위해 (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      위해 (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
