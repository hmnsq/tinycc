#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା MyInt;

ସଂରଚନା FunStruct
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା j;
};

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା FunStruct MyFunStruct;

ପ୍ରକାରବ୍ୟାଖ୍ୟା MyFunStruct *MoreFunThanEver;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା t[];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା tints[];

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   ପାଇଁ (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   ପାଇଁ (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)ଆକାର((t){1,2,3}));
   printf("%d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)ଆକାର((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   ପାଇଁ (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   ପାଇଁ (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   ପାଇଁ (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   ପାଇଁ (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ଫେରନ୍ତୁ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା A[3];
ବାହ୍ୟ A ଅଚଳ ca;
ବାହ୍ୟ ଅଚଳ A ca;
ବାହ୍ୟ ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା ca[3];

ପ୍ରକାରବ୍ୟାଖ୍ୟା A B[1][2];
ବାହ୍ୟ B ଅଚଳ cb;
ବାହ୍ୟ ଅଚଳ B cb;
ବାହ୍ୟ ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା cb[1][2][3];

ବାହ୍ୟ B b;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା b[1][2][3];

/* Funny but valid function declaration.  */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା functype (ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ବାହ୍ୟ functype func;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା func(ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
   ଫେରନ୍ତୁ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା set_anon_super(ଶୂନ୍ୟ);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା set_anon_super(ଶୂନ୍ୟ)
{
   ଫେରନ୍ତୁ 42;
}
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା sas_type (ଶୂନ୍ୟ);
ବାହ୍ୟ typeof(set_anon_super) set_anon_super;
ବାହ୍ୟ sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
