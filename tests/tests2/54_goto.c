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
   ကိန်းပြည့် b = 5678;

   printf("In joe()\n");

   {
      ကိန်းပြည့် c = 1234;
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

void henry()
{
   ကိန်းပြည့် a;

   printf("In henry()\n");
   goto inner;

   {
      ကိန်းပြည့် b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

ကိန်းပြည့် main()
{
   fred();
   joe();
   henry();

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
