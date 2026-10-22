#ضمن <stdio.h>

صحيح main()
{
    long long صحيح res = 0;

    אם (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        החזר 1;
    }
    אחרת
    אם (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        החזר 2;
    }
    אחרת
        printf("long long constant test ok.\n");
    החזר 0;
}
