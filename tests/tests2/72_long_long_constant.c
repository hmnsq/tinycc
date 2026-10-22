#include <stdio.h>

จำนวนเต็ม หลัก()
{
    long long จำนวนเต็ม res = 0;

    ถ้า (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        คืน 1;
    }
    มิฉะนั้น
    ถ้า (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        คืน 2;
    }
    มิฉะนั้น
        printf("long long constant test ok.\n");
    คืน 0;
}
