#include <stdio.h>

ཧྲིལ གཙོ()
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

   ཕྱིར 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
