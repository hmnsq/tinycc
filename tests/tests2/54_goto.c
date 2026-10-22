#ضمن <stdio.h>

فراغ fred()
{
   چاپ_کړه("In fred()\n");
   اذهب بشپړ;
   چاپ_کړه("In middle\n");
بشپړ:
   چاپ_کړه("At end\n");
}

فراغ joe()
{
   صحيح b = 5678;

   چاپ_کړه("In joe()\n");

   {
      صحيح c = 1234;
      چاپ_کړه("c = %d\n", c);
      اذهب outer;
      چاپ_کړه("uh-oh\n");
   }

outer:    

   چاپ_کړه("done\n");
}

فراغ henry()
{
   صحيح a;

   چاپ_کړه("In henry()\n");
   اذهب inner;

   {
      صحيح b;
inner:    
      b = 1234;
      چاپ_کړه("b = %d\n", b);
   }

   چاپ_کړه("done\n");
}

صحيح اصلي()
{
   fred();
   joe();
   henry();

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
