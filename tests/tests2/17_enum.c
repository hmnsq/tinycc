#include <stdio.h>

ga_nanaa fred
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
ga_nanaa efoo;
sa_nracanaa Sforward_use {
    පූර්ණ_සංඛ්‍යා (*fmember) (ga_nanaa efoo x);
};

extern ga_nanaa efoo it_real_fn(void);
ga_nanaa efoo {
  ONE,
  TWO,
};
sa_nracanaa S2 {
  ga_nanaa efoo (*f2) (void);
};
void should_compile(sa_nracanaa S2 *s)
{
  s->f2 = it_real_fn;
}

ga_nanaa efoo it_real_fn(void)
{
  ආපසු TWO;
}

static unsigned පූර්ණ_සංඛ්‍යා deref_uintptr(unsigned පූර්ණ_සංඛ්‍යා *p)
{
  ආපසු *p;
}

ga_nanaa Epositive {
    epos_one, epos_two
};

පූර්ණ_සංඛ්‍යා main()
{
   ga_nanaa fred frod;
   ga_nanaa Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
