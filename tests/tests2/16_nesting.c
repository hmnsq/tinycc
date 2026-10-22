#include <stdio.h>

số_nguyên main()
{
   số_nguyên x, y, z;

   cho (x = 0; x < 2; x++)
   {
      cho (y = 0; y < 3; y++)
      {
         cho (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
