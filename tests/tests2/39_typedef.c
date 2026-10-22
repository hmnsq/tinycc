#include <stdio.h>

typedef số_nguyên MyInt;

struct FunStruct
{
   số_nguyên i;
   số_nguyên j;
};

typedef struct FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef số_nguyên t[];
số_nguyên tints[];

số_nguyên main()
{
   số_nguyên i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   cho (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   cho (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (số_nguyên)sizeof((t){1,2,3}));
   printf("%d\n", (số_nguyên)sizeof((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   cho (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   cho (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   cho (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   cho (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   trả_về 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef số_nguyên A[3];
extern A const ca;
extern const A ca;
extern const số_nguyên ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const số_nguyên cb[1][2][3];

extern B b;
extern số_nguyên b[1][2][3];

/* Funny but valid function declaration.  */
typedef số_nguyên functype (số_nguyên);
extern functype func;
số_nguyên func(số_nguyên i)
{
   trả_về i + 1;
}

/* Even funnier function decl and definition using typeof.  */
số_nguyên set_anon_super(void);
số_nguyên set_anon_super(void)
{
   trả_về 42;
}
typedef số_nguyên sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
