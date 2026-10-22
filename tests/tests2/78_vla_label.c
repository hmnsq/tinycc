#অন্তর্ভাব <stdio.h>

/* This test segfaults as of April 27, 2015. */
শূন্য f1(পূর্ণাঙ্ক argc)
{
  বর্ণ test[argc];
  যদি(0)
  label:
    printf("boom!\n");
  যদি(argc-- == 0)
    প্রত্যাগম;
  গচ্ছ label;
}

/* This segfaulted on 2015-11-19. */
শূন্য f2(শূন্য)
{
    গচ্ছ start;
    {
        পূর্ণাঙ্ক a[1 && 1]; /* not a variable-length array */
        পূর্ণাঙ্ক b[1 || 1]; /* not a variable-length array */
        পূর্ণাঙ্ক c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

শূন্য f3(শূন্য)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

পূর্ণাঙ্ক main()
{
  f1(2);
  f2();
  f3();

  প্রত্যাগম 0;
}
