#include <stdio.h>

số_nguyên
main (void)
{
    số_nguyên n = 0;
    số_nguyên  first=1;
    số_nguyên *p[101];
    nếu (0) {
        lab:;
    }
    số_nguyên x[n % 100 + 1];
    nếu (first == 0) {
        nếu (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            trả_về(1);
        }
    }
    không_thì {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    nếu (n < 100000)
        goto lab;
    printf ("OK\n");
    trả_về 0;
}

