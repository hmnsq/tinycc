//#include <stdio.h>
बाह्य पूर्णाङ्क printf(ध्रुव वर्ण *, ...);

पूर्णाङ्क main()
{
   पूर्णाङ्क a;
   पूर्णाङ्क b;
   पूर्णाङ्क c;
   पूर्णाङ्क d;
   पूर्णाङ्क e;
   पूर्णाङ्क f;
   पूर्णाङ्क x;
   पूर्णाङ्क y;

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

   प्रत्यागम 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
