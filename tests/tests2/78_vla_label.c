#include <stdio.h>

/* This test segfaults as of April 27, 2015. */
void f1(целое argc)
{
  char test[argc];
  если(0)
  label:
    printf("boom!\n");
  если(argc-- == 0)
    вернуть;
  goto label;
}

/* This segfaulted on 2015-11-19. */
void f2(void)
{
    goto start;
    {
        целое a[1 && 1]; /* not a variable-length array */
        целое b[1 || 1]; /* not a variable-length array */
        целое c[1 ? 1 : 1]; /* not a variable-length array */
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

целое основной()
{
  f1(2);
  f2();
  f3();

  вернуть 0;
}
