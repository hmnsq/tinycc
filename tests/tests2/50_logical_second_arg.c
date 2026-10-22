#include <stdio.h>

цяло fred()
{
   printf("fred\n");
   върни 0;
}

цяло joe()
{
   printf("joe\n");
   върни 1;
}

цяло main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
