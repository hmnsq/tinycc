#अन्तर्भाव <stdio.h>

प्रकारव्याख्या पूर्णांक MyInt;

संरचना FunStruct
{
   पूर्णांक i;
   पूर्णांक j;
};

प्रकारव्याख्या संरचना FunStruct MyFunStruct;

प्रकारव्याख्या MyFunStruct *MoreFunThanEver;

प्रकारव्याख्या पूर्णांक t[];
पूर्णांक tints[];

पूर्णांक main()
{
   पूर्णांक i, *p;
   MyInt a = 1;
   म_लिखो("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   म_लिखो("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   म_लिखो("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   साठी (i = 0; i < 3 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");
   p = (t){1,2,3,4};
   साठी (i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");

   म_लिखो("%d\n", (पूर्णांक)आकार((t){1,2,3}));
   म_लिखो("%d\n", (पूर्णांक)आकार((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   साठी (p = t3, i = 0; i < 3 ; i++) म_लिखो("%d ", *p++);
   साठी (p = t4, i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   साठी (p = t5, i = 0; i < 3 ; i++) म_लिखो("%d ", *p++);
   साठी (p = t6, i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");

   परत 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

प्रकारव्याख्या पूर्णांक A[3];
बाह्य A स्थिरांक ca;
बाह्य स्थिरांक A ca;
बाह्य स्थिरांक पूर्णांक ca[3];

प्रकारव्याख्या A B[1][2];
बाह्य B स्थिरांक cb;
बाह्य स्थिरांक B cb;
बाह्य स्थिरांक पूर्णांक cb[1][2][3];

बाह्य B b;
बाह्य पूर्णांक b[1][2][3];

/* Funny but valid function declaration.  */
प्रकारव्याख्या पूर्णांक functype (पूर्णांक);
बाह्य functype func;
पूर्णांक func(पूर्णांक i)
{
   परत i + 1;
}

/* Even funnier function decl and definition using typeof.  */
पूर्णांक set_anon_super(शून्य);
पूर्णांक set_anon_super(शून्य)
{
   परत 42;
}
प्रकारव्याख्या पूर्णांक sas_type (शून्य);
बाह्य typeof(set_anon_super) set_anon_super;
बाह्य sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
