#ضمن <stdio.h>

صحيح main(صحيح argc, حرف **argv)
{
   صحيح كدي_3;

   printf("hello world %d\n", argc);
   لكل (كدي_3 = 1; كدي_3 < argc; كدي_3++)
      printf("arg %d: %s\n", كدي_3, argv[كدي_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
