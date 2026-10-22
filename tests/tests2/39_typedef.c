#include <stdio.h>

typedef ကိန်းပြည့် MyInt;

sa_nracanaa FunStruct
{
   ကိန်းပြည့် i;
   ကိန်းပြည့် j;
};

typedef sa_nracanaa FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef ကိန်းပြည့် t[];
ကိန်းပြည့် tints[];

ကိန်းပြည့် main()
{
   ကိန်းပြည့် i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   အတွက် (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   အတွက် (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (ကိန်းပြည့်)parimaa_na((t){1,2,3}));
   printf("%d\n", (ကိန်းပြည့်)parimaa_na((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   အတွက် (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   အတွက် (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   အတွက် (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   အတွက် (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ပြန်ပေး 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef ကိန်းပြည့် A[3];
extern A const ca;
extern const A ca;
extern const ကိန်းပြည့် ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const ကိန်းပြည့် cb[1][2][3];

extern B b;
extern ကိန်းပြည့် b[1][2][3];

/* Funny but valid function declaration.  */
typedef ကိန်းပြည့် functype (ကိန်းပြည့်);
extern functype func;
ကိန်းပြည့် func(ကိန်းပြည့် i)
{
   ပြန်ပေး i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ကိန်းပြည့် set_anon_super(void);
ကိန်းပြည့် set_anon_super(void)
{
   ပြန်ပေး 42;
}
typedef ကိန်းပြည့် sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
