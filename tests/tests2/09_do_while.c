#include <stdio.h>

ចំនួនគត់ main()
{
   ចំនួនគត់ a;
   ចំនួនគត់ p;
   ចំនួនគត់ t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } ខណៈពេល (a < 100);

   ត្រឡប់ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
