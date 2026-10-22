#include <stdio.h>

ཧྲིལ main()
{
   ཧྲིལ a;
   ཧྲིལ p;
   ཧྲིལ t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } སྐབས (a < 100);

   ལོག 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
