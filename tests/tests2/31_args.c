#include <stdio.h>

số_nguyên main(số_nguyên argc, char **argv)
{
   số_nguyên Count;

   printf("hello world %d\n", argc);
   cho (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
