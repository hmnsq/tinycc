#شامل <stdio.h>

ساکن صحیح fred = 1234;
ساکن صحیح joe;

خالی henry()
{
   ساکن صحیح fred = 4567;

   لکھو("%d\n", fred);
   fred++;
}

صحیح مین()
{
   لکھو("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   لکھو("%d\n", fred);
   fred = 8901;
   joe = 2345;
   لکھو("%d\n", fred);
   لکھو("%d\n", joe);

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
