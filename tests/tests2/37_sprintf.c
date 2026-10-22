#include <stdio.h>

int main()
{
   char Buf[100];
   int बिलांग_3;

   for (बिलांग_3 = 1; बिलांग_3 <= 20; बिलांग_3++)
   {
      sprintf(Buf, "->%02d<-\n", बिलांग_3);
      printf("%s", Buf);
   }

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
