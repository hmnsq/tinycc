#include <stdio.h>

ཧྲིལ གཙོ()
{
   ཧྲིལ a;
   ཧྲིལ *b;
   ཧྲིལ *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   གལ་ཏེ (b == NULL)
      printf("b is NULL\n");
   དེ་མིན
      printf("b is not NULL\n");

   གལ་ཏེ (c == NULL)
      printf("c is NULL\n");
   དེ་མིན
      printf("c is not NULL\n");

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
