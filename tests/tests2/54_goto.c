#అన్తర్భావ <stdio.h>

శూన్య fred()
{
   రాయి("In fred()\n");
   వెళ్ళు పూర్తి;
   రాయి("In middle\n");
పూర్తి:
   రాయి("At end\n");
}

శూన్య joe()
{
   పూర్ణాంకం b = 5678;

   రాయి("In joe()\n");

   {
      పూర్ణాంకం c = 1234;
      రాయి("c = %d\n", c);
      వెళ్ళు outer;
      రాయి("uh-oh\n");
   }

outer:    

   రాయి("done\n");
}

శూన్య henry()
{
   పూర్ణాంకం a;

   రాయి("In henry()\n");
   వెళ్ళు inner;

   {
      పూర్ణాంకం b;
inner:    
      b = 1234;
      రాయి("b = %d\n", b);
   }

   రాయి("done\n");
}

పూర్ణాంకం ప్రధాన()
{
   fred();
   joe();
   henry();

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
