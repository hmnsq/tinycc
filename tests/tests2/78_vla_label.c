#ضمن <stdio.h>

/* This test segfaults as of April 27, 2015. */
فراغ f1(صحيح argc)
{
  حرف test[argc];
  إذا(0)
  label:
    لکو("boom!\n");
  إذا(argc-- == 0)
    أرجع;
  اذهب label;
}

/* This segfaulted on 2015-11-19. */
فراغ f2(فراغ)
{
    اذهب شروعات;
    {
        صحيح a[1 && 1]; /* not a variable-length array */
        صحيح b[1 || 1]; /* not a variable-length array */
        صحيح c[1 ? 1 : 1]; /* not a variable-length array */
    شروعات:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

فراغ f3(فراغ)
{
    لکو("%d\n", 0 ? لکو("x1\n") : 11);
    لکو("%d\n", 1 ? 12 : لکو("x2\n"));
    لکو("%d\n", 0 && لکو("x3\n"));
    لکو("%d\n", 1 || لکو("x4\n"));
}

صحيح مکيه()
{
  f1(2);
  f2();
  f3();

  أرجع 0;
}
