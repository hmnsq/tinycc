//#include <stdio.h>
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ *, ...);

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಪೂರ್ಣಾಙ್ಕ a;
   ಪೂರ್ಣಾಙ್ಕ b;
   ಪೂರ್ಣಾಙ್ಕ c;
   ಪೂರ್ಣಾಙ್ಕ d;
   ಪೂರ್ಣಾಙ್ಕ e;
   ಪೂರ್ಣಾಙ್ಕ f;
   ಪೂರ್ಣಾಙ್ಕ x;
   ಪೂರ್ಣಾಙ್ಕ y;

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

   ಪ್ರತ್ಯಾಗಮ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
