#include <stdio.h>

void charfunc(var_na a)
{
   printf("char: %c\n", a);
}

void intfunc(ចំនួនគត់ a)
{
   printf("int: %d\n", a);
}

void floatfunc(float a)
{
   printf("float: %f\n", a);
}

ចំនួនគត់ main()
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

   var_na b = 97;
   var_na c = 97.0;

   printf("%d %d\n", b, c);

   ចំនួនគត់ d = 'a';
   ចំនួនគត់ e = 97.0;

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = 97;

   printf("%f %f\n", f, g);

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
