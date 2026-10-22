#ضمن <stdio.h>

صحيح الرئيسية()
{
    long long صحيح res = 0;

    إذا (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        إرجاع 1;
    }
    وإلا
    إذا (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        إرجاع 2;
    }
    وإلا
        printf("long long constant test ok.\n");
    إرجاع 0;
}
