#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক main()
{
    long long পূর্ণাঙ্ক res = 0;

    যদি (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ঘূৰাই 1;
    }
    অন্যথা
    যদি (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ঘূৰাই 2;
    }
    অন্যথা
        printf("long long constant test ok.\n");
    ঘূৰাই 0;
}
