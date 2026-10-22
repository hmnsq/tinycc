#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ fred()
{
   printf("fred\n");
   തിരികെ 0;
}

പൂർണ്ണസംഖ്യ joe()
{
   printf("joe\n");
   തിരികെ 1;
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
