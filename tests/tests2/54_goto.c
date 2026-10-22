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
   цяло b = 5678;

   printf("In joe()\n");

   {
      цяло c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   цяло a;

   printf("In henry()\n");
   goto inner;

   {
      цяло b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

цяло main()
{
   fred();
   joe();
   henry();

   върни 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
