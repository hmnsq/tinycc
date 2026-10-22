#شامل <stdio.h>

خالی fred()
{
   لکھو("In fred()\n");
   جاؤ مکمل;
   لکھو("In middle\n");
مکمل:
   لکھو("At end\n");
}

خالی joe()
{
   صحیح b = 5678;

   لکھو("In joe()\n");

   {
      صحیح c = 1234;
      لکھو("c = %d\n", c);
      جاؤ outer;
      لکھو("uh-oh\n");
   }

outer:    

   لکھو("done\n");
}

خالی henry()
{
   صحیح a;

   لکھو("In henry()\n");
   جاؤ inner;

   {
      صحیح b;
inner:    
      b = 1234;
      لکھو("b = %d\n", b);
   }

   لکھو("done\n");
}

صحیح مین()
{
   fred();
   joe();
   henry();

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
