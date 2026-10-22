#include <stdio.h>

정수 main()
{
   정수 a;
   char b;

   a = 0;
   동안 (a < 2)
   {
      printf("%d", a++);
      break;

      b = 'A';
      동안 (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
