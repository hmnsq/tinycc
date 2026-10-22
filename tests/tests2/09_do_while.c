#include <stdio.h>

số_nguyên main()
{
   số_nguyên a;
   số_nguyên p;
   số_nguyên t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } trong_khi (a < 100);

   trả_về 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
