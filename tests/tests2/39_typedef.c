#அந்தர்பாவ <stdio.h>

வகைவரை முழு MyInt;

கட்டமைப்பு FunStruct
{
   முழு i;
   முழு j;
};

வகைவரை கட்டமைப்பு FunStruct MyFunStruct;

வகைவரை MyFunStruct *MoreFunThanEver;

வகைவரை முழு t[];
முழு tints[];

முழு முதன்மை()
{
   முழு i, *p;
   MyInt a = 1;
   printf("%d\n", a);

   MyFunStruct b;
   b.i = 12;
   b.j = 34;
   printf("%d,%d\n", b.i, b.j);

   MoreFunThanEver c = &b;
   printf("%d,%d\n", c->i, c->j);

   p = (t){1,2,3};
   க்கு (i = 0; i < 3 ; i++) printf("%d ", *p++); printf("\n");
   p = (t){1,2,3,4};
   க்கு (i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   printf("%d\n", (முழு)அளவு((t){1,2,3}));
   printf("%d\n", (முழு)அளவு((t){1,2,3,4}));

   /* two arrays derived from same base type */
   t t3 = { 1,2,3 }, t4 = { 4,5,6,7 };
   க்கு (p = t3, i = 0; i < 3 ; i++) printf("%d ", *p++);
   க்கு (p = t4, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");
   typeof(tints) t5 = { 1,2,3 }, t6 = { 4,5,6,7 };
   க்கு (p = t5, i = 0; i < 3 ; i++) printf("%d ", *p++);
   க்கு (p = t6, i = 0; i < 4 ; i++) printf("%d ", *p++); printf("\n");

   திரும்பு 0;
}

/* "If the specification of an array type includes any type qualifiers,
   the element type is so-qualified, not the array type." */

வகைவரை முழு A[3];
வெளி A மாறிலி ca;
வெளி மாறிலி A ca;
வெளி மாறிலி முழு ca[3];

வகைவரை A B[1][2];
வெளி B மாறிலி cb;
வெளி மாறிலி B cb;
வெளி மாறிலி முழு cb[1][2][3];

வெளி B b;
வெளி முழு b[1][2][3];

/* Funny but valid function declaration.  */
வகைவரை முழு functype (முழு);
வெளி functype func;
முழு func(முழு i)
{
   திரும்பு i + 1;
}

/* Even funnier function decl and definition using typeof.  */
முழு set_anon_super(வெறுமை);
முழு set_anon_super(வெறுமை)
{
   திரும்பு 42;
}
வகைவரை முழு sas_type (வெறுமை);
வெளி typeof(set_anon_super) set_anon_super;
வெளி sas_type set_anon_super;

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
