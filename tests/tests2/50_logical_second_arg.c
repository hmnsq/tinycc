#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক fred()
{
   printf("fred\n");
   প্রত্যাগম 0;
}

পূর্ণাঙ্ক joe()
{
   printf("joe\n");
   প্রত্যাগম 1;
}

পূর্ণাঙ্ক main()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
