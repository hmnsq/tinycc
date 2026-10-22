#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
    long long पूर्णाङ्क res = 0;

    सचे (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        पटिनिवत्त 1;
    }
    अञ्ञथा
    सचे (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        पटिनिवत्त 2;
    }
    अञ्ञथा
        printf("long long constant test ok.\n");
    पटिनिवत्त 0;
}
