#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
    long long पूर्णाङ्क res = 0;

    यदि (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        प्रत्यागम 1;
    }
    अन्यथा
    यदि (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        प्रत्यागम 2;
    }
    अन्यथा
        printf("long long constant test ok.\n");
    प्रत्यागम 0;
}
