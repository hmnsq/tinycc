#شامل <stdio.h>

صحیح fred()
{
   لکھو("fred\n");
   واپس 0;
}

صحیح joe()
{
   لکھو("joe\n");
   واپس 1;
}

صحیح مین()
{
   لکھو("%d\n", fred() && joe());
   لکھو("%d\n", fred() || joe());
   لکھو("%d\n", joe() && fred());
   لکھو("%d\n", joe() || fred());
   لکھو("%d\n", fred() && (1 + joe()));
   لکھو("%d\n", fred() || (0 + joe()));
   لکھو("%d\n", joe() && (0 + fred()));
   لکھو("%d\n", joe() || (1 + fred()));

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
