#include <stdio.h>

ціле main()
{
   ціле a;
   ціле *b;
   ціле *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   якщо (b == NULL)
      printf("b is NULL\n");
   інакше
      printf("b is not NULL\n");

   якщо (c == NULL)
      printf("c is NULL\n");
   інакше
      printf("c is not NULL\n");

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
