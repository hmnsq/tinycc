//#include <stdio.h>
extern ចំនួនគត់ printf(const var_na *, ...);

ចំនួនគត់ main()
{
   ចំនួនគត់ a;
   ចំនួនគត់ b;
   ចំនួនគត់ c;
   ចំនួនគត់ d;
   ចំនួនគត់ e;
   ចំនួនគត់ f;
   ចំនួនគត់ x;
   ចំនួនគត់ y;

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

   ត្រឡប់ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
