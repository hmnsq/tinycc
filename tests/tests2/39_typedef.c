#অন্তর্ভাৱ <stdio.h>

প্রকারনির্দেশ পূর্ণাঙ্ক MyInt;

সংরচনা FunStruct
{
   পূর্ণাঙ্ক i;
   পূর্ণাঙ্ক j;
};

প্রকারনির্দেশ সংরচনা FunStruct MyFunStruct;

প্রকারনির্দেশ MyFunStruct *MoreFunThanEver;

প্রকারনির্দেশ পূর্ণাঙ্ক t[];
পূর্ণাঙ্ক tints[];

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   বাবে (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   বাবে (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (পূর্ণাঙ্ক)পরিমাণ((t){1,2,3}));
   printf("%d\n", (পূর্ণাঙ্ক)পরিমাণ((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   বাবে (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   বাবে (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   বাবে (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   বাবে (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ঘূৰাই 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

প্রকারনির্দেশ পূর্ণাঙ্ক A[3];
বাহ্য A ধ্রুৱ ca;
বাহ্য ধ্রুৱ A ca;
বাহ্য ধ্রুৱ পূর্ণাঙ্ক ca[3];

প্রকারনির্দেশ A B[1][2];
বাহ্য B ধ্রুৱ cb;
বাহ্য ধ্রুৱ B cb;
বাহ্য ধ্রুৱ পূর্ণাঙ্ক cb[1][2][3];

বাহ্য B b;
বাহ্য পূর্ণাঙ্ক b[1][2][3];

/* Funny but valid function declaration.  */
প্রকারনির্দেশ পূর্ণাঙ্ক functype (পূর্ণাঙ্ক);
বাহ্য functype func;
পূর্ণাঙ্ক func(পূর্ণাঙ্ক i)
{
   ঘূৰাই i + 1;
}

/* Even funnier function decl and definition using typeof.  */
পূর্ণাঙ্ক set_anon_super(শূন্য);
পূর্ণাঙ্ক set_anon_super(শূন্য)
{
   ঘূৰাই 42;
}
প্রকারনির্দেশ পূর্ণাঙ্ক sas_type (শূন্য);
বাহ্য typeof(set_anon_super) set_anon_super;
বাহ্য sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
