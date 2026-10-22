#include <stdio.h>

целое основной()
{
   целое a;
   char b;

   a = 0;
   пока (a < 2)
   {
      printf("%d", a++);
      break;

      b = 'A';
      пока (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
