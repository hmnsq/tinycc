#include <stdio.h>

整数 factorial(整数 i) 
{
   もし (i < 2)
      戻る i;
   否则
      戻る i * factorial(i - 1);
}

整数 メインページ()
{
   整数 Count;

   ために (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
