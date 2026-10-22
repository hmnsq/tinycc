#include <stdio.h>

int main(int argc, char **argv)
{
   int बिलांग_3;

   printf("hello world %d\n", argc);
   for (बिलांग_3 = 1; बिलांग_3 < argc; बिलांग_3++)
      printf("arg %d: %s\n", बिलांग_3, argv[बिलांग_3]);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
