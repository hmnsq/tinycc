#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

puur_naa_nka ibdg(long long n)
{
    switch (n) {
    pak_sa                     1LL ...                   9LL: ᬯᬮᬶ 1;
    pak_sa                    10LL ...                  99LL: ᬯᬮᬶ 2;
    pak_sa                   100LL ...                 999LL: ᬯᬮᬶ 3;
    pak_sa                  1000LL ...                9999LL: ᬯᬮᬶ 4;
    pak_sa                 10000LL ...               99999LL: ᬯᬮᬶ 5;
    pak_sa                100000LL ...              999999LL: ᬯᬮᬶ 6;
    pak_sa               1000000LL ...             9999999LL: ᬯᬮᬶ 7;
    pak_sa              10000000LL ...            99999999LL: ᬯᬮᬶ 8;
    pak_sa             100000000LL ...           999999999LL: ᬯᬮᬶ 9;
    pak_sa            1000000000LL ...          9999999999LL: ᬯᬮᬶ 10;
    pak_sa           10000000000LL ...         99999999999LL: ᬯᬮᬶ 11;
    pak_sa          100000000000LL ...        999999999999LL: ᬯᬮᬶ 12;
    pak_sa         1000000000000LL ...       9999999999999LL: ᬯᬮᬶ 13;
    pak_sa        10000000000000LL ...      99999999999999LL: ᬯᬮᬶ 14;
    pak_sa       100000000000000LL ...     999999999999999LL: ᬯᬮᬶ 15;
    pak_sa      1000000000000000LL ...    9999999999999999LL: ᬯᬮᬶ 16;
    pak_sa     10000000000000000LL ...   99999999999999999LL: ᬯᬮᬶ 17;
    pak_sa    100000000000000000LL ...  999999999999999999LL: ᬯᬮᬶ 18;
    pak_sa   1000000000000000000LL ... 9223372036854775807LL: ᬯᬮᬶ 19;
    pak_sa  -9223372036854775807LL-1LL ...              -1LL: ᬯᬮᬶ 20;
    }
    ᬯᬮᬶ 0;
}

puur_naa_nka ubdg(unsigned long long n)
{
    switch (n) {
    pak_sa                    1ULL ...                    9ULL: ᬯᬮᬶ 1;
    pak_sa                   10ULL ...                   99ULL: ᬯᬮᬶ 2;
    pak_sa                  100ULL ...                  999ULL: ᬯᬮᬶ 3;
    pak_sa                 1000ULL ...                 9999ULL: ᬯᬮᬶ 4;
    pak_sa                10000ULL ...                99999ULL: ᬯᬮᬶ 5;
    pak_sa               100000ULL ...               999999ULL: ᬯᬮᬶ 6;
    pak_sa              1000000ULL ...              9999999ULL: ᬯᬮᬶ 7;
    pak_sa             10000000ULL ...             99999999ULL: ᬯᬮᬶ 8;
    pak_sa            100000000ULL ...            999999999ULL: ᬯᬮᬶ 9;
    pak_sa           1000000000ULL ...           9999999999ULL: ᬯᬮᬶ 10;
    pak_sa          10000000000ULL ...          99999999999ULL: ᬯᬮᬶ 11;
    pak_sa         100000000000ULL ...         999999999999ULL: ᬯᬮᬶ 12;
    pak_sa        1000000000000ULL ...        9999999999999ULL: ᬯᬮᬶ 13;
    pak_sa       10000000000000ULL ...       99999999999999ULL: ᬯᬮᬶ 14;
    pak_sa      100000000000000ULL ...      999999999999999ULL: ᬯᬮᬶ 15;
    pak_sa     1000000000000000ULL ...     9999999999999999ULL: ᬯᬮᬶ 16;
    pak_sa    10000000000000000ULL ...    99999999999999999ULL: ᬯᬮᬶ 17;
    pak_sa   100000000000000000ULL ...   999999999999999999ULL: ᬯᬮᬶ 18;
    pak_sa  1000000000000000000ULL ...  9999999999999999999ULL: ᬯᬮᬶ 19;
    pak_sa 10000000000000000000ULL ... 18446744073709551615ULL: ᬯᬮᬶ 20;
    }
    ᬯᬮᬶ 0;
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
    ᬯᬮᬶ 0;
}
