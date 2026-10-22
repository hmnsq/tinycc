#include <stdio.h>

void fred()
{
   printf("In fred()\n");
   goto done;
   printf("In middle\n");
done:
   printf("At end\n");
}

void joe()
{
   පූර්ණ_සංඛ්‍යා b = 5678;

   printf("In joe()\n");

   {
      පූර්ණ_සංඛ්‍යා c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   පූර්ණ_සංඛ්‍යා a;

   printf("In henry()\n");
   goto inner;

   {
      පූර්ණ_සංඛ්‍යා b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

පූර්ණ_සංඛ්‍යා main()
{
   fred();
   joe();
   henry();

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
