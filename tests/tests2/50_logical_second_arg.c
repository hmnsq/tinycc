#include <stdio.h>

ကိန်းပြည့် fred()
{
   printf("fred\n");
   ပြန်ပေး 0;
}

ကိန်းပြည့် joe()
{
   printf("joe\n");
   ပြန်ပေး 1;
}

ကိန်းပြည့် main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
