#include <stdio.h>

целое основной()
{
   целое a;
   целое p;
   целое t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } пока (a < 100);

   вернуть 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
