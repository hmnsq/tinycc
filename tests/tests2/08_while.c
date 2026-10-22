#شامل <stdio.h>

صحیح اصلی()
{
   صحیح a;
   صحیح p;
   صحیح t;

   a = 1;
   p = 0;
   t = 0;

   وقتی (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   بازگشت 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
