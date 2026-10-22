#ضمن <stdio.h>

صحيح factorial(صحيح i) 
{
   إذا (i < 2)
      أرجع i;
   وإلا
      أرجع i * factorial(i - 1);
}

صحيح main()
{
   صحيح سانى_3;

   لكل (سانى_3 = 1; سانى_3 <= 10; سانى_3++)
      printf("%d\n", factorial(سانى_3));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
