#include <stdio.h>

puur_naa_nka fred()
{
   printf("fred\n");
   ᬯᬮᬶ 0;
}

puur_naa_nka joe()
{
   printf("joe\n");
   ᬯᬮᬶ 1;
}

puur_naa_nka main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   ᬯᬮᬶ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
