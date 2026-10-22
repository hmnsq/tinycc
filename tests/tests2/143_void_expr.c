#include <stdio.h>

static void f(целое x)
{
     printf("f(%d)\n", x);
}

целое основной(void)
{
     целое count = 0, i = 0;
     для (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     вернуть count == 1 ? 0 : 1;
}
