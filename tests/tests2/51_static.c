#ضمن <stdio.h>

ساكن صحيح fred = 1234;
ساكن صحيح joe;

فراغ henry()
{
   ساكن صحيح fred = 4567;

   چاپ_کن("%d\n", fred);
   fred++;
}

صحيح اصلی()
{
   چاپ_کن("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   چاپ_کن("%d\n", fred);
   fred = 8901;
   joe = 2345;
   چاپ_کن("%d\n", fred);
   چاپ_کن("%d\n", joe);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
