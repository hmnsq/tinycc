#include <stdio.h>

整数 fred()
{
   printf("fred\n");
   返回 0;
}

整数 joe()
{
   printf("joe\n");
   返回 1;
}

整数 主要()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
