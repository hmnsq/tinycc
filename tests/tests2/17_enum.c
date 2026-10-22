#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਗਿਣਤੀ fred
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
ਗਿਣਤੀ efoo;
ਬਣਤਰ Sforward_use {
    ਪੂਰਨ (*fmember) (ਗਿਣਤੀ efoo x);
};

ਬਾਹਰੀ ਗਿਣਤੀ efoo it_real_fn(ਖਾਲੀ);
ਗਿਣਤੀ efoo {
  ONE,
  TWO,
};
ਬਣਤਰ S2 {
  ਗਿਣਤੀ efoo (*f2) (ਖਾਲੀ);
};
ਖਾਲੀ should_compile(ਬਣਤਰ S2 *s)
{
  s->f2 = it_real_fn;
}

ਗਿਣਤੀ efoo it_real_fn(ਖਾਲੀ)
{
  ਵਾਪਸ TWO;
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ deref_uintptr(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *p)
{
  ਵਾਪਸ *p;
}

ਗਿਣਤੀ Epositive {
    epos_one, epos_two
};

ਪੂਰਨ ਮੁੱਖ()
{
   ਗਿਣਤੀ fred frod;
   ਗਿਣਤੀ Epositive epos = epos_two;

   ਲਿਖੋ("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   ਲਿਖੋ("%d\n", frod);
   frod = e;
   ਲਿਖੋ("%d\n", frod);

   /* Following should compile without warning.  */
   ਲਿਖੋ ("enum to int: %u\n", deref_uintptr(&epos));

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
