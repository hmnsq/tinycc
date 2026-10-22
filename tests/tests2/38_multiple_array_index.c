#include <stdio.h>

ចំនួនគត់ main()
{
   ចំនួនគត់ a[4][4];
   ចំនួនគត់ b = 0;
   ចំនួនគត់ x;
   ចំនួនគត់ y;

   សម្រាប់ (x = 0; x < 4; x++)
   {
      សម្រាប់ (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   សម្រាប់ (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      សម្រាប់ (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
