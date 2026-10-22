#include <stdio.h>

static void f(整数 x)
{
     printf("f(%d)\n", x);
}

整数 主要(void)
{
     整数 count = 0, i = 0;
     为 (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     返回 count == 1 ? 0 : 1;
}
