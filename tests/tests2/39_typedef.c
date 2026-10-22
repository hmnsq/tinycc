#include <stdio.h>

typedef 整数 MyInt;

struct FunStruct
{
   整数 i;
   整数 j;
};

typedef struct FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef 整数 t[];
整数 tints[];

整数 主要()
{
   整数 i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   为 (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   为 (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (整数)sizeof((t){1,2,3}));
   printf("%d\n", (整数)sizeof((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   为 (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   为 (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   为 (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   为 (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   返回 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef 整数 A[3];
extern A const ca;
extern const A ca;
extern const 整数 ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const 整数 cb[1][2][3];

extern B b;
extern 整数 b[1][2][3];

/* Funny but valid function declaration.  */
typedef 整数 functype (整数);
extern functype func;
整数 func(整数 i)
{
   返回 i + 1;
}

/* Even funnier function decl and definition using typeof.  */
整数 set_anon_super(void);
整数 set_anon_super(void)
{
   返回 42;
}
typedef 整数 sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
