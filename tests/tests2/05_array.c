#include <stdio.h>

ຈຳນວນເຕັມ main() 
{
   ຈຳນວນເຕັມ Count;
   ຈຳນວນເຕັມ Array[10];

   ສຳລັບ (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   ສຳລັບ (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   ສົ່ງຄືນ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
