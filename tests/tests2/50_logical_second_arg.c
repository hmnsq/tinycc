#include <stdio.h>

цео fred()
{
   printf("fred\n");
   врати 0;
}

цео joe()
{
   printf("joe\n");
   врати 1;
}

цео main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
