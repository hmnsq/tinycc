#include <stdio.h>

ціле main()
{
   ціле Count = 0;

   для (;;)
   {
      Count++;
      printf("%d\n", Count);
      якщо (Count >= 10)
         break;
   }

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
