#include <stdio.h>

static จำนวนเต็ม fred = 1234;
static จำนวนเต็ม joe;

void henry()
{
   static จำนวนเต็ม fred = 4567;

   printf("%d\n", fred);
   fred++;
}

จำนวนเต็ม หลัก()
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

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
