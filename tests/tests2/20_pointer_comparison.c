#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ a;
   ຈຳນວນເຕັມ b;
   ຈຳນວນເຕັມ *d;
   ຈຳນວນເຕັມ *e;
   d = &a;
   e = &b;
   a = 12;
   b = 34;
   printf("%d\n", *d);
   printf("%d\n", *e);
   printf("%d\n", d == e);
   printf("%d\n", d != e);
   d = e;
   printf("%d\n", d == e);
   printf("%d\n", d != e);

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
