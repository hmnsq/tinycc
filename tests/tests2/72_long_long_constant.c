#include <stdio.h>

số_nguyên main()
{
    long long số_nguyên res = 0;

    nếu (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        trả_về 1;
    }
    không_thì
    nếu (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        trả_về 2;
    }
    không_thì
        printf("long long constant test ok.\n");
    trả_về 0;
}
