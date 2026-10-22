#ಅನ್ತರ್ಭಾವ <stdio.h>

/* This test segfaults as of April 27, 2015. */
ಶೂನ್ಯ f1(ಪೂರ್ಣಾಂಕ argc)
{
  ಅಕ್ಷರ test[argc];
  ಆದರೆ(0)
  label:
    ಬರೆ("boom!\n");
  ಆದರೆ(argc-- == 0)
    ಹಿಂತಿರುಗಿ;
  ಹೋಗು label;
}

/* This segfaulted on 2015-11-19. */
ಶೂನ್ಯ f2(ಶೂನ್ಯ)
{
    ಹೋಗು ಆರಂಭ;
    {
        ಪೂರ್ಣಾಂಕ a[1 && 1]; /* not a variable-length array */
        ಪೂರ್ಣಾಂಕ b[1 || 1]; /* not a variable-length array */
        ಪೂರ್ಣಾಂಕ c[1 ? 1 : 1]; /* not a variable-length array */
    ಆರಂಭ:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

ಶೂನ್ಯ f3(ಶೂನ್ಯ)
{
    ಬರೆ("%d\n", 0 ? ಬರೆ("x1\n") : 11);
    ಬರೆ("%d\n", 1 ? 12 : ಬರೆ("x2\n"));
    ಬರೆ("%d\n", 0 && ಬರೆ("x3\n"));
    ಬರೆ("%d\n", 1 || ಬರೆ("x4\n"));
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
  f1(2);
  f2();
  f3();

  ಹಿಂತಿರುಗಿ 0;
}
