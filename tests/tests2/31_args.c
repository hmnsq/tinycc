#include <stdio.h>

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv)
{
   ຈຳນວນເຕັມ Count;

   printf("hello world %d\n", argc);
   ສຳລັບ (Count = 1; Count < argc; Count++)
      printf("arg %d: %s\n", Count, argv[Count]);

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
