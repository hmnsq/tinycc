#ضمن <stdio.h>

صحيح fred()
{
   لکو("fred\n");
   أرجع 0;
}

صحيح joe()
{
   لکو("joe\n");
   أرجع 1;
}

صحيح مکيه()
{
   لکو("%d\n", fred() && joe());
   لکو("%d\n", fred() || joe());
   لکو("%d\n", joe() && fred());
   لکو("%d\n", joe() || fred());
   لکو("%d\n", fred() && (1 + joe()));
   لکو("%d\n", fred() || (0 + joe()));
   لکو("%d\n", joe() && (0 + fred()));
   لکو("%d\n", joe() || (1 + fred()));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
