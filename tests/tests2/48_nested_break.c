#include <stdio.h>

цео main()
{
   цео a;
   char b;

   a = 0;
   док (a < 2)
   {
      printf("%d", a++);
      break;

      b = 'A';
      док (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
