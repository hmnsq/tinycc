#include <stdio.h>

static 整数 fred = 1234;
static 整数 joe;

void henry()
{
   static 整数 fred = 4567;

   printf("%d\n", fred);
   fred++;
}

整数 主要()
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

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
