#include <stdio.h>

static số_nguyên fred = 1234;
static số_nguyên joe;

void henry()
{
   static số_nguyên fred = 4567;

   printf("%d\n", fred);
   fred++;
}

số_nguyên main()
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

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
