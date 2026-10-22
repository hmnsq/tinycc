#include <stdio.h>

extern ຈຳນວນເຕັມ Array3[10];
ຈຳນວນເຕັມ Array3[] = { 12, 34, };
ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ Count;

   ຈຳນວນເຕັມ Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   ສຳລັບ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   ຈຳນວນເຕັມ Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   ສຳລັບ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   ສຳລັບ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
