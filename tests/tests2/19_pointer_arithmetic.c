#include <stdio.h>

puur_naa_nka main()
{
   puur_naa_nka a;
   puur_naa_nka *b;
   puur_naa_nka *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   ᮚᮦᮔ᮪ (b == NULL)
      printf("b is NULL\n");
   ᮜᮤᮚ
      printf("b is not NULL\n");

   ᮚᮦᮔ᮪ (c == NULL)
      printf("c is NULL\n");
   ᮜᮤᮚ
      printf("c is not NULL\n");

   ᮝᮜᮤ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
