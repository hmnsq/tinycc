#include <stdio.h>

static puur_naa_nka fred = 1234;
static puur_naa_nka joe;

void henry()
{
   static puur_naa_nka fred = 4567;

   printf("%d\n", fred);
   fred++;
}

puur_naa_nka main()
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

   ပွၵ်ႈ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
