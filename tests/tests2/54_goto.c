#அந்தர்பாவ <stdio.h>

வெறுமை fred()
{
   printf("In fred()\n");
   செல் done;
   printf("In middle\n");
done:
   printf("At end\n");
}

வெறுமை joe()
{
   முழு b = 5678;

   printf("In joe()\n");

   {
      முழு c = 1234;
      printf("c = %d\n", c);
      செல் outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

வெறுமை henry()
{
   முழு a;

   printf("In henry()\n");
   செல் inner;

   {
      முழு b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

முழு முதன்மை()
{
   fred();
   joe();
   henry();

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
