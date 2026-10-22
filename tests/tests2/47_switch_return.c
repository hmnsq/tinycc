#include <stdio.h>

void fred(целое x)
{
   switch (x)
   {
      case 1: printf("1\n"); вернуть;
      case 2: printf("2\n"); break;
      case 3: printf("3\n"); вернуть;
   }

   printf("out\n");
}

целое основной()
{
   fred(1);
   fred(2);
   fred(3);

   вернуть 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
