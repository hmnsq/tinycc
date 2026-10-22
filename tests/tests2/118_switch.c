#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

puur_naa_nka ibdg(long long n)
{
    switch (n) {
    pak_sa                     1LL ...                   9LL: ᯀᯮᯞ 1;
    pak_sa                    10LL ...                  99LL: ᯀᯮᯞ 2;
    pak_sa                   100LL ...                 999LL: ᯀᯮᯞ 3;
    pak_sa                  1000LL ...                9999LL: ᯀᯮᯞ 4;
    pak_sa                 10000LL ...               99999LL: ᯀᯮᯞ 5;
    pak_sa                100000LL ...              999999LL: ᯀᯮᯞ 6;
    pak_sa               1000000LL ...             9999999LL: ᯀᯮᯞ 7;
    pak_sa              10000000LL ...            99999999LL: ᯀᯮᯞ 8;
    pak_sa             100000000LL ...           999999999LL: ᯀᯮᯞ 9;
    pak_sa            1000000000LL ...          9999999999LL: ᯀᯮᯞ 10;
    pak_sa           10000000000LL ...         99999999999LL: ᯀᯮᯞ 11;
    pak_sa          100000000000LL ...        999999999999LL: ᯀᯮᯞ 12;
    pak_sa         1000000000000LL ...       9999999999999LL: ᯀᯮᯞ 13;
    pak_sa        10000000000000LL ...      99999999999999LL: ᯀᯮᯞ 14;
    pak_sa       100000000000000LL ...     999999999999999LL: ᯀᯮᯞ 15;
    pak_sa      1000000000000000LL ...    9999999999999999LL: ᯀᯮᯞ 16;
    pak_sa     10000000000000000LL ...   99999999999999999LL: ᯀᯮᯞ 17;
    pak_sa    100000000000000000LL ...  999999999999999999LL: ᯀᯮᯞ 18;
    pak_sa   1000000000000000000LL ... 9223372036854775807LL: ᯀᯮᯞ 19;
    pak_sa  -9223372036854775807LL-1LL ...              -1LL: ᯀᯮᯞ 20;
    }
    ᯀᯮᯞ 0;
}

puur_naa_nka ubdg(unsigned long long n)
{
    switch (n) {
    pak_sa                    1ULL ...                    9ULL: ᯀᯮᯞ 1;
    pak_sa                   10ULL ...                   99ULL: ᯀᯮᯞ 2;
    pak_sa                  100ULL ...                  999ULL: ᯀᯮᯞ 3;
    pak_sa                 1000ULL ...                 9999ULL: ᯀᯮᯞ 4;
    pak_sa                10000ULL ...                99999ULL: ᯀᯮᯞ 5;
    pak_sa               100000ULL ...               999999ULL: ᯀᯮᯞ 6;
    pak_sa              1000000ULL ...              9999999ULL: ᯀᯮᯞ 7;
    pak_sa             10000000ULL ...             99999999ULL: ᯀᯮᯞ 8;
    pak_sa            100000000ULL ...            999999999ULL: ᯀᯮᯞ 9;
    pak_sa           1000000000ULL ...           9999999999ULL: ᯀᯮᯞ 10;
    pak_sa          10000000000ULL ...          99999999999ULL: ᯀᯮᯞ 11;
    pak_sa         100000000000ULL ...         999999999999ULL: ᯀᯮᯞ 12;
    pak_sa        1000000000000ULL ...        9999999999999ULL: ᯀᯮᯞ 13;
    pak_sa       10000000000000ULL ...       99999999999999ULL: ᯀᯮᯞ 14;
    pak_sa      100000000000000ULL ...      999999999999999ULL: ᯀᯮᯞ 15;
    pak_sa     1000000000000000ULL ...     9999999999999999ULL: ᯀᯮᯞ 16;
    pak_sa    10000000000000000ULL ...    99999999999999999ULL: ᯀᯮᯞ 17;
    pak_sa   100000000000000000ULL ...   999999999999999999ULL: ᯀᯮᯞ 18;
    pak_sa  1000000000000000000ULL ...  9999999999999999999ULL: ᯀᯮᯞ 19;
    pak_sa 10000000000000000000ULL ... 18446744073709551615ULL: ᯀᯮᯞ 20;
    }
    ᯀᯮᯞ 0;
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
    ᯀᯮᯞ 0;
}
