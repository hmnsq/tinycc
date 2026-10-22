#include <stdio.h>

정수 main()
{
   정수 a;
   정수 p;
   정수 t;

   a = 1;
   p = 0;
   t = 0;

   동안 (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   반환 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
