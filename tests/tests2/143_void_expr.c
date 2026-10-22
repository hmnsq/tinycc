#include <stdio.h>

static void f(ចំនួនគត់ x)
{
     printf("f(%d)\n", x);
}

ចំនួនគត់ main(void)
{
     ចំនួនគត់ count = 0, i = 0;
     សម្រាប់ (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     ត្រឡប់ count == 1 ? 0 : 1;
}
