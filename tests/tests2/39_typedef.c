#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ MyInt;

ਬਣਤਰ FunStruct
{
   ਪੂਰਨ i;
   ਪੂਰਨ j;
};

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ FunStruct MyFunStruct;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ MyFunStruct *ਹੋਰ_Fun_Than_Ever;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ t[];
ਪੂਰਨ tints[];

ਪੂਰਨ ਮੁੱਖ()
{
   ਪੂਰਨ i, *p;
   MyInt a = 1;
   ਲਿਖੋ("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   ਲਿਖੋ("%d,%d\n", b.i, b.j);

   ਹੋਰ_Fun_Than_Ever c = &b;
   ਲਿਖੋ("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   ਲਈ (i = 0; i < 3 ; i++) ਲਿਖੋ("%d ", *p++); ਲਿਖੋ("\n");
   p = (t){1,2,3,4};
   ਲਈ (i = 0; i < 4 ; i++) ਲਿਖੋ("%d ", *p++); ਲਿਖੋ("\n");

   ਲਿਖੋ("%d\n", (ਪੂਰਨ)ਆਕਾਰ((t){1,2,3}));
   ਲਿਖੋ("%d\n", (ਪੂਰਨ)ਆਕਾਰ((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   ਲਈ (p = t3, i = 0; i < 3 ; i++) ਲਿਖੋ("%d ", *p++);
   ਲਈ (p = t4, i = 0; i < 4 ; i++) ਲਿਖੋ("%d ", *p++); ਲਿਖੋ("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   ਲਈ (p = t5, i = 0; i < 3 ; i++) ਲਿਖੋ("%d ", *p++);
   ਲਈ (p = t6, i = 0; i < 4 ; i++) ਲਿਖੋ("%d ", *p++); ਲਿਖੋ("\n");

   ਵਾਪਸ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ A[3];
ਬਾਹਰੀ A ਅਚਲ ca;
ਬਾਹਰੀ ਅਚਲ A ca;
ਬਾਹਰੀ ਅਚਲ ਪੂਰਨ ca[3];

ਕਿਸਮਪਰਿਭਾਸ਼ਾ A B[1][2];
ਬਾਹਰੀ B ਅਚਲ cb;
ਬਾਹਰੀ ਅਚਲ B cb;
ਬਾਹਰੀ ਅਚਲ ਪੂਰਨ cb[1][2][3];

ਬਾਹਰੀ B b;
ਬਾਹਰੀ ਪੂਰਨ b[1][2][3];

/* Funny but valid function declaration.  */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ functype (ਪੂਰਨ);
ਬਾਹਰੀ functype func;
ਪੂਰਨ func(ਪੂਰਨ i)
{
   ਵਾਪਸ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ਪੂਰਨ ਸੈੱਟ_anon_super(ਖਾਲੀ);
ਪੂਰਨ ਸੈੱਟ_anon_super(ਖਾਲੀ)
{
   ਵਾਪਸ 42;
}
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ sas_type (ਖਾਲੀ);
ਬਾਹਰੀ typeof(ਸੈੱਟ_anon_super) ਸੈੱਟ_anon_super;
ਬਾਹਰੀ sas_type ਸੈੱਟ_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
