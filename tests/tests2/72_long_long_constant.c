#include <stdio.h>

整数 メインページ()
{
    long long 整数 res = 0;

    もし (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        戻る 1;
    }
    否则
    もし (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        戻る 2;
    }
    否则
        printf("long long constant test ok.\n");
    戻る 0;
}
