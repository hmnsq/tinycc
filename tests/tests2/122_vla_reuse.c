#include <stdio.h>

puur_naa_nka
main (void)
{
    puur_naa_nka n = 0;
    puur_naa_nka  first=1;
    puur_naa_nka *p[101];
    ᬬᬾᬦ᭄ (0) {
        lab:;
    }
    puur_naa_nka x[n % 100 + 1];
    ᬬᬾᬦ᭄ (first == 0) {
        ᬬᬾᬦ᭄ (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            ᬯᬮᬶ(1);
        }
    }
    ᬮᬶᬬ {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    ᬬᬾᬦ᭄ (n < 100000)
        goto lab;
    printf ("OK\n");
    ᬯᬮᬶ 0;
}

