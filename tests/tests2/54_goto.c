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
   정수 b = 5678;

   printf("In joe()\n");

   {
      정수 c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   정수 a;

   printf("In henry()\n");
   goto inner;

   {
      정수 b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

정수 main()
{
   fred();
   joe();
   henry();

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
