#include <stdio.h>

ចំនួនគត់ main() 
{
   ចំនួនគត់ Count;
   ចំនួនគត់ Array[10];

   សម្រាប់ (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   សម្រាប់ (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   ត្រឡប់ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
