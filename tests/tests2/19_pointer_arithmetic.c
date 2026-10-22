#include <stdio.h>

цео main()
{
   цео a;
   цео *b;
   цео *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   ако (b == NULL)
      printf("b is NULL\n");
   инако
      printf("b is not NULL\n");

   ако (c == NULL)
      printf("c is NULL\n");
   инако
      printf("c is not NULL\n");

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
