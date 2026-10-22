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
   целое b = 5678;

   printf("In joe()\n");

   {
      целое c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   целое a;

   printf("In henry()\n");
   goto inner;

   {
      целое b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

целое основной()
{
   fred();
   joe();
   henry();

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
