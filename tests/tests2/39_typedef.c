#समावेश <stdio.h>

प्रकार पूर्णांक MyInt;

काष्ठा FunStruct
{
   पूर्णांक i;
   पूर्णांक j;
};

प्रकार काष्ठा FunStruct MyFunStruct;

प्रकार MyFunStruct *MoreFunThanEver;

प्रकार पूर्णांक t[];
पूर्णांक tints[];

पूर्णांक मुख्य()
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
   क्रम (i = 0; i < 3 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");
   p = (t){1,2,3,4};
   क्रम (i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");

   म_लिखो("%d\n", (पूर्णांक)माप((t){1,2,3}));
   म_लिखो("%d\n", (पूर्णांक)माप((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   क्रम (p = t3, i = 0; i < 3 ; i++) म_लिखो("%d ", *p++);
   क्रम (p = t4, i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   क्रम (p = t5, i = 0; i < 3 ; i++) म_लिखो("%d ", *p++);
   क्रम (p = t6, i = 0; i < 4 ; i++) म_लिखो("%d ", *p++); म_लिखो("\n");

   वापस 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

प्रकार पूर्णांक A[3];
बाह्य A स्थिर ca;
बाह्य स्थिर A ca;
बाह्य स्थिर पूर्णांक ca[3];

प्रकार A B[1][2];
बाह्य B स्थिर cb;
बाह्य स्थिर B cb;
बाह्य स्थिर पूर्णांक cb[1][2][3];

बाह्य B b;
बाह्य पूर्णांक b[1][2][3];

/* Funny but valid function declaration.  */
प्रकार पूर्णांक functype (पूर्णांक);
बाह्य functype func;
पूर्णांक func(पूर्णांक i)
{
   वापस i + 1;
}

/* Even funnier function decl and definition using typeof.  */
पूर्णांक set_anon_super(व्योम);
पूर्णांक set_anon_super(व्योम)
{
   वापस 42;
}
प्रकार पूर्णांक sas_type (व्योम);
बाह्य typeof(set_anon_super) set_anon_super;
बाह्य sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
