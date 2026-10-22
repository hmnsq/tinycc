#include <stdio.h>

static void f(จำนวนเต็ม x)
{
     printf("f(%d)\n", x);
}

จำนวนเต็ม หลัก(void)
{
     จำนวนเต็ม count = 0, i = 0;
     สำหรับ (; i < 3; ++i) {
         printf("%d\n", i);
         (void)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     คืน count == 1 ? 0 : 1;
}
