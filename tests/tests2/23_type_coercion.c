#অন্তর্ভাব <stdio.h>

শূন্য charfunc(বর্ণ a)
{
   printf("char: %c\n", a);
}

শূন্য intfunc(পূর্ণাঙ্ক a)
{
   printf("int: %d\n", a);
}

শূন্য floatfunc(ভিন্ন a)
{
   printf("float: %f\n", a);
}

পূর্ণাঙ্ক main()
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

   বর্ণ b = 97;
   বর্ণ c = 97.0;

   printf("%d %d\n", b, c);

   পূর্ণাঙ্ক d = 'a';
   পূর্ণাঙ্ক e = 97.0;

   printf("%d %d\n", d, e);

   ভিন্ন f = 'a';
   ভিন্ন g = 97;

   printf("%f %f\n", f, g);

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
