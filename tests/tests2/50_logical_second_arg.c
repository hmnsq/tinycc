#include <stdio.h>

정수 fred()
{
   printf("fred\n");
   반환 0;
}

정수 joe()
{
   printf("joe\n");
   반환 1;
}

정수 main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
