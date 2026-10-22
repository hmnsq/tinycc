#include <stdio.h>

ကိန်းပြည့် main()
{
   var_na Buf[100];
   ကိန်းပြည့် Count;

   အတွက် (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
