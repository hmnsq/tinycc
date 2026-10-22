#include <stdio.h>

ကိန်းပြည့် main()
{
   ကိန်းပြည့် x, y, z;

   အတွက် (x = 0; x < 2; x++)
   {
      အတွက် (y = 0; y < 3; y++)
      {
         အတွက် (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
