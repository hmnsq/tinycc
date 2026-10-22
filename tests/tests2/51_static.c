#شامل <stdio.h>

ایستا صحیح fred = 1234;
ایستا صحیح joe;

تهی henry()
{
   ایستا صحیح fred = 4567;

   printf("%d\n", fred);
   fred++;
}

صحیح اصلی()
{
   printf("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   printf("%d\n", fred);
   fred = 8901;
   joe = 2345;
   printf("%d\n", fred);
   printf("%d\n", joe);

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
