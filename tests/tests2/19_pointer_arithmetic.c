#include <stdio.h>

ཧྲིལ main()
{
   ཧྲིལ a;
   ཧྲིལ *b;
   ཧྲིལ *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   གལ་སྲིད (b == NULL)
      printf("b is NULL\n");
   དེ་མིན
      printf("b is not NULL\n");

   གལ་སྲིད (c == NULL)
      printf("c is NULL\n");
   དེ་མིན
      printf("c is not NULL\n");

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
