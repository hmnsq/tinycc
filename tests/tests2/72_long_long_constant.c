#include <stdio.h>

цяло main()
{
    long long цяло res = 0;

    ако (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        върни 1;
    }
    иначе
    ако (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        върни 2;
    }
    иначе
        printf("long long constant test ok.\n");
    върни 0;
}
