#include <stdio.h>

ཧྲིལ གཙོ()
{
    long long ཧྲིལ res = 0;

    གལ་ཏེ (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ཕྱིར 1;
    }
    དེ་མིན
    གལ་ཏེ (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ཕྱིར 2;
    }
    དེ་མིན
        printf("long long constant test ok.\n");
    ཕྱིར 0;
}
