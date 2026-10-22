#include <stdio.h>

puur_naa_nka
main (void)
{
    puur_naa_nka n = 0;
    puur_naa_nka  first=1;
    puur_naa_nka *p[101];
    ᰀᰧ (0) {
        lab:;
    }
    puur_naa_nka x[n % 100 + 1];
    ᰀᰧ (first == 0) {
        ᰀᰧ (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            ᰀᰧᰌ(1);
        }
    }
    ᰀᰧᰀ {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    ᰀᰧ (n < 100000)
        goto lab;
    printf ("OK\n");
    ᰀᰧᰌ 0;
}

