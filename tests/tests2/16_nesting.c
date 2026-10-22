#include <stdio.h>

පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා x, y, z;

   සඳහා (x = 0; x < 2; x++)
   {
      සඳහා (y = 0; y < 3; y++)
      {
         සඳහා (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
