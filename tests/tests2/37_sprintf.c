#include <stdio.h>

ཧྲིལ གཙོ()
{
   var_na Buf[100];
   ཧྲིལ Count;

   ཆེད་དུ (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
