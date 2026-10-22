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
   ຈຳນວນເຕັມ b = 5678;

   printf("In joe()\n");

   {
      ຈຳນວນເຕັມ c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   ຈຳນວນເຕັມ a;

   printf("In henry()\n");
   goto inner;

   {
      ຈຳນວນເຕັມ b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

ຈຳນວນເຕັມ main()
{
   fred();
   joe();
   henry();

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
