#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ x, y, z;

   ສຳລັບ (x = 0; x < 2; x++)
   {
      ສຳລັບ (y = 0; y < 3; y++)
      {
         ສຳລັບ (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
