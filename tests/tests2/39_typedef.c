#include <stdio.h>

typedef цео MyInt;

struct FunStruct
{
   цео i;
   цео j;
};

typedef struct FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef цео t[];
цео tints[];

цео main()
{
   цео i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   за (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   за (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (цео)sizeof((t){1,2,3}));
   printf("%d\n", (цео)sizeof((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   за (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   за (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   за (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   за (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   врати 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef цео A[3];
extern A const ca;
extern const A ca;
extern const цео ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const цео cb[1][2][3];

extern B b;
extern цео b[1][2][3];

/* Funny but valid function declaration.  */
typedef цео functype (цео);
extern functype func;
цео func(цео i)
{
   врати i + 1;
}

/* Even funnier function decl and definition using typeof.  */
цео set_anon_super(void);
цео set_anon_super(void)
{
   врати 42;
}
typedef цео sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
