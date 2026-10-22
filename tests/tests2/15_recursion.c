#include <stdio.h>

int factorial(int i) 
{
   if (i < 2)
      return i;
   else
      return i * factorial(i - 1);
}

int main()
{
   int बिलांग_3;

   for (बिलांग_3 = 1; बिलांग_3 <= 10; बिलांग_3++)
      printf("%d\n", factorial(बिलांग_3));

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
