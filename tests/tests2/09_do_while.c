#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
   முழு a;
   முழு p;
   முழு t;

   a = 1;
   p = 0;
   t = 0;

   செய்
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } போது (a < 100);

   திரும்பு 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
