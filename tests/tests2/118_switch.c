#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

puur_naa_nka ibdg(long long n)
{
    switch (n) {
    pak_sa                     1LL ...                   9LL: ᨀᨘᨒ 1;
    pak_sa                    10LL ...                  99LL: ᨀᨘᨒ 2;
    pak_sa                   100LL ...                 999LL: ᨀᨘᨒ 3;
    pak_sa                  1000LL ...                9999LL: ᨀᨘᨒ 4;
    pak_sa                 10000LL ...               99999LL: ᨀᨘᨒ 5;
    pak_sa                100000LL ...              999999LL: ᨀᨘᨒ 6;
    pak_sa               1000000LL ...             9999999LL: ᨀᨘᨒ 7;
    pak_sa              10000000LL ...            99999999LL: ᨀᨘᨒ 8;
    pak_sa             100000000LL ...           999999999LL: ᨀᨘᨒ 9;
    pak_sa            1000000000LL ...          9999999999LL: ᨀᨘᨒ 10;
    pak_sa           10000000000LL ...         99999999999LL: ᨀᨘᨒ 11;
    pak_sa          100000000000LL ...        999999999999LL: ᨀᨘᨒ 12;
    pak_sa         1000000000000LL ...       9999999999999LL: ᨀᨘᨒ 13;
    pak_sa        10000000000000LL ...      99999999999999LL: ᨀᨘᨒ 14;
    pak_sa       100000000000000LL ...     999999999999999LL: ᨀᨘᨒ 15;
    pak_sa      1000000000000000LL ...    9999999999999999LL: ᨀᨘᨒ 16;
    pak_sa     10000000000000000LL ...   99999999999999999LL: ᨀᨘᨒ 17;
    pak_sa    100000000000000000LL ...  999999999999999999LL: ᨀᨘᨒ 18;
    pak_sa   1000000000000000000LL ... 9223372036854775807LL: ᨀᨘᨒ 19;
    pak_sa  -9223372036854775807LL-1LL ...              -1LL: ᨀᨘᨒ 20;
    }
    ᨀᨘᨒ 0;
}

puur_naa_nka ubdg(unsigned long long n)
{
    switch (n) {
    pak_sa                    1ULL ...                    9ULL: ᨀᨘᨒ 1;
    pak_sa                   10ULL ...                   99ULL: ᨀᨘᨒ 2;
    pak_sa                  100ULL ...                  999ULL: ᨀᨘᨒ 3;
    pak_sa                 1000ULL ...                 9999ULL: ᨀᨘᨒ 4;
    pak_sa                10000ULL ...                99999ULL: ᨀᨘᨒ 5;
    pak_sa               100000ULL ...               999999ULL: ᨀᨘᨒ 6;
    pak_sa              1000000ULL ...              9999999ULL: ᨀᨘᨒ 7;
    pak_sa             10000000ULL ...             99999999ULL: ᨀᨘᨒ 8;
    pak_sa            100000000ULL ...            999999999ULL: ᨀᨘᨒ 9;
    pak_sa           1000000000ULL ...           9999999999ULL: ᨀᨘᨒ 10;
    pak_sa          10000000000ULL ...          99999999999ULL: ᨀᨘᨒ 11;
    pak_sa         100000000000ULL ...         999999999999ULL: ᨀᨘᨒ 12;
    pak_sa        1000000000000ULL ...        9999999999999ULL: ᨀᨘᨒ 13;
    pak_sa       10000000000000ULL ...       99999999999999ULL: ᨀᨘᨒ 14;
    pak_sa      100000000000000ULL ...      999999999999999ULL: ᨀᨘᨒ 15;
    pak_sa     1000000000000000ULL ...     9999999999999999ULL: ᨀᨘᨒ 16;
    pak_sa    10000000000000000ULL ...    99999999999999999ULL: ᨀᨘᨒ 17;
    pak_sa   100000000000000000ULL ...   999999999999999999ULL: ᨀᨘᨒ 18;
    pak_sa  1000000000000000000ULL ...  9999999999999999999ULL: ᨀᨘᨒ 19;
    pak_sa 10000000000000000000ULL ... 18446744073709551615ULL: ᨀᨘᨒ 20;
    }
    ᨀᨘᨒ 0;
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
    ᨀᨘᨒ 0;
}
