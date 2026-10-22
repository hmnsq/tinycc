#అన్తర్భావ <stdio.h>

రకనిర్వచనం పూర్ణాంకం MyInt;

నిర్మాణం FunStruct
{
   పూర్ణాంకం i;
   పూర్ణాంకం j;
};

రకనిర్వచనం నిర్మాణం FunStruct MyFunStruct;

రకనిర్వచనం MyFunStruct *మరిన్ని_Fun_Than_Ever;

రకనిర్వచనం పూర్ణాంకం t[];
పూర్ణాంకం tints[];

పూర్ణాంకం ప్రధాన()
{
   పూర్ణాంకం i, *p;
   MyInt a = 1;
   రాయి("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   రాయి("%d,%d\n", b.i, b.j);

   మరిన్ని_Fun_Than_Ever c = &b;
   రాయి("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   కొరకు (i = 0; i < 3 ; i++) రాయి("%d ", *p++); రాయి("\n");
   p = (t){1,2,3,4};
   కొరకు (i = 0; i < 4 ; i++) రాయి("%d ", *p++); రాయి("\n");

   రాయి("%d\n", (పూర్ణాంకం)పరిమాణం((t){1,2,3}));
   రాయి("%d\n", (పూర్ణాంకం)పరిమాణం((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   కొరకు (p = t3, i = 0; i < 3 ; i++) రాయి("%d ", *p++);
   కొరకు (p = t4, i = 0; i < 4 ; i++) రాయి("%d ", *p++); రాయి("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   కొరకు (p = t5, i = 0; i < 3 ; i++) రాయి("%d ", *p++);
   కొరకు (p = t6, i = 0; i < 4 ; i++) రాయి("%d ", *p++); రాయి("\n");

   తిరిగి 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

రకనిర్వచనం పూర్ణాంకం A[3];
బాహ్య A స్థిరరాశి ca;
బాహ్య స్థిరరాశి A ca;
బాహ్య స్థిరరాశి పూర్ణాంకం ca[3];

రకనిర్వచనం A B[1][2];
బాహ్య B స్థిరరాశి cb;
బాహ్య స్థిరరాశి B cb;
బాహ్య స్థిరరాశి పూర్ణాంకం cb[1][2][3];

బాహ్య B b;
బాహ్య పూర్ణాంకం b[1][2][3];

/* Funny but valid function declaration.  */
రకనిర్వచనం పూర్ణాంకం functype (పూర్ణాంకం);
బాహ్య functype func;
పూర్ణాంకం func(పూర్ణాంకం i)
{
   తిరిగి i + 1;
}

/* Even funnier function decl and definition using typeof.  */
పూర్ణాంకం సమితి_anon_super(శూన్య);
పూర్ణాంకం సమితి_anon_super(శూన్య)
{
   తిరిగి 42;
}
రకనిర్వచనం పూర్ణాంకం sas_type (శూన్య);
బాహ్య typeof(సమితి_anon_super) సమితి_anon_super;
బాహ్య sas_type సమితి_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
