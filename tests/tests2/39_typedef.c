#include <stdio.h>

typedef ຈຳນວນເຕັມ MyInt;

sa_nracanaa FunStruct
{
   ຈຳນວນເຕັມ i;
   ຈຳນວນເຕັມ j;
};

typedef sa_nracanaa FunStruct MyFunStruct;

typedef MyFunStruct *MoreFunThanEver;

typedef ຈຳນວນເຕັມ t[];
ຈຳນວນເຕັມ tints[];

ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   ສຳລັບ (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   ສຳລັບ (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (ຈຳນວນເຕັມ)parimaa_na((t){1,2,3}));
   printf("%d\n", (ຈຳນວນເຕັມ)parimaa_na((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   ສຳລັບ (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   ສຳລັບ (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   ສຳລັບ (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   ສຳລັບ (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ສົ່ງຄືນ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

typedef ຈຳນວນເຕັມ A[3];
extern A const ca;
extern const A ca;
extern const ຈຳນວນເຕັມ ca[3];

typedef A B[1][2];
extern B const cb;
extern const B cb;
extern const ຈຳນວນເຕັມ cb[1][2][3];

extern B b;
extern ຈຳນວນເຕັມ b[1][2][3];

/* Funny but valid function declaration.  */
typedef ຈຳນວນເຕັມ functype (ຈຳນວນເຕັມ);
extern functype func;
ຈຳນວນເຕັມ func(ຈຳນວນເຕັມ i)
{
   ສົ່ງຄືນ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ຈຳນວນເຕັມ set_anon_super(void);
ຈຳນວນເຕັມ set_anon_super(void)
{
   ສົ່ງຄືນ 42;
}
typedef ຈຳນວນເຕັມ sas_type (void);
extern typeof(set_anon_super) set_anon_super;
extern sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
