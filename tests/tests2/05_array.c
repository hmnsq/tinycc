#include <stdio.h>

ကိန်းပြည့် main() 
{
   ကိန်းပြည့် Count;
   ကိန်းပြည့် Array[10];

   အတွက် (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   အတွက် (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   ပြန်ပေး 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
