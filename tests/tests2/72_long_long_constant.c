#include <stdio.h>

цео main()
{
    long long цео res = 0;

    ако (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        врати 1;
    }
    инако
    ако (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        врати 2;
    }
    инако
        printf("long long constant test ok.\n");
    врати 0;
}
