#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান()
{
    long long পূর্ণসংখ্যা res = 0;

    যদি (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ফেরত 1;
    }
    অন্যথা
    যদি (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ফেরত 2;
    }
    অন্যথা
        printf("long long constant test ok.\n");
    ফেরত 0;
}
