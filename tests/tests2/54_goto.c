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
   ціле b = 5678;

   printf("In joe()\n");

   {
      ціле c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   ціле a;

   printf("In henry()\n");
   goto inner;

   {
      ціле b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

ціле main()
{
   fred();
   joe();
   henry();

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
