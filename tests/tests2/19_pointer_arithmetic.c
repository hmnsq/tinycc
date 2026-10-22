#include <stdio.h>

整数 メインページ()
{
   整数 a;
   整数 *b;
   整数 *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   もし (b == NULL)
      printf("b is NULL\n");
   否则
      printf("b is not NULL\n");

   もし (c == NULL)
      printf("c is NULL\n");
   否则
      printf("c is not NULL\n");

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
