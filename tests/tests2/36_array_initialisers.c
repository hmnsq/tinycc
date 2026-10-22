#include <stdio.h>

extern цяло Array3[10];
цяло Array3[] = { 12, 34, };
цяло main()
{
   цяло Count;

   цяло Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   за (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   цяло Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   за (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   за (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
