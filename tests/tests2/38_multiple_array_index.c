#include <stdio.h>

ကိန်းပြည့် main()
{
   ကိန်းပြည့် a[4][4];
   ကိန်းပြည့် b = 0;
   ကိန်းပြည့် x;
   ကိန်းပြည့် y;

   အတွက် (x = 0; x < 4; x++)
   {
      အတွက် (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   အတွက် (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      အတွက် (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
