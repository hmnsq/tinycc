#include <stdio.h>

static ціле fred = 1234;
static ціле joe;

void henry()
{
   static ціле fred = 4567;

   printf("%d\n", fred);
   fred++;
}

ціле main()
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

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
