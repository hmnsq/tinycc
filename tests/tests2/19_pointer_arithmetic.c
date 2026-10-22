#include <stdio.h>

整数 主要()
{
   整数 a;
   整数 *b;
   整数 *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   如果 (b == NULL)
      printf("b is NULL\n");
   否则
      printf("b is not NULL\n");

   如果 (c == NULL)
      printf("c is NULL\n");
   否则
      printf("c is not NULL\n");

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
