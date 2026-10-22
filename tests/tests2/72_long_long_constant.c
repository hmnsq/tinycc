#include <stdio.h>

ཧྲིལ main()
{
    long long ཧྲིལ res = 0;

    གལ་སྲིད (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ལོག 1;
    }
    དེ་མིན
    གལ་སྲིད (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ལོག 2;
    }
    དེ་མིན
        printf("long long constant test ok.\n");
    ལོག 0;
}
