#include <stdio.h>

цяло main()
{
   цяло a;
   цяло *b;
   цяло *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   ако (b == NULL)
      printf("b is NULL\n");
   иначе
      printf("b is not NULL\n");

   ако (c == NULL)
      printf("c is NULL\n");
   иначе
      printf("c is not NULL\n");

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
