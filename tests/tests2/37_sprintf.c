#include <stdio.h>

정수 main()
{
   char Buf[100];
   정수 Count;

   위해 (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
