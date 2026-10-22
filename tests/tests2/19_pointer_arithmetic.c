#include <stdio.h>

ចំនួនគត់ main()
{
   ចំនួនគត់ a;
   ចំនួនគត់ *b;
   ចំនួនគត់ *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   ប្រសិនបើ (b == NULL)
      printf("b is NULL\n");
   បើមិនដូច្នេះ
      printf("b is not NULL\n");

   ប្រសិនបើ (c == NULL)
      printf("c is NULL\n");
   បើមិនដូច្នេះ
      printf("c is not NULL\n");

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
