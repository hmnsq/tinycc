#ଅନ୍ତର୍ଭାଵ <stdio.h>

ଶୂନ୍ୟ fred()
{
   printf("In fred()\n");
   ଯାଅ done;
   printf("In middle\n");
done:
   printf("At end\n");
}

ଶୂନ୍ୟ joe()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା b = 5678;

   printf("In joe()\n");

   {
      ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = 1234;
      printf("c = %d\n", c);
      ଯାଅ outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

ଶୂନ୍ୟ henry()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;

   printf("In henry()\n");
   ଯାଅ inner;

   {
      ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   fred();
   joe();
   henry();

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
