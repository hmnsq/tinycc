#include <stdio.h>

typedef 정수 MyInt;

struct FunStruct
{
   정수 i;
   정수 j;
};

typedef struct FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef 정수 t[];
정수 tints[];

정수 main()
{
   정수 i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   위해 (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   위해 (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (정수)sizeof((t){1,2,3}));
   printf("%d\n", (정수)sizeof((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   위해 (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   위해 (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   위해 (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   위해 (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   반환 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef 정수 A[3];
extern A const ca;
extern const A ca;
extern const 정수 ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const 정수 cb[1][2][3];

extern B b;
extern 정수 b[1][2][3];

/* Funny but valid function declaration.  */
typedef 정수 functype (정수);
extern functype func;
정수 func(정수 i)
{
   반환 i + 1;
}

/* Even funnier function decl and definition using typeof.  */
정수 set_anon_super(void);
정수 set_anon_super(void)
{
   반환 42;
}
typedef 정수 sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
