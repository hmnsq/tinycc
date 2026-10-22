#include <stdio.h>

整数 主要()
{
    long long 整数 res = 0;

    如果 (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        返回 1;
    }
    否则
    如果 (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        返回 2;
    }
    否则
        printf("long long constant test ok.\n");
    返回 0;
}
