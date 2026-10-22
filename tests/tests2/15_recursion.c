#include <stdio.h>

정수 factorial(정수 i) 
{
   만약 (i < 2)
      반환 i;
   아니면
      반환 i * factorial(i - 1);
}

정수 main()
{
   정수 Count;

   위해 (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
