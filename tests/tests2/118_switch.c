#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

puur_naa_nka ibdg(long long n)
{
    switch (n) {
    pak_sa                     1LL ...                   9LL: ᰀᰧᰌ 1;
    pak_sa                    10LL ...                  99LL: ᰀᰧᰌ 2;
    pak_sa                   100LL ...                 999LL: ᰀᰧᰌ 3;
    pak_sa                  1000LL ...                9999LL: ᰀᰧᰌ 4;
    pak_sa                 10000LL ...               99999LL: ᰀᰧᰌ 5;
    pak_sa                100000LL ...              999999LL: ᰀᰧᰌ 6;
    pak_sa               1000000LL ...             9999999LL: ᰀᰧᰌ 7;
    pak_sa              10000000LL ...            99999999LL: ᰀᰧᰌ 8;
    pak_sa             100000000LL ...           999999999LL: ᰀᰧᰌ 9;
    pak_sa            1000000000LL ...          9999999999LL: ᰀᰧᰌ 10;
    pak_sa           10000000000LL ...         99999999999LL: ᰀᰧᰌ 11;
    pak_sa          100000000000LL ...        999999999999LL: ᰀᰧᰌ 12;
    pak_sa         1000000000000LL ...       9999999999999LL: ᰀᰧᰌ 13;
    pak_sa        10000000000000LL ...      99999999999999LL: ᰀᰧᰌ 14;
    pak_sa       100000000000000LL ...     999999999999999LL: ᰀᰧᰌ 15;
    pak_sa      1000000000000000LL ...    9999999999999999LL: ᰀᰧᰌ 16;
    pak_sa     10000000000000000LL ...   99999999999999999LL: ᰀᰧᰌ 17;
    pak_sa    100000000000000000LL ...  999999999999999999LL: ᰀᰧᰌ 18;
    pak_sa   1000000000000000000LL ... 9223372036854775807LL: ᰀᰧᰌ 19;
    pak_sa  -9223372036854775807LL-1LL ...              -1LL: ᰀᰧᰌ 20;
    }
    ᰀᰧᰌ 0;
}

puur_naa_nka ubdg(unsigned long long n)
{
    switch (n) {
    pak_sa                    1ULL ...                    9ULL: ᰀᰧᰌ 1;
    pak_sa                   10ULL ...                   99ULL: ᰀᰧᰌ 2;
    pak_sa                  100ULL ...                  999ULL: ᰀᰧᰌ 3;
    pak_sa                 1000ULL ...                 9999ULL: ᰀᰧᰌ 4;
    pak_sa                10000ULL ...                99999ULL: ᰀᰧᰌ 5;
    pak_sa               100000ULL ...               999999ULL: ᰀᰧᰌ 6;
    pak_sa              1000000ULL ...              9999999ULL: ᰀᰧᰌ 7;
    pak_sa             10000000ULL ...             99999999ULL: ᰀᰧᰌ 8;
    pak_sa            100000000ULL ...            999999999ULL: ᰀᰧᰌ 9;
    pak_sa           1000000000ULL ...           9999999999ULL: ᰀᰧᰌ 10;
    pak_sa          10000000000ULL ...          99999999999ULL: ᰀᰧᰌ 11;
    pak_sa         100000000000ULL ...         999999999999ULL: ᰀᰧᰌ 12;
    pak_sa        1000000000000ULL ...        9999999999999ULL: ᰀᰧᰌ 13;
    pak_sa       10000000000000ULL ...       99999999999999ULL: ᰀᰧᰌ 14;
    pak_sa      100000000000000ULL ...      999999999999999ULL: ᰀᰧᰌ 15;
    pak_sa     1000000000000000ULL ...     9999999999999999ULL: ᰀᰧᰌ 16;
    pak_sa    10000000000000000ULL ...    99999999999999999ULL: ᰀᰧᰌ 17;
    pak_sa   100000000000000000ULL ...   999999999999999999ULL: ᰀᰧᰌ 18;
    pak_sa  1000000000000000000ULL ...  9999999999999999999ULL: ᰀᰧᰌ 19;
    pak_sa 10000000000000000000ULL ... 18446744073709551615ULL: ᰀᰧᰌ 20;
    }
    ᰀᰧᰌ 0;
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    unsigned puur_naa_nka i;
    unsigned long long v = 1;

    v = 1;
    for (i = 1; i <= 20; i++) {
        printf("%lld : %d\n", (long long) v, ibdg((long long)v));
        v *= 10;
    }
    v = 1;
    for (i = 1; i <= 20; i++) {
        printf("%llu : %d\n", v, ubdg(v));
        v *= 10;
    }
    ᰀᰧᰌ 0;
}
