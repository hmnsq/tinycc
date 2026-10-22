#include <stdio.h>

정수 main()
{
   정수 x, y, z;

   위해 (x = 0; x < 2; x++)
   {
      위해 (y = 0; y < 3; y++)
      {
         위해 (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
