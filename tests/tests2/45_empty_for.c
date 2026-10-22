#include <stdio.h>

整数 主要()
{
   整数 Count = 0;

   为 (;;)
   {
      Count++;
      printf("%d\n", Count);
      如果 (Count >= 10)
         break;
   }

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
