#include <stdio.h>

extern จำนวนเต็ม Array3[10];
จำนวนเต็ม Array3[] = { 12, 34, };
จำนวนเต็ม หลัก()
{
   จำนวนเต็ม Count;

   จำนวนเต็ม Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   สำหรับ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   จำนวนเต็ม Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   สำหรับ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   สำหรับ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
