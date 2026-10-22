#include <stdio.h>

puur_naa_nka factorial(puur_naa_nka i) 
{
   ꦪꦼꦤ꧀ (i < 2)
      ꦮꦭꦶ i;
   ꦭꦶꦪ
      ꦮꦭꦶ i * factorial(i - 1);
}

puur_naa_nka main()
{
   puur_naa_nka Count;

   ꦏꦁꦒꦺꦴ (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ꦮꦭꦶ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
