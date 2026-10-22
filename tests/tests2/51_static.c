#include <stdio.h>

static පූර්ණ_සංඛ්‍යා fred = 1234;
static පූර්ණ_සංඛ්‍යා joe;

void henry()
{
   static පූර්ණ_සංඛ්‍යා fred = 4567;

   printf("%d\n", fred);
   fred++;
}

පූර්ණ_සංඛ්‍යා main()
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

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
