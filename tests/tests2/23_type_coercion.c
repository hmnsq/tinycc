#ضمن <stdio.h>

فراغ charfunc(حرف a)
{
   printf("char: %c\n", a);
}

فراغ intfunc(صحيح a)
{
   printf("int: %d\n", a);
}

فراغ floatfunc(عائم a)
{
   printf("float: %f\n", a);
}

صحيح الرئيسية()
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

   حرف b = 97;
   حرف c = 97.0;

   printf("%d %d\n", b, c);

   صحيح d = 'a';
   صحيح e = 97.0;

   printf("%d %d\n", d, e);

   عائم f = 'a';
   عائم g = 97;

   printf("%f %f\n", f, g);

   إرجاع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
