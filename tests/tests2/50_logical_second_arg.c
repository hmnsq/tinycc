#شامل <stdio.h>

صحیح fred()
{
   printf("fred\n");
   بازگشت 0;
}

صحیح joe()
{
   printf("joe\n");
   بازگشت 1;
}

صحیح اصلی()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
