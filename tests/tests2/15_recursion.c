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
   صحيح عدد_3;

   لكل (عدد_3 = 1; عدد_3 <= 10; عدد_3++)
      printf("%d\n", factorial(عدد_3));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
