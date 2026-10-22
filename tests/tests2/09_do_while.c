#ضمن <stdio.h>

صحيح main()
{
   صحيح a;
   صحيح p;
   صحيح t;

   a = 1;
   p = 0;
   t = 0;

   ܥܒܕ
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } ܟܡܐ (a < 100);

   ܦܢܐ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
