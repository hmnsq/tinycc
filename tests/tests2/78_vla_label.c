#include <stdio.h>

/* This test segfaults as of April 27, 2015. */
void f1(ကိန်းပြည့် argc)
{
  var_na test[argc];
  အကယ်၍(0)
  label:
    printf("boom!\n");
  အကယ်၍(argc-- == 0)
    ပြန်ပေး;
  goto label;
}

/* This segfaulted on 2015-11-19. */
void f2(void)
{
    goto start;
    {
        ကိန်းပြည့် a[1 && 1]; /* not a variable-length array */
        ကိန်းပြည့် b[1 || 1]; /* not a variable-length array */
        ကိန်းပြည့် c[1 ? 1 : 1]; /* not a variable-length array */
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

ကိန်းပြည့် main()
{
  f1(2);
  f2();
  f3();

  ပြန်ပေး 0;
}
