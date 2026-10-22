#অন্তর্ভাব <stdio.h>

শূন্য fred()
{
   printf("In fred()\n");
   যাও done;
   printf("In middle\n");
done:
   printf("At end\n");
}

শূন্য joe()
{
   পূর্ণসংখ্যা b = 5678;

   printf("In joe()\n");

   {
      পূর্ণসংখ্যা c = 1234;
      printf("c = %d\n", c);
      যাও outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

শূন্য henry()
{
   পূর্ণসংখ্যা a;

   printf("In henry()\n");
   যাও inner;

   {
      পূর্ণসংখ্যা b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

পূর্ণসংখ্যা প্রধান()
{
   fred();
   joe();
   henry();

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
