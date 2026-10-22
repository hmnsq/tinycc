#ضمن <stdio.h>

صحيح factorial(صحيح i) 
{
   אם (i < 2)
      החזר i;
   אחרת
      החזר i * factorial(i - 1);
}

صحيح main()
{
   صحيح Count;

   עבור (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   החזר 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
