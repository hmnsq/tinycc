#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

puur_naa_nka ibdg(long long n)
{
    switch (n) {
    pak_sa                     1LL ...                   9LL: ᮝᮜᮤ 1;
    pak_sa                    10LL ...                  99LL: ᮝᮜᮤ 2;
    pak_sa                   100LL ...                 999LL: ᮝᮜᮤ 3;
    pak_sa                  1000LL ...                9999LL: ᮝᮜᮤ 4;
    pak_sa                 10000LL ...               99999LL: ᮝᮜᮤ 5;
    pak_sa                100000LL ...              999999LL: ᮝᮜᮤ 6;
    pak_sa               1000000LL ...             9999999LL: ᮝᮜᮤ 7;
    pak_sa              10000000LL ...            99999999LL: ᮝᮜᮤ 8;
    pak_sa             100000000LL ...           999999999LL: ᮝᮜᮤ 9;
    pak_sa            1000000000LL ...          9999999999LL: ᮝᮜᮤ 10;
    pak_sa           10000000000LL ...         99999999999LL: ᮝᮜᮤ 11;
    pak_sa          100000000000LL ...        999999999999LL: ᮝᮜᮤ 12;
    pak_sa         1000000000000LL ...       9999999999999LL: ᮝᮜᮤ 13;
    pak_sa        10000000000000LL ...      99999999999999LL: ᮝᮜᮤ 14;
    pak_sa       100000000000000LL ...     999999999999999LL: ᮝᮜᮤ 15;
    pak_sa      1000000000000000LL ...    9999999999999999LL: ᮝᮜᮤ 16;
    pak_sa     10000000000000000LL ...   99999999999999999LL: ᮝᮜᮤ 17;
    pak_sa    100000000000000000LL ...  999999999999999999LL: ᮝᮜᮤ 18;
    pak_sa   1000000000000000000LL ... 9223372036854775807LL: ᮝᮜᮤ 19;
    pak_sa  -9223372036854775807LL-1LL ...              -1LL: ᮝᮜᮤ 20;
    }
    ᮝᮜᮤ 0;
}

puur_naa_nka ubdg(unsigned long long n)
{
    switch (n) {
    pak_sa                    1ULL ...                    9ULL: ᮝᮜᮤ 1;
    pak_sa                   10ULL ...                   99ULL: ᮝᮜᮤ 2;
    pak_sa                  100ULL ...                  999ULL: ᮝᮜᮤ 3;
    pak_sa                 1000ULL ...                 9999ULL: ᮝᮜᮤ 4;
    pak_sa                10000ULL ...                99999ULL: ᮝᮜᮤ 5;
    pak_sa               100000ULL ...               999999ULL: ᮝᮜᮤ 6;
    pak_sa              1000000ULL ...              9999999ULL: ᮝᮜᮤ 7;
    pak_sa             10000000ULL ...             99999999ULL: ᮝᮜᮤ 8;
    pak_sa            100000000ULL ...            999999999ULL: ᮝᮜᮤ 9;
    pak_sa           1000000000ULL ...           9999999999ULL: ᮝᮜᮤ 10;
    pak_sa          10000000000ULL ...          99999999999ULL: ᮝᮜᮤ 11;
    pak_sa         100000000000ULL ...         999999999999ULL: ᮝᮜᮤ 12;
    pak_sa        1000000000000ULL ...        9999999999999ULL: ᮝᮜᮤ 13;
    pak_sa       10000000000000ULL ...       99999999999999ULL: ᮝᮜᮤ 14;
    pak_sa      100000000000000ULL ...      999999999999999ULL: ᮝᮜᮤ 15;
    pak_sa     1000000000000000ULL ...     9999999999999999ULL: ᮝᮜᮤ 16;
    pak_sa    10000000000000000ULL ...    99999999999999999ULL: ᮝᮜᮤ 17;
    pak_sa   100000000000000000ULL ...   999999999999999999ULL: ᮝᮜᮤ 18;
    pak_sa  1000000000000000000ULL ...  9999999999999999999ULL: ᮝᮜᮤ 19;
    pak_sa 10000000000000000000ULL ... 18446744073709551615ULL: ᮝᮜᮤ 20;
    }
    ᮝᮜᮤ 0;
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
    ᮝᮜᮤ 0;
}
