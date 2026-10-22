#include <stdio.h>

số_nguyên main()
{
   số_nguyên x = 'a';
   char y = x;

   char *a = "hello";

   printf("%s\n", a);

   số_nguyên c;
   c = *a;

   char *b;
   cho (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   char destarray[10];
   char *dest = &destarray[0];
   char *src = a;

   trong_khi (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
