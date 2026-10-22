#include <stdio.h>

static 정수 fred = 1234;
static 정수 joe;

void henry()
{
   static 정수 fred = 4567;

   printf("%d\n", fred);
   fred++;
}

정수 main()
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

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
