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
   ཧྲིལ b = 5678;

   printf("In joe()\n");

   {
      ཧྲིལ c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   ཧྲིལ a;

   printf("In henry()\n");
   goto inner;

   {
      ཧྲིལ b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

ཧྲིལ main()
{
   fred();
   joe();
   henry();

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
