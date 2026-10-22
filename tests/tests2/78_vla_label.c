#ضمن <stdio.h>

/* This test segfaults as of April 27, 2015. */
فراغ f1(صحيح argc)
{
  حرف test[argc];
  إذا(0)
  label:
    printf("boom!\n");
  إذا(argc-- == 0)
    أرجع;
  اذهب label;
}

/* This segfaulted on 2015-11-19. */
فراغ f2(فراغ)
{
    اذهب start;
    {
        صحيح a[1 && 1]; /* not a variable-length array */
        صحيح b[1 || 1]; /* not a variable-length array */
        صحيح c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

فراغ f3(فراغ)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

صحيح main()
{
  f1(2);
  f2();
  f3();

  أرجع 0;
}
