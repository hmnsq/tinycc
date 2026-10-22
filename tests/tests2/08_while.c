#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ a;
   ຈຳນວນເຕັມ p;
   ຈຳນວນເຕັມ t;

   a = 1;
   p = 0;
   t = 0;

   ໃນຂະນະທີ່ (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   ສົ່ງຄືນ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
