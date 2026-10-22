#include <stdio.h>

整数 主要()
{
   整数 x = 'a';
   char y = x;

   char *a = "hello";

   printf("%s\n", a);

   整数 c;
   c = *a;

   char *b;
   为 (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   char destarray[10];
   char *dest = &destarray[0];
   char *src = a;

   当 (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
