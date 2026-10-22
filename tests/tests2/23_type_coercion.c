#অন্তর্ভাব <stdio.h>

শূন্য charfunc(অক্ষর a)
{
   printf("char: %c\n", a);
}

শূন্য intfunc(পূর্ণসংখ্যা a)
{
   printf("int: %d\n", a);
}

শূন্য floatfunc(দশমিক a)
{
   printf("float: %f\n", a);
}

পূর্ণসংখ্যা প্রধান()
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

   অক্ষর b = 97;
   অক্ষর c = 97.0;

   printf("%d %d\n", b, c);

   পূর্ণসংখ্যা d = 'a';
   পূর্ণসংখ্যা e = 97.0;

   printf("%d %d\n", d, e);

   দশমিক f = 'a';
   দশমিক g = 97;

   printf("%f %f\n", f, g);

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
