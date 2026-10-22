#include <stdio.h>

цяло main()
{
   цяло x = 'a';
   char y = x;

   char *a = "hello";

   printf("%s\n", a);

   цяло c;
   c = *a;

   char *b;
   за (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   char destarray[10];
   char *dest = &destarray[0];
   char *src = a;

   докато (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
