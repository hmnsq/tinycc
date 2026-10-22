#include <stdio.h>

ཧྲིལ གཙོ(ཧྲིལ argc, var_na **argv)
{
   ཧྲིལ Count;

   printf("hello world %d\n", argc);
   ཆེད་དུ (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
