#ضمن <stdio.h>

صحيح factorial(صحيح i) 
{
   𐡄𐡍 (i < 2)
      أرجع i;
   وإلا
      أرجع i * factorial(i - 1);
}

صحيح main()
{
   صحيح Count;

   لكل (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
