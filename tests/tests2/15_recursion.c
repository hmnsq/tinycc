#include <stdio.h>

số_nguyên factorial(số_nguyên i) 
{
   nếu (i < 2)
      trả_về i;
   không_thì
      trả_về i * factorial(i - 1);
}

số_nguyên main()
{
   số_nguyên Count;

   cho (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
