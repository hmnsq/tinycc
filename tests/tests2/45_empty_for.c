#include <stdio.h>

цео main()
{
   цео Count = 0;

   за (;;)
   {
      Count++;
      printf("%d\n", Count);
      ако (Count >= 10)
         break;
   }

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
