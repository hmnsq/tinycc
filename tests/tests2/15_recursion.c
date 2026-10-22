#include <stdio.h>

puur_naa_nka factorial(puur_naa_nka i) 
{
   ᯀᯮᯝ (i < 2)
      ᯀᯮᯞ i;
   ᯀᯮᯝᯂᯪ
      ᯀᯮᯞ i * factorial(i - 1);
}

puur_naa_nka main()
{
   puur_naa_nka Count;

   for (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ᯀᯮᯞ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
