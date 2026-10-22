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
   整数 b = 5678;

   printf("In joe()\n");

   {
      整数 c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   整数 a;

   printf("In henry()\n");
   goto inner;

   {
      整数 b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

整数 メインページ()
{
   fred();
   joe();
   henry();

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
