#include <stdio.h>

цяло main()
{
   char Buf[100];
   цяло Count;

   за (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
