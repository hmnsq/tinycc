#include <stdio.h>

цяло factorial(цяло i) 
{
   ако (i < 2)
      върни i;
   иначе
      върни i * factorial(i - 1);
}

цяло main()
{
   цяло Count;

   за (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
