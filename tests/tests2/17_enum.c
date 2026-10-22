#समावेश <stdio.h>

क्रमागत fred
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
क्रमागत efoo;
काष्ठा Sforward_use {
    पूर्णांक (*fmember) (क्रमागत efoo x);
};

बाह्य क्रमागत efoo it_real_fn(व्योम);
क्रमागत efoo {
  ONE,
  TWO,
};
काष्ठा S2 {
  क्रमागत efoo (*f2) (व्योम);
};
व्योम should_compile(काष्ठा S2 *s)
{
  s->f2 = it_real_fn;
}

क्रमागत efoo it_real_fn(व्योम)
{
  वापस TWO;
}

अटल अचिन्हित पूर्णांक deref_uintptr(अचिन्हित पूर्णांक *p)
{
  वापस *p;
}

क्रमागत Epositive {
    epos_one, epos_two
};

पूर्णांक मुख्य()
{
   क्रमागत fred frod;
   क्रमागत Epositive epos = epos_two;

   म_लिखो("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   म_लिखो("%d\n", frod);
   frod = e;
   म_लिखो("%d\n", frod);

   /* Following should compile without warning.  */
   म_लिखो ("enum to int: %u\n", deref_uintptr(&epos));

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
