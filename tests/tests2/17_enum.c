#ಅನ್ತರ್ಭಾವ <stdio.h>

ಎಣಿಕೆ fred
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
ಎಣಿಕೆ efoo;
ರಚನೆ Sforward_use {
    ಪೂರ್ಣಾಂಕ (*fmember) (ಎಣಿಕೆ efoo x);
};

ಬಾಹ್ಯ ಎಣಿಕೆ efoo it_real_fn(ಶೂನ್ಯ);
ಎಣಿಕೆ efoo {
  ONE,
  TWO,
};
ರಚನೆ S2 {
  ಎಣಿಕೆ efoo (*f2) (ಶೂನ್ಯ);
};
ಶೂನ್ಯ should_compile(ರಚನೆ S2 *s)
{
  s->f2 = it_real_fn;
}

ಎಣಿಕೆ efoo it_real_fn(ಶೂನ್ಯ)
{
  ಹಿಂತಿರುಗಿ TWO;
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ deref_uintptr(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *p)
{
  ಹಿಂತಿರುಗಿ *p;
}

ಎಣಿಕೆ Epositive {
    epos_one, epos_two
};

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಎಣಿಕೆ fred frod;
   ಎಣಿಕೆ Epositive epos = epos_two;

   ಬರೆ("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
   /* printf("%d\n", frod); */
   frod = 12;
   ಬರೆ("%d\n", frod);
   frod = e;
   ಬರೆ("%d\n", frod);

   /* Following should compile without warning.  */
   ಬರೆ ("enum to int: %u\n", deref_uintptr(&epos));

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
