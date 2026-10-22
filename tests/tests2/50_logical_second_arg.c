#include <stdio.h>

ཧྲིལ fred()
{
   printf("fred\n");
   ཕྱིར 0;
}

ཧྲིལ joe()
{
   printf("joe\n");
   ཕྱིར 1;
}

ཧྲིལ གཙོ()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
