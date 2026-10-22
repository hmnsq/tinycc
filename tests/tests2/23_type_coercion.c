#include <stdio.h>

void charfunc(char a)
{
   printf("char: %c\n", a);
}

void intfunc(整数 a)
{
   printf("int: %d\n", a);
}

void floatfunc(float a)
{
   printf("float: %f\n", a);
}

整数 主要()
{
   charfunc('a');
   charfunc(98);
   charfunc(99.0);

   intfunc('a');
   intfunc(98);
   intfunc(99.0);

   floatfunc('a');
   floatfunc(98);
   floatfunc(99.0);

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = 97;
   char c = 97.0;

   printf("%d %d\n", b, c);

   整数 d = 'a';
   整数 e = 97.0;

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = 97;

   printf("%f %f\n", f, g);

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
