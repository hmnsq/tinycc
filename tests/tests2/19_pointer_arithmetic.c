#include <stdio.h>

ကိန်းပြည့် main()
{
   ကိန်းပြည့် a;
   ကိန်းပြည့် *b;
   ကိန်းပြည့် *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   အကယ်၍ (b == NULL)
      printf("b is NULL\n");
   မဟုတ်ပါက
      printf("b is not NULL\n");

   အကယ်၍ (c == NULL)
      printf("c is NULL\n");
   မဟုတ်ပါက
      printf("c is not NULL\n");

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
