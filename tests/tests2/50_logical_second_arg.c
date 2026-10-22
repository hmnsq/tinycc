#include <stdio.h>

ຈຳນວນເຕັມ fred()
{
   printf("fred\n");
   ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ joe()
{
   printf("joe\n");
   ສົ່ງຄືນ 1;
}

ຈຳນວນເຕັມ main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
