#include <stdio.h>

static void f(số_nguyên x)
{
     printf("f(%d)\n", x);
}

số_nguyên main(void)
{
     số_nguyên count = 0, i = 0;
     cho (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     trả_về count == 1 ? 0 : 1;
}
