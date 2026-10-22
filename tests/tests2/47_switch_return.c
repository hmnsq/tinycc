#include <stdio.h>

void fred(整数 x)
{
   switch (x)
   {
      case 1: printf("1\n"); 返回;
      case 2: printf("2\n"); break;
      case 3: printf("3\n"); 返回;
   }

   printf("out\n");
}

整数 主要()
{
   fred(1);
   fred(2);
   fred(3);

   返回 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
