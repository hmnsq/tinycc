#شامل <stdio.h>

/* This test segfaults as of April 27, 2015. */
خالی f1(صحیح argc)
{
  حرف test[argc];
  اگر(0)
  label:
    لکھو("boom!\n");
  اگر(argc-- == 0)
    واپس;
  جاؤ label;
}

/* This segfaulted on 2015-11-19. */
خالی f2(خالی)
{
    جاؤ آغاز;
    {
        صحیح a[1 && 1]; /* not a variable-length array */
        صحیح b[1 || 1]; /* not a variable-length array */
        صحیح c[1 ? 1 : 1]; /* not a variable-length array */
    آغاز:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

خالی f3(خالی)
{
    لکھو("%d\n", 0 ? لکھو("x1\n") : 11);
    لکھو("%d\n", 1 ? 12 : لکھو("x2\n"));
    لکھو("%d\n", 0 && لکھو("x3\n"));
    لکھو("%d\n", 1 || لکھو("x4\n"));
}

صحیح مین()
{
  f1(2);
  f2();
  f3();

  واپس 0;
}
