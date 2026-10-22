#include <stdio.h>

ကိန်းပြည့် main()
{
   ကိန်းပြည့် a;
   ကိန်းပြည့် p;
   ကိန်းပြည့် t;

   a = 1;
   p = 0;
   t = 0;

   နေစဉ် (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   ပြန်ပေး 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
