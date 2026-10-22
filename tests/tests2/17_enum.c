#অন্তর্ভাব <stdio.h>

গণনা fred
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
গণনা efoo;
কাঠামো Sforward_use {
    পূর্ণসংখ্যা (*fmember) (গণনা efoo x);
};

বাহ্যিক গণনা efoo it_real_fn(শূন্য);
গণনা efoo {
  ONE,
  TWO,
};
কাঠামো S2 {
  গণনা efoo (*f2) (শূন্য);
};
শূন্য should_compile(কাঠামো S2 *s)
{
  s->f2 = it_real_fn;
}

গণনা efoo it_real_fn(শূন্য)
{
  ফেরত TWO;
}

স্থির unsigned পূর্ণসংখ্যা deref_uintptr(unsigned পূর্ণসংখ্যা *p)
{
  ফেরত *p;
}

গণনা Epositive {
    epos_one, epos_two
};

পূর্ণসংখ্যা প্রধান()
{
   গণনা fred frod;
   গণনা Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
