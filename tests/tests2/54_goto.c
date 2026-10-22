#ضمن <stdio.h>

فراغ fred()
{
   لکو("In fred()\n");
   اذهب پورو;
   لکو("In middle\n");
پورو:
   لکو("At end\n");
}

فراغ joe()
{
   صحيح b = 5678;

   لکو("In joe()\n");

   {
      صحيح c = 1234;
      لکو("c = %d\n", c);
      اذهب outer;
      لکو("uh-oh\n");
   }

outer:    

   لکو("done\n");
}

فراغ henry()
{
   صحيح a;

   لکو("In henry()\n");
   اذهب inner;

   {
      صحيح b;
inner:    
      b = 1234;
      لکو("b = %d\n", b);
   }

   لکو("done\n");
}

صحيح مکيه()
{
   fred();
   joe();
   henry();

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
