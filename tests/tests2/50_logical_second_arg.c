#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ fred()
{
   ਲਿਖੋ("fred\n");
   ਵਾਪਸ 0;
}

ਪੂਰਨ joe()
{
   ਲਿਖੋ("joe\n");
   ਵਾਪਸ 1;
}

ਪੂਰਨ ਮੁੱਖ()
{
   ਲਿਖੋ("%d\n", fred() && joe());
   ਲਿਖੋ("%d\n", fred() || joe());
   ਲਿਖੋ("%d\n", joe() && fred());
   ਲਿਖੋ("%d\n", joe() || fred());
   ਲਿਖੋ("%d\n", fred() && (1 + joe()));
   ਲਿਖੋ("%d\n", fred() || (0 + joe()));
   ਲਿਖੋ("%d\n", joe() && (0 + fred()));
   ਲਿਖੋ("%d\n", joe() || (1 + fred()));

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
