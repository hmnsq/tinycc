#include <stdio.h>

целое fred()
{
   printf("fred\n");
   вернуть 0;
}

целое joe()
{
   printf("joe\n");
   вернуть 1;
}

целое основной()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
