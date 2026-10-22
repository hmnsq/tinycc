#شامل <stdio.h>

/* This test segfaults as of April 27, 2015. */
تهی f1(صحیح argc)
{
  نویسه test[argc];
  اگر(0)
  label:
    printf("boom!\n");
  اگر(argc-- == 0)
    بازگشت;
  برو label;
}

/* This segfaulted on 2015-11-19. */
تهی f2(تهی)
{
    برو start;
    {
        صحیح a[1 && 1]; /* not a variable-length array */
        صحیح b[1 || 1]; /* not a variable-length array */
        صحیح c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

تهی f3(تهی)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

صحیح اصلی()
{
  f1(2);
  f2();
  f3();

  بازگشت 0;
}
