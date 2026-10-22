#ضمن <stdio.h>

تعداد fred
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
تعداد efoo;
بنية Sforward_use {
    صحيح (*fmember) (تعداد efoo x);
};

خارجي تعداد efoo it_real_fn(فراغ);
تعداد efoo {
  ONE,
  TWO,
};
بنية S2 {
  تعداد efoo (*f2) (فراغ);
};
فراغ should_compile(بنية S2 *s)
{
  s->f2 = it_real_fn;
}

تعداد efoo it_real_fn(فراغ)
{
  החזר TWO;
}

ساكن unsigned صحيح deref_uintptr(unsigned صحيح *p)
{
  החזר *p;
}

تعداد Epositive {
    epos_one, epos_two
};

صحيح main()
{
   تعداد fred frod;
   تعداد Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   החזר 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
