#include <stdio.h>

typedef puur_naa_nka MyInt;

sa_nracanaa FunStruct
{
   puur_naa_nka i;
   puur_naa_nka j;
};

typedef sa_nracanaa FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef puur_naa_nka t[];
puur_naa_nka tints[];

puur_naa_nka main()
{
   puur_naa_nka i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   for (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   for (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (puur_naa_nka)parimaa_na((t){1,2,3}));
   printf("%d\n", (puur_naa_nka)parimaa_na((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   for (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   for (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   for (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   for (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ပွၵ်ႈ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef puur_naa_nka A[3];
extern A const ca;
extern const A ca;
extern const puur_naa_nka ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const puur_naa_nka cb[1][2][3];

extern B b;
extern puur_naa_nka b[1][2][3];

/* Funny but valid function declaration.  */
typedef puur_naa_nka functype (puur_naa_nka);
extern functype func;
puur_naa_nka func(puur_naa_nka i)
{
   ပွၵ်ႈ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
puur_naa_nka set_anon_super(void);
puur_naa_nka set_anon_super(void)
{
   ပွၵ်ႈ 42;
}
typedef puur_naa_nka sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
