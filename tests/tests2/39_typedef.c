#अन्तर्भाव <stdio.h>

प्रकारनिर्देश पूर्णाङ्क MyInt;

संरचना FunStruct
{
   पूर्णाङ्क i;
   पूर्णाङ्क j;
};

प्रकारनिर्देश संरचना FunStruct MyFunStruct;

प्रकारनिर्देश MyFunStruct *अधिकम्_Fun_Than_Ever;

प्रकारनिर्देश पूर्णाङ्क t[];
पूर्णाङ्क tints[];

पूर्णाङ्क मुख्यम्()
{
   पूर्णाङ्क i, *p;
   MyInt a = 1;
   प्रारूप_लिख("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   प्रारूप_लिख("%d,%d\n", b.i, b.j);

   अधिकम्_Fun_Than_Ever c = &b;
   प्रारूप_लिख("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   प्रति (i = 0; i < 3 ; i++) प्रारूप_लिख("%d ", *p++); प्रारूप_लिख("\n");
   p = (t){1,2,3,4};
   प्रति (i = 0; i < 4 ; i++) प्रारूप_लिख("%d ", *p++); प्रारूप_लिख("\n");

   प्रारूप_लिख("%d\n", (पूर्णाङ्क)परिमाण((t){1,2,3}));
   प्रारूप_लिख("%d\n", (पूर्णाङ्क)परिमाण((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   प्रति (p = t3, i = 0; i < 3 ; i++) प्रारूप_लिख("%d ", *p++);
   प्रति (p = t4, i = 0; i < 4 ; i++) प्रारूप_लिख("%d ", *p++); प्रारूप_लिख("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   प्रति (p = t5, i = 0; i < 3 ; i++) प्रारूप_लिख("%d ", *p++);
   प्रति (p = t6, i = 0; i < 4 ; i++) प्रारूप_लिख("%d ", *p++); प्रारूप_लिख("\n");

   प्रत्यागम 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

प्रकारनिर्देश पूर्णाङ्क A[3];
बाह्य A ध्रुव ca;
बाह्य ध्रुव A ca;
बाह्य ध्रुव पूर्णाङ्क ca[3];

प्रकारनिर्देश A B[1][2];
बाह्य B ध्रुव cb;
बाह्य ध्रुव B cb;
बाह्य ध्रुव पूर्णाङ्क cb[1][2][3];

बाह्य B b;
बाह्य पूर्णाङ्क b[1][2][3];

/* Funny but valid function declaration.  */
प्रकारनिर्देश पूर्णाङ्क functype (पूर्णाङ्क);
बाह्य functype func;
पूर्णाङ्क func(पूर्णाङ्क i)
{
   प्रत्यागम i + 1;
}

/* Even funnier function decl and definition using typeof.  */
पूर्णाङ्क समुच्चयः_anon_super(शून्य);
पूर्णाङ्क समुच्चयः_anon_super(शून्य)
{
   प्रत्यागम 42;
}
प्रकारनिर्देश पूर्णाङ्क sas_type (शून्य);
बाह्य typeof(समुच्चयः_anon_super) समुच्चयः_anon_super;
बाह्य sas_type समुच्चयः_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
