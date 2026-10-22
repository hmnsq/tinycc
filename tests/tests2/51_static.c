#ضمن <stdio.h>

ساكن صحيح fred = 1234;
ساكن صحيح joe;

فراغ henry()
{
   ساكن صحيح fred = 4567;

   چاپ_کړه("%d\n", fred);
   fred++;
}

صحيح اصلي()
{
   چاپ_کړه("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   چاپ_کړه("%d\n", fred);
   fred = 8901;
   joe = 2345;
   چاپ_کړه("%d\n", fred);
   چاپ_کړه("%d\n", joe);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
