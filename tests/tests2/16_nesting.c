#include <stdio.h>

จำนวนเต็ม หลัก()
{
   จำนวนเต็ม x, y, z;

   สำหรับ (x = 0; x < 2; x++)
   {
      สำหรับ (y = 0; y < 3; y++)
      {
         สำหรับ (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
