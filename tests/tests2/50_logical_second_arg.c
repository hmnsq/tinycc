#ضمن <stdio.h>

صحيح fred()
{
   چاپ_کن("fred\n");
   أرجع 0;
}

صحيح joe()
{
   چاپ_کن("joe\n");
   أرجع 1;
}

صحيح اصلی()
{
   چاپ_کن("%d\n", fred() && joe());
   چاپ_کن("%d\n", fred() || joe());
   چاپ_کن("%d\n", joe() && fred());
   چاپ_کن("%d\n", joe() || fred());
   چاپ_کن("%d\n", fred() && (1 + joe()));
   چاپ_کن("%d\n", fred() || (0 + joe()));
   چاپ_کن("%d\n", joe() && (0 + fred()));
   چاپ_کن("%d\n", joe() || (1 + fred()));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
