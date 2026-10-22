#include <stdio.h>

целое factorial(целое i) 
{
   если (i < 2)
      вернуть i;
   иначе
      вернуть i * factorial(i - 1);
}

целое основной()
{
   целое Count;

   для (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
