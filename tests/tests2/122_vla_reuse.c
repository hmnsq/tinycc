#include <stdio.h>

цяло
main (void)
{
    цяло n = 0;
    цяло  first=1;
    цяло *p[101];
    ако (0) {
        lab:;
    }
    цяло x[n % 100 + 1];
    ако (first == 0) {
        ако (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            върни(1);
        }
    }
    иначе {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    ако (n < 100000)
        goto lab;
    printf ("OK\n");
    върни 0;
}

