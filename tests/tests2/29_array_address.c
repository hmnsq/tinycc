#include <stdio.h>
#include <string.h>

целое основной()
{
   char a[10];
   strcpy(a, "abcdef");
   printf("%s\n", &a[1]);

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
