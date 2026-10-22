#include <stdio.h>

ကိန်းပြည့် main()
{
    long long ကိန်းပြည့် res = 0;

    အကယ်၍ (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ပြန်ပေး 1;
    }
    မဟုတ်ပါက
    အကယ်၍ (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ပြန်ပေး 2;
    }
    မဟုတ်ပါက
        printf("long long constant test ok.\n");
    ပြန်ပေး 0;
}
