#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

số_nguyên ibdg(long long n)
{
    switch (n) {
    case                     1LL ...                   9LL: trả_về 1;
    case                    10LL ...                  99LL: trả_về 2;
    case                   100LL ...                 999LL: trả_về 3;
    case                  1000LL ...                9999LL: trả_về 4;
    case                 10000LL ...               99999LL: trả_về 5;
    case                100000LL ...              999999LL: trả_về 6;
    case               1000000LL ...             9999999LL: trả_về 7;
    case              10000000LL ...            99999999LL: trả_về 8;
    case             100000000LL ...           999999999LL: trả_về 9;
    case            1000000000LL ...          9999999999LL: trả_về 10;
    case           10000000000LL ...         99999999999LL: trả_về 11;
    case          100000000000LL ...        999999999999LL: trả_về 12;
    case         1000000000000LL ...       9999999999999LL: trả_về 13;
    case        10000000000000LL ...      99999999999999LL: trả_về 14;
    case       100000000000000LL ...     999999999999999LL: trả_về 15;
    case      1000000000000000LL ...    9999999999999999LL: trả_về 16;
    case     10000000000000000LL ...   99999999999999999LL: trả_về 17;
    case    100000000000000000LL ...  999999999999999999LL: trả_về 18;
    case   1000000000000000000LL ... 9223372036854775807LL: trả_về 19;
    case  -9223372036854775807LL-1LL ...              -1LL: trả_về 20;
    }
    trả_về 0;
}

số_nguyên ubdg(unsigned long long n)
{
    switch (n) {
    case                    1ULL ...                    9ULL: trả_về 1;
    case                   10ULL ...                   99ULL: trả_về 2;
    case                  100ULL ...                  999ULL: trả_về 3;
    case                 1000ULL ...                 9999ULL: trả_về 4;
    case                10000ULL ...                99999ULL: trả_về 5;
    case               100000ULL ...               999999ULL: trả_về 6;
    case              1000000ULL ...              9999999ULL: trả_về 7;
    case             10000000ULL ...             99999999ULL: trả_về 8;
    case            100000000ULL ...            999999999ULL: trả_về 9;
    case           1000000000ULL ...           9999999999ULL: trả_về 10;
    case          10000000000ULL ...          99999999999ULL: trả_về 11;
    case         100000000000ULL ...         999999999999ULL: trả_về 12;
    case        1000000000000ULL ...        9999999999999ULL: trả_về 13;
    case       10000000000000ULL ...       99999999999999ULL: trả_về 14;
    case      100000000000000ULL ...      999999999999999ULL: trả_về 15;
    case     1000000000000000ULL ...     9999999999999999ULL: trả_về 16;
    case    10000000000000000ULL ...    99999999999999999ULL: trả_về 17;
    case   100000000000000000ULL ...   999999999999999999ULL: trả_về 18;
    case  1000000000000000000ULL ...  9999999999999999999ULL: trả_về 19;
    case 10000000000000000000ULL ... 18446744073709551615ULL: trả_về 20;
    }
    trả_về 0;
}

số_nguyên main(số_nguyên argc, char **argv)
{
    unsigned số_nguyên i;
    unsigned long long v = 1;

    v = 1;
    cho (i = 1; i <= 20; i++) {
        printf("%lld : %d\n", (long long) v, ibdg((long long)v));
        v *= 10;
    }
    v = 1;
    cho (i = 1; i <= 20; i++) {
        printf("%llu : %d\n", v, ubdg(v));
        v *= 10;
    }
    trả_về 0;
}
