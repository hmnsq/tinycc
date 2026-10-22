#ضمن <stdio.h>

فراغ fred()
{
   چاپ_کن("In fred()\n");
   اذهب انجامشده;
   چاپ_کن("In middle\n");
انجامشده:
   چاپ_کن("At end\n");
}

فراغ joe()
{
   صحيح b = 5678;

   چاپ_کن("In joe()\n");

   {
      صحيح c = 1234;
      چاپ_کن("c = %d\n", c);
      اذهب outer;
      چاپ_کن("uh-oh\n");
   }

outer:    

   چاپ_کن("done\n");
}

فراغ henry()
{
   صحيح a;

   چاپ_کن("In henry()\n");
   اذهب inner;

   {
      صحيح b;
inner:    
      b = 1234;
      چاپ_کن("b = %d\n", b);
   }

   چاپ_کن("done\n");
}

صحيح اصلی()
{
   fred();
   joe();
   henry();

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
