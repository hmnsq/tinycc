#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક a;
   પૂર્ણાંક p;
   પૂર્ણાંક t;

   a = 1;
   p = 0;
   t = 0;

   જ્યારે (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   પાછા 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
