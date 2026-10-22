#include <stdio.h>

số_nguyên main()
{
   số_nguyên Count;

   cho (Count = 0; Count < 4; Count++)
   {
      printf("%d\n", Count);
      switch (Count)
      {
         case 1:
            printf("%d\n", 1);
            break;

         case 2:
            printf("%d\n", 2);
            break;

         default:
            printf("%d\n", 0);
            break;
      }
   }

   trả_về 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
