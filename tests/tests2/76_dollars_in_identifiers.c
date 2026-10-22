#include <stdio.h>

#define $(x) x
#define $fred 10
#define joe$ 20
#define hen$y 30

#define $10(x) x*10
#define _$10(x) x/10

ཧྲིལ གཙོ()
{
   printf("fred=%d\n", $fred);
   printf("joe=%d\n", joe$);
   printf("henry=%d\n", hen$y);

   printf("fred2=%d\n", $($fred));
   printf("joe2=%d\n", $(joe$));
   printf("henry2=%d\n", $(hen$y));

   printf("fred10=%d\n", $10($fred));
   printf("joe_10=%d\n", _$10(joe$));

   ཧྲིལ $ = 10;
   ཧྲིལ a100$ = 100;
   ཧྲིལ a$$ = 1000;
   ཧྲིལ a$c$b = 2121;
   ཧྲིལ $100 = 10000;
   const var_na *$$$ = "money";

   printf("local=%d\n", $);
   printf("a100$=%d\n", a100$);
   printf("a$$=%d\n", a$$);
   printf("a$c$b=%d\n", a$c$b);
   printf("$100=%d\n", $100);
   printf("$$$=%s", $$$);

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
