#شامل <stdio.h>

صحیح مین()
{
   صحیح a;
   صحیح p;
   صحیح t;

   a = 1;
   p = 0;
   t = 0;

   جب (a < 100)
   {
      لکھو("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   واپس 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
