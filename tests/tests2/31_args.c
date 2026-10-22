#include <stdio.h>

ཧྲིལ main(ཧྲིལ argc, var_na **argv)
{
   ཧྲིལ Count;

   printf("hello world %d\n", argc);
   དོན་ལུ (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
