#അന്തര്ഭാവ <stdio.h>

എണ്ണൽ fred
{
   a,
   b,
   c,
   d,
   e = 54,
   f = 73,
   g,
   h
};

/* All following uses of enum efoo should compile
   without warning.  While forward enums aren't ISO C,
   it's accepted by GCC also in strict mode, and only warned
   about with -pedantic.  This happens in the real world.  */
/* Strict ISO C doesn't allow this kind of forward declaration of
   enums, but GCC accepts it (and gives only pedantic warning), and
   it occurs in the wild.  */
എണ്ണൽ efoo;
ഘടന Sforward_use {
    പൂർണ്ണസംഖ്യ (*fmember) (എണ്ണൽ efoo x);
};

ബാഹ്യ എണ്ണൽ efoo it_real_fn(ശൂന്യം);
എണ്ണൽ efoo {
  ONE,
  TWO,
};
ഘടന S2 {
  എണ്ണൽ efoo (*f2) (ശൂന്യം);
};
ശൂന്യം should_compile(ഘടന S2 *s)
{
  s->f2 = it_real_fn;
}

എണ്ണൽ efoo it_real_fn(ശൂന്യം)
{
  തിരികെ TWO;
}

സ്ഥിതം unsigned പൂർണ്ണസംഖ്യ deref_uintptr(unsigned പൂർണ്ണസംഖ്യ *p)
{
  തിരികെ *p;
}

എണ്ണൽ Epositive {
    epos_one, epos_two
};

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   എണ്ണൽ fred frod;
   എണ്ണൽ Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
