#include <stdio.h>

ціле main()
{
    long long ціле res = 0;

    якщо (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        повернути 1;
    }
    інакше
    якщо (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        повернути 2;
    }
    інакше
        printf("long long constant test ok.\n");
    повернути 0;
}
