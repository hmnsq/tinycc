#ضمن <stdio.h>

صحيح main(صحيح argc, حرف **argv)
{
   صحيح کيراءن_3;

   printf("hello world %d\n", argc);
   لكل (کيراءن_3 = 1; کيراءن_3 < argc; کيراءن_3++)
      printf("arg %d: %s\n", کيراءن_3, argv[کيراءن_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
