#شامل <stdio.h>

قسمتعریف صحیح MyInt;

ساخت FunStruct
{
   صحیح i;
   صحیح j;
};

قسمتعریف ساخت FunStruct MyFunStruct;

قسمتعریف MyFunStruct *مزید_Fun_Than_Ever;

قسمتعریف صحیح t[];
صحیح tints[];

صحیح مین()
{
   صحیح i, *p;
   MyInt a = 1;
   لکھو("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   لکھو("%d,%d\n", b.i, b.j);

   مزید_Fun_Than_Ever c = &b;
   لکھو("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   برائے (i = 0; i < 3 ; i++) لکھو("%d ", *p++); لکھو("\n");
   p = (t){1,2,3,4};
   برائے (i = 0; i < 4 ; i++) لکھو("%d ", *p++); لکھو("\n");

   لکھو("%d\n", (صحیح)حجم((t){1,2,3}));
   لکھو("%d\n", (صحیح)حجم((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   برائے (p = t3, i = 0; i < 3 ; i++) لکھو("%d ", *p++);
   برائے (p = t4, i = 0; i < 4 ; i++) لکھو("%d ", *p++); لکھو("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   برائے (p = t5, i = 0; i < 3 ; i++) لکھو("%d ", *p++);
   برائے (p = t6, i = 0; i < 4 ; i++) لکھو("%d ", *p++); لکھو("\n");

   واپس 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

قسمتعریف صحیح A[3];
خارجی A ثابت ca;
خارجی ثابت A ca;
خارجی ثابت صحیح ca[3];

قسمتعریف A B[1][2];
خارجی B ثابت cb;
خارجی ثابت B cb;
خارجی ثابت صحیح cb[1][2][3];

خارجی B b;
خارجی صحیح b[1][2][3];

/* Funny but valid function declaration.  */
قسمتعریف صحیح functype (صحیح);
خارجی functype func;
صحیح func(صحیح i)
{
   واپس i + 1;
}

/* Even funnier function decl and definition using typeof.  */
صحیح سیٹ_anon_super(خالی);
صحیح سیٹ_anon_super(خالی)
{
   واپس 42;
}
قسمتعریف صحیح sas_type (خالی);
خارجی typeof(سیٹ_anon_super) سیٹ_anon_super;
خارجی sas_type سیٹ_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
