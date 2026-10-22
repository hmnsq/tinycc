#include <stdio.h>

ចំនួនគត់ main()
{
   var_na Buf[100];
   ចំនួនគត់ Count;

   សម្រាប់ (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
