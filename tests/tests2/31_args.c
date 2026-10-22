#ضمن <stdio.h>

صحيح اصلی(صحيح argc, حرف **argv)
{
   صحيح شمار_3;

   چاپ_کن("hello world %d\n", argc);
   لكل (شمار_3 = 1; شمار_3 < argc; شمار_3++)
      چاپ_کن("arg %d: %s\n", شمار_3, argv[شمار_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
