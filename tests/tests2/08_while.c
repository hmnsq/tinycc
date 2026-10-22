#ضمن <stdio.h>

صحيح مکھ()
{
   صحيح a;
   صحيح p;
   صحيح t;

   a = 1;
   p = 0;
   t = 0;

   طالما (a < 100)
   {
      لکھو("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
