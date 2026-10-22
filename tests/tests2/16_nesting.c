#include <stdio.h>

цяло main()
{
   цяло x, y, z;

   за (x = 0; x < 2; x++)
   {
      за (y = 0; y < 3; y++)
      {
         за (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
