#include <stdio.h>

цяло main()
{
   цяло a;
   цяло p;
   цяло t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } докато (a < 100);

   върни 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
