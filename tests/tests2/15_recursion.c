#include <stdio.h>

ཧྲིལ factorial(ཧྲིལ i) 
{
   གལ་སྲིད (i < 2)
      ལོག i;
   དེ་མིན
      ལོག i * factorial(i - 1);
}

ཧྲིལ main()
{
   ཧྲིལ Count;

   དོན་ལུ (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
