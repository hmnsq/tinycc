#include <stdio.h>

puur_naa_nka main()
{
   puur_naa_nka a;
   puur_naa_nka b;
   puur_naa_nka *d;
   puur_naa_nka *e;
   d = &a;
   e = &b;
   a = 12;
   b = 34;
   printf("%d\n", *d);
   printf("%d\n", *e);
   printf("%d\n", d == e);
   printf("%d\n", d != e);
   d = e;
   printf("%d\n", d == e);
   printf("%d\n", d != e);

   ꦮꦭꦶ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
