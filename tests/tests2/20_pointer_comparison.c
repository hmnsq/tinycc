#include <stdio.h>

целое основной()
{
   целое a;
   целое b;
   целое *d;
   целое *e;
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

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
