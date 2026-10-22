#ضمن <stdio.h>

/* This test segfaults as of April 27, 2015. */
فراغ f1(صحيح argc)
{
  حرف test[argc];
  إذا(0)
  label:
    چاپ_کړه("boom!\n");
  إذا(argc-- == 0)
    أرجع;
  اذهب label;
}

/* This segfaulted on 2015-11-19. */
فراغ f2(فراغ)
{
    اذهب پیل;
    {
        صحيح a[1 && 1]; /* not a variable-length array */
        صحيح b[1 || 1]; /* not a variable-length array */
        صحيح c[1 ? 1 : 1]; /* not a variable-length array */
    پیل:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

فراغ f3(فراغ)
{
    چاپ_کړه("%d\n", 0 ? چاپ_کړه("x1\n") : 11);
    چاپ_کړه("%d\n", 1 ? 12 : چاپ_کړه("x2\n"));
    چاپ_کړه("%d\n", 0 && چاپ_کړه("x3\n"));
    چاپ_کړه("%d\n", 1 || چاپ_کړه("x4\n"));
}

صحيح اصلي()
{
  f1(2);
  f2();
  f3();

  أرجع 0;
}
