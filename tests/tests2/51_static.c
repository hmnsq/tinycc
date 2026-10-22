#include <stdio.h>

static цяло fred = 1234;
static цяло joe;

void henry()
{
   static цяло fred = 4567;

   printf("%d\n", fred);
   fred++;
}

цяло main()
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

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
