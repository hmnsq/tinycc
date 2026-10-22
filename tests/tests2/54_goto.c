#ضمن <stdio.h>

فراغ fred()
{
   printf("In fred()\n");
   اذهب done;
   printf("In middle\n");
done:
   printf("At end\n");
}

فراغ joe()
{
   صحيح b = 5678;

   printf("In joe()\n");

   {
      صحيح c = 1234;
      printf("c = %d\n", c);
      اذهب outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

فراغ henry()
{
   صحيح a;

   printf("In henry()\n");
   اذهب inner;

   {
      صحيح b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

صحيح main()
{
   fred();
   joe();
   henry();

   ܦܢܐ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
