#include <stdio.h>

ཧྲིལ fred()
{
   printf("fred\n");
   ལོག 0;
}

ཧྲིལ joe()
{
   printf("joe\n");
   ལོག 1;
}

ཧྲིལ main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
