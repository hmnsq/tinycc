#include <stdio.h>

จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv)
{
   จำนวนเต็ม Count;

   printf("hello world %d\n", argc);
   สำหรับ (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
