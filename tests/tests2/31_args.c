#include <stdio.h>

цяло main(цяло argc, char **argv)
{
   цяло Count;

   printf("hello world %d\n", argc);
   за (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
