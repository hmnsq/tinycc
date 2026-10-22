#include <stdio.h>

typedef ཧྲིལ MyInt;

sa_nracanaa FunStruct
{
   ཧྲིལ i;
   ཧྲིལ j;
};

typedef sa_nracanaa FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef ཧྲིལ t[];
ཧྲིལ tints[];

ཧྲིལ main()
{
   ཧྲིལ i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   དོན་ལུ (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   དོན་ལུ (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (ཧྲིལ)parimaa_na((t){1,2,3}));
   printf("%d\n", (ཧྲིལ)parimaa_na((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   དོན་ལུ (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   དོན་ལུ (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   དོན་ལུ (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   དོན་ལུ (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ལོག 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef ཧྲིལ A[3];
extern A const ca;
extern const A ca;
extern const ཧྲིལ ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const ཧྲིལ cb[1][2][3];

extern B b;
extern ཧྲིལ b[1][2][3];

/* Funny but valid function declaration.  */
typedef ཧྲིལ functype (ཧྲིལ);
extern functype func;
ཧྲིལ func(ཧྲིལ i)
{
   ལོག i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ཧྲིལ set_anon_super(void);
ཧྲིལ set_anon_super(void)
{
   ལོག 42;
}
typedef ཧྲིལ sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
