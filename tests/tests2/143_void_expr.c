#include <stdio.h>

static void f(정수 x)
{
     printf("f(%d)\n", x);
}

정수 main(void)
{
     정수 count = 0, i = 0;
     위해 (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     반환 count == 1 ? 0 : 1;
}
