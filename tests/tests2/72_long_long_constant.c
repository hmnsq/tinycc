#include <stdio.h>

정수 main()
{
    long long 정수 res = 0;

    만약 (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        반환 1;
    }
    아니면
    만약 (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        반환 2;
    }
    아니면
        printf("long long constant test ok.\n");
    반환 0;
}
