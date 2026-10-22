#include <stdio.h>

extern ཧྲིལ Array3[10];
ཧྲིལ Array3[] = { 12, 34, };
ཧྲིལ གཙོ()
{
   ཧྲིལ Count;

   ཧྲིལ Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   ཆེད་དུ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   ཧྲིལ Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   ཆེད་དུ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   ཆེད་དུ (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
