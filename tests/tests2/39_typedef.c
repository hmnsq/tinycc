#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ MyInt;

ಸಂರಚನಾ FunStruct
{
   ಪೂರ್ಣಾಙ್ಕ i;
   ಪೂರ್ಣಾಙ್ಕ j;
};

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ FunStruct MyFunStruct;

ಪ್ರಕಾರನಿರ್ದೇಶ MyFunStruct *MoreFunThanEver;

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ t[];
ಪೂರ್ಣಾಙ್ಕ tints[];

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಪೂರ್ಣಾಙ್ಕ i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   ಪ್ರತಿ (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   ಪ್ರತಿ (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (ಪೂರ್ಣಾಙ್ಕ)ಪರಿಮಾಣ((t){1,2,3}));
   printf("%d\n", (ಪೂರ್ಣಾಙ್ಕ)ಪರಿಮಾಣ((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   ಪ್ರತಿ (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   ಪ್ರತಿ (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   ಪ್ರತಿ (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   ಪ್ರತಿ (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ A[3];
ಬಾಹ್ಯ A ಧ್ರುವ ca;
ಬಾಹ್ಯ ಧ್ರುವ A ca;
ಬಾಹ್ಯ ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ ca[3];

ಪ್ರಕಾರನಿರ್ದೇಶ A B[1][2];
ಬಾಹ್ಯ B ಧ್ರುವ cb;
ಬಾಹ್ಯ ಧ್ರುವ B cb;
ಬಾಹ್ಯ ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ cb[1][2][3];

ಬಾಹ್ಯ B b;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ b[1][2][3];

/* Funny but valid function declaration.  */
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ functype (ಪೂರ್ಣಾಙ್ಕ);
ಬಾಹ್ಯ functype func;
ಪೂರ್ಣಾಙ್ಕ func(ಪೂರ್ಣಾಙ್ಕ i)
{
   ಪ್ರತ್ಯಾಗಮ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ಪೂರ್ಣಾಙ್ಕ set_anon_super(ಶೂನ್ಯ);
ಪೂರ್ಣಾಙ್ಕ set_anon_super(ಶೂನ್ಯ)
{
   ಪ್ರತ್ಯಾಗಮ 42;
}
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ sas_type (ಶೂನ್ಯ);
ಬಾಹ್ಯ typeof(set_anon_super) set_anon_super;
ಬಾಹ್ಯ sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
