#ضمن <stdio.h>

صحيح factorial(صحيح i) 
{
   ܐܢ (i < 2)
      ܦܢܐ i;
   ܐܚܪܢܐ
      ܦܢܐ i * factorial(i - 1);
}

صحيح main()
{
   صحيح Count;

   لكل (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ܦܢܐ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
