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
   цео b = 5678;

   printf("In joe()\n");

   {
      цео c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   цео a;

   printf("In henry()\n");
   goto inner;

   {
      цео b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

цео main()
{
   fred();
   joe();
   henry();

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
