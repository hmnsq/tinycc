#شامل <stdio.h>

تعریفنوع صحیح MyInt;

ساختار FunStruct
{
   صحیح i;
   صحیح j;
};

تعریفنوع ساختار FunStruct MyFunStruct;

تعریفنوع MyFunStruct *MoreFunThanEver;

تعریفنوع صحیح t[];
صحیح tints[];

صحیح اصلی()
{
   صحیح i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   برای (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   برای (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (صحیح)اندازه((t){1,2,3}));
   printf("%d\n", (صحیح)اندازه((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   برای (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   برای (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   برای (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   برای (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   بازگشت 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

تعریفنوع صحیح A[3];
بیرونی A ثابت ca;
بیرونی ثابت A ca;
بیرونی ثابت صحیح ca[3];

تعریفنوع A B[1][2];
بیرونی B ثابت cb;
بیرونی ثابت B cb;
بیرونی ثابت صحیح cb[1][2][3];

بیرونی B b;
بیرونی صحیح b[1][2][3];

/* Funny but valid function declaration.  */
تعریفنوع صحیح functype (صحیح);
بیرونی functype func;
صحیح func(صحیح i)
{
   بازگشت i + 1;
}

/* Even funnier function decl and definition using typeof.  */
صحیح set_anon_super(تهی);
صحیح set_anon_super(تهی)
{
   بازگشت 42;
}
تعریفنوع صحیح sas_type (تهی);
بیرونی typeof(set_anon_super) set_anon_super;
بیرونی sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
