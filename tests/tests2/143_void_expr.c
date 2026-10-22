#include <stdio.h>

static void f(ціле x)
{
     printf("f(%d)\n", x);
}

ціле main(void)
{
     ціле count = 0, i = 0;
     для (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     повернути count == 1 ? 0 : 1;
}
