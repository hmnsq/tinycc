#include <stdio.h>

typedef පූර්ණ_සංඛ්‍යා MyInt;

sa_nracanaa FunStruct
{
   පූර්ණ_සංඛ්‍යා i;
   පූර්ණ_සංඛ්‍යා j;
};

typedef sa_nracanaa FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef පූර්ණ_සංඛ්‍යා t[];
පූර්ණ_සංඛ්‍යා tints[];

පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   සඳහා (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   සඳහා (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (පූර්ණ_සංඛ්‍යා)parimaa_na((t){1,2,3}));
   printf("%d\n", (පූර්ණ_සංඛ්‍යා)parimaa_na((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   සඳහා (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   සඳහා (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   සඳහා (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   සඳහා (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ආපසු 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef පූර්ණ_සංඛ්‍යා A[3];
extern A const ca;
extern const A ca;
extern const පූර්ණ_සංඛ්‍යා ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const පූර්ණ_සංඛ්‍යා cb[1][2][3];

extern B b;
extern පූර්ණ_සංඛ්‍යා b[1][2][3];

/* Funny but valid function declaration.  */
typedef පූර්ණ_සංඛ්‍යා functype (පූර්ණ_සංඛ්‍යා);
extern functype func;
පූර්ණ_සංඛ්‍යා func(පූර්ණ_සංඛ්‍යා i)
{
   ආපසු i + 1;
}

/* Even funnier function decl and definition using typeof.  */
පූර්ණ_සංඛ්‍යා set_anon_super(void);
පූර්ණ_සංඛ්‍යා set_anon_super(void)
{
   ආපසු 42;
}
typedef පූර්ණ_සංඛ්‍යා sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
