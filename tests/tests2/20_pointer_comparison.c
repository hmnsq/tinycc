#include <stdio.h>

ကိန်းပြည့် main()
{
   ကိန်းပြည့် a;
   ကိန်းပြည့် b;
   ကိန်းပြည့် *d;
   ကိန်းပြည့် *e;
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

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
