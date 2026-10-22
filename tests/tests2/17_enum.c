#અન્તર્ભાવ <stdio.h>

ગણના fred
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
ગણના efoo;
સંરચના Sforward_use {
    પૂર્ણાંક (*fmember) (ગણના efoo x);
};

બાહ્ય ગણના efoo it_real_fn(શૂન્ય);
ગણના efoo {
  ONE,
  TWO,
};
સંરચના S2 {
  ગણના efoo (*f2) (શૂન્ય);
};
શૂન્ય should_compile(સંરચના S2 *s)
{
  s->f2 = it_real_fn;
}

ગણના efoo it_real_fn(શૂન્ય)
{
  પાછા TWO;
}

સ્થિર unsigned પૂર્ણાંક deref_uintptr(unsigned પૂર્ણાંક *p)
{
  પાછા *p;
}

ગણના Epositive {
    epos_one, epos_two
};

પૂર્ણાંક મુખ્ય()
{
   ગણના fred frod;
   ગણના Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
