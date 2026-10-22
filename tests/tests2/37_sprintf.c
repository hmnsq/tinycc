#include <stdio.h>

整数 主要()
{
   char Buf[100];
   整数 Count;

   为 (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
