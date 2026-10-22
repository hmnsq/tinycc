#include <stdio.h>

целое основной()
{
   целое Count = 0;

   для (;;)
   {
      Count++;
      printf("%d\n", Count);
      если (Count >= 10)
         break;
   }

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
