#include <stdio.h>

puur_naa_nka
main (void)
{
    puur_naa_nka n = 0;
    puur_naa_nka  first=1;
    puur_naa_nka *p[101];
    ꦪꦼꦤ꧀ (0) {
        lab:;
    }
    puur_naa_nka x[n % 100 + 1];
    ꦪꦼꦤ꧀ (first == 0) {
        ꦪꦼꦤ꧀ (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            ꦮꦭꦶ(1);
        }
    }
    ꦭꦶꦪ {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    ꦪꦼꦤ꧀ (n < 100000)
        goto lab;
    printf ("OK\n");
    ꦮꦭꦶ 0;
}

