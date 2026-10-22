#include <stdio.h>

extern ចំនួនគត់ Array3[10];
ចំនួនគត់ Array3[] = { 12, 34, };
ចំនួនគត់ main()
{
   ចំនួនគត់ Count;

   ចំនួនគត់ Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   សម្រាប់ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   ចំនួនគត់ Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   សម្រាប់ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   សម្រាប់ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
