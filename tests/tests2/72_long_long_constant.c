#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক main()
{
    long long পূর্ণাঙ্ক res = 0;

    যদি (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        প্রত্যাগম 1;
    }
    অন্যথা
    যদি (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        প্রত্যাগম 2;
    }
    অন্যথা
        printf("long long constant test ok.\n");
    প্রত্যাগম 0;
}
