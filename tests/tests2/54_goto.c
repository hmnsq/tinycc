#شامل <stdio.h>

تهی fred()
{
   printf("In fred()\n");
   برو done;
   printf("In middle\n");
done:
   printf("At end\n");
}

تهی joe()
{
   صحیح b = 5678;

   printf("In joe()\n");

   {
      صحیح c = 1234;
      printf("c = %d\n", c);
      برو outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

تهی henry()
{
   صحیح a;

   printf("In henry()\n");
   برو inner;

   {
      صحیح b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

صحیح اصلی()
{
   fred();
   joe();
   henry();

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
