#include <stdio.h>

จำนวนเต็ม factorial(จำนวนเต็ม i) 
{
   ถ้า (i < 2)
      คืน i;
   มิฉะนั้น
      คืน i * factorial(i - 1);
}

จำนวนเต็ม หลัก()
{
   จำนวนเต็ม Count;

   สำหรับ (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
