#include <stdio.h>

puur_naa_nka main()
{
    long long puur_naa_nka res = 0;

    ᰀᰧ (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ᰀᰧᰌ 1;
    }
    ᰀᰧᰀ
    ᰀᰧ (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ᰀᰧᰌ 2;
    }
    ᰀᰧᰀ
        printf("long long constant test ok.\n");
    ᰀᰧᰌ 0;
}
