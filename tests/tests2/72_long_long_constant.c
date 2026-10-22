#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    long long ପୂର୍ଣ୍ଣସଂଖ୍ୟା res = 0;

    ଯଦି (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ଫେରନ୍ତୁ 1;
    }
    ଅନ୍ୟଥା
    ଯଦି (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ଫେରନ୍ତୁ 2;
    }
    ଅନ୍ୟଥା
        printf("long long constant test ok.\n");
    ଫେରନ୍ତୁ 0;
}
