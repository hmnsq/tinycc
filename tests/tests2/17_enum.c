#அந்தர்பாவ <stdio.h>

எண்ணிக்கை fred
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
எண்ணிக்கை efoo;
கட்டமைப்பு Sforward_use {
    முழு (*fmember) (எண்ணிக்கை efoo x);
};

வெளி எண்ணிக்கை efoo it_real_fn(வெறுமை);
எண்ணிக்கை efoo {
  ONE,
  TWO,
};
கட்டமைப்பு S2 {
  எண்ணிக்கை efoo (*f2) (வெறுமை);
};
வெறுமை should_compile(கட்டமைப்பு S2 *s)
{
  s->f2 = it_real_fn;
}

எண்ணிக்கை efoo it_real_fn(வெறுமை)
{
  திரும்பு TWO;
}

நிலையான unsigned முழு deref_uintptr(unsigned முழு *p)
{
  திரும்பு *p;
}

எண்ணிக்கை Epositive {
    epos_one, epos_two
};

முழு முதன்மை()
{
   எண்ணிக்கை fred frod;
   எண்ணிக்கை Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
