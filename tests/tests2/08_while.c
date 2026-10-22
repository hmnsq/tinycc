#include <stdio.h>

จำนวนเต็ม หลัก()
{
   จำนวนเต็ม a;
   จำนวนเต็ม p;
   จำนวนเต็ม t;

   a = 1;
   p = 0;
   t = 0;

   ขณะ (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   คืน 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
