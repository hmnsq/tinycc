#include <stdio.h>

整数 主要(整数 argc, char **argv)
{
   整数 Count;

   printf("hello world %d\n", argc);
   为 (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
