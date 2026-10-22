#شامل <stdio.h>

صحیح اصلی()
{
    long long صحیح res = 0;

    اگر (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        بازگشت 1;
    }
    وگرنه
    اگر (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        بازگشت 2;
    }
    وگرنه
        printf("long long constant test ok.\n");
    بازگشت 0;
}
