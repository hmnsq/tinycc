#অন্তর্ভাব <stdio.h>

প্রকারলেখ পূর্ণসংখ্যা MyInt;

কাঠামো FunStruct
{
   পূর্ণসংখ্যা i;
   পূর্ণসংখ্যা j;
};

প্রকারলেখ কাঠামো FunStruct MyFunStruct;

প্রকারলেখ MyFunStruct *MoreFunThanEver;

প্রকারলেখ পূর্ণসংখ্যা t[];
পূর্ণসংখ্যা tints[];

পূর্ণসংখ্যা প্রধান()
{
   পূর্ণসংখ্যা i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   জন্য (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   জন্য (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (পূর্ণসংখ্যা)আকার((t){1,2,3}));
   printf("%d\n", (পূর্ণসংখ্যা)আকার((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   জন্য (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   জন্য (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   জন্য (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   জন্য (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ফেরত 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

প্রকারলেখ পূর্ণসংখ্যা A[3];
বাহ্যিক A ধ্রুবক ca;
বাহ্যিক ধ্রুবক A ca;
বাহ্যিক ধ্রুবক পূর্ণসংখ্যা ca[3];

প্রকারলেখ A B[1][2];
বাহ্যিক B ধ্রুবক cb;
বাহ্যিক ধ্রুবক B cb;
বাহ্যিক ধ্রুবক পূর্ণসংখ্যা cb[1][2][3];

বাহ্যিক B b;
বাহ্যিক পূর্ণসংখ্যা b[1][2][3];

/* Funny but valid function declaration.  */
প্রকারলেখ পূর্ণসংখ্যা functype (পূর্ণসংখ্যা);
বাহ্যিক functype func;
পূর্ণসংখ্যা func(পূর্ণসংখ্যা i)
{
   ফেরত i + 1;
}

/* Even funnier function decl and definition using typeof.  */
পূর্ণসংখ্যা set_anon_super(শূন্য);
পূর্ণসংখ্যা set_anon_super(শূন্য)
{
   ফেরত 42;
}
প্রকারলেখ পূর্ণসংখ্যা sas_type (শূন্য);
বাহ্যিক typeof(set_anon_super) set_anon_super;
বাহ্যিক sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
