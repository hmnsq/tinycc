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
   صحيح کيراءن_3;

   لكل (کيراءن_3 = 1; کيراءن_3 <= 10; کيراءن_3++)
      printf("%d\n", factorial(کيراءن_3));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
