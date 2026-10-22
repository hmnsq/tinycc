#include <stdio.h>

цео factorial(цео i) 
{
   ако (i < 2)
      врати i;
   инако
      врати i * factorial(i - 1);
}

цео main()
{
   цео Count;

   за (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
