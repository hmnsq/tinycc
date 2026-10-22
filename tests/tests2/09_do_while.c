#ضمن <stdio.h>

صحيح مکھ()
{
   صحيح a;
   صحيح p;
   صحيح t;

   a = 1;
   p = 0;
   t = 0;

   افعل
   {
      لکھو("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } طالما (a < 100);

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
