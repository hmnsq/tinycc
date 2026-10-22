#include <stdio.h>

පූර්ණ_සංඛ්‍යා main()
{
   var_na Buf[100];
   පූර්ණ_සංඛ්‍යා Count;

   සඳහා (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
