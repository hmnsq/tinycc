#include <stdio.h>

puur_naa_nka main()
{
   puur_naa_nka a[4];

   a[0] = 12;
   a[1] = 23;
   a[2] = 34;
   a[3] = 45;

   printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);

   puur_naa_nka b[4];

   b = a;

   printf("%d %d %d %d\n", b[0], b[1], b[2], b[3]);

   ပွၵ်ႈ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
