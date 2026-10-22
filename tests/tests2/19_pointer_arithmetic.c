#include <stdio.h>

정수 main()
{
   정수 a;
   정수 *b;
   정수 *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   만약 (b == NULL)
      printf("b is NULL\n");
   아니면
      printf("b is not NULL\n");

   만약 (c == NULL)
      printf("c is NULL\n");
   아니면
      printf("c is not NULL\n");

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
