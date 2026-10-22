#include <stdio.h>

整数 メインページ()
{
   整数 a;
   整数 p;
   整数 t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } ながら (a < 100);

   戻る 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
