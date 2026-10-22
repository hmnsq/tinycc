#include <stdio.h>

整数 メインページ()
{
   char Buf[100];
   整数 Count;

   ために (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
