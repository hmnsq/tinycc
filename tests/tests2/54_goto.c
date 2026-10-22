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
   ចំនួនគត់ b = 5678;

   printf("In joe()\n");

   {
      ចំនួនគត់ c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   ចំនួនគត់ a;

   printf("In henry()\n");
   goto inner;

   {
      ចំនួនគត់ b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

ចំនួនគត់ main()
{
   fred();
   joe();
   henry();

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
