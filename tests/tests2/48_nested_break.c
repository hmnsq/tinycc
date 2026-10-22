#include <stdio.h>

整数 主要()
{
   整数 a;
   char b;

   a = 0;
   当 (a < 2)
   {
      printf("%d", a++);
      break;

      b = 'A';
      当 (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
