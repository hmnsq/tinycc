#ضمن <stdio.h>

صحيح main(صحيح argc, حرف **argv)
{
   صحيح گنتی_3;

   printf("hello world %d\n", argc);
   لكل (گنتی_3 = 1; گنتی_3 < argc; گنتی_3++)
      printf("arg %d: %s\n", گنتی_3, argv[گنتی_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
