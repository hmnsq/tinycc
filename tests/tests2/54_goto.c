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
   puur_naa_nka b = 5678;

   printf("In joe()\n");

   {
      puur_naa_nka c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   puur_naa_nka a;

   printf("In henry()\n");
   goto inner;

   {
      puur_naa_nka b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

puur_naa_nka main()
{
   fred();
   joe();
   henry();

   ᮝᮜᮤ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
