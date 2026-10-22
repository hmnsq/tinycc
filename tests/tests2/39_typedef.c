#include <stdio.h>

typedef ចំនួនគត់ MyInt;

sa_nracanaa FunStruct
{
   ចំនួនគត់ i;
   ចំនួនគត់ j;
};

typedef sa_nracanaa FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef ចំនួនគត់ t[];
ចំនួនគត់ tints[];

ចំនួនគត់ main()
{
   ចំនួនគត់ i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   សម្រាប់ (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   សម្រាប់ (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (ចំនួនគត់)parimaa_na((t){1,2,3}));
   printf("%d\n", (ចំនួនគត់)parimaa_na((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   សម្រាប់ (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   សម្រាប់ (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   សម្រាប់ (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   សម្រាប់ (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ត្រឡប់ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef ចំនួនគត់ A[3];
extern A const ca;
extern const A ca;
extern const ចំនួនគត់ ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const ចំនួនគត់ cb[1][2][3];

extern B b;
extern ចំនួនគត់ b[1][2][3];

/* Funny but valid function declaration.  */
typedef ចំនួនគត់ functype (ចំនួនគត់);
extern functype func;
ចំនួនគត់ func(ចំនួនគត់ i)
{
   ត្រឡប់ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ចំនួនគត់ set_anon_super(void);
ចំនួនគត់ set_anon_super(void)
{
   ត្រឡប់ 42;
}
typedef ចំនួនគត់ sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
