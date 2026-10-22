#include <stdio.h>

extern puur_naa_nka Array3[10];
puur_naa_nka Array3[] = { 12, 34, };
puur_naa_nka main()
{
   puur_naa_nka Count;

   puur_naa_nka Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   for (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   puur_naa_nka Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   for (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   for (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   ᮝᮜᮤ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
