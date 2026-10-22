#include <stdio.h>

цео main(цео argc, char **argv)
{
   цео Count;

   printf("hello world %d\n", argc);
   за (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
