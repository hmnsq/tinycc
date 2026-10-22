#ضمن <stdio.h>

تعريفنوع صحيح MyInt;

بنية FunStruct
{
   صحيح i;
   صحيح j;
};

تعريفنوع بنية FunStruct MyFunStruct;

تعريفنوع MyFunStruct *نور_Fun_Than_Ever;

تعريفنوع صحيح t[];
صحيح tints[];

صحيح اصلي()
{
   صحيح i, *p;
   MyInt a = 1;
   چاپ_کړه("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   چاپ_کړه("%d,%d\n", b.i, b.j);

   نور_Fun_Than_Ever c = &b;
   چاپ_کړه("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   لكل (i = 0; i < 3 ; i++) چاپ_کړه("%d ", *p++); چاپ_کړه("\n");
   p = (t){1,2,3,4};
   لكل (i = 0; i < 4 ; i++) چاپ_کړه("%d ", *p++); چاپ_کړه("\n");

   چاپ_کړه("%d\n", (صحيح)حجم((t){1,2,3}));
   چاپ_کړه("%d\n", (صحيح)حجم((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   لكل (p = t3, i = 0; i < 3 ; i++) چاپ_کړه("%d ", *p++);
   لكل (p = t4, i = 0; i < 4 ; i++) چاپ_کړه("%d ", *p++); چاپ_کړه("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   لكل (p = t5, i = 0; i < 3 ; i++) چاپ_کړه("%d ", *p++);
   لكل (p = t6, i = 0; i < 4 ; i++) چاپ_کړه("%d ", *p++); چاپ_کړه("\n");

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
صحيح سېټ_anon_super(فراغ);
صحيح سېټ_anon_super(فراغ)
{
   أرجع 42;
}
تعريفنوع صحيح sas_type (فراغ);
خارجي typeof(سېټ_anon_super) سېټ_anon_super;
خارجي sas_type سېټ_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
