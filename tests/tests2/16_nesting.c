#include <stdio.h>

ចំនួនគត់ main()
{
   ចំនួនគត់ x, y, z;

   សម្រាប់ (x = 0; x < 2; x++)
   {
      សម្រាប់ (y = 0; y < 3; y++)
      {
         សម្រាប់ (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
