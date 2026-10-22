#include <stdio.h>

void fred(정수 x)
{
   switch (x)
   {
      case 1: printf("1\n"); 반환;
      case 2: printf("2\n"); break;
      case 3: printf("3\n"); 반환;
   }

   printf("out\n");
}

정수 main()
{
   fred(1);
   fred(2);
   fred(3);

   반환 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
