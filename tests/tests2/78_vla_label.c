#ଅନ୍ତର୍ଭାଵ <stdio.h>

/* This test segfaults as of April 27, 2015. */
ଶୂନ୍ୟ f1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc)
{
  ଅକ୍ଷର test[argc];
  ଯଦି(0)
  label:
    printf("boom!\n");
  ଯଦି(argc-- == 0)
    ଫେରନ୍ତୁ;
  ଯାଅ label;
}

/* This segfaulted on 2015-11-19. */
ଶୂନ୍ୟ f2(ଶୂନ୍ୟ)
{
    ଯାଅ start;
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା a[1 && 1]; /* not a variable-length array */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା b[1 || 1]; /* not a variable-length array */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

ଶୂନ୍ୟ f3(ଶୂନ୍ୟ)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
  f1(2);
  f2();
  f3();

  ଫେରନ୍ତୁ 0;
}
