#include <stdio.h>

จำนวนเต็ม หลัก()
{
   var_na Buf[100];
   จำนวนเต็ม Count;

   สำหรับ (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
