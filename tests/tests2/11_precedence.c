//#include <stdio.h>
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର *, ...);

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା d;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା e;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା f;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;

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

   ଫେରନ୍ତୁ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
