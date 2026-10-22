#अन्तर्भाव <stdio.h>

प्रकारनिर्देश पूर्णाङ्क MyInt;

संरचना FunStruct
{
   पूर्णाङ्क i;
   पूर्णाङ्क j;
};

प्रकारनिर्देश संरचना FunStruct MyFunStruct;

प्रकारनिर्देश MyFunStruct *MoreFunThanEver;

प्रकारनिर्देश पूर्णाङ्क t[];
पूर्णाङ्क tints[];

पूर्णाङ्क main()
{
   पूर्णाङ्क i, *p;
   MyInt a = 1;
   म_लिखो("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   म_लिखो("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   म_लिखो("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   लागि (i = 0; i < 3 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");
   p = (t){1,2,3,4};
   लागि (i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");

   म_लिखो("%d\n", (पूर्णाङ्क)परिमाण((t){1,2,3}));
   म_लिखो("%d\n", (पूर्णाङ्क)परिमाण((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   लागि (p = t3, i = 0; i < 3 ; i++) म_लिखो("%d ", *p++);
   लागि (p = t4, i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   लागि (p = t5, i = 0; i < 3 ; i++) म_लिखो("%d ", *p++);
   लागि (p = t6, i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");

   फर्काऊ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

प्रकारनिर्देश पूर्णाङ्क A[3];
बाह्य A अचर ca;
बाह्य अचर A ca;
बाह्य अचर पूर्णाङ्क ca[3];

प्रकारनिर्देश A B[1][2];
बाह्य B अचर cb;
बाह्य अचर B cb;
बाह्य अचर पूर्णाङ्क cb[1][2][3];

बाह्य B b;
बाह्य पूर्णाङ्क b[1][2][3];

/* Funny but valid function declaration.  */
प्रकारनिर्देश पूर्णाङ्क functype (पूर्णाङ्क);
बाह्य functype func;
पूर्णाङ्क func(पूर्णाङ्क i)
{
   फर्काऊ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
पूर्णाङ्क set_anon_super(शून्य);
पूर्णाङ्क set_anon_super(शून्य)
{
   फर्काऊ 42;
}
प्रकारनिर्देश पूर्णाङ्क sas_type (शून्य);
बाह्य typeof(set_anon_super) set_anon_super;
बाह्य sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
