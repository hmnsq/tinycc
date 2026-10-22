#include <stdio.h>

ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
   ကိန်းပြည့် Count;

   printf("hello world %d\n", argc);
   အတွက် (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
