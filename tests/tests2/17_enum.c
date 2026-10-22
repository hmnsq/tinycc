#अन्तर्भाव <stdio.h>

गणना fred
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
गणना efoo;
संरचना Sforward_use {
    पूर्णांक (*fmember) (गणना efoo x);
};

बाह्य गणना efoo it_real_fn(शून्य);
गणना efoo {
  ONE,
  TWO,
};
संरचना S2 {
  गणना efoo (*f2) (शून्य);
};
शून्य should_compile(संरचना S2 *s)
{
  s->f2 = it_real_fn;
}

गणना efoo it_real_fn(शून्य)
{
  परत TWO;
}

स्थिर अचिन्हित पूर्णांक deref_uintptr(अचिन्हित पूर्णांक *p)
{
  परत *p;
}

गणना Epositive {
    epos_one, epos_two
};

पूर्णांक main()
{
   गणना fred frod;
   गणना Epositive epos = epos_two;

   म_लिखो("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   म_लिखो("%d\n", frod);
   frod = e;
   म_लिखो("%d\n", frod);

   /* Following should compile without warning.  */
   म_लिखो ("enum to int: %u\n", deref_uintptr(&epos));

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
