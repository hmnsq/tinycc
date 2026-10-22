#include <stdio.h>

ціле main()
{
   ціле a;
   char b;

   a = 0;
   поки (a < 2)
   {
      printf("%d", a++);
      break;

      b = 'A';
      поки (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
