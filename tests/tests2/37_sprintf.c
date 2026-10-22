#include <stdio.h>

ཧྲིལ main()
{
   var_na Buf[100];
   ཧྲིལ Count;

   དོན་ལུ (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
