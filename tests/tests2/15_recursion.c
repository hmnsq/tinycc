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
   صحيح گنتی_3;

   لكل (گنتی_3 = 1; گنتی_3 <= 10; گنتی_3++)
      printf("%d\n", factorial(گنتی_3));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
