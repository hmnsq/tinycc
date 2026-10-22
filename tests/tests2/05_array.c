#include <stdio.h>

ཧྲིལ main() 
{
   ཧྲིལ Count;
   ཧྲིལ Array[10];

   དོན་ལུ (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   དོན་ལུ (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   ལོག 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
