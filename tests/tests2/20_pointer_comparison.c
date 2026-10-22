#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক a;
   পূর্ণাঙ্ক b;
   পূর্ণাঙ্ক *d;
   পূর্ণাঙ্ক *e;
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

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
