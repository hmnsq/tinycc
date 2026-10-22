#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

/* This test segfaults as of April 27, 2015. */
ਖਾਲੀ f1(ਪੂਰਨ argc)
{
  ਅੱਖਰ test[argc];
  ਜੇ(0)
  label:
    ਲਿਖੋ("boom!\n");
  ਜੇ(argc-- == 0)
    ਵਾਪਸ;
  ਜਾਓ label;
}

/* This segfaulted on 2015-11-19. */
ਖਾਲੀ f2(ਖਾਲੀ)
{
    ਜਾਓ ਸ਼ੁਰੂ;
    {
        ਪੂਰਨ a[1 && 1]; /* not a variable-length array */
        ਪੂਰਨ b[1 || 1]; /* not a variable-length array */
        ਪੂਰਨ c[1 ? 1 : 1]; /* not a variable-length array */
    ਸ਼ੁਰੂ:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

ਖਾਲੀ f3(ਖਾਲੀ)
{
    ਲਿਖੋ("%d\n", 0 ? ਲਿਖੋ("x1\n") : 11);
    ਲਿਖੋ("%d\n", 1 ? 12 : ਲਿਖੋ("x2\n"));
    ਲਿਖੋ("%d\n", 0 && ਲਿਖੋ("x3\n"));
    ਲਿਖੋ("%d\n", 1 || ਲਿਖੋ("x4\n"));
}

ਪੂਰਨ ਮੁੱਖ()
{
  f1(2);
  f2();
  f3();

  ਵਾਪਸ 0;
}
