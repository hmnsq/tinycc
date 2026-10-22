#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    long long പൂർണ്ണസംഖ്യ res = 0;

    എങ്കിൽ (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        തിരികെ 1;
    }
    അല്ലെങ്കിൽ
    എങ്കിൽ (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        തിരികെ 2;
    }
    അല്ലെങ്കിൽ
        printf("long long constant test ok.\n");
    തിരികെ 0;
}
