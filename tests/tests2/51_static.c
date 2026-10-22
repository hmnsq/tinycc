#include <stdio.h>

static целое fred = 1234;
static целое joe;

void henry()
{
   static целое fred = 4567;

   printf("%d\n", fred);
   fred++;
}

целое основной()
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

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
