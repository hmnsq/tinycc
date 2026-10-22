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
   จำนวนเต็ม b = 5678;

   printf("In joe()\n");

   {
      จำนวนเต็ม c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   จำนวนเต็ม a;

   printf("In henry()\n");
   goto inner;

   {
      จำนวนเต็ม b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

จำนวนเต็ม หลัก()
{
   fred();
   joe();
   henry();

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
