#include <stdio.h>

extern 정수 Array3[10];
정수 Array3[] = { 12, 34, };
정수 main()
{
   정수 Count;

   정수 Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   위해 (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   정수 Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   위해 (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   위해 (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
