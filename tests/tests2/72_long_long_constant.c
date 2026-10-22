#include <stdio.h>

целое основной()
{
    long long целое res = 0;

    если (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        вернуть 1;
    }
    иначе
    если (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        вернуть 2;
    }
    иначе
        printf("long long constant test ok.\n");
    вернуть 0;
}
