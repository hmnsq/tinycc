#include <stdio.h>

整数
主要 (void)
{
    整数 n = 0;
    整数  first=1;
    整数 *p[101];
    如果 (0) {
        lab:;
    }
    整数 x[n % 100 + 1];
    如果 (first == 0) {
        如果 (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            返回(1);
        }
    }
    否则 {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    如果 (n < 100000)
        goto lab;
    printf ("OK\n");
    返回 0;
}

