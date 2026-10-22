#include <stdio.h>

static ចំនួនគត់ fred = 1234;
static ចំនួនគត់ joe;

void henry()
{
   static ចំនួនគត់ fred = 4567;

   printf("%d\n", fred);
   fred++;
}

ចំនួនគត់ main()
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

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
