#include <stdio.h>

số_nguyên fred()
{
   printf("fred\n");
   trả_về 0;
}

số_nguyên joe()
{
   printf("joe\n");
   trả_về 1;
}

số_nguyên main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
