//#include <stdio.h>
বাহ্য পূর্ণাঙ্ক printf(ধ্রুব বর্ণ *, ...);

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক a;
   পূর্ণাঙ্ক b;
   পূর্ণাঙ্ক c;
   পূর্ণাঙ্ক d;
   পূর্ণাঙ্ক e;
   পূর্ণাঙ্ক f;
   পূর্ণাঙ্ক x;
   পূর্ণাঙ্ক y;

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

   প্রত্যাগম 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
