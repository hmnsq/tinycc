#include <stdio.h>

පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා a;
   පූර්ණ_සංඛ්‍යා *b;
   පූර්ණ_සංඛ්‍යා *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   නම් (b == NULL)
      printf("b is NULL\n");
   නැතහොත්
      printf("b is not NULL\n");

   නම් (c == NULL)
      printf("c is NULL\n");
   නැතහොත්
      printf("c is not NULL\n");

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
