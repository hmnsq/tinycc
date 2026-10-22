#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક fred()
{
   printf("fred\n");
   પાછા 0;
}

પૂર્ણાંક joe()
{
   printf("joe\n");
   પાછા 1;
}

પૂર્ણાંક મુખ્ય()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
