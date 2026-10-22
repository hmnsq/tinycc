#અન્તર્ભાવ <stdio.h>

પ્રકારવ્યાખ્યા પૂર્ણાંક MyInt;

સંરચના FunStruct
{
   પૂર્ણાંક i;
   પૂર્ણાંક j;
};

પ્રકારવ્યાખ્યા સંરચના FunStruct MyFunStruct;

પ્રકારવ્યાખ્યા MyFunStruct *MoreFunThanEver;

પ્રકારવ્યાખ્યા પૂર્ણાંક t[];
પૂર્ણાંક tints[];

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   માટે (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   માટે (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (પૂર્ણાંક)કદ((t){1,2,3}));
   printf("%d\n", (પૂર્ણાંક)કદ((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   માટે (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   માટે (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   માટે (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   માટે (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   પાછા 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

પ્રકારવ્યાખ્યા પૂર્ણાંક A[3];
બાહ્ય A અચલ ca;
બાહ્ય અચલ A ca;
બાહ્ય અચલ પૂર્ણાંક ca[3];

પ્રકારવ્યાખ્યા A B[1][2];
બાહ્ય B અચલ cb;
બાહ્ય અચલ B cb;
બાહ્ય અચલ પૂર્ણાંક cb[1][2][3];

બાહ્ય B b;
બાહ્ય પૂર્ણાંક b[1][2][3];

/* Funny but valid function declaration.  */
પ્રકારવ્યાખ્યા પૂર્ણાંક functype (પૂર્ણાંક);
બાહ્ય functype func;
પૂર્ણાંક func(પૂર્ણાંક i)
{
   પાછા i + 1;
}

/* Even funnier function decl and definition using typeof.  */
પૂર્ણાંક set_anon_super(શૂન્ય);
પૂર્ણાંક set_anon_super(શૂન્ય)
{
   પાછા 42;
}
પ્રકારવ્યાખ્યા પૂર્ણાંક sas_type (શૂન્ય);
બાહ્ય typeof(set_anon_super) set_anon_super;
બાહ્ય sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
