#include <stdio.h>

ຈຳນວນເຕັມ main()
{
    long long ຈຳນວນເຕັມ res = 0;

    ຖ້າ (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ສົ່ງຄືນ 1;
    }
    ບໍ່ດັ່ງນັ້ນ
    ຖ້າ (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ສົ່ງຄືນ 2;
    }
    ບໍ່ດັ່ງນັ້ນ
        printf("long long constant test ok.\n");
    ສົ່ງຄືນ 0;
}
