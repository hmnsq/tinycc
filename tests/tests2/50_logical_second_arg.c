#include <stdio.h>

පූර්ණ_සංඛ්‍යා fred()
{
   printf("fred\n");
   ආපසු 0;
}

පූර්ණ_සංඛ්‍යා joe()
{
   printf("joe\n");
   ආපසු 1;
}

පූර්ණ_සංඛ්‍යා main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
