#include <stdio.h>

void fred(整数 x)
{
   switch (x)
   {
      case 1: printf("1\n"); 戻る;
      case 2: printf("2\n"); break;
      case 3: printf("3\n"); 戻る;
   }

   printf("out\n");
}

整数 メインページ()
{
   fred(1);
   fred(2);
   fred(3);

   戻る 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
