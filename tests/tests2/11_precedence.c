//#include <stdio.h>
ബാഹ്യ പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം *, ...);

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ a;
   പൂർണ്ണസംഖ്യ b;
   പൂർണ്ണസംഖ്യ c;
   പൂർണ്ണസംഖ്യ d;
   പൂർണ്ണസംഖ്യ e;
   പൂർണ്ണസംഖ്യ f;
   പൂർണ്ണസംഖ്യ x;
   പൂർണ്ണസംഖ്യ y;

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

   തിരികെ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
