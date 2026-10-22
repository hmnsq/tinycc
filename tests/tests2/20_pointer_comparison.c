#include <stdio.h>

정수 main()
{
   정수 a;
   정수 b;
   정수 *d;
   정수 *e;
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

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
