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

   ꦪꦼꦤ꧀ (b == NULL)
      printf("b is NULL\n");
   ꦭꦶꦪ
      printf("b is not NULL\n");

   ꦪꦼꦤ꧀ (c == NULL)
      printf("c is NULL\n");
   ꦭꦶꦪ
      printf("c is not NULL\n");

   ꦮꦭꦶ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
