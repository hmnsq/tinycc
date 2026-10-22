#ಅನ್ತರ್ಭಾವ <stdio.h>

/* This test segfaults as of April 27, 2015. */
ಶೂನ್ಯ f1(ಪೂರ್ಣಾಙ್ಕ argc)
{
  ವರ್ಣ test[argc];
  ಯದಿ(0)
  label:
    printf("boom!\n");
  ಯದಿ(argc-- == 0)
    ಪ್ರತ್ಯಾಗಮ;
  ಗಚ್ಛ label;
}

/* This segfaulted on 2015-11-19. */
ಶೂನ್ಯ f2(ಶೂನ್ಯ)
{
    ಗಚ್ಛ start;
    {
        ಪೂರ್ಣಾಙ್ಕ a[1 && 1]; /* not a variable-length array */
        ಪೂರ್ಣಾಙ್ಕ b[1 || 1]; /* not a variable-length array */
        ಪೂರ್ಣಾಙ್ಕ c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

ಶೂನ್ಯ f3(ಶೂನ್ಯ)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

ಪೂರ್ಣಾಙ್ಕ main()
{
  f1(2);
  f2();
  f3();

  ಪ್ರತ್ಯಾಗಮ 0;
}
