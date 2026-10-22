#ضمن <stdio.h>

تعريفنوع صحيح MyInt;

بنية FunStruct
{
   صحيح i;
   صحيح j;
};

تعريفنوع بنية FunStruct MyFunStruct;

تعريفنوع MyFunStruct *وڌيڪ_Fun_Than_Ever;

تعريفنوع صحيح t[];
صحيح tints[];

صحيح مکيه()
{
   صحيح i, *p;
   MyInt a = 1;
   لکو("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   لکو("%d,%d\n", b.i, b.j);

   وڌيڪ_Fun_Than_Ever c = &b;
   لکو("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   لكل (i = 0; i < 3 ; i++) لکو("%d ", *p++); لکو("\n");
   p = (t){1,2,3,4};
   لكل (i = 0; i < 4 ; i++) لکو("%d ", *p++); لکو("\n");

   لکو("%d\n", (صحيح)حجم((t){1,2,3}));
   لکو("%d\n", (صحيح)حجم((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   لكل (p = t3, i = 0; i < 3 ; i++) لکو("%d ", *p++);
   لكل (p = t4, i = 0; i < 4 ; i++) لکو("%d ", *p++); لکو("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   لكل (p = t5, i = 0; i < 3 ; i++) لکو("%d ", *p++);
   لكل (p = t6, i = 0; i < 4 ; i++) لکو("%d ", *p++); لکو("\n");

   أرجع 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

تعريفنوع صحيح A[3];
خارجي A ثابت ca;
خارجي ثابت A ca;
خارجي ثابت صحيح ca[3];

تعريفنوع A B[1][2];
خارجي B ثابت cb;
خارجي ثابت B cb;
خارجي ثابت صحيح cb[1][2][3];

خارجي B b;
خارجي صحيح b[1][2][3];

/* Funny but valid function declaration.  */
تعريفنوع صحيح functype (صحيح);
خارجي functype func;
صحيح func(صحيح i)
{
   أرجع i + 1;
}

/* Even funnier function decl and definition using typeof.  */
صحيح سيٽ_anon_super(فراغ);
صحيح سيٽ_anon_super(فراغ)
{
   أرجع 42;
}
تعريفنوع صحيح sas_type (فراغ);
خارجي typeof(سيٽ_anon_super) سيٽ_anon_super;
خارجي sas_type سيٽ_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
