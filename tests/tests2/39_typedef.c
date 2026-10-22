#include <stdio.h>

typedef จำนวนเต็ม MyInt;

sa_nracanaa FunStruct
{
   จำนวนเต็ม i;
   จำนวนเต็ม j;
};

typedef sa_nracanaa FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef จำนวนเต็ม t[];
จำนวนเต็ม tints[];

จำนวนเต็ม หลัก()
{
   จำนวนเต็ม i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   สำหรับ (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   สำหรับ (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (จำนวนเต็ม)parimaa_na((t){1,2,3}));
   printf("%d\n", (จำนวนเต็ม)parimaa_na((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   สำหรับ (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   สำหรับ (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   สำหรับ (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   สำหรับ (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   คืน 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef จำนวนเต็ม A[3];
extern A const ca;
extern const A ca;
extern const จำนวนเต็ม ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const จำนวนเต็ม cb[1][2][3];

extern B b;
extern จำนวนเต็ม b[1][2][3];

/* Funny but valid function declaration.  */
typedef จำนวนเต็ม functype (จำนวนเต็ม);
extern functype func;
จำนวนเต็ม func(จำนวนเต็ม i)
{
   คืน i + 1;
}

/* Even funnier function decl and definition using typeof.  */
จำนวนเต็ม set_anon_super(void);
จำนวนเต็ม set_anon_super(void)
{
   คืน 42;
}
typedef จำนวนเต็ม sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
