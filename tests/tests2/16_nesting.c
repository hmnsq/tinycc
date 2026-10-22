#include <stdio.h>

整数 主要()
{
   整数 x, y, z;

   为 (x = 0; x < 2; x++)
   {
      为 (y = 0; y < 3; y++)
      {
         为 (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
