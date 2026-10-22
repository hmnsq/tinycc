#include <stdio.h>

static ཧྲིལ fred = 1234;
static ཧྲིལ joe;

void henry()
{
   static ཧྲིལ fred = 4567;

   printf("%d\n", fred);
   fred++;
}

ཧྲིལ main()
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

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
