//#include <stdio.h>
বাহ্যিক পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর *, ...);

পূর্ণসংখ্যা প্রধান()
{
   পূর্ণসংখ্যা a;
   পূর্ণসংখ্যা b;
   পূর্ণসংখ্যা c;
   পূর্ণসংখ্যা d;
   পূর্ণসংখ্যা e;
   পূর্ণসংখ্যা f;
   পূর্ণসংখ্যা x;
   পূর্ণসংখ্যা y;

   a = 12;
   b = 34;
   c = 56;
   d = 78;
   e = 0;
   f = 1;

   printf("%d\n", c + d);
   printf("%d\n", (y = c + d));
   printf("%d\n", e || e && f);
   printf("%d\n", e || f && f);
   printf("%d\n", e && e || f);
   printf("%d\n", e && f || f);
   printf("%d\n", a && f | f);
   printf("%d\n", a | b ^ c & d);
   printf("%d, %d\n", a == a, a == b);
   printf("%d, %d\n", a != a, a != b);
   printf("%d\n", a != b && c != d);
   printf("%d\n", a + b * c / f);
   printf("%d\n", a + b * c / f);
   printf("%d\n", (4 << 4));
   printf("%d\n", (64 >> 4));

   ফেরত 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
