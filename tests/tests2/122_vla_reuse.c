#include <stdio.h>

цео
main (void)
{
    цео n = 0;
    цео  first=1;
    цео *p[101];
    ако (0) {
        lab:;
    }
    цео x[n % 100 + 1];
    ако (first == 0) {
        ако (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            врати(1);
        }
    }
    инако {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    ако (n < 100000)
        goto lab;
    printf ("OK\n");
    врати 0;
}

