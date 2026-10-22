#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

puur_naa_nka ibdg(long long n)
{
    switch (n) {
    pak_sa                     1LL ...                   9LL: ꦮꦭꦶ 1;
    pak_sa                    10LL ...                  99LL: ꦮꦭꦶ 2;
    pak_sa                   100LL ...                 999LL: ꦮꦭꦶ 3;
    pak_sa                  1000LL ...                9999LL: ꦮꦭꦶ 4;
    pak_sa                 10000LL ...               99999LL: ꦮꦭꦶ 5;
    pak_sa                100000LL ...              999999LL: ꦮꦭꦶ 6;
    pak_sa               1000000LL ...             9999999LL: ꦮꦭꦶ 7;
    pak_sa              10000000LL ...            99999999LL: ꦮꦭꦶ 8;
    pak_sa             100000000LL ...           999999999LL: ꦮꦭꦶ 9;
    pak_sa            1000000000LL ...          9999999999LL: ꦮꦭꦶ 10;
    pak_sa           10000000000LL ...         99999999999LL: ꦮꦭꦶ 11;
    pak_sa          100000000000LL ...        999999999999LL: ꦮꦭꦶ 12;
    pak_sa         1000000000000LL ...       9999999999999LL: ꦮꦭꦶ 13;
    pak_sa        10000000000000LL ...      99999999999999LL: ꦮꦭꦶ 14;
    pak_sa       100000000000000LL ...     999999999999999LL: ꦮꦭꦶ 15;
    pak_sa      1000000000000000LL ...    9999999999999999LL: ꦮꦭꦶ 16;
    pak_sa     10000000000000000LL ...   99999999999999999LL: ꦮꦭꦶ 17;
    pak_sa    100000000000000000LL ...  999999999999999999LL: ꦮꦭꦶ 18;
    pak_sa   1000000000000000000LL ... 9223372036854775807LL: ꦮꦭꦶ 19;
    pak_sa  -9223372036854775807LL-1LL ...              -1LL: ꦮꦭꦶ 20;
    }
    ꦮꦭꦶ 0;
}

puur_naa_nka ubdg(unsigned long long n)
{
    switch (n) {
    pak_sa                    1ULL ...                    9ULL: ꦮꦭꦶ 1;
    pak_sa                   10ULL ...                   99ULL: ꦮꦭꦶ 2;
    pak_sa                  100ULL ...                  999ULL: ꦮꦭꦶ 3;
    pak_sa                 1000ULL ...                 9999ULL: ꦮꦭꦶ 4;
    pak_sa                10000ULL ...                99999ULL: ꦮꦭꦶ 5;
    pak_sa               100000ULL ...               999999ULL: ꦮꦭꦶ 6;
    pak_sa              1000000ULL ...              9999999ULL: ꦮꦭꦶ 7;
    pak_sa             10000000ULL ...             99999999ULL: ꦮꦭꦶ 8;
    pak_sa            100000000ULL ...            999999999ULL: ꦮꦭꦶ 9;
    pak_sa           1000000000ULL ...           9999999999ULL: ꦮꦭꦶ 10;
    pak_sa          10000000000ULL ...          99999999999ULL: ꦮꦭꦶ 11;
    pak_sa         100000000000ULL ...         999999999999ULL: ꦮꦭꦶ 12;
    pak_sa        1000000000000ULL ...        9999999999999ULL: ꦮꦭꦶ 13;
    pak_sa       10000000000000ULL ...       99999999999999ULL: ꦮꦭꦶ 14;
    pak_sa      100000000000000ULL ...      999999999999999ULL: ꦮꦭꦶ 15;
    pak_sa     1000000000000000ULL ...     9999999999999999ULL: ꦮꦭꦶ 16;
    pak_sa    10000000000000000ULL ...    99999999999999999ULL: ꦮꦭꦶ 17;
    pak_sa   100000000000000000ULL ...   999999999999999999ULL: ꦮꦭꦶ 18;
    pak_sa  1000000000000000000ULL ...  9999999999999999999ULL: ꦮꦭꦶ 19;
    pak_sa 10000000000000000000ULL ... 18446744073709551615ULL: ꦮꦭꦶ 20;
    }
    ꦮꦭꦶ 0;
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    unsigned puur_naa_nka i;
    unsigned long long v = 1;

    v = 1;
    ꦏꦁꦒꦺꦴ (i = 1; i <= 20; i++) {
        printf("%lld : %d\n", (long long) v, ibdg((long long)v));
        v *= 10;
    }
    v = 1;
    ꦏꦁꦒꦺꦴ (i = 1; i <= 20; i++) {
        printf("%llu : %d\n", v, ubdg(v));
        v *= 10;
    }
    ꦮꦭꦶ 0;
}
