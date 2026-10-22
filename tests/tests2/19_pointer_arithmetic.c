#include <stdio.h>

целое основной()
{
   целое a;
   целое *b;
   целое *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   если (b == NULL)
      printf("b is NULL\n");
   иначе
      printf("b is not NULL\n");

   если (c == NULL)
      printf("c is NULL\n");
   иначе
      printf("c is not NULL\n");

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
