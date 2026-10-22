#include <stdio.h>

/* This test segfaults as of April 27, 2015. */
void f1(පූර්ණ_සංඛ්‍යා argc)
{
  var_na test[argc];
  නම්(0)
  label:
    printf("boom!\n");
  නම්(argc-- == 0)
    ආපසු;
  goto label;
}

/* This segfaulted on 2015-11-19. */
void f2(void)
{
    goto start;
    {
        පූර්ණ_සංඛ්‍යා a[1 && 1]; /* not a variable-length array */
        පූර්ණ_සංඛ්‍යා b[1 || 1]; /* not a variable-length array */
        පූර්ණ_සංඛ්‍යා c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

void f3(void)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

පූර්ණ_සංඛ්‍යා main()
{
  f1(2);
  f2();
  f3();

  ආපසු 0;
}
