#ضمن <stdio.h>

صحيح main(صحيح argc, حرف **argv)
{
   صحيح سانى_3;

   printf("hello world %d\n", argc);
   لكل (سانى_3 = 1; سانى_3 < argc; سانى_3++)
      printf("arg %d: %s\n", سانى_3, argv[سانى_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
