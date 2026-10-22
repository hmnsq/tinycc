#ضمن <stdio.h>

صحيح fred()
{
   لکھو("fred\n");
   أرجع 0;
}

صحيح joe()
{
   لکھو("joe\n");
   أرجع 1;
}

صحيح مکھ()
{
   لکھو("%d\n", fred() && joe());
   لکھو("%d\n", fred() || joe());
   لکھو("%d\n", joe() && fred());
   لکھو("%d\n", joe() || fred());
   لکھو("%d\n", fred() && (1 + joe()));
   لکھو("%d\n", fred() || (0 + joe()));
   لکھو("%d\n", joe() && (0 + fred()));
   لکھو("%d\n", joe() || (1 + fred()));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
