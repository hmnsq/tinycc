#ضمن <stdio.h>

ساكن صحيح fred = 1234;
ساكن صحيح joe;

فراغ henry()
{
   ساكن صحيح fred = 4567;

   printf("%d\n", fred);
   fred++;
}

صحيح main()
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

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
