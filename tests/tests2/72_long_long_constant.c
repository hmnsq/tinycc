#include <stdio.h>

ចំនួនគត់ main()
{
    long long ចំនួនគត់ res = 0;

    ប្រសិនបើ (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ត្រឡប់ 1;
    }
    បើមិនដូច្នេះ
    ប្រសិនបើ (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ត្រឡប់ 2;
    }
    បើមិនដូច្នេះ
        printf("long long constant test ok.\n");
    ត្រឡប់ 0;
}
