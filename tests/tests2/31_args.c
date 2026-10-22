#ضمن <stdio.h>

صحيح main(صحيح argc, حرف **argv)
{
   صحيح ژماردن_3;

   printf("hello world %d\n", argc);
   لكل (ژماردن_3 = 1; ژماردن_3 < argc; ژماردن_3++)
      printf("arg %d: %s\n", ژماردن_3, argv[ژماردن_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
