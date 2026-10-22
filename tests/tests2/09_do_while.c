#include <stdio.h>

цео main()
{
   цео a;
   цео p;
   цео t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } док (a < 100);

   врати 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
