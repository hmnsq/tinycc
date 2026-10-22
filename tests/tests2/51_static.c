#include <stdio.h>

static ຈຳນວນເຕັມ fred = 1234;
static ຈຳນວນເຕັມ joe;

void henry()
{
   static ຈຳນວນເຕັມ fred = 4567;

   printf("%d\n", fred);
   fred++;
}

ຈຳນວນເຕັມ main()
{
   printf("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   printf("%d\n", fred);
   fred = 8901;
   joe = 2345;
   printf("%d\n", fred);
   printf("%d\n", joe);

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
