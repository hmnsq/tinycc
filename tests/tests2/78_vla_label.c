#include <stdio.h>

/* This test segfaults as of April 27, 2015. */
void f1(จำนวนเต็ม argc)
{
  var_na test[argc];
  ถ้า(0)
  label:
    printf("boom!\n");
  ถ้า(argc-- == 0)
    คืน;
  goto label;
}

/* This segfaulted on 2015-11-19. */
void f2(void)
{
    goto start;
    {
        จำนวนเต็ม a[1 && 1]; /* not a variable-length array */
        จำนวนเต็ม b[1 || 1]; /* not a variable-length array */
        จำนวนเต็ม c[1 ? 1 : 1]; /* not a variable-length array */
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

จำนวนเต็ม หลัก()
{
  f1(2);
  f2();
  f3();

  คืน 0;
}
