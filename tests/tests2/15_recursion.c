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
   صحيح ژماردن_3;

   لكل (ژماردن_3 = 1; ژماردن_3 <= 10; ژماردن_3++)
      printf("%d\n", factorial(ژماردن_3));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
