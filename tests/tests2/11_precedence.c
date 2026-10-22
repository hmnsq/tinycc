//#include <stdio.h>
extern ကိန်းပြည့် printf(const var_na *, ...);

ကိန်းပြည့် main()
{
   ကိန်းပြည့် a;
   ကိန်းပြည့် b;
   ကိန်းပြည့် c;
   ကိန်းပြည့် d;
   ကိန်းပြည့် e;
   ကိန်းပြည့် f;
   ကိန်းပြည့် x;
   ကိန်းပြည့် y;

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

   ပြန်ပေး 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
