#include <stdio.h>

จำนวนเต็ม หลัก() 
{
   จำนวนเต็ม Count;
   จำนวนเต็ม Array[10];

   สำหรับ (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   สำหรับ (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   คืน 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
