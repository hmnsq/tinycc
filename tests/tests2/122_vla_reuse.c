#include <stdio.h>

정수
main (void)
{
    정수 n = 0;
    정수  first=1;
    정수 *p[101];
    만약 (0) {
        lab:;
    }
    정수 x[n % 100 + 1];
    만약 (first == 0) {
        만약 (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            반환(1);
        }
    }
    아니면 {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    만약 (n < 100000)
        goto lab;
    printf ("OK\n");
    반환 0;
}

