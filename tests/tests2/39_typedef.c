#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ MyInt;

ರಚನೆ FunStruct
{
   ಪೂರ್ಣಾಂಕ i;
   ಪೂರ್ಣಾಂಕ j;
};

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ FunStruct MyFunStruct;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MyFunStruct *ಇನ್ನಷ್ಟು_Fun_Than_Ever;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ t[];
ಪೂರ್ಣಾಂಕ tints[];

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಪೂರ್ಣಾಂಕ i, *p;
   MyInt a = 1;
   ಬರೆ("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   ಬರೆ("%d,%d\n", b.i, b.j);

   ಇನ್ನಷ್ಟು_Fun_Than_Ever c = &b;
   ಬರೆ("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   ಗಾಗಿ (i = 0; i < 3 ; i++) ಬರೆ("%d ", *p++); ಬರೆ("\n");
   p = (t){1,2,3,4};
   ಗಾಗಿ (i = 0; i < 4 ; i++) ಬರೆ("%d ", *p++); ಬರೆ("\n");

   ಬರೆ("%d\n", (ಪೂರ್ಣಾಂಕ)ಗಾತ್ರ((t){1,2,3}));
   ಬರೆ("%d\n", (ಪೂರ್ಣಾಂಕ)ಗಾತ್ರ((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   ಗಾಗಿ (p = t3, i = 0; i < 3 ; i++) ಬರೆ("%d ", *p++);
   ಗಾಗಿ (p = t4, i = 0; i < 4 ; i++) ಬರೆ("%d ", *p++); ಬರೆ("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   ಗಾಗಿ (p = t5, i = 0; i < 3 ; i++) ಬರೆ("%d ", *p++);
   ಗಾಗಿ (p = t6, i = 0; i < 4 ; i++) ಬರೆ("%d ", *p++); ಬರೆ("\n");

   ಹಿಂತಿರುಗಿ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ A[3];
ಬಾಹ್ಯ A ಸ್ಥಿರಾಂಕ ca;
ಬಾಹ್ಯ ಸ್ಥಿರಾಂಕ A ca;
ಬಾಹ್ಯ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ ca[3];

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ A B[1][2];
ಬಾಹ್ಯ B ಸ್ಥಿರಾಂಕ cb;
ಬಾಹ್ಯ ಸ್ಥಿರಾಂಕ B cb;
ಬಾಹ್ಯ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ cb[1][2][3];

ಬಾಹ್ಯ B b;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ b[1][2][3];

/* Funny but valid function declaration.  */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ functype (ಪೂರ್ಣಾಂಕ);
ಬಾಹ್ಯ functype func;
ಪೂರ್ಣಾಂಕ func(ಪೂರ್ಣಾಂಕ i)
{
   ಹಿಂತಿರುಗಿ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
ಪೂರ್ಣಾಂಕ ಗಣ_anon_super(ಶೂನ್ಯ);
ಪೂರ್ಣಾಂಕ ಗಣ_anon_super(ಶೂನ್ಯ)
{
   ಹಿಂತಿರುಗಿ 42;
}
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ sas_type (ಶೂನ್ಯ);
ಬಾಹ್ಯ typeof(ಗಣ_anon_super) ಗಣ_anon_super;
ಬಾಹ್ಯ sas_type ಗಣ_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
