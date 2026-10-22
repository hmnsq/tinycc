#include <stdio.h>

整数 メインページ()
{
   整数 a;
   char b;

   a = 0;
   ながら (a < 2)
   {
      printf("%d", a++);
      break;

      b = 'A';
      ながら (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
