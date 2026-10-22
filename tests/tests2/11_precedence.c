//#include <stdio.h>
extern puur_naa_nka printf(const var_na *, ...);

puur_naa_nka main()
{
   puur_naa_nka a;
   puur_naa_nka b;
   puur_naa_nka c;
   puur_naa_nka d;
   puur_naa_nka e;
   puur_naa_nka f;
   puur_naa_nka x;
   puur_naa_nka y;

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

   ᱨᱩᱣᱟᱹᱲ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
