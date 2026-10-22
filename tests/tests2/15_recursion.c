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
   صحيح كدي_3;

   لكل (كدي_3 = 1; كدي_3 <= 10; كدي_3++)
      printf("%d\n", factorial(كدي_3));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
