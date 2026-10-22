#ضمن <stdio.h>

صحيح main(صحيح argc, حرف **argv)
{
   صحيح Count;

   printf("hello world %d\n", argc);
   עבור (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   החזר 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
