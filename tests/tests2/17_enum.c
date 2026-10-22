#شامل <stdio.h>

شمار fred
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
شمار efoo;
ساخت Sforward_use {
    صحیح (*fmember) (شمار efoo x);
};

خارجی شمار efoo it_real_fn(خالی);
شمار efoo {
  ONE,
  TWO,
};
ساخت S2 {
  شمار efoo (*f2) (خالی);
};
خالی should_compile(ساخت S2 *s)
{
  s->f2 = it_real_fn;
}

شمار efoo it_real_fn(خالی)
{
  واپس TWO;
}

ساکن غیرعلامتی صحیح deref_uintptr(غیرعلامتی صحیح *p)
{
  واپس *p;
}

شمار Epositive {
    epos_one, epos_two
};

صحیح مین()
{
   شمار fred frod;
   شمار Epositive epos = epos_two;

   لکھو("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   لکھو("%d\n", frod);
   frod = e;
   لکھو("%d\n", frod);

   /* Following should compile without warning.  */
   لکھو ("enum to int: %u\n", deref_uintptr(&epos));

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
