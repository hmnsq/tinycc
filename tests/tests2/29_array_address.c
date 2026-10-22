#include <stdio.h>
#include <string.h>

整数 主要()
{
   char a[10];
   strcpy(a, "abcdef");
   printf("%s\n", &a[1]);

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
