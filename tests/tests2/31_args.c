#ضمن <stdio.h>

صحيح main(صحيح argc, حرف **argv)
{
   صحيح عدد_3;

   printf("hello world %d\n", argc);
   لكل (عدد_3 = 1; عدد_3 < argc; عدد_3++)
      printf("arg %d: %s\n", عدد_3, argv[عدد_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
