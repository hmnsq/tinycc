#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક a;
   પૂર્ણાંક b;
   પૂર્ણાંક *d;
   પૂર્ણાંક *e;
   d = &a;
   e = &b;
   a = 12;
   b = 34;
   printf("%d\n", *d);
   printf("%d\n", *e);
   printf("%d\n", d == e);
   printf("%d\n", d != e);
   d = e;
   printf("%d\n", d == e);
   printf("%d\n", d != e);

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
