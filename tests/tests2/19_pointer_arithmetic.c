#include <stdio.h>

จำนวนเต็ม หลัก()
{
   จำนวนเต็ม a;
   จำนวนเต็ม *b;
   จำนวนเต็ม *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   ถ้า (b == NULL)
      printf("b is NULL\n");
   มิฉะนั้น
      printf("b is not NULL\n");

   ถ้า (c == NULL)
      printf("c is NULL\n");
   มิฉะนั้น
      printf("c is not NULL\n");

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
