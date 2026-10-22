#include <stdio.h>

puur_naa_nka main() 
{
   puur_naa_nka Count;
   puur_naa_nka Array[10];

   for (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   for (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   ᨀᨘᨒ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
