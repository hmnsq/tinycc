#ضمن <stdio.h>

فراغ fred()
{
   لکھو("In fred()\n");
   اذهب پورا;
   لکھو("In middle\n");
پورا:
   لکھو("At end\n");
}

فراغ joe()
{
   صحيح b = 5678;

   لکھو("In joe()\n");

   {
      صحيح c = 1234;
      لکھو("c = %d\n", c);
      اذهب outer;
      لکھو("uh-oh\n");
   }

outer:    

   لکھو("done\n");
}

فراغ henry()
{
   صحيح a;

   لکھو("In henry()\n");
   اذهب inner;

   {
      صحيح b;
inner:    
      b = 1234;
      لکھو("b = %d\n", b);
   }

   لکھو("done\n");
}

صحيح مکھ()
{
   fred();
   joe();
   henry();

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
