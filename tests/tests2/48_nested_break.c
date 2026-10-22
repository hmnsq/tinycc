#include <stdio.h>

цяло main()
{
   цяло a;
   char b;

   a = 0;
   докато (a < 2)
   {
      printf("%d", a++);
      break;

      b = 'A';
      докато (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
