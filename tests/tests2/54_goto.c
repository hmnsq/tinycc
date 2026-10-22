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
   số_nguyên b = 5678;

   printf("In joe()\n");

   {
      số_nguyên c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   số_nguyên a;

   printf("In henry()\n");
   goto inner;

   {
      số_nguyên b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

số_nguyên main()
{
   fred();
   joe();
   henry();

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
