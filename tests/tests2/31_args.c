#include <stdio.h>

정수 main(정수 argc, char **argv)
{
   정수 Count;

   printf("hello world %d\n", argc);
   위해 (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
