#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান()
{
   পূর্ণসংখ্যা a;
   পূর্ণসংখ্যা b;
   পূর্ণসংখ্যা *d;
   পূর্ণসংখ্যা *e;
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

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
