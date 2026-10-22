#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ a[4][4];
   ຈຳນວນເຕັມ b = 0;
   ຈຳນວນເຕັມ x;
   ຈຳນວນເຕັມ y;

   ສຳລັບ (x = 0; x < 4; x++)
   {
      ສຳລັບ (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   ສຳລັບ (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      ສຳລັບ (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
