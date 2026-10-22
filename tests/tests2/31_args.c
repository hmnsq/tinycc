#ضمن <stdio.h>

صحيح الرئيسية(صحيح argc, حرف **argv)
{
   صحيح تعداد_4;

   printf("hello world %d\n", argc);
   لكل (تعداد_4 = 1; تعداد_4 < argc; تعداد_4++)
      printf("arg %d: %s\n", تعداد_4, argv[تعداد_4]);

   إرجاع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
