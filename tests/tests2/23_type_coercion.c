#ଅନ୍ତର୍ଭାଵ <stdio.h>

ଶୂନ୍ୟ charfunc(ଅକ୍ଷର a)
{
   printf("char: %c\n", a);
}

ଶୂନ୍ୟ intfunc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
   printf("int: %d\n", a);
}

ଶୂନ୍ୟ floatfunc(ଦଶମିକ a)
{
   printf("float: %f\n", a);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
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

   ଅକ୍ଷର b = 97;
   ଅକ୍ଷର c = 97.0;

   printf("%d %d\n", b, c);

   ପୂର୍ଣ୍ଣସଂଖ୍ୟା d = 'a';
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା e = 97.0;

   printf("%d %d\n", d, e);

   ଦଶମିକ f = 'a';
   ଦଶମିକ g = 97;

   printf("%f %f\n", f, g);

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
