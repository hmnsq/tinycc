#include <stdio.h>

จำนวนเต็ม fred()
{
   printf("fred\n");
   คืน 0;
}

จำนวนเต็ม joe()
{
   printf("joe\n");
   คืน 1;
}

จำนวนเต็ม หลัก()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
