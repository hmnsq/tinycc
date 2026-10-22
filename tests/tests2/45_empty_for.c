#include <stdio.h>

цяло main()
{
   цяло Count = 0;

   за (;;)
   {
      Count++;
      printf("%d\n", Count);
      ако (Count >= 10)
         break;
   }

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
