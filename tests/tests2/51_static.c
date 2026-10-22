#include <stdio.h>

static ကိန်းပြည့် fred = 1234;
static ကိန်းပြည့် joe;

void henry()
{
   static ကိန်းပြည့် fred = 4567;

   printf("%d\n", fred);
   fred++;
}

ကိန်းပြည့် main()
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

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
