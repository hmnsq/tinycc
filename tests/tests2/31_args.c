#ضمن <stdio.h>

صحيح اصلي(صحيح argc, حرف **argv)
{
   صحيح شمېر_3;

   چاپ_کړه("hello world %d\n", argc);
   لكل (شمېر_3 = 1; شمېر_3 < argc; شمېر_3++)
      چاپ_کړه("arg %d: %s\n", شمېر_3, argv[شمېر_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
