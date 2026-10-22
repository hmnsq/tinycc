#include <stdio.h>

ຈຳນວນເຕັມ factorial(ຈຳນວນເຕັມ i) 
{
   ຖ້າ (i < 2)
      ສົ່ງຄືນ i;
   ບໍ່ດັ່ງນັ້ນ
      ສົ່ງຄືນ i * factorial(i - 1);
}

ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ Count;

   ສຳລັບ (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
