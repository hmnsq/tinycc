#অন্তর্ভাব <stdio.h>

শূন্য fred()
{
   printf("In fred()\n");
   গচ্ছ done;
   printf("In middle\n");
done:
   printf("At end\n");
}

শূন্য joe()
{
   পূর্ণাঙ্ক b = 5678;

   printf("In joe()\n");

   {
      পূর্ণাঙ্ক c = 1234;
      printf("c = %d\n", c);
      গচ্ছ outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

শূন্য henry()
{
   পূর্ণাঙ্ক a;

   printf("In henry()\n");
   গচ্ছ inner;

   {
      পূর্ণাঙ্ক b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

পূর্ণাঙ্ক main()
{
   fred();
   joe();
   henry();

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
