#include <stdio.h>

static цео fred = 1234;
static цео joe;

void henry()
{
   static цео fred = 4567;

   printf("%d\n", fred);
   fred++;
}

цео main()
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

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
