#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা fred()
{
   printf("fred\n");
   ফেরত 0;
}

পূর্ণসংখ্যা joe()
{
   printf("joe\n");
   ফেরত 1;
}

পূর্ণসংখ্যা প্রধান()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
