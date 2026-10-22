#include <stdio.h>

ཧྲིལ factorial(ཧྲིལ i) 
{
   གལ་ཏེ (i < 2)
      ཕྱིར i;
   དེ་མིན
      ཕྱིར i * factorial(i - 1);
}

ཧྲིལ གཙོ()
{
   ཧྲིལ Count;

   ཆེད་དུ (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
