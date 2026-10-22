#include <stdio.h>

정수 main() 
{
   정수 Count;
   정수 Array[10];

   위해 (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   위해 (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   반환 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
