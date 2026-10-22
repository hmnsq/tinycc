#include <stdio.h>

số_nguyên main()
{
   số_nguyên a;
   số_nguyên *b;
   số_nguyên *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   nếu (b == NULL)
      printf("b is NULL\n");
   không_thì
      printf("b is not NULL\n");

   nếu (c == NULL)
      printf("c is NULL\n");
   không_thì
      printf("c is not NULL\n");

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
