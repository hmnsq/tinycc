#include <stdio.h>

static void f(цяло x)
{
     printf("f(%d)\n", x);
}

цяло main(void)
{
     цяло count = 0, i = 0;
     за (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     върни count == 1 ? 0 : 1;
}
