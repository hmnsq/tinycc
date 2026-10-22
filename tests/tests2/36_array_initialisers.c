#include <stdio.h>

extern ཧྲིལ Array3[10];
ཧྲིལ Array3[] = { 12, 34, };
ཧྲིལ main()
{
   ཧྲིལ Count;

   ཧྲིལ Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   དོན་ལུ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   ཧྲིལ Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   དོན་ལུ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   དོན་ལུ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
