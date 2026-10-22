#include <stdio.h>

puur_naa_nka
main (void)
{
    puur_naa_nka n = 0;
    puur_naa_nka  first=1;
    puur_naa_nka *p[101];
    ᱡᱩᱫᱤ (0) {
        lab:;
    }
    puur_naa_nka x[n % 100 + 1];
    ᱡᱩᱫᱤ (first == 0) {
        ᱡᱩᱫᱤ (&x[0] != p[n % 100 + 1]) {
            printf ("ERROR: %p %p\n", &x[0], p[n % 100 + 1]);
            ᱨᱩᱣᱟᱹᱲ(1);
        }
    }
    ᱵᱟᱝ {
        p[n % 100 + 1] = &x[0];
        first = n < 100;
    }
    x[0] = 1;
    x[n % 100] = 2;
    n++;
    ᱡᱩᱫᱤ (n < 100000)
        goto lab;
    printf ("OK\n");
    ᱨᱩᱣᱟᱹᱲ 0;
}

