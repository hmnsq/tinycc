#include <stdio.h>

ཧྲིལ གཙོ() 
{
   ཧྲིལ Count;
   ཧྲིལ Array[10];

   ཆེད་དུ (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   ཆེད་དུ (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   ཕྱིར 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
