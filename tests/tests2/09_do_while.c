#include <stdio.h>

puur_naa_nka main()
{
   puur_naa_nka a;
   puur_naa_nka p;
   puur_naa_nka t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } ᰀᰬ (a < 100);

   ᰀᰧᰌ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
