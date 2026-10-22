#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   var_na Buf[100];
   ຈຳນວນເຕັມ Count;

   ສຳລັບ (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
