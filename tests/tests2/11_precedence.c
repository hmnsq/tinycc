//#include <stdio.h>
extern จำนวนเต็ม printf(const var_na *, ...);

จำนวนเต็ม หลัก()
{
   จำนวนเต็ม a;
   จำนวนเต็ม b;
   จำนวนเต็ม c;
   จำนวนเต็ม d;
   จำนวนเต็ม e;
   จำนวนเต็ม f;
   จำนวนเต็ม x;
   จำนวนเต็ม y;

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

   คืน 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
