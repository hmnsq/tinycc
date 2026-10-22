#include <stdio.h>

puur_naa_nka main()
{
    long long puur_naa_nka res = 0;

    ᮚᮦᮔ᮪ (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ᮝᮜᮤ 1;
    }
    ᮜᮤᮚ
    ᮚᮦᮔ᮪ (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ᮝᮜᮤ 2;
    }
    ᮜᮤᮚ
        printf("long long constant test ok.\n");
    ᮝᮜᮤ 0;
}
