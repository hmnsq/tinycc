#include <stdio.h>

ចំនួនគត់ main(ចំនួនគត់ argc, var_na **argv)
{
   ចំនួនគត់ Count;

   printf("hello world %d\n", argc);
   សម្រាប់ (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
