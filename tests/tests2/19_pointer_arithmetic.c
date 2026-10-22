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

   ပေႃး (b == NULL)
      printf("b is NULL\n");
   ပေႃးဢမ်ႇ
      printf("b is not NULL\n");

   ပေႃး (c == NULL)
      printf("c is NULL\n");
   ပေႃးဢမ်ႇ
      printf("c is not NULL\n");

   ပွၵ်ႈ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
