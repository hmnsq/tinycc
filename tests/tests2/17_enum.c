#ଅନ୍ତର୍ଭାଵ <stdio.h>

ଗଣନା fred
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
ଗଣନା efoo;
ସଂରଚନା Sforward_use {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*fmember) (ଗଣନା efoo x);
};

ବାହ୍ୟ ଗଣନା efoo it_real_fn(ଶୂନ୍ୟ);
ଗଣନା efoo {
  ONE,
  TWO,
};
ସଂରଚନା S2 {
  ଗଣନା efoo (*f2) (ଶୂନ୍ୟ);
};
ଶୂନ୍ୟ should_compile(ସଂରଚନା S2 *s)
{
  s->f2 = it_real_fn;
}

ଗଣନା efoo it_real_fn(ଶୂନ୍ୟ)
{
  ଫେରନ୍ତୁ TWO;
}

ସ୍ଥିର unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା deref_uintptr(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p)
{
  ଫେରନ୍ତୁ *p;
}

ଗଣନା Epositive {
    epos_one, epos_two
};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ଗଣନା fred frod;
   ଗଣନା Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
