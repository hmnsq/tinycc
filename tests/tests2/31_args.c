#include <stdio.h>

ціле main(ціле argc, char **argv)
{
   ціле Count;

   printf("hello world %d\n", argc);
   для (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
