//#include <stdio.h>
extern 정수 printf(const char *, ...);

정수 main()
{
   정수 a;
   정수 b;
   정수 c;
   정수 d;
   정수 e;
   정수 f;
   정수 x;
   정수 y;

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

   반환 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
