#include <stdio.h>

ціле main()
{
   ціле x, y, z;

   для (x = 0; x < 2; x++)
   {
      для (y = 0; y < 3; y++)
      {
         для (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
