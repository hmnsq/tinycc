#ضمن <stdio.h>

/* This test segfaults as of April 27, 2015. */
فراغ f1(صحيح argc)
{
  حرف test[argc];
  إذا(0)
  label:
    لکھو("boom!\n");
  إذا(argc-- == 0)
    أرجع;
  اذهب label;
}

/* This segfaulted on 2015-11-19. */
فراغ f2(فراغ)
{
    اذهب شروع;
    {
        صحيح a[1 && 1]; /* not a variable-length array */
        صحيح b[1 || 1]; /* not a variable-length array */
        صحيح c[1 ? 1 : 1]; /* not a variable-length array */
    شروع:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

فراغ f3(فراغ)
{
    لکھو("%d\n", 0 ? لکھو("x1\n") : 11);
    لکھو("%d\n", 1 ? 12 : لکھو("x2\n"));
    لکھو("%d\n", 0 && لکھو("x3\n"));
    لکھو("%d\n", 1 || لکھو("x4\n"));
}

صحيح مکھ()
{
  f1(2);
  f2();
  f3();

  أرجع 0;
}
