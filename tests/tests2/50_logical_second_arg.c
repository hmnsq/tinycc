#அந்தர்பாவ <stdio.h>

முழு fred()
{
   printf("fred\n");
   திரும்பு 0;
}

முழு joe()
{
   printf("joe\n");
   திரும்பு 1;
}

முழு முதன்மை()
{
   printf("%d\n", fred() && joe());
   printf("%d\n", fred() || joe());
   printf("%d\n", joe() && fred());
   printf("%d\n", joe() || fred());
   printf("%d\n", fred() && (1 + joe()));
   printf("%d\n", fred() || (0 + joe()));
   printf("%d\n", joe() && (0 + fred()));
   printf("%d\n", joe() || (1 + fred()));

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
