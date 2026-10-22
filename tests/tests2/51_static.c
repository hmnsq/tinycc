#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਸਥਿਰ ਪੂਰਨ fred = 1234;
ਸਥਿਰ ਪੂਰਨ joe;

ਖਾਲੀ henry()
{
   ਸਥਿਰ ਪੂਰਨ fred = 4567;

   ਲਿਖੋ("%d\n", fred);
   fred++;
}

ਪੂਰਨ ਮੁੱਖ()
{
   ਲਿਖੋ("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   ਲਿਖੋ("%d\n", fred);
   fred = 8901;
   joe = 2345;
   ਲਿਖੋ("%d\n", fred);
   ਲਿਖੋ("%d\n", joe);

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
