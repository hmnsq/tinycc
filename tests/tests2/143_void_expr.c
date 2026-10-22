#include <stdio.h>

static void f(цео x)
{
     printf("f(%d)\n", x);
}

цео main(void)
{
     цео count = 0, i = 0;
     за (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     врати count == 1 ? 0 : 1;
}
