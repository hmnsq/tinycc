#ضمن <stdio.h>

صحيح main()
{
    long long صحيح res = 0;

    إذا (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        أرجع 1;
    }
    وإلا
    إذا (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        أرجع 2;
    }
    وإلا
        printf("long long constant test ok.\n");
    أرجع 0;
}
