#അന്തര്ഭാവ <stdio.h>

തരനിർവചനം പൂർണ്ണസംഖ്യ MyInt;

ഘടന FunStruct
{
   പൂർണ്ണസംഖ്യ i;
   പൂർണ്ണസംഖ്യ j;
};

തരനിർവചനം ഘടന FunStruct MyFunStruct;

തരനിർവചനം MyFunStruct *MoreFunThanEver;

തരനിർവചനം പൂർണ്ണസംഖ്യ t[];
പൂർണ്ണസംഖ്യ tints[];

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   വേണ്ടി (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   വേണ്ടി (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (പൂർണ്ണസംഖ്യ)വലുപ്പം((t){1,2,3}));
   printf("%d\n", (പൂർണ്ണസംഖ്യ)വലുപ്പം((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   വേണ്ടി (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   വേണ്ടി (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   വേണ്ടി (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   വേണ്ടി (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   തിരികെ 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

തരനിർവചനം പൂർണ്ണസംഖ്യ A[3];
ബാഹ്യ A സ്ഥിരം ca;
ബാഹ്യ സ്ഥിരം A ca;
ബാഹ്യ സ്ഥിരം പൂർണ്ണസംഖ്യ ca[3];

തരനിർവചനം A B[1][2];
ബാഹ്യ B സ്ഥിരം cb;
ബാഹ്യ സ്ഥിരം B cb;
ബാഹ്യ സ്ഥിരം പൂർണ്ണസംഖ്യ cb[1][2][3];

ബാഹ്യ B b;
ബാഹ്യ പൂർണ്ണസംഖ്യ b[1][2][3];

/* Funny but valid function declaration.  */
തരനിർവചനം പൂർണ്ണസംഖ്യ functype (പൂർണ്ണസംഖ്യ);
ബാഹ്യ functype func;
പൂർണ്ണസംഖ്യ func(പൂർണ്ണസംഖ്യ i)
{
   തിരികെ i + 1;
}

/* Even funnier function decl and definition using typeof.  */
പൂർണ്ണസംഖ്യ set_anon_super(ശൂന്യം);
പൂർണ്ണസംഖ്യ set_anon_super(ശൂന്യം)
{
   തിരികെ 42;
}
തരനിർവചനം പൂർണ്ണസംഖ്യ sas_type (ശൂന്യം);
ബാഹ്യ typeof(set_anon_super) set_anon_super;
ബാഹ്യ sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
