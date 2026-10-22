#include <stdio.h>

цео main()
{
   цео a;
   цео p;
   цео t;

   a = 1;
   p = 0;
   t = 0;

   док (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   врати 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
