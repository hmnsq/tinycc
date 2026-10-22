#అన్తర్భావ <stdio.h>

గణన fred
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
గణన efoo;
నిర్మాణం Sforward_use {
    పూర్ణాంకం (*fmember) (గణన efoo x);
};

బాహ్య గణన efoo it_real_fn(శూన్య);
గణన efoo {
  ONE,
  TWO,
};
నిర్మాణం S2 {
  గణన efoo (*f2) (శూన్య);
};
శూన్య should_compile(నిర్మాణం S2 *s)
{
  s->f2 = it_real_fn;
}

గణన efoo it_real_fn(శూన్య)
{
  తిరిగి TWO;
}

స్థిర గుర్తులేని పూర్ణాంకం deref_uintptr(గుర్తులేని పూర్ణాంకం *p)
{
  తిరిగి *p;
}

గణన Epositive {
    epos_one, epos_two
};

పూర్ణాంకం ప్రధాన()
{
   గణన fred frod;
   గణన Epositive epos = epos_two;

   రాయి("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   రాయి("%d\n", frod);
   frod = e;
   రాయి("%d\n", frod);

   /* Following should compile without warning.  */
   రాయి ("enum to int: %u\n", deref_uintptr(&epos));

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
