#అన్తర్భావ <stdio.h>

/* This test segfaults as of April 27, 2015. */
శూన్య f1(పూర్ణాంకం argc)
{
  అక్షరం test[argc];
  ఒకవేళ(0)
  label:
    రాయి("boom!\n");
  ఒకవేళ(argc-- == 0)
    తిరిగి;
  వెళ్ళు label;
}

/* This segfaulted on 2015-11-19. */
శూన్య f2(శూన్య)
{
    వెళ్ళు ప్రారంభం;
    {
        పూర్ణాంకం a[1 && 1]; /* not a variable-length array */
        పూర్ణాంకం b[1 || 1]; /* not a variable-length array */
        పూర్ణాంకం c[1 ? 1 : 1]; /* not a variable-length array */
    ప్రారంభం:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

శూన్య f3(శూన్య)
{
    రాయి("%d\n", 0 ? రాయి("x1\n") : 11);
    రాయి("%d\n", 1 ? 12 : రాయి("x2\n"));
    రాయి("%d\n", 0 && రాయి("x3\n"));
    రాయి("%d\n", 1 || రాయి("x4\n"));
}

పూర్ణాంకం ప్రధాన()
{
  f1(2);
  f2();
  f3();

  తిరిగి 0;
}
