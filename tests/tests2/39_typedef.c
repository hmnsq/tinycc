#include <stdio.h>

typedef ціле MyInt;

struct FunStruct
{
   ціле i;
   ціле j;
};

typedef struct FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef ціле t[];
ціле tints[];

ціле main()
{
   ціле i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   для (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   для (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (ціле)sizeof((t){1,2,3}));
   printf("%d\n", (ціле)sizeof((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   для (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   для (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   для (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   для (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   повернути 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef ціле A[3];
extern A const ca;
extern const A ca;
extern const ціле ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const ціле cb[1][2][3];

extern B b;
extern ціле b[1][2][3];

/* Funny but valid function declaration.  */
typedef ціле functype (ціле);
extern functype func;
ціле func(ціле i)
{
   повернути i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ціле set_anon_super(void);
ціле set_anon_super(void)
{
   повернути 42;
}
typedef ціле sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
