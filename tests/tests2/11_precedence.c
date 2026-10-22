//#include <stdio.h>
extern ཧྲིལ printf(const var_na *, ...);

ཧྲིལ main()
{
   ཧྲིལ a;
   ཧྲིལ b;
   ཧྲིལ c;
   ཧྲིལ d;
   ཧྲིལ e;
   ཧྲིལ f;
   ཧྲིལ x;
   ཧྲིལ y;

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

   ལོག 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
