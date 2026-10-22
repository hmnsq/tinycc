#include <stdio.h>

整数 factorial(整数 i) 
{
   如果 (i < 2)
      返回 i;
   否则
      返回 i * factorial(i - 1);
}

整数 主要()
{
   整数 Count;

   为 (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
