#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
    long long ಪೂರ್ಣಾಙ್ಕ res = 0;

    ಯದಿ (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        ಪ್ರತ್ಯಾಗಮ 1;
    }
    ಅನ್ಯಥಾ
    ಯದಿ (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        ಪ್ರತ್ಯಾಗಮ 2;
    }
    ಅನ್ಯಥಾ
        printf("long long constant test ok.\n");
    ಪ್ರತ್ಯಾಗಮ 0;
}
