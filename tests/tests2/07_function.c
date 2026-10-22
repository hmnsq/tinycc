#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ myfunc(പൂർണ്ണസംഖ്യ x)
{
   തിരികെ x * x;
}

ശൂന്യം vfunc(പൂർണ്ണസംഖ്യ a)
{
   printf("a=%d\n", a);
}

ശൂന്യം qfunc()
{
   printf("qfunc()\n");
}

ശൂന്യം zfunc()
{
	((ശൂന്യം (*)(ശൂന്യം))0) ();
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   തിരികെ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
