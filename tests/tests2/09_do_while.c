#include <stdio.h>

ціле main()
{
   ціле a;
   ціле p;
   ціле t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } поки (a < 100);

   повернути 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
