#include <stdio.h>

ціле fred()
{
   printf("fred\n");
   повернути 0;
}

ціле joe()
{
   printf("joe\n");
   повернути 1;
}

ціле main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
