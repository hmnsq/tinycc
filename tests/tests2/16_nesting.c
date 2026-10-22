#include <stdio.h>

ཧྲིལ main()
{
   ཧྲིལ x, y, z;

   དོན་ལུ (x = 0; x < 2; x++)
   {
      དོན་ལུ (y = 0; y < 3; y++)
      {
         དོན་ལུ (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
