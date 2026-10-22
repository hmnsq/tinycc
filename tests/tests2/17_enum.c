#ಅನ್ತರ್ಭಾವ <stdio.h>

ಗಣನಾ fred
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
ಗಣನಾ efoo;
ಸಂರಚನಾ Sforward_use {
    ಪೂರ್ಣಾಙ್ಕ (*fmember) (ಗಣನಾ efoo x);
};

ಬಾಹ್ಯ ಗಣನಾ efoo it_real_fn(ಶೂನ್ಯ);
ಗಣನಾ efoo {
  ONE,
  TWO,
};
ಸಂರಚನಾ S2 {
  ಗಣನಾ efoo (*f2) (ಶೂನ್ಯ);
};
ಶೂನ್ಯ should_compile(ಸಂರಚನಾ S2 *s)
{
  s->f2 = it_real_fn;
}

ಗಣನಾ efoo it_real_fn(ಶೂನ್ಯ)
{
  ಪ್ರತ್ಯಾಗಮ TWO;
}

ಸ್ಥಿರ unsigned ಪೂರ್ಣಾಙ್ಕ deref_uintptr(unsigned ಪೂರ್ಣಾಙ್ಕ *p)
{
  ಪ್ರತ್ಯಾಗಮ *p;
}

ಗಣನಾ Epositive {
    epos_one, epos_two
};

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಗಣನಾ fred frod;
   ಗಣನಾ Epositive epos = epos_two;

   printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   printf("%d\n", frod);
   frod = e;
   printf("%d\n", frod);

   /* Following should compile without warning.  */
   printf ("enum to int: %u\n", deref_uintptr(&epos));

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
