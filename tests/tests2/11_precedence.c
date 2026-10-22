//#include <stdio.h>
வெளி முழு printf(மாறிலி எழுத்து *, ...);

முழு முதன்மை()
{
   முழு a;
   முழு b;
   முழு c;
   முழு d;
   முழு e;
   முழு f;
   முழு x;
   முழு y;

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

   திரும்பு 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
