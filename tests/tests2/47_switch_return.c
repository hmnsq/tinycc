#include <stdio.h>

void fred(ціле x)
{
   switch (x)
   {
      case 1: printf("1\n"); повернути;
      case 2: printf("2\n"); break;
      case 3: printf("3\n"); повернути;
   }

   printf("out\n");
}

ціле main()
{
   fred(1);
   fred(2);
   fred(3);

   повернути 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
