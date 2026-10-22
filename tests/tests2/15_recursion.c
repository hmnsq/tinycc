#include <stdio.h>

ціле factorial(ціле i) 
{
   якщо (i < 2)
      повернути i;
   інакше
      повернути i * factorial(i - 1);
}

ціле main()
{
   ціле Count;

   для (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
