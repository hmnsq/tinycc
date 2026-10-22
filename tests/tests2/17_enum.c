#شامل <stdio.h>

شمارش fred
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
شمارش efoo;
ساختار Sforward_use {
    صحیح (*fmember) (شمارش efoo x);
};

بیرونی شمارش efoo it_real_fn(تهی);
شمارش efoo {
  ONE,
  TWO,
};
ساختار S2 {
  شمارش efoo (*f2) (تهی);
};
تهی should_compile(ساختار S2 *s)
{
  s->f2 = it_real_fn;
}

شمارش efoo it_real_fn(تهی)
{
  بازگشت TWO;
}

ایستا unsigned صحیح deref_uintptr(unsigned صحیح *p)
{
  بازگشت *p;
}

شمارش Epositive {
    epos_one, epos_two
};

صحیح اصلی()
{
   شمارش fred frod;
   شمارش Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
